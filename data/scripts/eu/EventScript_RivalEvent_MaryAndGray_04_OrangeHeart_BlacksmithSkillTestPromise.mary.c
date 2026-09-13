#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysSaibaraEntrustsHimWithRealWork[] =
        "Lately Gramps is finally\r\n"
        "letting me do some \r\n"
        "real work. {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryCongratulatesGray[] =
        "That's great! {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeOnlyHandlesSmallItems[] =
        "Well, just small things...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MarySaysThatIsStillProgress[] =
        "That's still good, right?{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayRespondsUncertainly[] =
        "I guess...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAsksWhatIsWrong[] =
        "...?\r\n"
        "What's wrong?{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayCreditsMaryForHisProgress[] =
        "I was just thinking that \r\n"
        "I owe everything to you. {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MarySaysSheDidNothing[] =
        "Me? But I haven't \r\n"
        "done anything! {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysSummitAdviceHelpedIdentifyHisProblem[] =
        "Talking to you on the peak\r\n"
        "of the mountain made me\r\n"
        "realize what's wrong {Press}\r\n"
        "with me.{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryIsGladHerAdviceHelped[] =
        "Oh yeah...\r\n"
        "I'm glad anything I said \r\n"
        "was useful...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeMightHaveGivenUpWithoutMary[] =
        "If you hadn't said that,\r\n"
        "then I might have given up!{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GrayPlansToTellMarySomethingAfterPassingSaibarasSkillTest[] =
        "Saibara said he would give \r\n"
        "me a test on my skills. {Press}\p"
        "If I pass it, there's some-\r\n"
        "thing I want to ask you. {Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAsksWhatGrayWantsToSay[] =
        "What is it!?{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_GraySaysHeMustPassFirstAndRetractsQuestion[] =
        "I have to pass the test \r\n"
        "first! Forget I said it...{Press}";

    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_MaryAcceptsWaiting[] =
        "If you say so...{Press}";
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
