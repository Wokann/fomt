#include "entity_sprite.hh"

bool WouldEntitySpriteAnimationWrap(UnknownEntityThing const * sprite)
{
    return WouldIndexedResourceHandleWrap(&sprite->sprite_animator);
}

bool IsEntitySpriteAnimationPlaying(UnknownEntityThing const * sprite)
{
    IndexedResourceHandle const & animation = sprite->sprite_animator;
    bool playing = false;
    if (animation.metric_scaled != 0)
        playing = animation.scroll_delta != 0;
    return playing;
}
