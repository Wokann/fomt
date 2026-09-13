#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_Proposal_ElliSuggestsTalkingPrivately[] =
        "How about here?\r\n"
        "I don't think anyone will \r\n"
        "interrupt. {Press}";

    const char gText_LoveEvent_Elli_Proposal_ElliAcceptsProposal[] =
        "I would be honored!{Press}";

    const char gText_LoveEvent_Elli_Proposal_ElliLeavesToTellEllen[] =
        "I'm going to tell my grandma\r\n"
        "about the wedding. {Press}\p"
        "I'm sure she and Stu will\r\n"
        "be so happy for me! {Press}\p"
        "I only with my mom and dad\r\n"
        "were still alive...{Press}";
};

void EventScript_LoveEvent_Elli_ProposalAccepted(void)
{
    ChangeMap(MAP_FARMHOUSE, X(331), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(303), Y(148), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_Proposal_ElliSuggestsTalkingPrivately);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(40);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RAISE_ARMS);
    ShowPlayerHoldingTool(ITEM_TOOL_BLUE_FEATHER);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_Proposal_ElliAcceptsProposal);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_Proposal_ElliLeavesToTellEllen);
    TalkClose();
    ClearPlayerHeldTool();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_ELLI, Y(250), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    HideEntity(ENTITY_ELLI);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    VarSet(VAR_ELLI_PROPOSAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
