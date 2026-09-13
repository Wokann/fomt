#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_May_TodayIsThePumpkinFestivalYou[] =
        "Heute ist das Kürbis-\r\n"
        "festival. {Press}\p"
        "Du musst Kindern \r\n"
        "Süßigkeiten geben. \r\n"
        "Bitte gib mir welche!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_May_ImWaiting[] =
        "Ich warte!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_May_MayThanksPlayerAndLeaves[] =
        "Ganz vielen Dank!\r\n"
        "Tschüss dann. {Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_May_ThisIsntATreat[] =
        "Das ist keine Leckerei!{Press}";
};

void EventScript_FestivalEvent_PumpkinFestival_TreatVisit_May(void)
{
    int var_0, var_1;
    VarSet(VAR_PUMPKIN_FESTIVAL_MAY_TREAT_VISIT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
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
    var_1 = GetEntityFacing(ENTITY_MAY);
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_MAY) == FALSE)
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_MAY);
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_May_TodayIsThePumpkinFestivalYou);
        TalkClose();
        VarSet(VAR_PUMPKIN_FESTIVAL_MAY_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    else
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_MAY);
        if (IsPlayerHoldingNothing())
        {
            SetTalkPortrait(TALK_PORTRAIT_MAY_NORMAL);
            TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_May_ImWaiting);
            TalkClose();
            VarSet(VAR_PUMPKIN_FESTIVAL_MAY_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        }
        else
        {
            if (var_0 == 16)
            {
                AddNpcFriendship(CHARACTER_MAY, 20);
                SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_May_MayThanksPlayerAndLeaves);
                TalkClose();
                UsePlayerHeldItem();
                if (X(GetEntityX(ENTITY_MAY)) != X(340))
                {
                    SetEntityFacing(ENTITY_MAY, FACING_RIGHT);
                    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
                    MoveEntityXTo(ENTITY_MAY, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_MAY);
                    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
                }
                SetEntityFacing(ENTITY_MAY, FACING_UP);
                SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
                MoveEntityYTo(ENTITY_MAY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_MAY);
                SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
                HideEntity(ENTITY_MAY);
                VarSet(VAR_PUMPKIN_FESTIVAL_MAY_TREAT_VISIT_STATE, EVENT_LIFECYCLE_COMPLETED);
                RefreshAllNpcSchedules();
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_MAY_AFRAID);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_May_ThisIsntATreat);
                TalkClose();
                VarSet(VAR_PUMPKIN_FESTIVAL_MAY_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
            }
        }
    }
    SetEntityFacing(ENTITY_MAY, var_1);
    MarkNpcSpokenTo(CHARACTER_MAY);
}
