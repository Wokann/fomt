#ifndef MAP_TERRAIN_HH
#define MAP_TERRAIN_HH

#include "prelude.h"

// Rectangle patches copy all four bytes. Plot refreshes change bit 0 and
// the upper halfword's bits 1..15; rectangle blocking checks bits 0 and 1.
struct FieldRenderTileAttributes
{
    bool unk_00_00 : 1;
    bool unk_00_01 : 1;
    u32 unk_00_02 : 14;
    u16 unk_02_00 : 1;
    u16 unk_02_01 : 15;
};

typedef char FieldRenderTileAttributesSizeCheck[sizeof(FieldRenderTileAttributes) == 4 ? 1 : -1];

// A direct tile grid or an indexed view of a table of tile attributes.
// This is a borrowed view; it does not own either input buffer.
struct MapTerrainView
{
    MapTerrainView(FieldRenderTileAttributes const * attributes, u32 width, u32 height)
        : attributes(attributes), indices(nullptr), width(width), height(height) {}

    MapTerrainView(FieldRenderTileAttributes const * attributes, u8 const * indices,
        u32 width, u32 height)
        : attributes(attributes), indices(indices), width(width), height(height) {}

    FieldRenderTileAttributes const * attributes;
    u8 const * indices;
    u16 width;
    u16 height;
};

typedef char MapTerrainViewSizeCheck[sizeof(MapTerrainView) == 12 ? 1 : -1];
typedef char MapTerrainViewIndicesCheck[offsetof(MapTerrainView, indices) == 4 ? 1 : -1];
typedef char MapTerrainViewWidthCheck[offsetof(MapTerrainView, width) == 8 ? 1 : -1];
typedef char MapTerrainViewHeightCheck[offsetof(MapTerrainView, height) == 10 ? 1 : -1];

struct Box;

extern "C" {

// Clip only the requested pixel-distance limits; null directions are not scanned.
// Stop at the first blocked tile or map edge before an existing limit.
// As in the original, callers supply a valid terrain view and collision box.
void ClipMapTerrainMovement(MapTerrainView const & map, Box const & box,
    i32 * down, i32 * up, i32 * left, i32 * right);
// The alternate scan blocks only on bit 0; bit 1 is intentionally ignored.
void ClipMapTerrainMovementIgnoringFlag1(MapTerrainView const & map, Box const & box,
    i32 * down, i32 * up, i32 * left, i32 * right);
bool IsMapTerrainBoxBlocked(MapTerrainView const & map, Box const & box);
// Require bit 1 on every tile intersecting the inclusive 12x12-pixel
// footprint [x-6,x+5] by [y-8,y+3]. Invalid/null views return false.
// Shared native assembly is retained until the C++ implementation matches.
bool IsMapTerrainFlag1Footprint(MapTerrainView const & map, i32 x, i32 y);


// Terrain dictionaries and row-major index grids in physical ROM order.
// Descriptor widths/heights remain format constraints; some seasonal patches
// intentionally read one fewer row from a shared grid.
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_146[];
extern u8 const gUnk_FieldRenderResource_147[][17];
extern FieldRenderTileAttributes const gUnk_MapDataResource_098[];
extern u8 const gUnk_MapDataResource_099[][150];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_120[];
extern u8 const gUnk_FieldRenderResource_121[][42];
extern FieldRenderTileAttributes const gUnk_MapDataResource_247[];
extern u8 const gUnk_MapDataResource_248[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_062[];
extern u8 const gUnk_MapDataResource_063[][64];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_137[];
extern u8 const gUnk_FieldRenderResource_138[][22];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_130[];
extern u8 const gUnk_FieldRenderResource_131[][17];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_141[];
extern u8 const gUnk_FieldRenderResource_142[][6];
extern FieldRenderTileAttributes const gUnk_MapDataResource_271[];
extern u8 const gUnk_MapDataResource_272[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_276[];
extern u8 const gUnk_MapDataResource_277[][30];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_212[];
extern u8 const gUnk_FieldRenderResource_213[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_208[];
extern u8 const gUnk_FieldRenderResource_209[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_198[];
extern u8 const gUnk_MapDataResource_199[][46];
extern FieldRenderTileAttributes const gUnk_MapDataResource_181[];
extern u8 const gUnk_MapDataResource_182[][30];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_041[];
extern u8 const gUnk_FieldRenderResource_042[][17];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_033[];
extern u8 const gUnk_FieldRenderResource_034[][9];
extern FieldRenderTileAttributes const gUnk_MapDataResource_006[];
extern u8 const gUnk_MapDataResource_007[][128];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_014[];
extern u8 const gUnk_FieldRenderResource_015[][24];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_008[];
extern u8 const gUnk_FieldRenderResource_009[][16];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_002[];
extern u8 const gUnk_FieldRenderResource_003[][8];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_026[];
extern u8 const gUnk_FieldRenderResource_027[][22];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_020[];
extern u8 const gUnk_FieldRenderResource_021[][12];
extern FieldRenderTileAttributes const gUnk_MapDataResource_087[];
extern u8 const gUnk_MapDataResource_088[][128];
extern FieldRenderTileAttributes const gUnk_MapDataResource_312[];
extern u8 const gUnk_MapDataResource_313[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_171[];
extern u8 const gUnk_MapDataResource_172[][36];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_155[];
extern u8 const gUnk_FieldRenderResource_156[][2];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_220[];
extern u8 const gUnk_FieldRenderResource_221[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_164[];
extern u8 const gUnk_MapDataResource_165[][36];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_152[];
extern u8 const gUnk_FieldRenderResource_153[][2];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_167[];
extern u8 const gUnk_FieldRenderResource_168[][9];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_161[];
extern u8 const gUnk_FieldRenderResource_162[][9];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_164[];
extern u8 const gUnk_FieldRenderResource_165[][9];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_108[];
extern u8 const gUnk_FieldRenderResource_109[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_232[];
extern u8 const gUnk_MapDataResource_233[][42];
extern FieldRenderTileAttributes const gUnk_MapDataResource_227[];
extern u8 const gUnk_MapDataResource_228[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_326[];
extern u8 const gUnk_MapDataResource_327[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_188[];
extern u8 const gUnk_MapDataResource_189[][46];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_204[];
extern u8 const gUnk_FieldRenderResource_205[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_200[];
extern u8 const gUnk_FieldRenderResource_201[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_193[];
extern u8 const gUnk_MapDataResource_194[][46];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_180[];
extern u8 const gUnk_FieldRenderResource_181[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_147[];
extern u8 const gUnk_MapDataResource_148[][46];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_188[];
extern u8 const gUnk_FieldRenderResource_189[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_184[];
extern u8 const gUnk_FieldRenderResource_185[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_152[];
extern u8 const gUnk_MapDataResource_153[][46];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_171[];
extern u8 const gUnk_FieldRenderResource_172[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_196[];
extern u8 const gUnk_FieldRenderResource_197[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_192[];
extern u8 const gUnk_FieldRenderResource_193[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_157[];
extern u8 const gUnk_MapDataResource_158[][46];
extern FieldRenderTileAttributes const gUnk_MapDataResource_215[];
extern u8 const gUnk_MapDataResource_216[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_220[];
extern u8 const gUnk_MapDataResource_221[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_205[];
extern u8 const gUnk_MapDataResource_206[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_210[];
extern u8 const gUnk_MapDataResource_211[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_319[];
extern u8 const gUnk_MapDataResource_320[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_307[];
extern u8 const gUnk_MapDataResource_308[][30];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_104[];
extern u8 const gUnk_FieldRenderResource_105[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_090[];
extern u8 const gUnk_FieldRenderResource_091[][6];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_100[];
extern u8 const gUnk_FieldRenderResource_101[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_084[];
extern u8 const gUnk_FieldRenderResource_085[][10];
extern FieldRenderTileAttributes const gUnk_MapDataResource_264[];
extern u8 const gUnk_MapDataResource_265[][59];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_097[];
extern u8 const gUnk_FieldRenderResource_098[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_259[];
extern u8 const gUnk_MapDataResource_260[][45];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_072[];
extern u8 const gUnk_FieldRenderResource_073[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_080[];
extern u8 const gUnk_FieldRenderResource_081[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_076[];
extern u8 const gUnk_FieldRenderResource_077[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_060[];
extern u8 const gUnk_FieldRenderResource_061[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_056[];
extern u8 const gUnk_FieldRenderResource_057[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_068[];
extern u8 const gUnk_FieldRenderResource_069[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_064[];
extern u8 const gUnk_FieldRenderResource_065[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_087[];
extern u8 const gUnk_FieldRenderResource_088[][6];
extern FieldRenderTileAttributes const gUnk_MapDataResource_254[];
extern u8 const gUnk_MapDataResource_255[][30];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_052[];
extern u8 const gUnk_FieldRenderResource_053[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_048[];
extern u8 const gUnk_FieldRenderResource_049[][4];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_094[];
extern u8 const gUnk_FieldRenderResource_095[][2];
extern FieldRenderTileAttributes const gUnk_MapDataResource_076[];
extern u8 const gUnk_MapDataResource_077[][64];
extern FieldRenderTileAttributes const gUnk_MapDataResource_034[];
extern u8 const gUnk_MapDataResource_035[][176];
extern FieldRenderTileAttributes const gUnk_MapDataResource_125[];
extern u8 const gUnk_MapDataResource_126[][30];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_174[];
extern u8 const gUnk_FieldRenderResource_175[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_130[];
extern u8 const gUnk_MapDataResource_131[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_343[];
extern u8 const gUnk_MapDataResource_344[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_348[];
extern u8 const gUnk_MapDataResource_349[][60];
extern FieldRenderTileAttributes const gUnk_MapDataResource_353[];
extern u8 const gUnk_MapDataResource_354[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_358[];
extern u8 const gUnk_MapDataResource_359[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_363[];
extern u8 const gUnk_MapDataResource_364[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_368[];
extern u8 const gUnk_MapDataResource_369[][30];
extern FieldRenderTileAttributes const gUnk_FarmHouseVisualResource_002[];
extern u8 const gUnk_FarmHouseVisualResource_003[][6];
extern FieldRenderTileAttributes const gUnk_MapDataResource_020[];
extern u8 const gUnk_MapDataResource_021[][60];
extern FieldRenderTileAttributes const gUnk_FarmHouseVisualResource_008[];
extern u8 const gUnk_FarmHouseVisualResource_009[][21];
extern FieldRenderTileAttributes const gUnk_FarmHouseVisualResource_032[];
extern u8 const gUnk_FarmHouseVisualResource_033[][4];
extern FieldRenderTileAttributes const gUnk_FarmHouseVisualResource_039[];
extern u8 const gUnk_FarmHouseVisualResource_040[][12];
extern FieldRenderTileAttributes const gUnk_FarmHouseVisualResource_020[];
extern u8 const gUnk_FarmHouseVisualResource_021[][13];
extern FieldRenderTileAttributes const gUnk_FarmHouseVisualResource_026[];
extern u8 const gUnk_FarmHouseVisualResource_027[][24];
extern FieldRenderTileAttributes const gUnk_MapDataResource_135[];
extern u8 const gUnk_MapDataResource_136[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_140[];
extern u8 const gUnk_MapDataResource_141[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_331[];
extern u8 const gUnk_MapDataResource_332[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_176[];
extern u8 const gUnk_MapDataResource_177[][30];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_116[];
extern u8 const gUnk_FieldRenderResource_117[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_242[];
extern u8 const gUnk_MapDataResource_243[][76];
extern FieldRenderTileAttributes const gUnk_MapDataResource_237[];
extern u8 const gUnk_MapDataResource_238[][46];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_112[];
extern u8 const gUnk_FieldRenderResource_113[][3];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_216[];
extern u8 const gUnk_FieldRenderResource_217[][3];
extern FieldRenderTileAttributes const gUnk_MapDataResource_295[];
extern u8 const gUnk_MapDataResource_296[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_048[];
extern u8 const gUnk_MapDataResource_049[][173];
extern FieldRenderTileAttributes const gUnk_FieldRenderResource_124[];
extern u8 const gUnk_FieldRenderResource_125[][14];
extern FieldRenderTileAttributes const gUnk_MapDataResource_112[];
extern u8 const gUnk_MapDataResource_113[][60];
extern FieldRenderTileAttributes const gUnk_MapDataResource_336[];
extern u8 const gUnk_MapDataResource_337[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_372[];
extern u8 const gUnk_MapDataResource_373[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_300[];
extern u8 const gUnk_MapDataResource_301[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_283[];
extern u8 const gUnk_MapDataResource_284[][30];
extern FieldRenderTileAttributes const gUnk_MapDataResource_288[];
extern u8 const gUnk_MapDataResource_289[][30];

}

#endif // MAP_TERRAIN_HH
