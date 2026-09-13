#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gray_NoPlayerEntryComment[] =
        "Ich habe Opa gebeten, \r\n"
        "dass ich kommen darf! \r\n"
        "Auf wen kann ich setzen...{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gray_SupportsPlayerEntry[] =
        "Rennst du, {Player}?\r\n"
        "Super! Dann setze\r\n"
        "ich auf dich! {Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Gray(void)
{
    if (HasMetNpc(CHARACTER_GRAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GRAY);
    }
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_GRAY);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gray_NoPlayerEntryComment);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_GRAY);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gray_SupportsPlayerEntry);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GRAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GRAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
}
