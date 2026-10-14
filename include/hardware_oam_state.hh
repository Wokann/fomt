#ifndef HARDWARE_OAM_STATE_HH
#define HARDWARE_OAM_STATE_HH

#include "prelude.h"

// The IWRAM renderer loads each width/height pair as one little-endian
// halfword. Keep the real two-byte layout in both C and old agbcp.
struct HardwareSpriteDimensions {
    u8 width;
    u8 height;
} PACKED;

typedef char HardwareSpriteDimensionsSizeCheck[sizeof(struct HardwareSpriteDimensions) == 2 ? 1 : -1];
typedef char HardwareSpriteDimensionsHeightCheck[offsetof(struct HardwareSpriteDimensions, height) == 1 ? 1 : -1];

EXTERN_C

// Shape rows: square, horizontal, vertical. Columns are OAM size 0..3.
extern struct HardwareSpriteDimensions const gHardwareSpriteDimensions[3][4];

void func_08009834(void * object);
void func_08009864(void * object);
void func_08009878(void * object);
void func_08009898(void * object);

EXTERN_C_END

#endif // HARDWARE_OAM_STATE_HH
