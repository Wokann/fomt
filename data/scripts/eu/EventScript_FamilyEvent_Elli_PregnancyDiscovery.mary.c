#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliFeelsIllAndRequestsClinicVisit[] =
        "I think I might have \r\n"
        "come down with something...{Press}\p"
        "I feel sick to my stomach.{Press}\p"
        "{NickName}, will you take\r\n"
        "me to the Clinic?{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliThanksPlayerForConcern[] =
        "Thanks. You're a sweetheart.{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorExplainsElliIsPregnant[] =
        "Your wife isn't sick.{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorCongratulatesPlayerAndElli[] =
        "You're going to be parents.\r\n"
        "Congratulations!{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_DoctorCongratulatesElliOnLongDesiredPregnancy[] =
        "Congratulations, Elli.\r\n"
        "You always did want a baby.{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliAcknowledgesPregnancy[] =
        "I...I understand.{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliMarvelsAtBeingPregnant[] =
        "I can't believe I'm actually\r\n"
        "pregnant!{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_ElliLooksForwardToTellingEllen[] =
        "I can't wait to tell \r\n"
        "Grandma and everybody!\r\n"
        "Let's go home!{Press}";

    const char gText_FamilyEvent_Elli_PregnancyDiscovery_PlayerReflectsOnFatherhoodAndLoveForElli[] =
        "I can't believe I'm about to\r\n"
        "become a father...\r\n"
        "This is so great!{Press}";
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
