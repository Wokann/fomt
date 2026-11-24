mary_text_table
{
    const char gText_ShopEvent_Supermarket_CurryPowderPurchase_CurryPowderPriceAndQuantityPrompt[] =
        "Willkommen!\r\n"
#ifdef BUGFIX
        "Currypulver zu je 50G.\r\n"
#else
        "Currypulver zu je 100G.\r\n"
#endif
        "Wie viele möchtest du?{Press}\p";

    const char gText_ShopEvent_Supermarket_CurryPowderPurchase_TooBadButYourHandsAre[] =
        "Zu schade, aber deine \r\n"
        "Hände sind schon voll. \r\n"
        "{Press}";

    const char gText_ShopEvent_Supermarket_CurryPowderPurchase_TooBadButYouDontHave[] =
        "Zu schade, du hast \r\n"
        "nicht genug Geld.\r\n"
        "{Press}";
};
