#include "world_map_sprites.hh"
#include "game_state.hh"

EC void RefreshWorldHillSeasonalSprites(GameSceneWorldPrefix & world)
{
    world.unk_106C = nullptr;
    world.unk_1070 = nullptr;
    if (world.vfunc_14() == MAP_MOTHERS_HILL_MIDDLE) {
        u32 season = func_0800E324(world.save->clock.calendar);
        if (season != SEASON_WINTER) {
            world.unk_106C = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 0,
                &world, 3, 0x1E, false);
            world.unk_1070 = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 0,
                &world, 3, 0x1E, false);
        } else {
            world.unk_106C = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 1,
                &world, 3, 0x1E, false);
            world.unk_1070 = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 1,
                &world, 3, 0x1E, false);
        }
    }
}

EC void RefreshWorldWinterAndFireplaceSprites(GameSceneWorldPrefix & world)
{
    world.unk_1074 = nullptr;
    world.unk_1078 = nullptr;
    switch (static_cast<i32>(world.vfunc_14())) {
    case MAP_SOUTH_SIDE_TOWN:
        if (world.save->unk_32) {
            world.unk_1078 = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        if (func_0800E324(world.save->clock.calendar) == SEASON_WINTER) {
            world.unk_1074 = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    case MAP_FOREST:
        if (func_0800E324(world.save->clock.calendar) == SEASON_WINTER) {
            world.unk_1074 = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    case MAP_MOTHERS_HILL_MIDDLE:
        if (world.save->unk_31) {
            world.unk_1074 = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    case MAP_FARM:
        if (world.save->farm.farm_house.IsFireplaceLighted()) {
            world.unk_1074 = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    }
}
