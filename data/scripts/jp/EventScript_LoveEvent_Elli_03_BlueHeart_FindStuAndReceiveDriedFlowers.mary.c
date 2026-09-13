#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForVisiting[] =
        "{Player}。\r\n"
        "よく、きたわね。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliWelcomesPlayerHome[] =
        "いらっしゃい…{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenEncouragesElli[] =
        "エリィ、元気だしなさいよ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsEllensEncouragement[] =
        "うん…{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenExplainsStuRanAwayAfterDinner[] =
        "エリィがユウのために、\r\n"
        "ごはん作ったんだけど、{Press}\p"
        "食べたくないって言って、\r\n"
        "ユウが外に出ていっちゃった\r\n"
        "のよ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliWorriesInSilence[] =
        "……………{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenRegretsUnableToSearch[] =
        "わたしの足がこんなんじゃ\r\n"
        "なかったら、\r\n"
        "連れもどせるんだけどねぇ…{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenAsksPlayerToFindStu[] =
        "そうだわ！{Player}、\r\n"
        "ユウを連れもどしてくれない？{Press}\p"
        "たぶん、あの子のことだから\r\n"
        "教会前にいると思うのよ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ChoiceRefuseToFindStu[] =
        "断わる";

    const char gText_LoveEvent_Elli_03_BlueHeart_ChoiceAgreeToFindStu[] =
        "ひきうける";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsPlayersRefusal[] =
        "いいのよ。{Press}\p"
        "味オンチのわたしが作ったもの\r\n"
        "なんて、おいしいわけないん\r\n"
        "だから…{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenReassuresElliAboutStu[] =
        "そんなことないわよ。\r\n"
        "ユウもしばらくしたら帰って\r\n"
        "くるわ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliRemainsWorried[] =
        "…………{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuReturnsAndApologizesToElli[] =
        "…………グスッ…\r\n"
        "お姉ちゃん…ごめんなさい…{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliForgivesStu[] =
        "ううん、いいのよ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenTellsStuElliForgivesHim[] =
        "ユウ、お姉ちゃんも\r\n"
        "ゆるしてるんだから泣くのを\r\n"
        "やめなさい。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuAcceptsReconciliation[] =
        "うん。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForKindness[] =
        "そう！\r\n"
        "じゃあ、お願いするわ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuGreetsPlayerWhenFound[] =
        "あっ、お兄ちゃん。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuRegretsHurtingElli[] =
        "お姉ちゃんが悲しんでたの？\r\n"
        "わかった、帰るよ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuApologizesAfterReturning[] =
        "お姉ちゃん、ごめんなさい。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerAfterStusReturn[] =
        "はぁ…よかったよ。\r\n"
        "{Player}、ありがとう。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliThanksPlayerAndIntroducesGift[] =
        "ありがとう、\r\n"
        "{Player}くん。\r\n"
        "あ、そうだ！{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliHandsDriedFlowersToPlayer[] =
        "ああ、あったわ！{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliExplainsDriedFlowerGift[] =
        "今日はありがとう。\r\n"
        "お礼といってはなんだけど、\r\n"
        "この前、押し花作ったの。{Press}\r\n"
        "もらってくれる？{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliRelievedPlayerLikesGift[] =
        "よかった。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliPlansAnotherDinnerForStu[] =
        "さあ、ユウも帰ってきた\r\n"
        "ことだし、\r\n"
        "ゴチソウを作るわよ。{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuDreadsAnotherDinner[] =
        "げっ、また作るの？{Press}";
};

void EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers(void)
{
    int var_0;
    ChangeMap(MAP_ELLEN_HOUSE, X(120), Y(104));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(104), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(136), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_STU, X(120), Y(208), FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_ELLEN, X(120), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForVisiting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliWelcomesPlayerHome);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenEncouragesElli);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsEllensEncouragement);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenExplainsStuRanAwayAfterDinner);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliWorriesInSilence);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenRegretsUnableToSearch);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenAsksPlayerToFindStu);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Elli_03_BlueHeart_ChoiceRefuseToFindStu, gText_LoveEvent_Elli_03_BlueHeart_ChoiceAgreeToFindStu);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_ELLEN, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsPlayersRefusal);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenReassuresElliAboutStu);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliRemainsWorried);
            TalkClose();
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityYTo(ENTITY_STU, Y(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
            StartEntityEffect(ENTITY_ELLEN, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_CRYING);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuReturnsAndApologizesToElli);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliForgivesStu);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenTellsStuElliForgivesHim);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuAcceptsReconciliation);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_STU);
            MarkNpcSpokenTo(CHARACTER_ELLEN);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_ELLEN, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupEllenDialogue);
            SetEntityEventScript(ENTITY_STU, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupStuDialogue);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_CHOICE, ELLI_BLUE_HEART_RESPONSE_REFUSE_TO_SEARCH);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            AddNpcFriendship(CHARACTER_ELLEN, 20);
            AddNpcFriendship(CHARACTER_STU, 20);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForKindness);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(1264), Y(216));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(1128), Y(216), FACING_RIGHT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_STU, X(1264), Y(216), FACING_UP);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            if (GetEntityLocation(ENTITY_CARTER) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_CARTER);
            }
            if (GetEntityLocation(ENTITY_DOCTOR) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_DOCTOR);
            }
            if (GetEntityLocation(ENTITY_CLIFF) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_CLIFF);
            }
            if (GetEntityLocation(ENTITY_ZACK) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_ZACK);
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(1184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_STU, FACING_LEFT);
            StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuGreetsPlayerWhenFound);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(1224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuRegretsHurtingElli);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_ELLEN_HOUSE, X(120), Y(80));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(120), FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_ELLI, X(136), Y(80), FACING_DOWN);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityPosition(ENTITY_STU, X(136), Y(120), FACING_UP);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            SetEntityPosition(ENTITY_ELLEN, X(120), Y(80), FACING_DOWN);
            SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuApologizesAfterReturning);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliForgivesStu);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerAfterStusReturn);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliThanksPlayerAndIntroducesGift);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_UP);
            StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliHandsDriedFlowersToPlayer);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliExplainsDriedFlowerGift);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliRelievedPlayerLikesGift);
            TalkClose();
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            SetPlayerHeldArticle(ITEM_ARTICLE_ELLIS_PRESSED_FLOWER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliPlansAnotherDinnerForStu);
            TalkClose();
            StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuDreadsAnotherDinner);
            TalkClose();
            PanCameraTo(X(120), Y(120), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForCameraMovement();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_STU);
            MarkNpcSpokenTo(CHARACTER_ELLEN);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_ELLEN, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupEllenDialogue);
            SetEntityEventScript(ENTITY_STU, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupStuDialogue);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_CHOICE, ELLI_BLUE_HEART_RESPONSE_HELP_FIND_STU);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
