mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterInvitesPlayerToWedding[] =
        "Hi, {Player}.\r\n"
        "Heute heiraten Karen  \r\n"
        "und Rick!! {Press}\p"
        "Komm und feier mit uns! {Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_ChoiceAttendWedding[] =
        "Ok!";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_ChoiceKeepWorking[] =
#if defined(BUGFIX)
    // The player still has work, rather than assigning work to Carter.
        "Ich muss arbeiten.";
#else
        "Ich habe Arbeit für dich.";
#endif

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterBeginsWeddingCelebration[] =
        "Dann lass uns feiern! {Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_GuestsToastNewlyweds[] =
        "Auf das junge Paar! {Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterInvitesPlayerAfterWork[] =
        "Komm vorbei, wenn du \r\n"
        "kannst. {Press}";
};
