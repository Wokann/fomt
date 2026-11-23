#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0720_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupMannaDialogue.mary.h"

void EventScript_0720_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupMannaDialogue(void)
{
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaApologizesForArgumentBeforePlayer);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    return;
}
