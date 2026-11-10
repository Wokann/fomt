#ifndef ENTITY_VISUAL_CONTROLLER_HH
#define ENTITY_VISUAL_CONTROLLER_HH

#include "prelude.h"

struct AEntity;
struct EntityDrawContext;

#pragma interface "entity_visual_controller.hh"

// The common actor-owned interface. Other entity controllers need not
// contain sprite members. Draw borrows the world renderer context; its
// queues, shared sprite buffer and signed camera coordinates are verified.
struct EntityVisualController {
    EntityVisualController(AEntity * owner);
    virtual ~EntityVisualController();
    virtual void Update() = 0;
    virtual void Draw(EntityDrawContext const & context) = 0;
    AEntity * entity;
};

inline EntityVisualController::EntityVisualController(AEntity * owner) : entity(owner) {}

typedef char EntityVisualControllerSizeCheck[sizeof(EntityVisualController) == 8 ? 1 : -1];
typedef char EntityVisualControllerOwnerOffset[offsetof(EntityVisualController, entity) == 0 ? 1 : -1];

#include "animal_actor_lifetimes.hh"


#endif // ENTITY_VISUAL_CONTROLLER_HH
