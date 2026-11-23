mary_text_table
{
    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeInvitesPlayerToGrapeHarvest[] =
        "Hi, {Player}. \r\n"
        "Morgen ernten wir \r\n"
        "Weintrauben. {Press}\r\n"
        "Willst du aushelfen?{Press}";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_ChoiceAcceptHelp[] =
        "Sicher!";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_ChoiceDeclineHelp[] =
        "Ich habe zu tun.";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeSchedulesTenAmPaidWork[] =
        "Toll! Wenn das so ist,\r\n"
        "komm gegen 10 Uhr. {Press}\p"
        "Wir bezahlen dich natürlich.{Press}";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeAsksPlayerToInviteAnotherWorker[] =
// Replace the untranslated line-break marker with the actual CR/LF control.
#ifdef BUGFIX
        "Oh ja. Wir brauchen noch \r\n"
        "jemanden, also bring Beglei-\r\n"
#else
        "Oh ja. Wir brauchen noch ret>jemanden, also bring Beglei-\r\n"
#endif
        "tung, wenn du dran denkst.{Press}";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeAcceptsDeclineAndStillRequestsRecruitment[] =
        "Das ist verständlich. \r\n"
        "Du hast deine eigene \r\n"
        "Farm zu bewirtschaften! {Press}\p"
        "Fragst du dann jemanden\r\n"
        "für mich? Du kannst \r\n"
        "natürlich auch kommen!{Press}";
};
