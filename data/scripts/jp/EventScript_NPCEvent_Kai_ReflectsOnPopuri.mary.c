#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Kai_ReflectsOnPopuri_KaiStrugglesWithPopurisSensitivity[] =
        "ポプリのわがままにも\r\n"
        "困ったもんだよ。{Press}\p"
        "自分の立場が悪くなると\r\n"
        "すぐ泣き出すし…{Press}";

    const char gText_NPCEvent_Kai_ReflectsOnPopuri_KaiValuesPopurisUnderstanding[] =
        "でも、ポプリはオレのことを\r\n"
        "よくわかってくれるんだよ。{Press}";
};

void EventScript_NPCEvent_Kai_ReflectsOnPopuri(void)
{
    SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAI);
    if (WasNpcSpokenToJustNow(CHARACTER_KAI) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
        TalkMessage(gText_NPCEvent_Kai_ReflectsOnPopuri_KaiStrugglesWithPopurisSensitivity);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
        TalkMessage(gText_NPCEvent_Kai_ReflectsOnPopuri_KaiValuesPopurisUnderstanding);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_KAI);
    SetEntityFacing(ENTITY_KAI, FACING_UP);
    return;
}
