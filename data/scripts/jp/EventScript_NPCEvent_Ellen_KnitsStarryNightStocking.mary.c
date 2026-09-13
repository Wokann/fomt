#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenAcceptsYarnAndPromisesStarryNightStocking[] =
        "あら、ありがとう。そうだ、\r\n"
        "この毛糸で星夜の贈り物で使う\r\n"
        "プレゼントを入れる靴下作って{Press}\r\n"
        "あげるわ。{Press}\p"
        "ちょっとまっててね。{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationEllenKnitsStockingQuickly[] =
        "エレンさんが神業のような\r\n"
        "手さばきで靴下を\r\n"
        "作っていく。{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenFinishesStockingAndRests[] =
        "はい、出来上がり！{Press}\p"
        "はぁ…さすがに疲れたわ。{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_EllenPromisesStuWillDeliverStocking[] =
        "よろこんでもらって\r\n"
        "よかったわ。じゃ、後で\r\n"
        "ユウに届けさせるわね。{Press}";

    const char gText_NPCEvent_Ellen_KnitsStarryNightStocking_NarrationPlayerWillHangStockingOnWall[] =
        "この靴下は、今から壁に\r\n"
        "かけておこう…{Press}";
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
