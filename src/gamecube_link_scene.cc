#include "gamecube_link_scene.hh"
#include "scene_gamecube_link.hh"
#include "game_scene_return.hh"
#include "game_state.hh"

SceneTransitionOwner GameCubeLinkScene::Run()
{
    GameCubeLinkUiScene ui(SceneTransitionOwner(nullptr), save);
    ui.Run();
    static_cast<ReturnToGameScene *>(continuation.get())->SetGameCubeLinkResult(ui.GetResult());
    return SceneTransitionOwner(continuation.release());
}
