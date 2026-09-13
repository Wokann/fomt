#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_Dialogue_Karen[] =
        "ラ－ラ－…\r\n"
        "うん、だいじょうぶ。{Press}";
};

void EventScript_FestivalEvent_MusicFestival_Dialogue_Karen(void)
{
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_KAREN);
    }
    TalkMessage(gText_FestivalEvent_MusicFestival_Dialogue_Karen);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_KAREN) == FALSE)
    {
        AddNpcFriendship(CHARACTER_KAREN, 5);
    }
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_KAREN);
}
