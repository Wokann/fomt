#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_ClinicDoctorRoomLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationInteraction_ClinicDoctorRoomLocked(void)
{
    int var_0;
    var_0 = FALSE;
    if (GetNpcFriendship(CHARACTER_DOCTOR) <= 100)
    {
        var_0 = FALSE;
    }
    else
    {
        var_0 = TRUE;
    }
    if (var_0 == TRUE)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        OpenDoor(DOOR_SLOT_7);
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_ClinicDoctorRoomLocked);
        TalkClose();
    }
}
