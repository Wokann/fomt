#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Harris_LookingAtTheseSheepJustPuts[] =
        "これだけりっぱな羊がいると、\r\n"
        "見ていて気分がいいですね。{Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Harris_IllBePrayingForYourSheep[] =
        "優勝出来るといいですね。\r\n"
        "わたしも祈ってますよ。{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PreJudgingDialogue_Harris(void)
{
    if (HasMetNpc(CHARACTER_HARRIS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Harris_LookingAtTheseSheepJustPuts);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Harris_IllBePrayingForYourSheep);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_HARRIS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_HARRIS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_DOWN);
}
