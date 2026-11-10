#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

std::string Trim(const std::string &value)
{
    const auto first = value.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";

    const auto last = value.find_last_not_of(" \t");
    return value.substr(first, last - first + 1);
}

std::string ReadTextFile(const std::filesystem::path &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input)
        throw std::runtime_error("cannot read '" + path.string() + "'");

    std::ostringstream buffer;
    buffer << input.rdbuf();
    return buffer.str();
}

void EnsureParentDirectory(const std::filesystem::path &path)
{
    const auto parent = path.parent_path();
    if (!parent.empty())
        std::filesystem::create_directories(parent);
}

void WriteTextFile(const std::filesystem::path &path, const std::string &contents)
{
    EnsureParentDirectory(path);
    std::ofstream output(path, std::ios::binary | std::ios::trunc);
    if (!output)
        throw std::runtime_error("cannot write '" + path.string() + "'");
    output << contents;
    if (!output)
        throw std::runtime_error("cannot write '" + path.string() + "'");
}

std::vector<std::string> SplitLines(const std::string &source)
{
    std::vector<std::string> lines;
    std::istringstream input(source);
    std::string line;
    while (std::getline(input, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        lines.push_back(std::move(line));
    }
    return lines;
}

std::string JoinLines(const std::vector<std::string> &lines)
{
    std::ostringstream output;
    for (const std::string &line : lines)
        output << line << '\n';
    return output.str();
}

bool IsAssemblyDataSectionTransition(const std::string &line)
{
    const std::string trimmed = Trim(line);
    return trimmed == ".text" || trimmed.rfind(".section", 0) == 0;
}

std::string AlignExecutableSections(const std::string &assembly)
{
    // This is the former align_sections.sh policy, now applied by the same
    // generic assembly-formatting pass.  It only closes executable
    // compiler sections; explicitly aligned .rodata objects keep the exact
    // ALIGN(n) directives emitted from their ordinary C/C++ declarations.
    static const std::regex section_pattern(
        R"(^[\t ]*\.section[\t ]+([A-Za-z0-9_.]+),"ax",%progbits[\t ]*$)");

    std::vector<std::string> lines = SplitLines(assembly);
    std::vector<std::string> sections;
    std::set<std::string> seen_sections;
    for (const std::string &line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, section_pattern)
            && seen_sections.insert(match[1].str()).second) {
            sections.push_back(match[1].str());
        }
    }

    for (const std::string &section : sections) {
        lines.push_back("\t.section \"" + section + "\"");
        lines.push_back("\t.align 2, 0");
    }
    lines.push_back("\t.text");
    lines.push_back("\t.align 2, 0");
    return JoinLines(lines);
}

std::string PreprocessAssembly(const std::string &, const std::string &assembly)
{
    return AlignExecutableSections(assembly);
}

// Optional localization reservations are generated from a verified native
// layout. They pad data input sections without changing source declarations,
// linker section names, object symbol sizes, relocations, or instructions.
std::string ReserveDataSections(const std::string &assembly,
    const std::string &plan, const std::string &owner)
{
    std::map<std::string, std::size_t> capacities;
    for (const auto &line : SplitLines(plan)) {
        if (Trim(line).empty() || Trim(line).front() == '#')
            continue;
        std::istringstream fields(line);
        std::string file, name, bytes, extra;
        if (!(fields >> file >> name >> bytes) || (fields >> extra))
            throw std::runtime_error("invalid data reservation row: " + line);
        if (file == owner && !capacities.emplace(name, std::stoul(bytes, nullptr, 0)).second)
            throw std::runtime_error("duplicate data reservation: " + name);
    }
    if (capacities.empty())
        return assembly;

    struct Part {
        std::string directive;
        std::size_t begin, end;
        std::set<std::string> objects;
    };
    const auto lines = SplitLines(assembly);
    std::vector<Part> parts;
    std::map<std::string, std::size_t> sections;
    const std::regex data_section(R"(^\s*\.section\s+\.rodata(?:[.,\s].*)?$)");
    const std::regex object_type(R"(^\s*\.type\s+([^,\s]+)\s*,\s*object\s*$)");
    std::size_t active = std::string::npos;
    for (std::size_t index = 0; index <= lines.size(); ++index) {
        if (index == lines.size() || IsAssemblyDataSectionTransition(lines[index])) {
            if (active != std::string::npos)
                parts[active].end = index;
            active = std::string::npos;
            if (index == lines.size() || !std::regex_match(lines[index], data_section))
                continue;
            const std::string directive = Trim(lines[index]);
            auto found = sections.find(directive);
            if (found == sections.end()) {
                active = parts.size();
                sections.emplace(directive, active);
                parts.push_back({directive, index + 1, index + 1, {}});
            } else {
                active = found->second;
            }
        } else if (active != std::string::npos) {
            std::smatch match;
            if (std::regex_match(lines[index], match, object_type))
                parts[active].objects.insert(match[1].str());
        }
    }
    std::map<std::size_t, std::vector<std::string>> insertions;
    std::set<std::string> used;
    for (std::size_t index = 0; index < parts.size(); ++index) {
        const Part &part = parts[index];
        std::vector<std::string> matches;
        for (const auto &name : part.objects) {
            if (capacities.count(name))
                matches.push_back(name);
        }
        if (matches.empty() && part.objects.empty()
            && part.directive.find("unique") == std::string::npos
            && capacities.count("@plain"))
            matches.push_back("@plain");
        if (matches.size() != 1)
            continue;
        const std::string &name = matches.front();
        if (!used.insert(name).second)
            throw std::runtime_error("ambiguous data reservation: " + name);
        const std::string size = std::to_string(capacities.at(name));
        auto &tail = insertions[part.end];
        // .org is relative to this individual input section. GAS rejects a
        // backwards .org, so an oversized object fails even with relaxation
        // fragments from compiler alignment directives.
        tail.push_back("\t.org " + size + ", 0 @ localization reservation: " + name);
    }
    for (const auto &[name, size] : capacities) {
        if (!used.count(name))
            throw std::runtime_error("data reservation object is missing: " + owner + ":" + name);
    }
    std::ostringstream output;
    for (std::size_t index = 0; index <= lines.size(); ++index) {
        for (const auto &line : insertions[index])
            output << line << '\n';
        if (index != lines.size())
            output << lines[index] << '\n';
    }
    return output.str();
}

void Require(bool condition, const std::string &message)
{
    if (!condition)
        throw std::runtime_error("self-test failed: " + message);
}

void SelfTest()
{
    const std::string reservation_input =
        "\t.section .rodata,\"a\",%progbits,unique,1\n"
        "\t.type gText,object\ngText:\n\t.ascii \"A\\000\"\n"
        "\t.section .text.example,\"ax\",%progbits\n"
        "example:\n\tbx lr\n"
        "\t.section .rodata,\"a\",%progbits,unique,2\n"
        "\t.type gTable,object\ngTable:\n\t.word gText\n";
    const std::string reserved = ReserveDataSections(reservation_input,
        "src/test.o gText 12\nsrc/test.o gTable 8\n", "src/test.o");
    Require(reserved.find(".org 12, 0 @ localization reservation: gText") != std::string::npos
        && reserved.find(".org 8, 0 @ localization reservation: gTable") != std::string::npos,
        "data reservations did not preserve separate input sections");
    Require(reserved.find("example:\n\tbx lr\n") != std::string::npos
        && reserved.find("\t.word gText\n") != std::string::npos,
        "data reservations changed an instruction or pointer");
    Require(ReserveDataSections(reservation_input, "other.o gText 8\n", "src/test.o")
        == reservation_input, "unselected objects were reserved");

    // Equal contents do not prove that an anonymous literal and a named
    // object are interchangeable. All labels and references must survive.
    const std::string independent_source =
        "char const title[] = \"same\";\n"
        "char const * const pointer = title;\n";
    const std::string independent_assembly =
        "\t.section .rodata\n"
        ".LC0:\n\t.ascii \"same\\000\"\n"
        "\t.text\nreader:\n\t.word .LC0\n"
        "\t.section .rodata.title,\"a\"\n"
        "title:\n\t.ascii \"same\\000\"\n"
        "\t.section .rodata.pointer,\"a\"\n"
        "pointer:\n\t.word title\n";
    const std::string independent_output = PreprocessAssembly(
        independent_source, independent_assembly);
    Require(independent_output.find(".LC0:\n\t.ascii \"same\\000\"") != std::string::npos
        && independent_output.find("title:\n\t.ascii \"same\\000\"") != std::string::npos
        && independent_output.find("reader:\n\t.word .LC0") != std::string::npos
        && independent_output.find("pointer:\n\t.word title") != std::string::npos,
        "formatting must preserve independent literals and their original references");

    const std::string stacked_setup_assembly =
        "\t.text\n"
        "generic_stacked_dispatch:\n"
        "\tadd\tr5, r1, #0\n"
        "\tldr\tr1, [sp, #0x30]\n"
        "\tadd\tr4, r0, #0\n"
        "\tmov\tsl, r5\n"
        "\tadd\tr5, r2, #0\n"
        "\tadd\tr6, r3, #0\n"
        "\tadd\tr0, sp, #0xc\n"
        "\tbl\tany_callee\n"
        "nonmatching_stacked_dispatch:\n"
        "\tadd\tr5, r1, #0\n"
        "\tldr\tr1, [sp, #0x30]\n"
        "\tadd\tr4, r0, #0\n"
        "\tmov\tsl, r5\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0xc\n"
        "\tbl\tany_callee\n";
    Require(PreprocessAssembly("", stacked_setup_assembly).compare(0,
                stacked_setup_assembly.size(), stacked_setup_assembly) == 0,
        "executable instructions must not be rewritten");

    const std::string trampoline_assembly =
        "\t.text\n"
        "literal_dispatch:\n"
        "\tldr\tr2, .Lliteral_dispatch_target\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\t_call_via_r2\n"
        "unrelated_call:\n"
        "\tldr\tr2, [r0]\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\t_call_via_r2\n";
    Require(PreprocessAssembly("", trampoline_assembly).compare(0,
                trampoline_assembly.size(), trampoline_assembly) == 0,
        "executable instructions must not be rewritten");

    const std::string three_outcome_assembly =
        "\t.text\n"
        "three_outcome:\n"
        "\tcmp\tr0, #0x1\n"
        "\tbeq\t.Lone\n"
        "\tcmp\tr0, #0\n"
        "\tbeq\t.Lzero\n"
        "\tcmp\tr0, #0x2\n"
        "\tbeq\t.Ltwo\n"
        "ordinary_zero_test:\n"
        "\tcmp\tr1, #0\n"
        "\tbeq\t.Lordinary\n";
    Require(PreprocessAssembly("", three_outcome_assembly).compare(0,
                three_outcome_assembly.size(), three_outcome_assembly) == 0,
        "executable instructions must not be rewritten");

    const std::string cpu_fast_set_assembly =
        "\t.text\n"
        "full_fill:\n"
        "\tmov\tr7, r9\n"
        "\tlsl\tr0, r0, #0x5\n"
        "\tmul\tr2, r2, r0\n"
        "\tstr\tr7, [sp]\n"
        "\tlsl\tr2, r2, #0x9\n"
        "\tlsr\tr2, r2, #0xb\n"
        "\tmov\tr0, #0x80\n"
        "\tlsl\tr0, r0, #0x11\n"
        "\torr\tr2, r2, r0\n"
        "\tmov\tr0, sp\n"
        "\tmov\tr1, r8\n"
        "\tbl\tCpuFastSet\n"
        "\tb\t.Ldone\n"
        ".Lpartial:\n"
        "\tldr\tr4, .Lmask\n"
        "\tmov\tr0, ip\n"
        "\tand\tr4, r4, r0\n"
        "\tldr\tr0, .Lmask+0x4\n"
        "\tand\tr4, r4, r0\n"
        "\tmov\tr1, #0x80\n"
        "\tlsl\tr1, r1, #0x11\n"
        "\tmov\tr8, r1\n"
        ".Lrow:\n"
        "\tmov\tr0, r9\n"
        "\tstr\tr0, [sp]\n"
        "\tadd\tr2, r4, #0\n"
        "\tmov\tr1, r8\n"
        "\torr\tr2, r2, r1\n"
        "\tmov\tr0, sp\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\tCpuFastSet\n"
        ".Ldone:\n"
        "\tbx\tlr\n"
        ".Lmask:\n"
        "\t.word\t0x3ffffff8\n"
        "\t.word\t0x1fffff\n";
    Require(PreprocessAssembly("", cpu_fast_set_assembly).compare(0,
                cpu_fast_set_assembly.size(), cpu_fast_set_assembly) == 0,
        "executable instructions must not be rewritten");

    const std::string fixed_register_assembly =
        "\t.text\n"
        "generic_wrapper:\n"
        "\tadd\tr4, r1, #0\n"
        "\tldr\tr1, [sp, #0xac]\n"
        "\tadd\tr5, r0, #0\n"
        "\tmov\tr9, r4\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0x4\n"
        "\tbl\tGenericCallee\n"
        "\tmov\tsl, r0\n"
        "\tsub\tr0, r0, #0x1\n"
        "\tcmp\tr0, #0x1\n"
        "\tbhi\t.Lgeneric_invalid\n"
        "\tlsr\tr4, r6, #0x3\n"
        "unrelated_wrapper:\n"
        "\tadd\tr4, r1, #0\n"
        "\tldr\tr1, [sp, #0xac]\n"
        "\tadd\tr5, r0, #0\n"
        "\tmov\tr9, r4\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0x4\n"
        "\tbl\tUnprovenCallee\n"
        "\tmov\tsl, r0\n"
        "\tsub\tr0, r0, #0x1\n"
        "\tcmp\tr0, #0x1\n"
        "\tbhi\t.Lunrelated_invalid\n"
        "\tlsr\tr5, r6, #0x3\n"
        "tile_address:\n"
        "\tlsl\tr0, r1, #0x5\n"
        "\tadd\tr0, r0, r9\n"
        "\tadd\tr1, r0, #0\n"
        "\tadd\tr1, r1, #0x20\n"
        "\tadd\tr0, sp, #0x64\n"
        "\tmov\tr2, #0x8\n"
        "\tbl\tGenericCopy\n"
        "unrelated_tile_address:\n"
        "\tlsl\tr0, r1, #0x5\n"
        "\tadd\tr0, r0, r8\n"
        "\tadd\tr1, r0, #0\n"
        "\tadd\tr1, r1, #0x20\n"
        "\tadd\tr0, sp, #0x64\n"
        "\tmov\tr2, #0x8\n"
        "\tbl\tOtherCopy\n"
        "unsafe_wrapper:\n"
        "\tadd\tr4, r1, #0\n"
        "\tldr\tr1, [sp, #0xac]\n"
        "\tadd\tr5, r0, #0\n"
        "\tmov\tr9, r4\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0x4\n"
        "\tbl\tUnsafeCallee\n"
        "\tmov\tsl, r0\n"
        "\tsub\tr0, r0, #0x1\n"
        "\tcmp\tr0, #0x1\n"
        "\tbhi\t.Lunsafe_invalid\n"
        "\tlsr\tr4, r6, #0x3\n"
        ".Lgeneric_invalid:\n"
        "\tmov\tr0, #0\n"
        "\tpop\t{r4, r5, r6, r7, pc}\n"
        ".Lunrelated_invalid:\n"
        "\tmov\tr0, #0\n"
        "\tpop\t{r4, r5, r6, r7, pc}\n"
        ".Lunsafe_invalid:\n"
        "\tadd\tr0, r4, #0\n"
        "\tbx\tlr\n";
    Require(PreprocessAssembly("", fixed_register_assembly).compare(0,
                fixed_register_assembly.size(), fixed_register_assembly) == 0,
        "executable instructions must not be rewritten");

}

const char *Usage()
{
    return "usage:\n"
           "  fomt-preproc self-test\n"
           "  fomt-preproc asm SOURCE ASSEMBLY\n"
           "  fomt-preproc reserve PLAN OWNER ASSEMBLY\n";
}

int Run(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]) == "self-test") {
        SelfTest();
        std::cout << "fomt-preproc: self-test passed\n";
        return 0;
    }
    if (argc == 4 && std::string(argv[1]) == "asm") {
        const std::filesystem::path source = argv[2];
        const std::filesystem::path assembly = argv[3];
        WriteTextFile(assembly, PreprocessAssembly(ReadTextFile(source), ReadTextFile(assembly)));
        return 0;
    }
    if (argc == 5 && std::string(argv[1]) == "reserve") {
        const std::filesystem::path assembly = argv[4];
        WriteTextFile(assembly, ReserveDataSections(ReadTextFile(assembly),
            ReadTextFile(argv[2]), argv[3]));
        return 0;
    }
    throw std::runtime_error(Usage());
}

} // namespace

int main(int argc, char **argv)
{
    try {
        return Run(argc, argv);
    } catch (const std::exception &error) {
        std::cerr << "fomt-preproc: " << error.what() << '\n';
        return 2;
    }
}
