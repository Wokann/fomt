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



#endif // TOWN_MAP_SELECTION_HH
