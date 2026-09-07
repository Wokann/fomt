#include "horse_race_text.hh"

char const * const gHorseRaceTicketControls[] SECTION(".rodata.horse_race_ticket_controls") = {
    gText_HorseRace_TicketControls_DPadUpDown,
    gText_HorseRace_TicketControls_SelectHorse,
    gText_HorseRace_TicketControls_DPadLeftRight,
    gText_HorseRace_TicketControls_ChangeQuantity,
    gText_HorseRace_TicketControls_LRButtons,
    gText_HorseRace_TicketControls_ChangeQuantityByTen,
    gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation,
    gText_HorseRace_TicketControls_MoveCursorToConfirm,
    gText_HorseRace_TicketControls_Buy,
    gText_HorseRace_TicketControls_Cancel,
    nullptr,
};

char const gCppRuntimeBadAlloc_HorseRaceTicketControls[]
    SECTION(".rodata.horse_race_ticket_controls_trailer") =
        "bad_alloc";
