mary_text_table
{
    const char gText_ShopEvent_Supermarket_CurryPowderPurchase_CurryPowderPriceAndQuantityPrompt[] =
        "Welcome!\r\n"
#ifdef BUGFIX
        "Curry Powder is 50G each.\r\n"
#else
        "Curry Powder is 100G each.\r\n"
#endif
        "How many do you want?{Press}\p";

    const char gText_ShopEvent_Supermarket_CurryPowderPurchase_TooBadButYourHandsAre[] =
        "Too bad, but your \r\n"
        "hands are already full. \r\n"
        "{Press}";

    const char gText_ShopEvent_Supermarket_CurryPowderPurchase_TooBadButYouDontHave[] =
        "Too bad, but you \r\n"
        "don't have enough money.\r\n"
        "{Press}";
};
