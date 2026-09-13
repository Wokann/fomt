#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Zack_GivesFishingRod_ZackPondersUnusedFishingRod[] =
        "Hmm... Was soll ich \r\n"
        "hiermit anfangen....?{Press}";

    const char gText_NPCEvent_Zack_GivesFishingRod_ZackGreetsPlayerAtRightTime[] =
        "Hi, {Player}! {Press}\p"
        "Du kommst zur \r\n"
        "richtigen Zeit!{Press}";

    const char gText_NPCEvent_Zack_GivesFishingRod_ZackOffersFriendsFishingRod[] =
        "Ein Freund hat mir diese\r\n"
        "Angelrute gegeben. {Press}\p"
        "Ich angele nicht, aber \r\n"
        "ich will sie auch nicht \r\n"
        "wegwerfen. {Press}\p"
        "Kannst du sie gebrauchen?\r\n"
        "Du siehst mir wie ein \r\n"
        "guter Angler aus!{Press}";

    const char gText_NPCEvent_Zack_GivesFishingRod_PlayerReceivesFishingRod[] =
        "Du hast eine \r\n"
        "Angelrute!{Press}";
};

void EventScript_NPCEvent_Zack_GivesFishingRod(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ZACK, X(215), Y(115), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    if (VarGet(VAR_WON_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        SetEntityPosition(ENTITY_WON, X(191), Y(141), FACING_LEFT);
        SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_GivesFishingRod_ZackPondersUnusedFishingRod);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(111), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_PLAYER, X(169), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    StartEntityEffect(ENTITY_ZACK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_GivesFishingRod_ZackGreetsPlayerAtRightTime);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Zack_GivesFishingRod_ZackOffersFriendsFishingRod);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ZACK);
    if (GetPlayerHeldToolId() == mary_negated_int(ITEM_TOOL_NOT_PRESENT))
    {
        SetPlayerHeldTool(ITEM_TOOL_FISHING_ROD_IRON, 1);
    }
    else
    {
        AddToolToRucksack(ITEM_TOOL_FISHING_ROD_IRON, 1);
    }
    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
    ShowPlayerHoldingTool(ITEM_TOOL_FISHING_ROD_IRON);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Zack_GivesFishingRod_PlayerReceivesFishingRod);
    TalkClose();
    PanCameraTo(X(169), Y(111), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    MarkNpcSpokenTo(CHARACTER_ZACK);
    EnableScriptedNpcControl();
    VarSet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_ZACK, EventScript_NPCEvent_Zack_GivesFishingRod_FollowupZackDialogue);
    if (VarGet(VAR_WON_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        SetEntityEventScript(ENTITY_WON, EventScript_NPCEvent_Zack_GivesFishingRod_WonDialogue);
    }
}
