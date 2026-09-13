#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenSearchesSleepingPlayersRucksack[] =
        "……………ゴソゴソ…{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenCannotLeaveGiftBecauseRucksackIsFull[] =
        "うわっ、\r\n"
        "これじゃあリュックの中には\r\n"
        "入れられないなぁ…{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenLeavesWithoutGivingGift[] =
        "ああ、もう。\r\n"
        "なんで寝ているときまで\r\n"
        "リュックせおってんだろ。{Press}\p"
        "…よし、入った入った。{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_MarySearchesSleepingPlayersRucksack[] =
        "ええっと…ゴソゴソゴソ…{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryCannotLeaveGiftBecauseRucksackIsFull[] =
        "リュックに入ったらあげよう\r\n"
        "かと思ったんだけど…\r\n"
        "いいか、自分で食べちゃお。{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryLeavesWithoutGivingGift[] =
        "んー、はやく起きないかな。\r\n"
        "{NickName}、よろこんで\r\n"
        "くれるかな。{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnSearchesSleepingPlayersRucksack[] =
        "ゴソゴソゴソ…{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnCannotLeaveGiftBecauseRucksackIsFull[] =
        "かー、しまったよー。{Press}\p"
        "リュックの中がいっぱいだった\r\n"
        "時の事なんて考えて\r\n"
        "なかったなぁ。{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnLeavesWithoutGivingGift[] =
        "うわっ！ああ、びっくりした。\r\n"
        "………起きてないよね、\r\n"
        "よかったー。{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriSearchesSleepingPlayersRucksack[] =
        "………ゴソ…ゴソ…{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriCannotLeaveGiftBecauseRucksackIsFull[] =
        "うそー、リュックがいっぱいで\r\n"
        "チョコが入らない！{Press}\p"
        "勝手に出したら、おこるかも\r\n"
        "しれないし…もういいもん！{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriLeavesWithoutGivingGift[] =
        "………寝てるみたいね。\r\n"
        "{NickName}、起きたら\r\n"
        "どんな顔するのかな？{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliSearchesSleepingPlayersRucksack[] =
        "ゴソゴソ…ふう…{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliCannotLeaveGiftBecauseRucksackIsFull[] =
        "あら、リュックがいっぱい\r\n"
        "だわ。後から忘れないで\r\n"
        "わたせるかしら？{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliLeavesWithoutGivingGift[] =
        "{NickName}は、今日が\r\n"
        "冬の感謝祭だって事、分かって\r\n"
        "いるのかしら。{Press}\p"
        "そうだ、もうリュックの中に\r\n"
        "入れておきましょ。{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessFindsPlayerAsleep[] =
        "キラキラキラ…ただいまーっ\r\n"
        "て…あれ？\r\n"
        "寝てるじゃない…{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessCannotLeaveGiftBecauseRucksackFull[] =
        "ん～、困ったわね…せっかく\r\n"
        "作ったのに…リュックが\r\n"
        "いっぱいじゃしょうがないか。{Press}\p"
        "じゃね～、キラキラキラ。{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessLeavesGiftInSleepingPlayersRucksack[] =
        "{Player}ちゃん、いいもの\r\n"
        "持ってきたわよ～。\r\n"
        "起きなさ～い。{Press}\p"
        "…ぜんぜん起きないわねー…\r\n"
        "しょうがないわね～。じゃ、\r\n"
        "リュックに入れておきましょ。{Press}";
};

void EventScript_FestivalEvent_WinterThanksgiving_RucksackFull(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_NIGHT);
    if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_ORIGINAL)
    {
        ChangeMap(MAP_FARMHOUSE, X(200), Y(48));
        SetEntityPosition(ENTITY_PLAYER, X(200), Y(mary_negated_int(-46)), FACING_DOWN);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
    }
    else
    {
        if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_FIRST_EXTENSION)
        {
            ChangeMap(MAP_FARMHOUSE, X(320), Y(48));
            SetEntityPosition(ENTITY_PLAYER, X(320), Y(mary_negated_int(-46)), FACING_DOWN);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
        }
        else
        {
            if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_SECOND_EXTENSION)
            {
                ChangeMap(MAP_FARMHOUSE, X(384), Y(48));
                SetEntityPosition(ENTITY_PLAYER, X(384), Y(mary_negated_int(-46)), FACING_DOWN);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
            }
        }
    }
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
    VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    WaitFrames(60 * 2);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenSearchesSleepingPlayersRucksack);
        TalkClose();
        if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
        {
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenCannotLeaveGiftBecauseRucksackIsFull);
            TalkClose();
            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        else
        {
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenLeavesWithoutGivingGift);
            TalkClose();
            if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_YELLOW_MIN)
            {
                AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_YELLOW_MIN)
                {
                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            AddCharacterLove(CHARACTER_KAREN, 1000);
        }
    }
    else
    {
        if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_MarySearchesSleepingPlayersRucksack);
            TalkClose();
            if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_MARY);
                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryCannotLeaveGiftBecauseRucksackIsFull);
                TalkClose();
                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            }
            else
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_MARY);
                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryLeavesWithoutGivingGift);
                TalkClose();
                if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_YELLOW_MIN)
                {
                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_YELLOW_MIN)
                    {
                        AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                    }
                }
                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                AddCharacterLove(CHARACTER_MARY, 1000);
            }
        }
        else
        {
            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                MarkNpcSpokenTo(CHARACTER_ANN);
                SetTalkNameplateCharacter(CHARACTER_ANN);
                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnSearchesSleepingPlayersRucksack);
                TalkClose();
                if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                {
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnCannotLeaveGiftBecauseRucksackIsFull);
                    TalkClose();
                    VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                }
                else
                {
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnLeavesWithoutGivingGift);
                    TalkClose();
                    if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_YELLOW_MIN)
                    {
                        AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                    }
                    else
                    {
                        if (GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_YELLOW_MIN)
                        {
                            AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                        }
                    }
                    VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    AddCharacterLove(CHARACTER_ANN, 1000);
                }
            }
            else
            {
                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    MarkNpcSpokenTo(CHARACTER_POPURI);
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriSearchesSleepingPlayersRucksack);
                    TalkClose();
                    if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                    {
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriCannotLeaveGiftBecauseRucksackIsFull);
                        TalkClose();
                        VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    }
                    else
                    {
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriLeavesWithoutGivingGift);
                        TalkClose();
                        if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN)
                        {
                            AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                        }
                        else
                        {
                            if (GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                            {
                                AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                            }
                        }
                        VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        AddCharacterLove(CHARACTER_POPURI, 1000);
                    }
                }
                else
                {
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        MarkNpcSpokenTo(CHARACTER_ELLI);
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliSearchesSleepingPlayersRucksack);
                        TalkClose();
                        if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                        {
                            TalkOpen();
                            SetTalkNameplateCharacter(CHARACTER_ELLI);
                            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliCannotLeaveGiftBecauseRucksackIsFull);
                            TalkClose();
                            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        }
                        else
                        {
                            TalkOpen();
                            SetTalkNameplateCharacter(CHARACTER_ELLI);
                            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliLeavesWithoutGivingGift);
                            TalkClose();
                            if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_YELLOW_MIN)
                            {
                                AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                            }
                            else
                            {
                                if (GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_YELLOW_MIN)
                                {
                                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                                }
                            }
                            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            AddCharacterLove(CHARACTER_ELLI, 1000);
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                        {
                            MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
                            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessFindsPlayerAsleep);
                            TalkClose();
                            if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                            {
                                TalkOpen();
                                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessCannotLeaveGiftBecauseRucksackFull);
                                TalkClose();
                                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            }
                            else
                            {
                                TalkOpen();
                                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessLeavesGiftInSleepingPlayersRucksack);
                                TalkClose();
                                if (GetCharacterLove(CHARACTER_HARVEST_GODDESS) >= LOVE_HEART_YELLOW_MIN)
                                {
                                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                                }
                                else
                                {
                                    if (GetCharacterLove(CHARACTER_HARVEST_GODDESS) < LOVE_HEART_YELLOW_MIN)
                                    {
                                        AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                                    }
                                }
                                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                AddCharacterLove(CHARACTER_HARVEST_GODDESS, 1000);
                            }
                        }
                    }
                }
            }
        }
    }
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
