#include "new_game_help_text.hh"

char const gText_NewGameHelp_Controls[88] SECTION(".rodata.new_game_help_text") =
    "Controls        1       2\r\n"
    "Control Pad     Walk    Run\r\n"
    "R Button        Run     Walk";

char const gText_NewGameHelp_ClockDisplay[44] SECTION(".rodata.new_game_help_text") =
    "Show or hide the Clock \r\n"
    "in the Map Window";

char const gText_NewGameHelp_FaceDisplay[80] SECTION(".rodata.new_game_help_text") =
    "Show or hide the face of \r\n"
    "the person you're talking\r\n"
    "to in the Message Window\x05";

char const gText_NewGameHelp_NameDisplay[80] SECTION(".rodata.new_game_help_text") =
    "Show or hide the name of \r\n"
    "the person you're talking\r\n"
    "to in the Message Window\x05";
