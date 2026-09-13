#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksPlayerToHearAboutDream[] =
        "Hey, {Player}! \r\n"
        "Listen to this!{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterDescribesHearingVoiceWhileDozingInConfessional[] =
        "I was kneeling in the \r\n"
        "confession room, like I \r\n"
        "always do, and I thought{Press}\r\n"
        "I heard a voice. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterSaysVoicePredictedGoodFortune[] =
        "It told me that I would \r\n"
        "meet with good fortune. {Press}\p"
        "I wonder if it was a \r\n"
        "dream, or what...?{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackCallsForCarter[] =
        "Are you awake, Carter? {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksWhyZackCameLate[] =
        "What's wrong\r\n"
        "at this hour?{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackSaysCartersWantedItemWasFound[] =
        "That thing you wanted \r\n"
        "is finally yours. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterReactsToItemBeingFound[] =
        "What? \r\n"
        "You finally found one?{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackExplainsDifficultyFindingItem[] =
        "I had a hard time locating \r\n"
        "it, but I finally managed \r\n"
        "to lay my hands on one. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterThanksZack[] =
        "Thanks very much. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackAsksCarterToCollectItem[] =
        "Come pick it up soon.\r\n"
        "Bye now. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterCreditsDreamForGoodFortune[] =
        "I guess the voice I \r\n"
        "heard was right about the \r\n"
        "good fortune!{Press}\p"
        "I'll have to spend more \r\n"
        "time in the confessional!{Press}";
};

void EventScript_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune(void)
{
    ChangeMap(MAP_CHURCH, X(183), Y(125));
    SetEntityPosition(ENTITY_CARTER, X(183), Y(103), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(161), Y(243), FACING_UP);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(183), Y(243), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(125), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksPlayerToHearAboutDream);
    TalkClose();
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterDescribesHearingVoiceWhileDozingInConfessional);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterSaysVoicePredictedGoodFortune);
    TalkClose();
    WaitFrames(60 * 2);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackCallsForCarter);
    TalkClose();
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityYTo(ENTITY_ZACK, Y(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksWhyZackCameLate);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackSaysCartersWantedItemWasFound);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterReactsToItemBeingFound);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackExplainsDifficultyFindingItem);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterThanksZack);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackAsksCarterToCollectItem);
    TalkClose();
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    MoveEntityYTo(ENTITY_ZACK, Y(243), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    HideEntity(ENTITY_ZACK);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterCreditsDreamForGoodFortune);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CARTER);
    EnableScriptedNpcControl();
    VarSet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_CARTER, EventScript_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_FollowupCarterDialogue);
}
