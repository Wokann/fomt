#include "reference_guide.hh"

// Reference Guide page 89: Gray's New Year Card. Fixed field capacities and
// physical order match the US ROM.

char const gText_ReferenceGuide_GrayNewYearCard_Title[24] SECTION(".rodata.reference_guide_gray_new_year_card_text") =
    "Gray's New Year Card";
char const gText_ReferenceGuide_GrayNewYearCard_Message_Line01[20] SECTION(".rodata.reference_guide_gray_new_year_card_text") =
    "My grandpa told me";
char const gText_ReferenceGuide_GrayNewYearCard_Message_Line02[20] SECTION(".rodata.reference_guide_gray_new_year_card_text") =
    "to write this. Bye.";
char const gText_ReferenceGuide_GrayNewYearCard_Signature[24] SECTION(".rodata.reference_guide_gray_new_year_card_text") =
    "                 Gray";
