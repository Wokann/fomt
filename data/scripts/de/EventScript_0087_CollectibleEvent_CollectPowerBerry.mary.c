#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0087_CollectibleEvent_CollectPowerBerry.mary.h"

void EventScript_0087_CollectibleEvent_CollectPowerBerry(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_COLLECT_POWER_BERRY_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
        {
            TalkOpen();
            TalkMessage(gText_CollectibleEvent_CollectPowerBerry_YouFoundAPowerBerry);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                TalkClose();
                PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                ObtainPowerBerry();
                VarSet(VAR_COLLECT_POWER_BERRY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            }
            else
            {
                TalkMessage(gText_CollectibleEvent_CollectPowerBerry_ButYourHandsAreAlreadyFull);
                TalkClose();
            }
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_CollectibleEvent_CollectPowerBerry_AlreadyCollected);
            TalkClose();
        }
    }
}
