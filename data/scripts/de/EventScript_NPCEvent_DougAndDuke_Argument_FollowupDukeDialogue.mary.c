#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_StoppedFight_DukeApologizesForJoiningFight[] =
        "Ich hätte nicht in diesen\r\n"
        "Streit geraten sollen. \r\n"
        "Sorry. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_NotIntervened_DukeWarnsPlayerAwayFromDoug[] =
        "Wenn ich du wäre, würde\r\n"
        "ich nicht mit ihm reden. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDukeDialogue_NotIntervened_DukeChallengesDougToSettleFight[] =
        "Lass uns das ein für\r\n"
        "alle Mal klären!{Press}";
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
