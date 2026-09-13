#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_FlattersJeff_JeffGreetsPlayerAtCounter[] =
        "Welcome. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaGreetsPlayer[] =
        "Oh, hi {Player}. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaExplainsShoppingAndDinnerErrand[] =
        "Did you come to do some \r\n"
        "shopping, {Player}? \r\n"
        "Me, I came to chat with \r\n"
        "Sasha, but I think I'll buy\r\n"
        "some things while I'm here.\r\n"
        "I need some things for \r\n"
        "dinner, come to think \r\n"
        "of it. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaOrdersRiceBallAndCurryPowder[] =
        "Can I have a Rice Ball \r\n"
        "and Curry Powder, please? {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffAsksMannaToWaitForHerOrder[] =
        "Just one second. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaComplimentsJeffsAppearance[] =
        "You look awfully handsome\r\n"
        "lately, Jeff. Have you been\r\n"
        "working out? {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffReactsInSurprise[] =
        "Huh? {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaInsistsJeffLooksFit[] =
        "Yes, you definitely look\r\n"
        "like you're in great shape!{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffAcceptsCompliment[] =
        "Well, if you say so...{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaFlirtsAndAsksPrice[] =
        "I might develop a crush \r\n"
        "on you myself! Now, \r\n"
        "how much for the food...?{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffOffersHalfPrice[] =
        "Umm...Half price for you \r\n"
        "today, Manna. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaThanksJeffAndComparesDuke[] =
        "Really? You're a \r\n"
        "sweety, Jeff!\r\n"
        "I wish my Duke would \r\n"
        "take a lesson from you! {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffIsFlatteredByMannasPraise[] =
        "Aww...Shucks...{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaRevealsFlatteryDiscountStrategy[] =
        "I always compliment Jeff\r\n"
        "like that, and he always \r\n"
        "gives me a deal. \r\n"
        "It never fails!...{Press}";
};

void EventScript_NPCEvent_Manna_FlattersJeff(void)
{
    EnableScriptedNpcControl();
    ChangeMap(MAP_SUPERMARKET, X(228), Y(152));
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(152), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_JEFF, X(228), Y(112), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffGreetsPlayerAtCounter);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MANNA, X(144), Y(288), FACING_UP);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_WALK);
    MoveEntityYTo(ENTITY_MANNA, Y(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    MoveEntityXTo(ENTITY_MANNA, X(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_UP);
    MoveEntityYTo(ENTITY_MANNA, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaGreetsPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaExplainsShoppingAndDinnerErrand);
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaOrdersRiceBallAndCurryPowder);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffAsksMannaToWaitForHerOrder);
    TalkClose();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaComplimentsJeffsAppearance);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffReactsInSurprise);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaInsistsJeffLooksFit);
    TalkClose();
    StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffAcceptsCompliment);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaFlirtsAndAsksPrice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffOffersHalfPrice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaThanksJeffAndComparesDuke);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffIsFlatteredByMannasPraise);
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaRevealsFlatteryDiscountStrategy);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    MarkNpcSpokenTo(CHARACTER_MANNA);
    EnableScriptedNpcControl();
    VarSet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_MANNA, EventScript_NPCEvent_Manna_FlattersJeff_FollowupMannaDialogue);
    SetEntityEventScript(ENTITY_JEFF, EventScript_NPCEvent_Manna_FlattersJeff_FollowupJeffDialogue);
    return;
}
