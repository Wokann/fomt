#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_IWantedToEnterMySheep[] =
        "メイがなかよくしている\r\n"
        "羊さんを出したかったの。\r\n"
        "でも、まだ子どもだから{Press}\r\n"
        "ダメなんだって。{Press}\p"
        "子どもってダメな事が\r\n"
        "たくさんあるのね。{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_ImSoGladYouWonPlayer[] =
        "優勝するなんて、すっごーい！\r\n"
        "さっすが、お兄ちゃん。{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_DontFeelBadPlayer[] =
        "お兄ちゃん、残念だったね。{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_IWantedToEnterMySheep);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_ImSoGladYouWonPlayer);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MAY_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_DontFeelBadPlayer);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MAY);
    SetEntityFacing(ENTITY_MAY, FACING_LEFT);
}
