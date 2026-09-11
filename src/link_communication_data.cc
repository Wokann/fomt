#include "link_communication.hh"
#include "link_communication_text.hh"

// Keep the selected regional dialog immediately before its native packet
// tables.  The linker gives this whole source object one bounded ROM island.
#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(link_communication.cc)
#else
#include FOMT_TEXT_INCLUDE(link_communication.cc)
#endif

EXTERN_C

LinkCommunicationDataRecord const gUnk_081007AC[] = {
    { 0x0000, 0x001A, 0x00000000 },
    { 0x0000, 0x001B, 0x00000000 },
    { 0x0000, 0x001C, 0x00000000 },
    { 0x0000, 0x001D, 0x00000000 },
    { 0x0000, 0x001E, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_081007D4[] = {
    { 0x0000, 0x001F, 0x00000000 },
    { 0x0000, 0x0020, 0x00000000 },
    { 0x0000, 0x0021, 0x00000000 },
    { 0x0000, 0x0022, 0x00000000 },
    { 0x0000, 0x0023, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_081007FC[] = {
    { 0x0000, 0x0024, 0x00000000 },
    { 0x0000, 0x0025, 0x00000000 },
    { 0x0000, 0x0026, 0x00000000 },
    { 0x0000, 0x0027, 0x00000000 },
    { 0x0000, 0x0028, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_08100824[] = {
    { 0x0000, 0x0029, 0x00000000 },
    { 0x0000, 0x002A, 0x00000000 },
    { 0x0000, 0x002B, 0x00000000 },
    { 0x0000, 0x002C, 0x00000000 },
    { 0x0000, 0x002D, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_0810084C[] = {
    { 0x0000, 0x002E, 0x00000000 },
    { 0x0000, 0x002F, 0x00000000 },
    { 0x0000, 0x0030, 0x00000000 },
    { 0x0000, 0x0031, 0x00000000 },
    { 0x0000, 0x0032, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_08100874[] = {
    { 0x0000, 0x0033, 0x00000000 },
    { 0x0000, 0x0034, 0x00000000 },
    { 0x0000, 0x0035, 0x00000000 },
    { 0x0000, 0x0036, 0x00000000 },
    { 0x0000, 0x0037, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_0810089C[] = {
    { 0x0000, 0x0038, 0x00000000 },
    { 0x0000, 0x0039, 0x00000000 },
    { 0x0000, 0x003A, 0x00000000 },
    { 0x0000, 0x003B, 0x00000000 },
    { 0x0000, 0x003C, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_081008C4[] = {
    { 0x0000, 0x003D, 0x00000000 },
    { 0x0000, 0x003E, 0x00000000 },
    { 0x0000, 0x003F, 0x00000000 },
    { 0x0000, 0x0040, 0x00000000 },
    { 0x0000, 0x0041, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_081008EC[] = {
    { 0x0000, 0x001A, 0x00000000 },
    { 0x0000, 0x001B, 0x00000000 },
    { 0x0000, 0x001C, 0x00000000 },
    { 0x0000, 0x001D, 0x00000000 },
    { 0x0000, 0x001E, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_08100914[] = {
    { 0x0000, 0x001F, 0x00000000 },
    { 0x0000, 0x0020, 0x00000000 },
    { 0x0000, 0x0021, 0x00000000 },
    { 0x0000, 0x0022, 0x00000000 },
    { 0x0000, 0x0023, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_0810093C[] = {
    { 0x0000, 0x0024, 0x00000000 },
    { 0x0000, 0x0025, 0x00000000 },
    { 0x0000, 0x0026, 0x00000000 },
    { 0x0000, 0x0027, 0x00000000 },
    { 0x0000, 0x0028, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_08100964[] = {
    { 0x0000, 0x0029, 0x00000000 },
    { 0x0000, 0x002A, 0x00000000 },
    { 0x0000, 0x002B, 0x00000000 },
    { 0x0000, 0x002C, 0x00000000 },
    { 0x0000, 0x002D, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_0810098C[] = {
    { 0x0000, 0x002E, 0x00000000 },
    { 0x0000, 0x002F, 0x00000000 },
    { 0x0000, 0x0030, 0x00000000 },
    { 0x0000, 0x0031, 0x00000000 },
    { 0x0000, 0x0032, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_081009B4[] = {
    { 0x0000, 0x0033, 0x00000000 },
    { 0x0000, 0x0034, 0x00000000 },
    { 0x0000, 0x0035, 0x00000000 },
    { 0x0000, 0x0036, 0x00000000 },
    { 0x0000, 0x0037, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_081009DC[] = {
    { 0x0000, 0x0038, 0x00000000 },
    { 0x0000, 0x0039, 0x00000000 },
    { 0x0000, 0x003A, 0x00000000 },
    { 0x0000, 0x003B, 0x00000000 },
    { 0x0000, 0x003C, 0x00000000 },
};

LinkCommunicationDataRecord const gUnk_08100A04[] = {
    { 0x0000, 0x003D, 0x00000000 },
    { 0x0000, 0x003E, 0x00000000 },
    { 0x0000, 0x003F, 0x00000000 },
    { 0x0000, 0x0040, 0x00000000 },
    { 0x0000, 0x0041, 0x00000000 },
};

char const gCppRuntimeBadAlloc_LinkCommunication[] =
    "bad_alloc";

EXTERN_C_END

#if defined(REGION_JP)
u16 const gLinkCommunicationCharacterCodeTable[] ALIGN(2) =
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

#else
// The extended single-byte game-font glyphs have no independently verified
// Unicode names yet, so keep their proven ROM codes explicit.
u8 const gLinkCommunicationCharacterCodeTable[] ALIGN(2) =
    FOMT_GLYPH_TEXT(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789!%&\xBF()~\xA2\xA3<>.?\xA5+-x*/o\xB6\xB7\xB3\xB2\xB1\xC0"
        "\xBB\xBC\xBD\xBE\xC1\xC2\xC3 \xB4"
    );
#endif

EXTERN_C

// The native link packet constructors load the first word of each object.
// The region-specific fourth character is the retail game-code suffix.
LinkCommunicationGameCode const gLinkCommunicationGameCodeA4N = {
#if defined(REGION_JP)
    0x4A4E3441,
#else
    0x454E3441,
#endif
    0x00000000,
};

LinkCommunicationGameCode const gLinkCommunicationGameCodeGYW = {
#if defined(REGION_JP)
    0x4A575947,
#else
    0x45575947,
#endif
    0x00000000,
};

char const gCppRuntimeBadAlloc_LinkCommunicationA4N[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_LinkCommunicationGYW[] =
    "bad_alloc";

EXTERN_C_END
