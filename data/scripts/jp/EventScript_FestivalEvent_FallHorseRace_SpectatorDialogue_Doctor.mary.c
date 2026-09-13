#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor_LilliaSaidSheWantedToCome[] =
        "リリアさんが馬を見たいって\r\n"
        "いうからついて来たんだ。{Press}\p"
        "外に出て気分が悪くなっても\r\n"
        "いけないからね。{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor_PleaseTryNotToHurtYourselves[] =
        "がんばるのはいいけど、\r\n"
        "ケガだけには注意しろよ。{Press}";
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
