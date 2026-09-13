#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Instructions[] =
        "　■海岸で遊ぶときの注意■{Press}\p"
        "ペットの犬とフリスビーで\r\n"
        "遊ぶためには…{Press}\p"
        "·フリスビーを各自で\r\n"
        "　用意すること\r\n"
        "·おとなの犬をつれてくること{Press}\p"
        "遊べるのは…{Press}\p"
        "·春夏秋の月　晴れの日\r\n"
        "·ＡＭ６時～ＰＭ５時{Press}\p"
        "以上の注意をよく守って\r\n"
        "楽しく遊びましょう！{Press}";

    const char gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Option[] =
        "フリスビーで遊びますか？";

    const char gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Accept[] =
        "遊ぶ";

    const char gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Decline[] =
        "遊ばない";
};

void EventScript_FarmEvent_Dog_BeachFrisbeePracticeChoice(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6, var_7;
    var_5 = TRUE;
    var_1 = VarGet(VAR_SEASON);
    var_2 = VarGet(VAR_DAY);
    var_3 = VarGet(VAR_HOUR);
    var_4 = VarGet(VAR_WEATHER_TODAY);
    if (VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        RunFrisbeeTournamentRound();
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    else
    {
        TalkOpen();
        TalkAppendMessage(gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Instructions);
        TalkClose();
        if (var_1 != SEASON_WINTER && var_3 >= 6 && var_3 < 17 && var_4 == WEATHER_SUNNY && VarGet(VAR_DOG_GROWTH_STAGE) == ANIMAL_PET_GROWTH_STAGE_ADULT && VarGet(VAR_FIREWORKS_FESTIVAL_ACTIVE) != FESTIVAL_PHASE_INITIAL && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE) != EVENT_LIFECYCLE_IN_PROGRESS && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE) != EVENT_LIFECYCLE_IN_PROGRESS && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE) != EVENT_LIFECYCLE_IN_PROGRESS && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) != EVENT_LIFECYCLE_IN_PROGRESS)
        {
            var_6 = FALSE;
            if (FindArticleInRucksack(ITEM_ARTICLE_FRISBEE) != mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
            {
                var_6 = TRUE;
            }
            else
            {
                if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE && GetPlayerHeldArticleId() == ITEM_ARTICLE_FRISBEE)
                {
                    var_6 = TRUE;
                }
            }
            var_7 = FALSE;
            if (GetEntityLocation(ENTITY_FARM_DOG) == MAP_MINERAL_BEACH || !IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_DOG)
            {
                var_7 = TRUE;
            }
            if (var_7 && var_6)
            {
                var_5 = FALSE;
            }
        }
        if (var_5 == FALSE)
        {
            TalkOpen();
            var_0 = TalkPromptChoice2(gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Option, gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Accept, gText_FarmEvent_Dog_BeachFrisbeePracticeChoice_Decline);
            TalkClose();
            switch (var_0)
            {
                case PROMPT_CHOICE_OPTION_1:
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    RunFrisbeeGame(FESTIVAL_FRISBEE_MODE_PRACTICE);
                    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    break;
                case PROMPT_CHOICE_OPTION_2:
                    break;
            }
        }
        else
        {
            return;
        }
    }
}
