#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_TodayIsThePumpkinFestivalYou[] =
        "Heute ist das Kürbis- \r\n"
        "festival. {Press}\p"
        "Du musst Kindern\r\n"
        "Süßigkeiten geben.\r\n"
        "Also dann...gib mir{Press}\r\n"
        "welche!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_HurryUpAndGiveMeSome[] =
        "Na los, gib mir etwas!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_StuThanksPlayerAndLeaves[] =
        "Vielen Dank! \r\n"
        "Tschüss dann. {Press}";

    const char gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_YouCantFoolMeThisIsnt[] =
        "Du kannst mich \r\n"
        "nicht vereimern! \r\n"
        "Das ist nichts Süßes!{Press}";
};

void EventScript_FestivalEvent_PumpkinFestival_TreatVisit_Stu(void)
{
    int var_0, var_1;
    VarSet(VAR_PUMPKIN_FESTIVAL_STU_TREAT_VISIT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
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
    var_1 = GetEntityFacing(ENTITY_STU);
    SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (HasMetNpc(CHARACTER_STU) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_STU);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_STU) == FALSE)
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_STU);
        SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
        TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_TodayIsThePumpkinFestivalYou);
        TalkClose();
        VarSet(VAR_PUMPKIN_FESTIVAL_STU_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    else
    {
        TalkOpen();
        if (IsPlayerHoldingNothing())
        {
            SetTalkNameplateCharacter(CHARACTER_STU);
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_HurryUpAndGiveMeSome);
            TalkClose();
            VarSet(VAR_PUMPKIN_FESTIVAL_STU_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
        }
        else
        {
            if (var_0 == 16)
            {
                AddNpcFriendship(CHARACTER_STU, 20);
                SetTalkNameplateCharacter(CHARACTER_STU);
                SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_StuThanksPlayerAndLeaves);
                TalkClose();
                UsePlayerHeldItem();
                if (X(GetEntityX(ENTITY_STU)) != X(340))
                {
                    SetEntityFacing(ENTITY_STU, FACING_RIGHT);
                    SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
                    MoveEntityXTo(ENTITY_STU, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_STU);
                    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
                }
                SetEntityFacing(ENTITY_STU, FACING_UP);
                SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
                MoveEntityYTo(ENTITY_STU, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_STU);
                SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
                HideEntity(ENTITY_STU);
                VarSet(VAR_PUMPKIN_FESTIVAL_STU_TREAT_VISIT_STATE, EVENT_LIFECYCLE_COMPLETED);
                RefreshAllNpcSchedules();
            }
            else
            {
                SetTalkNameplateCharacter(CHARACTER_STU);
                SetTalkPortrait(TALK_PORTRAIT_STU_ANGRY);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_TreatVisit_Stu_YouCantFoolMeThisIsnt);
                TalkClose();
                VarSet(VAR_PUMPKIN_FESTIVAL_STU_TREAT_VISIT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
            }
        }
    }
    SetEntityFacing(ENTITY_STU, var_1);
    MarkNpcSpokenTo(CHARACTER_STU);
}
