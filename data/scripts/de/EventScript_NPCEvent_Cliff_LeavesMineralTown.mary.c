#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougAsksCliffToStay[] =
        "Gehst du wirklich...?{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffThanksDougButSaysHeMustLeave[] =
        "Danke für alles. \r\n"
        "Ich muss trotzdem gehen.\r\n"
        "Ich mag es hier zu sehr..{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougSaysLikingTownIsNoReasonToLeave[] =
        "Wovon redest du!\r\n"
        "Was ist falsch daran, \r\n"
        "es hier zu mögen...?{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffAsksDougToThankEveryone[] =
        "Sag allen noch mal \r\n"
        "danke von mir. {Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougSaysAnnWillMissCliff[] =
        "Ann wird so traurig sein.\r\n"
        "Sie mag dich so sehr...{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffSaysGoodbyeAndLeaves[] =
        "...Bis dann.\r\n"
        "Zeit für mich zu gehen. {Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougWishesCliffGoodLuck[] =
        "Viel Glück!{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffThanksDougAndTownBeforeDeparture[] =
        "Danke noch mal für \r\n"
        "alles. {Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougInvitesCliffToReturnAnytime[] =
        "Komm jederzeit wieder!{Press}";
};

void EventScript_NPCEvent_Cliff_LeavesMineralTown(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(211), Y(164));
    SetEntityPosition(ENTITY_CLIFF, X(241), Y(138), FACING_DOWN);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(241), Y(168), FACING_UP);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_DougAsksCliffToStay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_CliffThanksDougButSaysHeMustLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_DougSaysLikingTownIsNoReasonToLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_CliffAsksDougToThankEveryone);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_DougSaysAnnWillMissCliff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_CliffSaysGoodbyeAndLeaves);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_RIGHT);
    SetEntityFacing(ENTITY_DOUG, FACING_RIGHT);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WALK);
    MoveEntityXTo(ENTITY_CLIFF, X(289), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_DougWishesCliffGoodLuck);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_CliffThanksDougAndTownBeforeDeparture);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_Cliff_LeavesMineralTown_DougInvitesCliffToReturnAnytime);
    TalkClose();
    WaitFrames(30);
    SetEntityFacing(ENTITY_CLIFF, FACING_RIGHT);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WALK);
    MoveEntityXTo(ENTITY_CLIFF, X(385), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    HideEntity(ENTITY_CLIFF);
    SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_WALK);
    MoveEntityYTo(ENTITY_DOUG, Y(307), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DOUG);
    HideEntity(ENTITY_DOUG);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    VarSet(VAR_CLIFF_LEAVES_MINERAL_TOWN_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
