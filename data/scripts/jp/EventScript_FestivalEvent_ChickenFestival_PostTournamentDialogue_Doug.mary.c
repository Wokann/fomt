#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IKnewWhoWouldWinFrom[] =
        "やっぱり、あいつが優勝か。\r\n"
        "オレが思ったとおりだったな。{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IKnewYourChickenWasThe[] =
        "やっぱりな、お前ん所の鶏は\r\n"
        "いいと思ったんだよ。\r\n"
        "うまい卵を産むからなぁ。{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug_IsYourChickenHavingAnOff[] =
        "なんだ、調子悪かったのか？\r\n"
        "牧場で１番強いヤツなんだろ？{Press}";
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
