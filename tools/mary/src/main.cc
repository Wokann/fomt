#include "analyse.hh"
#include "bytecode.hh"
#include "decompiler.hh"
#include "driver.hh"
#include "legacy.hh"
#include "low_level.hh"
#include "pretty.hh"
#include "rom_import.hh"
#include "symbols.hh"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <stdexcept>
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define WIN32_LEAN_AND_MEAN
#include <fcntl.h>
#include <io.h>
#include <windows.h>

#include <shellapi.h>
#else
#include <unistd.h>
#endif

namespace mary
{
namespace
{

struct Arguments
{
    std::string command;
    std::vector<std::string> positional, defines;
    std::map<std::string, std::string> values;
    std::set<std::string> flags;
    bool flag(const std::string &name) const
    {
        return flags.count(name) != 0;
    }
    std::optional<fs::path> path(const std::string &name) const
    {
        auto found = values.find(name);
        return found == values.end() ? std::nullopt
                                     : std::optional<fs::path>(fs::u8path(found->second));
    }
    std::optional<std::size_t> number(const std::string &name) const;
};
std::size_t number(const std::string &value)
{
    if (value.empty() || value.front() == '-')
        throw std::runtime_error("invalid nonnegative offset or ID: " + value);
    std::size_t used = 0;
    auto parsed = std::stoull(
        value,
        &used,
        value.size() > 2 && (value.substr(0, 2) == "0x" || value.substr(0, 2) == "0X") ? 16 : 10);
    if (used != value.size() || parsed > SIZE_MAX)
        throw std::runtime_error("invalid offset or ID: " + value);
    return std::size_t(parsed);
}
std::optional<std::size_t> Arguments::number(const std::string &name) const
{
    auto found = values.find(name);
    return found == values.end() ? std::nullopt
                                 : std::optional<std::size_t>(mary::number(found->second));
}
Arguments arguments(const std::vector<std::string> &input)
{
    Arguments result;
    bool positional_only = false;
    const std::set<std::string> values{ "output",
                                        "charmap",
                                        "library",
                                        "script-table",
                                        "source-map",
                                        "constants",
                                        "symbols",
                                        "text-names",
                                        "script-id",
                                        "offset",
                                        "pointer-table",
                                        "pointer-count",
                                        "address",
                                        "relocate-pointer-table",
                                        "layout" };
    const std::set<std::string> flags{ "binary",  "print-ir",      "mary-c", "all",    "force",
                                       "dry-run", "vanilla-names", "help",   "version" };
    for (std::size_t i = 1; i < input.size(); ++i)
    {
        auto item = input[i];
        auto next = [&]()
        {
            if (++i == input.size())
                throw std::runtime_error("missing value after " + item);
            return input[i];
        };
        if (item == "--" && !positional_only)
        {
            positional_only = true;
            continue;
        }
        if (!positional_only && (item == "-D" || item == "--define"))
        {
            result.defines.push_back(next());
            continue;
        }
        if (!positional_only && item.size() > 2 && item.substr(0, 2) == "-D")
        {
            result.defines.push_back(item.substr(2));
            continue;
        }
        if (!positional_only && item.substr(0, 9) == "--define=")
        {
            result.defines.push_back(item.substr(9));
            continue;
        }
        if (!positional_only && (item == "-o" || item == "-h" || item == "-V"))
            item = item == "-o" ? "--output" : item == "-h" ? "--help" : "--version";
        if (!positional_only && item.substr(0, 2) == "--")
        {
            auto eq = item.find('=');
            auto name = item.substr(2, eq == std::string::npos ? std::string::npos : eq - 2);
            if (values.count(name))
            {
                auto value = eq == std::string::npos ? next() : item.substr(eq + 1);
                if (name == "text-names")
                    name = "symbols";
                if (!result.values.emplace(name, value).second)
                    throw std::runtime_error("option repeated: --" + name);
            }
            else if (flags.count(name) && eq == std::string::npos)
                result.flags.insert(name);
            else
                throw std::runtime_error("unknown option: " + item);
        }
        else if (!positional_only && !item.empty() && item.front() == '-')
            throw std::runtime_error("unknown option: " + item);
        else if (result.command.empty())
            result.command = item;
        else
            result.positional.push_back(item);
    }
    return result;
}
void help()
{
    std::cout
        << "Mary: portable C++17 script compiler and decompiler\n\n"
           "mary compile [source] [-o output] [--binary] [--mary-c] [--library path]\n"
           "mary bundle source-directory -o output-directory [--layout packed|split]\n"
           "mary decompile input [library] [-o output] [--all | --script-id ID | --offset N]\n"
           "mary import input-rom source -o output-rom [--script-id ID] [--address N]\n"
           "mary analyse-callable-shapes input-rom [-o output]\n"
           "mary generate-script-table symbols MARY_TARGET output\n"
           "mary generate-symbols fomt-jp fomt-us fomt-eu fomt-de mfomt-jp mfomt-us output-dir\n\n"
           "Common: --charmap path, -D NAME[=VALUE], --constants path, --script-table path.\n"
           "Compile: --print-ir adds an instruction listing to C-array output.\n"
           "  --source-map FILE with --mary-c --binary writes line and condition metadata.\n"
           "  Use --source-map - to write this metadata to stderr.\n"
           "Decompile: --mary-c selects .mary.c; --print-ir adds a listing.\n"
           "  Default: neutral script/variable/callable IDs, with lossless numbered IR\n"
           "  when callable shapes are unavailable. --library explicitly supplies shapes.\n"
           "  --vanilla-names opts into the original game's names/constants. Optional\n"
           "  --symbols path overrides the original adaptation's text/local metadata.\n"
           "  --pointer-table N --pointer-count N select a modified ROM's script table.\n"
           "Import: --relocate-pointer-table N, --force, --dry-run. Input ROM is never "
           "overwritten.\n";
}
Options options(const std::vector<std::string> &defines)
{
    Options result;
    for (auto &d : defines)
        result.define(d);
    return result;
}
std::optional<Charmap> charmap(const Arguments &args, const Options &opts)
{
    auto path = args.path("charmap");
    return path ? std::optional<Charmap>(Charmap::parse(preprocess_charmap(read_text(*path), opts)))
                : std::nullopt;
}
void output(const Arguments &args, const std::string &text)
{
    if (auto path = args.path("output"))
        write_text(*path, text);
    else
        std::cout << text;
}
void output(const Arguments &args, const Bytes &bytes)
{
    if (auto path = args.path("output"))
        write_binary(*path, bytes);
    else
    {
#ifdef _WIN32
        _setmode(_fileno(stdout), _O_BINARY);
#endif
        std::cout.write(reinterpret_cast<const char *>(bytes.data()),
                        std::streamsize(bytes.size()));
        if (!std::cout)
            throw std::runtime_error("failed writing binary stdout");
    }
}
SourceRequest request(const Arguments &args, const fs::path &input)
{
    return { input,
             args.path("library"),
             args.path("script-table"),
             args.path("constants"),
             args.path("charmap"),
             args.defines };
}
std::string ir_comment(const Script &script, const Charmap *map)
{
    return "/* Script instructions and strings (IR):\n" + format_ir(script, 1, map) + "*/\n";
}

void write_source_map(const fs::path &path, const NamedScript &script,
                      const ConstScope &scope, const Charmap *map,
                      const std::vector<CodeSource> &locations)
{
    const auto type_name = [](const ValueType &type) -> std::string
    {
        switch (type.kind)
        {
            case ValueType::Undefined: return "void";
            case ValueType::Integer: return "int";
            case ValueType::String: return "const char*";
            case ValueType::User: return type.name;
        }
        throw std::runtime_error("invalid callable type");
    };
    std::ostringstream out;
    out << "MARY-SOURCE-MAP\t1\t" << script.id << '\t' << script.name << '\n';
    for (const auto &location : locations)
    {
        out << "code\t" << location.pc << '\t' << location.line;
        if (location.condition_start != SIZE_MAX)
            out << '\t' << location.condition_start << '\t' << location.jump_on_true;
        out << '\n';
    }
    for (const auto &entry : scope.callables)
    {
        const auto &call = entry.second;
        out << "call\t" << call.id << '\t' << entry.first << '\t' << call.is_function() << '\t';
        for (const auto &type : call.parameters)
            out << (type.kind == ValueType::String ? 's' : 'i');
        out << '\t' << type_name(call.return_type);
        for (const auto &type : call.parameters)
            out << '\t' << type_name(type);
        out << '\n';
    }
    for (const auto &entry : scope.constants)
        if (entry.first.compare(0, 4, "VAR_") == 0 ||
            entry.first.compare(0, 10, "AUDIO_BGM_") == 0)
            if (const auto *value = std::get_if<Integer>(&entry.second))
                out << (entry.first.compare(0, 4, "VAR_") == 0 ? "var\t" : "bgm\t")
                    << *value << '\t' << entry.first << '\n';
    for (std::size_t id = 0; id < script.script.strings.size(); ++id)
    {
        const auto &bytes = script.script.strings[id];
        out << "text\t" << id << '\t';
        for (std::size_t at = 0; at < bytes.size();)
        {
            std::string text;
            const auto decoded = map ? map->decode_one(bytes, at) : std::nullopt;
            if (decoded)
            {
                text = decoded->second;
                at += decoded->first;
            }
            else
                text = "{0x" + hex(bytes[at++], 2) + "}";
            for (unsigned char ch : text)
                out << hex(ch, 2);
        }
        out << '\n';
    }
    if (path == fs::path("-"))
        std::cerr << out.str();
    else
        write_text(path, out.str());
}

void compile(const Arguments &args)
{
    if (args.positional.size() > 1)
        throw std::runtime_error("compile accepts one source file or stdin");
    fs::path base;
    std::string source;
    if (args.positional.empty())
        source = std::string((std::istreambuf_iterator<char>(std::cin)), {});
    else
    {
        auto path = fs::u8path(args.positional[0]);
        base = path.parent_path();
        source = read_text(path);
    }
    auto opts = args.flag("mary-c") ? source_options(args.defines, source) : options(args.defines);
    auto map = charmap(args, opts);
    const auto source_map = args.path("source-map");
    if (source_map && (!args.flag("mary-c") || !args.flag("binary")))
        throw std::runtime_error("--source-map requires --mary-c --binary");
    std::optional<ConstScope> debug_scope;
    std::vector<NamedScript> scripts;
    if (args.flag("mary-c"))
    {
        auto includes = extract_includes(source);
        ConstScope scope;
        std::optional<ScriptTable> table;
        auto resolve = [&](fs::path path) { return path.is_absolute() ? path : base / path; };
        auto library = args.path("library"), constants = args.path("constants"),
             script_table = args.path("script-table");
        auto names = header_names(*selected_target(opts));
        for (auto &include : includes)
        {
            if ((library && include.filename() == fs::u8path(names.callables)) ||
                (constants && include.filename() == fs::u8path(names.constants)) ||
                (script_table && include.filename() == fs::u8path(names.scripts)))
                continue;
            auto path = resolve(include);
            auto text = read_text(path);
            if (text.find("mary_callable_table") != std::string::npos)
            {
                if (!library)
                    library = include;
            }
            else if (text.find("mary_script_table") != std::string::npos)
            {
                if (!script_table)
                    script_table = include;
            }
            else if (!constants)
                constants = include;
            else
                throw std::runtime_error("include is not a recognized Mary header: " +
                                         path.u8string());
        }
        if (constants)
            scope = parse_constant_header(read_text(resolve(*constants)), opts);
        if (library)
            scope = parse_callable_table(read_text(resolve(*library)), opts, scope).scope;
        if (script_table)
            table = parse_script_table(read_text(resolve(*script_table)), opts);
        scripts =
            parse_mary_c(source, opts, scope, table ? &*table : nullptr, map ? &*map : nullptr);
        if (source_map)
            debug_scope = std::move(scope);
    }
    else
    {
        ConstScope scope;
        if (auto library = args.path("library"))
            scope = parse_legacy(read_text(*library), map ? &*map : nullptr, {}, false).scope;
        scripts = parse_legacy(source, map ? &*map : nullptr, scope).scripts;
    }
    if (args.flag("binary"))
    {
        if (scripts.size() != 1)
            throw std::runtime_error("binary output requires exactly one script");
        std::vector<CodeSource> locations;
        const auto bytes = encode_script(scripts[0].script, source_map ? &locations : nullptr);
        if (source_map)
            write_source_map(*source_map, scripts[0], *debug_scope, map ? &*map : nullptr, locations);
        output(args, bytes);
        return;
    }
    std::ostringstream out;
    for (auto &script : scripts)
    {
        auto bytes = encode_script(script.script);
        if (args.flag("print-ir"))
            out << ir_comment(script.script, map ? &*map : nullptr) << '\n';
        out << "// " << script.name << ": length of " << bytes.size()
            << " bytes (+ padding)\nunsigned int const " << script.name << "[] = {";
        for (std::size_t i = 0; i < bytes.size(); i += 4)
        {
            std::uint32_t value = 0;
            for (unsigned n = 0; n < 4 && i + n < bytes.size(); ++n)
                value |= std::uint32_t(bytes[i + n]) << (8 * n);
            if ((i / 4) % 8 == 0)
                out << "\n   ";
            out << " 0x" << hex(value, 8) << ',';
        }
        out << "\n};\n";
    }
    output(args, out.str());
}
bool interactive()
{
#ifdef _WIN32
    return _isatty(_fileno(stdin)) != 0;
#else
    return isatty(STDIN_FILENO) != 0;
#endif
}
void confirm(const std::string &message, bool force)
{
    if (force)
        return;
    if (!interactive())
        throw std::runtime_error(message +
                                 "; confirmation requires an interactive terminal or --force");
    std::cerr << message << " [y/N] ";
    std::string answer;
    std::getline(std::cin, answer);
    std::transform(answer.begin(),
                   answer.end(),
                   answer.begin(),
                   [](unsigned char c) { return char(std::tolower(c)); });
    if (answer != "y" && answer != "yes")
        throw std::runtime_error("cancelled");
}
void import_rom(const Arguments &args)
{
    if (args.positional.size() != 2 || !args.path("output"))
        throw std::runtime_error("import requires input ROM, source and -o output ROM");
    auto input = fs::u8path(args.positional[0]), source = fs::u8path(args.positional[1]),
         destination = *args.path("output");
    bool directory = fs::is_directory(source);
    auto id = args.number("script-id");
    if (directory == id.has_value())
        throw std::runtime_error(
            "import requires a directory without --script-id or one source file with --script-id");
    if (fs::exists(destination) && fs::equivalent(input, destination))
        throw std::runtime_error("input and output ROM must be different files");
    auto table = args.number("pointer-table"), count = args.number("pointer-count");
    if (table.has_value() != count.has_value())
        throw std::runtime_error("--pointer-table and --pointer-count must be specified together");
    auto compiled = compile_sources(request(args, source));
    auto rom = read_binary(input);
    auto native = identify_rom(rom);
    if (!native || native->target != compiled.target)
        throw std::runtime_error("source target differs from ROM header");
    auto aligned_offset = [](std::size_t value)
    {
        auto offset = normalize_rom_offset(value);
        if (offset % 4)
            throw std::runtime_error("import addresses must be aligned to four bytes");
        return offset;
    };
    auto layout = resolve_script_layout(rom,
                                        table ? std::optional<std::pair<std::size_t, std::size_t>>(
                                                    { aligned_offset(*table), *count })
                                              : std::nullopt);
    auto address = args.number("address"), relocated = args.number("relocate-pointer-table");
    if (address)
        address = aligned_offset(*address);
    if (relocated)
        relocated = aligned_offset(*relocated);
    std::vector<std::string> warnings;
    auto planned = rom;
    auto warn = [&](Range range, const std::string &label)
    {
        if (auto occupied = range_occupancy(rom, range))
            warnings.push_back(label + " contains data at 0x" + hex(occupied->first, 8));
    };
    if (id)
    {
        if (relocated)
            throw std::runtime_error("single-script import cannot relocate the pointer table");
        auto script = compiled.scripts.find(*id);
        if (compiled.scripts.size() != 1 || script == compiled.scripts.end())
            throw std::runtime_error("source must define exactly the requested script ID");
        auto written = address
                           ? write_single_script_at(planned, layout, *id, script->second, *address)
                           : write_single_script_in_place(planned, layout, *id, script->second);
        if (address)
            warn(written, "script destination");
        std::cout << "Script " << *id << " write: 0x" << hex(written.start, 8) << "..0x"
                  << hex(written.end, 8) << '\n';
    }
    else
    {
        if (!layout.metadata_present && !relocated)
            layout.slot_count = infer_pointer_count(rom, layout);
        if (relocated && *relocated == layout.pointer_table_offset &&
            compiled.table.slots.size() != layout.slot_count)
            throw std::runtime_error("an expanded pointer table must use a new address");
        std::vector<std::optional<Bytes>> slots(compiled.table.slots.size());
        for (auto &script : compiled.scripts)
            slots.at(script.first) = script.second;
        auto packed = PackedScripts::from_slots(slots);
        if (!address)
        {
            if (!layout.script_area)
                throw std::runtime_error("scripts are not contiguous; specify a new --address");
            if (packed.bytes.size() > layout.script_area->size())
                throw std::runtime_error(
                    "compiled scripts exceed the original area; specify a new --address");
            address = layout.script_area->start;
        }
        if (!relocated && slots.size() > layout.slot_count)
        {
            Range extension{ layout.pointer_table_offset + layout.slot_count * 4,
                             layout.pointer_table_offset + slots.size() * 4 };
            if (auto conflict = pointer_extension_conflict(rom, extension))
            {
                auto message = "pointer-table extension would overwrite non-pointer data at 0x" +
                               hex(conflict->first, 8);
                if (!args.flag("force") && !args.flag("dry-run"))
                    throw std::runtime_error(message + "; use --force to authorize this range");
                warnings.push_back(message);
            }
        }
        auto written = write_packed_scripts(planned, layout, packed, *address, relocated);
        if (args.number("address"))
            warn(written.first, "packed script destination");
        if (relocated)
            warn(written.second, "pointer-table destination");
        std::cout << "Packed scripts: " << slots.size() << " slots, 0x"
                  << hex(written.first.start, 8) << "..0x" << hex(written.first.end, 8)
                  << "\nPointer table: 0x" << hex(written.second.start, 8) << "..0x"
                  << hex(written.second.end, 8) << '\n';
    }
    for (auto &warning : warnings)
        std::cerr << "warning: " << warning << '\n';
    if (!warnings.empty() && !args.flag("dry-run"))
        confirm("Continue with these occupied destinations?", args.flag("force"));
    if (args.flag("dry-run"))
    {
        std::cout << "Dry run complete; no ROM written.\n";
        return;
    }
    if (fs::exists(destination))
        confirm("Output ROM already exists. Overwrite?", args.flag("force"));
    write_rom_atomically(destination, planned);
    std::cout << "Wrote ROM copy: " << destination.u8string() << '\n';
}

fs::path tool_directory(const std::string &executable)
{
    auto path = fs::u8path(executable);
    if (path.has_parent_path())
        return fs::absolute(path).parent_path();
    if (auto search = std::getenv("PATH"))
    {
        std::string paths(search);
#ifdef _WIN32
        char separator = ';';
#else
        char separator = ':';
#endif
        std::size_t start = 0;
        do
        {
            auto end = paths.find(separator, start);
            auto candidate =
                fs::u8path(paths.substr(start, end == std::string::npos ? end : end - start)) /
                path;
            if (fs::is_regular_file(candidate))
                return fs::absolute(candidate).parent_path();
            if (end == std::string::npos)
                break;
            start = end + 1;
        } while (start <= paths.size());
    }
    return fs::current_path();
}
fs::path adaptation_file(const fs::path &tool, const std::string &name)
{
    for (auto root : { tool / fs::path("goodies"), fs::current_path() / "goodies" })
        if (fs::is_regular_file(root / fs::u8path(name)))
            return root / fs::u8path(name);
    throw std::runtime_error("original adaptation is unavailable: " + name +
                             "; provide the matching header path explicitly");
}
ConstScope generic_scope(const ConstScope &source)
{
    ConstScope result;
    for (auto &entry : source.callables)
    {
        auto callable = entry.second;
        for (auto &type : callable.parameters)
            if (type.kind == ValueType::User)
                type = ValueType::Integer;
        if (callable.return_type.kind == ValueType::User)
            callable.return_type = ValueType::Integer;
        auto name = (callable.is_function() ? "func_" : "proc_") + std::to_string(callable.id);
        result.callables[name] = std::move(callable);
    }
    return result;
}
std::string callable_header(const ConstScope &scope)
{
    std::map<std::uint32_t, std::pair<std::string, Callable>> calls;
    for (auto &entry : scope.callables)
        calls[entry.second.id] = entry;
    std::string out = "mary_callable_table\n{\n";
    if (!calls.empty())
        for (std::uint64_t id = 0; id <= calls.rbegin()->first; ++id)
        {
            auto found = calls.find(std::uint32_t(id));
            out += "    " + (found == calls.end() ? "NULL" : found->second.first) + ",\n";
        }
    out += "};\n\n";
    for (auto &entry : calls)
    {
        auto &call = entry.second.second;
        out += (call.is_function() ? "int " : "void ") + entry.second.first + "(";
        if (call.parameters.empty())
            out += "void";
        for (std::size_t i = 0; i < call.parameters.size(); ++i)
        {
            if (i)
                out += ", ";
            out += (call.parameters[i].kind == ValueType::String ? "const char *" : "int ") +
                   std::string("arg_") + std::to_string(i);
        }
        out += ");\n";
    }
    return out;
}
struct DecompileEntry
{
    std::size_t id;
    std::optional<Script> script;
};
void decompile(const Arguments &args, const fs::path &tool)
{
    if (args.positional.empty() || args.positional.size() > 2)
        throw std::runtime_error("decompile requires input and optionally a callable library");
    auto bytes = read_binary(fs::u8path(args.positional[0]));
    auto native = identify_rom(bytes);
    auto opts = options(args.defines);
    if (native)
    {
        if (auto selected = selected_target(opts); selected && *selected != native->target)
            throw std::runtime_error("selected target differs from ROM header");
        opts.define(native->target);
    }
    auto target = selected_target(opts);
    if (args.flag("mary-c") && !target)
        throw std::runtime_error(
            "Mary-C export requires one MARY_* target or a recognized ROM header");
    auto names = header_names(target ? *target : "");
    auto map = charmap(args, opts);
    bool vanilla = args.flag("vanilla-names");
    auto library = args.path("library"), constants = args.path("constants");
    if (args.positional.size() == 2)
    {
        if (library)
            throw std::runtime_error("supply the callable library only once");
        library = fs::u8path(args.positional[1]);
    }
    if (vanilla && !target)
        throw std::runtime_error(
            "--vanilla-names requires a recognized ROM or an explicit MARY_* target");
    if (vanilla && !library)
        library = adaptation_file(tool, names.callables);
    if (vanilla && !constants)
    {
        auto candidate = library->parent_path() / names.constants;
        constants =
            fs::is_regular_file(candidate) ? candidate : adaptation_file(tool, names.constants);
    }
    ConstScope scope;
    std::string library_source, constant_source;
    if (constants && vanilla)
    {
        constant_source = read_text(*constants);
        scope = parse_constant_header(constant_source, opts);
    }
    if (library)
    {
        library_source = read_text(*library);
        scope = library_source.find("mary_callable_table") != std::string::npos
                    ? parse_callable_table(library_source, opts, scope).scope
                    : parse_legacy(library_source, map ? &*map : nullptr, scope, false).scope;
    }
    std::optional<ScriptSymbols> symbols;
    std::optional<ScriptTable> named_table;
    if (vanilla)
    {
        auto symbols_path = args.path("symbols");
        if (!symbols_path)
        {
            auto candidate = library->parent_path() / names.symbols;
            if (fs::is_regular_file(candidate))
                symbols_path = candidate;
            else
                try
                {
                    symbols_path = adaptation_file(tool, names.symbols);
                }
                catch (const std::exception &)
                {
                }
        }
        if (symbols_path)
        {
            symbols = parse_text_name_table(read_text(*symbols_path), opts);
            named_table = symbols->script_table();
        }
        else if (auto path = args.path("script-table"))
            named_table = parse_script_table(read_text(*path), opts);
        if (named_table)
            named_table->add_constants(scope);
    }
    else
        scope = generic_scope(scope);
    auto table = args.number("pointer-table"), count = args.number("pointer-count"),
         offset = args.number("offset"), id = args.number("script-id");
    if (table.has_value() != count.has_value())
        throw std::runtime_error("--pointer-table and --pointer-count must be supplied together");
    if (offset && (id || table || args.flag("all")))
        throw std::runtime_error("--offset cannot be combined with table selection or --all");
    if (args.flag("all") && id)
        throw std::runtime_error("--all cannot be combined with --script-id");
    std::vector<DecompileEntry> entries;
    ScriptTable output_table;
    if (args.flag("all") || id)
    {
        auto layout =
            resolve_script_layout(bytes,
                                  table ? std::optional<std::pair<std::size_t, std::size_t>>(
                                              { normalize_rom_offset(*table), *count })
                                        : std::nullopt);
        if (named_table)
        {
            if (named_table->slots.size() != layout.scripts.size())
                throw std::runtime_error("original symbol table and ROM slot counts differ; use "
                                         "neutral export for this modification");
            for (std::size_t i = 0; i < layout.scripts.size(); ++i)
                if (named_table->slots[i].has_value() != layout.scripts[i].has_value())
                    throw std::runtime_error("original symbols and ROM have different NULL slots");
        }
        for (std::size_t i = 0; i < layout.scripts.size(); ++i)
        {
            auto &where = layout.scripts[i];
            output_table.slots.push_back(
                where ? std::optional<std::string>(named_table ? *named_table->slots[i]
                                                               : "script_" + std::to_string(i))
                      : std::nullopt);
            if (id && *id != i)
                continue;
            if (!where)
            {
                entries.push_back({ i, std::nullopt });
                continue;
            }
            Bytes riff(bytes.begin() + where->offset,
                       bytes.begin() + where->offset + where->riff_length);
            Bytes backing(bytes.begin() + where->offset, bytes.end());
            entries.push_back({ i, decode_script(riff, backing) });
        }
        if (id && *id >= layout.scripts.size())
            throw std::runtime_error("script ID is outside the pointer table");
    }
    else
    {
        auto at = offset ? normalize_rom_offset(*offset) : 0;
        if (at > bytes.size())
            throw std::runtime_error("offset is outside input");
        Bytes backing(bytes.begin() + at, bytes.end());
        entries.push_back({ 0, decode_script(backing) });
        output_table.slots.push_back(std::string("script_0"));
    }
    auto destination = args.path("output");
    if (args.flag("all") && !destination)
        throw std::runtime_error("--all requires -o output-directory");
    std::optional<fs::path> directory;
    if (destination)
    {
        directory = args.flag("all") ? *destination : destination->parent_path();
        if (directory->empty())
            *directory = ".";
        fs::create_directories(*directory);
    }
    bool raw = scope.callables.empty();
    std::string includes;
    if (args.flag("mary-c"))
    {
        includes = "#define " + *target + "\n";
        if (directory)
        {
            write_text(*directory / names.constants,
                       vanilla ? constant_source
                               : "/* Neutral export has no original named constants. */\n");
            write_text(*directory / names.callables,
                       vanilla ? library_source : callable_header(scope));
            write_text(*directory / names.scripts, render_script_table(output_table));
            includes += "#include \"" + names.constants + "\"\n#include \"" + names.callables +
                        "\"\n#include \"" + names.scripts + "\"\n\n";
        }
        else if (vanilla)
        {
            if (constants)
                includes += "#include \"" + assembler_path(*constants) + "\"\n";
            if (library)
                includes += "#include \"" + assembler_path(*library) + "\"\n";
            includes += '\n';
        }
    }
    else if (vanilla && library)
        includes = "#include \"" + assembler_path(*library) + "\"\n\n";
    for (auto &entry : entries)
    {
        std::string name = output_table.slots[entry.id] ? *output_table.slots[entry.id]
                                                        : "script_" + std::to_string(entry.id);
        std::string text = includes;
        if (!entry.script)
            text += "/* Script slot " + std::to_string(entry.id) + " is NULL. */\n";
        else if (raw)
        {
            text += args.flag("mary-c") ? "mary_script(" + std::to_string(entry.id) + ") void " +
                                              name + "(void)\n{\n    mary_ir\n    {\n"
                                        : "script " + std::to_string(entry.id) + " " + name +
                                              "\n{\n    ir\n    {\n";
            text += format_ir(*entry.script, 2, map ? &*map : nullptr) + "    }\n}\n";
        }
        else
        {
            std::vector<std::optional<std::string>> text_names;
            std::map<std::string, ValueType> local_types;
            if (symbols && entry.id < symbols->slots.size() && symbols->slots[entry.id])
            {
                auto &symbol = *symbols->slots[entry.id];
                for (auto &name : symbol.texts)
                    text_names.push_back(name);
                for (auto &local : symbol.local_types)
                {
                    if (!scope.user_types.count(local.second))
                        throw std::runtime_error("symbol metadata references unknown local type");
                    local_types[local.first] = ValueType(local.second);
                }
            }
            auto body = decompile_script(*entry.script, scope, name, text_names, local_types);
            text += args.flag("mary-c")
                        ? format_mary_c(name,
                                        body,
                                        map ? &*map : nullptr,
                                        directory ? std::nullopt
                                                  : std::optional<Integer>(Integer(entry.id)))
                        : format_legacy(Integer(entry.id), name, body, map ? &*map : nullptr);
        }
        if (entry.script && args.flag("print-ir"))
            text += '\n' + ir_comment(*entry.script, map ? &*map : nullptr);
        if (args.flag("all"))
            write_text(*directory / (name + (args.flag("mary-c") ? ".mary.c" : ".mary")), text);
        else
            output(args, text);
    }
}

int run(const std::vector<std::string> &input)
{
    auto args = arguments(input);
    if (args.flag("version"))
    {
        std::cout << "mary 0.2.0 (C++17)\n";
        return 0;
    }
    if (args.command.empty() || args.flag("help"))
    {
        help();
        return 0;
    }
    if (args.command == "generate-script-table")
    {
        if (args.positional.size() != 3)
            throw std::runtime_error("generate-script-table requires SYMBOLS MARY_TARGET OUTPUT");
        Options opts;
        opts.define(args.positional[1]);
        auto symbols = parse_text_name_table(read_text(fs::u8path(args.positional[0])), opts);
        write_text(fs::u8path(args.positional[2]),
                   render_script_table(symbols.script_table(), false));
    }
    else if (args.command == "generate-symbols")
    {
        if (args.positional.size() != 7)
            throw std::runtime_error(
                "generate-symbols requires six ROM paths and OUTPUT_DIRECTORY");
        std::vector<fs::path> roms;
        for (std::size_t i = 0; i < 6; ++i)
            roms.push_back(fs::u8path(args.positional[i]));
        generate_symbol_tables(roms, fs::u8path(args.positional[6]));
    }
    else if (args.command == "analyse-callable-shapes")
    {
        if (args.positional.size() != 1)
            throw std::runtime_error("analyse-callable-shapes requires one input ROM");
        output(args, analyse_callable_shapes(read_binary(fs::u8path(args.positional[0]))));
    }
    else if (args.command == "compile")
        compile(args);
    else if (args.command == "import")
        import_rom(args);
    else if (args.command == "bundle")
    {
        if (args.positional.size() != 1 || !args.path("output"))
            throw std::runtime_error("bundle requires source directory and -o output directory");
        auto layout = args.values.count("layout") ? args.values.at("layout") : "packed";
        if (layout != "packed" && layout != "split")
            throw std::runtime_error("bundle layout must be packed or split");
        bundle(
            request(args, fs::u8path(args.positional[0])), *args.path("output"), layout == "split");
    }
    else if (args.command == "decompile")
        decompile(args, tool_directory(input[0]));
    else
        throw std::runtime_error("unknown command: " + args.command);
    return 0;
}

} // namespace
} // namespace mary

int main(int argc, char **argv)
{
    try
    {
        std::vector<std::string> input;
#ifdef _WIN32
        int count = 0;
        auto wide = CommandLineToArgvW(GetCommandLineW(), &count);
        if (!wide)
            throw std::runtime_error("cannot decode Windows command line");
        try
        {
            for (int i = 0; i < count; ++i)
            {
                auto length = WideCharToMultiByte(
                    CP_UTF8, WC_ERR_INVALID_CHARS, wide[i], -1, nullptr, 0, nullptr, nullptr);
                if (!length)
                    throw std::runtime_error("invalid Unicode command-line argument");
                std::string text(std::size_t(length), '\0');
                WideCharToMultiByte(CP_UTF8,
                                    WC_ERR_INVALID_CHARS,
                                    wide[i],
                                    -1,
                                    text.data(),
                                    length,
                                    nullptr,
                                    nullptr);
                text.pop_back();
                input.push_back(std::move(text));
            }
        }
        catch (...)
        {
            LocalFree(wide);
            throw;
        }
        LocalFree(wide);
        (void)argc;
        (void)argv;
#else
        for (int i = 0; i < argc; ++i)
            input.emplace_back(argv[i]);
#endif
        return mary::run(input);
    }
    catch (const std::exception &error)
    {
        std::cerr << "error: " << error.what() << '\n';
        return 1;
    }
}
