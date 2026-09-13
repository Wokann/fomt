#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Foal_MoveIntoStable_Barley_ReprimandsHorseName[] =
        "Hi, {Player}.\r\n"
        "How can you call this a farm\r\n"
        "without a single horse?{Press}";

    const char gText_FarmEvent_Foal_MoveIntoStable_Barley_ExplainsFoalNeedsHome[] =
        "This Foal was born at our\r\n"
        "farm, but you can keep him\r\n"
        "here, if you like.{Press}\p"
        "You can name him\r\n"
        "however you like.{Press}";

    const char gText_FarmEvent_Foal_MoveIntoStable_Barley_MovesFoalToStable[] =
        "I'll put him in the \r\n"
        "Stable for you.{Press}\p"
        "Treat him well, now.\r\n"
        "Talk to him everyday and\r\n"
        "brush him, too. {Press}";

    const char gText_FarmEvent_Foal_MoveIntoStable_Barley_HorseCareReminder[] =
        "Take good care of\r\n"
        "{Horse}, now.{Press}";
};

void EventScript_FarmEvent_Foal_MoveIntoStable(void)
{
    CreateFarmHorse(FALSE, ANIMAL_HORSE_AGE_STAGE_ADULT, MAP_FARM, X(196), Y(145));
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_BARLEY, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_FARM_HORSE, X(196), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FarmEvent_Foal_MoveIntoStable_Barley_ReprimandsHorseName);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FarmEvent_Foal_MoveIntoStable_Barley_ExplainsFoalNeedsHome);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    OpenNameEntry(NAME_ENTRY_HORSE, NAME_ENTRY_SINGLETON_SLOT);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FarmEvent_Foal_MoveIntoStable_Barley_MovesFoalToStable);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityXTo(ENTITY_BARLEY, X(500), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    SetEntityFacing(ENTITY_FARM_HORSE, FACING_RIGHT);
    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_WALK);
    MoveEntityXTo(ENTITY_FARM_HORSE, X(500), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    WaitForEntityMovement(ENTITY_FARM_HORSE);
    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_IDLE);
    RelocateEntityToMap(ENTITY_FARM_HORSE, MAP_HORSE_STABLE, X(84), Y(124));
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityXTo(ENTITY_BARLEY, X(335), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FarmEvent_Foal_MoveIntoStable_Barley_HorseCareReminder);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    HideEntity(ENTITY_BARLEY);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    VarSet(VAR_BARLEY_REPLACEMENT_FOAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
