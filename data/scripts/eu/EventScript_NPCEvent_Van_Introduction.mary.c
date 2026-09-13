#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Van_Introduction_VanIntroducesWednesdayTravelingShopAtInn[] =
        "It is a pleasure to make\r\n"
        "your acquaintaince. {Press}\p"
        "My name is Van, and I am a \r\n"
        "travelling merchant with\r\n"
        "many rare and valuable {Press}\r\n"
        "items. {Press}\p"
        "I'm open for business every\r\n"
        "Wednesday at second \r\n"
        "floor of the Inn. {Press}\p"
        "I look forward to doing \r\n"
        "business with you. {Press}";
};

void EventScript_NPCEvent_Van_Introduction(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_VAN, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_VAN, ANIMATION_VAN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_VAN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_VAN);
    TalkMessage(gText_NPCEvent_Van_Introduction_VanIntroducesWednesdayTravelingShopAtInn);
    TalkClose();
    SetEntityFacing(ENTITY_VAN, FACING_RIGHT);
    SetEntityAnim(ENTITY_VAN, ANIMATION_VAN_WALK);
    MoveEntityXTo(ENTITY_VAN, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_VAN);
    SetEntityFacing(ENTITY_VAN, FACING_UP);
    MoveEntityYTo(ENTITY_VAN, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_VAN);
    HideEntity(ENTITY_VAN);
    MarkNpcSpokenTo(CHARACTER_VAN);
    VarSet(VAR_VAN_INTRODUCTION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
