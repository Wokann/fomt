#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Mary_BlocksLibraryUpstairsAccess[] =
        "We're still arranging the\r\n"
        "books upstairs, so please\r\n"
        "don't go up there.{Press}";
};

void EventScript_NPCEvent_Mary_BlocksLibraryUpstairsAccess(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_MARY_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_MARY);
            }
            TalkMessage(gText_NPCEvent_Mary_BlocksLibraryUpstairsAccess);
            TalkClose();
            MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_LIBRARY_2F, X(216), Y(96));
        SetEntityPosition(ENTITY_PLAYER, X(216), Y(96), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
