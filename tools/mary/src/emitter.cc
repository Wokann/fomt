#include "ast.hh"
#include "constant_expr.hh"

#include <algorithm>
#include <stdexcept>

namespace mary
{
namespace
{

using Binding = std::variant<std::uint32_t, Constant>;
struct BlockScope
{
    std::size_t next_id;
    std::map<std::string, Binding> names;
    const BlockScope *parent;
    const ConstScope &globals;

    BlockScope(const ConstScope &globals)
      : next_id(0)
      , parent(nullptr)
      , globals(globals)
    {
    }
    BlockScope(const BlockScope &parent, bool)
      : next_id(parent.next_id)
      , parent(&parent)
      , globals(parent.globals)
    {
    }
    const Binding *local(const std::string &name) const
    {
        auto found = names.find(name);
        return found != names.end() ? &found->second : parent ? parent->local(name) : nullptr;
    }
    std::optional<Constant> constant(const std::string &name) const
    {
        if (auto binding = local(name))
        {
            if (auto value = std::get_if<Constant>(binding))
                return *value;
            return std::nullopt;
        }
        auto found = globals.constants.find(name);
        return found != globals.constants.end() ? std::optional<Constant>(found->second)
                                                : std::nullopt;
    }
    std::uint32_t variable(const std::string &name) const
    {
        if (auto binding = local(name))
            if (auto id = std::get_if<std::uint32_t>(binding))
                return *id;
        throw std::runtime_error("not a declared variable: " + name);
    }
    std::uint32_t define_variable(const std::string &name)
    {
        if (names.count(name))
            throw std::runtime_error("name already declared: " + name);
        if (next_id > UINT32_MAX)
            throw std::runtime_error("variable ID exceeds VM space");
        auto id = static_cast<std::uint32_t>(next_id++);
        names[name] = id;
        return id;
    }
    void define_constant(const std::string &name, Constant value)
    {
        if (!names.emplace(name, std::move(value)).second)
            throw std::runtime_error("name already declared: " + name);
    }
};

void allocate_switches(std::vector<Statement> &statements, std::size_t &counter)
{
    for (auto &s : statements)
    {
        if (s.kind == Statement::For)
            allocate_switches(s.clauses, counter);
        allocate_switches(s.body, counter);
        allocate_switches(s.alternative, counter);
        for (auto &c : s.cases)
            allocate_switches(c.body, counter);
        if (s.kind == Statement::Switch)
            s.switch_id = counter++;
    }
}

struct Emitter
{
    Script result;
    Integer label_counter = 0;
    std::vector<Integer> switch_breaks;
    std::size_t source_line = 0;

    [[noreturn]] void fail(const std::string &message)
    {
        throw std::runtime_error(message);
    }
    Integer label()
    {
        return ++label_counter;
    }
    void ins(Op op, Integer argument = 0)
    {
        if (op == Op::PushInt && !encodable_integer(argument))
            fail("integer exceeds VM value range");
        result.instructions.push_back({ op, argument, 0, false, source_line });
    }
    Integer string_id(const Bytes &bytes)
    {
        auto found = std::find(result.strings.begin(), result.strings.end(), bytes);
        if (found != result.strings.end())
            return found - result.strings.begin();
        result.strings.push_back(bytes);
        return Integer(result.strings.size() - 1);
    }
    std::optional<Constant> constant(const Expr &expr, const BlockScope &scope)
    {
        return constant_value(expr, [&](auto &name) { return scope.constant(name); });
    }
    static Op comparison(const std::string &op)
    {
        return op == "=="   ? Op::Beq
               : op == "!=" ? Op::Bne
               : op == "<"  ? Op::Blt
               : op == "<=" ? Op::Ble
               : op == ">=" ? Op::Bge
                            : Op::Bgt;
    }
    void arguments(const Expr &expr, const BlockScope &scope, const Callable &callable)
    {
        (void)callable; // Mary-C validates prototypes before emission; the old DSL does not.
        for (auto &argument : expr.args)
            expression(argument, scope);
    }
    void expression(const Expr &e, const BlockScope &scope)
    {
        switch (e.kind)
        {
            case Expr::Int:
                ins(Op::PushInt, e.value);
                break;
            case Expr::Str:
                ins(Op::PushInt, string_id(e.bytes));
                break;
            case Expr::Name:
                if (auto value = scope.constant(e.name))
                {
                    if (auto n = std::get_if<Integer>(&*value))
                        ins(Op::PushInt, *n);
                    else
                        ins(Op::PushInt, string_id(std::get<Bytes>(*value)));
                }
                else
                    ins(Op::PushVar, scope.variable(e.name));
                break;
            case Expr::Unary:
                if (e.name == "-")
                    if (auto value = constant(e.args.at(0), scope))
                    {
                        if (auto n = std::get_if<Integer>(&*value))
                        {
                            ins(Op::PushInt, apply_integer_operator("-", 0, *n));
                            break;
                        }
                    }
                expression(e.args.at(0), scope);
                ins(e.name == "-" ? Op::Neg : Op::LogicalNot);
                break;
            case Expr::Increment:
            {
                auto id = scope.variable(e.name);
                ins(Op::PushVar, id);
                if (e.value == 1 || e.value == -1)
                    ins(Op::Dupe);
                ins(e.value > 0 ? Op::Inc : Op::Dec);
                if (e.value == 2 || e.value == -2)
                    ins(Op::Dupe);
                ins(Op::PopVar, id);
                break;
            }
            case Expr::Binary:
            {
                const bool compare = e.name == "==" || e.name == "!=" || e.name == "<" ||
                                     e.name == "<=" || e.name == ">" || e.name == ">=";
                auto yes = compare ? label() : 0, next = compare ? label() : 0;
                expression(e.args.at(0), scope);
                expression(e.args.at(1), scope);
                if (compare)
                {
                    ins(Op::Cmp);
                    ins(comparison(e.name), yes);
                    ins(Op::PushInt, 0);
                    ins(Op::Jmp, next);
                    ins(Op::Label, yes);
                    ins(Op::PushInt, 1);
                    ins(Op::Label, next);
                }
                else
                {
                    const std::map<std::string, Op> ops{
                        { "+", Op::Add },       { "-", Op::Sub }, { "*", Op::Mul },
                        { "/", Op::Div },       { "%", Op::Mod }, { "&&", Op::LogicalAnd },
                        { "||", Op::LogicalOr }
                    };
                    ins(ops.at(e.name));
                }
                break;
            }
            case Expr::Call:
                if (scope.globals.typed_identities.count(e.name))
                {
                    if (e.args.size() != 1)
                        fail("typed identity requires one argument");
                    expression(e.args[0], scope);
                }
                else if (e.name == "mary_negated_int")
                {
                    if (e.args.size() != 1)
                        fail("mary_negated_int requires one argument");
                    auto value = constant(e.args[0], scope);
                    if (!value || !std::holds_alternative<Integer>(*value))
                        fail("mary_negated_int requires an integer constant");
                    ins(Op::PushInt, apply_integer_operator("-", 0, std::get<Integer>(*value)));
                    ins(Op::Neg);
                }
                else
                {
                    auto found = scope.globals.callables.find(e.name);
                    if (scope.local(e.name) || found == scope.globals.callables.end() ||
                        !found->second.is_function())
                        fail("not a declared function: " + e.name);
                    arguments(e, scope, found->second);
                    ins(Op::Call, found->second.id);
                }
                break;
        }
    }
    void assign(const Statement &s, BlockScope &scope, bool discard)
    {
        ins(Op::PushInt, scope.variable(s.name));
        expression(s.expression, scope);
        const std::map<std::string, Op> ops{ { "=", Op::Assign },     { "+=", Op::AssignAdd },
                                             { "-=", Op::AssignSub }, { "*=", Op::AssignMul },
                                             { "/=", Op::AssignDiv }, { "%=", Op::AssignMod } };
        ins(ops.at(s.operation));
        if (discard)
            ins(Op::Discard);
    }
    void block(const std::vector<Statement> &statements, const BlockScope &parent)
    {
        BlockScope scope(parent, true);
        for (auto &statement : statements)
            stmt(statement, scope);
    }
    void condition(const Statement &s, const BlockScope &scope, Op jump, Integer target)
    {
        const auto saved = source_line;
        if (s.condition_line)
            source_line = s.condition_line;
        const auto start = result.instructions.size();
        expression(s.expression, scope);
        ins(jump, target);
        result.instructions.back().condition_start = start;
        result.instructions.back().jump_on_true = jump == Op::Bne;
        source_line = saved;
    }

    void stmt(const Statement &s, BlockScope &scope)
    {
        const auto saved = source_line;
        if (s.source_line)
            source_line = s.source_line;
        statement(s, scope);
        source_line = saved;
    }

    void statement(const Statement &s, BlockScope &scope)
    {
        switch (s.kind)
        {
            case Statement::Variables:
                for (auto &entry : s.declarations)
                {
                    auto id = scope.define_variable(entry.first);
                    if (entry.second)
                    {
                        ins(Op::PushInt, id);
                        expression(*entry.second, scope);
                        ins(Op::Assign);
                        ins(Op::Discard);
                    }
                }
                break;
            case Statement::Constants:
                for (auto &entry : s.declarations)
                {
                    if (!entry.second)
                        fail("constant requires an initializer");
                    auto value = constant(*entry.second, scope);
                    if (!value)
                        fail("failed constant evaluation");
                    if (auto bytes = std::get_if<Bytes>(&*value))
                    {
                        auto index = Integer(result.strings.size());
                        result.strings.push_back(*bytes);
                        value = index;
                    }
                    scope.define_constant(entry.first, std::move(*value));
                }
                break;
            case Statement::Assign:
                assign(s, scope, true);
                break;
            case Statement::AssignNoDiscard:
                assign(s, scope, false);
                break;
            case Statement::Expression:
                expression(s.expression, scope);
                ins(Op::Discard);
                break;
            case Statement::Call:
            {
                auto found = scope.globals.callables.find(s.expression.name);
                if (scope.local(s.expression.name) || found == scope.globals.callables.end())
                    fail("not a declared callable: " + s.expression.name);
                arguments(s.expression, scope, found->second);
                ins(Op::Call, found->second.id);
                if (found->second.is_function())
                    ins(Op::Discard);
                break;
            }
            case Statement::If:
            {
                auto next = label();
                condition(s, scope, Op::Beq, next);
                block(s.body, scope);
                ins(Op::Label, next);
                break;
            }
            case Statement::IfElse:
            {
                auto otherwise = label(), next = label();
                condition(s, scope, Op::Beq, otherwise);
                block(s.body, scope);
                ins(Op::Jmp, next);
                ins(Op::Label, otherwise);
                block(s.alternative, scope);
                ins(Op::Label, next);
                break;
            }
            case Statement::For:
            {
                BlockScope loop(scope, true);
                auto begin = label(), tail = label(), body = label(), next = label();
                stmt(s.clauses.at(0), loop);
                ins(Op::Label, begin);
                condition(s, loop, Op::Bne, body);
                ins(Op::Jmp, next);
                ins(Op::Label, tail);
                stmt(s.clauses.at(1), loop);
                ins(Op::Jmp, begin);
                ins(Op::Label, body);
                block(s.body, loop);
                ins(Op::Jmp, tail);
                ins(Op::Label, next);
                break;
            }
            case Statement::DoWhile:
            {
                auto begin = label();
                ins(Op::Label, begin);
                block(s.body, scope);
                condition(s, scope, Op::Bne, begin);
                break;
            }
            case Statement::Switch:
            {
                auto dispatch = label(), next = label();
                expression(s.expression, scope);
                ins(Op::Jmp, dispatch);
                switch_breaks.push_back(next);
                bool found_default = false;
                for (auto &c : s.cases)
                {
                    if (c.kind == SwitchCase::Default || c.kind == SwitchCase::ImplicitDefault)
                    {
                        if (found_default)
                            fail("multiple switch defaults");
                        found_default = true;
                    }
                    if (c.kind == SwitchCase::Default)
                        result.instructions.push_back({ Op::Case, Integer(s.switch_id), 0, true });
                    if (c.kind == SwitchCase::Values)
                        for (auto &expr : c.values)
                        {
                            auto value = constant(expr, scope);
                            if (!value || !std::holds_alternative<Integer>(*value))
                                fail("switch case requires an integer constant");
                            auto number = std::get<Integer>(*value);
                            if (!encodable_integer(number))
                                fail("case value exceeds VM range");
                            result.instructions.push_back(
                                { Op::Case, Integer(s.switch_id), number, false });
                        }
                    block(c.body, scope);
                    if (c.kind == SwitchCase::DeadJump ||
                        (!c.fallthrough && !sequence_terminates(c.body)))
                        ins(Op::Jmp, next);
                }
                switch_breaks.pop_back();
                if (!s.compact)
                    ins(Op::Jmp, next);
                ins(Op::Label, dispatch);
                ins(Op::Switch, Integer(s.switch_id));
                ins(Op::Label, next);
                break;
            }
            case Statement::JumpNext:
            {
                auto target = label();
                ins(Op::Jmp, target);
                ins(Op::Label, target);
                break;
            }
            case Statement::Break:
                if (switch_breaks.empty())
                    fail("break outside switch");
                ins(Op::Jmp, switch_breaks.back());
                break;
            case Statement::Exit:
                ins(Op::Exit);
                break;
            case Statement::Ir:
                fail("IR block must be the script's only statement");
        }
    }
};

} // namespace

Script compile_script(std::vector<Statement> statements, const ConstScope &scope)
{
    if (statements.size() == 1 && statements[0].kind == Statement::Ir)
        return statements[0].raw_ir;
    std::size_t switches = 0;
    allocate_switches(statements, switches);
    Emitter emitter;
    BlockScope root(scope);
    for (auto &statement : statements)
        emitter.stmt(statement, root);
    return std::move(emitter.result);
}

} // namespace mary
