#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenPraisesElliAndUrgesHerToPrioritizeHerNewFamily[] =
        "Elli, you are such a \r\n"
        "beautiful bride...!{Press}\p"
        "You've only thought about \r\n"
        "me and Stu, but now you \r\n"
        "have to concentrate on your{Press}\r\n"
        "new family. {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenWantsToLiveToSeeStuMarry[] =
        "Watching Elli get married\r\n"
        "has made me determined to\r\n"
        "live to see Stu married! {Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue(void)
{
    if (HasMetNpc(CHARACTER_ELLEN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_ELLEN) == FALSE)
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenPraisesElliAndUrgesHerToPrioritizeHerNewFamily);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
    else
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenWantsToLiveToSeeStuMarry);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
}
