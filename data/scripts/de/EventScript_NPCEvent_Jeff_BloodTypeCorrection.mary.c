#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffRejectsCorrectedBloodType[] =
        "Was?!\r\n"
        "Das muss ein Fehler sein!{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorConfirmsNewResultIsCorrect[] =
        "Es ist diesmal kein Fehler.{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffReactsToYearsOfWrongBelief[] =
        "Ich fasse nicht, dass\r\n"
        "in all diesen Jahren...{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorAdvisesJeffToAcceptResult[] =
        "So sind die Dinge eben.\r\n"
        "Du solltest es besser \r\n"
        "hinnehmen...{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffFallsSilent[] =
        ".......{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorAsksPlayerWhatIsWrong[] =
        "Was ist los, \r\n"
        "{Player}?{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorApologizesPlayerOverheard[] =
        "Hast du uns aus dem\r\n"
        "Wartezimmer gehört?\r\n"
        "Sorry...{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorExplainsImportantDiscoveryAboutJeff[] =
        "Siehst du, heute haben\r\n"
        "wir etwas Wichtiges \r\n"
        "über Jeff erfahren. {Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffExplainsEarlierBloodTypeResultWasWrong[] =
        "Vor langer Zeit habe ich\r\n"
        "beim Doktor mein Blut \r\n"
        "testen lassen und jetzt{Press}\r\n"
        "sagt er mir, es wär falsch!{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorApologizesForClericalError[] =
        "Es tut mir so leid.\r\n"
        "Muss eine Art Schreib-\r\n"
        "fehler gewesen sein. {Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffSaysOldBloodTypeSeemedToFitPersonality[] =
        "Und ich dachte, dass meine\r\n"
        "Blutgruppe so gut \r\n"
        "zu mir passt...{Press}";
};

void EventScript_NPCEvent_Jeff_BloodTypeCorrection(void)
{
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(184), Y(320));
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(250), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_JeffRejectsCorrectedBloodType);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(264), Y(137));
    SetEntityPosition(ENTITY_JEFF, X(233), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(260), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(220), Y(260), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorConfirmsNewResultIsCorrect);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_JeffReactsToYearsOfWrongBelief);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorAdvisesJeffToAcceptResult);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_JeffFallsSilent);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(151), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorAsksPlayerWhatIsWrong);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorApologizesPlayerOverheard);
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorExplainsImportantDiscoveryAboutJeff);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_JeffExplainsEarlierBloodTypeResultWasWrong);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorApologizesForClericalError);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_JeffSaysOldBloodTypeSeemedToFitPersonality);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_JEFF);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    EnableScriptedNpcControl();
    PanCameraTo(X(220), Y(151), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_NPCEvent_Jeff_BloodTypeCorrection_FollowupDoctorDialogue);
    SetEntityEventScript(ENTITY_JEFF, EventScript_NPCEvent_Jeff_BloodTypeCorrection_FollowupJeffDialogue);
    SetEntityEventScript(ENTITY_ELLI, EventScript_NPCEvent_Jeff_BloodTypeCorrection_FollowupElliDialogue);
}
