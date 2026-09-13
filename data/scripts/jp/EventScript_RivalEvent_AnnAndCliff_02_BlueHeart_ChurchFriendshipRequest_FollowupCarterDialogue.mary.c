#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCarterDialogue_CarterTrustsAnnToHelpCliff[] =
        "ランさんにたのんでおけば、\r\n"
        "安心でしょう。{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCarterDialogue(void)
{
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCarterDialogue_CarterTrustsAnnToHelpCliff);
    TalkClose();
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_CARTER);
}
