#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupStuDialogue_StuRespectsDoctorForHisKindness[] =
        "Der Doktor ist ein \r\n"
        "sehr guter Mann. {Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupStuDialogue(void)
{
    SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupStuDialogue_StuRespectsDoctorForHisKindness);
    TalkClose();
    SetEntityFacing(ENTITY_STU, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_STU);
}
