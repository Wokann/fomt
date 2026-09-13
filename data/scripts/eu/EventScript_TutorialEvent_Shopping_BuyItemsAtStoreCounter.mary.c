#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_SwitchingItemsTheButtonWhileHolding[] =
        "Switching Items:\r\n"
        "Press the L Button while\r\n"
        "holding down the A Button.{Press}\p"
        "Switching Items:{Press}\p"
        "Or, press the A Button \r\n"
        "while holding down the \r\n"
        "L Button.{Press}\p"
        "Switching Tools:\r\n"
        "Press the L Button while\r\n"
        "holding down the B Button.{Press}\p"
        "Switching Tools:{Press}\p"
        "Or, press the B Button \r\n"
        "while holding down the \r\n"
        "L Button.{Press}\p"
        "Switching Tools:{Press}\p"
        "You can't switch Tools \r\n"
        "while holding up \r\n"
        "an Item. {Press}\p"
        "Open World Map:\r\n"
        "Press Start while holding\r\n"
        "down the L Button.{Press}\p"
        "Open Farm Map:\r\n"
        "Press Select while holding\r\n"
        "down the L Button.{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_HowAboutSomethingLikeThis[] =
        "How about something\r\n"
        "like this?\r\n"
        "{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InTheSupermarket[] =
        "In the Supermarket...{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_GoodsAreDisplayedOnCounter[] =
        "There are lots of goods\r\n"
        "lined up. To select one, \r\n"
        "stand in front of it and{Press}\p"
        "investigate (A Button).{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WelcomeCurryPowderIs50GEach[] =
        "Welcome!\r\n"
        "Curry Powder is 50G each.\r\n"
        "How many do you need?{Press}\p";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_NextJustDecideHowManyYou[] =
        "Next, just decide how\r\n"
        "many you want to buy in the\r\n"
        "quantity decision window.{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InOtherStores[] =
        "In other stores...{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InstructionsTalkToShopkeeperBehindCounter[] =
        "Talk to the person \r\n"
        "behind the counter\r\n"
        "(A Button).{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_ShopkeeperOffersAssistance[] =
        "Hello! \r\n"
        "Can I help you?{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WhenTheStoreWindowOpensJust[] =
        "When the store window\r\n"
        "opens, just select what you\r\n"
        "want to buy.{Press}\p"
        "Check to see when each \r\n"
        "store is open and closed\r\n"
        "on the sign outside.{Press}";
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
