#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue[] =
        "種とか道具とかわからない\r\n"
        "ことがあったら、\r\n"
        "父さんに言ってね。{Press}";
};

void EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue(void)
{
    if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_KAREN);
}
