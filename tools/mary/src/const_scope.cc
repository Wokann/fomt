#include "const_scope.hh"
#include <stdexcept>

namespace mary
{

std::optional<Integer> ConstScope::integer_constant(std::string_view name) const
{
    auto found = constants.find(std::string(name));
    if (found != constants.end())
        if (auto value = std::get_if<Integer>(&found->second))
            return *value;
    return std::nullopt;
}

void ConstScope::add_typed_constant(const std::string &type, const std::string &name, Integer value)
{
    user_types.insert(type);
    constants[name] = value;
    constant_types[name] = type;
    typed_constants[{ type, value }] = name;
}

bool ConstScope::is_subset(const std::string &subset, const std::string &superset) const
{
    if (subset == superset)
        return true;
    std::vector<std::string> pending{ subset };
    std::set<std::string> visited;
    while (!pending.empty())
    {
        auto current = pending.back();
        pending.pop_back();
        if (!visited.insert(current).second)
            continue;
        for (auto &relation : type_subsets)
            if (relation.first == current)
            {
                if (relation.second == superset)
                    return true;
                pending.push_back(relation.second);
            }
    }
    return false;
}

std::optional<ValueType> ConstScope::narrower_type(const ValueType &left,
                                                   const ValueType &right) const
{
    if (left == right)
        return left;
    if (left.kind == ValueType::User && right.kind == ValueType::Integer)
        return left;
    if (right.kind == ValueType::User && left.kind == ValueType::Integer)
        return right;
    if (left.kind != ValueType::User || right.kind != ValueType::User)
        return std::nullopt;
    if (is_subset(left.name, right.name))
        return left;
    if (is_subset(right.name, left.name))
        return right;
    return std::nullopt;
}

void ConstScope::validate_callable_metadata() const
{
    auto callable = [&](const std::string &name) -> const Callable &
    {
        auto found = callables.find(name);
        if (found == callables.end())
            throw std::runtime_error("type metadata references undeclared callable '" + name + "'");
        return found->second;
    };
    auto parameter = [&](const std::string &name, std::size_t index)
    {
        if (index >= callable(name).parameters.size())
            throw std::runtime_error("type metadata references missing parameter of '" + name +
                                     "'");
    };
    for (auto &entry : dependent_return_types)
        parameter(std::get<0>(entry.first), std::get<1>(entry.first));
    for (auto &entry : dependent_parameter_types)
    {
        parameter(std::get<0>(entry.first), std::get<1>(entry.first));
        parameter(std::get<0>(entry.first), std::get<3>(entry.first));
    }
    for (auto &entry : related_return_types)
    {
        callable(std::get<0>(entry.first));
        callable(std::get<2>(entry.first));
    }
}

} // namespace mary
