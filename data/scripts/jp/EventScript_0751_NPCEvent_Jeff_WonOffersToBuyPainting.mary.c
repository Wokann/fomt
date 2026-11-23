#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0751_NPCEvent_Jeff_WonOffersToBuyPainting.mary.h"

void EventScript_0751_NPCEvent_Jeff_WonOffersToBuyPainting(void)
{
    ChangeMap(MAP_SUPERMARKET_BACK_ROOM, X(92), Y(165));
    SetEntityPosition(ENTITY_JEFF, X(166), Y(145), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(166), Y(165), FACING_UP);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_WON, X(92), Y(330), FACING_UP);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(92), Y(330), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(145), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_PLAYER, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
    SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffAsksAboutFarmLifeAndOffersHelp);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaOffersPlayerHelp);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonCallsFromFrontOfStore);
    TalkClose();
    WaitFrames(30);
    StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaGoesToAnswerVisitor);
    TalkClose();
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_WALK);
    MoveEntityXTo(ENTITY_SASHA, X(92), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SASHA);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    MoveEntityYTo(ENTITY_SASHA, Y(310), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SASHA);
    SetEntityFacing(ENTITY_SASHA, FACING_UP);
    StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
    MoveEntityYTo(ENTITY_JEFF, Y(165), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffAsksWhoArrived);
    TalkClose();
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_WALK);
    MoveEntityYTo(ENTITY_SASHA, Y(145), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_WON, Y(165), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SASHA);
    WaitForEntityMovement(ENTITY_WON);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    SetEntityFacing(ENTITY_WON, FACING_RIGHT);
    SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaTellsJeffVisitorCameForHim);
    TalkClose();
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
    MoveEntityXTo(ENTITY_JEFF, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAsksWhetherJeffOwnsStore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffConfirmsAndAsksWhoWonIs);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonIntroducesHimselfAsTravelingSalesman);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffAsksWhatWonWants);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAsksWhetherJeffPaints);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffSaysPaintingIsHobby);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonPraisesPaintingAndAsksToBuy);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaReactsToPraise);
    TalkClose();
    SetEntityFacing(ENTITY_WON, FACING_UP);
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonTellsSashaJeffHasGreatTalent);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaAsksOfferPrice);
    TalkClose();
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonOffers10000GPerPainting);
    TalkClose();
    StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaIsSurprisedByOffer);
    TalkClose();
    SetEntityFacing(ENTITY_WON, FACING_RIGHT);
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaUrgesJeffToSell);
    TalkClose();
    StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffRefusesToSellPaintings);
    TalkClose();
    StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_WON, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAsksWhyJeffRefuses);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaUrgesJeffToConsiderMoney);
    TalkClose();
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffExplainsPaintingsComeFromHeartAndCannotBeSold);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaCallsJeffByName);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAcceptsRefusalAndAdmiresJeffsResolve);
    TalkClose();
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_WALK);
    SetEntityFacing(ENTITY_WON, FACING_DOWN);
    MoveEntityYTo(ENTITY_WON, Y(330), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    HideEntity(ENTITY_WON);
    StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaTellsJeffSheIsProud);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffThanksSashaAndReturnsToWork);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaSaysGoodbye);
    TalkClose();
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
    MoveEntityXTo(ENTITY_JEFF, X(93), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    MoveEntityYTo(ENTITY_JEFF, Y(330), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_JEFF);
    HideEntity(ENTITY_JEFF);
    MarkNpcSpokenTo(CHARACTER_JEFF);
    MarkNpcSpokenTo(CHARACTER_SASHA);
    EnableScriptedNpcControl();
    PanCameraTo(X(136), Y(145), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_SASHA, EventScript_0752_NPCEvent_Jeff_WonOffersToBuyPainting_FollowupSashaDialogue);
}
