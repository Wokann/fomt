// fomt-text input, intentionally not a C++ translation unit.
// TITLE is fixed at the top of the screen; MAIN rows scroll below it.
TITLE
    "Vorstellung Wally"
MAIN
// JP describes a company marathon coach, not a race organizer.
#ifdef BUGFIX
    "Er ist Marathontrainer"
    "einer Firma in der Stadt."
    "Er lebt mit seiner Frau"
    "Chris und seinem Sohn Hugh."
    "Sie kamen ins"
#else
    "Er organisiert einen"
    "Marathonlauf in der Stadt,"
    "in der er mit seiner Frau "
    "Chris und seinem Sohn Hugh"
    "lebt. Sie kamen ins"
#endif
    "Vergissmeinnicht-Tal, "
    "weil es ein toller Ort"
    "zum Laufen ist."
// Restore the missing JP profile paragraphs and their existing level boundaries.
#ifdef BUGFIX
    "<041>"
    ""
    "Er war ein berühmter"
    "Marathonläufer. Ein"
    "Beinleiden zwang ihn zum"
    "Rücktritt. Danach wurde er"
    "Trainer. Er ist ein"
    "geborener Sportler."
    "<042>"
    ""
    "Er träumt davon, Hugh zum"
    "Spitzensportler zu machen,"
    "und joggt jeden Morgen"
    "mit ihm."
#endif
END_FOMT_REFERENCE_GUIDE_PAGE
