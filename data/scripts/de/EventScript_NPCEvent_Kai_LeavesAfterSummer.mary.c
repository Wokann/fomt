#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Kai_LeavesAfterSummer_KaiSaysHeAndPopuriAreLeavingForCity[] =
        "Der Sommer ist vorbei, also\r\n"
        "gehen Popuri und ich \r\n"
        "zurück in die Stadt. {Press}\p"
        "Ich wollte nur Auf \r\n"
        "Wiedersehen sagen. {Press}";

    const char gText_NPCEvent_Kai_LeavesAfterSummer_KaiSaysHeIsLeavingForCityAlone[] =
        "Der Sommer ist vorbei, ich\r\n"
        "gehe in die Stadt zurück.{Press}\p"
        "Ich wollte nur Auf \r\n"
        "Wiedersehen sagen. {Press}";

    const char gText_NPCEvent_Kai_LeavesAfterSummer_KaiSaysGoodbyeUntilNextYear[] =
        "Bis nächstes Jahr!{Press}";
};

void EventScript_NPCEvent_Kai_LeavesAfterSummer(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAI, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        TalkMessage(gText_NPCEvent_Kai_LeavesAfterSummer_KaiSaysHeAndPopuriAreLeavingForCity);
    }
    else
    {
        TalkMessage(gText_NPCEvent_Kai_LeavesAfterSummer_KaiSaysHeIsLeavingForCityAlone);
    }
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityXTo(ENTITY_KAI, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Kai_LeavesAfterSummer_KaiSaysGoodbyeUntilNextYear);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_UP);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityYTo(ENTITY_KAI, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    HideEntity(ENTITY_KAI);
    MarkNpcSpokenTo(CHARACTER_KAI);
    VarSet(VAR_KAI_LEAVES_AFTER_SUMMER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
