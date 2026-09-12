#include "library_text.hh"

#if defined(FOMT_LIBRARY_TEXT_OPENING_HOURS)

char const gText_Library_OpeningHours[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "Marys Bibliothek\r\n"
    "Öffnungszeiten: 10-16 Uhr\r\n"
    "Geschlossen: Donnerstags";

#elif defined(FOMT_LIBRARY_TEXT_MENU)

char const gText_Library_Menu[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "Bücher     \x00"
    "Briefe     ";

char const gCppRuntimeBadAlloc_LibraryMenu[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "bad_alloc";

#endif
