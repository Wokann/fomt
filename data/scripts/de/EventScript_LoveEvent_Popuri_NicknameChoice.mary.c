#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_Nickname_PopuriIntroducesNicknameChoice[] =
        "Wir müssen uns Kosenamen \r\n"
        "geben, wo wir jetzt \r\n"
        "verheiratet sind! Wie {Press}\r\n"
        "willst du genannt werden?{Press}";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceUsePlayerName[] =
        "Mein Name";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceHoney[] =
        "Schatz";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceDarling[] =
        "Spatz";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceCustomNickname[] =
        "Andere";

    const char gText_LoveEvent_Popuri_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriConfirmsSelectedNickname[] =
        "OK, abgemacht!\r\n"
        "Ab jetzt nenne ich \r\n"
        "dich {NickName}!{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriRequestsAnotherNickname[] =
        "Was?\r\n"
        "Wie soll ich dich \r\n"
        "denn dann{Press}\r\n"
        "nennen?{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriConfirmsCustomNickname[] =
        "OK. \r\n"
        "Ab jetzt nenne ich dich\r\n"
        "{NickName}.{Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriAsksToContinuePoultryFarmWork[] =
        "Kann ich dich etwas fragen, \r\n"
        "{NickName}?{Press}\r\n"
        "Ich würde immer noch{Press}\r\n"
        "gerne meiner Mutter helfen. \r\n"
        "Ist das in Ordnung?{Press}";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceAllowPoultryFarmWork[] =
        "Natürlich!";

    const char gText_LoveEvent_Popuri_Nickname_ChoiceDeclinePoultryFarmWork[] =
        "Nein.";

    const char gText_LoveEvent_Popuri_Nickname_PopuriThanksPlayerForPermission[] =
        "Danke, {NickName}.{Press}";

    const char gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterWorkDecision[] =
        "Morgen ist der erste Tag\r\n"
        "in unserem neuen Leben! {Press}";

    const char gText_LoveEvent_Popuri_Nickname_PopuriAcceptsFarmhouseWork[] =
        "Ok. In diesem Fall\r\n"
        "übernehme ich den \r\n"
        "Haushalt. {Press}";
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
            TalkMessage(gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterWorkDecision);
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
            TalkMessage(gText_LoveEvent_Popuri_Nickname_AnticipatesNewLifeAfterWorkDecision);
            TalkClose();
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
