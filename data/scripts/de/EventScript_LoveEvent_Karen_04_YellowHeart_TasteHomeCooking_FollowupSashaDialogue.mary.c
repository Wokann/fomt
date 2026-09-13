#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupSashaDialogue[] =
        "Wo habe ich diese Magen- \r\n"
        "medizin hingetan...{Press}";
};

void EventScript_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupSashaDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_SASHA, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_SASHA);
}
