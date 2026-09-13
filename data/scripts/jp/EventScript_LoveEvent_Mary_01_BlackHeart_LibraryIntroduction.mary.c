#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_01_BlackHeart_MaryWorriesAboutHerWriting[] =
        "うーん…\r\n"
        "どうすればいいかなぁ…\r\n"
        "あっ、こうすれば…{Press}\r\n"
        "でも、違う…{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesForCollision[] =
        "きゃっ。\r\n"
        "あっ、ごめんなさい。つい\r\n"
        "考えごとしてたものだから…{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAsksIfPlayerIsNew[] =
        "あら？\r\n"
        "見かけない人ね。\r\n"
        "観光できたの？{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryRecognizesNewFarmer[] =
        "ああ！\r\n"
        "あの牧場にきた人ね！\r\n"
        "ふ～ん、{Player}くんって{Press}\r\n"
        "言うんだ。\r\n"
        "わたしの名前はマリーよ。\r\n"
        "よろしくね。{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryWelcomesPlayerToLibrary[] =
        "あっ、{Player}くん。\r\n"
        "来てくれたのね。{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAppreciatesLibraryVisitor[] =
        "この図書館に来てくれる人が、\r\n"
        "あまりいないから、\r\n"
        "うれしいわ。{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesAgain[] =
        "さっきはごめんなさいね。\r\n"
        "わたしって考え事すると\r\n"
        "周りが見えなくなるの…{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_ChoiceOfferToHelpMary[] =
        "悩み事だったら相談に乗るよ";

    const char gText_LoveEvent_Mary_01_BlackHeart_ChoiceTellMaryToBeCareful[] =
        "危ないから気をつけてね";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryExplainsSheIsWritingNovel[] =
        "ううん、違うの。\r\n"
        "わたし、自分で小説を書いて\r\n"
        "いるんだけど、{Press}\r\n"
        "内容につまって色々\r\n"
        "考えていたの。\r\n"
        "ありがとう。心配してくれて。{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsPlayersHelp[] =
        "読みたい本があったら、\r\n"
        "いつでも来てね。{Press}\p"
        "{Player}くんに\r\n"
        "役立つ本がきっとあるから。{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsCautiousAdvice[] =
        "本当にごめんなさい。\r\n"
        "今度から気をつけるわ。{Press}";
};

void EventScript_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction(void)
{
    int var_0;
    ChangeMap(MAP_LIBRARY_1F, X(120), Y(144));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_MARY, X(216), Y(168), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryWorriesAboutHerWriting);
    TalkClose();
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesForCollision);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    if (HasMetNpc(CHARACTER_MARY) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAsksIfPlayerIsNew);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryRecognizesNewFarmer);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryWelcomesPlayerToLibrary);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAppreciatesLibraryVisitor);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesAgain);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Mary_01_BlackHeart_ChoiceOfferToHelpMary, gText_LoveEvent_Mary_01_BlackHeart_ChoiceTellMaryToBeCareful);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_MARY, 3000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryExplainsSheIsWritingNovel);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsPlayersHelp);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetEntityEventScript(ENTITY_MARY, EventScript_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction_FollowupMaryDialogue);
            VarSet(VAR_MARY_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsCautiousAdvice);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetEntityEventScript(ENTITY_MARY, EventScript_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction_FollowupMaryDialogue);
            VarSet(VAR_MARY_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
    EnableScriptedNpcControl();
}
