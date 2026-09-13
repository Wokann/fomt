#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaGreetsPlayer[] =
        "あ、{Player}くん～。\r\n"
        "こんにちは～。\r\n"
        "うふふふ。{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickGreetsPlayer[] =
        "やあ。\r\n"
        "{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriGreetsPlayer[] =
        "{Player}さん、\r\n"
        "こんにちは。{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaExplainsGoodMood[] =
        "え？\r\n"
        "機嫌がいいようにみえるって？{Press}\p"
        "そうなのよ～。\r\n"
        "わたし、今とっても機嫌が\r\n"
        "いいのよ～。{Press}\p"
        "なぜだかわかる～？{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaRevealsFirstLetterFromRod[] =
        "うふふふ。\r\n"
        "実はね～、うちの人から\r\n"
        "手紙がとどいたのよ～。{Press}\p"
        "こんなこと、\r\n"
        "はじめてだから\r\n"
        "うれしくって～。{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaOffersToReadLetter[] =
        "手紙の内容聞きたい～？\r\n"
        "{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RodsLetterFromDesertSearchForCure[] =
        "リリアへ。\r\n"
        "リックやポプリは元気で\r\n"
        "やっているか？{Press}\p"
        "オレは元気だ。オレは、今、\r\n"
        "おまえの病気を治せるって\r\n"
        "いう花を探して砂漠にいる。{Press}\p"
        "この広大な砂漠で花を探すのは\r\n"
        "大変かもしれんが、\r\n"
        "おまえの病気を治すためだ。{Press}\p"
        "きっと見つけてくる。\r\n"
        "まっててくれ。\r\n"
        "それまで、店の方をたのむぞ。{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaPraisesRod[] =
        "ね～。\r\n"
        "うちの人って\r\n"
        "男らしいでしょう？{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickResentsRodsStoreRequest[] =
        "店をたのむぞって、\r\n"
        "簡単に言ってくれるよ。\r\n"
        "大変なのに。{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_PopuriAsksRickToShareLilliasHappiness[] =
        "もう、\r\n"
        "なんで素直に喜べないのよ～。{Press}";

    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaCelebratesRodsSafety[] =
        "手紙が来るってことは\r\n"
        "無事ってことだもの。\r\n"
        "安心したわ～。{Press}";
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
