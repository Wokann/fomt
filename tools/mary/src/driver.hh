#ifndef MARY_DRIVER_HH
#define MARY_DRIVER_HH

#include "io.hh"
#include "mary_c.hh"

namespace mary
{

struct SourceRequest
{
    fs::path input;
    std::optional<fs::path> library, script_table, constants, charmap;
    std::vector<std::string> defines;
};
struct CompiledSources
{
    std::string target;
    ScriptTable table;
    std::map<std::size_t, Bytes> scripts;
    std::map<std::size_t, std::vector<std::string>> text_names;
    std::vector<fs::path> dependencies;
};
struct HeaderNames
{
    std::string constants, callables, scripts, symbols;
};

Options source_options(const std::vector<std::string> &defines, std::string_view source);
std::optional<std::string> selected_target(const Options &options);
HeaderNames header_names(std::string_view target);
std::vector<fs::path> extract_includes(std::string &source);
CompiledSources compile_sources(const SourceRequest &request);
void bundle(const SourceRequest &request, const fs::path &output, bool split);
std::string render_script_table(const ScriptTable &table, bool guarded = true);

} // namespace mary
#endif
