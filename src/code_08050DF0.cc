#include "prelude.h"

// This partial layout is shared with the status-byte adapters.  Only the
// fields accessed by this query have been established from the ROM code.
struct FirstFieldQueryData
{
    u8 unused_00[8];
    u32 mode;
    u8 unused_0c[0x14C];
    void * result;
};

EC void * func_08050DF0(void * const * object)
{
    FirstFieldQueryData * const data = static_cast<FirstFieldQueryData *>(*object);

    if (data->mode == 6)
        return nullptr;

    return data->result;
}
