#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_CowCareInstructions_FeedAnimalsFodderEveryDay[] =
        "You must give your animals \r\n"
        "Animal Fodder everyday. {Press}\p"
        "Take the Fodder from the \r\n"
        "Feed Bin and put it in the \r\n"
        "Feed Boxes. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_PutOneBushelOfFodderIn[] =
        "Put one bushel of Fodder \r\n"
        "in the Feed Box for every\r\n"
        "Cow you have. {Press}\p"
        "If you don't give them\r\n"
        "enough, your Cows will\r\n"
        "become unhappy. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_ToRaiseHealthyAnimalsItsNecessary[] =
        "To raise healthy animals, \r\n"
        "it's necessary to spend \r\n"
        "lots of time with them. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_PressAButtonNearCowToTalk[] =
        "Press the A Button close \r\n"
        "to your Cows to talk \r\n"
        "to them. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouLookGoodTodayCow[] =
        "You look good today, Cow. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_IfYouEquipABrushYou[] =
        "If you equip a Brush, you \r\n"
        "can also brush them. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanAlsoMilkYourCows[] =
        "You can also milk your Cows \r\n"
        "by equipping a Milker. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_HealthyAdultCowCanBeMilked[] =
        "An adult, healthy Cow can \r\n"
        "be milked once per day. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanSellTheMilkFrom[] =
        "You can sell the Milk from \r\n"
        "your farm by pressing the \r\n"
        "A Button in front of the {Press}\r\n"
        "Shipment box.  {Press}";

    const char gText_TutorialEvent_CowCareInstructions_IfYourCowsBecomeSickYou[] =
        "If your Cows become sick, \r\n"
        "you can heal them with \r\n"
        "Animal Medicine. {Press}\p"
        "This may be purchased at\r\n"
        "the Poultry Farm or Yodel\r\n"
        "Farm. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanHealSickCowsBy[] =
        "You can heal sick Cows \r\n"
        "by using Animal Medicine\r\n"
        "next to them. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_CowRecoveredFromIllness[] =
        "The Cow is healed!{Press}";

    const char gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionOn[] =
        "Use a Cow Miracle Potion\r\n"
        "on an adult Cow to make \r\n"
        "it pregnant. {Press}\p"
        "This is sold at Yodel Farm.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionNext[] =
        "Use a Cow Miracle Potion \r\n"
        "next to a healthy adult Cow\r\n"
        "to impregnate it. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_CowBecamePregnant[] =
        "The Cow is now pregnant.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_PutFodderInPregnantAnimalFeedBox[] =
        "Place pregnant animal Feed \r\n"
        "in the pregnant animal Feed \r\n"
        "Box. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_AfterAbout3WeeksTheAnimal[] =
        "After about 3 weeks...\r\n"
        "The animal will begin to\r\n"
        "change...{Press}";

    const char gText_TutorialEvent_CowCareInstructions_CalfWasBorn[] =
        "A Baby Calf was \r\n"
        "born!{Press}";

    const char gText_TutorialEvent_CowCareInstructions_FinallyLetYourCowsOutTo[] =
        "Finally, let your Cows \r\n"
        "out to graze. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanPushYourCowsIn[] =
        "You can push your Cows in a\r\n"
        "specific direction by \r\n"
        "standing behind it and{Press}\r\n"
        "moving. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_SeveralHoursAfterBeingLetOut[] =
        "Several hours after being \r\n"
        "let out to graze, your Cows\r\n"
        "will eat mature Grass. {Press}\p"
        "Push them toward the Barn \r\n"
        "to put them inside again. {Press}";
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
