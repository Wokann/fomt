#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_Proposal_Karen_RequestsPrivacy[] =
        "Ich denke nicht, dass uns\r\n"
        "jemand hier stört...{Press}";

    const char gText_LoveEvent_Karen_Proposal_Karen_AcceptsBlueFeather[] =
        "Meine Mutter hat mir von\r\n"
        "ihrer Hochzeit erzählt und\r\n"
        "ich habe mich gefragt, {Press}\r\n"
        "wann ich heiraten werde...{Press}\p"
        "Ich hatte keine Ahnung, dass\r\n"
        "du es sein würdest. {Press}\p"
        "Natürlich sage ich ja!{Press}";

    const char gText_LoveEvent_Karen_Proposal_Karen_GoesToTellParents[] =
        "Ich muss jetzt meinen\r\n"
        "Eltern Bescheid sagen. \r\n"
        "Meine Mutter wird sich{Press}\p"
        "freuen, aber ich denke, \r\n"
        "mein Vater wird weinen!{Press}";
};

void EventScript_LoveEvent_Karen_ProposalAccepted(void)
{
    ChangeMap(MAP_FARMHOUSE, X(331), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_KAREN, X(303), Y(148), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_Proposal_Karen_RequestsPrivacy);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(40);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RAISE_ARMS);
    ShowPlayerHoldingTool(ITEM_TOOL_BLUE_FEATHER);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_Proposal_Karen_AcceptsBlueFeather);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_Proposal_Karen_GoesToTellParents);
    TalkClose();
    ClearPlayerHeldTool();
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_KAREN, Y(250), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    HideEntity(ENTITY_KAREN);
    MarkNpcSpokenTo(CHARACTER_KAREN);
    VarSet(VAR_KAREN_PROPOSAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
