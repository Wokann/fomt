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
    "Jetzt geht es \r\n"
    "ins Halbfinale!{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement[] =
    "\p"
    "Auf in die dritte Runde!\r\n"
    "Jetzt entscheidet sich, wer\r\n"
    "der Sieger sein wird,{Press}\r\n"
    "also gib dein Bestes! {Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion[] =
    "Brauchst du eine Erklärung?";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo[] =
    "Nein, danke.";

char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes[] =
    "Lass hören.";

char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart[] =
    "1.Runde. Auf die Plätze...{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart[] =
    "Halbfinale.\r\n"
    "Auf die Plätze...{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart[] =
    "Finale. Auf die Plätze...{Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_Start[] =
    "Los! {Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_Stop[] =
    "Stopp! {Press}";

char const gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix[] =
    " Gewinnt!{Press}";
