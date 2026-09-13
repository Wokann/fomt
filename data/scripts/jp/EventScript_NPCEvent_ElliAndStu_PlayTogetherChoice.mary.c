#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuCallsForGrandmother[] =
        "えへへ～、\r\n"
        "おばあちゃ～ん。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenAnswersStu[] =
        "なぁに？{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuAsksEllenToReadStory[] =
        "絵本読んでくれる？{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenAgreesToReadStory[] =
        "ええ、いいわよ。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliGreetsPlayer[] =
        "あら、{Player}くん。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuGreetsPlayerAsOlderSibling[] =
        "あっ、お兄ちゃん！{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenExplainsStuLooksUpToPlayerAsOlderSibling[] =
        "おやおや、いらっしゃい。\r\n"
        "ユウったら、うれしそうに。{Press}\p"
        "あなたのことを\r\n"
        "本当のお兄ちゃんのように\r\n"
        "思ってるみたいよ。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuInvitesPlayerToPlay[] =
        "お兄ちゃん遊ぼうよ。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliSaysPlayerMayBeBusy[] =
        "ユウ、ダメよ。\r\n"
        "{Player}さんも\r\n"
        "仕事があるんだから。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuPleadsWithPlayerToPlay[] =
        "お兄ちゃん、遊んでよ～。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ChoicePlayWithStu[] =
        "遊ぶ";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ChoiceTooBusy[] =
        "いそがしいからダメ！";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliConfirmsPlayerDoesNotMind[] =
        "ごめんなさい。\r\n"
        "ほんとにいいの？{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuCelebratesAcceptance[] =
        "やった～！{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuAsksToKeepPlaying[] =
        "お兄ちゃん、もっと遊ぼうよ。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliEndsPlaytime[] =
        "ユウ、もういいでしょ？\r\n"
        "{Player}さんも\r\n"
        "仕事があるんだから。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuReluctantlyAgrees[] =
        "…うん、わかった。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenPromptsStuToThankPlayer[] =
        "{Player}さんに、\r\n"
        "お礼を言いなさい。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuThanksPlayer[] =
        "お兄ちゃん、ありがとう。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliThanksPlayerForHelpingWithStu[] =
        "ユウのめんどうを見てくれて\r\n"
        "ありがとう。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenInvitesPlayerBack[] =
        "また、いつでも来ておくれ。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuCriesAfterRefusal[] =
        "…ひぐっ、わ～ん…{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliReassuresStuAfterRefusal[] =
        "しょうがないじゃないの！\r\n"
        "{Player}くんは\r\n"
        "仕事があるんだから。{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuAcceptsRefusal[] =
        "だって…だって…\r\n"
        "うわ～ん…{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliOffersStuTreatAndTakesHimHome[] =
        "ユウは、わたしが\r\n"
        "なだめるから、今日のところは\r\n"
        "帰ってくれない？{Press}";

    const char gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliApologizesToPlayer[] =
        "ごめんね。{Press}";
};

void EventScript_NPCEvent_ElliAndStu_PlayTogetherChoice(void)
{
    int var_0;
    ChangeMap(MAP_ELLEN_HOUSE, X(143), Y(114));
    SetEntityPosition(ENTITY_ELLEN, X(128), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_STU, X(128), Y(118), FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(154), Y(96), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(128), Y(260), FACING_UP);
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
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuCallsForGrandmother);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenAnswersStu);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuAsksEllenToReadStory);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenAgreesToReadStory);
    TalkClose();
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(138), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliGreetsPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_STU, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuGreetsPlayerAsOlderSibling);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenExplainsStuLooksUpToPlayerAsOlderSibling);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuInvitesPlayerToPlay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliSaysPlayerMayBeBusy);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuPleadsWithPlayerToPlay);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ChoicePlayWithStu, gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ChoiceTooBusy);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ELLI);
            }
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliConfirmsPlayerDoesNotMind);
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
            SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuCelebratesAcceptance);
            TalkClose();
            WaitFrames(30);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            WaitFrames(30);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            WaitFrames(30);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SWEAT);
            WaitFrames(60);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            WaitFrames(30);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuAsksToKeepPlaying);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliEndsPlaytime);
            TalkClose();
            SetEntityFacing(ENTITY_STU, FACING_UP);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuReluctantlyAgrees);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenPromptsStuToThankPlayer);
            TalkClose();
            SetEntityFacing(ENTITY_STU, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuThanksPlayer);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ELLI);
            }
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliThanksPlayerForHelpingWithStu);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_EllenInvitesPlayerBack);
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
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            AddNpcFriendship(CHARACTER_STU, 20);
            AddNpcFriendship(CHARACTER_ELLI, 20);
            AddNpcFriendship(CHARACTER_ELLEN, 20);
            SetGameTime(19, 0);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(400), Y(168));
            SetEntityPosition(ENTITY_PLAYER, X(400), Y(168), FACING_DOWN);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
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
            SetTalkPortrait(TALK_PORTRAIT_STU_CRYING);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuCriesAfterRefusal);
            TalkClose();
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_AFRAID, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliReassuresStuAfterRefusal);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_CRYING);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_StuAcceptsRefusal);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ELLI);
            }
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliOffersStuTreatAndTakesHimHome);
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
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ELLI);
            }
            TalkMessage(gText_NPCEvent_ElliAndStu_PlayTogetherChoice_ElliApologizesToPlayer);
            TalkClose();
            WaitFrames(30);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            AddNpcFriendship(CHARACTER_STU, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_ELLI, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_ELLEN, mary_negated_int(-10));
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(400), Y(168));
            SetEntityPosition(ENTITY_PLAYER, X(400), Y(168), FACING_DOWN);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            break;
    }
    VarSet(VAR_ELLI_AND_STU_PLAY_TOGETHER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    MarkNpcSpokenTo(CHARACTER_STU);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    MarkNpcSpokenTo(CHARACTER_ELLEN);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
