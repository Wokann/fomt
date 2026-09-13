#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysHeIsHungry[] =
        "I'm starving!{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiOffersDishForTasting[] =
        "Can you try this then?{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesDish[] =
        "Hey, this is great!{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiAsksForConfirmation[] =
        "You really think so?{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiWelcomesPlayer[] =
        "Oh, {Player}.\r\n"
        "Welcome. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayGreetsPlayer[] =
        "Hi there. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayExplainsKaiInvitedHim[] =
        "You say it's unusual for me\r\n"
        "to be at Kai's place? {Press}\p"
        "I guess so, but he \r\n"
        "invited me. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiValuesGraysCityFoodExperience[] =
        "Gray is the only person \r\n"
        "around here who knows what \r\n"
        "food in the city tastes {Press}\r\n"
        "like. {Press}\p"
        "So, I value his opinion. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesKaisCookingSkill[] =
        "I have to say I'm \r\n"
        "impressed with your \r\n"
        "skill, Kai!{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiGainsConfidenceFromGraysPraise[] =
        "Thanks. Hearing that from \r\n"
        "you gives me confidence. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayReturnsToForgeWork[] =
        "I better get back to \r\n"
        "work before gramps starts \r\n"
        "complaining. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiThanksGrayForVisiting[] =
        "Thanks for coming. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToKai[] =
        "Bye now. {Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToPlayer[] =
        "See you later, {Player}.{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiPraisesGrayToPlayer[] =
        "Gray's a great guy, \r\n"
        "don't you think? {Press}";
};

void EventScript_NPCEvent_GrayAndKai_KaiCooksForGray(void)
{
    ChangeMap(MAP_KAI_RESTAURANT, X(120), Y(124));
    SetEntityPosition(ENTITY_KAI, X(110), Y(91), FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(122), Y(240), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(250), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WALK);
    MoveEntityYTo(ENTITY_GRAY, Y(161), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    MoveEntityXTo(ENTITY_GRAY, X(140), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_UP);
    MoveEntityYTo(ENTITY_GRAY, Y(91), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysHeIsHungry);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiOffersDishForTasting);
    TalkClose();
    WaitFrames(60);
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesDish);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiAsksForConfirmation);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(124), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiWelcomesPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayGreetsPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayExplainsKaiInvitedHim);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiValuesGraysCityFoodExperience);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesKaisCookingSkill);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiGainsConfidenceFromGraysPraise);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayReturnsToForgeWork);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiThanksGrayForVisiting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToKai);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WALK);
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    MoveEntityXTo(ENTITY_GRAY, X(142), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    MoveEntityYTo(ENTITY_GRAY, Y(156), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    MoveEntityXTo(ENTITY_GRAY, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    MoveEntityYTo(ENTITY_GRAY, Y(230), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    HideEntity(ENTITY_GRAY);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiPraisesGrayToPlayer);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_KAI);
    MarkNpcSpokenTo(CHARACTER_GRAY);
    EnableScriptedNpcControl();
    VarSet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_KAI, EventScript_NPCEvent_GrayAndKai_KaiCooksForGray_FollowupKaiDialogue);
}
