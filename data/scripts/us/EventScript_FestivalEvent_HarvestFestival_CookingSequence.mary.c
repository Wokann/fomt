#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_HarvestFestival_CookingSequence(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(222), Y(200));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetEntityPosition(ENTITY_PLAYER, X(198), Y(232), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
    SetPlayerHeldFood(ITEM_FOOD_STEW);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    SetEntityPosition(ENTITY_MARY, X(262), Y(280), FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(150), Y(200), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(158), Y(160), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(286), Y(248), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_ANN, X(286), Y(200), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(222), Y(232), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(60), Y(392), FACING_DOWN);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(78), Y(368), FACING_DOWN);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(100), Y(392), FACING_DOWN);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(362), Y(84), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_GOTZ, X(354), Y(160), FACING_DOWN);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60 * 2);
    PlaySong(AUDIO_START, AUDIO_SFX_EAT);
    ClearPlayerHeldItem();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_EAT);
    WaitFrames(24);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(60);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == FALSE)
    {
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_GOOD, FALSE);
        WaitFrames(60 * 4);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        SetGameTime(18, 0);
        CallScript(EventScript_FestivalEvent_HarvestFestival_JudgingSceneSetup);
    }
    else
    {
        FadeOutScreen(SCREEN_FADE_STYLE_MOSAIC, SCREEN_FADE_SPEED_FAST);
        FadeInScreen(SCREEN_FADE_STYLE_MOSAIC, SCREEN_FADE_SPEED_FAST);
        WaitFrames(30);
        FadeOutScreen(SCREEN_FADE_STYLE_MOSAIC, SCREEN_FADE_SPEED_FAST);
        FadeInScreen(SCREEN_FADE_STYLE_MOSAIC, SCREEN_FADE_SPEED_FAST);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_COLLAPSE);
        WaitFrames(36);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        SetGameTime(18, 0);
        CallScript(EventScript_FestivalEvent_HarvestFestival_JudgingSceneSetup);
    }
}
