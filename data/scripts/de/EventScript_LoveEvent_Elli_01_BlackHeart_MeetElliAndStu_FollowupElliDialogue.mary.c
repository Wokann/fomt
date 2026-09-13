#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupElliDialogue[] =
        "Das Kind war immer so\r\n"
        "zierlich!{Press}";
};

void EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupElliDialogue(void)
{
    if (VarGet(VAR_ELLI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupElliDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_ELLI);
}
