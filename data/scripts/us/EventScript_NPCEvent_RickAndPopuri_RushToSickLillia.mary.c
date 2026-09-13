#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaClosesStoreDueToIllness[] =
        "I'm not feeling very well\r\n"
        "today, so the store is \r\n"
        "closed. {Press}\p"
        "Sorry, {Player}. {Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaSaysChildrenRushedAway[] =
        "Rick and Popuri?\r\n"
        "They both rushed off \r\n"
        "somewhere, but I don't\r\n"
        "know where...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickArrivesBreathless[] =
        "Pant...wheeze...gasp...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaAsksWhereRickRan[] =
        "Rick! What's wrong! \r\n"
        "Where did you run to?...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickExplainsBuyingMedicineAtClinic[] =
        "You weren't feeling well, \r\n"
        "so I ran to the Clinic to \r\n"
        "buy some medicine!{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaThanksRickForThoughtfulness[] =
        "You're so thoughtful...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriArrivesWithMedicine[] =
        "Pant...gasp...\r\n"
        "I brought you some \r\n"
        "medicine, Mom!{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickRealizesPopuriAlsoWentForMedicine[] =
        "So you went too?!{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriNotesTheyBothBoughtMedicine[] =
        "You went too, Rick?\r\n"
        "Looks like we bought \r\n"
        "twice as much as {Press}\r\n"
        "you need...{Press}\p"
        "Sorry, Mom...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaThanksChildrenForConcern[] =
        "Don't worry about it. \r\n"
        "I'm just glad my children \r\n"
        "are so concerned about me!{Press}\p"
        "Thank you both, dears...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriUrgesLilliaToRest[] =
        "Just take care, Mom...{Press}";
};

void EventScript_NPCEvent_RickAndPopuri_RushToSickLillia(void)
{
    EnableScriptedNpcControl();
    ChangeMap(MAP_POULTRY_FARM_HOUSE_1F, X(192), Y(80));
    HideEntity(ENTITY_POPURI);
    HideEntity(ENTITY_RICK);
    SetEntityPosition(ENTITY_PLAYER, X(192), Y(80), FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_LILLIA, X(216), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaClosesStoreDueToIllness);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaSaysChildrenRushedAway);
    TalkClose();
    SetEntityPosition(ENTITY_RICK, X(120), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityYTo(ENTITY_RICK, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
    MoveEntityXTo(ENTITY_RICK, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_UP);
    MoveEntityYTo(ENTITY_RICK, Y(98), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    MoveEntityXTo(ENTITY_RICK, X(216), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_UP);
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickArrivesBreathless);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaAsksWhereRickRan);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickExplainsBuyingMedicineAtClinic);
    TalkClose();
    StartEntityEffect(ENTITY_LILLIA, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaThanksRickForThoughtfulness);
    TalkClose();
    SetEntityPosition(ENTITY_POPURI, X(120), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    MoveEntityXTo(ENTITY_POPURI, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    MoveEntityYTo(ENTITY_POPURI, Y(98), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    MoveEntityXTo(ENTITY_POPURI, X(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    MoveEntityXTo(ENTITY_POPURI, X(212), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_RICK, X(226), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriArrivesWithMedicine);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickRealizesPopuriAlsoWentForMedicine);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriNotesTheyBothBoughtMedicine);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaThanksChildrenForConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriUrgesLilliaToRest);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_LILLIA);
    VarSet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    VarSet(VAR_RICK_AND_POPURI_SICK_LILLIA_FOLLOWUP_STATE, TRUE);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_POPURI, EventScript_NPCEvent_Rick_WorriesAboutLilliasHealth_FollowupPopuriDialogue);
    SetEntityEventScript(ENTITY_RICK, EventScript_NPCEvent_Rick_WorriesAboutLilliasHealth);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_NPCEvent_Rick_WorriesAboutLilliasHealth_FollowupLilliaDialogue);
    return;
}
