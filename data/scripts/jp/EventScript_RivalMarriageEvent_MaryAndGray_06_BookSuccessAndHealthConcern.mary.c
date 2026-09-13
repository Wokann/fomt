#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayPraisesMarysBookSuccess[] =
        "マリーが書いた本は人気が\r\n"
        "あるみたいだな。{Press}\p"
        "飛ぶように売れているって\r\n"
        "聞いたぜ？{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MarySharesSequelOffer[] =
        "そうなのよ。\r\n"
        "次回作を書いてくれって話しも\r\n"
        "あるのよ。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayHesitates[] =
        "ふぅ～ん…\r\n"
        "{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryQuestionsGraysReaction[] =
        "なんか、あんまりうれしそう\r\n"
        "じゃないわね。{Press}\p"
        "わたしの書いた本が売れるのが\r\n"
        "気に入らないの？{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayStrugglesToExplainConcern[] =
        "そうじゃないよ。\r\n"
        "{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryUrgesGrayToSpeakHonestly[] =
        "じゃあ、なんなのよ…\r\n"
        "はっきり言わないなんてグレイ\r\n"
        "らしくないよ。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAdmitsConcernForMarysHealth[] =
        "じゃあ、はっきり言うよ。\r\n"
        "マリーの体が心配なんだよ！{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayRecallsMaryOverworkingOnPreviousBook[] =
        "ああ、そうだよ！\r\n"
        "この前の本だって、夜もねない\r\n"
        "ってザラだったじゃないか。{Press}\p"
        "オレは、心配で心配でしょうが\r\n"
        "なかったんだ！{Press}\p"
        "何度も言おうと思ったけど、\r\n"
        "マリーが必死にやってたから\r\n"
        "水をさしちゃ悪いと思って{Press}\p"
        "言えなかったんだ。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryThanksGrayForCaring[] =
        "そうだったの…{Press}\p"
        "ありがとう、グレイ。\r\n"
        "わたしのこと、そんなに考えて\r\n"
        "くれていたんだ。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAffirmsHeCaresAboutMary[] =
        "と…当然だろ？\r\n"
        "{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryPromisesNotToOverwork[] =
        "わかったわ。これからは根を\r\n"
        "つめずに本を書くから。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayOffersToHelp[] =
        "ああ、がんばれよ。\r\n"
        "オレも出来る限り、協力するか\r\n"
        "ら。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryExpressesHappinessInMarriage[] =
        "うん。\r\n"
        "わたし、グレイと結婚してよか\r\n"
        "った♡{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayReactsEmbarrassed[] =
        "よせよ、テレるだろ？\r\n"
        "{Press}";
};

void EventScript_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern(void)
{
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MARY, X(224), Y(256), FACING_RIGHT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(244), Y(256), FACING_LEFT);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(240), Y(256), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayPraisesMarysBookSuccess);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MarySharesSequelOffer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayHesitates);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryQuestionsGraysReaction);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayStrugglesToExplainConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryUrgesGrayToSpeakHonestly);
    TalkClose();
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAdmitsConcernForMarysHealth);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayRecallsMaryOverworkingOnPreviousBook);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryThanksGrayForCaring);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_SHY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAffirmsHeCaresAboutMary);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryPromisesNotToOverwork);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayOffersToHelp);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryExpressesHappinessInMarriage);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_SHY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayReactsEmbarrassed);
    TalkClose();
    PanCameraTo(X(236), Y(464), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    VarSet(VAR_MARY_AND_GRAY_BOOK_AND_HEALTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_MARY, EventScript_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue);
    SetEntityEventScript(ENTITY_GRAY, EventScript_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupGrayDialogue);
    return;
}
