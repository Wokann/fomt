#ifndef SCENE_CLOCK_HH
#define SCENE_CLOCK_HH

#include "scene.hh"
#include "map_clock_status.hh"


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


#include "scene_clock_transition.hh"


#endif
