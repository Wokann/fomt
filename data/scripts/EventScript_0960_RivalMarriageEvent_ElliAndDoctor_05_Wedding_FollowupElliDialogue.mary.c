#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0960_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue.mary.h"

void EventScript_0960_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue(void)
{
    if (HasMetNpc(CHARACTER_ELLI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
    {
        SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliIsHappyHerFeelingsForDoctorAreMutual);
        TalkClose();
        SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    else
    {
        SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliPlansToStudyAndCureEllensLegs);
        TalkClose();
        SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
}
