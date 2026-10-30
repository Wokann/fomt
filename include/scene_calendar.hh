#ifndef SCENE_CALENDAR_HH
#define SCENE_CALENDAR_HH

#include "game_scene.hh"
#pragma interface "scene_calendar.hh"

struct CalendarSceneCore;
struct CalendarScene : AScene {
    CalendarScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct CalendarTransition : SceneTransition {
    CalendarTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char CalendarSceneSizeCheck[sizeof(CalendarScene) == 12 ? 1 : -1];
typedef char CalendarSceneCoreCheck[offsetof(CalendarScene, core) == 4 ? 1 : -1];
typedef char CalendarSceneContinuationCheck[offsetof(CalendarScene, continuation) == 8 ? 1 : -1];
typedef char CalendarTransitionSizeCheck[sizeof(CalendarTransition) == 12 ? 1 : -1];

EXTERN_C

// The native core keeps its verified UI base prefix and opaque remaining layout.
CalendarSceneCore * ConstructCalendarSceneCore(void * object, GameStateSaveImage * image);
SceneTransitionOwner RunCalendarSceneCore(CalendarSceneCore * core);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
CalendarScene * __13CalendarSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_CALENDAR_HH
