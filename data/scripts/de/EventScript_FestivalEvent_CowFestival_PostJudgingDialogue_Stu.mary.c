#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_NoPlayerEntryComment[] =
        "Meine Schwester ist böse\r\n"
        "geworden, als ich versucht \r\n"
        "habe, auf der hübschen {Press}\r\n"
        "Kuh zu reiten. {Press}\p"
        "Sie ist so gemein...{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_CongratulatesPlayerVictory[] =
        "Toll, dass du \r\n"
        "gewonnen hast!\r\n"
        "Kann ich deine Kuh reiten?{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_RespondsToPlayerLoss[] =
        "Tut mir Leid, dass \r\n"
        "du verloren hast.\r\n"
        "Ich wette, du kannst {Press}\r\n"
        "nächstes Jahr gewinnen!{Press}";
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
