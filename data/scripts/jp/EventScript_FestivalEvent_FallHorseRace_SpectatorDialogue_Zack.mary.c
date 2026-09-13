#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Zack_ItLooksLikeSaibaraLetGray[] =
        "グレイのやつ今日は来てるな。\r\n"
        "よく、じいさんがゆるして\r\n"
        "くれたな。{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Zack_ZackWishesPlayerLuck[] =
        "よぉ、レースに出るんだろ？\r\n"
        "がんばれよ。{Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Zack_ItLooksLikeSaibaraLetGray);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Zack_ZackWishesPlayerLuck);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
}
