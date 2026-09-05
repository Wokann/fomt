#include "reference_guide.hh"

// Reference Guide page 76: Shelf. Fixed field capacities and physical order
// match the US ROM.

char const gText_ReferenceGuide_Shelf_Title[8] SECTION(".rodata.reference_guide_shelf_text") =
    "Shelf";
char const gText_ReferenceGuide_Shelf_Storage_Line02[16] SECTION(".rodata.reference_guide_shelf_text") =
    "inedible Items.";
char const gText_ReferenceGuide_Shelf_Capacity_Line01[16] SECTION(".rodata.reference_guide_shelf_text") =
    "Shelf holds 99 ";
char const gText_ReferenceGuide_Shelf_CookingSelectionRestriction_Line01[20] SECTION(".rodata.reference_guide_shelf_text") =
    "You cannot select ";
char const gText_ReferenceGuide_Shelf_CookingSelectionRestriction_Line02[24] SECTION(".rodata.reference_guide_shelf_text") =
    "Ingredients from the";
char const gText_ReferenceGuide_Shelf_CookingSelectionRestriction_Line03[20] SECTION(".rodata.reference_guide_shelf_text") =
    "Shelf when cooking.";
