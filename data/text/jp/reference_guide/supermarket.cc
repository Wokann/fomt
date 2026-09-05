#include "reference_guide.hh"

// Reference Guide page 62: Supermarket. Fixed field capacities and physical
// order match the Japanese ROM.

char const gText_ReferenceGuide_Supermarket_Title[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "ザっか屋　　　　　　　　　　";

char const gText_ReferenceGuide_Supermarket_Overview_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·作物の種やお料理用の材料、";
char const gText_ReferenceGuide_Supermarket_Overview_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　かごやリュックなどが買える";
char const gText_ReferenceGuide_Supermarket_Overview_Line03[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　他に、持っているものをプレ";
char const gText_ReferenceGuide_Supermarket_Overview_Line04[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　ゼント用に包んでもらうこと";
char const gText_ReferenceGuide_Supermarket_Overview_Line05[20] SECTION(".rodata.reference_guide_supermarket_text") =
    "　もできるお店。";

char const gText_ReferenceGuide_Supermarket_StoreHours_Value[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "　午前９時～午後５時";
char const gText_ReferenceGuide_Supermarket_ClosedDay_Value[20] SECTION(".rodata.reference_guide_supermarket_text") =
    "　火曜日　日曜日";

char const gText_ReferenceGuide_Supermarket_Seeds_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆種";
char const gText_ReferenceGuide_Supermarket_Seeds_Description_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·耕した土地にこれをまいて、";
char const gText_ReferenceGuide_Supermarket_Seeds_Description_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　水を毎日あげれば成長する。";
char const gText_ReferenceGuide_Supermarket_Seeds_Description_Line03[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　※種によって育つ季節と育た";
char const gText_ReferenceGuide_Supermarket_Seeds_Description_Line04[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　　ない季節があるので注意。";
char const gText_ReferenceGuide_Supermarket_Seeds_SeasonalAvailability_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·季節によって売っている種の";
char const gText_ReferenceGuide_Supermarket_Seeds_SeasonalAvailability_Line02[20] SECTION(".rodata.reference_guide_supermarket_text") =
    "　種類が変わる。";

char const gText_ReferenceGuide_Supermarket_Ingredients_RiceBall_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆おにぎり";
char const gText_ReferenceGuide_Supermarket_Ingredients_Bread_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆パン";
char const gText_ReferenceGuide_Supermarket_Ingredients_Oil_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆油";
char const gText_ReferenceGuide_Supermarket_Ingredients_Flour_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆小麦粉";
char const gText_ReferenceGuide_Supermarket_Ingredients_CurryPowder_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆カレー粉";
char const gText_ReferenceGuide_Supermarket_Ingredients_DumplingFlour_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆だんご粉";
char const gText_ReferenceGuide_Supermarket_Ingredients_Chocolate_Title[16] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆チョコレート";
char const gText_ReferenceGuide_UseInCooking_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·これらはお料理に使う材料。";
char const gText_ReferenceGuide_Supermarket_Ingredients_EatDirectly_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·お料理に使わずにそのまま食";
char const gText_ReferenceGuide_Supermarket_Ingredients_EatDirectly_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "　べることもできる。";
char const gText_ReferenceGuide_RefrigeratorPurchases_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·『冷蔵庫』があれば、一度に";
char const gText_ReferenceGuide_RefrigeratorPurchases_Line02[20] SECTION(".rodata.reference_guide_supermarket_text") =
    "　たくさん買える。";
char const gText_ReferenceGuide_Supermarket_Ingredients_SeasonalAvailability_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·時期によって売ってない場合";
char const gText_ReferenceGuide_Supermarket_Ingredients_SeasonalAvailability_Line02[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "　もある。";

char const gText_ReferenceGuide_Supermarket_Basket_Title[8] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆かご";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·出荷するものを３０コまで、";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "　ここに入れておける。";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line03[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　一旦入れたものを取り出すこ";
char const gText_ReferenceGuide_Supermarket_Basket_Description_Line04[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "　とはできないので注意。";
char const gText_ReferenceGuide_Supermarket_Basket_Purchase_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·「持ち物」を持ち上げてると";
char const gText_ReferenceGuide_Supermarket_Basket_Purchase_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "　買えないので注意。";
char const gText_ReferenceGuide_Supermarket_Basket_Purchase_Line03[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　買った時に持ち上げるので…";

char const gText_ReferenceGuide_Supermarket_Rucksack_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆リュック";
char const gText_ReferenceGuide_Supermarket_Rucksack_Description_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·持てる「装備」「持ち物」の";
char const gText_ReferenceGuide_Supermarket_Rucksack_Description_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　数がそれぞれ４コ＋１コずつ";
char const gText_ReferenceGuide_Supermarket_Rucksack_Description_Line03[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "　になる。";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Title[20] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆大きいリュック";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Description_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　数がそれぞれ８コ＋１コずつ";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Requirements_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·大きいリュックはリュックを";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_Requirements_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　買わないと売り出されない。";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_ImmediateUse_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·買った瞬間に装着されるので";
char const gText_ReferenceGuide_Supermarket_LargeRucksack_ImmediateUse_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　装備の空きなどは関係なし。";

char const gText_ReferenceGuide_Supermarket_BlueFeather_Title[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆青い羽根";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Description_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·女の子にプロポーズするため";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Description_Line02[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "　の道具。";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Availability_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·仲の良い女の子がいると売り";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Availability_Line02[24] SECTION(".rodata.reference_guide_supermarket_text") =
    "　出されるようになる。";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Classification_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·「持ち物」ではなく「装備」";
char const gText_ReferenceGuide_Supermarket_BlueFeather_Classification_Line02[16] SECTION(".rodata.reference_guide_supermarket_text") =
    "　なので注意。";

char const gText_ReferenceGuide_Supermarket_GiftWrapping_Title[16] SECTION(".rodata.reference_guide_supermarket_text") =
    "☆プレゼント";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·これに包んでプレゼントする";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　と、普通にプレゼントした場";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line03[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "　合よりも喜んでもらえる。";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line04[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　嫌いなものを包んでプレゼン";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Description_Line05[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　トした場合はもっと嫌われる";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_EligibleItems_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·「持ち物」に入ってるものを";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_EligibleItems_Line02[12] SECTION(".rodata.reference_guide_supermarket_text") =
    "　包む。";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_EligibleItems_Line03[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　プレゼント出来るものなら何";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_EligibleItems_Line04[28] SECTION(".rodata.reference_guide_supermarket_text") =
    "　でも包むことができる。";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Removal_Line01[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "·『冷蔵庫』『整理棚』に入れ";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Removal_Line02[32] SECTION(".rodata.reference_guide_supermarket_text") =
    "　ようとすると包みが取れてし";
char const gText_ReferenceGuide_Supermarket_GiftWrapping_Removal_Line03[20] SECTION(".rodata.reference_guide_supermarket_text") =
    "　まうので注意。";
