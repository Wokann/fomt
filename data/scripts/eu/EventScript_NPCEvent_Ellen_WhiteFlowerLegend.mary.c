#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenGreetsPlayer[] =
        "Hello, {Player}. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenExpectsBasilToVisit[] =
        "Basil is supposed to come\r\n"
        "today, too. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenWelcomesBasil[] =
        "Welcome, Basil. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilThanksEllenForHelpingHisResearch[] =
        "Thanks for assisting \r\n"
        "me, Ellen. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilGreetsPlayer[] =
        "Hi, {Player}. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilInvitesPlayerToHearRarePlantStory[] =
        "Today Ellen is going to tell\r\n"
        "me about a very rare plant. {Press}\p"
        "Why don't you listen, too?{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilChecksPlayerIsReady[] =
        "Alright?{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilTellsEllenHeIsReady[] =
        "I'm ready, Ellen. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenRecallsSummerNightWhiteFlowerStory[] =
        "When I was young, before \r\n"
        "both of you were born...{Press}\p"
        "I heard someone talk of a \r\n"
        "beautiful white flower that\r\n"
        "bloomed on a Summer night.{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenExplainsNoLivingWitnessRemains[] =
        "That flower was called the \r\n"
        "White Flower, and \r\n"
        "there is no one left alive{Press}\r\n"
        "who has seen it. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilResolvesToFindWhiteFlower[] =
        "The White Flower, eh?\r\n"
        "I'd love to find it...{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilAsksPlayerToBringFlowerToEllen[] =
        "If you find it, \r\n"
        "{Player}, will you \r\n"
        "bring it to Ellen for me? {Press}\p"
        "I'll try searching for it \r\n"
        "as well. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilLeavesToResearchFlower[] =
        "I'm going to research \r\n"
        "it more at home. {Press}";
};

void EventScript_NPCEvent_Ellen_WhiteFlowerLegend(void)
{
    ChangeMap(MAP_ELLEN_HOUSE, X(128), Y(119));
    SetEntityPosition(ENTITY_ELLEN, X(128), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_BASIL, X(128), Y(250), FACING_UP);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(128), Y(119), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenGreetsPlayer);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenExpectsBasilToVisit);
    TalkClose();
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
    MoveEntityYTo(ENTITY_BASIL, Y(153), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityFacing(ENTITY_BASIL, FACING_RIGHT);
    MoveEntityXTo(ENTITY_BASIL, X(151), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityFacing(ENTITY_BASIL, FACING_UP);
    MoveEntityYTo(ENTITY_BASIL, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenWelcomesBasil);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilThanksEllenForHelpingHisResearch);
    TalkClose();
    SetEntityFacing(ENTITY_BASIL, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilGreetsPlayer);
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilInvitesPlayerToHearRarePlantStory);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilChecksPlayerIsReady);
    TalkClose();
    SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilTellsEllenHeIsReady);
    TalkClose();
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenRecallsSummerNightWhiteFlowerStory);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenExplainsNoLivingWitnessRemains);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilResolvesToFindWhiteFlower);
    TalkClose();
    SetEntityFacing(ENTITY_BASIL, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilAsksPlayerToBringFlowerToEllen);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilLeavesToResearchFlower);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_BASIL);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityYTo(ENTITY_BASIL, Y(153), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
    MoveEntityXTo(ENTITY_BASIL, X(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityFacing(ENTITY_BASIL, FACING_DOWN);
    MoveEntityYTo(ENTITY_BASIL, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    HideEntity(ENTITY_BASIL);
    MarkNpcSpokenTo(CHARACTER_ELLEN);
    MarkNpcSpokenTo(CHARACTER_BASIL);
    EnableScriptedNpcControl();
    PanCameraTo(X(128), Y(119), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_ELLEN, EventScript_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue);
}
