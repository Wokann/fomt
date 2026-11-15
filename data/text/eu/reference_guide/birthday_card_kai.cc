// fomt-text input, intentionally not a C++ translation unit.
// TITLE is fixed at the top of the screen; MAIN rows scroll below it.
TITLE
    "Happy Birthday from Kai"
MAIN
    ""
    "HAPPY BIRTHDAY,"
    "<p>."
    ""
// The signature contains a stray tab escape, not a guide control code.
#ifdef BUGFIX
    "                Kai"
#else
    "\\t                Kai"
#endif
END_FOMT_REFERENCE_GUIDE_PAGE
