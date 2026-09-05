#include "reference_guide.hh"

// Reference Guide page 15: Using Tools. Fixed field capacities and physical order match the ROM.

char const gText_ReferenceGuide_UsingTools_Title[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "道具の効果　　　　　　　　　";

char const gText_ReferenceGuide_UsingTools_Sickle_Title[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "★カマ";

char const gText_ReferenceGuide_UsingTools_Sickle_Line01[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "·牧草を刈り取る。";

char const gText_ReferenceGuide_UsingTools_Sickle_Line02[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "·雑草を刈り取る。";

char const gText_ReferenceGuide_UsingTools_Sickle_Line03[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "·その他作物を刈り取る。";

char const gText_ReferenceGuide_UsingTools_Sickle_Line04[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "初期状態だと目の前１マス分し";

char const gText_ReferenceGuide_UsingTools_Sickle_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "か刈れないんだけど、鍛冶屋で";

char const gText_ReferenceGuide_UsingTools_Sickle_Line06[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "改造してもらうと、道具レベル";

char const gText_ReferenceGuide_UsingTools_Sickle_Line07[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "とため時間によって効果範囲が";

char const gText_ReferenceGuide_UsingTools_Sickle_Line08[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "大きくなって行く。";

char const gText_ReferenceGuide_UsingTools_Sickle_Line09[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『ミスリルのカマ』にした場合";

char const gText_ReferenceGuide_UsingTools_Sickle_Line10[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "なら最大までためて使うと効果";

char const gText_ReferenceGuide_UsingTools_Sickle_Line11[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "範囲が自分中心５×５マス分に";

char const gText_ReferenceGuide_UsingTools_Sickle_Line12[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "なる。";

char const gText_ReferenceGuide_UsingTools_Hoe_Title[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "★クワ";

char const gText_ReferenceGuide_UsingTools_Hoe_Line01[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "·土地を耕す。";

char const gText_ReferenceGuide_UsingTools_Hoe_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "·種をまいてまだ芽が出ていな";

char const gText_ReferenceGuide_UsingTools_Hoe_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "　い土地、牧草地を刈り取った";

char const gText_ReferenceGuide_UsingTools_Hoe_Line04[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "　直後の土地を掘り返す。";

char const gText_ReferenceGuide_UsingTools_Hoe_Line05[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "·鉱石場の地面を掘る。";

char const gText_ReferenceGuide_UsingTools_Hoe_Line06[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "か耕せないんだけど、鍛冶屋で";

char const gText_ReferenceGuide_UsingTools_Hoe_Line07[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『ミスリルのクワ』にした場合";

char const gText_ReferenceGuide_UsingTools_Hoe_Line08[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "範囲が自分の前方６マス分にな";

char const gText_ReferenceGuide_UsingTools_Hoe_Line09[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "る。";

char const gText_ReferenceGuide_UsingTools_Hoe_Line10[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "※鉱石場で使った場合はいくら";

char const gText_ReferenceGuide_UsingTools_Hoe_Line11[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "　ためても１マス分しか効果は";

char const gText_ReferenceGuide_UsingTools_Hoe_Line12[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "　無い。";

char const gText_ReferenceGuide_UsingTools_Axe_Title[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "★オノ";

char const gText_ReferenceGuide_UsingTools_Axe_Line01[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "·枝、切り株を壊す。";

char const gText_ReferenceGuide_UsingTools_Axe_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "初期状態だと枝しか壊せないん";

char const gText_ReferenceGuide_UsingTools_Axe_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "だけど、鍛冶屋で改造してもら";

char const gText_ReferenceGuide_UsingTools_Axe_Line04[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "うと、道具レベルとため時間に";

char const gText_ReferenceGuide_UsingTools_Axe_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "よって切り株が壊せるようにな";

char const gText_ReferenceGuide_UsingTools_Axe_Line06[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "って、壊すまでにかかる回数も";

char const gText_ReferenceGuide_UsingTools_Axe_Line07[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "変わってくる。";

char const gText_ReferenceGuide_UsingTools_Axe_Line08[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『銅のオノ』にして最大までた";

char const gText_ReferenceGuide_UsingTools_Axe_Line09[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "めて使うと「切り株」が壊せる";

char const gText_ReferenceGuide_UsingTools_Axe_Line10[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "ようになる。壊すまで６回叩く";

char const gText_ReferenceGuide_UsingTools_Axe_Line11[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "必要がある。";

char const gText_ReferenceGuide_UsingTools_Axe_Line12[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『ミスリルのオノ』にして最大";

char const gText_ReferenceGuide_UsingTools_Axe_Line13[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "までためて使うと「切り株」は";

char const gText_ReferenceGuide_UsingTools_Axe_Line14[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "１回叩くだけで壊せるようにな";

char const gText_ReferenceGuide_UsingTools_Hammer_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★ハンマー";

char const gText_ReferenceGuide_UsingTools_Hammer_Line01[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "·石、大きな石、岩、";

char const gText_ReferenceGuide_UsingTools_Hammer_Line02[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　柵、壊れた柵を壊す。";

char const gText_ReferenceGuide_UsingTools_Hammer_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "·耕地を耕す前の地面に戻す。";

char const gText_ReferenceGuide_UsingTools_Hammer_Line04[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "·鉱石場の石を壊す。";

char const gText_ReferenceGuide_UsingTools_Hammer_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "初期状態だと大きな石と岩は壊";

char const gText_ReferenceGuide_UsingTools_Hammer_Line06[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "せないんだけど、鍛冶屋で改造";

char const gText_ReferenceGuide_UsingTools_Hammer_Line07[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "してもらうと、道具レベルとた";

char const gText_ReferenceGuide_UsingTools_Hammer_Line08[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "め時間によってそれらが壊せる";

char const gText_ReferenceGuide_UsingTools_Hammer_Line09[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "ようになったり、壊すまでにか";

char const gText_ReferenceGuide_UsingTools_Hammer_Line10[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "かる回数も変わってくる。";

char const gText_ReferenceGuide_UsingTools_Hammer_Line11[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『銅のハンマー』にして最大ま";

char const gText_ReferenceGuide_UsingTools_Hammer_Line12[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "でためて使うと「大きな石」が";

char const gText_ReferenceGuide_UsingTools_Hammer_Line13[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "壊せるようになる。壊すまで６";

char const gText_ReferenceGuide_UsingTools_Hammer_Line14[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "回叩く必要がある。";

char const gText_ReferenceGuide_UsingTools_Hammer_Line15[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『銀のハンマー』にして最大ま";

char const gText_ReferenceGuide_UsingTools_Hammer_Line16[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "でためて使うと「岩」が壊せる";

char const gText_ReferenceGuide_UsingTools_Hammer_Line17[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "ちなみに「大きな石」だと３回";

char const gText_ReferenceGuide_UsingTools_Hammer_Line18[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "で壊せる。";

char const gText_ReferenceGuide_UsingTools_Hammer_Line19[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『ミスリルのハンマー』にして";

char const gText_ReferenceGuide_UsingTools_Hammer_Line20[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "最大までためて使うと「大きな";

char const gText_ReferenceGuide_UsingTools_Hammer_Line21[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "石」は１回で、「岩」は２回叩";

char const gText_ReferenceGuide_UsingTools_Hammer_Line22[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "くと壊せるようになる。";

char const gText_ReferenceGuide_UsingTools_WateringCan_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★じょうろ";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line01[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "·耕地に水をまく。";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "·水場で使うと水を補給する。";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "か水がまけないんだけど、鍛冶";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line04[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "屋で改造してもらうと、道具レ";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "ベルとため時間によって効果範";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line06[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "囲が大きくなって、水の入る最";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line07[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "大量も多くなる。";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line08[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "『ミスリルのじょうろ』にした";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line09[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "場合、水の入る最大量が１５０";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line10[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "マス分になって、最大までため";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line11[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "て使うと効果範囲が自分の前方";

char const gText_ReferenceGuide_UsingTools_WateringCan_Line12[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "横５×縦３マス分になる。";

char const gText_ReferenceGuide_UsingTools_FishingRod_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★釣り竿";

char const gText_ReferenceGuide_UsingTools_FishingRod_Line01[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "·水場で使うと魚を釣る。";

char const gText_ReferenceGuide_UsingTools_FishingRod_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "釣る場所、季節、ためレベルに";

char const gText_ReferenceGuide_UsingTools_FishingRod_Line03[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "よって釣れるものが変わる。";

char const gText_ReferenceGuide_UsingTools_Seeds_Title[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "★種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line01[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "·耕したマスに種をまく。";

char const gText_ReferenceGuide_UsingTools_Seeds_Line02[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "　（自分中心に３×３マス）";

char const gText_ReferenceGuide_UsingTools_Seeds_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "耕したマス以外のマスに種をま";

char const gText_ReferenceGuide_UsingTools_Seeds_Line04[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "いても育たないので注意。";

char const gText_ReferenceGuide_UsingTools_Seeds_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "耕したマスでもそうでないマス";

char const gText_ReferenceGuide_UsingTools_Seeds_Line06[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "でも、どのマスにでも使ったら";

char const gText_ReferenceGuide_UsingTools_Seeds_Line07[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "なくなる。";

char const gText_ReferenceGuide_UsingTools_Seeds_Line08[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "種ごとに育つ季節が決まってい";

char const gText_ReferenceGuide_UsingTools_Seeds_Line09[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "て、それ以外の季節に種をまい";

char const gText_ReferenceGuide_UsingTools_Seeds_Line10[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "てもなくなるので注意。";

char const gText_ReferenceGuide_UsingTools_Seeds_Line11[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "春…かぶの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line12[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　じゃがいもの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line13[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　きゅうりの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line14[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　いちごの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line15[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　きゃべつの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line16[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　牧草の種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line17[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　ムーンドロップの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line18[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　トイフラワーの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line19[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "夏…トマトの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line20[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　とうもろこしの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line21[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　かぼちゃの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line22[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　パイナップルの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line23[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　たまねぎの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line24[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　ピンクキャットの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line25[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "秋…なすの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line26[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　さつまいもの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line27[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　ピーマンの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line28[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　にんじんの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line29[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　ほうれんそうの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line30[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　　マジックレッドの種";

char const gText_ReferenceGuide_UsingTools_Seeds_Line31[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "冬…何も育たない。";

char const gText_ReferenceGuide_UsingTools_Pedometer_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★万歩計";

char const gText_ReferenceGuide_UsingTools_Pedometer_Line01[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "·リュックに入れている間に、";

char const gText_ReferenceGuide_UsingTools_Pedometer_Line02[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "　歩数を数えてくれる。";

char const gText_ReferenceGuide_UsingTools_Pedometer_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "　装備していなくてもいいんだ";

char const gText_ReferenceGuide_UsingTools_Pedometer_Line04[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "　けど、装備して使っても歩数";

char const gText_ReferenceGuide_UsingTools_Pedometer_Line05[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "　は増やせる。";

char const gText_ReferenceGuide_UsingTools_BlueFeather_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★青い羽根";

char const gText_ReferenceGuide_UsingTools_BlueFeather_Line01[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "·女の子にプロポーズする。";

char const gText_ReferenceGuide_UsingTools_BlueFeather_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "結婚できる女の子以外に使って";

char const gText_ReferenceGuide_UsingTools_BlueFeather_Line03[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "も結婚できないので注意。";

char const gText_ReferenceGuide_UsingTools_Bell_Title[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "★ベル";

char const gText_ReferenceGuide_UsingTools_Bell_Line01[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "·牛、羊を呼ぶ。";

char const gText_ReferenceGuide_UsingTools_Bell_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "※遠くにいる牛、羊や、愛情度";

char const gText_ReferenceGuide_UsingTools_Bell_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "　の低い牛、羊は寄って来にく";

char const gText_ReferenceGuide_UsingTools_Bell_Line04[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "　いので注意。";

char const gText_ReferenceGuide_UsingTools_Brush_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★ブラシ";

char const gText_ReferenceGuide_UsingTools_Brush_Line01[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "·牛、羊、馬の世話に使う。";

char const gText_ReferenceGuide_UsingTools_Brush_Line02[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "１日１回使うだけでいい。";

char const gText_ReferenceGuide_UsingTools_Brush_Line03[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "２回以上使っても意味無し。";

char const gText_ReferenceGuide_UsingTools_Milker_Title[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "★乳しぼり器";

char const gText_ReferenceGuide_UsingTools_Milker_Line01[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "·健康な大牛の乳をしぼるのに";

char const gText_ReferenceGuide_UsingTools_Milker_Line02[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "　使う。";

char const gText_ReferenceGuide_UsingTools_Milker_Line03[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "１日１回しかしぼれない。";

char const gText_ReferenceGuide_UsingTools_Milker_Line04[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "病気の牛、小さい牛、妊娠中の";

char const gText_ReferenceGuide_UsingTools_Milker_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "牛からはしぼれないので注意。";

char const gText_ReferenceGuide_UsingTools_Milker_Line06[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "牛の愛情度によってしぼれる牛";

char const gText_ReferenceGuide_UsingTools_Milker_Line07[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "乳のサイズが変わる。";

char const gText_ReferenceGuide_UsingTools_Clippers_Title[16] SECTION(".rodata.reference_guide_using_tools_text") =
    "★毛がりばさみ";

char const gText_ReferenceGuide_UsingTools_Clippers_Line01[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "·大羊の毛を刈るのに使う。";

char const gText_ReferenceGuide_UsingTools_Clippers_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "毛を刈ると羊は丸刈りになって";

char const gText_ReferenceGuide_UsingTools_Clippers_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "それから７日経過するまでは毛";

char const gText_ReferenceGuide_UsingTools_Clippers_Line04[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "が生えそろわない。";

char const gText_ReferenceGuide_UsingTools_Clippers_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "小さい羊、妊娠中の羊からは毛";

char const gText_ReferenceGuide_UsingTools_Clippers_Line06[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "を刈れないので注意。";

char const gText_ReferenceGuide_UsingTools_Clippers_Line07[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "羊の愛情度によって刈れる羊毛";

char const gText_ReferenceGuide_UsingTools_Clippers_Line08[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "のサイズが変わる。";

char const gText_ReferenceGuide_UsingTools_AnimalMedicine_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★動物の薬";

char const gText_ReferenceGuide_UsingTools_AnimalMedicine_Line01[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "·鶏、牛、羊の病気をなおす。";

char const gText_ReferenceGuide_UsingTools_AnimalMedicine_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "健康、不機嫌な鶏、牛、羊に使";

char const gText_ReferenceGuide_UsingTools_AnimalMedicine_Line03[20] SECTION(".rodata.reference_guide_using_tools_text") =
    "っても効果無し。";

char const gText_ReferenceGuide_UsingTools_AnimalMedicine_Line04[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "犬、馬は病気にならないから、";

char const gText_ReferenceGuide_UsingTools_AnimalMedicine_Line05[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "これらに使っても効果無し。";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★牛のタネ";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line01[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "·大牛を妊娠させる。";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "大牛でも病気になっていると、";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line03[28] SECTION(".rodata.reference_guide_using_tools_text") =
    "妊娠させることができない。";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line04[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "動物小屋に牛、羊がまんたんに";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line05[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "いる場合も妊娠させることがで";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line06[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "きない。";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line07[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "動物小屋の妊娠場に空きがない";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line08[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "場合も妊娠させることができな";

char const gText_ReferenceGuide_UsingTools_CowMiraclePotion_Line09[8] SECTION(".rodata.reference_guide_using_tools_text") =
    "い。";

char const gText_ReferenceGuide_UsingTools_SheepMiraclePotion_Title[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "★羊のタネ";

char const gText_ReferenceGuide_UsingTools_SheepMiraclePotion_Line01[24] SECTION(".rodata.reference_guide_using_tools_text") =
    "·大羊を妊娠させる。";

char const gText_ReferenceGuide_UsingTools_SheepMiraclePotion_Line02[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "大羊でも病気になっていると、";

char const gText_ReferenceGuide_UsingTools_SheepMiraclePotion_Line03[32] SECTION(".rodata.reference_guide_using_tools_text") =
    "丸刈りの羊も妊娠させることが";

char const gText_ReferenceGuide_UsingTools_SheepMiraclePotion_Line04[12] SECTION(".rodata.reference_guide_using_tools_text") =
    "できない。";
