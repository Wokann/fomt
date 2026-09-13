#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Gotz_RegainsMotivation_GotzGreetsPlayer[] =
        "よう、{Player}！\r\n"
        "{Press}";

    const char gText_NPCEvent_Gotz_RegainsMotivation_GotzAnnouncesReturnToWork[] =
        "やっとやる気が出てきたぜ！\r\n"
        "心配かけて悪かったな。{Press}";

    const char gText_NPCEvent_Gotz_RegainsMotivation_GotzOffersToHandleExpansion[] =
        "増築の依頼にきたのか？\r\n"
        "それだったら、気合入れて\r\n"
        "やらさせてもらうぜ。{Press}";
};

void EventScript_NPCEvent_Gotz_RegainsMotivation(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_GOTZ, X(120), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(100), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_Gotz_RegainsMotivation_GotzGreetsPlayer);
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
    TalkMessage(gText_NPCEvent_Gotz_RegainsMotivation_GotzAnnouncesReturnToWork);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_Gotz_RegainsMotivation_GotzOffersToHandleExpansion);
    TalkClose();
    SetEntityFacing(ENTITY_GOTZ, FACING_RIGHT);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_WALK);
    MoveEntityXTo(ENTITY_GOTZ, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_DOWN);
    MoveEntityYTo(ENTITY_GOTZ, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_RIGHT);
    MoveEntityXTo(ENTITY_GOTZ, X(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_DOWN);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    MarkNpcSpokenTo(CHARACTER_GOTZ);
    VarSet(VAR_GOTZ_REGAINS_MOTIVATION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_GOTZ_WORK_SUSPENDED, FALSE);
    return;
}
