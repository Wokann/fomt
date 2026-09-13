#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTheSquaresGarbageCanThrowAway[] =
        "広場のゴミ箱\r\n"
        "ゴミはここに捨てるんだろう。{Press}";
};

void EventScript_LocationInteraction_InspectTheSquaresGarbageCanThrowAway(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        TalkOpen();
        TalkAppendMessage(gText_LocationInteraction_InspectTheSquaresGarbageCanThrowAway);
        TalkClose();
    }
    else
    {
        if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_BASKET || GetPlayerHeldItemKind() == HELD_ITEM_KIND_DOG)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectTheSquaresGarbageCanThrowAway);
            TalkClose();
        }
        else
        {
            if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
            {
                if (!CanDiscardPlayerHeldArticle())
                {
                    TalkOpen();
                    TalkAppendMessage(gText_LocationInteraction_InspectTheSquaresGarbageCanThrowAway);
                    TalkClose();
                }
                else
                {
                    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
                    UsePlayerHeldItem();
                    PlaySong(AUDIO_START, AUDIO_SFX_SHIPMENT_DEPOSIT);
                }
            }
            else
            {
                PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
                UsePlayerHeldItem();
                PlaySong(AUDIO_START, AUDIO_SFX_SHIPMENT_DEPOSIT);
            }
        }
    }
}
