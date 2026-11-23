#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0811_NPCEvent_Won_AppleChallenge.mary.h"

void EventScript_0811_NPCEvent_Won_AppleChallenge(void)
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
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonOffersThreeRareApples);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExplainsApplesAreSpecial);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonIntroducesSUGDWApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExpandsSUGDWName);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonIntroducesHMSGBApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExpandsHMSGBName);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
#if defined(REGION_JP)
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName);
#else
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberHMSGBName);
#endif
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
#if defined(REGION_JP)
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName);
#else
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonPraisesAEPFEName);
#endif
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonUrgesPlayerToTasteApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonOffersEachAppleFor500G);
    var_0 = TalkPromptChoice4(gText_NPCEvent_Won_AppleChallenge_AppleSelectionPrompt, gText_NPCEvent_Won_AppleChallenge_SelectSUGDWApple, gText_NPCEvent_Won_AppleChallenge_SelectHMSGBApple, gText_NPCEvent_Won_AppleChallenge_SelectAEPFEApple, gText_NPCEvent_Won_AppleChallenge_DeclineApplePurchase);
    switch (var_0)
    {
        case PROMPT_CHOICE_OPTION_1:
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple);
            TalkClose();
            SetPlayerHeldFood(ITEM_FOOD_SUGDW_APPLE);
            SubtractMoney(500);
            break;
        case PROMPT_CHOICE_OPTION_2:
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple);
            TalkClose();
            SetPlayerHeldFood(ITEM_FOOD_HMSGB_APPLE);
            SubtractMoney(500);
            break;
        case PROMPT_CHOICE_OPTION_3:
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple);
            TalkClose();
            SetPlayerHeldFood(ITEM_FOOD_AEPFE_APPLE);
            SubtractMoney(500);
            break;
        case PROMPT_CHOICE_OPTION_4:
            SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_WON);
            TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonMocksPlayerForLacking500G);
            TalkClose();
            break;
    }
    SetEntityFacing(ENTITY_WON, FACING_RIGHT);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_WALK);
    MoveEntityXTo(ENTITY_WON, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    SetEntityFacing(ENTITY_WON, FACING_UP);
    MoveEntityYTo(ENTITY_WON, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    HideEntity(ENTITY_WON);
    MarkNpcSpokenTo(CHARACTER_WON);
    VarSet(VAR_WON_APPLE_CHALLENGE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
