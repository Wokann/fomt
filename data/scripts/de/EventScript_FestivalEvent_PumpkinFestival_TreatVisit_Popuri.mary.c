#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_IThinkItsUnfairThatOnly[] =
        "Ich finde es unfair, \r\n"
        "dass nur Kinder beim Kür-\r\n"
        "bisfestival etwas kriegen.{Press}\p"
        "Ich möchte auch etwas!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_PopuriAsksForCandy[] =
        "Kann ich etwas haben?{Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_PopuriThanksPlayerForCandy[] =
        "Vielen Dank, \r\n"
        "{Player}. {Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_AreYouTryingToTrickMe[] =
        "Versuchst du, \r\n"
        "mich hereinzulegen ?{Press}";
};

void EventScript_FestivalEvent_PumpkinFestival_TreatVisit_Popuri(void)
{
    int var_0, var_1;
    VarSet(VAR_PUMPKIN_FESTIVAL_POPURI_TREAT_VISIT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    switch (GetPlayerHeldItemKind())
    {
        case HELD_ITEM_KIND_FOOD:
            switch (GetPlayerHeldFoodId())
            {
                case ITEM_FOOD_CHOCOLATE:
                case ITEM_FOOD_PUMPKIN_PUDDING:
                case ITEM_FOOD_SWEET_POTATOES:
                case ITEM_FOOD_BAKED_SWEET_POTATO:
                case ITEM_FOOD_CHEESE_CAKE:
                case ITEM_FOOD_APPLE_PIE:
                case ITEM_FOOD_APPLE_SOUFFLE:
                case ITEM_FOOD_COOKIES:
                case ITEM_FOOD_CHOCOLATE_COOKIES:
                case ITEM_FOOD_ICE_CREAM:
                case ITEM_FOOD_CAKE:
                case ITEM_FOOD_CHOCOLATE_CAKE:
                case ITEM_FOOD_PUDDING:
                case ITEM_FOOD_MOON_DUMPLINGS:
                case ITEM_FOOD_RICE_CAKE:
                case ITEM_FOOD_ROASTED_RICE_CAKE:
                case ITEM_FOOD_PANCAKES:
                case ITEM_FOOD_CANDIED_POTATO:
                    var_0 = 16;
                    break;
            }
            break;
    }
    var_1 = GetEntityFacing(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_POPURI);
        }
        TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_IThinkItsUnfairThatOnly);
        TalkClose();
        VarSet(VAR_PUMPKIN_FESTIVAL_POPURI_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    else
    {
        TalkOpen();
        if (IsPlayerHoldingNothing())
        {
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_PopuriAsksForCandy);
            TalkClose();
            VarSet(VAR_PUMPKIN_FESTIVAL_POPURI_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        }
        else
        {
            if (var_0 == 16)
            {
                AddCharacterLove(CHARACTER_POPURI, 1000);
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                {
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                }
                TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_PopuriThanksPlayerForCandy);
                TalkClose();
                UsePlayerHeldItem();
                if (X(GetEntityX(ENTITY_POPURI)) != X(340))
                {
                    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
                    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
                    MoveEntityXTo(ENTITY_POPURI, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_POPURI);
                    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
                }
                SetEntityFacing(ENTITY_POPURI, FACING_UP);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
                MoveEntityYTo(ENTITY_POPURI, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_POPURI);
                SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
                HideEntity(ENTITY_POPURI);
                VarSet(VAR_PUMPKIN_FESTIVAL_POPURI_TREAT_VISIT_STATE, EVENT_LIFECYCLE_COMPLETED);
                RefreshAllNpcSchedules();
            }
            else
            {
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                {
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                }
                TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Popuri_AreYouTryingToTrickMe);
                TalkClose();
                VarSet(VAR_PUMPKIN_FESTIVAL_POPURI_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
            }
        }
    }
    SetEntityFacing(ENTITY_POPURI, var_1);
    MarkNpcSpokenTo(CHARACTER_POPURI);
}
