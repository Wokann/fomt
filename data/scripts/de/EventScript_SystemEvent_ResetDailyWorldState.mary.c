#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_SystemEvent_ResetDailyWorldState(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    RebuildMapEntitiesForNewDay();
    var_0 = VarGet(VAR_YEAR);
    var_1 = VarGet(VAR_SEASON);
    var_2 = VarGet(VAR_DAY);
    var_3 = VarGet(VAR_DAY_OF_WEEK);
    var_4 = VarGet(VAR_WEATHER_TODAY);
    switch (GetVaseArticleId())
    {
        case ITEM_ARTICLE_FLOWER_MOON_DROP:
            ChangePlayerStaminaAndFatigue(10, 0);
            break;
        case ITEM_ARTICLE_FLOWER_PINK_CAT:
            ChangePlayerStaminaAndFatigue(0, mary_negated_int(-5));
            break;
        case ITEM_ARTICLE_FLOWER_MAGIC_BLUE:
            ChangePlayerStaminaAndFatigue(3, 0);
            break;
        case ITEM_ARTICLE_FLOWER_MAGIC_RED:
            ChangePlayerStaminaAndFatigue(0, mary_negated_int(-10));
            break;
        case ITEM_ARTICLE_FLOWER_TOY:
            ChangePlayerStaminaAndFatigue(0, mary_negated_int(-7));
            break;
    }
    VarSet(VAR_HARVEST_GODDESS_OFFERING_MADE_TODAY, FALSE);
    VarSet(VAR_KAPPA_CUCUMBER_OFFERING_MADE_TODAY, FALSE);
    VarSet(VAR_CHURCH_CONFESSION_USED_TODAY, FALSE);
    VarSet(VAR_GOLDEN_LUMBER_ANGER_EVENT_TODAY_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    if (VarGet(VAR_YEAR) == 1 && VarGet(VAR_SEASON) == SEASON_SPRING && VarGet(VAR_DAY) == DAY_OF_MONTH_03)
    {
        VarSet(VAR_TV_CARD_COLLECTOR_CHISATO_EPISODE_INDEX, 0);
        VarSet(VAR_TV_MY_DEAR_PRINCESS_EPISODE_INDEX, 0);
        VarSet(VAR_TV_DUELING_CHEFS_EPISODE_INDEX, 0);
        VarSet(VAR_TV_FAIRY_AND_ME_HIS_STORY_EPISODE_INDEX, 0);
        VarSet(VAR_TV_FAIRY_AND_ME_HER_STORY_EPISODE_INDEX, 0);
        VarSet(VAR_TV_AARON_CHANGES_EPISODE_INDEX, 0);
        VarSet(VAR_TV_MECHABOT_ULTROR_EPISODE_INDEX, 0);
        VarSet(VAR_TV_MECHABOT_ULTROR_ZERO_REMINDER_INDEX, 0);
        VarSet(VAR_TV_MINERAL_TOWN_FRIENDS_PROFILE_INDEX, 0);
        VarSet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS, 0);
        VarSet(VAR_TV_ST_EMERALD_ACADEMY_EPISODE_INDEX, 0);
        VarSet(VAR_TV_STAR_LILY_BANDIT_GIRL_EPISODE_INDEX, 0);
        VarSet(VAR_TV_MINE_RESEARCH_GROUP_EPISODE_INDEX, 0);
        VarSet(VAR_TV_FISHING_HOUR_SEGMENT_INDEX, 0);
    }
    if (VarGet(VAR_SEASON) == SEASON_SPRING && (VarGet(VAR_DAY) == DAY_OF_MONTH_01 || VarGet(VAR_DAY) == DAY_OF_MONTH_02 || VarGet(VAR_DAY) == DAY_OF_MONTH_03 || VarGet(VAR_DAY) == DAY_OF_MONTH_04 || VarGet(VAR_DAY) == DAY_OF_MONTH_05) || VarGet(VAR_SEASON) == SEASON_WINTER && (VarGet(VAR_DAY) == DAY_OF_MONTH_29 || VarGet(VAR_DAY) == DAY_OF_MONTH_30))
    {
        VarSet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS, 0);
    }
    if (!(VarGet(VAR_YEAR) == 1 && VarGet(VAR_SEASON) == SEASON_SPRING && VarGet(VAR_DAY) == DAY_OF_MONTH_06) && VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_FRIDAY)
    {
        if (VarGet(VAR_SEASON) == SEASON_SPRING && (VarGet(VAR_DAY) == DAY_OF_MONTH_01 || VarGet(VAR_DAY) == DAY_OF_MONTH_02 || VarGet(VAR_DAY) == DAY_OF_MONTH_03 || VarGet(VAR_DAY) == DAY_OF_MONTH_04 || VarGet(VAR_DAY) == DAY_OF_MONTH_05) || VarGet(VAR_SEASON) == SEASON_WINTER && (VarGet(VAR_DAY) == DAY_OF_MONTH_29 || VarGet(VAR_DAY) == DAY_OF_MONTH_30))
        {
        }
        else
        {
            if (VarGet(VAR_TV_CARD_COLLECTOR_CHISATO_EPISODE_INDEX) == 11)
            {
                VarSet(VAR_TV_CARD_COLLECTOR_CHISATO_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_CARD_COLLECTOR_CHISATO_EPISODE_INDEX, VarGet(VAR_TV_CARD_COLLECTOR_CHISATO_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_MY_DEAR_PRINCESS_EPISODE_INDEX) == 33)
            {
                VarSet(VAR_TV_MY_DEAR_PRINCESS_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_MY_DEAR_PRINCESS_EPISODE_INDEX, VarGet(VAR_TV_MY_DEAR_PRINCESS_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_DUELING_CHEFS_EPISODE_INDEX) == 11)
            {
                VarSet(VAR_TV_DUELING_CHEFS_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_DUELING_CHEFS_EPISODE_INDEX, VarGet(VAR_TV_DUELING_CHEFS_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_FAIRY_AND_ME_HIS_STORY_EPISODE_INDEX) == 37)
            {
                VarSet(VAR_TV_FAIRY_AND_ME_HIS_STORY_EPISODE_INDEX, 0);
                VarSet(VAR_TV_FAIRY_AND_ME_HER_STORY_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_FAIRY_AND_ME_HIS_STORY_EPISODE_INDEX, VarGet(VAR_TV_FAIRY_AND_ME_HIS_STORY_EPISODE_INDEX) + 1);
                VarSet(VAR_TV_FAIRY_AND_ME_HER_STORY_EPISODE_INDEX, VarGet(VAR_TV_FAIRY_AND_ME_HER_STORY_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_AARON_CHANGES_EPISODE_INDEX) == 38)
            {
                VarSet(VAR_TV_AARON_CHANGES_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_AARON_CHANGES_EPISODE_INDEX, VarGet(VAR_TV_AARON_CHANGES_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_MECHABOT_ULTROR_EPISODE_INDEX) == 47)
            {
                VarSet(VAR_TV_MECHABOT_ULTROR_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_MECHABOT_ULTROR_EPISODE_INDEX, VarGet(VAR_TV_MECHABOT_ULTROR_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_MECHABOT_ULTROR_ZERO_REMINDER_INDEX) == 19)
            {
                VarSet(VAR_TV_MECHABOT_ULTROR_ZERO_REMINDER_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_MECHABOT_ULTROR_ZERO_REMINDER_INDEX, VarGet(VAR_TV_MECHABOT_ULTROR_ZERO_REMINDER_INDEX) + 1);
            }
            if (VarGet(VAR_TV_MINERAL_TOWN_FRIENDS_PROFILE_INDEX) == 39)
            {
                VarSet(VAR_TV_MINERAL_TOWN_FRIENDS_PROFILE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_MINERAL_TOWN_FRIENDS_PROFILE_INDEX, VarGet(VAR_TV_MINERAL_TOWN_FRIENDS_PROFILE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS) == 7)
            {
                VarSet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS, 0);
            }
            else
            {
                VarSet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS, VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS) + 1);
            }
            if (VarGet(VAR_TV_ST_EMERALD_ACADEMY_EPISODE_INDEX) == 9)
            {
                VarSet(VAR_TV_ST_EMERALD_ACADEMY_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_ST_EMERALD_ACADEMY_EPISODE_INDEX, VarGet(VAR_TV_ST_EMERALD_ACADEMY_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_STAR_LILY_BANDIT_GIRL_EPISODE_INDEX) == 24)
            {
                VarSet(VAR_TV_STAR_LILY_BANDIT_GIRL_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_STAR_LILY_BANDIT_GIRL_EPISODE_INDEX, VarGet(VAR_TV_STAR_LILY_BANDIT_GIRL_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_MINE_RESEARCH_GROUP_EPISODE_INDEX) == 12)
            {
                VarSet(VAR_TV_MINE_RESEARCH_GROUP_EPISODE_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_MINE_RESEARCH_GROUP_EPISODE_INDEX, VarGet(VAR_TV_MINE_RESEARCH_GROUP_EPISODE_INDEX) + 1);
            }
            if (VarGet(VAR_TV_FISHING_HOUR_SEGMENT_INDEX) == 3)
            {
                VarSet(VAR_TV_FISHING_HOUR_SEGMENT_INDEX, 0);
            }
            else
            {
                VarSet(VAR_TV_FISHING_HOUR_SEGMENT_INDEX, VarGet(VAR_TV_FISHING_HOUR_SEGMENT_INDEX) + 1);
            }
        }
    }
    if (VarGet(VAR_SEASON) == SEASON_SPRING && VarGet(VAR_DAY) == DAY_OF_MONTH_01)
    {
        if (HasMetNpc(CHARACTER_CLIFF) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_CLIFF) >= 100)
            {
                if (VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_CLIFF_AND_ANN);
                }
                else
                {
                    if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE && VarGet(VAR_YEAR) >= 2)
                    {
                        DeliverLetter(LETTER_NEW_YEAR_CLIFF_AT_INN);
                    }
                    else
                    {
                        if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
                        {
                            DeliverLetter(LETTER_NEW_YEAR_CLIFF_AT_WINERY);
                        }
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_DOCTOR) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_DOCTOR) >= 100)
            {
                if (VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_DOCTOR_WITH_ELLI);
                }
                else
                {
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        DeliverLetter(LETTER_NEW_YEAR_MINERAL_CLINIC);
                    }
                    else
                    {
                        DeliverLetter(LETTER_NEW_YEAR_DOCTOR_AND_ELLI);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_RICK) == TRUE || HasMetNpc(CHARACTER_POPURI) == TRUE || HasMetNpc(CHARACTER_LILLIA) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_RICK) >= 100 || GetNpcFriendship(CHARACTER_POPURI) >= 100 || GetNpcFriendship(CHARACTER_LILLIA) >= 100)
            {
                if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_POPURI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_POULTRY_FARM_FAMILY);
                }
                if (VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_POULTRY_FARM_RICK_AND_KAREN);
                }
                else
                {
                    if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        DeliverLetter(LETTER_NEW_YEAR_POULTRY_FARM_WITHOUT_POPURI);
                    }
                    if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        DeliverLetter(LETTER_NEW_YEAR_POULTRY_FARM_TO_POPURI);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_GRAY) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_GRAY) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_GRAY_FORMAL);
            }
            else
            {
                DeliverLetter(LETTER_NEW_YEAR_GRAY_FRIENDLY);
            }
        }
        if (HasMetNpc(CHARACTER_KAI) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_KAI) >= 100)
            {
                if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_KAI_AND_POPURI);
                }
                else
                {
                    DeliverLetter(LETTER_NEW_YEAR_KAI);
                }
            }
        }
        if (HasMetNpc(CHARACTER_JEFF) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_JEFF) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_JEFF);
            }
        }
        if (HasMetNpc(CHARACTER_SAIBARA) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_SAIBARA) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_SAIBARA);
            }
        }
        if (HasMetNpc(CHARACTER_DOUG) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_DOUG) >= 100)
            {
                if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_DOUG_TO_ANN_AND_PLAYER);
                }
                else
                {
                    DeliverLetter(LETTER_NEW_YEAR_DOUG_INN);
                }
            }
        }
        if (HasMetNpc(CHARACTER_CARTER) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_CARTER) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_CARTER);
            }
        }
        if (HasMetNpc(CHARACTER_BASIL) == TRUE && HasMetNpc(CHARACTER_ANNA) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_BASIL) >= 100 || GetNpcFriendship(CHARACTER_ANNA) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_BASIL_AND_ANNA);
            }
        }
        if (HasMetNpc(CHARACTER_MAY) == TRUE && HasMetNpc(CHARACTER_BARLEY) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_MAY) >= 100 && GetNpcFriendship(CHARACTER_BARLEY) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_MAY_AND_BARLEY);
            }
        }
        if (HasMetNpc(CHARACTER_THOMAS) == TRUE && HasMetNpc(CHARACTER_HARRIS) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_THOMAS) >= 100 && GetNpcFriendship(CHARACTER_HARRIS) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_THOMAS_AND_HARRIS_TOWN);
            }
            else
            {
                DeliverLetter(LETTER_NEW_YEAR_THOMAS_AND_HARRIS_FARM);
            }
        }
        if (HasMetNpc(CHARACTER_MANNA) == TRUE && HasMetNpc(CHARACTER_DUKE) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_MANNA) >= 100 && GetNpcFriendship(CHARACTER_DUKE) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_MANNA_AND_DUKE);
            }
        }
        if (HasMetNpc(CHARACTER_ELLEN) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_ELLEN) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_ELLEN);
            }
        }
        if (HasMetNpc(CHARACTER_STAID) == TRUE && HasMetNpc(CHARACTER_NAPPY) == TRUE && HasMetNpc(CHARACTER_CHEF) == TRUE && HasMetNpc(CHARACTER_AQUA) == TRUE && HasMetNpc(CHARACTER_HOGGY) == TRUE && HasMetNpc(CHARACTER_TIMID) == TRUE && HasMetNpc(CHARACTER_STAID) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_STAID) >= 100 && GetNpcFriendship(CHARACTER_BOLD) >= 100 && GetNpcFriendship(CHARACTER_CHEF) >= 100 && GetNpcFriendship(CHARACTER_AQUA) >= 100 && GetNpcFriendship(CHARACTER_HOGGY) >= 100 && GetNpcFriendship(CHARACTER_TIMID) >= 100 && GetNpcFriendship(CHARACTER_STAID) >= 100)
            {
                DeliverLetter(LETTER_NEW_YEAR_HARVEST_SPRITES);
            }
        }
        if (HasMetNpc(CHARACTER_POPURI) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_POPURI) >= 100)
            {
                if (VarGet(VAR_KAREN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_POPURI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ANN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_MARY_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ELLI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_POPURI);
                }
            }
        }
        if (HasMetNpc(CHARACTER_ANN) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_ANN) >= 100)
            {
                if (VarGet(VAR_KAREN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_POPURI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ANN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_MARY_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ELLI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_ANN);
                }
            }
        }
        if (HasMetNpc(CHARACTER_KAREN) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_KAREN) >= 100)
            {
                if (VarGet(VAR_KAREN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_POPURI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ANN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_MARY_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ELLI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_KAREN);
                }
            }
        }
        if (HasMetNpc(CHARACTER_ELLI) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_ELLI) >= 100)
            {
                if (VarGet(VAR_KAREN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_POPURI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ANN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_MARY_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ELLI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_ELLI);
                }
            }
        }
        if (HasMetNpc(CHARACTER_MARY) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_MARY) >= 100)
            {
                if (VarGet(VAR_KAREN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_POPURI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ANN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_MARY_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_ELLI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
                {
                    DeliverLetter(LETTER_NEW_YEAR_MARY);
                }
            }
        }
    }
    if (VarGet(VAR_SEASON) == VarGet(VAR_PLAYER_BIRTHDAY_SEASON) && VarGet(VAR_DAY) == VarGet(VAR_PLAYER_BIRTHDAY_DAY))
    {
        if (HasMetNpc(CHARACTER_POPURI) == TRUE)
        {
            if (VarGet(VAR_POPURI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
            {
                if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    if (GetNpcFriendship(CHARACTER_POPURI) >= 200)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_POPURI);
                    }
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_POPURI);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_ANN) == TRUE)
        {
            if (VarGet(VAR_ANN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
            {
                if (VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    if (GetNpcFriendship(CHARACTER_ANN) >= 200)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_ANN);
                    }
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_YELLOW_MIN)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_ANN);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_KAREN) == TRUE)
        {
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
            {
                if (VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    if (GetNpcFriendship(CHARACTER_KAREN) >= 200)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_KAREN);
                    }
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_YELLOW_MIN)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_KAREN);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_ELLI) == TRUE)
        {
            if (VarGet(VAR_ELLI_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
            {
                if (VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    if (GetNpcFriendship(CHARACTER_ELLI) >= 200)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_ELLI);
                    }
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_YELLOW_MIN)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_ELLI);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_MARY) == TRUE)
        {
            if (VarGet(VAR_MARY_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
            {
                if (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    if (GetNpcFriendship(CHARACTER_MARY) >= 200)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_MARY);
                    }
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_YELLOW_MIN)
                    {
                        DeliverLetter(LETTER_BIRTHDAY_MARY);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_KAI) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_KAI) >= 100)
            {
                DeliverLetter(LETTER_BIRTHDAY_KAI);
            }
        }
        if (HasMetNpc(CHARACTER_CLIFF) == TRUE)
        {
            if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE && VarGet(VAR_YEAR) >= 2)
            {
                if (GetNpcFriendship(CHARACTER_CLIFF) >= 100)
                {
                    DeliverLetter(LETTER_BIRTHDAY_CLIFF);
                }
            }
        }
        if (HasMetNpc(CHARACTER_DOCTOR) == TRUE)
        {
            if (GetNpcFriendship(CHARACTER_DOCTOR) >= 100)
            {
                DeliverLetter(LETTER_BIRTHDAY_DOCTOR);
            }
        }
    }
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (HasMetNpc(CHARACTER_KAI) == TRUE && HasMetNpc(CHARACTER_POPURI) == TRUE)
        {
            if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (HasReceivedLetter(LETTER_CHILD_BIRTH_KAI_AND_POPURI) == FALSE)
                {
                    if (VarGet(VAR_CHILD_AGE_DAYS) <= 5)
                    {
                        DeliverLetter(LETTER_CHILD_BIRTH_KAI_AND_POPURI);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_CLIFF) == TRUE && HasMetNpc(CHARACTER_ANN) == TRUE)
        {
            if (VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (HasReceivedLetter(LETTER_CHILD_BIRTH_CLIFF_AND_ANN) == FALSE)
                {
                    if (VarGet(VAR_CHILD_AGE_DAYS) <= 5)
                    {
                        DeliverLetter(LETTER_CHILD_BIRTH_CLIFF_AND_ANN);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_RICK) == TRUE && HasMetNpc(CHARACTER_KAREN) == TRUE)
        {
            if (VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (HasReceivedLetter(LETTER_CHILD_BIRTH_RICK_AND_KAREN) == FALSE)
                {
                    if (VarGet(VAR_CHILD_AGE_DAYS) <= 5)
                    {
                        DeliverLetter(LETTER_CHILD_BIRTH_RICK_AND_KAREN);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_DOCTOR) == TRUE && HasMetNpc(CHARACTER_ELLI) == TRUE)
        {
            if (VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (HasReceivedLetter(LETTER_CHILD_BIRTH_DOCTOR_AND_ELLI) == FALSE)
                {
                    if (VarGet(VAR_CHILD_AGE_DAYS) <= 5)
                    {
                        DeliverLetter(LETTER_CHILD_BIRTH_DOCTOR_AND_ELLI);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_GRAY) == TRUE && HasMetNpc(CHARACTER_MARY) == TRUE)
        {
            if (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (HasReceivedLetter(LETTER_CHILD_BIRTH_MARY_AND_GRAY) == FALSE)
                {
                    if (VarGet(VAR_CHILD_AGE_DAYS) <= 5)
                    {
                        DeliverLetter(LETTER_CHILD_BIRTH_MARY_AND_GRAY);
                    }
                }
            }
        }
        if (HasMetNpc(CHARACTER_THOMAS) == TRUE && HasMetNpc(CHARACTER_HARRIS) == TRUE)
        {
            if (HasReceivedLetter(LETTER_CHILD_BIRTH_THOMAS_AND_HARRIS) == FALSE)
            {
                DeliverLetter(LETTER_CHILD_BIRTH_THOMAS_AND_HARRIS);
            }
        }
    }
    if (GetAmountShipped(PRODUCT_TURNIP) >= 100 && GetAmountShipped(PRODUCT_POTATO) >= 100 && GetAmountShipped(PRODUCT_CUCUMBER) >= 100)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_STRAWBERRY_SEEDS) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_STRAWBERRY_SEEDS);
        }
    }
    if (GetAmountShipped(PRODUCT_TOMATO) >= 100 && GetAmountShipped(PRODUCT_CORN) >= 100 && GetAmountShipped(PRODUCT_ONION) >= 100)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_PUMPKIN_SEEDS) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_PUMPKIN_SEEDS);
        }
    }
    if (GetAmountShipped(PRODUCT_EGGPLANT) >= 100 && GetAmountShipped(PRODUCT_CARROT) >= 100 && GetAmountShipped(PRODUCT_SWEET_POTATO) >= 100)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_SPINACH_SEEDS) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_SPINACH_SEEDS);
        }
    }
    if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_ORANGE_MIN || GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_ORANGE_MIN || GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_ORANGE_MIN || GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_ORANGE_MIN || GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_ORANGE_MIN || GetCharacterLove(CHARACTER_HARVEST_GODDESS) >= LOVE_HEART_ORANGE_MIN)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_BLUE_FEATHER) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_BLUE_FEATHER);
        }
    }
    if (GetAmountShipped(PRODUCT_BLUE_GRASS) >= 50)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_BODIGIZER_XL) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_BODIGIZER_XL);
        }
    }
    if (GetAmountShipped(PRODUCT_GREEN_GRASS) >= 50)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_TURBOJOLT_XL) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_TURBOJOLT_XL);
        }
    }
    if ((GetCowCount() >= 1 || GetSheepCount() >= 1 || VarGet(VAR_BARLEY_FOAL_OFFER_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_HAS_HORSE) == TRUE) && PlayerOwnsTool(ITEM_TOOL_BRUSH) == FALSE)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_BRUSH) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_BRUSH);
        }
    }
    if (GetCowCount() >= 1 && PlayerOwnsTool(ITEM_TOOL_MILKER) == FALSE)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_MILKER) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_MILKER);
        }
    }
    if (GetSheepCount() >= 1 && PlayerOwnsTool(ITEM_TOOL_CLIPPER_OR_CLIPPERS) == FALSE)
    {
        if (HasReceivedLetter(LETTER_SHOP_NEWS_CLIPPERS) == FALSE)
        {
            DeliverLetter(LETTER_SHOP_NEWS_CLIPPERS);
        }
    }
    if (HasMetNpc(CHARACTER_GRAY) == TRUE && HasMetNpc(CHARACTER_MARY) == TRUE)
    {
        if (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            if (HasReceivedLetter(LETTER_LIBRARY_DAY_OFF_CHANGE) == FALSE)
            {
                DeliverLetter(LETTER_LIBRARY_DAY_OFF_CHANGE);
            }
        }
    }
    if (var_1 == SEASON_SUMMER && (var_2 == DAY_OF_MONTH_01 || var_2 == DAY_OF_MONTH_02))
    {
        VarSet(VAR_HARVEST_SPRITE_TEA_PARTY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    if (!PlayerOwnsArticle(ITEM_ARTICLE_INVITATION) && VarGet(VAR_HARVEST_SPRITE_TEA_PARTY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SPRING && (var_2 == DAY_OF_MONTH_30 || RandomIntInclusive(0, 99) < 30) && GetNpcFriendship(CHARACTER_STAID) >= 75 && GetNpcFriendship(CHARACTER_NAPPY) >= 75 && GetNpcFriendship(CHARACTER_BOLD) >= 75 && GetNpcFriendship(CHARACTER_CHEF) >= 75 && GetNpcFriendship(CHARACTER_AQUA) >= 75 && GetNpcFriendship(CHARACTER_HOGGY) >= 75 && GetNpcFriendship(CHARACTER_TIMID) >= 75)
    {
        DeliverLetter(LETTER_HARVEST_SPRITE_TEA_PARTY_INVITATION);
    }
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (HasReceivedLetter(LETTER_STAFF_CREDITS) == FALSE)
        {
            DeliverLetter(LETTER_STAFF_CREDITS);
        }
    }
    if (VarGet(VAR_RICK_AND_POPURI_SICK_LILLIA_FOLLOWUP_STATE) == TRUE)
    {
        VarSet(VAR_RICK_AND_POPURI_SICK_LILLIA_FOLLOWUP_STATE, FALSE);
    }
    if (VarGet(VAR_POPURI_BLUE_HEART_EVENT_CHOICE) == POPURI_BLUE_HEART_RESPONSE_RETURN_TO_WORK)
    {
        VarSet(VAR_POPURI_BLUE_HEART_EVENT_CHOICE, POPURI_BLUE_HEART_RESPONSE_PLAY_WITH_CHILDREN);
    }
    if (VarGet(VAR_CLIFF_COLLAPSE_FOLLOWUP_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        if (VarGet(VAR_CLIFF_COLLAPSE_FOLLOWUP_DELAY_DAY_COUNTER) <= 2)
        {
            VarSet(VAR_CLIFF_COLLAPSE_FOLLOWUP_DELAY_DAY_COUNTER, VarGet(VAR_CLIFF_COLLAPSE_FOLLOWUP_DELAY_DAY_COUNTER) + 1);
        }
        else
        {
            VarSet(VAR_CLIFF_COLLAPSE_FOLLOWUP_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (VarGet(VAR_PLAYER_SNEAKS_PAST_SLEEPING_CARTER_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        VarSet(VAR_PLAYER_SNEAKS_PAST_SLEEPING_CARTER_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    if (var_2 == DAY_OF_MONTH_30 || var_2 == DAY_OF_MONTH_01)
    {
        VarSet(VAR_WON_APPLE_CHALLENGE_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_WON_VASE_PURCHASE_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    if (var_1 == SEASON_WINTER && (var_2 == DAY_OF_MONTH_02 || var_2 == DAY_OF_MONTH_03 || var_2 == DAY_OF_MONTH_04))
    {
        VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_CHOICE, THOMAS_RANDOM_ITEM_REQUEST_ACCEPTED);
        VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
    }
    if (VarGet(VAR_HARRIS_AJA_LETTER_ADVICE_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_HARRIS_AJA_LETTER_ADVICE_CHOICE) == HARRIS_AJA_LETTER_ADVICE_TELL_HER_FEELINGS && VarGet(VAR_DAYS_SINCE_HARRIS_AJA_LETTER_ADVICE) < 20)
    {
        VarSet(VAR_DAYS_SINCE_HARRIS_AJA_LETTER_ADVICE, VarGet(VAR_DAYS_SINCE_HARRIS_AJA_LETTER_ADVICE) + 1);
    }
    if (VarGet(VAR_ANNA_COOKING_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        VarSet(VAR_ANNA_COOKING_LESSON_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    if (VarGet(VAR_BARLEY_HORSE_YEAR_EVALUATION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_BARLEY_REPLACEMENT_FOAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_FAILED_HORSE_YEAR_EVALUATION) < 120 && VarGet(VAR_HAS_HORSE) == FALSE)
    {
        VarSet(VAR_DAYS_SINCE_FAILED_HORSE_YEAR_EVALUATION, VarGet(VAR_DAYS_SINCE_FAILED_HORSE_YEAR_EVALUATION) + 1);
    }
    if (var_0 == 1 && var_1 == SEASON_FALL && (var_2 == DAY_OF_MONTH_16 || var_2 == DAY_OF_MONTH_17) && VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
    {
        VarSet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    }
    if (VarGet(VAR_ENTERED_FARMHOUSE_TODAY) == TRUE)
    {
        VarSet(VAR_ENTERED_FARMHOUSE_TODAY, FALSE);
    }
    if (VarGet(VAR_KAPPA_DAILY_APPEARANCE_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        VarSet(VAR_KAPPA_DAILY_APPEARANCE_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    if (var_1 == SEASON_SPRING && (var_2 == DAY_OF_MONTH_19 || var_2 == DAY_OF_MONTH_20))
    {
        ClearContestAnimal(ANIMAL_KIND_HORSE);
        VarSet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
    }
    if (var_1 == SEASON_SUMMER && (var_2 == DAY_OF_MONTH_02 || var_2 == DAY_OF_MONTH_03))
    {
        ClearContestAnimal(ANIMAL_KIND_DOG);
        VarSet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED, FALSE);
        VarSet(VAR_FRISBEE_TOURNAMENT_RESULT, FESTIVAL_CONTEST_RESULT_NOT_WON);
    }
    if (var_1 == SEASON_SUMMER && (var_2 == DAY_OF_MONTH_08 || var_2 == DAY_OF_MONTH_09))
    {
        ClearContestAnimal(ANIMAL_KIND_CHICKEN);
        VarSet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_CHICKEN_FESTIVAL_RESULT, FESTIVAL_CONTEST_RESULT_NOT_WON);
    }
    if (var_1 == SEASON_SUMMER && (var_2 == DAY_OF_MONTH_21 || var_2 == DAY_OF_MONTH_22))
    {
        ClearContestAnimal(ANIMAL_KIND_COW);
        VarSet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_COW_FESTIVAL_PLAYER_RESULT, FESTIVAL_CONTEST_RESULT_NOT_WON);
    }
    if (var_1 == SEASON_FALL && (var_2 == DAY_OF_MONTH_19 || var_2 == DAY_OF_MONTH_20))
    {
        ClearContestAnimal(ANIMAL_KIND_HORSE);
        VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
    }
    if (var_1 == SEASON_FALL && (var_2 == DAY_OF_MONTH_22 || var_2 == DAY_OF_MONTH_23))
    {
        ClearContestAnimal(ANIMAL_KIND_SHEEP);
        VarSet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_SHEEP_FESTIVAL_RESULT, FESTIVAL_CONTEST_RESULT_NOT_WON);
    }
    if (var_0 == 1 && var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30 || var_0 == 2 && var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01)
    {
        if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE && VarGet(VAR_CLIFF_LEAVES_MINERAL_TOWN_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
        {
            VarSet(VAR_CLIFF_LEAVES_MINERAL_TOWN_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        if (VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2)
        {
            VarSet(VAR_WEDDING_ANNIVERSARIES_ELAPSED, VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) + 1);
        }
        if (VarGet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_POPURI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
        }
        ClearEntityEventScript(ENTITY_POPURI);
        ClearEntityEventScript(ENTITY_CHILD);
        VarSet(VAR_POPURI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        if (VarGet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_POPURI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        if (VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2)
        {
            VarSet(VAR_WEDDING_ANNIVERSARIES_ELAPSED, VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) + 1);
        }
        if (VarGet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_ANN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
        }
        ClearEntityEventScript(ENTITY_ANN);
        ClearEntityEventScript(ENTITY_CHILD);
        VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
        if (VarGet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ANN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        if (VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2)
        {
            VarSet(VAR_WEDDING_ANNIVERSARIES_ELAPSED, VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) + 1);
        }
        if (VarGet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_ELLI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
        }
        ClearEntityEventScript(ENTITY_ELLI);
        ClearEntityEventScript(ENTITY_CHILD);
        VarSet(VAR_ELLI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
        if (VarGet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ELLI_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        if (VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2)
        {
            VarSet(VAR_WEDDING_ANNIVERSARIES_ELAPSED, VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) + 1);
        }
        if (VarGet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_KAREN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
        }
        ClearEntityEventScript(ENTITY_KAREN);
        ClearEntityEventScript(ENTITY_CHILD);
        VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
        if (VarGet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_KAREN_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        if (VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2)
        {
            VarSet(VAR_WEDDING_ANNIVERSARIES_ELAPSED, VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) + 1);
        }
        if (VarGet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_MARY_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
        }
        ClearEntityEventScript(ENTITY_MARY);
        ClearEntityEventScript(ENTITY_CHILD);
        VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
        if (VarGet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        if (VarGet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_MARY_SPOUSE_COLLAPSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2)
        {
            VarSet(VAR_WEDDING_ANNIVERSARIES_ELAPSED, VarGet(VAR_WEDDING_ANNIVERSARIES_ELAPSED) + 1);
        }
        if (VarGet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            DisableScriptedNpcControl();
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
        }
        ClearEntityEventScript(ENTITY_HARVEST_GODDESS);
        ClearEntityEventScript(ENTITY_CHILD);
        VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        if (VarGet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
    }
    if (var_1 == SEASON_SPRING && (var_2 == DAY_OF_MONTH_15 || var_2 == DAY_OF_MONTH_16))
    {
        VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_POPURI, FALSE);
        VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_ANN, FALSE);
        VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_ELLI, FALSE);
        VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_KAREN, FALSE);
        VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_MARY, FALSE);
    }
    if (var_1 == SEASON_FALL && (var_2 == DAY_OF_MONTH_10 || var_2 == DAY_OF_MONTH_11))
    {
        VarSet(VAR_HARVEST_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
        ClearEntityEventScript(ENTITY_THOMAS);
        ClearEntityEventScript(ENTITY_ELLI);
        ClearEntityEventScript(ENTITY_CARTER);
        ClearEntityEventScript(ENTITY_ANN);
        ClearEntityEventScript(ENTITY_GOTZ);
        ClearEntityEventScript(ENTITY_KAREN);
        ClearEntityEventScript(ENTITY_DOUG);
        ClearEntityEventScript(ENTITY_MARY);
        ClearEntityEventScript(ENTITY_SASHA);
        ClearEntityEventScript(ENTITY_ANNA);
        ClearEntityEventScript(ENTITY_MANNA);
    }
    if (var_1 == SEASON_FALL && (var_2 == DAY_OF_MONTH_14 || var_2 == DAY_OF_MONTH_15))
    {
        VarSet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        switch (VarGet(VAR_FESTIVAL_MOON_VIEWING_PARTNER_INDEX))
        {
            case FESTIVAL_MOON_VIEWING_PARTNER_KAREN:
                var_5 = ENTITY_KAREN;
                break;
            case FESTIVAL_MOON_VIEWING_PARTNER_ANN:
                var_5 = ENTITY_ANN;
                break;
            case FESTIVAL_MOON_VIEWING_PARTNER_POPURI:
                var_5 = ENTITY_POPURI;
                break;
            case FESTIVAL_MOON_VIEWING_PARTNER_MARY:
                var_5 = ENTITY_MARY;
                break;
            case FESTIVAL_MOON_VIEWING_PARTNER_ELLI:
                var_5 = ENTITY_ELLI;
                break;
        }
        ClearEntityEventScript(var_5);
    }
    if (VarGet(VAR_RICK_KAREN_WEDDING_MISSED))
    {
        VarSet(VAR_RICK_KAREN_WEDDING_MISSED, FALSE);
        VarSet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE, FALSE);
        ClearEntityEventScript(ENTITY_CARTER);
        ClearEntityEventScript(ENTITY_RICK);
        ClearEntityEventScript(ENTITY_LILLIA);
        ClearEntityEventScript(ENTITY_JEFF);
        ClearEntityEventScript(ENTITY_KAREN);
        ClearEntityEventScript(ENTITY_SASHA);
        AddNpcFriendship(CHARACTER_KAREN, mary_negated_int(-10));
        AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
        AddNpcFriendship(CHARACTER_LILLIA, mary_negated_int(-10));
        AddNpcFriendship(CHARACTER_JEFF, mary_negated_int(-10));
        AddNpcFriendship(CHARACTER_SASHA, mary_negated_int(-10));
        SetNpcFriendship(CHARACTER_RICK, 100);
        VarSet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
    }
    else
    {
        if (VarGet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE) == TRUE)
        {
            VarSet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE, FALSE);
            VarSet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
        }
        else
        {
            if (VarGet(VAR_POPURI_KAI_WEDDING_MISSED))
            {
                VarSet(VAR_POPURI_KAI_WEDDING_MISSED, FALSE);
                VarSet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                ClearEntityEventScript(ENTITY_RICK);
                ClearEntityEventScript(ENTITY_POPURI);
                ClearEntityEventScript(ENTITY_LILLIA);
                ClearEntityEventScript(ENTITY_KAREN);
                ClearEntityEventScript(ENTITY_CARTER);
                ClearEntityEventScript(ENTITY_KAI);
                AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
                AddNpcFriendship(CHARACTER_LILLIA, mary_negated_int(-10));
                AddNpcFriendship(CHARACTER_RICK, mary_negated_int(-10));
                AddNpcFriendship(CHARACTER_KAREN, mary_negated_int(-10));
                SetNpcFriendship(CHARACTER_POPURI, 100);
                VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
            }
            else
            {
                if (VarGet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE) == TRUE)
                {
                    VarSet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                    VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                }
                else
                {
                    if (VarGet(VAR_ANN_CLIFF_WEDDING_MISSED))
                    {
                        VarSet(VAR_ANN_CLIFF_WEDDING_MISSED, FALSE);
                        VarSet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                        ClearEntityEventScript(ENTITY_CLIFF);
                        ClearEntityEventScript(ENTITY_DOUG);
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_DUKE);
                        ClearEntityEventScript(ENTITY_MANNA);
                        ClearEntityEventScript(ENTITY_CARTER);
                        AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
                        AddNpcFriendship(CHARACTER_MANNA, mary_negated_int(-10));
                        AddNpcFriendship(CHARACTER_DUKE, mary_negated_int(-10));
                        AddNpcFriendship(CHARACTER_DOUG, mary_negated_int(-10));
                        SetNpcFriendship(CHARACTER_ANN, 100);
                        SetNpcFriendship(CHARACTER_CLIFF, 100);
                        VarSet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                    }
                    else
                    {
                        if (VarGet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE) == TRUE)
                        {
                            VarSet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                            VarSet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                        }
                        else
                        {
                            if (VarGet(VAR_MARY_GRAY_WEDDING_MISSED))
                            {
                                VarSet(VAR_MARY_GRAY_WEDDING_MISSED, FALSE);
                                VarSet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                                ClearEntityEventScript(ENTITY_BASIL);
                                ClearEntityEventScript(ENTITY_MARY);
                                ClearEntityEventScript(ENTITY_ANNA);
                                ClearEntityEventScript(ENTITY_CARTER);
                                ClearEntityEventScript(ENTITY_GRAY);
                                ClearEntityEventScript(ENTITY_SAIBARA);
                                AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
                                AddNpcFriendship(CHARACTER_SAIBARA, mary_negated_int(-10));
                                AddNpcFriendship(CHARACTER_ANNA, mary_negated_int(-10));
                                AddNpcFriendship(CHARACTER_BASIL, mary_negated_int(-10));
                                SetNpcFriendship(CHARACTER_MARY, 100);
                                SetNpcFriendship(CHARACTER_GRAY, 100);
                                VarSet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                            }
                            else
                            {
                                if (VarGet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE) == TRUE)
                                {
                                    VarSet(VAR_MARY_AND_GRAY_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                                    VarSet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                                }
                                else
                                {
                                    if (VarGet(VAR_ELLI_DOCTOR_WEDDING_MISSED))
                                    {
                                        VarSet(VAR_ELLI_DOCTOR_WEDDING_MISSED, FALSE);
                                        VarSet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                                        ClearEntityEventScript(ENTITY_DOCTOR);
                                        ClearEntityEventScript(ENTITY_ELLEN);
                                        ClearEntityEventScript(ENTITY_ELLI);
                                        ClearEntityEventScript(ENTITY_STU);
                                        ClearEntityEventScript(ENTITY_HARRIS);
                                        ClearEntityEventScript(ENTITY_CARTER);
                                        AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
                                        AddNpcFriendship(CHARACTER_ELLEN, mary_negated_int(-10));
                                        AddNpcFriendship(CHARACTER_STU, mary_negated_int(-10));
                                        AddNpcFriendship(CHARACTER_HARRIS, mary_negated_int(-10));
                                        SetNpcFriendship(CHARACTER_ELLI, 100);
                                        SetNpcFriendship(CHARACTER_DOCTOR, 100);
                                        VarSet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE) == TRUE)
                                        {
                                            VarSet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                                            VarSet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
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
    if (var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_25)
    {
        VarSet(VAR_THOMAS_STOCKING_GIFT_SELECTION, SelectThomasStockingGift());
    }
    if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22)
    {
        if (var_0 >= 6)
        {
            VarSet(VAR_COOKING_FESTIVAL_DISH_CATEGORY, RandomIntInclusive(0, 4));
        }
        else
        {
            VarSet(VAR_COOKING_FESTIVAL_DISH_CATEGORY, var_0 - 1);
        }
    }
    if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 && VarGet(VAR_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED)
    {
        PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_NPC_ONLY);
    }
    if (var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 && VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED)
    {
        PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_NPC_ONLY);
    }
    if (var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01)
    {
        PrepareAnimalFestivalOpponents();
    }
    if (var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13)
    {
        VarSet(VAR_FESTIVAL_MOON_VIEWING_PARTNER_INDEX, SelectMoonViewingPartner());
    }
    if (HasGoldenLumberOnFarm())
    {
        VarSet(VAR_GOLDEN_LUMBER_WAS_ON_FARM_AT_DAY_START, TRUE);
    }
    else
    {
        VarSet(VAR_GOLDEN_LUMBER_WAS_ON_FARM_AT_DAY_START, FALSE);
    }
    if (var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_02)
    {
        VarSet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_KAREN, FALSE);
        VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI, FALSE);
        VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_ANN, FALSE);
        VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_ELLI, FALSE);
        VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_MARY, FALSE);
        VarSet(VAR_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_COOKING_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_COOKING_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_COOKING_FESTIVAL_COMPLETED, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_FRISBEE_TOURNAMENT_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_BEACH_DAY_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_CHICKEN_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_CHICKEN_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_COW_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_COW_FESTIVAL_SESSION_STATE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_MUSIC_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_MUSIC_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_MUSIC_FESTIVAL_PLAYER_PERFORMANCE_ACCEPTED, FALSE);
        VarSet(VAR_HARVEST_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_HARVEST_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_HARVEST_FESTIVAL_SESSION_PHASE, HARVEST_FESTIVAL_SESSION_BEFORE_JUDGING);
        VarSet(VAR_UNKNOWN_022, FALSE);
        VarSet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_NOT_TRIGGERED);
        VarSet(VAR_SHEEP_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
        VarSet(VAR_PUMPKIN_FESTIVAL_MAY_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_PUMPKIN_FESTIVAL_STU_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_PUMPKIN_FESTIVAL_POPURI_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_WINTER_THANKSGIVING_POPURI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_WINTER_THANKSGIVING_ANN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_WINTER_THANKSGIVING_ELLI_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_WINTER_THANKSGIVING_KAREN_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_WINTER_THANKSGIVING_MARY_VISIT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_UNKNOWN_SLOT_449, 0);
        VarSet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX, STARRY_NIGHT_HOST_NONE);
        VarSet(VAR_STARRY_NIGHT_POPURI_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_STARRY_NIGHT_ANN_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_STARRY_NIGHT_ELLI_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_STARRY_NIGHT_KAREN_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_STARRY_NIGHT_MARY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_STARRY_NIGHT_POPURI_INVITATION_HANDLED, FALSE);
        VarSet(VAR_STARRY_NIGHT_ANN_INVITATION_HANDLED, FALSE);
        VarSet(VAR_STARRY_NIGHT_ELLI_INVITATION_HANDLED, FALSE);
        VarSet(VAR_STARRY_NIGHT_KAREN_INVITATION_HANDLED, FALSE);
        VarSet(VAR_STARRY_NIGHT_MARY_INVITATION_HANDLED, FALSE);
        VarSet(VAR_STARRY_NIGHT_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_THOMAS_STOCKING_DELIVERY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_NEW_YEAR_SUNRISE_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_KAI_RETURN_GREETING_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_KAI_LEAVES_AFTER_SUMMER_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_POPURI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ANN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ELLI_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_MARY_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_SHOOTING_STAR_WISH_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        VarSet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    if (VarGet(VAR_PLAYER_COLLAPSE_RECOVERY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        VarSet(VAR_PLAYER_COLLAPSE_RECOVERY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        if (!(VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2 || VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2 || VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2 || VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2 || VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2 || VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_WEDDING_SEASON) == var_1 && VarGet(VAR_WEDDING_DAY) == var_2))
        {
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
        }
    }
    CallScript(EventScript_SystemEvent_ScheduleDailyEvents);
}
