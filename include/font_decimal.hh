#ifndef FONT_DECIMAL_HH
#define FONT_DECIMAL_HH

#include "prelude.h"
#include "decimal_text.hh"
#ifdef __cplusplus
#include "hardware_linked_list.hh"
#endif

EXTERN_C


// Draws decimal digits from right to left, using four consecutive tiles per
// digit. right_tile points to the upper-right tile of the final digit;
// row_stride counts u16 entries, and palette occupies the tilemap's high bits.
void DrawDecimalTo2x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride);

EXTERN_C_END

// These sibling queue commands retain the same payload layout, but have
// distinct virtual drawing methods. right_tile is the upper-right tile of
// the final digit. The base unlinks a command when its Run returns false.
typedef struct FontTilemapDecimalCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    u32 value;
    u16 * right_tile;
    u16 base_tile;
    u16 palette;
    u32 row_stride;
#ifdef __cplusplus
    FontTilemapDecimalCommand(u32 value, u16 * right_tile, u16 base_tile,
        u16 palette, u32 row_stride);
    virtual ~FontTilemapDecimalCommand();
    virtual bool Run();
#endif
} FontTilemapDecimalCommand;

typedef char FontTilemapDecimalCommandSizeCheck[sizeof(FontTilemapDecimalCommand) == 0x1C ? 1 : -1];
typedef char FontTilemapDecimalCommandValueCheck[offsetof(FontTilemapDecimalCommand, value) == 0x0C ? 1 : -1];
typedef char FontTilemapDecimalCommandDestinationCheck[offsetof(FontTilemapDecimalCommand, right_tile) == 0x10 ? 1 : -1];
typedef char FontTilemapDecimalCommandBaseTileCheck[offsetof(FontTilemapDecimalCommand, base_tile) == 0x14 ? 1 : -1];
typedef char FontTilemapDecimalCommandPaletteCheck[offsetof(FontTilemapDecimalCommand, palette) == 0x16 ? 1 : -1];
typedef char FontTilemapDecimalCommandRowStrideCheck[offsetof(FontTilemapDecimalCommand, row_stride) == 0x18 ? 1 : -1];

// Overseas ROMs insert the one-column, two-row variant. JP has no such class.
#if !defined(REGION_JP)
typedef struct FontTilemapTallDecimalCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    u32 value;
    u16 * right_tile;
    u16 base_tile;
    u16 palette;
    u32 row_stride;
#ifdef __cplusplus
    FontTilemapTallDecimalCommand(u32 value, u16 * right_tile, u16 base_tile,
        u16 palette, u32 row_stride);
    virtual ~FontTilemapTallDecimalCommand();
    virtual bool Run();
#endif
} FontTilemapTallDecimalCommand;

typedef char FontTilemapTallDecimalCommandSizeCheck[sizeof(FontTilemapTallDecimalCommand) == 0x1C ? 1 : -1];
typedef char FontTilemapTallDecimalCommandValueCheck[offsetof(FontTilemapTallDecimalCommand, value) == 0x0C ? 1 : -1];
typedef char FontTilemapTallDecimalCommandDestinationCheck[offsetof(FontTilemapTallDecimalCommand, right_tile) == 0x10 ? 1 : -1];
typedef char FontTilemapTallDecimalCommandBaseTileCheck[offsetof(FontTilemapTallDecimalCommand, base_tile) == 0x14 ? 1 : -1];
typedef char FontTilemapTallDecimalCommandPaletteCheck[offsetof(FontTilemapTallDecimalCommand, palette) == 0x16 ? 1 : -1];
typedef char FontTilemapTallDecimalCommandStrideCheck[offsetof(FontTilemapTallDecimalCommand, row_stride) == 0x18 ? 1 : -1];
#endif

// Single-tile digits retain row_stride in the ABI but write only one row.
typedef struct FontTilemapSingleTileDecimalCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    u32 value;
    u16 * right_tile;
    u16 base_tile;
    u16 palette;
    u32 row_stride;
#ifdef __cplusplus
    FontTilemapSingleTileDecimalCommand(u32 value, u16 * right_tile, u16 base_tile,
        u16 palette, u32 row_stride);
    virtual ~FontTilemapSingleTileDecimalCommand();
    virtual bool Run();
#endif
} FontTilemapSingleTileDecimalCommand;

typedef char FontTilemapSingleTileDecimalCommandSizeCheck[sizeof(FontTilemapSingleTileDecimalCommand) == 0x1C ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandValueCheck[offsetof(FontTilemapSingleTileDecimalCommand, value) == 0x0C ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandDestinationCheck[offsetof(FontTilemapSingleTileDecimalCommand, right_tile) == 0x10 ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandBaseTileCheck[offsetof(FontTilemapSingleTileDecimalCommand, base_tile) == 0x14 ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandPaletteCheck[offsetof(FontTilemapSingleTileDecimalCommand, palette) == 0x16 ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandStrideCheck[offsetof(FontTilemapSingleTileDecimalCommand, row_stride) == 0x18 ? 1 : -1];

EXTERN_C

#if !defined(REGION_JP)
void DrawDecimalTo1x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride);
#endif
void DrawDecimalToTilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride);

EXTERN_C_END

#endif // FONT_DECIMAL_HH
