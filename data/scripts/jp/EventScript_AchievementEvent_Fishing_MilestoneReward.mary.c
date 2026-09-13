#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishWithoutSize[] =
        "{Var1}を釣り上げた。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInCentimeters[] =
        "{Var1}を釣り上げた。\r\n"
        "大きさは{Var2}ｃｍだ。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInMeters[] =
        "{Var1}を釣り上げた。\r\n"
        "大きさは{Var2}ｍだ。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInMetersAndCentimeters[] =
        "{Var1}を釣り上げた。\r\n"
        "大きさは{Var2}ｍ{Var3}ｃｍだ。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtKingFish[] =
        "これはぬしだ！{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtMaximumSizeFish[] =
        "{Var1}の\r\n"
        "最大サイズだ。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught10000FishMilestone[] =
        "ぱんぱかぱーん。{Press}\p"
        "ただいま釣った数が\r\n"
        "１００００匹になりました。{Press}\p"
        "おめでとうございまーす。{Press}\p"
        "それだけ。\r\n"
        "特に何かプレゼントとかある\r\n"
        "わけじゃないので。じゃねー。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught100000FishMilestone[] =
        "ぱんぱかぱーん。{Press}\p"
        "ただいま釣った数が\r\n"
        "１０００００匹になりました。{Press}\p"
        "おめでとうございまーす。{Press}\p"
        "それだけ。\r\n"
        "特に何かプレゼントとかある\r\n"
        "わけじゃないので。じゃねー。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught1000000FishMilestone[] =
        "ぱんぱかぱーん。{Press}\p"
        "ただいま釣った数が\r\n"
        "１００００００匹になり\r\n"
        "ました。{Press}\p"
        "おめでとうございまーす。{Press}\p"
        "それだけ。\r\n"
        "特に何かプレゼントとかある\r\n"
        "わけじゃないので。じゃねー。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught10000000FishMilestone[] =
        "ぱんぱかぱーん。{Press}\p"
        "ただいま釣った数が\r\n"
        "１０００００００匹になり\r\n"
        "ました。{Press}\p"
        "おめでとうございまーす。{Press}\p"
        "それだけ。\r\n"
        "特に何かプレゼントとかある\r\n"
        "わけじゃないので。じゃねー。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught100000000FishMilestone[] =
        "ぱんぱかぱーん。{Press}\p"
        "ただいま釣った数が\r\n"
        "１００００００００匹になり\r\n"
        "ました。{Press}\p"
        "おめでとうございまーす。{Press}\p"
        "それだけ。\r\n"
        "特に何かプレゼントとかある\r\n"
        "わけじゃないので。じゃねー。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught1000000000FishMilestone[] =
        "ぱんぱかぱーん。{Press}\p"
        "ただいま釣った数が\r\n"
        "１０００００００００匹になり\r\n"
        "ました。{Press}\p"
        "おめでとうございまーす。{Press}\p"
        "それだけ。\r\n"
        "特に何かプレゼントとかある\r\n"
        "わけじゃないので。じゃねー。{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtEveryFishSpeciesMilestone[] =
        "ぱんぱかぱーん。{Press}\p"
        "ただいま魚種を全種類釣り上げ\r\n"
        "ました。\r\n"
        "おめでとうございまーす。{Press}\p"
        "それだけ。\r\n"
        "特に何かプレゼントとかある\r\n"
        "わけじゃないので。じゃねー。{Press}";
};

void EventScript_AchievementEvent_Fishing_MilestoneReward(void)
{
    int var_0, var_1, var_2;
    var_0 = GetCaughtFishSize();
    var_1 = var_0 / 100;
    var_2 = var_0 % 100;
    SetTextVariableToCaughtFishName(TEXT_VARIABLE_1);
    TalkOpen();
    if (var_0 == 0)
    {
        TalkAppendMessage(gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishWithoutSize);
    }
    else
    {
        if (var_1 == 0)
        {
            SetTextVariableNumber(TEXT_VARIABLE_2, var_2);
            TalkAppendMessage(gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInCentimeters);
        }
        else
        {
            if (var_2 == 0)
            {
                SetTextVariableNumber(TEXT_VARIABLE_2, var_1);
                TalkAppendMessage(gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInMeters);
            }
            else
            {
                SetTextVariableNumber(TEXT_VARIABLE_2, var_1);
                SetTextVariableNumber(TEXT_VARIABLE_3, var_2);
                TalkAppendMessage(gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInMetersAndCentimeters);
            }
        }
    }
    if (IsCaughtFishKing())
    {
        PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
        TalkAppendMessage(gText_AchievementEvent_Fishing_MilestoneReward_CaughtKingFish);
    }
    else
    {
        if (IsCaughtFishMaximumSize())
        {
            TalkAppendMessage(gText_AchievementEvent_Fishing_MilestoneReward_CaughtMaximumSizeFish);
        }
    }
    TalkClose();
    if (IsCaughtFishKing())
    {
        UsePlayerHeldItem();
    }
    if (VarGet(VAR_ACHIEVEMENT_CAUGHT_10000_FISH_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && GetTotalFishCaught() >= 10000 && var_0 != 0)
    {
        VarSet(VAR_ACHIEVEMENT_CAUGHT_10000_FISH_STATE, ACHIEVEMENT_EVENT_PRESENTING);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_AchievementEvent_Fishing_MilestoneReward_Caught10000FishMilestone);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
        VarSet(VAR_ACHIEVEMENT_CAUGHT_10000_FISH_STATE, ACHIEVEMENT_EVENT_COMPLETED);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
    if (VarGet(VAR_ACHIEVEMENT_CAUGHT_100000_FISH_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && GetTotalFishCaught() >= 100000 && var_0 != 0)
    {
        VarSet(VAR_ACHIEVEMENT_CAUGHT_100000_FISH_STATE, ACHIEVEMENT_EVENT_PRESENTING);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_AchievementEvent_Fishing_MilestoneReward_Caught100000FishMilestone);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
        VarSet(VAR_ACHIEVEMENT_CAUGHT_100000_FISH_STATE, ACHIEVEMENT_EVENT_COMPLETED);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
    if (VarGet(VAR_ACHIEVEMENT_CAUGHT_1000000_FISH_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && GetTotalFishCaught() >= 1000000 && var_0 != 0)
    {
        VarSet(VAR_ACHIEVEMENT_CAUGHT_1000000_FISH_STATE, ACHIEVEMENT_EVENT_PRESENTING);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_AchievementEvent_Fishing_MilestoneReward_Caught1000000FishMilestone);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
        VarSet(VAR_ACHIEVEMENT_CAUGHT_1000000_FISH_STATE, ACHIEVEMENT_EVENT_COMPLETED);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
    if (VarGet(VAR_ACHIEVEMENT_CAUGHT_10000000_FISH_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && GetTotalFishCaught() >= 10000000 && var_0 != 0)
    {
        VarSet(VAR_ACHIEVEMENT_CAUGHT_10000000_FISH_STATE, ACHIEVEMENT_EVENT_PRESENTING);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_AchievementEvent_Fishing_MilestoneReward_Caught10000000FishMilestone);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
        VarSet(VAR_ACHIEVEMENT_CAUGHT_10000000_FISH_STATE, ACHIEVEMENT_EVENT_COMPLETED);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
    if (VarGet(VAR_ACHIEVEMENT_CAUGHT_100000000_FISH_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && GetTotalFishCaught() >= 100000000 && var_0 != 0)
    {
        VarSet(VAR_ACHIEVEMENT_CAUGHT_100000000_FISH_STATE, ACHIEVEMENT_EVENT_PRESENTING);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_AchievementEvent_Fishing_MilestoneReward_Caught100000000FishMilestone);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
        VarSet(VAR_ACHIEVEMENT_CAUGHT_100000000_FISH_STATE, ACHIEVEMENT_EVENT_COMPLETED);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
    if (VarGet(VAR_ACHIEVEMENT_CAUGHT_1000000000_FISH_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && GetTotalFishCaught() >= 1000000000 && var_0 != 0)
    {
        VarSet(VAR_ACHIEVEMENT_CAUGHT_1000000000_FISH_STATE, ACHIEVEMENT_EVENT_PRESENTING);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_AchievementEvent_Fishing_MilestoneReward_Caught1000000000FishMilestone);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
        VarSet(VAR_ACHIEVEMENT_CAUGHT_1000000000_FISH_STATE, ACHIEVEMENT_EVENT_COMPLETED);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
    if (VarGet(VAR_ACHIEVEMENT_CAUGHT_EVERY_FISH_SPECIES_STATE) == ACHIEVEMENT_EVENT_NOT_REACHED && HasCaughtEveryFishSpecies())
    {
        VarSet(VAR_ACHIEVEMENT_CAUGHT_EVERY_FISH_SPECIES_STATE, ACHIEVEMENT_EVENT_PRESENTING);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        TalkMessage(gText_AchievementEvent_Fishing_MilestoneReward_CaughtEveryFishSpeciesMilestone);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
        AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
        VarSet(VAR_ACHIEVEMENT_CAUGHT_EVERY_FISH_SPECIES_STATE, ACHIEVEMENT_EVENT_COMPLETED);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    }
}
