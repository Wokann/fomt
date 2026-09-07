#include "map_data.hh"

EXTERN_C

// These labels point into still-raw map assets.  Their payload types are not decoded yet.
extern u8 const gUnk_MapDataResource_000[];
extern u8 const gUnk_MapDataResource_001[];
extern u8 const gUnk_MapDataResource_002[];
extern u8 const gUnk_MapDataResource_003[];
extern u8 const gUnk_MapDataResource_004[];
extern u8 const gUnk_MapDataResource_005[];
extern u8 const gUnk_MapDataResource_006[];
extern u8 const gUnk_MapDataResource_007[];
extern u8 const gUnk_MapDataResource_008[];
extern u8 const gUnk_MapDataResource_009[];
extern u8 const gUnk_MapDataResource_010[];
extern u8 const gUnk_MapDataResource_011[];
extern u8 const gUnk_MapDataResource_012[];
extern u8 const gUnk_MapDataResource_013[];
extern u8 const gUnk_MapDataResource_014[];
extern u8 const gUnk_MapDataResource_015[];
extern u8 const gUnk_MapDataResource_016[];
extern u8 const gUnk_MapDataResource_017[];
extern u8 const gUnk_MapDataResource_018[];
extern u8 const gUnk_MapDataResource_019[];
extern u8 const gUnk_MapDataResource_020[];
extern u8 const gUnk_MapDataResource_021[];
extern u8 const gUnk_MapDataResource_022[];
extern u8 const gUnk_MapDataResource_023[];
extern u8 const gUnk_MapDataResource_024[];
extern u8 const gUnk_MapDataResource_025[];
extern u8 const gUnk_MapDataResource_026[];
extern u8 const gUnk_MapDataResource_027[];
extern u8 const gUnk_MapDataResource_028[];
extern u8 const gUnk_MapDataResource_029[];
extern u8 const gUnk_MapDataResource_030[];
extern u8 const gUnk_MapDataResource_031[];
extern u8 const gUnk_MapDataResource_032[];
extern u8 const gUnk_MapDataResource_033[];
extern u8 const gUnk_MapDataResource_034[];
extern u8 const gUnk_MapDataResource_035[];
extern u8 const gUnk_MapDataResource_036[];
extern u8 const gUnk_MapDataResource_037[];
extern u8 const gUnk_MapDataResource_038[];
extern u8 const gUnk_MapDataResource_039[];
extern u8 const gUnk_MapDataResource_040[];
extern u8 const gUnk_MapDataResource_041[];
extern u8 const gUnk_MapDataResource_042[];
extern u8 const gUnk_MapDataResource_043[];
extern u8 const gUnk_MapDataResource_044[];
extern u8 const gUnk_MapDataResource_045[];
extern u8 const gUnk_MapDataResource_046[];
extern u8 const gUnk_MapDataResource_047[];
extern u8 const gUnk_MapDataResource_048[];
extern u8 const gUnk_MapDataResource_049[];
extern u8 const gUnk_MapDataResource_050[];
extern u8 const gUnk_MapDataResource_051[];
extern u8 const gUnk_MapDataResource_052[];
extern u8 const gUnk_MapDataResource_053[];
extern u8 const gUnk_MapDataResource_054[];
extern u8 const gUnk_MapDataResource_055[];
extern u8 const gUnk_MapDataResource_056[];
extern u8 const gUnk_MapDataResource_057[];
extern u8 const gUnk_MapDataResource_058[];
extern u8 const gUnk_MapDataResource_059[];
extern u8 const gUnk_MapDataResource_060[];
extern u8 const gUnk_MapDataResource_061[];
extern u8 const gUnk_MapDataResource_062[];
extern u8 const gUnk_MapDataResource_063[];
extern u8 const gUnk_MapDataResource_064[];
extern u8 const gUnk_MapDataResource_065[];
extern u8 const gUnk_MapDataResource_066[];
extern u8 const gUnk_MapDataResource_067[];
extern u8 const gUnk_MapDataResource_068[];
extern u8 const gUnk_MapDataResource_069[];
extern u8 const gUnk_MapDataResource_070[];
extern u8 const gUnk_MapDataResource_071[];
extern u8 const gUnk_MapDataResource_072[];
extern u8 const gUnk_MapDataResource_073[];
extern u8 const gUnk_MapDataResource_074[];
extern u8 const gUnk_MapDataResource_075[];
extern u8 const gUnk_MapDataResource_076[];
extern u8 const gUnk_MapDataResource_077[];
extern u8 const gUnk_MapDataResource_078[];
extern u8 const gUnk_MapDataResource_079[];
extern u8 const gUnk_MapDataResource_080[];
extern u8 const gUnk_MapDataResource_081[];
extern u8 const gUnk_MapDataResource_082[];
extern u8 const gUnk_MapDataResource_083[];
extern u8 const gUnk_MapDataResource_084[];
extern u8 const gUnk_MapDataResource_085[];
extern u8 const gUnk_MapDataResource_086[];
extern u8 const gUnk_MapDataResource_087[];
extern u8 const gUnk_MapDataResource_088[];
extern u8 const gUnk_MapDataResource_089[];
extern u8 const gUnk_MapDataResource_090[];
extern u8 const gUnk_MapDataResource_091[];
extern u8 const gUnk_MapDataResource_092[];
extern u8 const gUnk_MapDataResource_093[];
extern u8 const gUnk_MapDataResource_094[];
extern u8 const gUnk_MapDataResource_095[];
extern u8 const gUnk_MapDataResource_096[];
extern u8 const gUnk_MapDataResource_097[];
extern u8 const gUnk_MapDataResource_098[];
extern u8 const gUnk_MapDataResource_099[];
extern u8 const gUnk_MapDataResource_100[];
extern u8 const gUnk_MapDataResource_101[];
extern u8 const gUnk_MapDataResource_102[];
extern u8 const gUnk_MapDataResource_103[];
extern u8 const gUnk_MapDataResource_104[];
extern u8 const gUnk_MapDataResource_105[];
extern u8 const gUnk_MapDataResource_106[];
extern u8 const gUnk_MapDataResource_107[];
extern u8 const gUnk_MapDataResource_108[];
extern u8 const gUnk_MapDataResource_109[];
extern u8 const gUnk_MapDataResource_110[];
extern u8 const gUnk_MapDataResource_111[];
extern u8 const gUnk_MapDataResource_112[];
extern u8 const gUnk_MapDataResource_113[];
extern u8 const gUnk_MapDataResource_114[];
extern u8 const gUnk_MapDataResource_115[];
extern u8 const gUnk_MapDataResource_116[];
extern u8 const gUnk_MapDataResource_117[];
extern u8 const gUnk_MapDataResource_118[];
extern u8 const gUnk_MapDataResource_119[];
extern u8 const gUnk_MapDataResource_120[];
extern u8 const gUnk_MapDataResource_121[];
extern u8 const gUnk_MapDataResource_122[];
extern u8 const gUnk_MapDataResource_123[];
extern u8 const gUnk_MapDataResource_124[];
extern u8 const gUnk_MapDataResource_125[];
extern u8 const gUnk_MapDataResource_126[];
extern u8 const gUnk_MapDataResource_127[];
extern u8 const gUnk_MapDataResource_128[];
extern u8 const gUnk_MapDataResource_129[];
extern u8 const gUnk_MapDataResource_130[];
extern u8 const gUnk_MapDataResource_131[];
extern u8 const gUnk_MapDataResource_132[];
extern u8 const gUnk_MapDataResource_133[];
extern u8 const gUnk_MapDataResource_134[];
extern u8 const gUnk_MapDataResource_135[];
extern u8 const gUnk_MapDataResource_136[];
extern u8 const gUnk_MapDataResource_137[];
extern u8 const gUnk_MapDataResource_138[];
extern u8 const gUnk_MapDataResource_139[];
extern u8 const gUnk_MapDataResource_140[];
extern u8 const gUnk_MapDataResource_141[];
extern u8 const gUnk_MapDataResource_142[];
extern u8 const gUnk_MapDataResource_143[];
extern u8 const gUnk_MapDataResource_144[];
extern u8 const gUnk_MapDataResource_145[];
extern u8 const gUnk_MapDataResource_146[];
extern u8 const gUnk_MapDataResource_147[];
extern u8 const gUnk_MapDataResource_148[];
extern u8 const gUnk_MapDataResource_149[];
extern u8 const gUnk_MapDataResource_150[];
extern u8 const gUnk_MapDataResource_151[];
extern u8 const gUnk_MapDataResource_152[];
extern u8 const gUnk_MapDataResource_153[];
extern u8 const gUnk_MapDataResource_154[];
extern u8 const gUnk_MapDataResource_155[];
extern u8 const gUnk_MapDataResource_156[];
extern u8 const gUnk_MapDataResource_157[];
extern u8 const gUnk_MapDataResource_158[];
extern u8 const gUnk_MapDataResource_159[];
extern u8 const gUnk_MapDataResource_160[];
extern u8 const gUnk_MapDataResource_161[];
extern u8 const gUnk_MapDataResource_162[];
extern u8 const gUnk_MapDataResource_163[];
extern u8 const gUnk_MapDataResource_164[];
extern u8 const gUnk_MapDataResource_165[];
extern u8 const gUnk_MapDataResource_166[];
extern u8 const gUnk_MapDataResource_167[];
extern u8 const gUnk_MapDataResource_168[];
extern u8 const gUnk_MapDataResource_169[];
extern u8 const gUnk_MapDataResource_170[];
extern u8 const gUnk_MapDataResource_171[];
extern u8 const gUnk_MapDataResource_172[];
extern u8 const gUnk_MapDataResource_173[];
extern u8 const gUnk_MapDataResource_174[];
extern u8 const gUnk_MapDataResource_175[];
extern u8 const gUnk_MapDataResource_176[];
extern u8 const gUnk_MapDataResource_177[];
extern u8 const gUnk_MapDataResource_178[];
extern u8 const gUnk_MapDataResource_179[];
extern u8 const gUnk_MapDataResource_180[];
extern u8 const gUnk_MapDataResource_181[];
extern u8 const gUnk_MapDataResource_182[];
extern u8 const gUnk_MapDataResource_183[];
extern u8 const gUnk_MapDataResource_184[];
extern u8 const gUnk_MapDataResource_185[];
extern u8 const gUnk_MapDataResource_186[];
extern u8 const gUnk_MapDataResource_187[];
extern u8 const gUnk_MapDataResource_188[];
extern u8 const gUnk_MapDataResource_189[];
extern u8 const gUnk_MapDataResource_190[];
extern u8 const gUnk_MapDataResource_191[];
extern u8 const gUnk_MapDataResource_192[];
extern u8 const gUnk_MapDataResource_193[];
extern u8 const gUnk_MapDataResource_194[];
extern u8 const gUnk_MapDataResource_195[];
extern u8 const gUnk_MapDataResource_196[];
extern u8 const gUnk_MapDataResource_197[];
extern u8 const gUnk_MapDataResource_198[];
extern u8 const gUnk_MapDataResource_199[];
extern u8 const gUnk_MapDataResource_200[];
extern u8 const gUnk_MapDataResource_201[];
extern u8 const gUnk_MapDataResource_202[];
extern u8 const gUnk_MapDataResource_203[];
extern u8 const gUnk_MapDataResource_204[];
extern u8 const gUnk_MapDataResource_205[];
extern u8 const gUnk_MapDataResource_206[];
extern u8 const gUnk_MapDataResource_207[];
extern u8 const gUnk_MapDataResource_208[];
extern u8 const gUnk_MapDataResource_209[];
extern u8 const gUnk_MapDataResource_210[];
extern u8 const gUnk_MapDataResource_211[];
extern u8 const gUnk_MapDataResource_212[];
extern u8 const gUnk_MapDataResource_213[];
extern u8 const gUnk_MapDataResource_214[];
extern u8 const gUnk_MapDataResource_215[];
extern u8 const gUnk_MapDataResource_216[];
extern u8 const gUnk_MapDataResource_217[];
extern u8 const gUnk_MapDataResource_218[];
extern u8 const gUnk_MapDataResource_219[];
extern u8 const gUnk_MapDataResource_220[];
extern u8 const gUnk_MapDataResource_221[];
extern u8 const gUnk_MapDataResource_222[];
extern u8 const gUnk_MapDataResource_223[];
extern u8 const gUnk_MapDataResource_224[];
extern u8 const gUnk_MapDataResource_225[];
extern u8 const gUnk_MapDataResource_226[];
extern u8 const gUnk_MapDataResource_227[];
extern u8 const gUnk_MapDataResource_228[];
extern u8 const gUnk_MapDataResource_229[];
extern u8 const gUnk_MapDataResource_230[];
extern u8 const gUnk_MapDataResource_231[];
extern u8 const gUnk_MapDataResource_232[];
extern u8 const gUnk_MapDataResource_233[];
extern u8 const gUnk_MapDataResource_234[];
extern u8 const gUnk_MapDataResource_235[];
extern u8 const gUnk_MapDataResource_236[];
extern u8 const gUnk_MapDataResource_237[];
extern u8 const gUnk_MapDataResource_238[];
extern u8 const gUnk_MapDataResource_239[];
extern u8 const gUnk_MapDataResource_240[];
extern u8 const gUnk_MapDataResource_241[];
extern u8 const gUnk_MapDataResource_242[];
extern u8 const gUnk_MapDataResource_243[];
extern u8 const gUnk_MapDataResource_244[];
extern u8 const gUnk_MapDataResource_245[];
extern u8 const gUnk_MapDataResource_246[];
extern u8 const gUnk_MapDataResource_247[];
extern u8 const gUnk_MapDataResource_248[];
extern u8 const gUnk_MapDataResource_249[];
extern u8 const gUnk_MapDataResource_250[];
extern u8 const gUnk_MapDataResource_251[];
extern u8 const gUnk_MapDataResource_252[];
extern u8 const gUnk_MapDataResource_253[];
extern u8 const gUnk_MapDataResource_254[];
extern u8 const gUnk_MapDataResource_255[];
extern u8 const gUnk_MapDataResource_256[];
extern u8 const gUnk_MapDataResource_257[];
extern u8 const gUnk_MapDataResource_258[];
extern u8 const gUnk_MapDataResource_259[];
extern u8 const gUnk_MapDataResource_260[];
extern u8 const gUnk_MapDataResource_261[];
extern u8 const gUnk_MapDataResource_262[];
extern u8 const gUnk_MapDataResource_263[];
extern u8 const gUnk_MapDataResource_264[];
extern u8 const gUnk_MapDataResource_265[];
extern u8 const gUnk_MapDataResource_266[];
extern u8 const gUnk_MapDataResource_267[];
extern u8 const gUnk_MapDataResource_268[];
extern u8 const gUnk_MapDataResource_269[];
extern u8 const gUnk_MapDataResource_270[];
extern u8 const gUnk_MapDataResource_271[];
extern u8 const gUnk_MapDataResource_272[];
extern u8 const gUnk_MapDataResource_273[];
extern u8 const gUnk_MapDataResource_274[];
extern u8 const gUnk_MapDataResource_275[];
extern u8 const gUnk_MapDataResource_276[];
extern u8 const gUnk_MapDataResource_277[];
extern u8 const gUnk_MapDataResource_278[];
extern u8 const gUnk_MapDataResource_279[];
extern u8 const gUnk_MapDataResource_280[];
extern u8 const gUnk_MapDataResource_281[];
extern u8 const gUnk_MapDataResource_282[];
extern u8 const gUnk_MapDataResource_283[];
extern u8 const gUnk_MapDataResource_284[];
extern u8 const gUnk_MapDataResource_285[];
extern u8 const gUnk_MapDataResource_286[];
extern u8 const gUnk_MapDataResource_287[];
extern u8 const gUnk_MapDataResource_288[];
extern u8 const gUnk_MapDataResource_289[];
extern u8 const gUnk_MapDataResource_290[];
extern u8 const gUnk_MapDataResource_291[];
extern u8 const gUnk_MapDataResource_292[];
extern u8 const gUnk_MapDataResource_293[];
extern u8 const gUnk_MapDataResource_294[];
extern u8 const gUnk_MapDataResource_295[];
extern u8 const gUnk_MapDataResource_296[];
extern u8 const gUnk_MapDataResource_297[];
extern u8 const gUnk_MapDataResource_298[];
extern u8 const gUnk_MapDataResource_299[];
extern u8 const gUnk_MapDataResource_300[];
extern u8 const gUnk_MapDataResource_301[];
extern u8 const gUnk_MapDataResource_302[];
extern u8 const gUnk_MapDataResource_303[];
extern u8 const gUnk_MapDataResource_304[];
extern u8 const gUnk_MapDataResource_305[];
extern u8 const gUnk_MapDataResource_306[];
extern u8 const gUnk_MapDataResource_307[];
extern u8 const gUnk_MapDataResource_308[];
extern u8 const gUnk_MapDataResource_309[];
extern u8 const gUnk_MapDataResource_310[];
extern u8 const gUnk_MapDataResource_311[];
extern u8 const gUnk_MapDataResource_312[];
extern u8 const gUnk_MapDataResource_313[];
extern u8 const gUnk_MapDataResource_314[];
extern u8 const gUnk_MapDataResource_315[];
extern u8 const gUnk_MapDataResource_316[];
extern u8 const gUnk_MapDataResource_317[];
extern u8 const gUnk_MapDataResource_318[];
extern u8 const gUnk_MapDataResource_319[];
extern u8 const gUnk_MapDataResource_320[];
extern u8 const gUnk_MapDataResource_321[];
extern u8 const gUnk_MapDataResource_322[];
extern u8 const gUnk_MapDataResource_323[];
extern u8 const gUnk_MapDataResource_324[];
extern u8 const gUnk_MapDataResource_325[];
extern u8 const gUnk_MapDataResource_326[];
extern u8 const gUnk_MapDataResource_327[];
extern u8 const gUnk_MapDataResource_328[];
extern u8 const gUnk_MapDataResource_329[];
extern u8 const gUnk_MapDataResource_330[];
extern u8 const gUnk_MapDataResource_331[];
extern u8 const gUnk_MapDataResource_332[];
extern u8 const gUnk_MapDataResource_333[];
extern u8 const gUnk_MapDataResource_334[];
extern u8 const gUnk_MapDataResource_335[];
extern u8 const gUnk_MapDataResource_336[];
extern u8 const gUnk_MapDataResource_337[];
extern u8 const gUnk_MapDataResource_338[];
extern u8 const gUnk_MapDataResource_339[];
extern u8 const gUnk_MapDataResource_340[];
extern u8 const gUnk_MapDataResource_341[];
extern u8 const gUnk_MapDataResource_342[];
extern u8 const gUnk_MapDataResource_343[];
extern u8 const gUnk_MapDataResource_344[];
extern u8 const gUnk_MapDataResource_345[];
extern u8 const gUnk_MapDataResource_346[];
extern u8 const gUnk_MapDataResource_347[];
extern u8 const gUnk_MapDataResource_348[];
extern u8 const gUnk_MapDataResource_349[];
extern u8 const gUnk_MapDataResource_350[];
extern u8 const gUnk_MapDataResource_351[];
extern u8 const gUnk_MapDataResource_352[];
extern u8 const gUnk_MapDataResource_353[];
extern u8 const gUnk_MapDataResource_354[];
extern u8 const gUnk_MapDataResource_355[];
extern u8 const gUnk_MapDataResource_356[];
extern u8 const gUnk_MapDataResource_357[];
extern u8 const gUnk_MapDataResource_358[];
extern u8 const gUnk_MapDataResource_359[];
extern u8 const gUnk_MapDataResource_360[];
extern u8 const gUnk_MapDataResource_361[];
extern u8 const gUnk_MapDataResource_362[];
extern u8 const gUnk_MapDataResource_363[];
extern u8 const gUnk_MapDataResource_364[];
extern u8 const gUnk_MapDataResource_365[];
extern u8 const gUnk_MapDataResource_366[];
extern u8 const gUnk_MapDataResource_367[];
extern u8 const gUnk_MapDataResource_368[];
extern u8 const gUnk_MapDataResource_369[];
extern u8 const gUnk_MapDataResource_370[];
extern u8 const gUnk_MapDataResource_371[];
extern u8 const gUnk_MapDataResource_372[];
extern u8 const gUnk_MapDataResource_373[];
extern u8 const gUnk_MapDataResource_374[];
extern u8 const gUnk_MapDataResource_375[];
extern u8 const gUnk_MapDataResource_376[];
extern u8 const gUnk_MapDataResource_377[];
extern u8 const gUnk_MapDataResource_378[];
extern u8 const gUnk_MapDataResource_379[];

MapData const gMapData[MAP_DATA_COUNT] SECTION(".rodata.map_data") = {
    /* 0x00 */ {
        {
            gUnk_MapDataResource_000, gUnk_MapDataResource_001,
            gUnk_MapDataResource_002, gUnk_MapDataResource_003,
            gUnk_MapDataResource_004, gUnk_MapDataResource_005,
        },
        gUnk_MapDataResource_006,
        gUnk_MapDataResource_007,
        0x0080, 0x0058, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x01 */ {
        {
            gUnk_MapDataResource_008, gUnk_MapDataResource_009,
            gUnk_MapDataResource_010, gUnk_MapDataResource_011,
            gUnk_MapDataResource_012, gUnk_MapDataResource_013,
        },
        gUnk_MapDataResource_006,
        gUnk_MapDataResource_007,
        0x0080, 0x0058, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x02 */ {
        {
            gUnk_MapDataResource_014, gUnk_MapDataResource_015,
            gUnk_MapDataResource_016, gUnk_MapDataResource_017,
            gUnk_MapDataResource_018, gUnk_MapDataResource_019,
        },
        gUnk_MapDataResource_020,
        gUnk_MapDataResource_021,
        0x003C, 0x0038, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x03 */ {
        {
            gUnk_MapDataResource_022, gUnk_MapDataResource_023,
            gUnk_MapDataResource_024, gUnk_MapDataResource_025,
            gUnk_MapDataResource_026, gUnk_MapDataResource_027,
        },
        gUnk_MapDataResource_020,
        gUnk_MapDataResource_021,
        0x003C, 0x0038, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x04 */ {
        {
            gUnk_MapDataResource_028, gUnk_MapDataResource_029,
            gUnk_MapDataResource_030, gUnk_MapDataResource_031,
            gUnk_MapDataResource_032, gUnk_MapDataResource_033,
        },
        gUnk_MapDataResource_034,
        gUnk_MapDataResource_035,
        0x00B0, 0x0058, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x05 */ {
        {
            gUnk_MapDataResource_036, gUnk_MapDataResource_037,
            gUnk_MapDataResource_038, gUnk_MapDataResource_039,
            gUnk_MapDataResource_040, gUnk_MapDataResource_041,
        },
        gUnk_MapDataResource_034,
        gUnk_MapDataResource_035,
        0x00B0, 0x0058, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x06 */ {
        {
            gUnk_MapDataResource_042, gUnk_MapDataResource_043,
            gUnk_MapDataResource_044, gUnk_MapDataResource_045,
            gUnk_MapDataResource_046, gUnk_MapDataResource_047,
        },
        gUnk_MapDataResource_048,
        gUnk_MapDataResource_049,
        0x00AD, 0x0040, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x07 */ {
        {
            gUnk_MapDataResource_050, gUnk_MapDataResource_051,
            gUnk_MapDataResource_052, gUnk_MapDataResource_053,
            gUnk_MapDataResource_054, gUnk_MapDataResource_055,
        },
        gUnk_MapDataResource_048,
        gUnk_MapDataResource_049,
        0x00AD, 0x0040, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x08 */ {
        {
            gUnk_MapDataResource_056, gUnk_MapDataResource_057,
            gUnk_MapDataResource_058, gUnk_MapDataResource_059,
            gUnk_MapDataResource_060, gUnk_MapDataResource_061,
        },
        gUnk_MapDataResource_062,
        gUnk_MapDataResource_063,
        0x0040, 0x0050, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x09 */ {
        {
            gUnk_MapDataResource_064, gUnk_MapDataResource_065,
            gUnk_MapDataResource_066, gUnk_MapDataResource_067,
            gUnk_MapDataResource_068, gUnk_MapDataResource_069,
        },
        gUnk_MapDataResource_062,
        gUnk_MapDataResource_063,
        0x0040, 0x0050, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x0A */ {
        {
            gUnk_MapDataResource_070, gUnk_MapDataResource_071,
            gUnk_MapDataResource_072, gUnk_MapDataResource_073,
            gUnk_MapDataResource_074, gUnk_MapDataResource_075,
        },
        gUnk_MapDataResource_076,
        gUnk_MapDataResource_077,
        0x0040, 0x0030, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x0B */ {
        {
            gUnk_MapDataResource_078, gUnk_MapDataResource_079,
            gUnk_MapDataResource_080, gUnk_MapDataResource_081,
            gUnk_MapDataResource_082, gUnk_MapDataResource_083,
        },
        gUnk_MapDataResource_076,
        gUnk_MapDataResource_077,
        0x0040, 0x0030, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x0C */ {
        {
            gUnk_MapDataResource_070, gUnk_MapDataResource_071,
            gUnk_MapDataResource_072, gUnk_MapDataResource_084,
            gUnk_MapDataResource_085, gUnk_MapDataResource_086,
        },
        gUnk_MapDataResource_087,
        gUnk_MapDataResource_088,
        0x0080, 0x0040, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x0D */ {
        {
            gUnk_MapDataResource_078, gUnk_MapDataResource_079,
            gUnk_MapDataResource_080, gUnk_MapDataResource_089,
            gUnk_MapDataResource_090, gUnk_MapDataResource_091,
        },
        gUnk_MapDataResource_087,
        gUnk_MapDataResource_088,
        0x0080, 0x0040, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x0E */ {
        {
            gUnk_MapDataResource_092, gUnk_MapDataResource_093,
            gUnk_MapDataResource_094, gUnk_MapDataResource_095,
            gUnk_MapDataResource_096, gUnk_MapDataResource_097,
        },
        gUnk_MapDataResource_098,
        gUnk_MapDataResource_099,
        0x0096, 0x0064, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x0F */ {
        {
            gUnk_MapDataResource_100, gUnk_MapDataResource_101,
            gUnk_MapDataResource_102, gUnk_MapDataResource_103,
            gUnk_MapDataResource_104, gUnk_MapDataResource_105,
        },
        gUnk_MapDataResource_098,
        gUnk_MapDataResource_099,
        0x0096, 0x0064, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x10 */ {
        {
            gUnk_MapDataResource_106, gUnk_MapDataResource_107,
            gUnk_MapDataResource_108, gUnk_MapDataResource_109,
            gUnk_MapDataResource_110, gUnk_MapDataResource_111,
        },
        gUnk_MapDataResource_112,
        gUnk_MapDataResource_113,
        0x003C, 0x003C, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x11 */ {
        {
            gUnk_MapDataResource_114, gUnk_MapDataResource_115,
            gUnk_MapDataResource_116, gUnk_MapDataResource_117,
            gUnk_MapDataResource_118, gUnk_MapDataResource_119,
        },
        gUnk_MapDataResource_112,
        gUnk_MapDataResource_113,
        0x003C, 0x003C, 0x00, { 0x00, 0x00, 0x00 },
    },
    /* 0x12 */ {
        {
            gUnk_MapDataResource_120, gUnk_MapDataResource_121,
            gUnk_MapDataResource_121, gUnk_MapDataResource_122,
            gUnk_MapDataResource_123, gUnk_MapDataResource_124,
        },
        gUnk_MapDataResource_125,
        gUnk_MapDataResource_126,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x13 */ {
        {
            gUnk_MapDataResource_120, gUnk_MapDataResource_121,
            gUnk_MapDataResource_121, gUnk_MapDataResource_127,
            gUnk_MapDataResource_128, gUnk_MapDataResource_129,
        },
        gUnk_MapDataResource_130,
        gUnk_MapDataResource_131,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x14 */ {
        {
            gUnk_MapDataResource_120, gUnk_MapDataResource_121,
            gUnk_MapDataResource_121, gUnk_MapDataResource_132,
            gUnk_MapDataResource_133, gUnk_MapDataResource_134,
        },
        gUnk_MapDataResource_135,
        gUnk_MapDataResource_136,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x15 */ {
        {
            gUnk_MapDataResource_120, gUnk_MapDataResource_121,
            gUnk_MapDataResource_121, gUnk_MapDataResource_137,
            gUnk_MapDataResource_138, gUnk_MapDataResource_139,
        },
        gUnk_MapDataResource_140,
        gUnk_MapDataResource_141,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x16 */ {
        {
            gUnk_MapDataResource_142, gUnk_MapDataResource_143,
            gUnk_MapDataResource_143, gUnk_MapDataResource_144,
            gUnk_MapDataResource_145, gUnk_MapDataResource_146,
        },
        gUnk_MapDataResource_147,
        gUnk_MapDataResource_148,
        0x002E, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x17 */ {
        {
            gUnk_MapDataResource_142, gUnk_MapDataResource_143,
            gUnk_MapDataResource_143, gUnk_MapDataResource_149,
            gUnk_MapDataResource_150, gUnk_MapDataResource_151,
        },
        gUnk_MapDataResource_152,
        gUnk_MapDataResource_153,
        0x002E, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x18 */ {
        {
            gUnk_MapDataResource_142, gUnk_MapDataResource_143,
            gUnk_MapDataResource_143, gUnk_MapDataResource_154,
            gUnk_MapDataResource_155, gUnk_MapDataResource_156,
        },
        gUnk_MapDataResource_157,
        gUnk_MapDataResource_158,
        0x002E, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x19 */ {
        {
            gUnk_MapDataResource_159, gUnk_MapDataResource_160,
            gUnk_MapDataResource_160, gUnk_MapDataResource_161,
            gUnk_MapDataResource_162, gUnk_MapDataResource_163,
        },
        gUnk_MapDataResource_164,
        gUnk_MapDataResource_165,
        0x0024, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x1A */ {
        {
            gUnk_MapDataResource_166, gUnk_MapDataResource_167,
            gUnk_MapDataResource_167, gUnk_MapDataResource_168,
            gUnk_MapDataResource_169, gUnk_MapDataResource_170,
        },
        gUnk_MapDataResource_171,
        gUnk_MapDataResource_172,
        0x0024, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x1B */ {
        {
            gUnk_MapDataResource_166, gUnk_MapDataResource_167,
            gUnk_MapDataResource_167, gUnk_MapDataResource_173,
            gUnk_MapDataResource_174, gUnk_MapDataResource_175,
        },
        gUnk_MapDataResource_176,
        gUnk_MapDataResource_177,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x1C */ {
        {
            gUnk_MapDataResource_166, gUnk_MapDataResource_167,
            gUnk_MapDataResource_167, gUnk_MapDataResource_178,
            gUnk_MapDataResource_179, gUnk_MapDataResource_180,
        },
        gUnk_MapDataResource_181,
        gUnk_MapDataResource_182,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x1D */ {
        {
            gUnk_MapDataResource_183, gUnk_MapDataResource_184,
            gUnk_MapDataResource_184, gUnk_MapDataResource_185,
            gUnk_MapDataResource_186, gUnk_MapDataResource_187,
        },
        gUnk_MapDataResource_188,
        gUnk_MapDataResource_189,
        0x002E, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x1E */ {
        {
            gUnk_MapDataResource_183, gUnk_MapDataResource_184,
            gUnk_MapDataResource_184, gUnk_MapDataResource_190,
            gUnk_MapDataResource_191, gUnk_MapDataResource_192,
        },
        gUnk_MapDataResource_193,
        gUnk_MapDataResource_194,
        0x002E, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x1F */ {
        {
            gUnk_MapDataResource_183, gUnk_MapDataResource_184,
            gUnk_MapDataResource_184, gUnk_MapDataResource_195,
            gUnk_MapDataResource_196, gUnk_MapDataResource_197,
        },
        gUnk_MapDataResource_198,
        gUnk_MapDataResource_199,
        0x002E, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x20 */ {
        {
            gUnk_MapDataResource_200, gUnk_MapDataResource_201,
            gUnk_MapDataResource_201, gUnk_MapDataResource_202,
            gUnk_MapDataResource_203, gUnk_MapDataResource_204,
        },
        gUnk_MapDataResource_205,
        gUnk_MapDataResource_206,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x21 */ {
        {
            gUnk_MapDataResource_200, gUnk_MapDataResource_201,
            gUnk_MapDataResource_201, gUnk_MapDataResource_207,
            gUnk_MapDataResource_208, gUnk_MapDataResource_209,
        },
        gUnk_MapDataResource_210,
        gUnk_MapDataResource_211,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x22 */ {
        {
            gUnk_MapDataResource_200, gUnk_MapDataResource_201,
            gUnk_MapDataResource_201, gUnk_MapDataResource_212,
            gUnk_MapDataResource_213, gUnk_MapDataResource_214,
        },
        gUnk_MapDataResource_215,
        gUnk_MapDataResource_216,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x23 */ {
        {
            gUnk_MapDataResource_200, gUnk_MapDataResource_201,
            gUnk_MapDataResource_201, gUnk_MapDataResource_217,
            gUnk_MapDataResource_218, gUnk_MapDataResource_219,
        },
        gUnk_MapDataResource_220,
        gUnk_MapDataResource_221,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x24 */ {
        {
            gUnk_MapDataResource_222, gUnk_MapDataResource_223,
            gUnk_MapDataResource_223, gUnk_MapDataResource_224,
            gUnk_MapDataResource_225, gUnk_MapDataResource_226,
        },
        gUnk_MapDataResource_227,
        gUnk_MapDataResource_228,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x25 */ {
        {
            gUnk_MapDataResource_222, gUnk_MapDataResource_223,
            gUnk_MapDataResource_223, gUnk_MapDataResource_229,
            gUnk_MapDataResource_230, gUnk_MapDataResource_231,
        },
        gUnk_MapDataResource_232,
        gUnk_MapDataResource_233,
        0x002A, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x26 */ {
        {
            gUnk_MapDataResource_222, gUnk_MapDataResource_223,
            gUnk_MapDataResource_223, gUnk_MapDataResource_234,
            gUnk_MapDataResource_235, gUnk_MapDataResource_236,
        },
        gUnk_MapDataResource_237,
        gUnk_MapDataResource_238,
        0x002E, 0x0024, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x27 */ {
        {
            gUnk_MapDataResource_222, gUnk_MapDataResource_223,
            gUnk_MapDataResource_223, gUnk_MapDataResource_239,
            gUnk_MapDataResource_240, gUnk_MapDataResource_241,
        },
        gUnk_MapDataResource_242,
        gUnk_MapDataResource_243,
        0x004C, 0x0024, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x28 */ {
        {
            gUnk_MapDataResource_222, gUnk_MapDataResource_223,
            gUnk_MapDataResource_223, gUnk_MapDataResource_244,
            gUnk_MapDataResource_245, gUnk_MapDataResource_246,
        },
        gUnk_MapDataResource_247,
        gUnk_MapDataResource_248,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x29 */ {
        {
            gUnk_MapDataResource_249, gUnk_MapDataResource_250,
            gUnk_MapDataResource_250, gUnk_MapDataResource_251,
            gUnk_MapDataResource_252, gUnk_MapDataResource_253,
        },
        gUnk_MapDataResource_254,
        gUnk_MapDataResource_255,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x2A */ {
        {
            gUnk_MapDataResource_249, gUnk_MapDataResource_250,
            gUnk_MapDataResource_250, gUnk_MapDataResource_256,
            gUnk_MapDataResource_257, gUnk_MapDataResource_258,
        },
        gUnk_MapDataResource_259,
        gUnk_MapDataResource_260,
        0x002D, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x2B */ {
        {
            gUnk_MapDataResource_249, gUnk_MapDataResource_250,
            gUnk_MapDataResource_250, gUnk_MapDataResource_261,
            gUnk_MapDataResource_262, gUnk_MapDataResource_263,
        },
        gUnk_MapDataResource_264,
        gUnk_MapDataResource_265,
        0x003B, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x2C */ {
        {
            gUnk_MapDataResource_266, gUnk_MapDataResource_267,
            gUnk_MapDataResource_267, gUnk_MapDataResource_268,
            gUnk_MapDataResource_269, gUnk_MapDataResource_270,
        },
        gUnk_MapDataResource_271,
        gUnk_MapDataResource_272,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x2D */ {
        {
            gUnk_MapDataResource_266, gUnk_MapDataResource_267,
            gUnk_MapDataResource_267, gUnk_MapDataResource_273,
            gUnk_MapDataResource_274, gUnk_MapDataResource_275,
        },
        gUnk_MapDataResource_276,
        gUnk_MapDataResource_277,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x2E */ {
        {
            gUnk_MapDataResource_278, gUnk_MapDataResource_279,
            gUnk_MapDataResource_279, gUnk_MapDataResource_280,
            gUnk_MapDataResource_281, gUnk_MapDataResource_282,
        },
        gUnk_MapDataResource_283,
        gUnk_MapDataResource_284,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x2F */ {
        {
            gUnk_MapDataResource_278, gUnk_MapDataResource_279,
            gUnk_MapDataResource_279, gUnk_MapDataResource_285,
            gUnk_MapDataResource_286, gUnk_MapDataResource_287,
        },
        gUnk_MapDataResource_288,
        gUnk_MapDataResource_289,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x30 */ {
        {
            gUnk_MapDataResource_290, gUnk_MapDataResource_291,
            gUnk_MapDataResource_291, gUnk_MapDataResource_292,
            gUnk_MapDataResource_293, gUnk_MapDataResource_294,
        },
        gUnk_MapDataResource_295,
        gUnk_MapDataResource_296,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x31 */ {
        {
            gUnk_MapDataResource_290, gUnk_MapDataResource_291,
            gUnk_MapDataResource_291, gUnk_MapDataResource_297,
            gUnk_MapDataResource_298, gUnk_MapDataResource_299,
        },
        gUnk_MapDataResource_300,
        gUnk_MapDataResource_301,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x32 */ {
        {
            gUnk_MapDataResource_302, gUnk_MapDataResource_303,
            gUnk_MapDataResource_303, gUnk_MapDataResource_304,
            gUnk_MapDataResource_305, gUnk_MapDataResource_306,
        },
        gUnk_MapDataResource_307,
        gUnk_MapDataResource_308,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x33 */ {
        {
            gUnk_MapDataResource_302, gUnk_MapDataResource_303,
            gUnk_MapDataResource_303, gUnk_MapDataResource_309,
            gUnk_MapDataResource_310, gUnk_MapDataResource_311,
        },
        gUnk_MapDataResource_312,
        gUnk_MapDataResource_313,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x34 */ {
        {
            gUnk_MapDataResource_314, gUnk_MapDataResource_315,
            gUnk_MapDataResource_315, gUnk_MapDataResource_316,
            gUnk_MapDataResource_317, gUnk_MapDataResource_318,
        },
        gUnk_MapDataResource_319,
        gUnk_MapDataResource_320,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x35 */ {
        {
            gUnk_MapDataResource_321, gUnk_MapDataResource_322,
            gUnk_MapDataResource_322, gUnk_MapDataResource_323,
            gUnk_MapDataResource_324, gUnk_MapDataResource_325,
        },
        gUnk_MapDataResource_326,
        gUnk_MapDataResource_327,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x36 */ {
        {
            gUnk_MapDataResource_321, gUnk_MapDataResource_322,
            gUnk_MapDataResource_322, gUnk_MapDataResource_328,
            gUnk_MapDataResource_329, gUnk_MapDataResource_330,
        },
        gUnk_MapDataResource_331,
        gUnk_MapDataResource_332,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x37 */ {
        {
            gUnk_MapDataResource_321, gUnk_MapDataResource_322,
            gUnk_MapDataResource_322, gUnk_MapDataResource_333,
            gUnk_MapDataResource_334, gUnk_MapDataResource_335,
        },
        gUnk_MapDataResource_336,
        gUnk_MapDataResource_337,
        0x001E, 0x001C, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x38 */ {
        {
            gUnk_MapDataResource_338, gUnk_MapDataResource_339,
            gUnk_MapDataResource_339, gUnk_MapDataResource_340,
            gUnk_MapDataResource_341, gUnk_MapDataResource_342,
        },
        gUnk_MapDataResource_343,
        gUnk_MapDataResource_344,
        0x001E, 0x001A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x39 */ {
        {
            gUnk_MapDataResource_338, gUnk_MapDataResource_339,
            gUnk_MapDataResource_339, gUnk_MapDataResource_345,
            gUnk_MapDataResource_346, gUnk_MapDataResource_347,
        },
        gUnk_MapDataResource_348,
        gUnk_MapDataResource_349,
        0x003C, 0x0046, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x3A */ {
        {
            gUnk_MapDataResource_338, gUnk_MapDataResource_339,
            gUnk_MapDataResource_339, gUnk_MapDataResource_350,
            gUnk_MapDataResource_351, gUnk_MapDataResource_352,
        },
        gUnk_MapDataResource_353,
        gUnk_MapDataResource_354,
        0x001E, 0x002A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x3B */ {
        {
            gUnk_MapDataResource_338, gUnk_MapDataResource_339,
            gUnk_MapDataResource_339, gUnk_MapDataResource_355,
            gUnk_MapDataResource_356, gUnk_MapDataResource_357,
        },
        gUnk_MapDataResource_358,
        gUnk_MapDataResource_359,
        0x001E, 0x001A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x3C */ {
        {
            gUnk_MapDataResource_338, gUnk_MapDataResource_339,
            gUnk_MapDataResource_339, gUnk_MapDataResource_360,
            gUnk_MapDataResource_361, gUnk_MapDataResource_362,
        },
        gUnk_MapDataResource_363,
        gUnk_MapDataResource_364,
        0x001E, 0x0014, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x3D */ {
        {
            gUnk_MapDataResource_338, gUnk_MapDataResource_339,
            gUnk_MapDataResource_339, gUnk_MapDataResource_365,
            gUnk_MapDataResource_366, gUnk_MapDataResource_367,
        },
        gUnk_MapDataResource_368,
        gUnk_MapDataResource_369,
        0x001E, 0x001A, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x3E */ {
        {
            gUnk_MapDataResource_000, gUnk_MapDataResource_001,
            gUnk_MapDataResource_001, gUnk_MapDataResource_370,
            gUnk_MapDataResource_371, nullptr,
        },
        gUnk_MapDataResource_372,
        gUnk_MapDataResource_373,
        0x001E, 0x0014, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x3F */ {
        {
            gUnk_MapDataResource_000, gUnk_MapDataResource_001,
            gUnk_MapDataResource_001, gUnk_MapDataResource_374,
            gUnk_MapDataResource_375, nullptr,
        },
        nullptr,
        nullptr,
        0x001E, 0x0014, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x40 */ {
        {
            gUnk_MapDataResource_222, gUnk_MapDataResource_223,
            gUnk_MapDataResource_223, gUnk_MapDataResource_376,
            gUnk_MapDataResource_377, nullptr,
        },
        nullptr,
        nullptr,
        0x001E, 0x0014, 0x01, { 0x00, 0x00, 0x00 },
    },
    /* 0x41 */ {
        {
            gUnk_MapDataResource_222, gUnk_MapDataResource_223,
            gUnk_MapDataResource_223, gUnk_MapDataResource_378,
            gUnk_MapDataResource_379, nullptr,
        },
        nullptr,
        nullptr,
        0x001E, 0x0014, 0x01, { 0x00, 0x00, 0x00 },
    },
};

EXTERN_C_END

extern "C" MapData const * GetMapData(u32 map_id) SECTION(".text.get_map_data");

extern "C" MapData const * GetMapData(u32 map_id)
{
    return gMapData + map_id;
}
