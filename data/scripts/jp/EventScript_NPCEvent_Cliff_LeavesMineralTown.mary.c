#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougAsksCliffToStay[] =
        "本当に行っちまうのか…{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffThanksDougButSaysHeMustLeave[] =
        "はい、…お世話になりました。\r\n"
        "…ここは、なんだかいごこちが\r\n"
        "よすぎるんです…{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougSaysLikingTownIsNoReasonToLeave[] =
        "ばかやろう。\r\n"
        "いごこちがよすぎて、\r\n"
        "悪いって事はねぇだろう…{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffAsksDougToThankEveryone[] =
        "ありがとうございました。\r\n"
        "みなさんによろしく。{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougSaysAnnWillMissCliff[] =
        "ああ…\r\n"
        "ランには言わないで来たよ。\r\n"
        "ランがさみしがるだろうなぁ。{Press}\p"
        "クリフのこと、\r\n"
        "気に入ってたようだしな。{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffSaysGoodbyeAndLeaves[] =
        "…………{Press}\p"
        "じゃあ、ボク行きます。{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougWishesCliffGoodLuck[] =
        "元気でな！{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_CliffThanksDougAndTownBeforeDeparture[] =
        "本当に\r\n"
        "ありがとうございました。{Press}";

    const char gText_NPCEvent_Cliff_LeavesMineralTown_DougInvitesCliffToReturnAnytime[] =
        "いつでも帰って来いよ！{Press}";
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
