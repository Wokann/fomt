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
    u32 row_count;
    // Fixed native capacities, not counts of the current shop's ROM catalog.
    ShopScreenRow rows[40];
    u32 catalog_count;
    u32 catalog_indices[40];
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

typedef char ShopScreenRowSizeCheck[sizeof(ShopScreenRow) == 0x10 ? 1 : -1];
typedef char ShopScreenSpriteSizeCheck[sizeof(ShopScreenSprite) == 0x38 ? 1 : -1];
typedef char ShopScreenCursorSizeCheck[sizeof(ShopScreenCursor) == 0x40 ? 1 : -1];
typedef char ShopScreenCoreRowsCheck[offsetof(ShopScreenCore, rows) == 0x24 ? 1 : -1];
typedef char ShopScreenCoreCatalogCheck[offsetof(ShopScreenCore, catalog_indices) == 0x2A8 ? 1 : -1];
typedef char ShopScreenCoreDialogCheck[offsetof(ShopScreenCore, dialog) == 0x348 ? 1 : -1];
typedef char ShopScreenCoreItemTilesCheck[offsetof(ShopScreenCore, item_tiles) == 0x3A4 ? 1 : -1];
typedef char ShopScreenCoreVCountCheck[offsetof(ShopScreenCore, vcount) == 0x438 ? 1 : -1];
typedef char ShopScreenCoreGoldUnitCheck[offsetof(ShopScreenCore, gold_unit_tiles) == 0x454 ? 1 : -1];
typedef char ShopScreenCoreArchiveCheck[offsetof(ShopScreenCore, arrow_archive) == 0x4D4 ? 1 : -1];
typedef char ShopScreenCoreSpritesCheck[offsetof(ShopScreenCore, up_arrow) == 0x564 ? 1 : -1];
typedef char ShopScreenCoreCursorCheck[offsetof(ShopScreenCore, cursor) == 0x644 ? 1 : -1];
typedef char ShopScreenCoreQuantityCheck[offsetof(ShopScreenCore, quantity_selector) == 0x684 ? 1 : -1];
typedef char ShopScreenCoreSizeCheck[sizeof(ShopScreenCore) == 0x6A4 ? 1 : -1];

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
