#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Zack_GrayWantedToComeTooBut[] =
        "Gray wollte auch \r\n"
        "kommen, aber Saibara  \r\n"
        "hat ihn nicht gelassen. {Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Zack_YoureGoingToRaceGoodLuck[] =
        "Machst du auch mit?\r\n"
        "Viel Glück!{Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Zack_GrayWantedToComeTooBut);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Zack_YoureGoingToRaceGoodLuck);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
}
