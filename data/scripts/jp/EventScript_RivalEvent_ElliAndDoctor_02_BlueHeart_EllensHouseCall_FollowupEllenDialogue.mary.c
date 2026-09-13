#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupEllenDialogue_EllenIsGratefulToElliAndDoctor[] =
        "エリィとドクターには、\r\n"
        "いつも感謝してるんだよ。{Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupEllenDialogue(void)
{
    SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_02_BlueHeart_EllensHouseCall_FollowupEllenDialogue_EllenIsGratefulToElliAndDoctor);
    TalkClose();
    SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_ELLEN);
}
