#pragma implementation "horse_race_medal_exchange.hh"
#pragma implementation "horse_race.hh"
#include "horse_race.hh"
#include "decimal_text.hh"

UiTextSubstitution HorseRaceTextVariables::Lookup(u32 code)
{
    u32 name_id;
    switch (code) {
    case 0xFA:
        char text[8];
#if defined(REGION_JP)
        FormatFullWidthDecimal(round_number, text, 0);
#else
        FormatSignedDecimal(round_number, text, 0);
#endif
        return UiTextSubstitution(true, FixedStr<31>(text));

    case 0xFC:
        name_id = contestant_name_ids[0];
        goto contestant_name;
    case 0xFD:
        name_id = contestant_name_ids[1];
        goto contestant_name;
    case 0xFE:
        name_id = contestant_name_ids[2];
        goto contestant_name;
    case 0xFF:
        name_id = contestant_name_ids[3];
    contestant_name:
        if (name_id != 0x80)
            return UiTextSubstitution(true, FixedStr<31>(gText_AnimalFestival_LivestockContestantNames[name_id]));
        // A slot containing the player's horse uses the same name as token 0xFB.
    case 0xFB:
        break;

    default:
        return UiTextSubstitution(false, FixedStr<31>());
    }
    return UiTextSubstitution(true, FixedStr<31>(player_horse_name));
}
