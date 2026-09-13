#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_BlockFarmExitWhileRidingHorse[] =
        "You can't go outside\r\n"
        "while riding a horse!{Press}";
};

void EventScript_LocationInteraction_BlockFarmExitWhileRidingHorse(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (IsPlayerRidingHorse() == TRUE)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_BlockFarmExitWhileRidingHorse);
            TalkClose();
            return;
        }
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_BARN, X(184), Y(272));
        SetEntityPosition(ENTITY_PLAYER, X(184), Y(272), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
