#ifndef ANIMAL_ACTOR_LIFETIMES_HH
#define ANIMAL_ACTOR_LIFETIMES_HH

#include "entity_visual_controller.hh"

#pragma interface "animal_actor_lifetimes.hh"

// Derived controllers inline this base cleanup. Its standalone virtual entry
// follows the horse-controller and animal cleanup entries in the native ROM.
inline EntityVisualController::~EntityVisualController()
{
}


#endif // ANIMAL_ACTOR_LIFETIMES_HH
