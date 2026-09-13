#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Won_AppleChallenge_WonOffersThreeRareApples[] =
        "I brought 3 rare and \r\n"
        "valuable items for you \r\n"
        "today! These are special{Press}\r\n"
        "for you.{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExplainsApplesAreSpecial[] =
        "These 3 kinds of Apples are\r\n"
        "no ordinary Apples, \r\n"
        "you understand? {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesSUGDWApple[] =
        "This is the first kind. \r\n"
        "It's called SUGDW Apple. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsSUGDWName[] =
        "It's real name is very long:\r\n"
        "Super Ultra Great Delicious\r\n"
        "Wonderful Apple!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName[] =
        "Sometimes I can't remember\r\n"
        "all of it...! {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesHMSGBApple[] =
        "This is the second one: \r\n"
        "the HMSGB Apple! {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsHMSGBName[] =
        "That's short for Hyper \r\n"
        "Miracle Sweet Gorgeous \r\n"
        "Beautiful  Apple!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberHMSGBName[] =
        "That one is hard to \r\n"
        "remember, too!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple[] =
        "Finally, I have this. \r\n"
        "It's an AEPFE Apple!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName[] =
        "That's short for:\r\n"
        "Angel Eternal Pure \r\n"
        "Fresh Elegant Apple. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonPraisesAEPFEName[] =
        "See? Even the name \r\n"
        "is wonderful!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonUrgesPlayerToTasteApple[] =
        "Of course, you have to eat\r\n"
        "each one to see how \r\n"
        "wonderful it really is!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonOffersEachAppleFor500G[] =
        "Price is 500G. \r\n"
        "Very cheap, very cheap. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_AppleSelectionPrompt[] =
        "Which will it be?";

    const char gText_NPCEvent_Won_AppleChallenge_SelectSUGDWApple[] =
        "SUGDW";

    const char gText_NPCEvent_Won_AppleChallenge_SelectHMSGBApple[] =
        "HMSGB";

    const char gText_NPCEvent_Won_AppleChallenge_SelectAEPFEApple[] =
        "AEPFE";

    const char gText_NPCEvent_Won_AppleChallenge_DeclineApplePurchase[] =
        "No thanks.";

    const char gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple[] =
        "Thanks very much!\r\n"
        "I didn't think anyone would\r\n"
        "ever -- I mean...{Press}\r\n"
        "You have a fine eye, sir!\r\n"
        "I'll be going now!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonMocksPlayerForLacking500G[] =
        "You don't even have 500G?\r\n"
        "What a poor man you are!{Press}";
};

void EventScript_NPCEvent_Won_AppleChallenge(void)
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
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberHMSGBName);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple);
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    TalkMessage(gText_NPCEvent_Won_AppleChallenge_WonPraisesAEPFEName);
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
