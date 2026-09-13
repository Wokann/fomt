#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectShipmentBoxInstructions[] =
        "出荷箱\r\n"
        "ここに出荷する物を入れると\r\n"
        "夕方にはお金に変わってる。{Press}";
};

void EventScript_LocationInteraction_InspectShipmentBoxInstructions(void)
{
    if (IsPlayerHoldingNothing())
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectShipmentBoxInstructions);
        TalkClose();
    }
    else
    {
        if (TryShipPlayerHeldItem())
        {
            PlaySong(AUDIO_START, AUDIO_SFX_SHIPMENT_DEPOSIT);
            StartShipmentBoxDepositAnimation();
        }
    }
}
