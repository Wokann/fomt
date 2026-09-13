#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemEvent_CursedToolPurificationMessage_CursedAxePurified[] =
        "The curse has been\r\n"
        "lifted from the Axe!{Press}";

    const char gText_SystemEvent_CursedToolPurificationMessage_CursedFishingRodPurified[] =
        "The curse has been lifted\r\n"
        "from the Fishing Rod!{Press}";
};

void EventScript_SystemEvent_CursedToolPurificationMessage(void)
{
    int var_0;
    var_0 = GetPlayerHeldToolId();
    ShowPlayerHoldingTool(var_0);
    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
    TalkOpen();
    switch (var_0)
    {
        case ITEM_TOOL_AXE_BLESSED:
            TalkMessage(gText_SystemEvent_CursedToolPurificationMessage_CursedAxePurified);
            break;
        case ITEM_TOOL_FISHING_ROD_BLESSED:
            TalkMessage(gText_SystemEvent_CursedToolPurificationMessage_CursedFishingRodPurified);
            break;
    }
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
}
