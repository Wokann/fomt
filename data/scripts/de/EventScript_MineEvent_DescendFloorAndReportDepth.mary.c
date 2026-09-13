#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_MineEvent_DescendFloorAndReportDepth_DescendPrompt[] =
        "Runtergehen?";

    const char gText_MineEvent_DescendFloorAndReportDepth_ChoiceYes[] =
        "Ja";

    const char gText_MineEvent_DescendFloorAndReportDepth_ChoiceNo[] =
        "Nein";

    const char gText_MineEvent_DescendFloorAndReportDepth_ReachedMorningWithoutSleep[] =
        "Es ist Morgen...{Press}";

    const char gText_MineEvent_DescendFloorAndReportDepth_SpringMineFloorLabel[] =
        "Unter Tage in der Mine\r\n"
        "nahe der Quelle,\r\n"
        "Level {Var1}{Press}";

    const char gText_MineEvent_DescendFloorAndReportDepth_LakeMineFloorLabel[] =
        "Unter Tage in der Mine\r\n"
        "in der Nähe des Sees,\r\n"
        "Level {Var1}{Press}";
};

void EventScript_MineEvent_DescendFloorAndReportDepth(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6;
    TalkOpen();
    var_0 = TalkPromptChoice2(gText_MineEvent_DescendFloorAndReportDepth_DescendPrompt, gText_MineEvent_DescendFloorAndReportDepth_ChoiceYes, gText_MineEvent_DescendFloorAndReportDepth_ChoiceNo);
    TalkClose();
    switch (var_0)
    {
        case PROMPT_CHOICE_OPTION_1:
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            DescendMineFloor();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            var_3 = VarGet(VAR_HOUR);
            var_4 = VarGet(VAR_MINUTE);
            if (var_4 == 59)
            {
                var_4 = 0;
                if (var_3 == 23)
                {
                    var_3 = 0;
                }
                else
                {
                    var_3++;
                }
            }
            else
            {
                var_4++;
            }
            SetGameTime(var_3, var_4);
            if (var_3 == 6 && var_4 == 0)
            {
                TalkOpen();
                TalkMessage(gText_MineEvent_DescendFloorAndReportDepth_ReachedMorningWithoutSleep);
                TalkClose();
                var_5 = VarGet(VAR_PLAYER_FATIGUE);
                ClearPreservedPlayerLocation();
                ChangePlayerStaminaAndFatigue(0, 10);
                var_6 = VarGet(VAR_PLAYER_FATIGUE);
                if (var_5 < var_6)
                {
                    if (var_6 == 100)
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_FAINT_FROM_EXHAUSTION);
                        WaitFrames(194);
                        CallScript(EventScript_NPCEvent_Doctor_PlayerCollapseRecovery);
                    }
                    else
                    {
                        if (var_5 < 80 && 80 <= var_6)
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_COLLAPSE_HOLDING_HEAD);
                            WaitFrames(282);
                        }
                        else
                        {
                            if (var_5 < 50 && 50 <= var_6)
                            {
                                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_HOLD_HEAD_IN_PAIN);
                                WaitFrames(240);
                            }
                        }
                    }
                }
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                CallScript(EventScript_SystemEvent_AdvanceToNextDay);
            }
            var_1 = GetEntityLocation(ENTITY_PLAYER);
            if (MAP_SPRING_MINE_FLOOR_0 <= var_1 && var_1 < MAP_SPRING_MINE_FLOOR_0 + 256)
            {
                var_2 = var_1 - 52;
                if (VarGet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_B100_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && var_2 == 100)
                {
                    CallScript(EventScript_AchievementEvent_SpringMine_ReachedB100);
                }
                else
                {
                    if (VarGet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_B200_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && var_2 == 200)
                    {
                        CallScript(EventScript_AchievementEvent_SpringMine_ReachedB200);
                    }
                    else
                    {
                        if (VarGet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_BOTTOM_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && var_2 == 255)
                        {
                            CallScript(EventScript_AchievementEvent_SpringMine_ReachedBottom);
                        }
                        else
                        {
                            SetTextVariableNumber(TEXT_VARIABLE_1, var_2);
                            TalkOpen();
                            TalkAppendMessage(gText_MineEvent_DescendFloorAndReportDepth_SpringMineFloorLabel);
                            TalkClose();
                        }
                    }
                }
            }
            else
            {
                if (MAP_LAKE_MINE_FLOOR_0 <= var_1 && var_1 < MAP_LAKE_MINE_FLOOR_0 + 256)
                {
                    var_2 = var_1 - 308;
                    SetTextVariableNumber(TEXT_VARIABLE_1, var_2);
                    TalkOpen();
                    TalkAppendMessage(gText_MineEvent_DescendFloorAndReportDepth_LakeMineFloorLabel);
                    TalkClose();
                }
            }
            break;
        case PROMPT_CHOICE_OPTION_2:
            break;
    }
}
