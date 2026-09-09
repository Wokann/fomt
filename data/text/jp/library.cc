#include "library_text.hh"

#if defined(FOMT_LIBRARY_TEXT_OPENING_HOURS)

char const gText_Library_OpeningHours[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "マリーの図書館\r\n"
    "時間…午前１０時～午後　４時\r\n"
    "休日…木曜日";

#elif defined(FOMT_LIBRARY_TEXT_MENU)

char const gText_Library_Menu[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "本一覧　\x00"
    "手紙一覧";

char const gCppRuntimeBadAlloc_LibraryMenu[] FOMT_LIBRARY_TEXT_ATTRIBUTE =
    "bad_alloc";

#endif
