#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliAsksDoctorAboutStudyMaterial[] =
        "I don't understand this \r\n"
        "part here...{Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorExplainsStudyMaterial[] =
        "This? It's just like \r\n"
        "this, see...?{Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliThanksDoctorForExplanation[] =
        "I see now! \r\n"
        "Thanks, Doctor!{Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorOffersFurtherHelp[] =
        "Just ask me anything \r\n"
        "you don't understand. {Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliPraisesDoctorsKindness[] =
        "You're so kind. {Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorGreetsPlayer[] =
        "Hi, there. {Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliGreetsPlayer[] =
        "How are you, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliExplainsStudyingMedicineToHealEllen[] =
        "What am I studying? \r\n"
        "I'm studying medicine to try\r\n"
        "to figure out how to heal{Press}\r\n"
        "my grandmother's legs. {Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ChoiceEncourageElli[] =
        "You can do it!";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ChoiceSuggestLargeHospital[] =
        "Put her in a big hospital.";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliVowsNeverToGiveUp[] =
        "Thanks for saying so!\r\n"
        "I'll never give up!{Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorExpressesConfidenceInElli[] =
        "I have confidence \r\n"
        "in you, Elli.{Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliThanksForSupport[] =
        "Thanks!{Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliRefusesHospitalBecauseEllenWantsToStay[] =
        "But Grandma doesn't want \r\n"
        "to leave Mineral Town!\r\n"
        "I could never send her {Press}\r\n"
        "away...She'd be so sad!{Press}";

    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorReassuresElliThereIsNoNeedToRush[] =
        "No need to rush, Elli. \r\n"
        "You'll do it eventually. {Press}";
};

void EventScript_NPCEvent_Elli_StudiesMedicineForEllensLegs(void)
{
    int var_0;
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(264), Y(137));
    SetEntityPosition(ENTITY_ELLI, X(233), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
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
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliAsksDoctorAboutStudyMaterial);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorExplainsStudyMaterial);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliThanksDoctorForExplanation);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorOffersFurtherHelp);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliPraisesDoctorsKindness);
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
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliGreetsPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliExplainsStudyingMedicineToHealEllen);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ChoiceEncourageElli, gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ChoiceSuggestLargeHospital);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ELLI);
            }
            TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliVowsNeverToGiveUp);
            TalkClose();
            SetEntityFacing(ENTITY_DOCTOR, FACING_LEFT);
            WaitFrames(30);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorExpressesConfidenceInElli);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
            WaitFrames(30);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliThanksForSupport);
            TalkClose();
            AddNpcFriendship(CHARACTER_ELLI, 20);
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_ELLI);
            }
            TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliRefusesHospitalBecauseEllenWantsToStay);
            TalkClose();
            SetEntityFacing(ENTITY_DOCTOR, FACING_LEFT);
            WaitFrames(30);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_DoctorReassuresElliThereIsNoNeedToRush);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
            WaitFrames(30);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_ElliThanksForSupport);
            TalkClose();
            AddNpcFriendship(CHARACTER_ELLI, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_DOCTOR, mary_negated_int(-10));
            break;
    }
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    EnableScriptedNpcControl();
    PanCameraTo(X(220), Y(151), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_NPCEvent_Elli_StudiesMedicineForEllensLegs_FollowupDoctorDialogue);
    SetEntityEventScript(ENTITY_ELLI, EventScript_NPCEvent_Elli_StudiesMedicineForEllensLegs_FollowupElliDialogue);
}
