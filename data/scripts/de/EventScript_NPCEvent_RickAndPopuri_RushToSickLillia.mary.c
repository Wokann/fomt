#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaClosesStoreDueToIllness[] =
        "Ich fühle mich heute\r\n"
        "nicht so gut, also bleibt \r\n"
        "der Laden geschlossen. {Press}\p"
        "Sorry, {Player}. {Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaSaysChildrenRushedAway[] =
        "Rick und Popuri?\r\n"
        "Sie sind beide weg- \r\n"
        "gestürmt, ich weiß{Press}\r\n"
        "aber nicht wohin...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickArrivesBreathless[] =
        "Keuch...schnauf...ächz...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaAsksWhereRickRan[] =
        "Rick! Was ist los! \r\n"
        "Wo bist du hingerannt?{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickExplainsBuyingMedicineAtClinic[] =
        "Dir ging es nicht so gut, \r\n"
        "also bin ich zur Klinik \r\n"
        "gerannt, um Medizin{Press}\p"
        "zu kaufen!{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaThanksRickForThoughtfulness[] =
        "Du bist so aufmerksam...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriArrivesWithMedicine[] =
        "Keuch...schnauf...\r\n"
        "Mama, ich habe dir \r\n"
        "Medizin gebracht!{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_RickRealizesPopuriAlsoWentForMedicine[] =
        "Du also auch?!{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriNotesTheyBothBoughtMedicine[] =
        "Du auch, Rick?\r\n"
        "Ha! Sieht aus, als hätten\r\n"
        "wir dir doppelt so viel {Press}\r\n"
        "gekauft wie du brauchst!{Press}\p"
        "Sorry, Mama!...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_LilliaThanksChildrenForConcern[] =
        "Keine Sorge. \r\n"
        "Ich freue mich, dass \r\n"
        "meine Kinder sich so sorgen!{Press}\p"
        "Vielen Dank, ihr Lieben...{Press}";

    const char gText_NPCEvent_RickAndPopuri_RushToSickLillia_PopuriUrgesLilliaToRest[] =
        "Pass auf dich auf, Mama...{Press}";
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
