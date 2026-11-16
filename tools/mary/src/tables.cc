#include "tables.hh"
#include "constant_expr.hh"
#include "lexer.hh"

#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace mary
{
namespace
{

Integer expression(Tokens &tokens, const ConstScope &scope, std::string_view ending)
{
    std::string text;
    unsigned nesting = 0;
    while (!tokens.end())
    {
        if (!nesting && tokens.is(ending))
            break;
        if (tokens.is("("))
            ++nesting;
        else if (tokens.is(")"))
        {
            if (!nesting)
                tokens.error("unexpected ')' in constant expression");
            --nesting;
        }
        text += tokens.take().text + " ";
    }
    return evaluate_constant(text, [&](auto name) { return scope.integer_constant(name); });
}

std::string known_type(Tokens &tokens, const ConstScope &scope)
{
    auto name = tokens.identifier();
    if (!scope.user_types.count(name))
        tokens.error("metadata references unknown type '" + name + "'");
    return name;
}

std::size_t nonnegative(Integer value, Tokens &tokens)
{
    if (value < 0 || static_cast<std::uint64_t>(value) > SIZE_MAX)
        tokens.error("index must be nonnegative and fit the host size type");
    return static_cast<std::size_t>(value);
}

template<class Map, class Key, class Value>
void insert_unique(Map &map, Key key, Value value, Tokens &tokens)
{
    if (!map.emplace(std::move(key), std::move(value)).second)
        tokens.error("metadata declares the same binding more than once");
}

void metadata(Tokens &tokens, ConstScope &scope)
{
    auto name = tokens.identifier();
    tokens.require("(");
    auto comma = [&] { tokens.require(","); };
    auto number = [&] { return expression(tokens, scope, ","); };
    if (name == "mary_type_subset")
    {
        auto child = known_type(tokens, scope);
        comma();
        auto parent = known_type(tokens, scope);
        if (scope.is_subset(parent, child))
            tokens.error("type subset would create a cycle");
        if (!scope.type_subsets.emplace(child, parent).second)
            tokens.error("duplicate type subset");
    }
    else if (name == "mary_typed_identity")
    {
        auto type = known_type(tokens, scope);
        comma();
        auto wrapper = tokens.identifier();
        if (scope.typed_identities.count(wrapper) || scope.identity_names.count(type) ||
            scope.constants.count(wrapper) || scope.callables.count(wrapper))
            tokens.error("typed identity redeclares a type or name");
        scope.typed_identities[wrapper] = type;
        scope.identity_names[type] = wrapper;
    }
    else if (name == "mary_var_type")
    {
        auto variable = tokens.identifier();
        comma();
        auto value = scope.integer_constant(variable);
        if (!value)
            tokens.error("variable type references an unknown variable symbol");
        auto type = known_type(tokens, scope);
        insert_unique(scope.variable_types, *value, type, tokens);
    }
    else if (name == "mary_callable_return_type_when")
    {
        auto callable = tokens.identifier();
        comma();
        auto index = nonnegative(number(), tokens);
        comma();
        auto value = number();
        comma();
        auto type = known_type(tokens, scope);
        insert_unique(
            scope.dependent_return_types, std::make_tuple(callable, index, value), type, tokens);
    }
    else if (name == "mary_callable_parameter_type_when")
    {
        auto callable = tokens.identifier();
        comma();
        auto discriminator = nonnegative(number(), tokens);
        comma();
        auto value = number();
        comma();
        auto target = nonnegative(number(), tokens);
        comma();
        auto type = known_type(tokens, scope);
        insert_unique(scope.dependent_parameter_types,
                      std::make_tuple(callable, discriminator, value, target),
                      type,
                      tokens);
    }
    else if (name == "mary_callable_return_type_when_callable")
    {
        auto callable = tokens.identifier();
        comma();
        auto discriminator = tokens.identifier();
        comma();
        auto value = number();
        comma();
        auto type = known_type(tokens, scope);
        insert_unique(scope.related_return_types,
                      std::make_tuple(discriminator, value, callable),
                      type,
                      tokens);
    }
    else
        tokens.error("unknown constant metadata directive '" + name + "'");
    tokens.require(")");
    tokens.require(";");
}

ValueType value_type(Tokens &tokens, ConstScope &scope, bool allow_void)
{
    if (tokens.eat("int"))
        return ValueType::Integer;
    if (allow_void && tokens.eat("void"))
        return ValueType::Undefined;
    if (tokens.eat("const"))
    {
        tokens.require("char");
        tokens.require("*");
        return ValueType::String;
    }
    auto name = tokens.identifier();
    scope.user_types.insert(name);
    return ValueType(std::move(name));
}

std::pair<std::string, Callable> prototype(Tokens &tokens, ConstScope &scope)
{
    auto result = value_type(tokens, scope, true);
    auto name = tokens.identifier();
    tokens.require("(");
    std::vector<ValueType> params;
    if (tokens.eat("void"))
    {
        if (!tokens.is(")"))
            tokens.error("void must be the only parameter");
    }
    else if (!tokens.is(")"))
        do
        {
            params.push_back(value_type(tokens, scope, false));
            tokens.identifier();
        } while (tokens.eat(","));
    tokens.require(")");
    tokens.require(";");
    return { name, Callable{ 0, result, std::move(params) } };
}

std::vector<std::optional<std::string>> ordered_slots(Tokens &tokens)
{
    tokens.require("{");
    std::vector<std::optional<std::string>> slots;
    std::set<std::string> names;
    while (!tokens.eat("}"))
    {
        if (tokens.eat("NULL"))
            slots.emplace_back();
        else
        {
            auto name = tokens.identifier();
            if (!names.insert(name).second)
                tokens.error("duplicate table symbol '" + name + "'");
            slots.emplace_back(std::move(name));
        }
        if (!tokens.eat(",") && !tokens.is("}"))
            tokens.error("expected ',' or '}' after table slot");
    }
    tokens.eat(";");
    return slots;
}

} // namespace

ConstScope parse_constant_header(std::string_view source, const Options &options)
{
    auto processed = preprocess(source, options);
    Tokens tokens(lex(processed.text));
    ConstScope scope;
    scope.macros = std::move(processed.macros);
    std::set<std::pair<std::string, Integer>> values;
    while (!tokens.end())
    {
        if (!tokens.eat("typedef"))
        {
            metadata(tokens, scope);
            continue;
        }
        if (tokens.eat("int"))
        {
            scope.user_types.insert(tokens.identifier());
            tokens.require(";");
            continue;
        }
        tokens.require("enum");
        auto type = tokens.identifier();
        scope.user_types.insert(type);
        tokens.require("{");
        while (!tokens.eat("}"))
        {
            auto name = tokens.identifier();
            tokens.require("=");
            auto value = expression(tokens, scope, ",");
            tokens.require(",");
            if (!values.emplace(type, value).second)
                tokens.error("enum assigns the same value twice");
            scope.add_typed_constant(type, name, value);
        }
        if (tokens.identifier() != type)
            tokens.error("enum closing type differs from its opening type");
        tokens.require(";");
    }
    return scope;
}

CallableTable parse_callable_table(std::string_view source,
                                   const Options &options,
                                   const ConstScope &scope)
{
    auto processed = preprocess(source, options, scope.macros);
    Tokens tokens(lex(processed.text));
    tokens.require("mary_callable_table");
    CallableTable result;
    result.scope = scope;
    std::set<std::string> names;
    if (tokens.is("{"))
    {
        result.name = "MARY_CALLABLES";
        auto slots = ordered_slots(tokens);
        std::map<std::string, Callable> declarations;
        while (!tokens.end())
        {
            auto declared = prototype(tokens, result.scope);
            auto name = declared.first;
            if (!declarations.emplace(name, std::move(declared.second)).second)
                tokens.error("duplicate callable prototype '" + name + "'");
        }
        for (std::size_t i = 0; i < slots.size(); ++i)
        {
            if (!slots[i])
                continue;
            auto found = declarations.find(*slots[i]);
            if (found == declarations.end())
                tokens.error("callable has a slot but no prototype: " + *slots[i]);
            if (i > UINT32_MAX)
                tokens.error("callable ID exceeds VM space");
            found->second.id = static_cast<std::uint32_t>(i);
            result.scope.callables[*slots[i]] = found->second;
        }
        result.next_id = slots.size();
    }
    else
    {
        tokens.require("(");
        result.name = tokens.identifier();
        tokens.require(",");
        result.base = nonnegative(tokens.integer(), tokens);
        result.next_id = result.base;
        tokens.require(")");
        tokens.require("{");
        while (!tokens.eat("}"))
        {
            if (tokens.eat("mary_unknown"))
            {
                tokens.require("(");
                tokens.identifier();
                tokens.require(")");
                tokens.require(";");
            }
            else if (tokens.eat("mary_reserved"))
            {
                tokens.require("(");
                tokens.require(")");
                tokens.require(";");
            }
            else
            {
                auto declared = prototype(tokens, result.scope);
                if (!names.insert(declared.first).second)
                    tokens.error("duplicate callable name");
                if (result.next_id > UINT32_MAX)
                    tokens.error("callable ID exceeds VM space");
                declared.second.id = static_cast<std::uint32_t>(result.next_id);
                result.scope.callables[declared.first] = std::move(declared.second);
            }
            if (result.next_id == SIZE_MAX)
                tokens.error("callable table overflows host index");
            ++result.next_id;
        }
        tokens.eat(";");
        if (!tokens.end())
            tokens.error("unexpected text after callable table");
    }
    result.scope.validate_callable_metadata();
    return result;
}

ScriptTable ScriptTable::from_slots(std::vector<std::optional<std::string>> slots)
{
    ScriptTable result;
    result.slots = std::move(slots);
    for (std::size_t i = 0; i < result.slots.size(); ++i)
    {
        if (!result.slots[i])
            continue;
        if (i > UINT32_MAX)
            throw std::runtime_error("script table exceeds VM ID space");
        if (!result.ids.emplace(*result.slots[i], Integer(i)).second)
            throw std::runtime_error("duplicate script symbol");
    }
    return result;
}

void ScriptTable::add_constants(ConstScope &scope) const
{
    for (auto &entry : ids)
        scope.add_typed_constant("MaryScriptId", entry.first, entry.second);
}

ScriptTable parse_script_table(std::string_view source, const Options &options)
{
    Tokens tokens(lex(preprocess(source, options).text));
    tokens.require("mary_script_table");
    auto result = ScriptTable::from_slots(ordered_slots(tokens));
    if (!tokens.end())
        tokens.error("unexpected text after script table");
    return result;
}

ScriptTable ScriptSymbols::script_table() const
{
    std::vector<std::optional<std::string>> names;
    for (auto &slot : slots)
        names.push_back(slot ? std::optional<std::string>(slot->name) : std::nullopt);
    return ScriptTable::from_slots(std::move(names));
}

ScriptSymbols parse_text_name_table(std::string_view source, const Options &options)
{
    Tokens tokens(lex(preprocess(source, options).text));
    tokens.require("mary_script_symbols");
    tokens.require("{");
    ScriptSymbols result;
    std::set<std::string> names;
    while (!tokens.eat("}"))
    {
        if (tokens.eat("NULL"))
            result.slots.emplace_back();
        else
        {
            ScriptSymbol script;
            script.name = tokens.identifier();
            if (!names.insert(script.name).second)
                tokens.error("duplicate script symbol");
            tokens.require("{");
            std::set<std::string> text_names;
            while (!tokens.eat("}"))
            {
                if (tokens.eat("mary_local_type"))
                {
                    tokens.require("(");
                    auto local = tokens.identifier();
                    if (local.size() <= 4 || local.substr(0, 4) != "var_" ||
                        !std::all_of(local.begin() + 4,
                                     local.end(),
                                     [](unsigned char c) { return std::isdigit(c); }))
                        tokens.error("local type name must use generated var_N form");
                    tokens.require(",");
                    auto type = tokens.identifier();
                    tokens.require(")");
                    if (!script.local_types.emplace(local, type).second)
                        tokens.error("duplicate local type");
                }
                else
                {
                    auto name = tokens.identifier();
                    if (!text_names.insert(name).second)
                        tokens.error("duplicate text symbol");
                    script.texts.push_back(std::move(name));
                }
                if (!tokens.eat(",") && !tokens.is("}"))
                    tokens.error("expected ',' or '}' after symbol");
            }
            result.slots.emplace_back(std::move(script));
        }
        if (!tokens.eat(",") && !tokens.is("}"))
            tokens.error("expected ',' or '}' after script symbol");
    }
    tokens.eat(";");
    if (!tokens.end())
        tokens.error("unexpected text after symbol table");
    return result;
}

} // namespace mary
