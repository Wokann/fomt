#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiIsGladLilliaEnjoyedHisCooking[] =
        "Ich freue mich, dass\r\n"
        "es deiner Mutter \r\n"
        "geschmeckt hat. {Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriThanksKaiForKeepingHisPromise[] =
        "Danke, dass du dein \r\n"
        "Versprechen gehalten hast.{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiHopesHisCookingHelpedLillia[] =
        "Ich hoffe, ich konnte ihr\r\n"
        "etwas Gutes tun. {Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriSharesKaisHope[] =
        "Ich auch. {Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriIsGladRickMissedKaisVisit[] =
        "Gut, dass Rick nicht zu \r\n"
        "Hause war. Er wäre \r\n"
        "sicher böse geworden, {Press}\p"
        "wenn er dich in meinem \r\n"
        "Haus gesehen hätte! {Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiUneasilyAgrees[] =
        "Ja...{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickCallsOutToPopuri[] =
        "Popuri!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickConfrontsKaiForWalkingWithPopuri[] =
        "Wo, glaubst du, gehst \r\n"
        "du mit meiner Schwester \r\n"
        "hin, Kai?! {Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriSaysConversationIsNoneOfRicksBusiness[] =
        "Reg dich nicht auf! \r\n"
        "Wir haben nur geredet,\r\n"
        "es geht dich nichts an!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickOrdersPopuriBackToStore[] =
        "Du solltest trotzdem zum\r\n"
        "zum Laden gehen und helfen!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriTellsRickToHelpStoreHimself[] =
        "Warum gehst du nicht \r\n"
        "selber!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickBlamesKaiAndOrdersHimAwayFromPopuri[] =
        "Das ist deine Schuld, Kai!\r\n"
        "Du solltest meiner\r\n"
        "Schwester nicht nahe kommen!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriDefendsKaiFromRick[] =
        "So kannst du nicht \r\n"
        "mit Kai reden!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickHesitatesAfterPopurisDefense[] =
        "Popuri...{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiUrgesPopuriToReturnForLilliasSake[] =
        "Geh du lieber zurück.\r\n"
        "Denk an deine Mutter.{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriReluctantlyAgreesToReturnHome[] =
        "...Aber... Ja, ich denke.{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickOrdersKaiToLeavePopuriAlone[] =
        "Ab jetzt lässt du Popuri\r\n"
        "in Ruhe, Kai!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriApologizesAndSaysGoodbyeToKai[] =
        "Ab jetzt lässt du Popuri \r\n"
        "in Ruhe, Kai!{Press}";

    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiAcceptsPopurisGoodbye[] =
        "OK...{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(240), Y(216));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_POPURI, X(100), Y(232), FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_KAI, X(100), Y(200), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_RICK, X(104), Y(216), FACING_RIGHT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityXTo(ENTITY_KAI, X(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_POPURI, X(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    WaitFrames(30);
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiIsGladLilliaEnjoyedHisCooking);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriThanksKaiForKeepingHisPromise);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiHopesHisCookingHelpedLillia);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriSharesKaisHope);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriIsGladRickMissedKaisVisit);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiUneasilyAgrees);
    TalkClose();
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityXTo(ENTITY_RICK, X(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickCallsOutToPopuri);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityXTo(ENTITY_RICK, X(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickConfrontsKaiForWalkingWithPopuri);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriSaysConversationIsNoneOfRicksBusiness);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickOrdersPopuriBackToStore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriTellsRickToHelpStoreHimself);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickBlamesKaiAndOrdersHimAwayFromPopuri);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriDefendsKaiFromRick);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickHesitatesAfterPopurisDefense);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiUrgesPopuriToReturnForLilliasSake);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriReluctantlyAgreesToReturnHome);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_RickOrdersKaiToLeavePopuriAlone);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_PopuriApologizesAndSaysGoodbyeToKai);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_KaiAcceptsPopurisGoodbye);
    TalkClose();
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    MoveEntityXTo(ENTITY_RICK, X(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_POPURI, X(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    WaitForEntityMovement(ENTITY_POPURI);
    HideEntity(ENTITY_POPURI);
    HideEntity(ENTITY_RICK);
    PanCameraTo(X(24), Y(280), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_KAI, EventScript_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_FollowupKaiDialogue);
    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
