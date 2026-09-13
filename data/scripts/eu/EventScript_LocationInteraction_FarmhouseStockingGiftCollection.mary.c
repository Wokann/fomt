#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_NothingInStocking[] =
        "Nothing in the sock.{Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_PresentFoundInside[] =
        "There was a present inside!{Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsMystrile[] =
        "It's Mystrile!{Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_MustEmptyHandsBeforeTakingGift[] =
        "I have to put \r\n"
        "something down first.{Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsOrichalc[] =
        "It's Orichalc!{Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsAMoonStone[] =
        "It's a Moon Stone!{Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsSandRose[] =
        "It's Sand Rose!{Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsAlexandrite[] =
        "It's Alexandrite {Press}";

    const char gText_LocationInteraction_FarmhouseStockingGiftCollection_StockingHook[] =
        "Sock Hook{Press}";
};

void EventScript_LocationInteraction_FarmhouseStockingGiftCollection(void)
{
    if (VarGet(VAR_HAS_STOCKING) == TRUE)
    {
        switch (VarGet(VAR_STOCKING_ARTICLE_ID))
        {
            case ITEM_ARTICLE_NONE:
                TalkOpen();
                TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_NothingInStocking);
                TalkClose();
                break;
            case ITEM_ARTICLE_MYSTRILE:
                TalkOpen();
                TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_PresentFoundInside);
                TalkClose();
                if (IsPlayerHoldingNothing())
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                    SetPlayerHeldWrappedArticle(ITEM_ARTICLE_MYSTRILE);
                    WaitFrames(30);
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsMystrile);
                    TalkClose();
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_NONE);
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_MustEmptyHandsBeforeTakingGift);
                    TalkClose();
                }
                break;
            case ITEM_ARTICLE_ORICHALC:
                TalkOpen();
                TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_PresentFoundInside);
                TalkClose();
                if (IsPlayerHoldingNothing())
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                    SetPlayerHeldWrappedArticle(ITEM_ARTICLE_ORICHALC);
                    WaitFrames(30);
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsOrichalc);
                    TalkClose();
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_NONE);
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_MustEmptyHandsBeforeTakingGift);
                    TalkClose();
                }
                break;
            case ITEM_ARTICLE_MOON_STONE:
                TalkOpen();
                TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_PresentFoundInside);
                TalkClose();
                if (IsPlayerHoldingNothing())
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                    SetPlayerHeldWrappedArticle(ITEM_ARTICLE_MOON_STONE);
                    WaitFrames(30);
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsAMoonStone);
                    TalkClose();
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_NONE);
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_MustEmptyHandsBeforeTakingGift);
                    TalkClose();
                }
                break;
            case ITEM_ARTICLE_SAND_ROSE:
                TalkOpen();
                TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_PresentFoundInside);
                TalkClose();
                if (IsPlayerHoldingNothing())
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                    SetPlayerHeldWrappedArticle(ITEM_ARTICLE_SAND_ROSE);
                    WaitFrames(30);
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsSandRose);
                    TalkClose();
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_NONE);
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_MustEmptyHandsBeforeTakingGift);
                    TalkClose();
                }
                break;
            case ITEM_ARTICLE_ALEXANDRITE:
                TalkOpen();
                TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_PresentFoundInside);
                TalkClose();
                if (IsPlayerHoldingNothing())
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                    SetPlayerHeldWrappedArticle(ITEM_ARTICLE_ALEXANDRITE);
                    WaitFrames(30);
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_ItsAlexandrite);
                    TalkClose();
                    VarSet(VAR_STOCKING_ARTICLE_ID, ITEM_ARTICLE_NONE);
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_MustEmptyHandsBeforeTakingGift);
                    TalkClose();
                }
                break;
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_FarmhouseStockingGiftCollection_StockingHook);
        TalkClose();
    }
}
