#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhyDoctorCalledHerToTheBeach[] =
        "Doktor, warum hast du\r\n"
        "mich gerufen?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorHesitatesToSpeak[] =
        "Ähm... Mal sehen...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliPromptsDoctor[] =
        "Doktor?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysHeHasNeverDoneThisBefore[] =
        "Ich habe das noch \r\n"
        "nie getan...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorMeans[] =
        "Was getan...?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksAboutEllensLegs[] =
        "Wie geht es deiner Oma?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliExplainsDailyMassageAndHopeForEllensRecovery[] =
        "Ich versuche, ihre Beine \r\n"
        "täglich zu massieren. Das\r\n"
        "hilft etwas...{Press}\p"
        "Ich hoffe immer noch, \r\n"
        "sie ganz zu heilen!{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorConfessesHeFellInLoveWithEllisStrength[] =
        "Elli, du bist so stark...\r\n"
        "Ich glaube, deshalb \r\n"
        "habe ich mich verliebt...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorJustSaid[] =
        "...W-was sagst du da?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksElliToStayAndRunTheClinicWithHim[] =
        "Elli. Ich will, dass  \r\n"
        "du immer bei mir bleibst. \r\n"
        "Ohne dich wäre ich nichts.{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhetherDoctorReallyMeansHer[] =
        "Meinst... meinst du echt?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysOnlyElliWillDo[] =
        "Ja. Ich will, dass du \r\n"
        "bei mir bleibst... \r\n"
        "für immer!{Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(240), Y(334));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLI, X(240), Y(348), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(240), Y(312), FACING_RIGHT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    if (GetEntityLocation(ENTITY_KAREN) == MAP_MINERAL_BEACH)
    {
        HideEntity(ENTITY_KAREN);
    }
    if (GetEntityLocation(ENTITY_KAI) == MAP_MINERAL_BEACH)
    {
        HideEntity(ENTITY_KAI);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityFacing(ENTITY_ELLI, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhyDoctorCalledHerToTheBeach);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorHesitatesToSpeak);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliPromptsDoctor);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysHeHasNeverDoneThisBefore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorMeans);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksAboutEllensLegs);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliExplainsDailyMassageAndHopeForEllensRecovery);
    TalkClose();
    StartEntityEffect(ENTITY_DOCTOR, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorConfessesHeFellInLoveWithEllisStrength);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorJustSaid);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksElliToStayAndRunTheClinicWithHim);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhetherDoctorReallyMeansHer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysOnlyElliWillDo);
    TalkClose();
    PanCameraTo(X(24), Y(280), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_FollowupDoctorDialogue);
    SetEntityEventScript(ENTITY_ELLI, EventScript_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_FollowupElliDialogue);
    VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
