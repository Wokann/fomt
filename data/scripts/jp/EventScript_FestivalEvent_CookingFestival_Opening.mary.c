#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_CookingFestival_Opening(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetEntityPosition(ENTITY_THOMAS, X(180), Y(102), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_GOURMET, X(220), Y(118), FACING_DOWN);
    SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(316), Y(294), FACING_UP);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(284), Y(326), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(316), Y(350), FACING_LEFT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_GOTZ, X(116), Y(196), FACING_UP);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(308), Y(98), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(68), Y(172), FACING_RIGHT);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_LILLIA, X(100), Y(244), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(348), Y(174), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_ANN, X(320), Y(198), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(68), Y(244), FACING_RIGHT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(148), Y(350), FACING_UP);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    if (GetEntityLocation(ENTITY_BASKET) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_BASKET, X(416 + 16), Y(133), FACING_DOWN);
    }
    if (GetEntityLocation(ENTITY_BALL) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_BALL, X(416 + 32), Y(133), FACING_DOWN);
    }
    if (GetEntityLocation(ENTITY_FARM_DOG) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_FARM_DOG, X(416), Y(133), FACING_DOWN);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Thomas);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Doctor);
    SetEntityEventScript(ENTITY_CARTER, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Carter);
    SetEntityEventScript(ENTITY_GOURMET, EventScript_FestivalEvent_CookingFestival_ThemeAnnouncement);
    SetEntityEventScript(ENTITY_ZACK, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack);
    SetEntityEventScript(ENTITY_ANN, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Ann);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Gotz);
    SetEntityEventScript(ENTITY_KAREN, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Karen);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Doug);
    SetEntityEventScript(ENTITY_SASHA, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Sasha);
    SetEntityEventScript(ENTITY_MANNA, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna);
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Rick);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Lillia);
    VarSet(VAR_COOKING_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
}
