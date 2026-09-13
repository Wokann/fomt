#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_PlayerFindsWhiteFlowerOnMothersHillSummit[] =
        "Ist dies die Weiße Blume,\r\n"
        "von der Ellen gesprochen \r\n"
        "hat?{Press}\p"
        "Du solltest sie ihr bringen.{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_BasilRecognizesFlower[] =
        "Sie ist...{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_StuAdmiresFlower[] =
        "Wunderschön...{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_EllenRealizesPlayerFoundFlower[] =
        "Du hast sie gefunden...{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_EllenConfirmsLegendaryWhiteFlower[] =
        "Das ist die berühmte \r\n"
        "Weiße Blume...{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_BasilLearnsFlowerBloomsOnMothersHillSummit[] =
        "Wo hast du sie gefunden, \r\n"
        "{Player}?{Press}\p"
        "Auf der Bergspitze?\r\n"
        "Da blüht sie also!{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_EllenThanksPlayerAndPromisesToTreasureFlower[] =
        "Danke, {Player}. \r\n"
        "Ich hüte sie. {Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerDiscovery_NarrationEllenIsVeryHappy[] =
        "Du hast Ellen sehr \r\n"
        "glücklich gemacht. {Press}";
};

void EventScript_NPCEvent_Ellen_WhiteFlowerDiscovery(void)
{
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(236), Y(291));
    CreateEventIcon(EVENT_ICON_SLOT_0, X(236), Y(255), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_QUEEN_OF_THE_NIGHT_OR_MYSTERY_FLOWER));
    SetEntityPosition(ENTITY_PLAYER, X(236), Y(443), FACING_UP);
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
    MoveEntityYTo(ENTITY_PLAYER, Y(332), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(283), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60 * 2);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_PlayerFindsWhiteFlowerOnMothersHillSummit);
    TalkClose();
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    ChangeMap(MAP_ELLEN_HOUSE, X(143), Y(114));
    SetEntityPosition(ENTITY_ELLEN, X(128), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_BASIL, X(154), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    SetEntityPosition(ENTITY_STU, X(183), Y(102), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(128), Y(118), FACING_UP);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(128), Y(118 - 21), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_QUEEN_OF_THE_NIGHT_OR_MYSTERY_FLOWER));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_BasilRecognizesFlower);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_StuAdmiresFlower);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_EllenRealizesPlayerFoundFlower);
    TalkClose();
    WaitFrames(60);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PUT_AWAY_PRESENTED_ITEM);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_EllenConfirmsLegendaryWhiteFlower);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_BasilLearnsFlowerBloomsOnMothersHillSummit);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_EllenThanksPlayerAndPromisesToTreasureFlower);
    TalkClose();
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerDiscovery_NarrationEllenIsVeryHappy);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ELLEN);
    MarkNpcSpokenTo(CHARACTER_BASIL);
    AddNpcFriendship(CHARACTER_ELLEN, 20);
    AddNpcFriendship(CHARACTER_BASIL, 20);
    AddNpcFriendship(CHARACTER_STU, 20);
    VarSet(VAR_ELLEN_WHITE_FLOWER_DISCOVERY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
