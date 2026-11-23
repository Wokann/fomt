#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0406_FestivalEvent_NewYearCelebration_StartChoice.mary.h"

void EventScript_0406_FestivalEvent_NewYearCelebration_StartChoice(void)
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
                    CallScript(EventScript_1066_FestivalEvent_NewYearRiceCakeFestival_Meal);
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
                        CallScript(EventScript_1309_FestivalEvent_NewYearsEve_NoodleFestivalMeal);
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
