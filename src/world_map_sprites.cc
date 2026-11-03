#include "world_map_sprites.hh"
#include "game_state.hh"

EC void RefreshWorldHillSeasonalSprites(GameSceneWorld & world)
{
    world.hill_seasonal_sprites[0] = nullptr;
    world.hill_seasonal_sprites[1] = nullptr;
    if (world.vfunc_14() == MAP_MOTHERS_HILL_MIDDLE) {
        u32 season = GetCalendarEffectiveSeason(world.save->clock.calendar);
        if (season != SEASON_WINTER) {
            world.hill_seasonal_sprites[0] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 0,
                &world, 3, 0x1E, false);
            world.hill_seasonal_sprites[1] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 0,
                &world, 3, 0x1E, false);
        } else {
            world.hill_seasonal_sprites[0] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 1,
                &world, 3, 0x1E, false);
            world.hill_seasonal_sprites[1] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 1,
                &world, 3, 0x1E, false);
        }
    }
}

EC void RefreshWorldWinterAndFireplaceSprites(GameSceneWorld & world)
{
    world.winter_and_fireplace_sprites[0] = nullptr;
    world.winter_and_fireplace_sprites[1] = nullptr;
    switch (static_cast<i32>(world.vfunc_14())) {
    case MAP_SOUTH_SIDE_TOWN:
        if (world.save->unk_32) {
            world.winter_and_fireplace_sprites[1] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        if (GetCalendarEffectiveSeason(world.save->clock.calendar) == SEASON_WINTER) {
            world.winter_and_fireplace_sprites[0] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    case MAP_FOREST:
        if (GetCalendarEffectiveSeason(world.save->clock.calendar) == SEASON_WINTER) {
            world.winter_and_fireplace_sprites[0] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    case MAP_MOTHERS_HILL_MIDDLE:
        if (world.save->unk_31) {
            world.winter_and_fireplace_sprites[0] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    case MAP_FARM:
        if (world.save->farm.farm_house.IsFireplaceLighted()) {
            world.winter_and_fireplace_sprites[0] = new GameSceneIndexedSprite(world.data.GetMapSpriteArchive(), 2,
                &world, 2, 0x1F, false);
        }
        break;
    }
}
