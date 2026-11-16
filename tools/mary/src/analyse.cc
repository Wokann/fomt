#include "analyse.hh"
#include "bytecode.hh"
#include "io.hh"
#include "rom_import.hh"

#include <algorithm>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{

constexpr std::uint64_t unknown_maximum = 99999;

struct Displacement
{
    std::uint64_t minimum = 0, maximum = unknown_maximum;
};

struct CallableShape
{
    std::optional<bool> function;
    std::uint64_t minimum = 0, maximum = unknown_maximum;
};

struct Block
{
    std::vector<Instruction> instructions;
    std::vector<Displacement> stack;
};

std::uint64_t subtract(std::uint64_t a, std::uint64_t b)
{
    return a > b ? a - b : 0;
}

std::vector<Block> split(const std::vector<Instruction> &code)
{
    std::set<Integer> switches;
    for (std::size_t i = 0; i + 1 < code.size(); ++i)
        if (code[i].op == Op::Label && code[i + 1].op == Op::Switch)
            switches.insert(code[i].argument);
    std::vector<Block> blocks;
    std::vector<Instruction> current;
    auto flush = [&]
    {
        if (current.empty())
            return;
        auto count = current.size();
        blocks.push_back({ std::move(current), std::vector<Displacement>(count + 1) });
        current.clear();
    };
    for (std::size_t at = 0; at < code.size();)
    {
        auto ins = code[at];
        if (at + 6 < code.size() && ins.op == Op::Cmp && code[at + 2].op == Op::PushInt &&
            code[at + 3].op == Op::Jmp && code[at + 4].op == Op::Label &&
            code[at + 5].op == Op::PushInt && code[at + 6].op == Op::Label)
        {
            current.push_back(ins);
            at += 7;
            continue;
        }
        if (ins.op == Op::Label || ins.op == Op::Case)
        {
            flush();
            current.push_back(ins);
        }
        else if (ins.op == Op::Jmp && switches.count(ins.argument))
        {
            current.push_back({ Op::Discard });
            current.push_back(ins);
            flush();
        }
        else if (ins.op == Op::Switch)
            flush();
        else if (ins.op == Op::Assign)
        {
            current.push_back(ins);
            current.push_back({ Op::Discard });
            if (at + 1 < code.size() && code[at + 1].op == Op::Discard)
                ++at;
            flush();
        }
        else
        {
            current.push_back(ins);
            if (ins.op == Op::Discard || ins.op == Op::Exit ||
                (ins.op >= Op::Jmp && ins.op <= Op::Bgt))
                flush();
        }
        ++at;
    }
    flush();
    return blocks;
}

Integer displacement(Op op)
{
    if ((op >= Op::Assign && op <= Op::LogicalOr) || op == Op::Cmp || op == Op::PopVar ||
        op == Op::Discard || (op >= Op::Blt && op <= Op::Bgt) || op == Op::Switch)
        return -1;
    if (op == Op::PushVar || op == Op::PushInt || op == Op::Dupe)
        return 1;
    return 0;
}

void update(CallableShape &shape, Displacement before, Displacement after)
{
    bool procedure = after.maximum == 0, function = after.minimum > 0;
    if (procedure || function)
        shape.function = function;
    std::uint64_t minimum, maximum;
    if (shape.function && *shape.function)
    {
        minimum = subtract(before.minimum, subtract(after.maximum, 1));
        maximum = subtract(before.maximum, subtract(after.minimum, 1));
    }
    else if (shape.function)
    {
        minimum = before.minimum;
        maximum = before.maximum;
    }
    else
    {
        minimum = subtract(before.minimum, after.maximum);
        maximum = subtract(before.maximum, subtract(after.minimum, 1));
    }
    if (minimum <= maximum)
    {
        shape.minimum = std::max(shape.minimum, minimum);
        shape.maximum = std::min(shape.maximum, maximum);
    }
}

void backwards(Block &block, std::map<Integer, CallableShape> &knowledge)
{
    block.stack.back() = { 0, 0 };
    for (auto n = block.instructions.size(); n > 0; --n)
    {
        auto at = n - 1;
        auto after = block.stack[at + 1];
        auto &before = block.stack[at];
        auto ins = block.instructions[at];
        if (ins.op == Op::Call)
        {
            auto &shape = knowledge[ins.argument];
            update(shape, before, after);
            auto produced_min = shape.function && *shape.function ? 1u : 0u;
            auto produced_max = shape.function && !*shape.function ? 0u : 1u;
            before.minimum = subtract(after.minimum + shape.minimum, produced_max);
            before.maximum = subtract(after.maximum + shape.maximum, produced_min);
        }
        else
        {
            auto delta = displacement(ins.op);
            before.minimum = std::uint64_t(std::max<Integer>(0, Integer(after.minimum) - delta));
            before.maximum = std::uint64_t(std::max<Integer>(0, Integer(after.maximum) - delta));
        }
    }
}

void forwards(Block &block, std::map<Integer, CallableShape> &knowledge)
{
    block.stack.front() = { 0, 0 };
    for (std::size_t at = 0; at < block.instructions.size(); ++at)
    {
        auto before = block.stack[at];
        auto &after = block.stack[at + 1];
        auto ins = block.instructions[at];
        if (ins.op == Op::Call)
        {
            auto &shape = knowledge[ins.argument];
            update(shape, before, after);
            if (shape.minimum > shape.maximum)
                throw std::runtime_error("inconsistent callable constraints for ID " +
                                         std::to_string(ins.argument));
            if (shape.function && !*shape.function)
                after = { 0, 0 };
            else
            {
                auto produced_min = shape.function && *shape.function ? 1u : 0u;
                after.minimum = subtract(before.minimum, shape.maximum) + produced_min;
                after.maximum = subtract(before.maximum, shape.minimum) + 1;
            }
        }
        else
        {
            auto delta = displacement(ins.op);
            after.minimum = std::uint64_t(Integer(before.minimum) + delta);
            after.maximum = std::uint64_t(Integer(before.maximum) + delta);
        }
    }
}

} // namespace

std::string analyse_callable_shapes(const Bytes &rom)
{
    auto layout = resolve_script_layout(rom);
    std::vector<Block> blocks;
    for (auto &location : layout.scripts)
        if (location)
        {
            Bytes riff(rom.begin() + location->offset,
                       rom.begin() + location->offset + location->riff_length);
            auto script = decode_script(riff);
            auto local = split(script.instructions);
            blocks.insert(blocks.end(),
                          std::make_move_iterator(local.begin()),
                          std::make_move_iterator(local.end()));
        }
    std::map<Integer, CallableShape> knowledge;
    for (unsigned pass = 0; pass < 50; ++pass)
    {
        for (auto &block : blocks)
            backwards(block, knowledge);
        for (auto &block : blocks)
            forwards(block, knowledge);
    }
    std::ostringstream output;
    if (knowledge.empty())
        return {};
    auto last = knowledge.rbegin()->first;
    for (Integer id = 0; id <= last; ++id)
    {
        auto &shape = knowledge[id];
        auto keyword = !shape.function ? "// ?" : *shape.function ? "func" : "proc";
        auto prefix = !shape.function ? "Unk" : *shape.function ? "Func" : "Proc";
        output << keyword << " 0x" << hex(std::size_t(id), 3) << ' ' << prefix
               << hex(std::size_t(id), 3) << '(';
        for (std::uint64_t i = 0; i < shape.minimum; ++i)
        {
            if (i)
                output << ", ";
            output << "arg_" << i + 1;
        }
        if (shape.minimum != shape.maximum)
            output << " /* ... potentially up to " << shape.maximum << " */";
        output << ")\n";
    }
    return output.str();
}

} // namespace mary
