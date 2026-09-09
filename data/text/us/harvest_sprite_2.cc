#include "harvest_sprite.hh"

char const gCppRuntimeBadAlloc_HarvestSpriteMiniGameAnimalHusbandry[] =
    "bad_alloc";

// The native US exception path deliberately takes this final NUL byte's
// address rather than the adjacent "bad_alloc" string.
char const gText_HarvestSpriteMiniGameAnimalHusbandryEmpty[] =
    "";

// Direct-indexed chicken-festival contestant names. The fixed 13-byte rows
// retain the original US display-space padding.
char const gText_ChickenFestival_ContestantNames[CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT][CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH] ALIGN(1) = {
    "Saber",
    "Homer",
    "Beowolf",
    "Bones",
    "Sarge",
    "Hawkeye",
    "Shamus",
    "Bruno",
    "Sharpy",
    "Buzz",
    "Junior",
    "Byron",
    "King",
    "Caesar",
    "Kellog",
    "Skip",
    "Cash",
    "Lioin",
    "Lance",
    "Spike"
};


char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsAnnouncement[] =
    "\p"
    "Now for the semi-finals!{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement[] =
    "\p"
    "Now for the third round!\r\n"
    "This will decide the\r\n"
    "champion, so do your best! {Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion[] =
    "Do you need an explanation?";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo[] =
    "No, thanks.";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes[] =
    "Yes, please.";

char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart[] =
    "\p"
    "Round 1. Get ready...{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart[] =
    "\p"
    "Semi-finals. Get ready...{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart[] =
    "\p"
    "Finals. Get ready...{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_Start[] =
    "\p"
    "Go!{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_Stop[] =
    "\p"
    "Stop!{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix[] =
    " wins!{Press}";
