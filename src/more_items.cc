#include "more_items.hh"

#include <new>

MoreItems::MoreItems() : size(0), location(MAP_NONE, 0, 0)
{
}

u32 MoreItems::GetSize() const
{
    return size;
}

u8 * MoreItems::Begin()
{
    return data;
}

u8 * MoreItems::End()
{
    return data + size;
}

Location MoreItems::GetLocation() const
{
    return location;
}

void MoreItems::PushBack(u32 value)
{
    if (size < ARRAY_COUNT(data))
    {
        u8 * destination = (u8 *)this + (offsetof(MoreItems, data) + size);
        new (destination) u8(value);
        size++;
    }
}

void MoreItems::SetLocation(Location const & value)
{
    location = value;
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "\n"
    "    @ The remaining native range-destruction loop. The constructor and\n"
    "    @ accessors are ordinary C++ in src/more_items.cc, preceding this entry.\n"
    "    .align 2, 0\n"
    "\n"
    "    thumb_func_start Clear__9MoreItems\n"
    "Clear__9MoreItems: @ US 0x08010024\n"
    "    push {r4, r5, lr}\n"
    "    adds r3, r0, #0\n"
    "    adds r5, r3, #4\n"
    "    ldr r0, [r3]\n"
    "    adds r0, #4\n"
    "    adds r0, r3, r0\n"
    "    adds r2, r0, #0\n"
    "    adds r1, r5, #0\n"
    "    ldr r4, [r3]\n"
    "    cmp r1, r2\n"
    "    beq .L08010040\n"
    ".L0801003A:\n"
    "    adds r1, #1\n"
    "    cmp r1, r2\n"
    "    bne .L0801003A\n"
    ".L08010040:\n"
    "    subs r0, r0, r5\n"
    "    subs r0, r4, r0\n"
    "    str r0, [r3]\n"
    "    pop {r4, r5}\n"
    "    pop {r0}\n"
    "    bx r0\n"
);
