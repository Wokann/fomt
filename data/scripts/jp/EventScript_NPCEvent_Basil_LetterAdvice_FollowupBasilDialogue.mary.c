#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue_BasilReaffirmsConfidenceAndPlansReply[] =
        "さて、返事でも書くよ。\r\n"
        "キミのおかげだよ。\r\n"
        "ありがとう。{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue_BasilAsksToBeLeftAlone[] =
        "一人にしておいてくれるかな。\r\n"
        "{Press}\p"
        "……………\r\n"
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
