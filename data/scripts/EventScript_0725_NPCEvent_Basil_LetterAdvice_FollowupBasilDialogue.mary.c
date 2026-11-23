#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0725_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue.mary.h"

void EventScript_0725_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue(void)
{
    SetEntityFacing(ENTITY_BASIL, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    if (VarGet(VAR_BASIL_LETTER_ADVICE_CHOICE) == BASIL_LETTER_ADVICE_EXPLAIN_ERROR)
    {
        SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
        TalkMessage(gText_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue_BasilReaffirmsConfidenceAndPlansReply);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_BASIL_AFRAID);
        TalkMessage(gText_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue_BasilAsksToBeLeftAlone);
    }
    MarkNpcSpokenTo(CHARACTER_BASIL);
    TalkClose();
    SetEntityFacing(ENTITY_BASIL, FACING_UP);
    return;
}
