#ifndef SHOP_COMMON_HH
#define SHOP_COMMON_HH

#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "scroll_state.hh"
#include "ui_state.hh"
#include "ui_vcount.hh"
#include "ui_quantity_selector.hh"
#include "resource_handle.hh"
#include "obj_tile_collection_storage.hh"
#include "obj_palette_pool.hh"

struct GameStateSaveImage;

// Native fixed-capacity lists store a count followed by placement-constructed
// elements. Only the counted range contains live objects.
template<class T, u32 Capacity>
struct ShopScreenList {
    u32 count;
    u32 storage[(sizeof(T) * Capacity + sizeof(u32) - 1) / sizeof(u32)];

    ShopScreenList() : count(0) {}
    u32 Size() const { return count; }
    T * Begin() { return reinterpret_cast<T *>(storage); }
    T * End() { return &(*this)[count]; }
    T & operator[](u32 index)
    {
        return *reinterpret_cast<T *>(reinterpret_cast<u8 *>(this)
            + (sizeof(count) + index * sizeof(T)));
    }
};

// The native list stores forty 16-byte rows, followed by forty catalog indices.
// Rows reference native 4bpp tiles and an independent palette.
struct ShopScreenRow {
    i16 y;
    u16 unk_02;
    i32 x;
    void const * tiles;
    u16 const * palette;
};

struct ShopScreenSprite {
    explicit ShopScreenSprite(IndexedResourceProvider * provider)
        : x(0), y(0), handle(provider, 0, 0x100), unk_34(0) {}
    i16 x;
    i16 y;
    IndexedResourceHandle handle;
    IndexedResourceSpriteParameters parameters;
    u8 unk_34;
};

// The cursor has a word-sized vertical position, unlike the other sprites.
struct ShopScreenCursor {
    i16 x;
    i32 y;
    IndexedResourceHandle handle;
    IndexedResourceSpriteParameters parameters;
    u8 unk_38;
    u32 unk_3C;
};

#pragma interface "shop_common.hh"
struct ShopScreenCore : HardwareContext {
    explicit ShopScreenCore(GameStateSaveImage * image);
    virtual ~ShopScreenCore();

    GameStateSaveImage * save;
    u16 scroll_y;
    u32 selected_row;
    i32 previous_selected_row;
    HardwareMusicPlayerSlot music;
    ScrollState * scroll;
    // Fixed native capacities, not counts of the current shop's ROM catalog.
    ShopScreenList<ShopScreenRow, 40> rows;
    ShopScreenList<u32, 40> catalog;
    UiStateOwner dialog;
    i32 previous_dialog_state;
    i32 dialog_state;
    ObjTileCollectionEntry tile_354;
    ObjPaletteCollectionEntry palette_35C;
    ObjTileCollectionEntry tile_364;
    ObjPaletteCollectionEntry palette_36C;
    ObjTileCollectionEntry tile_374;
    ObjTileCollectionEntry tile_37C;
    ObjPaletteCollectionEntry palette_384;
    ObjTileCollectionEntry tile_38C;
    ObjTileCollectionEntry tile_394;
    ObjPaletteCollectionEntry palette_39C;
    ObjTileCollectionEntry item_tiles[9];
    ObjPaletteCollectionEntry item_palettes[9];
    // This mask uses SetInterruptNestingMask, not InterruptGuard's API.
    u16 interrupt_mask;
    UiVCountBinding vcount;
    u32 unk_450;
    u32 gold_unit_tiles[2 * 2 * 8];
    IndexedResourceArchive arrow_archive;
    IndexedResourceArchive cursor_archive;
    IndexedResourceArchive unk_534;
    ShopScreenSprite up_arrow;
    ShopScreenSprite down_arrow;
    ShopScreenSprite sprite_5D4;
    ShopScreenSprite sprite_60C;
    ShopScreenCursor cursor;
    UiPurchaseQuantitySelector quantity_selector;
    u8 unk_6A0;
    u8 unk_6A1;
    u8 unk_6A2;
    u8 unk_6A3;
};


EXTERN_C
void DrawShopMoney(ShopScreenCore * core);
void InitializeShopScreenDisplay(ShopScreenCore * core);
void UpdateShopInputState(ShopScreenCore * core, u32 row_count);
void UpdateShopScreenDisplay(ShopScreenCore * core);
void UpdateUiVCount(ShopScreenCore * core);
EXTERN_C_END

extern u16 const gShopDigitGlyphs[10];
extern char const gText_ShopCommon_GoldUnit[];
extern char const gText_ShopCommon_QuantitySuffix[];
extern char const * const gShopCommonQuantitySuffixTextRef;
extern char const gText_ShopCommon_OwnedQuantityLabel[];
extern char const * const gShopCommonOwnedQuantityLabelTextRef;

#endif // SHOP_COMMON_HH
