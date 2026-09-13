#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_04_YellowHeart_DougWelcomesPlayer[] =
        "おお、{Player}\r\n"
        "いらっしゃい。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougIntroducesPrivateQuestion[] =
        "ちょうどいいや。\r\n"
        "{Player}に\r\n"
        "話があるんだよ。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougExplainsConcernForAnn[] =
        "実は、ランのこと\r\n"
        "なんだけどよ。あいつには、\r\n"
        "昔っから苦労をかけててなぁ。{Press}\p"
        "あいつの母親が死んで、\r\n"
        "男手ひとつで育てたって\r\n"
        "言ったら、聞こえはいいが、{Press}\r\n"
        "実際は、あいつがしっかり\r\n"
        "してくれたおかげでオレも\r\n"
        "ここまでやってこれたんだよ。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougWantsAnnToBeHappy[] =
        "あいつには、\r\n"
        "今まで苦労してきた分、\r\n"
        "いい男見つけて幸せになって{Press}\r\n"
        "ほしいんだよ。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCreditsPlayerForAnnsChange[] =
        "今まで、男には全然興味\r\n"
        "なかったみたいなのに、\r\n"
        "最近、おまえの話ばっかり、{Press}\r\n"
        "家でしてやがるんだよ。\r\n"
        "で、話っていうより聞きたいん\r\n"
        "だけどよ。{Press}\p"
        "おまえ、ランのこと、\r\n"
        "どう思ってるんだ？{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_ChoiceAdmitLikingAnn[] =
        "好きです";

    const char gText_LoveEvent_Ann_04_YellowHeart_ChoiceSayAnnIsOnlyFriend[] =
        "友達です";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCelebratesPlayersFeelings[] =
        "そうか！！！\r\n"
        "それを聞いて安心したぜ！{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnWelcomesPlayer[] =
        "あっ、{Player}くん。\r\n"
        "いらっしゃ～い。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCallsAnnOver[] =
        "ラン、ちょっと{Player}の\r\n"
        "横に座れ。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnAsksWhatIsWrong[] =
        "えっ、いいけど…\r\n"
        "なんで？{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougInsistsAnnComeCloser[] =
        "いいから、いいから。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougAsksAnnsFeelingsForPlayer[] =
        "…ゴホン。\r\n"
        "ラン、{Player}のこと\r\n"
        "どう思ってるんだ？{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnReactsInSurprise[] =
        "え…{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnRefusesToAnswerDoug[] =
        "と…父さんに\r\n"
        "関係ないじゃない！{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougClaimsParentalInterest[] =
        "関係ないとはなんだ！\r\n"
        "大事なことじゃねぇか！{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnFallsSilentInEmbarrassment[] =
        "…………！{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougTeasesAnnAboutPlayer[] =
        "はっはっはっはっはっ。\r\n"
        "あいつ、一人前に\r\n"
        "テレやがって…{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougNoticesPlayerBlushing[] =
        "なに、おまえも赤く\r\n"
        "なってるんだよ。{Press}\p"
        "まぁ、とにかくよろしく\r\n"
        "頼むな。{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougDismissesUnfavorableAnswer[] =
        "…そうか…\r\n"
        "これからも、ランといい友達で\r\n"
        "いてくれよ。{Press}";
};

void EventScript_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn(void)
{
    int var_0;
    ChangeMap(MAP_INN_1F, X(248), Y(116));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(315), Y(248), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ANN, X(112), Y(116), FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(315), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougWelcomesPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougIntroducesPrivateQuestion);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougExplainsConcernForAnn);
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougWantsAnnToBeHappy);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougCreditsPlayerForAnnsChange);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Ann_04_YellowHeart_ChoiceAdmitLikingAnn, gText_LoveEvent_Ann_04_YellowHeart_ChoiceSayAnnIsOnlyFriend);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ANN, 3000);
            AddNpcFriendship(CHARACTER_DOUG, 20);
            TalkClose();
            StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougCelebratesPlayersFeelings);
            TalkClose();
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityXTo(ENTITY_ANN, X(232), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnWelcomesPlayer);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            WaitFrames(30);
            SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougCallsAnnOver);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnAsksWhatIsWrong);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougInsistsAnnComeCloser);
            TalkClose();
            StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_QUESTION, FALSE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityXTo(ENTITY_ANN, X(300), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
            WaitFrames(30);
            SetEntityFacing(ENTITY_ANN, FACING_UP);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougAsksAnnsFeelingsForPlayer);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnReactsInSurprise);
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnRefusesToAnswerDoug);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougClaimsParentalInterest);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnFallsSilentInEmbarrassment);
            TalkClose();
            StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_ANGRY, FALSE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_ANN, FACING_LEFT);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityXTo(ENTITY_ANN, X(112), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
            SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            HideEntity(ENTITY_ANN);
            WaitFrames(60);
            SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougTeasesAnnAboutPlayer);
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougNoticesPlayerBlushing);
            TalkClose();
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ANN);
            MarkNpcSpokenTo(CHARACTER_DOUG);
            SetEntityEventScript(ENTITY_DOUG, EventScript_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn_FollowupDougDialogue);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_CHOICE, ANN_YELLOW_HEART_RESPONSE_LIKE_ANN);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddNpcFriendship(CHARACTER_DOUG, mary_negated_int(-10));
            HideEntity(ENTITY_ANN);
            TalkClose();
            StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougDismissesUnfavorableAnswer);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_DOUG);
            SetEntityEventScript(ENTITY_DOUG, EventScript_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn_FollowupDougDialogue);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_CHOICE, ANN_YELLOW_HEART_RESPONSE_ONLY_FRIENDS);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
