#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Gotz_LosesMotivation_GotzLamentsLossOfMotivation[] =
        "Aaahh...I just don't feel \r\n"
        "like working any more...{Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzApologizesForStartlingPlayer[] =
        "Oh, {Player}, \r\n"
        "sorry I didn't notice you. {Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzRefusesExpansionWork[] =
        "Did you come to ask about an\r\n"
        "expansion? Sorry, but I \r\n"
        "can't do it right now. {Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzExplainsHeIsInSlump[] =
        "I just can't get excited \r\n"
        "about it now. I'm in a \r\n"
        "slump, I guess. {Press}";

    const char gText_NPCEvent_Gotz_LosesMotivation_GotzSuspendsWorkUntilHeRecovers[] =
        "I'll snap out of it  \r\n"
        "eventually, but not now. {Press}\p"
        "Sorry. {Press}";
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
