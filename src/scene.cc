#include "scene.hh"

AScene::~AScene() {}

SceneTransition::~SceneTransition() {}

void SceneMain(SceneOwner scene)
{
    while (scene.get() != nullptr)
    {
        SceneTransitionOwner transition = scene->Run();
        scene = nullptr;
        if (transition.get() == nullptr)
            break;
        SceneOwner next = transition->CreateScene();
        scene = next;
    }
}
