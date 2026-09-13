#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_IGotTiredJustWatching[] =
        "Ich bin vom Zuschauen \r\n"
        "schon müde!{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_ThatWasFantasticHowDidYou[] =
        "Das war fantastisch! \r\n"
        "Wie hast du dein Huhn \r\n"
        "so stark gekriegt?{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke_MaybeYouShouldSpendMoreTime[] =
        "Vielleicht solltest du\r\n"
        "mehr Zeit mit der\r\n"
        "Hühnerpflege verbringen...?{Press}";
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
