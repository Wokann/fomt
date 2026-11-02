#include "prelude.h"
#include "new_game.hh"
#include <new>
#include <string.h>
#include "hardware_blend.hh"
#include "hardware_manager.hh"
#include "hardware_dma.hh"
#include "hardware_bootstrap.hh"
#include "hardware_nested_accessors.hh"
#include "game_state.hh"
#include "field_item_data.hh"
#include "field_render_rect_descriptors.hh"
#include "field_render_farm_house_data.hh"
#include "field_render_resource_data.hh"
#include "map_patch_flags.hh"
#include "entity_actor.hh"
#include "npc_entity.hh"
#include "entity_ui.hh"
#include "fomt_constants.hh"
#if defined(REGION_JP)
#include "data/scripts/jp/fomt_scripts.mary.h"
#elif defined(REGION_US)
#include "data/scripts/us/fomt_scripts.mary.h"
#elif defined(REGION_EU)
#include "data/scripts/eu/fomt_scripts.mary.h"
#else
#include "data/scripts/de/fomt_scripts.mary.h"
#endif
#include "hardware_music_player.hh"
#include "hardware_song.hh"
#include "script_engine.hh"
#include "font.hh"
#include "gbasvc.h"
#include "gbaio.h"
#include <iterator>

#pragma implementation "game_world.hh"
#include "game_world.hh"
#include "world_audio.hh"
#include "game_scene.hh"

EC u32 func_0801740C(FieldPlot const & plot)
{
    switch (plot.GetUnk2()) {
    case 0x1B:
    case 0x1F:
    case 0x23:
    default:
        return 0;
    case 0x1C:
    case 0x20:
    case 0x24:
        return 1;
    case 0x1D:
    case 0x21:
    case 0x25:
        return 2;
    case 0x1E:
    case 0x22:
    case 0x26:
        return 3;
    }
}

EC u32 func_0801746C(FieldPlot const & plot)
{
    switch (plot.GetUnk2()) {
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    default:
        return 0;
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
        return 1;
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
        return 2;
    }
}

EC bool func_080174C8(Farm & farm, FieldItemState & items, u32 index, i32 season,
    i32 power, bool hammer, GameSceneFieldItemToolResult & result)
{
    FieldItemInstance const & record = items.GetRecord(index);
    i32 minimum = 0;
    i32 remaining;
    if (hammer) {
        switch (record.kind) {
        case 0x13: minimum = 2; break;
        case 0x14: minimum = 7; break;
        default: goto failure;
        }
    } else {
        switch (record.kind) {
        case 0x12: break;
        case 0x15: minimum = 1; break;
        default: goto failure;
        }
    }

    // A valid target is accepted even if this hit does not remove it.
    result.rejected = false;
    remaining = power - minimum;
    if (remaining <= 0)
        goto failure;
    if (record.kind != 0x12)
        items.DecreaseResourceValue(index, remaining);
    if (record.kind != 0x12 && items.GetResourceValue(index) != 0)
        goto failure;

    items.ClearAvailability(index, season);
    result.removed = true;
    result.x = record.x;
    result.y = record.y;
    switch (record.kind) {
    case 0x15:
        farm.method_08009B68(6);
        result.kind = 7;
        break;
    case 0x12:
        farm.method_08009B68(1);
        result.kind = 4;
        break;
    case 0x13:
        result.kind = 6;
        break;
    case 0x14:
        result.kind = 9;
        break;
    }
    return true;
failure:
    return false;
}

EC bool func_08019F38(GameSceneWorld & world, Location const & location)
{
    if (GetMapData(world.data.map.value->map_data_id)->flags != 0
        || (GetCalendarEffectiveSeason(world.save->clock.calendar) != SEASON_WINTER
            && !func_080A5EB8(world.data.map.value, location)))
        return false;
    return true;
}

EC i32 GetWorldMapPixelWidth(GameSceneWorld & world, u32 map)
{
    u32 season = GetCalendarEffectiveSeason(world.save->clock.calendar);
    u32 house = world.save->farm.farm_house.GetUpgradeLevel();
    u32 coop = world.save->farm.coop.GetUpgradeLevel();
    u32 barn = world.save->farm.barn.GetUpgradeLevel();
    u32 data_id = SelectMapDataId(map, season, house, coop, barn);
    return GetMapData(data_id)->width * 8;
}

EC i32 GetWorldMapPixelHeight(GameSceneWorld & world, u32 map)
{
    u32 season = GetCalendarEffectiveSeason(world.save->clock.calendar);
    u32 house = world.save->farm.farm_house.GetUpgradeLevel();
    u32 coop = world.save->farm.coop.GetUpgradeLevel();
    u32 barn = world.save->farm.barn.GetUpgradeLevel();
    u32 data_id = SelectMapDataId(map, season, house, coop, barn);
    return GetMapData(data_id)->height * 8;
}

EC MapTerrainView GetWorldMapTerrain(GameSceneWorld & world, u32 map_id)
{
    if (map_id > MAP_LAKE_MINE_FLOOR_255)
        return MapTerrainView(nullptr, 0, 0);
    u32 current_map = world.data.map.value->map;
    if (map_id == MAP_FARM && current_map != MAP_FARM)
        return MapTerrainView(world.farm_tile_attributes, 128, 88);

    u32 data_id;
    if (current_map == map_id) {
        data_id = world.data.map.value->map_data_id;
    } else {
        u32 season = GetCalendarEffectiveSeason(world.save->clock.calendar);
        u32 house = world.save->farm.farm_house.GetUpgradeLevel();
        u32 coop = world.save->farm.coop.GetUpgradeLevel();
        u32 barn = world.save->farm.barn.GetUpgradeLevel();
        data_id = SelectMapDataId(map_id, season, house, coop, barn);
    }
    MapData const * data = GetMapData(data_id);
    u32 width = data->width;
    u32 height = data->height;
    FieldRenderTileAttributes const * attributes;
    u8 const * indices;
    if (current_map == map_id) {
        GameSceneWorldMap * active = world.data.map.value;
        // The native branch performs this lookup even though its result is unused.
        GetMapData(active->map_data_id);
        indices = nullptr;
        attributes = active->tile_attributes;
    } else {
        indices = static_cast<u8 const *>(data->terrain_map);
        attributes = static_cast<FieldRenderTileAttributes const *>(data->terrain_data);
    }
    return MapTerrainView(attributes, indices, width, height);
}

EC u32 func_0801B5C0(GameSceneWorld & world, i32 kind)
{
    switch (kind) {
    case 0: return 0;
    case 1:
    case 2:
    case 4: return 1;
    case 3:
    case 5: return 2;
    case 14: return 3;
    case 15:
    case 16:
    case 17:
    case 18: return 4;
    case 6:
    case 7:
    case 8:
    case 26: return 5;
    }

    u32 first = 6;
    switch (world.vfunc_14()) {
    case MAP_FARM:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 12: return 10;
        case 13: return 11;
        case 19:
        case 21:
        case 22: return 7;
        case 20:
        case 23:
        case 25: return 8;
        case 24: return 9;
        default: first = 12;
        }
        break;
    case MAP_HARVEST_SPRITES_HUT:
        switch (kind) {
        case 19:
        case 21:
        case 22: return 6;
        case 20:
        case 23:
        case 25: return 7;
        case 24: return 8;
        default: first = 9;
        }
        break;
    case MAP_BARN:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 12: return 10;
        case 19:
        case 21:
        case 22: return 7;
        case 20:
        case 23:
        case 25: return 8;
        case 24: return 9;
        default: first = 11;
        }
        break;
    case MAP_CHICKEN_COOP:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 19:
        case 21:
        case 22: return 7;
        case 20:
        case 23:
        case 25: return 8;
        case 24: return 9;
        default: first = 10;
        }
        break;
    case MAP_HORSE_STABLE:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 13: return 7;
        default: first = 8;
        }
        break;
    case MAP_FARMHOUSE:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        default: first = 7;
        }
        break;
    case MAP_SOUTH_SIDE_TOWN:
        switch (kind) {
        case 9:
        case 10:
        case 11: return 6;
        case 12: return 7;
        case 31: return 8;
        default: first = 9;
        }
        break;
    case MAP_MOTHERS_HILL_SUMMIT: {
        if (kind == 29)
            return 6;
        first = 7;
        u32 wish_state = world.save->event_state.shooting_star_wish_event_state;
        if (wish_state == 1) {
            if (kind == 28)
                return 7;
            first = 8;
        }
        break;
    }
    case MAP_CHURCH:
        if (world.save->event_state.IsActiveRomanceEvent(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE)) {
            switch (kind) {
            case 19:
            case 21:
            case 22: return 6;
            case 20:
            case 23:
            case 25: return 7;
            case 24: return 8;
            default: first = 9;
            }
        }
        break;
    case MAP_MOTHERS_HILL_MIDDLE:
        if (kind == 30)
            return 6;
        first = 7;
        break;
    case MAP_KAI_RESTAURANT: {
        GameEventState const & events = world.save->event_state;
        u32 cafe_state = events.popuri_brings_customers_to_kais_beach_cafe_event_state;
        if (cafe_state == 1) {
            switch (kind) {
            case 19:
            case 21:
            case 22: return 6;
            case 20:
            case 23:
            case 25: return 7;
            case 24: return 8;
            default: first = 9;
            }
        }
        break;
    }
    case MAP_ROSE_SQUARE:
        if (kind == 32)
            return 6;
        first = 7;
        break;
    case MAP_MINERAL_BEACH:
    case MAP_FOREST:
    case MAP_BEHIND_CHURCH:
    case MAP_NORTH_SIDE_TOWN:
    case MAP_POULTRY_FARM_HOUSE_1F:
    case MAP_POULTRY_FARM_HOUSE_2F:
    case MAP_ZACK_HOUSE:
    case MAP_ELLEN_HOUSE:
    case MAP_SUPERMARKET:
    case MAP_SUPERMARKET_BACK_ROOM:
    case MAP_MOUNTAIN_COTTAGE:
    case MAP_MINERAL_CLINIC_1F:
    case MAP_MINERAL_CLINIC_2F:
    case MAP_INN_1F:
    case MAP_INN_BACK_ROOM:
    case MAP_INN_2F:
    case MAP_LIBRARY_1F:
    case MAP_LIBRARY_2F:
    case MAP_BASIL_HOUSE_1F:
    case MAP_BASIL_HOUSE_2F:
    case MAP_MAYOR_HOUSE:
    case MAP_AJA_WINERY_1F:
    case MAP_AJA_WINERY_2F:
    case MAP_AJA_WINERY_STORAGE_1F:
    case MAP_AJA_WINERY_STORAGE_B1F:
    case MAP_BEACH_HOUSE:
    case MAP_BLACKSMITH:
    case MAP_TOWN_COTTAGE:
    case MAP_GOTZ_HOUSE:
    case MAP_YODEL_RANCH_HOUSE_1F:
    case MAP_YODEL_RANCH_HOUSE_2F:
    case MAP_LAKE_MINE_ENTRANCE:
    case MAP_MOTHERS_HILL_SUMMIT_CLEAR:
    case MAP_MOTHERS_HILL_SUMMIT_RAIN:
    case MAP_MOTHERS_HILL_SUMMIT_SNOW:
    case MAP_TUTORIAL_FIELD:
        break;
    }
    GameScenePaletteCache & cache = world.data.palette_cache;
    for (u32 index = first; index < cache.ResourceCount(); ++index) {
        GameScenePaletteResource & resource = cache.resources[index];
        if (resource.unk_81 == 0) {
            resource.unk_81 = 1;
            return index;
        }
    }
    return ARRAY_COUNT(cache.resources) - 1;
}

EC void SetWorldPendingUnknownValue(GameSceneWorld & world, u8 value)
{
    world.unk_10C8 = 1;
    world.unk_10C9 = value;
}

EC bool TryGetFarmPlotAtLocation(GameSceneWorld & world, Location const & location,
    GameSceneFarmPlotLocation & output)
{
    // Each farm plot spans two 8-pixel tiles from the field origin.
    u32 first_x = 34;
    u32 first_y = 22;
    bool found = false;
    if (location.GetMap() == MAP_FARM) {
        u32 x = location.GetX() / 8;
        u32 y = location.GetY() / 8;
        if (x >= first_x && y >= first_y &&
            x <= first_x + Farm::FIELD_WIDTH * 2 - 1 &&
            y <= first_y + Farm::FIELD_HEIGHT * 2 - 1) {
            u32 column = (x - first_x) / 2;
            u32 row = (y - first_y) / 2;
            output.plot = &world.save->farm.field.PlotAt(column, row);
            output.tile_x = column * 2 + first_x;
            output.tile_y = row * 2 + first_y;
            output.column = column;
            output.row = row;
            found = true;
        }
    }
    return found;
}

EC u32 func_0801C29C(GameSceneWorld & world, Location const & location)
{
    u32 result = 0;
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        result = hit.plot->method_0800A190(world.save->clock.weather_today == WEATHER_SUNNY);
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMap * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
        if (result == 3) {
            for (u32 index = 0; index < ARRAY_COUNT(world.unk_1080); ++index) {
                if (world.unk_1080[index].state == 0) {
                    world.unk_1080[index].state = 2;
                    world.unk_1080[index].tile_x = hit.tile_x;
                    world.unk_1080[index].tile_y = hit.tile_y;
                    break;
                }
            }
        }
    }
    return result;
}

EC u32 func_0801D3FC(GameSceneWorld & world, Location const & location)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        u32 result = hit.plot->method_0800A438();
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMap * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
        if (result == 1)
            return 1;
    }
    return 0;
}

EC void func_0801D4E0(GameSceneWorld & world, Location const & location, i32 id)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        hit.plot->method_0800A460(id);
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMap * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
    }
}

EC void func_0801D5BC(GameSceneWorld & world, Location const & location,
    RucksackItem & output)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        output = hit.plot->method_0800A4A4();
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMap * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
    } else {
        output = PickUpFieldItemAtLocation(world, location);
    }
}

EC RucksackItem PickUpFieldItemAtLocation(GameSceneWorld & world, Location const & location)
{
    FieldItemState & items = world.save->field_items;
    i32 season = GetCalendarEffectiveSeason(world.save->clock.calendar);
    Box area(location.GetX(), location.GetY(), 1, 1);
    i32 index = items.Find(location.GetMap(), area, season);
    RucksackItem item;
    if (index != -1) {
        item = items.PickUp(location.GetMap(), area, season);
        if (!item.IsEmpty() && location.GetMap() == world.data.map.value->map) {
            FieldItemInstance record = items.GetRecord(index);
            GameSceneWorldMap * map = world.data.map.value;
            Vec2 position(record.x / 8, record.y / 8);
            ClearWorldMapTileRectangle(map, 1, position, 2, 2);
        }
    }
    return item;
}

EC void func_0801D7B0(GameSceneWorld & world, Location const & location,
    Article const & article)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        hit.plot->method_0800A6F4(article);
        if (world.vfunc_14() == location.GetMap()) {
            GameSceneWorldMap * map = world.data.map.value;
            FieldPlotRenderData const * render_data =
                world.save->farm.field.PlotRenderDataAt(hit.column, hit.row);
            RefreshFieldPlotTiles(map, hit.tile_x, hit.tile_y, hit.plot, render_data);
        }
    }
}

EC u32 func_0801D88C(GameSceneWorld & world, Location const & location,
    Article const & article)
{
    GameSceneFarmPlotLocation hit;
    if (TryGetFarmPlotAtLocation(world, location, hit)) {
        if (hit.plot->method_0800A6C8(article))
            return 0;
        return 1;
    }
    return 2;
}

EC void QueueWorldScript(GameSceneWorld & world,
    GameSceneScriptRequest const & request, i32 queue_kind)
{
    world.scene->QueueScript(request, queue_kind);
}

EC void func_0801DC24(GameSceneWorld & world, u32 index)
{
    GameSceneIndexedSprite * sprite = world.unk_1058.Get();
    if (sprite != nullptr) {
        ResolveIndexedResourceHandle(&sprite->handle, index);
        sprite->unk_3C = 1;
        sprite->unk_3E = 0;
        sprite->unk_3F = 1;
    } else {
        world.unk_1058 = new GameSceneIndexedSprite(
            reinterpret_cast<IndexedResourceProvider *>(world.vfunc_5C()),
            index, &world, 3, 0x1B, true);
    }
}

EC void func_0801DCA8(GameSceneWorld & world)
{
    world.unk_1058 = nullptr;
}

EC void CollectDailyShippingRevenue(GameSceneWorld & world)
{
    i32 value = world.save->farm.shipping_bin.GetValueShipped();
    world.save->CollectShippingRevenue();
    world.QueueScript(GameSceneScriptRequest(
        EventScript_FarmEvent_Zack_DailyShippingPickup, value), 1);
}

EC void func_0801DD18(GameSceneWorld & world)
{
    func_080A6138(world.data.map.value);
}

EC void func_0801DD24(GameSceneWorld & world)
{
    func_080A6194(world.data.map.value);
}

EC void func_0801DD30(GameSceneWorld & world)
{
    func_080A61F0(world.data.map.value);
}

EC void func_0801DD3C(GameSceneWorld & world)
{
    func_080A6234(world.data.map.value);
}

EC void func_0801DD48(GameSceneWorld & world)
{
    func_080A6278(world.data.map.value);
}

EC void func_0801DD54(GameSceneWorld & world)
{
    func_080A62BC(world.data.map.value);
}

EC void func_0801DD60(GameSceneWorld & world, u32 index)
{
    func_080A607C(world.data.map.value, index);
}

EC void func_0801DD6C(GameSceneWorld & world, u32 index)
{
    RefreshCoopFeedTrough(world.data.map.value, index);
}

EC void func_0801DD78(GameSceneWorld & world)
{
    StartWorldMapTilePatchCountdown(world.data.map.value);
}

EC MaryItemArticleId RemoveRecordPlayerAlbum(GameSceneWorld & world)
{
    RecordPlayer * record_player = world.save->farm.farm_house.GetRecordPlayer();
    func_080A6300(world.data.map.value);
    ArticleStack album = record_player->RemoveAlbum();
    UpdateWorldBackgroundAudio(world);
    return static_cast<MaryItemArticleId>(album.GetArticle().GetId());
}

EC void SetWorldMapPatchFlag(GameSceneWorld & world, u32 index)
{
    world.save->map_patch_flags.Set(index);
    RefreshWorldMapPatch(static_cast<GameSceneSavedMap *>(world.data.map.value), index);
}

EC void ClearWorldMapPatchFlag(GameSceneWorld & world, u32 index)
{
    world.save->map_patch_flags.Clear(index);
    RefreshWorldMapPatch(static_cast<GameSceneSavedMap *>(world.data.map.value), index);
}

EC void func_0801DE24(GameSceneWorld & world, u32 unk)
{
    func_080A63B8(world.data.map.value, unk);
}

EC void func_0801DE30(GameSceneWorld & world)
{
    func_080AA89C(world.data.map.value);
}

EC void func_0801DE3C(GameSceneWorld & world)
{
    func_080AA8BC(world.data.map.value);
}

EC void func_0801DE48(GameSceneWorld & world)
{
    func_080AA8DC(static_cast<GameSceneSavedMap *>(world.data.map.value));
}

EC MaryItemArticleId SwapRecordPlayerAlbum(GameSceneWorld & world, MaryItemArticleId article_id)
{
    RecordPlayer * record_player = world.save->farm.farm_house.GetRecordPlayer();
    func_080A635C(world.data.map.value);
    ArticleStack album = record_player->SetAlbum(Article(article_id));
    UpdateWorldBackgroundAudio(world);
    return static_cast<MaryItemArticleId>(album.GetArticle().GetId());
}

EC AEntity * GetWorldEntity(GameObject * world, u32 id)
{
    return world->GetEntity(id);
}

EC AEntity * GetWorldEntityConst(GameObject const * world, u32 id)
{
    return world->GetEntity(id);
}

EC IndexedResourceArchive * func_0801FBDC(GameSceneWorld & world)
{
    return &world.data.unk_FF0;
}

EC IndexedResourceArchive * func_0801FBE8(GameSceneWorld & world)
{
    return &world.data.unk_FC0;
}

EC IndexedResourceArchive * func_0801FBF4(GameSceneWorld & world)
{
    return &world.data.unk_F90;
}

EC IndexedResourceArchive * func_0801FC00(GameSceneWorld & world)
{
    return &world.data.unk_F60;
}

EC IndexedResourceArchive * func_0801FC0C(GameSceneWorld & world)
{
    return &world.data.unk_F30;
}

EC IndexedResourceArchive * GetWorldMapSpriteArchive(GameSceneWorld & world)
{
    return world.data.GetMapSpriteArchive();
}

EC IndexedResourceArchive * func_0801FC24(GameSceneWorld & world)
{
    return &world.data.unk_ED0;
}

EC IndexedResourceArchive * func_0801FC30(GameSceneWorld & world)
{
    return &world.data.unk_EA0;
}

EC IndexedResourceArchive * func_0801FC3C(GameSceneWorld & world)
{
    return &world.data.unk_E70;
}

EC IndexedResourceArchive * func_0801FC48(GameSceneWorld & world)
{
    return &world.data.unk_E40;
}

EC IndexedResourceArchive * func_0801FC54(GameSceneWorld & world)
{
    return &world.data.unk_E10;
}

EC IndexedResourceArchive * func_0801FC60(GameSceneWorld & world)
{
    return &world.data.unk_DE0;
}

EC IndexedResourceArchive * GetWorldActorAnimationArchive(GameSceneWorld & world)
{
    return &world.data.actor_archive;
}

EC GameSceneWorldMap * func_0801FC9C(GameSceneWorld & world)
{
    return world.data.map.value;
}

EC GameSceneWorldMap * func_0801FCA0(GameSceneWorld & world)
{
    return world.data.map.value;
}

EC GameStateClock const * GetWorldClock(GameSceneWorld const & world)
{
    return &world.save->clock;
}

AEntity * GameSceneWorld::GetEntity(u32 index) const
{
    AEntity * const * first = data.entities;
    std::advance(first, index);
    return *first;
}

AEntity * GameSceneWorld::GetEntity(u32 index)
{
    AEntity ** first = data.entities;
    std::advance(first, index);
    return *first;
}

EC void RemoveWorldEntity(GameSceneWorld & world, u32 index)
{
    AEntity ** entity = world.data.entities;
    std::advance(entity, index);
    if (*entity != nullptr) {
        delete *entity;
        *entity = nullptr;
    }
}

EC EntityAuxiliarySprites * GetWorldEntityAuxiliarySprites(GameSceneWorld & world)
{
    return world.data.entity_auxiliary_sprites;
}

EC bool IsWorldCameraMovementComplete(GameSceneWorld const & world)
{
    return IsWorldMapCameraMovementComplete(world.data.map.value);
}

EC i32 GetWorldCameraY(GameSceneWorld const & world)
{
    return world.data.map.value->y.parts.integer;
}

EC i32 GetWorldCameraX(GameSceneWorld const & world)
{
    return world.data.map.value->x.parts.integer;
}

EC u32 GetWorldCurrentMapId(GameSceneWorld const & world)
{
    return world.data.map.value->map;
}

EC void PanWorldCameraTo(GameSceneWorld & world, i32 x, i32 y, u32 speed)
{
    PanWorldMapCameraTo(world.data.map.value, x, y, speed);
}

EC void SetWorldCameraPosition(GameSceneWorld & world, i32 x, i32 y)
{
    SetWorldMapCameraPosition(world.data.map.value, x, y);
}
