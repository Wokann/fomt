#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_StoppedFight_DukeApologizesForJoiningFight[] =
        "I shouldn't have gotten \r\n"
        "dragged into that fight. \r\n"
        "Sorry. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_NotIntervened_DukeWarnsPlayerAwayFromDoug[] =
        "I wouldn't talk to him now,\r\n"
        "if I were you. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_NotIntervened_DukeChallengesDougToSettleFight[] =
        "Let's settle this once and\r\n"
        "for all!{Press}";
};

void EventScript_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue(void)
{
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE) == DOUG_DUKE_ARGUMENT_STOP_FIGHT)
    {
        SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_StoppedFight_DukeApologizesForJoiningFight);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_NotIntervened_DukeWarnsPlayerAwayFromDoug);
        SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_NotIntervened_DukeChallengesDougToSettleFight);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
    return;
}
