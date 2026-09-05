#include "reference_guide.hh"

// Reference Guide page 53: AWL character profile for Flak. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_AwlFlak_Title[32] SECTION(".rodata.reference_guide_awl_flak_text") =
    "フラットさんの紹介　　　　　";

char const gText_ReferenceGuide_AwlFlak_Profile01_Marker[8] SECTION(".rodata.reference_guide_awl_flak_text") =
    "<351>";

char const gText_ReferenceGuide_AwlFlak_Profile02_Marker[8] SECTION(".rodata.reference_guide_awl_flak_text") =
    "<352>";

char const gText_ReferenceGuide_AwlFlak_Profile02_Line01[20] SECTION(".rodata.reference_guide_awl_flak_text") =
    "赤い服を着ている。";

char const gText_ReferenceGuide_AwlFlak_Profile02_Line02[32] SECTION(".rodata.reference_guide_awl_flak_text") =
    "コロボックルの中ではリーダー";

char const gText_ReferenceGuide_AwlFlak_Profile02_Line03[12] SECTION(".rodata.reference_guide_awl_flak_text") =
    "的存在。";
