#include "animal_festival_text.hh"

// Direct-indexed animal-festival livestock contestant names. The fixed
// 13-byte rows retain the original JP display-space padding.

char const gCppRuntimeBadAlloc_AnimalFestivalLivestockContestantNames[]
    SECTION(".rodata.animal_festival_livestock_contestant_names_runtime") =
        "bad_alloc";

char const gText_AnimalFestival_LivestockContestantNames[40][13] SECTION(".rodata.animal_festival_livestock_contestant_names") ALIGN(1) = {
    "ミッドナイト",
    "ハルモニア　",
    "ダストホール",
    "イングヴァイ",
    "レストアップ",
    "ホーリーデイ",
    "トンプクヤク",
    "アラビアン　",
    "セイタイゴウ",
    "サコリュウ　",
    "ナガレボシ　",
    "ヒクテアマタ",
    "ギャンブラー",
    "ベオウルフ　",
    "ブルーアイ　",
    "トイワールド",
    "サマークール",
    "マリオネット",
    "インサイド　",
    "ラストワン　",
    "アグリアス　",
    "シーマム　　",
    "タキノボリ　",
    "マングローブ",
    "ナルシスト　",
    "ワープゾーン",
    "シーアール　",
    "ダンスマン　",
    "シチフクジン",
    "ロングホーン",
    "ワスレナグサ",
    "ミンサン　　",
    "ラッキーラン",
    "テイグンザン",
    "ライドオン　",
    "ダイセイコー",
    "ファクトリー",
    "マドレーヌ　",
    "カウボーイ　",
    "ネコマムシ　"
};
