#include "prelude.h"

// Only the byte used by these adapters is known.  Its owning object remains
// intentionally anonymous until a higher-confidence class boundary is found.
struct FirstFieldStatusByte
{
    u8 unused_00[0x0D];
    u8 value;
};

EC u8 func_08050DD8(void * const * object)
{
    FirstFieldStatusByte * const status = static_cast<FirstFieldStatusByte *>(*object);
    u8 const value = status->value;
    status->value = 0;
    return value;
}

EC u8 func_08050DE4(void * const * object)
{
    FirstFieldStatusByte * const status = static_cast<FirstFieldStatusByte *>(*object);
    u8 const value = status->value;
    status->value = 1;
    return value;
}
