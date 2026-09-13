#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationInteraction_OpenInnDoorEntity04(void)
{
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    OpenDoor(DOOR_SLOT_4);
}
