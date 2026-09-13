#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenGreetsPlayer[] =
        "Hallo, {Player}.{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenExpectsBasilToVisit[] =
        "Basil sollte heute\r\n"
        "auch kommen. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenWelcomesBasil[] =
        "Willkommen, Basil. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilThanksEllenForHelpingHisResearch[] =
        "Danke, dass du mir \r\n"
        "geholfen hast, Ellen. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilGreetsPlayer[] =
        "Hi, {Player}. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilInvitesPlayerToHearRarePlantStory[] =
        "Ellen erzählt heute über\r\n"
        "eine seltene Pflanze. {Press}\p"
        "Warum hörst du nicht zu?{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilChecksPlayerIsReady[] =
        "Ok?{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilTellsEllenHeIsReady[] =
        "Ich bin soweit, Ellen. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenRecallsSummerNightWhiteFlowerStory[] =
        "Als ich jung war, bevor \r\n"
        "ihr beiden geboren wart...{Press}\p"
        "habe ich jemanden von einer\r\n"
        "wunderschönen, weißen\r\n"
        "Blume reden hören, die \r\n"
        "in einer Sommernacht blühte.{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_EllenExplainsNoLivingWitnessRemains[] =
        "Der Name der Blume \r\n"
        "war Weiße Blume und \r\n"
        "kein heute lebender{Press}\r\n"
        "Mensch hat sie je gesehen.{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilResolvesToFindWhiteFlower[] =
        "Die Weiße Blume?\r\n"
        "Ich würde sie gerne finden!{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilAsksPlayerToBringFlowerToEllen[] =
        "Wenn du sie findest, \r\n"
        "{Player}, bringst du\r\n"
        "sie für mich zu Ellen?{Press}\p"
        "Ich versuche sie \r\n"
        "auch zu finden. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_BasilLeavesToResearchFlower[] =
        "Ich untersuche dies \r\n"
        "zu Hause genauer. {Press}";
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
