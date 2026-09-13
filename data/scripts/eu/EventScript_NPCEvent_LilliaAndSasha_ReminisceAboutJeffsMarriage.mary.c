#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRemarksOnSashaAndJeffsLongMarriage[] =
        "You and Jeff have been \r\n"
        "married a long time, \r\n"
        "haven't you? {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaConfirmsLongMarriage[] =
        "Yes. {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaAndJeffWereChildhoodFriends[] =
        "You've known each other\r\n"
        "since you were kids, right?{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffAlwaysDependedOnHer[] =
        "Yeah...Jeff never used to be\r\n"
        "able to do anything without \r\n"
        "me!{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsJeffAlwaysStayedBehindSasha[] =
        "He used to cling to you\r\n"
        "when we were kids, \r\n"
        "didn't he? {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffHidingBehindHerWhenScared[] =
        "He was always scared\r\n"
        "of things without me...{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaProtectingJeffFromDuke[] =
        "Ha ha...He used to run\r\n"
        "to you when Duke bullied \r\n"
        "him too, didn't he? {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsStandingUpToDukeForJeff[] =
        "That's right! Jeff never\r\n"
        "knew how to stand up for\r\n"
        "himself to Duke...{Press}\p"
        "That's why he came \r\n"
        "running to me...{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaAppreciatesJeffAsHusbandAndFather[] =
        "Still, I am grateful to him\r\n"
        "for everything.{Press}\p"
        "He's been a great husband\r\n"
        "and a great dad to Karen.{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaTeasesSashaForSentimentalStory[] =
        "Huh, thanks for the mushy.\r\n"
        "story. Hee hee hee! {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRespondsToLilliasTeasing[] =
        "Come by any time. {Press}";
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
