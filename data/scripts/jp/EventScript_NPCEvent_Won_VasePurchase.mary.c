#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Won_VasePurchase_WonComplimentsFarmhouse[] =
        "この家、とてもすてきある。\r\n"
        "そんなあなただけに、\r\n"
        "特別いい話があるあるよ。{Press}";

    const char gText_NPCEvent_Won_VasePurchase_WonOffersVaseFor5000G[] =
        "いくら家がすてきても、\r\n"
        "さみしい、よくないあるね。{Press}\p"
        "そんな時、この花ビン！\r\n"
        "たった５０００Ｇで部屋が\r\n"
        "はなやかあるよ。{Press}";

    const char gText_NPCEvent_Won_VasePurchase_BuyVaseChoice[] =
        "花ビンを買う";

    const char gText_NPCEvent_Won_VasePurchase_DeclineVaseChoice[] =
        "花ビンを買わない";

    const char gText_NPCEvent_Won_VasePurchase_WonClaimsVaseIsRareMingDynastyPiece[] =
        "この花ビンのすごいところは\r\n"
        "…花がかざれることある。{Press}";

    const char gText_NPCEvent_Won_VasePurchase_WonSaysPlayerMustSupplyFlowers[] =
        "花ビンたけては、\r\n"
        "どうにもならないね。{Press}";

    const char gText_NPCEvent_Won_VasePurchase_WonClaimsBeautyBenefitsSoul[] =
        "役に立たない物、\r\n"
        "持てると心がよくなるよ。\r\n"
        "持てないと、かなしいね。{Press}";
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
