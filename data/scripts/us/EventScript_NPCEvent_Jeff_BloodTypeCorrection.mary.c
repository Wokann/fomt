#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffRejectsCorrectedBloodType[] =
        "What!\r\n"
        "This must be a mistake...!{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorConfirmsNewResultIsCorrect[] =
        "It's no mistake this time.{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffReactsToYearsOfWrongBelief[] =
        "I can't believe that\r\n"
        "for all these years...{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorAdvisesJeffToAcceptResult[] =
        "Things are the way they are.\r\n"
        "You might as well \r\n"
        "accept it...{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffFallsSilent[] =
        ".......{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorAsksPlayerWhatIsWrong[] =
        "What's wrong, \r\n"
        "{Player}? {Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorApologizesPlayerOverheard[] =
        "You heard us from \r\n"
        "the waiting room? \r\n"
        "Sorry...{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorExplainsImportantDiscoveryAboutJeff[] =
        "You see, today we found\r\n"
        "out something very \r\n"
        "important about Jeff. {Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffExplainsEarlierBloodTypeResultWasWrong[] =
        "A long time ago I had the \r\n"
        "Doctor check my blood \r\n"
        "type, but now he tells me{Press}\r\n"
        "it's wrong!{Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_DoctorApologizesForClericalError[] =
        "I'm terribly sorry. \r\n"
        "It must have been some \r\n"
        "kind of clerical error. {Press}";

    const char gText_NPCEvent_Jeff_BloodTypeCorrection_JeffSaysOldBloodTypeSeemedToFitPersonality[] =
        "And I used to think that \r\n"
        "my blood type fit my \r\n"
        "personality so well...{Press}";
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
