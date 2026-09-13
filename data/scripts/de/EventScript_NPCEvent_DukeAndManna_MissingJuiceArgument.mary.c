#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaAccusesDukeOfDrinkingWineryStock[] =
        "Du hast unseren Saft\r\n"
        "und Wein getrunken, oder!?!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDeniesDrinkingStock[] =
        "Habe ich nicht!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRevealsBottlesUnderBed[] =
        "Lüg mich nicht an!{Press}\p"
        "Was ist mit den Flaschen\r\n"
        "unter dem Bett!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeHesitatesWhenConfronted[] =
        "Ähm.......\"{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeClaimsHeWasResearchingQuality[] =
        "Ich wollte nur herausfinden,\r\n"
        "ob ich besseren Wein \r\n"
        "machen könnte..{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaChallengesResearchExcuse[] =
        "Herausfinden, wie?{Press}\p"
        "Warum trinkst du dann \r\n"
        "immer davon, wenn \r\n"
        "ich ins Bett gehe?{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDefendsModerateDrinkingAndResentsMonitoring[] =
        "Du musst mich nicht so\r\n"
        "kontrollieren, weißt du!\r\n"
        "Ein bisschen trinken {Press}\r\n"
        "kann nicht schaden!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRecallsPromiseAndAjasDeparture[] =
        "Du hast doch gesagt, dass \r\n"
        "du aufhörst, unsere \r\n"
        "Weine zu trinken!{Press}\p"
        "Du solltest deine Versprechen\r\n"
        "einhalten!{Press}\p"
        "Schließlich ist Aja weg,\r\n"
        "weil du schlechte Laune\r\n"
        "kriegst, wenn du trinkst!{Press}\r\n"
        "Was, wenn Cliff auch\r\n"
        "deshalb geht?{Press}\p"
        "Ich vergebe dir nie!{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeFallsSilent[] =
        "............\r\n"
        "{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaExplainsConcernAndRequestsModeration[] =
        "Ich habe nie gesagt, du \r\n"
        "sollst gar nichts trinken,{Press}\p"
        "Duke. Nur etwas weniger. {Press}\p"
        "Ich mache mir eben Sorgen \r\n"
        "um dich...{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeAgreesToCutBack[] =
        "...OK.{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaForgivesDuke[] =
        "Gut. Ich verzeihe \r\n"
        "dir noch mal.{Press}";
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
