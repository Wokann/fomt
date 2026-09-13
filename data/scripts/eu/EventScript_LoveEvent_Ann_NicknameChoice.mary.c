#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_Nickname_AnnIntroducesNicknameChoice[] =
        "I always imagined calling my\r\n"
        "husband a cute nickname. {Press}\r\n"
        "What should I call you, \r\n"
        "{Player}? {Press}";

    const char gText_LoveEvent_Ann_Nickname_ChoiceUsePlayerName[] =
        "Just my name";

    const char gText_LoveEvent_Ann_Nickname_ChoiceHoney[] =
        "Honey";

    const char gText_LoveEvent_Ann_Nickname_ChoiceDarling[] =
        "Darling";

    const char gText_LoveEvent_Ann_Nickname_ChoiceCustomNickname[] =
        "Other";

    const char gText_LoveEvent_Ann_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Ann_Nickname_AnnConfirmsSelectedNickname[] =
        "It's set, then.\r\n"
        "{NickName}, it is!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnRejectsUnsuitableNickname[] =
        "Can't you think of \r\n"
        "something really good?\r\n"
        "Don't disappoint me now!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnConfirmsCustomNickname[] =
        "Good idea! From now on, \r\n"
        "I'll call you \r\n"
        "{NickName}!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnAsksToContinueInnWork[] =
        "{NickName}...\r\n"
        "There's something I want\r\n"
        "to ask you...{Press}\r\n"
        "Although we're married now,\r\n"
        "I'd still like to help my \r\n"
        "dad out at the Inn. {Press}\r\n"
        "Is that OK with you?{Press}";

    const char gText_LoveEvent_Ann_Nickname_ChoiceAllowInnWork[] =
        "Yes";

    const char gText_LoveEvent_Ann_Nickname_ChoiceDeclineInnWork[] =
        "No";

    const char gText_LoveEvent_Ann_Nickname_AnnThanksPlayerForPermission[] =
        "Thanks, {NickName}!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnAnticipatesNewLife[] =
        "Tomorrow is the first day\r\n"
        "of our new life together!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnAcceptsFarmhouseWork[] =
        "I understand. I'll \r\n"
        "concentrate on the chores\r\n"
        "around here from tomorrow.{Press}";
};

void EventScript_LoveEvent_Ann_NicknameChoice(void)
{
    int var_0;
    VarSet(VAR_ANN_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_FARMHOUSE, X(303), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(303), Y(148), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ANN, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_Nickname_AnnIntroducesNicknameChoice);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice4(gText_LoveEvent_Ann_Nickname_ChoiceUsePlayerName, gText_LoveEvent_Ann_Nickname_ChoiceHoney, gText_LoveEvent_Ann_Nickname_ChoiceDarling, gText_LoveEvent_Ann_Nickname_ChoiceCustomNickname);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Ann_Nickname_PlayerNameNicknameValue);
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Ann_Nickname_ChoiceHoney);
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_3:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            SetPlayerNicknameForSpouse(gText_LoveEvent_Ann_Nickname_ChoiceDarling);
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnConfirmsSelectedNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
        case CHOICE_OPTION_4:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnRejectsUnsuitableNickname);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenNameEntry(NAME_ENTRY_SPOUSE_NICKNAME, NAME_ENTRY_SINGLETON_SLOT);
            PreparePlayerForScriptedAnimation();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnConfirmsCustomNickname);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            break;
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_Nickname_AnnAsksToContinueInnWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Ann_Nickname_ChoiceAllowInnWork, gText_LoveEvent_Ann_Nickname_ChoiceDeclineInnWork);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            VarSet(VAR_SPOUSE_CONTINUES_FAMILY_WORK, TRUE);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnThanksPlayerForPermission);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_ANN);
            VarSet(VAR_ANN_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnAnticipatesNewLife);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            VarSet(VAR_SPOUSE_CONTINUES_FAMILY_WORK, FALSE);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnAcceptsFarmhouseWork);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_ANN);
            VarSet(VAR_ANN_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_LoveEvent_Ann_Nickname_AnnAnticipatesNewLife);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
