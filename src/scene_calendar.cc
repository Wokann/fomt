#include "prelude.h"
#pragma implementation "scene_calendar.hh"
#include "scene_calendar.hh"

void GameScene::OpenCalendar()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CALENDAR);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CalendarTransition(continuation, current->save);
    current->script_state = 0x18;
}

CalendarScene::CalendarScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructCalendarSceneCore(
          ::operator new(0x228), image))), continuation(next)
{
}

SceneTransitionOwner CalendarScene::Run()
{
    RunCalendarSceneCore(reinterpret_cast<CalendarSceneCore *>(core.value));
    return continuation;
}

SceneOwner CalendarTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__13CalendarSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(CalendarScene)), &next, save));
}
