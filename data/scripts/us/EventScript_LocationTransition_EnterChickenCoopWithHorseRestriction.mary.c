#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterChickenCoopWithHorseRestriction[] =
        "You can't go inside\r\n"
        "while riding a horse!{Press}";
};

void EventScript_LocationTransition_EnterChickenCoopWithHorseRestriction(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (IsPlayerRidingHorse() == TRUE)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationTransition_EnterChickenCoopWithHorseRestriction);
            TalkClose();
            return;
        }
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_CHICKEN_COOP, X(120), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
