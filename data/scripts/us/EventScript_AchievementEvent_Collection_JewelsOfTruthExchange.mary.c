#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_AchievementEvent_Collection_JewelsOfTruthExchange_ThomasRecognizesFinalJewelAndLeadsPlayer[] =
        "You have found the final \r\n"
        "Jewel of Truth. {Press}\p"
        "Please follow me.{Press}";

    const char gText_AchievementEvent_Collection_JewelsOfTruthExchange_ThomasOffersGemOfTruthExchange[] =
        "You can now exchange all of \r\n"
        "the Jewels of Truth for \r\n"
        "the Gem of Truth. {Press}";

    const char gText_AchievementEvent_Collection_JewelsOfTruthExchange_ThomasDefersExchangeUntilToolSlotAvailable[] =
        "...But, it seems you can't \r\n"
        "hold any more. {Press}\p"
        "Come back when your \r\n"
        "load is lighter. {Press}";
};

void EventScript_AchievementEvent_Collection_JewelsOfTruthExchange(void)
{
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(10);
    if (VarGet(VAR_JEWELS_OF_TRUTH_EXCHANGE_RETRY_STATE) != EVENT_LIFECYCLE_COMPLETED)
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        TalkMessage(gText_AchievementEvent_Collection_JewelsOfTruthExchange_ThomasRecognizesFinalJewelAndLeadsPlayer);
        TalkClose();
        PanCameraTo(X(120), Y(88), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
        MoveEntityXTo(ENTITY_PLAYER, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        MoveEntityYTo(ENTITY_PLAYER, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    TalkMessage(gText_AchievementEvent_Collection_JewelsOfTruthExchange_ThomasOffersGemOfTruthExchange);
    if (GetPlayerHeldToolStackCount() != mary_negated_int(ITEM_TOOL_STACK_NOT_PRESENT) && GetFirstFreeRucksackToolSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
        TalkMessage(gText_AchievementEvent_Collection_JewelsOfTruthExchange_ThomasDefersExchangeUntilToolSlotAvailable);
        TalkClose();
        VarSet(VAR_JEWELS_OF_TRUTH_EXCHANGE_RETRY_STATE, EVENT_LIFECYCLE_COMPLETED);
    }
    else
    {
        TalkClose();
        if (IsPlayerHoldingNothing() == FALSE)
        {
            if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
            {
                if (GetPlayerHeldArticleId() == ITEM_ARTICLE_JEWEL_OF_TRUTH)
                {
                    UsePlayerHeldItem();
                }
            }
        }
        RemoveAllOwnedArticles(ITEM_ARTICLE_JEWEL_OF_TRUTH);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
            ShowPlayerHoldingTool(ITEM_TOOL_GEM_TRUTH);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        if (GetPlayerHeldToolStackCount() == mary_negated_int(ITEM_TOOL_STACK_NOT_PRESENT))
        {
            SetPlayerHeldTool(ITEM_TOOL_GEM_TRUTH, 1);
        }
        else
        {
            AddToolToRucksack(ITEM_TOOL_GEM_TRUTH, 1);
        }
        VarSet(VAR_JEWELS_OF_TRUTH_REWARD_STATE, EVENT_LIFECYCLE_COMPLETED);
    }
}
