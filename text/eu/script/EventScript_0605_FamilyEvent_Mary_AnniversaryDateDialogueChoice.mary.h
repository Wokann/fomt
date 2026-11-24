mary_text_table
{
    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "Good morning!\r\n"
        "Did you sleep well?\r\n"
        "Do you know what today is?{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "Your birthday";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "Our anniversary";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "My birthday";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "My birthday?!?\r\n"
        "This means you don't \r\n"
        "really remember either my{Press}\r\n"
        "birthday or our anniversary!{Press}\p"
        "So much for your present!{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "Of course! I knew \r\n"
        "you'd remember! You're so\r\n"
        "considerate, {NickName}.{Press}\p"
        "Here's a present for you!{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "Here you are, {NickName}.{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
        "I'm going to give you a \r\n"
        "present, so empty your \r\n"
        "hands, OK?{Press}";

    const char gText_FamilyEvent_Mary_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
#if defined(BUGFIX)
    // The birthday takes the possessive Your, not You are.
        "Your birthday!?\r\n"
#else
        "You're birthday!?\r\n"
#endif
        "That's the most insensitive \r\n"
        "thing I've ever heard!{Press}\p"
        "Now you're not getting\r\n"
        "your present anymore!{Press}";
};
