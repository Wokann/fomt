#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Mary_IThinkItsGreatForKids[] =
        "Ich finde, es ist toll für\r\n"
        "Kinder, mit Tieren zu leben.{Press}\p"
        "Manche Eltern erlauben \r\n"
        "nicht einmal Hunde!{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Mary_IllBeRootingForYourCow[] =
        "Ich feuere deine\r\n"
        "Kuh an. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Mary(void)
{
    if (HasMetNpc(CHARACTER_MARY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_MARY);
    }
    SetTalkNameplateCharacter(CHARACTER_MARY);
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Mary_IThinkItsGreatForKids);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Mary_IllBeRootingForYourCow);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MARY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MARY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MARY);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
}
