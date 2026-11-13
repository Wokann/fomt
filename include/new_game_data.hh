#ifndef NEW_GAME_DATA_HH
#define NEW_GAME_DATA_HH

// The native keyboard stores three fixed-width pages. Each row has fifteen
// two-byte cells (JP glyphs or overseas character/spacing pairs) plus NUL.
// Rows and pages are two views of the same serialized character table.
#define NEW_GAME_NAME_ENTRY_PAGE_COUNT 3
#if defined(REGION_DE)
#define NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE 7
#else
#define NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE 6
#endif
#define NEW_GAME_NAME_ENTRY_ROW_COUNT (NEW_GAME_NAME_ENTRY_PAGE_COUNT * NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE)
#define NEW_GAME_NAME_ENTRY_ROW_WIDTH 31

#ifndef __ASSEMBLER__

#include "prelude.h"

// The renderer advances by one three-pointer row and draws its labels at
// X=16, 128 and 192. Keep the original regional text-pointer reuse.
struct NewGameMenuLabelRow
{
    char const * label;
    char const * left_choice;
    char const * right_choice;
};

typedef char NewGameMenuLabelRowSizeCheck[sizeof(NewGameMenuLabelRow) == 12 ? 1 : -1];
typedef char NewGameMenuLabelRowLeftCheck[offsetof(NewGameMenuLabelRow, left_choice) == 4 ? 1 : -1];
typedef char NewGameMenuLabelRowRightCheck[offsetof(NewGameMenuLabelRow, right_choice) == 8 ? 1 : -1];



// Rendering reads fixed-width, single-terminated rows; character insertion
// addresses the same contiguous storage by page, row and byte-column offsets.
union NewGameNameEntryCharacterTable {
    char rows[NEW_GAME_NAME_ENTRY_ROW_COUNT][NEW_GAME_NAME_ENTRY_ROW_WIDTH];
    char page_bytes[NEW_GAME_NAME_ENTRY_PAGE_COUNT][NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH];
    char bytes[NEW_GAME_NAME_ENTRY_ROW_COUNT * NEW_GAME_NAME_ENTRY_ROW_WIDTH];
} __attribute__((packed));

typedef char NewGameNameEntryCharacterTableSizeCheck[
    sizeof(NewGameNameEntryCharacterTable)
        == NEW_GAME_NAME_ENTRY_ROW_COUNT * NEW_GAME_NAME_ENTRY_ROW_WIDTH ? 1 : -1];


#endif // !__ASSEMBLER__

#endif // NEW_GAME_DATA_HH
