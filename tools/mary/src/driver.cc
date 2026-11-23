#include "driver.hh"
#include "bytecode.hh"
#include "lexer.hh"

#include <algorithm>
#include <array>
#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{
const std::vector<std::string> targets{ "MARY_FOMT_JP", "MARY_FOMT_US",  "MARY_FOMT_EU",
                                        "MARY_FOMT_DE", "MARY_MFOMT_JP", "MARY_MFOMT_US" };
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
    if (std::none_of(targets.begin(), targets.end(), [&](const auto &target)
        { return options.defines.count(target); }))
        for (const auto &[name, macro] : scan_source_preamble(source, options).macros)
            if (std::find(targets.begin(), targets.end(), name) != targets.end())
                options.define(name);
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
namespace
{

using TablePaths = std::array<std::optional<fs::path>, 3>;
enum TableIndex { Constants, Callables, Scripts };

std::array<fs::path, 3> table_names(const Options &options)
{
    const auto names = header_names(*selected_target(options));
    return { fs::u8path(names.constants), fs::u8path(names.callables), fs::u8path(names.scripts) };
}

TablePaths table_paths(const SourceRequest &request)
{
    return { request.constants, request.library, request.script_table };
}

struct Metadata
{
    IncludeOptions includes;
    std::array<std::optional<Preprocessed>, 3> tables;
    Macros macros;
    std::vector<fs::path> dependencies;
};

void dependencies_from(const Preprocessed &source, std::vector<fs::path> &dependencies)
{
    for (const auto &path : source.locations.files)
        if (!path.empty())
            dependencies.push_back(path);
}

Metadata load_metadata(const SourceRequest &request, const Options &options, const TablePaths &paths)
{
    Metadata metadata;
    metadata.includes.directories = request.include_dirs;
    const auto names = table_names(options);
    for (std::size_t i = 0; i < paths.size(); ++i)
    {
        if (const auto &path = paths[i])
        {
            auto processed = preprocess_file(read_text(*path), *path, options, metadata.includes,
                                             metadata.macros);
            metadata.macros = std::move(processed.macros);
            dependencies_from(processed, metadata.dependencies);
            metadata.tables[i] = std::move(processed);
            metadata.includes.provided.emplace(names[i], *path);
            metadata.includes.provided.emplace(path->filename(), *path);
        }
    }
    return metadata;
}

ConstScope parse_scope(const Metadata &metadata)
{
    ConstScope scope;
    if (metadata.tables[Constants])
        scope = parse_constant_header(*metadata.tables[Constants]);
    if (metadata.tables[Callables])
        scope = parse_callable_table(*metadata.tables[Callables], scope).scope;
    return scope;
}

std::optional<Charmap> source_charmap(const SourceRequest &request, const Options &options)
{
    if (request.charmap)
        return Charmap::parse(preprocess_charmap(read_text(*request.charmap), options));
    return std::nullopt;
}

void require_target(const Preprocessed &source, const Options &options, const fs::path &path)
{
    auto target = selected_target(options);
    for (const auto &name : targets)
        if (bool(source.macros.count(name)) != (name == *target))
            throw std::runtime_error("input selects a different Mary-C target: " + path.u8string());
}

Preprocessed extract_header(const Preprocessed &source, const IncludedFile &include)
{
    auto begin = source.text.begin() + include.begin, end = source.text.begin() + include.end;
    const auto first = std::count(source.text.begin(), begin, '\n');
    const auto length = std::count(begin, end, '\n');
    Preprocessed header;
    header.text.assign(begin, end);
    header.locations.files = source.locations.files;
    header.locations.lines.assign(source.locations.lines.begin() + first,
                                  source.locations.lines.begin() + first + length);
    return header;
}

void capture_metadata(const Options &options, Metadata &metadata, Preprocessed &source)
{
    const auto names = table_names(options);
    std::vector<std::pair<std::size_t, std::size_t>> removed;
    for (const auto &include : source.includes)
    {
        if (include.begin == include.end)
            continue;
        auto header = extract_header(source, include);
        const auto path = source.locations.files[include.file].filename();
        const auto name = std::find(names.begin(), names.end(), path);
        std::size_t table = std::size_t(name - names.begin());
        if (name == names.end())
        {
            const auto tokens = lex(header.text, nullptr, false, &header.locations);
            if (tokens.front().kind == TokenKind::End ||
                header.locations.at(tokens.front().line).file != include.file)
                continue;
            const auto &word = tokens.front().text;
            if (word == "mary_callable_table")
                table = Callables;
            else if (word == "mary_script_table")
                table = Scripts;
            else if (word == "typedef" || word == "mary_typed_identity" ||
                     word == "mary_type_subset" || word == "mary_var_type")
                table = Constants;
            else
                continue;
        }
        if (metadata.tables[table])
        {
            const auto tokens = lex(header.text, nullptr, false, &header.locations);
            if (tokens.front().kind != TokenKind::End)
                throw std::runtime_error(source.locations.files[include.file].generic_u8string() +
                                         ": more than one active Mary metadata table of this kind");
        }
        else
            metadata.tables[table] = std::move(header);
        removed.emplace_back(include.begin, include.end);
    }
    for (const auto &[begin, end] : removed)
        for (auto at = begin; at < end; ++at)
            if (source.text[at] != '\n')
                source.text[at] = ' ';
}

} // namespace

PreparedSource prepare_source(const SourceRequest &request, std::string_view source)
{
    auto options = source_options(request.defines, source);
    auto paths = table_paths(request);
    auto metadata = load_metadata(request, options, paths);
    auto processed = preprocess_file(source, request.input, options, metadata.includes, metadata.macros);
    require_target(processed, options, request.input);
    if (std::any_of(paths.begin(), paths.end(), [](const auto &path) { return !path; }))
        capture_metadata(options, metadata, processed);
    std::optional<ScriptTable> table;
    if (metadata.tables[Scripts])
        table = parse_script_table(*metadata.tables[Scripts]);
    return { std::move(processed), parse_scope(metadata), std::move(table),
             source_charmap(request, options) };
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
    auto headers = table_paths(request);
    if (std::any_of(headers.begin(), headers.end(), [](const auto &path) { return !path; }))
    {
        const auto base = paths.front().parent_path();
        const auto names = table_names(options);
        const auto preamble = scan_source_preamble(first, options);
        for (std::size_t i = 0; i < headers.size(); ++i)
        {
            if (headers[i])
                continue;
            const auto include = std::find_if(preamble.includes.begin(), preamble.includes.end(),
                [&](const auto &path) { return path.filename() == names[i]; });
            auto name = include == preamble.includes.end() ? names[i] : *include;
            auto path = base / name;
            if (!name.is_absolute() && !fs::is_regular_file(path))
                for (const auto &directory : request.include_dirs)
                    if (fs::is_regular_file(directory / name))
                    {
                        path = directory / name;
                        break;
                    }
            headers[i] = std::move(path);
        }
    }
    auto metadata = load_metadata(request, options, headers);
    auto scope = parse_scope(metadata);
    auto table = parse_script_table(*metadata.tables[Scripts]);
    auto map = source_charmap(request, options);
    CompiledSources result{ target, table, {}, {}, std::move(metadata.dependencies) };
    if (request.charmap)
        result.dependencies.push_back(*request.charmap);
    for (auto &path : paths)
    {
        auto source = preprocess_file(read_text(path), path, options, metadata.includes,
                                      metadata.macros);
        dependencies_from(source, result.dependencies);
        auto discovered = discover_script_names(source);
        std::size_t registered = 0;
        for (auto &name : discovered)
            if (table.ids.count(name))
                ++registered;
        if (!registered)
            continue;
        if (registered != discovered.size())
            throw std::runtime_error(path.u8string() +
                                     " mixes registered and unregistered script names");
        require_target(source, options, path);
        for (auto &script :
             parse_mary_c(source, scope, &table, map ? &*map : nullptr))
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
    if (request.dep_target)
        produced.push_back(*request.dep_target);
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
    for (const auto &path : dependencies)
        dep += makefile_path(path) + ":\n";
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
