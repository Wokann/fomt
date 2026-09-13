#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Won_AppleChallenge_WonOffersThreeRareApples[] =
        "Ich habe dir heute 3 seltene\r\n"
        "und sehr wertvolle \r\n"
        "Gegenstände mitgebracht!{Press}\r\n"
        "Die sind speziell\r\n"
        "für dich.{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExplainsApplesAreSpecial[] =
        "Diese 3 Apfelsorten sind\r\n"
        "keine gewöhnlichen Äpfel,\r\n"
        "verstehst du. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesSUGDWApple[] =
        "Dies ist die erste Sorte.\r\n"
        "Der SUGDW Apfel. {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsSUGDWName[] =
        "Sein voller Name ist lang:\r\n"
        "Super-Ultra-Guter-Delikater-\r\n"
        "Wunder-Apfel!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberSUGDWName[] =
        "Manchmal vergesse ich\r\n"
        "Teile des Namens...! {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesHMSGBApple[] =
        "Dies ist die zweite Sorte:\r\n"
        "Der HMSGB Apfel! {Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsHMSGBName[] =
        "Die Abkürzung für Hyper-\r\n"
        "Magischer-Süßer-Guter-\r\n"
        "Galaktischer-Bombiger Apfel!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonStrugglesToRememberHMSGBName[] =
        "Ebenfalls schwer zu \r\n"
        "merken!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonIntroducesAEPFEApple[] =
        "Und schließlich dieser. \r\n"
        "Das ist ein HKEFG Apfel!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonExpandsAEPFEName[] =
        "Die Abkürzung für:\r\n"
        "Himmlisch-Knackig-Ewig-\r\n"
        "Frischer-Geschmackvoller.{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonPraisesAEPFEName[] =
        "Siehst du? Sogar der Name\r\n"
        "ist wundervoll!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonUrgesPlayerToTasteApple[] =
        "Natürlich musst du alle 3\r\n"
        "probieren, damit du siehst,\r\n"
        "wie gut sie sind!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonOffersEachAppleFor500G[] =
        "Der Preis ist 500G. \r\n"
        "Sehr günstig, sehr günstig.{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_AppleSelectionPrompt[] =
        "Welcher darf es sein?";

    const char gText_NPCEvent_Won_AppleChallenge_SelectSUGDWApple[] =
        "SUGDW";

    const char gText_NPCEvent_Won_AppleChallenge_SelectHMSGBApple[] =
        "HMSGB";

    const char gText_NPCEvent_Won_AppleChallenge_SelectAEPFEApple[] =
        "HKEFG";

    const char gText_NPCEvent_Won_AppleChallenge_DeclineApplePurchase[] =
        "Nein, danke.";

    const char gText_NPCEvent_Won_AppleChallenge_WonThanksPlayerForBuyingApple[] =
        "Sehr vielen Dank!\r\n"
        "Ich hätte nicht gedacht,\r\n"
        "dass je einer ? Ich meine...{Press}\r\n"
        "Sehr gute Augen, mein Herr!\r\n"
        "Ich gehe jetzt!{Press}";

    const char gText_NPCEvent_Won_AppleChallenge_WonMocksPlayerForLacking500G[] =
        "Du hast keine 500G?\r\n"
        "Du armer Mann!{Press}";
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
