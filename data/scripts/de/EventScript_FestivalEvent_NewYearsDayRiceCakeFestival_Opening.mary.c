#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_NewYearsDayRiceCakeFestival_Opening(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
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
    SetEntityPosition(ENTITY_ANN, X(156), Y(360), FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(252), Y(88), FACING_DOWN);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(80), Y(392), FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_MAY, X(320), Y(368), FACING_DOWN);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_STU, X(304), Y(384), FACING_RIGHT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(164), Y(328), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(80), Y(184), FACING_DOWN);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(112), Y(192), FACING_LEFT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_GOTZ, X(376), Y(248), FACING_LEFT);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(376), Y(360), FACING_LEFT);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(372), Y(104), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    EnableScriptedNpcControl();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Thomas);
    SetEntityEventScript(ENTITY_ANN, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Ann);
    SetEntityEventScript(ENTITY_SAIBARA, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Saibara);
    SetEntityEventScript(ENTITY_ELLI, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Elli);
    SetEntityEventScript(ENTITY_MAY, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_May);
    SetEntityEventScript(ENTITY_STU, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Stu);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Doug);
    SetEntityEventScript(ENTITY_DUKE, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Duke);
    SetEntityEventScript(ENTITY_MANNA, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Manna);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Gotz);
    SetEntityEventScript(ENTITY_ZACK, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Zack);
    SetEntityEventScript(ENTITY_CARTER, EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Carter);
}
