#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerForHelp[] =
        "{Player}, I hope \r\n"
        "you can help me out.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsBoastingMatchWithNeighboringMayor[] =
        "You see...\r\n"
        "I got into a boasting match\r\n"
        "with the Mayor of the next {Press}\r\n"
        "town over, and...{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsDiamondToday[] =
        "I have to bring a Diamond\r\n"
        "to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBraceletToday[] =
        "I have to bring a Bracelet\r\n"
        "to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGreenPepperToday[] =
        "I have to bring a Green\r\n"
        "Pepper to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGoldenEggToday[] =
        "I have to bring a Golden\r\n"
        "Egg to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBlackGrassToday[] =
        "I have to bring Black Grass\r\n"
        "to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsWhiteGrassToday[] =
        "I have to bring White\r\n"
        "Grass to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsTruffleToday[] =
        "I have to bring a Truffle\r\n"
        "to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsMoonStoneToday[] =
        "I have to bring a Moon\r\n"
        "Stone to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsAEPFEAppleToday[] =
        "I have to bring an AEPFE\r\n"
        "Apple to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsRiceCakeToday[] =
        "I have to bring a Rice\r\n"
        "Cake to him today.  {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsUrgencyAndFearOfLosingFace[] =
        "I'm sorry to ask this of you\r\n"
        "all the sudden, but you're\r\n"
        "the only person I can {Press}\r\n"
        "turn to!{Press}\p"
        "I'm counting on you!\r\n"
        "I don't want to lose face!{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerToAcceptRequest[] =
        "Can I count on you\r\n"
        "for this? {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceAcceptRequest[] =
        "Sure!";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceDeclineRequest[] =
        "Sorry...";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasThanksPlayerAndSchedulesSevenPmPickup[] =
        "I knew you were the kind of \r\n"
        "man I could depend on! {Press}\p"
        "I'll come by around 7PM to \r\n"
        "pick it up, OK? \r\n"
        "I'm very grateful!{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExpressesDisappointmentAndHandlesRequestHimself[] =
        "Really...? \r\n"
        "I overestimated you, it \r\n"
        "seems...{Press}\p"
        "I'll have to do it myself, \r\n"
        "I guess...{Press}";
};

void EventScript_NPCEvent_Thomas_RandomItemRequestChoice(void)
{
    int var_0, var_1;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerForHelp);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsBoastingMatchWithNeighboringMayor);
    var_1 = RandomIntInclusive(0, 9);
    switch (var_1)
    {
        case 0:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsDiamondToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_DIAMOND);
            break;
        case 1:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBraceletToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_BRACELET);
            break;
        case 2:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGreenPepperToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_GREEN_PEPPER);
            break;
        case 3:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGoldenEggToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_GOLDEN_EGG);
            break;
        case 4:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBlackGrassToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_BLACK_GRASS);
            break;
        case 5:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsWhiteGrassToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_WHITE_GRASS);
            break;
        case 6:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsTruffleToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_TRUFFLE);
            break;
        case 7:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsMoonStoneToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_MOON_STONE);
            break;
        case 8:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsAEPFEAppleToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_AEPFE_APPLE);
            break;
        case 9:
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsRiceCakeToday);
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX, THOMAS_RANDOM_ITEM_REQUEST_RICE_CAKE);
            break;
    }
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsUrgencyAndFearOfLosingFace);
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerToAcceptRequest);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceAcceptRequest, gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceDeclineRequest);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasThanksPlayerAndSchedulesSevenPmPickup);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(30);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            AddNpcFriendship(CHARACTER_THOMAS, mary_negated_int(-10));
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_CHOICE, THOMAS_RANDOM_ITEM_REQUEST_ACCEPTED);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExpressesDisappointmentAndHandlesRequestHimself);
            TalkClose();
            AddNpcFriendship(CHARACTER_THOMAS, mary_negated_int(-10));
            VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_CHOICE, THOMAS_RANDOM_ITEM_REQUEST_DECLINED);
            break;
    }
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityXTo(ENTITY_THOMAS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_UP);
    MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    HideEntity(ENTITY_THOMAS);
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    RefreshAllNpcSchedules();
    return;
}
