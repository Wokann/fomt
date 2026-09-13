#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Karen_ItWasntMeIDecidedNot[] =
        "Ich war es nicht! \r\n"
        "Ich habe entschieden, die \r\n"
        "Marmelade nicht reinzutun!{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Karen_IAccidentallyDroppedTheWholeJar[] =
        "Aus Versehen habe ich\r\n"
        "die ganze Marmelade \r\n"
        "hineingetan!{Press}\p"
        "Ich habe sie später \r\n"
        "heimlich rausgenommen. {Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Karen(void)
{
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_KAREN) == FALSE)
    {
        AddNpcFriendship(CHARACTER_KAREN, 5);
    }
    TalkOpen();
    if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_KAREN);
    }
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Karen_ItWasntMeIDecidedNot);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Karen_IAccidentallyDroppedTheWholeJar);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
}
