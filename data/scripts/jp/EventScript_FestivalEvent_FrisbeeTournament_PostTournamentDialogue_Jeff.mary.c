#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff_YouDidAGreatJobI[] =
        "惜しかったね。\r\n"
        "でも、出場するだけでも\r\n"
        "スゴイと思うよ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff_CongratulationsYouAndDogWereFantastic[] =
        "おめでとう！\r\n"
        "スゴイよねぇ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff_JeffPraisesDogs[] =
        "やっぱり、犬って賢いよねぇ。\r\n"
        "つくづく、そう思ったよ。{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff(void)
{
    if (HasMetNpc(CHARACTER_JEFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == TRUE)
    {
        if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_NOT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff_YouDidAGreatJobI);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff_CongratulationsYouAndDogWereFantastic);
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff_JeffPraisesDogs);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_JEFF) == FALSE)
    {
        AddNpcFriendship(CHARACTER_JEFF, 5);
    }
    MarkNpcSpokenTo(CHARACTER_JEFF);
    SetEntityFacing(ENTITY_JEFF, FACING_RIGHT);
}
