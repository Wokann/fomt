#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara_YouMustBecomeOneWithThe[] =
        "馬はいい。一心にゴールを\r\n"
        "目ざす心がすばらしい。{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara_YouMustBelieveInYourself[] =
        "今までやってきたことを信じて\r\n"
        "やってみることだな。{Press}";
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
