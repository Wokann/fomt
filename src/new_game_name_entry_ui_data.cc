#include "new_game_name_entry_ui_text.hh"

#if defined(REGION_JP)
// The native name-entry path reads the first thirteen glyph codes.  The
// declared capacity preserves its seven trailing zero slots as part of this
// fixed table, rather than treating them as an unrelated padding array.
u16 const gNewGameNameEntryUiCharacterCodes[20] =
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９．ｍ位");

#else
// The native name-entry path reads the first thirteen glyph codes.  The
// declared capacity preserves its eight trailing zero slots as part of this
// fixed table, rather than treating them as an unrelated padding array.
u16 const gNewGameNameEntryUiCharacterCodes[21] =
    FOMT_GLYPH_SEQUENCE("0123456789.m#");
#endif
