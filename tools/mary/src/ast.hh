#ifndef MARY_AST_HH
#define MARY_AST_HH

#include "const_scope.hh"
#include <functional>

namespace mary
{

struct Expr
{
    enum Kind
    {
        Name,
        Int,
        Str,
        Binary,
        Unary,
        Call,
        Increment
    } kind = Int;
    std::string name;
    Integer value = 0;
    Bytes bytes;
    std::vector<Expr> args;

    static Expr integer(Integer value);
    static Expr string(Bytes bytes);
    static Expr named(std::string name);
    static Expr operation(Kind kind, std::string op, std::vector<Expr> args);
};

struct SwitchCase;
struct Statement
{
    enum Kind
    {
        Variables,
        Constants,
        Assign,
        AssignNoDiscard,
        Expression,
        Call,
        If,
        IfElse,
        For,
        DoWhile,
        Switch,
        JumpNext,
        Break,
        Exit,
        Ir
    } kind = Exit;
    std::string name, operation;
    Expr expression;
    std::vector<std::pair<std::string, std::optional<Expr>>> declarations;
    std::vector<Statement> body, alternative, clauses;
    std::vector<SwitchCase> cases;
    std::size_t switch_id = 0;
    bool compact = false;
    Script raw_ir;
    std::size_t source_line = 0;
    std::size_t condition_line = 0;
};

struct SwitchCase
{
    enum Kind
    {
        Values,
        Default,
        ImplicitDefault,
        DeadJump
    } kind = Values;
    std::vector<Expr> values;
    std::vector<Statement> body;
    bool fallthrough = false;
};

using ConstantAccess = std::function<std::optional<Constant>(const std::string &)>;
std::optional<Constant> constant_value(const Expr &expr, const ConstantAccess &lookup);
bool sequence_terminates(const std::vector<Statement> &statements);
bool statement_terminates(const Statement &statement);
Script compile_script(std::vector<Statement> statements, const ConstScope &scope);

} // namespace mary
#endif
