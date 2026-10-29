#ifndef UI_POSITION_HH
#define UI_POSITION_HH

#include "prelude.h"

// Window coordinates retain their low 16 bits. Pixel consumers interpret
// those bits as signed coordinates; Set and Offset retain wrapping behavior.
struct UiPosition {
    u16 x;
    u16 y;
#ifdef __cplusplus
    void Set(u32 x, u32 y);
    void Offset(u32 dx, u32 dy);
#endif
};

typedef char UiPositionSizeCheck[sizeof(struct UiPosition) == 4 ? 1 : -1];
typedef char UiPositionYCheck[offsetof(struct UiPosition, y) == 2 ? 1 : -1];

#endif // UI_POSITION_HH
