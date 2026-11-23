#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectEllenHouseAndSupermarketResidenceBookshelf[] =
        "Bookshelf{Press}";
};

void EventScript_0191_LocationInteraction_InspectEllenHouseAndSupermarketResidenceBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectEllenHouseAndSupermarketResidenceBookshelf);
    TalkClose();
}
