#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayPraisesMarysBookSuccess[] =
        "Ich habe gehört, dass\r\n"
        "dein letztes Buch sich \r\n"
        "spitze verkauft, Mary. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MarySharesSequelOffer[] =
        "Ja, der Verleger will  \r\n"
        "sogar, dass ich eine \r\n"
        "Fortsetzung schreibe!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayHesitates[] =
        "Hmm....{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryQuestionsGraysReaction[] =
        "Was ist los, Gray? \r\n"
        "Freust du dich \r\n"
        "nicht für mich?{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayStrugglesToExplainConcern[] =
        "Das ist es nicht...\r\n"
        "Es ist nur, dass...{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryUrgesGrayToSpeakHonestly[] =
        "Sonst sagst du doch,\r\n"
        "was du denkst, Gray. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAdmitsConcernForMarysHealth[] =
        "OK... ich sorge mich um\r\n"
        "deine Gesundheit!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayRecallsMaryOverworkingOnPreviousBook[] =
        "Beim letzten Buch hast\r\n"
        "du in jeder Nacht \r\n"
        "gearbeitet. {Press}\p"
        "Du warst immer müde,\r\n"
        "ich konnte nicht umhin, \r\n"
        "mich zu sorgen!{Press}\p"
        "Ich wollte dich trotzdem \r\n"
        "nicht abhalten, dein \r\n"
        "Buch zu schreiben. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryThanksGrayForCaring[] =
        "Danke, dass du dich\r\n"
        "um mich sorgst, Gray. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayAffirmsHeCaresAboutMary[] =
        "Natürlich!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryPromisesNotToOverwork[] =
        "Wenn das so ist, verspreche\r\n"
        "ich, nächstes Mal nicht\r\n"
        "so hart zu arbeiten. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayOffersToHelp[] =
        "Ich versuche, alles \r\n"
        "zu tun, um dir zu helfen. {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_MaryExpressesHappinessInMarriage[] =
        "Ich bin froh, mit dir \r\n"
        "verheiratet zu sein, Gray!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_GrayReactsEmbarrassed[] =
        "Jetzt machst du mich\r\n"
        "aber verlegen...!{Press}";
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
