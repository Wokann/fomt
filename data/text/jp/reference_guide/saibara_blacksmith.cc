#include "reference_guide.hh"

// Reference Guide page 61: Saibara the blacksmith. Fixed field capacities and
// physical order match the Japanese ROM.

char const gText_ReferenceGuide_SaibaraBlacksmith_Title[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "鍛冶屋サイバラ　　　　　　　";

char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·道具の改造をしてもらったり";
char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　動物の世話をする道具を買っ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　たりする他に、アクセサリー";
char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　や、いろいろなメーカーを作";
char const gText_ReferenceGuide_SaibaraBlacksmith_Overview_Line05[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ってもらえるお店。";

char const gText_ReferenceGuide_SaibaraBlacksmith_StoreHours_Heading[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·開店時間";
char const gText_ReferenceGuide_SaibaraBlacksmith_StoreHours_Value[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　午前１０時～午後４時";
char const gText_ReferenceGuide_SaibaraBlacksmith_ClosedDay_Heading[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·定休日";
char const gText_ReferenceGuide_SaibaraBlacksmith_ClosedDay_Value[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　木曜日";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Title[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆道具の改造";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·改造すると、道具を使う時に";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ボタンを押しっぱなしにする";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　と、ためることができるよう";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　になる。道具をためて使うと";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line05[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　効果範囲が広がったり、低い";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line06[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　レベルでは壊せなかったもの";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Benefits_Line07[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　が壊せるようになる。";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Heading[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·改造の手順は、";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　改造したい道具をリュックに";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　入れて（装備していなくても";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　いい）、改造したいレベルに";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　対応した鉱石をリュックに入";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line05[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　れる。（これも鉱石は持ち上";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line06[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　げていなくてもいい）";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line07[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　この状態でカウンター越しに";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line08[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　サイバラさんに話しかけて、";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line09[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　お店のウインドウを出したら";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line10[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　「道具のレベルアップ」を選";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line11[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　んでから、改造したい道具と";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line12[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　それに使う鉱石を選ぶと、そ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line13[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　の場で道具と鉱石をわたす。";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line14[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　改造をたのむと完成するまで";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line15[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　お店は閉まったままで、道具";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line16[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　もあずけたままになって使え";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line17[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　なくなるので注意。";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line18[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　改造が終わるとお店が開くの";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line19[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　で、サイバラさんに話しかけ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line20[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ると改造が終わった道具を受";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line21[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　け取れる。そのとき「装備」";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line22[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　がまんたんだったら受け取れ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Procedure_Line23[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ないので注意。";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Heading[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·改造できる道具は、";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Hoe[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　クワ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Scythe[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　カマ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Axe[8] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　オノ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_Hammer[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ハンマー";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_WateringCan[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　じょうろ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_EligibleTools_FishingRod[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　釣り竿　　の６種類。";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·改造にかかる日数は今の道具";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　のレベルと改造したいレベル";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line03[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　によって変わる。";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　一気に高いレベルの物に改造";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line05[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　しようとするとたくさん日数";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Duration_Line06[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　がかかる。";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Cost_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·改造にかかる値段はどのレベ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Cost_Line02[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ルに改造するかで変わる。";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Cost_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　高いレベルに変えようとする";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Cost_Line04[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　とお金がたくさんかかる。";

char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·道具の経験値によって改造が";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line02[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　できるかどうか決まる。";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　どのレベルまで改造できるの";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　かは『家計簿』の「道具のレ";
char const gText_ReferenceGuide_SaibaraBlacksmith_ToolUpgrade_Experience_Line05[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ベル一覧」を見ればいい。";

char const gText_ReferenceGuide_SaibaraBlacksmith_Brush_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆ブラシ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Milker_Title[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆乳しぼり器";
char const gText_ReferenceGuide_SaibaraBlacksmith_Clippers_Title[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆毛がりばさみ";
char const gText_ReferenceGuide_SaibaraBlacksmith_AnimalTools_PurchaseLimit_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·この３つはその場で買える。";
char const gText_ReferenceGuide_SaibaraBlacksmith_AnimalTools_PurchaseLimit_Line02[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　１コずつしか買えない。";

char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Bracelet_Title[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆ブレスレット";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Necklace_Title[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆ネックレス";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Earrings_Title[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆イヤリング";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Broach_Title[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆ブローチ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Gift_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·女の子にプレゼントすると喜";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Gift_Line02[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ばれるかも？";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·値段は１０００Ｇなんだけど";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　それとは別にオリハルコンが";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　必要。これは道具の改造と同";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　じで、持ち上げている必要は";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line05[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　無くてリュックに入っていれ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Requirements_Line06[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ばいい。";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_CompletionTime_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·頼んでから２日後に出来あが";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·完成するまでお店は閉まった";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ままになる。完成するとお店";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　が開くようになるので、サイ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　バラさんに話しかけて、出来";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line05[28] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　あがった物を受け取れる。";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line06[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　そのとき「持ち物」がまんた";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line07[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　んだったら受け取れないので";
char const gText_ReferenceGuide_SaibaraBlacksmith_Jewelry_Pickup_Line08[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　注意。";

char const gText_ReferenceGuide_SaibaraBlacksmith_MayonnaiseMaker_Title[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆マヨネーズメーカー";
char const gText_ReferenceGuide_SaibaraBlacksmith_MayonnaiseMaker_Description_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·卵を入れるとマヨネーズがで";
char const gText_ReferenceGuide_SaibaraBlacksmith_MayonnaiseMaker_Description_Line02[16] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　きる機械。";
char const gText_ReferenceGuide_SaibaraBlacksmith_MayonnaiseMaker_Description_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　卵のサイズによってマヨネー";
char const gText_ReferenceGuide_SaibaraBlacksmith_MayonnaiseMaker_Description_Line04[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ズのサイズが変わる。";
char const gText_ReferenceGuide_SaibaraBlacksmith_CheeseMaker_Title[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆チーズメーカー";
char const gText_ReferenceGuide_SaibaraBlacksmith_CheeseMaker_Description_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·牛乳を入れるとチーズができ";
char const gText_ReferenceGuide_SaibaraBlacksmith_CheeseMaker_Description_Line02[12] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　る機械。";
char const gText_ReferenceGuide_SaibaraBlacksmith_CheeseMaker_Description_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　牛乳のサイズによってチーズ";
char const gText_ReferenceGuide_SaibaraBlacksmith_CheeseMaker_Description_Line04[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　のサイズが変わる。";
char const gText_ReferenceGuide_SaibaraBlacksmith_YarnMaker_Title[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "☆毛糸玉メーカー";
char const gText_ReferenceGuide_SaibaraBlacksmith_YarnMaker_Description_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·羊毛を入れると毛糸玉ができ";
char const gText_ReferenceGuide_SaibaraBlacksmith_YarnMaker_Description_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　羊毛のサイズによって毛糸玉";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Requirements_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·この３つのメーカーはどれも";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Requirements_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　値段が２００００Ｇなんだけ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Requirements_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ど、それとは別にアダマンタ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Requirements_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　イトが必要。これは道具の改";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Requirements_Line05[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　造と同じで、持ち上げている";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Requirements_Line06[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　必要は無くてリュックに入っ";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Requirements_Line07[20] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　ていればいい。";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_CompletionTime_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·頼んでから５日後に出来あが";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Placement_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　に行かなくても直接小屋の中";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Placement_Line02[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　（マヨネーズメーカーなら鶏";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Placement_Line03[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　小屋、チーズメーカーと毛糸";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Placement_Line04[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　玉メーカーなら動物小屋）に";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_Placement_Line05[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　置いておいてくれる。";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_AfterExpansion_Line01[32] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "·小屋を増築した後じゃないと";
char const gText_ReferenceGuide_SaibaraBlacksmith_Makers_AfterExpansion_Line02[24] SECTION(".rodata.reference_guide_saibara_blacksmith_text") =
    "　頼めないので注意！";
