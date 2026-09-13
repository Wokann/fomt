#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gray_JustLookingAtTheseSheepMakes[] =
        "ふわぁ～、\r\n"
        "羊見ているとねむくなって\r\n"
        "きたぜ。{Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gray_IBetYourSheepHasA[] =
        "おまえの羊が出てるんだって？\r\n"
        "すっげー。{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PreJudgingDialogue_Gray(void)
{
    if (HasMetNpc(CHARACTER_GRAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GRAY);
    }
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_GRAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gray_JustLookingAtTheseSheepMakes);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GRAY_BLUSHING);
        SetTalkNameplateCharacter(CHARACTER_GRAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gray_IBetYourSheepHasA);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GRAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GRAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_UP);
}
