#include "frisbee_text.hh"

// Static Frisbee UI text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_Frisbee_ExplanationQuestion[] SECTION(".rodata.frisbee") =
    "遊び方の説明を見ますか？";

char const gText_Frisbee_Yes[] SECTION(".rodata.frisbee") =
    "はい";

char const gText_Frisbee_No[] SECTION(".rodata.frisbee") =
    "いいえ";

char const gText_Frisbee_ExplanationCursorTiming[] SECTION(".rodata.frisbee") =
    "\p"
    "ゲームが始ると、画面左にある\r\n"
    "遠投ゲージのカーソルが動き始\r\n"
    "めます。{Press}\r\n"
    "タイミングよくＡボタンを押し\r\n"
    "て、カーソルを止めましょう。{Press}";

char const gText_Frisbee_ExplanationGreenZone[] SECTION(".rodata.frisbee") =
    "\p"
    "ゲージの緑色の部分は、犬が\r\n"
    "フリスビーをキャッチできる\r\n"
    "距離です。{Press}";

char const gText_Frisbee_ExplanationRedZone[] SECTION(".rodata.frisbee") =
    "\p"
    "ゲージの赤色の部分は、犬が\r\n"
    "フリスビーをキャッチできな\r\n"
    "い距離です。{Press}\r\n"
    "うまくゲージの緑色の範囲内で\r\n"
    "距離を決めましょう。{Press}";

char const gText_Frisbee_ExplanationPractice[] SECTION(".rodata.frisbee") =
    "\p"
    "フリスビーの練習を重ねること\r\n"
    "で、キャッチできる距離が長く\r\n"
    "なっていきます。{Press}\r\n"
    "ただし、１日に何度も遊んでい\r\n"
    "ると、犬が飽きてしまいます。{Press}\r\n"
    "そうなると、その日はもう遊べ\r\n"
    "ないので注意しましょう。{Press}\r\n"
    "犬と仲良くなれば、１日に遊べ\r\n"
    "る回数も増えていきます。{Press}";

char const gText_Frisbee_ExplanationTournament[] SECTION(".rodata.frisbee") =
    "\p"
    "フリスビー大会では\r\n"
    "２回投げて、良いほうの記録を\r\n"
    "採用します。{Press}";

char const gText_Frisbee_ExplainAgain[] SECTION(".rodata.frisbee") =
    "もう一度説明を見ますか？";

char const gText_Frisbee_ThrowAgain[] SECTION(".rodata.frisbee") =
    "\p"
    "２投目を投げてください。{Press}";

char const gText_Frisbee_TournamentFinished[] SECTION(".rodata.frisbee") =
    "\p"
    "競技が終了しました。{Press}";

char const gText_Frisbee_PlayAgain[] SECTION(".rodata.frisbee") =
    "もう一度遊びますか？";

char const gText_Frisbee_DogNoLongerWantsToPlay[] SECTION(".rodata.frisbee") =
    "\p"
    "今日はもうフリスビーで\r\n"
    "遊びたくないようだ…{Press}";

char const gText_Frisbee_FoundItem[] SECTION(".rodata.frisbee") =
    "\p"
    "\xFFをみつけた！{Press}";

char const gText_Frisbee_FoundNothing[] SECTION(".rodata.frisbee") =
    "\p"
    "なにもみつからなかった…{Press}";

char const gText_Frisbee_TournamentScoreboard[] FRISBEE_SCOREBOARD_TEXT =
    "フリスビー大会　記録表";

char const gCppRuntimeBadAlloc_FrisbeeScoreboard[]
    SECTION(".rodata.frisbee_scoreboard_trailer_runtime") =
        "bad_alloc";

char const gCppRuntimeBadAlloc_FrisbeeTextTrailer[]
    SECTION(".rodata.frisbee_text_trailer_runtime") =
        "bad_alloc";
