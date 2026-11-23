#include "mary_c.hh"
#include "constant_expr.hh"
#include "lexer.hh"
#include "low_level.hh"

#include <algorithm>
#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{

unsigned precedence(std::string_view op)
{
    if (op == "||")
        return 1;
    if (op == "&&")
        return 2;
    if (op == "|")
        return 3;
    if (op == "^")
        return 4;
    if (op == "&")
        return 5;
    if (op == "==" || op == "!=")
        return 6;
    if (op == "<" || op == "<=" || op == ">" || op == ">=")
        return 7;
    if (op == "<<" || op == ">>")
        return 8;
    if (op == "+" || op == "-")
        return 9;
    if (op == "*" || op == "/" || op == "%")
        return 10;
    return 0;
}

bool assignment(std::string_view value)
{
    return value == "=" || value == "+=" || value == "-=" || value == "*=" || value == "/=" ||
           value == "%=";
}

class Parser
{
  public:
    Parser(std::vector<Token> input, const ConstScope &scope, const SourceLines *locations)
      : tokens(std::move(input), locations)
      , scope(scope)
    {
    }

    std::vector<NamedScript> scripts(const ScriptTable *table)
    {
        auto text = text_table();
        std::vector<NamedScript> result;
        std::set<Integer> ids;
        std::set<std::string> names;
        while (!tokens.end())
        {
            std::optional<Integer> explicit_id;
            if (tokens.eat("mary_script"))
            {
                tokens.require("(");
                if (tokens.peek().kind != TokenKind::Integer)
                    tokens.error("mary_script requires an unsigned integer ID");
                explicit_id = tokens.take().integer;
                if (*explicit_id < 0 || *explicit_id > UINT32_MAX)
                    tokens.error("script ID exceeds VM space");
                tokens.require(")");
            }
            tokens.require("void");
            auto name = tokens.identifier();
            tokens.require("(");
            tokens.require("void");
            tokens.require(")");
            Integer id;
            if (explicit_id)
                id = *explicit_id;
            else
            {
                if (!table)
                    tokens.error("plain definitions require a mary_script_table");
                auto found = table->ids.find(name);
                if (found == table->ids.end())
                    tokens.error("script is not present in mary_script_table: " + name);
                id = found->second;
            }
            if (!ids.insert(id).second || !names.insert(name).second)
                tokens.error("duplicate script name or ID");
            auto body = block();
            if (!text.first.empty())
            {
                if (!result.empty())
                    tokens.error("mary_text_table may belong to only one script per source file");
                body.insert(body.begin(), text.first.begin(), text.first.end());
            }
            validate_calls(body, scope);
            const bool raw = body.size() == 1 && body[0].kind == Statement::Ir;
            auto compiled = compile_script(std::move(body), scope);
            auto text_names = text.second;
            std::vector<std::size_t> text_lines;
            for (const auto &text_name : text_names)
                text_lines.push_back(text_positions.at(text_name));
            if (raw)
                for (std::size_t i = 0; i < compiled.strings.size(); ++i)
                {
                    std::ostringstream symbol;
                    symbol << "gText_" << name << "_";
                    symbol.width(3);
                    symbol.fill('0');
                    symbol << i;
                    text_names.push_back(symbol.str());
                }
            result.push_back({ id, std::move(name), std::move(compiled), std::move(text_names),
                               std::move(text_lines) });
        }
        return result;
    }

  private:
    Tokens tokens;
    const ConstScope &scope;
    std::map<std::string, std::size_t> text_positions;
    // true means switch; false means loop. This distinguishes C break from
    // the explicit cross-loop mary_break_switch form.
    std::vector<bool> controls;
    std::vector<std::map<std::string, std::optional<Constant>>> constants{ 1 };

    std::optional<Constant> constant(const Expr &expr) const
    {
        return constant_value(
            expr,
            [&](const std::string &name) -> std::optional<Constant>
            {
                for (auto frame = constants.rbegin(); frame != constants.rend(); ++frame)
                {
                    auto found = frame->find(name);
                    if (found != frame->end())
                        return found->second;
                }
                auto found = scope.constants.find(name);
                return found != scope.constants.end() ? std::optional<Constant>(found->second)
                                                      : std::nullopt;
            });
    }

    std::pair<std::string, Expr> text_declaration(bool require_const = true)
    {
        if (require_const)
            tokens.require("const");
        tokens.require("char");
        const auto line = tokens.peek().line;
        auto name = tokens.identifier();
        tokens.require("[");
        tokens.require("]");
        tokens.require("=");
        if (tokens.peek().kind != TokenKind::String)
            tokens.error("text declaration requires string literals");
        Bytes bytes;
        while (tokens.peek().kind == TokenKind::String)
        {
            auto part = tokens.take();
            bytes.insert(bytes.end(), part.bytes.begin(), part.bytes.end());
        }
        tokens.require(";");
        text_positions.emplace(name, line);
        return { std::move(name), Expr::string(std::move(bytes)) };
    }

    std::pair<std::vector<Statement>, std::vector<std::string>> text_table()
    {
        std::vector<Statement> result;
        std::vector<std::string> names;
        if (!tokens.eat("mary_text_table"))
            return { result, names };
        tokens.require("{");
        std::map<std::string, Expr> declarations;
        if (tokens.is("const"))
        {
            while (!tokens.eat("}"))
            {
                auto declaration = text_declaration();
                names.push_back(declaration.first);
                if (!declarations.emplace(declaration.first, std::move(declaration.second)).second)
                    tokens.error("duplicate text declaration");
            }
            tokens.eat(";");
        }
        else
        {
            std::set<std::string> used;
            while (!tokens.eat("}"))
            {
                auto name = tokens.identifier();
                if (!used.insert(name).second)
                    tokens.error("duplicate text slot");
                names.push_back(std::move(name));
                if (!tokens.eat(",") && !tokens.is("}"))
                    tokens.error("expected ',' or '}' after text slot");
            }
            tokens.eat(";");
            while (tokens.eat("const"))
            {
                auto declaration = text_declaration(false);
                if (!declarations.emplace(declaration.first, std::move(declaration.second)).second)
                    tokens.error("duplicate text declaration");
            }
        }
        for (auto &name : names)
        {
            auto found = declarations.find(name);
            if (found == declarations.end())
                tokens.error("text has a slot but no declaration: " + name);
            Statement statement;
            statement.kind = Statement::Constants;
            statement.declarations.emplace_back(name, std::move(found->second));
            result.push_back(std::move(statement));
            declarations.erase(found);
        }
        if (!declarations.empty())
            tokens.error("text declaration has no table slot");
        return { std::move(result), std::move(names) };
    }

    std::vector<Statement> block()
    {
        tokens.require("{");
        constants.emplace_back();
        std::vector<Statement> result;
        while (!tokens.eat("}"))
        {
            if (tokens.end())
                tokens.error("unterminated block");
            if (sequence_terminates(result))
                tokens.error("unreachable statement after return or break");
            result.push_back(stmt());
        }
        constants.pop_back();
        return result;
    }

    Statement declarations(bool require_initializer)
    {
        Statement result;
        result.kind = require_initializer ? Statement::Constants : Statement::Variables;
        do
        {
            auto name = tokens.identifier();
            constants.back()[name] = std::nullopt;
            std::optional<Expr> value;
            if (tokens.eat("="))
                value = expression();
            else if (require_initializer)
                tokens.error("constant requires an initializer");
            if (require_initializer)
                constants.back()[name] = constant(*value);
            result.declarations.emplace_back(std::move(name), std::move(value));
        } while (tokens.eat(","));
        return result;
    }

    Statement assignment_statement()
    {
        Statement result;
        result.kind = Statement::Assign;
        result.name = tokens.identifier();
        if (!assignment(tokens.peek().text))
            tokens.error("expected assignment operator");
        result.operation = tokens.take().text;
        result.expression = expression();
        return result;
    }

    Statement simple()
    {
        if (tokens.peek().kind == TokenKind::Identifier && assignment(tokens.peek(1).text))
            return assignment_statement();
        Statement result;
        result.expression = expression();
        result.kind =
            result.expression.kind == Expr::Call ? Statement::Call : Statement::Expression;
        return result;
    }

    Expr parenthesized()
    {
        tokens.require("(");
        auto result = expression();
        tokens.require(")");
        return result;
    }

    Statement stmt()
    {
        const auto line = tokens.peek().line;
        auto result = statement();
        result.source_line = line;
        return result;
    }

    Statement statement()
    {
        if (tokens.eat("mary_ir"))
        {
            Statement result;
            result.kind = Statement::Ir;
            result.raw_ir = parse_ir(tokens);
            return result;
        }
        if (tokens.eat("int"))
        {
            auto result = declarations(false);
            tokens.require(";");
            return result;
        }
        if (tokens.eat("const"))
        {
            if (!tokens.eat("int"))
            {
                tokens.require("char");
                tokens.require("*");
            }
            auto result = declarations(true);
            tokens.require(";");
            return result;
        }
        Statement result;
        if (tokens.eat("if"))
        {
            result.kind = Statement::If;
            result.expression = parenthesized();
            result.body = block();
            if (tokens.eat("else"))
            {
                result.kind = Statement::IfElse;
                result.alternative = tokens.is("if") ? std::vector<Statement>{ stmt() } : block();
            }
            return result;
        }
        if (tokens.eat("do"))
        {
            result.kind = Statement::DoWhile;
            controls.push_back(false);
            result.body = block();
            controls.pop_back();
            result.condition_line = tokens.peek().line;
            tokens.require("while");
            result.expression = parenthesized();
            tokens.require(";");
            return result;
        }
        if (tokens.eat("for"))
        {
            constants.emplace_back();
            result.kind = Statement::For;
            tokens.require("(");
            const auto init_line = tokens.peek().line;
            result.clauses.push_back(tokens.eat("int") ? declarations(false) : simple());
            result.clauses.back().source_line = init_line;
            tokens.require(";");
            result.condition_line = tokens.peek().line;
            result.expression = expression();
            tokens.require(";");
            const auto update_line = tokens.peek().line;
            result.clauses.push_back(simple());
            result.clauses.back().source_line = update_line;
            tokens.require(")");
            controls.push_back(false);
            result.body = block();
            controls.pop_back();
            constants.pop_back();
            return result;
        }
        if (tokens.is("switch") || tokens.is("mary_switch_compact"))
        {
            result.kind = Statement::Switch;
            result.compact = tokens.take().text == "mary_switch_compact";
            result.expression = parenthesized();
            tokens.require("{");
            constants.emplace_back();
            controls.push_back(true);
            while (!tokens.eat("}"))
            {
                SwitchCase c;
                if (tokens.eat("case"))
                {
                    do
                    {
                        c.values.push_back(expression());
                        tokens.require(":");
                    } while (tokens.eat("case"));
                }
                else if (tokens.eat("default"))
                {
                    c.kind = SwitchCase::Default;
                    tokens.require(":");
                }
                else if (tokens.eat("mary_implicit_default"))
                {
                    c.kind = SwitchCase::ImplicitDefault;
                    tokens.require(":");
                }
                else if (tokens.eat("mary_dead_jump"))
                {
                    c.kind = SwitchCase::DeadJump;
                    tokens.require(":");
                }
                else
                    tokens.error("expected case/default label");
                while (!tokens.is("}") && !tokens.is("case") && !tokens.is("default") &&
                       !tokens.is("mary_implicit_default") && !tokens.is("mary_dead_jump"))
                {
                    if (tokens.end())
                        tokens.error("unterminated switch");
                    if (sequence_terminates(c.body))
                        tokens.error("unreachable statement after return or break");
                    c.body.push_back(stmt());
                }
                c.fallthrough = (c.kind == SwitchCase::Values || c.kind == SwitchCase::Default) &&
                                !sequence_terminates(c.body);
                result.cases.push_back(std::move(c));
            }
            controls.pop_back();
            constants.pop_back();
            return result;
        }
        if (tokens.eat("return"))
        {
            tokens.require(";");
            return result;
        }
        if (tokens.eat("break"))
        {
            if (controls.empty() || !controls.back())
                tokens.error("standard break must target the nearest switch");
            result.kind = Statement::Break;
            tokens.require(";");
            return result;
        }
        if (tokens.eat("mary_break_switch"))
        {
            if (std::find(controls.begin(), controls.end(), true) == controls.end())
                tokens.error("mary_break_switch requires an enclosing switch");
            result.kind = Statement::Break;
            tokens.require(";");
            return result;
        }
        if (tokens.eat("mary_nodisc"))
        {
            tokens.require("(");
            result = assignment_statement();
            result.kind = Statement::AssignNoDiscard;
            tokens.require(")");
            tokens.require(";");
            return result;
        }
        result = simple();
        tokens.require(";");
        return result;
    }

    Expr primary()
    {
        if (tokens.is("("))
            return parenthesized();
        auto token = tokens.take();
        if (token.kind == TokenKind::Integer)
            return Expr::integer(token.integer);
        if (token.kind == TokenKind::String)
            return Expr::string(std::move(token.bytes));
        if (token.kind != TokenKind::Identifier)
            tokens.error("expected expression");
        if (tokens.eat("("))
        {
            std::vector<Expr> args;
            if (!tokens.eat(")"))
            {
                do
                {
                    args.push_back(expression());
                } while (tokens.eat(","));
                tokens.require(")");
            }
            return Expr::operation(Expr::Call, std::move(token.text), std::move(args));
        }
        auto result = Expr::named(std::move(token.text));
        if (tokens.is("++") || tokens.is("--"))
        {
            result.kind = Expr::Increment;
            result.value = tokens.take().text == "++" ? 1 : -1;
        }
        return result;
    }

    Expr expression(unsigned minimum = 0)
    {
        Expr left;
        if (tokens.eat("+"))
            left = expression(11);
        else if (tokens.eat("~"))
        {
            auto value = constant(expression(11));
            if (!value || !std::holds_alternative<Integer>(*value))
                tokens.error("bitwise operators require integer constant operands");
            left = Expr::integer(~std::get<Integer>(*value));
        }
        else if (tokens.is("-") || tokens.is("!"))
        {
            auto op = tokens.take().text;
            left = Expr::operation(Expr::Unary, std::move(op), { expression(11) });
        }
        else if (tokens.is("++") || tokens.is("--"))
        {
            auto op = tokens.take().text;
            left = Expr::named(tokens.identifier());
            left.kind = Expr::Increment;
            left.value = op == "++" ? 2 : -2;
        }
        else
            left = primary();
        for (;;)
        {
            auto priority = precedence(tokens.peek().text);
            if (!priority || priority < minimum)
                break;
            auto op = tokens.take().text;
            auto right = expression(priority + 1);
            if (op == "&" || op == "|" || op == "^" || op == "<<" || op == ">>")
            {
                auto a = constant(left), b = constant(right);
                if (!a || !b || !std::holds_alternative<Integer>(*a) ||
                    !std::holds_alternative<Integer>(*b))
                    tokens.error("bitwise operators require integer constant operands");
                left = Expr::integer(
                    apply_integer_operator(op, std::get<Integer>(*a), std::get<Integer>(*b)));
            }
            else
                left = Expr::operation(
                    Expr::Binary, std::move(op), { std::move(left), std::move(right) });
        }
        return left;
    }
};

} // namespace

void validate_calls(const std::vector<Statement> &body, const ConstScope &scope)
{
    std::map<std::string, bool> string_locals;
    auto is_string = [&](const Expr &e)
    {
        if (e.kind == Expr::Str)
            return true;
        if (e.kind != Expr::Name)
            return false;
        auto local = string_locals.find(e.name);
        if (local != string_locals.end())
            return local->second;
        auto found = scope.constants.find(e.name);
        return found != scope.constants.end() && std::holds_alternative<Bytes>(found->second);
    };
    std::vector<const Statement *> pending;
    std::vector<const Expr *> expressions;
    auto add = [&](const std::vector<Statement> &v)
    {
        for (auto &s : v)
            pending.push_back(&s);
    };
    add(body);
    while (!pending.empty())
    {
        auto s = pending.back();
        pending.pop_back();
        for (auto &entry : s->declarations)
        {
            string_locals[entry.first] =
                s->kind == Statement::Constants && entry.second && is_string(*entry.second);
            if (entry.second)
                expressions.push_back(&*entry.second);
        }
        expressions.push_back(&s->expression);
        add(s->body);
        add(s->alternative);
        add(s->clauses);
        for (auto &c : s->cases)
        {
            add(c.body);
            for (auto &value : c.values)
                expressions.push_back(&value);
        }
    }
    while (!expressions.empty())
    {
        auto e = expressions.back();
        expressions.pop_back();
        for (auto &arg : e->args)
            expressions.push_back(&arg);
        if (e->kind != Expr::Call)
            continue;
        auto call = scope.callables.find(e->name);
        if (call == scope.callables.end())
            continue;
        if (call->second.parameters.size() != e->args.size())
            throw std::runtime_error("wrong argument count for '" + e->name + "'");
        for (std::size_t i = 0; i < e->args.size(); ++i)
        {
            auto expected = call->second.parameters[i].kind;
            if (expected != ValueType::Undefined &&
                (expected == ValueType::String) != is_string(e->args[i]))
                throw std::runtime_error("argument type mismatch for '" + e->name + "'");
        }
    }
}

std::vector<NamedScript> parse_mary_c(std::string_view source,
                                      const Options &options,
                                      const ConstScope &scope,
                                      const ScriptTable *scripts,
                                      const Charmap *map)
{
    return parse_mary_c(preprocess(source, options, scope.macros), scope, scripts, map);
}

std::vector<NamedScript> parse_mary_c(const Preprocessed &source,
                                     const ConstScope &scope,
                                     const ScriptTable *scripts,
                                     const Charmap *map)
{
    auto combined = scope;
    if (scripts)
        scripts->add_constants(combined);
    return Parser(lex(source.text, map, false, &source.locations), combined, &source.locations)
        .scripts(scripts);
}

std::vector<std::string> discover_script_names(std::string_view source, const Options &options)
{
    return discover_script_names(preprocess(source, options));
}

std::vector<std::string> discover_script_names(const Preprocessed &source)
{
    auto tokens = lex(source.text, nullptr, false, &source.locations);
    std::vector<std::string> names;
    for (std::size_t i = 0; i + 5 < tokens.size(); ++i)
        if (tokens[i].text == "void" && tokens[i + 1].kind == TokenKind::Identifier &&
            tokens[i + 2].text == "(" && tokens[i + 3].text == "void" &&
            tokens[i + 4].text == ")" && tokens[i + 5].text == "{")
            names.push_back(tokens[i + 1].text);
    return names;
}

} // namespace mary
