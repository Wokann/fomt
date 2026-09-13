#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KaiThanksRickForWithholdingObjections[] =
        "Rick, danke, dass du \r\n"
        "Popuri und mich\r\n"
        "heiraten lassen hast. {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_PopuriThanksRick[] =
        "Ja, danke dir!{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_RickBeginsToRestateObjection[] =
        "Also, ich bin immer noch...{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KarenInterruptsRick[] =
        "Rick!{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_RickRelents[] =
        "Ok...{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KarenAsksKaiToMakePopuriHappy[] =
        "Mach Popuri glücklich, Kai.{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KaiPromisesToMakePopuriHappy[] =
        "Ich tue mein Bestes. \r\n"
        "Versprochen. {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_CarterInvitesPlayerToCelebrateWedding[] =
        "Hey, {Player}!\r\n"
        "Heute ist Popuris und \r\n"
        "Kais Hochzeitstag!{Press}\p"
        "Willst du mit uns bis \r\n"
        "in den Morgen feiern?{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_ChoiceCelebrateWedding[] =
        "Ok!";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_ChoiceKeepWorking[] =
        "Ich muss arbeiten.";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_CarterBeginsWeddingCelebration[] =
        "Feiern wir!{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_GuestsToastNewlyweds[] =
        "Auf das neue Paar!{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_CarterInvitesPlayerToJoinLater[] =
        "Mach einfach mit, wenn \r\n"
        "du Zeit hast. {Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice(void)
{
    int var_0;
    ChangeMap(MAP_CHURCH, X(184), Y(320));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_WEDDING);
    SetEntityPosition(ENTITY_POPURI, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_IDLE);
    SetEntityPosition(ENTITY_KAI, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(144), Y(152), FACING_RIGHT);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_LILLIA, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(296), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
    }
    if (GetEntityLocation(ENTITY_DUKE) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DUKE);
    }
    if (GetEntityLocation(ENTITY_MANNA) == MAP_CHURCH)
    {
        HideEntity(ENTITY_MANNA);
    }
    if (VarGet(VAR_POPURI_KAI_WEDDING_ATTENDANCE_DEFERRED) == FALSE)
    {
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        PanCameraTo(X(184), Y(160), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
        WaitForCameraMovement();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KaiThanksRickForWithholdingObjections);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_PopuriThanksRick);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_SURPRISED);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_RickBeginsToRestateObjection);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KarenInterruptsRick);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_RickRelents);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KarenAsksKaiToMakePopuriHappy);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_KaiPromisesToMakePopuriHappy);
        TalkClose();
        SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_CarterInvitesPlayerToCelebrateWedding);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_ChoiceCelebrateWedding, gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_ChoiceKeepWorking);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                AddNpcFriendship(CHARACTER_CARTER, 20);
                AddNpcFriendship(CHARACTER_LILLIA, 20);
                AddNpcFriendship(CHARACTER_RICK, 20);
                AddNpcFriendship(CHARACTER_KAREN, 20);
                SetNpcFriendship(CHARACTER_POPURI, 200);
                SetNpcFriendship(CHARACTER_KAI, 200);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_CarterBeginsWeddingCelebration);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_GuestsToastNewlyweds);
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                VarSet(VAR_POPURI_KAI_WEDDING_MISSED, FALSE);
                VarSet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                break;
            case CHOICE_OPTION_2:
                VarSet(VAR_POPURI_KAI_WEDDING_ATTENDANCE_DEFERRED, TRUE);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceChoice_CarterInvitesPlayerToJoinLater);
                TalkClose();
                SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
                PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
                WaitForCameraMovement();
                EnableScriptedNpcControl();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                SetEntityEventScript(ENTITY_RICK, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupRickDialogue);
                SetEntityEventScript(ENTITY_POPURI, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue);
                SetEntityEventScript(ENTITY_LILLIA, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue);
                SetEntityEventScript(ENTITY_KAREN, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKarenDialogue);
                SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice);
                SetEntityEventScript(ENTITY_KAI, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue);
                VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                break;
        }
    }
    else
    {
        EnableScriptedNpcControl();
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        SetEntityEventScript(ENTITY_RICK, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupRickDialogue);
        SetEntityEventScript(ENTITY_POPURI, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue);
        SetEntityEventScript(ENTITY_LILLIA, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue);
        SetEntityEventScript(ENTITY_KAREN, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKarenDialogue);
        SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice);
        SetEntityEventScript(ENTITY_KAI, EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue);
        VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
    }
}
