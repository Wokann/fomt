#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksPlayerToHearAboutDream[] =
        "ああ、{Player}さん！\r\n"
        "聞いてください！{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterDescribesHearingVoiceWhileDozingInConfessional[] =
        "いつものようにざんげ室で\r\n"
        "ウトウトしていたんですが、{Press}\p"
        "そのとき、夢の中で誰かが\r\n"
        "ささやいてきたんです。{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterSaysVoicePredictedGoodFortune[] =
        "あなたに幸運が\r\n"
        "訪れることでしょうって\r\n"
        "言われたのですよ。{Press}\p"
        "夢なんですが、\r\n"
        "どうも気になって…{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackCallsForCarter[] =
        "おおい、カーターさんは\r\n"
        "いるか？{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksWhyZackCameLate[] =
        "どうしたのですか？\r\n"
        "こんな時間に。{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackSaysCartersWantedItemWasFound[] =
        "あんたがほしがっていたアレが\r\n"
        "手に入ったから\r\n"
        "言いに来たんだ。{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterReactsToItemBeingFound[] =
        "え？\r\n"
        "アレ手に入ったんですか？{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackExplainsDifficultyFindingItem[] =
        "どこにもなかったんだが、\r\n"
        "さっき在庫があったって\r\n"
        "電話がかかってきたんだ。{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterThanksZack[] =
        "そうですか。\r\n"
        "ありがとうございます。{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackAsksCarterToCollectItem[] =
        "近いうちに取りにきてくれよ。\r\n"
        "じゃあな。{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterCreditsDreamForGoodFortune[] =
        "やりましたよ。\r\n"
        "あの夢は、わたしに幸運を\r\n"
        "もたらしてくれたようです。{Press}\p"
        "やはり、ざんげ室で寝たのが\r\n"
        "よかったのでしょうね。{Press}";
};

void EventScript_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune(void)
{
    ChangeMap(MAP_CHURCH, X(183), Y(125));
    SetEntityPosition(ENTITY_CARTER, X(183), Y(103), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(161), Y(243), FACING_UP);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(183), Y(243), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(125), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksPlayerToHearAboutDream);
    TalkClose();
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterDescribesHearingVoiceWhileDozingInConfessional);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterSaysVoicePredictedGoodFortune);
    TalkClose();
    WaitFrames(60 * 2);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackCallsForCarter);
    TalkClose();
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityYTo(ENTITY_ZACK, Y(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksWhyZackCameLate);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackSaysCartersWantedItemWasFound);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterReactsToItemBeingFound);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackExplainsDifficultyFindingItem);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterThanksZack);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackAsksCarterToCollectItem);
    TalkClose();
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    MoveEntityYTo(ENTITY_ZACK, Y(243), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    HideEntity(ENTITY_ZACK);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterCreditsDreamForGoodFortune);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CARTER);
    EnableScriptedNpcControl();
    VarSet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_CARTER, EventScript_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_FollowupCarterDialogue);
}
