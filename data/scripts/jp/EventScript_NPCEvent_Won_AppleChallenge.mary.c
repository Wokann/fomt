#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Won_AppleChallenge_WonOffersThreeRareApples[] =
        "今日は、わたし、あなたにたけ\r\n"
        "特別な物、３種類持ってきた\r\n"
        "あるよ。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExplainsApplesAreSpecial[] =
        "ホントにここたけの話あるよ…\r\n"
        "じゃん、りんごね。{Press}\p"
        "この３種類のりんご、タダの\r\n"
        "りんごと、ちがうあるね。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesSUGDWApple[] =
        "一つ目はこれ！\r\n"
        "その名もＳＵＧＤＷりんご\r\n"
        "ある。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsSUGDWName[] =
        "ホントの名前、とても長いよ、\r\n"
        "いいあるか。{Press}\p"
        "スーパー·ウルトラ·グレート\r\n"
        "·デリシャス·ワンダフルりん\r\n"
        "ご！{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName[] =
        "はぁはぁはぁ…\r\n"
        "という名前ある。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesHMSGBApple[] =
        "二つ目はこれ！\r\n"
        "その名もＨＭＳＧＢりんご\r\n"
        "ある。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsHMSGBName[] =
        "このりんごもホントの名前、\r\n"
        "とても長いよ、いいあるか。{Press}\p"
        "ハイパー·ミラクル·スウィー\r\n"
        "ト·ゴージャス·ビューティフ\r\n"
        "ルりんご！{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple[] =
        "最後はこれ！\r\n"
        "その名もＡＥＰＦＥりんご\r\n"
        "ある。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName[] =
        "このりんごもホントの名前、\r\n"
        "とても長いよ、いいあるか。{Press}\p"
        "エンジェル·エターナル·ピュ\r\n"
        "ア·フレッシュ·エレガントり\r\n"
        "んご！{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonUrgesPlayerToTasteApple[] =
        "３種類とも、\r\n"
        "どこがすごいのかは、\r\n"
        "食べてみてのお楽しみあるよ。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonOffersEachAppleFor500G[] =
        "ねたんは５００Ｇある。\r\n"
        "とてもとても安いね。\r\n"
        "お買いとくね！{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_AppleSelectionPrompt[] =
        "とれ買うあるか？";

    const char gText_NPCEvent_Won_AppleChallenge_SelectSUGDWApple[] =
        "ＳＵＧＤＷ";

    const char gText_NPCEvent_Won_AppleChallenge_SelectHMSGBApple[] =
        "ＨＭＳＧＢ";

    const char gText_NPCEvent_Won_AppleChallenge_SelectAEPFEApple[] =
        "ＡＥＰＦＥ";

    const char gText_NPCEvent_Won_AppleChallenge_DeclineApplePurchase[] =
        "買わない";

    const char gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple[] =
        "ありがとうある！\r\n"
        "まさか、買ってくれるとは…{Press}\p"
        "いやいや、さすがにお目が高い\r\n"
        "あるねぇ。{Press}\p"
        "それじゃ、わたし、\r\n"
        "これで帰るあるよ。{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonMocksPlayerForLacking500G[] =
        "５００Ｇもないあるか？\r\n"
        "あなた、とても運のない人ね。{Press}";
};

void EventScript_NPCEvent_Won_AppleChallenge(void)
{
    int var_0;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_WON, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonOffersThreeRareApples);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExplainsApplesAreSpecial);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonIntroducesSUGDWApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExpandsSUGDWName);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonIntroducesHMSGBApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExpandsHMSGBName);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonUrgesPlayerToTasteApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonOffersEachAppleFor500G);
    var_0 = TalkPromptChoice4(gText_NPCEvent_Won_AppleChallenge_AppleSelectionPrompt, gText_NPCEvent_Won_AppleChallenge_SelectSUGDWApple, gText_NPCEvent_Won_AppleChallenge_SelectHMSGBApple, gText_NPCEvent_Won_AppleChallenge_SelectAEPFEApple, gText_NPCEvent_Won_AppleChallenge_DeclineApplePurchase);
    switch (var_0)
    {
        case PROMPT_CHOICE_OPTION_1:
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple);
            TalkClose();
            SetPlayerHeldFood(ITEM_FOOD_SUGDW_APPLE);
            SubtractMoney(500);
            break;
        case PROMPT_CHOICE_OPTION_2:
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple);
            TalkClose();
            SetPlayerHeldFood(ITEM_FOOD_HMSGB_APPLE);
            SubtractMoney(500);
            break;
        case PROMPT_CHOICE_OPTION_3:
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple);
            TalkClose();
            SetPlayerHeldFood(ITEM_FOOD_AEPFE_APPLE);
            SubtractMoney(500);
            break;
        case PROMPT_CHOICE_OPTION_4:
            SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonMocksPlayerForLacking500G);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_WON, FACING_RIGHT);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_WALK);
    MoveEntityXTo(ENTITY_WON, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    SetEntityFacing(ENTITY_WON, FACING_UP);
    MoveEntityYTo(ENTITY_WON, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    HideEntity(ENTITY_WON);
    MarkNpcSpokenTo(CHARACTER_WON);
    VarSet(VAR_WON_APPLE_CHALLENGE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
