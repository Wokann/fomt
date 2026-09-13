#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Mary_ImGoingToBetTodayBut[] =
        "I'm going to bet today, \r\n"
        "but I haven't decided on \r\n"
        "which Horse yet...{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Mary_GoodLuckIllBeRootingFor[] =
        "Good luck. \r\n"
        "I'll be rooting for you. {Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Mary(void)
{
    if (HasMetNpc(CHARACTER_MARY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_MARY);
    }
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Mary_ImGoingToBetTodayBut);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Mary_GoodLuckIllBeRootingFor);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MARY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MARY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MARY);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
}
