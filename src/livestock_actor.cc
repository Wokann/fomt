#include "livestock.hh"

#pragma implementation "livestock_actor.hh"
#include "livestock_actor.hh"

bool ChickenActor::IsSick() const
{
    return livestock->IsSick();
}

void ChickenActor::CureSickness()
{
    livestock->ResetSick();
    if (livestock->IsUnhappy())
        livestock->ResetUnhappy();
}

bool CowActor::IsSick() const
{
    return livestock->IsSick();
}

void CowActor::CureSickness()
{
    livestock->ResetSick();
    if (livestock->IsUnhappy())
        livestock->ResetUnhappy();
}

bool SheepActor::IsSick() const
{
    return livestock->IsSick();
}

void SheepActor::CureSickness()
{
    livestock->ResetSick();
    if (livestock->IsUnhappy())
        livestock->ResetUnhappy();
}
