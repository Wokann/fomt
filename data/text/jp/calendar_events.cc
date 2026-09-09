#include "calendar_text.hh"

#include "unknown_types.hh"

// This is the separate fixed-width season-name copy expanded by the calendar
// dynamic-field handler, followed by the native calendar date storage.  Its
// final NUL is the first logical season byte; every following pair stores a
// day and the next logical season byte.

CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames
    ALIGN(1) = {
    {
        "春",
        "夏",
        "秋",
        "冬",
    },
    {
        {  1, SEASON_SPRING },
        { 14, SEASON_SPRING },
        { 18, SEASON_SPRING },
        { 22, SEASON_SUMMER },
        {  1, SEASON_SUMMER },
        {  7, SEASON_SUMMER },
        { 20, SEASON_SUMMER },
        { 24, SEASON_AUTUMN },
        {  3, SEASON_AUTUMN },
        {  9, SEASON_AUTUMN },
        { 13, SEASON_AUTUMN },
        { 18, SEASON_AUTUMN },
        { 21, SEASON_AUTUMN },
        { 30, SEASON_WINTER },
        { 14, SEASON_WINTER },
        { 24, SEASON_WINTER },
        { 30, SEASON_SPRING },
    },
};

char const gText_Calendar_Festival_NewYearFestival[] =
    "\p"
    "春の月　　１日\r\n"
    "ローズ広場で『もちつき大会』\r\n"
    "午後６時～深夜０時まで{Press}";

char const gText_Calendar_Festival_SpringThanksgiving[] ALIGN(4) =
    "\p"
    "春の月　１４日\r\n"
    "『春の感謝祭』{Press}";

char const gText_Calendar_Festival_SpringHorseRace[] ALIGN(4) =
    "\p"
    "春の月　１８日\r\n"
    "ローズ広場で『春の草競馬』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_CookingFestival[] ALIGN(4) =
    "\p"
    "春の月　２２日\r\n"
    "ローズ広場で『料理祭』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_BeachDay[] ALIGN(4) =
    "\p"
    "夏の月　　１日\r\n"
    "ミネラルビーチで『海開き』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_ChickenFestival[] ALIGN(4) =
    "\p"
    "夏の月　　７日\r\n"
    "ローズ広場で『鶏祭り』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_CowFestival[] ALIGN(4) =
    "\p"
    "夏の月　２０日\r\n"
    "ローズ広場で『牛祭り』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_FireworksFestival[] ALIGN(4) =
    "\p"
    "夏の月　２４日\r\n"
    "ミネラルビーチで『花火大会』\r\n"
    "（午後６時～午後９時まで）{Press}";

char const gText_Calendar_Festival_MusicFestival[] ALIGN(4) =
    "\p"
    "秋の月　　３日\r\n"
    "教会で『音楽祭』\r\n"
    "（午後６時～深夜０時まで）{Press}";

char const gText_Calendar_Festival_HarvestFestival[] ALIGN(4) =
    "\p"
    "秋の月　　９日\r\n"
    "ローズ広場で『収穫祭』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_FullMoonFestival[] ALIGN(4) =
    "\p"
    "秋の月　１３日\r\n"
    "マザーズヒル山頂で『お月見』\r\n"
    "（午後６時～深夜０時まで）{Press}";

char const gText_Calendar_Festival_FallHorseRace[] ALIGN(4) =
    "\p"
    "秋の月　１８日\r\n"
    "ローズ広場で『秋の草競馬』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_SheepFestival[] ALIGN(4) =
    "\p"
    "秋の月　２１日\r\n"
    "ローズ広場で『羊祭り』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_PumpkinFestival[] ALIGN(4) =
    "\p"
    "秋の月　３０日\r\n"
    "『かぼちゃ祭り』{Press}";

char const gText_Calendar_Festival_WinterThanksgiving[] ALIGN(4) =
    "\p"
    "冬の月　１４日\r\n"
    "『冬の感謝祭』{Press}";

char const gText_Calendar_Festival_StarryNightFestival[] ALIGN(4) =
    "\p"
    "冬の月　２４日\r\n"
    "『星夜祭』{Press}";

char const gText_Calendar_Festival_YearEndGathering[] ALIGN(4) =
    "\p"
    "冬の月　３０日\r\n"
    "『年越しの集い』\r\n"
    "『年越しそば』{Press}";

char const gText_Calendar_Festival_Marriage[] =
    "\p"
    "\xF0の月　\xF1日\r\n"
    "『\xF2との結婚式』{Press}";

char const gText_Calendar_Festival_WeddingAnniversary[] ALIGN(4) =
    "\p"
    "\xF0の月　\xF1日\r\n"
    "『結婚記念日』{Press}";

char const gText_Calendar_Festival_NoPlans[] ALIGN(4) =
    "\p"
    "この日は特に何もない…{Press}";

char const gCppRuntimeBadAlloc_CalendarNoPlansFirst[] ALIGN(4) =
    "bad_alloc";

char const gText_Calendar_FallbackNone[] ALIGN(4) =
    "なし";

char const gCppRuntimeBadAlloc_CalendarNoPlansSecond[] ALIGN(4) =
    "bad_alloc";
