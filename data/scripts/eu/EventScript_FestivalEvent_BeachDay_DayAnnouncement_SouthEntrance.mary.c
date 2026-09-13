#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_BeachDay_DayAnnouncement_SouthEntrance_ThomasAnnouncesStartTimeAndInvitesPlayer[] =
        "Beach Day is today at the\r\n"
        "Beach from 10 AM on. {Press}\p"
        "Right now I'm getting ready\r\n"
        "for it.{Press}\p"
        "You should come, too. {Press}";
};

void EventScript_FestivalEvent_BeachDay_DayAnnouncement_SouthEntrance(void)
{
    int var_0, var_1, var_2;
    ChangeMap(MAP_MINERAL_BEACH, X(260), Y(492));
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_BEACH);
    SetEntityPosition(ENTITY_PLAYER, X(260), Y(492), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(260), Y(515), FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    if (VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01)
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        TalkMessage(gText_FestivalEvent_BeachDay_DayAnnouncement_SouthEntrance_ThomasAnnouncesStartTimeAndInvitesPlayer);
        TalkClose();
        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_ROSE_SQUARE, X(456), Y(128));
        SetEntityPosition(ENTITY_PLAYER, X(456), Y(128), FACING_LEFT);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        return;
    }
}
