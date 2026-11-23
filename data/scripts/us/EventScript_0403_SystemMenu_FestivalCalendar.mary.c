#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0403_SystemMenu_FestivalCalendar.mary.h"

void EventScript_0403_SystemMenu_FestivalCalendar(void)
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
                    case DAY_01:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_NewYearFestivalListing);
                        break;
                    case DAY_02:
                    case DAY_03:
                    case DAY_04:
                    case DAY_05:
                    case DAY_06:
                    case DAY_07:
                    case DAY_08:
                    case DAY_09:
                    case DAY_10:
                    case DAY_11:
                    case DAY_12:
                    case DAY_13:
                    case DAY_14:
                    case DAY_15:
                    case DAY_16:
                    case DAY_17:
                    case DAY_18:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_SpringHorseRaceListing);
                        break;
                    case DAY_19:
                    case DAY_20:
                    case DAY_21:
                    case DAY_22:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_CookingFestivalListing);
                        break;
                    case DAY_23:
                    case DAY_24:
                    case DAY_25:
                    case DAY_26:
                    case DAY_27:
                    case DAY_28:
                    case DAY_29:
                    case DAY_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_BeachDayListing);
                        break;
                }
                break;
            case SEASON_SUMMER:
                switch (VarGet(VAR_DAY))
                {
                    case DAY_01:
                    case DAY_02:
                    case DAY_03:
                    case DAY_04:
                    case DAY_05:
                    case DAY_06:
                    case DAY_07:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_ChickenFestivalListing);
                        break;
                    case DAY_08:
                    case DAY_09:
                    case DAY_10:
                    case DAY_11:
                    case DAY_12:
                    case DAY_13:
                    case DAY_14:
                    case DAY_15:
                    case DAY_16:
                    case DAY_17:
                    case DAY_18:
                    case DAY_19:
                    case DAY_20:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_CowFestivalListing);
                        break;
                    case DAY_21:
                    case DAY_22:
                    case DAY_23:
                    case DAY_24:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_FireworksFestivalListing);
                        break;
                    case DAY_25:
                    case DAY_26:
                    case DAY_27:
                    case DAY_28:
                    case DAY_29:
                    case DAY_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_MusicFestivalListing);
                        break;
                }
                break;
            case SEASON_FALL:
                switch (VarGet(VAR_DAY))
                {
                    case DAY_01:
                    case DAY_02:
                    case DAY_03:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_MusicFestivalListing);
                        break;
                    case DAY_04:
                    case DAY_05:
                    case DAY_06:
                    case DAY_07:
                    case DAY_08:
                    case DAY_09:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_HarvestFestivalListing);
                        break;
                    case DAY_10:
                    case DAY_11:
                    case DAY_12:
                    case DAY_13:
                    case DAY_14:
                    case DAY_15:
                    case DAY_16:
                    case DAY_17:
                    case DAY_18:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_FallHorseRaceListing);
                        break;
                    case DAY_19:
                    case DAY_20:
                    case DAY_21:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_SheepFestivalListing);
                        break;
                    case DAY_22:
                    case DAY_23:
                    case DAY_24:
                    case DAY_25:
                    case DAY_26:
                    case DAY_27:
                    case DAY_28:
                    case DAY_29:
                    case DAY_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_YearEndEventsFallOrWinterPreview);
                        break;
                }
                break;
            case SEASON_WINTER:
                mary_switch_compact (VarGet(VAR_DAY))
                {
                    case DAY_01:
                    case DAY_02:
                    case DAY_03:
                    case DAY_04:
                    case DAY_05:
                    case DAY_06:
                    case DAY_07:
                    case DAY_08:
                    case DAY_09:
                    case DAY_10:
                    case DAY_11:
                    case DAY_12:
                    case DAY_13:
                    case DAY_14:
                    case DAY_15:
                    case DAY_16:
                    case DAY_17:
                    case DAY_18:
                    case DAY_19:
                    case DAY_20:
                    case DAY_21:
                    case DAY_22:
                    case DAY_23:
                    case DAY_24:
                    case DAY_25:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_YearEndEventsFallOrWinterPreview);
                        break;
                    case DAY_26:
                    case DAY_27:
                    case DAY_28:
                    case DAY_29:
                    case DAY_30:
                        TalkAppendMessage(gText_SystemMenu_FestivalCalendar_YearEndAndNewYearEventsLateWinter);
                        break;
                }
                break;
        }
    }
    TalkClose();
}
