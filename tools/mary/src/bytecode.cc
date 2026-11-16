#include "bytecode.hh"

#include <algorithm>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>

namespace mary
{
namespace
{

[[noreturn]] void fail(const std::string &message)
{
    throw std::runtime_error(message);
}

void range(const Bytes &data, std::size_t offset, std::size_t length)
{
    if (offset > data.size() || length > data.size() - offset)
        fail("truncated bytecode");
}

std::uint32_t size32(std::size_t value)
{
    if (value > UINT32_MAX)
        fail("bytecode exceeds its 32-bit size field");
    return static_cast<std::uint32_t>(value);
}

void patch(Bytes &out, std::size_t at, std::uint32_t value)
{
    range(out, at, 4);
    for (unsigned i = 0; i < 4; ++i)
        out[at + i] = static_cast<std::uint8_t>(value >> (8 * i));
}

void word(Bytes &out, std::uint32_t value)
{
    auto at = out.size();
    out.resize(at + 4);
    patch(out, at, value);
}

void tag(Bytes &out, const char *value)
{
    out.insert(out.end(), value, value + 4);
}

bool branch(Op op)
{
    return op >= Op::Jmp && op <= Op::Bgt;
}

std::uint32_t id(Integer value)
{
    if (value < 0 || value > UINT32_MAX)
        fail("bytecode ID is outside its 32-bit field");
    return static_cast<std::uint32_t>(value);
}

unsigned operand_size(unsigned opcode)
{
    if (opcode == 0x22)
        return 2;
    if (opcode == 0x23)
        return 1;
    if (opcode == 0x13 || opcode == 0x14 || opcode == 0x17 || (opcode >= 0x18 && opcode <= 0x1e) ||
        opcode == 0x21 || opcode == 0x24)
        return 4;
    return 0;
}

bool valid_opcode(unsigned opcode)
{
    return opcode <= 0x1e || (opcode >= 0x20 && opcode <= 0x24);
}

struct Case
{
    bool is_default;
    Integer value;
    std::size_t target;
};

struct Jump
{
    std::size_t source, target, label;
};

struct Chunk
{
    std::size_t start, size;
};

void validate(const Script &script)
{
    std::set<Integer> labels, switches;
    std::vector<Integer> targets, case_tables;
    std::map<Integer, std::set<std::pair<bool, Integer>>> cases;
    for (auto &ins : script.instructions)
    {
        if (ins.op == Op::PushInt && !encodable_integer(ins.argument))
            fail("integer does not fit the bytecode's 32-bit field");
        if (ins.op == Op::Case && !ins.default_case && !encodable_integer(ins.case_value))
            fail("case value does not fit the bytecode's 32-bit field");
        switch (ins.op)
        {
            case Op::Label:
                id(ins.argument);
                if (!labels.insert(ins.argument).second)
                    fail("duplicate jump label");
                break;
            case Op::Switch:
                id(ins.argument);
                if (!switches.insert(ins.argument).second)
                    fail("duplicate switch table");
                break;
            case Op::Case:
                id(ins.argument);
                case_tables.push_back(ins.argument);
                if (!cases[ins.argument]
                         .insert({ ins.default_case, ins.default_case ? 0 : ins.case_value })
                         .second)
                    fail("duplicate switch case or default");
                break;
            case Op::PushVar:
            case Op::PopVar:
            case Op::Call:
                id(ins.argument);
                break;
            default:
                if (branch(ins.op))
                {
                    id(ins.argument);
                    targets.push_back(ins.argument);
                }
        }
    }
    for (auto target : targets)
        if (!labels.count(target))
            fail("jump target label is not defined");
    for (auto table : case_tables)
        if (!switches.count(table))
            fail("case refers to an undefined switch");
}

} // namespace

std::uint32_t read_u32(const Bytes &data, std::size_t offset)
{
    range(data, offset, 4);
    std::uint32_t value = 0;
    for (unsigned i = 0; i < 4; ++i)
        value |= std::uint32_t(data[offset + i]) << (8 * i);
    return value;
}

Bytes encode_script(const Script &script)
{
    validate(script);
    Bytes out;
    tag(out, "RIFF");
    word(out, 0);
    tag(out, "SCR ");
    tag(out, "CODE");
    word(out, 0);
    word(out, 0);
    const auto code_start = out.size();
    std::map<Integer, std::size_t> labels;
    std::vector<std::pair<std::size_t, Integer>> patches;
    std::vector<std::vector<Case>> tables;
    for (auto &ins : script.instructions)
        if (ins.op == Op::Switch)
            tables.resize(std::max(tables.size(), std::size_t(ins.argument) + 1));
    for (auto &ins : script.instructions)
    {
        if (ins.op == Op::Label)
        {
            labels[ins.argument] = out.size() - code_start;
        }
        else if (ins.op == Op::Case)
        {
            tables.at(std::size_t(ins.argument))
                .push_back({ ins.default_case, ins.case_value, out.size() - code_start });
        }
        else if (ins.op == Op::PushInt)
        {
            const auto value = static_cast<std::uint32_t>(ins.argument);
            // Preserve the original compiler's signed-width thresholds.
            if (value < 0x80)
            {
                out.push_back(0x23);
                out.push_back(static_cast<std::uint8_t>(value));
            }
            else if (value < 0x8000)
            {
                out.push_back(0x22);
                out.push_back(static_cast<std::uint8_t>(value));
                out.push_back(static_cast<std::uint8_t>(value >> 8));
            }
            else
            {
                out.push_back(0x17);
                word(out, value);
            }
        }
        else
        {
            const auto opcode = static_cast<unsigned>(ins.op);
            if (!valid_opcode(opcode) || opcode == 0 || opcode == 0x22 || opcode == 0x23)
                fail("invalid intermediate instruction");
            out.push_back(static_cast<std::uint8_t>(opcode));
            if (branch(ins.op))
            {
                patches.push_back({ out.size(), ins.argument });
                word(out, 0);
            }
            else if (operand_size(opcode))
            {
                word(out, id(ins.argument));
            }
        }
    }
    for (auto &entry : patches)
        patch(out, entry.first, size32(labels.at(entry.second)));
    out.push_back(0x20);
    while ((out.size() - code_start) % 4)
        out.push_back(0);
    patch(out, code_start - 4, size32(out.size() - code_start));
    patch(out, 16, size32(out.size() - 20));
    if (!tables.empty())
    {
        tag(out, "JUMP");
        const auto length = out.size();
        word(out, 0);
        word(out, size32(tables.size()));
        const auto pool = out.size();
        out.resize(out.size() + tables.size() * 4);
        for (std::size_t i = 0; i < tables.size(); ++i)
        {
            patch(out, pool + i * 4, size32(out.size() - pool));
            auto values = tables[i];
            auto def = std::find_if(
                values.begin(), values.end(), [](const Case &c) { return c.is_default; });
            word(out, size32(values.size() - (def != values.end())));
            word(out, def != values.end() ? size32(def->target) : UINT32_MAX);
            std::stable_sort(values.begin(),
                             values.end(),
                             [](const Case &a, const Case &b)
                             { return std::tie(a.value, a.target) < std::tie(b.value, b.target); });
            for (auto &c : values)
                if (!c.is_default)
                {
                    word(out, static_cast<std::uint32_t>(c.value));
                    word(out, size32(c.target));
                }
        }
        patch(out, length, size32(out.size() - length - 4));
    }
    tag(out, "STR ");
    const auto length = out.size();
    word(out, 0);
    word(out, size32(script.strings.size()));
    const auto offsets = out.size();
    out.resize(out.size() + script.strings.size() * 4);
    const auto pool = out.size();
    for (std::size_t i = 0; i < script.strings.size(); ++i)
    {
        patch(out, offsets + i * 4, size32(out.size() - pool));
        out.insert(out.end(), script.strings[i].begin(), script.strings[i].end());
        out.push_back(0);
    }
    patch(out, length, size32(out.size() - length - 4));
    patch(out, 4, size32(out.size()));
    return out;
}

Script decode_script(const Bytes &riff)
{
    return decode_script(riff, riff);
}

Script decode_script(const Bytes &riff, const Bytes &backing)
{
    range(riff, 0, 12);
    if (!std::equal(riff.begin(), riff.begin() + 4, "RIFF") ||
        !std::equal(riff.begin() + 8, riff.begin() + 12, "SCR "))
        fail("not a valid script binary (invalid RIFF/SCR magic)");
    const auto total = read_u32(riff, 4);
    if (total < 12 || total > riff.size())
        fail("inconsistent RIFF size");
    std::map<std::string, Chunk> chunks;
    for (std::size_t at = 12; at < total;)
    {
        if (total - at < 8)
            fail("inconsistent RIFF chunk boundary");
        auto length = read_u32(riff, at + 4);
        if (length > total - at - 8)
            fail("RIFF chunk exceeds declared size");
        std::string name(riff.begin() + at, riff.begin() + at + 4);
        if (!chunks.emplace(name, Chunk{ at + 8, length }).second)
            fail("duplicate RIFF chunk: " + name);
        at += 8 + length;
    }
    if (!chunks.count("CODE"))
        fail("missing CODE chunk");
    const auto code = chunks.at("CODE");
    if (code.size < 4 || read_u32(riff, code.start) != code.size - 4)
        fail("CODE chunk size mismatch");
    Bytes bytes(riff.begin() + code.start + 4, riff.begin() + code.start + code.size);
    std::size_t final_end = bytes.size();
    for (std::size_t at = 0; at < bytes.size();)
    {
        auto op = bytes[at];
        if (!valid_opcode(op))
            fail("unknown CODE opcode at " + std::to_string(at));
        auto length = 1 + operand_size(op);
        range(bytes, at, length);
        if (op == 0x20)
            final_end = at;
        at += length;
    }
    if (final_end == bytes.size())
        fail("CODE has no terminating END");
    if (std::any_of(
            bytes.begin() + final_end + 1, bytes.end(), [](std::uint8_t v) { return v != 0; }))
        fail("non-NOP CODE padding");
    bytes.resize(final_end);
    std::set<std::size_t> boundaries{ bytes.size() };
    std::vector<Jump> jumps;
    for (std::size_t at = 0; at < bytes.size();)
    {
        boundaries.insert(at);
        if (branch(static_cast<Op>(bytes[at])))
            jumps.push_back({ at, read_u32(bytes, at + 1), jumps.size() });
        at += 1 + operand_size(bytes[at]);
    }
    std::stable_sort(jumps.begin(),
                     jumps.end(),
                     [](const Jump &a, const Jump &b)
                     {
                         if (a.target != b.target)
                             return a.target < b.target;
                         auto da = Integer(a.target) - Integer(a.source + 1);
                         auto db = Integer(b.target) - Integer(b.source + 1);
                         if ((da < 0 && db < 0) || (da > 0 && db > 0))
                             return da < db;
                         return da > db;
                     });
    std::map<std::size_t, std::size_t> jump_sources;
    for (auto &j : jumps)
    {
        if (!boundaries.count(j.target))
            fail("jump target is not an instruction boundary");
        jump_sources[j.source] = j.label;
    }
    std::vector<std::tuple<std::size_t, std::size_t, Case>> cases;
    std::size_t table_count = 0;
    if (chunks.count("JUMP"))
    {
        auto chunk = chunks.at("JUMP");
        Bytes data(riff.begin() + chunk.start, riff.begin() + chunk.start + chunk.size);
        table_count = read_u32(data, 0);
        range(data, 4, table_count * 4);
        for (std::size_t i = 0; i < table_count; ++i)
        {
            auto offset = read_u32(data, 4 + i * 4);
            if (offset % 4)
                fail("misaligned JUMP table offset");
            const auto at = std::size_t(offset) + 4;
            auto count = read_u32(data, at), def = read_u32(data, at + 4);
            range(data, at + 8, std::size_t(count) * 8);
            std::set<Integer> values;
            auto add_case = [&](bool is_default, Integer value, std::size_t target)
            {
                if (!boundaries.count(target))
                    fail("case target is not an instruction boundary");
                cases.emplace_back(target, i, Case{ is_default, value, target });
            };
            if (!(def & 0x80000000))
                add_case(true, 0, def);
            for (std::size_t n = 0; n < count; ++n)
            {
                const auto raw = read_u32(data, at + 8 + n * 8);
                const Integer value =
                    raw <= INT32_MAX ? Integer(raw) : Integer(raw) - 0x100000000LL;
                if (!values.insert(value).second)
                    fail("duplicate JUMP case value");
                add_case(false, value, read_u32(data, at + 12 + n * 8));
            }
        }
    }
    std::stable_sort(cases.begin(),
                     cases.end(),
                     [](const auto &a, const auto &b) { return std::get<0>(a) < std::get<0>(b); });
    Script result;
    std::size_t ji = 0, ci = 0;
    std::set<std::uint32_t> switches;
    auto labels_at = [&](std::size_t at)
    {
        while (ji < jumps.size() && jumps[ji].target == at)
            result.instructions.push_back({ Op::Label, Integer(jumps[ji++].label) });
        while (ci < cases.size() && std::get<0>(cases[ci]) == at)
        {
            auto &c = std::get<2>(cases[ci]);
            result.instructions.push_back(
                { Op::Case, Integer(std::get<1>(cases[ci])), c.value, c.is_default });
            ++ci;
        }
    };
    for (std::size_t at = 0; at < bytes.size();)
    {
        labels_at(at);
        const auto opcode = bytes[at];
        const auto width = operand_size(opcode);
        std::uint32_t value = 0;
        for (unsigned i = 0; i < width; ++i)
            value |= std::uint32_t(bytes[at + 1 + i]) << (8 * i);
        auto op = static_cast<Op>(opcode);
        Integer arg = value;
        if (opcode == 0x17 || opcode == 0x22 || opcode == 0x23)
        {
            op = Op::PushInt;
            if (value > INT32_MAX)
                arg -= 0x100000000LL;
        }
        if (branch(op))
            arg = Integer(jump_sources.at(at));
        if (op == Op::Switch)
        {
            if (value >= table_count)
                fail("CODE refers to a missing switch table");
            if (!switches.insert(value).second)
                fail("CODE repeats a switch table ID");
        }
        if (opcode != 0)
            result.instructions.push_back({ op, arg });
        at += 1 + width;
    }
    labels_at(bytes.size());
    const auto expected_tables = switches.empty() ? 0 : std::size_t(*switches.rbegin()) + 1;
    if (expected_tables != table_count)
        fail("CODE/JUMP switch table count mismatch");
    if (chunks.count("STR "))
    {
        const auto chunk = chunks.at("STR ");
        if (chunk.size < 4)
            fail("corrupt STR chunk");
        const auto count = read_u32(riff, chunk.start);
        if (count > (chunk.size - 4) / 4)
            fail("corrupt STR offset table");
        const auto pool = chunk.start + 4 + std::size_t(count) * 4;
        const auto &storage = backing.size() >= chunk.start ? backing : riff;
        // Without external backing, the declared STR chunk is the boundary.
        const auto end = &backing == &riff ? chunk.start + chunk.size : storage.size();
        for (std::size_t i = 0; i < count; ++i)
        {
            auto offset = read_u32(riff, chunk.start + 4 + i * 4);
            if (pool > end || offset >= end - pool)
                fail("STR offset is outside available storage");
            auto start = storage.begin() + pool + offset;
            auto terminator = std::find(start, storage.begin() + end, 0);
            if (terminator == storage.begin() + end)
                fail("unterminated STR string");
            result.strings.emplace_back(start, terminator);
        }
    }
    return result;
}

} // namespace mary
