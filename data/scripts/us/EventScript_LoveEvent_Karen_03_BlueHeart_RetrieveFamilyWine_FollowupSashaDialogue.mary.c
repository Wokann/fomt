#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupSashaDialogue[] =
        "I had no idea Karen would \r\n"
        "be so happy!{Press}";
};

void EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupSashaDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_SASHA);
}
