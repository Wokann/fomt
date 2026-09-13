#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksPlayerToHearAboutDream[] =
        "Hey, {Player}! \r\n"
        "Hör dir das an!{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterDescribesHearingVoiceWhileDozingInConfessional[] =
        "Ich habe im Beichtstuhl\r\n"
        "gekniet, wie immer, als \r\n"
        "mir war, als hörte{Press}\r\n"
        "ich eine Stimme. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterSaysVoicePredictedGoodFortune[] =
        "Sie sagte mir, dass ich \r\n"
        "Glück haben werde. {Press}\p"
        "Ob das wohl ein Traum war?{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackCallsForCarter[] =
        "Bist du wach, Carter?{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterAsksWhyZackCameLate[] =
        "Was ist los\r\n"
        "um diese Zeit?{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackSaysCartersWantedItemWasFound[] =
        "Das Ding, was du wolltest,\r\n"
        "gehört endlich dir.{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterReactsToItemBeingFound[] =
        "Was?\r\n"
        "Du hast eins gefunden?{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackExplainsDifficultyFindingItem[] =
        "Es war nicht leicht, es\r\n"
        "zu finden, aber schließlich \r\n"
        "konnte ich eins bekommen.{Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterThanksZack[] =
        "Vielen Dank. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_ZackAsksCarterToCollectItem[] =
        "Hole es bald ab.\r\n"
        "Tschüss dann. {Press}";

    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_CarterCreditsDreamForGoodFortune[] =
        "Ich denke, die Stimme\r\n"
        "hatte Recht mit meinem\r\n"
        "Glück!{Press}\p"
        "Ich sollte mehr Zeit im\r\n"
        "Beichtstuhl verbringen!{Press}";
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
