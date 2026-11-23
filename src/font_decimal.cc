#include "font_decimal.hh"
#include "font_draw.hh"
#include "decimal_format.h"
#include "ui_state.hh"


void DrawDecimalTo2x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride)
{
    u32 first_tile = static_cast<u16>(base_tile);
    u16 palette_index = palette;
    u16 * cursor = right_tile;
    u32 attributes = palette_index << 12;
    do {
        u32 quotient = value / 10;
        u32 tile = first_tile + (value - quotient * 10) * 4;
        cursor[0] = (tile + 1) | attributes;
        cursor[-1] = attributes | tile;
        cursor[row_stride] = (tile + 3) | attributes;
        cursor[row_stride - 1] = (tile + 2) | attributes;
        value = quotient;
        cursor -= 2;
    } while (value != 0);
}

FontTilemapDecimalCommand::FontTilemapDecimalCommand(u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride)
{
    this->value = value;
    this->right_tile = right_tile;
    this->base_tile = base_tile;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapDecimalCommand::~FontTilemapDecimalCommand()
{
}

#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
void DrawDecimalTo1x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride)
{
    u32 first_tile = static_cast<u16>(base_tile);
    u16 palette_index = palette;
    u16 * cursor = right_tile;
    u32 attributes = palette_index << 12;
    do {
        u32 quotient = value / 10;
        u32 tile = first_tile + (value - quotient * 10) * 2;
        cursor[0] = attributes | tile;
        cursor[row_stride] = (tile + 1) | attributes;
        value = quotient;
        cursor--;
    } while (value != 0);
}

FontTilemapTallDecimalCommand::FontTilemapTallDecimalCommand(u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride)
{
    this->value = value;
    this->right_tile = right_tile;
    this->base_tile = base_tile;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapTallDecimalCommand::~FontTilemapTallDecimalCommand()
{
}
#endif

void DrawDecimalToTilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride)
{
    u32 first_tile = static_cast<u16>(base_tile);
    u16 palette_index = palette;
    u16 * cursor = right_tile;
    u32 attributes = palette_index << 12;
    do {
        u32 quotient = value / 10;
        u32 tile = first_tile + (value - quotient * 10);
        cursor[0] = tile | attributes;
        value = quotient;
        cursor--;
    } while (value != 0);
}

FontTilemapSingleTileDecimalCommand::FontTilemapSingleTileDecimalCommand(u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride)
{
    this->value = value;
    this->right_tile = right_tile;
    this->base_tile = base_tile;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapSingleTileDecimalCommand::~FontTilemapSingleTileDecimalCommand()
{
}

bool FontTilemapSingleTileDecimalCommand::Run()
{
    DrawDecimalToTilemap(value, right_tile, base_tile, palette, row_stride);
    return false;
}

#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
bool FontTilemapTallDecimalCommand::Run()
{
    DrawDecimalTo1x2Tilemap(value, right_tile, base_tile, palette, row_stride);
    return false;
}
#endif

bool FontTilemapDecimalCommand::Run()
{
    DrawDecimalTo2x2Tilemap(value, right_tile, base_tile, palette, row_stride);
    return false;
}

bool FontTilemapRectCommand::Run()
{
    Fill2DGfxTilemapRect(destination, first_tile, width, height, palette, row_stride);
    return false;
}
