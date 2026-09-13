#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen_SheepAreSoCute[] =
        "Schafe sind so süß!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen_CongratulationsItsAllTheAttentionYou[] =
        "Herzlichen Glückwunsch!\r\n"
        "Das macht die ganze\r\n"
        "Aufmerksamkeit, die {Press}\r\n"
        "du ihnen gibst. {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen_DontGetTooSadJustWork[] =
        "Sei nicht traurig. \r\n"
        "Versuch es einfach \r\n"
        "nächstes Jahr!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen(void)
{
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_KAREN);
    }
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen_SheepAreSoCute);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen_CongratulationsItsAllTheAttentionYou);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen_DontGetTooSadJustWork);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_KAREN) == FALSE)
    {
        AddNpcFriendship(CHARACTER_KAREN, 5);
    }
    MarkNpcSpokenTo(CHARACTER_KAREN);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
}
