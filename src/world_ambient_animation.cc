#pragma implementation "world_ambient_sprites.hh"
#include "world_ambient_animation.hh"

asm(".include \"asm/macro.inc\"\n");

#include "world_ambient_sprites.hh"
i16 GetWorldAmbientSpriteAnimationStep(WorldAmbientSprite const * self)
{
    IndexedResourceHandle const * handle = &self->sprite.handle;
    return handle->scroll_delta;
}

void SetWorldAmbientSpriteAnimationStep(WorldAmbientSprite * self, i16 step)
{
    self->sprite.handle.SetScrollDelta(step);
}

bool WouldWorldAmbientSpriteAnimationWrap(WorldAmbientSprite const * self)
{
    return WouldIndexedResourceHandleWrap(&self->sprite.handle);
}

bool IsWorldAmbientSpriteAnimationPlaying(WorldAmbientSprite const * self)
{
    IndexedResourceHandle const * handle = &self->sprite.handle;
    bool playing = false;
    if (handle->metric_scaled != 0)
        playing = handle->scroll_delta != 0;
    return playing;
}

void UpdateWorldAmbientSpriteAnimation(WorldAmbientSprite * self)
{
    self->sprite.UpdateAnimation();
}

void SetWorldAmbientSpriteAnimation(WorldAmbientSprite * self, u32 animation)
{
    self->SetAnimation(animation);
}

GameObject * GetWorldAmbientSpriteWorld(WorldAmbientSprite const * self)
{
    return self->world;
}
