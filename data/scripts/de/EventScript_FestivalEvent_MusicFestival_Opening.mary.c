#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_MusicFestival_Opening(void)
{
    ChangeMap(MAP_CHURCH, X(184), Y(258));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_MUSIC_FESTIVAL);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
    SetEntityPosition(ENTITY_MAY, X(264), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_MARY, X(72), Y(155), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_STU, X(296), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(104), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(72), Y(195), FACING_UP);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(104), Y(155), FACING_UP);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(264), Y(155), FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(67), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_ANN, X(296), Y(155), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_ELLI, EventScript_FestivalEvent_MusicFestival_Dialogue_Elli);
    SetEntityEventScript(ENTITY_CARTER, EventScript_FestivalEvent_MusicFestival_StartPerformanceChoice_Carter);
    SetEntityEventScript(ENTITY_MAY, EventScript_FestivalEvent_MusicFestival_Dialogue_May);
    SetEntityEventScript(ENTITY_ANN, EventScript_FestivalEvent_MusicFestival_Dialogue_Ann);
    SetEntityEventScript(ENTITY_KAREN, EventScript_FestivalEvent_MusicFestival_Dialogue_Karen);
    SetEntityEventScript(ENTITY_MARY, EventScript_FestivalEvent_MusicFestival_Dialogue_Mary);
    SetEntityEventScript(ENTITY_JEFF, EventScript_FestivalEvent_MusicFestival_Dialogue_Jeff);
    SetEntityEventScript(ENTITY_SASHA, EventScript_FestivalEvent_MusicFestival_Dialogue_Sasha);
    SetEntityEventScript(ENTITY_STU, EventScript_FestivalEvent_MusicFestival_Dialogue_Stu);
    VarSet(VAR_MUSIC_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
}
