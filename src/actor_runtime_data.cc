#include "actor_runtime_data.hh"

Unk_Actor_0809BFE8::Unk_Actor_0809BFE8()
    : Actor(ActorLocation(Location(MAP_NONE, 0, 0), 0)), unk_08_0(100), behavior_state(WILD_DOG_STATE_INACTIVE)
{
}

extern "C" unsigned int func_0809C060(Unk_Actor_0809BFE8 const & self)
{
    return self.unk_08_0;
}

extern "C" void func_0809C068(Unk_Actor_0809BFE8 & self, int arg_0)
{
    int val = self.unk_08_0 - arg_0;

    if (val < 0)
        val = 0;
    else if (val > 100)
        val = 100;

    self.unk_08_0 = val;
}

extern "C" void SetWildDogInactiveState(Unk_Actor_0809BFE8 & self, u32 const &)
{
    self.behavior_state = WILD_DOG_STATE_INACTIVE;
}

extern "C" void SetWildDogDepartureState(Unk_Actor_0809BFE8 & self, WildDogDeparturePayload const & value)
{
    self.unk_10 = value.raw;
    self.behavior_state = WILD_DOG_STATE_DEPARTURE;
}

extern "C" void SetWildDogChaseState(Unk_Actor_0809BFE8 & self, WildDogChaseState const & value)
{
    self.chase = value;
    self.behavior_state = WILD_DOG_STATE_CHASE;
}

extern "C" void SetWildDogAttackState(Unk_Actor_0809BFE8 & self, WildDogAttackPayload const & value)
{
    self.unk_10 = value.raw;
    self.behavior_state = WILD_DOG_STATE_ATTACK;
}

extern "C" void SetWildDogReactionState(Unk_Actor_0809BFE8 & self, AnimalReactionPayload const & value)
{
    self.unk_10 = value.raw;
    self.behavior_state = WILD_DOG_STATE_REACTION;
}

extern "C" void ResetActorRuntimeState(Unk_Actor_0809BFE8 & self)
{
    ActorLocation const location(Location(MAP_NONE, 0, 0), 0);
    u32 unused;

    self.SetLocation(location);
    SetWildDogInactiveState(self, unused);
    self.unk_08_0 = 100;
}
