#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterBasilHouse1FWithEventDispatch_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterBasilHouse1FWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_4 = VarGet(VAR_DAY_OF_WEEK);
        if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30)
        {
            var_0 = FALSE;
        }
        else
        {
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24)
            {
                if (VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_MARY_HOUSEHOLD)
                {
                    if (var_3 >= 18)
                    {
                        var_0 = TRUE;
                    }
                }
                else
                {
                    var_0 = FALSE;
                }
            }
            else
            {
                if (VarGet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE) == TRUE || VarGet(VAR_MARY_GRAY_WEDDING_MISSED) == TRUE)
                {
                    var_0 = FALSE;
                }
                else
                {
                    if (GetEntityLocation(ENTITY_ANNA) == MAP_BASIL_HOUSE_1F)
                    {
                        if (GetNpcFriendship(CHARACTER_ANNA) <= 100)
                        {
                            if (var_3 >= 10 && var_3 < 19)
                            {
                                var_0 = TRUE;
                            }
                        }
                        else
                        {
                            if (GetNpcFriendship(CHARACTER_ANNA) > 100)
                            {
                                if (var_3 >= 8 && var_3 < 20)
                                {
                                    var_0 = TRUE;
                                }
                                if (GetNpcFriendship(CHARACTER_ANNA) > 200)
                                {
                                    if (var_3 >= 6 && var_3 < 22)
                                    {
                                        var_0 = TRUE;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_BASIL_HOUSE_1F, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 && VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_MARY_HOUSEHOLD)
            {
                if (var_3 >= 18)
                {
                    CallScript(EventScript_FestivalEvent_StarryNight_WithMaryFamily);
                }
            }
            else
            {
                if (VarGet(VAR_MARY_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_MONDAY && (var_3 >= 10 && var_3 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_YELLOW_MIN && (GetEntityLocation(ENTITY_BASIL) == MAP_BASIL_HOUSE_1F || GetEntityLocation(ENTITY_BASIL) == MAP_BASIL_HOUSE_2F) && (GetEntityLocation(ENTITY_ANNA) == MAP_BASIL_HOUSE_1F || GetEntityLocation(ENTITY_ANNA) == MAP_BASIL_HOUSE_2F) && (GetEntityLocation(ENTITY_MARY) == MAP_BASIL_HOUSE_1F || GetEntityLocation(ENTITY_MARY) == MAP_BASIL_HOUSE_2F) && IsPlayerHoldingNothing() == TRUE)
                {
                    VarSet(VAR_MARY_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                    CallScript(EventScript_LoveEvent_Mary_04_YellowHeart_SuggestNovelSubject);
                }
                else
                {
                    if (VarGet(VAR_BASIL_PUBLISHING_AWARD_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_THURSDAY && (var_3 >= 16 && var_3 < 19) && GetNpcFriendship(CHARACTER_BASIL) >= 250 && (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && GetEntityLocation(ENTITY_BASIL) == MAP_BASIL_HOUSE_1F && GetEntityLocation(ENTITY_ANNA) == MAP_BASIL_HOUSE_1F && GetEntityLocation(ENTITY_MARY) == MAP_BASIL_HOUSE_1F && GetEntityLocation(ENTITY_GRAY) == MAP_BASIL_HOUSE_1F && HasMetNpc(CHARACTER_BASIL) == TRUE && HasMetNpc(CHARACTER_ANNA) == TRUE && HasMetNpc(CHARACTER_MARY) == TRUE && HasMetNpc(CHARACTER_GRAY) == TRUE)
                    {
                        VarSet(VAR_BASIL_PUBLISHING_AWARD_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_NPCEvent_Basil_PublishingAward);
                    }
                    else
                    {
                        if (VarGet(VAR_ANNA_COOKING_LESSONS_INVITATION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_4 == DAY_OF_WEEK_SATURDAY && (var_3 >= 10 && var_3 < 13) && GetNpcFriendship(CHARACTER_ANNA) >= 200 && GetEntityLocation(ENTITY_MANNA) == MAP_BASIL_HOUSE_1F && HasMetNpc(CHARACTER_MANNA) == TRUE && HasMetNpc(CHARACTER_ANNA) == TRUE)
                        {
                            VarSet(VAR_ANNA_COOKING_LESSONS_INVITATION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_NPCEvent_Anna_CookingLessonsInvitationChoice);
                        }
                        else
                        {
                            if (VarGet(VAR_ANNA_COOKING_LESSONS_INVITATION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANNA_COOKING_LESSONS_ACCEPTED) == TRUE && VarGet(VAR_ANNA_COOKING_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANNA_COOKING_LESSONS_COMPLETED_COUNT) < 5 && var_4 == DAY_OF_WEEK_SATURDAY && (var_3 >= 10 && var_3 < 13) && GetEntityLocation(ENTITY_MANNA) == MAP_BASIL_HOUSE_1F)
                            {
                                VarSet(VAR_ANNA_COOKING_LESSON_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_NPCEvent_Anna_CookingClass);
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
            TalkMessage(gText_LocationTransition_EnterBasilHouse1FWithEventDispatch_DoorIsLocked);
            TalkClose();
        }
    }
}
