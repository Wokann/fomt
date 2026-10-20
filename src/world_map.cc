#include "world_map.hh"
#include "game_state.hh"
#include "map_data.hh"
#include "field_render_rect_descriptors.hh"
#include "field_render_resource_data.hh"
#include "hardware_dma.hh"
#include "hardware_state_accessors.hh"
#include "time_of_day.hh"
#include "gbasvc.h"
#include <string.h>

EC void UpdateWorldMap(GameSceneWorldMapPrefix * map)
{
    if (map->movement_frames != 0) {
        map->x.q16 += map->step_x_q16;
        map->y.q16 += map->step_y_q16;
        --map->movement_frames;
        map->view_changed = true;
    }
    // These are layout indices, not the logical MAP_* identifiers.
    switch (map->map_data_id) {
    case 14:
        map->layout_animations[4].Tick(gMapLayoutTileAnimation8);
        map->layout_animations[5].Tick(gMapLayoutTileAnimation9);
        map->layout_animations[6].Tick(gMapLayoutTileAnimation10);
        break;
    case 15:
        map->layout_animations[4].Tick(gMapLayoutTileAnimation11);
        map->layout_animations[5].Tick(gMapLayoutTileAnimation12);
        map->layout_animations[6].Tick(gMapLayoutTileAnimation13);
        break;
    case 60:
        map->layout_animations[8].Tick(gMapLayoutTileAnimation17);
        break;
    case 31:
        map->layout_animations[9].Tick(gMapLayoutTileAnimation15);
        break;
    case 8:
        map->layout_animations[7].Tick(gMapLayoutTileAnimation14);
        break;
    case 9:
        map->layout_animations[7].Tick(gMapLayoutTileAnimation16);
        break;
    case 6:
        map->layout_animations[2].Tick(gMapLayoutTileAnimation4);
        map->layout_animations[3].Tick(gMapLayoutTileAnimation5);
        break;
    case 7:
        map->layout_animations[2].Tick(gMapLayoutTileAnimation6);
        map->layout_animations[3].Tick(gMapLayoutTileAnimation7);
        break;
    case 0:
    case 62:
    case 63:
        map->layout_animations[0].Tick(gMapLayoutTileAnimation0);
        map->layout_animations[1].Tick(gMapLayoutTileAnimation2);
        break;
    case 1:
        map->layout_animations[0].Tick(gMapLayoutTileAnimation1);
        map->layout_animations[1].Tick(gMapLayoutTileAnimation3);
        break;
    }
}

EC Vec2 ClampWorldMapCameraPosition(GameSceneWorldMapPrefix const * map, i32 x, i32 y)
{
    i32 old_x = map->x.parts.integer;
    i32 old_y = map->y.parts.integer;
    i32 center_x = old_x + 120;
    i32 center_y = old_y + 80;
    MapData const * data = GetMapData(map->map_data_id);
    i32 width = data->width * 8;
    i32 height = data->height * 8;
    i32 dx = x - center_x;
    i32 dy = y - center_y;
    i32 next_x = old_x + dx;
    if (next_x < 0)
        next_x = 0;
    else if (next_x > width - 240)
        next_x = width - 240;
    i32 next_y = old_y + dy;
    if (next_y < 0)
        next_y = 0;
    else if (next_y > height - 160)
        next_y = height - 160;
    return Vec2(next_x, next_y);
}

EC void SetWorldMapCameraPosition(GameSceneWorldMapPrefix * map, i32 x, i32 y)
{
    Vec2 target;
    target = ClampWorldMapCameraPosition(map, x, y);
    Vec2 const & position = target;
    if (map->x.parts.integer != position.x) {
        map->view_changed = true;
        map->x.q16 = position.x << 16;
    }
    i32 current_y = map->y.parts.integer;
    if (current_y != position.y) {
        map->view_changed = true;
        map->y.q16 = position.y << 16;
    }
}

EC void PanWorldMapCameraTo(GameSceneWorldMapPrefix * map, i32 x, i32 y, u32 speed)
{
    Vec2 target;
    target = ClampWorldMapCameraPosition(map, x, y);
    Vec2 const & position = target;
    if (speed == 0)
        speed = 1;
    i32 old_x = map->x.parts.integer;
    i32 dx = position.x - old_x;
    i32 old_y = map->y.parts.integer;
    i32 dy = position.y - old_y;
    if (dx != 0 || dy != 0) {
        u32 squared = dx * dx + dy * dy;
        i32 shift = 0;
        while ((squared << (shift * 2)) <= 0x3FFFFFFF)
            ++shift;
        squared <<= shift * 2;
        i32 distance = Sqrt(squared) >> shift;
        i32 frames = static_cast<u32>(distance) / speed;
        if (frames == 0)
            frames = 1;
        map->step_x_q16 = ((position.x << 16) - map->x.q16) / frames;
        map->step_y_q16 = ((position.y << 16) - map->y.q16) / frames;
        map->movement_frames = frames;
    } else {
        map->movement_frames = 0;
    }
}

EC bool IsWorldMapCameraMovementComplete(GameSceneWorldMapPrefix const * map)
{
    return map->movement_frames == 0;
}

EC void ApplyMapTilePatch(GameSceneWorldMapPrefix * map,
    FieldRenderRectDescriptor const & patch, u32 x, u32 y)
{
    u32 map_width = GetMapData(map->map_data_id)->width;
    u32 width = patch.width;
    u32 height = patch.height;
    void const * const * buffers = patch.source_buffers;
    for (u32 layer = 0; layer < 3; ++layer) {
        if (buffers[layer] != nullptr) {
            for (u32 row = 0; row < height; ++row) {
                memcpy(map->tile_layers[layer] + x + (y + row) * map_width,
                    static_cast<u16 const *>(buffers[layer]) + row * width,
                    width * sizeof(u16));
            }
        }
    }
    if (patch.lookup_indices != nullptr && patch.lookup_values != nullptr) {
        for (u32 row = 0; row < height; ++row) {
            u8 const * source = static_cast<u8 const *>(patch.lookup_indices) + row * width;
            FieldRenderTileAttributes * destination = map->tile_attributes + x + (y + row) * map_width;
            for (u32 column = 0; column < width; ++column) {
                *destination++ = static_cast<FieldRenderTileAttributes const *>(patch.lookup_values)[*source++];
            }
        }
    }
}

EC void LoadWorldMapTilemaps(GameSceneWorldMapPrefix & map)
{
    MapData const * data = GetMapData(map.map_data_id);
    u32 layer = 0;
    u16 ** destination = map.tile_layers;
    for (; layer < 3; ++destination, ++layer) {
        u8 const * source = data->tilemaps[layer];
        if (source != nullptr)
            Unpack(source, *destination);
        else
            func_08008EB8(0x03FF03FF, *destination, static_cast<u32>(data->width) * (data->height << 1));
    }
    map.view_changed = true;
}

EC void SetWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period)
{
    switch (period) {
    case TIME_OF_DAY_PERIOD_NIGHT:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_NIGHT, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_MORNING, 1);
        break;
    case TIME_OF_DAY_PERIOD_MORNING:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_MORNING, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_AFTERNOON, 1);
        break;
    case TIME_OF_DAY_PERIOD_AFTERNOON:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_AFTERNOON, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_EVENING, 1);
        break;
    case TIME_OF_DAY_PERIOD_EVENING:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_EVENING, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_NIGHT, 1);
        break;
    }
    map.time_palette_changed = true;
}

EC void LoadWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period,
    u32 buffer_index)
{
    MapData const * data = GetMapData(map.map_data_id);
    // The native loader first decodes the default palette even when the
    // selected period will decode that same resource again below.
    Unpack(data->palettes[0], map.time_palette_buffers[buffer_index]);
    switch (period) {
    case TIME_OF_DAY_PERIOD_MORNING:
    case TIME_OF_DAY_PERIOD_AFTERNOON:
    case TIME_OF_DAY_PERIOD_EVENING:
        Unpack(data->palettes[0], map.time_palette_buffers[buffer_index]);
        break;
    case TIME_OF_DAY_PERIOD_NIGHT:
        Unpack(data->palettes[1], map.time_palette_buffers[buffer_index]);
        break;
    }
}

EC void LoadWorldMapTiles(GameSceneWorldMapPrefix & map)
{
    MapData const * data = GetMapData(map.map_data_id);
    Unpack(data->tiles, reinterpret_cast<void *>(0x06000000));
}

EC bool func_080A5EB8(GameSceneWorldMapPrefix * map, Location const & location)
{
    if (location.GetMap() != MAP_MINERAL_BEACH || map->map != MAP_MINERAL_BEACH
        || map->map_data_id != 8)
        return false;

    Vec2 position(location.GetX() / 8, location.GetY() / 8);
    u32 width = GetMapData(8)->width;
    for (u32 layer = 0; layer < 3; ++layer) {
        u16 const * column = map->tile_layers[2 - layer] + position.x;
        column += position.y * width;
        u32 tile = *column & 0x3FF;
        if (tile != 0x3FF) {
            if (tile - 0x58 <= 0x3C || tile <= 0x33)
                return true;
            return false;
        }
    }
    return false;
}

EC void func_080A601C(GameSceneWorldMapPrefix * map)
{
    map->unk_58 = 0x14;
}

EC void RefreshCoopFeedTrough(GameSceneWorldMapPrefix * map, u32 index)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x24:
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[36],
            gFieldRenderPatchArgumentData.values_00[index], 8);
        break;
    case 0x40:
    {
        FieldRenderRectDescriptor const & patch = gFieldRenderRectDescriptors[36];
        u8 const * coordinates = gFieldRenderPatchArgumentData.values_08;
        ApplyMapTilePatch(map, patch,
            coordinates[index], 4);
        break;
    }
    }
    map->view_changed = true;
}

EC void func_080A6138(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[14], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[14], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[14], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6194(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[15], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[15], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[15], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A61F0(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[16], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[16], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6234(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[17], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[17], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6278(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[18], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[18], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A62BC(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[19], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[19], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6300(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A635C(GameSceneWorldMapPrefix * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[21], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[21], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[21], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A63B8(GameSceneWorldMapPrefix * map, u32 unk)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x40:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[81], 1, 0xD);
        break;
    case 0x24:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[81], 1, 0x11);
        break;
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[81], 1, unk == 0 ? 0x11 : 0xD);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC u32 SelectDefaultWorldMapData(GameSceneWorldMapPrefix const * map)
{
    return SelectMapDataId(map->map, SEASON_SUMMER, 0, 0, 0);
}

EC FieldRenderTileAttributes * GetWorldMapTileAttributes(GameSceneWorldMapPrefix * map,
    u32 x, u32 y)
{
    u32 width = GetMapData(map->map_data_id)->width;
    return &map->tile_attributes[x + y * width];
}

EC u32 GetWorldMapDataId(GameSceneWorldMapPrefix const * map)
{
    return map->map_data_id;
}

EC u32 GetWorldMapId(GameSceneWorldMapPrefix const * map)
{
    return map->map;
}

EC i32 GetWorldMapViewY(GameSceneWorldMapPrefix const * map)
{
    return map->y.parts.integer;
}

EC i32 GetWorldMapViewX(GameSceneWorldMapPrefix const * map)
{
    return map->x.parts.integer;
}

EC void UpdateSavedMapTileAnimationTimers(GameSceneSavedMapPrefix * map)
{
    UpdateWorldMap(map);
    GameStateSaveImage * save = map->save;
    if (map->map == MAP_ROSE_SQUARE
        && save->event_state.harvest_festival_active == FESTIVAL_PHASE_INITIAL) {
        map->tile_animations[0].Tick(gMapTilePatchAnimation0);
        map->tile_animations[1].Tick(gMapTilePatchAnimation1);
    }
}

static inline bool AdvanceMapAnimationFrame(MapTilePatchAnimationState & state, u32 count)
{
    return ++state.frame == count;
}

static inline void QueueMapAnimationFrame(MapTilePatchAnimationState & state,
    GameSceneWorldMapPrefix * map, FarmHouseTilePatchAnimationDescriptor const & animation,
    HardwareDmaQueue & queue)
{
    if (state.update_pending) {
        state.update_pending = false;
        QueueMapTilePatch(map, animation.patch, state.frame, queue);
        MapTilePatchFrameHeader const * frames =
            reinterpret_cast<MapTilePatchFrameHeader const *>(animation.patch.frame_data);
        if (AdvanceMapAnimationFrame(state, frames->frame_count))
            state.frame = 0;
    }
}

EC void DrawSavedWorldMap(GameSceneSavedMapPrefix * map, HardwareDmaQueue & queue,
    HardwareDisplayState & display, void * unk)
{
    func_080A4F50(map, queue, display, unk);
    GameStateSaveImage * save = map->save;
    switch (map->map) {
    case MAP_FARMHOUSE:
        if (map->unk_98) {
            map->unk_98 = false;
            if (map->save->farm.farm_house.HasStocking()) {
                if (map->save->farm.farm_house.GetStockingArticleId() == ITEM_ARTICLE_NONE)
                    QueueMapTilePatch(map, gMapTilePatch6, 1, queue);
                else
                    QueueMapTilePatch(map, gMapTilePatch6, 2, queue);
            } else {
                QueueMapTilePatch(map, gMapTilePatch6, 0, queue);
            }
        }
        break;
    case MAP_ROSE_SQUARE:
        if (save->event_state.harvest_festival_active == FESTIVAL_PHASE_INITIAL) {
            QueueMapAnimationFrame(map->tile_animations[0], map, gMapTilePatchAnimation0, queue);
            QueueMapAnimationFrame(map->tile_animations[1], map, gMapTilePatchAnimation1, queue);
        }
        break;
    }
}

EC void ResetSavedMapTileAnimationFrames(GameSceneSavedMapPrefix * map)
{
#if defined(REGION_JP)
    func_080A5198(map);
#else
    func_080A5760(map);
#endif
    map->tile_animations[0].ResetFrame();
    map->tile_animations[1].ResetFrame();
}

EC void RefreshFieldPlotTiles(GameSceneWorldMapPrefix * map, u32 x, u32 y,
    FieldPlot const * plot, FieldPlotRenderData const * render_data)
{
    u32 width = GetMapData(map->map_data_id)->width;
    u16 const * ground = static_cast<u16 const *>(plot->method_0800AF20());
    if (ground != nullptr) {
        memcpy(map->tile_layers[0] + x + y * width, ground, 4);
        memcpy(map->tile_layers[0] + x + (y + 1) * width, ground + 2, 4);
        map->view_changed = true;
    }
    if (render_data != nullptr) {
        memcpy(map->tile_layers[2] + x + (y - 1) * width, render_data->tiles[0], 4);
        memcpy(map->tile_layers[1] + x + y * width, render_data->tiles[1], 4);
        memcpy(map->tile_layers[1] + x + (y + 1) * width, render_data->tiles[2], 4);
        map->view_changed = true;
    }
    map->tile_attributes[x + y * width].unk_00_00 =
        map->tile_attributes[x + 1 + y * width].unk_00_00 =
        map->tile_attributes[x + (y + 1) * width].unk_00_00 =
        map->tile_attributes[x + 1 + (y + 1) * width].unk_00_00 = plot->method_0800A07C();
    map->tile_attributes[x + y * width].unk_02_01 =
        map->tile_attributes[x + 1 + y * width].unk_02_01 =
        map->tile_attributes[x + (y + 1) * width].unk_02_01 =
        map->tile_attributes[x + 1 + (y + 1) * width].unk_02_01 = plot->method_0800A0A4();
}

EC void func_080AA850(GameSceneSavedMapPrefix * map, u32 index)
{
    Season season = static_cast<Season>(func_0800E324(map->save->clock.calendar));
    FieldRenderPatchPlacement placement = SelectMapFlagPatch(
        map->save->unk_34D8.value, index, season == SEASON_WINTER);
    ApplyMapTilePatch(map, *placement.patch, placement.x, placement.y);
    map->view_changed = true;
}

EC void func_080AA89C(GameSceneWorldMapPrefix * map)
{
    ApplyMapTilePatch(map, gFieldRenderRectDescriptors[48], 0x21, 0x14);
    map->view_changed = true;
}

EC void func_080AA8BC(GameSceneWorldMapPrefix * map)
{
    ApplyMapTilePatch(map, gFieldRenderRectDescriptors[48], 0x21, 0x17);
    map->view_changed = true;
}

EC void func_080AA8DC(GameSceneSavedMapPrefix * map)
{
    if (map->map == MAP_FARMHOUSE)
        map->unk_98 = true;
}

