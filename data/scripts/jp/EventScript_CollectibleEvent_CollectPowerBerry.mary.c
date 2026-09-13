#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_CollectibleEvent_CollectPowerBerry_YouFoundAPowerBerry[] =
        "力の木の実を見つけた。\r\n"
        "{Press}";

    const char gText_CollectibleEvent_CollectPowerBerry_ButYourHandsAreAlreadyFull[] =
        "…んだけど、手に物を持って\r\n"
        "いるので持てない。{Press}";

    const char gText_CollectibleEvent_CollectPowerBerry_AlreadyCollected[] =
        "もう何もない。\r\n"
        "{Press}";
};

void EventScript_CollectibleEvent_CollectPowerBerry(void)
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
