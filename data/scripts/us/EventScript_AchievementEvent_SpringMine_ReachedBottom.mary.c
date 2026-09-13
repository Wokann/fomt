#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_AchievementEvent_SpringMine_ReachedBottom[] =
        "Ta-daaaa!\r\n"
        "You've reached the lowest{Press}\p"
        "level.  That's all.\r\n"
        "You get nothing.\r\n"
        "Bye.{Press}";
};

void EventScript_AchievementEvent_SpringMine_ReachedBottom(void)
{
    VarSet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_BOTTOM_STATE, ACHIEVEMENT_EVENT_PRESENTING);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_AchievementEvent_SpringMine_ReachedBottom);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
    VarSet(VAR_ACHIEVEMENT_REACHED_SPRING_MINE_BOTTOM_STATE, ACHIEVEMENT_EVENT_COMPLETED);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
}
