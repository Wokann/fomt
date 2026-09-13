#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaSaysJeffHasCriedSinceWedding[] =
        "ジェフはいつまで\r\n"
        "ないてるつもりなのかしら…{Press}\p"
        "きのうから、ずっと\r\n"
        "こうなのよ。{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaRecallsJeffCryingOverChildhoodMarriagePromise[] =
        "カレンが小さいころ、リックと\r\n"
        "結婚するって言った時も、\r\n"
        "ジェフはずっとないてたのよ。{Press}\p"
        "もうなれたかと思ってたんだけ\r\n"
        "ど…{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_SASHA) == FALSE)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaSaysJeffHasCriedSinceWedding);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    else
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaRecallsJeffCryingOverChildhoodMarriagePromise);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
}
