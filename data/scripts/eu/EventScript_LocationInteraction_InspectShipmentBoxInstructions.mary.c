#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectShipmentBoxInstructions[] =
        "Shipment Box\r\n"
        "Put things here to ship,\r\n"
        "and by evening you'll{Press}\r\n"
        "recieve payment.{Press}";
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
