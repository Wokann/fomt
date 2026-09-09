#include "library_text.hh"

#if defined(FOMT_LIBRARY_TEXT_OPENING_HOURS)

char const gText_Library_OpeningHours[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "Mary's Library\r\n"
    "Hours: 10AM-4PM\r\n"
    "Closed: Thursdays";

#elif defined(FOMT_LIBRARY_TEXT_MENU)

char const gText_Library_Menu[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "Books      \x00"
    "Letters    ";

char const gCppRuntimeBadAlloc_LibraryMenu[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "bad_alloc";

#endif
