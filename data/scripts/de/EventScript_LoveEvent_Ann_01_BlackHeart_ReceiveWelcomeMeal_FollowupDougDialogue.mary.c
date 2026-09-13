#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupDougDialogue[] =
        "Komm jederzeit wieder. \r\n"
        "Es wird allerdings nicht\r\n"
        "immer aufs Haus gehen! {Press}";
};

void EventScript_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupDougDialogue(void)
{
    if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupDougDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_DOUG);
}
