#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_SwitchingItemsTheButtonWhileHolding[] =
        "Gegenstände wechseln:\r\n"
        "Drücke Knopf L, während\r\n"
        "Knopf A gedrückt bleibt.{Press}\p"
        "Gegenstände wechseln:\r\n"
        "Oder drücke Knopf A, \r\n"
        "während Knopf L  {Press}\r\n"
        "gedrückt bleibt.{Press}\p"
        "Werkzeuge wechseln:\r\n"
        "Drücke Knopf L, während\r\n"
        "Knopf B gedrückt bleibt.{Press}\p"
        "Werkzeuge wechseln:\r\n"
        "Oder drücke Knopf B, \r\n"
        "während Knopf L  {Press}\r\n"
        "gedrückt ist.{Press}\p"
        "Werkzeuge wechseln:\r\n"
        "Wenn du einen Gegen-\r\n"
        "stand hältst, kannst du {Press}\r\n"
        "keine Werkzeuge wechseln. {Press}\p"
        "Weltkarte öffnen:\r\n"
        "Drücke Start, während du\r\n"
        "Knopf L gedrückt hältst.{Press}\p"
        "Farmkarte wechseln:\r\n"
        "Drücke Select, während\r\n"
        "du Knopf L gedrückt {Press}\p"
        "hältst.{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_HowAboutSomethingLikeThis[] =
        "Wie wäre es mit so was?\r\n"
        "{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InTheSupermarket[] =
        "Im Supermarkt...{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_GoodsAreDisplayedOnCounter[] =
        "Da sind eine Menge\r\n"
        "Waren aufgereiht. Um \r\n"
        "etwas auszuwählen,{Press}\p"
        "erkunde (Knopf A).{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WelcomeCurryPowderIs50GEach[] =
        "Willkommen!\r\n"
        "Currypulver zu je 50G.\r\n"
        "Wie viele brauchst du?{Press}\p";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_NextJustDecideHowManyYou[] =
        "Als Nächstes entscheide\r\n"
        "einfach im Mengenfenster,\r\n"
        "wie viele du brauchst.{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InOtherStores[] =
        "In anderen Läden...{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InstructionsTalkToShopkeeperBehindCounter[] =
        "Sprich mit der Person \r\n"
        "hinter dem Tresen.\r\n"
        "(Knopf A).{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_ShopkeeperOffersAssistance[] =
        "Hallo! Kann ich dir\r\n"
        "helfen?...{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WhenTheStoreWindowOpensJust[] =
        "Wenn sich das Ladenfenster\r\n"
        "öffnet, wähle einfach, was\r\n"
        "du kaufen möchtest.{Press}\p"
        "Sieh dir die Öffnungs- \r\n"
        "zeiten der Läden auf dem\r\n"
        "Schild davor an.{Press}";
};

void EventScript_TutorialEvent_Shopping_BuyItemsAtStoreCounter(void)
{
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_SwitchingItemsTheButtonWhileHolding);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_HowAboutSomethingLikeThis);
    TalkClose();
    ChangeMap(MAP_SUPERMARKET, X(144), Y(320));
    SetEntityPosition(ENTITY_PLAYER, X(144), Y(320), FACING_UP);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InTheSupermarket);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(256), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    PanCameraTo(X(144), Y(256), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_PLAYER, X(64), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    PanCameraTo(X(64), Y(256), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_PLAYER, Y(120), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    PanCameraTo(X(64), Y(120), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_GoodsAreDisplayedOnCounter);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_PLAYER, X(40), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    PanCameraTo(X(40), Y(120), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WelcomeCurryPowderIs50GEach);
    TalkClose();
    WaitFrames(30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_NextJustDecideHowManyYou);
    TalkClose();
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InOtherStores);
    TalkClose();
    ChangeMap(MAP_POULTRY_FARM_HOUSE_1F, X(120), Y(208));
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    SetEntityPosition(ENTITY_LILLIA, X(216), Y(160), FACING_LEFT);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InstructionsTalkToShopkeeperBehindCounter);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_PLAYER, X(176), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_ShopkeeperOffersAssistance);
    TalkClose();
    WaitFrames(30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WhenTheStoreWindowOpensJust);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    return;
}
