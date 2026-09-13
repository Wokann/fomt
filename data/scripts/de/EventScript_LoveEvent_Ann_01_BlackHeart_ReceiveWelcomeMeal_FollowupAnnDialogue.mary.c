#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupAnnDialogue[] =
        "Komm mal wieder!{Press}";
};

void EventScript_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupAnnDialogue(void)
{
    if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupAnnDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_ANN);
}
