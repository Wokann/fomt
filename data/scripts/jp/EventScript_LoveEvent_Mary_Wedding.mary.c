#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_Wedding_CarterPronouncesMarriage[] =
        "では、ちかいのキスを…{Press}";

    const char gText_LoveEvent_Mary_Wedding_MaryPromisesHappyFamily[] =
        "幸せな家庭を作ろうね。{Press}";

    const char gText_LoveEvent_Mary_Wedding_CarterBlessesCouple[] =
        "二人でいつまでも幸せにね。{Press}";
};

void EventScript_LoveEvent_Mary_Wedding(void)
{
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_PLAYER, X(168), Y(152), FACING_DOWN);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    SetEntityPosition(ENTITY_MARY, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_MAY, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_STU, X(104), Y(195), FACING_RIGHT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_BASIL, X(296), Y(155), FACING_LEFT);
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
    TalkMessage(gText_LoveEvent_Mary_Wedding_CarterPronouncesMarriage);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_WEDDING);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_Wedding_MaryPromisesHappyFamily);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_WALK);
    MoveEntityXTo(ENTITY_PLAYER, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_KISS);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_KISS);
    WaitFrames(90);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_IDLE);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_WALK);
    MoveEntityXTo(ENTITY_PLAYER, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_LoveEvent_Mary_Wedding_CarterBlessesCouple);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_WALK);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WEDDING_WALK);
    MoveEntityYTo(ENTITY_PLAYER, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MARY, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
    SetEntityFacing(ENTITY_BASIL, FACING_DOWN);
    SetEntityFacing(ENTITY_ANNA, FACING_DOWN);
    MoveEntityYTo(ENTITY_PLAYER, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MARY, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityXTo(ENTITY_STU, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_MAY, X(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    WaitForEntityMovement(ENTITY_MAY);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityFacing(ENTITY_STU, FACING_DOWN);
    SetEntityFacing(ENTITY_MAY, FACING_DOWN);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityYTo(ENTITY_STU, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MAY, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_STU);
    WaitForEntityMovement(ENTITY_MAY);
    WaitFrames(60 * 2);
    AddNpcFriendship(CHARACTER_CARTER, 20);
    AddNpcFriendship(CHARACTER_THOMAS, 20);
    AddNpcFriendship(CHARACTER_MAY, 20);
    AddNpcFriendship(CHARACTER_STU, 20);
    AddNpcFriendship(CHARACTER_BASIL, 255);
    AddNpcFriendship(CHARACTER_ANNA, 255);
    MarkNpcSpokenTo(CHARACTER_MARY);
    MarkNpcSpokenTo(CHARACTER_CARTER);
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    MarkNpcSpokenTo(CHARACTER_MAY);
    MarkNpcSpokenTo(CHARACTER_STU);
    MarkNpcSpokenTo(CHARACTER_BASIL);
    MarkNpcSpokenTo(CHARACTER_ANNA);
    VarSet(VAR_MARY_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    RunStaffCredits();
    CallScript(EventScript_LoveEvent_Mary_NicknameChoice);
}
