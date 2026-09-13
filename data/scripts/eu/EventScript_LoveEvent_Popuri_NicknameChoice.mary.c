#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_Nickname_PopuriIntroducesNicknameChoice[] =
        "Now that we're married, \r\n"
        "we have to think of \r\n"
        "nicknames! What do you {Press}\r\n"
        "want to be called? {Press}";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceUsePlayerName[] =
        "Just my name";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceHoney[] =
        "Honey";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceDarling[] =
        "Darling";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceCustomNickname[] =
        "Other";

    const char gText_LoveEvent_Popuri_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriConfirmsSelectedNickname[] =
        "OK, it's set!\r\n"
        "From now on, I'll call \r\n"
        "you {NickName}!{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriRequestsAnotherNickname[] =
        "What?\r\n"
        "What do you want me\r\n"
        "to call you then?{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriConfirmsCustomNickname[] =
        "OK. \r\n"
        "From now on I'll call you\r\n"
        "{NickName}.{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriAsksToContinuePoultryFarmWork[] =
        "Can I ask you a question, \r\n"
        "{NickName}?{Press}\r\n"
        "I would still like to help{Press}\r\n"
        "my mom out. Is that OK?{Press}";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceAllowPoultryFarmWork[] =
        "Of course!";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceDeclinePoultryFarmWork[] =
        "No.";

    const char gText_LoveEvent_Popuri_Nickname_PopuriThanksPlayerForPermission[] =
        "Thanks, {NickName}.{Press}";

    const char gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterContinuingPoultryFarmWork[] =
        "Tomorrow is the first day\r\n"
        "of our new life together! {Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriAcceptsFarmhouseWork[] =
        "Alright. In that case,\r\n"
        "leave the house chores \r\n"
        "to me. {Press}";

    const char gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterChoosingFarmhouseWork[] =
        "Tomorrow is the first day\r\n"
        "of our new life together!{Press}";
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
            TalkMessage(gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterChoosingFarmhouseWork);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
