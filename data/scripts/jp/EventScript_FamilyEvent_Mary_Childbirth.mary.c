#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Mary_Childbirth_AnnaSaysBirthIsNear[] =
        "まだ産まれないのかしら…{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_MaryBeginsLabor[] =
        "ッッッッ、たすけっ、\r\n"
        "カミサマー！{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_ElliEncouragesMaryDuringLabor[] =
        "がんばりなさいっ！\r\n"
        "もう少しよ。{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_AnnaReassuresMaryDuringLabor[] =
        "あの子ッたら…\r\n"
        "でも、もうすぐみたいね。{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_MaryFirstLaborCry[] =
        "いたいーっ。{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_MarySecondLaborCry[] =
        "ぎゃーッ！{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_DoctorRemarksOnWomensStrength[] =
        "女って…強い生き物だなぁ…{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_AnnaLooksForwardToShowingBasilGrandson[] =
        "はやくバジルにも見せたいわ♡\r\n"
        "いったい、何をしているの\r\n"
        "かしら。{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_ElliAnnouncesHealthyBabyBoy[] =
        "元気な男の子よ。はやくマリー\r\n"
        "にがんばったねって言って\r\n"
        "あげて。{Press}\p"
        "こんなにかわいい子を産んだん\r\n"
        "だもの。{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_MaryMarvelsAtNewLifeAndRequestsName[] =
        "この子がさっきまで、おなかの\r\n"
        "中にいたなんて、生命の神秘\r\n"
        "だわ。{Press}\p"
        "ふふ、はじめまして………\r\n"
        "そうか、まだ名前決めてなかっ\r\n"
        "たんだ。ねぇ、どうしよう？{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_MaryApprovesBabyName[] =
        "{Baby}………やっぱり、\r\n"
        "母親が産んだ子の名前を父親が\r\n"
        "決めるのって、いいよね。{Press}";

    const char gText_FamilyEvent_Mary_Childbirth_PlayerReflectsOnFatherhoodAndLoveForMary[] =
        "今日からボクもお父さんだ！\r\n"
        "{Baby}、元気に生まれて\r\n"
        "きてくれてありがとう！{Press}";
};

void EventScript_FamilyEvent_Mary_Childbirth(void)
{
    ChangeMap(MAP_FARMHOUSE, X(117), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(117), Y(148), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANNA, X(117), Y(124), FACING_DOWN);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_MARY_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(75), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(165), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(117), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_AnnaSaysBirthIsNear);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_MaryBeginsLabor);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_ElliEncouragesMaryDuringLabor);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_AnnaReassuresMaryDuringLabor);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(75), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_MaryFirstLaborCry);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(165), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_MarySecondLaborCry);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(117), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_BABY_CRY);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_BABY_CRY);
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60 * 2);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_FARMHOUSE, X(430), Y(124));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(430), Y(124), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MARY, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IN_BED);
    CreatePlayerChildEntity();
    SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_NEWBORN);
    SetEntityPosition(ENTITY_ANNA, X(408), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(452), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(430), Y(148), FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_DoctorRemarksOnWomensStrength);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_AnnaLooksForwardToShowingBasilGrandson);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_ElliAnnouncesHealthyBabyBoy);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_MaryMarvelsAtNewLifeAndRequestsName);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    OpenNameEntry(NAME_ENTRY_CHILD, NAME_ENTRY_SINGLETON_SLOT);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_MaryApprovesBabyName);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_MARY);
    MarkNpcSpokenTo(CHARACTER_ANNA);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    AddCharacterLove(CHARACTER_MARY, 3000);
    AddNpcFriendship(CHARACTER_ANNA, 20);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    AddNpcFriendship(CHARACTER_ELLI, 20);
    VarSet(VAR_MARY_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FamilyEvent_Mary_Childbirth_PlayerReflectsOnFatherhoodAndLoveForMary);
    TalkClose();
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
