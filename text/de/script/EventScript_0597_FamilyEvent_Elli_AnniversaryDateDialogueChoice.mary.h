mary_text_table
{
    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "Guten Morgen!!\r\n"
        "Weißt du, warum heute\r\n"
        "ein besonderer Tag ist?{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "Mein Geburtstag?\r\n"
        "Nein, es ist unser \r\n"
        "Hochzeitstag, du Dummer! {Press}\r\n"
        "Ich kann nicht fassen, dass\r\n"
        "du das vergessen hast, ich\r\n"
        "konnte kaum abwarten, dir{Press}\r\n"
        "dein Geschenk zu geben!{Press}\p"
        "Aber das hast du jetzt \r\n"
        "nicht mehr verdient!{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "Du hast Recht!\r\n"
        "Ich dachte schon, du\r\n"
        "vergisst es, aber du bist so{Press}\r\n"
        "toll, du überraschst \r\n"
        "mich immer wieder!{Press}\p"
        "Ich liebe dich, {NickName}!{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "Hier bitte, {NickName}.{Press}";

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
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

    const char gText_FamilyEvent_Elli_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
#if defined(BUGFIX)
    // JP worries about illness and asks the player to rest.
        "Du scherzt, oder?!\r\n"
        "Geht es dir gut?{Press}\r\n"
        "Du hast vielleicht Fieber.{Press}\p"
        "Es ist unser Hochzeitstag,\r\n"
        "aber das muss jetzt warten.\r\n"
        "Ruh dich heute aus.{Press}";
#else
        "Du scherzt, oder?!\r\n"
        "Du hast besser Fieber,\r\n"
        "ansonsten gibt es keine {Press}\r\n"
        "Entschuldigung hierfür!{Press}\p"
        "Es ist unser Hochzeitstag! {Press}";
#endif
};
