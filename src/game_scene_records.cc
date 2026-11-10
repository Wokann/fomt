#include "game_scene_records.hh"

GameSceneControllerActorRecord::GameSceneControllerActorRecord()
    : location(Location(MAP_NONE, 0, 0), 0), animation(0), event_script(0)
{
}

GameSceneEventIconRecord::GameSceneEventIconRecord()
    : state(0), location(MAP_NONE, 0, 0)
{
}
