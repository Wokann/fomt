#include "frisbee_scoreboard.hh"

// One-based contestant IDs select fixed thirteen-byte encoded rows.
char const gText_FrisbeeScoreboard_ContestantNames
    [FRISBEE_SCOREBOARD_CONTESTANT_COUNT]
    [FRISBEE_SCOREBOARD_CONTESTANT_NAME_WIDTH] ALIGN(1) = {
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

// The display reads thirteen codes; keep the original forty-byte bound.
u16 const gFrisbeeScoreboardCharacterCodes[20] = {
    "０１２３４５６７８９．ｍ位"
};

char const gText_Frisbee_TournamentScoreboard[] =
    "フリスビー大会　記録表";
