#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiChallengesRick[] =
        "Hast du ein Problem\r\n"
        "mit mir?{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickWarnsKaiAwayFromPopuri[] =
        "Ja! Fang nichts mit \r\n"
        "meiner Schwester an!{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiQuestionsRicksAuthority[] =
        "Was! Was denkst du, \r\n"
        "wer du bist!?{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickIdentifiesAsProtectiveBrother[] =
        "Ich bin Popuris Bruder \r\n"
        "und will nicht, dass \r\n"
        "sie dich trifft, Kai! {Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiDefendsPopurisIndependence[] =
        "Warum denkst du, dass du \r\n"
        "über sie bestimmen kannst?{Press}\p"
        "Sie kann tun, was sie will!{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickClaimsBrotherKnowsBest[] =
        "Ich bin ihr Bruder, darum \r\n"
        "weiß ich manchmal, was \r\n"
        "das Beste für sie ist! {Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiPitiesPopuriForControllingBrother[] =
        "Popuri tut mir leid, dass\r\n"
        "sie einen Bruder wie\r\n"
        "dich hat! {Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickDemandsKaiRetractHisInsult[] =
        "Nimm das zurück!! {Press}\p"
        "...............{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickForbidsKaiSeeingPopuri[] =
        "Ich verbiete dir ab sofort,\r\n"
        "meine Schwester zu sehen!{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiChallengesBanIfPopuriVisits[] =
        "Oh ja, und wenn sie mich \r\n"
        "trotzdem besuchen kommt?{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickGrowlsInFrustration[] =
        "Grrr...{Press}";
};

void EventScript_NPCEvent_Rick_ConfrontsKaiAboutPopuri(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAI, X(104), Y(128), FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    PanCameraTo(X(92), Y(128), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitForCameraMovement();
    WaitFrames(30);
    SetEntityPosition(ENTITY_RICK, X(80), Y(264), FACING_UP);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityYTo(ENTITY_RICK, Y(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_ANGRY, FALSE);
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiChallengesRick);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickWarnsKaiAwayFromPopuri);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiQuestionsRicksAuthority);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickIdentifiesAsProtectiveBrother);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiDefendsPopurisIndependence);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickClaimsBrotherKnowsBest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiPitiesPopuriForControllingBrother);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickDemandsKaiRetractHisInsult);
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickForbidsKaiSeeingPopuri);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiChallengesBanIfPopuriVisits);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickGrowlsInFrustration);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_ANGRY, TRUE);
    SetEntityPosition(ENTITY_RICK, X(80), Y(128), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityYTo(ENTITY_RICK, Y(264), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    HideEntity(ENTITY_RICK);
    PanCameraTo(X(24), Y(280), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_RICK_CONFRONTS_KAI_ABOUT_POPURI_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
