#ifndef MARY_DECOMPILER_HH
#define MARY_DECOMPILER_HH

#include "ast.hh"

namespace mary
{
std::vector<Statement> decompile_instructions(const std::vector<Instruction> &instructions,
                                              const ConstScope &scope);
std::vector<Statement> decompile_script(
    const Script &script,
    const ConstScope &scope,
    const std::string &name = {},
    const std::vector<std::optional<std::string>> &text_names = {},
    const std::map<std::string, ValueType> &local_types = {});
} // namespace mary
#endif
