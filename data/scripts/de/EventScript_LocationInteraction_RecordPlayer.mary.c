#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_RecordPlayer_RecordPlayer[] =
        "Plattenspieler{Press}";

    const char gText_LocationInteraction_RecordPlayer_Table[] =
        "Tisch{Press}";
};

void EventScript_LocationInteraction_RecordPlayer(void)
{
    int var_0, var_1;
    if (VarGet(VAR_HAS_RECORD_PLAYER) == TRUE)
    {
        var_0 = FALSE;
        if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
        {
            var_1 = GetPlayerHeldArticleId();
            switch (var_1)
            {
                case ITEM_ARTICLE_ALBUM_1:
                case ITEM_ARTICLE_ALBUM_2:
                case ITEM_ARTICLE_ALBUM_3:
                case ITEM_ARTICLE_ALBUM_4:
                case ITEM_ARTICLE_ALBUM_5:
                case ITEM_ARTICLE_ALBUM_6:
                case ITEM_ARTICLE_ALBUM_7:
                case ITEM_ARTICLE_ALBUM_8:
                case ITEM_ARTICLE_ALBUM_9:
                case ITEM_ARTICLE_ALBUM_10:
                case ITEM_ARTICLE_ALBUM_11:
                case ITEM_ARTICLE_ALBUM_12:
                case ITEM_ARTICLE_ALBUM_13:
                case ITEM_ARTICLE_ALBUM_14:
                case ITEM_ARTICLE_ALBUM_15:
                    var_0 = TRUE;
                    break;
            }
        }
        if (var_0)
        {
            if (IsPlayerHeldItemWrapped() == TRUE)
            {
                TalkOpen();
                TalkMessage(gText_LocationInteraction_RecordPlayer_RecordPlayer);
                TalkClose();
                return;
            }
            else
            {
                if (RecordPlayerHasAlbum())
                {
                    UsePlayerHeldItem();
                    var_1 = SwapRecordPlayerAlbum(var_1);
                    SetPlayerHeldArticle(var_1);
                }
                else
                {
                    UsePlayerHeldItem();
                    SwapRecordPlayerAlbum(var_1);
                }
            }
        }
        else
        {
            if (IsPlayerHoldingNothing() && RecordPlayerHasAlbum())
            {
                var_1 = RemoveRecordPlayerAlbum();
                SetPlayerHeldArticle(var_1);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_LocationInteraction_RecordPlayer_RecordPlayer);
                TalkClose();
            }
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_RecordPlayer_Table);
        TalkClose();
    }
}
