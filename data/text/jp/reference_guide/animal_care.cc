#include "reference_guide.hh"

// Reference Guide page 17: Caring for Animals. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_AnimalCare_Title[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "動物の飼い方　　　　　　　　";

char const gText_ReferenceGuide_AnimalCare_Introduction_Title[12] SECTION(".rodata.reference_guide_animal_care_text") =
    "★動物とは";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line01[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "鶏、牛、羊を指し、";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line02[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "卵や牛乳、羊毛を提供して";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line03[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "くれる、牧場生活において";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line04[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "欠かすことの出来ない存在";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line05[12] SECTION(".rodata.reference_guide_animal_care_text") =
    "である。";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line06[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "動物を育てて増やすことが";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line07[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "できれば、牧場生活はより";

char const gText_ReferenceGuide_AnimalCare_Introduction_Line08[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "充実したものとなるだろう。";

char const gText_ReferenceGuide_AnimalCare_Chickens_Title[8] SECTION(".rodata.reference_guide_animal_care_text") =
    "★鶏";

char const gText_ReferenceGuide_AnimalCare_Chickens_Line01[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "卵を生んでくれる。";

char const gText_ReferenceGuide_AnimalCare_Chickens_Line02[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "生んだ卵をふ化箱に置くと";

char const gText_ReferenceGuide_AnimalCare_Chickens_Line03[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "３日でヒヨコが生まれる。";

char const gText_ReferenceGuide_AnimalCare_Chickens_Line04[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "ヒヨコは１週間で鶏になる。";

char const gText_ReferenceGuide_AnimalCare_Cows_Title[8] SECTION(".rodata.reference_guide_animal_care_text") =
    "★牛";

char const gText_ReferenceGuide_AnimalCare_Cows_Line01[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "大人の牛（大牛）は牛乳を";

char const gText_ReferenceGuide_AnimalCare_CanCollectSuffix[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "取ることができる。";

char const gText_ReferenceGuide_AnimalCare_Cows_Line03[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "牛のタネを使って妊娠させると";

char const gText_ReferenceGuide_AnimalCare_Cows_Line04[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "３週間ほどで子牛を出産する。";

char const gText_ReferenceGuide_AnimalCare_FedDailyPrefix[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "毎日エサを与えた場合、";

char const gText_ReferenceGuide_AnimalCare_Cows_Line06[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "子牛は２週間で中牛に成長、";

char const gText_ReferenceGuide_AnimalCare_Cows_Line07[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "中牛は１週間で大牛へと";

char const gText_ReferenceGuide_AnimalCare_MaturitySuffix[12] SECTION(".rodata.reference_guide_animal_care_text") =
    "成長する。";

char const gText_ReferenceGuide_AnimalCare_Sheep_Title[8] SECTION(".rodata.reference_guide_animal_care_text") =
    "★羊";

char const gText_ReferenceGuide_AnimalCare_Sheep_Line01[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "大人の羊（大羊）は羊毛を";

char const gText_ReferenceGuide_AnimalCare_Sheep_Line02[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "毛は１週間で生えそろう。";

char const gText_ReferenceGuide_AnimalCare_Sheep_Line03[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "羊のタネを使って妊娠させると";

char const gText_ReferenceGuide_AnimalCare_Sheep_Line04[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "３週間ほどで子羊を出産する。";

char const gText_ReferenceGuide_AnimalCare_Sheep_Line05[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "子羊は２週間で大羊に";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Title[16] SECTION(".rodata.reference_guide_animal_care_text") =
    "★動物を育てる";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line01[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "動物には体調があり、";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line02[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "動物への接し方で変化する。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line03[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "毎日エサを与え、話しかけたり";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line04[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "ブラシがけをしてやる";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line05[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "エサを忘れると、不機嫌に";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line06[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "なることがあるので";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line07[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "毎日エサを与えること。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line08[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "不機嫌になっても毎日エサを";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line09[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "与えたり、ブラシがけを";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line10[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "することで健康状態に";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line11[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "戻すことができる。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line12[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "間違っても動物を農具で";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line13[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "たたいたりしないこと。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line14[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "すぐに不機嫌になり、愛情度も";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line15[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "下がってしまう。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line16[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "不機嫌の状態が続くと病気に";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line17[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "なる恐れがある。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line18[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "病気になったら、動物の薬を";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line19[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "使って直ちに病気を治すこと。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line20[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "病気のまま放置すると、";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line21[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "病死してしまう。";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line22[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "動物の体調管理をしっかり";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line23[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "行い、動物を育てていけば";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line24[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "動物の愛情度が上がっていき、";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line25[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "卵、牛乳、羊毛の質も";

char const gText_ReferenceGuide_AnimalCare_RaisingAnimals_Line26[12] SECTION(".rodata.reference_guide_animal_care_text") =
    "向上する。";

char const gText_ReferenceGuide_AnimalCare_Grazing_Title[16] SECTION(".rodata.reference_guide_animal_care_text") =
    "★放牧について";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line01[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "動物を小屋から牧場に出すこと";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line02[20] SECTION(".rodata.reference_guide_animal_care_text") =
    "を「放牧」と呼ぶ。";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line03[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "鶏はしばらく放牧しておくと";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line04[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "地面のエサを見つけて";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line05[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "食べる。牛、羊はよく育った";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line06[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "牧草が牧場に生えていれば";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line07[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "それをエサとして食べる。";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line08[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "また、不機嫌がなおったり、";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line09[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "愛情度が上がったりする";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line10[16] SECTION(".rodata.reference_guide_animal_care_text") =
    "効果もある。";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line11[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "よく放牧して育てた動物は";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line12[24] SECTION(".rodata.reference_guide_animal_care_text") =
    "卵、牛乳、羊毛の質が";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line13[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "良くなるという報告もあるので";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line14[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "積極的に放牧するべきである。";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line15[28] SECTION(".rodata.reference_guide_animal_care_text") =
    "ただし、放牧は晴れた日に";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line16[32] SECTION(".rodata.reference_guide_animal_care_text") =
    "行うこと。そして夜間は野犬に";

char const gText_ReferenceGuide_AnimalCare_Grazing_Line17[16] SECTION(".rodata.reference_guide_animal_care_text") =
    "注意すること。";
