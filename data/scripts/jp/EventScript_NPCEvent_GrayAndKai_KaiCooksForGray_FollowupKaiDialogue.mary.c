#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiReflectsOnGraysFirstRestaurantVisit[] =
        "グレイとは宿屋でも\r\n"
        "結構話すんだよ。{Press}\p"
        "店にきてくれたのは、\r\n"
        "はじめてだけどな。{Press}";
};

void EventScript_NPCEvent_GrayAndKai_KaiCooksForGray_FollowupKaiDialogue(void)
{
    if (VarGet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiReflectsOnGraysFirstRestaurantVisit);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_KAI);
        SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    }
}
