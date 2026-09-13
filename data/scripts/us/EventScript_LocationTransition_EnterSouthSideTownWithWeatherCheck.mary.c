#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterSouthSideTownWithWeatherCheck_TyphoonBlocksOutdoorTravel[] =
        "The wind is too strong\r\n"
        "to go outside.{Press}";

    const char gText_LocationTransition_EnterSouthSideTownWithWeatherCheck_SnowstormBlocksOutdoorTravel[] =
        "The snow is too deep\r\n"
        "to go outside.{Press}";
};

void EventScript_LocationTransition_EnterSouthSideTownWithWeatherCheck(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_WEATHER_TODAY) == WEATHER_TYPHOON)
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterSouthSideTownWithWeatherCheck_TyphoonBlocksOutdoorTravel);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
            }
            MoveEntityYTo(ENTITY_PLAYER, Y(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        if (VarGet(VAR_WEATHER_TODAY) == WEATHER_SNOWSTORM)
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterSouthSideTownWithWeatherCheck_SnowstormBlocksOutdoorTravel);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
            }
            MoveEntityYTo(ENTITY_PLAYER, Y(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_SOUTH_SIDE_TOWN, X(548), Y(106));
        SetEntityPosition(ENTITY_PLAYER, X(548), Y(106), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
