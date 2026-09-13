#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Stu_ThisCowIsSoBigAnd[] =
        "This Cow is so big and \r\n"
        "strong!!\r\n"
        "I bet it would flatten you \r\n"
        "if you got stepped on!{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Stu_YourCowLooksLikeAWinner[] =
        "Your cow looks like a winner\r\n"
        "to me, {Player}. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Stu(void)
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
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Stu_ThisCowIsSoBigAnd);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Stu_YourCowLooksLikeAWinner);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_STU) == FALSE)
    {
        AddNpcFriendship(CHARACTER_STU, 5);
    }
    MarkNpcSpokenTo(CHARACTER_STU);
    SetEntityFacing(ENTITY_STU, FACING_UP);
}
