#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupPopuri_SupportPopuri[] =
        "Danke, dass du mich \r\n"
        "unterstützt hast, \r\n"
        "{Player}.{Press}";

    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupPopuri_SupportRick[] =
        "Ich kann nicht fassen, dass\r\n"
        "du meinem Bruder \r\n"
        "zugestimmt hast!{Press}";

    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupPopuri_SympathizeWithLillia[] =
        "Tur mir Leid, dass du\r\n"
        "dir Sorgen gemacht hast, \r\n"
        "{Player}. {Press}\r\n"
        "Alles in Ordnung. {Press}";
};

void EventScript_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupPopuriDialogue(void)
{
    if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_CHOICE) == POPURI_YELLOW_HEART_CHOICE_SUPPORT_POPURI)
        {
            SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupPopuri_SupportPopuri);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
            MarkNpcSpokenTo(CHARACTER_POPURI);
        }
        else
        {
            if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_CHOICE) == POPURI_YELLOW_HEART_CHOICE_SUPPORT_RICK)
            {
                SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                ShowTalkHeartIndicator(CHARACTER_POPURI);
                TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupPopuri_SupportRick);
                TalkClose();
                SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
                MarkNpcSpokenTo(CHARACTER_POPURI);
            }
            else
            {
                SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                ShowTalkHeartIndicator(CHARACTER_POPURI);
                TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupPopuri_SympathizeWithLillia);
                TalkClose();
                SetEntityFacing(ENTITY_POPURI, FACING_UP);
                MarkNpcSpokenTo(CHARACTER_POPURI);
            }
        }
    }
}
