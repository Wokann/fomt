#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhyDoctorCalledHerToTheBeach[] =
        "どうしたんですか？\r\n"
        "こんなところに\r\n"
        "よびだしたりして。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorHesitatesToSpeak[] =
        "ああ…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliPromptsDoctor[] =
        "ドクター？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysHeHasNeverDoneThisBefore[] =
        "いや…困ったな。\r\n"
        "こんなこと言うのは、\r\n"
        "はじめてで…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorMeans[] =
        "？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksAboutEllensLegs[] =
        "エリィ、エレンさんの\r\n"
        "足の具合はどうだい？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliExplainsDailyMassageAndHopeForEllensRecovery[] =
        "マッサージとか色々\r\n"
        "ためしてるんですけどね。{Press}\p"
        "こればっかりは根気よく\r\n"
        "続けないと…\r\n"
        "あきらめちゃダメですもんね。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorConfessesHeFellInLoveWithEllisStrength[] =
        "キミは強いなぁ…\r\n"
        "そんなキミだからこそ、ボクは\r\n"
        "好きになったのかもしれない…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhatDoctorJustSaid[] =
        "え？今、なんて…{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorAsksElliToStayAndRunTheClinicWithHim[] =
        "エリィ、ボクはキミとずっと\r\n"
        "病院をやっていきたい。{Press}\p"
        "キミの強さがボクには\r\n"
        "必要なんだ。{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_ElliAsksWhetherDoctorReallyMeansHer[] =
        "わたしでいいんですか？{Press}";

    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_DoctorSaysOnlyElliWillDo[] =
        "ああ、\r\n"
        "キミじゃないとダメなんだ。{Press}";
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
