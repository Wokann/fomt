#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_HarvestFestival_JudgingSceneSetup(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(198), Y(232));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetEntityPosition(ENTITY_PLAYER, X(198), Y(232), FACING_DOWN);
    SetEntityPosition(ENTITY_MANNA, X(60), Y(392), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(78), Y(368), FACING_DOWN);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_MARY, X(262), Y(280), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(222), Y(232), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(100), Y(392), FACING_LEFT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(150), Y(200), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(158), Y(160), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(362), Y(84), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(286), Y(248), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_ANN, X(286), Y(200), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_GOTZ, X(354), Y(160), FACING_LEFT);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_HARVEST_FESTIVAL_SESSION_PHASE, HARVEST_FESTIVAL_SESSION_JUDGING_STARTED);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_HarvestFestival_Dialogue_Thomas);
    SetEntityEventScript(ENTITY_ELLI, EventScript_FestivalEvent_HarvestFestival_Dialogue_Elli);
    SetEntityEventScript(ENTITY_CARTER, EventScript_FestivalEvent_HarvestFestival_Dialogue_Carter);
    SetEntityEventScript(ENTITY_ANN, EventScript_FestivalEvent_HarvestFestival_Dialogue_Ann);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_FestivalEvent_HarvestFestival_Dialogue_Gotz);
    SetEntityEventScript(ENTITY_KAREN, EventScript_FestivalEvent_HarvestFestival_Dialogue_Karen);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_HarvestFestival_Dialogue_Doug);
    SetEntityEventScript(ENTITY_MARY, EventScript_FestivalEvent_HarvestFestival_Dialogue_Mary);
    SetEntityEventScript(ENTITY_SASHA, EventScript_FestivalEvent_HarvestFestival_Dialogue_Sasha);
    SetEntityEventScript(ENTITY_ANNA, EventScript_FestivalEvent_HarvestFestival_Dialogue_Anna);
    SetEntityEventScript(ENTITY_MANNA, EventScript_FestivalEvent_HarvestFestival_Dialogue_Manna);
    VarSet(VAR_HARVEST_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
}
