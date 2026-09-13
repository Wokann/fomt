#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_BlockWineryUpstairs[] =
        "I haven't cleaned upstairs\r\n"
        "yet, so please don't \r\n"
        "go up there.{Press}";
};

void EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument_BlockWineryUpstairs(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_BlockWineryUpstairs);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
            }
            MoveEntityYTo(ENTITY_PLAYER, Y(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            return;
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_AJA_WINERY_2F, X(216), Y(64));
        SetEntityPosition(ENTITY_PLAYER, X(216), Y(64), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
