#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_ChildInjury_KarenWakesPlayerForEmergency[] =
        "{NickName}、起きて！！\r\n"
        "ねぇ、起きてってば！{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_KarenExplainsChildFellFromBed[] =
        "どうしよう、今朝起きたら、\r\n"
        "{Baby}がベッドから\r\n"
        "落ちてケガしたんだ。{Press}\p"
        "どうしたらいいと思う？{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_ChildCriesAfterFall[] =
        "わぁぁぁぁぁん！{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_ChoiceAssumeChildIsFine[] =
        "男の子だから大丈夫！";

    const char gText_FamilyEvent_Karen_ChildInjury_ChoiceTakeChildToClinic[] =
        "病院に連れていこう";

    const char gText_FamilyEvent_Karen_ChildInjury_KarenRebukesPlayerForIgnoringInjury[] =
        "はぁ？何言ってるのよ！\r\n"
        "{NickName}は{Baby}が\r\n"
        "心配じゃないの？{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_KarenTakesChildToClinicAlone[] =
        "ちょっと、病院行ってくる！\r\n"
        "ドクターの事、たたき起こして\r\n"
        "くるわ！{Press}\p"
        "{Baby}、行くわよ。{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_DoctorDiagnosesMinorScratch[] =
        "大丈夫だ、かすり傷だよ。\r\n"
        "骨にも異常ないし…{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_KarenExpressesRelief[] =
        "は、…よかったぁ。{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_DoctorWarnsParentsToBeCareful[] =
        "しんぱいないよ。\r\n"
        "でも、この時期の子供は動き\r\n"
        "回るから注意して見てあげ{Press}\r\n"
        "なきゃダメだよ。{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_KarenApologizesToChild[] =
        "そうよね。\r\n"
        "ごめんね。{Baby}。{Press}";

    const char gText_FamilyEvent_Karen_ChildInjury_ChildCallsPlayerDa[] =
        "だぁ。{Press}";
};

void EventScript_FamilyEvent_Karen_ChildInjury(void)
{
    int var_0;
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    ChangeMap(MAP_FARMHOUSE, X(400), Y(100));
    SetEntityPosition(ENTITY_PLAYER, X(400), Y(100), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(450), Y(100), FACING_LEFT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_CHILD, X(432), Y(100), FACING_LEFT);
    if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    }
    else
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_ChildInjury_KarenWakesPlayerForEmergency);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_ChildInjury_KarenExplainsChildFellFromBed);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
    TalkMessage(gText_FamilyEvent_Karen_ChildInjury_ChildCriesAfterFall);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Karen_ChildInjury_ChoiceAssumeChildIsFine, gText_FamilyEvent_Karen_ChildInjury_ChoiceTakeChildToClinic);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_ChildInjury_KarenRebukesPlayerForIgnoringInjury);
            TalkClose();
            SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_ChildInjury_KarenTakesChildToClinicAlone);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            VarSet(VAR_KAREN_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_KAREN, 3000);
            AddNpcFriendship(CHARACTER_CHILD, 20);
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
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
            SetEntityPosition(ENTITY_DOCTOR, X(262), Y(124), FACING_LEFT);
            SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
            SetEntityPosition(ENTITY_CHILD, X(262), Y(148), FACING_LEFT);
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
            }
            else
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FamilyEvent_Karen_ChildInjury_DoctorDiagnosesMinorScratch);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            TalkMessage(gText_FamilyEvent_Karen_ChildInjury_KarenExpressesRelief);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FamilyEvent_Karen_ChildInjury_DoctorWarnsParentsToBeCareful);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            TalkMessage(gText_FamilyEvent_Karen_ChildInjury_KarenApologizesToChild);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_CHILD);
            SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
            TalkMessage(gText_FamilyEvent_Karen_ChildInjury_ChildCallsPlayerDa);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            VarSet(VAR_KAREN_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
