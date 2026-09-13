#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCliffDialogue_CliffIsConfusedByCartersRequest[] =
        "What is Carter talking about\r\n"
        "all the sudden?{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCliffDialogue(void)
{
    SetEntityFacing(ENTITY_CLIFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCliffDialogue_CliffIsConfusedByCartersRequest);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_CLIFF);
}
