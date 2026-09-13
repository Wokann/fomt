#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_FavorableChoice[] =
        "はぁ…\r\n"
        "わたしが選んだ種の方がいいと\r\n"
        "思うんだけどねぇ…{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_UnfavorableChoice[] =
        "あんたもわたしと同じ種を選ぶ\r\n"
        "なんて、センスいいねぇ。{Press}";
};

void EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_CHOICE) == KAREN_PURPLE_HEART_RESPONSE_MOONDROP_SEEDS)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_FavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    else
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_UnfavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
}
