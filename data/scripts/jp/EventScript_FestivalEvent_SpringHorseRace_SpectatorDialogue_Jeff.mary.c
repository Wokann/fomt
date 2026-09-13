#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Jeff_ICantBelieveYouAllArent[] =
        "馬に乗って走るなんて、\r\n"
        "ボクには考えられないよ。\r\n"
        "みんなすごいなぁ。{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Jeff_PleaseJustDontGetHurt[] =
        "くれぐれも、ケガだけは\r\n"
        "しないようにね。{Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Jeff(void)
{
    if (HasMetNpc(CHARACTER_JEFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Jeff_ICantBelieveYouAllArent);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Jeff_PleaseJustDontGetHurt);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_JEFF) == FALSE)
    {
        AddNpcFriendship(CHARACTER_JEFF, 5);
    }
    MarkNpcSpokenTo(CHARACTER_JEFF);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
}
