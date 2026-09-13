#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterMineralClinic1FWithEventDispatch_DoorIsLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationTransition_EnterMineralClinic1FWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_4 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_DAY_OF_WEEK);
        var_5 = VarGet(VAR_WEATHER_TODAY);
        var_6 = VarGet(VAR_YEAR);
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_ELLI_DOCTOR_WEDDING_MISSED) == TRUE)
            {
                var_0 = FALSE;
            }
            else
            {
                if (GetEntityLocation(ENTITY_DOCTOR) == MAP_MINERAL_CLINIC_1F)
                {
                    if (GetNpcFriendship(CHARACTER_DOCTOR) <= 200)
                    {
                        if (var_4 >= 9 && var_4 < 16)
                        {
                            var_0 = TRUE;
                        }
                    }
                    else
                    {
                        if (var_4 >= 9 && var_4 < 22)
                        {
                            var_0 = TRUE;
                        }
                    }
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_MINERAL_CLINIC_1F, X(184), Y(320));
            SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
            if (VarGet(VAR_ELLI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_3 == DAY_OF_WEEK_WEDNESDAY || var_3 == DAY_OF_WEEK_MONDAY) && (var_4 >= 9 && var_4 < 19) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetEntityLocation(ENTITY_ELLI) == MAP_MINERAL_CLINIC_1F && GetEntityLocation(ENTITY_DOCTOR) == MAP_MINERAL_CLINIC_1F && IsPlayerHoldingNothing() == TRUE)
            {
                VarSet(VAR_ELLI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu);
            }
            else
            {
                if (VarGet(VAR_ELLI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_3 == DAY_OF_WEEK_MONDAY || var_3 == DAY_OF_WEEK_TUESDAY || var_3 == DAY_OF_WEEK_WEDNESDAY || var_3 == DAY_OF_WEEK_FRIDAY) && (var_4 >= 9 && var_4 < 19) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_PURPLE_MIN && GetEntityLocation(ENTITY_ELLI) == MAP_MINERAL_CLINIC_1F && GetEntityLocation(ENTITY_DOCTOR) == MAP_MINERAL_CLINIC_1F && IsPlayerHoldingNothing() == TRUE)
                {
                    VarSet(VAR_ELLI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Elli_02_PurpleHeart_MedicineMixup);
                }
                else
                {
                    if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_3 == DAY_OF_WEEK_TUESDAY || var_3 == DAY_OF_WEEK_WEDNESDAY) && (var_4 >= 9 && var_4 < 19) && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_PURPLE_MIN && HasMetNpc(CHARACTER_DOCTOR) == TRUE && HasMetNpc(CHARACTER_ELLI) == TRUE && IsPlayerHoldingNothing() == TRUE)
                    {
                        VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding);
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_3 == DAY_OF_WEEK_TUESDAY || var_3 == DAY_OF_WEEK_WEDNESDAY) && var_6 >= 2 && (var_4 >= 9 && var_4 < 19) && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_YELLOW_MIN)
                        {
                            VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll);
                        }
                        else
                        {
                            if (VarGet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 == DAY_OF_WEEK_TUESDAY && (var_4 >= 13 && var_4 < 16) && GetNpcFriendship(CHARACTER_DOCTOR) >= 150 && HasMetNpc(CHARACTER_DOCTOR) == TRUE && GetEntityLocation(ENTITY_JEFF) == MAP_MINERAL_CLINIC_1F && GetEntityLocation(ENTITY_DOCTOR) == MAP_MINERAL_CLINIC_1F)
                            {
                                VarSet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_NPCEvent_Jeff_BloodTypeCorrection);
                            }
                            else
                            {
                                if (VarGet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 != DAY_OF_WEEK_WEDNESDAY && (var_4 >= 12 && var_4 < 19) && (VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && HasMetNpc(CHARACTER_DOCTOR) == TRUE && HasMetNpc(CHARACTER_ELLI) == TRUE)
                                {
                                    VarSet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_NPCEvent_Elli_StudiesMedicineForEllensLegs);
                                }
                            }
                        }
                    }
                }
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterMineralClinic1FWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}
