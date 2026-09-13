#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_AchievementEvent_Pedometer_1000000Steps[] =
        "Ta-daaaa!{Press}\p"
        "Dein Schrittmesser hat\r\n"
        "gerade 1.000.000 gezählt.{Press}\p"
        "Herzlichen Glückwunsch!{Press}\p"
        "Das ist alles.\r\n"
        "Du bekommst nichts.\r\n"
        "Tschüss.{Press}";
};

void EventScript_AchievementEvent_Pedometer_1000000Steps(void)
{
    VarSet(VAR_ACHIEVEMENT_WALKED_1000000_STEPS_STATE, ACHIEVEMENT_EVENT_PRESENTING);
    SetPlayerActorUpdateSuspended(TRUE);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_AchievementEvent_Pedometer_1000000Steps);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    AddCharacterLove(CHARACTER_HARVEST_GODDESS, 3000);
    VarSet(VAR_ACHIEVEMENT_WALKED_1000000_STEPS_STATE, ACHIEVEMENT_EVENT_COMPLETED);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    SetPlayerActorUpdateSuspended(FALSE);
}
