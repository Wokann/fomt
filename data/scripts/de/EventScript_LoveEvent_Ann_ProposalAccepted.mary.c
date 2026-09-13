#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_Proposal_AnnSuggestsTalkingPrivately[] =
        "Ich denke, wir können uns\r\n"
        "hier privat unterhalten. {Press}";

    const char gText_LoveEvent_Ann_Proposal_AnnAcceptsProposal[] =
        "{Player}...Meinst\r\n"
        "du wirklich...?{Press}\p"
        "Ich...freue mich so! \r\n"
        "Sicher sage ich ja!{Press}";

    const char gText_LoveEvent_Ann_Proposal_AnnLeavesToTellDoug[] =
        "Das muss ich Papa sagen!\r\n"
        "Und...Mama im Himmel!{Press}\p"
        "Das ist der glücklichste\r\n"
        "Tag meines Lebens! {Press}";
};

void EventScript_LoveEvent_Ann_ProposalAccepted(void)
{
    ChangeMap(MAP_FARMHOUSE, X(331), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ANN, X(303), Y(148), FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_Proposal_AnnSuggestsTalkingPrivately);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(40);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RAISE_ARMS);
    ShowPlayerHoldingTool(ITEM_TOOL_BLUE_FEATHER);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_Proposal_AnnAcceptsProposal);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_Proposal_AnnLeavesToTellDoug);
    TalkClose();
    ClearPlayerHeldTool();
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_ANN, Y(250), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    HideEntity(ENTITY_ANN);
    MarkNpcSpokenTo(CHARACTER_ANN);
    VarSet(VAR_ANN_PROPOSAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
