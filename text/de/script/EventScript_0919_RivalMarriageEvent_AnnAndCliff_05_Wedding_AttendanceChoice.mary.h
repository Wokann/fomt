mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterInvitesPlayerToCelebrateWedding[] =
        "Hi, {Player}.\r\n"
        "Heute ist Cliffs und \r\n"
        "Anns Hochzeit!! {Press}\p"
        "Komm und feier mit uns!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_ChoiceCelebrateWedding[] =
        "Ok!";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_ChoiceKeepWorking[] =
#if defined(BUGFIX)
    // The player still has work, rather than assigning work to Carter.
        "Ich muss arbeiten.";
#else
        "Ich habe Arbeit für dich.";
#endif

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterWelcomesPlayerToCelebration[] =
        "Dann lass uns feiern! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_GuestsToastNewlyweds[] =
        "Auf das junge Paar! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterInvitesPlayerToJoinWhenFree[] =
        "Komm vorbei, wenn du \r\n"
        "kannst. {Press}";
};
