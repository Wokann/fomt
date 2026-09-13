#include "frisbee_text.hh"

// Static Frisbee UI text.  The text processor converts these UTF-8 strings
// and named controls into the exact regional ROM bytes during the build.

char const gText_Frisbee_ExplanationQuestion[] =
    "遊び方の説明を見ますか？";

char const gText_Frisbee_Yes[] ALIGN(4) =
    "はい";

char const gText_Frisbee_No[] ALIGN(4) =
    "いいえ";

char const gText_Frisbee_ExplanationCursorTiming[] ALIGN(4) =
    "\p"
    "ゲームが始ると、画面左にある\r\n"
    "遠投ゲージのカーソルが動き始\r\n"
    "めます。{Press}\r\n"
    "タイミングよくＡボタンを押し\r\n"
    "て、カーソルを止めましょう。{Press}";

char const gText_Frisbee_ExplanationGreenZone[] ALIGN(4) =
    "\p"
    "ゲージの緑色の部分は、犬が\r\n"
    "フリスビーをキャッチできる\r\n"
    "距離です。{Press}";

char const gText_Frisbee_ExplanationRedZone[] ALIGN(4) =
    "\p"
    "ゲージの赤色の部分は、犬が\r\n"
    "フリスビーをキャッチできな\r\n"
    "い距離です。{Press}\r\n"
    "うまくゲージの緑色の範囲内で\r\n"
    "距離を決めましょう。{Press}";

char const gText_Frisbee_ExplanationPractice[] ALIGN(4) =
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

char const gText_Frisbee_ExplanationTournament[] ALIGN(4) =
    "\p"
    "フリスビー大会では\r\n"
    "２回投げて、良いほうの記録を\r\n"
    "採用します。{Press}";

char const gText_Frisbee_ExplainAgain[] ALIGN(4) =
    "もう一度説明を見ますか？";

char const gText_Frisbee_ThrowAgain[] ALIGN(4) =
    "\p"
    "２投目を投げてください。{Press}";

char const gText_Frisbee_TournamentFinished[] ALIGN(4) =
    "\p"
    "競技が終了しました。{Press}";

char const gText_Frisbee_PlayAgain[] ALIGN(4) =
    "もう一度遊びますか？";

char const gText_Frisbee_DogNoLongerWantsToPlay[] ALIGN(4) =
    "\p"
    "今日はもうフリスビーで\r\n"
    "遊びたくないようだ…{Press}";

char const gText_Frisbee_FoundItem[] ALIGN(4) =
    "\p"
    "\xFFをみつけた！{Press}";

char const gText_Frisbee_FoundNothing[] ALIGN(4) =
    "\p"
    "なにもみつからなかった…{Press}";

char const gCppRuntimeBadAlloc_FrisbeeTextTrailer[] ALIGN(4) =
    "bad_alloc";
