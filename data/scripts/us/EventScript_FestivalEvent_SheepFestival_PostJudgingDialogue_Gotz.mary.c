#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz_IFeltWarmJustLookingAt[] =
        "I felt warm just \r\n"
        "looking at those Sheep!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz_DidYouWinWouldYouSave[] =
        "Did you win? Would you save\r\n"
        "some of your Wool for me?\r\n"
        "It looks so warm!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz_YourSheepLostTryNotTo[] =
        "Your Sheep lost?\r\n"
        "Try not to get too upset. {Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz(void)
{
    if (HasMetNpc(CHARACTER_GOTZ) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOTZ);
    }
    SetEntityFacing(ENTITY_GOTZ, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_GOTZ);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz_IFeltWarmJustLookingAt);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_GOTZ);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz_DidYouWinWouldYouSave);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_GOTZ);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz_YourSheepLostTryNotTo);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOTZ) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOTZ, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_DOWN);
}
