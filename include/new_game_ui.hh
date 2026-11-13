#ifndef NEW_GAME_UI_HH
#define NEW_GAME_UI_HH

#include "prelude.h"
#include "font_draw.hh"
#include "ui_text_commands.hh"
#include "gbaio.h"

// The font routines take width and height as the low and high halfwords.
union TextTileDimensions {
    u32 packed;
    u16 axes[2];

private:
    static void Set(u16 (&axes)[2], u16 width, u16 height)
    {
        axes[0] = width;
        axes[1] = height;
    }

public:
    TextTileDimensions(u16 width, u16 height)
    {
        Set(axes, width, height);
    }
};

// Clear2DGfxBuffer and DrawStringTo2DGfxBuffer consume the tile words after
// the untouched four-byte prefix. Each 4bpp tile occupies eight words and
// the default new-game text buffers are two tiles high. Native construction
// leaves them uninitialized; the corresponding UI setup draws their tiles.
template <u32 Width, u32 Height = 2>
struct NewGameTextTileBuffer {
    enum { TileWidth = Width, TileCount = Width * Height };

    NewGameTextTileBuffer() {}

    u32 const * TileData() const { return tiles; }

    u32 PackedDimensions() const
    {
        return TextTileDimensions(Width, Height).packed;
    }

    void Clear()
    {
        UnkUiSelectionDimensions size(Width, Height);
        Clear2DGfxBuffer(reinterpret_cast<u32 const &>(size), tiles, 0);
    }

    void ClearRect(u32 x, u32 y, u32 width, u32 height, u32 color)
    {
        UnkUiSelectionDimensions size(Width, Height);
        Clear2DGfxBufferRect(reinterpret_cast<u32 const &>(size), tiles,
            x, y, width, height, color);
    }

    void DrawString(i32 x, i32 y, char const * text)
    {
        UnkUiSelectionDimensions size(Width, Height);
        DrawStringTo2DGfxBuffer(reinterpret_cast<u32 const &>(size), tiles,
            x, y, reinterpret_cast<u8 const *>(text));
    }

    void DrawStringExt(i32 x, i32 y, char const * text, i32 background, i32 foreground)
    {
        UnkUiSelectionDimensions size(Width, Height);
        DrawStringTo2DGfxBufferExt(reinterpret_cast<u32 const &>(size), tiles,
            x, y, reinterpret_cast<u8 const *>(text), background, foreground);
    }

    void DrawCharacterExt(i32 x, i32 y, i32 character, i32 background, i32 foreground)
    {
        UnkUiSelectionDimensions size(Width, Height);
        DrawCharacterGlyphTo2DGfxBufferExt(reinterpret_cast<u32 const &>(size), tiles,
            x, y, character, background, foreground);
    }

    u32 unk_00;
    u32 tiles[TileCount * (TILE_SIZE_4BPP / sizeof(u32))];
};

#if defined(REGION_JP)
typedef NewGameTextTileBuffer<2> UiSpriteGlyphBuffer;
#else
typedef NewGameTextTileBuffer<1> UiSpriteGlyphBuffer;
#endif

// Menu OAM coordinates use their wrapped hardware representation, not the
// signed offsets stored in sprite archives. Only the first six bytes are
// copied to OAM; the destination's affine coefficient is left untouched.
struct NewGameMenuSpriteAttributes {
    u32 y : 8;
    u32 affine_mode : 2;
    u32 object_mode : 2;
    u32 mosaic : 1;
    u32 color_mode : 1;
    u32 shape : 2;
    u32 x : 9;
    u32 affine_index_low : 3;
    u32 horizontal_flip : 1;
    u32 vertical_flip : 1;
    u32 size : 2;
    u16 tile_attributes;
    u16 affine_coefficient;
};

typedef char NewGameMenuSpriteAttributesSizeCheck[sizeof(NewGameMenuSpriteAttributes) == 8 ? 1 : -1];
typedef char NewGameMenuSpriteAttributesTileCheck[offsetof(NewGameMenuSpriteAttributes, tile_attributes) == 4 ? 1 : -1];
typedef char NewGameMenuSpriteAttributesCoefficientCheck[offsetof(NewGameMenuSpriteAttributes, affine_coefficient) == 6 ? 1 : -1];

#endif // NEW_GAME_UI_HH
