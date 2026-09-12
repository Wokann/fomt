#include "supermarket_text.hh"

#if defined(FOMT_TEXT_SUPERMARKET_PRIMARY)

char const gText_Supermarket_EquipmentCapacityFull[] =
    "Ich fürchte du kannst\r\n"
    "nichts mehr aufrüsten...{Press}";

char const gText_Supermarket_BlankLinePair[] =
    "\r\n"
    "\r\n";

char const gText_Supermarket_InsufficientGold[] =
    "Hm...tja...Du hast\r\n"
    "wohl nicht genug Gold...{Press}";

char const gText_Supermarket_ThankYou[] =
    "Vielen Dank!{Press}";

char const gText_Supermarket_PurchaseConfirmation[] =
    "Echt?\r\n"
    "Bist du sicher?{Press}";

char const gText_Supermarket_PurchaseMorePrompt[] =
    "Brauchst du noch etwas?{Press}";

char const gText_Supermarket_EquipmentDelivery[] =
    "Vielen Dank.{Press}\p"
    "Warte eine Minute.\r\n"
    "Dein Rucksack ist voll.\r\n"
    "Ich lasse es liefern.{Press}.";

char const gText_Supermarket_DeliveryPartial[] =
    "Vielen Dank.{Press}\p"
    "Warte.\r\n"
    "Du kannst nicht mehr tragen.\r\n"
    "Ich lasse es liefern.{Press}";

#elif defined(FOMT_TEXT_SUPERMARKET_SECONDARY)

char const gText_Supermarket_SeedDelivery[] =
    "Vielen Dank.{Press}\p"
    "Warte.\r\n"
    "Dein Rucksack ist voll.\r\n"
    "Ich lasse es liefern.{Press}";

char const gText_Supermarket_SeedPurchaseConfirmation[] =
    "Bist du sicher?{Press}";

extern char const gCppRuntimeBadAlloc_SupermarketTrailer[] =
    "bad_alloc";

#else
#error "Select one supermarket text fragment before including this file."
#endif
