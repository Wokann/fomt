#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackLookedSad[] =
        "ザクちゃん、帰るとき元気\r\n"
        "なかったわね～。\r\n"
        "どうかしたのかしら～？{Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackIsNervousAroundHer[] =
        "ザクちゃんって、\r\n"
        "わたしの前ではいつもオドオド\r\n"
        "するのよ～。{Press}\p"
        "なんでなのかな～？{Press}";
};

void EventScript_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue(void)
{
    SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    if (WasNpcSpokenToJustNow(CHARACTER_LILLIA) == FALSE)
    {
        TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackLookedSad);
    }
    else
    {
        TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackIsNervousAroundHer);
    }
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
    return;
}
