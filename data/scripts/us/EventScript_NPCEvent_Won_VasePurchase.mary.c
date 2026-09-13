#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Won_VasePurchase_WonComplimentsFarmhouse[] =
        "This is a very beautiful \r\n"
        "house! It deserves \r\n"
        "something special...{Press}";

    const char gText_NPCEvent_Won_VasePurchase_WonOffersVaseFor5000G[] =
        "What this house lacks is a \r\n"
        "Vase! Believe me, I know \r\n"
        "about such things! {Press}\p"
        "I happen to have one here \r\n"
        "I can sell for just 5000G.{Press}";

    const char gText_NPCEvent_Won_VasePurchase_BuyVaseChoice[] =
        "Buy Vase.";

    const char gText_NPCEvent_Won_VasePurchase_DeclineVaseChoice[] =
        "Don't Buy.";

    const char gText_NPCEvent_Won_VasePurchase_WonClaimsVaseIsRareMingDynastyPiece[] =
        "It’s a very rare vase from\r\n"
        "the Ming Dynasty!{Press}";

    const char gText_NPCEvent_Won_VasePurchase_WonSaysPlayerMustSupplyFlowers[] =
        "Of course, you'll have to \r\n"
        "find some flowers for it \r\n"
        "yourself. {Press}";

    const char gText_NPCEvent_Won_VasePurchase_WonClaimsBeautyBenefitsSoul[] =
        "It's good for your soul to\r\n"
        "surround yourself with \r\n"
        "beauty!{Press}";
};

void EventScript_NPCEvent_Won_VasePurchase(void)
{
    int var_0;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_WON, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_VasePurchase_WonComplimentsFarmhouse);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_VasePurchase_WonOffersVaseFor5000G);
    var_0 = TalkChoice2(gText_NPCEvent_Won_VasePurchase_BuyVaseChoice, gText_NPCEvent_Won_VasePurchase_DeclineVaseChoice);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessage(gText_NPCEvent_Won_VasePurchase_WonClaimsVaseIsRareMingDynastyPiece);
            SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
            TalkMessage(gText_NPCEvent_Won_VasePurchase_WonSaysPlayerMustSupplyFlowers);
            VarSet(VAR_HAS_VASE, TRUE);
            SubtractMoney(5000);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessage(gText_NPCEvent_Won_VasePurchase_WonClaimsBeautyBenefitsSoul);
            break;
    }
    TalkClose();
    SetEntityFacing(ENTITY_WON, FACING_RIGHT);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_WALK);
    MoveEntityXTo(ENTITY_WON, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    SetEntityFacing(ENTITY_WON, FACING_UP);
    MoveEntityYTo(ENTITY_WON, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    HideEntity(ENTITY_WON);
    MarkNpcSpokenTo(CHARACTER_WON);
    VarSet(VAR_WON_VASE_PURCHASE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
