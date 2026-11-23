#ifndef MARY_PREPROCESSOR_HH
#define MARY_PREPROCESSOR_HH

#include <filesystem>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <string_view>
#include <vector>

namespace mary
{

struct PreprocessToken
{
    std::string text;
    bool trivia = false;
    bool identifier = false;
    std::set<std::string> hidden;
    std::size_t line = 0;
};

struct Macro
{
    std::optional<std::vector<std::string>> parameters;
    std::vector<PreprocessToken> replacement;
};
using Macros = std::map<std::string, Macro>;

struct Options
{
    std::map<std::string, std::string> defines{ { "MARY_C", "1" } };
    void define(std::string_view definition);
};

struct SourceLine
{
    std::size_t file = 0, line = 0;
};

struct SourceLines
{
    std::vector<std::filesystem::path> files;
    std::vector<SourceLine> lines;
    SourceLine at(std::size_t expanded_line) const;
    std::string describe(std::size_t expanded_line) const;
};

struct IncludedFile
{
    SourceLine from;
    std::size_t file;
    std::size_t begin, end;
};

struct IncludeOptions
{
    std::vector<std::filesystem::path> directories;
    std::map<std::filesystem::path, std::filesystem::path> provided;
};

struct Preprocessed
{
    std::string text;
    Macros macros;
    SourceLines locations;
    std::vector<IncludedFile> includes;
};

Preprocessed preprocess(std::string_view source,
                        const Options &options = {},
                        const Macros &inherited = {});
Preprocessed preprocess_file(std::string_view source,
                             const std::filesystem::path &path,
                             const Options &options,
                             const IncludeOptions &includes,
                             const Macros &inherited = {});
struct SourcePreamble
{
    Macros macros;
    std::vector<std::filesystem::path> includes;
};
SourcePreamble scan_source_preamble(std::string_view source, const Options &options);
// Mapping records remain opaque, including quotes, slashes and '#' comments.
std::string preprocess_charmap(std::string_view source, const Options &options = {});

} // namespace mary
#endif
