#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Anna_BlocksBasilHouseUpstairsAccess_AnnaSaysUpstairsIsNotCleaned[] =
        "I haven't cleaned upstairs\r\n"
        "yet, so please don't \r\n"
        "go up there.{Press}";

    const char gText_NPCEvent_Anna_BlocksBasilHouseUpstairsAccess_AnnaSaysDoNotGoUpstairs[] =
        "Please don't go upstairs!{Press}";
};

void EventScript_NPCEvent_Anna_BlocksBasilHouseUpstairsAccess(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_4 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_DAY_OF_WEEK);
        if (GetNpcFriendship(CHARACTER_BASIL) <= 200)
        {
            var_0 = FALSE;
        }
        else
        {
            var_0 = TRUE;
        }
        if (var_0 == TRUE)
        {
            if (VarGet(VAR_BASIL_PUBLISHING_AWARD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_ANNA_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_ANNA);
                TalkMessage(gText_NPCEvent_Anna_BlocksBasilHouseUpstairsAccess_AnnaSaysUpstairsIsNotCleaned);
                TalkClose();
                MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
                WaitForEntityMovement(ENTITY_PLAYER);
                return;
            }
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_BASIL_HOUSE_2F, X(216), Y(88));
            SetEntityPosition(ENTITY_PLAYER, X(216), Y(88), FACING_UP);
            if (VarGet(VAR_BASIL_LETTER_ADVICE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_3 != DAY_OF_WEEK_MONDAY && (var_4 >= 13 && var_4 < 16) && var_1 == SEASON_SPRING && GetNpcFriendship(CHARACTER_BASIL) > 200 && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && HasMetNpc(CHARACTER_BASIL) == TRUE && GetEntityLocation(ENTITY_BASIL) == MAP_BASIL_HOUSE_2F)
            {
                VarSet(VAR_BASIL_LETTER_ADVICE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_NPCEvent_Basil_LetterAdvice);
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_BlocksBasilHouseUpstairsAccess_AnnaSaysDoNotGoUpstairs);
            TalkClose();
            MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
