#include "intro_scene_startup.hh"

EXTERN_C

// InitializeIntroSceneSequenceResources unpacks these four payloads for
// the opening sequence. The raw resource bytes retain region-specific labels in the
// asset container; this table preserves their original relocation order.
u8 const * const gIntroSceneStartupUnpackSources[] = {
    gUnk_IntroSceneStartupUnpackSource_000,
    gUnk_IntroSceneStartupUnpackSource_001,
    gUnk_IntroSceneStartupUnpackSource_002,
    gUnk_IntroSceneStartupUnpackSource_003,
};

EXTERN_C_END

// These runtime strings immediately follow the startup resource table in the
// original ROM and are selected from the regional text source at this exact
// physical point.
#include FOMT_TEXT_INCLUDE(intro_scene_startup.cc)
