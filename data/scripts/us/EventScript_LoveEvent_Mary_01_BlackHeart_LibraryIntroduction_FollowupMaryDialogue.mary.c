#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction_FollowupMaryDialogue[] =
        "Read any book you want. {Press}";
};

void EventScript_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction_FollowupMaryDialogue(void)
{
    if (VarGet(VAR_MARY_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction_FollowupMaryDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_MARY);
}
