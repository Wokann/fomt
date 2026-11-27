#include "world_ambient_animation.hh"

asm(".include \"asm/macro.inc\"\n");

asm_unified(
    ".text\n"
);

#include "world_ambient_sprites.hh"
i16 GetWorldAmbientSpriteAnimationStep(WorldAmbientSprite const * self)
{
    IndexedResourceHandle const * handle = &self->sprite.handle;
    return handle->scroll_delta;
}

asm_unified(
    "    .align 2, 0\n"
);

void SetWorldAmbientSpriteAnimationStep(WorldAmbientSprite * self, i16 step)
{
    self->sprite.handle.SetScrollDelta(step);
}

asm_unified(
    "    .align 2, 0\n"
);

bool WouldWorldAmbientSpriteAnimationWrap(WorldAmbientSprite const * self)
{
    return WouldIndexedResourceHandleWrap(&self->sprite.handle);
}

asm_unified(
    "    .align 2, 0\n"
);

bool IsWorldAmbientSpriteAnimationPlaying(WorldAmbientSprite const * self)
{
    IndexedResourceHandle const * handle = &self->sprite.handle;
    bool playing = false;
    if (handle->metric_scaled != 0)
        playing = handle->scroll_delta != 0;
    return playing;
}

asm_unified(
    "    .align 2, 0\n"
);

void UpdateWorldAmbientSpriteAnimation(WorldAmbientSprite * self)
{
    self->sprite.UpdateAnimation();
}

asm_unified(
    "    .align 2, 0\n"
);

void SetWorldAmbientSpriteAnimation(WorldAmbientSprite * self, u32 animation)
{
    if (self->animation != animation)
    {
        self->sprite.SetAnimation(animation);
        self->animation = animation;
    }
}

asm_unified(
    "    .align 2, 0\n"
);

GameObject * GetWorldAmbientSpriteWorld(WorldAmbientSprite const * self)
{
    return self->world;
}

asm_unified(
    "    .align 2, 0\n"
);
