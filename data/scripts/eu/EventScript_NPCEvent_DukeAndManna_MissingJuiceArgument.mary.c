#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaAccusesDukeOfDrinkingWineryStock[] =
        "You've been drinking \r\n"
        "our juice and wine\r\n"
        "again, haven't you!?!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDeniesDrinkingStock[] =
        "I have not!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRevealsBottlesUnderBed[] =
        "Don't lie to me!{Press}\p"
        "What about those bottles \r\n"
        "under the bed!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeHesitatesWhenConfronted[] =
        "Err.......\"{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeClaimsHeWasResearchingQuality[] =
        "I just wanted to research\r\n"
        "if I could make them \r\n"
        "better, that's all...{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaChallengesResearchExcuse[] =
        "Research, huh?{Press}\p"
        "Then why do you drink\r\n"
        "from it every time \r\n"
        "I go to bed? {Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDefendsModerateDrinkingAndResentsMonitoring[] =
        "You don't have to check up\r\n"
        "on me so much, you know!\r\n"
        "It's OK to drink a little, \r\n"
        "isn't it!?{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRecallsPromiseAndAjasDeparture[] =
        "You were the one who said\r\n"
        "you'd stop drinking\r\n"
        "our sales!{Press}\p"
        "You should keep your own\r\n"
        "promises!{Press}\p"
        "After all, Aja left because\r\n"
        "you can’t keep your\r\n"
        "promises!{Press}\p"
        "What if Cliff left for the\r\n"
        "same reason? {Press}\p"
        "I'd never forgive you!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeFallsSilent[] =
        "............\r\n"
        "{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaExplainsConcernAndRequestsModeration[] =
        "I never said I wanted you \r\n"
        "not to drink at all, Duke. {Press}\p"
        "I just wanted you to cut \r\n"
        "back a little, that's all. {Press}\p"
        "I'm just because I worry \r\n"
        "about you, that's all...{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeAgreesToCutBack[] =
        "...OK.{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaForgivesDuke[] =
        "Good. I'll forgive you \r\n"
        "this time.{Press}";
};

void EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument(void)
{
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MANNA, X(88), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(108), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(80), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaAccusesDukeOfDrinkingWineryStock);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDeniesDrinkingStock);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRevealsBottlesUnderBed);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeHesitatesWhenConfronted);
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeClaimsHeWasResearchingQuality);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaChallengesResearchExcuse);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDefendsModerateDrinkingAndResentsMonitoring);
    TalkClose();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRecallsPromiseAndAjasDeparture);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeFallsSilent);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaExplainsConcernAndRequestsModeration);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeAgreesToCutBack);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaForgivesDuke);
    TalkClose();
    PanCameraTo(X(120), Y(208), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    VarSet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_MANNA, EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupMannaDialogue);
    SetEntityEventScript(ENTITY_DUKE, EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupDukeDialogue);
    return;
}
