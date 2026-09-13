#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnRickGrowingUp[] =
        "Warum ist es so über-\r\n"
        "raschend, wie schnell \r\n"
        "die Kinder wachsen?!...{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaHopesRecoveryWillBringRodHome[] =
        "Wenn es mir nur besser\r\n"
        "gehen würde, so dass \r\n"
        "mein Mann wiederkommen {Press}\r\n"
        "könnte...{Press}\p"
        "Wenn er hier bei mir\r\n"
        "wäre, wäre alles gut...{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue(void)
{
    if (HasMetNpc(CHARACTER_LILLIA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_LILLIA) == FALSE)
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnRickGrowingUp);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    else
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaHopesRecoveryWillBringRodHome);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
}
