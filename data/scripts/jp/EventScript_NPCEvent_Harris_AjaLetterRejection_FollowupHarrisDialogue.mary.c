#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisReturnsLateAtNight[] =
        "すいません、\r\n"
        "こんなおそくに…{Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisExplainsConfessionLetterAndReply[] =
        "元気なさそうに見えますか？\r\n"
        "はぁ………\r\n"
        "実は、そうなんですよ…{Press}\p"
        "先日、アージュさんに\r\n"
        "気持ちのすべてを込めて\r\n"
        "手紙を書いたんですよ。{Press}\p"
        "返事が来たのですが…{Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisRevealsAjaHasBoyfriend[] =
        "アージュさんには、\r\n"
        "今いる街に好きな人が\r\n"
        "いるらしいんです。{Press}\p"
        "ははは…\r\n"
        "見事にフラれてしまいました。{Press}";

    const char gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisThanksPlayerForHelpingHimMoveOn[] =
        "そんなに\r\n"
        "気にしないでください。{Press}\p"
        "{Player}さんには\r\n"
        "感謝してるんです。{Press}\p"
        "手紙を書いたおかげで\r\n"
        "結果を知ることが\r\n"
        "出来たんですからね。{Press}\p"
        "アージュさんのことは、\r\n"
        "あきらめることにしました。{Press}\p"
        "アドバイスをくれた\r\n"
        "{Player}さんには、\r\n"
        "このことを言っておこうと{Press}\r\n"
        "思いましてね。{Press}\p"
        "では、とじまりに気をつけて…{Press}";
};

void EventScript_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue(void)
{
    SetEntityPosition(ENTITY_HARRIS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisReturnsLateAtNight);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisExplainsConfessionLetterAndReply);
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisRevealsAjaHasBoyfriend);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue_HarrisThanksPlayerForHelpingHimMoveOn);
    TalkClose();
    AddNpcFriendship(CHARACTER_HARRIS, 20);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_WALK);
    SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
    MoveEntityXTo(ENTITY_HARRIS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_UP);
    MoveEntityYTo(ENTITY_HARRIS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_HARRIS);
    HideEntity(ENTITY_HARRIS);
    VarSet(VAR_HARRIS_AJA_LETTER_REJECTION_FOLLOWUP_STATE, EVENT_LIFECYCLE_COMPLETED);
    MarkNpcSpokenTo(CHARACTER_HARRIS);
}
