#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_ChildFirstSteps_FollowupKarenDialogue_KarenSaysBabiesGrowQuickly[] =
        "Babies wachsen\r\n"
        "so schnell heran!{Press}";
};

void EventScript_FamilyEvent_Karen_ChildFirstSteps_FollowupKarenDialogue(void)
{
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_ChildFirstSteps_FollowupKarenDialogue_KarenSaysBabiesGrowQuickly);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_KAREN);
    SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
}
