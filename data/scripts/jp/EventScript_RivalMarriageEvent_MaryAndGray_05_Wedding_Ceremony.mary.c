#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_WeddingAnnouncement[] =
        "{Player}、\r\n"
        "今日、オレとマリーの\r\n"
        "結婚式があるんだ。{Press}\p"
        "オレ…こんなに幸せで\r\n"
        "いいのかなぁ。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails[] =
        "あ、ここに来たもくてきを\r\n"
        "忘れるところだった。{Press}\p"
        "お前をオレたちの結婚式に\r\n"
        "よびにきたんだよ。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_CarterInvitesWeddingKiss[] =
        "では、ちかいのキスを…{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_GuestsToastNewlyweds[] =
        "わかい２人にカンパイ！！{Press}";
};

void EventScript_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony(void)
{
    VarSet(VAR_MARY_GRAY_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    ChangeMap(MAP_FARM, X(228), Y(160));
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_GRAY, X(228), Y(160), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_WeddingAnnouncement);
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_MARY, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(104), Y(195), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityPosition(ENTITY_SAIBARA, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_BASIL, X(296), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
    }
    if (GetEntityLocation(ENTITY_DUKE) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DUKE);
    }
    if (GetEntityLocation(ENTITY_MANNA) == MAP_CHURCH)
    {
        HideEntity(ENTITY_MANNA);
    }
    if (GetEntityLocation(ENTITY_POPURI) == MAP_CHURCH)
    {
        HideEntity(ENTITY_POPURI);
    }
    StopAllSongs();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
    WaitFrames(60 * 3);
    PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
    WaitFrames(60 * 3);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_WEDDING);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_CarterInvitesWeddingKiss);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_WALK);
    MoveEntityXTo(ENTITY_GRAY, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_IDLE);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_KISS);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_KISS);
    WaitFrames(90);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_IDLE);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_IDLE);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_WALK);
    MoveEntityXTo(ENTITY_GRAY, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    WaitFrames(60);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WEDDING_WALK);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_WALK);
    MoveEntityYTo(ENTITY_GRAY, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MARY, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
    MoveEntityYTo(ENTITY_GRAY, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MARY, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_ANNA, FACING_DOWN);
    SetEntityFacing(ENTITY_BASIL, FACING_DOWN);
    MoveEntityYTo(ENTITY_GRAY, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MARY, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitFrames(60 * 3);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_Ceremony_GuestsToastNewlyweds);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_GRAY);
    VarSet(VAR_MARY_GRAY_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
