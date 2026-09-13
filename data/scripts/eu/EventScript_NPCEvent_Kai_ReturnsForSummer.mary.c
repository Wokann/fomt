#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Kai_ReturnsForSummer_MayRecognizesKai[] =
        "It's Kai!{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_PopuriWelcomesKaiAndMarksStartOfSummer[] =
        "Welcome back, Kai. \r\n"
        "When Kai comes, we know \r\n"
        "summer has officially {Press}\r\n"
        "started!{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_KaiInvitesEveryoneToBeachHouseOpening[] =
        "The Beach House will be\r\n"
        "open from the day after\r\n"
        "tomorrow, so come on by.{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_MayCheersForBeachHouse[] =
        "Great!{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_PopuriSaysGoodbye[] =
        "See you. {Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_KaiIntroducesHimselfAndBeachHouseToPlayer[] =
        "I don't think you were here\r\n"
        "last summer. {Press}\p"
        "The name's Kai. {Press}\p"
        "Know that tiny cottage on \r\n"
        "the beach? I run it during\r\n"
        "the summer. {Press}\p"
        "Come by for a visit some-\r\n"
        "time. {Press}\p"
        "Bye now. {Press}";
};

void EventScript_NPCEvent_Kai_ReturnsForSummer(void)
{
    ChangeMap(MAP_SOUTH_SIDE_TOWN, X(104), Y(194));
    SetEntityPosition(ENTITY_PLAYER, X(104), Y(316), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAI, X(104), Y(163), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(135), Y(171), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_MAY, X(135), Y(145), FACING_LEFT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_MayRecognizesKai);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_PopuriWelcomesKaiAndMarksStartOfSummer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_KaiInvitesEveryoneToBeachHouseOpening);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_MayCheersForBeachHouse);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_PopuriSaysGoodbye);
    TalkClose();
    WaitFrames(30);
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    SetEntityFacing(ENTITY_MAY, FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityXTo(ENTITY_POPURI, X(299), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_MAY, X(299), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    WaitForEntityMovement(ENTITY_MAY);
    HideEntity(ENTITY_POPURI);
    HideEntity(ENTITY_MAY);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(194), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_KaiIntroducesHimselfAndBeachHouseToPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityXTo(ENTITY_KAI, X(299), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    HideEntity(ENTITY_KAI);
    MarkNpcSpokenTo(CHARACTER_KAI);
    AddNpcFriendship(CHARACTER_KAI, 20);
    VarSet(VAR_KAI_RETURNS_FOR_SUMMER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
