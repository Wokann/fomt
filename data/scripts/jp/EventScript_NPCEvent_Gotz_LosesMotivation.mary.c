#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Gotz_LosesMotivation_GotzLamentsLossOfMotivation[] =
        "ああ～！！\tダメだ！\r\n"
        "ぜんっぜん、やる気が\r\n"
        "しねぇ～！！{Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzApologizesForStartlingPlayer[] =
        "なんだ、{Player}か…\r\n"
        "おどろかせちまったみてぇ\r\n"
        "だな。{Press}\p"
        "すまねぇ。{Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzRefusesExpansionWork[] =
        "増築の依頼にきたのか？{Press}\p"
        "それだったら、\r\n"
        "今はできねぇぜ。{Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzExplainsHeIsInSlump[] =
        "今、作る気がおきねぇんだよ。\r\n"
        "スランプっていうやつだよ。{Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzSuspendsWorkUntilHeRecovers[] =
        "気分が変われば、抜け出せる\r\n"
        "とは思うんだけどよ。{Press}\p"
        "そういうことだから、\r\n"
        "今は仕事できねぇぜ。{Press}";
};

void EventScript_NPCEvent_Gotz_LosesMotivation(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_GOTZ, X(120), Y(80), FACING_UP);
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
    MoveEntityYTo(ENTITY_PLAYER, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_Gotz_LosesMotivation_GotzLamentsLossOfMotivation);
    TalkClose();
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_GOTZ, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_Gotz_LosesMotivation_GotzApologizesForStartlingPlayer);
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
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_Gotz_LosesMotivation_GotzRefusesExpansionWork);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_Gotz_LosesMotivation_GotzExplainsHeIsInSlump);
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    TalkMessage(gText_NPCEvent_Gotz_LosesMotivation_GotzSuspendsWorkUntilHeRecovers);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_GOTZ);
    VarSet(VAR_GOTZ_LOSES_MOTIVATION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_GOTZ_WORK_SUSPENDED, TRUE);
    return;
}
