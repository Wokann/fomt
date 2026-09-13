#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_ChildInjury_AnnWakesPlayerForEmergency[] =
        "{NickName}！\r\n"
        "大変だよ、はやく起きて！{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_AnnExplainsChildFellFromBed[] =
        "今朝起きたら、{Baby}が\r\n"
        "ベッドから落ちてケガしたん\r\n"
        "だよ！ねぇ、どうしよう？{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_ChildCriesAfterFall[] =
        "わぁぁぁぁぁん！{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_ChoiceAssumeChildIsFine[] =
        "男の子だから大丈夫！";

    const char gText_FamilyEvent_Ann_ChildInjury_ChoiceTakeChildToClinic[] =
        "病院に連れていこう";

    const char gText_FamilyEvent_Ann_ChildInjury_AnnRejectsIgnoringInjury[] =
        "へ？\r\n"
        "何言ってるのよ！大ケガ\r\n"
        "だったらどうするのよっ！{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_AnnTakesChildToClinicAlone[] =
        "わたし、今から病院へ行って\r\n"
        "来るよ！時間なんて、かんけい\r\n"
        "ない！{Press}\p"
        "{Baby}、おいで。{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_DoctorDiagnosesMinorScratch[] =
        "大丈夫だ、かすり傷だよ。\r\n"
        "骨にも異常ないし…{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_AnnExpressesRelief[] =
        "はぁ～、\r\n"
        "よかった…{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_DoctorWarnsParentsToBeCareful[] =
        "しんぱいないよ。\r\n"
        "でも、この時期の子供は動き\r\n"
        "回るから注意して見てあげ{Press}\r\n"
        "なきゃダメだよ。{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_AnnApologizesToChild[] =
        "うん。\r\n"
        "ごめんね、{Baby}。{Press}";

    const char gText_FamilyEvent_Ann_ChildInjury_ChildCallsPlayerDa[] =
        "だぁ。{Press}";
};

void EventScript_FamilyEvent_Ann_ChildInjury(void)
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
    SetEntityPosition(ENTITY_ANN, X(450), Y(100), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
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
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_ChildInjury_AnnWakesPlayerForEmergency);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_ChildInjury_AnnExplainsChildFellFromBed);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
    TalkMessage(gText_FamilyEvent_Ann_ChildInjury_ChildCriesAfterFall);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FamilyEvent_Ann_ChildInjury_ChoiceAssumeChildIsFine, gText_FamilyEvent_Ann_ChildInjury_ChoiceTakeChildToClinic);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_ChildInjury_AnnRejectsIgnoringInjury);
            TalkClose();
            SetEntityFacing(ENTITY_ANN, FACING_DOWN);
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FamilyEvent_Ann_ChildInjury_AnnTakesChildToClinicAlone);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_ANN);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            VarSet(VAR_ANN_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ANN, 3000);
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
            SetEntityPosition(ENTITY_ANN, X(228), Y(148), FACING_RIGHT);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
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
            TalkMessage(gText_FamilyEvent_Ann_ChildInjury_DoctorDiagnosesMinorScratch);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            TalkMessage(gText_FamilyEvent_Ann_ChildInjury_AnnExpressesRelief);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FamilyEvent_Ann_ChildInjury_DoctorWarnsParentsToBeCareful);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_ANN);
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            TalkMessage(gText_FamilyEvent_Ann_ChildInjury_AnnApologizesToChild);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_CHILD);
            SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
            TalkMessage(gText_FamilyEvent_Ann_ChildInjury_ChildCallsPlayerDa);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_ANN);
            MarkNpcSpokenTo(CHARACTER_CHILD);
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
            VarSet(VAR_ANN_CHILD_INJURY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
    }
}
