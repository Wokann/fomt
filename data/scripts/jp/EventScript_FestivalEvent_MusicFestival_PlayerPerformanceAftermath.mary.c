#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_PlayerPerformanceAftermath_EnjoyedFestivalAndWillSleepWell[] =
        "楽しかった…\r\n"
        "今日はよく眠れそうだ…{Press}";
};

void EventScript_FestivalEvent_MusicFestival_PlayerPerformanceAftermath(void)
{
    ChangeMap(MAP_CHURCH, X(184), Y(80));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_MUSIC_FESTIVAL);
    SetEntityPosition(ENTITY_MAY, X(264), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_MARY, X(264), Y(mary_negated_int(-62)), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_MUSIC_FESTIVAL_IDLE);
    SetEntityPosition(ENTITY_STU, X(296), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(104), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(72), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(184), Y(140), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(166), Y(67), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(84), Y(100), FACING_RIGHT);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_ANN, X(198), Y(67), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    if (VarGet(VAR_MUSIC_FESTIVAL_PLAYER_PERFORMANCE_ACCEPTED) == TRUE)
    {
        SetEntityPosition(ENTITY_PLAYER, X(264), Y(120), FACING_DOWN);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        AddNpcFriendship(CHARACTER_ELLI, 10);
        AddNpcFriendship(CHARACTER_CARTER, 10);
        AddNpcFriendship(CHARACTER_MAY, 10);
        AddNpcFriendship(CHARACTER_ANN, 10);
        AddNpcFriendship(CHARACTER_KAREN, 10);
        AddNpcFriendship(CHARACTER_MARY, 10);
        AddNpcFriendship(CHARACTER_JEFF, 10);
        AddNpcFriendship(CHARACTER_SASHA, 10);
        AddNpcFriendship(CHARACTER_STU, 10);
    }
    else
    {
        SetEntityPosition(ENTITY_PLAYER, X(108), Y(150), FACING_UP);
        PreparePlayerForScriptedAnimation();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopAllSongs();
    WaitFrames(60 * 4);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_MUSIC_FESTIVAL_PERFORMANCE);
    if (VarGet(VAR_MUSIC_FESTIVAL_PLAYER_PERFORMANCE_ACCEPTED) == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PLAY_OCARINA);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_MUSIC_FESTIVAL_PERFORMANCE);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_MUSIC_FESTIVAL_PERFORMANCE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_MUSIC_FESTIVAL_PERFORMANCE);
    WaitFrames(60 * 12);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_MUSIC_FESTIVAL_PERFORMANCE);
    WaitFrames(60 * 34);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_MUSIC_FESTIVAL_IDLE);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(60 * 4);
    StopAllSongs();
    PlaySong(AUDIO_START, AUDIO_SFX_APPLAUSE);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_MusicFestival_PlayerPerformanceAftermath_EnjoyedFestivalAndWillSleepWell);
    TalkClose();
    DisableScriptedNpcControl();
    ClearEntityEventScript(ENTITY_ELLI);
    ClearEntityEventScript(ENTITY_CARTER);
    ClearEntityEventScript(ENTITY_MAY);
    ClearEntityEventScript(ENTITY_ANN);
    ClearEntityEventScript(ENTITY_KAREN);
    ClearEntityEventScript(ENTITY_MARY);
    ClearEntityEventScript(ENTITY_JEFF);
    ClearEntityEventScript(ENTITY_SASHA);
    ClearEntityEventScript(ENTITY_STU);
    VarSet(VAR_MUSIC_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
