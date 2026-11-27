#ifndef SCENE_CALENDAR_HH
#define SCENE_CALENDAR_HH

#include "scene.hh"

struct GameStateSaveImage;

struct CalendarSceneCore;

struct CalendarSceneCoreOwner {
    explicit CalendarSceneCoreOwner(CalendarSceneCore * input) : value(input) {}
    ~CalendarSceneCoreOwner();
    CalendarSceneCore * value;
};

#pragma interface "scene_calendar.hh"

#pragma interface "scene_calendar.hh"
struct CalendarScene : AScene {
    CalendarScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneTransitionOwner Run();

    CalendarSceneCoreOwner core;
    SceneTransitionOwner continuation;
};


EXTERN_C

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
CalendarScene * __13CalendarSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_calendar.hh"

// Retained calendar-theme trailer; no current direct reader is established.
extern char const gText_Calendar_FallbackNone[];


#endif // SCENE_CALENDAR_HH
