#include "calendar_text.hh"

#include "unknown_types.hh"

// The section boundaries preserve the original two-byte alignment gaps without
// embedding padding bytes in the authored text.
char const gText_Calendar_SeasonNames[4][3] SECTION(".rodata.calendar.season") ALIGN(1) = {
    "春",
    "夏",
    "秋",
    "冬"
};

// This is the separate fixed-width season-name copy expanded by the calendar
// dynamic-field handler, followed by the native calendar date storage.  Its
// final NUL is the first logical season byte; every following pair stores a
// day and the next logical season byte.
CalendarDynamicSeasonData const gText_Calendar_DynamicSeasonNames
    CALENDAR_DYNAMIC_SEASON_TEXT ALIGN(1) = {
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

char const gText_Calendar_None[] SECTION(".rodata.calendar.none") =
    "無";

char const gText_Calendar_WeekdayNames[7][3] SECTION(".rodata.calendar.weekday") ALIGN(1) = {
    "日",
    "月",
    "火",
    "水",
    "木",
    "金",
    "土"
};

char const gText_Calendar_Festival_NewYearFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "春の月　　１日\r\n"
    "ローズ広場で『もちつき大会』\r\n"
    "午後６時～深夜０時まで{Press}";

char const gText_Calendar_Festival_SpringThanksgiving[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "春の月　１４日\r\n"
    "『春の感謝祭』{Press}";

char const gText_Calendar_Festival_SpringHorseRace[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "春の月　１８日\r\n"
    "ローズ広場で『春の草競馬』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_CookingFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "春の月　２２日\r\n"
    "ローズ広場で『料理祭』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_BeachDay[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "夏の月　　１日\r\n"
    "ミネラルビーチで『海開き』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_ChickenFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "夏の月　　７日\r\n"
    "ローズ広場で『鶏祭り』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_CowFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "夏の月　２０日\r\n"
    "ローズ広場で『牛祭り』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_FireworksFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "夏の月　２４日\r\n"
    "ミネラルビーチで『花火大会』\r\n"
    "（午後６時～午後９時まで）{Press}";

char const gText_Calendar_Festival_MusicFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "秋の月　　３日\r\n"
    "教会で『音楽祭』\r\n"
    "（午後６時～深夜０時まで）{Press}";

char const gText_Calendar_Festival_HarvestFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "秋の月　　９日\r\n"
    "ローズ広場で『収穫祭』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_FullMoonFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "秋の月　１３日\r\n"
    "マザーズヒル山頂で『お月見』\r\n"
    "（午後６時～深夜０時まで）{Press}";

char const gText_Calendar_Festival_FallHorseRace[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "秋の月　１８日\r\n"
    "ローズ広場で『秋の草競馬』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_SheepFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "秋の月　２１日\r\n"
    "ローズ広場で『羊祭り』\r\n"
    "（午前１０時～午後６時まで）{Press}";

char const gText_Calendar_Festival_PumpkinFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "秋の月　３０日\r\n"
    "『かぼちゃ祭り』{Press}";

char const gText_Calendar_Festival_WinterThanksgiving[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "冬の月　１４日\r\n"
    "『冬の感謝祭』{Press}";

char const gText_Calendar_Festival_StarryNightFestival[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "冬の月　２４日\r\n"
    "『星夜祭』{Press}";

char const gText_Calendar_Festival_YearEndGathering[] CALENDAR_FESTIVAL_TEXT =
    "\p"
    "冬の月　３０日\r\n"
    "『年越しの集い』\r\n"
    "『年越しそば』{Press}";

char const gText_Calendar_Festival_Marriage[] CALENDAR_FESTIVAL_DYNAMIC_TEXT =
    "\p"
    "\xF0の月　\xF1日\r\n"
    "『\xF2との結婚式』{Press}";

char const gText_Calendar_Festival_WeddingAnniversary[] CALENDAR_FESTIVAL_DYNAMIC_TEXT =
    "\p"
    "\xF0の月　\xF1日\r\n"
    "『結婚記念日』{Press}";

char const gText_Calendar_Festival_NoPlans[] CALENDAR_NO_PLANS_TEXT =
    "\p"
    "この日は特に何もない…{Press}";
