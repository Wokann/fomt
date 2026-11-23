mary_text_table
{
    const char gText_NPCEvent_LouOrRuby_Introduction_LouOrRubyIntroducesWeeklyFoodBuyingVisitAtInn[] =
        "Hi. {Press}\p"
// Use Ruby; omit the trailing space to keep the line within 28 columns.
#ifdef BUGFIX
        "Ich bin Ruby. Ich komme jede\r\n"
#else
        "Ich bin Lou. Ich komme jede \r\n"
#endif
        "Woche nach Mineralstadt, um \r\n"
        "Essen zu kaufen. {Press}\p"
        "Das Essen aus Mineral- \r\n"
        "stadt ist so k[o]stlich, \r\n"
        "dass ich es in meinem {Press}\r\n"
        "eigenen Gasthof verwende! {Press}\p"
// The actual weekly visit is on Sunday, not Monday.
#ifdef BUGFIX
        "Ich bin jeden Sonntag \r\n"
#else
        "Ich bin jeden Montag \r\n"
#endif
        "im Gasthof. Komm, wenn du\r\n"
        "etwas verkaufen willst! {Press}";
};
