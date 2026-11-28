#include "npc_schedule_child.hh"
#include "game_state.hh"

extern "C" u32 SelectChildSchedule(void const * context)
{
    GameStateSaveImage const & save = *static_cast<GameStateSaveImage const *>(context);
    NpcCollection const & characters = save.npcs;
    Child const * child = characters.GetChild();
    if (child != nullptr) {
        if (child->GetAgeDays() <= 59) {
            u32 spouse = characters.GetSpouseCharacterId();
            if (spouse == CHARACTER_HARVEST_GODDESS)
                return 3;

            GameDayDate date;
            DecodeGameDayDate(&date, &save.clock.calendar);
            u8 season = date.season;
            u8 day = date.day;
            u8 weekday = date.weekday;
            if (season == SEASON_FALL && day == DAY_13)
                return 5;
            if (static_cast<u8>(IsNpcScheduleDateListed(season, day))
                || save.clock.weather_today == WEATHER_TYPHOON
                || save.clock.weather_today == WEATHER_SNOWSTORM)
                return 2;

            u8 family_state = save.npcs.unk_474;
            switch (spouse) {
            case CHARACTER_MARY:
                if (weekday == DAY_OF_WEEK_MONDAY)
                    return 2;
                break;
            case CHARACTER_POPURI:
                if (family_state == 0 || weekday == DAY_OF_WEEK_SUNDAY)
                    return 2;
                break;
            case CHARACTER_KAREN:
                if (family_state == 0 || weekday == DAY_OF_WEEK_TUESDAY
                    || weekday == DAY_OF_WEEK_SUNDAY)
                    return 2;
                break;
            case CHARACTER_ELLI:
                if (weekday == DAY_OF_WEEK_WEDNESDAY)
                    return 2;
                break;
            case CHARACTER_ANN:
                if (family_state == 0)
                    return 2;
                break;
            case CHARACTER_HARVEST_GODDESS:
                break;
            }
            return 1;
        }
        return 4;
    }
    return 0;
}

// Recovered schedule data at US ROM 0x080F29C0 (JP 0x080F221C).
// The two regional payloads differ only in relocated function/data pointers.

extern "C" ChildScheduleData const gChildScheduleData = {
    // descriptor
    { SelectChildSchedule, ARRAY_COUNT(gChildScheduleData.table_choices), gChildScheduleData.table_choices },
    // table_choices
    {
        nullptr, &gChildScheduleData.table_storage[0], &gChildScheduleData.table_storage[1], &gChildScheduleData.table_storage[2],
        &gChildScheduleData.table_storage[3], &gChildScheduleData.table_storage[4],
    },
    // table_storage
    {
        { ARRAY_COUNT(gChildScheduleData.entries_0), gChildScheduleData.entries_0 },
        { ARRAY_COUNT(gChildScheduleData.entries_1), gChildScheduleData.entries_1 },
        { ARRAY_COUNT(gChildScheduleData.entries_2), gChildScheduleData.entries_2 },
        { ARRAY_COUNT(gChildScheduleData.entries_3), gChildScheduleData.entries_3 },
        { ARRAY_COUNT(gChildScheduleData.entries_4), gChildScheduleData.entries_4 },
    },
    // entries_0
    {
        { 0, &gChildScheduleData.payload_storage[0] },
        { 180, &gChildScheduleData.payload_storage[1] },
        { 720, &gChildScheduleData.payload_storage[0] },
        { 840, &gChildScheduleData.payload_storage[1] },
    },
    // entries_1
    {
        { 0, &gChildScheduleData.payload_storage[0] },
        { 300, &gChildScheduleData.payload_storage[1] },
        { 720, &gChildScheduleData.payload_storage[0] },
        { 840, &gChildScheduleData.payload_storage[1] },
    },
    // entries_2
    {
        { 0, &gChildScheduleData.payload_storage[1] },
    },
    // entries_3
    {
        { 0, &gChildScheduleData.payload_storage[2] },
        { 300, &gChildScheduleData.payload_storage[3] },
        { 720, &gChildScheduleData.payload_storage[1] },
    },
    // entries_4
    {
        { 0, &gChildScheduleData.payload_storage[0] },
        { 180, &gChildScheduleData.payload_storage[1] },
    },
    // payload_storage
    {
        { nullptr, 0, 0, 0, 564, 1, 0 },
        { nullptr, 0, 416, -48, 29, 0, 0 },
        { gChildScheduleData.points_2, ARRAY_COUNT(gChildScheduleData.points_2), 352, 128, 29, 0, 1 },
        { gChildScheduleData.points_3, ARRAY_COUNT(gChildScheduleData.points_3), 56, 128, 29, 0, 1 },
    },
    // points_2
    {
        { 408, 2, 120, 3, 0 },
        { 160, 2, 120, 0, 1 },
        { 352, 2, 120, 2, 0 },
        { 128, 2, 120, 1, 1 },
    },
    // points_3
    {
        { 160, 2, 120, 0, 1 },
        { 104, 2, 120, 3, 0 },
        { 128, 2, 120, 1, 1 },
        { 56, 2, 120, 2, 0 },
    },
};
