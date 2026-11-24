mary_text_table
{
    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "Guten Morgen!!\r\n"
        "Weißt du, was heute ist?{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "Mein Geburtstag?\r\n"
        "Nein, es ist unser, \r\n"
        "Hochzeitstag, du Dummer! {Press}\r\n"
        "Ich kann nicht fassen, dass \r\n"
        "du das vergessen hast. \r\n"
        "Ich konnte nicht erwarten,{Press}\r\n"
        "dir was zu schenken!{Press}\p"
        "Aber jetzt kriegst du \r\n"
        "es nicht mehr!{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "Du hast Recht!\r\n"
        "Du bist so ein guter \r\n"
        "Ehemann! Hier ist ein {Press}\r\n"
        "Geschenk für dich!{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "Hier bitte, {NickName}.{Press}";

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
#if defined(BUGFIX)
    // The deferred gift needs the empty-hands prompt.
        "Ich möchte dir etwas\r\n"
        "schenken, also mach\r\n"
        "deine Hände leer, OK?{Press}";
#else
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";
#endif

    const char gText_FamilyEvent_Ann_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
#if defined(BUGFIX)
    // Forgetting the anniversary makes Ann withhold the gift.
        "Den Hochzeitstag vergessen?\r\n"
        "Ich hatte ein Geschenk,\r\n"
        "das du jetzt nicht bekommst!{Press}";
#else
        "Ich möchte dir etwas \r\n"
        "schenken, also mach \r\n"
        "deine Hände leer, OK?{Press}";
#endif
};
