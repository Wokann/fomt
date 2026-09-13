#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAsksWhyMaryVisited[] =
        "Is there something you need?{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryThanksSaibaraForRepairingHerTool[] =
        "You upgraded a tool\r\n"
        "for me. It's so much easier \r\n"
        "to use now. I wanted {Press}\p"
        "to thank you. {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraIsGladRepairHelpedAndOffersFutureRepairs[] =
        "I didn't know it mattered \r\n"
        "so much...I'm glad we were \r\n"
        "able to help! {Press}\p"
        "Just come again if you need \r\n"
        "anything else, OK? {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryThanksSaibaraAgain[] =
        "OK. \r\n"
        "Thanks very much. {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayCriesOutInPain[] =
        "Ouch! {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAsksWhatHappenedToGray[] =
        "What's wrong? {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayDismissesHisInjury[] =
        "Oh...just a scratch. {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryNoticesGraysBleedingHand[] =
        "But you're bleeding! {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraScoldsGrayForNotPayingAttention[] =
        "It's your own fault for\r\n"
        "not paying more attention!{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayInsistsHeIsFine[] =
        "I said I'm fine! {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryOrdersGrayToStopWorking[] =
        "Stop that! {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MarySearchesForBandage[] =
        "Just wait one second...{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryAsksGrayToHoldOutHisHand[] =
        "Just hold your hand still...\r\n"
        "please!{Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryFinishesBandagingGraysHand[] =
        "How's this? {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayThanksMaryWhileBlushing[] =
        "...Th-Thanks. {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryTellsGrayNotToMentionIt[] =
        "Don't mention it. {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MaryReturnsToLibraryAndInvitesGray[] =
        "Alright...I'm going back to \r\n"
        "the Library now. Come \r\n"
        "around any time! {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_SaibaraAcceptsMarysLibraryInvitation[] =
        "I'll do that! {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_GrayPromisesToVisitLibrary[] =
        "I'll see you there! {Press}";

    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_MarySaysGoodbye[] =
        "Bye, now! {Press}";
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
