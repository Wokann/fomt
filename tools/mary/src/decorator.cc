#include "constant_expr.hh"
#include "decompiler.hh"

#include <algorithm>
#include <deque>
#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{

bool comparison(const Expr &e)
{
    return e.kind == Expr::Binary && (e.name == "==" || e.name == "!=" || e.name == "<" ||
                                      e.name == "<=" || e.name == ">" || e.name == ">=");
}
template<class Map, class Key>
std::optional<typename Map::mapped_type> get(const Map &map, const Key &key)
{
    auto found = map.find(key);
    return found == map.end() ? std::nullopt
                              : std::optional<typename Map::mapped_type>(found->second);
}
using IntegerResolver = std::function<std::optional<Integer>(const Expr &)>;

std::optional<Integer> integer_value(const Expr &e,
                                     const ConstScope &scope,
                                     const std::map<std::string, Integer> &locals = {})
{
    if (e.kind == Expr::Int)
        return e.value;
    if (e.kind == Expr::Name)
    {
        auto value = scope.integer_constant(e.name);
        return value ? value : get(locals, e.name);
    }
    if (e.kind == Expr::Call && e.args.size() == 1 && scope.typed_identities.count(e.name))
        return integer_value(e.args[0], scope, locals);
    if (e.kind == Expr::Unary && e.name == "-")
    {
        if (auto value = integer_value(e.args[0], scope, locals))
        {
            try
            {
                return apply_integer_operator("-", 0, *value);
            }
            catch (const std::exception &)
            {
            }
        }
    }
    if (e.kind == Expr::Binary &&
        (e.name == "+" || e.name == "-" || e.name == "*" || e.name == "/" || e.name == "%"))
    {
        auto a = integer_value(e.args[0], scope, locals),
             b = integer_value(e.args[1], scope, locals);
        if (a && b)
            try
            {
                return apply_integer_operator(e.name, *a, *b);
            }
            catch (const std::exception &)
            {
            }
    }
    return std::nullopt;
}

std::vector<ValueType> parameter_types(const Expr &call,
                                       const ConstScope &scope,
                                       const IntegerResolver &resolve)
{
    auto found = scope.callables.find(call.name);
    if (found == scope.callables.end())
        return {};
    auto types = found->second.parameters;
    for (std::size_t target = 0; target < types.size(); ++target)
        for (std::size_t discriminator = 0; discriminator < call.args.size(); ++discriminator)
        {
            auto value = resolve(call.args[discriminator]);
            if (!value)
                continue;
            auto type = get(scope.dependent_parameter_types,
                            std::make_tuple(call.name, discriminator, *value, target));
            if (type)
            {
                types[target] = ValueType(*type);
                break;
            }
        }
    return types;
}

ValueType call_type(const Expr &call,
                    const ConstScope &scope,
                    const IntegerResolver &resolve,
                    const std::map<std::string, ValueType> &overrides = {})
{
    if (call.name == "VarGet" && !call.args.empty())
    {
        if (auto id = resolve(call.args[0]))
            if (auto type = get(scope.variable_types, *id))
                return ValueType(*type);
        return ValueType::Integer;
    }
    if (auto type = get(scope.typed_identities, call.name))
        return ValueType(*type);
    for (std::size_t i = 0; i < call.args.size(); ++i)
        if (auto value = resolve(call.args[i]))
            if (auto type =
                    get(scope.dependent_return_types, std::make_tuple(call.name, i, *value)))
                return ValueType(*type);
    if (auto type = get(overrides, call.name))
        return *type;
    auto found = scope.callables.find(call.name);
    return found == scope.callables.end() ? ValueType{} : found->second.return_type;
}

struct Requirement
{
    bool conflict = false;
    ValueType type;
};
using Requirements = std::map<std::string, Requirement>;
using Hints = std::map<std::string, std::deque<std::optional<Requirement>>>;

class Backpropagator
{
  public:
    Hints hints;
    std::set<std::string> compound;
    Backpropagator(const ConstScope &scope, const std::map<std::string, ValueType> &explicit_types)
      : scope(scope)
      , explicit_types(explicit_types)
    {
    }
    Requirements statements(std::vector<Statement> &body, Requirements requirements = {})
    {
        for (auto s = body.rbegin(); s != body.rend(); ++s)
            requirements = statement(*s, std::move(requirements));
        return requirements;
    }

  private:
    const ConstScope &scope;
    const std::map<std::string, ValueType> &explicit_types;
    void require(Requirements &requirements, const std::string &name, ValueType type)
    {
        if (type.kind != ValueType::User)
            return;
        auto found = requirements.find(name);
        if (found == requirements.end())
            requirements[name] = { false, type };
        else if (!found->second.conflict)
        {
            auto narrower = scope.narrower_type(found->second.type, type);
            found->second = narrower ? Requirement{ false, *narrower } : Requirement{ true, {} };
        }
    }
    Requirements merge(const std::vector<Requirements> &paths)
    {
        Requirements result;
        for (auto &path : paths)
            for (auto &entry : path)
            {
                if (entry.second.conflict)
                    result[entry.first] = entry.second;
                else
                    require(result, entry.first, entry.second.type);
            }
        return result;
    }
    ValueType type(const Expr &e)
    {
        if (e.kind == Expr::Call)
            return call_type(e, scope, [&](auto &v) { return integer_value(v, scope); });
        if (e.kind == Expr::Name)
            if (auto t = get(scope.constant_types, e.name))
                return ValueType(*t);
        return e.kind == Expr::Int   ? ValueType(ValueType::Integer)
               : e.kind == Expr::Str ? ValueType(ValueType::String)
                                     : ValueType{};
    }
    void require_expr(Expr &e, ValueType expected, Requirements &requirements)
    {
        if (e.kind == Expr::Name && !scope.integer_constant(e.name))
        {
            require(requirements, e.name, expected);
            return;
        }
        if (expected.kind == ValueType::User && e.kind == Expr::Int)
        {
            if (auto name = get(scope.typed_constants, std::make_pair(expected.name, e.value)))
                e = Expr::named(*name);
            else if (auto wrapper = get(scope.identity_names, expected.name))
                e = Expr::operation(Expr::Call, *wrapper, { std::move(e) });
            return;
        }
        if (expected.kind == ValueType::User && e.kind == Expr::Unary && e.name == "-")
        {
            auto positive = e.args[0].kind == Expr::Int    ? std::optional<Integer>(e.args[0].value)
                            : e.args[0].kind == Expr::Name ? scope.integer_constant(e.args[0].name)
                                                           : std::nullopt;
            if (positive && *positive != INT64_MIN)
            {
                auto value = -*positive;
                if (auto name = get(scope.typed_constants, std::make_pair(expected.name, value)))
                {
                    e = Expr::operation(Expr::Call, "mary_negated_int", { Expr::named(*name) });
                    return;
                }
                if (auto wrapper = get(scope.identity_names, expected.name))
                {
                    e = Expr::operation(Expr::Call,
                                        *wrapper,
                                        { Expr::operation(Expr::Call,
                                                          "mary_negated_int",
                                                          { Expr::integer(value) }) });
                    return;
                }
            }
        }
        expression(e, requirements);
    }
    void expression(Expr &e, Requirements &requirements)
    {
        if (e.kind == Expr::Increment)
        {
            compound.insert(e.name);
            requirements.erase(e.name);
            return;
        }
        if (e.kind == Expr::Call)
        {
            auto types =
                parameter_types(e, scope, [&](auto &v) { return integer_value(v, scope); });
            if (types.size() == e.args.size())
            {
                for (std::size_t i = 0; i < types.size(); ++i)
                    require_expr(e.args[i], types[i], requirements);
            }
            else
                for (auto &arg : e.args)
                    expression(arg, requirements);
            return;
        }
        if (comparison(e))
        {
            auto left = type(e.args[0]), right = type(e.args[1]);
            require_expr(e.args[0], right, requirements);
            require_expr(e.args[1], left, requirements);
        }
        else
            for (auto &arg : e.args)
                expression(arg, requirements);
    }
    void definition(const std::string &name, Expr &e, Requirements &requirements)
    {
        std::optional<Requirement> requirement;
        if (auto explicit_hint = get(explicit_types, name))
            requirement = Requirement{ false, *explicit_hint };
        else if (auto existing = get(requirements, name))
        {
            requirement = *existing;
            requirements.erase(name);
        }
        else if (auto inferred = type(e); inferred.kind == ValueType::User)
            requirement = Requirement{ false, inferred };
        hints[name].push_front(requirement);
        if (requirement && !requirement->conflict)
            require_expr(e, requirement->type, requirements);
        else
            expression(e, requirements);
    }
    Requirements statement(Statement &s, Requirements requirements)
    {
        switch (s.kind)
        {
            case Statement::Variables:
                for (auto entry = s.declarations.rbegin(); entry != s.declarations.rend(); ++entry)
                {
                    if (entry->second)
                        definition(entry->first, *entry->second, requirements);
                    else
                        requirements.erase(entry->first);
                }
                break;
            case Statement::Assign:
            case Statement::AssignNoDiscard:
                if (s.operation == "=")
                    definition(s.name, s.expression, requirements);
                else
                {
                    compound.insert(s.name);
                    requirements.erase(s.name);
                    expression(s.expression, requirements);
                }
                break;
            case Statement::Expression:
            case Statement::Call:
                expression(s.expression, requirements);
                break;
            case Statement::If:
            {
                auto entered = statements(s.body, requirements);
                requirements = merge({ requirements, entered });
                expression(s.expression, requirements);
                break;
            }
            case Statement::IfElse:
            {
                auto no = statements(s.alternative, requirements),
                     yes = statements(s.body, requirements);
                requirements = merge({ yes, no });
                expression(s.expression, requirements);
                break;
            }
            case Statement::Switch:
            {
                std::optional<ValueType> case_type;
                bool conflict = false, has_default = false;
                for (auto &c : s.cases)
                {
                    if (c.kind == SwitchCase::Default || c.kind == SwitchCase::ImplicitDefault)
                        has_default = true;
                    for (auto &v : c.values)
                        if (auto value_type = type(v); value_type.kind == ValueType::User)
                        {
                            if (!case_type)
                                case_type = value_type;
                            else if (auto narrower = scope.narrower_type(*case_type, value_type))
                                case_type = *narrower;
                            else
                                conflict = true;
                        }
                }
                std::vector<Requirements> paths;
                if (!has_default)
                    paths.push_back(requirements);
                for (auto c = s.cases.rbegin(); c != s.cases.rend(); ++c)
                    paths.push_back(statements(c->body, requirements));
                requirements = merge(paths);
                if (!conflict && case_type)
                    require_expr(s.expression, *case_type, requirements);
                expression(s.expression, requirements);
                break;
            }
            case Statement::For:
            {
                auto update = statement(s.clauses[1], requirements);
                auto iterated = statements(s.body, std::move(update));
                expression(s.expression, iterated);
                requirements = merge({ requirements, iterated });
                requirements = statement(s.clauses[0], requirements);
                break;
            }
            case Statement::DoWhile:
                expression(s.expression, requirements);
                requirements = statements(s.body, requirements);
                break;
            case Statement::Exit:
                requirements.clear();
                break;
            default:
                break;
        }
        return requirements;
    }
};

struct State
{
    std::map<std::string, ValueType> types, overrides;
    std::map<std::string, std::string> origins;
    std::map<std::string, Integer> values;
};

template<class Map>
Map intersect(Map left, const Map &right)
{
    for (auto it = left.begin(); it != left.end();)
    {
        auto found = right.find(it->first);
        if (found == right.end() || found->second != it->second)
            it = left.erase(it);
        else
            ++it;
    }
    return left;
}

void mutated_expression(const Expr &e, std::set<std::string> &names)
{
    if (e.kind == Expr::Increment)
        names.insert(e.name);
    for (auto &arg : e.args)
        mutated_expression(arg, names);
}
void assigned(const std::vector<Statement> &body, std::set<std::string> &names)
{
    for (auto &s : body)
    {
        if (s.kind == Statement::Variables)
            for (auto &d : s.declarations)
            {
                names.insert(d.first);
                if (d.second)
                    mutated_expression(*d.second, names);
            }
        if (s.kind == Statement::Assign || s.kind == Statement::AssignNoDiscard)
            names.insert(s.name);
        if (s.kind != Statement::Constants)
            mutated_expression(s.expression, names);
        assigned(s.body, names);
        assigned(s.alternative, names);
        assigned(s.clauses, names);
        for (auto &c : s.cases)
            assigned(c.body, names);
    }
}
bool external_break(const std::vector<Statement> &body)
{
    for (auto &s : body)
    {
        if (s.kind == Statement::Break)
            return true;
        if (s.kind != Statement::Switch &&
            (external_break(s.body) || external_break(s.alternative)))
            return true;
    }
    return false;
}
struct Outcomes
{
    bool falls = true, exits = false, escapes = false;
};
Outcomes outcomes(const std::vector<Statement> &body)
{
    Outcomes result;
    for (auto &s : body)
    {
        if (!result.falls)
            break;
        Outcomes current;
        if (s.kind == Statement::Exit)
            current = { false, true, false };
        else if (s.kind == Statement::Break)
            current = { false, false, true };
        else if (s.kind == Statement::If)
        {
            current = outcomes(s.body);
            current.falls = true;
        }
        else if (s.kind == Statement::IfElse)
        {
            auto a = outcomes(s.body), b = outcomes(s.alternative);
            current = { a.falls || b.falls, a.exits || b.exits, a.escapes || b.escapes };
        }
        else if (s.kind == Statement::For || s.kind == Statement::DoWhile)
            current.escapes = external_break(s.body);
        result.exits = result.exits || current.exits;
        result.escapes = result.escapes || current.escapes;
        result.falls = current.falls;
    }
    return result;
}

// Forward decoration follows the live paths separately from physical string
// traversal. Unreachable code still owns its original STR references.
class Decorator
{
  public:
    Decorator(const ConstScope &scope,
              std::vector<std::string> strings,
              Hints hints,
              const std::set<std::string> &compound,
              const std::map<std::string, ValueType> &explicit_types)
      : scope(scope)
      , strings(std::move(strings))
      , hints(std::move(hints))
    {
        for (auto &entry : this->hints)
        {
            if (compound.count(entry.first))
                continue;
            std::optional<ValueType> common;
            for (auto &hint : entry.second)
            {
                if (!hint || hint->conflict)
                {
                    common.reset();
                    break;
                }
                common = common ? scope.narrower_type(*common, hint->type)
                                : std::optional<ValueType>(hint->type);
                if (!common)
                    break;
            }
            if (common)
                stable_types[entry.first] = *common;
        }
        for (auto &entry : explicit_types)
            stable_types[entry.first] = entry.second;
    }
    void statements(std::vector<Statement> &body);
    std::size_t strings_placed() const
    {
        return next_string;
    }

  private:
    const ConstScope &scope;
    std::vector<std::string> strings;
    std::size_t next_string = 0;
    Hints hints;
    std::map<std::string, ValueType> stable_types;
    State state;

    std::optional<Integer> integer(const Expr &e) const
    {
        return integer_value(e, scope, state.values);
    }
    ValueType type(const Expr &e) const
    {
        if (e.kind == Expr::Call)
            return call_type(e, scope, [&](auto &arg) { return integer(arg); }, state.overrides);
        if (e.kind == Expr::Name)
        {
            if (auto t = get(state.types, e.name))
                return *t;
            if (auto t = get(stable_types, e.name))
                return *t;
            if (auto t = get(scope.constant_types, e.name))
                return ValueType(*t);
        }
        return e.kind == Expr::Int   ? ValueType(ValueType::Integer)
               : e.kind == Expr::Str ? ValueType(ValueType::String)
                                     : ValueType{};
    }
    std::optional<std::string> origin(const Expr &e) const
    {
        return e.kind == Expr::Call   ? std::optional<std::string>(e.name)
               : e.kind == Expr::Name ? get(state.origins, e.name)
                                      : std::nullopt;
    }
    ValueType definition_type(const std::string &name, const Expr &e)
    {
        auto expression_type = type(e);
        auto found = hints.find(name);
        if (found == hints.end() || found->second.empty())
            return expression_type;
        auto hint = found->second.front();
        found->second.pop_front();
        if (!hint)
            return expression_type;
        if (hint->conflict)
            return ValueType::Integer;
        auto narrower = scope.narrower_type(hint->type, expression_type);
        return narrower                                       ? *narrower
               : expression_type.kind == ValueType::Undefined ? hint->type
                                                              : ValueType(ValueType::Integer);
    }
    void typed(Expr &e, ValueType expected) const;
    void expression(Expr &e);
    void invoke(Expr &e);
    void statement(Statement &s);
    State join(const State &a, const State &b, bool values) const;
    void refine(const Expr &condition, bool truth);
    void refine(const std::map<std::string, std::optional<ValueType>> &refinements);
    void related(const std::string &callable,
                 Integer value,
                 std::map<std::string, std::optional<ValueType>> &result) const;
    void collect_refinements(const Expr &condition,
                             bool truth,
                             std::map<std::string, std::optional<ValueType>> &result) const;
    void invalidate(const std::set<std::string> &names)
    {
        for (auto &name : names)
        {
            state.types.erase(name);
            state.origins.erase(name);
            state.values.erase(name);
        }
    }
};

void Decorator::typed(Expr &e, ValueType expected) const
{
    if (expected.kind != ValueType::User)
        return;
    if (e.kind == Expr::Call &&
        get(scope.typed_identities, e.name) == std::optional<std::string>(expected.name))
        return;
    if (e.kind == Expr::Int)
    {
        if (auto name = get(scope.typed_constants, std::make_pair(expected.name, e.value)))
            e = Expr::named(*name);
        else if (auto wrapper = get(scope.identity_names, expected.name))
            e = Expr::operation(Expr::Call, *wrapper, { std::move(e) });
        return;
    }
    std::optional<Integer> value;
    if (e.kind == Expr::Unary && e.name == "-")
    {
        auto positive = e.args[0].kind == Expr::Int    ? std::optional<Integer>(e.args[0].value)
                        : e.args[0].kind == Expr::Name ? scope.integer_constant(e.args[0].name)
                                                       : std::nullopt;
        if (positive && *positive != INT64_MIN)
            value = -*positive;
    }
    auto named =
        value ? get(scope.typed_constants, std::make_pair(expected.name, *value)) : std::nullopt;
    auto wrapper = get(scope.identity_names, expected.name);
    if (named)
        e = Expr::operation(Expr::Call, "mary_negated_int", { Expr::named(*named) });
    else if (value && wrapper)
        e = Expr::operation(
            Expr::Call,
            *wrapper,
            { Expr::operation(Expr::Call, "mary_negated_int", { Expr::integer(*value) }) });
    else if (!value && wrapper)
        e = Expr::operation(Expr::Call, *wrapper, { std::move(e) });
    else if (!value && e.kind == Expr::Binary && (e.name == "+" || e.name == "-"))
        typed(e.args[0], expected);
}

void Decorator::invoke(Expr &e)
{
    if (e.name == "mary_negated_int" || scope.typed_identities.count(e.name))
    {
        for (auto &arg : e.args)
            expression(arg);
        return;
    }
    auto found = scope.callables.find(e.name);
    if (found == scope.callables.end())
        throw std::runtime_error("cannot decorate unknown callable " + e.name);
    auto types = parameter_types(e, scope, [&](auto &arg) { return integer(arg); });
    if (types.size() != e.args.size())
        throw std::runtime_error("callable shape mismatch during decoration");
    std::optional<std::string> variable_type;
    if (e.name == "VarSet" && !e.args.empty())
        if (auto id = integer(e.args[0]))
            variable_type = get(scope.variable_types, *id);
    for (std::size_t i = 0; i < types.size(); ++i)
    {
        auto &arg = e.args[i];
        if (types[i].kind == ValueType::String)
        {
            if (arg.kind != Expr::Int || arg.value < 0 ||
                std::uint64_t(arg.value) >= strings.size() ||
                std::uint64_t(arg.value) > next_string)
                throw std::runtime_error("not enough ordered string consumers");
            if (std::size_t(arg.value) == next_string)
                ++next_string;
            arg = Expr::named(strings[std::size_t(arg.value)]);
        }
        else if (types[i].kind == ValueType::User)
        {
            auto value = arg.kind == Expr::Int    ? std::optional<Integer>(arg.value)
                         : arg.kind == Expr::Name ? scope.integer_constant(arg.name)
                                                  : std::nullopt;
            if (value)
            {
                if (auto name = get(scope.typed_constants, std::make_pair(types[i].name, *value)))
                    arg = Expr::named(*name);
                else if (auto wrapper = get(scope.identity_names, types[i].name))
                    arg = Expr::operation(Expr::Call, *wrapper, { Expr::integer(*value) });
            }
            else
            {
                typed(arg, types[i]);
                expression(arg);
            }
        }
        else
            expression(arg);
    }
    if (variable_type && e.args.size() > 1)
        typed(e.args[1], ValueType(*variable_type));
}

State Decorator::join(const State &a, const State &b, bool values) const
{
    State result{ intersect(a.types, b.types),
                  intersect(a.overrides, b.overrides),
                  intersect(a.origins, b.origins),
                  intersect(a.values, b.values) };
    if (!values)
        return result;
    std::set<std::string> names;
    for (auto &entry : a.types)
        names.insert(entry.first);
    for (auto &entry : b.types)
        names.insert(entry.first);
    for (auto &name : names)
    {
        if (result.types.count(name))
            continue;
        std::optional<ValueType> candidate;
        bool conflict = false;
        for (auto state : { &a, &b })
            if (auto type = get(state->types, name); type && type->kind == ValueType::User)
            {
                candidate = candidate ? scope.narrower_type(*candidate, *type) : type;
                if (!candidate)
                {
                    conflict = true;
                    break;
                }
            }
        if (conflict || !candidate)
            continue;
        bool compatible = true;
        for (auto state : { &a, &b })
        {
            auto type = get(state->types, name);
            if (type && type->kind == ValueType::User)
                compatible = compatible && scope.narrower_type(*candidate, *type).has_value();
            else if (!type || type->kind == ValueType::Integer)
            {
                auto value = get(state->values, name);
                compatible = compatible && value &&
                             (scope.typed_constants.count({ candidate->name, *value }) ||
                              scope.identity_names.count(candidate->name));
            }
            else
                compatible = false;
        }
        if (compatible)
            result.types[name] = *candidate;
    }
    return result;
}

void Decorator::related(const std::string &callable,
                        Integer value,
                        std::map<std::string, std::optional<ValueType>> &result) const
{
    for (auto &entry : scope.related_return_types)
        if (std::get<0>(entry.first) == callable && std::get<1>(entry.first) == value)
        {
            auto name = std::get<2>(entry.first);
            ValueType type(entry.second);
            auto found = result.find(name);
            if (found == result.end())
                result[name] = type;
            else if (found->second)
                found->second = scope.narrower_type(*found->second, type);
        }
}
void Decorator::collect_refinements(const Expr &e,
                                    bool truth,
                                    std::map<std::string, std::optional<ValueType>> &result) const
{
    if (e.kind == Expr::Binary && ((e.name == "&&" && truth) || (e.name == "||" && !truth)))
    {
        collect_refinements(e.args[0], truth, result);
        collect_refinements(e.args[1], truth, result);
        return;
    }
    if (e.kind == Expr::Unary && e.name == "!")
    {
        collect_refinements(e.args[0], !truth, result);
        return;
    }
    if (auto boolean = get(scope.constant_types, std::string("TRUE"));
        boolean && type(e) == ValueType(*boolean))
    {
        if (auto call = origin(e))
            if (auto value = scope.integer_constant(truth ? "TRUE" : "FALSE"))
                related(*call, *value, result);
        return;
    }
    if (e.kind != Expr::Binary || !((e.name == "==" && truth) || (e.name == "!=" && !truth)))
        return;
    for (unsigned i = 0; i < 2; ++i)
    {
        auto call = origin(e.args[i]);
        auto value = integer(e.args[1 - i]);
        if (call && value)
        {
            related(*call, *value, result);
            return;
        }
    }
}
void Decorator::refine(const std::map<std::string, std::optional<ValueType>> &refinements)
{
    for (auto &entry : refinements)
    {
        if (!entry.second)
        {
            state.overrides.erase(entry.first);
            for (auto &local : state.origins)
                if (local.second == entry.first)
                    state.types.erase(local.first);
            continue;
        }
        auto merge = [&](auto &map, const std::string &name)
        {
            auto old = get(map, name);
            auto type = old ? scope.narrower_type(*old, *entry.second) : entry.second;
            if (type)
                map[name] = *type;
            else
                map.erase(name);
        };
        merge(state.overrides, entry.first);
        for (auto &local : state.origins)
            if (local.second == entry.first)
                merge(state.types, local.first);
    }
}
void Decorator::refine(const Expr &e, bool truth)
{
    std::map<std::string, std::optional<ValueType>> refinements;
    collect_refinements(e, truth, refinements);
    refine(refinements);
}

void Decorator::expression(Expr &e)
{
    if (e.kind == Expr::Increment)
    {
        invalidate({ e.name });
        return;
    }
    if (e.kind == Expr::Call)
    {
        invoke(e);
        return;
    }
    if (e.kind == Expr::Unary && e.name == "-" && e.args[0].kind == Expr::Int &&
        e.args[0].value != INT64_MIN)
    {
        e = Expr::operation(Expr::Call, "mary_negated_int", { Expr::integer(-e.args[0].value) });
        return;
    }
    if (comparison(e))
    {
        auto a = type(e.args[0]), b = type(e.args[1]);
        typed(e.args[1], a);
        typed(e.args[0], b);
    }
    if (e.kind == Expr::Binary && (e.name == "&&" || e.name == "||"))
    {
        expression(e.args[0]);
        auto outer = state;
        refine(e.args[0], e.name == "&&");
        expression(e.args[1]);
        state = join(outer, state, true);
        return;
    }
    for (auto &arg : e.args)
        expression(arg);
}

void Decorator::statement(Statement &s)
{
    switch (s.kind)
    {
        case Statement::Variables:
            for (auto &entry : s.declarations)
                if (entry.second)
                {
                    auto t = definition_type(entry.first, *entry.second);
                    auto o = origin(*entry.second);
                    auto v = integer(*entry.second);
                    expression(*entry.second);
                    if (t.kind != ValueType::Undefined)
                        state.types[entry.first] = t;
                    if (o)
                        state.origins[entry.first] = *o;
                    if (v)
                        state.values[entry.first] = *v;
                    else
                        state.values.erase(entry.first);
                }
            break;
        case Statement::Constants:
            for (auto &entry : s.declarations)
                if (entry.second)
                    expression(*entry.second);
            break;
        case Statement::Assign:
        case Statement::AssignNoDiscard:
        {
            auto t =
                s.operation == "=" ? definition_type(s.name, s.expression) : type(s.expression);
            auto o = origin(s.expression);
            auto v = integer(s.expression);
            expression(s.expression);
            if (s.operation == "=" && t.kind != ValueType::Undefined)
                state.types[s.name] = t;
            else
                state.types.erase(s.name);
            if (s.operation == "=" && o)
                state.origins[s.name] = *o;
            else
                state.origins.erase(s.name);
            if (s.operation == "=" && v)
                state.values[s.name] = *v;
            else
                state.values.erase(s.name);
            break;
        }
        case Statement::Expression:
        case Statement::Call:
            expression(s.expression);
            break;
        case Statement::If:
        {
            expression(s.expression);
            auto outer = state;
            refine(s.expression, true);
            statements(s.body);
            auto flow = outcomes(s.body);
            auto entered = state;
            state.overrides = outer.overrides;
            if (flow.falls || flow.escapes)
            {
                state = join(outer, entered, true);
                state.overrides = outer.overrides;
            }
            else
            {
                state = outer;
                refine(s.expression, false);
            }
            break;
        }
        case Statement::IfElse:
        {
            expression(s.expression);
            auto outer = state;
            refine(s.expression, true);
            statements(s.body);
            auto yes = state;
            state = outer;
            refine(s.expression, false);
            statements(s.alternative);
            auto no = state;
            auto a = outcomes(s.body), b = outcomes(s.alternative);
            bool live_a = a.falls || a.escapes, live_b = b.falls || b.escapes;
            state = live_a ? (live_b ? join(yes, no, true) : yes) : (live_b ? no : outer);
            break;
        }
        case Statement::For:
        {
            bool has_break = external_break(s.body);
            statement(s.clauses[0]);
            auto entry = state;
            std::set<std::string> names;
            assigned(s.body, names);
            assigned({ s.clauses[1] }, names);
            invalidate(names);
            expression(s.expression);
            refine(s.expression, true);
            statements(s.body);
            statement(s.clauses[1]);
            state = join(entry, state, false);
            state.overrides = entry.overrides;
            if (!has_break)
                refine(s.expression, false);
            break;
        }
        case Statement::DoWhile:
        {
            bool has_break = external_break(s.body);
            std::set<std::string> names;
            assigned(s.body, names);
            invalidate(names);
            statements(s.body);
            expression(s.expression);
            if (!has_break)
                refine(s.expression, false);
            break;
        }
        case Statement::Switch:
        {
            auto expected = type(s.expression);
            auto discriminator = origin(s.expression);
            expression(s.expression);
            auto outer = state;
            bool has_default = std::any_of(
                s.cases.begin(),
                s.cases.end(),
                [](auto &c)
                { return c.kind == SwitchCase::Default || c.kind == SwitchCase::ImplicitDefault; });
            std::vector<State> exits;
            if (!has_default)
                exits.push_back(outer);
            std::optional<State> fallthrough;
            for (auto &c : s.cases)
            {
                state = outer;
                std::optional<State> labels;
                for (auto &value : c.values)
                {
                    state = outer;
                    auto raw = value.kind == Expr::Int    ? std::optional<Integer>(value.value)
                               : value.kind == Expr::Name ? scope.integer_constant(value.name)
                                                          : std::nullopt;
                    if (discriminator && raw)
                    {
                        std::map<std::string, std::optional<ValueType>> refinements;
                        related(*discriminator, *raw, refinements);
                        refine(refinements);
                    }
                    typed(value, expected);
                    expression(value);
                    labels = labels ? std::optional<State>(join(*labels, state, true))
                                    : std::optional<State>(state);
                }
                if (labels)
                    state = *labels;
                if (fallthrough)
                {
                    state = join(state, *fallthrough, true);
                    fallthrough.reset();
                }
                auto flow = outcomes(c.body);
                std::set<std::string> names;
                assigned(c.body, names);
                auto overrides = state.overrides;
                statements(c.body);
                if (flow.escapes && (flow.falls || flow.exits))
                {
                    invalidate(names);
                    state.overrides = overrides;
                }
                if (!flow.falls && flow.exits && !flow.escapes)
                    fallthrough.reset();
                else if (c.fallthrough || c.kind == SwitchCase::ImplicitDefault ||
                         c.kind == SwitchCase::DeadJump)
                    fallthrough = state;
                else
                    exits.push_back(state);
            }
            if (fallthrough)
                exits.push_back(*fallthrough);
            state = exits.empty() ? State{} : exits[0];
            for (std::size_t i = 1; i < exits.size(); ++i)
                state = join(state, exits[i], false);
            break;
        }
        default:
            break;
    }
}

void Decorator::statements(std::vector<Statement> &body)
{
    std::optional<State> terminal;
    for (auto &s : body)
    {
        statement(s);
        if (!terminal)
        {
            auto flow = outcomes({ s });
            if (!flow.falls && (flow.exits || flow.escapes))
                terminal = state;
        }
    }
    if (terminal)
        state = *terminal;
}

} // namespace

std::vector<Statement> decompile_script(const Script &script,
                                        const ConstScope &scope,
                                        const std::string &name,
                                        const std::vector<std::optional<std::string>> &text_names,
                                        const std::map<std::string, ValueType> &local_types)
{
    auto statements = decompile_instructions(script.instructions, scope);
    std::vector<std::string> strings;
    std::vector<Statement> body;
    for (std::size_t i = 0; i < script.strings.size(); ++i)
    {
        std::ostringstream generated;
        if (name.empty())
            generated << "MESSAGE_" << i;
        else
        {
            generated << "gText_" << name << "_";
            generated.width(3);
            generated.fill('0');
            generated << i;
        }
        auto symbol = i < text_names.size() && text_names[i] ? *text_names[i] : generated.str();
        strings.push_back(symbol);
        Statement s;
        s.kind = Statement::Constants;
        s.declarations.emplace_back(symbol, Expr::string(script.strings[i]));
        body.push_back(std::move(s));
    }
    body.insert(body.end(),
                std::make_move_iterator(statements.begin()),
                std::make_move_iterator(statements.end()));
    std::set<std::string> names;
    assigned(body, names);
    for (auto &entry : local_types)
        if (!names.count(entry.first))
            throw std::runtime_error("unknown local type hint: " + entry.first);
    Backpropagator back(scope, local_types);
    back.statements(body);
    Decorator visitor(scope, std::move(strings), std::move(back.hints), back.compound, local_types);
    visitor.statements(body);
    if (visitor.strings_placed() < script.strings.size())
        throw std::runtime_error("not enough ordered string consumers");
    return body;
}

} // namespace mary
