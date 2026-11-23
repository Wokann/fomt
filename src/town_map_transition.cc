#include "town_map_transition.hh"
#include "town_map.hh"
#include "game_scene.hh"
#include "game_scene_return.hh"
#include "game_state.hh"

SceneOwner TownMapTransition::CreateScene()
{
    bool allow_teleport = false;
    if (mode == 2)
        allow_teleport = true;
    SceneTransition * next = result.release();
    return SceneOwner(new TownMapUiScene(save, SceneTransitionOwner(next), allow_teleport));
}

SceneOwner TownMapReturnTransition::CreateScene()
{
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_TOWN_MAP);
    switch (mode) {
    case 0:
        request = GameSceneResumeRequest(1);
        break;
    case 1:
        // This other native mode has its own regional resume kind.
#if defined(REGION_JP)
        request = GameSceneResumeRequest(4);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
        request = GameSceneResumeRequest(5);
#endif
        break;
    case 2:
        request.town_map_selection.has_selection = has_selection;
        if (has_selection) {
            request.town_map_selection.map = location.map;
            request.town_map_selection.x = location.x;
            request.town_map_selection.y = location.y;
        }
        break;
    }
    return SceneOwner(new GameScene(save, request));
}
