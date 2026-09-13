#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRemarksOnSashaAndJeffsLongMarriage[] =
        "Du und Jeff, ihr seid \r\n"
        "schon lange verheiratet,\r\n"
        "oder?{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaConfirmsLongMarriage[] =
        "Ja. {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaAndJeffWereChildhoodFriends[] =
        "Ihr kennt euch, seid ihr\r\n"
        "Kinder wart, richtig?{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffAlwaysDependedOnHer[] =
        "Ja... Jeff konnte nie \r\n"
        "etwas ohne mich tun. {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsJeffAlwaysStayedBehindSasha[] =
        "Er hat an dir gehangen,\r\n"
        "als wir Kinder waren, \r\n"
        "oder?{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffHidingBehindHerWhenScared[] =
        "Er hatte immer Angst\r\n"
        "ohne mich...{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaProtectingJeffFromDuke[] =
        "Ha ha... Er ist immer zu\r\n"
        "dir gekommen, wenn Duke \r\n"
        "ihn geärgert hat, stimmt's?{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsStandingUpToDukeForJeff[] =
        "Das stimmt! Jeff wusste nie,\r\n"
        "wie er sich Duke gegenüber\r\n"
        "verteidigen sollte...{Press}\p"
        "Darum ist er dann \r\n"
        "zu mir gerannt...{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaAppreciatesJeffAsHusbandAndFather[] =
        "Trotzdem... Ich bin ihm\r\n"
        "dankbar für alles.{Press}\p"
        "Er war ein toller Mann\r\n"
        "und guter Vater für Karen.{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaTeasesSashaForSentimentalStory[] =
        "Uhu, danke für die \r\n"
        "interessante Geschichte.{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRespondsToLilliasTeasing[] =
        "Jederzeit. \r\n"
        "Aha ha ha! {Press}";
};

void EventScript_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage(void)
{
    ChangeMap(MAP_POULTRY_FARM_HOUSE_1F, X(161), Y(87));
    SetEntityPosition(ENTITY_LILLIA, X(208), Y(79), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(190), Y(79), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRemarksOnSashaAndJeffsLongMarriage);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaConfirmsLongMarriage);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaAndJeffWereChildhoodFriends);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffAlwaysDependedOnHer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsJeffAlwaysStayedBehindSasha);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffHidingBehindHerWhenScared);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaProtectingJeffFromDuke);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsStandingUpToDukeForJeff);
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaAppreciatesJeffAsHusbandAndFather);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaTeasesSashaForSentimentalStory);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRespondsToLilliasTeasing);
    TalkClose();
    EnableScriptedNpcControl();
    PanCameraTo(X(120), Y(208), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_SASHA, EventScript_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupSashaDialogue);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue);
}
