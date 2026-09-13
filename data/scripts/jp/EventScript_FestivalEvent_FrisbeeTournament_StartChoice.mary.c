#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_StartChoice_ZackAsksIfPlayerIsReady[] =
        "フリスビー大会を\r\n"
        "始めてもいいか？{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_StartChoice_StartNowChoice[] =
        "フリスビー大会を始める";

    const char gText_FestivalEvent_FrisbeeTournament_StartChoice_WaitChoice[] =
        "ちょっとまって";

    const char gText_FestivalEvent_FrisbeeTournament_StartChoice_ZackStartsTournament[] =
        "じゃあ、始めるぜ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_StartChoice_ZackInvitesPlayerToReturnWhenReady[] =
        "フリスビー大会を始めるときは\r\n"
        "おれに言ってくれよ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_StartChoice_Counter[] =
        "カウンター{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_StartChoice(void)
{
    int var_0, var_1, var_2;
    var_1 = VarGet(VAR_HOUR);
    var_2 = VarGet(VAR_MINUTE);
    if (VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL && !(var_1 == 18 && var_2 == 1))
    {
        if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
        {
            MarkNpcSpokenTo(CHARACTER_ZACK);
            SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_StartChoice_ZackAsksIfPlayerIsReady);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice2(gText_FestivalEvent_FrisbeeTournament_StartChoice_StartNowChoice, gText_FestivalEvent_FrisbeeTournament_StartChoice_WaitChoice);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_ZACK);
                    TalkMessage(gText_FestivalEvent_FrisbeeTournament_StartChoice_ZackStartsTournament);
                    TalkClose();
                    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == TRUE)
                    {
                        VarSet(VAR_FRISBEE_TOURNAMENT_RESULT, RunFrisbeeGame(FESTIVAL_FRISBEE_MODE_CONTEST));
                        if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
                        {
                            CallScript(EventScript_FestivalEvent_DogFrisbeeTournament_PlayerVictory);
                        }
                    }
                    CallScript(EventScript_FestivalEvent_BeachDay_Closing);
                    break;
                case CHOICE_OPTION_2:
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_ZACK);
                    TalkMessage(gText_FestivalEvent_FrisbeeTournament_StartChoice_ZackInvitesPlayerToReturnWhenReady);
                    TalkClose();
                    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
                    break;
            }
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_StartChoice_Counter);
            TalkClose();
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_StartChoice_Counter);
        TalkClose();
    }
}
