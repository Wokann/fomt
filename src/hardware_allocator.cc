#include "hardware_allocator.hh"

EXTERN_C

u32 AllocateHardwarePoolHandle(void *)
{
    Unk_hardware_03000404 * state = gUnk_03000404;
    Unk_hardware_ent_080D6D98 * const current = state->unk_00;
    Unk_hardware_ent_080D6D98 * entry = state->AllocEntry(current);
    u32 result;
    if (entry != 0) {
        u32 index = state->IndexOf(entry);
        state->inl_func_1(index);
        ++state->unk_48;
        entry->params.unk_00 = 1;
        u32 generation = state->unk_4A + 1;
        if (generation > 0xFFFF)
            generation = 1;
        current->params.unk_02 = generation;
        state->unk_4A = generation;
        HardwareHandle handle(index, *current);
        result = handle.value;
        goto done;
    }
    result = 0;
done:
    return result;
}

void ReleaseHardwarePoolHandle(void * self, u32 handle)
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

u32 RetainHardwarePoolHandle(void * self, u32 handle)
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

u32 GetHardwarePoolHandleIndex(void * self, u32 handle)
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

u32 GetHardwarePoolHandleReferenceCount(void * self, u32 handle)
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

u16 GetHardwarePoolAllocatedCount(void)
{
    return gUnk_03000404->unk_48;
}

u32 GetHardwarePoolCapacity(void)
{
    return 0x10;
}

EXTERN_C_END
