#ifndef GAME_SCENE_ACTIONS_HH
#define GAME_SCENE_ACTIONS_HH

#include "prelude.h"

struct GameSceneState;

#include "game_scene_state.hh"
#include "game_state.hh"
#include <memory>

// Runtime operations share the actual song-player pool layout.
inline void GameSceneSongPlayerPool::PushBack(HardwareMusicPlayerSlot * const & value)
{
    if (end != allocation.end) {
        std::construct(end, value);
        ++end;
    } else {
        Grow(end, 1, value);
    }
}

static inline HardwareMusicPlayerSlot * FindActorSoundPlayer(GameSceneSongPlayerPool const & pool)
{
    HardwareMusicPlayerSlot ** current = pool.begin;
    HardwareMusicPlayerSlot ** end = pool.end;
    for (; current != end; ++current) {
        if (!(*current)->IsUnpaused())
            return *current;
    }
    // Native callers provide a nonempty pool; saturation reuses its last slot.
    return *(end - 1);
}


static inline void ApplyEntityLocation(GameSceneState * current, i32 entity_id,
    u32 map, i32 x, i32 y, u32 facing)
{
    if (entity_id <= ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3) {
        AActorEntity * entity = static_cast<AActorEntity *>(
            current->game_object.value->GetEntity(entity_id));
        if (entity != nullptr) {
            entity->SetLocation(ActorLocation(Location(map, x, y), facing));
            entity->SuspendNormalUpdates();
        }
    } else {
        AEntity * entity = current->game_object.value->GetEntity(entity_id);
        if (entity != nullptr) {
            entity->SetLocation(Location(map, x, y));
            entity->SuspendNormalUpdates();
        }
    }

    // Missing actors do not suppress the original player-map side effects.
    if (entity_id == ENTITY_PLAYER) {
        if (map == MAP_LIBRARY_2F)
            current->save->npcs.RecordLibrarySecondFloorVisit();

        i32 floor = 0;
        if (map >= MAP_SPRING_MINE_FLOOR_1 && map <= MAP_SPRING_MINE_FLOOR_255)
            floor = map - MAP_SPRING_MINE_FLOOR_0;
        else if (map >= MAP_LAKE_MINE_FLOOR_1 && map <= MAP_LAKE_MINE_FLOOR_255)
            floor = map - MAP_LAKE_MINE_FLOOR_0;

        if (floor > 0)
            UpdateDeepestMineFloor(current->save->farmer, floor);
    }
}

EXTERN_C

void RemoveLivestockDeadFromNeglect(GameScene * scene);
void RemoveNaturallyDeadLivestock(GameScene * scene);

// Load the controller's event script, then suspend ordinary world updates.
void StartSceneEventScript(GameSceneState * state, i32 script_id, i32 context_value);

// Location stores a ten-bit map and signed sixteen-bit coordinates. The world
// changes the map with audio enabled, then notifies the existing NPC callbacks.
void ChangeSceneMap(GameSceneState * state, u32 map, i32 x, i32 y);

// Resolve the current map through the world, then use the common entity path.
void RelocateEntityInSceneMap(GameSceneState * state, i32 entity_id,
    i32 x, i32 y, u32 facing);

EXTERN_C_END

#endif // GAME_SCENE_ACTIONS_HH
