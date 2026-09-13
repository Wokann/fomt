#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectShipmentBoxInstructions[] =
        "Lege deine Waren zum Ver-\r\n"
        "sand hinein, du erhältst\r\n"
        "am Abend das Geld dafür.{Press}";
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
