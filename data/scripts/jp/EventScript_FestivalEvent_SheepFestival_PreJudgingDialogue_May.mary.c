#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IHaveAWoolBlanketYou[] =
        "メイのベッド、羊さんの毛で\r\n"
        "出来てるのよ。おじいちゃんが\r\n"
        "作ってくれたの。{Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IfYourSheepDoesntWinIll[] =
        "お兄ちゃんの羊なら、\r\n"
        "絶対優勝するよ。{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PreJudgingDialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IHaveAWoolBlanketYou);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IfYourSheepDoesntWinIll);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MAY);
    SetEntityFacing(ENTITY_MAY, FACING_LEFT);
}
