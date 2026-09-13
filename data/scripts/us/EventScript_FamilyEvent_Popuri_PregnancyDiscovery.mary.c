#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriFeelsIllAndRequestsClinicVisit[] =
        "I don't feel well at all!\r\n"
        "{NickName}, will you take\r\n"
        "me to the Clinic?{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriThanksPlayerAndLeavesForClinic[] =
        "Thanks. Let's go.{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_DoctorExplainsPopuriIsPregnant[] =
        "Your wife isn't sick.{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_DoctorCongratulatesPlayerAndPopuri[] =
        "You're going to be parents.\r\n"
        "Congratulations!{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_ElliCongratulatesPopuri[] =
        "Congratulations, Popuri.{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriRespondsToCongratulations[] =
        "......OK.{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriMarvelsAtHavingBaby[] =
        "I can't believe we're \r\n"
        "going to have a baby!{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriLooksForwardToTellingFamily[] =
        "I can't wait to tell\r\n"
        "my family! Let's go home,\r\n"
        "{NickName}!{Press}";

    const char gText_FamilyEvent_Popuri_PregnancyDiscovery_PlayerReflectsOnFatherhoodAndLoveForPopuri[] =
        "I can't believe I'm about to\r\n"
        "become a father...\r\n"
        "This is so great!{Press}";
};

void EventScript_FamilyEvent_Popuri_PregnancyDiscovery(void)
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
    SetEntityPosition(ENTITY_POPURI, X(333), Y(94), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_POPURI_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriFeelsIllAndRequestsClinicVisit);
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
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriThanksPlayerAndLeavesForClinic);
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
    SetEntityPosition(ENTITY_POPURI, X(228), Y(148), FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(262), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(262), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_DoctorExplainsPopuriIsPregnant);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_QUESTION, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_DoctorCongratulatesPlayerAndPopuri);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HEART, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_ElliCongratulatesPopuri);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriRespondsToCongratulations);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriMarvelsAtHavingBaby);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_PopuriLooksForwardToTellingFamily);
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
    MarkNpcSpokenTo(CHARACTER_POPURI);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    AddCharacterLove(CHARACTER_POPURI, 3000);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    AddNpcFriendship(CHARACTER_ELLI, 20);
    VarSet(VAR_POPURI_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FamilyEvent_Popuri_PregnancyDiscovery_PlayerReflectsOnFatherhoodAndLoveForPopuri);
    TalkClose();
    PlacePlayerAtFarmhouseBed();
    SetGameTime(17, 0);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    return;
}
