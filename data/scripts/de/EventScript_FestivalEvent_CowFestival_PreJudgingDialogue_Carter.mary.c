#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_PeopleKeepCowsAllOverThe[] =
        "Auf der ganzen Welt \r\n"
        "werden Kühe gehalten. {Press}\r\n"
        "Sie geben Milch und \r\n"
        "arbeiten hart. Kein \r\n"
        "Wunder, dass die Leute {Press}\r\n"
        "sich auf sie verlassen. {Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_AreYouKeepingGoodCareOf[] =
        "Pflegst du deine Kühe\r\n"
        "auch gut? Du musst \r\n"
        "ihnen viel Aufmerksamkeit{Press}\r\n"
        "schenken. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Carter(void)
{
    if (HasMetNpc(CHARACTER_CARTER) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_PeopleKeepCowsAllOverThe);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_AreYouKeepingGoodCareOf);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_CARTER) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CARTER, 5);
    }
    MarkNpcSpokenTo(CHARACTER_CARTER);
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
}
