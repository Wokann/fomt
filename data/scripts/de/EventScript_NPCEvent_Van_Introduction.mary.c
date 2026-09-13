#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Van_Introduction_VanIntroducesWednesdayTravelingShopAtInn[] =
        "Ich freue mich, deine\r\n"
        "Bekanntschaft zu machen. {Press}\p"
        "Mein Name ist Van und ich\r\n"
        "bin ein reisender Händler\r\n"
        "mit vielen seltenen und{Press}\r\n"
        "wertvollen Waren. {Press}\p"
        "Mein Geschäft ist jeden\r\n"
        "Mittwoch im zweiten Stock\r\n"
        "des Gasthofs geöffnet. {Press}\p"
        "Ich freue mich schon, mit \r\n"
        "dir Geschäfte zu machen. {Press}";
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
