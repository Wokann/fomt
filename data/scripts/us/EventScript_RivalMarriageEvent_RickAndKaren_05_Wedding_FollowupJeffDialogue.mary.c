#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupJeffDialogue_JeffCriesOverKarensMarriage[] =
        "Karen...{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupJeffDialogue_JeffPraisesKarenAtWedding[] =
        "Karen's so pretty...{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupJeffDialogue(void)
{
    if (HasMetNpc(CHARACTER_JEFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_JEFF) == FALSE)
    {
        SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupJeffDialogue_JeffCriesOverKarensMarriage);
        TalkClose();
        SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    else
    {
        SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupJeffDialogue_JeffPraisesKarenAtWedding);
        TalkClose();
        SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
}
