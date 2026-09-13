#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara_NoPlayerEntryComment[] =
        "Die Hühner so tapfer \r\n"
        "kämpfen zu sehen, erfüllt\r\n"
        "mich mit Stolz!{Press}";

    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara_EncouragesPlayersEnteredChicken[] =
        "Dann zeig mal, was \r\n"
        "dein Huhn kann!{Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara(void)
{
    if (HasMetNpc(CHARACTER_SAIBARA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SAIBARA);
    }
    SetEntityFacing(ENTITY_SAIBARA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara_NoPlayerEntryComment);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara_EncouragesPlayersEnteredChicken);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SAIBARA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SAIBARA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SAIBARA);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
}
