#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Barley_BlocksYodelRanchUpstairsAccess_BarleyWarnsYouMightGetLostUpstairs[] =
        "Du könntest dich verirren,\r\n"
        "also geh nicht nach oben.{Press}";

    const char gText_NPCEvent_Barley_BlocksYodelRanchUpstairsAccess_HannahBlocksTheStairs[] =
        "Wau-wau! WAU-WAU!!\r\n"
        "Hannah ist über \r\n"
        "etwas sauer ...{Press}";

    const char gText_NPCEvent_Barley_BlocksYodelRanchUpstairsAccess_BarleySaysDoNotGoUpstairs[] =
        "Bitte geh nicht hoch!{Press}";
};

void EventScript_NPCEvent_Barley_BlocksYodelRanchUpstairsAccess(void)
{
    int var_0, var_1;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_HOUR);
        if (var_1 >= 22)
        {
            var_0 = FALSE;
        }
        if (GetNpcFriendship(CHARACTER_BARLEY) <= 100)
        {
            var_0 = FALSE;
        }
        else
        {
            if (GetNpcFriendship(CHARACTER_BARLEY) > 100)
            {
                var_0 = TRUE;
            }
        }
        if (var_0 == TRUE)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_YODEL_RANCH_HOUSE_2F, X(216), Y(96));
            SetEntityPosition(ENTITY_PLAYER, X(216), Y(96), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            if (var_1 >= 22)
            {
                TalkMessage(gText_NPCEvent_Barley_BlocksYodelRanchUpstairsAccess_BarleyWarnsYouMightGetLostUpstairs);
            }
            else
            {
                if (GetEntityLocation(ENTITY_BARLEY) != MAP_YODEL_RANCH_HOUSE_1F && GetNpcFriendship(CHARACTER_BARLEY) <= 100)
                {
                    TalkMessage(gText_NPCEvent_Barley_BlocksYodelRanchUpstairsAccess_HannahBlocksTheStairs);
                }
                else
                {
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_NPCEvent_Barley_BlocksYodelRanchUpstairsAccess_BarleySaysDoNotGoUpstairs);
                }
            }
            TalkClose();
            MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
