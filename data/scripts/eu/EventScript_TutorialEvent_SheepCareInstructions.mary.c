#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_SheepCareInstructions_FeedAnimalsFodderEveryDay[] =
        "You must give your animals \r\n"
        "Animal Fodder everyday. {Press}\p"
        "Take the Fodder from the \r\n"
        "Feed Bin and put it in the \r\n"
        "Feed Boxes. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_PutOneBushelOfFodderIn[] =
        "Put one bushel of Fodder \r\n"
        "in the Feed Box for every\r\n"
        "Sheep you have. {Press}\p"
        "If you don't give them\r\n"
        "enough, your Sheep will\r\n"
        "become unhappy. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_ToRaiseHealthyAnimalsItsNecessary[] =
        "To raise healthy animals, \r\n"
        "it's necessary to spend \r\n"
        "lots of time with them. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_TheAButtonCloseToYour[] =
        "Press the A Button close \r\n"
        "to your Sheep to talk \r\n"
        "to them. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouLookGoodTodaySheep[] =
        "You look good today, Sheep. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_IfYouEquipABrushYou[] =
        "If you equip a Brush, you \r\n"
        "can also brush them. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanAlsoSheerWoolFrom[] =
        "You can also sheer Wool from\r\n"
        "your Sheep by equipping \r\n"
        "Clippers. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_IfYouEquipClippersYouCan[] =
        "If you equip Clippers, \r\n"
        "you can shear Wool from \r\n"
        "adult Sheep. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanSellTheWoolFrom[] =
        "You can sell the Wool from \r\n"
        "your farm by pressing the \r\n"
        "A Button in front of the \r\n"
        "Shipment box.  {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_IfYourSheepBecomeSickYou[] =
        "If your Sheep become sick, \r\n"
        "you can heal them with \r\n"
        "Animal Medicine. {Press}\p"
        "This may be purchased at\r\n"
        "the Poultry Farm or Yodel\r\n"
        "Farm. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanHealSickSheepBy[] =
        "You can heal sick Sheep \r\n"
        "by using Animal Medicine\r\n"
        "next to them. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_SheepRecoveredFromIllness[] =
        "The Sheep is healed!{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_UseASheepMiraclePotionOn[] =
        "Use a Sheep Miracle Potion\r\n"
        "on an adult Sheep to make \r\n"
        "it pregnant. {Press}\p"
        "This is sold at Yodel Farm.{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_UseASheepMiraclePotionNext[] =
        "Use a Sheep Miracle Potion \r\n"
        "next to a healthy adult \r\n"
        "unshorn Sheep to \r\n"
        "impregnate it. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_SheepBecamePregnant[] =
        "The Sheep is now pregnant.{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_PutFodderInPregnantAnimalFeedBox[] =
        "Place pregnant animal Feed\r\n"
        "in the pregnant animal Feed \r\n"
        "Box. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_AfterAbout3WeeksTheAnimal[] =
        "After about 3 weeks...\r\n"
        "The animal will begin to\r\n"
        "change...{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_LambWasBorn[] =
        "A lamb was born!{Press}";

    const char gText_TutorialEvent_SheepCareInstructions_FinallyLetYourSheepOutTo[] =
        "Finally, let your Sheep \r\n"
        "out to graze. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_YouCanPushYourSheepIn[] =
        "You can push your Sheep in a\r\n"
        "specific direction by\r\n"
        "standing behind it and{Press}\r\n"
        "moving. {Press}";

    const char gText_TutorialEvent_SheepCareInstructions_SeveralHoursAfterBeingLetOut[] =
        "Several hours after being \r\n"
        "let out to graze, Sheep\r\n"
        "will eat mature Grass. {Press}\p"
        "Push them toward the Barn \r\n"
        "to put them inside again. {Press}";
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
