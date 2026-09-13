#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_StockingGift_ThomasDelivery_NoStockingInstalled[] =
        "!!...Uff, es ist viel\r\n"
        "schwerer als ich dachte,\r\n"
        "sich wo einzuschleichen!{Press}\p"
        "Warte, hier ist kein\r\n"
        "Strumpf...{Press}\p"
        "Das heißt, ich kann kein\r\n"
        "Geschenk hier lassen. \r\n"
        "Zu dumm!{Press}\p"
        "Ich schätze, ich muss es\r\n"
        "wieder mitnehmen...{Press}";

    const char gText_FestivalEvent_StockingGift_ThomasDelivery_GiftPlacedInEmptyStocking[] =
        "!!...Uff, es ist viel\r\n"
        "schwerer als ich dachte,\r\n"
        "sich wo einzuschleichen!{Press}\p"
        "Gut, er hat einen Strumpf\r\n"
        "aufgehängt. {Press}\p"
        "Es ist so dunkel, ich kann\r\n"
        "nicht sehen, welches sein \r\n"
        "Geschenk ist!{Press}\p"
        "Ach egal, es ist\r\n"
        "wohl dieses!{Press}";

    const char gText_FestivalEvent_StockingGift_ThomasDelivery_ExistingGiftBlocksDelivery[] =
        "!!...Uff, es ist viel\r\n"
        "schwerer als ich dachte,\r\n"
        "sich wo einzuschleichen!{Press}\p"
        "Das Geschenk ist noch da!\r\n"
        "Manche Leute scheren\r\n"
        "sich gar nicht um die {Press}\r\n"
        "Mühe, die ich mir mache!{Press}\p"
        "Enttäuschend... Ich \r\n"
        "gehe einfach heim...{Press}";
};

void EventScript_FestivalEvent_StockingGift_ThomasDelivery(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_NIGHT);
    switch (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL))
    {
        case FARMHOUSE_UPGRADE_ORIGINAL:
            ChangeMap(MAP_FARMHOUSE, X(200), Y(48));
            SetEntityPosition(ENTITY_PLAYER, X(200), Y(mary_negated_int(-46)), FACING_DOWN);
            break;
        case FARMHOUSE_UPGRADE_FIRST_EXTENSION:
            ChangeMap(MAP_FARMHOUSE, X(320), Y(48));
            SetEntityPosition(ENTITY_PLAYER, X(320), Y(mary_negated_int(-46)), FACING_DOWN);
            break;
        case FARMHOUSE_UPGRADE_SECOND_EXTENSION:
            ChangeMap(MAP_FARMHOUSE, X(384), Y(48));
            SetEntityPosition(ENTITY_PLAYER, X(384), Y(mary_negated_int(-46)), FACING_DOWN);
            break;
    }
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        SetEntityPosition(ENTITY_KAREN, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
        SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IN_BED);
    }
    else
    {
        if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            SetEntityPosition(ENTITY_POPURI, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IN_BED);
        }
        else
        {
            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetEntityPosition(ENTITY_ANN, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IN_BED);
            }
            else
            {
                if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetEntityPosition(ENTITY_MARY, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
                    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IN_BED);
                }
                else
                {
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetEntityPosition(ENTITY_ELLI, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
                        SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IN_BED);
                    }
                }
            }
        }
    }
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_SLEEPING);
        }
        else
        {
            SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_INFANT_SLEEPING);
        }
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_THOMAS_STOCKING_DELIVERY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    WaitFrames(60 * 2);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    if (VarGet(VAR_HAS_STOCKING) == FALSE)
    {
        TalkMessage(gText_FestivalEvent_StockingGift_ThomasDelivery_NoStockingInstalled);
        TalkClose();
        VarSet(VAR_THOMAS_STOCKING_DELIVERY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
    }
    else
    {
        if (VarGet(VAR_STOCKING_ARTICLE_ID) == ITEM_ARTICLE_NONE)
        {
            TalkMessage(gText_FestivalEvent_StockingGift_ThomasDelivery_GiftPlacedInEmptyStocking);
            TalkClose();
            VarSet(VAR_THOMAS_STOCKING_DELIVERY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            switch (VarGet(VAR_THOMAS_STOCKING_GIFT_SELECTION))
            {
                case THOMAS_STOCKING_GIFT_NONE:
                case THOMAS_STOCKING_GIFT_MYSTRILE:
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_MYSTRILE);
                    break;
                case THOMAS_STOCKING_GIFT_ORICHALC:
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_ORICHALC);
                    break;
                case THOMAS_STOCKING_GIFT_MOON_STONE:
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_MOON_STONE);
                    break;
                case THOMAS_STOCKING_GIFT_SAND_ROSE:
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_SAND_ROSE);
                    break;
                case THOMAS_STOCKING_GIFT_ALEXANDRITE:
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_ALEXANDRITE);
                    break;
            }
            VarSet(VAR_THOMAS_STOCKING_GIFT_SELECTION, THOMAS_STOCKING_GIFT_NONE);
            AddNpcFriendship(CHARACTER_THOMAS, 20);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
        }
        else
        {
            TalkMessage(gText_FestivalEvent_StockingGift_ThomasDelivery_ExistingGiftBlocksDelivery);
            TalkClose();
            VarSet(VAR_THOMAS_STOCKING_DELIVERY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            VarSet(VAR_THOMAS_STOCKING_GIFT_SELECTION, THOMAS_STOCKING_GIFT_NONE);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
        }
    }
}
