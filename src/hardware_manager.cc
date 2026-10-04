#include "hardware_manager.hh"
#include "hardware_interrupt_guard.hh"
#include "hardware_song.hh"
#include "hardware_linked_list.hh"

EXTERN_C
extern void * vtable_unk_080E5B0C[];
extern void * vtable_unk_080E5B18[];
extern void * vtable_unk_080E5B70[];
extern void * vtable_unk_080E5B90[];
extern void * vtable_unk_080E5B60[];
extern void * func_080D78F8(void * object, void * value);
extern void func_080D7944(void * object, u32 flags);
extern void * __builtin_new(u32 size);
extern void __builtin_delete(void * object);
EXTERN_C_END

struct HardwareManagerOwner * func_08008980(struct HardwareManagerOwner * owner)
{
    u8 * state = (u8 *)__builtin_new(0x6C);
    u32 zero = 0;
    *(u32 *)(state + 0x00) = zero;
    *(u32 *)(state + 0x04) = zero;
    *(void **)(state + 0x08) = vtable_unk_080E5B70;

    u8 * first = state + 0x0C;
    *(u32 *)(first + 0x00) = zero;
    *(u32 *)(first + 0x04) = zero;
    *(void **)(first + 0x08) = (void *)vtable_unk_080E5BB4;
    u8 * first_sentinel = state + 0x1C;
    *(void **)(first + 0x0C) = first_sentinel;
    *(u32 *)(first_sentinel + 0x00) = zero;
    *(u32 *)(first_sentinel + 0x04) = zero;
    *(void **)(first_sentinel + 0x08) = (void *)vtable_unk_080E5BD8;
    *(void **)(first + 0x10) = first + 0x0C;
    *(void **)(first + 0x14) = first_sentinel;
    *(void **)(first + 0x08) = vtable_unk_080E5B90;

    u8 * link = state + 0x28;
    *(u32 *)(link + 0x00) = zero;
    *(u32 *)(link + 0x04) = zero;
    *(void **)(link + 0x08) = vtable_unk_080E5B60;

    u8 * second = state + 0x34;
    *(u32 *)(second + 0x00) = zero;
    *(u32 *)(second + 0x04) = zero;
    *(void **)(second + 0x08) = (void *)vtable_unk_080E5BB4;
    u8 * second_sentinel = state + 0x44;
    *(void **)(second + 0x0C) = second_sentinel;
    *(u32 *)(second_sentinel + 0x00) = zero;
    *(u32 *)(second_sentinel + 0x04) = zero;
    *(void **)(second_sentinel + 0x08) = (void *)vtable_unk_080E5BD8;
    *(void **)(second + 0x10) = second + 0x0C;
    *(void **)(second + 0x14) = second_sentinel;
    *(void **)(second + 0x08) = vtable_unk_080E5B90;

    u8 * resource = state + 0x50;
    void * second_pointer = second;
    func_080D78F8(resource, &second_pointer);
    *(void **)(second + 0x30) = vtable_unk_080E5B0C;
    *(void **)(second + 0x08) = vtable_unk_080E5B18;

    u8 * enabled = state + 0x68;
    *enabled = (u8)(func_08008D9C() ^ 1);
    if (*enabled != 0)
        func_08008D84();

    func_080095C0((struct HardwareBlendObject *)second, (u32)state);
    func_080095C0((struct HardwareBlendObject *)second, (u32)first);
    func_080095C0((struct HardwareBlendObject *)second, (u32)link);
    owner->state = (struct HardwareManagerState *)state;
    return owner;
}

void func_08008A68(struct HardwareManagerOwner * owner, u32 flags)
{
    u8 * state = (u8 *)owner->state;
    if (state != 0) {
        if (state[0x68] != 0)
            func_08008D90();

        u8 * secondary = state + 0x34;
        *(void **)(secondary + 0x30) = vtable_unk_080E5B0C;
        *(void **)(secondary + 8) = vtable_unk_080E5B18;
        func_080D7944(state + 0x50, 0);
        func_0800959C((struct HardwareBlendObject *)secondary, 2);
        func_080098AC(state + 0x28, 2);
        func_0800959C((struct HardwareBlendObject *)(state + 0x0C), 2);
        func_080098AC(state, 2);
        __builtin_delete(state);
    }
    if (flags & 1)
        __builtin_delete(owner);
}
