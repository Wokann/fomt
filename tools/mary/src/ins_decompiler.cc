#include "decompiler.hh"

#include <algorithm>
#include <initializer_list>
#include <stdexcept>

namespace mary
{
namespace
{

enum Kind
{
    Stmts,
    Expression,
    Assignment,
    Cases,
    Function,
    PushVar,
    PushInt,
    Beq,
    Bne,
    Jump,
    Label,
    Case,
    AnyExpr
};
struct Token
{
    Kind kind;
    Integer number = 0, value = 0;
    bool default_case = false;
    Expr expression;
    std::string operation;
    std::vector<Statement> statements;
    std::vector<std::pair<SwitchCase, std::optional<Integer>>> cases;
    explicit Token(Kind kind, Integer number = 0)
      : kind(kind)
      , number(number)
    {
    }
};

class Decompiler
{
  public:
    Decompiler(const std::vector<Instruction> &code, const ConstScope &scope)
      : code(code)
    {
        for (auto &entry : scope.callables)
            callables[entry.second.id] = entry;
        std::size_t physical = 0;
        for (auto &ins : code)
        {
            if (ins.op == Op::Label)
                targets[ins.argument] = physical;
            else if (ins.op != Op::Case)
                ++physical;
        }
        for (std::size_t i = 0; i < code.size(); ++i)
            if (code[i].op == Op::Switch)
            {
                std::set<Integer> tails;
                for (auto n = i + 1; n < code.size() && code[n].op == Op::Label; ++n)
                    tails.insert(code[n].argument);
                auto first = std::find_if(
                    code.begin(),
                    code.begin() + i,
                    [&](auto &ins)
                    { return ins.op == Op::Case && ins.argument == code[i].argument; });
                for (auto it = first; it != code.begin() + i; ++it)
                    if (it->op == Op::Jmp && tails.count(it->argument))
                        switch_breaks.insert(it->argument);
            }
    }

    std::vector<Statement> run()
    {
        while (pc < code.size())
        {
            auto before = pc;
            next();
            if (pc <= before)
                fail("instruction reduction made no progress");
        }
        if (suffix({ Assignment, Stmts }) && stack.size() == 2)
        {
            auto body = pop().statements;
            auto assignment = pop();
            Statement statement;
            statement.kind = Statement::AssignNoDiscard;
            statement.name = variable(assignment.number);
            statement.operation = assignment.operation;
            statement.expression = std::move(assignment.expression);
            body.insert(body.begin(), std::move(statement));
            Token token(Stmts);
            token.statements = std::move(body);
            stack.push_back(std::move(token));
        }
        if (stack.empty())
            return {};
        if (stack.size() != 1 || stack[0].kind != Stmts)
            fail("unreduced state at end of script");
        auto body = std::move(stack[0].statements);
        if (!variables.empty())
        {
            Statement declarations;
            declarations.kind = Statement::Variables;
            const auto count = variables.rbegin()->first + 1;
            for (Integer id = 0; id < count; ++id)
                declarations.declarations.emplace_back(
                    variables.count(id) ? variables.at(id) : "unused_" + std::to_string(id),
                    std::nullopt);
            body.insert(body.begin(), std::move(declarations));
        }
        return body;
    }

  private:
    const std::vector<Instruction> &code;
    std::size_t pc = 0;
    std::vector<Token> stack;
    std::map<Integer, std::string> variables;
    std::map<Integer, std::size_t> targets;
    std::set<Integer> switch_breaks;
    std::map<Integer, std::pair<std::string, Callable>> callables;

    [[noreturn]] void fail(const std::string &message) const
    {
        throw std::runtime_error("instruction " + std::to_string(pc) + ": " + message);
    }
    static bool expression(const Token &t)
    {
        return t.kind == Expression || t.kind == Function || t.kind == PushVar || t.kind == PushInt;
    }
    bool suffix(std::initializer_list<Kind> pattern) const
    {
        if (stack.size() < pattern.size())
            return false;
        auto at = stack.size() - pattern.size();
        for (auto kind : pattern)
        {
            auto &token = stack[at++];
            if (kind == AnyExpr ? !expression(token) : token.kind != kind)
                return false;
        }
        return true;
    }
    const Token &back(std::size_t distance = 1) const
    {
        if (!distance || distance > stack.size())
            fail("missing reduction operand");
        return stack[stack.size() - distance];
    }
    bool ahead(std::size_t n, Op op) const
    {
        return pc + n < code.size() && code[pc + n].op == op;
    }
    Integer arg(std::size_t n) const
    {
        return code.at(pc + n).argument;
    }
    Token pop()
    {
        if (stack.empty())
            fail("empty reduction stack");
        auto token = std::move(stack.back());
        stack.pop_back();
        return token;
    }
    std::string variable(Integer id)
    {
        if (id < 0 || id > UINT32_MAX)
            fail("variable ID exceeds VM space");
        auto found = variables.emplace(id, "var_" + std::to_string(id));
        return found.first->second;
    }
    Expr pop_expr()
    {
        auto token = pop();
        if (token.kind == Expression || token.kind == Function)
            return std::move(token.expression);
        if (token.kind == PushVar)
            return Expr::named(variable(token.number));
        if (token.kind == PushInt)
            return Expr::integer(token.number);
        fail("expected expression on reduction stack");
    }
    void push_expr(Expr expr, Kind kind = Expression)
    {
        Token token(kind);
        token.expression = std::move(expr);
        stack.push_back(std::move(token));
    }
    void push_stmt(Statement stmt)
    {
        if (stack.empty() || stack.back().kind != Stmts)
            stack.emplace_back(Stmts);
        stack.back().statements.push_back(std::move(stmt));
    }
    void append_case(Integer id, SwitchCase c, std::optional<Integer> target)
    {
        if (stack.empty() || stack.back().kind != Cases || stack.back().number != id)
            stack.emplace_back(Cases, id);
        stack.back().cases.emplace_back(std::move(c), target);
    }
    SwitchCase reduce_case(bool consume, bool fallthrough)
    {
        if (consume)
            ++pc;
        SwitchCase result;
        if (!stack.empty() && back().kind == Stmts)
            result.body = pop().statements;
        auto marker = pop();
        if (marker.kind != Case)
            fail("expected case marker");
        result.kind = marker.default_case ? SwitchCase::Default : SwitchCase::Values;
        result.fallthrough = fallthrough;
        if (!marker.default_case)
        {
            result.values.push_back(Expr::integer(marker.value));
            while (!stack.empty() && back().kind == Case && !back().default_case)
                result.values.push_back(Expr::integer(pop().value));
            std::reverse(result.values.begin(), result.values.end());
        }
        return result;
    }
    bool match_jump(std::optional<Integer> target)
    {
        if (suffix({ Case, Stmts }) || suffix({ Case }))
        {
            auto id = back(back().kind == Stmts ? 2 : 1).number;
            std::optional<std::size_t> split;
            if (!target && back().kind == Stmts)
            {
                auto &body = back().statements;
                std::vector<Statement> prefix;
                for (std::size_t i = 0; i + 1 < body.size(); ++i)
                {
                    prefix.push_back(body[i]);
                    if (sequence_terminates(prefix))
                    {
                        split = i;
                        break;
                    }
                }
            }
            if (split)
            {
                auto body = pop().statements;
                SwitchCase implicit;
                implicit.kind = SwitchCase::ImplicitDefault;
                implicit.body.assign(std::make_move_iterator(body.begin() + *split + 1),
                                     std::make_move_iterator(body.end()));
                body.resize(*split + 1);
                Token token(Stmts);
                token.statements = std::move(body);
                stack.push_back(std::move(token));
                auto c = reduce_case(false, false);
                append_case(id, std::move(c), std::nullopt);
                append_case(id, std::move(implicit), std::nullopt);
                ++pc;
            }
            else
                append_case(id, reduce_case(true, false), target);
            return true;
        }
        if (suffix({ Cases, Stmts }) && ahead(1, Op::Label) && ahead(2, Op::Switch) &&
            arg(2) == back(2).number)
        {
            auto body = pop().statements;
            auto id = back().number;
            SwitchCase c;
            c.kind = !target && sequence_terminates(body) ? SwitchCase::ImplicitDefault
                                                          : SwitchCase::DeadJump;
            c.body = std::move(body);
            append_case(id, std::move(c), target);
            ++pc;
            return true;
        }
        if (suffix({ Cases }) && (ahead(1, Op::Case) || ahead(1, Op::Jmp)))
        {
            SwitchCase c;
            c.kind = SwitchCase::DeadJump;
            stack.back().cases.emplace_back(std::move(c), target);
            ++pc;
            return true;
        }
        return false;
    }
    bool match_label(Integer id)
    {
        if ((suffix({ AnyExpr, Beq, Stmts }) && back(2).number == id) ||
            (suffix({ AnyExpr, Beq }) && back().number == id))
        {
            std::vector<Statement> body;
            if (back().kind == Stmts)
                body = pop().statements;
            pop();
            auto expr = pop_expr();
            ++pc;
            Statement s;
            s.kind = Statement::If;
            s.expression = std::move(expr);
            s.body = std::move(body);
            if (!s.body.empty() && s.body.back().kind == Statement::JumpNext)
            {
                s.kind = Statement::IfElse;
                s.body.pop_back();
            }
            push_stmt(std::move(s));
            return true;
        }
        for (bool has_else : { true, false })
            for (bool has_then : { true, false })
            {
                bool match = has_else
                                 ? (has_then ? suffix({ AnyExpr, Beq, Stmts, Jump, Label, Stmts })
                                             : suffix({ AnyExpr, Beq, Jump, Label, Stmts }))
                                 : (has_then ? suffix({ AnyExpr, Beq, Stmts, Jump, Label })
                                             : suffix({ AnyExpr, Beq, Jump, Label }));
                if (!match)
                    continue;
                auto label_distance = has_else ? 2u : 1u;
                auto beq_distance = label_distance + 2 + unsigned(has_then);
                if (back(beq_distance).number != back(label_distance).number ||
                    back(label_distance + 1).number != id)
                    continue;
                Statement s;
                s.kind = Statement::IfElse;
                if (has_else)
                    s.alternative = pop().statements;
                pop();
                pop();
                if (has_then)
                    s.body = pop().statements;
                pop();
                s.expression = pop_expr();
                ++pc;
                push_stmt(std::move(s));
                return true;
            }
        for (bool has_body : { true, false })
        {
            bool match =
                has_body
                    ? suffix({ Stmts,
                               Label,
                               AnyExpr,
                               Bne,
                               Jump,
                               Label,
                               Stmts,
                               Jump,
                               Label,
                               Stmts,
                               Jump })
                    : suffix({ Stmts, Label, AnyExpr, Bne, Jump, Label, Stmts, Jump, Label, Jump });
            if (!match)
                continue;
            auto d = has_body ? 1u : 0u;
            if (back(3 + d).number != back(9 + d).number ||
                back(7 + d).number != back(2 + d).number || back().number != back(5 + d).number ||
                back(4 + d).statements.size() != 1 || back(6 + d).number != id)
                continue;
            pop();
            Statement s;
            s.kind = Statement::For;
            if (has_body)
                s.body = pop().statements;
            pop();
            pop();
            auto iteration = pop().statements;
            pop();
            pop();
            pop();
            s.expression = pop_expr();
            pop();
            auto previous = pop().statements;
            if (previous.empty())
                fail("for loop has no initializer statement");
            s.clauses.push_back(std::move(previous.back()));
            previous.pop_back();
            s.clauses.push_back(std::move(iteration.back()));
            previous.push_back(std::move(s));
            Token token(Stmts);
            token.statements = std::move(previous);
            stack.push_back(std::move(token));
            ++pc;
            return true;
        }
        if (suffix({ Jump }) && back().number == id)
        {
            pop();
            Statement s;
            s.kind = Statement::JumpNext;
            push_stmt(std::move(s));
            ++pc;
            return true;
        }
        return false;
    }
    bool match_bne(Integer target)
    {
        if (suffix({ Label, Stmts, AnyExpr }) && back(3).number == target)
        {
            Statement s;
            s.kind = Statement::DoWhile;
            s.expression = pop_expr();
            s.body = pop().statements;
            pop();
            push_stmt(std::move(s));
            ++pc;
            return true;
        }
        if (suffix({ Label, Case, Stmts, AnyExpr }) && back(4).number == target)
        {
            Statement s;
            s.kind = Statement::DoWhile;
            s.expression = pop_expr();
            s.body = pop().statements;
            auto c = pop();
            pop();
            stack.push_back(std::move(c));
            push_stmt(std::move(s));
            ++pc;
            return true;
        }
        if (suffix({ Label, AnyExpr }) && back(2).number == target)
        {
            Statement s;
            s.kind = Statement::DoWhile;
            s.expression = pop_expr();
            pop();
            push_stmt(std::move(s));
            ++pc;
            return true;
        }
        return false;
    }
    void match_switch()
    {
        if (!ahead(1, Op::Label))
            fail("switch dispatch lacks its tail label");
        auto id = arg(0), past = arg(1);
        for (bool compact : { false, true })
        {
            if (!(compact ? suffix({ AnyExpr, Jump, Cases, Label })
                          : suffix({ AnyExpr, Jump, Cases, Jump, Label })))
                continue;
            auto distance = compact ? 2u : 3u;
            if (back(distance).number != id || back(distance + 1).number != back().number ||
                (!compact && back(2).number != past))
                continue;
            auto &cases = back(distance).cases;
            bool valid = true;
            std::set<Integer> required{ past };
            for (auto &c : cases)
                if (c.second)
                {
                    if (targets.at(*c.second) != targets.at(past))
                        valid = false;
                    required.insert(*c.second);
                }
            if (!valid)
                continue;
            std::size_t consume = 0;
            for (auto n = pc + 1; n < code.size() && code[n].op == Op::Label &&
                                  targets.at(code[n].argument) == targets.at(past);
                 ++n)
            {
                if (required.erase(code[n].argument))
                    consume = n - pc;
            }
            if (!required.empty())
                fail("switch cases do not share the dispatch tail");
            pop();
            if (!compact)
                pop();
            auto c = pop();
            pop();
            Statement s;
            s.kind = Statement::Switch;
            s.compact = compact;
            s.expression = pop_expr();
            for (auto &entry : c.cases)
                s.cases.push_back(std::move(entry.first));
            push_stmt(std::move(s));
            pc += 1 + consume;
            return;
        }
        fail("cannot reduce switch dispatch");
    }
    void case_marker(const Instruction &ins)
    {
        if (suffix({ AnyExpr, Jump, Stmts, Jump }))
        {
            auto target = pop().number;
            auto body = pop().statements;
            SwitchCase c;
            c.kind = SwitchCase::ImplicitDefault;
            c.body = std::move(body);
            append_case(ins.argument, std::move(c), target);
        }
        if (suffix({ AnyExpr, Jump, Stmts }) && sequence_terminates(back().statements))
        {
            SwitchCase c;
            c.kind = SwitchCase::ImplicitDefault;
            c.body = pop().statements;
            append_case(ins.argument, std::move(c), std::nullopt);
        }
        if (suffix({ Cases, Stmts, Jump }) && back(3).number == ins.argument)
        {
            auto target = pop().number;
            SwitchCase c;
            c.kind = SwitchCase::ImplicitDefault;
            c.body = pop().statements;
            append_case(ins.argument, std::move(c), target);
        }
        if (suffix({ Cases, Stmts }) && back(2).number == ins.argument &&
            sequence_terminates(back().statements))
        {
            SwitchCase c;
            c.kind = SwitchCase::ImplicitDefault;
            c.body = pop().statements;
            append_case(ins.argument, std::move(c), std::nullopt);
        }
        if (suffix({ Case, Stmts }))
        {
            auto id = back(2).number;
            append_case(id, reduce_case(false, true), std::nullopt);
        }
        if (suffix({ Case }) && back().number == ins.argument &&
            (back().default_case || ins.default_case))
        {
            auto id = back().number;
            append_case(id, reduce_case(false, true), std::nullopt);
        }
        Token token(Case, ins.argument);
        token.value = ins.case_value;
        token.default_case = ins.default_case;
        stack.push_back(std::move(token));
        ++pc;
    }
    void next()
    {
        const auto ins = code[pc];
        if (ins.op >= Op::Assign && ins.op <= Op::AssignMod)
        {
            if (!suffix({ PushInt, AnyExpr }))
                fail("assignment lacks its variable ID and value");
            auto expr = pop_expr();
            auto id = pop().number;
            const char *ops[] = { "=", "+=", "-=", "*=", "/=", "%=" };
            Token token(Assignment, id);
            token.expression = std::move(expr);
            token.operation = ops[static_cast<unsigned>(ins.op) - 1];
            stack.push_back(std::move(token));
            ++pc;
            return;
        }
        if (ins.op >= Op::Add && ins.op <= Op::LogicalOr)
        {
            if (!suffix({ AnyExpr, AnyExpr }))
                fail("binary operation lacks two expressions");
            auto right = pop_expr(), left = pop_expr();
            const char *ops[] = { "+", "-", "*", "/", "%", "&&", "||" };
            push_expr(Expr::operation(Expr::Binary,
                                      ops[static_cast<unsigned>(ins.op) - 7],
                                      { std::move(left), std::move(right) }));
            ++pc;
            return;
        }
        switch (ins.op)
        {
            case Op::PushVar:
                stack.emplace_back(PushVar, ins.argument);
                ++pc;
                break;
            case Op::PushInt:
                stack.emplace_back(PushInt, ins.argument);
                ++pc;
                break;
            case Op::Neg:
            case Op::LogicalNot:
                if (!suffix({ AnyExpr }))
                    fail("unary operation lacks an expression");
                push_expr(
                    Expr::operation(Expr::Unary, ins.op == Op::Neg ? "-" : "!", { pop_expr() }));
                ++pc;
                break;
            case Op::Cmp:
            {
                if (!suffix({ AnyExpr, AnyExpr }) || !ahead(2, Op::PushInt) || arg(2) != 0 ||
                    !ahead(3, Op::Jmp) || !ahead(4, Op::Label) || !ahead(5, Op::PushInt) ||
                    arg(5) != 1 || !ahead(6, Op::Label) || arg(1) != arg(4) || arg(3) != arg(6))
                    fail("comparison does not match the VM boolean-value pattern");
                auto op = code[pc + 1].op;
                if (op < Op::Blt || op > Op::Bgt)
                    fail("invalid comparison branch");
                const char *ops[] = { "<", "<=", "==", "!=", ">=", ">" };
                auto right = pop_expr(), left = pop_expr();
                push_expr(Expr::operation(Expr::Binary,
                                          ops[static_cast<unsigned>(op) - 0x19],
                                          { std::move(left), std::move(right) }));
                pc += 7;
                break;
            }
            case Op::Dupe:
            case Op::Inc:
            case Op::Dec:
            {
                if (!suffix({ PushVar }))
                    fail("increment requires a pushed variable");
                auto id = back().number;
                bool post = ahead(0, Op::Dupe) && (ahead(1, Op::Inc) || ahead(1, Op::Dec));
                bool pre = (ahead(0, Op::Inc) || ahead(0, Op::Dec)) && ahead(1, Op::Dupe);
                if ((!post && !pre) || !ahead(2, Op::PopVar) || arg(2) != id)
                    fail("invalid pre/post increment pattern");
                auto e = Expr::named(variable(id));
                e.kind = Expr::Increment;
                auto positive = code[pc + unsigned(post)].op == Op::Inc;
                e.value = (post ? 1 : 2) * (positive ? 1 : -1);
                pop();
                push_expr(std::move(e));
                pc += 3;
                break;
            }
            case Op::Discard:
            {
                Statement s;
                if (suffix({ Assignment }))
                {
                    auto assignment = pop();
                    s.kind = Statement::Assign;
                    s.name = variable(assignment.number);
                    s.operation = assignment.operation;
                    s.expression = std::move(assignment.expression);
                }
                else if (suffix({ AnyExpr }))
                {
                    s.kind = back().kind == Function ? Statement::Call : Statement::Expression;
                    s.expression = pop_expr();
                }
                else
                    fail("discard has no reducible value");
                push_stmt(std::move(s));
                ++pc;
                break;
            }
            case Op::Jmp:
                if (!match_jump(ins.argument))
                {
                    bool else_break = suffix({ AnyExpr, Beq, Stmts, Jump, Label }) &&
                                      back(4).number == back().number && ahead(1, Op::Label) &&
                                      arg(1) == back(2).number;
                    bool if_break =
                        suffix({ AnyExpr, Beq }) && ahead(1, Op::Label) && arg(1) == back().number;
                    if (switch_breaks.count(ins.argument) &&
                        (ahead(1, Op::Jmp) || else_break || if_break))
                    {
                        Statement s;
                        s.kind = Statement::Break;
                        push_stmt(std::move(s));
                    }
                    else
                        stack.emplace_back(Jump, ins.argument);
                    ++pc;
                }
                break;
            case Op::Beq:
                stack.emplace_back(Beq, ins.argument);
                ++pc;
                break;
            case Op::Bne:
                if (!match_bne(ins.argument))
                {
                    stack.emplace_back(Bne, ins.argument);
                    ++pc;
                }
                break;
            case Op::Call:
            {
                auto found = callables.find(ins.argument);
                if (found == callables.end())
                    fail("unknown callable ID " + std::to_string(ins.argument));
                auto &call = found->second;
                auto count = call.second.parameters.size();
                if (count > stack.size())
                    fail("call has insufficient arguments");
                for (std::size_t n = 1; n <= count; ++n)
                    if (!expression(back(n)))
                        fail("call argument is not an expression");
                std::vector<Expr> args;
                while (count--)
                    args.push_back(pop_expr());
                std::reverse(args.begin(), args.end());
                auto e = Expr::operation(Expr::Call, call.first, std::move(args));
                if (call.second.is_function())
                    push_expr(std::move(e), Function);
                else
                {
                    Statement s;
                    s.kind = Statement::Call;
                    s.expression = std::move(e);
                    push_stmt(std::move(s));
                }
                ++pc;
                break;
            }
            case Op::Switch:
                match_switch();
                break;
            case Op::Case:
                case_marker(ins);
                break;
            case Op::Exit:
            {
                Statement s;
                s.kind = Statement::Exit;
                push_stmt(std::move(s));
                if (!match_jump(std::nullopt))
                    ++pc;
                break;
            }
            case Op::Label:
                if (!match_label(ins.argument))
                {
                    stack.emplace_back(Label, ins.argument);
                    ++pc;
                }
                break;
            default:
                fail("instruction cannot be reduced to structured source");
        }
    }
};

} // namespace

std::vector<Statement> decompile_instructions(const std::vector<Instruction> &instructions,
                                              const ConstScope &scope)
{
    return Decompiler(instructions, scope).run();
}

} // namespace mary
