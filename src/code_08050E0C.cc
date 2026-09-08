#include "ui_text_layout.hh"

EC void func_08050478(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3);
EC void func_08050664(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2);

// The original C++ runtime object is a normal ten-byte terminated string.
// Its following two zero bytes are supplied by the next object's four-byte
// alignment, rather than written into this string.
extern char const gCppRuntimeBadAlloc_PreUiTextLayout[] ALIGN(4) =
    "bad_alloc";

// Ten consecutive, independently terminated fixed-width Shift-JIS digit
// rows.  The three-byte row extent is real data, not a guessed zero-filled
// array: each row has a two-byte glyph followed by its C-string terminator.
extern char const gUnk_PreUiTextLayoutDigitRows[10][3] ALIGN(4) = {
    "０", "１", "２", "３", "４",
    "５", "６", "７", "８", "９",
};

// Their native consumers are still unknown; these labels deliberately state
// only the literal glyphs, not a guessed gameplay meaning.
extern char const gUnk_PreUiTextLayoutFullWidthSpace[] ALIGN(4) =
    "　";
extern char const gUnk_PreUiTextLayoutFullWidthHyphen[] ALIGN(4) =
    "－";

extern char const gCppRuntimeBadAlloc_PostUiTextLayoutGlyphRows[] ALIGN(4) =
    "bad_alloc";

UiTextLayoutPositionTable const gUiTextLayoutPositionTable = {
    0x00,
    {
        { 0x08, 0x09, 0x00, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x40, 0x41, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x42 },
        { 0x09, 0x0A, 0x00, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x42, 0x00, 0x00 },
    },
};

EC void func_08050E0C(void * const * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3)
{
    func_08050478(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1, arg_sp2, arg_sp3);
}

EC void func_08050E30(void * const * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2)
{
    func_08050664(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1, arg_sp2);
}
