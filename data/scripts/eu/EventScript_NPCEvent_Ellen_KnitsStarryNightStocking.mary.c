#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenAcceptsYarnAndPromisesStarryNightStocking[] =
        "Thanks very much! \r\n"
        "I'm going to use this yarn \r\n"
        "to knit you a sock for a {Press}\r\n"
        "Starry Night present!\r\n"
        "Just wait one moment. {Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationEllenKnitsStockingQuickly[] =
        "Ellen knits a sock \r\n"
        "with lightning speed...{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenFinishesStockingAndRests[] =
        "It's ready!{Press}\p"
        "Ha...I'm tired.{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenPromisesStuWillDeliverStocking[] =
        "I'm glad you like it.\r\n"
        "I will have Stu deliver\r\n"
        "it to you later.{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationPlayerWillHangStockingOnWall[] =
        "I will hang this sock\r\n"
        "on my wall from now on...{Press}";
};

void EventScript_NPCEvent_Ellen_KnitsStarryNightStocking(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenAcceptsYarnAndPromisesStarryNightStocking);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    UsePlayerHeldItem();
    TalkOpen();
    TalkMessage(gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationEllenKnitsStockingQuickly);
    TalkClose();
    SetEntityPosition(ENTITY_PLAYER, X(128), Y(117), FACING_UP);
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
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenFinishesStockingAndRests);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenPromisesStuWillDeliverStocking);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationPlayerWillHangStockingOnWall);
    TalkClose();
    PlacePlayerAtFarmhouseBed();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetGameTime(18, 0);
    AddNpcFriendship(CHARACTER_ELLEN, 20);
    MarkNpcSpokenTo(CHARACTER_ELLEN);
    VarSet(VAR_HAS_STOCKING, TRUE);
    VarSet(VAR_ELLEN_KNITS_STOCKING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
