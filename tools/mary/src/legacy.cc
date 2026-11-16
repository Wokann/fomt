#include "legacy.hh"
#include "lexer.hh"
#include "low_level.hh"
#include <stdexcept>

namespace mary
{
namespace
{

unsigned priority(std::string_view op)
{
    return op == "||"                                           ? 1
           : op == "&&"                                         ? 2
           : op == "==" || op == "!="                           ? 3
           : op == "<" || op == "<=" || op == ">=" || op == ">" ? 4
           : op == "+" || op == "-"                             ? 5
           : op == "*" || op == "/" || op == "%"                ? 6
                                                                : 0;
}
bool assignment(std::string_view op)
{
    return op == "=" || op == "+=" || op == "-=" || op == "*=" || op == "/=" || op == "%=";
}

struct Parser
{
    Tokens tokens;
    LegacyContext result;
    bool declarations_allowed = true, allow_scripts;

    Parser(std::vector<Token> input, const ConstScope &scope, bool allow)
      : tokens(std::move(input))
      , result{ scope, {} }
      , allow_scripts(allow)
    {
    }

    Constant constant(const Expr &expr)
    {
        auto value = constant_value(expr,
                                    [&](auto &name) -> std::optional<Constant>
                                    {
                                        auto found = result.scope.constants.find(name);
                                        return found != result.scope.constants.end()
                                                   ? std::optional<Constant>(found->second)
                                                   : std::nullopt;
                                    });
        if (!value)
            tokens.error("failed constant evaluation");
        return *value;
    }
    Integer integer(const Expr &expr)
    {
        auto value = constant(expr);
        if (!std::holds_alternative<Integer>(value))
            tokens.error("expected integer constant");
        return std::get<Integer>(value);
    }
    ValueType type()
    {
        if (tokens.eat("integer"))
            return ValueType::Integer;
        if (tokens.eat("string"))
            return ValueType::String;
        auto name = tokens.identifier();
        result.scope.user_types.insert(name);
        return ValueType(name);
    }
    LegacyContext program()
    {
        while (!tokens.end())
        {
            if (tokens.eat("script"))
            {
                if (!allow_scripts)
                    tokens.error("scripts are not permitted in included files");
                declarations_allowed = false;
                auto id = integer(expression());
                auto name = tokens.identifier();
                auto body = block();
                result.scripts.push_back(
                    { id, std::move(name), compile_script(std::move(body), result.scope), {} });
                continue;
            }
            if (!declarations_allowed)
                tokens.error("declarations after first script");
            if (tokens.eat("const"))
            {
                auto name = tokens.identifier();
                tokens.require("=");
                result.scope.constants[name] = constant(expression());
            }
            else if (tokens.is("func") || tokens.is("proc"))
            {
                bool function = tokens.take().text == "func";
                auto id = integer(primary());
                if (id < 0 || id > UINT32_MAX)
                    tokens.error("callable ID exceeds VM space");
                auto name = tokens.identifier();
                tokens.require("(");
                std::vector<ValueType> params;
                if (!tokens.eat(")"))
                {
                    do
                    {
                        tokens.identifier();
                        params.push_back(tokens.eat(":") ? type() : ValueType::Undefined);
                    } while (tokens.eat(","));
                    tokens.require(")");
                }
                result.scope.callables[name] = { static_cast<std::uint32_t>(id),
                                                 function ? ValueType::Integer
                                                          : ValueType::Undefined,
                                                 std::move(params) };
            }
            else
                tokens.error("expected const, func, proc, or script declaration");
        }
        return std::move(result);
    }
    Expr primary()
    {
        if (tokens.eat("("))
        {
            auto expr = expression();
            tokens.require(")");
            return expr;
        }
        auto token = tokens.take();
        if (token.kind == TokenKind::Integer)
            return Expr::integer(token.integer);
        if (token.kind == TokenKind::String)
        {
            auto bytes = std::move(token.bytes);
            while (tokens.peek().kind == TokenKind::String)
            {
                auto next = tokens.take();
                bytes.insert(bytes.end(), next.bytes.begin(), next.bytes.end());
            }
            return Expr::string(std::move(bytes));
        }
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
        auto expr = Expr::named(std::move(token.text));
        if (tokens.is("++") || tokens.is("--"))
        {
            expr.kind = Expr::Increment;
            expr.value = tokens.take().text == "++" ? 1 : -1;
        }
        return expr;
    }
    Expr expression(unsigned minimum = 0)
    {
        Expr left;
        if (tokens.eat("+"))
            left = expression(7);
        else if (tokens.is("-") || tokens.is("!"))
        {
            auto op = tokens.take().text;
            left = Expr::operation(Expr::Unary, std::move(op), { expression(7) });
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
            auto p = priority(tokens.peek().text);
            if (!p || p < minimum)
                break;
            auto op = tokens.take().text;
            auto right = expression(p + 1);
            left =
                Expr::operation(Expr::Binary, std::move(op), { std::move(left), std::move(right) });
        }
        return left;
    }
    std::vector<Statement> block()
    {
        tokens.require("{");
        std::vector<Statement> body;
        while (!tokens.eat("}"))
            body.push_back(stmt());
        return body;
    }
    Statement stmt()
    {
        Statement s;
        if (tokens.is("var") || tokens.is("const"))
        {
            bool require_value = tokens.take().text == "const";
            s.kind = require_value ? Statement::Constants : Statement::Variables;
            do
            {
                auto name = tokens.identifier();
                std::optional<Expr> value;
                if (tokens.eat("="))
                    value = expression();
                else if (require_value)
                    tokens.error("constant requires an initializer");
                s.declarations.emplace_back(std::move(name), std::move(value));
            } while (tokens.eat(","));
            return s;
        }
        if (tokens.eat("if"))
        {
            s.kind = Statement::If;
            s.expression = expression();
            s.body = block();
            if (tokens.eat("else"))
            {
                s.kind = Statement::IfElse;
                s.alternative = tokens.is("if") ? std::vector<Statement>{ stmt() } : block();
            }
            return s;
        }
        if (tokens.eat("do"))
        {
            s.kind = Statement::DoWhile;
            s.body = block();
            tokens.require("while");
            s.expression = expression();
            return s;
        }
        if (tokens.eat("for"))
        {
            s.kind = Statement::For;
            s.clauses.push_back(stmt());
            tokens.require(";");
            s.expression = expression();
            tokens.require(";");
            s.clauses.push_back(stmt());
            s.body = block();
            return s;
        }
        if (tokens.eat("switch"))
        {
            s.kind = Statement::Switch;
            s.compact = tokens.eat("compact");
            s.expression = expression();
            tokens.require("{");
            while (!tokens.eat("}"))
            {
                SwitchCase c;
                if (tokens.eat("case"))
                {
                    do
                    {
                        c.values.push_back(expression());
                    } while (tokens.eat(","));
                    c.fallthrough = tokens.eat("fallthrough");
                }
                else if (tokens.eat("default"))
                {
                    c.kind = SwitchCase::Default;
                    if (tokens.eat("implicit"))
                        c.kind = SwitchCase::ImplicitDefault;
                    else
                        c.fallthrough = tokens.eat("fallthrough");
                }
                else if (tokens.eat("dead"))
                    c.kind = SwitchCase::DeadJump;
                else
                    tokens.error("expected case, default or dead");
                c.body = block();
                s.cases.push_back(std::move(c));
            }
            if (s.cases.empty())
                tokens.error("legacy switch requires at least one case");
            return s;
        }
        if (tokens.eat("exit"))
            return s;
        if (tokens.eat("break"))
        {
            s.kind = Statement::Break;
            return s;
        }
        if (tokens.eat("jump"))
        {
            tokens.require("next");
            s.kind = Statement::JumpNext;
            return s;
        }
        if (tokens.eat("discard"))
        {
            s.kind = Statement::Expression;
            s.expression = expression();
            return s;
        }
        if (tokens.eat("ir"))
        {
            s.kind = Statement::Ir;
            s.raw_ir = parse_ir(tokens);
            return s;
        }
        bool nodisc = tokens.eat("nodisc");
        if (tokens.peek().kind == TokenKind::Identifier && assignment(tokens.peek(1).text))
        {
            s.kind = nodisc ? Statement::AssignNoDiscard : Statement::Assign;
            s.name = tokens.identifier();
            s.operation = tokens.take().text;
            s.expression = expression();
            return s;
        }
        if (nodisc)
            tokens.error("nodisc requires an assignment");
        s.expression = expression();
        if (s.expression.kind == Expr::Call)
            s.kind = Statement::Call;
        else if (s.expression.kind == Expr::Increment)
            s.kind = Statement::Expression;
        else
            tokens.error("expression statement requires discard in the legacy DSL");
        return s;
    }
};

} // namespace

LegacyContext parse_legacy(std::string_view source,
                           const Charmap *map,
                           const ConstScope &scope,
                           bool allow_scripts)
{
    return Parser(lex(source, map, true), scope, allow_scripts).program();
}

} // namespace mary
