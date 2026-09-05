#include "reference_guide.hh"

// Reference Guide page 50: AWL character profile for the player's child. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_AwlChild_Title[20] SECTION(".rodata.reference_guide_awl_child_text") =
    "Introducing <cs>";

char const gText_ReferenceGuide_AwlChild_Introduction_Line01[12] SECTION(".rodata.reference_guide_awl_child_text") =
    "<cp>'s son.";

char const gText_ReferenceGuide_AwlChild_Profile01_Marker[8] SECTION(".rodata.reference_guide_awl_child_text") =
    "<321>";

char const gText_ReferenceGuide_AwlChild_Profile01_Line01[28] SECTION(".rodata.reference_guide_awl_child_text") =
    "He takes after his mother.";

char const gText_ReferenceGuide_AwlChild_Profile02_Marker[8] SECTION(".rodata.reference_guide_awl_child_text") =
    "<322>";

char const gText_ReferenceGuide_AwlChild_Profile02_Line01[28] SECTION(".rodata.reference_guide_awl_child_text") =
    "What kind of man will he";

char const gText_ReferenceGuide_AwlChild_Profile02_Line02[16] SECTION(".rodata.reference_guide_awl_child_text") =
    "grow up to be?";
