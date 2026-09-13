#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_Followup_CarterKeepsWantedItemSecret[] =
        "え？アレのことが\r\n"
        "知りたいですって？{Press}\p"
        "ふふふ…秘密です。{Press}";
};

void EventScript_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_FollowupCarterDialogue(void)
{
    if (VarGet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_NPCEvent_Carter_ConfessionalDreamPredictsGoodFortune_Followup_CarterKeepsWantedItemSecret);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_CARTER);
        SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    }
}
