#ifndef MARY_CONSTANT_EXPR_HH
#define MARY_CONSTANT_EXPR_HH

#include "ir.hh"
#include <functional>
#include <optional>
#include <string_view>

namespace mary
{

using ConstantLookup = std::function<std::optional<Integer>(std::string_view)>;
Integer evaluate_constant(std::string_view input,
                          const ConstantLookup &lookup,
                          bool undefined_is_zero = false);
Integer apply_integer_operator(std::string_view op, Integer lhs, Integer rhs);

} // namespace mary
#endif
