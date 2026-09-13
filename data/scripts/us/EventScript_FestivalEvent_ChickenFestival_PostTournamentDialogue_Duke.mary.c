#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_IGotTiredJustWatching[] =
        "I got tired just watching!{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_ThatWasFantasticHowDidYou[] =
        "That was fantastic! \r\n"
        "How did you train your \r\n"
        "Chicken to be so fierce? {Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_MaybeYouShouldSpendMoreTime[] =
        "Maybe you should spend more\r\n"
        "time caring for your\r\n"
        "Chickens...?{Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke(void)
{
    if (HasMetNpc(CHARACTER_DUKE) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_IGotTiredJustWatching);
    }
    else
    {
        if (VarGet(VAR_CHICKEN_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_ThatWasFantasticHowDidYou);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_MaybeYouShouldSpendMoreTime);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DUKE) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DUKE, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
}
