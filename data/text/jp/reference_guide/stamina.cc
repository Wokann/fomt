#include "reference_guide.hh"

// Reference Guide page 13: Stamina and Fatigue. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_StaminaAndFatigue_Title[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "体力·疲労の変化　　　　　　";

char const gText_ReferenceGuide_StaminaAndFatigue_Line01[8] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "★体力";

char const gText_ReferenceGuide_StaminaAndFatigue_Line02[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "·装備アイテムを使うのに必要";

char const gText_ReferenceGuide_StaminaAndFatigue_Line03[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　で、使ったアイテムやレベル";

char const gText_ReferenceGuide_StaminaAndFatigue_Line04[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　によって減る体力は変わる。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line05[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "·体力を回復させるためには…";

char const gText_ReferenceGuide_StaminaAndFatigue_Line06[12] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　·寝る。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line07[20] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　·温泉に入る。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line08[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　（寝るも温泉に入るも時間に";

char const gText_ReferenceGuide_StaminaAndFatigue_Line09[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　　よって変化。長いほど回復";

char const gText_ReferenceGuide_StaminaAndFatigue_Line10[20] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　　量が増える）";

char const gText_ReferenceGuide_StaminaAndFatigue_Line11[24] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　·食べ物を食べる。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line12[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　（食べた物によって回復量は";

char const gText_ReferenceGuide_StaminaAndFatigue_Line13[28] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　　変化。減る場合もある）";

char const gText_ReferenceGuide_StaminaAndFatigue_Line14[28] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　·花瓶に花を飾っておく。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line15[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　（飾る花によっては回復しな";

char const gText_ReferenceGuide_StaminaAndFatigue_Line16[20] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　　いものもあり）";

char const gText_ReferenceGuide_StaminaAndFatigue_Line17[12] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "ちなみに、";

char const gText_ReferenceGuide_StaminaAndFatigue_Line18[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "物を持ち上げたり、おろしたり";

char const gText_ReferenceGuide_StaminaAndFatigue_Line19[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "するだけでは体力は減らない。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line20[8] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "★疲労";

char const gText_ReferenceGuide_StaminaAndFatigue_Line21[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "·天気の悪い日に外で装備アイ";

char const gText_ReferenceGuide_StaminaAndFatigue_Line22[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　テムを使ったり、夜遅くまで";

char const gText_ReferenceGuide_StaminaAndFatigue_Line23[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　仕事をしていたり、体力が無";

char const gText_ReferenceGuide_StaminaAndFatigue_Line24[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　い時に装備アイテムを使うと";

char const gText_ReferenceGuide_StaminaAndFatigue_Line25[20] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　増えてしまう。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line26[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　疲労がまんたんになると倒れ";

char const gText_ReferenceGuide_StaminaAndFatigue_Line27[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　て病院に入院することになる";

char const gText_ReferenceGuide_StaminaAndFatigue_Line28[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "·疲労を回復させるためには…";

char const gText_ReferenceGuide_StaminaAndFatigue_Line29[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　　変化。増える場合もある）";

char const gText_ReferenceGuide_StaminaAndFatigue_Line30[28] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　·暖炉に薪を投げ込む。";

char const gText_ReferenceGuide_StaminaAndFatigue_Line31[32] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　（冬のみ、他の季節だと逆に";

char const gText_ReferenceGuide_StaminaAndFatigue_Line32[20] SECTION(".rodata.reference_guide_stamina_and_fatigue_text") =
    "　　疲労が増える）";
