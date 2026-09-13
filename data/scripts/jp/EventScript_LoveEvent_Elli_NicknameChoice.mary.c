#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_Nickname_ElliIntroducesNicknameChoice[] =
        "これからわたし、{Player}\r\n"
        "くんのことどう呼んだら\r\n"
        "いいかしら？{Press}";

    const char gText_LoveEvent_Elli_Nickname_ChoiceUsePlayerName[] =
        "よびすて";

    const char gText_LoveEvent_Elli_Nickname_ChoiceHoney[] =
        "あなた";

    const char gText_LoveEvent_Elli_Nickname_ChoiceDarling[] =
        "ダーリン";

    const char gText_LoveEvent_Elli_Nickname_ChoiceCustomNickname[] =
        "その他";

    const char gText_LoveEvent_Elli_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Elli_Nickname_ElliConfirmsSelectedNickname[] =
        "ふふふ、わかったわ。\r\n"
        "{NickName}♡、ね。{Press}";

    const char gText_LoveEvent_Elli_Nickname_ElliRequestsAnotherNickname[] =
        "なにか、いいよびかたないの？{Press}";

    const char gText_LoveEvent_Elli_Nickname_ElliConfirmsCustomNickname[] =
        "うん、それじゃ\r\n"
        "{NickName}ね♡{Press}";

    const char gText_LoveEvent_Elli_Nickname_ElliAsksToContinueClinicWork[] =
        "{NickName}、\r\n"
        "おばあちゃんの足の事も\r\n"
        "あるし、{Press}\p"
        "結婚しても、これまで通り\r\n"
        "病院をつづけたいの。\r\n"
        "いいでしょ？{Press}";

    const char gText_LoveEvent_Elli_Nickname_ElliThanksPlayerForPermission[] =
        "{NickName}、ありがとう。{Press}";

    const char gText_LoveEvent_Elli_Nickname_ElliAnticipatesNewLife[] =
        "さぁ、\r\n"
        "明日から新生活のスタートだ！{Press}";
};

void EventScript_LoveEvent_Elli_NicknameChoice(void)
{
    int var_0;
    VarSet(VAR_ELLI_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_FARMHOUSE, X(303), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(303), Y(148), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_Nickname_ElliIntroducesNicknameChoice);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice4(gText_LoveEvent_Elli_Nickname_ChoiceUsePlayerName, gText_LoveEvent_Elli_Nickname_ChoiceHoney, gText_LoveEvent_Elli_Nickname_ChoiceDarling, gText_LoveEvent_Elli_Nickname_ChoiceCustomNickname);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Elli_Nickname_PlayerNameNicknameValue);
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Elli_Nickname_ChoiceHoney);
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_3:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Elli_Nickname_ChoiceDarling);
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_4:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliRequestsAnotherNickname);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenNameEntry(NAME_ENTRY_SPOUSE_NICKNAME, NAME_ENTRY_SINGLETON_SLOT);
            PreparePlayerForScriptedAnimation();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsCustomNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_Nickname_ElliAsksToContinueClinicWork);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_Nickname_ElliThanksPlayerForPermission);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ELLI);
    VarSet(VAR_ELLI_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_LoveEvent_Elli_Nickname_ElliAnticipatesNewLife);
    TalkClose();
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
