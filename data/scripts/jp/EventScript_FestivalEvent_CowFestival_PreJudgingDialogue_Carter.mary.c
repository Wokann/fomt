#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_PeopleKeepCowsAllOverThe[] =
        "牛は、国によってあつかいが\r\n"
        "ずいぶんちがうんだけれど、\r\n"
        "よく働くし、{Press}\r\n"
        "牛乳も出してくれるから、\r\n"
        "大事にされている事は\r\n"
        "たしかだね。{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Carter_AreYouKeepingGoodCareOf[] =
        "あなたは牛を大事に\r\n"
        "育ててますか？\r\n"
        "愛情をそそがなければ、{Press}\r\n"
        "いい牛を育てることは\r\n"
        "出来ませんよ。{Press}";
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
