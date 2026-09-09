#include "new_game_name_entry_text.hh"

// The JP name-entry screen indexes this one-indexed table with index × 13.
// Keeping the rows fixed-width preserves the original full-width padding and
// the metadata lookup base located 14 bytes before the first valid entry.
u32 const gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue =
    0x20;

char const gCppRuntimeBadAlloc_NewGameNameEntryPresetNames[] =
    "bad_alloc";

char const gText_NameEntry_PresetAnimalNames[30][13] ALIGN(1) = {
    "アーガイル　",
    "アヴァロン　",
    "アンコロモチ",
    "カタナ　　　",
    "カンデンチ　",
    "さくや　　　",
    "桜丸　　　　",
    "シシオー　　",
    "シャリオン　",
    "ジロー　　　",
    "セラフィック",
    "チョビチ　　",
    "トリスタン　",
    "とんこつ丸　",
    "日輪丸　　　",
    "バウワウ　　",
    "ハナビ　　　",
    "ぷにぷに　　",
    "ブロンディ　",
    "ぽん太　　　",
    "マメタロウ　",
    "マローン　　",
    "モロキュウ　",
    "夜叉　　　　",
    "ゆうなぎ　　",
    "ハナ　　　　",
    "ランブル　　",
    "リーソクツモ",
    "リヴァイアン",
    "ロケッツ　　",
};
