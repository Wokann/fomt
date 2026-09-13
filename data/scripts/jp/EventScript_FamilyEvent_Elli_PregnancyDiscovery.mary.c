#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliFeelsIllAndRequestsClinicVisit[] =
        "わたし、何かの病気にかかった\r\n"
        "のかしら？\r\n"
        "ひどく気分が悪いの…{Press}\p"
        "{NickName}、心細いから\r\n"
        "病院までいっしょに来て\r\n"
        "くれる？{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliThanksPlayerForConcern[] =
        "ありがとう。\r\n"
        "心強いわ。{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorExplainsElliIsPregnant[] =
        "キミの奥さんは病気じゃ\r\n"
        "ないよ。{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorCongratulatesPlayerAndElli[] =
        "おめでとう。\r\n"
        "おめでただよ。{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorCongratulatesElliOnLongDesiredPregnancy[] =
        "エリィ、よかったね。\r\n"
        "エリィは、前から赤ちゃんが\r\n"
        "ほしいって言っていたから。{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliAcknowledgesPregnancy[] =
        "は、はい。{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliMarvelsAtBeingPregnant[] =
        "赤ちゃんが出来たんだって♡{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliLooksForwardToTellingEllen[] =
        "おばあちゃんたちにも知らせ\r\n"
        "なきゃ♡{NickName}、帰り\r\n"
        "ましょう。{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_PlayerReflectsOnFatherhoodAndLoveForElli[] =
        "もうすぐ、お父さんか…\r\n"
        "うれしいな。{Press}";
};

void EventScript_FamilyEvent_Elli_PregnancyDiscovery(void)
{
    ChangeMap(MAP_FARMHOUSE, X(300), Y(94));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(300), Y(94), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(333), Y(94), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_ELLI_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_ElliFeelsIllAndRequestsClinicVisit);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_ElliThanksPlayerForConcern);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(228), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(124), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(228), Y(148), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(262), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorExplainsElliIsPregnant);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_QUESTION, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorCongratulatesPlayerAndElli);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_HEART, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorCongratulatesElliOnLongDesiredPregnancy);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_ElliAcknowledgesPregnancy);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_UP);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_ElliMarvelsAtBeingPregnant);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_ElliLooksForwardToTellingEllen);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    AddCharacterLove(CHARACTER_ELLI, 3000);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    VarSet(VAR_ELLI_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FamilyEvent_Elli_PregnancyDiscovery_PlayerReflectsOnFatherhoodAndLoveForElli);
    TalkClose();
    PlacePlayerAtFarmhouseBed();
    SetGameTime(17, 0);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    return;
}
