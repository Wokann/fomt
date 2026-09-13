#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_AchievementEvent_Collection_HarvestGoddessJewelsExchange_GoddessExchangesJewelsForGoddessGem[] =
        "Herzlichen Glückwunsch!\r\n"
        "Du hast alle Juwelen der \r\n"
        "Erntegöttin eingesammelt.{Press}\r\n"
        "Ich erlaube dir, sie gegen \r\n"
        "den Stein der Göttin zu{Press}\p"
        "tauschen. Tschüss dann.{Press}";
};

void EventScript_AchievementEvent_Collection_HarvestGoddessJewelsExchange(void)
{
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    if (X(GetEntityX(ENTITY_PLAYER)) > X(160))
    {
        SetEntityPosition(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER) - 32), FACING_DOWN);
    }
    else
    {
        SetEntityPosition(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER) - 32), FACING_DOWN);
    }
    SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_LEVITATE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    MoveEntityYTo(ENTITY_HARVEST_GODDESS, Y(GetEntityY(ENTITY_PLAYER)), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    if (X(GetEntityX(ENTITY_PLAYER)) > X(160))
    {
        SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_RIGHT);
        WaitFrames(10);
        SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    }
    else
    {
        SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_LEFT);
        WaitFrames(10);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_AchievementEvent_Collection_HarvestGoddessJewelsExchange_GoddessExchangesJewelsForGoddessGem);
    TalkClose();
    SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_DOWN);
    MoveEntityYTo(ENTITY_HARVEST_GODDESS, Y(GetEntityY(ENTITY_PLAYER) - 100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    HideEntity(ENTITY_HARVEST_GODDESS);
    UsePlayerHeldItem();
    RemoveAllOwnedArticles(ITEM_ARTICLE_HARVEST_GODDESS_JEWEL);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
    ShowPlayerHoldingTool(ITEM_TOOL_GEM_GODDESS);
    WaitFrames(50);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    if (GetPlayerHeldToolStackCount() == mary_negated_int(ITEM_TOOL_STACK_NOT_PRESENT))
    {
        SetPlayerHeldTool(ITEM_TOOL_GEM_GODDESS, 1);
    }
    else
    {
        AddToolToRucksack(ITEM_TOOL_GEM_GODDESS, 1);
    }
    VarSet(VAR_HARVEST_GODDESS_JEWEL_EXCHANGE_STATE, EVENT_LIFECYCLE_COMPLETED);
}
