#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_Invitation[] =
        "The Cooking Festival is \r\n"
        "tomorrow at 10AM in Rose \r\n"
        "Square, you know.{Press}\p"
        "If you bring a dish, you\r\n"
        "can enter it. {Press}";
};

void EventScript_FestivalEvent_CookingFestival_Invitation(void)
{
    ChangeMap(MAP_FARM, X(228), Y(120));
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_COOKING_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_CookingFestival_Invitation);
    TalkClose();
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityXTo(ENTITY_THOMAS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityFacing(ENTITY_THOMAS, FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    HideEntity(ENTITY_THOMAS);
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    VarSet(VAR_COOKING_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
    return;
}
