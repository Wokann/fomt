#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysSaibaraEntrustsHimWithRealWork[] =
        "In letzter Zeit lässt Opa\r\n"
        "mich endlich \r\n"
        "richtige Arbeit tun. {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryCongratulatesGray[] =
        "Das ist toll! {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeOnlyHandlesSmallItems[] =
        "Nur kleine Dinge...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MarySaysThatIsStillProgress[] =
        "Trotzdem gut, oder?{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayRespondsUncertainly[] =
        "Ja, schon...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAsksWhatIsWrong[] =
        "...?\r\n"
        "Was ist los?{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayCreditsMaryForHisProgress[] =
        "Ich habe gerade  gedacht, \r\n"
        "dass ich dir alles verdanke.{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MarySaysSheDidNothing[] =
        "Mir? Aber ich habe \r\n"
        "doch nichts getan! {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysSummitAdviceHelpedIdentifyHisProblem[] =
        "Mit dir auf dem Gipfel des\r\n"
        "Berges zu sprechen, hat\r\n"
        "mir die Augen geöffnet, was{Press}\r\n"
        "mit mir los war.{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryIsGladHerAdviceHelped[] =
        "Oh, ja...\r\n"
        "Freut mich, dass ich \r\n"
        "dir helfen konnte...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeMightHaveGivenUpWithoutMary[] =
        "Wenn du das nicht gesagt\r\n"
        "hättest, hätte ich\r\n"
        "vielleicht aufgegeben!{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayPlansToTellMarySomethingAfterPassingSaibarasSkillTest[] =
        "Saibara sagte, er würde\r\n"
        "mein Talent testen. {Press}\p"
        "Wenn ich das bestehe-\r\n"
        "möchte ich dich was fragen.{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAsksWhatGrayWantsToSay[] =
        "Was ist es!?{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeMustPassFirstAndRetractsQuestion[] =
        "Ich muss erst den Test \r\n"
        "bestehen! Vergiss es...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAcceptsWaiting[] =
        "Wenn du es sagst...{Press}";
};

void EventScript_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise(void)
{
    ChangeMap(MAP_LIBRARY_1F, X(120), Y(80));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_GRAY, X(104), Y(68), FACING_RIGHT);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_MARY, X(136), Y(68), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysSaibaraEntrustsHimWithRealWork);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryCongratulatesGray);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeOnlyHandlesSmallItems);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MarySaysThatIsStillProgress);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayRespondsUncertainly);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAsksWhatIsWrong);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayCreditsMaryForHisProgress);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MarySaysSheDidNothing);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysSummitAdviceHelpedIdentifyHisProblem);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryIsGladHerAdviceHelped);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeMightHaveGivenUpWithoutMary);
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayPlansToTellMarySomethingAfterPassingSaibarasSkillTest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAsksWhatGrayWantsToSay);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_SHY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeMustPassFirstAndRetractsQuestion);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAcceptsWaiting);
    TalkClose();
    PanCameraTo(X(120), Y(144), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_MARY, EventScript_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_FollowupMaryDialogue);
    SetEntityEventScript(ENTITY_GRAY, EventScript_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_FollowupGrayDialogue);
    VarSet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
