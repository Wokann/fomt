#include "main_menu_data.hh"

u32 const gMenuEntryIds[7] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
};

#include FOMT_TEXT_INCLUDE(main_menu_data.cc)

char const * const gMenuEntryLabels[7] = {
    gText_Menu_Diary,
    gText_Menu_Rucksack,
    gText_Menu_WorldMap,
    gText_Menu_FarmMap,
    gText_Menu_Earnings,
    gText_Menu_Memo,
    gText_Menu_Tutorial,
};

// This implementation allocates the menu's actual sprite owners.
#include <new>

MainMenuData::MainMenuData()
    : archive(gMainMenuSpriteResourceArchive),
      cursor(new MainMenuSpriteResource(&archive, 7, 256))
{
    for (u32 i = 0; i < 7; ++i)
        icons[i] = new MainMenuSpriteResource(&archive, gMenuEntryIds[i], 256);
}

MainMenuData::~MainMenuData()
{
}
