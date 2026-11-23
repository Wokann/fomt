#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1093_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna.mary.h"

void EventScript_1093_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
        TalkMessageSlow(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces);
#else
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces);
#endif
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
#if defined(REGION_JP)
        TalkMessageSlow(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_ImGoingToBetOnYou);
#else
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_ImGoingToBetOnYou);
#endif
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
}
