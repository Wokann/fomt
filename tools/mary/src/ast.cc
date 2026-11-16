#include "ast.hh"
#include "constant_expr.hh"

namespace mary
{

Expr Expr::integer(Integer value)
{
    Expr e;
    e.value = value;
    return e;
}
Expr Expr::string(Bytes bytes)
{
    Expr e;
    e.kind = Str;
    e.bytes = std::move(bytes);
    return e;
}
Expr Expr::named(std::string name)
{
    Expr e;
    e.kind = Name;
    e.name = std::move(name);
    return e;
}
Expr Expr::operation(Kind kind, std::string op, std::vector<Expr> args)
{
    Expr e;
    e.kind = kind;
    e.name = std::move(op);
    e.args = std::move(args);
    return e;
}

std::optional<Constant> constant_value(const Expr &expr, const ConstantAccess &lookup)
{
    switch (expr.kind)
    {
        case Expr::Name:
            return lookup(expr.name);
        case Expr::Int:
            return expr.value;
        case Expr::Str:
            return expr.bytes;
        case Expr::Unary:
        {
            auto inner = constant_value(expr.args.at(0), lookup);
            if (!inner || !std::holds_alternative<Integer>(*inner))
                return std::nullopt;
            auto value = std::get<Integer>(*inner);
            if (expr.name == "!")
                return Integer(value == 0);
            if (expr.name == "-")
            {
                try
                {
                    return apply_integer_operator("-", 0, value);
                }
                catch (const std::exception &)
                {
                    return std::nullopt;
                }
            }
            return std::nullopt;
        }
        case Expr::Binary:
        {
            if (expr.name != "+" && expr.name != "-" && expr.name != "*" && expr.name != "/" &&
                expr.name != "%" && expr.name != "&&" && expr.name != "||")
                return std::nullopt;
            auto a = constant_value(expr.args.at(0), lookup),
                 b = constant_value(expr.args.at(1), lookup);
            if (!a || !b || !std::holds_alternative<Integer>(*a) ||
                !std::holds_alternative<Integer>(*b))
                return std::nullopt;
            try
            {
                return apply_integer_operator(
                    expr.name, std::get<Integer>(*a), std::get<Integer>(*b));
            }
            catch (const std::exception &)
            {
                return std::nullopt;
            }
        }
        default:
            return std::nullopt;
    }
}

bool sequence_terminates(const std::vector<Statement> &statements)
{
    return !statements.empty() && statement_terminates(statements.back());
}

bool statement_terminates(const Statement &last)
{
    return last.kind == Statement::Exit || last.kind == Statement::Break ||
           (last.kind == Statement::IfElse && sequence_terminates(last.body) &&
            sequence_terminates(last.alternative));
}

} // namespace mary
