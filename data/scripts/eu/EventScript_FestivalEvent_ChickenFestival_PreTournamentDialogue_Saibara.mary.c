#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara_NoPlayerEntryComment[] =
        "Watching the Chickens fight\r\n"
        "so fiercely fills me\r\n"
        "with vigor!{Press}";

    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara_EncouragesPlayersEnteredChicken[] =
        "Let's see what your \r\n"
        "Chicken can do!{Press}";
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
