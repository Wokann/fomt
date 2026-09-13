#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_Nickname_KarenIntroducesNicknameChoice[] =
        "Don't all married couples \r\n"
        "have to call each other by \r\n"
        "nickanmes?{Press}\p"
        "What do you want me \r\n"
        "to call you? {Press}";

    const char gText_LoveEvent_Karen_Nickname_ChoiceUsePlayerName[] =
        "Just my name";

    const char gText_LoveEvent_Karen_Nickname_ChoiceHoney[] =
        "Honey";

    const char gText_LoveEvent_Karen_Nickname_ChoiceDarling[] =
        "Darling";

    const char gText_LoveEvent_Karen_Nickname_ChoiceCustomNickname[] =
        "Other";

    const char gText_LoveEvent_Karen_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Karen_Nickname_KarenConfirmsSelectedNickname[] =
        "{NickName}...\r\n"
        "How do you like it?{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenRejectsUnsuitableNickname[] =
        "Can't you think of a \r\n"
        "really good name then?{Press}\r\n"
        "It's for the rest of our\r\n"
        "lives, after all!{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenConfirmsCustomNickname[] =
        "OK, it's \r\n"
        "{NickName} \r\n"
        "from now on, then.  {Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenAsksToContinueStoreWork[] =
        "{NickName}...\r\n"
        "There's something I want\r\n"
        "to ask you...{Press}\r\n"
        "Although we're married now,\r\n"
        "I'd still like to help my \r\n"
        "dad out at the store. {Press}\r\n"
        "Is that OK with you?{Press}";

    const char gText_LoveEvent_Karen_Nickname_ChoiceAllowStoreWork[] =
        "Yes";

    const char gText_LoveEvent_Karen_Nickname_ChoiceDeclineStoreWork[] =
        "No";

    const char gText_LoveEvent_Karen_Nickname_KarenThanksPlayerForPermission[] =
        "Thanks, {NickName}!{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenAnticipatesNewLife[] =
        "Tomorrow is the first day\r\n"
        "of our new life together!{Press}";

    const char gText_LoveEvent_Karen_Nickname_KarenAcceptsFarmhouseWork[] =
        "I understand. I'll \r\n"
        "concentrate on the chores\r\n"
        "around here, then. {Press}";
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
