#include "scene_calendar.hh"
#include "scene_calendar_core.hh"
#include <new>

CalendarScene::CalendarScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(new CalendarSceneCore(image)), continuation(next)
{
}

SceneTransitionOwner CalendarScene::Run()
{
    core.value->Run();
    return continuation;
}

// Preserve the original calendar-theme trailer after this scene's allocation.
#include FOMT_TEXT_INCLUDE(scene_calendar.cc)
