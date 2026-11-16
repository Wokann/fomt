#ifndef MARY_LOW_LEVEL_HH
#define MARY_LOW_LEVEL_HH

#include "lexer.hh"

namespace mary
{
Script parse_ir(Tokens &tokens);
std::string format_ir(const Script &script, unsigned indent = 0, const Charmap *map = nullptr);
} // namespace mary
#endif
