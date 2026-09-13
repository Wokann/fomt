#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_NoPlayerEntryComment[] =
        "Sis got mad at me when I \r\n"
        "tried to ride the pretty \r\n"
        "Cow. {Press}\p"
        "She's such a meany...{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_CongratulatesPlayerVictory[] =
        "It's great you won!\r\n"
        "Can I ride your Cow now? {Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_RespondsToPlayerLoss[] =
        "I'm sorry you lost.\r\n"
        "I bet you could win next\r\n"
        "year, though!{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Stu(void)
{
    if (HasMetNpc(CHARACTER_STU) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_STU);
    }
    SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_NoPlayerEntryComment);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_CongratulatesPlayerVictory);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_RespondsToPlayerLoss);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_STU) == FALSE)
    {
        AddNpcFriendship(CHARACTER_STU, 5);
    }
    MarkNpcSpokenTo(CHARACTER_STU);
    SetEntityFacing(ENTITY_STU, FACING_UP);
}
