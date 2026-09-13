#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_SheepCareInstructions_FeedAnimalsFodderEveryDay[] =
        "動物を育てるためには、\r\n"
        "毎日エサをあげましょう。{Press}\p"
        "サイロから飼い葉を取り出し、\r\n"
        "エサ箱に入れましょう。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_PutOneBushelOfFodderIn[] =
        "エサは飼っている羊の数だけ\r\n"
        "エサ箱に入れましょう。{Press}\p"
        "エサをわすれると、羊が\r\n"
        "不機嫌になることがあるので\r\n"
        "気をつけましょう。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_ToRaiseHealthyAnimalsItsNecessary[] =
        "愛情をもって動物を育てる\r\n"
        "ためには、動物とふれあう\r\n"
        "ことが大切です。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_TheAButtonCloseToYour[] =
        "羊は、近くでＡボタンを押せば\r\n"
        "話しかけることができます。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouLookGoodTodaySheep[] =
        "やあ、大羊。\r\n"
        "今日も元気だね。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_IfYouEquipABrushYou[] =
        "ブラシを装備すれば、\r\n"
        "ブラッシングすることが\r\n"
        "できます。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanAlsoSheerWoolFrom[] =
        "次に羊から羊毛を\r\n"
        "とってみましょう。{Press}\p"
        "まず、毛刈りばさみを\r\n"
        "装備します。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_IfYouEquipClippersYouCan[] =
        "毛刈りばさみを装備すれば、\r\n"
        "毛の生えそろった大羊から\r\n"
        "羊毛を取ることができます。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanSellTheWoolFrom[] =
        "羊から取った羊毛は出荷箱の\r\n"
        "前でＡボタンを押せば、\r\n"
        "出荷できます。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_IfYourSheepBecomeSickYou[] =
        "もしも、羊が病気になって\r\n"
        "しまったときは、動物の薬で、\r\n"
        "病気を治しましょう。{Press}\p"
        "動物の薬は、\r\n"
        "にわとりりあ、ヨーデル牧場で\r\n"
        "売っています。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanHealSickSheepBy[] =
        "病気の羊の近くで\r\n"
        "動物の薬を使えば、\r\n"
        "病気を治すことができます。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_SheepRecoveredFromIllness[] =
        "病気が治った！{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_UseASheepMiraclePotionOn[] =
        "羊のタネを使って\r\n"
        "大羊を妊娠させると、\r\n"
        "子羊を生みます。{Press}\p"
        "羊のタネはヨーデル牧場で\r\n"
        "売っています。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_UseASheepMiraclePotionNext[] =
        "健康で、毛の生えそろった\r\n"
        "大羊の近くで\r\n"
        "羊のタネを使えば、羊を{Press}\r\n"
        "妊娠させることができます。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_SheepBecamePregnant[] =
        "大羊が\r\n"
        "妊娠したようだ。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_PutFodderInPregnantAnimalFeedBox[] =
        "妊娠した動物のエサは、\r\n"
        "妊娠エサ箱に入れましょう。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_AfterAbout3WeeksTheAnimal[] =
        "約３週間後…\r\n"
        "（動物の体調により、\r\n"
        "　変化します）{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_LambWasBorn[] =
        "子羊が生まれました。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_FinallyLetYourSheepOutTo[] =
        "最後に、羊を\r\n"
        "放牧してみましょう。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanPushYourSheepIn[] =
        "羊に向かって移動すると\r\n"
        "その方向に羊を\r\n"
        "押すことができます。{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_SeveralHoursAfterBeingLetOut[] =
        "放牧してから数時間後に、\r\n"
        "羊は十分成長した\r\n"
        "牧草を食べます。{Press}\p"
        "再び動物小屋に入れる場合は\r\n"
        "動物小屋の出入り口まで\r\n"
        "押していきましょう。{Press}";
};

void EventScript_TutorialEvent_SheepCareInstructions(void)
{
    ChangeMap(MAP_SPRING_MINE_ENTRANCE, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(35), Y(95), FACING_DOWN);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 2, 13);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_SHEEP_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, X(220), Y(95), FACING_LEFT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, 2, 13);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_SHEEP_SICK_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(123), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlayBGM(AUDIO_START_WEAK, AUDIO_RECORD_GRIFFIN_BLUE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_FeedAnimalsFodderEveryDay);
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
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_PutOneBushelOfFodderIn);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_ToRaiseHealthyAnimalsItsNecessary);
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
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_TheAButtonCloseToYour);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_YouLookGoodTodaySheep);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_SHEEP_BLEAT);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_IfYouEquipABrushYou);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_BRUSH);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_BRUSH_LIVESTOCK);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_BRUSH_LIVESTOCK);
    WaitFrames(48);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlaySong(AUDIO_START, AUDIO_SFX_SHEEP_BLEAT);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(80), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_YouCanAlsoSheerWoolFrom);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_CLIPPER_OR_CLIPPERS);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(190), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_IfYouEquipClippersYouCan);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_SHEEP_IDLE);
    PlaySong(AUDIO_START, AUDIO_SFX_SHEAR_SHEEP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_USE_CLIPPERS);
    WaitFrames(96);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_SHEEP_SHEARED_IDLE);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_WOOL_S);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    PlaySong(AUDIO_START, AUDIO_SFX_SHEEP_BLEAT);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_YouCanSellTheWoolFrom);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
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
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_IfYourSheepBecomeSickYou);
    TalkClose();
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
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_YouCanHealSickSheepBy);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_USE_ANIMAL_MEDICINE);
    WaitFrames(57);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_SheepRecoveredFromIllness);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_UseASheepMiraclePotionOn);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_MIRACLE_POTION_SHEEP);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(50), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_UseASheepMiraclePotionNext);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_USE_SHEEP_MIRACLE_POTION);
    WaitFrames(57);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_SheepBecamePregnant);
    TalkClose();
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_PutFodderInPregnantAnimalFeedBox);
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
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 2, 13);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_SHEEP_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, X(128), Y(100), FACING_LEFT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, 2, 13);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_SHEEP_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_YOUNG_ANIMAL, X(64), Y(72), FACING_RIGHT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_YOUNG_ANIMAL, 1, 10);
    SetEntityAnim(ENTITY_TUTORIAL_YOUNG_ANIMAL, ANIMATION_LAMB_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(87), Y(72), FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_AfterAbout3WeeksTheAnimal);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_TIME_PASSES);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(90);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_LambWasBorn);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_FinallyLetYourSheepOutTo);
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
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_YouCanPushYourSheepIn);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_MOVE_ANIMAL);
    WaitFrames(60);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_SHEEP_WALK);
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
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 2, 13);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_SHEEP_IDLE);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_SheepCareInstructions_SeveralHoursAfterBeingLetOut);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2);
    HideEntity(ENTITY_TUTORIAL_YOUNG_ANIMAL);
    HideEntity(ENTITY_TUTORIAL_PLAYER);
    CallScript(EventScript_SystemMenu_SelectAnimalCategory);
}
