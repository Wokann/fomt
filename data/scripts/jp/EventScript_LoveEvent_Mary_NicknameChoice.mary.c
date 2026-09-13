#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_Nickname_MaryIntroducesNicknameChoice[] =
        "わたし、今まで{Player}\r\n"
        "くんの事は、{Player}くん\r\n"
        "って言っていたでしょう？{Press}\p"
        "でも結婚後は、これじゃ\r\n"
        "おかしいと思うの。{Press}\p"
        "それで、どうしようと\r\n"
        "思ってるんだけど…{Press}";

    const char gText_LoveEvent_Mary_Nickname_ChoiceUsePlayerName[] =
        "よびすて";

    const char gText_LoveEvent_Mary_Nickname_ChoiceHoney[] =
        "あなた";

    const char gText_LoveEvent_Mary_Nickname_ChoiceDarling[] =
        "ダーリン";

    const char gText_LoveEvent_Mary_Nickname_ChoiceCustomNickname[] =
        "その他";

    const char gText_LoveEvent_Mary_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Mary_Nickname_MaryConfirmsSelectedNickname[] =
        "……………{NickName}♡\r\n"
        "うん、いい感じ！{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryRequestsAnotherNickname[] =
        "いいよびかたが思いつかない？\r\n"
        "ダメダメ、ちゃんと考えて。{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryConfirmsCustomNickname[] =
        "うん、それ気に入ったわ\r\n"
        "よろしくね。\r\n"
        "{NickName}♡{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryAsksToContinueLibraryWork[] =
        "あ、そうそう。結婚しても、\r\n"
        "これまで通り図書館をつづける\r\n"
        "から。いいでしょ？{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryThanksPlayerForPermission[] =
        "{NickName}、ありがとう。{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryAnticipatesNewLife[] =
        "さぁ、\r\n"
        "明日から新生活のスタートだ！{Press}";
};

void EventScript_LoveEvent_Mary_NicknameChoice(void)
{
    int var_0;
    VarSet(VAR_MARY_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_FARMHOUSE, X(303), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(303), Y(148), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_MARY, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_Nickname_MaryIntroducesNicknameChoice);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice4(gText_LoveEvent_Mary_Nickname_ChoiceUsePlayerName, gText_LoveEvent_Mary_Nickname_ChoiceHoney, gText_LoveEvent_Mary_Nickname_ChoiceDarling, gText_LoveEvent_Mary_Nickname_ChoiceCustomNickname);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Mary_Nickname_PlayerNameNicknameValue);
            TalkMessage(gText_LoveEvent_Mary_Nickname_MaryConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Mary_Nickname_ChoiceHoney);
            TalkMessage(gText_LoveEvent_Mary_Nickname_MaryConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_3:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Mary_Nickname_ChoiceDarling);
            TalkMessage(gText_LoveEvent_Mary_Nickname_MaryConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_4:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_Nickname_MaryRequestsAnotherNickname);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenNameEntry(NAME_ENTRY_SPOUSE_NICKNAME, NAME_ENTRY_SINGLETON_SLOT);
            PreparePlayerForScriptedAnimation();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_Nickname_MaryConfirmsCustomNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_Nickname_MaryAsksToContinueLibraryWork);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_Nickname_MaryThanksPlayerForPermission);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_MARY);
    VarSet(VAR_MARY_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_LoveEvent_Mary_Nickname_MaryAnticipatesNewLife);
    TalkClose();
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
