#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_04_YellowHeart_ElliGreetsPlayerAtBeach[] =
        "なんだ、{Player}くんか。{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliAsksIfVisitIsSurprising[] =
        "えっ、わたしが海にいるのが\r\n"
        "めずらしいって？{Press}\p"
        "お父さんたちが生きてたころは\r\n"
        "よく家族できてたのよ。{Press}\p"
        "ここは、お父さんたちとの\r\n"
        "思い出がいっぱい\r\n"
        "つまってるの。{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliExplainsSheVisitsWhenWorried[] =
        "辛いこととか、相談したいこと\r\n"
        "なんかがあると、たまに\r\n"
        "来るのよ。{Press}\p"
        "ここにいると、お父さんたちが\r\n"
        "聞いてくれてるような\r\n"
        "気がして…{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliIntroducesConcernAboutStu[] =
        "今日はユウのことで来たの…{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliDescribesStusMisbehavior[] =
        "あの子、イタズラとか好き\r\n"
        "でしょう？わたしの言うこと\r\n"
        "なんて、全然聞かないのよ。{Press}\p"
        "わたしが母親がわりに育てて\r\n"
        "きたんだけど、\r\n"
        "甘やかせすぎたのかしら？{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ChoiceSayElliSpoilsStu[] =
        "甘やかせすぎ";

    const char gText_LoveEvent_Elli_04_YellowHeart_ChoicePraiseElliForRaisingStu[] =
        "そんなことはない";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliAcceptsNeedForMoreDiscipline[] =
        "…そう、人からみて、\r\n"
        "そう思われているんなら、\r\n"
        "甘やかせすぎたのよね…{Press}\p"
        "はぁ、自信無くしちゃったわ…\r\n"
        "それじゃ、わたしは帰るね。{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliThanksPlayerForReassurance[] =
        "ありがとう。\r\n"
        "あなたにそう言われると自信が\r\n"
        "出てくるわ。{Press}\p"
        "さて、帰ってユウと遊んで\r\n"
        "あげようかな。\r\n"
        "じゃあね、{Player}くん。{Press}";
};

void EventScript_LoveEvent_Elli_04_YellowHeart_DiscussRaisingStu(void)
{
    int var_0;
    ChangeMap(MAP_MINERAL_BEACH, X(385), Y(144));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(231), Y(144), FACING_RIGHT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(221), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityXTo(ENTITY_ELLI, X(385), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(90);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_PLAYER, X(385), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(60);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliGreetsPlayerAtBeach);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliAsksIfVisitIsSurprising);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliExplainsSheVisitsWhenWorried);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliIntroducesConcernAboutStu);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliDescribesStusMisbehavior);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Elli_04_YellowHeart_ChoiceSayElliSpoilsStu, gText_LoveEvent_Elli_04_YellowHeart_ChoicePraiseElliForRaisingStu);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliAcceptsNeedForMoreDiscipline);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            MoveEntityXTo(ENTITY_ELLI, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            HideEntity(ENTITY_ELLI);
            MarkNpcSpokenTo(CHARACTER_ELLI);
            VarSet(VAR_ELLI_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliThanksPlayerForReassurance);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            MoveEntityXTo(ENTITY_ELLI, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            HideEntity(ENTITY_ELLI);
            MarkNpcSpokenTo(CHARACTER_ELLI);
            VarSet(VAR_ELLI_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
    }
}
