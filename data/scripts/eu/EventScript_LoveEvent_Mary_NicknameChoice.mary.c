#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_Nickname_MaryIntroducesNicknameChoice[] =
        "I've always looked forward\r\n"
        "to calling my husband a nice\r\n"
        "nickname. {Press}\p"
        "What would you like me\r\n"
        "to call you from now on?{Press}";

    const char gText_LoveEvent_Mary_Nickname_ChoiceUsePlayerName[] =
        "Just my name";

    const char gText_LoveEvent_Mary_Nickname_ChoiceHoney[] =
        "Honey";

    const char gText_LoveEvent_Mary_Nickname_ChoiceDarling[] =
        "Darling";

    const char gText_LoveEvent_Mary_Nickname_ChoiceCustomNickname[] =
        "Other";

    const char gText_LoveEvent_Mary_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Mary_Nickname_MaryConfirmsSelectedNickname[] =
        ".......{NickName}.\r\n"
        "I like the sound of it!{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryRequestsAnotherNickname[] =
        "Can you think of anything\r\n"
        "you like? For me...?{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryConfirmsCustomNickname[] =
        "I like the sound of that!\r\n"
        "{NickName}, it is!{Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryAsksToContinueLibraryWork[] =
        "You don't mind if I continue\r\n"
        "working at the Library,\r\n"
        "do you? {Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryThanksPlayerForPermission[] =
        "Thanks, {NickName}. {Press}";

    const char gText_LoveEvent_Mary_Nickname_MaryAnticipatesNewLife[] =
        "Tomorrow is the first day\r\n"
        "of our new life together!{Press}";
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
