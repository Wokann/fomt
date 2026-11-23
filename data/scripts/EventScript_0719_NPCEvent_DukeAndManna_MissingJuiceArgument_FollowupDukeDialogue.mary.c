#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0719_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupDukeDialogue.mary.h"

void EventScript_0719_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupDukeDialogue(void)
{
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeApologizesForArgumentBeforePlayer);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
    return;
}
