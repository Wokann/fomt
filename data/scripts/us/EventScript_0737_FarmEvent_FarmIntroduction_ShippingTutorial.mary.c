#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0737_FarmEvent_FarmIntroduction_ShippingTutorial.mary.h"

void EventScript_0737_FarmEvent_FarmIntroduction_ShippingTutorial(void)
{
    int var_0;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasExplainsBasicControls);
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasOffersDetailedTutorial);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ChoiceOpenDetailedTutorial, gText_FarmEvent_FarmIntroduction_ShippingTutorial_ChoiceSkipDetailedTutorial);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasOpensTutorialTopicMenu);
            TalkClose();
            do
            {
                TalkOpen();
                var_0 = TalkChoice4(gText_FarmEvent_FarmIntroduction_ShippingTutorial_MenuCrops, gText_FarmEvent_FarmIntroduction_ShippingTutorial_MenuAnimals, gText_FarmEvent_FarmIntroduction_ShippingTutorial_MenuUsefulTips, gText_FarmEvent_FarmIntroduction_ShippingTutorial_MenuQuit);
                TalkClose();
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        OpenFarmingTutorial(FARMING_TUTORIAL_CROPS);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        break;
                    case CHOICE_OPTION_2:
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        OpenFarmingTutorial(FARMING_TUTORIAL_ANIMALS);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        break;
                    case CHOICE_OPTION_3:
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_USEFUL_CONTROLS);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        break;
                }
            }
            while (var_0 != CHOICE_OPTION_4);
            TalkOpen();
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasExplainsTutorialCanBeReviewedLater);
            break;
    }
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasAdvisesEarningMoney);
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasSuggestsExploringNearbyFarms);
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasExplainsPedometerGift);
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ThomasDeparts);
    TalkClose();
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityXTo(ENTITY_THOMAS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_UP);
    MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    HideEntity(ENTITY_THOMAS);
    SetEntityPosition(ENTITY_ZACK, X(319), Y(0), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityYTo(ENTITY_ZACK, Y(145), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
    MoveEntityXTo(ENTITY_ZACK, X(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_UP);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackIntroducesShippingService);
    TalkClose();
    PanCameraTo(X(228), Y(201), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityYTo(ENTITY_ZACK, Y(171), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    MoveEntityXTo(ENTITY_ZACK, X(257), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(171), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitForCameraMovement();
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackExplainsShippingBinAndPickupTime);
    TalkClose();
    SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackExplainsFestivalDayClosures);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackPausesAfterJoke);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackPointsOutBarnAndCoopShippingBins);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackListsShippableProducts);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackWarnsAgainstOverwork);
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    TalkMessage(gText_FarmEvent_FarmIntroduction_ShippingTutorial_ZackRepeatsFivePmPickupAndDeparts);
    TalkClose();
    SetEntityFacing(ENTITY_ZACK, FACING_UP);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityYTo(ENTITY_ZACK, Y(145), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    MoveEntityXTo(ENTITY_ZACK, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_UP);
    MoveEntityYTo(ENTITY_ZACK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    HideEntity(ENTITY_ZACK);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    PanCameraTo(X(228), Y(171), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    MarkNpcSpokenTo(CHARACTER_ZACK);
    VarSet(VAR_FARM_INTRODUCTION_AND_SHIPPING_TUTORIAL_STATE, EVENT_LIFECYCLE_COMPLETED);
}
