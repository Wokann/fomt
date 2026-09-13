#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupDougDialogue_DougTellsPlayerCliffMovedIntoTheInn[] =
        "おう、{Player}。\r\n"
        "今日からクリフが住むことに\r\n"
        "なったんだ。よろしくな。{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupDougDialogue(void)
{
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupDougDialogue_DougTellsPlayerCliffMovedIntoTheInn);
    TalkClose();
    SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_DOUG);
}
