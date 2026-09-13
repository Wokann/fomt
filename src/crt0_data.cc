#include "crt0_data.hh"

EXTERN_C

u32 const init_array[4] = {
    0,
    0,
    0,
    0,
};

#include FOMT_TEXT_INCLUDE(crt0_data.cc)

EXTERN_C_END
