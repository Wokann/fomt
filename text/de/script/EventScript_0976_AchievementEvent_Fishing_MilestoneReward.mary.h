mary_text_table
{
    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishWithoutSize[] =
        "Du hast einen {Var1}\r\n"
        "gefangen.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInCentimeters[] =
// A 14-character fish name fills all 28 columns; a trailing space wraps over the first letter.
#ifdef BUGFIX
        "Du hast einen {Var1}\r\n"
#else
        "Du hast einen {Var1} \r\n"
#endif
        "gefangen.\r\n"
        "Er ist {Var2}cm lang.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInMeters[] =
// A 14-character fish name fills all 28 columns; a trailing space wraps over the first letter.
#ifdef BUGFIX
        "Du hast einen {Var1}\r\n"
#else
        "Du hast einen {Var1} \r\n"
#endif
        "gefangen.\r\n"
        "Er ist {Var2}m lang.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtFishSizeInMetersAndCentimeters[] =
// A 14-character fish name fills all 28 columns; a trailing space wraps over the first letter.
#ifdef BUGFIX
        "Du hast einen {Var1}\r\n"
#else
        "Du hast einen {Var1} \r\n"
#endif
        "gefangen.\r\n"
        "Er {Var2}m{Var3}cm lang.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtKingFish[] =
        "Ein Flusskönig!{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtMaximumSizeFish[] =
        "Das ist die maximale Größe\r\n"
        "für einen {Var1}.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught10000FishMilestone[] =
        "Herzlichen Glückwunsch!{Press}\p"
        "Du hast jetzt 10.000\r\n"
        "Fische gefangen!{Press}\p"
        "Das ist alles. Du \r\n"
        "bekommst keinen Preis\r\n"
        "oder so etwas. Tschüss.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught100000FishMilestone[] =
        "Herzlichen Glückwunsch!{Press}\p"
        "Du hast jetzt 100.000\r\n"
        "Fische gefangen!{Press}\p"
        "Das ist alles. Du \r\n"
        "bekommst keinen Preis\r\n"
        "oder so etwas. Tschüss.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught1000000FishMilestone[] =
        "Herzlichen Glückwunsch!{Press}\p"
        "Du hast jetzt 1.000.000\r\n"
        "Fische gefangen!{Press}\p"
        "Das ist alles. Du \r\n"
        "bekommst keinen Preis\r\n"
        "oder so etwas. Tschüss.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_Shared_CaughtTenOrHundredMillionFishMilestone[] =
        "Herzlichen Glückwunsch!{Press}\p"
        "Du hast jetzt 10.000.000\r\n"
        "Fische gefangen!{Press}\p"
        "Das ist alles. Du \r\n"
        "bekommst keinen Preis\r\n"
        "oder so etwas. Tschüss.{Press}";

#ifdef BUGFIX
    // This separate milestone is 100 million, not the preceding 10 million.
    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught100000000FishMilestone[] =
        "Herzlichen Glückwunsch!{Press}\p"
        "Du hast jetzt 100.000.000\r\n"
        "Fische gefangen!{Press}\p"
        "Das ist alles. Du \r\n"
        "bekommst keinen Preis\r\n"
        "oder so etwas. Tschüss.{Press}";
#endif

    const char gText_AchievementEvent_Fishing_MilestoneReward_Caught1000000000FishMilestone[] =
        "Herzlichen Glückwunsch!{Press}\p"
        "Du hast jetzt 1.000.000.000\r\n"
        "Fische gefangen!{Press}\p"
        "Das ist alles. Du \r\n"
        "bekommst keinen Preis\r\n"
        "oder so etwas. Tschüss.{Press}";

    const char gText_AchievementEvent_Fishing_MilestoneReward_CaughtEveryFishSpeciesMilestone[] =
        "Herzlichen Glückwunsch!{Press}\p"
        "Du hast jetzt ...\r\n"
        "jede Sorte gefangen!{Press}\p"
        "Das ist alles. Du \r\n"
        "bekommst keinen Preis\r\n"
        "oder so etwas. Tschüss.{Press}";
};
