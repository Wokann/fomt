// fomt-text input, intentionally not a C++ translation unit.
// TITLE is fixed at the top of the screen; MAIN rows scroll below it.
TITLE
    "Änderung des freien Tages"
MAIN
    ""
    "Unser freier Tag ist nun"
// After the wedding the library closes on Thursday, not Monday.
#ifdef BUGFIX
    "Donnerstag anstatt Montag."
#else
    "Montag anstatt Donnerstag."
#endif
    "Bitte zur Kenntnis nehmen."
    ""
    "       Marys Bibliothek"
END_FOMT_REFERENCE_GUIDE_PAGE
