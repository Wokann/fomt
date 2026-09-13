#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffGreetsPlayer[] =
        "Hello, {Player}. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaGreetsPlayer[] =
        "Hi, how are you? {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffAsksAboutFarmLifeAndOffersHelp[] =
        "How is farm life treating \r\n"
        "you? Let me know if you \r\n"
        "need anything. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaOffersPlayerHelp[] =
        "I'll try to help you \r\n"
        "any way I can. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonCallsFromFrontOfStore[] =
        "Hello? Is anybody home?\r\n"
        "Hello?{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaGoesToAnswerVisitor[] =
        "What could it be?\r\n"
        "Wait one second. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffAsksWhoArrived[] =
        "Who is it? {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaTellsJeffVisitorCameForHim[] =
        "He came to see you, dear.{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAsksWhetherJeffOwnsStore[] =
        "Are you the owner here? {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffConfirmsAndAsksWhoWonIs[] =
        "Yes, and you are? {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonIntroducesHimselfAsTravelingSalesman[] =
        "I am Won, a wandering \r\n"
        "salesman. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffAsksWhatWonWants[] =
        "What do you want with me?{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAsksWhetherJeffPaints[] =
        "You create paintings, right?{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffSaysPaintingIsHobby[] =
        "Yes, I paint as a hobby. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonPraisesPaintingAndAsksToBuy[] =
        "I happened to see your\r\n"
        "painting. {Press}\p"
        "I think it’s beautiful, \r\n"
        "Would you please sell \r\n"
        "me paintings...?{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaReactsToPraise[] =
        "Really!? \r\n"
        "I can't believe this!{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonTellsSashaJeffHasGreatTalent[] =
        "Your husband has very \r\n"
        "great talent!{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaAsksOfferPrice[] =
        "How much would\r\n"
        "you pay...?{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonOffers10000GPerPainting[] =
        "Let's see...I would pay \r\n"
        "10000G per painting!{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaIsSurprisedByOffer[] =
        "That much?!{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaUrgesJeffToSell[] =
        "You should sell!{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffRefusesToSellPaintings[] =
        ".......\r\n"
        "I'm very sorry, but I can't\r\n"
        "sell you my paintings.{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAsksWhyJeffRefuses[] =
        "...Why not?{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaUrgesJeffToConsiderMoney[] =
        "Are you sure? \r\n"
        "Think about all \r\n"
        "that money!{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffExplainsPaintingsComeFromHeartAndCannotBeSold[] =
        "I'm sorry, Sasha. {Press}\p"
        "I paint straight from my \r\n"
        "heart. {Press}\p"
        "If I sold my paintings, it \r\n"
        "would be like selling a \r\n"
        "piece of my heart.{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SilentReactionToJeffsConviction[] =
        "...{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaCallsJeffByName[] =
        "Jeff...{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_WonAcceptsRefusalAndAdmiresJeffsResolve[] =
        "I see you won't change\r\n"
        "your mind. That is very \r\n"
        "unfortunate! {Press}\p"
        "I thought it was very good\r\n"
        "business opportunity.{Press}\p"
        "I admire your resolve,\r\n"
        "though. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaTellsJeffSheIsProud[] =
        "I'm proud of you, dear. {Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_JeffThanksSashaAndReturnsToWork[] =
        "Really? Gee, thanks!\r\n"
        "OK, now go back to work!{Press}";

    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_SashaSaysGoodbye[] =
        "Bye now!{Press}";
};

void EventScript_NPCEvent_Jeff_WonOffersToBuyPainting(void)
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
    TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_SilentReactionToJeffsConviction);
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
    SetEntityEventScript(ENTITY_SASHA, EventScript_NPCEvent_Jeff_WonOffersToBuyPainting_FollowupSashaDialogue);
}
