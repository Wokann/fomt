#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_FollowupGrayDialogue_GrayIsDeterminedToPassBlacksmithSkillTest[] =
        "なにがなんでも、\r\n"
        "テストに合格しなきゃな…{Press}";
};

void EventScript_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_FollowupGrayDialogue(void)
{
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_04_OrangeHeart_BlacksmithSkillTestPromise_FollowupGrayDialogue_GrayIsDeterminedToPassBlacksmithSkillTest);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_GRAY);
}
