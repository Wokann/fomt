#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeApologizesForArgumentBeforePlayer[] =
        "Sorry, dass du eine so \r\n"
        "hässliche Szene \r\n"
        "mitansehen musstest...{Press}";
};

void EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupDukeDialogue(void)
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
