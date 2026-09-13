#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiChallengesRick[] =
        "Do you have a problem with\r\n"
        "me?{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickWarnsKaiAwayFromPopuri[] =
        "Yeah! Don't mess around \r\n"
        "with my sister!{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiQuestionsRicksAuthority[] =
        "What! Just who do \r\n"
        "you think you are!?{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickIdentifiesAsProtectiveBrother[] =
        "I'm Popuri's brother, and \r\n"
        "I don't like her seeing \r\n"
        "you, Kai! {Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiDefendsPopurisIndependence[] =
        "What makes you think you\r\n"
        "can run her life?{Press}\p"
        "She can do as she wants!{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickClaimsBrotherKnowsBest[] =
        "I'm her brother, so \r\n"
        "sometimes I know what's \r\n"
        "best for her! {Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiPitiesPopuriForControllingBrother[] =
        "I feel sorry for Popuri,\r\n"
        "that she has a brother like\r\n"
        "you! {Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickDemandsKaiRetractHisInsult[] =
        "Take that back!! {Press}\p"
        "...............{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_RickForbidsKaiSeeingPopuri[] =
        "From now on, I forbid you\r\n"
        "to see my sister!{Press}";

    const char gText_NPCEvent_Rick_ConfrontsKaiAboutPopuri_KaiChallengesBanIfPopuriVisits[] =
        "Oh yeah, what if she \r\n"
        "comes and visits me anyway? {Press}";

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
