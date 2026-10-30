#ifndef SCENE_CLOCK_HH
#define SCENE_CLOCK_HH

#include "scene.hh"
#include "map_clock_status.hh"

#pragma interface "scene_clock.hh"

struct GameStateSaveImage;

// Native scene construction stores a MapClockStatusHudWidget in this slot.
struct GameSceneClockWindowOwner {
    MapClockStatusHudWidget * value;
    GameSceneClockWindowOwner() : value(nullptr) {}
    explicit GameSceneClockWindowOwner(MapClockStatusHudWidget * input) : value(input) {}
    ~GameSceneClockWindowOwner() { delete value; }
    GameSceneClockWindowOwner & operator=(MapClockStatusHudWidget * next)
    {
        if (next != value)
            delete value;
        value = next;
        return *this;
    }
};

typedef char GameSceneClockWindowOwnerSizeCheck[sizeof(GameSceneClockWindowOwner) == 4 ? 1 : -1];

struct ClockTransition : SceneTransition {
    ClockTransition(GameStateSaveImage * image, SceneTransitionOwner next)
        : save(image), continuation(next) {}
    virtual SceneOwner CreateScene();
    GameStateSaveImage * save;
    SceneTransitionOwner continuation;
};
typedef char ClockTransitionSizeCheck[sizeof(ClockTransition) == 12 ? 1 : -1];
typedef char ClockTransitionOwnerCheck[offsetof(ClockTransition, continuation) == 8 ? 1 : -1];

#endif
