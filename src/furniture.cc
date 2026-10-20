#include "furniture.hh"

Unk_0800BC58::Unk_0800BC58() {}

void Unk_0800BC58::method_0800BCB0(u32 unk)
{
    u32 unk_2 = unk - 0x4D;

    bit_array_00.Set(unk_2);
}

void Unk_0800BC58::method_0800BCD0(u32 unk)
{
    u32 unk_2 = unk - 0x4D;

    bit_array_00.Clear(unk_2);
    bit_array_08.Set(unk_2);
}

bool Unk_0800BC58::method_0800BD14(u32 unk) const
{
    u32 unk_2 = unk - 0x4D;

    return bit_array_00.Test(unk_2);
}

bool Unk_0800BC58::method_0800BD40(u32 unk) const
{
    u32 unk_2 = unk - 0x4D;

    return bit_array_08.Test(unk_2);
}

u32 Unk_0800BC58::method_0800BD6C() const
{
    return bit_array_00.Count();
}

u32 Unk_0800BC58::method_0800BDEC() const
{
    return bit_array_08.Count();
}

