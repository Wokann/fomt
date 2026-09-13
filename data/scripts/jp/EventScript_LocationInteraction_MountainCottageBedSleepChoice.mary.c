#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_MountainCottageBedSleepChoice_TurnInForTheDay[] =
        "今日はもう寝る？";

    const char gText_LocationInteraction_MountainCottageBedSleepChoice_Yes[] =
        "はい";

    const char gText_LocationInteraction_MountainCottageBedSleepChoice_No[] =
        "いいえ";

    const char gText_LocationInteraction_MountainCottageBedSleepChoice_BedInvestigateFromTheLeftSide[] =
        "ベッド\r\n"
        "寝る時は左側から調べよう。{Press}";
};

void EventScript_LocationInteraction_MountainCottageBedSleepChoice(void)
{
    int var_0;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_RIGHT)
    {
        TalkOpen();
        var_0 = TalkPromptChoice2(gText_LocationInteraction_MountainCottageBedSleepChoice_TurnInForTheDay, gText_LocationInteraction_MountainCottageBedSleepChoice_Yes, gText_LocationInteraction_MountainCottageBedSleepChoice_No);
        TalkClose();
        switch (var_0)
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
                if (X(GetEntityX(ENTITY_PLAYER)) != X(193))
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
                    MoveEntityXTo(ENTITY_PLAYER, X(193), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_PLAYER);
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                }
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_HIGH_JUMP);
                WaitFrames(12);
                MoveEntityXToRaw(ENTITY_PLAYER, X(GetEntityX(ENTITY_PLAYER) + 16), ENTITY_MOVE_SPEED_Q16_HALF_PIXEL_PER_FRAME);
                WaitFrames(32);
                SetEntityPosition(ENTITY_PLAYER, X(200), Y(mary_negated_int(-46)), FACING_DOWN);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
                WaitFrames(30);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangePlayerStaminaAndFatigue(50, mary_negated_int(-5));
                CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                break;
            case PROMPT_CHOICE_OPTION_2:
                break;
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_MountainCottageBedSleepChoice_BedInvestigateFromTheLeftSide);
        TalkClose();
    }
}
