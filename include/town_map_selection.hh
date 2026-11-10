#ifndef TOWN_MAP_SELECTION_HH
#define TOWN_MAP_SELECTION_HH

#include "scene.hh"
#include "actor.hh"

#pragma interface "town_map_selection.hh"

struct TownMapSelectionTransition : SceneTransition {
    inline TownMapSelectionTransition();
    bool has_selection;
    Location location;
};

typedef char TownMapSelectionTransitionSizeCheck[sizeof(TownMapSelectionTransition) == 12 ? 1 : -1];
typedef char TownMapSelectionTransitionFlagCheck[offsetof(TownMapSelectionTransition, has_selection) == 4 ? 1 : -1];
typedef char TownMapSelectionTransitionLocationCheck[offsetof(TownMapSelectionTransition, location) == 6 ? 1 : -1];


#endif // TOWN_MAP_SELECTION_HH
