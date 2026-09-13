#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_PeopleKeepCowsAllOverThe[] =
        "People keep Cows all over \r\n"
        "the world, you know. {Press}\r\n"
        "They give Milk, and they \r\n"
        "work hard. No wonder people\r\n"
        "depend on them so much. {Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_AreYouKeepingGoodCareOf[] =
        "Are you keeping good care of\r\n"
        "your Cows? You have to give\r\n"
        "them lots of attention, {Press}\r\n"
        "you know. {Press}";
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
