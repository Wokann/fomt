#include "spouse_gift.hh"

#include "item.hh"

EXTERN_C

// func_08043484 samples (rand() >> 4) & 0xFF against each weight and returns
// the selected article_id. The second byte in every native record is zero.
SpouseGiftArticleWeightEntry const gSpouseGiftArticleSelectionEntries[5] = {
    { 125, 0, ITEM_ARTICLE_AMETHYST },
    { 43, 0, ITEM_ARTICLE_TOPAZ },
    { 43, 0, ITEM_ARTICLE_RUBY },
    { 43, 0, ITEM_ARTICLE_DIAMOND },
    { 1, 0, ITEM_ARTICLE_PINK_DIAMOND },
};

EXTERN_C_END
