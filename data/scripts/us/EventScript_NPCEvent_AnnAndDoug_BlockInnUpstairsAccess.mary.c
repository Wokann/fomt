#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_AnnAndDoug_BlockInnUpstairsAccess_Shared_AnnAndDougSayUpstairsIsNotCleaned[] =
        "I haven't cleaned upstairs\r\n"
        "yet, so please don't \r\n"
        "go up there.{Press}";
};

void EventScript_NPCEvent_AnnAndDoug_BlockInnUpstairsAccess(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_NPCEvent_AnnAndDoug_BlockInnUpstairsAccess_Shared_AnnAndDougSayUpstairsIsNotCleaned);
            TalkClose();
            MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        else
        {
            if (VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_DOUG);
                TalkMessage(gText_NPCEvent_AnnAndDoug_BlockInnUpstairsAccess_Shared_AnnAndDougSayUpstairsIsNotCleaned);
                TalkClose();
                MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
                WaitForEntityMovement(ENTITY_PLAYER);
                return;
            }
        }
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_INN_2F, X(40), Y(248));
        SetEntityPosition(ENTITY_PLAYER, X(40), Y(248), FACING_UP);
        if (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_2 == DAY_OF_WEEK_MONDAY || var_2 == DAY_OF_WEEK_WEDNESDAY || var_2 == DAY_OF_WEEK_FRIDAY) && (var_3 >= 10 && var_3 < 13) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_PURPLE_MIN && GetEntityLocation(ENTITY_ANN) == MAP_INN_2F && IsPlayerHoldingNothing() == TRUE)
        {
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning);
        }
        else
        {
            if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SUMMER) && (var_1 >= DAY_OF_MONTH_06 && var_1 <= DAY_OF_MONTH_30) && !(var_2 == DAY_OF_WEEK_SATURDAY) && (var_3 >= 19 && var_3 < 21) && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_PURPLE_MIN && HasMetNpc(CHARACTER_ANN) == TRUE && HasMetNpc(CHARACTER_CLIFF) == TRUE && GetEntityLocation(ENTITY_ANN) == MAP_INN_1F && (GetEntityLocation(ENTITY_CLIFF) == MAP_INN_1F || GetEntityLocation(ENTITY_CLIFF) == MAP_INN_2F))
            {
                VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                CallScript(EventScript_RivalEvent_AnnAndCliff_01_BlackHeart_InnHelpOffer);
            }
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
