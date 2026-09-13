#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IKnewWhoWouldWinFrom[] =
        "Ich wusste immer, wer\r\n"
        "gewinnen würde.{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IKnewYourChickenWasThe[] =
        "Den Eiern nach war  \r\n"
        "dein Huhn offensichtlich \r\n"
        "das Stärkste! {Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IsYourChickenHavingAnOff[] =
        "Hat dein Huhn heute \r\n"
        "einen Ruhetag? Ist es \r\n"
        "wirklich dein stärkstes?{Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IKnewWhoWouldWinFrom);
    }
    else
    {
        if (VarGet(VAR_CHICKEN_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IKnewYourChickenWasThe);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IsYourChickenHavingAnOff);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOUG) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOUG, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DOUG);
    SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
}
