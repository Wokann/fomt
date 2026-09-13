#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_Nickname_KarenIntroducesNicknameChoice[] =
        "わたしたち、今日から\r\n"
        "「ふうふ」じゃない？{Press}\p"
        "今までとちがう呼び方で\r\n"
        "呼び合いましょうよ。{Press}\p"
        "わたしは、カレンね。\r\n"
        "{Player}くんは？{Press}";

    const char gText_LoveEvent_Karen_Nickname_ChoiceUsePlayerName[] =
        "よびすて";

    const char gText_LoveEvent_Karen_Nickname_ChoiceHoney[] =
        "あなた";

    const char gText_LoveEvent_Karen_Nickname_ChoiceDarling[] =
        "ダーリン";

    const char gText_LoveEvent_Karen_Nickname_ChoiceCustomNickname[] =
        "その他";

    const char gText_LoveEvent_Karen_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Karen_Nickname_KarenConfirmsSelectedNickname[] =
        "{NickName}♡\r\n"
        "…どう、これでいい？{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenRejectsUnsuitableNickname[] =
        "え？\r\n"
        "もっと、他の呼び方が\r\n"
        "いいって？{Press}\r\n"
        "しょうがないわねぇ。\r\n"
        "じゃあ、\r\n"
        "なんて呼んでほしいの？{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenConfirmsCustomNickname[] =
        "わかったわ。\r\n"
        "今日から{NickName}って\r\n"
        "呼ぶね♡{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenAsksToContinueStoreWork[] =
        "{NickName}、相談が\r\n"
        "あるんだけど…\r\n"
        "結婚しても、父さんのところで{Press}\r\n"
        "手伝いたいのよ。\r\n"
        "手伝いにいってもいい？{Press}";

    const char gText_LoveEvent_Karen_Nickname_ChoiceAllowStoreWork[] =
        "はい";

    const char gText_LoveEvent_Karen_Nickname_ChoiceDeclineStoreWork[] =
        "いいえ";

    const char gText_LoveEvent_Karen_Nickname_KarenThanksPlayerForPermission[] =
        "{NickName}、ありがとう。{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenAnticipatesNewLife[] =
        "さぁ、\r\n"
        "明日から新生活のスタートだ！{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenAcceptsFarmhouseWork[] =
        "わかったわ。\r\n"
        "じゃ、今日からよろしくね。{Press}";
};

void EventScript_LoveEvent_Karen_NicknameChoice(void)
{
    int var_0;
    VarSet(VAR_KAREN_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_FARMHOUSE, X(303), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(303), Y(148), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_KAREN, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_Nickname_KarenIntroducesNicknameChoice);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice4(gText_LoveEvent_Karen_Nickname_ChoiceUsePlayerName, gText_LoveEvent_Karen_Nickname_ChoiceHoney, gText_LoveEvent_Karen_Nickname_ChoiceDarling, gText_LoveEvent_Karen_Nickname_ChoiceCustomNickname);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Karen_Nickname_PlayerNameNicknameValue);
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Karen_Nickname_ChoiceHoney);
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_3:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Karen_Nickname_ChoiceDarling);
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_4:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenRejectsUnsuitableNickname);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenNameEntry(NAME_ENTRY_SPOUSE_NICKNAME, NAME_ENTRY_SINGLETON_SLOT);
            PreparePlayerForScriptedAnimation();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenConfirmsCustomNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_Nickname_KarenAsksToContinueStoreWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Karen_Nickname_ChoiceAllowStoreWork, gText_LoveEvent_Karen_Nickname_ChoiceDeclineStoreWork);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            VarSet(VAR_SPOUSE_CONTINUES_FAMILY_WORK, TRUE);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenThanksPlayerForPermission);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_KAREN);
            VarSet(VAR_KAREN_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenAnticipatesNewLife);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            VarSet(VAR_SPOUSE_CONTINUES_FAMILY_WORK, FALSE);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenAcceptsFarmhouseWork);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_KAREN);
            VarSet(VAR_KAREN_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_LoveEvent_Karen_Nickname_KarenAnticipatesNewLife);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
