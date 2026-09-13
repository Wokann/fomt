#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_NewYearsEve_NoodleFestivalOpening(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(20 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_BUCKWHEAT_NOODLES));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(23 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_BUCKWHEAT_NOODLES));
    CreateEventIcon(EVENT_ICON_SLOT_2, X(26 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_BUCKWHEAT_NOODLES));
    CreateEventIcon(EVENT_ICON_SLOT_3, X(29 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_BUCKWHEAT_NOODLES));
    CreateEventIcon(EVENT_ICON_SLOT_4, X(32 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_BUCKWHEAT_NOODLES));
    CreateEventIcon(EVENT_ICON_SLOT_5, X(35 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_BUCKWHEAT_NOODLES));
    if (GetEntityLocation(ENTITY_BASKET) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_BASKET, X(416 + 16), Y(133), FACING_DOWN);
    }
    if (GetEntityLocation(ENTITY_BALL) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_BALL, X(416 + 32), Y(133), FACING_DOWN);
    }
    SetEntityPosition(ENTITY_THOMAS, X(220), Y(128), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_GOTZ, X(376), Y(248), FACING_LEFT);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(372), Y(104), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(80), Y(184), FACING_RIGHT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(112), Y(192), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(320), Y(368), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(304), Y(384), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_ANN, X(156), Y(360), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    EnableScriptedNpcControl();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Thomas);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Gotz);
    SetEntityEventScript(ENTITY_CARTER, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Carter);
    SetEntityEventScript(ENTITY_DUKE, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Duke);
    SetEntityEventScript(ENTITY_MANNA, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Manna);
    SetEntityEventScript(ENTITY_JEFF, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Jeff);
    SetEntityEventScript(ENTITY_SASHA, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Sasha);
    SetEntityEventScript(ENTITY_ANN, EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Ann);
}
