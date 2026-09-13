#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupJeffDialogue[] =
        "牧場がんばってね。{Press}";
};

void EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupJeffDialogue(void)
{
    if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupJeffDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_JEFF);
}
