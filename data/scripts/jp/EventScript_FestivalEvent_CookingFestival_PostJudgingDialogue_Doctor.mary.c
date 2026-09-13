#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Doctor[] =
        "やっぱり健康を考えた\r\n"
        "メニューがいいだろうね。{Press}\p"
        "まぁ、１品では\r\n"
        "それもむずかしいけど。{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PostJudgingDialogue_Doctor(void)
{
    if (HasMetNpc(CHARACTER_DOCTOR) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Doctor);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOCTOR) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOCTOR, 5);
    }
    SetEntityFacing(ENTITY_DOCTOR, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
}
