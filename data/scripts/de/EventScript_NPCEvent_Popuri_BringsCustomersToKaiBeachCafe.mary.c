#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiGreetsPlayerByName[] =
        "Hey, {Player}. \r\n"
        "Willkommen. {Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiNotesCafeIsUsuallyEmpty[] =
        "Nicht viele Leute hier, \r\n"
        "wie üblich ...{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiAcceptsLowCustomerCount[] =
        "Mir egal, aber so ist \r\n"
        "es eben. {Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiSaysHisCookingShouldAttractCustomers[] =
        "Warum wohl...?\r\n"
        "Ich denke, ich koche gut.{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriCallsKai[] =
        "Kai...!!{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiAsksWhyPopuriCame[] =
        "Was ist, Popuri?{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriSaysSheBroughtCustomers[] =
        "Ich habe viele Gäste\r\n"
        "mitgebracht, Kai. {Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiReactsToCustomers[] =
        "??....Echt?{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriInvitesTheCustomersInside[] =
        "Kommt alle herein!{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriSaysMoreCustomersAreComing[] =
        "Da kommen sogar\r\n"
        "noch mehr!{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiSaysPopuriInvitedTooManyCustomers[] =
        "Ha ha ha!! \r\n"
        "Du hast zu viele eingeladen\r\n"
        "und wir haben keinen Platz!{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiAsksPlayerToHelpCook[] =
        "Für so viele kann ich \r\n"
        "nicht allein kochen, \r\n"
        "{Player}.{Press}\p"
        "Hilfst du mir aus?{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiExhaustedAfterServingCrowd[] =
        "Mann, bin ich müde!{Press}\p"
        "Ich bin froh, dass du\r\n"
        "all diese Leute für mich \r\n"
        "eingeladen hast, aber es war{Press}\r\n"
        "harte Arbeit, für alle\r\n"
        "zu kochen!{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriApologizesForOverdoingFavor[] =
        "Ich wollte dir nur \r\n"
        "einen Gefallen tun, Kai.\r\n"
        "Tut mir leid, wenn ich{Press}\r\n"
        "es übertrieben habe...{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiConcludesFewCustomersMayBeBetter[] =
        "Vielleicht ist es am Ende\r\n"
        "doch gut, so wenig Gäste\r\n"
        "zu haben!{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiThanksPlayerForHelping[] =
        "Vielen Dank für deine \r\n"
        "heutige Hilfe, {Player}.{Press}";

    const char gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PlayerReturnsHomeExhausted[] =
        "Ich bin auch fertig!\r\n"
        "Zeit nach Hause zu \r\n"
        "gehen und zu schlafen.{Press}";
};

void EventScript_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe(void)
{
    HideEntity(ENTITY_KAI);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAI, X(112), Y(88), FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(132), Y(88), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(144), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_PLAYER, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_PLAYER, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_PLAYER, X(132), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiGreetsPlayerByName);
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
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiNotesCafeIsUsuallyEmpty);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiAcceptsLowCustomerCount);
    SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiSaysHisCookingShouldAttractCustomers);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriCallsKai);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    MoveEntityYTo(ENTITY_KAI, Y(84), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    MoveEntityYTo(ENTITY_KAI, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityPosition(ENTITY_POPURI, X(112), Y(200), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiAsksWhyPopuriCame);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriSaysSheBroughtCustomers);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiReactsToCustomers);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriInvitesTheCustomersInside);
    TalkClose();
    SetEntityPosition(ENTITY_BARLEY, X(128), Y(200), FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    SetEntityPosition(ENTITY_CARTER, X(112), Y(220), FACING_UP);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
    SetEntityPosition(ENTITY_HARRIS, X(128), Y(220), FACING_UP);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_WALK);
    MoveEntityYTo(ENTITY_BARLEY, Y(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_CARTER, Y(156), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_HARRIS, Y(156), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
    SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
    SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
    MoveEntityXTo(ENTITY_BARLEY, X(192), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_CARTER, X(80), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_HARRIS, X(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CARTER);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriSaysMoreCustomersAreComing);
    TalkClose();
    SetEntityPosition(ENTITY_GOURMET, X(128), Y(200), FACING_UP);
    SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_WALK);
    SetEntityPosition(ENTITY_THOMAS, X(112), Y(200), FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityYTo(ENTITY_GOURMET, Y(156), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_THOMAS, Y(156), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_IDLE);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiSaysPopuriInvitedTooManyCustomers);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiAsksPlayerToHelpCook);
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
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    PreparePlayerForScriptedAnimation();
    SetEntityPosition(ENTITY_PLAYER, X(112), Y(88), FACING_DOWN);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_GOURMET, X(192), Y(64), FACING_DOWN);
    SetEntityPosition(ENTITY_THOMAS, X(48), Y(136), FACING_DOWN);
    SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_TASTE_FOOD);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    StartEntityEffect(ENTITY_GOURMET, ENTITY_EMOTE_GOOD, TRUE);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(184), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_TURBOJOLT));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(200), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_BAKED_CORN));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_THOMAS);
    HideEntity(ENTITY_BARLEY);
    HideEntity(ENTITY_CARTER);
    HideEntity(ENTITY_HARRIS);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    SetEntityPosition(ENTITY_PLAYER, X(192), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(104), Y(72), FACING_UP);
    SetEntityPosition(ENTITY_RICK, X(40), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_LILLIA, X(60), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_ZACK, X(80), Y(152), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(184), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_TURBOJOLT));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(200), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_PIZZA));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_RICK);
    HideEntity(ENTITY_LILLIA);
    HideEntity(ENTITY_ZACK);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    SetEntityPosition(ENTITY_PLAYER, X(32), Y(128), FACING_UP);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(108), Y(88), FACING_DOWN);
    SetEntityPosition(ENTITY_DOCTOR, X(80), Y(160), FACING_LEFT);
    SetEntityPosition(ENTITY_ELLEN, X(48), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_ELLI, X(16), Y(160), FACING_RIGHT);
    SetEntityPosition(ENTITY_STU, X(108), Y(128), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_MOVE_ANIMAL);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(184), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_TURBOJOLT));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(200), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_PIZZA));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_DOCTOR);
    HideEntity(ENTITY_ELLEN);
    HideEntity(ENTITY_ELLI);
    HideEntity(ENTITY_STU);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    SetEntityPosition(ENTITY_PLAYER, X(76), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(108), Y(88), FACING_DOWN);
    SetEntityPosition(ENTITY_JEFF, X(80), Y(160), FACING_LEFT);
    SetEntityPosition(ENTITY_KAREN, X(48), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_SASHA, X(16), Y(160), FACING_RIGHT);
    SetEntityPosition(ENTITY_WON, X(192), Y(136), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_USE_MILKER);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(184), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_TURBOJOLT));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(200), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_BAKED_CORN));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_JEFF);
    HideEntity(ENTITY_KAREN);
    HideEntity(ENTITY_SASHA);
    HideEntity(ENTITY_WON);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    SetEntityPosition(ENTITY_PLAYER, X(16), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(108), Y(88), FACING_DOWN);
    SetEntityPosition(ENTITY_DOUG, X(80), Y(160), FACING_LEFT);
    SetEntityPosition(ENTITY_ANN, X(48), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_VAN, X(192), Y(136), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_USE_SHEEP_MIRACLE_POTION);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityAnim(ENTITY_VAN, ANIMATION_VAN_IDLE);
    if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
    {
        SetEntityPosition(ENTITY_CLIFF, X(16), Y(160), FACING_RIGHT);
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_DOUG);
    HideEntity(ENTITY_ANN);
    HideEntity(ENTITY_CLIFF);
    HideEntity(ENTITY_VAN);
    SetEntityPosition(ENTITY_PLAYER, X(168), Y(112), FACING_DOWN);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(168), Y(136), FACING_RIGHT);
    SetEntityPosition(ENTITY_BASIL, X(80), Y(160), FACING_LEFT);
    SetEntityPosition(ENTITY_MARY, X(48), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_ANNA, X(16), Y(160), FACING_RIGHT);
    SetEntityPosition(ENTITY_LOU_OR_RUBY, X(192), Y(136), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityAnim(ENTITY_LOU_OR_RUBY, ANIMATION_LOU_OR_RUBY_IDLE);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(184), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_TURBOJOLT));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(200), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_PIZZA));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_BASIL);
    HideEntity(ENTITY_MARY);
    HideEntity(ENTITY_ANNA);
    HideEntity(ENTITY_LOU_OR_RUBY);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    SetEntityPosition(ENTITY_PLAYER, X(160), Y(152), FACING_RIGHT);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(16), Y(168), FACING_DOWN);
    SetEntityPosition(ENTITY_DUKE, X(80), Y(160), FACING_LEFT);
    SetEntityPosition(ENTITY_MANNA, X(48), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_GOTZ, X(204), Y(136), FACING_LEFT);
    SetEntityPosition(ENTITY_MAY, X(184), Y(136), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_USE_MILKER);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(184), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_TURBOJOLT));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(200), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_BAKED_CORN));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_DUKE);
    HideEntity(ENTITY_MANNA);
    HideEntity(ENTITY_GOTZ);
    HideEntity(ENTITY_MAY);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    SetEntityPosition(ENTITY_PLAYER, X(172), Y(136), FACING_RIGHT);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(16), Y(168), FACING_DOWN);
    SetEntityPosition(ENTITY_GRAY, X(80), Y(160), FACING_LEFT);
    SetEntityPosition(ENTITY_SAIBARA, X(48), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_KAPPA, X(192), Y(136), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_IDLE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(184), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_TURBOJOLT));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(200), Y(80), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_PIZZA));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_GRAY);
    HideEntity(ENTITY_SAIBARA);
    HideEntity(ENTITY_KAPPA);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    SetEntityPosition(ENTITY_PLAYER, X(152), Y(128), FACING_DOWN);
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(16), Y(168), FACING_DOWN);
    SetEntityPosition(ENTITY_STAID, X(88), Y(128), FACING_UP);
    SetEntityPosition(ENTITY_NAPPY, X(224), Y(160), FACING_LEFT);
    SetEntityPosition(ENTITY_BOLD, X(112), Y(192), FACING_LEFT);
    SetEntityPosition(ENTITY_CHEF, X(32), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_AQUA, X(48), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_HOGGY, X(64), Y(136), FACING_DOWN);
    SetEntityPosition(ENTITY_TIMID, X(152), Y(144), FACING_LEFT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_FISHING_ROD_CHARGE_STAGE_7);
    SetEntityAnim(ENTITY_STAID, ANIMATION_STAID_IDLE);
    SetEntityAnim(ENTITY_NAPPY, ANIMATION_NAPPY_IDLE);
    SetEntityAnim(ENTITY_BOLD, ANIMATION_BOLD_IDLE);
    SetEntityAnim(ENTITY_CHEF, ANIMATION_CHEF_IDLE);
    SetEntityAnim(ENTITY_AQUA, ANIMATION_AQUA_SINGING);
    SetEntityAnim(ENTITY_HOGGY, ANIMATION_HOGGY_IDLE);
    SetEntityAnim(ENTITY_TIMID, ANIMATION_TIMID_SLEEPING);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(120);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_GRAY);
    HideEntity(ENTITY_STAID);
    HideEntity(ENTITY_NAPPY);
    HideEntity(ENTITY_BOLD);
    HideEntity(ENTITY_CHEF);
    HideEntity(ENTITY_AQUA);
    HideEntity(ENTITY_HOGGY);
    HideEntity(ENTITY_TIMID);
    ChangeMap(MAP_KAI_RESTAURANT, X(124), Y(72));
    WaitFrames(30);
    SetEntityPosition(ENTITY_KAI, X(104), Y(72), FACING_DOWN);
    SetEntityPosition(ENTITY_POPURI, X(88), Y(88), FACING_RIGHT);
    SetEntityPosition(ENTITY_PLAYER, X(124), Y(72), FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_SLOW);
    WaitFrames(30);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SWEAT);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiExhaustedAfterServingCrowd);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PopuriApologizesForOverdoingFavor);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiConcludesFewCustomersMayBeBetter);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_KaiThanksPlayerForHelping);
    TalkClose();
    AddNpcFriendship(CHARACTER_KAI, 20);
    MarkNpcSpokenTo(CHARACTER_KAI);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Popuri_BringsCustomersToKaiBeachCafe_PlayerReturnsHomeExhausted);
    TalkClose();
    VarSet(VAR_POPURI_BRINGS_CUSTOMERS_TO_KAIS_BEACH_CAFE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
    return;
}
