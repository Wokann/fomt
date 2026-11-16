#ifndef MARY_CONST_SCOPE_HH
#define MARY_CONST_SCOPE_HH

#include "ir.hh"
#include "preprocessor.hh"
#include <map>
#include <optional>
#include <set>
#include <string>
#include <tuple>
#include <variant>

namespace mary
{

struct ValueType
{
    enum Kind
    {
        Undefined,
        Integer,
        String,
        User
    } kind = Undefined;
    std::string name;
    ValueType() = default;
    ValueType(Kind kind)
      : kind(kind)
    {
    }
    explicit ValueType(std::string name)
      : kind(User)
      , name(std::move(name))
    {
    }
    bool operator==(const ValueType &other) const
    {
        return kind == other.kind && name == other.name;
    }
    bool operator!=(const ValueType &other) const
    {
        return !(*this == other);
    }
};

using Constant = std::variant<Integer, Bytes>;
struct Callable
{
    std::uint32_t id;
    ValueType return_type;
    std::vector<ValueType> parameters;
    bool is_function() const
    {
        return return_type.kind != ValueType::Undefined;
    }
};

struct ConstScope
{
    Macros macros;
    std::map<std::string, Constant> constants;
    std::map<std::string, Callable> callables;
    std::set<std::string> user_types;
    std::map<std::pair<std::string, Integer>, std::string> typed_constants;
    std::map<std::string, std::string> constant_types;
    std::map<Integer, std::string> variable_types;
    std::map<std::tuple<std::string, std::size_t, Integer>, std::string> dependent_return_types;
    std::map<std::tuple<std::string, std::size_t, Integer, std::size_t>, std::string>
        dependent_parameter_types;
    std::map<std::tuple<std::string, Integer, std::string>, std::string> related_return_types;
    std::set<std::pair<std::string, std::string>> type_subsets;
    std::map<std::string, std::string> typed_identities;
    std::map<std::string, std::string> identity_names;

    std::optional<Integer> integer_constant(std::string_view name) const;
    void add_typed_constant(const std::string &type, const std::string &name, Integer value);
    bool is_subset(const std::string &subset, const std::string &superset) const;
    std::optional<ValueType> narrower_type(const ValueType &left, const ValueType &right) const;
    void validate_callable_metadata() const;
};

} // namespace mary
#endif
