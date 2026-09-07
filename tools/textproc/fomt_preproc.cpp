#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
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

std::string TrimWhitespace(const std::string &value)
{
    const auto first = value.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";

    const auto last = value.find_last_not_of(" \t\r\n");
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

bool IsAssemblyStringPayload(const std::string &line)
{
    const std::string trimmed = Trim(line);
    return trimmed.rfind(".ascii", 0) == 0
        || trimmed.rfind(".string", 0) == 0;
}

bool IsAssemblyAlign(const std::string &line)
{
    return Trim(line).rfind(".align", 0) == 0;
}

std::size_t FindAssemblyLabel(const std::vector<std::string> &lines,
    const std::string &label)
{
    const std::string wanted = label + ":";
    for (std::size_t index = 0; index < lines.size(); ++index) {
        if (Trim(lines[index]) == wanted)
            return index;
    }
    return std::string::npos;
}

std::vector<std::string> AssemblyStringPayloadAfter(const std::vector<std::string> &lines,
    std::size_t label_index)
{
    std::vector<std::string> payload;
    for (std::size_t index = label_index + 1;
         index < lines.size() && IsAssemblyStringPayload(lines[index]); ++index) {
        payload.push_back(Trim(lines[index]));
    }
    return payload;
}

std::map<std::string, std::string> FindDirectConstCharPointerInitializers(
    const std::string &source)
{
    // This recognizes the ordinary C++ form
    // "char const * const pointer = named_char_array;" in every translation
    // unit.  agbcp 2.9 can replace its target with a duplicate .LC string;
    // only a byte-for-byte match is eligible for repair below.
    static const std::regex pattern(
        R"((?:extern\s+)?char\s+const\s*\*\s*const\s+([A-Za-z_][A-Za-z0-9_]*)\s*=\s*([A-Za-z_][A-Za-z0-9_]*)\s*;)");

    std::map<std::string, std::string> result;
    for (std::sregex_iterator match(source.begin(), source.end(), pattern), end;
         match != end; ++match) {
        result.emplace((*match)[1].str(), (*match)[2].str());
    }
    return result;
}

struct ConstCharPointerArrayInitializer {
    std::string reference_name;
    std::vector<std::string> target_names;
};

std::vector<ConstCharPointerArrayInitializer> FindConstCharPointerArrayInitializers(
    const std::string &source)
{
    // Keep this deliberately constrained to a flat, ordinary pointer array.
    // The generated assembly is checked before any anonymous compiler constant
    // is replaced by a named relocation.
    std::vector<ConstCharPointerArrayInitializer> result;
    static constexpr char kDeclarator[] = "char const * const";
    std::size_t at = 0;
    while ((at = source.find(kDeclarator, at)) != std::string::npos) {
        std::size_t cursor = at + sizeof(kDeclarator) - 1;
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size()
            || !(std::isalpha(static_cast<unsigned char>(source[cursor])) != 0
                || source[cursor] == '_')) {
            at = cursor;
            continue;
        }

        const std::size_t name_begin = cursor++;
        while (cursor < source.size()
            && (std::isalnum(static_cast<unsigned char>(source[cursor])) != 0
                || source[cursor] == '_')) {
            ++cursor;
        }
        const std::string name = source.substr(name_begin, cursor - name_begin);
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size() || source[cursor] != '[') {
            at = cursor;
            continue;
        }
        const std::size_t dimension_end = source.find(']', cursor + 1);
        if (dimension_end == std::string::npos) {
            at = cursor + 1;
            continue;
        }
        cursor = dimension_end + 1;
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size() || source[cursor] != '=') {
            at = cursor;
            continue;
        }
        ++cursor;
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size() || source[cursor] != '{') {
            at = cursor;
            continue;
        }
        const std::size_t entries_begin = ++cursor;
        const std::size_t entries_end = source.find('}', entries_begin);
        if (entries_end == std::string::npos) {
            at = entries_begin;
            continue;
        }

        ConstCharPointerArrayInitializer initializer;
        initializer.reference_name = name;

        bool valid = true;
        std::istringstream entries(source.substr(entries_begin, entries_end - entries_begin));
        std::string entry;
        while (std::getline(entries, entry, ',')) {
            entry = TrimWhitespace(entry);
            if (entry.empty()) {
                continue;
            } else if (entry == "nullptr" || entry == "0") {
                initializer.target_names.emplace_back();
            } else if (!entry.empty()
                && (std::isalpha(static_cast<unsigned char>(entry.front())) != 0
                    || entry.front() == '_')
                && std::all_of(entry.begin() + 1, entry.end(), [](const char value) {
                    return std::isalnum(static_cast<unsigned char>(value)) != 0 || value == '_';
                })) {
                initializer.target_names.push_back(std::move(entry));
            } else {
                valid = false;
                break;
            }
        }
        if (valid && !initializer.target_names.empty())
            result.push_back(std::move(initializer));
        at = entries_end + 1;
    }
    return result;
}

bool IsIdentifier(const std::string &value)
{
    if (value.empty()
        || !(std::isalpha(static_cast<unsigned char>(value.front())) != 0
            || value.front() == '_')) {
        return false;
    }
    return std::all_of(value.begin() + 1, value.end(), [](const char value) {
        return std::isalnum(static_cast<unsigned char>(value)) != 0 || value == '_';
    });
}

std::size_t SkipWhitespace(const std::string &source, std::size_t cursor)
{
    while (cursor < source.size()
        && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
        ++cursor;
    }
    return cursor;
}

std::size_t FindMatchingDelimiter(const std::string &source, std::size_t begin,
    char open, char close)
{
    if (begin == source.size() || source[begin] != open)
        return std::string::npos;

    std::size_t depth = 0;
    bool in_string = false;
    bool in_character = false;
    bool in_line_comment = false;
    bool in_block_comment = false;
    for (std::size_t cursor = begin; cursor < source.size(); ++cursor) {
        const char value = source[cursor];
        const char next = cursor + 1 < source.size() ? source[cursor + 1] : '\0';
        if (in_line_comment) {
            if (value == '\n')
                in_line_comment = false;
            continue;
        }
        if (in_block_comment) {
            if (value == '*' && next == '/') {
                in_block_comment = false;
                ++cursor;
            }
            continue;
        }
        if (in_string || in_character) {
            if (value == '\\') {
                ++cursor;
            } else if ((in_string && value == '"')
                || (in_character && value == '\'')) {
                in_string = false;
                in_character = false;
            }
            continue;
        }
        if (value == '/' && next == '/') {
            in_line_comment = true;
            ++cursor;
            continue;
        }
        if (value == '/' && next == '*') {
            in_block_comment = true;
            ++cursor;
            continue;
        }
        if (value == '"') {
            in_string = true;
            continue;
        }
        if (value == '\'') {
            in_character = true;
            continue;
        }
        if (value == open) {
            ++depth;
        } else if (value == close && --depth == 0) {
            return cursor;
        }
    }
    return std::string::npos;
}

std::string StripAggregateBraces(std::string value)
{
    value = TrimWhitespace(value);
    while (!value.empty() && (value.front() == '{' || value.front() == '}')) {
        value.erase(value.begin());
        value = TrimWhitespace(value);
    }
    while (!value.empty() && (value.back() == '{' || value.back() == '}')) {
        value.pop_back();
        value = TrimWhitespace(value);
    }
    return value;
}

std::vector<std::string> FlattenAggregateInitializer(const std::string &source,
    std::size_t begin, std::size_t end)
{
    std::vector<std::string> result;
    std::size_t field_begin = begin;
    std::size_t parenthesis_depth = 0;
    bool in_string = false;
    bool in_character = false;
    bool in_line_comment = false;
    bool in_block_comment = false;

    const auto append_field = [&]() {
        const std::string field = StripAggregateBraces(
            source.substr(field_begin, end - field_begin));
        if (!field.empty())
            result.push_back(field);
    };

    for (std::size_t cursor = begin; cursor < end; ++cursor) {
        const char value = source[cursor];
        const char next = cursor + 1 < end ? source[cursor + 1] : '\0';
        if (in_line_comment) {
            if (value == '\n')
                in_line_comment = false;
            continue;
        }
        if (in_block_comment) {
            if (value == '*' && next == '/') {
                in_block_comment = false;
                ++cursor;
            }
            continue;
        }
        if (in_string || in_character) {
            if (value == '\\') {
                ++cursor;
            } else if ((in_string && value == '"')
                || (in_character && value == '\'')) {
                in_string = false;
                in_character = false;
            }
            continue;
        }
        if (value == '/' && next == '/') {
            in_line_comment = true;
            ++cursor;
            continue;
        }
        if (value == '/' && next == '*') {
            in_block_comment = true;
            ++cursor;
            continue;
        }
        if (value == '"') {
            in_string = true;
            continue;
        }
        if (value == '\'') {
            in_character = true;
            continue;
        }
        if (value == '(') {
            ++parenthesis_depth;
        } else if (value == ')' && parenthesis_depth != 0) {
            --parenthesis_depth;
        } else if (value == ',' && parenthesis_depth == 0) {
            const std::string field = StripAggregateBraces(
                source.substr(field_begin, cursor - field_begin));
            if (!field.empty())
                result.push_back(field);
            field_begin = cursor + 1;
        }
    }
    append_field();
    return result;
}

struct WordOnlyAggregateInitializer {
    std::string reference_name;
    std::vector<std::string> fields;
};

std::vector<WordOnlyAggregateInitializer> FindWordOnlyAggregateInitializers(
    const std::string &source)
{
    // This is intentionally a lexical, source-order parser.  It accepts an
    // ordinary aggregate initializer only when its emitted object later proves
    // to contain precisely one .word for every source field.  That condition
    // makes it safe for pointer-bearing structure arrays without guessing any
    // field types or changing byte/halfword records.
    std::vector<WordOnlyAggregateInitializer> result;
    for (std::size_t at = 0; at < source.size();) {
        if (!(std::isalpha(static_cast<unsigned char>(source[at])) != 0
                || source[at] == '_')) {
            ++at;
            continue;
        }
        const std::size_t name_begin = at++;
        while (at < source.size()
            && (std::isalnum(static_cast<unsigned char>(source[at])) != 0
                || source[at] == '_')) {
            ++at;
        }
        const std::string name = source.substr(name_begin, at - name_begin);
        if (name.empty() || name.front() != 'g')
            continue;

        std::size_t cursor = SkipWhitespace(source, at);
        while (cursor < source.size() && source[cursor] == '[') {
            const std::size_t end = FindMatchingDelimiter(source, cursor, '[', ']');
            if (end == std::string::npos) {
                cursor = source.size();
                break;
            }
            cursor = SkipWhitespace(source, end + 1);
        }
        while (cursor < source.size()) {
            const std::size_t attribute_begin = cursor;
            while (cursor < source.size()
                && (std::isalnum(static_cast<unsigned char>(source[cursor])) != 0
                    || source[cursor] == '_')) {
                ++cursor;
            }
            const std::string attribute = source.substr(attribute_begin,
                cursor - attribute_begin);
            if (attribute != "ALIGN" && attribute != "SECTION"
                && attribute != "__attribute__") {
                cursor = attribute_begin;
                break;
            }
            cursor = SkipWhitespace(source, cursor);
            if (cursor == source.size() || source[cursor] != '(') {
                cursor = attribute_begin;
                break;
            }
            const std::size_t end = FindMatchingDelimiter(source, cursor, '(', ')');
            if (end == std::string::npos) {
                cursor = source.size();
                break;
            }
            cursor = SkipWhitespace(source, end + 1);
        }
        if (cursor == source.size() || source[cursor] != '=')
            continue;
        cursor = SkipWhitespace(source, cursor + 1);
        if (cursor == source.size() || source[cursor] != '{')
            continue;
        const std::size_t end = FindMatchingDelimiter(source, cursor, '{', '}');
        if (end == std::string::npos)
            continue;

        std::vector<std::string> fields = FlattenAggregateInitializer(source,
            cursor + 1, end);
        if (!fields.empty())
            result.push_back({ name, std::move(fields) });
        at = end + 1;
    }
    return result;
}

std::vector<std::size_t> FindObjectWordInitializers(
    const std::vector<std::string> &lines, std::size_t label_index)
{
    std::vector<std::size_t> result;
    static const std::regex global_pattern(
        R"(^[\t ]*\.(?:globl|global)[\t ]+[A-Za-z_][A-Za-z0-9_]*[\t ]*$)");
    for (std::size_t index = label_index + 1; index < lines.size(); ++index) {
        if (std::regex_match(lines[index], global_pattern))
            break;
        if (Trim(lines[index]).rfind(".word", 0) == 0)
            result.push_back(index);
    }
    return result;
}

void FixupConstCharPointerWord(std::vector<std::string> &lines,
    std::size_t word_index, const std::string &reference_name,
    const std::string &target_name,
    std::vector<std::pair<std::size_t, std::size_t>> &removals,
    std::set<std::string> &removed_local_constants)
{
    if (word_index == lines.size())
        throw std::runtime_error("missing initializer for '" + reference_name + "'");

    const std::string word = Trim(lines[word_index]);
    static constexpr std::string_view kWord = ".word";
    if (word.rfind(kWord, 0) != 0)
        throw std::runtime_error("expected .word initializer for '" + reference_name + "'");
    const std::string local_constant = Trim(word.substr(kWord.size()));
    if (local_constant.rfind(".LC", 0) != 0)
        return;

    const std::size_t local_label = FindAssemblyLabel(lines, local_constant);
    const std::size_t target_label = FindAssemblyLabel(lines, target_name);
    if (local_label == std::string::npos || target_label == std::string::npos) {
        throw std::runtime_error("cannot resolve compiler constant for '"
            + reference_name + "'");
    }

    const std::vector<std::string> local_payload =
        AssemblyStringPayloadAfter(lines, local_label);
    const std::vector<std::string> target_payload =
        AssemblyStringPayloadAfter(lines, target_label);
    if (local_payload.empty() || local_payload != target_payload) {
        throw std::runtime_error("compiler constant for '" + reference_name
            + "' does not exactly duplicate '" + target_name + "'");
    }

    const std::size_t local_end = local_label + 1 + local_payload.size();
    if (local_end == lines.size() || !IsAssemblyAlign(lines[local_end])) {
        throw std::runtime_error("unexpected compiler-constant layout for '"
            + reference_name + "'");
    }

    const std::size_t indent_end = lines[word_index].find_first_not_of(" \t");
    const std::string indent = indent_end == std::string::npos
        ? "" : lines[word_index].substr(0, indent_end);
    lines[word_index] = indent + ".word\t" + target_name;
    if (removed_local_constants.insert(local_constant).second)
        removals.emplace_back(local_label, local_end);
}

std::string FixupSameUnitConstCharReferences(const std::string &source,
    const std::string &assembly)
{
    const std::map<std::string, std::string> references =
        FindDirectConstCharPointerInitializers(source);
    const std::vector<ConstCharPointerArrayInitializer> arrays =
        FindConstCharPointerArrayInitializers(source);
    const std::vector<WordOnlyAggregateInitializer> aggregates =
        FindWordOnlyAggregateInitializers(source);
    if (references.empty() && arrays.empty() && aggregates.empty())
        return assembly;

    std::vector<std::string> lines = SplitLines(assembly);
    std::vector<std::pair<std::size_t, std::size_t>> removals;
    std::set<std::string> removed_local_constants;

    for (const WordOnlyAggregateInitializer &aggregate : aggregates) {
        const std::size_t reference_label = FindAssemblyLabel(lines,
            aggregate.reference_name);
        if (reference_label == std::string::npos)
            continue;

        const std::vector<std::size_t> words = FindObjectWordInitializers(lines,
            reference_label);
        if (words.size() != aggregate.fields.size())
            continue;

        for (std::size_t index = 0; index < words.size(); ++index) {
            const std::string target_name = TrimWhitespace(aggregate.fields[index]);
            if (!IsIdentifier(target_name)
                || FindAssemblyLabel(lines, target_name) == std::string::npos
                || AssemblyStringPayloadAfter(lines,
                       FindAssemblyLabel(lines, target_name)).empty()) {
                continue;
            }
            const std::string reference = aggregate.reference_name + "["
                + std::to_string(index) + "]";
            FixupConstCharPointerWord(lines, words[index], reference, target_name,
                removals, removed_local_constants);
        }
    }

    for (const auto &[reference_name, target_name] : references) {
        const std::size_t reference_label = FindAssemblyLabel(lines, reference_name);
        if (reference_label == std::string::npos)
            continue;

        std::size_t word_index = reference_label + 1;
        while (word_index < lines.size() && Trim(lines[word_index]).empty())
            ++word_index;
        FixupConstCharPointerWord(lines, word_index, reference_name, target_name,
            removals, removed_local_constants);
    }

    for (const ConstCharPointerArrayInitializer &array : arrays) {
        const std::size_t reference_label = FindAssemblyLabel(lines, array.reference_name);
        if (reference_label == std::string::npos)
            continue;

        std::size_t word_index = reference_label + 1;
        for (std::size_t index = 0; index < array.target_names.size(); ++index) {
            while (word_index < lines.size() && Trim(lines[word_index]).empty())
                ++word_index;
            const std::string reference = array.reference_name + "["
                + std::to_string(index) + "]";
            if (array.target_names[index].empty()) {
                if (word_index == lines.size()
                    || Trim(lines[word_index]).rfind(".word", 0) != 0) {
                    throw std::runtime_error("expected .word initializer for '" + reference + "'");
                }
            } else {
                FixupConstCharPointerWord(lines, word_index, reference,
                    array.target_names[index], removals, removed_local_constants);
            }
            ++word_index;
        }
    }

    std::sort(removals.rbegin(), removals.rend());
    for (const auto &[begin, end] : removals)
        lines.erase(lines.begin() + static_cast<std::ptrdiff_t>(begin),
            lines.begin() + static_cast<std::ptrdiff_t>(end));
    return JoinLines(lines);
}

std::string AlignExecutableSections(const std::string &assembly)
{
    // This is the former align_sections.sh policy, now applied by the same
    // generic pass that repairs relocations.  It only closes executable
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

std::string PreprocessAssembly(const std::string &source, const std::string &assembly)
{
    return AlignExecutableSections(FixupSameUnitConstCharReferences(source, assembly));
}

void Require(bool condition, const std::string &message)
{
    if (!condition)
        throw std::runtime_error("self-test failed: " + message);
}

void SelfTest()
{
    const std::string source =
        "char const gNamedByteSequence[] = \"A\";\n"
        "char const * const gPointerToNamedByteSequence = gNamedByteSequence;\n"
        "char const * const gNamedPointers[] = {\n"
        "    gNamedByteSequence,\n"
        "    gNamedByteSequence,\n"
        "};\n"
        "struct NamedPointerPair { unsigned int kind; char const *text; "
        "unsigned int value; char const *repeat; };\n"
        "NamedPointerPair const gNamedPointerPairs[] = {\n"
        "    { 0, gNamedByteSequence, 1, gNamedByteSequence },\n"
        "};\n";
    const std::string assembly =
        "\t.section .rodata.sample,\"a\",%progbits\n"
        "gNamedByteSequence:\n"
        "\t.ascii\t\"A\\000\"\n"
        ".LC0:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.align\t2, 0\n"
        "gPointerToNamedByteSequence:\n"
        "\t.word\t.LC0\n"
        ".LC1:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.align\t2, 0\n"
        "gNamedPointers:\n"
        "\t.word\t.LC1\n"
        "\t.word\t.LC1\n"
        ".LC2:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.align\t2, 0\n"
        "gNamedPointerPairs:\n"
        "\t.word\t0\n"
        "\t.word\t.LC2\n"
        "\t.word\t1\n"
        "\t.word\t.LC2\n"
        "\t.section .text.sample,\"ax\",%progbits\n"
        "sample_function:\n"
        "\tbx\tlr\n";

    const std::string output = PreprocessAssembly(source, assembly);
    Require(output.find(".LC0:") == std::string::npos
            && output.find(".LC1:") == std::string::npos
            && output.find(".LC2:") == std::string::npos,
        "duplicate compiler string constants were retained");
    Require(output.find(".word\tgNamedByteSequence") != std::string::npos,
        "named text relocation was not restored");
    Require(output.find("\t.section \".text.sample\"\n\t.align 2, 0\n") != std::string::npos,
        "executable section alignment was not appended");
    Require(output.find("\t.section \".rodata.sample\"") == std::string::npos,
        "ordinary rodata was given an implicit text-section alignment");
}

const char *Usage()
{
    return "usage:\n"
           "  fomt-preproc self-test\n"
           "  fomt-preproc asm SOURCE ASSEMBLY\n";
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
