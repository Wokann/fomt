#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupSashaDialogue[] =
        "牧場、がんばるんだよ。\r\n"
        "こまったら、相談に\r\n"
        "のるからね。{Press}";
};

void EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupSashaDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_SASHA);
}
