#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue_BasilReaffirmsConfidenceAndPlansReply[] =
        "Thanks for helping me be \r\n"
        "confident in myself. Now I \r\n"
        "have to write the letter.{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue_BasilAsksToBeLeftAlone[] =
        "I think I need to be\r\n"
        "alone now. \r\n"
        "{Press}\p"
        "{Press}";
};

void EventScript_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue(void)
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
