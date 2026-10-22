#include "entity_event_effects.hh"

#include "entity.hh"

extern "C" void CreateEntityNewYearSunriseEffect(AEntity * entity)
{
    UnknownEntityThing * controller = entity->unk_10.Get();
    if (controller != nullptr)
        CreateControllerNewYearSunriseEffect(reinterpret_cast<EntityEventEffectControllerPrefix &>(*controller));
}

extern "C" void PlayEntityNewYearSunriseEffect(AEntity * entity)
{
    UnknownEntityThing * controller = entity->unk_10.Get();
    if (controller != nullptr)
        PlayControllerNewYearSunriseEffect(reinterpret_cast<EntityEventEffectControllerPrefix &>(*controller));
}

extern "C" bool IsEntityNewYearSunriseEffectComplete(AEntity * entity)
{
    UnknownEntityThing * controller = entity->unk_10.Get();
    if (controller != nullptr)
        return IsControllerNewYearSunriseEffectComplete(reinterpret_cast<EntityEventEffectControllerPrefix &>(*controller));
    return true;
}

extern "C" void DestroyEntityNewYearSunriseEffect(AEntity * entity)
{
    UnknownEntityThing * controller = entity->unk_10.Get();
    if (controller != nullptr)
        DestroyControllerNewYearSunriseEffect(reinterpret_cast<EntityEventEffectControllerPrefix &>(*controller));
}

extern "C" void PlayEntityStarSparkleEffect(AEntity * entity)
{
    UnknownEntityThing * controller = entity->unk_10.Get();
    if (controller != nullptr)
        PlayControllerStarSparkleEffect(controller);
}

extern "C" bool HasEntityStarSparkleEffect(AEntity * entity)
{
    UnknownEntityThing * controller = entity->unk_10.Get();
    if (controller != nullptr)
        return HasControllerStarSparkleEffect(controller);
    return false;
}

extern "C" void PlayControllerNewYearSunriseEffect(EntityEventEffectControllerPrefix & controller)
{
    NewYearSunriseEffectState * effect = controller.sunrise.value;
    effect->unk_4C = 288 << 16;
    effect->active = 1;
}

extern "C" bool IsControllerNewYearSunriseEffectComplete(EntityEventEffectControllerPrefix & controller)
{
    NewYearSunriseEffectState * effect = controller.sunrise.value;
    return effect->active == 0;
}

extern "C" void DestroyControllerNewYearSunriseEffect(EntityEventEffectControllerPrefix & controller)
{
    controller.sunrise = nullptr;
}
