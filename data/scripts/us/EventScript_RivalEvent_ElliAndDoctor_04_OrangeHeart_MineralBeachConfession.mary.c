#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhyDoctorCalledHerToTheBeach[] =
        "Doctor, is there some reason\r\n"
        "you asked for me? {Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorHesitatesToSpeak[] =
        "Ahem...Um...Let's see...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliPromptsDoctor[] =
        "Doctor...?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysHeHasNeverDoneThisBefore[] =
        "I've never done this \r\n"
        "before, you see...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorMeans[] =
        "Done what...?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksAboutEllensLegs[] =
        "...How is your grandmother?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliExplainsDailyMassageAndHopeForEllensRecovery[] =
        "I'm trying to massage her\r\n"
        "legs everyday. That makes\r\n"
        "it a little better...{Press}\p"
        "I still hope to heal her\r\n"
        "completely, though!{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorConfessesHeFellInLoveWithEllisStrength[] =
        "Elli, you are so strong...\r\n"
        "I think that's why I \r\n"
        "fell in love with you...{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorJustSaid[] =
        "...Wh-what did you just say?{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksElliToStayAndRunTheClinicWithHim[] =
        "Elli. I want you to stay \r\n"
        "with me always. I couldn't \r\n"
        "do anything without you. {Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhetherDoctorReallyMeansHer[] =
        "You...you really mean it? {Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysOnlyElliWillDo[] =
        "Yes. I want you by my \r\n"
        "side... always. {Press}";
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
