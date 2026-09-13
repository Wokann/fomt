#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterMineralBeachWithFestivalDispatch_TyphoonBlocksOutdoorTravel[] =
        "The wind is too strong\r\n"
        "to go outside.{Press}";

    const char gText_LocationTransition_EnterMineralBeachWithFestivalDispatch_SnowstormBlocksOutdoorTravel[] =
        "The snow is too deep\r\n"
        "to go outside.{Press}";
};

void EventScript_LocationTransition_EnterMineralBeachWithFestivalDispatch(void)
{
    int var_0, var_1, var_2;
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_WEATHER_TODAY) == WEATHER_TYPHOON)
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterMineralBeachWithFestivalDispatch_TyphoonBlocksOutdoorTravel);
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
            TalkMessage(gText_LocationTransition_EnterMineralBeachWithFestivalDispatch_SnowstormBlocksOutdoorTravel);
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
        ChangeMap(MAP_MINERAL_BEACH, X(260), Y(504));
        SetEntityPosition(ENTITY_PLAYER, X(260), Y(504), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        if (VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01)
        {
            if (var_2 >= 6 && var_2 < 10)
            {
                CallScript(EventScript_FestivalEvent_BeachDay_DayAnnouncement_SouthEntrance);
            }
            if (var_2 >= 10 && var_2 < 18)
            {
                VarSet(VAR_BEACH_DAY_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                CallScript(EventScript_FestivalEvent_FrisbeeTournament_Opening);
            }
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
