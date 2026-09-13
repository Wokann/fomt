#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaGreetsPlayer[] =
        "Hello, {Player}. \r\n"
        "How are you?  {Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickGreetsPlayer[] =
        "Hi.\r\n"
        "{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriGreetsPlayer[] =
        "Hi there, {Player}. {Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaExplainsGoodMood[] =
        "What? You say I look \r\n"
        "in a good mood? {Press}\p"
        "That's because I am!\r\n"
        "Do you want to know why? {Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaRevealsFirstLetterFromRod[] =
        "You see...tee-hee...\r\n"
        "I got a letter from my \r\n"
        "darling today...{Press}\p"
        "It was the first time \r\n"
        "ever!{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaOffersToReadLetter[] =
        "Do you want to hear\r\n"
        "what he wrote? {Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RodsLetterFromDesertSearchForCure[] =
        "Dear Lillia, \r\n"
        "How are Popuri and Rick? \r\n"
        "I am fine. I'm writing from{Press}\r\n"
        "a vast desert, where the \r\n"
        "search for the flower to \r\n"
        "cure you has lead me. {Press}\p"
        "I am confident I'll find it\r\n"
        "soon, so do not give up\r\n"
        "hope. Look after the store.{Press}\p"
        "All my love, your husband. {Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaPraisesRod[] =
        "Isn't he wonderful...?{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickResentsRodsStoreRequest[] =
        "\"Look after the store\"...\r\n"
        "Easy for him to say!{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriAsksRickToShareLilliasHappiness[] =
        "Why can't you just be happy\r\n"
        "like Mom, Rick?{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaCelebratesRodsSafety[] =
        "This mean's he's safe, \r\n"
        "don't you see?\r\n"
        "I'm so happy...{Press}";
};

void EventScript_NPCEvent_Lillia_ReadsRodsLetter(void)
{
    EnableScriptedNpcControl();
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_LILLIA, X(120), Y(144), FACING_DOWN);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_RICK, X(140), Y(144), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(160), Y(160), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    MoveEntityYTo(ENTITY_PLAYER, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_RickGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriGreetsPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaExplainsGoodMood);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaRevealsFirstLetterFromRod);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaOffersToReadLetter);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
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
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_RodsLetterFromDesertSearchForCure);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaPraisesRod);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_RickResentsRodsStoreRequest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriAsksRickToShareLilliasHappiness);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaCelebratesRodsSafety);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_LILLIA);
    EnableScriptedNpcControl();
    VarSet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_POPURI, EventScript_NPCEvent_Lillia_ReadsRodsLetter_FollowupPopuriDialogue);
    SetEntityEventScript(ENTITY_RICK, EventScript_NPCEvent_Lillia_ReadsRodsLetter_FollowupRickDialogue);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_NPCEvent_Lillia_ReadsRodsLetter_FollowupLilliaDialogue);
    return;
}
