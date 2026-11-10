#ifndef FARMING_TUTORIAL_TRANSITION_HH
#define FARMING_TUTORIAL_TRANSITION_HH

#include "scene.hh"
#include "fomt_constants.hh"

#pragma interface "farming_tutorial_transition.hh"

// Crops and animal-care tutorials run in this dedicated script host.
// Both entry paths transfer their continuation and one complete kind word.
struct FarmingTutorialTransition : SceneTransition {
    FarmingTutorialTransition(SceneTransitionOwner next, MaryFarmingTutorialKind value);
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    MaryFarmingTutorialKind kind;
};


#endif // FARMING_TUTORIAL_TRANSITION_HH
