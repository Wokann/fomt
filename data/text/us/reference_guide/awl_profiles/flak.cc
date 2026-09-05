#include "reference_guide.hh"

// Reference Guide page 53: AWL character profile for Flak. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_AwlFlak_Title[20] SECTION(".rodata.reference_guide_awl_flak_text") =
    "Introducing Flak";

char const gText_ReferenceGuide_AwlFlak_Profile01_Marker[8] SECTION(".rodata.reference_guide_awl_flak_text") =
    "<351>";

char const gText_ReferenceGuide_AwlFlak_Profile02_Marker[8] SECTION(".rodata.reference_guide_awl_flak_text") =
    "<352>";

char const gText_ReferenceGuide_AwlFlak_Profile02_Line01[24] SECTION(".rodata.reference_guide_awl_flak_text") =
    "He likes wearing red.";

char const gText_ReferenceGuide_AwlFlak_Profile02_Line02[24] SECTION(".rodata.reference_guide_awl_flak_text") =
    "He is a leader of the ";

char const gText_ReferenceGuide_AwlFlak_Profile02_Line03[20] SECTION(".rodata.reference_guide_awl_flak_text") =
    "Harvest Sprites.";
