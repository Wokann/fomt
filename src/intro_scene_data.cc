#include "intro_scene_text.hh"

EXTERN_C

// The concrete graphics payload formats remain raw.  These labels retain the
// original region-specific relocations while the loading order is expressed
// as ordinary C++ data.
extern u8 const gUnk_IntroSceneUnpackSource_000[];
extern u8 const gUnk_IntroSceneUnpackSource_001[];
extern u8 const gUnk_IntroSceneUnpackSource_002[];
extern u8 const gUnk_IntroSceneUnpackSource_003[];
extern u8 const gUnk_IntroSceneUnpackSource_004[];
extern u8 const gUnk_IntroSceneUnpackSource_005[];
extern u8 const gUnk_IntroSceneUnpackSource_006[];
extern u8 const gUnk_IntroSceneUnpackSource_007[];
extern u8 const gUnk_IntroSceneUnpackSource_008[];
extern u8 const gUnk_IntroSceneUnpackSource_009[];
extern u8 const gUnk_IntroSceneUnpackSource_010[];
extern u8 const gUnk_IntroSceneUnpackSource_011[];
extern u8 const gUnk_IntroSceneUnpackSource_012[];
extern u8 const gUnk_IntroSceneUnpackSource_013[];
extern u8 const gUnk_IntroSceneUnpackSource_014[];
extern u8 const gUnk_IntroSceneUnpackSource_015[];
extern u8 const gUnk_IntroSceneUnpackSource_016[];
extern u8 const gUnk_IntroSceneUnpackSource_017[];
extern u8 const gUnk_IntroSceneUnpackSource_018[];
extern u8 const gUnk_IntroSceneUnpackSource_019[];
extern u8 const gUnk_IntroSceneStartupUnpackSource_000[];
extern u8 const gUnk_IntroSceneStartupUnpackSource_001[];
extern u8 const gUnk_IntroSceneStartupUnpackSource_002[];
extern u8 const gUnk_IntroSceneStartupUnpackSource_003[];

// func_08001A90 unpacks these four payloads before the later Intro Scene
// sequence. The raw resource bytes retain region-specific labels in the
// asset container; this table preserves their original relocation order.
u8 const * const gIntroSceneStartupUnpackSources[]
    SECTION(".rodata.intro_scene_startup_resources") = {
        gUnk_IntroSceneStartupUnpackSource_000,
        gUnk_IntroSceneStartupUnpackSource_001,
        gUnk_IntroSceneStartupUnpackSource_002,
    gUnk_IntroSceneStartupUnpackSource_003,
};

// These runtime strings immediately follow the startup resource table in the
// original ROM.  C++ supplies each terminator; the linker supplies only the
// object-boundary padding required by the next four-byte-aligned object.
char const gCppRuntimeBadAlloc_IntroSceneStartup[]
    SECTION(".rodata.intro_scene_startup_resources") =
        "bad_alloc";

char const gCppRuntimeError_IntroSceneStartup[]
    SECTION(".rodata.intro_scene_startup_resources") ALIGN(4) =
        "Error";

u8 const * const gIntroSceneUnpackSources[] = {
    gUnk_IntroSceneUnpackSource_000,
    gUnk_IntroSceneUnpackSource_001,
    gUnk_IntroSceneUnpackSource_002,
    gUnk_IntroSceneUnpackSource_003,
    gUnk_IntroSceneUnpackSource_004,
    gUnk_IntroSceneUnpackSource_005,
    gUnk_IntroSceneUnpackSource_006,
    gUnk_IntroSceneUnpackSource_007,
    gUnk_IntroSceneUnpackSource_008,
    gUnk_IntroSceneUnpackSource_009,
    gUnk_IntroSceneUnpackSource_010,
    gUnk_IntroSceneUnpackSource_011,
    gUnk_IntroSceneUnpackSource_012,
    gUnk_IntroSceneUnpackSource_013,
    gUnk_IntroSceneUnpackSource_014,
    gUnk_IntroSceneUnpackSource_015,
    gUnk_IntroSceneUnpackSource_016,
    gUnk_IntroSceneUnpackSource_017,
    gUnk_IntroSceneUnpackSource_018,
    gUnk_IntroSceneUnpackSource_019,
};

EXTERN_C_END
