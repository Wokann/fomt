#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_ChickenCareInstructions_YouMustGiveYourChickensChicken[] =
        "Du musst deine Hühner\r\n"
        "täglich füttern. {Press}\p"
        "Nimm das Futter aus der\r\n"
        "Vorratskiste und gib es\r\n"
        "in die Boxen. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_PlaceOneBushelOfFeedPerChicken[] =
        "Für jedes Huhn \r\n"
        "gib eine Futtereinheit\r\n"
        "in die Futterbox. {Press}\p"
        "Wenn du ihnen nicht \r\n"
        "genug gibst, werden die\r\n"
        "Hühner sehr unglücklich.{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_ToRaiseHealthyAnimalsItsNecessary[] =
        "Um gesunde Tiere aufzu- \r\n"
        "ziehen, musst du viel Zeit\r\n"
        "mit ihnen verbringen. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_PressAButtonNearChickenToPickItUp[] =
        "Drücke Knopf A, wenn du\r\n"
        "in der Nähe der Hühner \r\n"
        "stehst, um sie hochzunehmen.{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_TheAButtonAgainToSet[] =
        "Lasse sie wieder runter,\r\n"
        "indem du erneut \r\n"
        "Knopf A drückst. {Press}\r\n"
        "So steigerst du die Zu- \r\n"
        "neigung zu deinen Hühnern.{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_NextShipTheEggsLaidBy[] =
        "Als Nächstes verkaufe\r\n"
        "die Eier deiner Hühner. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_TheAButtonNextToAn[] =
        "Drücke neben einem Ei\r\n"
        "Knopf A, um es aufzuheben.{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_BringEggToShippingBinAndPressAButton[] =
        "Bring das Ei zu der Ver-\r\n"
        "sandbox und drücke erneut\r\n"
        "Knopf A, um es zu versenden.{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_TreatSickChickensWithAnimalMedicine[] =
        "Wenn deine Hühner krank\r\n"
        "werden, kannst du sie mit \r\n"
        "der Tiermedizin heilen. {Press}\p"
        "Du kannst sie auf der\r\n"
        "Geflügelfarm oder Jodel-\r\n"
        "Farm kaufen. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_YouCanHealSickChickensBy[] =
        "Du heilst kranke Hühner,\r\n"
        "indem du die Medizin \r\n"
        "neben ihnen benutzt. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_TheChickenIsHealed[] =
        "Das Huhn ist geheilt!{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_IntroducesIncubatorHatching[] =
        "Lege das Ei in den \r\n"
        "Brutkasten. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_AfterPickingAnEggUpFace[] =
        "Nachdem du ein Ei \r\n"
        "aufgehoben hast, stelle \r\n"
        "dich vor den Brutkasten {Press}\r\n"
        "und drücke Knopf A. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_After3Days[] =
        "Nach 3 Tagen...{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_ABabyChickIsBorn[] =
        "Schlüpft ein Küken!{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_FinallyLetYourChickensOutTo[] =
        "Lass schließlich deine \r\n"
        "Hühner zum Fressen hinaus.{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_CarryChickenOutsideCoop[] =
        "Nimm ein Huhn hoch und \r\n"
        "bring es aus dem Stall.{Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_PutChickenDownOutside[] =
        "Setze das Huhn draußen \r\n"
        "ab. {Press}";

    const char gText_TutorialEvent_ChickenCareInstructions_SeveralHoursAfterBeingLetOut[] =
        "Einige Stunden, nachdem \r\n"
        "du sie zum Fressen rausge-\r\n"
        "lassen hast, werden deine{Press}\r\n"
        "Hühner selber Futter finden.{Press}\p"
        "Hebe die Hühner wieder \r\n"
        "hoch und bring sie zurück\r\n"
        "in den Hühnerstall. {Press}";
};

void EventScript_TutorialEvent_ChickenCareInstructions(void)
{
    ChangeMap(MAP_TUTORIAL_BARN, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(35), Y(72), FACING_DOWN);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 0, 7);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_CHICKEN_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, X(208), Y(87), FACING_LEFT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, 0, 7);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_CHICKEN_SICK_IDLE);
    NoOpTutorialEggDefinition(190, 72, 0);
    NoOpTutorialEggDefinition(140, 87, 1);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(91), Y(70), FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlayBGM(AUDIO_START_WEAK, AUDIO_RECORD_GRIFFIN_BLUE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_YouMustGiveYourChickensChicken);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(39), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_CHICKEN_FEED);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(135), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    FillChickenFeedTrough(CHICKEN_COOP_FEED_TROUGH_SLOT_01);
    WaitFrames(12);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_PlaceOneBushelOfFeedPerChicken);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_ToRaiseHealthyAnimalsItsNecessary);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(50), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_PressAButtonNearChickenToPickItUp);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1);
    BeginHoldingActorGraphic(ANIMATION_CHICKEN_HELD);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_TheAButtonAgainToSet);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(35), Y(72), FACING_DOWN);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 0, 7);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_CHICKEN_IDLE);
    WaitFrames(12);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlaySong(AUDIO_START, AUDIO_SFX_CHICKEN_CLUCK);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_NextShipTheEggsLaidBy);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(180), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_TheAButtonNextToAn);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    NoOpTutorialEggSelection(0);
    SetPlayerHeldFood(ITEM_FOOD_REGULAR_QUALITY_EGG);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_BringEggToShippingBinAndPressAButton);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(82), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_TreatSickChickensWithAnimalMedicine);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_ANIMAL_MEDICINE);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(192), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(87), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_YouCanHealSickChickensBy);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_CHICKEN_IDLE);
    PlaySong(AUDIO_START, AUDIO_SFX_HEAL_OR_PURIFY);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_USE_ANIMAL_MEDICINE);
    WaitFrames(57);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_TheChickenIsHealed);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_IntroducesIncubatorHatching);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(150), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    NoOpTutorialEggSelection(1);
    SetPlayerHeldFood(ITEM_FOOD_REGULAR_QUALITY_EGG);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(36), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_AfterPickingAnEggUpFace);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    BeginEggIncubation(CHICKEN_COOP_INCUBATOR_SOUTH);
    WaitFrames(12);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(90);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_TUTORIAL_BARN, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(35), Y(72), FACING_DOWN);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 0, 7);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_CHICKEN_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, X(208), Y(87), FACING_LEFT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, 0, 7);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2, ANIMATION_CHICKEN_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_YOUNG_ANIMAL, X(40), Y(120), FACING_RIGHT);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_YOUNG_ANIMAL, 0, 6);
    SetEntityAnim(ENTITY_TUTORIAL_YOUNG_ANIMAL, ANIMATION_CHICK_IDLE);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(55), Y(120), FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_After3Days);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_TIME_PASSES);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(90);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_ABabyChickIsBorn);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_FinallyLetYourChickensOutTo);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1);
    BeginHoldingActorGraphic(ANIMATION_CHICKEN_HELD);
    WaitFrames(16);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_CarryChickenOutsideCoop);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_TUTORIAL_CHICKEN_COOP, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(80), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    BeginHoldingActorGraphic(ANIMATION_CHICKEN_HELD);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(30);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_PutChickenDownOutside);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    SetEntityPosition(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, X(92), Y(80), FACING_DOWN);
    NoOpAnimalEventEntityInitialization(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, 0, 7);
    SetEntityAnim(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ANIMATION_CHICKEN_IDLE);
    WaitFrames(12);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    PlaySong(AUDIO_START, AUDIO_SFX_CHICKEN_CLUCK);
    StartEntityEffect(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_ChickenCareInstructions_SeveralHoursAfterBeingLetOut);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_1);
    HideEntity(ENTITY_TUTORIAL_ADULT_ANIMAL_SLOT_2);
    HideEntity(ENTITY_TUTORIAL_YOUNG_ANIMAL);
    HideEntity(ENTITY_TUTORIAL_PLAYER);
    CallScript(EventScript_SystemMenu_SelectAnimalCategory);
}
