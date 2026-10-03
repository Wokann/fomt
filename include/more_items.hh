#ifndef MORE_ITEMS_HH
#define MORE_ITEMS_HH

#include "prelude.h"

struct PACKED ALIGN(2) MoreItemsState
{
    u16 unk_00 : 10;
    u16 unk_01 : 6;
    u16 unk_02 : 10;
    u16 unk_03 : 6;
    u16 unk_04 : 10;
    u16 unk_05 : 6;
};

struct MoreItems
{
    /* +00 */ u32 size;
    /* +04 */ u8 data[30];
    /* +22 */ u8 unk_22[2];
    /* +24 */ MoreItemsState unk_24;
};

typedef char MoreItemsState_size_check[sizeof(MoreItemsState) == 6 ? 1 : -1];
typedef char MoreItems_state_offset_check[offsetof(MoreItems, unk_24) == 0x24 ? 1 : -1];
typedef char MoreItems_size_check[sizeof(MoreItems) == 0x2C ? 1 : -1];

EXTERN_C

void func_0800FF8C(MoreItems * self);
u32 func_0800FFD0(MoreItems const * self);
u8 * func_0800FFD4(MoreItems * self);
u8 * func_0800FFD8(MoreItems * self);
MoreItemsState func_0800FFE0(MoreItems const * self);
void func_0800FFF4(MoreItems * self, u32 value);
void func_08010014(MoreItems * self, MoreItemsState const & value);
void func_08010024(MoreItems * self);

EXTERN_C_END

#endif // MORE_ITEMS_HH
