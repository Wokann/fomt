#ifndef MARY_PREPROCESSOR_HH
#define MARY_PREPROCESSOR_HH

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

struct Preprocessed
{
    std::string text;
    Macros macros;
};

Preprocessed preprocess(std::string_view source,
                        const Options &options = {},
                        const Macros &inherited = {});
// Mapping records remain opaque, including quotes, slashes and '#' comments.
std::string preprocess_charmap(std::string_view source, const Options &options = {});

} // namespace mary
#endif
