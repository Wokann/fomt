#ifndef HOME_STORAGE_TEXT_HH
#define HOME_STORAGE_TEXT_HH

#include "prelude.h"

// These sections intentionally follow the original physical text groups.
// Identical visible choices are kept separate when the ROM stores them at
// distinct addresses for different storage interfaces.
#define HOME_STORAGE_FRIDGE_TEXT SECTION(".rodata.home_storage_fridge")
#define HOME_STORAGE_CONFIRMATION_TEXT SECTION(".rodata.home_storage_confirmation")
#define HOME_STORAGE_TOOL_CHEST_CATEGORY_TEXT SECTION(".rodata.home_storage_tool_chest_category")
#define HOME_STORAGE_SHELF_TEXT SECTION(".rodata.home_storage_shelf")
#define HOME_STORAGE_TOOL_CHEST_HEADER_TEXT SECTION(".rodata.home_storage_tool_chest_header")

extern char const gText_Fridge_EmptyDescription[];
extern char const gText_Fridge_WrappedGiftWarning[];
extern char const gText_Fridge_Yes[];
extern char const gText_Fridge_No[];
extern char const gText_Fridge_Items[];
extern char const gText_Fridge_Title[];

extern char const gText_HomeStorage_ConfirmationYes[];
extern char const gText_HomeStorage_ConfirmationNo[];
extern char const gText_HomeStorage_EmptyDescription[];

extern char const gText_HomeStorage_CategoryTools[];
extern char const gText_HomeStorage_CategoryItems[];

extern char const gText_Shelf_WrappedGiftWarning[];
extern char const gText_Shelf_Yes[];
extern char const gText_Shelf_No[];
extern char const gText_Shelf_Items[];
extern char const gText_Shelf_Title[];
extern char const gText_Shelf_EmptyDescription[];

extern char const gText_ToolChest_HeaderTools[];
extern char const gText_ToolChest_Title[];
extern char const gText_ToolChest_EmptyDescription[];

#endif // HOME_STORAGE_TEXT_HH
