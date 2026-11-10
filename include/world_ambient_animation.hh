#ifndef WORLD_AMBIENT_ANIMATION_HH
#define WORLD_AMBIENT_ANIMATION_HH

#include "prelude.h"

struct WorldAmbientSprite;
struct GameObject;

EXTERN_C
i16 GetWorldAmbientSpriteAnimationStep(WorldAmbientSprite const * self);
void SetWorldAmbientSpriteAnimationStep(WorldAmbientSprite * self, i16 step);
bool WouldWorldAmbientSpriteAnimationWrap(WorldAmbientSprite const * self);
bool IsWorldAmbientSpriteAnimationPlaying(WorldAmbientSprite const * self);
void UpdateWorldAmbientSpriteAnimation(WorldAmbientSprite * self);
void SetWorldAmbientSpriteAnimation(WorldAmbientSprite * self, u32 animation);
GameObject * GetWorldAmbientSpriteWorld(WorldAmbientSprite const * self);
EXTERN_C_END

#endif // WORLD_AMBIENT_ANIMATION_HH
