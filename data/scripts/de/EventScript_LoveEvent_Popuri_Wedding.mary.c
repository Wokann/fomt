#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_Wedding_Carter_PronouncesMarriage[] =
        "Du darfst die Braut küssen.{Press}";

    const char gText_LoveEvent_Popuri_Wedding_Popuri_PledgesToBeGoodWife[] =
        "Ich werde eine tolle\r\n"
        "Ehefrau sein. {Press}";

    const char gText_LoveEvent_Popuri_Wedding_Thomas_CongratulatesCouple[] =
        "Mögt ihr immer\r\n"
        "glücklich sein.{Press}";
};

void EventScript_LoveEvent_Popuri_Wedding(void)
{
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_PLAYER, X(168), Y(152), FACING_DOWN);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_MAY, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_STU, X(104), Y(195), FACING_RIGHT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_RICK, X(296), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_LILLIA, X(256), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
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
    TalkMessage(gText_LoveEvent_Popuri_Wedding_Carter_PronouncesMarriage);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_WEDDING);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_Wedding_Popuri_PledgesToBeGoodWife);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_WALK);
    MoveEntityXTo(ENTITY_PLAYER, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_KISS);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_KISS);
    WaitFrames(90);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_IDLE);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_WALK);
    MoveEntityXTo(ENTITY_PLAYER, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_LoveEvent_Popuri_Wedding_Thomas_CongratulatesCouple);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_WALK);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_WALK);
    MoveEntityYTo(ENTITY_PLAYER, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_POPURI, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
    MoveEntityYTo(ENTITY_PLAYER, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_POPURI, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    AddNpcFriendship(CHARACTER_RICK, 255);
    AddNpcFriendship(CHARACTER_LILLIA, 255);
    MarkNpcSpokenTo(CHARACTER_POPURI);
    MarkNpcSpokenTo(CHARACTER_CARTER);
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    MarkNpcSpokenTo(CHARACTER_MAY);
    MarkNpcSpokenTo(CHARACTER_STU);
    MarkNpcSpokenTo(CHARACTER_RICK);
    MarkNpcSpokenTo(CHARACTER_LILLIA);
    VarSet(VAR_POPURI_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    RunStaffCredits();
    CallScript(EventScript_LoveEvent_Popuri_NicknameChoice);
}
