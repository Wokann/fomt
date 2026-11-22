#ifndef MARY_IR_HH
#define MARY_IR_HH

#include <cstddef>
#include <cstdint>
#include <vector>

namespace mary
{

using Bytes = std::vector<std::uint8_t>;
using Integer = std::int64_t;

// Physical opcodes retain their VM values. Labels and cases occupy no CODE bytes.
enum class Op : unsigned
{
    Assign = 1,
    AssignAdd,
    AssignSub,
    AssignMul,
    AssignDiv,
    AssignMod,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    LogicalAnd,
    LogicalOr,
    Inc,
    Dec,
    Neg,
    LogicalNot,
    Cmp,
    PushVar,
    PopVar,
    Dupe,
    Discard,
    PushInt,
    Jmp,
    Blt,
    Ble,
    Beq,
    Bne,
    Bge,
    Bgt,
    Exit = 0x20,
    Call,
    Switch = 0x24,
    Label = 0x100,
    Case
};

struct Instruction
{
    Op op;
    Integer argument = 0;
    Integer case_value = 0;
    bool default_case = false;
    std::size_t source_line = 0;
    // Instruction index where evaluation of a source-level condition starts.
    std::size_t condition_start = SIZE_MAX;
    bool jump_on_true = false;
};

struct Script
{
    std::vector<Instruction> instructions;
    std::vector<Bytes> strings;
};

inline bool encodable_integer(Integer value)
{
    return value >= INT32_MIN && value <= UINT32_MAX;
}

} // namespace mary
#endif
