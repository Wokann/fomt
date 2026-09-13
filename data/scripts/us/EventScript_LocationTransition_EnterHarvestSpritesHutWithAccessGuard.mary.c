#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterHarvestSpritesHutWithAccessGuard_DoorIsLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationTransition_EnterHarvestSpritesHutWithAccessGuard(void)
{
    int var_0, var_1;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_HOUR);
        if (GetEntityLocation(ENTITY_STAID) != MAP_HARVEST_SPRITES_HUT && GetEntityLocation(ENTITY_NAPPY) != MAP_HARVEST_SPRITES_HUT && GetEntityLocation(ENTITY_BOLD) != MAP_HARVEST_SPRITES_HUT && GetEntityLocation(ENTITY_CHEF) != MAP_HARVEST_SPRITES_HUT && GetEntityLocation(ENTITY_AQUA) != MAP_HARVEST_SPRITES_HUT && GetEntityLocation(ENTITY_HOGGY) != MAP_HARVEST_SPRITES_HUT && GetEntityLocation(ENTITY_TIMID) != MAP_HARVEST_SPRITES_HUT)
        {
            var_0 = FALSE;
        }
        else
        {
            if (var_1 >= 9 && var_1 < 18)
            {
                var_0 = TRUE;
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_HARVEST_SPRITES_HUT, X(120), Y(208));
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterHarvestSpritesHutWithAccessGuard_DoorIsLocked);
            TalkClose();
        }
    }
}
