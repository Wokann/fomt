#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearCelebration_StartChoice_RiceCakeFestivalStartPrompt[] =
        "Well, should we start the\r\n"
        "New Year Festival now?{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_HoldingItemCannotParticipateInRiceCakeFestival[] =
        "...But, you can't \r\n"
        "participate while your hands\r\n"
        "are full!{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceStartRiceCakeFestival[] =
        "Start";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceWaitBeforeRiceCakeFestival[] =
        "Wait a minute";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasStartsRiceCakeFestival[] =
        "Alright, let's get started.\r\n"
        "\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasWaitsToStartRiceCakeFestival[] =
        "Well, let me know when\r\n"
        "you're ready.\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_NewYearsEveNoodleFestivalStartPrompt[] =
        "Shall we get started on\r\n"
        "the new year celebration?{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_HoldingItemCannotEatAtNoodleFestival[] =
        "...But, you can't eat while\r\n"
        "your hands are full, \r\n"
        "can you?{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceStartNoodleFestivalMeal[] =
        "Start.";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceWaitBeforeNoodleFestivalMeal[] =
        "Hold on a second.";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasStartsNoodleFestivalMeal[] =
        "Let's eat, then!\r\n"
        "\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_ThomasWaitsToStartNoodleFestivalMeal[] =
        "Just let me know when you're\r\n"
        "ready to eat.\r\n"
        "{Press}";

    const char gText_FestivalEvent_NewYearCelebration_StartChoice_LongTableDescription[] =
        "Long table{Press}";
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
            var_0 = TalkChoice2(gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceStartRiceCakeFestival, gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceWaitBeforeRiceCakeFestival);
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
                var_0 = TalkChoice2(gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceStartNoodleFestivalMeal, gText_FestivalEvent_NewYearCelebration_StartChoice_ChoiceWaitBeforeNoodleFestivalMeal);
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
