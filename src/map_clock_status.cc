#include <new>
#include "prelude.h"
#include "gbaio.h"
#include "ui_text_window.hh"
#include "map_clock_status.hh"

#include "fomt_constants.hh"

#include <string.h>

static inline u8 const * GetMapClockStatusGlyph(u32 index)
{
    return gMapClockStatusGlyphTiles[index];
}

inline MapClockStatusHudData::MapClockStatusHudData()
    : unk_archive_000(gUnk_0875B444),
#if defined(REGION_JP)
      unk_archive_030(gUnk_083ED9FC),
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
      unk_archive_030(gUnk_086678A0),
#endif
      palette_dirty(1), unk_selector(0), unk_state_2D0(2),
      unk_selector_dirty(1), unk_value_active(0), unk_state_314(2),
      unk_value_dirty(1), unk_state_338(2), unk_358(1)
{
#if defined(REGION_DE)
    u8 const * middle_glyph = GetMapClockStatusGlyph(29);
    u32 (&first_label_tile)[8] = date_tiles.tiles[4];
    date_tiles.SetTile(5, middle_glyph);
    date_tiles.SetTile(first_label_tile, GetMapClockStatusGlyph(28));
    date_tiles.SetTile(6, GetMapClockStatusGlyph(30));
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    date_tiles.SetTile(5, GetMapClockStatusGlyph(29));
#endif
#if defined(REGION_JP)
    time_tiles.SetTile(0, GetMapClockStatusGlyph(21));
    time_tiles.SetTile(1, GetMapClockStatusGlyph(19));
    // Slot 2 belongs to the weekday setter; this fixed glyph occupies slot 3.
    time_tiles.SetTile(3, GetMapClockStatusGlyph(20));
#endif
    u8 blank[TILE_SIZE_4BPP];
    memset(blank, 0, sizeof(blank));
    time_tiles.SetTile(7, blank);
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    time_tiles.SetTile(3, blank);
#endif
}

MapClockStatusHudWidget::MapClockStatusHudWidget(u32 background, u32 screen,
    u32 palette, u32 mode)
    : ControlWidget(128, 136, 112, 24, background, screen, palette, mode), content()
{
}

MapClockStatusHudWidget::~MapClockStatusHudWidget()
{
}

MapClockStatusHudContent::MapClockStatusHudContent()
    : state(new MapClockStatusHudData)
{
}

MapClockStatusHudContent::~MapClockStatusHudContent()
{
    delete state;
}

static inline bool HudHasHandle(ObjPaletteCollectionEntry const & entry)
{
    return entry.handle != 0;
}

static inline bool HudHasHandle(ObjTileCollectionEntry const & entry)
{
    return entry.handle != 0;
}

static inline void QueueHudCopy(HardwareDmaCopyLink & link,
    void const * source, void * destination, u32 bytes, HardwareLinkedList * queue)
{
    link.source = source;
    link.destination = destination;
    link.byte_count = bytes;
    queue->Append(&link);
}

static inline void SubmitHudSprite(HardwareSpriteBufferState * buffer,
    HardwareSpriteOamRecord const & sprite)
{
    u32 const & position_and_mode = reinterpret_cast<u32 const &>(sprite);
    u32 count = buffer->sprite_count;
    if (count < ARRAY_COUNT(buffer->sprites)) {
        HardwareSpriteOamRecord & destination = buffer->sprites[count];
        reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
        reinterpret_cast<u16 *>(&destination)[2] = reinterpret_cast<u16 const *>(&sprite)[2];
        buffer->sprite_count = count + 1;
    }
}

static inline u32 HudPaletteBank(ObjPaletteCollectionEntry & entry)
{
    return GetObjPaletteBank(&entry, entry.handle);
}

static inline void DrawHudTileBuffer(MapClockStatusHudTileBuffer & tiles,
    i32 x, i32 y, u32 palette, HardwareSpriteBufferState * buffer, HardwareLinkedList * queue)
{
    if (HudHasHandle(tiles.state)) {
        u32 tile = tiles.state.GetTileIndex();
        if (tiles.dirty && !tiles.upload.IsQueued()) {
            QueueHudCopy(tiles.upload, tiles.tiles,
                reinterpret_cast<void *>(OBJ_VRAM0 + tile * TILE_SIZE_4BPP), 256, queue);
            tiles.dirty = 0;
        }
        HardwareSpriteOamRecord sprite = {};
        sprite.mosaic = 1;
        sprite.shape = 1;
        sprite.size = 2;
        sprite.y = y;
        sprite.x = x;
        sprite.tile_index = tile;
        sprite.palette_bank = static_cast<u16>(palette);
        SubmitHudSprite(buffer, sprite);
    }
}

void DrawMapClockStatusHud(MapClockStatusHudContent const * hud, i32 x, i32 y,
    HardwareSpriteBufferState * buffer, HardwareLinkedList * queue)
{
    MapClockStatusHudData * state = hud->state;
    if (!HudHasHandle(state->palette)) return;
    u32 palette = HudPaletteBank(state->palette);
    if (state->palette_dirty && !state->palette_upload.IsQueued()) {
        QueueHudCopy(state->palette_upload,
            state->unk_archive_000.GetGroupData(0).palettes.data,
            reinterpret_cast<void *>(OBJ_PLTT + palette * PLTT_SIZE_4BPP), PLTT_SIZE_4BPP, queue);
        state->palette_dirty = 0;
    }
    i32 draw_x = x + 4;
    i32 draw_y = y + 4;
    DrawHudTileBuffer(state->date_tiles, draw_x, draw_y, palette, buffer, queue);
    DrawHudTileBuffer(state->time_tiles, draw_x + 32, draw_y, palette, buffer, queue);
    HardwareSpriteOamRecord base = {};
    base.mosaic = 1;
    base.size = 1;
    if (HudHasHandle(state->unk_state_2D0)) {
        u32 tile = state->unk_state_2D0.GetTileIndex();
        if (state->unk_selector_dirty && !state->unk_dma_2D8.IsQueued()) {
            IndexedResourceGroupResult group = ResolveIndexedResourceGroup(&state->unk_archive_000, state->unk_selector);
            QueueHudCopy(state->unk_dma_2D8, group.tiles.data,
                reinterpret_cast<void *>(OBJ_VRAM0 + tile * TILE_SIZE_4BPP), 128, queue);
            state->unk_selector_dirty = 0;
        }
        HardwareSpriteOamRecord sprite = base;
        sprite.y = draw_y;
        sprite.x = draw_x + 64;
        sprite.tile_index = tile;
        sprite.palette_bank = static_cast<u16>(palette);
        SubmitHudSprite(buffer, sprite);
    }
    if (!HudHasHandle(state->unk_state_314) || !HudHasHandle(state->unk_pool_2F4)) return;
    HardwareSpriteOamRecord sprite = base;
    sprite.y = draw_y;
    sprite.x = draw_x + 88;
    if (state->unk_value_active) {
        u32 tile = state->unk_state_314.GetTileIndex();
        u32 value_palette = HudPaletteBank(state->unk_pool_2F4);
        if (state->unk_value_dirty) {
            IndexedResourceGroupResult group = ResolveIndexedResourceGroup(&state->unk_archive_030, state->unk_value);
            if (!state->unk_dma_31C.IsQueued()) {
                QueueHudCopy(state->unk_dma_31C, group.tiles.data,
                    reinterpret_cast<void *>(OBJ_VRAM0 + tile * TILE_SIZE_4BPP), 128, queue);
            }
            if (!state->unk_dma_2FC.IsQueued()) {
                QueueHudCopy(state->unk_dma_2FC, group.palettes.data,
                    reinterpret_cast<void *>(OBJ_PLTT + value_palette * PLTT_SIZE_4BPP), PLTT_SIZE_4BPP, queue);
            }
            state->unk_value_dirty = 0;
        }
        sprite.tile_index = tile;
        sprite.palette_bank = static_cast<u16>(value_palette);
        SubmitHudSprite(buffer, sprite);
    }
    if (HudHasHandle(state->unk_state_338)) {
        u32 tile = state->unk_state_338.GetTileIndex();
        if (state->unk_358 && !state->unk_dma_340.IsQueued()) {
            IndexedResourceGroupResult group = ResolveIndexedResourceGroup(&state->unk_archive_000, 5);
            QueueHudCopy(state->unk_dma_340, group.tiles.data,
                reinterpret_cast<void *>(OBJ_VRAM0 + tile * TILE_SIZE_4BPP), 128, queue);
            state->unk_358 = 0;
        }
        HardwareSpriteOamRecord & record = sprite;
        record.tile_index = tile;
        record.palette_bank = palette;
        SubmitHudSprite(buffer, sprite);
    }
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"asm/gba.inc\"\n"
#if defined(REGION_JP)
    "    .align 2, 0\n"
    "    .global UpdateMapClockStatusHudCalendar\n"
    "    .thumb_func\n"
    "UpdateMapClockStatusHudCalendar:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #40\t@ 0x28\n"
    "    str\tr1, [sp, #32]\n"
    "    lsls\tr2, r2, #24\n"
    "    lsrs\tr2, r2, #24\n"
    "    str\tr2, [sp, #36]\t@ 0x24\n"
    "    ldr\tr7, [r0, #0]\n"
    "    ldrb\tr0, [r1, #1]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    beq .Ljp_0803CB42\n"
    "    cmp\tr0, #1\n"
    "    ble .Ljp_0803CB3C\n"
    "    cmp\tr0, #2\n"
    "    beq .Ljp_0803CB48\n"
    "    cmp\tr0, #3\n"
    "    beq .Ljp_0803CB4E\n"
    ".Ljp_0803CB3C:\n"
    "    movs\tr5, #11\n"
    "    movs\tr6, #12\n"
    "    b .Ljp_0803CB52\n"
    ".Ljp_0803CB42:\n"
    "    movs\tr5, #13\n"
    "    movs\tr6, #14\n"
    "    b .Ljp_0803CB52\n"
    ".Ljp_0803CB48:\n"
    "    movs\tr5, #15\n"
    "    movs\tr6, #16\n"
    "    b .Ljp_0803CB52\n"
    ".Ljp_0803CB4E:\n"
    "    movs\tr5, #17\n"
    "    movs\tr6, #18\n"
    ".Ljp_0803CB52:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #132\t@ 0x84\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r2, .Ljp_0803CBF0\n"
    "    mov\tr9, r2\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #198\t@ 0xc6\n"
    "    lsls\tr0, r0, #1\n"
    "    adds\tr4, r7, r0\n"
    "    movs\tr1, #1\n"
    "    mov\tr8, r1\n"
    "    mov\tr2, r8\n"
    "    strb\tr2, [r4, #0]\n"
    "    lsls\tr1, r6, #5\n"
    "    add\tr1, r9\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #164\t@ 0xa4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr0, [r4, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldrb\tr3, [r1, #1]\n"
    "    lsls\tr0, r3, #25\n"
    "    lsrs\tr0, r0, #27\n"
    "    adds\tr0, #1\n"
    "    adds\tr6, r0, #0\n"
    "    ldrb\tr2, [r1, #0]\n"
    "    lsls\tr2, r2, #29\n"
    "    lsrs\tr2, r2, #29\n"
    "    lsls\tr3, r3, #30\n"
    "    lsrs\tr3, r3, #30\n"
    "    adds\tr2, #6\n"
    "    lsls\tr1, r3, #4\n"
    "    subs\tr1, r1, r3\n"
    "    lsls\tr1, r1, #1\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #3\n"
    "    adds\tr1, r1, r0\n"
    "    adds\tr1, r1, r6\n"
    "    subs\tr1, #1\n"
    "    cmp\tr1, #6\n"
    "    bls .Ljp_0803CBBC\n"
    "    adds\tr0, r1, #0\n"
    "    movs\tr1, #7\n"
    "    bl __umodsi3\n"
    "    adds\tr1, r0, #0\n"
    ".Ljp_0803CBBC:\n"
    "    movs\tr0, #7\n"
    "    ands\tr1, r0\n"
    "    mov\tsl, r1\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr6, r0, #0\n"
    "    cmp\tr5, #0\n"
    "    ble .Ljp_0803CBF4\n"
    "    lsls\tr1, r5, #5\n"
    "    add\tr1, r9\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    strb\tr2, [r4, #0]\n"
    "    b .Ljp_0803CC0E\n"
    "    .align 2, 0\n"
    ".Ljp_0803CBF0: .word gMapClockStatusGlyphTiles\n"
    ".Ljp_0803CBF4:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr0, [r4, #0]\n"
    ".Ljp_0803CC0E:\n"
    "    lsls\tr1, r6, #5\n"
    "    ldr r2, .Ljp_0803CCA4\n"
    "    mov\tr9, r2\n"
    "    add\tr1, r9\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #228\t@ 0xe4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr8, r0\n"
    "    mov\tr1, r8\n"
    "    strb\tr1, [r4, #0]\n"
    "    mov\tr1, sl\n"
    "    adds\tr1, #21\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #244\t@ 0xf4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #172\t@ 0xac\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr1, r7, r0\n"
    "    mov\tr2, r8\n"
    "    strb\tr2, [r1, #0]\n"
    "    ldr\tr2, [sp, #32]\n"
    "    ldr\tr0, [r2, #0]\n"
    "    lsls\tr0, r0, #11\n"
    "    lsrs\tr0, r0, #27\n"
    "    adds\tr5, r0, #0\n"
    "    movs\tr0, #30\n"
    "    mov\tsl, r1\n"
    "    cmp\tr5, #11\n"
    "    bhi .Ljp_0803CC5A\n"
    "    movs\tr0, #28\n"
    ".Ljp_0803CC5A:\n"
    "    lsls\tr1, r0, #5\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #130\t@ 0x82\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr0, [r4, #0]\n"
    "    cmp\tr5, #11\n"
    "    bls .Ljp_0803CC74\n"
    "    subs\tr5, #12\n"
    ".Ljp_0803CC74:\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr6, r0, #0\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr5, r0, #0\n"
    "    cmp\tr6, #0\n"
    "    ble .Ljp_0803CCA8\n"
    "    lsls\tr1, r6, #5\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr0, [r4, #0]\n"
    "    b .Ljp_0803CCC4\n"
    "    .align 2, 0\n"
    ".Ljp_0803CCA4: .word gMapClockStatusGlyphTiles\n"
    ".Ljp_0803CCA8:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    movs\tr1, #162\t@ 0xa2\n"
    "    lsls\tr1, r1, #1\n"
    "    adds\tr0, r7, r1\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    strb\tr2, [r4, #0]\n"
    ".Ljp_0803CCC4:\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r0, .Ljp_0803CD60\n"
    "    mov\tr9, r0\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #178\t@ 0xb2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr8, r0\n"
    "    mov\tr1, r8\n"
    "    strb\tr1, [r4, #0]\n"
    "    ldr\tr2, [sp, #32]\n"
    "    ldr\tr0, [r2, #0]\n"
    "    lsls\tr0, r0, #5\n"
    "    lsrs\tr0, r0, #26\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    lsls\tr4, r0, #2\n"
    "    adds\tr4, r4, r0\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr4, r0, #0\n"
    "    lsls\tr5, r5, #5\n"
    "    add\tr5, r9\n"
    "    movs\tr0, #138\t@ 0x8a\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr6, r7, r0\n"
    "    movs\tr1, #146\t@ 0x92\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    adds\tr1, r5, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    mov\tr2, sl\n"
    "    strb\tr0, [r2, #0]\n"
    "    lsls\tr4, r4, #5\n"
    "    add\tr4, r9\n"
    "    movs\tr1, #154\t@ 0x9a\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    mov\tr2, sl\n"
    "    strb\tr0, [r2, #0]\n"
    "    ldr\tr1, [sp, #36]\t@ 0x24\n"
    "    cmp\tr1, #0\n"
    "    beq .Ljp_0803CD64\n"
    "    movs\tr1, #160\t@ 0xa0\n"
    "    lsls\tr1, r1, #1\n"
    "    add\tr1, r9\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    mov\tr2, sl\n"
    "    strb\tr0, [r2, #0]\n"
    "    b .Ljp_0803CD7E\n"
    "    .align 2, 0\n"
    ".Ljp_0803CD60: .word gMapClockStatusGlyphTiles\n"
    ".Ljp_0803CD64:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    adds\tr0, r6, #0\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    mov\tr1, sl\n"
    "    strb\tr2, [r1, #0]\n"
    ".Ljp_0803CD7E:\n"
    "    add\tsp, #40\t@ 0x28\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .align 2, 0\n"
    "\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#if defined(REGION_EU)
    "    .align 2, 0\n"
    "    .global UpdateMapClockStatusHudCalendar\n"
    "    .thumb_func\n"
    "UpdateMapClockStatusHudCalendar:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #48\t@ 0x30\n"
    "    str\tr1, [sp, #32]\n"
    "    lsls\tr2, r2, #24\n"
    "    lsrs\tr2, r2, #24\n"
    "    str\tr2, [sp, #36]\t@ 0x24\n"
    "    ldr\tr7, [r0, #0]\n"
    "    ldrb\tr0, [r1, #1]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    beq .Leu_0803CD92\n"
    "    cmp\tr0, #1\n"
    "    ble .Leu_0803CD8C\n"
    "    cmp\tr0, #2\n"
    "    beq .Leu_0803CD98\n"
    "    cmp\tr0, #3\n"
    "    beq .Leu_0803CD9E\n"
    ".Leu_0803CD8C:\n"
    "    movs\tr5, #11\n"
    "    movs\tr6, #12\n"
    "    b .Leu_0803CDA2\n"
    ".Leu_0803CD92:\n"
    "    movs\tr5, #13\n"
    "    movs\tr6, #14\n"
    "    b .Leu_0803CDA2\n"
    ".Leu_0803CD98:\n"
    "    movs\tr5, #15\n"
    "    movs\tr6, #16\n"
    "    b .Leu_0803CDA2\n"
    ".Leu_0803CD9E:\n"
    "    movs\tr5, #17\n"
    "    movs\tr6, #18\n"
    ".Leu_0803CDA2:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #132\t@ 0x84\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r2, .Leu_0803CE44\n"
    "    mov\tsl, r2\n"
    "    add\tr1, sl\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #198\t@ 0xc6\n"
    "    lsls\tr0, r0, #1\n"
    "    adds\tr4, r7, r0\n"
    "    movs\tr1, #1\n"
    "    mov\tr8, r1\n"
    "    mov\tr2, r8\n"
    "    strb\tr2, [r4, #0]\n"
    "    lsls\tr1, r6, #5\n"
    "    add\tr1, sl\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #164\t@ 0xa4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr0, [r4, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldrb\tr3, [r1, #1]\n"
    "    lsls\tr0, r3, #25\n"
    "    lsrs\tr0, r0, #27\n"
    "    adds\tr0, #1\n"
    "    adds\tr5, r0, #0\n"
    "    ldrb\tr2, [r1, #0]\n"
    "    lsls\tr2, r2, #29\n"
    "    lsrs\tr2, r2, #29\n"
    "    lsls\tr3, r3, #30\n"
    "    lsrs\tr3, r3, #30\n"
    "    adds\tr2, #6\n"
    "    lsls\tr1, r3, #4\n"
    "    subs\tr1, r1, r3\n"
    "    lsls\tr1, r1, #1\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #3\n"
    "    adds\tr1, r1, r0\n"
    "    adds\tr1, r1, r5\n"
    "    subs\tr1, #1\n"
    "    mov\tr9, r4\n"
    "    cmp\tr1, #6\n"
    "    bls .Leu_0803CE0E\n"
    "    adds\tr0, r1, #0\n"
    "    movs\tr1, #7\n"
    "    bl __umodsi3\n"
    "    adds\tr1, r0, #0\n"
    ".Leu_0803CE0E:\n"
    "    movs\tr0, #7\n"
    "    adds\tr6, r0, #0\n"
    "    ands\tr6, r1\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr4, r0, #0\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr5, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    ble .Leu_0803CE48\n"
    "    lsls\tr1, r4, #5\n"
    "    add\tr1, sl\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    mov\tr2, r9\n"
    "    strb\tr0, [r2, #0]\n"
    "    b .Leu_0803CE64\n"
    "    .align 2, 0\n"
    ".Leu_0803CE44: .word gMapClockStatusGlyphTiles\n"
    ".Leu_0803CE48:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    mov\tr1, r9\n"
    "    strb\tr2, [r1, #0]\n"
    ".Leu_0803CE64:\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r0, .Leu_0803CE88\n"
    "    adds\tr1, r1, r0\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #228\t@ 0xe4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr1, r9\n"
    "    strb\tr0, [r1, #0]\n"
    "    cmp\tr6, #6\n"
    "    bhi .Leu_0803CEAC\n"
    "    lsls\tr0, r6, #2\n"
    "    ldr r1, .Leu_0803CE8C\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    mov\tpc, r0\n"
    ".Leu_0803CE88: .word gMapClockStatusGlyphTiles\n"
    ".Leu_0803CE8C: .word .Leu_0803CE90\n"
    ".Leu_0803CE90: .word .Leu_0803CEAC\n"
    "    .word .Leu_0803CEB8\n"
    "    .word .Leu_0803CEC4\n"
    "    .word .Leu_0803CED0\n"
    "    .word .Leu_0803CEDC\n"
    "    .word .Leu_0803CEE8\n"
    "    .word .Leu_0803CEF4\n"
    ".Leu_0803CEAC:\n"
    "    movs\tr0, #96\t@ 0x60\n"
    "    str\tr0, [sp, #0]\n"
    "    movs\tr0, #97\t@ 0x61\n"
    "    str\tr0, [sp, #4]\n"
    "    movs\tr0, #98\t@ 0x62\n"
    "    b .Leu_0803CEFE\n"
    ".Leu_0803CEB8:\n"
    "    movs r0, #0x63\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x64\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x65\n"
    "    b .Leu_0803CEFE\n"
    ".Leu_0803CEC4:\n"
    "    movs r0, #0x66\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x67\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x68\n"
    "    b .Leu_0803CEFE\n"
    ".Leu_0803CED0:\n"
    "    movs r0, #0x69\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x6a\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x6b\n"
    "    b .Leu_0803CEFE\n"
    ".Leu_0803CEDC:\n"
    "    movs r0, #0x6c\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x6d\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x6e\n"
    "    b .Leu_0803CEFE\n"
    ".Leu_0803CEE8:\n"
    "    movs r0, #0x6f\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x70\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x71\n"
    "    b .Leu_0803CEFE\n"
    ".Leu_0803CEF4:\n"
    "    movs r0, #0x72\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x73\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x74\n"
    ".Leu_0803CEFE:\n"
    "    str\tr0, [sp, #8]\n"
    "    movs\tr2, #212\t@ 0xd4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    ldr\tr1, [sp, #0]\n"
    "    lsls\tr1, r1, #5\n"
    "    ldr r2, .Leu_0803CFA4\n"
    "    mov\tr8, r2\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #172\t@ 0xac\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr4, r7, r0\n"
    "    movs\tr6, #1\n"
    "    strb\tr6, [r4, #0]\n"
    "    ldr\tr1, [sp, #4]\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #228\t@ 0xe4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    strb\tr6, [r4, #0]\n"
    "    ldr\tr1, [sp, #8]\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #244\t@ 0xf4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    strb\tr6, [r4, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldr\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #11\n"
    "    lsrs\tr0, r0, #27\n"
    "    adds\tr5, r0, #0\n"
    "    movs\tr1, #30\n"
    "    str\tr4, [sp, #44]\t@ 0x2c\n"
    "    cmp\tr5, #11\n"
    "    bhi .Leu_0803CF5C\n"
    "    movs\tr1, #28\n"
    ".Leu_0803CF5C:\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #130\t@ 0x82\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r9\n"
    "    strb\tr6, [r0, #0]\n"
    "    movs\tr4, #12\n"
    "    cmp\tr5, #12\n"
    "    beq .Leu_0803CF7E\n"
    "    adds\tr4, r5, #0\n"
    "    cmp\tr4, #11\n"
    "    bls .Leu_0803CF7E\n"
    "    subs\tr4, #12\n"
    ".Leu_0803CF7E:\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr5, #0\n"
    "    ble .Leu_0803CFA8\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r0, .Leu_0803CFA4\n"
    "    adds\tr1, r1, r0\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    b .Leu_0803CFBA\n"
    ".Leu_0803CFA4: .word gMapClockStatusGlyphTiles\n"
    ".Leu_0803CFA8:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    mov\tr1, sp\n"
    ".Leu_0803CFBA:\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr1, r9\n"
    "    strb\tr0, [r1, #0]\n"
    "    lsls\tr1, r4, #5\n"
    "    ldr r2, .Leu_0803D064\n"
    "    mov\tsl, r2\n"
    "    add\tr1, sl\n"
    "    movs\tr2, #178\t@ 0xb2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr8, r0\n"
    "    mov\tr2, r8\n"
    "    mov\tr1, r9\n"
    "    strb\tr2, [r1, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldr\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #5\n"
    "    lsrs\tr0, r0, #26\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    lsls\tr4, r0, #2\n"
    "    adds\tr4, r4, r0\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr4, r0, #0\n"
    "    lsls\tr5, r5, #5\n"
    "    add\tr5, sl\n"
    "    movs\tr2, #138\t@ 0x8a\n"
    "    lsls\tr2, r2, #2\n"
    "    adds\tr6, r7, r2\n"
    "    movs\tr1, #146\t@ 0x92\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    adds\tr1, r5, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    ldr\tr2, [sp, #44]\t@ 0x2c\n"
    "    strb\tr0, [r2, #0]\n"
    "    lsls\tr4, r4, #5\n"
    "    add\tr4, sl\n"
    "    movs\tr1, #154\t@ 0x9a\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    ldr\tr2, [sp, #44]\t@ 0x2c\n"
    "    strb\tr0, [r2, #0]\n"
    "    ldr\tr1, [sp, #36]\t@ 0x24\n"
    "    cmp\tr1, #0\n"
    "    beq .Leu_0803D068\n"
    "    movs\tr1, #160\t@ 0xa0\n"
    "    lsls\tr1, r1, #1\n"
    "    add\tr1, sl\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    ldr\tr2, [sp, #44]\t@ 0x2c\n"
    "    strb\tr0, [r2, #0]\n"
    "    b .Leu_0803D082\n"
    "    .align 2, 0\n"
    ".Leu_0803D064: .word gMapClockStatusGlyphTiles\n"
    ".Leu_0803D068:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    adds\tr0, r6, #0\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    ldr\tr1, [sp, #44]\t@ 0x2c\n"
    "    strb\tr2, [r1, #0]\n"
    ".Leu_0803D082:\n"
    "    add\tsp, #48\t@ 0x30\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .align 2, 0\n"
    "\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_DE)
#if defined(REGION_DE)
    "    .align 2, 0\n"
    "    .global UpdateMapClockStatusHudCalendar\n"
    "    .thumb_func\n"
    "UpdateMapClockStatusHudCalendar:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #44\t@ 0x2c\n"
    "    str\tr1, [sp, #32]\n"
    "    lsls\tr2, r2, #24\n"
    "    lsrs\tr2, r2, #24\n"
    "    str\tr2, [sp, #36]\t@ 0x24\n"
    "    ldr\tr7, [r0, #0]\n"
    "    ldrb\tr0, [r1, #1]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    beq .Lde_0803CCC2\n"
    "    cmp\tr0, #1\n"
    "    ble .Lde_0803CCBC\n"
    "    cmp\tr0, #2\n"
    "    beq .Lde_0803CCC8\n"
    "    cmp\tr0, #3\n"
    "    beq .Lde_0803CCCE\n"
    ".Lde_0803CCBC:\n"
    "    movs\tr5, #11\n"
    "    movs\tr6, #12\n"
    "    b .Lde_0803CCD2\n"
    ".Lde_0803CCC2:\n"
    "    movs\tr5, #13\n"
    "    movs\tr6, #14\n"
    "    b .Lde_0803CCD2\n"
    ".Lde_0803CCC8:\n"
    "    movs\tr5, #15\n"
    "    movs\tr6, #16\n"
    "    b .Lde_0803CCD2\n"
    ".Lde_0803CCCE:\n"
    "    movs\tr5, #17\n"
    "    movs\tr6, #18\n"
    ".Lde_0803CCD2:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #132\t@ 0x84\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r2, .Lde_0803CD74\n"
    "    mov\tr9, r2\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #198\t@ 0xc6\n"
    "    lsls\tr0, r0, #1\n"
    "    adds\tr4, r7, r0\n"
    "    movs\tr1, #1\n"
    "    mov\tr8, r1\n"
    "    mov\tr2, r8\n"
    "    strb\tr2, [r4, #0]\n"
    "    lsls\tr1, r6, #5\n"
    "    add\tr1, r9\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #164\t@ 0xa4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr0, [r4, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldrb\tr3, [r1, #1]\n"
    "    lsls\tr0, r3, #25\n"
    "    lsrs\tr0, r0, #27\n"
    "    adds\tr0, #1\n"
    "    adds\tr5, r0, #0\n"
    "    ldrb\tr2, [r1, #0]\n"
    "    lsls\tr2, r2, #29\n"
    "    lsrs\tr2, r2, #29\n"
    "    lsls\tr3, r3, #30\n"
    "    lsrs\tr3, r3, #30\n"
    "    adds\tr2, #6\n"
    "    lsls\tr1, r3, #4\n"
    "    subs\tr1, r1, r3\n"
    "    lsls\tr1, r1, #1\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #3\n"
    "    adds\tr1, r1, r0\n"
    "    adds\tr1, r1, r5\n"
    "    subs\tr1, #1\n"
    "    str\tr4, [sp, #40]\t@ 0x28\n"
    "    cmp\tr1, #6\n"
    "    bls .Lde_0803CD3E\n"
    "    adds\tr0, r1, #0\n"
    "    movs\tr1, #7\n"
    "    bl __umodsi3\n"
    "    adds\tr1, r0, #0\n"
    ".Lde_0803CD3E:\n"
    "    movs\tr0, #7\n"
    "    adds\tr6, r0, #0\n"
    "    ands\tr6, r1\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr4, r0, #0\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr5, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    ble .Lde_0803CD78\n"
    "    lsls\tr1, r4, #5\n"
    "    add\tr1, r9\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    ldr\tr2, [sp, #40]\t@ 0x28\n"
    "    strb\tr0, [r2, #0]\n"
    "    b .Lde_0803CD94\n"
    "    .align 2, 0\n"
    ".Lde_0803CD74: .word gMapClockStatusGlyphTiles\n"
    ".Lde_0803CD78:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    ldr\tr1, [sp, #40]\t@ 0x28\n"
    "    strb\tr2, [r1, #0]\n"
    ".Lde_0803CD94:\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r0, .Lde_0803CDB8\n"
    "    adds\tr1, r1, r0\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #228\t@ 0xe4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    ldr\tr1, [sp, #40]\t@ 0x28\n"
    "    strb\tr0, [r1, #0]\n"
    "    cmp\tr6, #6\n"
    "    bhi .Lde_0803CDDC\n"
    "    lsls\tr0, r6, #2\n"
    "    ldr r1, .Lde_0803CDBC\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    mov\tpc, r0\n"
    ".Lde_0803CDB8: .word gMapClockStatusGlyphTiles\n"
    ".Lde_0803CDBC: .word .Lde_0803CDC0\n"
    ".Lde_0803CDC0: .word .Lde_0803CDDC\n"
    "    .word .Lde_0803CDE8\n"
    "    .word .Lde_0803CDF4\n"
    "    .word .Lde_0803CE00\n"
    "    .word .Lde_0803CE0C\n"
    "    .word .Lde_0803CE18\n"
    "    .word .Lde_0803CE24\n"
    ".Lde_0803CDDC:\n"
    "    movs\tr0, #96\t@ 0x60\n"
    "    str\tr0, [sp, #0]\n"
    "    movs\tr0, #97\t@ 0x61\n"
    "    str\tr0, [sp, #4]\n"
    "    movs\tr0, #98\t@ 0x62\n"
    "    b .Lde_0803CE2E\n"
    ".Lde_0803CDE8:\n"
    "    movs r0, #0x63\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x64\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x65\n"
    "    b .Lde_0803CE2E\n"
    ".Lde_0803CDF4:\n"
    "    movs r0, #0x66\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x67\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x68\n"
    "    b .Lde_0803CE2E\n"
    ".Lde_0803CE00:\n"
    "    movs r0, #0x69\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x6a\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x6b\n"
    "    b .Lde_0803CE2E\n"
    ".Lde_0803CE0C:\n"
    "    movs r0, #0x6c\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x6d\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x6e\n"
    "    b .Lde_0803CE2E\n"
    ".Lde_0803CE18:\n"
    "    movs r0, #0x6f\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x70\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x71\n"
    "    b .Lde_0803CE2E\n"
    ".Lde_0803CE24:\n"
    "    movs r0, #0x72\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x73\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x74\n"
    ".Lde_0803CE2E:\n"
    "    str\tr0, [sp, #8]\n"
    "    movs\tr2, #212\t@ 0xd4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    ldr\tr1, [sp, #0]\n"
    "    lsls\tr1, r1, #5\n"
    "    ldr r2, .Lde_0803CEB0\n"
    "    mov\tr9, r2\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #172\t@ 0xac\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr5, r7, r0\n"
    "    movs\tr1, #1\n"
    "    mov\tsl, r1\n"
    "    mov\tr2, sl\n"
    "    strb\tr2, [r5, #0]\n"
    "    ldr\tr1, [sp, #4]\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #228\t@ 0xe4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, sl\n"
    "    strb\tr0, [r5, #0]\n"
    "    ldr\tr1, [sp, #8]\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #244\t@ 0xf4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, sl\n"
    "    strb\tr0, [r5, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldr\tr4, [r1, #0]\n"
    "    lsls\tr4, r4, #11\n"
    "    lsrs\tr4, r4, #27\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr6, r0, #0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr4, r0, #0\n"
    "    mov\tr8, r5\n"
    "    cmp\tr6, #0\n"
    "    ble .Lde_0803CEB4\n"
    "    lsls\tr1, r6, #5\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #178\t@ 0xb2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    b .Lde_0803CEC6\n"
    "    .align 2, 0\n"
    ".Lde_0803CEB0: .word gMapClockStatusGlyphTiles\n"
    ".Lde_0803CEB4:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    movs\tr2, #178\t@ 0xb2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    mov\tr1, sp\n"
    ".Lde_0803CEC6:\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr1, sl\n"
    "    ldr\tr0, [sp, #40]\t@ 0x28\n"
    "    strb\tr1, [r0, #0]\n"
    "    lsls\tr1, r4, #5\n"
    "    ldr r2, .Lde_0803CF64\n"
    "    mov\tr9, r2\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #138\t@ 0x8a\n"
    "    lsls\tr2, r2, #2\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr6, #1\n"
    "    mov\tr0, r8\n"
    "    strb\tr6, [r0, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldr\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #5\n"
    "    lsrs\tr0, r0, #26\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    lsls\tr4, r0, #2\n"
    "    adds\tr4, r4, r0\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr4, r0, #0\n"
    "    lsls\tr5, r5, #5\n"
    "    add\tr5, r9\n"
    "    movs\tr2, #154\t@ 0x9a\n"
    "    lsls\tr2, r2, #2\n"
    "    adds\tr0, r7, r2\n"
    "    adds\tr1, r5, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr6, [r0, #0]\n"
    "    lsls\tr4, r4, #5\n"
    "    add\tr4, r9\n"
    "    movs\tr1, #162\t@ 0xa2\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    strb\tr6, [r2, #0]\n"
    "    ldr\tr0, [sp, #36]\t@ 0x24\n"
    "    cmp\tr0, #0\n"
    "    beq .Lde_0803CF68\n"
    "    movs\tr1, #160\t@ 0xa0\n"
    "    lsls\tr1, r1, #1\n"
    "    add\tr1, r9\n"
    "    movs\tr2, #146\t@ 0x92\n"
    "    lsls\tr2, r2, #2\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr6, [r0, #0]\n"
    "    b .Lde_0803CF84\n"
    "    .align 2, 0\n"
    ".Lde_0803CF64: .word gMapClockStatusGlyphTiles\n"
    ".Lde_0803CF68:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    movs\tr1, #146\t@ 0x92\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    strb\tr6, [r2, #0]\n"
    ".Lde_0803CF84:\n"
    "    add\tsp, #44\t@ 0x2c\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    .align 2, 0\n"
    "    .global UpdateMapClockStatusHudCalendar\n"
    "    .thumb_func\n"
    "UpdateMapClockStatusHudCalendar:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #48\t@ 0x30\n"
    "    str\tr1, [sp, #32]\n"
    "    lsls\tr2, r2, #24\n"
    "    lsrs\tr2, r2, #24\n"
    "    str\tr2, [sp, #36]\t@ 0x24\n"
    "    ldr\tr7, [r0, #0]\n"
    "    ldrb\tr0, [r1, #1]\n"
    "    lsls\tr0, r0, #30\n"
    "    lsrs\tr0, r0, #30\n"
    "    cmp\tr0, #1\n"
    "    beq .Lus_0803CD7E\n"
    "    cmp\tr0, #1\n"
    "    ble .Lus_0803CD78\n"
    "    cmp\tr0, #2\n"
    "    beq .Lus_0803CD84\n"
    "    cmp\tr0, #3\n"
    "    beq .Lus_0803CD8A\n"
    ".Lus_0803CD78:\n"
    "    movs\tr5, #11\n"
    "    movs\tr6, #12\n"
    "    b .Lus_0803CD8E\n"
    ".Lus_0803CD7E:\n"
    "    movs\tr5, #13\n"
    "    movs\tr6, #14\n"
    "    b .Lus_0803CD8E\n"
    ".Lus_0803CD84:\n"
    "    movs\tr5, #15\n"
    "    movs\tr6, #16\n"
    "    b .Lus_0803CD8E\n"
    ".Lus_0803CD8A:\n"
    "    movs\tr5, #17\n"
    "    movs\tr6, #18\n"
    ".Lus_0803CD8E:\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #132\t@ 0x84\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r2, .Lus_0803CE30\n"
    "    mov\tsl, r2\n"
    "    add\tr1, sl\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #198\t@ 0xc6\n"
    "    lsls\tr0, r0, #1\n"
    "    adds\tr4, r7, r0\n"
    "    movs\tr1, #1\n"
    "    mov\tr8, r1\n"
    "    mov\tr2, r8\n"
    "    strb\tr2, [r4, #0]\n"
    "    lsls\tr1, r6, #5\n"
    "    add\tr1, sl\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #164\t@ 0xa4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    strb\tr0, [r4, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldrb\tr3, [r1, #1]\n"
    "    lsls\tr0, r3, #25\n"
    "    lsrs\tr0, r0, #27\n"
    "    adds\tr0, #1\n"
    "    adds\tr5, r0, #0\n"
    "    ldrb\tr2, [r1, #0]\n"
    "    lsls\tr2, r2, #29\n"
    "    lsrs\tr2, r2, #29\n"
    "    lsls\tr3, r3, #30\n"
    "    lsrs\tr3, r3, #30\n"
    "    adds\tr2, #6\n"
    "    lsls\tr1, r3, #4\n"
    "    subs\tr1, r1, r3\n"
    "    lsls\tr1, r1, #1\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #3\n"
    "    adds\tr1, r1, r0\n"
    "    adds\tr1, r1, r5\n"
    "    subs\tr1, #1\n"
    "    mov\tr9, r4\n"
    "    cmp\tr1, #6\n"
    "    bls .Lus_0803CDFA\n"
    "    adds\tr0, r1, #0\n"
    "    movs\tr1, #7\n"
    "    bl __umodsi3\n"
    "    adds\tr1, r0, #0\n"
    ".Lus_0803CDFA:\n"
    "    movs\tr0, #7\n"
    "    adds\tr6, r0, #0\n"
    "    ands\tr6, r1\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr4, r0, #0\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr5, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    ble .Lus_0803CE34\n"
    "    lsls\tr1, r4, #5\n"
    "    add\tr1, sl\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    mov\tr2, r9\n"
    "    strb\tr0, [r2, #0]\n"
    "    b .Lus_0803CE50\n"
    "    .align 2, 0\n"
    ".Lus_0803CE30: .word gMapClockStatusGlyphTiles\n"
    ".Lus_0803CE34:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #196\t@ 0xc4\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    mov\tr1, r9\n"
    "    strb\tr2, [r1, #0]\n"
    ".Lus_0803CE50:\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r0, .Lus_0803CE74\n"
    "    adds\tr1, r1, r0\n"
    "    adds\tr0, r7, #0\n"
    "    adds\tr0, #228\t@ 0xe4\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr1, r9\n"
    "    strb\tr0, [r1, #0]\n"
    "    cmp\tr6, #6\n"
    "    bhi .Lus_0803CE98\n"
    "    lsls\tr0, r6, #2\n"
    "    ldr r1, .Lus_0803CE78\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    mov\tpc, r0\n"
    ".Lus_0803CE74: .word gMapClockStatusGlyphTiles\n"
    ".Lus_0803CE78: .word .Lus_0803CE7C\n"
    ".Lus_0803CE7C: .word .Lus_0803CE98\n"
    "    .word .Lus_0803CEA4\n"
    "    .word .Lus_0803CEB0\n"
    "    .word .Lus_0803CEBC\n"
    "    .word .Lus_0803CEC8\n"
    "    .word .Lus_0803CED4\n"
    "    .word .Lus_0803CEE0\n"
    ".Lus_0803CE98:\n"
    "    movs\tr0, #96\t@ 0x60\n"
    "    str\tr0, [sp, #0]\n"
    "    movs\tr0, #97\t@ 0x61\n"
    "    str\tr0, [sp, #4]\n"
    "    movs\tr0, #98\t@ 0x62\n"
    "    b .Lus_0803CEEA\n"
    ".Lus_0803CEA4:\n"
    "    movs r0, #0x63\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x64\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x65\n"
    "    b .Lus_0803CEEA\n"
    ".Lus_0803CEB0:\n"
    "    movs r0, #0x66\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x67\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x68\n"
    "    b .Lus_0803CEEA\n"
    ".Lus_0803CEBC:\n"
    "    movs r0, #0x69\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x6a\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x6b\n"
    "    b .Lus_0803CEEA\n"
    ".Lus_0803CEC8:\n"
    "    movs r0, #0x6c\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x6d\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x6e\n"
    "    b .Lus_0803CEEA\n"
    ".Lus_0803CED4:\n"
    "    movs r0, #0x6f\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x70\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x71\n"
    "    b .Lus_0803CEEA\n"
    ".Lus_0803CEE0:\n"
    "    movs r0, #0x72\n"
    "    str r0, [sp]\n"
    "    movs r0, #0x73\n"
    "    str r0, [sp, #4]\n"
    "    movs r0, #0x74\n"
    ".Lus_0803CEEA:\n"
    "    str\tr0, [sp, #8]\n"
    "    movs\tr2, #212\t@ 0xd4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    ldr\tr1, [sp, #0]\n"
    "    lsls\tr1, r1, #5\n"
    "    ldr r2, .Lus_0803CF90\n"
    "    mov\tr8, r2\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #172\t@ 0xac\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr4, r7, r0\n"
    "    movs\tr6, #1\n"
    "    strb\tr6, [r4, #0]\n"
    "    ldr\tr1, [sp, #4]\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #228\t@ 0xe4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    strb\tr6, [r4, #0]\n"
    "    ldr\tr1, [sp, #8]\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #244\t@ 0xf4\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    strb\tr6, [r4, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldr\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #11\n"
    "    lsrs\tr0, r0, #27\n"
    "    adds\tr5, r0, #0\n"
    "    movs\tr1, #30\n"
    "    str\tr4, [sp, #44]\t@ 0x2c\n"
    "    cmp\tr5, #11\n"
    "    bhi .Lus_0803CF48\n"
    "    movs\tr1, #28\n"
    ".Lus_0803CF48:\n"
    "    lsls\tr1, r1, #5\n"
    "    add\tr1, r8\n"
    "    movs\tr2, #130\t@ 0x82\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r9\n"
    "    strb\tr6, [r0, #0]\n"
    "    movs\tr4, #12\n"
    "    cmp\tr5, #12\n"
    "    beq .Lus_0803CF6A\n"
    "    adds\tr4, r5, #0\n"
    "    cmp\tr4, #11\n"
    "    bls .Lus_0803CF6A\n"
    "    subs\tr4, #12\n"
    ".Lus_0803CF6A:\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr5, #0\n"
    "    ble .Lus_0803CF94\n"
    "    lsls\tr1, r5, #5\n"
    "    ldr r0, .Lus_0803CF90\n"
    "    adds\tr1, r1, r0\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    b .Lus_0803CFA6\n"
    ".Lus_0803CF90: .word gMapClockStatusGlyphTiles\n"
    ".Lus_0803CF94:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    mov\tr1, sp\n"
    ".Lus_0803CFA6:\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr1, r9\n"
    "    strb\tr0, [r1, #0]\n"
    "    lsls\tr1, r4, #5\n"
    "    ldr r2, .Lus_0803D050\n"
    "    mov\tsl, r2\n"
    "    add\tr1, sl\n"
    "    movs\tr2, #178\t@ 0xb2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr0, r7, r2\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    movs\tr0, #1\n"
    "    mov\tr8, r0\n"
    "    mov\tr2, r8\n"
    "    mov\tr1, r9\n"
    "    strb\tr2, [r1, #0]\n"
    "    ldr\tr1, [sp, #32]\n"
    "    ldr\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #5\n"
    "    lsrs\tr0, r0, #26\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    lsls\tr4, r0, #2\n"
    "    adds\tr4, r4, r0\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __udivsi3\n"
    "    adds\tr5, r0, #0\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #10\n"
    "    bl __umodsi3\n"
    "    adds\tr4, r0, #0\n"
    "    lsls\tr5, r5, #5\n"
    "    add\tr5, sl\n"
    "    movs\tr2, #138\t@ 0x8a\n"
    "    lsls\tr2, r2, #2\n"
    "    adds\tr6, r7, r2\n"
    "    movs\tr1, #146\t@ 0x92\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    adds\tr1, r5, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    ldr\tr2, [sp, #44]\t@ 0x2c\n"
    "    strb\tr0, [r2, #0]\n"
    "    lsls\tr4, r4, #5\n"
    "    add\tr4, sl\n"
    "    movs\tr1, #154\t@ 0x9a\n"
    "    lsls\tr1, r1, #2\n"
    "    adds\tr0, r7, r1\n"
    "    adds\tr1, r4, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    ldr\tr2, [sp, #44]\t@ 0x2c\n"
    "    strb\tr0, [r2, #0]\n"
    "    ldr\tr1, [sp, #36]\t@ 0x24\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_0803D054\n"
    "    movs\tr1, #160\t@ 0xa0\n"
    "    lsls\tr1, r1, #1\n"
    "    add\tr1, sl\n"
    "    adds\tr0, r6, #0\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, r8\n"
    "    ldr\tr2, [sp, #44]\t@ 0x2c\n"
    "    strb\tr0, [r2, #0]\n"
    "    b .Lus_0803D06E\n"
    "    .align 2, 0\n"
    ".Lus_0803D050: .word gMapClockStatusGlyphTiles\n"
    ".Lus_0803D054:\n"
    "    mov\tr0, sp\n"
    "    movs\tr1, #0\n"
    "    movs\tr2, #32\n"
    "    bl memset\n"
    "    adds\tr0, r6, #0\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr2, r8\n"
    "    ldr\tr1, [sp, #44]\t@ 0x2c\n"
    "    strb\tr2, [r1, #0]\n"
    ".Lus_0803D06E:\n"
    "    add\tsp, #48\t@ 0x30\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .align 2, 0\n"
    "\n"
#endif
#endif
#endif
);


void SetMapClockStatusHudSeason(MapClockStatusHudContent const * hud, int season)
{
    MapClockStatusHudData * state = hud->state;
    u32 tiles[2];
    switch (season) {
    default:
    case SEASON_SPRING: tiles[0] = 11; tiles[1] = 12; break;
    case SEASON_SUMMER: tiles[0] = 13; tiles[1] = 14; break;
    case SEASON_FALL:   tiles[0] = 15; tiles[1] = 16; break;
    case SEASON_WINTER: tiles[0] = 17; tiles[1] = 18; break;
    }
    memcpy(state->date_tiles.tiles[0], gMapClockStatusGlyphTiles[tiles[0]], TILE_SIZE_4BPP);
    state->date_tiles.dirty = 1;
    u8 const * second_tile = gMapClockStatusGlyphTiles[tiles[1]];
    memcpy(state->date_tiles.tiles[1], second_tile, TILE_SIZE_4BPP);
    state->date_tiles.dirty = 1;
}

void SetMapClockStatusHudDayAndWeekday(MapClockStatusHudContent const * hud,
    u32 day, u32 weekday)
{
    MapClockStatusHudData * state = hud->state;
    i32 tens = day / 10;
    u32 ones = day % 10;
    if (tens > 0) {
        u8 const * tile = GetMapClockStatusGlyph(tens);
        memcpy(state->date_tiles.tiles[2], tile, TILE_SIZE_4BPP);
        state->date_tiles.dirty = 1;
    } else {
        u8 blank[TILE_SIZE_4BPP];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->date_tiles.tiles[2], pixels, TILE_SIZE_4BPP);
        state->date_tiles.dirty = 1;
    }
    u8 const * ones_tile = GetMapClockStatusGlyph(ones);
    memcpy(state->date_tiles.tiles[3], ones_tile, TILE_SIZE_4BPP);
    state->date_tiles.dirty = 1;
#if defined(REGION_JP)
    u8 const * weekday_tile = GetMapClockStatusGlyph(weekday + 21);
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE], weekday_tile, TILE_SIZE_4BPP);
    state->time_tiles.dirty = 1;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    u32 tiles[3];
    switch (weekday) {
    default:
    case DAY_OF_WEEK_SUNDAY:    tiles[0] = 96;  tiles[1] = 97;  tiles[2] = 98;  break;
    case DAY_OF_WEEK_MONDAY:    tiles[0] = 99;  tiles[1] = 100; tiles[2] = 101; break;
    case DAY_OF_WEEK_TUESDAY:   tiles[0] = 102; tiles[1] = 103; tiles[2] = 104; break;
    case DAY_OF_WEEK_WEDNESDAY: tiles[0] = 105; tiles[1] = 106; tiles[2] = 107; break;
    case DAY_OF_WEEK_THURSDAY:  tiles[0] = 108; tiles[1] = 109; tiles[2] = 110; break;
    case DAY_OF_WEEK_FRIDAY:    tiles[0] = 111; tiles[1] = 112; tiles[2] = 113; break;
    case DAY_OF_WEEK_SATURDAY:  tiles[0] = 114; tiles[1] = 115; tiles[2] = 116; break;
    }
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE], gMapClockStatusGlyphTiles[tiles[0]], TILE_SIZE_4BPP);
    state->time_tiles.dirty = 1;
    u8 const * second_tile = GetMapClockStatusGlyph(tiles[1]);
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE + 1], second_tile, TILE_SIZE_4BPP);
    state->time_tiles.dirty = 1;
    u8 const * third_tile = GetMapClockStatusGlyph(tiles[2]);
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE + 2], third_tile, TILE_SIZE_4BPP);
    state->time_tiles.dirty = 1;
#endif
}

void SetMapClockStatusHudHour(MapClockStatusHudContent const * hud, u32 hour)
{
    MapClockStatusHudData * state = hud->state;
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    u32 meridiem = 30;
    if (hour <= 11)
        meridiem = 28;
    u8 const * meridiem_tile = GetMapClockStatusGlyph(meridiem);
    memcpy(state->date_tiles.tiles[4], meridiem_tile, TILE_SIZE_4BPP);
    state->date_tiles.dirty = 1;
#if defined(REGION_JP)
    u32 display_hour = hour;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    u32 display_hour = 12;
#endif
    // Meridiem and both digits share this date-component dirty byte.
    u8 & date_dirty = state->date_tiles.dirty;
#if defined(REGION_JP)
    if (display_hour > 11)
        display_hour -= 12;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    if (hour != 12) {
        display_hour = hour;
        if (display_hour > 11)
            display_hour -= 12;
    }
#endif
#elif defined(REGION_DE)
    u32 display_hour = hour;
#endif
    i32 tens = display_hour / 10;
    u32 ones = display_hour % 10;
    if (tens > 0) {
        u8 const * tile = GetMapClockStatusGlyph(tens);
        memcpy(state->date_tiles.tiles[MAP_CLOCK_DATE_HOUR_TENS_TILE], tile, TILE_SIZE_4BPP);
#if defined(REGION_DE)
        state->date_tiles.dirty = 1;
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
        date_dirty = 1;
#endif
    } else {
        u8 blank[TILE_SIZE_4BPP];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->date_tiles.tiles[MAP_CLOCK_DATE_HOUR_TENS_TILE], pixels, TILE_SIZE_4BPP);
#if defined(REGION_DE)
        state->date_tiles.dirty = 1;
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
        date_dirty = 1;
#endif
    }
    u8 const * ones_tile = GetMapClockStatusGlyph(ones);
#if defined(REGION_DE)
    memcpy(state->time_tiles.tiles[4], ones_tile, TILE_SIZE_4BPP);
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    memcpy(state->date_tiles.tiles[7], ones_tile, TILE_SIZE_4BPP);
#endif
#if defined(REGION_DE)
    // The DE ones digit belongs to the separate time component.
    state->time_tiles.dirty = 1;
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    date_dirty = 1;
#endif
}

void SetMapClockStatusHudColonVisible(MapClockStatusHudContent const * hud, u8 visible)
{
    MapClockStatusHudData * state = hud->state;
    if (visible != 0) {
        u8 const * colon = GetMapClockStatusGlyph(10);
        memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_COLON_TILE], colon, TILE_SIZE_4BPP);
        state->time_tiles.dirty = 1;
    } else {
        u8 blank[TILE_SIZE_4BPP];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_COLON_TILE], pixels, TILE_SIZE_4BPP);
        state->time_tiles.dirty = 1;
    }
}

void SetMapClockStatusHudMinuteDigits(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudData * state = hud->state;
    u32 tens = value / 10;
    u32 ones = value % 10;
    u8 const * tens_tile = gMapClockStatusGlyphTiles[tens];
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_MINUTE_TENS_TILE], tens_tile, TILE_SIZE_4BPP);
    state->time_tiles.dirty = 1;
    u8 const * ones_tile = gMapClockStatusGlyphTiles[ones];
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_MINUTE_TENS_TILE + 1], ones_tile, TILE_SIZE_4BPP);
    state->time_tiles.dirty = 1;
}

void SetMapClockStatusHudUnkSelector(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudData * state = hud->state;
    u32 next = state->unk_selector;
    switch (value) {
    case 0: next = 0; break;
    case 1: next = 1; break;
    case 2: next = 2; break;
    case 3: next = 3; break;
    case 4: next = 4; break;
    }
    if (next != state->unk_selector) {
        state->unk_selector = next;
        state->unk_selector_dirty = 1;
    }
}

void SetMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudData * state = hud->state;
    if (state->unk_value_active == 0 || value != state->unk_value) {
        state->unk_value_active = 1;
        state->unk_value = value;
        state->unk_value_dirty = 1;
    }
}

void ClearMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud)
{
    MapClockStatusHudData * state = hud->state;
    if (state->unk_value_active != 0) {
        state->unk_value_active = 0;
        state->unk_value_dirty = 1;
    }
}

void ClearMapClockStatusWidgetUnkValue(MapClockStatusHudWidget const * widget)
{
    ClearMapClockStatusHudUnkValue(&widget->content);
}

void SetMapClockStatusWidgetUnkValue(MapClockStatusHudWidget const * widget, u32 value)
{
    SetMapClockStatusHudUnkValue(&widget->content, value);
}

void SetMapClockStatusWidgetUnkSelector(MapClockStatusHudWidget const * widget, u32 value)
{
    SetMapClockStatusHudUnkSelector(&widget->content, value);
}

void SetMapClockStatusWidgetMinuteDigits(MapClockStatusHudWidget const * widget, u32 value)
{
    SetMapClockStatusHudMinuteDigits(&widget->content, value);
}

void SetMapClockStatusWidgetColonVisible(MapClockStatusHudWidget const * widget, u8 visible)
{
    SetMapClockStatusHudColonVisible(&widget->content, visible);
}

void SetMapClockStatusWidgetHour(MapClockStatusHudWidget const * widget, u32 hour)
{
    SetMapClockStatusHudHour(&widget->content, hour);
}

void SetMapClockStatusWidgetDayAndWeekday(MapClockStatusHudWidget const * widget, u32 day, u32 weekday)
{
    SetMapClockStatusHudDayAndWeekday(&widget->content, day, weekday);
}

void SetMapClockStatusWidgetSeason(MapClockStatusHudWidget const * widget, int season)
{
    SetMapClockStatusHudSeason(&widget->content, season);
}

void UpdateMapClockStatusWidgetCalendar(MapClockStatusHudWidget const * widget,
    GameCalendar const & calendar, u8 show_colon)
{
    UpdateMapClockStatusHudCalendar(&widget->content, calendar, show_colon);
}

u32 MapClockStatusHudWidget::Draw(
    HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands)
{
    u32 const state = Update(display, uploads, commands);
    if (state == 3) {
        i32 x = GetX();
        i32 y = GetY();
        DrawMapClockStatusHud(&content, x, y, sprites, uploads);
    }
    return state;
}
