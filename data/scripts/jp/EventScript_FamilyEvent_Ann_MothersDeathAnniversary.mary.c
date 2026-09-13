#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_MothersDeathAnniversary_DougExplainsAnnMothersDeathAnniversary[] =
        "今日は、ランの母親が\r\n"
        "死んだ日なんだよ。{Press}\p"
        "この日だけはランが\r\n"
        "オレを休ませてくれる。\r\n"
        "ありがたいねぇ。{Press}";
};

void EventScript_FamilyEvent_Ann_MothersDeathAnniversary(void)
{
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(230), Y(280));
    SetEntityPosition(ENTITY_PLAYER, X(230), Y(420), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOUG, X(200), Y(280), FACING_UP);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(280), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Ann_MothersDeathAnniversary_DougExplainsAnnMothersDeathAnniversary);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_DOUG);
    EnableScriptedNpcControl();
    VarSet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FamilyEvent_Ann_MothersDeathAnniversary_FollowupDougDialogue);
}
