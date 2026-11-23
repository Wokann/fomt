#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0079_LoveEvent_Elli_NicknameChoice.mary.h"

void EventScript_0079_LoveEvent_Elli_NicknameChoice(void)
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
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsNickname);
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
#if defined(BUGFIX) || defined(REGION_JP) || defined(REGION_DE)
            // Store the selected nickname before confirming it, as in JP and DE.
            SetPlayerNicknameForSpouse(gText_LoveEvent_Elli_Nickname_ChoiceHoney);
#endif
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsNickname);
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
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsNickname);
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
#if defined(UNIFY_REGIONS) || defined(REGION_JP)
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsNickname_2);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
            TalkMessage(gText_LoveEvent_Elli_Nickname_ElliConfirmsNickname);
#endif
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
    CallScript(EventScript_0988_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
