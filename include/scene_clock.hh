#ifndef SCENE_CLOCK_HH
#define SCENE_CLOCK_HH

#include "map_clock_status.hh"

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

#endif
