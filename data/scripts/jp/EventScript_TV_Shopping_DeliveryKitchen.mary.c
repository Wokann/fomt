#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_Shopping_DeliveryKitchen_TheKitchenYouOrderedIsHere[] =
        "おい、おまえが注文した台所が\r\n"
        "とどいてたぜ。{Press}\p"
        "これからはちゃんとした料理\r\n"
        "とかが作れるぜ。\r\n"
        "いい買い物したじゃねぇか。{Press}";

    const char gText_TV_Shopping_DeliveryKitchen_DeliveredSafeAndSound[] =
        "それじゃ、確かにとどけたぜ。{Press}";
};

void EventScript_TV_Shopping_DeliveryKitchen(void)
{
    ChangeMap(MAP_FARM, X(228), Y(120));
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ZACK, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_TV_SHOPPING_KITCHEN_DELIVERY_STATE, TV_SHOPPING_DELIVERY_IN_PROGRESS);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_TV_Shopping_DeliveryKitchen_TheKitchenYouOrderedIsHere);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_TV_Shopping_DeliveryKitchen_DeliveredSafeAndSound);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityXTo(ENTITY_ZACK, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityFacing(ENTITY_ZACK, FACING_UP);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityYTo(ENTITY_ZACK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    HideEntity(ENTITY_ZACK);
    MarkNpcSpokenTo(CHARACTER_ZACK);
    CompleteTVShoppingDelivery();
    VarSet(VAR_HAS_KITCHEN, TRUE);
    VarSet(VAR_TV_SHOPPING_KITCHEN_DELIVERY_STATE, TV_SHOPPING_DELIVERY_COMPLETED);
    return;
}
