#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Rick_IsItJustMeOrAre[] =
        "Finde das nur ich oder\r\n"
        "sind Schafaugen gruselig?{Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Rick_AreYouGoingToEnterA[] =
        "Lässt du ein Schaf\r\n"
        "mitmachen? Viel Glück!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PreJudgingDialogue_Rick(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Rick_IsItJustMeOrAre);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Rick_AreYouGoingToEnterA);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_RICK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_RICK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
}
