#include "prelude.h"

#pragma implementation "player_actor.hh"
#include "player_actor.hh"

u8 PlayerActor::GetUpdateSuspended() const
{
    return update_suspended;
}

void PlayerActor::SetUpdateSuspended(u8 suspended)
{
    update_suspended = suspended;
}
