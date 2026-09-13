#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRemarksOnSashaAndJeffsLongMarriage[] =
        "サーシャのところも\r\n"
        "結婚して長いわね～。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaConfirmsLongMarriage[] =
        "そうね。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaAndJeffWereChildhoodFriends[] =
        "もっとも、ジェフとサーシャは\r\n"
        "幼なじみだから{Press}\p"
        "付き合いって生まれたときから\r\n"
        "じゃな～い？{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffAlwaysDependedOnHer[] =
        "そうなるわね。昔っから、\r\n"
        "ジェフはわたしがいないと\r\n"
        "何も出来なかったからね。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsJeffAlwaysStayedBehindSasha[] =
        "そうよねぇ～。\r\n"
        "ジェフって、サーシャの後ろに\r\n"
        "いっつもいたわねぇ～。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsJeffHidingBehindHerWhenScared[] =
        "そうそう、何かあったら\r\n"
        "わたしの後ろで\r\n"
        "ビクビクしてるの。{Press}\r\n"
        "なんだか、かわいくってね。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaRecallsSashaProtectingJeffFromDuke[] =
        "うふふ…ジェフがデュークに\r\n"
        "いじめられると\r\n"
        "サーシャが飛び出して、{Press}\r\n"
        "助けにいってたわよね～。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRecallsStandingUpToDukeForJeff[] =
        "あはははは…そうそう、\r\n"
        "ジェフは腕っぷしが\r\n"
        "ダメだからね。{Press}\p"
        "わたしが助けに\r\n"
        "いってたっけ…{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaAppreciatesJeffAsHusbandAndFather[] =
        "まあ、なんだかんだ言っても、\r\n"
        "ジェフには感謝してるんだよ。{Press}\p"
        "カレンも生まれて、\r\n"
        "幸せな家庭も持てたしね。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_LilliaTeasesSashaForSentimentalStory[] =
        "まあ、ごちそうさま～。\r\n"
        "うふふふふ…{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_SashaRespondsToLilliasTeasing[] =
        "どういたしまして。\r\n"
        "あははははは…{Press}";
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
