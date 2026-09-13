#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LouOrRuby_Introduction_LouOrRubyIntroducesWeeklyFoodBuyingVisitAtInn[] =
        "Hi. {Press}\p"
        "Ich bin Lou. Ich komme jede \r\n"
        "Woche nach Mineralstadt, um \r\n"
        "Essen zu kaufen. {Press}\p"
        "Das Essen aus Mineral- \r\n"
        "stadt ist so k[o]stlich, \r\n"
        "dass ich es in meinem {Press}\r\n"
        "eigenen Gasthof verwende! {Press}\p"
        "Ich bin jeden Montag \r\n"
        "im Gasthof. Komm, wenn du\r\n"
        "etwas verkaufen willst! {Press}";
};

void EventScript_NPCEvent_LouOrRuby_Introduction(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_LOU_OR_RUBY, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_LOU_OR_RUBY, ANIMATION_LOU_OR_RUBY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LOU_OR_RUBY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LOU_OR_RUBY);
    TalkMessage(gText_NPCEvent_LouOrRuby_Introduction_LouOrRubyIntroducesWeeklyFoodBuyingVisitAtInn);
    TalkClose();
    SetEntityFacing(ENTITY_LOU_OR_RUBY, FACING_RIGHT);
    SetEntityAnim(ENTITY_LOU_OR_RUBY, ANIMATION_LOU_OR_RUBY_WALK);
    MoveEntityXTo(ENTITY_LOU_OR_RUBY, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_LOU_OR_RUBY);
    SetEntityFacing(ENTITY_LOU_OR_RUBY, FACING_UP);
    MoveEntityYTo(ENTITY_LOU_OR_RUBY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_LOU_OR_RUBY);
    HideEntity(ENTITY_LOU_OR_RUBY);
    MarkNpcSpokenTo(CHARACTER_LOU_OR_RUBY);
    VarSet(VAR_LOU_OR_RUBY_INTRODUCTION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
