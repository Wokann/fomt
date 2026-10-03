#include "hardware_allocator.hh"

EXTERN_C

void func_080073E0(void * self, u32 handle)
{
    Unk_hardware_03000404 * h = gUnk_03000404;
    HardwareHandle packed;
    packed.value = handle;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->inl_pred_0(idx))
        {
            Unk_hardware_ent_080D6D98 & ent = h->GetEntry(idx);
            bool valid = packed.fields.generation == ent.params.unk_02;
            if (valid)
            {
                if (--ent.params.unk_00 == 0)
                {
                    ent.params.unk_02 = 0;
                    h->FreeEntry(&ent);
                    h->inl_func_0(idx);
                    h->unk_48--;
                }
            }
        }
    }
}

u32 func_0800745C(void * self, u32 handle)
{
    Unk_hardware_03000404 * h = gUnk_03000404;
    HardwareHandle packed;
    packed.value = handle;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->inl_pred_0(idx))
        {
            Unk_hardware_ent_080D6D98 & ent = h->GetEntry(idx);
            bool valid = packed.fields.generation == ent.params.unk_02;
            if (valid)
            {
                u16 old_count = ent.params.unk_00;
                if (++ent.params.unk_00 != 0)
                    return handle;
                ent.params.unk_00 = old_count;
            }
        }
    }

    return 0;
}

u32 func_080074C0(void * self, u32 handle)
{
    Unk_hardware_03000404 * h = gUnk_03000404;
    HardwareHandle packed;
    packed.value = handle;
    u32 result;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->inl_pred_0(idx))
        {
            bool valid = packed.fields.generation == h->GetEntry(idx).params.unk_02;
            result = idx;
            if (valid)
                goto done;
        }
    }

    result = -1u;
done:
    return result;
}

u32 func_08007510(void * self, u32 handle)
{
    Unk_hardware_03000404 * h = gUnk_03000404;
    HardwareHandle packed;
    packed.value = handle;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->inl_pred_0(idx))
        {
            Unk_hardware_ent_080D6D98 & ent = h->GetEntry(idx);
            bool valid = packed.fields.generation == ent.params.unk_02;
            if (valid)
                return ent.params.unk_00;
        }
    }

    return 0;
}

u16 func_08007564(void)
{
    return gUnk_03000404->unk_48;
}

u32 func_08007574(void)
{
    return 0x10;
}

EXTERN_C_END
