#include "intro_scene_data.hh"

EXTERN_C

#include FOMT_TEXT_INCLUDE(intro_scene_data_1.cc)

// Ten pairs of compressed 32x20 BG tilemaps, in the loader's exact order.
// They are map entries, not 4bpp pixels or OAM descriptors.
extern u8 const gIntroStoryFrame00Bg3Tilemap[];
extern u8 const gIntroStoryFrame00Bg2Tilemap[];
extern u8 const gIntroStoryFrame01Bg3Tilemap[];
extern u8 const gIntroStoryFrame01Bg2Tilemap[];
extern u8 const gIntroStoryFrame02Bg3Tilemap[];
extern u8 const gIntroStoryFrame02Bg2Tilemap[];
extern u8 const gIntroStoryFrame03Bg3Tilemap[];
extern u8 const gIntroStoryFrame03Bg2Tilemap[];
extern u8 const gIntroStoryFrame04Bg3Tilemap[];
extern u8 const gIntroStoryFrame04Bg2Tilemap[];
extern u8 const gIntroStoryFrame05Bg3Tilemap[];
extern u8 const gIntroStoryFrame05Bg2Tilemap[];
extern u8 const gIntroStoryFrame06Bg3Tilemap[];
extern u8 const gIntroStoryFrame06Bg2Tilemap[];
extern u8 const gIntroStoryFrame07Bg3Tilemap[];
extern u8 const gIntroStoryFrame07Bg2Tilemap[];
extern u8 const gIntroStoryFrame08Bg3Tilemap[];
extern u8 const gIntroStoryFrame08Bg2Tilemap[];
extern u8 const gIntroStoryFrame09Bg3Tilemap[];
extern u8 const gIntroStoryFrame09Bg2Tilemap[];
u8 const * const gIntroStoryTilemapSources[10][2] = {
    { gIntroStoryFrame00Bg3Tilemap, gIntroStoryFrame00Bg2Tilemap },
    { gIntroStoryFrame01Bg3Tilemap, gIntroStoryFrame01Bg2Tilemap },
    { gIntroStoryFrame02Bg3Tilemap, gIntroStoryFrame02Bg2Tilemap },
    { gIntroStoryFrame03Bg3Tilemap, gIntroStoryFrame03Bg2Tilemap },
    { gIntroStoryFrame04Bg3Tilemap, gIntroStoryFrame04Bg2Tilemap },
    { gIntroStoryFrame05Bg3Tilemap, gIntroStoryFrame05Bg2Tilemap },
    { gIntroStoryFrame06Bg3Tilemap, gIntroStoryFrame06Bg2Tilemap },
    { gIntroStoryFrame07Bg3Tilemap, gIntroStoryFrame07Bg2Tilemap },
    { gIntroStoryFrame08Bg3Tilemap, gIntroStoryFrame08Bg2Tilemap },
    { gIntroStoryFrame09Bg3Tilemap, gIntroStoryFrame09Bg2Tilemap },
};

EXTERN_C_END

// The childhood-visit dialogue follows the tilemap source table in the regional ROMs.
#include FOMT_TEXT_INCLUDE(intro_scene_data_2.cc)

EXTERN_C

#include FOMT_TEXT_INCLUDE(intro_scene_data_3.cc)

EXTERN_C_END
