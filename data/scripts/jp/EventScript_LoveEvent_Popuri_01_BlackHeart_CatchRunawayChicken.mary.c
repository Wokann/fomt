#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ChasesRunawayChicken[] =
        "ちょっと、待って～。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_CallsChickenBack[] =
        "コッコ、待ってよ～。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ScoldsChicken[] =
        "コッコ、にげちゃダメよ。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerForCatch[] =
        "ありがとう。\r\n"
        "捕まえてもらって…{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerIsNew[] =
        "あれ？\r\n"
        "はじめて話す人だよね？\r\n"
        "こんにちは。{Press}\r\n"
        "わたし、ポプリっていうの。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_RecognizesNewFarmer[] =
        "あの牧場にきた人って、\r\n"
        "あなただったのね。{Press}\p"
        "{Player}さんって\r\n"
        "言うんだ～。よろしくね。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ExplainsChickenEscaped[] =
        "あっ、{Player}さん\r\n"
        "ちょっと目をはなしたら、\r\n"
        "コッコが逃げちゃったのよ。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerAgain[] =
        "ありがとう。コッコって\r\n"
        "足が速いから、なかなか\r\n"
        "捕まえられないのよ。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerLikesChickens[] =
        "{Player}さんって、\r\n"
        "鶏好き？{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_ChoiceLikesChickens[] =
        "好き";

    const char gText_LoveEvent_Popuri_01_BlackHeart_ChoiceDislikesChickens[] =
        "嫌い";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_HappyPlayerLikesChickens[] =
        "やっぱり！そんな気が\r\n"
        "してたんだ。ポプリも鶏が\r\n"
        "すご～く好きなの♡{Press}\p"
        "鶏が好きな人に悪い人は\r\n"
        "いないって、\r\n"
        "お父さんも言ってたの。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_PreparesToReturnChicken[] =
        "じゃあ、ポプリはコッコを\r\n"
        "連れていかないとダメだから\r\n"
        "帰るね。{Press}\p"
        "鶏のことで困ったら、\r\n"
        "いつでも家にきてね。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_InvitesRunawayChickenHome[] =
        "コッコ、帰るよ。\r\n"
        "おいで。{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsChickenDislike[] =
        "え～～～！！\r\n"
        "こんなにかわいいのに…{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsFarmVisit[] =
        "じゃあ、\r\n"
        "ここには何しに来たの？{Press}\p"
        "ここはあなたが嫌いな鶏がいる\r\n"
        "養鶏場なんだけど…{Press}\p"
        "ごめんね。\r\n"
        "嫌いな鶏を捕まえてもらって。{Press}";
};

void EventScript_LoveEvent_Popuri_01_BlackHeart_CatchRunawayChicken(void)
{
    int var_0;
    ChangeMap(MAP_SOUTH_SIDE_TOWN, X(471), Y(171));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(320), Y(171), FACING_RIGHT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_POPURI, X(471), Y(300), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(471), Y(300), FACING_UP);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_PLAYER, X(471), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ChasesRunawayChicken);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
    MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(GetEntityY(ENTITY_PLAYER) + 8), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_CallsChickenBack);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    BeginHoldingActorGraphic(ANIMATION_CHICKEN_HELD);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(202), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(GetEntityY(ENTITY_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ScoldsChicken);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerForCatch);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
        WaitFrames(60);
        UsePlayerHeldItem();
        SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        WaitFrames(60);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerIsNew);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_RecognizesNewFarmer);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ExplainsChickenEscaped);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
        WaitFrames(60);
        UsePlayerHeldItem();
        SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerAgain);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerLikesChickens);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Popuri_01_BlackHeart_ChoiceLikesChickens, gText_LoveEvent_Popuri_01_BlackHeart_ChoiceDislikesChickens);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_POPURI, 3000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_HappyPlayerLikesChickens);
            TalkClose();
            StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_PreparesToReturnChicken);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_InvitesRunawayChickenHome);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(GetEntityY(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_DOWN);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(226), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityXTo(ENTITY_POPURI, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(556), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            HideEntity(ENTITY_POPURI);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsChickenDislike);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsFarmVisit);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_InvitesRunawayChickenHome);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(GetEntityY(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_DOWN);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(226), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityXTo(ENTITY_POPURI, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(556), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            HideEntity(ENTITY_POPURI);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
    }
    RefreshAllNpcSchedules();
}
