mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_WorkCompletionPrompt[] =
        "Are you done with work?{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceFinishedWork[] =
        "Yes";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceStillWorking[] =
        "No";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_DateQuestion[] =
        "{Player}, \r\n"
        "Do you know what day it \r\n"
        "is today? {Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceWeddingAnniversary[] =
        "Our anniversary";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoicePlayerBirthday[] =
#if defined(BUGFIX)
    // The answer is the player's birthday, not an anniversary.
        "My birthday";
#else
        "My anniversary";
#endif

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceHarvestGoddessBirthday[] =
        "Your birthday";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectWeddingAnniversaryResponse[] =
        "Our anniversary? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerRegretsIncorrectAnswer[] =
        "I better apologize later on.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_CorrectPlayerBirthdayResponse[] =
        "That's right!\r\n"
        "Congratulations!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_HarvestGoddessDiscussesFutureChild[] =
        "I can't wait to have kids...!{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_PlayerReflectsOnCelebration[] =
        "I had so much fun today!\r\n"
        "I'll sleep like a log...{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectHarvestGoddessBirthdayResponse[] =
        "My birthday? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";

#ifndef UNIFY_REGIONS
    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoicePlayerBirthday_2[] =
        "My birthday";
#endif

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_ChoiceChildBirthday[] =
        "{Baby}'s birthday";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_HarvestGoddessCelebratesPlayerMaturity[] =
        "You are now a grown man.\r\n"
        "Although, you still look \r\n"
        "more like a baby to me...{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_IncorrectChildBirthdayResponse[] =
        "{Baby}'s birthday? \r\n"
        "Hmm...\r\n"
        "Bye now.{Press}";

    const char gText_FamilyEvent_HarvestGoddess_PlayerBirthdayDateChoice_StillWorkingResponse[] =
        "Hurry up and finish work. {Press}";
};
