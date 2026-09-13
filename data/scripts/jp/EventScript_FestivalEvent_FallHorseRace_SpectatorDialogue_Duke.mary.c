#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke_HaveYouPlacedYourBetWith[] =
        "ちゃんとチケットは買ったか？\r\n"
        "町長のところで買えるからな。{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke_IllBeBettingOnYouSo[] =
        "お前のチケット買うからな。\r\n"
        "勝ってくれよ！{Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke(void)
{
    if (HasMetNpc(CHARACTER_DUKE) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke_HaveYouPlacedYourBetWith);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke_IllBeBettingOnYouSo);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DUKE) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DUKE, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
}
