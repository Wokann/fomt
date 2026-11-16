#include "low_level.hh"
#include "pretty.hh"
#include <map>
#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{

const std::map<std::string, Op> names{ { "Assign", Op::Assign },
                                       { "AssignAdd", Op::AssignAdd },
                                       { "AssignSub", Op::AssignSub },
                                       { "AssignMul", Op::AssignMul },
                                       { "AssignDiv", Op::AssignDiv },
                                       { "AssignMod", Op::AssignMod },
                                       { "Add", Op::Add },
                                       { "Sub", Op::Sub },
                                       { "Mul", Op::Mul },
                                       { "Div", Op::Div },
                                       { "Mod", Op::Mod },
                                       { "LogicalAnd", Op::LogicalAnd },
                                       { "LogicalOr", Op::LogicalOr },
                                       { "Inc", Op::Inc },
                                       { "Dec", Op::Dec },
                                       { "Neg", Op::Neg },
                                       { "LogicalNot", Op::LogicalNot },
                                       { "Cmp", Op::Cmp },
                                       { "PushVar", Op::PushVar },
                                       { "PopVar", Op::PopVar },
                                       { "Dupe", Op::Dupe },
                                       { "Discard", Op::Discard },
                                       { "PushInt", Op::PushInt },
                                       { "Jmp", Op::Jmp },
                                       { "Blt", Op::Blt },
                                       { "Ble", Op::Ble },
                                       { "Beq", Op::Beq },
                                       { "Bne", Op::Bne },
                                       { "Bge", Op::Bge },
                                       { "Bgt", Op::Bgt },
                                       { "Call", Op::Call },
                                       { "Switch", Op::Switch },
                                       { "Exit", Op::Exit },
                                       { "Case", Op::Case },
                                       { "Default", Op::Case },
                                       { "Label", Op::Label } };
bool has_argument(Op op)
{
    return op == Op::PushVar || op == Op::PopVar || op == Op::PushInt ||
           (op >= Op::Jmp && op <= Op::Bgt) || op == Op::Call || op == Op::Switch ||
           op == Op::Label || op == Op::Case;
}
} // namespace

Script parse_ir(Tokens &tokens)
{
    Script result;
    tokens.require("{");
    while (!tokens.eat("}"))
    {
        auto name = tokens.identifier();
        tokens.require("(");
        if (name == "String")
        {
            if (!result.instructions.empty())
                tokens.error("String entries must precede instructions");
            if (tokens.peek().kind != TokenKind::String)
                tokens.error("String requires a string literal");
            Bytes bytes;
            do
            {
                auto literal = tokens.take();
                bytes.insert(bytes.end(), literal.bytes.begin(), literal.bytes.end());
            } while (tokens.peek().kind == TokenKind::String);
            result.strings.push_back(std::move(bytes));
        }
        else
        {
            auto found = names.find(name);
            if (found == names.end())
                tokens.error("unknown IR instruction: " + name);
            Instruction instruction{ found->second };
            if (has_argument(instruction.op))
            {
                instruction.argument = tokens.integer();
                if (instruction.op != Op::PushInt && instruction.argument < 0)
                    tokens.error("IR ID must be nonnegative");
            }
            if (name == "Case")
            {
                tokens.require(",");
                instruction.case_value = tokens.integer();
            }
            if (name == "Default")
                instruction.default_case = true;
            result.instructions.push_back(instruction);
        }
        tokens.require(")");
    }
    return result;
}

std::string format_ir(const Script &script, unsigned indent, const Charmap *map)
{
    std::ostringstream out;
    std::string prefix(indent * 4, ' ');
    for (auto &string : script.strings)
    {
        out << prefix << "String(";
        if (map)
        {
            auto fragments = string_fragments(string, map, true);
            for (std::size_t i = 0; i < fragments.size(); ++i)
            {
                if (i)
                    out << '\n' << prefix << "       ";
                out << '"' << fragments[i] << '"';
            }
        }
        else
        {
            out << '"';
            const char hex[] = "0123456789ABCDEF";
            for (auto byte : string)
                out << "\\x" << hex[byte >> 4] << hex[byte & 15];
            out << '"';
        }
        out << ")\n";
    }
    for (auto &instruction : script.instructions)
    {
        std::string name;
        if (instruction.op == Op::Case)
            name = instruction.default_case ? "Default" : "Case";
        else
            for (auto &entry : names)
                if (entry.second == instruction.op)
                {
                    name = entry.first;
                    break;
                }
        if (name.empty())
            throw std::runtime_error("unknown intermediate opcode");
        out << prefix << name << "(";
        if (has_argument(instruction.op))
            out << instruction.argument;
        if (instruction.op == Op::Case && !instruction.default_case)
            out << ", " << instruction.case_value;
        out << ")\n";
    }
    return out.str();
}

} // namespace mary
