#include "frisbee_text.hh"

// Static Frisbee UI text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_Frisbee_ExplanationQuestion[] =
    "Do you want an explanation?";

char const gText_Frisbee_Yes[] ALIGN(4) =
    "Yes";

char const gText_Frisbee_No[] ALIGN(4) =
    "No";

char const gText_Frisbee_ExplanationCursorTiming[] ALIGN(4) =
    "\p"
    "The cursor on the gauge\r\n"
    "to the left will start to \r\n"
    "move when the game starts.{Press}\r\n"
    "Press the A Button to stop\r\n"
    "the cursor with the \r\n"
    "correct timing.{Press}";

char const gText_Frisbee_ExplanationGreenZone[] ALIGN(4) =
    "\p"
    "The green zone shows how\r\n"
    "far your dog can catch \r\n"
    "the frisbee.{Press}";

char const gText_Frisbee_ExplanationRedZone[] ALIGN(4) =
    "\p"
    "The red zone shows where\r\n"
    "the frisbee can't be \r\n"
    "caught.{Press}\r\n"
    "Be sure to catch the \r\n"
    "frisbee inside the green\r\n"
    "zone.{Press}";

char const gText_Frisbee_ExplanationPractice[] ALIGN(4) =
    "\p"
    "The more you practice,\r\n"
    "the greater your dog's \r\n"
    "range becomes{Press}\r\n"
    "However, if you practice\r\n"
    "too much at once, your\r\n"
    "dog will get bored.{Press}\r\n"
    "If this happens he won't\r\n"
    "play any more. The higher\r\n"
    "your dog's affection is{Press}\r\n"
    "toward you, the more he\r\n"
    "will practice.{Press}";

char const gText_Frisbee_ExplanationTournament[] ALIGN(4) =
    "\p"
    "In the Frisbee Tournament,\r\n"
    "you get two tries. The\r\n"
    "better throw is used.{Press}";

char const gText_Frisbee_ExplainAgain[] ALIGN(4) =
    "Explain again?";

char const gText_Frisbee_ThrowAgain[] ALIGN(4) =
    "\p"
    "Now throw again.{Press}";

char const gText_Frisbee_TournamentFinished[] ALIGN(4) =
    "\p"
    "The Tournament is over.{Press}";

char const gText_Frisbee_PlayAgain[] ALIGN(4) =
    "Play again?";

char const gText_Frisbee_DogNoLongerWantsToPlay[] ALIGN(4) =
    "\p"
    "Your dog doesn't seem to\r\n"
    "want to play anymore.{Press}";

char const gText_Frisbee_FoundItem[] ALIGN(4) =
    "\p"
    "You found a\r\n"
    "{Player}{Press}";

char const gText_Frisbee_FoundNothing[] ALIGN(4) =
    "\p"
    "You didn't find anything.{Press}";

char const gCppRuntimeBadAlloc_FrisbeeTextTrailer[] ALIGN(4) =
    "bad_alloc";
