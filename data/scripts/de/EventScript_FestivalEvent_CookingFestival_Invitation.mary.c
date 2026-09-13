#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_Invitation[] =
        "Das Kochfestival ist \r\n"
        "morgen um 10 Uhr auf \r\n"
        "dem Rosenplatz.{Press}\p"
        "Wenn du ein Gericht mit-\r\n"
        "bringst, kannst du \r\n"
        "teilnehmen. {Press}";
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
