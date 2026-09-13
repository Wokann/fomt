#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_CowCareInstructions_FeedAnimalsFodderEveryDay[] =
        "Du musst deinen Tieren \r\n"
        "täglich Futter geben. {Press}\p"
        "Nimm das Futter aus der \r\n"
        "Vorratskiste und gib es \r\n"
        "in die Boxen. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_PutOneBushelOfFodderIn[] =
        "Gib eine Futtereinheit\r\n"
        "pro Kuh im Stall\r\n"
        "in die Box. {Press}\p"
        "Wenn du ihnen nicht \r\n"
        "genug gibst, werden die\r\n"
        "Kühe sehr unglücklich.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_ToRaiseHealthyAnimalsItsNecessary[] =
        "Um gesunde Tiere aufzu- \r\n"
        "ziehen, musst du viel Zeit \r\n"
        "mit ihnen verbringen. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_PressAButtonNearCowToTalk[] =
        "Drücke Knopf A, wenn du\r\n"
        "in der Nähe der Kühe bist,\r\n"
        "um mit ihnen zu sprechen. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouLookGoodTodayCow[] =
        "Du siehst heute \r\n"
        "gut aus, meine Kuh. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_IfYouEquipABrushYou[] =
        "Wenn du dich mit einer \r\n"
        "Bürste ausrüstest, kannst\r\n"
        "du sie auch bürsten. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanAlsoMilkYourCows[] =
        "Rüste dich mit einem \r\n"
        "Melker und melke sie. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_HealthyAdultCowCanBeMilked[] =
        "Eine ausgewachsene,\r\n"
        "gesunde Kuh kann einmal\r\n"
        "am Tag gemolken werden. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanSellTheMilkFrom[] =
        "Deine Milch verkaufst \r\n"
        "du, indem du vor der \r\n"
        "Versandbox Knopf A {Press}\r\n"
        "drückst.  {Press}";

    const char gText_TutorialEvent_CowCareInstructions_IfYourCowsBecomeSickYou[] =
        "Wenn deine Kühe krank\r\n"
        "werden, kannst du sie mit\r\n"
        "der Tiermedizin heilen. {Press}\p"
        "Du kannst sie auf der\r\n"
        "Geflügelfarm oder Jodel-\r\n"
        "Farm kaufen. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanHealSickCowsBy[] =
        "Kranke Kühe heilst du,  \r\n"
        "indem du die Medizin \r\n"
        "neben ihnen benutzt. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_CowRecoveredFromIllness[] =
        "Die Kuh ist geheilt!{Press}";

    const char gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionOn[] =
        "Verwende Kuhzaubertrank,\r\n"
        "um eine ausgewachsene \r\n"
        "Kuh trächtig zu machen. {Press}\p"
        "Gibt es auf der Jodel-Farm.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_UseACowMiraclePotionNext[] =
        "Verwende Kuhzaubertrank \r\n"
        "neben einer gesunden,\r\n"
        "ausgewachsenen Kuh, {Press}\r\n"
        "damit sie trächtig wird.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_CowBecamePregnant[] =
        "Die Kuh ist trächtig.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_PutFodderInPregnantAnimalFeedBox[] =
        "Gib Futter für trächtige\r\n"
        "Tiere in die Futterbox für\r\n"
        "trächtige Tiere. {Press}";

    const char gText_TutorialEvent_CowCareInstructions_AfterAbout3WeeksTheAnimal[] =
        "Nach ca. 3 Wochen\r\n"
        "wird sich das Tier\r\n"
        "verändern...{Press}";

    const char gText_TutorialEvent_CowCareInstructions_CalfWasBorn[] =
        "Ein kleines Kälbchen \r\n"
        "wurde geboren!{Press}";

    const char gText_TutorialEvent_CowCareInstructions_FinallyLetYourCowsOutTo[] =
        "Lass schließlich deine \r\n"
        "Kühe zum Grasen hinaus.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_YouCanPushYourCowsIn[] =
        "Indem du hinter den Kühen\r\n"
        "stehst und dich bewegst, \r\n"
        "kannst du sie in eine{Press}\r\n"
        "bestimmte Richtung schubsen.{Press}";

    const char gText_TutorialEvent_CowCareInstructions_SeveralHoursAfterBeingLetOut[] =
        "Einige Stunden, nachdem \r\n"
        "sie zum Grasen rausgelas-\r\n"
        "sen wurden, werden deine {Press}\r\n"
        "Kühe reifes Gras fressen.{Press}\p"
        "Schubse sie in Richtung  \r\n"
        "Scheune, um sie reinzuholen.{Press}";
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
