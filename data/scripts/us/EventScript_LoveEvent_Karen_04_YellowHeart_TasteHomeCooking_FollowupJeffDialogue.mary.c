#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupJeffDialogue[] =
        "So I have to eat Karen's\r\n"
        "cooking?...{Press}\p"
        "Just the thought makes\r\n"
        "me queasy!{Press}";
};

void EventScript_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupJeffDialogue(void)
{
    if (VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupJeffDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_JEFF, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_JEFF);
}
