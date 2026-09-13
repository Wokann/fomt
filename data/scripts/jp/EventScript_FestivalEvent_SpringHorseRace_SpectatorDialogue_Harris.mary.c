#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Harris_MeIJustLikeLookingAt[] =
        "草競馬は、みなさんが育てた\r\n"
        "馬を見られる機会でも\r\n"
        "あります。{Press}\p"
        "そういう意味でも\r\n"
        "楽しみですよ。{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Harris_LooksLikeItsAboutToStart[] =
        "いよいよですね、\r\n"
        "がんばって下さい。{Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Harris(void)
{
    if (HasMetNpc(CHARACTER_HARRIS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Harris_MeIJustLikeLookingAt);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Harris_LooksLikeItsAboutToStart);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_HARRIS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_HARRIS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_DOWN);
}
