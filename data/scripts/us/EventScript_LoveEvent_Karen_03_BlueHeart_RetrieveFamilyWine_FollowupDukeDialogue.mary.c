#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupDukeDialogue[] =
        "Jeff will probably come \r\n"
        "pick them up, but I doubt \r\n"
        "he'll be able to carry them.{Press}\p"
        "He asked me to make 3 \r\n"
        "crates, then forgot about \r\n"
        "all about 'em!{Press}";
};

void EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupDukeDialogue(void)
{
    if (VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupDukeDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_DUKE);
}
