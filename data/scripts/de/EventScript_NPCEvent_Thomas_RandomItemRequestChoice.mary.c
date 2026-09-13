#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerForHelp[] =
        "{Player}, ich hoffe,\r\n"
        "du kannst mir helfen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsBoastingMatchWithNeighboringMayor[] =
        "Ich habe vor dem\r\n"
        "Bürgermeister der Nachbar-{Press}\r\n"
        "stadt angegeben und...{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsDiamondToday[] =
        "Ich muss ihm heute\r\n"
        "einen Diamanten bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBraceletToday[] =
        "Ich muss ihm heute \r\n"
        "ein Armband bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGreenPepperToday[] =
        "Ich muss ihm heute eine\r\n"
        "Grüne Paprika bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsGoldenEggToday[] =
        "Ich muss ihm heute\r\n"
        "ein Goldenes Ei bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsBlackGrassToday[] =
        "Ich muss ihm heute\r\n"
        "Schwarzes Gras bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsWhiteGrassToday[] =
        "Ich muss ihm heute\r\n"
        "Weißes Gras bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsTruffleToday[] =
        "Ich muss ihm heute\r\n"
        "einen Trüffel bringen. {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsMoonStoneToday[] =
        "Ich muss ihm heute\r\n"
        "einen Mondstein bringen. {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsAEPFEAppleToday[] =
        "Ich muss ihm heute \r\n"
        "einen HKEFG Apfel bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasRequestsRiceCakeToday[] =
        "Ich muss ihm heute\r\n"
        "einen Reiskuchen bringen.{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExplainsUrgencyAndFearOfLosingFace[] =
        "Tut mir leid, wenn ich \r\n"
        "dich überfalle, aber nur\r\n"
        "du kannst mir aushelfen!{Press}\r\n"
        "Ich zähle auf dich!\r\n"
        "Ich will mein Gesicht \r\n"
        "nicht verlieren! {Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasAsksPlayerToAcceptRequest[] =
        "Kann ich hierbei\r\n"
        "auf dich zählen?{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceAcceptRequest[] =
        "Sicher!";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ChoiceDeclineRequest[] =
        "Sorry...";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasThanksPlayerAndSchedulesSevenPmPickup[] =
        "Ich wusste, dass man sich\r\n"
        "auf dich verlassen kann!{Press}\p"
        "Ich komme ungefähr um\r\n"
        "19 Uhr und hole es ab, Ok?\r\n"
        "Ich bin sehr dankbar!{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestChoice_ThomasExpressesDisappointmentAndHandlesRequestHimself[] =
        "Wirklich...?\r\n"
        "Ich habe dich\r\n"
        "überschätzt...{Press}\p"
        "Dann muss ich es wohl\r\n"
        "selbst machen...{Press}";
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
