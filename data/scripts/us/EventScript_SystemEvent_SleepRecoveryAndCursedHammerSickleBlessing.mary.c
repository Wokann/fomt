#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing_Overslept[] =
        "You overslept...{Press}";

    const char gText_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing_HammerCurseLifted[] =
        "The curse has been lifted\r\n"
        "from the Hammer!{Press}";

    const char gText_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing_SickleCurseLifted[] =
        "The Sickle's curse\r\n"
        "has been removed!{Press}";
};

void EventScript_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing(void)
{
    int var_0, var_1;
    if (GetPreservedPlayerMapId() != MAP_NONE)
    {
        var_1 = VarGet(VAR_PLAYER_FATIGUE);
        if (var_1 < 50)
        {
            var_0 = FALSE;
        }
        else
        {
            var_0 = TRUE;
            if (var_1 < 70)
            {
                SetGameTime(8, 0);
                ChangePlayerStaminaAndFatigue(14, mary_negated_int(-4));
            }
            else
            {
                if (var_1 < 80)
                {
                    SetGameTime(10, 0);
                    ChangePlayerStaminaAndFatigue(28, mary_negated_int(-6));
                }
                else
                {
                    SetGameTime(12, 0);
                    ChangePlayerStaminaAndFatigue(42, mary_negated_int(-12));
                }
            }
        }
    }
    switch (GetPreservedPlayerMapId())
    {
        case MAP_TOWN_COTTAGE:
            ChangeMap(MAP_TOWN_COTTAGE, X(103), Y(83));
            SetEntityPosition(ENTITY_PLAYER, X(103), Y(83), FACING_DOWN);
            break;
        case MAP_MOUNTAIN_COTTAGE:
            ChangeMap(MAP_MOUNTAIN_COTTAGE, X(143), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(143), Y(112), FACING_LEFT);
            break;
        case MAP_BEACH_HOUSE:
            ChangeMap(MAP_BEACH_HOUSE, X(143), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(143), Y(112), FACING_LEFT);
            break;
        default:
            PlacePlayerAtFarmhouseBed();
            break;
    }
    PlaySong(AUDIO_START, AUDIO_SFX_TIME_PASSES);
    PreparePlayerForScriptedAnimation();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (var_0)
    {
        TalkOpen();
        TalkMessage(gText_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing_Overslept);
        TalkClose();
    }
    if (IsToolCursed(ITEM_TOOL_HAMMER_CURSED) && GetPlayerHeldToolId() == ITEM_TOOL_HAMMER_CURSED)
    {
        if (TRUE == AdvanceCursedToolLiftProgress(ITEM_TOOL_HAMMER_CURSED))
        {
            ClearPlayerHeldTool();
            SetPlayerHeldTool(ITEM_TOOL_HAMMER_BLESSED, 1);
            ShowPlayerHoldingTool(ITEM_TOOL_HAMMER_BLESSED);
            PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
            WaitFrames(50);
            TalkOpen();
            TalkMessage(gText_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing_HammerCurseLifted);
            TalkClose();
        }
    }
    if (IsToolCursed(ITEM_TOOL_SICKLE_CURSED) && GetPlayerHeldToolId() == ITEM_TOOL_SICKLE_CURSED)
    {
        if (TRUE == AdvanceCursedToolLiftProgress(ITEM_TOOL_SICKLE_CURSED))
        {
            ClearPlayerHeldTool();
            SetPlayerHeldTool(ITEM_TOOL_SICKLE_BLESSED, 1);
            ShowPlayerHoldingTool(ITEM_TOOL_SICKLE_BLESSED);
            PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
            WaitFrames(50);
            TalkOpen();
            TalkMessage(gText_SystemEvent_SleepRecoveryAndCursedHammerSickleBlessing_SickleCurseLifted);
            TalkClose();
        }
    }
    EatRandomMeal();
    RestorePlayerAfterScriptedAnimation();
}
