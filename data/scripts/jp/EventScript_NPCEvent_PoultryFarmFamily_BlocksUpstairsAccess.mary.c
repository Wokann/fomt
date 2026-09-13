#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickAsksWhereYouAreGoing[] =
        "どこに行くんだよ？{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysUpstairsIsNotCleaned[] =
        "２階は、まだ掃除してない\r\n"
        "のよ～。\r\n"
        "あがらないでくれる～。{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysUpstairsIsNotTidied[] =
        "２階は、片付いてないんだよ。\r\n"
        "あがらないでくれ。{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysDoNotGoUpstairs[] =
        "２階には上がらないでくれよ。{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysDoNotGoUpstairs[] =
        "２階には上がらないでね～。{Press}";

    const char gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_PopuriSaysDoNotGoUpstairs[] =
        "２階には上がらないでね。{Press}";
};

void EventScript_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess(void)
{
    int var_0, var_1;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        var_1 = VarGet(VAR_DAY_OF_WEEK);
        if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                var_0 = TRUE;
            }
            else
            {
                if (GetNpcFriendship(CHARACTER_LILLIA) <= 200)
                {
                    var_0 = FALSE;
                }
                else
                {
                    var_0 = TRUE;
                }
            }
        }
        if (var_0 == TRUE)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_POULTRY_FARM_HOUSE_2F, X(24), Y(96));
            SetEntityPosition(ENTITY_PLAYER, X(24), Y(96), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_RICK);
                TalkMessage(gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickAsksWhereYouAreGoing);
            }
            else
            {
                if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_LILLIA);
                    TalkMessage(gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysUpstairsIsNotCleaned);
                }
                else
                {
                    if (VarGet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_RICK);
                        TalkMessage(gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysUpstairsIsNotTidied);
                    }
                    else
                    {
                        if (var_1 == DAY_OF_WEEK_SUNDAY)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
                            SetTalkNameplateCharacter(CHARACTER_RICK);
                            TalkMessage(gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_RickSaysDoNotGoUpstairs);
                        }
                        else
                        {
                            if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_LILLIA);
                                TalkMessage(gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_LilliaSaysDoNotGoUpstairs);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_POPURI);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_PoultryFarmFamily_BlocksUpstairsAccess_PopuriSaysDoNotGoUpstairs);
                            }
                        }
                    }
                }
            }
            TalkClose();
            MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 2), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 2), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
