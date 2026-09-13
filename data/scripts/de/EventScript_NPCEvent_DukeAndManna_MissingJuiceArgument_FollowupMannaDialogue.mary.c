#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaApologizesForArgumentBeforePlayer[] =
        "Ich entschuldige mich, \r\n"
        "dass wir vor deinen Augen \r\n"
        "gestritten haben, {Press}\r\n"
        "{Player}. {Press}\p"
        "Es ist unentschuldbar...{Press}";
};

void EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupMannaDialogue(void)
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
