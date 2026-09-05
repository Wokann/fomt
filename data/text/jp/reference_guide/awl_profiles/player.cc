#include "reference_guide.hh"

// Reference Guide page 54: AWL character profile for the player. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_AwlPlayer_Title[32] SECTION(".rodata.reference_guide_awl_player_text") =
    "<cp>さんの紹介　　　　　　　";

char const gText_ReferenceGuide_AwlPlayer_Introduction_Line01[32] SECTION(".rodata.reference_guide_awl_player_text") =
    "「わすれ谷」でタカクラという";

char const gText_ReferenceGuide_AwlPlayer_Introduction_Line02[32] SECTION(".rodata.reference_guide_awl_player_text") =
    "男と一緒に牧場をやっている。";

char const gText_ReferenceGuide_AwlPlayer_Profile01_Marker[8] SECTION(".rodata.reference_guide_awl_player_text") =
    "<361>";

char const gText_ReferenceGuide_AwlPlayer_Profile01_Line01[32] SECTION(".rodata.reference_guide_awl_player_text") =
    "嫁さんと息子の３人で暮らして";

char const gText_ReferenceGuide_AwlPlayer_Profile02_Marker[8] SECTION(".rodata.reference_guide_awl_player_text") =
    "<362>";

char const gText_ReferenceGuide_AwlPlayer_Profile02_Line01[28] SECTION(".rodata.reference_guide_awl_player_text") =
    "ここの畑では不思議な作物を";

char const gText_ReferenceGuide_AwlPlayer_Profile02_Line02[20] SECTION(".rodata.reference_guide_awl_player_text") =
    "育てているらしい。";
