#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_ThisIsWhereYouPlaceBets[] =
        "Hier kannst du Wetten\r\n"
        "abschließen oder Medail-\r\n"
        "len gegen Preise tauschen. {Press}\p"
        "Sag mir hier auch, ob\r\n"
        "du am Rennen teilnimmst. {Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_YouCanBetEvenIfYou[] =
        "Du kannst sogar wetten, \r\n"
        "wenn du mitmachst. Die\r\n"
        "meisten setzen auf sich. {Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_ThisIsWhereYouPlaceBets);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_YouCanBetEvenIfYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
