#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayPraisesMarysBookSuccess[] =
        "I hear that your latest book\r\n"
        "is selling like hotcakes, \r\n"
        "Mary. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MarySharesSequelOffer[] =
        "Yeah, the publisher even \r\n"
        "wants me to write a \r\n"
        "sequel!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayHesitates[] =
        "Hmm....{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryQuestionsGraysReaction[] =
        "Why don't you seem very \r\n"
        "happy about it, Gray?\r\n"
        "Aren't you glad for me? {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayStrugglesToExplainConcern[] =
        "It's not like that...\r\n"
        "It's just that, well...{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryUrgesGrayToSpeakHonestly[] =
        "It's not like you to not\r\n"
        "say what you think, Gray. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAdmitsConcernForMarysHealth[] =
        "OK...I'm worried about \r\n"
        "your health!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayRecallsMaryOverworkingOnPreviousBook[] =
        "When you wrote the last\r\n"
        "book, you stayed up late \r\n"
        "every night working on it.{Press}\p"
        "You were so tired all the\r\n"
        "time I couldn't help but\r\n"
        "worry!{Press}\p"
        "I didn't want to stop you \r\n"
        "from doing what you \r\n"
        "wanted, though. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryThanksGrayForCaring[] =
        "Thanks for caring about me\r\n"
        "so much, Gray. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAffirmsHeCaresAboutMary[] =
        "Of course I do!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryPromisesNotToOverwork[] =
        "In that case, I promise not \r\n"
        "to work so hard writing\r\n"
        "the next one. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayOffersToHelp[] =
        "I'll try to do what I can \r\n"
        "to help, too. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryExpressesHappinessInMarriage[] =
        "I'm glad I married \r\n"
        "you, Gray!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayReactsEmbarrassed[] =
        "Now you're making me\r\n"
        "embarrassed...!{Press}";
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
