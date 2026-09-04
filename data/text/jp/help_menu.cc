#include "help_menu_text.hh"

// The original constructor receives these as four separate pointers.
char const gText_HelpMenu_Crops[] SECTION(".rodata.help_menu") =
    "作物の育て方";

char const gText_HelpMenu_Animals[] SECTION(".rodata.help_menu") =
    "動物の育て方";

char const gText_HelpMenu_UsefulTips[] SECTION(".rodata.help_menu") =
    "便利な操作";

char const gText_HelpMenu_Exit[] SECTION(".rodata.help_menu") =
    "やめる";
