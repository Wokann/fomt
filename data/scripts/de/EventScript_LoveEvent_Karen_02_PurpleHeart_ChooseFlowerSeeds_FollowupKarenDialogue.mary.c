#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupKaren_FavorableChoice[] =
        "Ich bin froh, dass du \r\n"
        "mich gewählt hast. {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupKaren_UnfavorableChoice[] =
        "Dann noch mal... Ich habe\r\n"
        "nach deiner Meinung gefragt?{Press}";
};

void EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupKarenDialogue(void)
{
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_CHOICE) == KAREN_PURPLE_HEART_RESPONSE_MOONDROP_SEEDS)
    {
        SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupKaren_FavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    else
    {
        SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupKaren_UnfavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
}
