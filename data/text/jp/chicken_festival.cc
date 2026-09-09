#include "chicken_festival_text.hh"

#ifndef FOMT_CHICKEN_FESTIVAL_TEXT_ATTRIBUTE
#define FOMT_CHICKEN_FESTIVAL_TEXT_ATTRIBUTE
#define FOMT_CHICKEN_FESTIVAL_TEXT_ATTRIBUTE_LOCAL
#endif

// Direct-indexed chicken-festival contestant names. The fixed 13-byte rows
// retain the original JP display-space padding.

char const gText_ChickenFestival_ContestantNames[20][13] ALIGN(1) FOMT_CHICKEN_FESTIVAL_TEXT_ATTRIBUTE = {
    "ここりターン",
    "こじろー",
    "だーく",
    "バクバク",
    "ピヨリン",
    "ピヨたろう",
    "ヨチスケ",
    "へっぽこ",
    "カタきち",
    "とさのすけ",
    "ぴよまろ",
    "しんえもん",
    "キング",
    "テン",
    "フランソワ",
    "ピッピヨ",
    "コテツ",
    "ライライ",
    "コッケ",
    "スイート"
};

#ifdef FOMT_CHICKEN_FESTIVAL_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_CHICKEN_FESTIVAL_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_CHICKEN_FESTIVAL_TEXT_ATTRIBUTE
#endif
