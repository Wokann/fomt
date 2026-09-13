#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearCelebration_StartChoice_RiceCakeFestivalStartPrompt[] =
        "それじゃあ、もちつき大会を\r\n"
        "始めてもいいかな？{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_HoldingItemCannotParticipateInRiceCakeFestival[] =
        "…でも、物を持ったままだと、\r\n"
        "おもちがわたせないけどいいの\r\n"
        "かな？{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_Shared_RiceCakeAndNoodleFestivalStartChoice[] =
        "始める";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_Shared_RiceCakeAndNoodleFestivalWaitChoice[] =
        "ちょっと待って";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasStartsRiceCakeFestival[] =
        "じゃ、始めようか。\r\n"
        "\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasWaitsToStartRiceCakeFestival[] =
        "じゃ、始めてよかったら\r\n"
        "声をかけてね。\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_NewYearsEveNoodleFestivalStartPrompt[] =
        "それじゃあ、年越しそばを\r\n"
        "食べ始めようか？{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_HoldingItemCannotEatAtNoodleFestival[] =
        "…でも、物を持ったままだと、\r\n"
        "そばがわたせないけどいいの\r\n"
        "かな？{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasStartsNoodleFestivalMeal[] =
        "じゃ、食べようか。\r\n"
        "\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasWaitsToStartNoodleFestivalMeal[] =
        "じゃ、食べたくなったら\r\n"
        "声をかけてね。\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_LongTableDescription[] =
        "長机{Press}";
};

void EventScript_FestivalEvent_NewYearCelebration_StartChoice(void)
{
    int var_0;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_RiceCakeFestivalStartPrompt);
            if (IsPlayerHoldingNothing() == FALSE)
            {
                TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_HoldingItemCannotParticipateInRiceCakeFestival);
            }
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice2(gText_FestivalEvent_NewYearCelebration_StartChoice_Shared_RiceCakeAndNoodleFestivalStartChoice, gText_FestivalEvent_NewYearCelebration_StartChoice_Shared_RiceCakeAndNoodleFestivalWaitChoice);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasStartsRiceCakeFestival);
                    TalkClose();
                    MarkNpcSpokenTo(CHARACTER_THOMAS);
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    CallScript(EventScript_FestivalEvent_NewYearRiceCakeFestival_Meal);
                    break;
                case CHOICE_OPTION_2:
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasWaitsToStartRiceCakeFestival);
                    TalkClose();
                    MarkNpcSpokenTo(CHARACTER_THOMAS);
                    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                    break;
            }
        }
        else
        {
            if (VarGet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_NewYearsEveNoodleFestivalStartPrompt);
                if (IsPlayerHoldingNothing() == FALSE)
                {
                    TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_HoldingItemCannotEatAtNoodleFestival);
                }
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_NewYearCelebration_StartChoice_Shared_RiceCakeAndNoodleFestivalStartChoice, gText_FestivalEvent_NewYearCelebration_StartChoice_Shared_RiceCakeAndNoodleFestivalWaitChoice);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasStartsNoodleFestivalMeal);
                        TalkClose();
                        MarkNpcSpokenTo(CHARACTER_THOMAS);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        CallScript(EventScript_FestivalEvent_NewYearsEve_NoodleFestivalMeal);
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasWaitsToStartNoodleFestivalMeal);
                        TalkClose();
                        MarkNpcSpokenTo(CHARACTER_THOMAS);
                        SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                        break;
                }
            }
        }
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_FestivalEvent_NewYearCelebration_StartChoice_LongTableDescription);
        TalkClose();
    }
}
