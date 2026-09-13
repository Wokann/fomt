#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_SystemEvent_ScheduleDailyEvents(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_3 = VarGet(VAR_HOUR);
    var_2 = VarGet(VAR_DAY_OF_WEEK);
    var_4 = VarGet(VAR_WEATHER_TODAY);
    if (!(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_14 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_30 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_14 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30))
    {
        if (VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
        {
            VarSet(VAR_KAREN_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
            CallScript(EventScript_LoveEvent_Karen_Wedding);
        }
        else
        {
            if (VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
            {
                VarSet(VAR_POPURI_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                CallScript(EventScript_LoveEvent_Popuri_Wedding);
            }
            else
            {
                if (VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                {
                    VarSet(VAR_ANN_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Ann_Wedding);
                }
                else
                {
                    if (VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                    {
                        VarSet(VAR_MARY_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                        CallScript(EventScript_LoveEvent_Mary_Wedding);
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                        {
                            VarSet(VAR_ELLI_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                            CallScript(EventScript_LoveEvent_Elli_Wedding);
                        }
                        else
                        {
                            if (VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                            {
                                VarSet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection);
                            }
                            else
                            {
                                if (VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_DAYS_SINCE_KAREN_FINAL_RIVAL_EVENT) >= 7)
                                {
                                    if (GetNpcFriendship(CHARACTER_RICK) < 200 || (GetEntityLocation(ENTITY_PLAYER) == MAP_MOUNTAIN_COTTAGE || GetEntityLocation(ENTITY_PLAYER) == MAP_BEACH_HOUSE || GetEntityLocation(ENTITY_PLAYER) == MAP_TOWN_COTTAGE))
                                    {
                                        VarSet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE, TRUE);
                                    }
                                    else
                                    {
                                        if (GetNpcFriendship(CHARACTER_RICK) >= 200 && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                                        {
                                            VarSet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_CeremonyWithPopuriIntroduction);
                                        }
                                        else
                                        {
                                            if (GetNpcFriendship(CHARACTER_RICK) >= 200)
                                            {
                                                VarSet(VAR_RICK_KAREN_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony);
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_DAYS_SINCE_POPURI_FINAL_RIVAL_EVENT) >= 7)
                                    {
                                        if (GetNpcFriendship(CHARACTER_KAI) < 200 || (GetEntityLocation(ENTITY_PLAYER) == MAP_MOUNTAIN_COTTAGE || GetEntityLocation(ENTITY_PLAYER) == MAP_BEACH_HOUSE || GetEntityLocation(ENTITY_PLAYER) == MAP_TOWN_COTTAGE))
                                        {
                                            VarSet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE, TRUE);
                                        }
                                        else
                                        {
                                            if (GetNpcFriendship(CHARACTER_KAI) >= 200)
                                            {
                                                VarSet(VAR_POPURI_KAI_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_DAYS_SINCE_ANN_FINAL_RIVAL_EVENT) >= 7)
                                        {
                                            if (GetNpcFriendship(CHARACTER_CLIFF) < 200 || (GetEntityLocation(ENTITY_PLAYER) == MAP_MOUNTAIN_COTTAGE || GetEntityLocation(ENTITY_PLAYER) == MAP_BEACH_HOUSE || GetEntityLocation(ENTITY_PLAYER) == MAP_TOWN_COTTAGE))
                                            {
                                                VarSet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE, TRUE);
                                            }
                                            else
                                            {
                                                if (GetNpcFriendship(CHARACTER_CLIFF) >= 200)
                                                {
                                                    VarSet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                    CallScript(EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_DAYS_SINCE_MARY_FINAL_RIVAL_EVENT) >= 7)
                                            {
                                                if (GetNpcFriendship(CHARACTER_GRAY) < 200 || (GetEntityLocation(ENTITY_PLAYER) == MAP_MOUNTAIN_COTTAGE || GetEntityLocation(ENTITY_PLAYER) == MAP_BEACH_HOUSE || GetEntityLocation(ENTITY_PLAYER) == MAP_TOWN_COTTAGE))
                                                {
                                                    VarSet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE, TRUE);
                                                }
                                                else
                                                {
                                                    if (GetNpcFriendship(CHARACTER_GRAY) >= 200)
                                                    {
                                                        VarSet(VAR_MARY_GRAY_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                        CallScript(EventScript_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony);
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_DAYS_SINCE_ELLI_FINAL_RIVAL_EVENT) >= 7)
                                                {
                                                    if (GetNpcFriendship(CHARACTER_DOCTOR) < 200 || (GetEntityLocation(ENTITY_PLAYER) == MAP_MOUNTAIN_COTTAGE || GetEntityLocation(ENTITY_PLAYER) == MAP_BEACH_HOUSE || GetEntityLocation(ENTITY_PLAYER) == MAP_TOWN_COTTAGE))
                                                    {
                                                        VarSet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE, TRUE);
                                                    }
                                                    else
                                                    {
                                                        if (GetNpcFriendship(CHARACTER_DOCTOR) >= 200)
                                                        {
                                                            VarSet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                            CallScript(EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony);
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED && GetEntityLocation(ENTITY_PLAYER) == MAP_FARMHOUSE)
                                                    {
                                                        var_5 = VarGet(VAR_SEASON) * 30 + VarGet(VAR_DAY);
                                                        var_6 = VarGet(VAR_WEDDING_SEASON) * 30 + VarGet(VAR_WEDDING_DAY);
                                                        if (var_5 < var_6)
                                                        {
                                                            var_5 += 120;
                                                        }
                                                        if (VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) == 50 && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1 && VarGet(VAR_KAREN_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                                        {
                                                            VarSet(VAR_KAREN_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                            CallScript(EventScript_FamilyEvent_Karen_FiftiethAnniversaryMountainCottageGift);
                                                        }
                                                        else
                                                        {
                                                            if (VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                                                            {
                                                                VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                CallScript(EventScript_FamilyEvent_Karen_AnniversaryDateDialogueChoice);
                                                            }
                                                            else
                                                            {
                                                                if (VarGet(VAR_KAREN_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_KAREN) >= 65000 && var_5 >= var_6 + 30)
                                                                {
                                                                    VarSet(VAR_KAREN_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                    CallScript(EventScript_FamilyEvent_Karen_PregnancyDiscovery);
                                                                }
                                                                else
                                                                {
                                                                    if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_CHILDBIRTH_EVENT_START && !(var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_15) && !(var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_23) && !(VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1))
                                                                    {
                                                                        VarSet(VAR_KAREN_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                        CallScript(EventScript_FamilyEvent_Karen_Childbirth);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (VarGet(VAR_KAREN_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
                                                                        {
                                                                            VarSet(VAR_KAREN_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                            CallScript(EventScript_FamilyEvent_Karen_ChildInjury);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (VarGet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START)
                                                                            {
                                                                                VarSet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                CallScript(EventScript_FamilyEvent_Karen_ChildFirstSteps);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (VarGet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetDaysSinceLastSpokenToNpc(CHARACTER_KAREN) >= 10 && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) == 0 && VarGet(VAR_CHILD_AGE_DAYS) == 0)
                                                                                {
                                                                                    VarSet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                    CallScript(EventScript_FamilyEvent_Karen_SpouseCollapseRecovery);
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED && GetEntityLocation(ENTITY_PLAYER) == MAP_FARMHOUSE)
                                                        {
                                                            var_5 = VarGet(VAR_SEASON) * 30 + VarGet(VAR_DAY);
                                                            var_6 = VarGet(VAR_WEDDING_SEASON) * 30 + VarGet(VAR_WEDDING_DAY);
                                                            if (var_5 < var_6)
                                                            {
                                                                var_5 += 120;
                                                            }
                                                            if (VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) == 50 && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1 && VarGet(VAR_POPURI_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                                            {
                                                                VarSet(VAR_POPURI_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                CallScript(EventScript_FamilyEvent_Popuri_FiftiethAnniversaryMountainCottageGift);
                                                            }
                                                            else
                                                            {
                                                                if (VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                                                                {
                                                                    VarSet(VAR_POPURI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                    CallScript(EventScript_FamilyEvent_Popuri_AnniversaryDateDialogueChoice);
                                                                }
                                                                else
                                                                {
                                                                    if (VarGet(VAR_POPURI_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) >= 65000 && var_5 >= var_6 + 30)
                                                                    {
                                                                        VarSet(VAR_POPURI_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                        CallScript(EventScript_FamilyEvent_Popuri_PregnancyDiscovery);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_CHILDBIRTH_EVENT_START && !(var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_03) && !(var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_10) && !(VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1))
                                                                        {
                                                                            VarSet(VAR_POPURI_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                            CallScript(EventScript_FamilyEvent_Popuri_Childbirth);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (VarGet(VAR_POPURI_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
                                                                            {
                                                                                VarSet(VAR_POPURI_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                CallScript(EventScript_FamilyEvent_Popuri_ChildInjury);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (VarGet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START)
                                                                                {
                                                                                    VarSet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                    CallScript(EventScript_FamilyEvent_Popuri_ChildFirstSteps);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (VarGet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetDaysSinceLastSpokenToNpc(CHARACTER_POPURI) >= 10 && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) == 0 && VarGet(VAR_CHILD_AGE_DAYS) == 0)
                                                                                    {
                                                                                        VarSet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                        CallScript(EventScript_FamilyEvent_Popuri_SpouseCollapseRecovery);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED && GetEntityLocation(ENTITY_PLAYER) == MAP_FARMHOUSE)
                                                            {
                                                                var_5 = VarGet(VAR_SEASON) * 30 + VarGet(VAR_DAY);
                                                                var_6 = VarGet(VAR_WEDDING_SEASON) * 30 + VarGet(VAR_WEDDING_DAY);
                                                                if (var_5 < var_6)
                                                                {
                                                                    var_5 += 120;
                                                                }
                                                                if (VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) == 50 && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1 && VarGet(VAR_ANN_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                                                {
                                                                    VarSet(VAR_ANN_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                    CallScript(EventScript_FamilyEvent_Ann_FiftiethAnniversaryMountainCottageGift);
                                                                }
                                                                else
                                                                {
                                                                    if (VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                                                                    {
                                                                        VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                        CallScript(EventScript_FamilyEvent_Ann_AnniversaryDateDialogueChoice);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (VarGet(VAR_ANN_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) >= 65000 && var_5 >= var_6 + 30)
                                                                        {
                                                                            VarSet(VAR_ANN_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                            CallScript(EventScript_FamilyEvent_Ann_PregnancyDiscovery);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_CHILDBIRTH_EVENT_START && !(var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_17) && !(var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_22) && !(VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1))
                                                                            {
                                                                                VarSet(VAR_ANN_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                CallScript(EventScript_FamilyEvent_Ann_Childbirth);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (VarGet(VAR_ANN_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
                                                                                {
                                                                                    VarSet(VAR_ANN_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                    CallScript(EventScript_FamilyEvent_Ann_ChildInjury);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (VarGet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START)
                                                                                    {
                                                                                        VarSet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                        CallScript(EventScript_FamilyEvent_Ann_ChildFirstSteps);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (VarGet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetDaysSinceLastSpokenToNpc(CHARACTER_ANN) >= 10 && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) == 0 && VarGet(VAR_CHILD_AGE_DAYS) == 0)
                                                                                        {
                                                                                            VarSet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                            CallScript(EventScript_FamilyEvent_Ann_SpouseCollapseRecovery);
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                            else
                                                            {
                                                                if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED && GetEntityLocation(ENTITY_PLAYER) == MAP_FARMHOUSE)
                                                                {
                                                                    var_5 = VarGet(VAR_SEASON) * 30 + VarGet(VAR_DAY);
                                                                    var_6 = VarGet(VAR_WEDDING_SEASON) * 30 + VarGet(VAR_WEDDING_DAY);
                                                                    if (var_5 < var_6)
                                                                    {
                                                                        var_5 += 120;
                                                                    }
                                                                    if (VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) == 50 && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1 && VarGet(VAR_MARY_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                                                    {
                                                                        VarSet(VAR_MARY_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                        CallScript(EventScript_FamilyEvent_Mary_FiftiethAnniversaryMountainCottageGift);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                                                                        {
                                                                            VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                            CallScript(EventScript_FamilyEvent_Mary_AnniversaryDateDialogueChoice);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (VarGet(VAR_MARY_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_MARY) >= 65000 && var_5 >= var_6 + 30)
                                                                            {
                                                                                VarSet(VAR_MARY_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                CallScript(EventScript_FamilyEvent_Mary_PregnancyDiscovery);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_CHILDBIRTH_EVENT_START && !(var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_20) && !(var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_23) && !(VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1))
                                                                                {
                                                                                    VarSet(VAR_MARY_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                    CallScript(EventScript_FamilyEvent_Mary_Childbirth);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (VarGet(VAR_MARY_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
                                                                                    {
                                                                                        VarSet(VAR_MARY_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                        CallScript(EventScript_FamilyEvent_Mary_ChildInjury);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (VarGet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START)
                                                                                        {
                                                                                            VarSet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                            CallScript(EventScript_FamilyEvent_Mary_ChildFirstSteps);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (VarGet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetDaysSinceLastSpokenToNpc(CHARACTER_MARY) >= 10 && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) == 0 && VarGet(VAR_CHILD_AGE_DAYS) == 0)
                                                                                            {
                                                                                                VarSet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                                CallScript(EventScript_FamilyEvent_Mary_SpouseCollapseRecovery);
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED && GetEntityLocation(ENTITY_PLAYER) == MAP_FARMHOUSE)
                                                                    {
                                                                        var_5 = VarGet(VAR_SEASON) * 30 + VarGet(VAR_DAY);
                                                                        var_6 = VarGet(VAR_WEDDING_SEASON) * 30 + VarGet(VAR_WEDDING_DAY);
                                                                        if (var_5 < var_6)
                                                                        {
                                                                            var_5 += 120;
                                                                        }
                                                                        if (VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) == 50 && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1 && VarGet(VAR_ELLI_ANNIVERSARY_MORNING_REMINDER_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                                                        {
                                                                            VarSet(VAR_ELLI_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                            CallScript(EventScript_FamilyEvent_Elli_FiftiethAnniversaryMountainCottageGift);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                                                                            {
                                                                                VarSet(VAR_ELLI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                CallScript(EventScript_FamilyEvent_Elli_AnniversaryDateDialogueChoice);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (VarGet(VAR_ELLI_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ELLI) >= 65000 && var_5 >= var_6 + 30)
                                                                                {
                                                                                    VarSet(VAR_ELLI_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                    CallScript(EventScript_FamilyEvent_Elli_PregnancyDiscovery);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_CHILDBIRTH_EVENT_START && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_16) && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_20) && !(VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1))
                                                                                    {
                                                                                        VarSet(VAR_ELLI_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                        CallScript(EventScript_FamilyEvent_Elli_Childbirth);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (VarGet(VAR_ELLI_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
                                                                                        {
                                                                                            VarSet(VAR_ELLI_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                            CallScript(EventScript_FamilyEvent_Elli_ChildInjury);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (VarGet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START)
                                                                                            {
                                                                                                VarSet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                                CallScript(EventScript_FamilyEvent_Elli_ChildFirstSteps);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (VarGet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetDaysSinceLastSpokenToNpc(CHARACTER_ELLI) >= 10 && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) == 0 && VarGet(VAR_CHILD_AGE_DAYS) == 0)
                                                                                                {
                                                                                                    VarSet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                                    CallScript(EventScript_FamilyEvent_Elli_SpouseCollapseRecovery);
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        if (VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && GetEntityLocation(ENTITY_PLAYER) == MAP_FARMHOUSE)
                                                                        {
                                                                            var_5 = VarGet(VAR_SEASON) * 30 + VarGet(VAR_DAY);
                                                                            var_6 = VarGet(VAR_WEDDING_SEASON) * 30 + VarGet(VAR_WEDDING_DAY);
                                                                            if (var_5 < var_6)
                                                                            {
                                                                                var_5 += 120;
                                                                            }
                                                                            if (VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) == 50 && VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1 && VarGet(VAR_HARVEST_GODDESS_FIFTIETH_ANNIVERSARY_GIFT_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                                                            {
                                                                                VarSet(VAR_HARVEST_GODDESS_FIFTIETH_ANNIVERSARY_GIFT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                CallScript(EventScript_FamilyEvent_HarvestGoddess_FiftiethAnniversaryMountainCottageGift);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (VarGet(VAR_WEDDING_SEASON) == var_0 && VarGet(VAR_WEDDING_DAY) == var_1)
                                                                                {
                                                                                    VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                    CallScript(EventScript_FamilyEvent_HarvestGoddess_AnniversaryAndBirthdayChoice);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (VarGet(VAR_HARVEST_GODDESS_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_HARVEST_GODDESS) >= 65000 && var_5 >= var_6 + 30)
                                                                                    {
                                                                                        VarSet(VAR_HARVEST_GODDESS_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                        CallScript(EventScript_FamilyEvent_HarvestGoddess_PregnancyAnnouncement);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_CHILDBIRTH_EVENT_START && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_08) && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_09) && !(VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1))
                                                                                        {
                                                                                            VarSet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                            CallScript(EventScript_FamilyEvent_HarvestGoddess_Childbirth);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (VarGet(VAR_HARVEST_GODDESS_CHILD_INJURY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
                                                                                            {
                                                                                                VarSet(VAR_HARVEST_GODDESS_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                                CallScript(EventScript_FamilyEvent_HarvestGoddess_ChildInjury);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (VarGet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START)
                                                                                                {
                                                                                                    VarSet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                                                    CallScript(EventScript_FamilyEvent_HarvestGoddess_ChildFirstSteps);
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (var_4 != WEATHER_TYPHOON && var_4 != WEATHER_SNOWSTORM)
        {
            CallScript(EventScript_FarmEvent_Livestock_NewBirthAndNaming);
        }
    }
    CallScript(EventScript_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing);
}
