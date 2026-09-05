#include "reference_guide.hh"

// Reference Guide page 50: AWL character profile for the player's child. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_AwlChild_Title[20] SECTION(".rodata.reference_guide_awl_child_text") =
    "<cs>の紹介　　　　";

char const gText_ReferenceGuide_AwlChild_Introduction_Line01[16] SECTION(".rodata.reference_guide_awl_child_text") =
    "<cp>の息子。";

char const gText_ReferenceGuide_AwlChild_Profile01_Marker[8] SECTION(".rodata.reference_guide_awl_child_text") =
    "<321>";

char const gText_ReferenceGuide_AwlChild_Profile01_Line01[24] SECTION(".rodata.reference_guide_awl_child_text") =
    "どこか母親に似ている。";

char const gText_ReferenceGuide_AwlChild_Profile02_Marker[8] SECTION(".rodata.reference_guide_awl_child_text") =
    "<322>";

char const gText_ReferenceGuide_AwlChild_Profile02_Line01[28] SECTION(".rodata.reference_guide_awl_child_text") =
    "これからどうなっていくのか";

char const gText_ReferenceGuide_AwlChild_Profile02_Line02[12] SECTION(".rodata.reference_guide_awl_child_text") =
    "楽しみ。";
