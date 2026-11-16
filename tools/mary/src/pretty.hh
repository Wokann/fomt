#ifndef MARY_PRETTY_HH
#define MARY_PRETTY_HH

#include "ast.hh"
#include "charmap.hh"

namespace mary
{
std::vector<std::string> string_fragments(const Bytes &bytes,
                                          const Charmap *map = nullptr,
                                          bool legacy = false);
std::string format_expression(const Expr &expression,
                              const Charmap *map = nullptr,
                              bool legacy = false);
std::string format_statements(const std::vector<Statement> &statements,
                              bool mary_c,
                              unsigned indent = 0,
                              const Charmap *map = nullptr);
std::string format_mary_c(const std::string &name,
                          const std::vector<Statement> &statements,
                          const Charmap *map = nullptr,
                          std::optional<Integer> id = std::nullopt);
std::string format_legacy(Integer id,
                          const std::string &name,
                          const std::vector<Statement> &statements,
                          const Charmap *map = nullptr);
} // namespace mary
#endif
