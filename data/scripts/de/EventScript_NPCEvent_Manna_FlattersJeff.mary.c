#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_FlattersJeff_JeffGreetsPlayerAtCounter[] =
        "Willkommen. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaGreetsPlayer[] =
        "Oh, hi {Player}. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaExplainsShoppingAndDinnerErrand[] =
        "Bist du zum Einkaufen \r\n"
        "hergekommen, {Player}?\r\n"
        "Ich wollte mit Sasha \r\n"
        "plaudern, aber wo ich\r\n"
        "einmal hier bin, kaufe ich\r\n"
        "ein paar Dinge.\r\n"
        "Wenn ich darüber nachdenke,\r\n"
        "brauche ich ein paar \r\n"
        "Sachen fürs Abendessen. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaOrdersRiceBallAndCurryPowder[] =
        "Ich hätte gerne ein \r\n"
        "Reisbällchen und \r\n"
        "Currypulver. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffAsksMannaToWaitForHerOrder[] =
        "In einer Sekunde. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaComplimentsJeffsAppearance[] =
        "In letzter Zeit siehst du\r\n"
        "verdammt gut aus, Jeff. \r\n"
        "Hast du trainiert?{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffReactsInSurprise[] =
        "Hä?{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaInsistsJeffLooksFit[] =
        "Ja, du siehst definitiv aus,\r\n"
        "als seiest du in Bestform!{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffAcceptsCompliment[] =
        "Wenn du es sagst...{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaFlirtsAndAsksPrice[] =
        "Ich bin zum Verlieben!\r\n"
        "Nun aber, wie viel schulde \r\n"
        "ich dir fürs Essen...?{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffOffersHalfPrice[] =
        "Mhmm... Für dich heute \r\n"
        "zum halben Preis, Manna. {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaThanksJeffAndComparesDuke[] =
        "Echt? Du bist ein Schatz, \r\n"
        "Jeff! Ich wünschte, Duke\r\n"
        "würde sich ein Beispiel \r\n"
        "an dir nehmen! {Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffIsFlatteredByMannasPraise[] =
        "Ahh...Mist...{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaRevealsFlatteryDiscountStrategy[] =
        "Ich mache Jeff \r\n"
        "Komplimente und kriege \r\n"
        "dann einen Sonderpreis. \r\n"
        "Das klappt immer!{Press}";
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
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_MannaOrdersRiceBallAndCurryPowder);
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
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_MannaComplimentsJeffsAppearance);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffReactsInSurprise);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_MannaInsistsJeffLooksFit);
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
