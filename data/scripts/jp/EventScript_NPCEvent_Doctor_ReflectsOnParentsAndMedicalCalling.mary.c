#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorSaysHeWasThinkingAboutParents[] =
        "やあ、キミか…\r\n"
        "元気が無いって？{Press}\p"
        "ああ、ちょっと両親のことを\r\n"
        "考えていたんだ。{Press}";

    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorExplainsFamilyMedicalProfession[] =
        "ボクの家系は代々医者でね。\r\n"
        "父も医者だったんだよ。\r\n"
        "母は看護婦をやっていたんだ。{Press}";

    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorRecallsLonelinessAndResentingParentsWork[] =
        "うちの病院はいそがしくてね。{Press}\p"
        "子供のころ、\r\n"
        "両親がかまってくれなくて\r\n"
        "さみしかったんだよ。{Press}\p"
        "医者って職業を恨んだことさえ\r\n"
        "あった…\r\n"
        "親に反抗したりもしたよ。{Press}";

    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_DoctorUnderstandsParentsAfterBecomingDoctor[] =
        "でも、こうやって\r\n"
        "同じ職業についてみると\r\n"
        "その時の両親の心境が{Press}\r\n"
        "わかったんだよ。{Press}\p"
        "命をあずかる者の\r\n"
        "大変さなんかがね。{Press}\p"
        "少しでも、その時の気持ちを\r\n"
        "わかってあげられたら\r\n"
        "反抗なんてバカなことは{Press}\r\n"
        "しなかっただろうな。{Press}";
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
