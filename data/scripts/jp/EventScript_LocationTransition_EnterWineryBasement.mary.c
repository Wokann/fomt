#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterWineryBasement[] =
        "今、ワイン棚を整理して\r\n"
        "るんだ。下には行かねぇで\r\n"
        "くれるか？{Press}";
};

void EventScript_LocationTransition_EnterWineryBasement(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_LocationTransition_EnterWineryBasement);
            TalkClose();
            MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) - 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_AJA_WINERY_STORAGE_B1F, X(120), Y(152));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(152), FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
