#ifndef MARY_TABLES_HH
#define MARY_TABLES_HH

#include "const_scope.hh"

namespace mary
{

struct ScriptTable
{
    std::vector<std::optional<std::string>> slots;
    std::map<std::string, Integer> ids;
    void add_constants(ConstScope &scope) const;
    static ScriptTable from_slots(std::vector<std::optional<std::string>> slots);
};

struct CallableTable
{
    std::string name;
    std::size_t base = 0, next_id = 0;
    ConstScope scope;
};

struct ScriptSymbol
{
    std::string name;
    std::vector<std::string> texts;
    std::map<std::string, std::string> local_types;
};
struct ScriptSymbols
{
    std::vector<std::optional<ScriptSymbol>> slots;
    ScriptTable script_table() const;
};

ConstScope parse_constant_header(std::string_view source, const Options &options = {});
CallableTable parse_callable_table(std::string_view source,
                                   const Options &options = {},
                                   const ConstScope &scope = {});
ScriptTable parse_script_table(std::string_view source, const Options &options = {});
ScriptSymbols parse_text_name_table(std::string_view source, const Options &options = {});

} // namespace mary
#endif
