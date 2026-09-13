#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupSashaDialogue_SashaIsEmbarrassedPlayerOverheard[] =
        "聞いてたのかい？\r\n"
        "やだよ、\r\n"
        "はずかしいじゃないか。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupSashaDialogue_SashaSaysSheCouldNeverLeaveJeffAlone[] =
        "ジェフって昔から\r\n"
        "放っておけない\r\n"
        "タイプだったんだよ。{Press}";
};

void EventScript_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        if (WasNpcSpokenToJustNow(CHARACTER_SASHA) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupSashaDialogue_SashaIsEmbarrassedPlayerOverheard);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupSashaDialogue_SashaSaysSheCouldNeverLeaveJeffAlone);
        }
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_SASHA);
        SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    }
}
