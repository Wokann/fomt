#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorSaysHeWasThinkingAboutParents[] =
        "Hi there.\r\n"
        "I look kind of down? {Press}\p"
        "I was just remembering\r\n"
        "my parents, you see. {Press}";

    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorExplainsFamilyMedicalProfession[] =
        "My family have always been \r\n"
        "doctors. My father was a \r\n"
        "doctor and my mother {Press}\r\n"
        "a nurse. {Press}";

    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorRecallsLonelinessAndResentingParentsWork[] =
        "They were so busy that they \r\n"
        "didn't have much time for\r\n"
        "me when I was a child. {Press}\p"
        "I was lonely, and I blamed \r\n"
        "them for not paying \r\n"
        "enough attention to me. {Press}";

    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorUnderstandsParentsAfterBecomingDoctor[] =
        "But, now that I'm a doctor\r\n"
        "myself, I understand them\r\n"
        "much better. {Press}\p"
        "It's a sacred duty, being \r\n"
        "responsible for someone's\r\n"
        "life! {Press}\p"
        "Now I wish I hadn't \r\n"
        "rebelled against them so \r\n"
        "much! What a fool I was!...{Press}";
};

void EventScript_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling(void)
{
    ChangeMap(MAP_MOTHERS_HILL_MIDDLE, X(422), Y(584));
    SetEntityPosition(ENTITY_PLAYER, X(612), Y(584), FACING_LEFT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOCTOR, X(422), Y(556), FACING_UP);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    if (GetEntityLocation(ENTITY_GOTZ) == MAP_MOTHERS_HILL_MIDDLE)
    {
        HideEntity(ENTITY_GOTZ);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityXTo(ENTITY_PLAYER, X(422), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        MoveEntityXTo(ENTITY_PLAYER, X(422), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_DOCTOR, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorSaysHeWasThinkingAboutParents);
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    TalkMessage(gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorExplainsFamilyMedicalProfession);
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
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorRecallsLonelinessAndResentingParentsWork);
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    TalkMessage(gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorUnderstandsParentsAfterBecomingDoctor);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    EnableScriptedNpcControl();
    VarSet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_FollowupDoctorDialogue);
}
