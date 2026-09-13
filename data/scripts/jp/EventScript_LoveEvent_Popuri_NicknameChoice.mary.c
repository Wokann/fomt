#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_Nickname_PopuriIntroducesNicknameChoice[] =
        "ねぇねぇ、結婚したんだから、\r\n"
        "呼び方考えなくちゃ。\r\n"
        "なんて呼んでほしい？{Press}";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceUsePlayerName[] =
        "よびすて";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceHoney[] =
        "あなた";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceDarling[] =
        "ダーリン";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceCustomNickname[] =
        "その他";

    const char gText_LoveEvent_Popuri_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriConfirmsSelectedNickname[] =
        "うん、じゃ決まりね。\r\n"
        "これからよろしくおねがい\r\n"
        "します。{NickName}♡{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriRequestsAnotherNickname[] =
        "え？\r\n"
        "もっと、他の呼びかたが\r\n"
        "いいの？{Press}\r\n"
        "しょうがないな～。\r\n"
        "じゃあ、\r\n"
        "なんてよんでほしいの？{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriConfirmsCustomNickname[] =
        "わかった。\r\n"
        "今日から{NickName}って\r\n"
        "よぶね♡{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriAsksToContinuePoultryFarmWork[] =
        "あっ、そうだ。{NickName}、\r\n"
        "相談があるの…\r\n"
        "結婚しても、お母さんの{Press}\r\n"
        "ところで手伝いたいの。\r\n"
        "手伝いにいってもいい？{Press}";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceAllowPoultryFarmWork[] =
        "はい";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceDeclinePoultryFarmWork[] =
        "いいえ";

    const char gText_LoveEvent_Popuri_Nickname_PopuriThanksPlayerForPermission[] =
        "{NickName}、ありがと。{Press}";

    const char gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterContinuingPoultryFarmWork[] =
        "さぁ、\r\n"
        "明日から新生活のスタートだ！{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriAcceptsFarmhouseWork[] =
        "わかった。\r\n"
        "じゃ、明日から家のことは\r\n"
        "まかせてね。{Press}";
};

void EventScript_LoveEvent_Popuri_NicknameChoice(void)
{
    int var_0;
    VarSet(VAR_POPURI_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_FARMHOUSE, X(303), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(303), Y(148), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_POPURI, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriIntroducesNicknameChoice);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice4(gText_LoveEvent_Popuri_Nickname_ChoiceUsePlayerName, gText_LoveEvent_Popuri_Nickname_ChoiceHoney, gText_LoveEvent_Popuri_Nickname_ChoiceDarling, gText_LoveEvent_Popuri_Nickname_ChoiceCustomNickname);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Popuri_Nickname_PlayerNameNicknameValue);
            TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Popuri_Nickname_ChoiceHoney);
            TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_3:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Popuri_Nickname_ChoiceDarling);
            TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_4:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriRequestsAnotherNickname);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenNameEntry(NAME_ENTRY_SPOUSE_NICKNAME, NAME_ENTRY_SINGLETON_SLOT);
            PreparePlayerForScriptedAnimation();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriConfirmsCustomNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriAsksToContinuePoultryFarmWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Popuri_Nickname_ChoiceAllowPoultryFarmWork, gText_LoveEvent_Popuri_Nickname_ChoiceDeclinePoultryFarmWork);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            VarSet(VAR_SPOUSE_CONTINUES_FAMILY_WORK, TRUE);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriThanksPlayerForPermission);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterContinuingPoultryFarmWork);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            VarSet(VAR_SPOUSE_CONTINUES_FAMILY_WORK, FALSE);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_Nickname_PopuriAcceptsFarmhouseWork);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterContinuingPoultryFarmWork);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
