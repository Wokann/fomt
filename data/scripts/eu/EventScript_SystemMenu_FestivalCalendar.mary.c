#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_FestivalCalendar_GoldenLumberWarning[] =
        "Hey, {Player}!\r\n"
        "Don't use Golden Lumber\r\n"
        "at your farm!{Press}";

    const char gText_SystemMenu_FestivalCalendar_NewYearFestivalListing[] =
        "☆New Year Festival\r\n"
        "1st day of Spring, 6PM\r\n"
        "At Rose Square{Press}\p"
        "Come one, come all!\r\n"
        "                    Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_SpringHorseRaceListing[] =
        "☆Spring Horse Races\r\n"
        "18th day of Spring, 10AM\r\n"
        "At Rose Square{Press}\p"
        "Come one, come all!\r\n"
        "                    Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_CookingFestivalListing[] =
        "☆Cooking Festival\r\n"
        "22nd day of Spring, 10AM\r\n"
        "At Rose Square{Press}\p"
        "Spice things up!\r\n"
        "                    Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_BeachDayListing[] =
        "Swimming Festival\r\n"
        "1st day of Summer, 10AM\r\n"
        "At Mineral Beach{Press}\p"
        "Bring Dogs to Frisbee\r\n"
        "Tournament!          Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_ChickenFestivalListing[] =
        "☆Chicken Festival\r\n"
        "7th day of Summer, 10AM\r\n"
        "At Rose Square{Press}\p"
        "Bring your strongest\r\n"
        "Chicken!           Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_CowFestivalListing[] =
        "☆Cow Festival\r\n"
        "20th day of Summer, 10AM\r\n"
        "At Rose Square{Press}\p"
        "Bring your best Cow!\r\n"
        "                    Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_FireworksFestivalListing[] =
        "☆Fireworks Festival\r\n"
        "24th day of Summer, 6PM\r\n"
        "Mineral Beach{Press}\p"
        "Come celebrate the end of\r\n"
        "Summer!              Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_MusicFestivalListing[] =
        "☆Music Festival\r\n"
        "3rd day of Fall, 6PM\r\n"
        "At the Church{Press}\p"
        "Come celebrate the Fall\r\n"
        "Equinox!             Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_HarvestFestivalListing[] =
        "☆Harvest Festival\r\n"
        "9th day of Fall, 10AM\r\n"
        "At Rose Square{Press}\p"
        "Come to partake together!\r\n"
        "                     Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_FallHorseRaceListing[] =
        "☆Fall Horse Races\r\n"
        "18th day of Fall, 10AM\r\n"
        "At Rose Square{Press}\p"
        "Come one, come all!\r\n"
        "                    Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_SheepFestivalListing[] =
        "☆Sheep Festival\r\n"
        "21st day of Fall, 10AM\r\n"
        "At Yodel Farm{Press}\p"
        "Bring Dyed in the Wool\r\n"
        "Sheep!               Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_YearEndEventsFallPreview[] =
        "☆Year End Festival and\r\n"
        "Year End Noodles{Press}\p"
        "Come celebrate the end of\r\n"
        "the old year and the \r\n"
        "beginning of the new!{Press}\p"
        "☆Year End Festival\r\n"
        "30th day of Winter,\r\n"
        "Midnight, at Mother's Hill\r\n"
        "Peak.{Press}\p"
        "☆Year End Noodles\r\n"
        "30th day of Winter, 6PM\r\n"
        "At Rose Square{Press}\p"
        "Everyone come celebrate!\r\n"
        "                     Mayor\r\n"
        "{Press}";

    const char gText_SystemMenu_FestivalCalendar_YearEndAndNewYearEventsLateWinter[] =
        "☆Year End Festival,\r\n"
        "Year End Noodles, and \r\n"
        "New Year Festival{Press}\p"
        "Come celebrate the end of\r\n"
        "the old year and the \r\n"
        "beginning of the new!{Press}\p"
        "☆Year End Festival\r\n"
        "30th day of Winter,\r\n"
        "Midnight, at Mother's Hill\r\n"
        "Peak.{Press}\p"
        "☆Year End Noodles\r\n"
        "30th day of Winter, 6PM\r\n"
        "At Rose Square{Press}\p"
        "☆New Year Festival\r\n"
        "1st day of Spring, 6PM\r\n"
        "At Rose Square{Press}\p"
        "Everyone come celebrate!\r\n"
        "                     Mayor\r\n"
        "{Press}";
};

void EventScript_SystemMenu_FestivalCalendar(void)
{
    TalkOpen();
    if (HasGoldenLumberOnFarm())
    {
        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_GoldenLumberWarning);
    }
    else
    {
        switch (VarGet(VAR_SEASON))
        {
            case SEASON_SPRING:
                switch (VarGet(VAR_DAY))
                {
                    case DAY_OF_MONTH_01:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_NewYearFestivalListing);
                        break;
                    case DAY_OF_MONTH_02:
                    case DAY_OF_MONTH_03:
                    case DAY_OF_MONTH_04:
                    case DAY_OF_MONTH_05:
                    case DAY_OF_MONTH_06:
                    case DAY_OF_MONTH_07:
                    case DAY_OF_MONTH_08:
                    case DAY_OF_MONTH_09:
                    case DAY_OF_MONTH_10:
                    case DAY_OF_MONTH_11:
                    case DAY_OF_MONTH_12:
                    case DAY_OF_MONTH_13:
                    case DAY_OF_MONTH_14:
                    case DAY_OF_MONTH_15:
                    case DAY_OF_MONTH_16:
                    case DAY_OF_MONTH_17:
                    case DAY_OF_MONTH_18:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_SpringHorseRaceListing);
                        break;
                    case DAY_OF_MONTH_19:
                    case DAY_OF_MONTH_20:
                    case DAY_OF_MONTH_21:
                    case DAY_OF_MONTH_22:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_CookingFestivalListing);
                        break;
                    case DAY_OF_MONTH_23:
                    case DAY_OF_MONTH_24:
                    case DAY_OF_MONTH_25:
                    case DAY_OF_MONTH_26:
                    case DAY_OF_MONTH_27:
                    case DAY_OF_MONTH_28:
                    case DAY_OF_MONTH_29:
                    case DAY_OF_MONTH_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_BeachDayListing);
                        break;
                }
                break;
            case SEASON_SUMMER:
                switch (VarGet(VAR_DAY))
                {
                    case DAY_OF_MONTH_01:
                    case DAY_OF_MONTH_02:
                    case DAY_OF_MONTH_03:
                    case DAY_OF_MONTH_04:
                    case DAY_OF_MONTH_05:
                    case DAY_OF_MONTH_06:
                    case DAY_OF_MONTH_07:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_ChickenFestivalListing);
                        break;
                    case DAY_OF_MONTH_08:
                    case DAY_OF_MONTH_09:
                    case DAY_OF_MONTH_10:
                    case DAY_OF_MONTH_11:
                    case DAY_OF_MONTH_12:
                    case DAY_OF_MONTH_13:
                    case DAY_OF_MONTH_14:
                    case DAY_OF_MONTH_15:
                    case DAY_OF_MONTH_16:
                    case DAY_OF_MONTH_17:
                    case DAY_OF_MONTH_18:
                    case DAY_OF_MONTH_19:
                    case DAY_OF_MONTH_20:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_CowFestivalListing);
                        break;
                    case DAY_OF_MONTH_21:
                    case DAY_OF_MONTH_22:
                    case DAY_OF_MONTH_23:
                    case DAY_OF_MONTH_24:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_FireworksFestivalListing);
                        break;
                    case DAY_OF_MONTH_25:
                    case DAY_OF_MONTH_26:
                    case DAY_OF_MONTH_27:
                    case DAY_OF_MONTH_28:
                    case DAY_OF_MONTH_29:
                    case DAY_OF_MONTH_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_MusicFestivalListing);
                        break;
                }
                break;
            case SEASON_FALL:
                switch (VarGet(VAR_DAY))
                {
                    case DAY_OF_MONTH_01:
                    case DAY_OF_MONTH_02:
                    case DAY_OF_MONTH_03:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_MusicFestivalListing);
                        break;
                    case DAY_OF_MONTH_04:
                    case DAY_OF_MONTH_05:
                    case DAY_OF_MONTH_06:
                    case DAY_OF_MONTH_07:
                    case DAY_OF_MONTH_08:
                    case DAY_OF_MONTH_09:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_HarvestFestivalListing);
                        break;
                    case DAY_OF_MONTH_10:
                    case DAY_OF_MONTH_11:
                    case DAY_OF_MONTH_12:
                    case DAY_OF_MONTH_13:
                    case DAY_OF_MONTH_14:
                    case DAY_OF_MONTH_15:
                    case DAY_OF_MONTH_16:
                    case DAY_OF_MONTH_17:
                    case DAY_OF_MONTH_18:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_FallHorseRaceListing);
                        break;
                    case DAY_OF_MONTH_19:
                    case DAY_OF_MONTH_20:
                    case DAY_OF_MONTH_21:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_SheepFestivalListing);
                        break;
                    case DAY_OF_MONTH_22:
                    case DAY_OF_MONTH_23:
                    case DAY_OF_MONTH_24:
                    case DAY_OF_MONTH_25:
                    case DAY_OF_MONTH_26:
                    case DAY_OF_MONTH_27:
                    case DAY_OF_MONTH_28:
                    case DAY_OF_MONTH_29:
                    case DAY_OF_MONTH_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_YearEndEventsFallPreview);
                        break;
                }
                break;
            case SEASON_WINTER:
                mary_switch_compact (VarGet(VAR_DAY))
                {
                    case DAY_OF_MONTH_01:
                    case DAY_OF_MONTH_02:
                    case DAY_OF_MONTH_03:
                    case DAY_OF_MONTH_04:
                    case DAY_OF_MONTH_05:
                    case DAY_OF_MONTH_06:
                    case DAY_OF_MONTH_07:
                    case DAY_OF_MONTH_08:
                    case DAY_OF_MONTH_09:
                    case DAY_OF_MONTH_10:
                    case DAY_OF_MONTH_11:
                    case DAY_OF_MONTH_12:
                    case DAY_OF_MONTH_13:
                    case DAY_OF_MONTH_14:
                    case DAY_OF_MONTH_15:
                    case DAY_OF_MONTH_16:
                    case DAY_OF_MONTH_17:
                    case DAY_OF_MONTH_18:
                    case DAY_OF_MONTH_19:
                    case DAY_OF_MONTH_20:
                    case DAY_OF_MONTH_21:
                    case DAY_OF_MONTH_22:
                    case DAY_OF_MONTH_23:
                    case DAY_OF_MONTH_24:
                    case DAY_OF_MONTH_25:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_YearEndEventsFallPreview);
                        break;
                    case DAY_OF_MONTH_26:
                    case DAY_OF_MONTH_27:
                    case DAY_OF_MONTH_28:
                    case DAY_OF_MONTH_29:
                    case DAY_OF_MONTH_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_YearEndAndNewYearEventsLateWinter);
                        break;
                }
                break;
        }
    }
    TalkClose();
}
