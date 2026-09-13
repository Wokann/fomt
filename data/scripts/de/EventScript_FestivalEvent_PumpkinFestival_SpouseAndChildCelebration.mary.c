#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_KarenIntroductionWithWalkingChild[] =
        "Heute ist das Kürbis- \r\n"
        "festival, also habe ich\r\n"
        "Leckereien für {Press}\r\n"
        "{Baby}\r\n"
        "und dich gemacht. {Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PopuriIntroductionWithWalkingChild[] =
        "Heute ist das Kürbis- \r\n"
        "festival. {Press}\p"
        "Ich habe eine Menge\r\n"
        "Süßigkeiten für\r\n"
        "{Baby}{Press}\r\n"
        "und dich gemacht.{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_AnnIntroductionWithWalkingChild[] =
        "Heute ist das Kürbis-\r\n"
        "festival. {Press}\p"
        "Ich habe eine Menge\r\n"
        "Süßes für euch gemacht!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_MaryIntroductionWithWalkingChild[] =
        "Heute ist das Kürbis-\r\n"
        "festival, ich habe versucht,\r\n"
        "Süßigkeiten zu machen. {Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ElliIntroductionWithWalkingChild[] =
        "Heute ist das Kürbis- \r\n"
        "festival, darum haben Oma\r\n"
        "und ich eine Menge {Press}\r\n"
        "Leckereien für dich und\r\n"
        "{Baby} gemacht.{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ChildBabbles[] =
        "Ga-ga!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_KarenInvitesFamilyToEatSweets[] =
        "Probier sie mal!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_Shared_PopuriAnnAndMaryInviteFamilyToEatSweets[] =
        "Essen wir!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ElliInvitesFamilyToEatSweets[] =
        "Iss jetzt auf!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PlayerOvereatsPumpkinSweetsWithWalkingChild[] =
        "Mir ist schlecht von den \r\n"
        "vielen Süßigkeiten...ich \r\n"
        "fühle schon die {Press}\r\n"
        "Zahnlöcher.{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_KarenIntroductionWithoutWalkingChild[] =
        "Heute ist das Kürbis- \r\n"
        "festival, also habe ich\r\n"
        "Süßes für {Baby}{Press}\r\n"
        "und dich gemacht. Ich\r\n"
        "hoffe, sie schmecken...{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PopuriIntroductionWithoutWalkingChild[] =
        "Heute ist das Kürbis- \r\n"
        "festival. {Press}\p"
        "Ich habe eine Menge\r\n"
        "Süßigkeiten für {Baby}\r\n"
        "und dich gemacht. {Press}\r\n"
        "Esst alles auf!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_AnnIntroductionWithoutWalkingChild[] =
        "Heute ist das Kürbis- \r\n"
        "festival. {Press}\p"
        "Ich habe eine Menge\r\n"
        "Süßes für euch gemacht!\r\n"
        "Esst alles auf!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_MaryIntroductionWithYoungChild[] =
        "Heute ist das Kürbis-\r\n"
        "festival.{Press}\p"
        "Ich habe Pasteten.\r\n"
        "Möchtest du probieren?{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ElliIntroductionWithoutWalkingChild[] =
        "Heute ist das Kürbis- \r\n"
        "festival, darum haben Oma\r\n"
        "und ich jede Menge {Press}\r\n"
        "Süßes gemacht.{Press}\p"
        "Keine Sorge, sie hat sie \r\n"
        "schon probiert. \r\n"
        "Iss auf!{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PlayerOvereatsPumpkinSweetsWithoutWalkingChild[] =
        "Mir ist schlecht von den\r\n"
        "vielen Süßigkeiten...ich \r\n"
        "fühle schon die {Press}\r\n"
        "Zahnlöcher.{Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_MaryIntroductionWithoutChild[] =
        "Heute ist das Kürbis-\r\n"
        "festival, ich habe versucht,\r\n"
        "Süßigkeiten zu machen.{Press}\r\n"
        "Koste sie mal. {Press}";

    const char gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PlayerOvereatsPumpkinSweetsWithoutChild[] =
        "Mir ist schlecht von den \r\n"
        "vielen Süßigkeiten...ich\r\n"
        "fühle schon die {Press}\r\n"
        "Zahnlöcher.{Press}";
};

void EventScript_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration(void)
{
    ChangeMap(MAP_FARMHOUSE, X(288), Y(148));
    SetEntityPosition(ENTITY_PLAYER, X(304), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        SetEntityPosition(ENTITY_KAREN, X(288), Y(99), FACING_DOWN);
        SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    }
    else
    {
        if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            SetEntityPosition(ENTITY_POPURI, X(288), Y(99), FACING_DOWN);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
        }
        else
        {
            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetEntityPosition(ENTITY_ANN, X(288), Y(99), FACING_DOWN);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            }
            else
            {
                if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetEntityPosition(ENTITY_MARY, X(288), Y(99), FACING_DOWN);
                    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
                }
                else
                {
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetEntityPosition(ENTITY_ELLI, X(288), Y(99), FACING_DOWN);
                        SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
                    }
                }
            }
        }
    }
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            SetEntityPosition(ENTITY_CHILD, X(304), Y(96), FACING_DOWN);
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
            }
            else
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
            }
        }
    }
    CreateEventIcon(EVENT_ICON_SLOT_0, X(288), Y(120), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(304), Y(121), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_COOKIES));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(148), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(295), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(60);
    TalkOpen();
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        AddNpcFriendship(CHARACTER_CHILD, 20);
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetTalkNameplateCharacter(CHARACTER_KAREN);
                SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                ShowTalkHeartIndicator(CHARACTER_KAREN);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_KarenIntroductionWithWalkingChild);
                TalkClose();
            }
            else
            {
                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PopuriIntroductionWithWalkingChild);
                    TalkClose();
                }
                else
                {
                    if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_AnnIntroductionWithWalkingChild);
                        TalkClose();
                    }
                    else
                    {
                        if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            SetTalkNameplateCharacter(CHARACTER_MARY);
                            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                            ShowTalkHeartIndicator(CHARACTER_MARY);
                            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_MaryIntroductionWithWalkingChild);
                            TalkClose();
                        }
                        else
                        {
                            if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkNameplateCharacter(CHARACTER_ELLI);
                                SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_ELLI);
                                TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ElliIntroductionWithWalkingChild);
                                TalkClose();
                            }
                        }
                    }
                }
            }
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_CHILD);
            SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ChildBabbles);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_CHILD);
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetTalkNameplateCharacter(CHARACTER_KAREN);
                SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                ShowTalkHeartIndicator(CHARACTER_KAREN);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_KarenInvitesFamilyToEatSweets);
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_KAREN);
                AddCharacterLove(CHARACTER_KAREN, 1000);
            }
            else
            {
                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_Shared_PopuriAnnAndMaryInviteFamilyToEatSweets);
                    TalkClose();
                    MarkNpcSpokenTo(CHARACTER_POPURI);
                    AddCharacterLove(CHARACTER_POPURI, 1000);
                }
                else
                {
                    if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_Shared_PopuriAnnAndMaryInviteFamilyToEatSweets);
                        TalkClose();
                        MarkNpcSpokenTo(CHARACTER_ANN);
                        AddCharacterLove(CHARACTER_ANN, 1000);
                    }
                    else
                    {
                        if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            SetTalkNameplateCharacter(CHARACTER_MARY);
                            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                            ShowTalkHeartIndicator(CHARACTER_MARY);
                            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_Shared_PopuriAnnAndMaryInviteFamilyToEatSweets);
                            TalkClose();
                            MarkNpcSpokenTo(CHARACTER_MARY);
                            AddCharacterLove(CHARACTER_MARY, 1000);
                        }
                        else
                        {
                            if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkNameplateCharacter(CHARACTER_ELLI);
                                SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_ELLI);
                                TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ElliInvitesFamilyToEatSweets);
                                TalkClose();
                                MarkNpcSpokenTo(CHARACTER_ELLI);
                                AddCharacterLove(CHARACTER_ELLI, 1000);
                            }
                        }
                    }
                }
            }
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            if (IsPlayerHoldingNothing())
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
            TalkOpen();
            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PlayerOvereatsPumpkinSweetsWithWalkingChild);
            TalkClose();
            VarSet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
        }
        else
        {
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetTalkNameplateCharacter(CHARACTER_KAREN);
                SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                ShowTalkHeartIndicator(CHARACTER_KAREN);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_KarenIntroductionWithoutWalkingChild);
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_KAREN);
                AddCharacterLove(CHARACTER_KAREN, 1000);
            }
            else
            {
                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PopuriIntroductionWithoutWalkingChild);
                    TalkClose();
                    MarkNpcSpokenTo(CHARACTER_POPURI);
                    AddCharacterLove(CHARACTER_POPURI, 1000);
                }
                else
                {
                    if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_AnnIntroductionWithoutWalkingChild);
                        TalkClose();
                        MarkNpcSpokenTo(CHARACTER_ANN);
                        AddCharacterLove(CHARACTER_ANN, 1000);
                    }
                    else
                    {
                        if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            SetTalkNameplateCharacter(CHARACTER_MARY);
                            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                            ShowTalkHeartIndicator(CHARACTER_MARY);
                            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_MaryIntroductionWithYoungChild);
                            TalkClose();
                            MarkNpcSpokenTo(CHARACTER_MARY);
                            AddCharacterLove(CHARACTER_MARY, 1000);
                        }
                        else
                        {
                            if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkNameplateCharacter(CHARACTER_ELLI);
                                SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_ELLI);
                                TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ElliIntroductionWithoutWalkingChild);
                                TalkClose();
                                MarkNpcSpokenTo(CHARACTER_ELLI);
                                AddCharacterLove(CHARACTER_ELLI, 1000);
                            }
                        }
                    }
                }
            }
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            if (IsPlayerHoldingNothing())
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
            TalkOpen();
            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PlayerOvereatsPumpkinSweetsWithoutWalkingChild);
            TalkClose();
            VarSet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
        }
    }
    else
    {
        if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_KarenIntroductionWithoutWalkingChild);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            AddCharacterLove(CHARACTER_KAREN, 1000);
        }
        else
        {
            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                ShowTalkHeartIndicator(CHARACTER_POPURI);
                TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PopuriIntroductionWithoutWalkingChild);
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_POPURI);
                AddCharacterLove(CHARACTER_POPURI, 1000);
            }
            else
            {
                if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_AnnIntroductionWithoutWalkingChild);
                    TalkClose();
                    MarkNpcSpokenTo(CHARACTER_ANN);
                    AddCharacterLove(CHARACTER_ANN, 1000);
                }
                else
                {
                    if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetTalkNameplateCharacter(CHARACTER_MARY);
                        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                        ShowTalkHeartIndicator(CHARACTER_MARY);
                        TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_MaryIntroductionWithoutChild);
                        TalkClose();
                        MarkNpcSpokenTo(CHARACTER_MARY);
                        AddCharacterLove(CHARACTER_MARY, 1000);
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            SetTalkNameplateCharacter(CHARACTER_ELLI);
                            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                            ShowTalkHeartIndicator(CHARACTER_ELLI);
                            TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_ElliIntroductionWithoutWalkingChild);
                            TalkClose();
                            MarkNpcSpokenTo(CHARACTER_ELLI);
                            AddCharacterLove(CHARACTER_ELLI, 1000);
                        }
                    }
                }
            }
        }
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        if (IsPlayerHoldingNothing())
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        WaitFrames(60);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        RemoveEventIcon(EVENT_ICON_SLOT_0);
        RemoveEventIcon(EVENT_ICON_SLOT_1);
        TalkOpen();
        TalkMessage(gText_FestivalEvent_PumpkinFestival_SpouseAndChildCelebration_PlayerOvereatsPumpkinSweetsWithoutChild);
        TalkClose();
        VarSet(VAR_PUMPKIN_FESTIVAL_FARMHOUSE_SPOUSE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
    }
}
