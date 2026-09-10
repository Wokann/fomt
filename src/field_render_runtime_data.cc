#include "field_render_runtime_data.hh"

FieldRenderSeasonalRecordRange const gFieldRenderSeasonalRecordRanges[NUM_SEASONS] = {
        { 0x00, 0x1A },
        { 0x1A, 0x3A },
        { 0x3A, 0x5E },
        { 0x5E, 0x60 },
    };


// func_080AAF28 indexes this as [native_record_index][variant].  The two
// columns are both consumed by the native field-render path, but their
// gameplay roles remain undecoded.
u16 const gUnk_FieldRenderLookupValues[18][2] = {
        { 0x0032, 0x0033 },
        { 0x0135, 0x0136 },
        { 0x0132, 0x0133 },
        { 0x00F5, 0x00F6 },
        { 0x0119, 0x011A },
        { 0x0041, 0x0042 },
        { 0x00D8, 0x00D9 },
        { 0x0178, 0x0179 },
        { 0x01EA, 0x01EB },
        { 0x0142, 0x0143 },
        { 0x0165, 0x0166 },
        { 0x0100, 0x0101 },
        { 0x01D9, 0x01DA },
        { 0x0008, 0x0009 },
        { 0x012F, 0x0130 },
        { 0x0151, 0x0152 },
        { 0x0110, 0x0111 },
        { 0x01C4, 0x01C5 },
    };

// These are distinct compiler-runtime objects in the original layout.  Their
// ordinal names describe physical order only; no owning native C++ object has
// been recovered yet.
char const gCppRuntimeBadAlloc_FieldRenderRuntime00[] =
        "bad_alloc";
char const gCppRuntimeBadAlloc_FieldRenderRuntime01[] =
        "bad_alloc";
char const gCppRuntimeBadAlloc_FieldRenderRuntime02[] =
        "bad_alloc";
char const gCppRuntimeBadAlloc_FieldRenderRuntime03[] =
        "bad_alloc";
char const gCppRuntimeBadAlloc_FieldRenderRuntime04[] =
        "bad_alloc";
char const gCppRuntimeError_FieldRenderRuntime[] =
        "Error";
char const gText_FieldRenderFallbackNone[] =
#if defined(REGION_JP)
        "なし";
#else
        "N/A ";
#endif
char const gCppRuntimeBadAlloc_FieldRenderRuntime05[] =
        "bad_alloc";

// func_080ADBB4 uses this as a sorted lower-bound range.  Its key is derived
// from a packed native field value; the values' gameplay role is not decoded
// yet.  The JP release has two fewer entries.
u8 const gUnk_FieldRenderSortedValues[] = {
#if defined(REGION_JP)
        0x00, 0x0D, 0x10, 0x11, 0x14, 0x15, 0x1D, 0x1E, 0x23,
        0x24, 0x30, 0x31, 0x35, 0x3D, 0x3E, 0x43, 0x44, 0x48,
        0x4C, 0x4D, 0x4F, 0x50, 0x67, 0x71, 0x77,
#else
        0x00, 0x0D, 0x10, 0x11, 0x14, 0x15, 0x1D, 0x1E, 0x23,
        0x24, 0x30, 0x31, 0x35, 0x3D, 0x3E, 0x43, 0x44, 0x48,
        0x4C, 0x4D, 0x4F, 0x50, 0x59, 0x67, 0x71, 0x72, 0x77,
#endif
    };

char const gCppRuntimeBadAlloc_FieldRenderSortedValuesFirst[] =
        "bad_alloc";
char const gCppRuntimeBadAlloc_FieldRenderSortedValuesSecond[] =
        "bad_alloc";

// These value groups are copied directly by still-native callers.  Their
// high-level gameplay roles remain unknown, so the names identify only the
// consuming function and their fixed layout.
u32 const gUnk_080AE894InitialValues[5] = {
        0x48, 0x60, 0x78, 0x90, 0xA8,
    };
u32 const gUnk_080AE894LayoutValues[10] = {
        0x48, 0x5E, 0x60, 0x5E, 0x78,
        0x5E, 0x90, 0x5E, 0xA8, 0x5E,
    };

// func_080B0708 copies exactly two bytes from this object.  The selected
// region stores its original single glyph: ASCII zero in US and full-width
// zero in JP.
char const gText_080B0708DefaultGlyph[] =
#if defined(REGION_JP)
        "０";
#else
        "0";
#endif

u32 const gUnk_080B09B0IndexValues[7] = {
        4, 0, 1, 6, 3, 2, 5,
    };

u32 const gUnk_080B0BB8FirstValues[5] = {
        0x3C, 0x1E, 0x3C, 0x1E, 0x3C,
    };
u32 const gUnk_080B0BB8SecondValues[5] = {
        4, 0, 2, 1, 3,
    };
