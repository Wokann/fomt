#include "link_communication_text.hh"

char const gText_LinkCommunication_Waiting[] =
    "通信待機中なのよー。\r\n"
    "相手側の準備をしてね。\r\n"
    "（Ｂボタンでキャンセルよ♡）";

char const gText_LinkCommunication_SendingGameData[] =
    "ゲームデータを送ってるわよ。";

char const gText_LinkCommunication_TestingConnection[] =
    "通信できるか確認中～。";

char const gText_LinkCommunication_CannotResendPreviousData[] =
    "前のゲームデータとは、\r\n"
    "通信できなくなるのよ。{Press}";

char const gText_LinkCommunication_ProceedQuestion[] =
    "いい？";

char const gText_LinkCommunication_Yes[] =
    "はい";

char const gText_LinkCommunication_No[] =
    "いいえ";

char const gText_LinkCommunication_WaitingForOtherPlayer[] =
    "相手の決定待ちなのよー。\r\n"
    "（Ｂボタンでキャンセルよ♡）";

char const gText_LinkCommunication_NowSendingData[] =
    "データを送受信中だよ";

char const gText_LinkCommunication_DataExchangeFailed[] =
    "データ交換に失敗したみたい。\r\n"
    "もう一度やってみる？{Press}";

char const gText_LinkCommunication_QuitCommunication[] =
    "じゃ、一旦通信をやめるわよ。{Press}";

char const gText_LinkCommunication_OtherPlayerCanceled[] =
    "あらら？\r\n"
    "相手側が中止しちゃった。{Press}";

char const gText_LinkCommunication_IncompatibleGameData[] =
    "あらあら？\r\n"
    "このデータとゲームキューブの\r\n"
    "『牧場物語』のデータが合わな{Press}\r\n"
    "かったみたいね。{Press}";

char const gText_LinkCommunication_ExchangeRestriction[] =
    "このデータと通信できるのは、\r\n"
    "ゲームキューブの『牧場物語』\r\n"
    "で、他のゲームと通信した事の{Press}\r\n"
    "ないデータだけなの。{Press}";

char const gText_LinkCommunication_ActionQuestion[] =
    "じゃ、通信を始めましょうか？";

char const gText_LinkCommunication_Declined[] =
    "あら？\r\n"
    "通信しないの？\r\n"
    "残念ねー。{Press}";

char const gText_LinkCommunication_Complete[] =
    "通信が終わったわよ。{Press}";

u16 const gLinkCommunicationCharacterCodeTable[]
    SECTION(".rodata.link_communication_character_codes") ALIGN(2) =
    FOMT_GLYPH_TEXT(
        "　あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほま"
        "みむめもやゆよらりるれろわをんぁぃぅぇぉっゃゅょがぎぐげござじず"
        "ぜぞだぢづでどばびぶべぼぱぴぷぺぽアイウエオカキクケコサシスセソ"
        "タチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワヲンァ"
        "ィゥェォッャュョガギグゲゴザジズゼゾダヂヅデドバビブベボパピプペ"
        "ポーＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺａｂｃｄ"
        "ｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ０１２３４５６７８９"
        "！％＆’（）～「」＜＞．？·＋－×＊／○☆★♪♂♀※"
    );
