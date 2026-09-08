#ifndef SPOUSE_GIFT_HH
#define SPOUSE_GIFT_HH

#include "prelude.h"

EXTERN_C

struct SpouseGiftArticleWeightEntry
{
    u8 weight;
    u8 padding;
    u16 article_id;
};

extern SpouseGiftArticleWeightEntry const gSpouseGiftArticleSelectionEntries[5];

EXTERN_C_END

#endif // SPOUSE_GIFT_HH
