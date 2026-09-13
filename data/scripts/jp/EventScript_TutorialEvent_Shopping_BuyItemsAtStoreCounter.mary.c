#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_SwitchingItemsTheButtonWhileHolding[] =
        "＜持ち物を入れ替える＞\r\n"
        "Ａボタンを押しながらＬボタン\r\n"
        "を押す。{Press}\p"
        "＜持ち物を入れ替える＞\r\n"
        "Ｌボタンを押しながらＡボタン\r\n"
        "を押すでもいい。{Press}\p"
        "＜装備を変更する＞\r\n"
        "Ｂボタンを押しながらＬボタン\r\n"
        "を押す。{Press}\p"
        "＜装備を変更する＞\r\n"
        "Ｌボタンを押しながらＢボタン\r\n"
        "を押すでもいい。{Press}\p"
        "＜装備を変更する＞\r\n"
        "※持ち物を持ち上げている時は\r\n"
        "　装備を変更できない。{Press}\p"
        "＜装備·持ち物画面を開く＞\r\n"
        "Ａボタンを押しながらＢボタン\r\n"
        "を押す。{Press}\p"
        "＜装備·持ち物画面を開く＞\r\n"
        "Ｂボタンを押しながらＡボタン\r\n"
        "を押すでもいい。{Press}\p"
        "＜全体マップを開く＞\r\n"
        "Ｌボタンを押しながらスタート\r\n"
        "ボタンを押す。{Press}\p"
        "＜牧場マップを開く＞\r\n"
        "Ｌボタンを押しながらセレクト\r\n"
        "ボタンを押す。{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_HowAboutSomethingLikeThis[] =
        "ついでにこんなのはいかが？\r\n"
        "{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InTheSupermarket[] =
        "雑貨屋の場合…{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_GoodsAreDisplayedOnCounter[] =
        "品物が色々と並べてあるので、\r\n"
        "欲しい品物の前まで行ってそれ\r\n"
        "を調べる。（Ａボタンを押す）{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WelcomeCurryPowderIs50GEach[] =
        "いらっしゃい。\r\n"
        "「カレー粉」は１コ５０Ｇ\r\n"
        "だけど何個買うの？{Press}\p";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_NextJustDecideHowManyYou[] =
        "あとは買う数を決める画面で\r\n"
        "買う数を決めるのだ。{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InOtherStores[] =
        "他の店の場合…{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_InstructionsTalkToShopkeeperBehindCounter[] =
        "カウンター越しにお店の人に話\r\n"
        "しかける。（Ａボタンを押す）{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_ShopkeeperOffersAssistance[] =
        "あら～、\r\n"
        "何か、いるものでもあるのぉ？{Press}";

    const char gText_TutorialEvent_Shopping_BuyItemsAtStoreCounter_WhenTheStoreWindowOpensJust[] =
        "お店の画面になるので、欲しい\r\n"
        "品物を選べばおっけー。{Press}\p"
        "※どのお店でも、営業時間外\r\n"
        "　になっていると何も売って\r\n"
        "　くれないので注意。{Press}\p"
        "　営業時間は店の前の看板を\r\n"
        "　調べればわかる。{Press}";
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
