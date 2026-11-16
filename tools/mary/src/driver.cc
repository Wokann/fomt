#include "driver.hh"
#include "bytecode.hh"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{
const std::vector<std::string> targets{ "MARY_FOMT_JP", "MARY_FOMT_US",  "MARY_FOMT_EU",
                                        "MARY_FOMT_DE", "MARY_MFOMT_JP", "MARY_MFOMT_US" };
std::string_view trim(std::string_view text)
{
    while (!text.empty() && std::isspace(static_cast<unsigned char>(text.front())))
        text.remove_prefix(1);
    while (!text.empty() && std::isspace(static_cast<unsigned char>(text.back())))
        text.remove_suffix(1);
    return text;
}
std::vector<std::size_t> text_offsets(const Bytes &riff)
{
    if (riff.size() < 12 || read_u32(riff, 4) != riff.size())
        throw std::runtime_error("invalid RIFF size while exporting symbols");
    for (std::size_t at = 12; at < riff.size();)
    {
        if (riff.size() - at < 8)
            throw std::runtime_error("truncated RIFF chunk header");
        auto length = read_u32(riff, at + 4);
        if (length > riff.size() - at - 8)
            throw std::runtime_error("truncated RIFF chunk");
        if (std::equal(riff.begin() + at, riff.begin() + at + 4, "STR "))
        {
            if (length < 4)
                throw std::runtime_error("truncated STR count");
            auto count = read_u32(riff, at + 8);
            if (count > (length - 4) / 4)
                throw std::runtime_error("truncated STR table");
            auto pool = at + 12 + std::size_t(count) * 4;
            std::vector<std::size_t> result;
            for (std::size_t i = 0; i < count; ++i)
            {
                auto offset = read_u32(riff, at + 12 + i * 4);
                if (pool > riff.size() || offset >= riff.size() - pool)
                    throw std::runtime_error("STR offset is outside RIFF");
                result.push_back(pool + offset);
            }
            return result;
        }
        at += 8 + length;
    }
    return {};
}
} // namespace

std::optional<std::string> selected_target(const Options &options)
{
    std::optional<std::string> result;
    for (auto &target : targets)
        if (options.defines.count(target))
        {
            if (result)
                return std::nullopt;
            result = target;
        }
    return result;
}
Options source_options(const std::vector<std::string> &defines, std::string_view source)
{
    Options options;
    for (auto &define : defines)
        options.define(define);
    std::istringstream lines{ std::string(source) };
    std::string line;
    while (std::getline(lines, line))
    {
        auto text = trim(line);
        if (text.substr(0, 7) != "#define")
            continue;
        text = trim(text.substr(7));
        auto end = text.find_first_of(" \t\r");
        auto name = std::string(text.substr(0, end));
        if (std::find(targets.begin(), targets.end(), name) != targets.end())
            options.define(name);
    }
    if (!selected_target(options))
        throw std::runtime_error("Mary-C source must select exactly one MARY_* ROM target");
    return options;
}
HeaderNames header_names(std::string_view target)
{
    std::string prefix = target.substr(0, 11) == "MARY_MFOMT_" ? "mfomt" : "fomt";
    return { prefix + "_constants.mary.h",
             prefix + "_callables.mary.h",
             prefix + "_scripts.mary.h",
             prefix + "_scripts_text.mary.sym" };
}
std::vector<fs::path> extract_includes(std::string &source)
{
    std::vector<fs::path> includes;
    std::string rebuilt;
    std::size_t at = 0;
    while (at < source.size())
    {
        auto end = source.find('\n', at);
        if (end == std::string::npos)
            end = source.size();
        else
            ++end;
        auto raw = std::string_view(source).substr(at, end - at), text = trim(raw);
        if (text.substr(0, 8) == "#include")
        {
            auto path = trim(text.substr(8));
            if (path.size() < 2 || path.front() != '"' || path.back() != '"')
                throw std::runtime_error("Mary-C include must use a quoted path");
            includes.push_back(fs::u8path(path.substr(1, path.size() - 2)));
            if (!raw.empty() && raw.back() == '\n')
                rebuilt += '\n';
        }
        else
            rebuilt += raw;
        at = end;
    }
    source = std::move(rebuilt);
    return includes;
}
CompiledSources compile_sources(const SourceRequest &request)
{
    bool complete = fs::is_directory(request.input);
    std::vector<fs::path> paths;
    if (complete)
        for (auto &entry : fs::directory_iterator(request.input))
        {
            auto name = entry.path().filename().u8string();
            if (entry.is_regular_file() && name.size() >= 7 &&
                name.substr(name.size() - 7) == ".mary.c")
                paths.push_back(entry.path());
        }
    else
        paths.push_back(request.input);
    std::sort(paths.begin(), paths.end());
    if (paths.empty())
        throw std::runtime_error("source directory has no .mary.c files");
    auto first = read_text(paths.front());
    auto options = source_options(request.defines, first);
    auto target = *selected_target(options);
    auto names = header_names(target);
    auto base = paths.front().parent_path();
    auto includes = extract_includes(first);
    auto included = [&](const std::string &name) -> std::optional<fs::path>
    {
        for (auto &path : includes)
            if (path.filename() == fs::u8path(name))
                return path.is_absolute() ? path : base / path;
        return std::nullopt;
    };
    auto choose = [&](const std::optional<fs::path> &override, const std::string &name)
    {
        if (override)
            return *override;
        if (auto path = included(name))
            return *path;
        return base / fs::u8path(name);
    };
    auto library = choose(request.library, names.callables),
         scripts = choose(request.script_table, names.scripts),
         constants = choose(request.constants, names.constants);
    auto scope = parse_constant_header(read_text(constants), options);
    auto calls = parse_callable_table(read_text(library), options, scope);
    auto table = parse_script_table(read_text(scripts), options);
    std::optional<Charmap> map;
    if (request.charmap)
        map = Charmap::parse(preprocess_charmap(read_text(*request.charmap), options));
    CompiledSources result{ target, table, {}, {}, { library, scripts, constants } };
    if (request.charmap)
        result.dependencies.push_back(*request.charmap);
    for (auto &path : paths)
    {
        auto source = read_text(path);
        auto own_options = source_options({}, source);
        extract_includes(source);
        auto discovered = discover_script_names(source, own_options);
        std::size_t registered = 0;
        for (auto &name : discovered)
            if (table.ids.count(name))
                ++registered;
        if (!registered)
            continue;
        if (registered != discovered.size())
            throw std::runtime_error(path.u8string() +
                                     " mixes registered and unregistered script names");
        if (selected_target(own_options) != std::optional<std::string>(target))
            throw std::runtime_error("input selects a different Mary-C target: " + path.u8string());
        result.dependencies.push_back(path);
        for (auto &script :
             parse_mary_c(source, options, calls.scope, &table, map ? &*map : nullptr))
        {
            if (script.id < 0 || std::uint64_t(script.id) >= table.slots.size() ||
                table.slots[std::size_t(script.id)] != std::optional<std::string>(script.name))
                throw std::runtime_error("script name and ordered ID disagree: " + script.name);
            auto id = std::size_t(script.id);
            if (!result.scripts.emplace(id, encode_script(script.script)).second)
                throw std::runtime_error("script ID occurs in multiple input files");
            result.text_names[id] = std::move(script.text_names);
        }
    }
    if (complete)
        for (std::size_t id = 0; id < table.slots.size(); ++id)
            if (table.slots[id] && !result.scripts.count(id))
                throw std::runtime_error("script definition is missing: " + *table.slots[id]);
    return result;
}
void bundle(const SourceRequest &request, const fs::path &output, bool split)
{
    if (!fs::is_directory(request.input))
        throw std::runtime_error("bundle input must be a directory");
    auto compiled = compile_sources(request);
    fs::create_directories(output);
    std::ostringstream assembly;
    assembly << ".section .rodata.mary_scripts, \"a\", %progbits\n.balign 4\n\n";
    Bytes packed;
    auto riff_dir = output / "riff";
    if (split)
        fs::create_directories(riff_dir);
    else
        assembly
            << ".global gMaryScripts\n.type gMaryScripts, %object\ngMaryScripts:\n    .incbin \""
            << assembler_path(output / "scripts.bin")
            << "\"\n.global gMaryScriptsEnd\ngMaryScriptsEnd:\n.size gMaryScripts, gMaryScriptsEnd "
               "- "
               "gMaryScripts\n\n";
    std::vector<fs::path> produced{ output / "scripts.s",
                                    output / "script_table.s",
                                    output / "scripts.d" };
    if (!split)
        produced.push_back(output / "scripts.bin");
    for (std::size_t id = 0; id < compiled.table.slots.size(); ++id)
    {
        if (!compiled.table.slots[id])
            continue;
        auto &name = *compiled.table.slots[id];
        auto &riff = compiled.scripts.at(id);
        auto offsets = text_offsets(riff);
        auto &symbols = compiled.text_names.at(id);
        if (offsets.size() != symbols.size())
            throw std::runtime_error("STR count and source text declaration count differ for " +
                                     name);
        auto offset = packed.size();
        if (split)
        {
            auto path = riff_dir / (name + ".riff");
            write_binary(path, riff);
            produced.push_back(path);
            assembly << ".balign 4\n.global " << name << "\n.type " << name << ", %object\n"
                     << name << ":\n    .incbin \"" << assembler_path(path) << "\"\n";
        }
        else
        {
            assembly << ".global " << name << "\n.type " << name << ", %object\n.set " << name
                     << ", gMaryScripts + 0x" << hex(offset) << '\n';
            packed.insert(packed.end(), riff.begin(), riff.end());
            while (packed.size() % 4)
                packed.push_back(0);
        }
        assembly << ".size " << name << ", 0x" << hex(riff.size()) << '\n';
        for (std::size_t i = 0; i < symbols.size(); ++i)
            assembly << ".global " << symbols[i] << "\n.type " << symbols[i] << ", %object\n.set "
                     << symbols[i] << ", " << name << " + 0x" << hex(offsets[i]) << '\n';
        assembly << '\n';
    }
    if (!split)
        write_binary(output / "scripts.bin", packed);
    write_text(output / "scripts.s", assembly.str());
    std::string table =
        ".section .rodata.mary_script_table, \"a\", %progbits\n.balign 4\n\n.global "
        "gMaryScriptTable\n.type gMaryScriptTable, %object\ngMaryScriptTable:\n";
    for (auto &slot : compiled.table.slots)
        table += "    .word " + (slot ? *slot : "0") + "\n";
    table +=
        "gMaryScriptTableEnd:\n.size gMaryScriptTable, gMaryScriptTableEnd - gMaryScriptTable\n";
    write_text(output / "script_table.s", table);
    auto dependencies = compiled.dependencies;
    std::sort(dependencies.begin(), dependencies.end());
    dependencies.erase(std::unique(dependencies.begin(), dependencies.end()), dependencies.end());
    std::string dep;
    for (auto &path : produced)
    {
        if (!dep.empty())
            dep += " \\\n    ";
        dep += makefile_path(path);
    }
    dep += ": \\\n    ";
    bool first = true;
    for (auto &path : dependencies)
    {
        if (!first)
            dep += " \\\n    ";
        first = false;
        dep += makefile_path(path);
    }
    dep += '\n';
    write_text(output / "scripts.d", dep);
}
std::string render_script_table(const ScriptTable &table, bool guarded)
{
    std::string source =
        guarded ? "#if defined(MARY_C)\nmary_script_table\n{\n" : "mary_script_table\n{\n";
    for (std::size_t id = 0; id < table.slots.size(); ++id)
        source += "    /* 0x" + hex(id, 4) + " */ " +
                  (table.slots[id] ? *table.slots[id] : "NULL") + ",\n";
    return source + (guarded ? "};\n#endif\n" : "};\n");
}

} // namespace mary
