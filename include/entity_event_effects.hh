#ifndef ENTITY_EVENT_EFFECTS_HH
#define ENTITY_EVENT_EFFECTS_HH

#include "scene_sprite.hh"

struct AEntity;
struct UnknownEntityThing;

// The native factory embeds a group sprite; it does not install a derived
// sunrise vtable. The meanings of +0x4C and +0x51 remain unestablished.
struct NewYearSunriseEffectState {
    GameSceneGroupSprite sprite;
    i32 unk_4C;
    u8 active;
    u8 unk_51;
};

struct NewYearSunriseEffectOwner {
    NewYearSunriseEffectState * value;

    NewYearSunriseEffectOwner & operator=(NewYearSunriseEffectState * next)
    {
        if (next != value) {
            if (value != nullptr)
                delete value;
        }
        value = next;
        return *this;
    }
};

// A borrowed view of the known prefix, not the size of the full controller.
// Native code also owns a separate sparkle collection at +0x10.
struct EntityEventEffectControllerPrefix {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    NewYearSunriseEffectOwner sunrise;

private:
    EntityEventEffectControllerPrefix();
};

typedef char NewYearSunriseEffectSizeCheck[sizeof(NewYearSunriseEffectState) == 0x54 ? 1 : -1];
typedef char NewYearSunriseEffectValueCheck[offsetof(NewYearSunriseEffectState, unk_4C) == 0x4C ? 1 : -1];
typedef char NewYearSunriseEffectActiveCheck[offsetof(NewYearSunriseEffectState, active) == 0x50 ? 1 : -1];
typedef char EntityEventEffectSunriseOffsetCheck[offsetof(EntityEventEffectControllerPrefix, sunrise) == 0x0C ? 1 : -1];

extern "C" void CreateEntityNewYearSunriseEffect(AEntity * entity);
extern "C" void PlayEntityNewYearSunriseEffect(AEntity * entity);
extern "C" bool IsEntityNewYearSunriseEffectComplete(AEntity * entity);
extern "C" void DestroyEntityNewYearSunriseEffect(AEntity * entity);
extern "C" void PlayEntityStarSparkleEffect(AEntity * entity);
extern "C" bool HasEntityStarSparkleEffect(AEntity * entity);

// Creation and the sparkle operations still use their genuine native bodies.
extern "C" void CreateControllerNewYearSunriseEffect(EntityEventEffectControllerPrefix & controller);
extern "C" void PlayControllerNewYearSunriseEffect(EntityEventEffectControllerPrefix & controller);
extern "C" bool IsControllerNewYearSunriseEffectComplete(EntityEventEffectControllerPrefix & controller);
extern "C" void DestroyControllerNewYearSunriseEffect(EntityEventEffectControllerPrefix & controller);
extern "C" void PlayControllerStarSparkleEffect(UnknownEntityThing * controller);
extern "C" bool HasControllerStarSparkleEffect(UnknownEntityThing * controller);

#endif // ENTITY_EVENT_EFFECTS_HH
