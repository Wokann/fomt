#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1258_FestivalEvent_FallHorseRace_SpectatorDialogue_Harris.mary.h"

void EventScript_1258_FestivalEvent_FallHorseRace_SpectatorDialogue_Harris(void)
{
    if (HasMetNpc(CHARACTER_HARRIS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Harris_MyGreatestJoyIsObservingEverybodys);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Harris_LookLikeTheRacesAreBeginning);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_HARRIS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_HARRIS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_DOWN);
}
