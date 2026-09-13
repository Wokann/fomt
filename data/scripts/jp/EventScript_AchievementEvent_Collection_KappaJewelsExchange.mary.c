#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_AchievementEvent_Collection_KappaJewelsExchange_KappaExchangesJewelsForKappaGem[] =
        "…おまえ、\r\n"
        "かっぱの玉、全部あつめた。{Press}\p"
        "『かっぱの秘宝』と\r\n"
        "交換してやる。{Press}\p"
        "もう来るな。{Press}";
};

void EventScript_AchievementEvent_Collection_KappaJewelsExchange(void)
{
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    if (X(GetEntityX(ENTITY_PLAYER)) > X(160))
    {
        SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
    }
    else
    {
        SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
    }
    SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    if (X(GetEntityX(ENTITY_PLAYER)) > X(160))
    {
        SetEntityFacing(ENTITY_KAPPA, FACING_RIGHT);
        WaitFrames(10);
        SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    }
    else
    {
        SetEntityFacing(ENTITY_KAPPA, FACING_LEFT);
        WaitFrames(10);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAPPA);
    SetTalkPortrait(TALK_PORTRAIT_KAPPA_NORMAL);
    TalkMessage(gText_AchievementEvent_Collection_KappaJewelsExchange_KappaExchangesJewelsForKappaGem);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_KAPPA);
    UsePlayerHeldItem();
    RemoveAllOwnedArticles(ITEM_ARTICLE_KAPPA_JEWEL);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
    ShowPlayerHoldingTool(ITEM_TOOL_GEM_KAPPA);
    WaitFrames(50);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    if (GetPlayerHeldToolStackCount() == mary_negated_int(ITEM_TOOL_STACK_NOT_PRESENT))
    {
        SetPlayerHeldTool(ITEM_TOOL_GEM_KAPPA, 1);
    }
    else
    {
        AddToolToRucksack(ITEM_TOOL_GEM_KAPPA, 1);
    }
    VarSet(VAR_KAPPA_JEWEL_EXCHANGE_STATE, EVENT_LIFECYCLE_COMPLETED);
}
