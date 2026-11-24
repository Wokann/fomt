mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterInvitesPlayerToWeddingCelebration[] =
        "Hi, {Player}.\r\n"
        "Heute ist Ellis und des \r\n"
        "Doktors Hochzeitstag!! {Press}\p"
        "Komm und feier mit uns! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_ChoiceAttendWedding[] =
        "Ok!";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_ChoiceKeepWorking[] =
#if defined(BUGFIX)
    // The player still has work, rather than assigning work to Carter.
        "Ich muss arbeiten.";
#else
        "Ich habe Arbeit für dich.";
#endif

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterWelcomesPlayerToCelebration[] =
        "Dann lass uns feiern! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterToastsElliAndDoctor[] =
        "Auf das junge Paar! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterInvitesPlayerToComeLater[] =
        "Komm vorbei, wenn du \r\n"
        "kannst. {Press}";
};
