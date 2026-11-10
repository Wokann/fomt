#include "game_scene.hh"
#include "game_scene_return.hh"

SceneOwner ReturnToGameScene::CreateScene()
{
    return SceneOwner(new GameScene(save, request));
}
