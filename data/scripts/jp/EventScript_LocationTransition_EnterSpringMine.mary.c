#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterSpringMine(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        GenerateMineFloorLayout(MINE_SPRING, 0);
        ChangeMap(MAP_SPRING_MINE_FLOOR_0, X(120), Y(192));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(192), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
