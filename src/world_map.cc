#include "world_map.hh"
#include "map_patch_flags.hh"
#include "compression.hh"
#include "game_state.hh"
#include "map_data.hh"
#include "field_render_rect_descriptors.hh"
#include "field_render_resource_data.hh"
#include "hardware_dma.hh"
#include "hardware_state_accessors.hh"
#include "hardware_dma_queue.hh"
#include "time_of_day.hh"
#include "gbasvc.h"
#include "gbaio.h"
#include <string.h>
#include <algorithm>

GameSceneWorldMap::GameSceneWorldMap()
    : map(MAP_NONE), map_data_id(MAP_DATA_COUNT), x(), y(),
      tiles_changed(0), view_changed(false), time_palette_changed(false),
      tile_attributes(nullptr), tile_patch_countdown(0), movement_frames(0)
{
    for (u32 layer = 0; layer < ARRAY_COUNT(time_palette_buffers); ++layer)
        time_palette_buffers[layer] = new u16[240];
    for (u32 layer = 0; layer < ARRAY_COUNT(tile_layers); ++layer)
        tile_layers[layer] = new u16[0x3C80];
    tile_attributes = new FieldRenderTileAttributes[0x3C80];
}

GameSceneWorldMap::~GameSceneWorldMap()
{
    delete[] tile_attributes;
    for (u32 layer = 0; layer < ARRAY_COUNT(tile_layers); ++layer)
        delete[] tile_layers[layer];
    for (u32 layer = 0; layer < ARRAY_COUNT(time_palette_buffers); ++layer)
        delete[] time_palette_buffers[layer];
}

void GameSceneWorldMap::Update()
{
    GameSceneWorldMap * map = this;
    if (map->movement_frames != 0) {
        map->x.q16 += map->step_x_q16;
        map->y.q16 += map->step_y_q16;
        --map->movement_frames;
        map->view_changed = true;
    }
    // These are layout indices, not the logical MAP_* identifiers.
    switch (map->map_data_id) {
    case 14:
        map->layout_animation_4.Tick(gMapLayoutTileAnimation8);
        map->layout_animation_5.Tick(gMapLayoutTileAnimation9);
        map->layout_animation_6.Tick(gMapLayoutTileAnimation10);
        break;
    case 15:
        map->layout_animation_4.Tick(gMapLayoutTileAnimation11);
        map->layout_animation_5.Tick(gMapLayoutTileAnimation12);
        map->layout_animation_6.Tick(gMapLayoutTileAnimation13);
        break;
    case 60:
        map->layout_animation_8.Tick(gMapLayoutTileAnimation17);
        break;
    case 31:
        map->layout_animation_9.Tick(gMapLayoutTileAnimation15);
        break;
    case 8:
        map->layout_animation_7.Tick(gMapLayoutTileAnimation14);
        break;
    case 9:
        map->layout_animation_7.Tick(gMapLayoutTileAnimation16);
        break;
    case 6:
        map->layout_animation_2.Tick(gMapLayoutTileAnimation4);
        map->layout_animation_3.Tick(gMapLayoutTileAnimation5);
        break;
    case 7:
        map->layout_animation_2.Tick(gMapLayoutTileAnimation6);
        map->layout_animation_3.Tick(gMapLayoutTileAnimation7);
        break;
    case 0:
    case 62:
    case 63:
        map->layout_animation_0.Tick(gMapLayoutTileAnimation0);
        map->layout_animation_1.Tick(gMapLayoutTileAnimation2);
        break;
    case 1:
        map->layout_animation_0.Tick(gMapLayoutTileAnimation1);
        map->layout_animation_1.Tick(gMapLayoutTileAnimation3);
        break;
    }
}

bool MapViewportTilemapCommand::Run()
{
    u32 source_stride = source_width * sizeof(u16);
    volatile HardwareDmaRegisters * registers =
        reinterpret_cast<volatile HardwareDmaRegisters *>(&REG_DMA3SAD);
    for (u32 layer = 0; layer < ARRAY_COUNT(layers); ++layer) {
        u16 const * input = layers[layer].source;
        if (input != nullptr) {
            u8 const * source = reinterpret_cast<u8 const *>(input);
            u16 * destination = layers[layer].destination;
            u16 * end = destination + 32 * 21;
            do {
                WriteHardwareDmaRegisters(source, destination,
                    (static_cast<u32>(DMA_ENABLE) << 16) | 31, registers);
                source += source_stride;
                destination += 32;
            } while (destination != end);
        }
    }
    return false;
}

void GameSceneWorldMap::SetLocation(Location const & location, i32 period,
    u32 first_weight, u32 second_weight)
{
    map = location.GetMap();
    x.q16 = location.GetX() << 16;
    y.q16 = location.GetY() << 16;
    RefreshAppearance(period, first_weight, second_weight);
    SetWorldMapCameraPosition(this, location.GetX(), location.GetY());
}

void GameSceneWorldMap::RefreshAppearance(i32 period, u32 first_weight, u32 second_weight)
{
    map_data_id = SelectMapData();
    MapData const * data = GetMapData(map_data_id);
    if (data->terrain_map != nullptr && data->terrain_data != nullptr) {
        for (u32 row = 0; row < data->height; ++row) {
            for (u32 column = 0; column < data->width; ++column) {
                u32 index = column + row * data->width;
                u8 attribute = static_cast<u8 const *>(data->terrain_map)[index];
                tile_attributes[index] = static_cast<FieldRenderTileAttributes const *>(data->terrain_data)[attribute];
            }
        }
    } else {
        FieldRenderTileAttributes empty = { false, false, 0, 0, 0 };
        std::fill(tile_attributes, tile_attributes + 0x3C80, empty);
    }
    LoadTilemaps();
    SetWorldMapTimeOfDayPalette(*this, period);
    BlendTimeOfDayPalettes(first_weight, second_weight);
    tiles_changed = 1;
    layout_animation_0.ResetFrame();
    layout_animation_1.ResetFrame();
    layout_animation_2.ResetFrame();
    layout_animation_3.ResetFrame();
    layout_animation_4.ResetFrame();
    layout_animation_5.ResetFrame();
    layout_animation_6.ResetFrame();
    layout_animation_7.ResetFrame();
    layout_animation_8.ResetFrame();
    layout_animation_9.ResetFrame();
    tile_patch_countdown = 0;
}

EC Vec2 ClampWorldMapCameraPosition(GameSceneWorldMap const * map, i32 x, i32 y)
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

EC void SetWorldMapCameraPosition(GameSceneWorldMap * map, i32 x, i32 y)
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

EC void PanWorldMapCameraTo(GameSceneWorldMap * map, i32 x, i32 y, u32 speed)
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

EC bool IsWorldMapCameraMovementComplete(GameSceneWorldMap const * map)
{
    return map->movement_frames == 0;
}

EC void QueueMapTilePatch(GameSceneWorldMap *,
    FarmHouseTilePatchDescriptor const & patch, u32 frame, HardwareDmaQueue & queue)
{
    // The unused receiver and unchecked frame number preserve the native ABI.
    u8 const * data = patch.frame_data;
    MapTilePatchFrameHeader const * header = reinterpret_cast<MapTilePatchFrameHeader const *>(data);
    u32 tile_count = header->tiles_per_frame;
    data += sizeof(MapTilePatchFrameHeader);
    data += tile_count * frame * 32;
    u32 destination_tile = patch.destination_tile;
    u32 byte_count = tile_count * 32;
    DmaTransferDescriptor transfer(data,
        reinterpret_cast<void *>(0x06000000u + destination_tile * 32), byte_count);
    queue.PushBack(transfer);
}

EC void ApplyMapTilePatch(GameSceneWorldMap * map,
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

void GameSceneWorldMap::LoadTilemaps()
{
    GameSceneWorldMap & map = *this;
    MapData const * data = GetMapData(map.map_data_id);
    u32 layer = 0;
    u16 ** destination = map.tile_layers;
    for (; layer < 3; ++destination, ++layer) {
        u8 const * source = data->tilemaps[layer];
        if (source != nullptr)
            Unpack(source, *destination);
        else
            FillHardwareDma3(0x03FF03FF, *destination, static_cast<u32>(data->width) * (data->height << 1));
    }
    map.view_changed = true;
}

EC void SetWorldMapTimeOfDayPalette(GameSceneWorldMap & map, i32 period)
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

void GameSceneWorldMap::LoadTimeOfDayPalette(i32 period, u32 buffer_index)
{
    GameSceneWorldMap & map = *this;
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

void GameSceneWorldMap::LoadTiles(HardwareDmaQueue &)
{
    GameSceneWorldMap & map = *this;
    MapData const * data = GetMapData(map.map_data_id);
    Unpack(data->tiles, reinterpret_cast<void *>(0x06000000));
}

EC bool func_080A5EB8(GameSceneWorldMap * map, Location const & location)
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

EC void ClearWorldMapTileRectangle(GameSceneWorldMap * map, u32 layer,
    Vec2 const & position, u32 width, u32 height)
{
    u32 map_width = GetMapData(map->map_data_id)->width;
    for (u32 row = 0; row < height; ++row) {
        for (u32 column = 0; column < width; ++column) {
            u32 index = position.x + column + (position.y + row) * map_width;
            u16 & tile = map->tile_layers[layer][index];
            tile = 0x3FF;
            map->tile_attributes[index].unk_00_00 = false;
            map->tile_attributes[index].unk_02_01 = 0;
        }
    }
    map->view_changed = true;
}

EC void StartWorldMapTilePatchCountdown(GameSceneWorldMap * map)
{
    map->tile_patch_countdown = 0x14;
}

EC void RefreshCoopFeedTrough(GameSceneWorldMap * map, u32 index)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x24:
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22],
            gFieldRenderPatchArgumentData.values_00[index], 8);
        break;
    case 0x40:
    {
        FieldRenderRectDescriptor const & patch = gFieldRenderRectDescriptors[22];
        u8 const * coordinates = gFieldRenderPatchArgumentData.values_08;
        ApplyMapTilePatch(map, patch,
            coordinates[index], 4);
        break;
    }
    }
    map->view_changed = true;
}

EC void func_080A6138(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[0], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[0], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[0], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6194(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[1], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[1], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[1], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A61F0(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[2], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[2], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6234(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[3], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[3], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6278(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[4], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[4], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A62BC(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[5], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[5], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6300(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[8], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[8], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[8], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A635C(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[7], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[7], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[7], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A63B8(GameSceneWorldMap * map, u32 unk)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x40:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[67], 1, 0xD);
        break;
    case 0x24:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[67], 1, 0x11);
        break;
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[67], 1, unk == 0 ? 0x11 : 0xD);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

u32 GameSceneWorldMap::SelectMapData()
{
    GameSceneWorldMap const * map = this;
    return SelectMapDataId(map->map, SEASON_SUMMER, 0, 0, 0);
}

EC FieldRenderTileAttributes * GetWorldMapTileAttributes(GameSceneWorldMap * map,
    u32 x, u32 y)
{
    u32 width = GetMapData(map->map_data_id)->width;
    return &map->tile_attributes[x + y * width];
}

EC u32 GetWorldMapDataId(GameSceneWorldMap const * map)
{
    return map->map_data_id;
}

EC u32 GetWorldMapId(GameSceneWorldMap const * map)
{
    return map->map;
}

EC i32 GetWorldMapViewY(GameSceneWorldMap const * map)
{
    return map->y.parts.integer;
}

EC i32 GetWorldMapViewX(GameSceneWorldMap const * map)
{
    return map->x.parts.integer;
}

EC void UpdateSavedMapTileAnimationTimers(GameSceneSavedMapPrefix * map)
{
    map->GameSceneWorldMap::Update();
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
    GameSceneWorldMap * map, FarmHouseTilePatchAnimationDescriptor const & animation,
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
    HardwareDisplayState & display, HardwareLinkedList & commands)
{
    map->GameSceneWorldMap::Draw(queue, display, commands);
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

EC void RefreshSavedWorldMapAppearance(GameSceneSavedMapPrefix * map, i32 period,
    u32 first_weight, u32 second_weight)
{
    map->GameSceneWorldMap::RefreshAppearance(period, first_weight, second_weight);
    map->tile_animations[0].ResetFrame();
    map->tile_animations[1].ResetFrame();
}

EC void RefreshFieldPlotTiles(GameSceneWorldMap * map, u32 x, u32 y,
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
        map->tile_attributes[x + 1 + (y + 1) * width].unk_00_00 = plot->IsTerrainBlocking();
    map->tile_attributes[x + y * width].unk_02_01 =
        map->tile_attributes[x + 1 + y * width].unk_02_01 =
        map->tile_attributes[x + (y + 1) * width].unk_02_01 =
        map->tile_attributes[x + 1 + (y + 1) * width].unk_02_01 = plot->method_0800A0A4();
}

EC void RefreshWorldMapPatch(GameSceneSavedMapPrefix * map, u32 index)
{
    Season season = static_cast<Season>(GetCalendarEffectiveSeason(map->save->clock.calendar));
    FieldRenderPatchPlacement placement = SelectMapFlagPatch(
        map->save->map_patch_flags, index, season == SEASON_WINTER);
    ApplyMapTilePatch(map, *placement.patch, placement.x, placement.y);
    map->view_changed = true;
}

EC void func_080AA89C(GameSceneWorldMap * map)
{
    ApplyMapTilePatch(map, gFieldRenderRectDescriptors[34], 0x21, 0x14);
    map->view_changed = true;
}

EC void func_080AA8BC(GameSceneWorldMap * map)
{
    ApplyMapTilePatch(map, gFieldRenderRectDescriptors[34], 0x21, 0x17);
    map->view_changed = true;
}

EC void func_080AA8DC(GameSceneSavedMapPrefix * map)
{
    if (map->map == MAP_FARMHOUSE)
        map->unk_98 = true;
}

EC void ResetSavedMapTree(SavedMapTree * tree, u32 unk_00, u32 unk_04)
{
    tree->unk_00 = unk_00;
    tree->unk_04 = unk_04;
    SavedMapTreeState * state = &tree->state;
    if (state->node_count != 0) {
        EraseSavedMapTreeNodes(state, state->header->parent);
        state->header->left = state->header;
        state->header->parent = nullptr;
        state->header->right = state->header;
        state->node_count = 0;
    }
}

EC void EraseSavedMapTreeNodes(SavedMapTreeState * state, SavedMapTreeNode * node)
{
    while (node != nullptr) {
        EraseSavedMapTreeNodes(state, node->right);
        SavedMapTreeNode * left = node->left;
        if (node != nullptr)
            free(node);
        node = left;
    }
}

EC void DestroySavedWorldMap(GameSceneSavedMapPrefix * map, int flags)
{
    SavedMapTreeState * state = &map->saved_tree.state;
    if (state->node_count != 0) {
        EraseSavedMapTreeNodes(state, state->header->parent);
        state->header->left = state->header;
        state->header->parent = nullptr;
        state->header->right = state->header;
        state->node_count = 0;
    }
    if (state->header != nullptr)
        free(state->header);
    DestroyWorldMapBase(map, flags);
}
