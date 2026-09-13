#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_FarmhouseBedSleepForDayChoice_TurnInForTheDay[] =
        "今日はもう寝る？";

    const char gText_LocationInteraction_FarmhouseBedSleepForDayChoice_Yes[] =
        "はい";

    const char gText_LocationInteraction_FarmhouseBedSleepForDayChoice_No[] =
        "いいえ";

    const char gText_LocationInteraction_FarmhouseBedSleepForDayChoice_InstructionsInspectBedFromLeftSideToSleep[] =
        "ベッド\r\n"
        "寝る時は左側から調べよう。{Press}";
};

void EventScript_LocationInteraction_FarmhouseBedSleepForDayChoice(void)
{
    int var_0, var_1, var_2, var_3;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_RIGHT)
    {
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_2 = VarGet(VAR_HOUR);
        TalkOpen();
        var_3 = TalkPromptChoice2(gText_LocationInteraction_FarmhouseBedSleepForDayChoice_TurnInForTheDay, gText_LocationInteraction_FarmhouseBedSleepForDayChoice_Yes, gText_LocationInteraction_FarmhouseBedSleepForDayChoice_No);
        TalkClose();
        switch (var_3)
        {
            case PROMPT_CHOICE_OPTION_1:
                PreparePlayerForScriptedAnimation();
                if (Y(GetEntityY(ENTITY_PLAYER)) != Y(76))
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
                    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
                    MoveEntityYTo(ENTITY_PLAYER, Y(76), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_PLAYER);
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
                }
                switch (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL))
                {
                    case FARMHOUSE_UPGRADE_ORIGINAL:
                        if (X(GetEntityX(ENTITY_PLAYER)) != X(193))
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
                            MoveEntityXTo(ENTITY_PLAYER, X(193), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                            WaitForEntityMovement(ENTITY_PLAYER);
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                        }
                        break;
                    case FARMHOUSE_UPGRADE_FIRST_EXTENSION:
                        if (X(GetEntityX(ENTITY_PLAYER)) != X(313))
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
                            MoveEntityXTo(ENTITY_PLAYER, X(313), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                            WaitForEntityMovement(ENTITY_PLAYER);
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                        }
                        break;
                    case FARMHOUSE_UPGRADE_SECOND_EXTENSION:
                        if (X(GetEntityX(ENTITY_PLAYER)) != X(377))
                        {
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
                            MoveEntityXTo(ENTITY_PLAYER, X(377), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                            WaitForEntityMovement(ENTITY_PLAYER);
                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                        }
                        break;
                }
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_HIGH_JUMP);
                WaitFrames(12);
                MoveEntityXToRaw(ENTITY_PLAYER, X(GetEntityX(ENTITY_PLAYER) + 16), ENTITY_MOVE_SPEED_Q16_HALF_PIXEL_PER_FRAME);
                WaitFrames(32);
                switch (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL))
                {
                    case FARMHOUSE_UPGRADE_ORIGINAL:
                        SetEntityPosition(ENTITY_PLAYER, X(200), Y(mary_negated_int(-46)), FACING_DOWN);
                        break;
                    case FARMHOUSE_UPGRADE_FIRST_EXTENSION:
                        SetEntityPosition(ENTITY_PLAYER, X(320), Y(mary_negated_int(-46)), FACING_DOWN);
                        break;
                    case FARMHOUSE_UPGRADE_SECOND_EXTENSION:
                        SetEntityPosition(ENTITY_PLAYER, X(384), Y(mary_negated_int(-46)), FACING_DOWN);
                        break;
                }
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
                WaitFrames(30);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangePlayerStaminaAndFatigue(50, mary_negated_int(-5));
                if (var_0 == SEASON_WINTER && (var_1 == DAY_OF_MONTH_14 && (var_2 >= 18 && var_2 <= 23) || var_1 == DAY_OF_MONTH_15 && (var_2 >= 0 && var_2 <= 5)) && (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED))
                {
                    CallScript(EventScript_FestivalEvent_WinterThanksgiving_RucksackFull);
                }
                else
                {
                    if (var_0 == SEASON_WINTER && (var_1 == DAY_OF_MONTH_25 && (var_2 >= 21 && var_2 <= 23)))
                    {
                        CallScript(EventScript_FestivalEvent_StockingGift_ThomasDelivery);
                    }
                }
                CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                break;
            case PROMPT_CHOICE_OPTION_2:
                break;
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_FarmhouseBedSleepForDayChoice_InstructionsInspectBedFromLeftSideToSleep);
        TalkClose();
    }
}
