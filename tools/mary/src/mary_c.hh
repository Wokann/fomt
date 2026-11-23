#ifndef MARY_MARY_C_HH
#define MARY_MARY_C_HH

#include "ast.hh"
#include "charmap.hh"
#include "tables.hh"

namespace mary
{

struct NamedScript
{
    Integer id;
    std::string name;
    Script script;
    std::vector<std::string> text_names;
    std::vector<std::size_t> text_lines{};
};

std::vector<NamedScript> parse_mary_c(std::string_view source,
                                      const Options &options,
                                      const ConstScope &scope,
                                      const ScriptTable *scripts = nullptr,
                                      const Charmap *map = nullptr);
std::vector<std::string> discover_script_names(std::string_view source, const Options &options);
std::vector<NamedScript> parse_mary_c(const Preprocessed &source,
                                     const ConstScope &scope,
                                     const ScriptTable *scripts = nullptr,
                                     const Charmap *map = nullptr);
std::vector<std::string> discover_script_names(const Preprocessed &source);
void validate_calls(const std::vector<Statement> &body, const ConstScope &scope);

} // namespace mary
#endif
