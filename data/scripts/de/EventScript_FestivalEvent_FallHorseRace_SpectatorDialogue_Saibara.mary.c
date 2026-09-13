#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara_YouMustBecomeOneWithThe[] =
        "Du musst eins mit dem \r\n"
        "Pferd werden, wenn du auf\r\n"
        "dein Ziel zustürmst. {Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara_YouMustBelieveInYourself[] =
        "Du musst an dich\r\n"
        "glauben. {Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara(void)
{
    if (HasMetNpc(CHARACTER_SAIBARA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SAIBARA);
    }
    SetEntityFacing(ENTITY_SAIBARA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara_YouMustBecomeOneWithThe);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara_YouMustBelieveInYourself);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SAIBARA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SAIBARA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SAIBARA);
    SetEntityFacing(ENTITY_SAIBARA, FACING_RIGHT);
}
