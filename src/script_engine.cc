#if defined(REGION_JP)
/*
 * Byte-exact JP assembly stays in this module.  As matching functions are
 * recovered, keep shared definitions outside the regional guard and retain
 * only genuinely version-specific definitions inside it.
 */
asm(
    "    @ JP revision 0 counterpart of src/script_engine.cc.\n"
    "    @\n"
    "    @ Script instructions and their text-dependent control flow are kept as\n"
    "    @ one static JP implementation.  Each public function boundary below was\n"
    "    @ matched against the JP ROM; no generator participates in the build.\n"
    "\n"
    "    .section .text\n"
    "    .syntax unified\n"
    "    .thumb\n"
    "\n"
    "    .macro jp_script_func name, start, end\n"
    "        .global \\name\n"
    "        .thumb_func\n"
    "\\name:\n"
    "        .incbin \"baserom_jp.gba\", \\start, (\\end - \\start)\n"
    "    .endm\n"
    "\n"
    "    jp_script_func __13AScriptEngine, 0x3EB08, 0x3EB3C\n"
    "    jp_script_func _._13AScriptEngine, 0x3EB3C, 0x3EB60\n"
    "    jp_script_func Load__13AScriptEnginePCv, 0x3EB60, 0x3EC4C\n"
    "    jp_script_func method_0803EFD8__13AScriptEngine, 0x3EC4C, 0x3ECA0\n"
    "    jp_script_func method_0803F02C__C13AScriptEngine, 0x3ECA0, 0x3ECA4\n"
    "    jp_script_func Opcode__C13AScriptEnginei, 0x3ECA4, 0x3ECB0\n"
    "    jp_script_func OpcodeFlag__C13AScriptEnginei, 0x3ECB0, 0x3ECBC\n"
    "    jp_script_func Operand32__C13AScriptEnginei, 0x3ECBC, 0x3ECF8\n"
    "    jp_script_func Operand16__C13AScriptEnginei, 0x3ECF8, 0x3ED28\n"
    "    jp_script_func Operand8__C13AScriptEnginei, 0x3ED28, 0x3ED50\n"
    "    jp_script_func method_0803F0DC__C13AScriptEngine, 0x3ED50, 0x3ED54\n"
    "    jp_script_func NextInstruction__13AScriptEngine, 0x3ED54, 0x3F454\n"
    "    jp_script_func GetString__C13AScriptEngineUi, 0x3F454, 0x3F478\n"
    "    jp_script_func __12ScriptEnginePv, 0x3F478, 0x3F4B0\n"
    "    jp_script_func __12ScriptEnginePvT1, 0x3F4B0, 0x3F4EC\n"
    "    jp_script_func LoadById__12ScriptEngineii, 0x3F4EC, 0x3F514\n"
    "    jp_script_func SetUnk__12ScriptEnginePv, 0x3F514, 0x3F520\n"
    "    jp_script_func ClearUnk__12ScriptEngine, 0x3F520, 0x3F52C\n"
    "    jp_script_func Push__12ScriptEnginei, 0x3F52C, 0x3F704\n"
    "\n"
    "    @ The template helper is emitted in the same dedicated linkonce section\n"
    "    @ as the US object so fomt_jp.lds can retain the original object layout.\n"
    "    .section .gnu.linkonce.t.__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01, \"ax\", %progbits\n"
    "    .global __lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01\n"
    "    .thumb_func\n"
    "__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01:\n"
    "    .incbin \"baserom_jp.gba\", 0xE0654, 0x3C\n"
    "\n"
    "    @ This ordinary C++ string object follows the JP data layout.  The\n"
    "    @ adjacent JP data signature fixes this copy at ROM offset 0xF96F4.\n"
    "    .section .rodata\n"
    "    .incbin \"baserom_jp.gba\", 0xF96F4, 0x14\n"
    "\n"
    "    @ Keep later shared C++ emission in agbcp's default syntax mode.\n"
    "    .syntax divided\n"
);
#else

#include "script_engine.hh"

#include <string.h> // memset, memcpy
#include <algorithm>

AScriptEngine::AScriptEngine()
    : unk_00(0)
{
    stack.Clear();
}

AScriptEngine::~AScriptEngine() {}

bool AScriptEngine::Load(void const * script_data)
{
    // TODO: constants

    struct ScriptHead
    {
        u32 riff_magic;
        u32 length;
        u32 scr_magic;
    };

    struct ChunkHead
    {
        u32 magic;
        u32 length;
    };

    if (script_data == nullptr)
        return false;

    unsigned char const * script = reinterpret_cast<unsigned char const *>(script_data);

    ScriptHead head;
    memcpy(&head, script, sizeof(ScriptHead));

    u32 offset = sizeof(ScriptHead);

    // 'RIFF' & 'SCR '
    if (head.riff_magic == 0x46464952 && head.scr_magic == 0x20524353)
    {
        u32 length = head.length;

        code = nullptr;

        while (offset <= length)
        {
            ChunkHead chunk;
            memcpy(&chunk, script + offset, sizeof(ChunkHead));

            offset = offset + sizeof(ChunkHead);

            if (chunk.magic == 0x45444F43) // 'CODE'
            {
                pc = 0;
                code_length = *reinterpret_cast<u32 const *>(script + offset);
                code = script + offset + sizeof(u32);
            }
            else if (chunk.magic == 0x20525453) // 'STR '
            {
                string_count = *reinterpret_cast<u32 const *>(script + offset);
                string_offset_table = reinterpret_cast<u32 const *>(script + sizeof(u32) + offset);
                string_pool = reinterpret_cast<char const *>(string_offset_table + string_count);
            }
            else if (chunk.magic == 0x504D554A) // 'JUMP'
            {
                jump_count = *reinterpret_cast<u32 const *>(script + offset);
                jump_table = script + offset + sizeof(u32);
            }

            offset = offset + chunk.length;
        }

        if (code != nullptr)
        {
            stack.Clear();
            unk_348 = 0;
            memset(vmmem, 0, sizeof(vmmem));
            unk_00 = 1;

            return true;
        }
    }

    return false;
}

int AScriptEngine::method_0803EFD8()
{
    if (unk_00 != 0)
    {
        switch (unk_00)
        {
            case 1:
                for (int r2 = 0; r2 == 0;)
                {
                    r2 = NextInstruction();

                    switch (r2)
                    {
                        case -3:
                            unk_00 = 0;
                            break;

                        case -2:
                            unk_00 = 0;
                            break;

                        case -1:
                            unk_00 = 0;
                            break;

                        case +1:
                            break;

                        case +2:
                            unk_00 = 0;
                            break;
                    }
                }

                break;
        }
    }

    return unk_00;
}

int AScriptEngine::method_0803F02C() const
{
    return unk_00;
}

int AScriptEngine::Opcode(int offset) const
{
    return code[offset] & 0x7F;
}

fu8 AScriptEngine::OpcodeFlag(int offset) const
{
    return code[offset] >> 7;
}

u32 AScriptEngine::Operand32(int offset) const
{
    u32 result;

    fu8 flag = OpcodeFlag(offset);

    result = code[offset + 1];
    result += code[offset + 2] << 8;
    result += code[offset + 3] << 16;
    result += code[offset + 4] << 24;

    if (flag != 0)
    {
        result += unk_348;
    }

    return result;
}

u32 AScriptEngine::Operand16(int offset) const
{
    u32 result;

    fu8 flag = OpcodeFlag(offset);

    result = code[offset + 1];
    result += code[offset + 2] << 8;

    if (flag != 0)
    {
        result += unk_348;
    }

    return result;
}

u32 AScriptEngine::Operand8(int offset) const
{
    u32 result;

    fu8 flag = OpcodeFlag(offset);

    result = code[offset + 1];

    if (flag != 0)
    {
        result += unk_348;
    }

    return result;
}

void AScriptEngine::method_0803F0DC() const {}

struct ScriptJumpTableSearchCompare
{
    bool operator()(JumpTableEnt const & left, int right) { return left.value < right; }
};

int AScriptEngine::NextInstruction()
{
    switch (Opcode(pc))
    {
        case 0x00:
        {
            pc += 1;
            break;
        }

        case 0x01:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            vmmem[op1] = stack.Top() = op2;
            pc += 1;
            break;
        }

        case 0x02:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            int val = vmmem[op1] + op2;
            vmmem[op1] = stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x03:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            int val = vmmem[op1] - op2;
            vmmem[op1] = stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x04:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            int val = vmmem[op1] * op2;
            vmmem[op1] = stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x05:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();

            if (op2 == 0)
                return -2;

            int val = vmmem[op1] / op2;
            vmmem[op1] = stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x06:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();

            if (op2 == 0)
                return -2;

            int val = vmmem[op1] % op2;
            vmmem[op1] = stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x07:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            int val = op1 + op2;
            stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x08:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            int val = op1 - op2;
            stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x09:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            int val = op1 * op2;
            stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x0A:
        {
            int op2 = stack.Top();
            stack.Pop();

            if (op2 == 0)
                return -2;

            int op1 = stack.Top();
            int val = op1 / op2;
            stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x0B:
        {
            int op2 = stack.Top();
            stack.Pop();

            if (op2 == 0)
                return -2;

            int op1 = stack.Top();
            int val = op1 % op2;
            stack.Top() = val;
            pc += 1;
            break;
        }

        case 0x0C:
        {
            int op2 = stack.Top();
            stack.Pop();
            stack.Top() = stack.Top() && op2;
            pc += 1;
            break;
        }

        case 0x0D:
        {
            int op2 = stack.Top();
            stack.Pop();
            stack.Top() = stack.Top() || op2;
            pc += 1;
            break;
        }

        case 0x0E:
        {
            stack.Top() = stack.Top() + 1;
            pc += 1;
            break;
        }

        case 0x0F:
        {
            stack.Top() = stack.Top() - 1;
            pc += 1;
            break;
        }

        case 0x10:
        {
            stack.Top() = -stack.Top();
            pc += 1;
            break;
        }

        case 0x11:
        {
            stack.Top() = !stack.Top();
            pc += 1;
            break;
        }

        case 0x13:
        {
            int var = Operand32(pc);
            stack.Push(vmmem[var]);
            pc += 5;
            break;
        }

        case 0x14:
        {
            int var = Operand32(pc);
            vmmem[var] = stack.Top();
            stack.Pop();
            pc += 5;
            break;
        }

        case 0x15:
        {
            int val = stack.Top();
            stack.Push(val);
            pc += 1;
            break;
        }

        case 0x16:
        {
            stack.Pop();
            pc += 1;
            break;
        }

        case 0x17:
        {
            int value = Operand32(pc);
            stack.Push(value);
            pc += 5;
            break;
        }

        case 0x22:
        {
            int value = Operand16(pc);
            stack.Push(value);
            pc += 3;
            break;
        }

        case 0x23:
        {
            int value = Operand8(pc);
            stack.Push(value);
            pc += 2;
            break;
        }

        case 0x12:
        {
            int op2 = stack.Top();
            stack.Pop();
            int op1 = stack.Top();
            stack.Pop();

            if (op1 > op2)
                stack.Push(1);
            else if (op1 < op2)
                stack.Push(-1);
            else
                stack.Push(0);

            pc += 1;
            break;
        }

        case 0x18:
        {
            pc = Operand32(pc);
            break;
        }

        case 0x19:
        {
            int target = Operand32(pc);
            pc += 5;

            if (stack.Top() < 0)
                pc = target;

            stack.Pop();
            break;
        }

        case 0x1A:
        {
            int operand = Operand32(pc);
            pc += 5;

            if (stack.Top() <= 0)
                pc = operand;

            stack.Pop();
            break;
        }

        case 0x1B:
        {
            int operand = Operand32(pc);
            pc += 5;

            if (stack.Top() == 0)
                pc = operand;

            stack.Pop();
            break;
        }

        case 0x1C:
        {
            int operand = Operand32(pc);
            pc += 5;

            if (stack.Top() != 0)
                pc = operand;

            stack.Pop();
            break;
        }

        case 0x1D:
        {
            int operand = Operand32(pc);
            pc += 5;

            if (stack.Top() >= 0)
                pc = operand;

            stack.Pop();
            break;
        }

        case 0x1E:
        {
            int operand = Operand32(pc);
            pc += 5;

            if (stack.Top() > 0)
                pc = operand;

            stack.Pop();
            break;
        }

        case 0x1F:
        {
            pc = stack.Top();
            stack.Pop();
            break;
        }

        case 0x20:
        {
            pc += 1;
            return 2;
        }

        case 0x21:
        {
            int operand = Operand32(pc);
            pc += 5;
            return OnCall(operand);
        }

        case 0x24:
        {
            // TODO: clean this up

            u32 const * jt = reinterpret_cast<u32 const *>(jump_table + reinterpret_cast<u32 const *>(jump_table)[Operand32(pc)]);
            JumpTableEnt const * beg = reinterpret_cast<JumpTableEnt const *>(jt + 2);
            JumpTableEnt const * end = reinterpret_cast<JumpTableEnt const *>(jt + 2) + jt[0];

            int value = stack.Top();
            stack.Pop();

            JumpTableEnt const * ent = std::lower_bound(beg, end, value, ScriptJumpTableSearchCompare());

            if (ent != end && ent->value == value)
            {
                pc = ent->target;
                return 0;
            }

            // note: this means there can't be a case at offset 0
            if ((i32)(jt[1]) > 0)
            {
                pc = jt[1];
                return 0;
            }

            pc += 5;
            break;
        }

        default:
            return -1;
    }

    return 0;
}

char const * AScriptEngine::GetString(u32 id) const
{
    // BUG: this should be strict compare
    if (id <= string_count)
        return string_pool + string_offset_table[id];

    return "Error";
}

ScriptEngine::ScriptEngine(void * arg_r1)
{
    unk_350 = arg_r1;
    unk_354 = nullptr;
    unk_358 = 0;
}

ScriptEngine::ScriptEngine(void * arg_r1, void * arg_r2)
{
    unk_350 = arg_r1;
    unk_354 = arg_r2;
    unk_358 = 0;
}

// TODO: move and dump
extern void const * const gUnk_080F89D4[]; // event scripts

void ScriptEngine::LoadById(int id, int arg_r2)
{
    Load(gUnk_080F89D4[id]);
    unk_358 = arg_r2;
}

void ScriptEngine::SetUnk(void * unk)
{
    unk_354 = unk;
}

void ScriptEngine::ClearUnk()
{
    unk_354 = nullptr;
}

void ScriptEngine::Push(i32 value)
{
    stack.Push(value);
}

// next up: int OnCall(int id);

#endif // REGION_JP
