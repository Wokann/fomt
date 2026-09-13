#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_Nickname_AnnIntroducesNicknameChoice[] =
        "Ich wollte meinem Mann\r\n"
        "immer einen süßen \r\n"
        "Kosenamen geben. {Press}\r\n"
        "Wie soll ich dich nennen, \r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Ann_Nickname_ChoiceUsePlayerName[] =
        "Mein Name";

    const char gText_LoveEvent_Ann_Nickname_ChoiceHoney[] =
        "Schatz";

    const char gText_LoveEvent_Ann_Nickname_ChoiceDarling[] =
        "Spatz";

    const char gText_LoveEvent_Ann_Nickname_ChoiceCustomNickname[] =
        "Andere";

    const char gText_LoveEvent_Ann_Nickname_PlayerNameNicknameValue[] =
        "{Player}";

    const char gText_LoveEvent_Ann_Nickname_AnnConfirmsSelectedNickname[] =
        "Es ist abgemacht.\r\n"
        "{NickName}!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnRejectsUnsuitableNickname[] =
        "Kannst du dir nicht \r\n"
        "etwas Besseres ausdenken?\r\n"
        "Du enttäuschst mich aber!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnConfirmsCustomNickname[] =
        "Gute Idee! Ab jetzt \r\n"
        "nenne ich dich \r\n"
        "{NickName}!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnAsksToContinueInnWork[] =
        "Da ist etwas, was ich\r\n"
        "dich fragen wollte...{Press}\r\n"
        "Obwohl wir verheiratet \r\n"
        "sind, muss ich meinem \r\n"
        "Vater im Gasthof helfen. {Press}\r\n"
        "Ist das ok für dich?{Press}";

    const char gText_LoveEvent_Ann_Nickname_ChoiceAllowInnWork[] =
        "Ja";

    const char gText_LoveEvent_Ann_Nickname_ChoiceDeclineInnWork[] =
        "Nein";

    const char gText_LoveEvent_Ann_Nickname_AnnThanksPlayerForPermission[] =
        "Danke, {NickName}!{Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnAnticipatesNewLife[] =
        "Morgen ist der erste Tag\r\n"
        "in unserem neuen Leben! {Press}";

    const char gText_LoveEvent_Ann_Nickname_AnnAcceptsFarmhouseWork[] =
        "Verstehe. Ich \r\n"
        "mache dann eben den\r\n"
        "Haushalt ab morgen.{Press}";
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
