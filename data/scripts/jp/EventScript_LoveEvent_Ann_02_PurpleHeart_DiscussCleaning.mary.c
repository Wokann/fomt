#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnHummingWhileCleaning[] =
        "ラ～ラララララ～\r\n"
        "ラララララ～、\r\n"
        "フフフン～～～～。{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnStartledByPlayer[] =
        "あ～～～！\r\n"
        "ビックリした～～～！！！{Press}\p"
        "もう、{Player}くん、\r\n"
        "おどかさないでよ。{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnReassuresPlayer[] =
        "あ、あやまらなくてもいいよ。\r\n"
        "本気でおこったんじゃ\r\n"
        "ないから…{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnAsksOpinionAboutCleaning[] =
        "何やってたかって？\r\n"
        "おそうじよ。わたし、おそうじ\r\n"
        "するの大好きなんだ～。{Press}\p"
        "おそうじしてると、気分まで\r\n"
        "キレイになっていくしね。{Press}\p"
        "{Player}くんは、\r\n"
        "おそうじ好き？{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_ChoiceEnjoyCleaning[] =
        "そうじが好き";

    const char gText_LoveEvent_Ann_02_PurpleHeart_ChoiceDislikeCleaning[] =
        "そうじが嫌い";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnApprovesSharedInterest[] =
        "{Player}くんは、\r\n"
        "キレイ好きだろうと\r\n"
        "思ってたんだぁ。{Press}\p"
        "えらいなぁ～。\r\n"
        "ウチの父さんなんか、そうじ\r\n"
        "嫌いだから、全部わたしが{Press}\r\n"
        "しなきゃダメなの。{Press}\p"
        "わたし、おそうじが好きだから\r\n"
        "構わないんだけどね。{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnEncouragesCleaning[] =
        "そんなこと言ってちゃ、\r\n"
        "だめだよ。\r\n"
        "ちゃんとおそうじしないと。{Press}\p"
        "男の人ってみんな\r\n"
        "そうなのかな？ウチの父さんも\r\n"
        "おそうじが嫌いなのよ。{Press}";
};

void EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning(void)
{
    int var_0;
    ChangeMap(MAP_INN_2F, X(276), Y(116));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(276), Y(248), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ANN, X(255), Y(116), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnHummingWhileCleaning);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnStartledByPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnReassuresPlayer);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnAsksOpinionAboutCleaning);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Ann_02_PurpleHeart_ChoiceEnjoyCleaning, gText_LoveEvent_Ann_02_PurpleHeart_ChoiceDislikeCleaning);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ANN, 3000);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnApprovesSharedInterest);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ANN);
            SetEntityEventScript(ENTITY_ANN, EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning_FollowupAnnDialogue);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_CHOICE, ANN_PURPLE_HEART_RESPONSE_LIKE_CLEANING);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnEncouragesCleaning);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ANN);
            SetEntityEventScript(ENTITY_ANN, EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning_FollowupAnnDialogue);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_CHOICE, ANN_PURPLE_HEART_RESPONSE_HATE_CLEANING);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
