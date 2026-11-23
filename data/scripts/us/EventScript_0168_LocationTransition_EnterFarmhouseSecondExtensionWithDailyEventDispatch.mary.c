#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0168_LocationTransition_EnterFarmhouseSecondExtensionWithDailyEventDispatch.mary.h"

void EventScript_0168_LocationTransition_EnterFarmhouseSecondExtensionWithDailyEventDispatch(void)
{
    int var_0, var_1, var_2;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (IsPlayerRidingHorse() == TRUE)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationTransition_EnterFarmhouseSecondExtensionWithDailyEventDispatch);
            TalkClose();
            return;
        }
        if (IsFireplaceLitAtLocation(MAP_FARMHOUSE))
        {
            switch (VarGet(VAR_SEASON))
            {
                case SEASON_SPRING:
                    ChangePlayerStaminaAndFatigue(0, 1);
                    break;
                case SEASON_SUMMER:
                    ChangePlayerStaminaAndFatigue(0, 2);
                    break;
                case SEASON_FALL:
                    ChangePlayerStaminaAndFatigue(0, 1);
                    break;
                case SEASON_WINTER:
                    ChangePlayerStaminaAndFatigue(0, mary_negated_int(-1));
                    break;
            }
        }
        VarSet(VAR_ENTERED_FARMHOUSE_TODAY, TRUE);
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FARMHOUSE, X(304), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(304), Y(208), FACING_UP);
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_2 = VarGet(VAR_HOUR);
        if (VarGet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_FALL && var_1 == DAY_30)
        {
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (var_2 >= 12 && var_2 < 18)
                {
                    VarSet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_1293_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration);
                }
            }
        }
        else
        {
            if (VarGet(VAR_STARRY_NIGHT_FARMHOUSE_SPOUSE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_WINTER && var_1 == DAY_24)
            {
                if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    if (var_2 >= 12 && var_2 < 18)
                    {
                        VarSet(VAR_STARRY_NIGHT_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_1306_FestivalEvent_StarryNight_WithSpouseAndChild);
                    }
                }
            }
            else
            {
                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    if (VarGet(VAR_CHILD_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_CHILD_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                    {
                        VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_0609_FamilyEvent_Popuri_BabyBirthday);
                    }
                    else
                    {
                        if (IsCharacterBirthdayToday(CHARACTER_POPURI) == TRUE && (VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                        {
                            VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_0624_FamilyEvent_Popuri_SpouseBirthdayDinner);
                        }
                        else
                        {
                            if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                            {
                                VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_0639_FamilyEvent_Popuri_PlayerBirthdayDinner);
                            }
                            else
                            {
                                if (var_2 >= 0 && var_2 < 6)
                                {
                                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                                    ClearEntityEventScript(ENTITY_POPURI);
                                    ClearEntityEventScript(ENTITY_CHILD);
                                    VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        if (VarGet(VAR_CHILD_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_CHILD_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                        {
                            VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_0612_FamilyEvent_Ann_BabyBirthday);
                        }
                        else
                        {
                            if (IsCharacterBirthdayToday(CHARACTER_ANN) == TRUE && (VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                            {
                                VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_0627_FamilyEvent_Ann_SpouseBirthdayDinner);
                            }
                            else
                            {
                                if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                {
                                    VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_0642_FamilyEvent_Ann_PlayerBirthdayDinner);
                                }
                                else
                                {
                                    if (var_2 >= 0 && var_2 < 6)
                                    {
                                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                                        ClearEntityEventScript(ENTITY_ANN);
                                        ClearEntityEventScript(ENTITY_CHILD);
                                        VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            if (VarGet(VAR_CHILD_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_CHILD_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                            {
                                VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_0615_FamilyEvent_Elli_BabyBirthday);
                            }
                            else
                            {
                                if (IsCharacterBirthdayToday(CHARACTER_ELLI) == TRUE && (VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                {
                                    VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_0630_FamilyEvent_Elli_SpouseBirthdayDinner);
                                }
                                else
                                {
                                    if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                    {
                                        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_0645_FamilyEvent_Elli_PlayerBirthdayDinner);
                                    }
                                    else
                                    {
                                        if (var_2 >= 0 && var_2 < 6)
                                        {
                                            RemoveEventIcon(EVENT_ICON_SLOT_0);
                                            RemoveEventIcon(EVENT_ICON_SLOT_1);
                                            ClearEntityEventScript(ENTITY_ELLI);
                                            ClearEntityEventScript(ENTITY_CHILD);
                                            VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                if (VarGet(VAR_CHILD_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_CHILD_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                {
                                    VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_0618_FamilyEvent_Karen_BabyBirthday);
                                }
                                else
                                {
                                    if (IsCharacterBirthdayToday(CHARACTER_KAREN) == TRUE && (VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                    {
                                        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_0633_FamilyEvent_Karen_SpouseBirthdayDinner);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                        {
                                            VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_0648_FamilyEvent_Karen_PlayerBirthdayDinner);
                                        }
                                        else
                                        {
                                            if (var_2 >= 0 && var_2 < 6)
                                            {
                                                RemoveEventIcon(EVENT_ICON_SLOT_0);
                                                RemoveEventIcon(EVENT_ICON_SLOT_1);
                                                ClearEntityEventScript(ENTITY_KAREN);
                                                ClearEntityEventScript(ENTITY_CHILD);
                                                VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                                {
                                    if (VarGet(VAR_CHILD_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_CHILD_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                    {
                                        VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_0621_FamilyEvent_Mary_BabyBirthday);
                                    }
                                    else
                                    {
                                        if (IsCharacterBirthdayToday(CHARACTER_MARY) == TRUE && (VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                        {
                                            VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_0636_FamilyEvent_Mary_SpouseBirthdayDinner);
                                        }
                                    }
                                    if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                    {
                                        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_0651_FamilyEvent_Mary_PlayerBirthdayDinner);
                                    }
                                    else
                                    {
                                        if (var_2 >= 0 && var_2 < 6)
                                        {
                                            RemoveEventIcon(EVENT_ICON_SLOT_0);
                                            RemoveEventIcon(EVENT_ICON_SLOT_1);
                                            ClearEntityEventScript(ENTITY_MARY);
                                            ClearEntityEventScript(ENTITY_CHILD);
                                            VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        }
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                                    {
                                        if (VarGet(VAR_CHILD_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_CHILD_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                        {
                                            VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_0853_FamilyEvent_HarvestGoddess_ChildBirthday);
                                        }
                                        else
                                        {
                                            if (IsCharacterBirthdayToday(CHARACTER_HARVEST_GODDESS) == TRUE && (VarGet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                            {
                                                VarSet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_0856_FamilyEvent_HarvestGoddess_Evening);
                                            }
                                        }
                                        if (VarGet(VAR_PLAYER_BIRTHDAY_SEASON) == var_0 && VarGet(VAR_PLAYER_BIRTHDAY_DAY) == var_1 && (VarGet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED || VarGet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (var_2 >= 18 && var_2 <= 23))
                                        {
                                            VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_0859_FamilyEvent_HarvestGoddess_PlayerBirthday);
                                        }
                                        else
                                        {
                                            if (var_2 >= 0 && var_2 < 6)
                                            {
                                                RemoveEventIcon(EVENT_ICON_SLOT_0);
                                                RemoveEventIcon(EVENT_ICON_SLOT_1);
                                                ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
                                                ClearEntityEventScript(ENTITY_CHILD);
                                                VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                VarSet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
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
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
