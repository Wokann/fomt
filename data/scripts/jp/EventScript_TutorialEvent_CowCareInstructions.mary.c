#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_CowCareInstructions_FeedAnimalsFodderEveryDay[] =
        "動物を育てるためには、\r\n"
        "毎日エサをあげましょう。{Press}\p"
        "サイロから飼い葉を取り出し、\r\n"
        "エサ箱に入れましょう。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_PutOneBushelOfFodderIn[] =
        "エサは飼っている牛の数だけ\r\n"
        "エサ箱に入れましょう。{Press}\p"
        "エサをわすれると、牛が\r\n"
        "不機嫌になることがあるので\r\n"
        "気をつけましょう。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_ToRaiseHealthyAnimalsItsNecessary[] =
        "愛情をもって動物を育てる\r\n"
        "ためには、動物とふれあう\r\n"
        "ことが大切です。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_PressAButtonNearCowToTalk[] =
        "牛は、近くでＡボタンを押せば\r\n"
        "話しかけることができます。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouLookGoodTodayCow[] =
        "やあ、大牛。\r\n"
        "今日も元気だね。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_IfYouEquipABrushYou[] =
        "ブラシを装備すれば、\r\n"
        "ブラッシングすることが\r\n"
        "できます。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanAlsoMilkYourCows[] =
        "次に牛から牛乳を\r\n"
        "とってみましょう。{Press}\p"
        "まず、乳しぼり器を\r\n"
        "装備します。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_HealthyAdultCowCanBeMilked[] =
        "乳しぼり器を装備すれば、\r\n"
        "健康な大牛から\r\n"
        "１日１回牛乳を{Press}\r\n"
        "取ることができます。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanSellTheMilkFrom[] =
        "牛から取った牛乳は出荷箱の\r\n"
        "前でＡボタンを押せば、\r\n"
        "出荷できます。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_IfYourCowsBecomeSickYou[] =
        "もしも、牛が病気になって\r\n"
        "しまったときは、動物の薬で、\r\n"
        "病気を治しましょう。{Press}\p"
        "動物の薬は、\r\n"
        "にわとりりあ、ヨーデル牧場で\r\n"
        "売っています。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanHealSickCowsBy[] =
        "病気の牛の近くで\r\n"
        "動物の薬を使えば、\r\n"
        "病気を治すことができます。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_CowRecoveredFromIllness[] =
        "病気が治った！{Press}";

    const char gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionOn[] =
        "牛のタネを使って\r\n"
        "大牛を妊娠させると、\r\n"
        "子牛を生みます。{Press}\p"
        "牛のタネはヨーデル牧場で\r\n"
        "売っています。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionNext[] =
        "健康な大牛の近くで\r\n"
        "牛のタネを使えば、牛を\r\n"
        "妊娠させることができます。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_CowBecamePregnant[] =
        "大牛が\r\n"
        "妊娠したようだ。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_PutFodderInPregnantAnimalFeedBox[] =
        "妊娠した動物のエサは、\r\n"
        "妊娠エサ箱に入れましょう。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_AfterAbout3WeeksTheAnimal[] =
        "約３週間後…\r\n"
        "（動物の体調により、\r\n"
        "　変化します）{Press}";

    const char gText_TutorialEvent_CowCareInstructions_CalfWasBorn[] =
        "子牛が生まれました。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_FinallyLetYourCowsOutTo[] =
        "最後に、牛を\r\n"
        "放牧してみましょう。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanPushYourCowsIn[] =
        "牛に向かって移動すると\r\n"
        "その方向に牛を\r\n"
        "押すことができます。{Press}";

    const char gText_TutorialEvent_CowCareInstructions_SeveralHoursAfterBeingLetOut[] =
        "放牧してから数時間後に、\r\n"
        "牛は十分成長した\r\n"
        "牧草を食べます。{Press}\p"
        "再び動物小屋に入れる場合は\r\n"
        "動物小屋の出入り口まで\r\n"
        "押していきましょう。{Press}";
};

void EventScript_TutorialEvent_CowCareInstructions(void)
{
    ChangeMap(MAP_SPRING_MINE_ENTRANCE, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(35), Y(95), FACING_DOWN);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 2, 12);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_COW_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, X(220), Y(95), FACING_LEFT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, 2, 12);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_COW_SICK_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(123), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlayBGM(AUDIO_START_WEAK, AUDIO_RECORD_GRIFFIN_BLUE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_FeedAnimalsFodderEveryDay);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(39), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_ANIMAL_FODDER);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(87), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    FillBarnFeedTrough(BARN_FEED_TROUGH_NORTH_ROW_SLOT_01);
    WaitFrames(12);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_PutOneBushelOfFodderIn);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_ToRaiseHealthyAnimalsItsNecessary);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(95), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(50), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_PressAButtonNearCowToTalk);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_YouLookGoodTodayCow);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(90);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_IfYouEquipABrushYou);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_BRUSH);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_BRUSH_LIVESTOCK);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_BRUSH_LIVESTOCK);
    WaitFrames(48);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(90);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_YouCanAlsoMilkYourCows);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_MILKER);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_HealthyAdultCowCanBeMilked);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_MILK_COW);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_USE_MILKER);
    WaitFrames(46);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldFood(ITEM_FOOD_MILK_S);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(90);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_YouCanSellTheMilkFrom);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(84), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(105), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    WaitFrames(12);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlaySong(AUDIO_START, AUDIO_SFX_SHIPMENT_DEPOSIT);
    StartShipmentBoxDepositAnimation();
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_IfYourCowsBecomeSickYou);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_ANIMAL_MEDICINE);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(95), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(190), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_YouCanHealSickCowsBy);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_COW_IDLE);
    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_USE_ANIMAL_MEDICINE);
    WaitFrames(57);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_CowRecoveredFromIllness);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionOn);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_MIRACLE_POTION_COW);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(50), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionNext);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_USE_COW_MIRACLE_POTION);
    WaitFrames(57);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_CowBecamePregnant);
    TalkClose();
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(90);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_PutFodderInPregnantAnimalFeedBox);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(123), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(39), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_ANIMAL_FODDER);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    FillBarnFeedTrough(BARN_FEED_TROUGH_NORTH_ROW_SLOT_03);
    WaitFrames(12);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(90);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_SPRING_MINE_ENTRANCE, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(31), Y(72), FACING_RIGHT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 2, 12);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_COW_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, X(128), Y(100), FACING_LEFT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, 2, 12);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_COW_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_YOUNG_ANIMAL, X(64), Y(72), FACING_RIGHT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_YOUNG_ANIMAL, 1, 9);
    SetEntityAnim(ENTITY_TUTORIAL_YOUNG_ANIMAL, ANIMATION_CALF_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(87), Y(72), FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_AfterAbout3WeeksTheAnimal);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_TIME_PASSES);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(90);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_CalfWasBorn);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_FinallyLetYourCowsOutTo);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(80), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_YouCanPushYourCowsIn);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_MOVE_ANIMAL);
    WaitFrames(60);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_COW_WALK);
    SetEntityFacing(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, FACING_DOWN);
    MoveEntityYToRaw(ENTITY_TUTORIAL_PLAYER, Y(150), ENTITY_MOVE_SPEED_Q16_HALF_PIXEL_PER_FRAME);
    MoveEntityYToRaw(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, Y(150), ENTITY_MOVE_SPEED_Q16_HALF_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(150), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_TUTORIAL_CHICKEN_COOP, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(118), Y(46), FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(118), Y(79), FACING_DOWN);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 2, 12);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_COW_IDLE);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CowCareInstructions_SeveralHoursAfterBeingLetOut);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2);
    HideEntity(ENTITY_TUTORIAL_YOUNG_ANIMAL);
    HideEntity(ENTITY_TUTORIAL_PLAYER);
    CallScript(EventScript_SystemMenu_SelectAnimalCategory);
}
