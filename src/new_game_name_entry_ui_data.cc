#include "new_game_name_entry_ui_data.hh"

#include FOMT_TEXT_INCLUDE(new_game_name_entry_ui_data.cc)

// The renderer consumes the first thirteen glyph codes; the explicit array
// sizes preserve the remaining zero slots present in each regional ROM.
#if defined(REGION_JP)
u16 const gNewGameNameEntryUiCharacterCodes[20] = {
    "０１２３４５６７８９．ｍ位"
};
#else
u16 const gNewGameNameEntryUiCharacterCodes[21] = {
    "0123456789.m#"
};
#endif
