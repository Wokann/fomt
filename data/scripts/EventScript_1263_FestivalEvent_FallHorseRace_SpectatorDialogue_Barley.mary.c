#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1263_FestivalEvent_FallHorseRace_SpectatorDialogue_Barley.mary.h"

void EventScript_1263_FestivalEvent_FallHorseRace_SpectatorDialogue_Barley(void)
{
    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BARLEY);
    }
    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Barley_ILookForwardToThisDay);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Barley_YoureRacingMyAdviceIsTo);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BARLEY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
}
