#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenAcceptsYarnAndPromisesStarryNightStocking[] =
        "Ganz vielen Dank! \r\n"
        "Ich nehme dieses Garn \r\n"
        "und mache dir eine Socke {Press}\r\n"
        "als Sternennachtgeschenk!\r\n"
        "Warte nur einen Moment. {Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationEllenKnitsStockingQuickly[] =
        "Ellen strickt eine Socke \r\n"
        "in Windeseile...{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenFinishesStockingAndRests[] =
        "Sie ist fertig!{Press}\p"
        "Ha... Ich bin müde.{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenPromisesStuWillDeliverStocking[] =
        "Schön, dass sie dir gefällt.\r\n"
        "Ich werde sie später von\r\n"
        "Stu liefern lassen.{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationPlayerWillHangStockingOnWall[] =
        "Ab jetzt hänge ich diese\r\n"
        "Socke an meine Wand...{Press}";
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
