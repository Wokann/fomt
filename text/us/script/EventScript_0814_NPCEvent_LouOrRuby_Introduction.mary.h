mary_text_table
{
    const char gText_NPCEvent_LouOrRuby_Introduction_LouOrRubyIntroducesWeeklyFoodBuyingVisitAtInn[] =
        "Hi there. {Press}\p"
// Use Ruby here too, matching the linked GameCube character.
#ifdef BUGFIX
        "My name's Ruby. I come to \r\n"
#else
        "My name's Lou. I come to \r\n"
#endif
        "Mineral Town every week \r\n"
        "to buy food. {Press}\p"
        "The food from Mineral Town \r\n"
        "is so delicious, I've \r\n"
        "decided to use it at my {Press}\r\n"
        "own Inn! {Press}\p"
        "I'm at the Inn here every \r\n"
// The actual weekly visit is on Sunday, not Monday.
#ifdef BUGFIX
        "Sunday, so come by if you\r\n"
#else
        "Monday, so come by if you\r\n"
#endif
        "want to sell something! {Press}";
};
