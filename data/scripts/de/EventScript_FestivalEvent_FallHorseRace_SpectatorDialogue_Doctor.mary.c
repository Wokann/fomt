#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor_LilliaSaidSheWantedToCome[] =
        "Lillia sagte, sie wollte \r\n"
        "sich die Pferde ansehen. {Press}\p"
        "Ich bin mitgekommen,\r\n"
        "falls sie sich erkältet.{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor_PleaseTryNotToHurtYourselves[] =
        "Verletzt euch bitte \r\n"
        "bloß nicht!{Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor(void)
{
    if (HasMetNpc(CHARACTER_DOCTOR) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor_LilliaSaidSheWantedToCome);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor_PleaseTryNotToHurtYourselves);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOCTOR) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOCTOR, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    SetEntityFacing(ENTITY_DOCTOR, FACING_LEFT);
}
