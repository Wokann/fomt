#include "frisbee_text.hh"

#if defined(FOMT_FRISBEE_TEXT_SCOREBOARD)

char const gText_Frisbee_TournamentScoreboard[] =
    "Frisbeeturnier Punktetafel ";

#else

char const gText_Frisbee_ExplanationQuestion[] =
    "Möchtest du eine Erklärung?";

char const gText_Frisbee_Yes[] ALIGN(4) =
    "Ja";

char const gText_Frisbee_No[] ALIGN(4) =
    "Nein";

char const gText_Frisbee_ExplanationCursorTiming[] ALIGN(4) =
    "\p"
    "Der Cursor links auf der\r\n"
    "Anzeige beginnt sich zu \r\n"
    "bewegen,  wenn{Press}\r\n"
    "das Spiel beginnt.\r\n"
    "Drücke Knopf A, um den\r\n"
    "Cursor im richtigen{Press}\r\n"
    "Augenblick zu stoppen.{Press}";

char const gText_Frisbee_ExplanationGreenZone[] ALIGN(4) =
    "\p"
    "Die grüne Zone markiert\r\n"
    "den Raum, in dem dein Hund \r\n"
    "den Frisbee erwischen kann.{Press}";

char const gText_Frisbee_ExplanationRedZone[] ALIGN(4) =
    "\p"
    "Die rote Zone markiert\r\n"
    "den Raum, in dem der Frisbee\r\n"
    "nicht erwischt werden kann.{Press}\r\n"
    "Sieh zu, dass du den\r\n"
    "Frisbee innerhalb der\r\n"
    "grünen Zone erwischst.{Press}\r\n";

char const gText_Frisbee_ExplanationPractice[] ALIGN(4) =
    "\p"
    "Je mehr du übst,\r\n"
    "umso größer wird die\r\n"
    "Zone, in der dein Hund den{Press}\r\n"
    "Frisbee schnappen kann.\r\n"
    "Wenn du aber zu lange\r\n"
    "am Stück spielst, verliert{Press}\r\n"
    "dein Hund die Lust am Spiel.\r\n"
    "Wenn das passiert, wird\r\n"
    "er nicht mehr spielen.{Press}\r\n"
    "Je mehr dein Hund dich\r\n"
    "mag, desto mehr\r\n"
    "wird er üben.{Press}";

char const gText_Frisbee_ExplanationTournament[] ALIGN(4) =
    "\p"
    "Im Frisbee-Wettkampf\r\n"
    "kriegst du zwei Versuche. \r\n"
    "Der bessere Wurf zählt.{Press}";

char const gText_Frisbee_ExplainAgain[] ALIGN(4) =
    "Nochmal erklären?";

char const gText_Frisbee_ThrowAgain[] ALIGN(4) =
    "\p"
    "Jetzt wirf nochmal.{Press}";

char const gText_Frisbee_TournamentFinished[] ALIGN(4) =
    "\p"
    "Der Wettkampf ist vorbei.{Press}";

char const gText_Frisbee_PlayAgain[] ALIGN(4) =
    "Noch einmal spielen?";

char const gText_Frisbee_DogNoLongerWantsToPlay[] ALIGN(4) =
    "\p"
    "Dein Hund will anscheinend\r\n"
    "nicht mehr spielen.{Press}";

char const gText_Frisbee_FoundItem[] ALIGN(4) =
    "\p"
    "Du hast ein\r\n"
    "gefunden!\r\n"
    "{Player}{Press}";

char const gText_Frisbee_FoundNothing[] ALIGN(4) =
    "\p"
    "Du hast nichts gefunden.{Press}";

char const gCppRuntimeBadAlloc_FrisbeeTextTrailer[] ALIGN(4) =
    "bad_alloc";

#endif
