#include "npc_runtime_data.hh"

EC char * func_0809EACC(NpcRuntimeData * const self)
{
    return self->name;
}

EC u8 func_0809EAD0(NpcRuntimeData const * const self)
{
    return self->unknown_24;
}

EC u8 func_0809EAD8(NpcRuntimeData const * const self)
{
    return self->unknown_25;
}

EC bool func_0809EAE0(NpcRuntimeData const * const self)
{
    return self->flag_26_0;
}

EC void func_0809EAEC(NpcRuntimeData * const self)
{
    self->flag_26_0 = true;
}
