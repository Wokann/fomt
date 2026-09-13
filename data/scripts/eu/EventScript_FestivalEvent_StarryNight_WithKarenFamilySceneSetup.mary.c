#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_StarryNight_WithKarenFamilySceneSetup(void)
{
    ChangeMap(MAP_SUPERMARKET, X(145), Y(275));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(145), Y(274), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_KAREN, X(145), Y(227), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(175), Y(115), FACING_DOWN);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(226), Y(115), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
}
