#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara_IWonderWhatHappenedToThat[] =
        "I wonder what happened\r\n"
        "to that chicken?{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara_EvenThatChickensFaceLooksFierce[] =
        "Even that Chicken's face\r\n"
        "looks fierce!{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara_ThatWasAGoodEffort[] =
        "That was a good effort. {Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara(void)
{
    if (HasMetNpc(CHARACTER_SAIBARA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SAIBARA);
    }
    SetEntityFacing(ENTITY_SAIBARA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara_IWonderWhatHappenedToThat);
    }
    else
    {
        if (VarGet(VAR_CHICKEN_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SAIBARA);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara_EvenThatChickensFaceLooksFierce);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SAIBARA);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara_ThatWasAGoodEffort);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SAIBARA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SAIBARA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SAIBARA);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
}
