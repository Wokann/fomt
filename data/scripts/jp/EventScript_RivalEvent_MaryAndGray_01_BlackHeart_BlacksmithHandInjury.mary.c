#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAsksWhyMaryVisited[] =
        "どうなされた？{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryThanksSaibaraForRepairingHerTool[] =
        "この間、サイバラさんに\r\n"
        "修理してもらった道具が、\r\n"
        "とても使いやすくって、{Press}\r\n"
        "改めてお礼を言いに来たん\r\n"
        "です。\r\n"
        "ありがとうございました。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraIsGladRepairHelpedAndOffersFutureRepairs[] =
        "なんの、これほど喜んで\r\n"
        "もらえるとは、わしも修理した\r\n"
        "かいがあったというものだ。{Press}\p"
        "なにかあったら、\r\n"
        "いつでも持ってきなさい。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryThanksSaibaraAgain[] =
        "はいっ、\r\n"
        "ありがとうございます。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayCriesOutInPain[] =
        "イテッ。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAsksWhatHappenedToGray[] =
        "どうした、グレイ？{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayDismissesHisInjury[] =
        "なんでもないよ。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryNoticesGraysBleedingHand[] =
        "大変。血が出てるわ。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraScoldsGrayForNotPayingAttention[] =
        "バカもの。\r\n"
        "よそみをするからだ。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayInsistsHeIsFine[] =
        "大丈夫だって。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryOrdersGrayToStopWorking[] =
        "ダメよ！{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MarySearchesForBandage[] =
        "ちょっと待ってね。ええっと…{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryAsksGrayToHoldOutHisHand[] =
        "ああ、あったあった。\r\n"
        "手を出して。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryFinishesBandagingGraysHand[] =
        "これでよしっと。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayThanksMaryWhileBlushing[] =
        "あ…ありがとう。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryTellsGrayNotToMentionIt[] =
        "いいえ、どういたしまして。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryReturnsToLibraryAndInvitesGray[] =
        "それじゃ、わたしはこれで…\r\n"
        "図書館にも、\r\n"
        "ぜひ来てくださいね。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAcceptsMarysLibraryInvitation[] =
        "ああ、今度行かせてもらうよ。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayPromisesToVisitLibrary[] =
        "ぜったいに行くから。{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MarySaysGoodbye[] =
        "うん、じゃあね。{Press}";
};

void EventScript_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury(void)
{
    ChangeMap(MAP_BLACKSMITH, X(120), Y(80));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MARY, X(120), Y(208), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(96), Y(99), FACING_DOWN);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(120), Y(76), FACING_DOWN);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(171), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(49), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(76), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_SAIBARA, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAsksWhyMaryVisited);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryThanksSaibaraForRepairingHerTool);
    TalkClose();
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraIsGladRepairHelpedAndOffersFutureRepairs);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryThanksSaibaraAgain);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayCriesOutInPain);
    TalkClose();
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAsksWhatHappenedToGray);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayDismissesHisInjury);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryNoticesGraysBleedingHand);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraScoldsGrayForNotPayingAttention);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayInsistsHeIsFine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryOrdersGrayToStopWorking);
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MarySearchesForBandage);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryAsksGrayToHoldOutHisHand);
    TalkClose();
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_GESTURE);
    WaitFrames(60);
    WaitFrames(60);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    WaitFrames(30);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryFinishesBandagingGraysHand);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayThanksMaryWhileBlushing);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryTellsGrayNotToMentionIt);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryReturnsToLibraryAndInvitesGray);
    TalkClose();
    SetEntityFacing(ENTITY_SAIBARA, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAcceptsMarysLibraryInvitation);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayPromisesToVisitLibrary);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MarySaysGoodbye);
    TalkClose();
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    MoveEntityXTo(ENTITY_MARY, X(49), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(171), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    HideEntity(ENTITY_MARY);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    PanCameraTo(X(120), Y(148), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_GRAY, EventScript_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupGrayDialogue);
    SetEntityEventScript(ENTITY_SAIBARA, EventScript_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupSaibaraDialogue);
    VarSet(VAR_MARY_GRAY_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
}
