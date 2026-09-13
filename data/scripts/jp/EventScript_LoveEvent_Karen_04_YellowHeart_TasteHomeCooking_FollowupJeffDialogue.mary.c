#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupJeffDialogue[] =
        "ああ…\r\n"
        "カレンの料理を食べなくちゃ\r\n"
        "ダメなのか…{Press}\p"
        "考えただけで\r\n"
        "胃が痛くなってきたよ…{Press}";
};

void EventScript_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupJeffDialogue(void)
{
    if (VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupJeffDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_JEFF, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_JEFF);
}
