#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKarenDialogue_KarenPrivatelyApprovesTheCouple[] =
        "Ich würde es Rick nicht \r\n"
        "sagen, aber Popuri und \r\n"
        "Kai sind ein tolles Paar. {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKarenDialogue_KarenEncouragesFollowingYourHeart[] =
        "Man lebt nur einmal! \r\n"
        "Man muss seinem Herz folgen.{Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKarenDialogue(void)
{
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
    {
        SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_KAREN);
        }
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKarenDialogue_KarenPrivatelyApprovesTheCouple);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    else
    {
        SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_KAREN);
        }
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKarenDialogue_KarenEncouragesFollowingYourHeart);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
}
