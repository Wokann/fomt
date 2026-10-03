#ifndef HARDWARE_HH
#define HARDWARE_HH

#include "prelude.h"

// A lifetime reference to the shared hardware pool; its destructor updates
// the global owner count rather than reading fields from the receiver.
struct HardwarePoolOwner
{
    ~HardwarePoolOwner();
};

EXTERN_C
void * func_08007128(void * self);
void * func_08007174(void * self, void const * other);
void func_080071BC(void * self, unsigned int from, unsigned int count);
EXTERN_C_END

union Unk_hardware_ent_080D6D98
{
    Unk_hardware_ent_080D6D98 * next_free;

    struct
    {
        u16 unk_00;
        u16 unk_02;
    } params;
};

EC Unk_hardware_ent_080D6D98 * InitializeHardwareFreeList(
    Unk_hardware_ent_080D6D98 * entries, int count,
    Unk_hardware_ent_080D6D98 * tail);

struct Unk_hardware_03000404
{
    Unk_hardware_03000404()
    {
        unk_00 = InitializeHardwareFreeList(unk_04, 0x10, 0);
        unk_44 = 0;
        unk_48 = 0;
        unk_4C = 0;
        unk_50 = 0;
        unk_51 = 0;
        unk_44 = 0;
    }

    bool inl_pred_0(unsigned int idx) const { return idx < 0x10 && (unk_44 & (1 << (idx % 0x20u))) != 0; }

    void inl_func_0(unsigned int idx)
    {
        if (idx < 0x10)
            unk_44 &= ~(1 << (idx % 0x20u));
    }

    void inl_func_1(unsigned int idx)
    {
        if (idx < 0x10)
            unk_44 |= (1 << (idx % 0x20u));
    }

    Unk_hardware_ent_080D6D98 & GetEntry(unsigned int idx) { return unk_04[idx]; }

    unsigned int IndexOf(Unk_hardware_ent_080D6D98 const * ent) const { return ent - unk_04; }

    void FreeEntry(Unk_hardware_ent_080D6D98 * ent)
    {
        ent->next_free = unk_00;
        unk_00 = ent;
    }

    Unk_hardware_ent_080D6D98 * AllocEntry(Unk_hardware_ent_080D6D98 * ent)
    {
        Unk_hardware_ent_080D6D98 * prev = unk_00;

        if (ent != nullptr)
            unk_00 = ent->next_free;

        return prev;
    }

    /* +00 */ Unk_hardware_ent_080D6D98 * unk_00;
    /* +04 */ Unk_hardware_ent_080D6D98 unk_04[0x10];
    /* +44 */ u32 unk_44;
    /* +48 */ u16 unk_48;
    /* +4A */ u16 unk_4A;
    /* +4C */ u32 unk_4C;
    /* +50 */ u8 unk_50;
    /* +51 */ u8 unk_51;
};

extern Unk_hardware_03000404 * gUnk_03000404;

#endif // HARDWARE_HH
