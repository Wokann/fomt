#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaScoldsJeffForAllowingStoreCredit[] =
        "How many times do \r\n"
        "I have to tell you!?{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffComplainsOfStomachPainToAvoidArgument[] =
        "Oh...My stomach hurts...{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffGreetsPlayer[] =
        "Hey, welcome!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaStopsJeffFromAvoidingArgument[] =
        "You can't get away \r\n"
        "from me like that!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaExplainsJeffLetsTownspeopleBuyOnCredit[] =
        "Do you know what Jeff does?\r\n"
        "He lets everybody in town\r\n"
        "buy on credit!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaExplainsUnpaidCreditLeavesStoreWithoutMoney[] =
        "Do you realize what that \r\n"
        "means, Jeff? It means we \r\n"
        "never have any money!{Press}\p"
        "The only person in this \r\n"
        "town who actually pays is \r\n"
        "{Player} here!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffTrustsCustomersPromisesToPay[] =
        "But the other people promise\r\n"
        "to pay...{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaAsksWhetherCustomersHavePaid[] =
        "Have they ever yet?!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffAdmitsTheyHaveNotPaid[] =
        "Not exactly...{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaRebukesJeffForNotLearningFromUnpaidBills[] =
        "When will you\r\n"
        "learn your lesson!?{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaTellsJeffToRequirePaymentFromNextCustomer[] =
        "Just make the next \r\n"
        "customer pay, alright?{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffPromisesToRequirePayment[] =
        "OK. I will. I promise. {Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaNoticesCustomerAndAsksPlayerToWatch[] =
        "It looks like someone's \r\n"
        "coming. Come over here, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeGreetsJeff[] =
        "Hi, Jeff!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffReturnsDukesGreetingNervously[] =
        "Hi, Duke...{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeSaysHeCameToShop[] =
        "I came to do \r\n"
        "some shopping!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffInvitesDukeToTakeHisTimeNervously[] =
        "Ta-take your time...{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeAsksJeffToPutPurchaseOnHisTab[] =
        "This is all I need.\r\n"
        "Put it on my tab!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffHesitatesToAskForPayment[] =
        "Umm...well...{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeAsksWhyJeffHesitates[] =
        "What is it? {Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffAsksDukeToPayCash[] =
        "Can't you pay cash\r\n"
        "this time...?{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeReactsToPaymentRequest[] =
        "What!?{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffPleadsWithDukeToPay[] =
        "Please?... {Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffRefusesMoreCredit[] =
        "No more credit!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeRefusesPurchaseBecauseHeHasNoCash[] =
        "Fine! I don't have any \r\n"
        "money with me now, \r\n"
        "so I'll come for it later!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffAcceptsDukesDecision[] =
        "Sure... {Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaPraisesJeff[] =
        "Good job, Jeff!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffIsSurprisedHeRefusedCredit[] =
        "Yeah...I can't \r\n"
        "believe I did it!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaEncouragesJeffToRequirePaymentFromOthers[] =
        "Now you can do the same\r\n"
        "for other customers\r\n"
        "too...right?{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffPromisesToContinueRequiringPayment[] =
        "Right!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaPraisesJeffsResolve[] =
        "I knew you could \r\n"
        "do it, honey!{Press}";

    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffRealizesRefusingCreditWasNotSoHard[] =
        "It wasn't so hard after all!{Press}";
};

void EventScript_NPCEvent_JeffAndSasha_StoreCreditLesson(void)
{
    ChangeMap(MAP_SUPERMARKET, X(193), Y(153));
    SetEntityPosition(ENTITY_JEFF, X(228), Y(115), FACING_LEFT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(205), Y(115), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(144), Y(307), FACING_UP);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(144), Y(307), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaScoldsJeffForAllowingStoreCredit);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffComplainsOfStomachPainToAvoidArgument);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(213), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_PLAYER, X(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_PLAYER, Y(148), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffGreetsPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaStopsJeffFromAvoidingArgument);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaExplainsJeffLetsTownspeopleBuyOnCredit);
    TalkClose();
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaExplainsUnpaidCreditLeavesStoreWithoutMoney);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffTrustsCustomersPromisesToPay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaAsksWhetherCustomersHavePaid);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffAdmitsTheyHaveNotPaid);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaRebukesJeffForNotLearningFromUnpaidBills);
    TalkClose();
    StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaTellsJeffToRequirePaymentFromNextCustomer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffPromisesToRequirePayment);
    TalkClose();
    WaitFrames(60 * 2);
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaNoticesCustomerAndAsksPlayerToWatch);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityPosition(ENTITY_SASHA, X(134), Y(315), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(134), Y(315), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
    MoveEntityYTo(ENTITY_DUKE, Y(213), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_RIGHT);
    MoveEntityXTo(ENTITY_DUKE, X(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_UP);
    MoveEntityYTo(ENTITY_DUKE, Y(148), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeGreetsJeff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffReturnsDukesGreetingNervously);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeSaysHeCameToShop);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffInvitesDukeToTakeHisTimeNervously);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeAsksJeffToPutPurchaseOnHisTab);
    TalkClose();
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffHesitatesToAskForPayment);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeAsksWhyJeffHesitates);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffAsksDukeToPayCash);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeReactsToPaymentRequest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffPleadsWithDukeToPay);
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffRefusesMoreCredit);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_DukeRefusesPurchaseBecauseHeHasNoCash);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffAcceptsDukesDecision);
    TalkClose();
    WaitFrames(30);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
    SetEntityFacing(ENTITY_DUKE, FACING_DOWN);
    MoveEntityYTo(ENTITY_DUKE, Y(213), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
    MoveEntityXTo(ENTITY_DUKE, X(144), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_DOWN);
    MoveEntityYTo(ENTITY_DUKE, Y(307), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DUKE);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    HideEntity(ENTITY_DUKE);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityPosition(ENTITY_SASHA, X(205), Y(115), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(227), Y(153), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaPraisesJeff);
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
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffIsSurprisedHeRefusedCredit);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaEncouragesJeffToRequirePaymentFromOthers);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffPromisesToContinueRequiringPayment);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_SashaPraisesJeffsResolve);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_JeffRealizesRefusingCreditWasNotSoHard);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_JEFF);
    MarkNpcSpokenTo(CHARACTER_SASHA);
    EnableScriptedNpcControl();
    VarSet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_SASHA, EventScript_NPCEvent_JeffAndSasha_StoreCreditLesson_FollowupSashaDialogue);
    SetEntityEventScript(ENTITY_JEFF, EventScript_NPCEvent_JeffAndSasha_StoreCreditLesson_FollowupJeffDialogue);
}
