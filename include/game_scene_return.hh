#ifndef GAME_SCENE_RETURN_HH
#define GAME_SCENE_RETURN_HH

#include "game_scene.hh"

struct GameStateSaveImage;

#pragma interface "game_scene_return.hh"

struct ReturnToGameScene : SceneTransition {
    ReturnToGameScene(GameStateSaveImage * image, GameSceneResumeRequest value);
    void SetGameCubeLinkResult(MaryGameCubeLinkResult value);
    void SetHarvestSpriteMinigameResult(bool value);
    virtual SceneOwner CreateScene();

    GameStateSaveImage * save;
    GameSceneResumeRequest request;
};

typedef char ReturnToGameSceneSizeCheck[sizeof(ReturnToGameScene) == 20 ? 1 : -1];
typedef char ReturnToGameSceneRequestCheck[offsetof(ReturnToGameScene, request) == 8 ? 1 : -1];

#pragma interface "game_scene.hh"

inline ReturnToGameScene::ReturnToGameScene(GameStateSaveImage * image, GameSceneResumeRequest value)
    : save(image), request(value) {}

inline void ReturnToGameScene::SetGameCubeLinkResult(MaryGameCubeLinkResult value)
{
    request.gamecube_link_result = value;
}

inline void ReturnToGameScene::SetHarvestSpriteMinigameResult(bool value)
{
    request.harvest_sprite_minigame_succeeded = value;
}


#endif // GAME_SCENE_RETURN_HH
