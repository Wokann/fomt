#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Jeff_WonOffersToBuyPainting_FollowupSashaDialogue_SashaPraisesJeffsPaintingTalent[] =
        "ちゃんと信念を持って絵を\r\n"
        "描いてたんだねぇ。\r\n"
        "カッコよく見えたよ。{Press}";
};

void EventScript_NPCEvent_Jeff_WonOffersToBuyPainting_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_NPCEvent_Jeff_WonOffersToBuyPainting_FollowupSashaDialogue_SashaPraisesJeffsPaintingTalent);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_SASHA);
        SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    }
}
