#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_PregnancyDiscovery_KarenMistakesNauseaForHangoverAndRequestsClinicVisit[] =
        "I feel kind of nauseous...\r\n"
        "I wonder if I drank too much\r\n"
        "last night?{Press}\p"
        "{NickName}, will you\r\n"
        "take me to the Clinic?{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_KarenThanksPlayerForConcern[] =
        "Thank you.{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_DoctorExplainsKarenIsPregnant[] =
        "Your wife isn't sick.{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_DoctorCongratulatesPlayerAndKaren[] =
        "You're going to be parents.\r\n"
        "Congratulations!{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_ElliCongratulatesKaren[] =
        "Karen, you're going to have \r\n"
        "a baby. Congratulations!{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_KarenRespondsToCongratulations[] =
        "Congratulations!{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_KarenRealizesNauseaWasPregnancyAndStopsDrinking[] =
        "I thought I just had a \r\n"
        "hangover, but I'm pregnant\r\n"
        "instead! Can you believe it?{Press}\p"
        "No more alcohol for me \r\n"
        "from now on, I guess!{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_KarenAnticipatesJeffsReactionAndReturnsHome[] =
        "When I tell my dad about \r\n"
        "this, he's going to cry.\r\n"
        "Let's go home, OK?{Press}";

    const char gText_FamilyEvent_Karen_PregnancyDiscovery_PlayerReflectsOnFatherhood[] =
        "I can't believe I'm about to\r\n"
        "become a father...\r\n"
        "This is so great!{Press}";
};

void EventScript_FamilyEvent_Karen_PregnancyDiscovery(void)
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
    SetEntityPosition(ENTITY_KAREN, X(333), Y(94), FACING_LEFT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_KAREN_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_KarenMistakesNauseaForHangoverAndRequestsClinicVisit);
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
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_KarenThanksPlayerForConcern);
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
    SetEntityPosition(ENTITY_KAREN, X(228), Y(148), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(262), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(262), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_DoctorExplainsKarenIsPregnant);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_QUESTION, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_DoctorCongratulatesPlayerAndKaren);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HEART, FALSE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_ElliCongratulatesKaren);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_KarenRespondsToCongratulations);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_KarenRealizesNauseaWasPregnancyAndStopsDrinking);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_KarenAnticipatesJeffsReactionAndReturnsHome);
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
    MarkNpcSpokenTo(CHARACTER_KAREN);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    AddCharacterLove(CHARACTER_KAREN, 3000);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    AddNpcFriendship(CHARACTER_ELLI, 20);
    VarSet(VAR_KAREN_PREGNANCY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FamilyEvent_Karen_PregnancyDiscovery_PlayerReflectsOnFatherhood);
    TalkClose();
    PlacePlayerAtFarmhouseBed();
    SetGameTime(17, 0);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    return;
}
