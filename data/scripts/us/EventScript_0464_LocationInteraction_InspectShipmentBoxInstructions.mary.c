#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0464_LocationInteraction_InspectShipmentBoxInstructions.mary.h"

void EventScript_0464_LocationInteraction_InspectShipmentBoxInstructions(void)
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
