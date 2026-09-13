#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaGreetsPlayer[] =
        "Hallo, {Player}. \r\n"
        "Wie geht es dir?{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickGreetsPlayer[] =
        "Hi.\r\n"
        "{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriGreetsPlayer[] =
        "Hi, {Player}. {Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaExplainsGoodMood[] =
        "Was? Du sagst, ich sehe \r\n"
        "gut gelaunt aus?{Press}\p"
        "Tja, das bin ich auch!\r\n"
        "Willst du wissen warum?{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaRevealsFirstLetterFromRod[] =
        "Siehst du...he-he...\r\n"
        "Ich habe heute einen \r\n"
        "Brief von meinem Schatz{Press}\r\n"
        "bekommen...{Press}\p"
        "Zum ersten Mal \r\n"
        "überhaupt!{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaOffersToReadLetter[] =
        "Willst du hören, was er\r\n"
        "geschrieben hat?{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RodsLetterFromDesertSearchForCure[] =
        "Liebe Lillia, \r\n"
        "wie geht es Popuri und Rick?\r\n"
        "Mir geht's gut. Ich schreibe{Press}\r\n"
        "aus einer gewaltigen Wüste,\r\n"
        "in die mich die Suche nach\r\n"
        "der Blume, die dich heilen{Press}\r\n"
        "kann, geführt hat.{Press}\p"
        "Ich bin sicher, ich finde\r\n"
        "sie bald. Ich gebe die\r\n"
        "Hoffnung nicht auf. {Press}\r\n"
        "Pass auf den Laden auf.{Press}\p"
        "Mit aller Liebe, dein Mann. {Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaPraisesRod[] =
        "Ist er nicht wunderbar...?{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickResentsRodsStoreRequest[] =
        "\"Pass auf den Laden auf\"...\r\n"
        "Er hat leicht reden!{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriAsksRickToShareLilliasHappiness[] =
        "Warum freust du dich nicht\r\n"
        "einfach - wie Mama, Rick?{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaCelebratesRodsSafety[] =
        "Das hei t, er ist in\r\n"
        "Sicherheit, verstehst\r\n"
        "du nicht?{Press}\p"
        "Ich freue mich so...{Press}";
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
