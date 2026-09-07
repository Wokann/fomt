    .ifdef REGION_JP
    @ JP revision 0 counterpart of data_0813B288.s.
    @
    @ The original object is an asset-only incbin container.  JP retains that
    @ object boundary while using its independently matched JP asset range.

    .section .rodata
jp_data_0813b288_start:
    .incbin "baserom_jp.gba", 0x13C3CC, (0x45C5B4 - 0x13C3CC)

    @ Region-neutral labels for gMapData raw resource targets.
    @ Their payload types are not decoded yet.
    .global gUnk_MapDataResource_092
    .set gUnk_MapDataResource_092, jp_data_0813b288_start + 0x2C3E78
    .global gUnk_MapDataResource_093
    .set gUnk_MapDataResource_093, jp_data_0813b288_start + 0x2C89B4
    .global gUnk_MapDataResource_095
    .set gUnk_MapDataResource_095, jp_data_0813b288_start + 0x2C8AAC
    .global gUnk_MapDataResource_096
    .set gUnk_MapDataResource_096, jp_data_0813b288_start + 0x2CA7A0
    .global gUnk_MapDataResource_097
    .set gUnk_MapDataResource_097, jp_data_0813b288_start + 0x2CB40C
    .global gUnk_MapDataResource_094
    .set gUnk_MapDataResource_094, jp_data_0813b288_start + 0x2CBBE4
    .global gUnk_MapDataResource_100
    .set gUnk_MapDataResource_100, jp_data_0813b288_start + 0x2CBCBC
    .global gUnk_MapDataResource_101
    .set gUnk_MapDataResource_101, jp_data_0813b288_start + 0x2D0CBC
    .global gUnk_MapDataResource_103
    .set gUnk_MapDataResource_103, jp_data_0813b288_start + 0x2D0DB4
    .global gUnk_MapDataResource_104
    .set gUnk_MapDataResource_104, jp_data_0813b288_start + 0x2D2B34
    .global gUnk_MapDataResource_105
    .set gUnk_MapDataResource_105, jp_data_0813b288_start + 0x2D379C
    .global gUnk_MapDataResource_102
    .set gUnk_MapDataResource_102, jp_data_0813b288_start + 0x2D3F0C
    .global gUnk_MapDataResource_244
    .set gUnk_MapDataResource_244, jp_data_0813b288_start + 0x2D3FE0
    .global gUnk_MapDataResource_245
    .set gUnk_MapDataResource_245, jp_data_0813b288_start + 0x2D41EC
    .global gUnk_MapDataResource_246
    .set gUnk_MapDataResource_246, jp_data_0813b288_start + 0x2D4344
    .global gUnk_MapDataResource_056
    .set gUnk_MapDataResource_056, jp_data_0813b288_start + 0x2D43CC
    .global gUnk_MapDataResource_057
    .set gUnk_MapDataResource_057, jp_data_0813b288_start + 0x2D749C
    .global gUnk_MapDataResource_059
    .set gUnk_MapDataResource_059, jp_data_0813b288_start + 0x2D757C
    .global gUnk_MapDataResource_060
    .set gUnk_MapDataResource_060, jp_data_0813b288_start + 0x2D7C98
    .global gUnk_MapDataResource_061
    .set gUnk_MapDataResource_061, jp_data_0813b288_start + 0x2D7EF8
    .global gUnk_MapDataResource_058
    .set gUnk_MapDataResource_058, jp_data_0813b288_start + 0x2D7F74
    .global gUnk_MapDataResource_064
    .set gUnk_MapDataResource_064, jp_data_0813b288_start + 0x2D8058
    .global gUnk_MapDataResource_065
    .set gUnk_MapDataResource_065, jp_data_0813b288_start + 0x2DA62C
    .global gUnk_MapDataResource_067
    .set gUnk_MapDataResource_067, jp_data_0813b288_start + 0x2DA704
    .global gUnk_MapDataResource_068
    .set gUnk_MapDataResource_068, jp_data_0813b288_start + 0x2DAE08
    .global gUnk_MapDataResource_069
    .set gUnk_MapDataResource_069, jp_data_0813b288_start + 0x2DB02C
    .global gUnk_MapDataResource_066
    .set gUnk_MapDataResource_066, jp_data_0813b288_start + 0x2DB098
    .global gUnk_MapDataResource_222
    .set gUnk_MapDataResource_222, jp_data_0813b288_start + 0x2DB164
    .global gUnk_MapDataResource_223
    .set gUnk_MapDataResource_223, jp_data_0813b288_start + 0x2DCA1C
    .global gUnk_MapDataResource_268
    .set gUnk_MapDataResource_268, jp_data_0813b288_start + 0x2DCB40
    .global gUnk_MapDataResource_269
    .set gUnk_MapDataResource_269, jp_data_0813b288_start + 0x2DCD94
    .global gUnk_MapDataResource_270
    .set gUnk_MapDataResource_270, jp_data_0813b288_start + 0x2DCEC8
    .global gUnk_MapDataResource_273
    .set gUnk_MapDataResource_273, jp_data_0813b288_start + 0x2DCF9C
    .global gUnk_MapDataResource_274
    .set gUnk_MapDataResource_274, jp_data_0813b288_start + 0x2DD1BC
    .global gUnk_MapDataResource_275
    .set gUnk_MapDataResource_275, jp_data_0813b288_start + 0x2DD330
    .global gUnk_MapDataResource_266
    .set gUnk_MapDataResource_266, jp_data_0813b288_start + 0x2DD3C0
    .global gUnk_MapDataResource_267
    .set gUnk_MapDataResource_267, jp_data_0813b288_start + 0x2DF938
    .global gUnk_MapDataResource_195
    .set gUnk_MapDataResource_195, jp_data_0813b288_start + 0x2DFA40
    .global gUnk_MapDataResource_196
    .set gUnk_MapDataResource_196, jp_data_0813b288_start + 0x2DFD60
    .global gUnk_MapDataResource_197
    .set gUnk_MapDataResource_197, jp_data_0813b288_start + 0x2DFE64
    .global gUnk_MapDataResource_321
    .set gUnk_MapDataResource_321, jp_data_0813b288_start + 0x2DFF50
    .global gUnk_MapDataResource_322
    .set gUnk_MapDataResource_322, jp_data_0813b288_start + 0x2E1558
    .global gUnk_MapDataResource_178
    .set gUnk_MapDataResource_178, jp_data_0813b288_start + 0x2E5148
    .global gUnk_MapDataResource_179
    .set gUnk_MapDataResource_179, jp_data_0813b288_start + 0x2E529C
    .global gUnk_MapDataResource_180
    .set gUnk_MapDataResource_180, jp_data_0813b288_start + 0x2E53EC
    .global gUnk_MapDataResource_000
    .set gUnk_MapDataResource_000, jp_data_0813b288_start + 0x2E54C0
    .global gUnk_MapDataResource_001
    .set gUnk_MapDataResource_001, jp_data_0813b288_start + 0x2E9070
    .global gUnk_MapDataResource_003
    .set gUnk_MapDataResource_003, jp_data_0813b288_start + 0x2E9164
    .global gUnk_MapDataResource_004
    .set gUnk_MapDataResource_004, jp_data_0813b288_start + 0x2E9910
    .global gUnk_MapDataResource_005
    .set gUnk_MapDataResource_005, jp_data_0813b288_start + 0x2E9D98
    .global gUnk_MapDataResource_002
    .set gUnk_MapDataResource_002, jp_data_0813b288_start + 0x2E9E28
    .global gUnk_MapDataResource_008
    .set gUnk_MapDataResource_008, jp_data_0813b288_start + 0x2E9F1C
    .global gUnk_MapDataResource_009
    .set gUnk_MapDataResource_009, jp_data_0813b288_start + 0x2EDCD8
    .global gUnk_MapDataResource_011
    .set gUnk_MapDataResource_011, jp_data_0813b288_start + 0x2EDDBC
    .global gUnk_MapDataResource_012
    .set gUnk_MapDataResource_012, jp_data_0813b288_start + 0x2EE6E0
    .global gUnk_MapDataResource_013
    .set gUnk_MapDataResource_013, jp_data_0813b288_start + 0x2EEB94
    .global gUnk_MapDataResource_010
    .set gUnk_MapDataResource_010, jp_data_0813b288_start + 0x2EEC28
    .global gUnk_MapDataResource_070
    .set gUnk_MapDataResource_070, jp_data_0813b288_start + 0x2EECFC
    .global gUnk_MapDataResource_071
    .set gUnk_MapDataResource_071, jp_data_0813b288_start + 0x2F2678
    .global gUnk_MapDataResource_084
    .set gUnk_MapDataResource_084, jp_data_0813b288_start + 0x2F2744
    .global gUnk_MapDataResource_085
    .set gUnk_MapDataResource_085, jp_data_0813b288_start + 0x2F31C4
    .global gUnk_MapDataResource_086
    .set gUnk_MapDataResource_086, jp_data_0813b288_start + 0x2F38BC
    .global gUnk_MapDataResource_072
    .set gUnk_MapDataResource_072, jp_data_0813b288_start + 0x2F3E04
    .global gUnk_MapDataResource_078
    .set gUnk_MapDataResource_078, jp_data_0813b288_start + 0x2F3EC0
    .global gUnk_MapDataResource_079
    .set gUnk_MapDataResource_079, jp_data_0813b288_start + 0x2F7818
    .global gUnk_MapDataResource_089
    .set gUnk_MapDataResource_089, jp_data_0813b288_start + 0x2F78E0
    .global gUnk_MapDataResource_090
    .set gUnk_MapDataResource_090, jp_data_0813b288_start + 0x2F846C
    .global gUnk_MapDataResource_091
    .set gUnk_MapDataResource_091, jp_data_0813b288_start + 0x2F8ACC
    .global gUnk_MapDataResource_080
    .set gUnk_MapDataResource_080, jp_data_0813b288_start + 0x2F9004
    .global gUnk_MapDataResource_309
    .set gUnk_MapDataResource_309, jp_data_0813b288_start + 0x2F90BC
    .global gUnk_MapDataResource_310
    .set gUnk_MapDataResource_310, jp_data_0813b288_start + 0x2F92B0
    .global gUnk_MapDataResource_311
    .set gUnk_MapDataResource_311, jp_data_0813b288_start + 0x2F946C
    .global gUnk_MapDataResource_168
    .set gUnk_MapDataResource_168, jp_data_0813b288_start + 0x2F9538
    .global gUnk_MapDataResource_169
    .set gUnk_MapDataResource_169, jp_data_0813b288_start + 0x2F9704
    .global gUnk_MapDataResource_170
    .set gUnk_MapDataResource_170, jp_data_0813b288_start + 0x2F98C4
    .global gUnk_MapDataResource_159
    .set gUnk_MapDataResource_159, jp_data_0813b288_start + 0x2F9998
    .global gUnk_MapDataResource_160
    .set gUnk_MapDataResource_160, jp_data_0813b288_start + 0x2FB0A4
    .global gUnk_MapDataResource_161
    .set gUnk_MapDataResource_161, jp_data_0813b288_start + 0x2FB25C
    .global gUnk_MapDataResource_162
    .set gUnk_MapDataResource_162, jp_data_0813b288_start + 0x2FB4C4
    .global gUnk_MapDataResource_163
    .set gUnk_MapDataResource_163, jp_data_0813b288_start + 0x2FB6A4
    .global gUnk_MapDataResource_229
    .set gUnk_MapDataResource_229, jp_data_0813b288_start + 0x2FB7B8
    .global gUnk_MapDataResource_230
    .set gUnk_MapDataResource_230, jp_data_0813b288_start + 0x2FBAA0
    .global gUnk_MapDataResource_231
    .set gUnk_MapDataResource_231, jp_data_0813b288_start + 0x2FBB54
    .global gUnk_MapDataResource_224
    .set gUnk_MapDataResource_224, jp_data_0813b288_start + 0x2FBBF4
    .global gUnk_MapDataResource_225
    .set gUnk_MapDataResource_225, jp_data_0813b288_start + 0x2FBE68
    .global gUnk_MapDataResource_226
    .set gUnk_MapDataResource_226, jp_data_0813b288_start + 0x2FBEF8
    .global gUnk_MapDataResource_323
    .set gUnk_MapDataResource_323, jp_data_0813b288_start + 0x2FBF8C
    .global gUnk_MapDataResource_324
    .set gUnk_MapDataResource_324, jp_data_0813b288_start + 0x2FC110
    .global gUnk_MapDataResource_325
    .set gUnk_MapDataResource_325, jp_data_0813b288_start + 0x2FC1FC
    .global gUnk_MapDataResource_185
    .set gUnk_MapDataResource_185, jp_data_0813b288_start + 0x2FC280
    .global gUnk_MapDataResource_186
    .set gUnk_MapDataResource_186, jp_data_0813b288_start + 0x2FC5D0
    .global gUnk_MapDataResource_187
    .set gUnk_MapDataResource_187, jp_data_0813b288_start + 0x2FC7B4
    .global gUnk_MapDataResource_190
    .set gUnk_MapDataResource_190, jp_data_0813b288_start + 0x2FC92C
    .global gUnk_MapDataResource_191
    .set gUnk_MapDataResource_191, jp_data_0813b288_start + 0x2FCB78
    .global gUnk_MapDataResource_192
    .set gUnk_MapDataResource_192, jp_data_0813b288_start + 0x2FCDC4
    .global gUnk_MapDataResource_183
    .set gUnk_MapDataResource_183, jp_data_0813b288_start + 0x2FCF10
    .global gUnk_MapDataResource_184
    .set gUnk_MapDataResource_184, jp_data_0813b288_start + 0x30070C
    .global gUnk_MapDataResource_144
    .set gUnk_MapDataResource_144, jp_data_0813b288_start + 0x300884
    .global gUnk_MapDataResource_145
    .set gUnk_MapDataResource_145, jp_data_0813b288_start + 0x300B84
    .global gUnk_MapDataResource_146
    .set gUnk_MapDataResource_146, jp_data_0813b288_start + 0x300D84
    .global gUnk_MapDataResource_149
    .set gUnk_MapDataResource_149, jp_data_0813b288_start + 0x300EB0
    .global gUnk_MapDataResource_150
    .set gUnk_MapDataResource_150, jp_data_0813b288_start + 0x3011B8
    .global gUnk_MapDataResource_151
    .set gUnk_MapDataResource_151, jp_data_0813b288_start + 0x3014BC
    .global gUnk_MapDataResource_154
    .set gUnk_MapDataResource_154, jp_data_0813b288_start + 0x3015E8
    .global gUnk_MapDataResource_155
    .set gUnk_MapDataResource_155, jp_data_0813b288_start + 0x3018E4
    .global gUnk_MapDataResource_156
    .set gUnk_MapDataResource_156, jp_data_0813b288_start + 0x301B18
    .global gUnk_MapDataResource_142
    .set gUnk_MapDataResource_142, jp_data_0813b288_start + 0x301C0C
    .global gUnk_MapDataResource_143
    .set gUnk_MapDataResource_143, jp_data_0813b288_start + 0x3051D0
    .global gUnk_MapDataResource_302
    .set gUnk_MapDataResource_302, jp_data_0813b288_start + 0x30532C
    .global gUnk_MapDataResource_303
    .set gUnk_MapDataResource_303, jp_data_0813b288_start + 0x306D8C
    .global gUnk_MapDataResource_212
    .set gUnk_MapDataResource_212, jp_data_0813b288_start + 0x306EA0
    .global gUnk_MapDataResource_213
    .set gUnk_MapDataResource_213, jp_data_0813b288_start + 0x307058
    .global gUnk_MapDataResource_214
    .set gUnk_MapDataResource_214, jp_data_0813b288_start + 0x307158
    .global gUnk_MapDataResource_217
    .set gUnk_MapDataResource_217, jp_data_0813b288_start + 0x307278
    .global gUnk_MapDataResource_218
    .set gUnk_MapDataResource_218, jp_data_0813b288_start + 0x307410
    .global gUnk_MapDataResource_219
    .set gUnk_MapDataResource_219, jp_data_0813b288_start + 0x307528
    .global gUnk_MapDataResource_202
    .set gUnk_MapDataResource_202, jp_data_0813b288_start + 0x3075D0
    .global gUnk_MapDataResource_203
    .set gUnk_MapDataResource_203, jp_data_0813b288_start + 0x30774C
    .global gUnk_MapDataResource_204
    .set gUnk_MapDataResource_204, jp_data_0813b288_start + 0x30783C
    .global gUnk_MapDataResource_207
    .set gUnk_MapDataResource_207, jp_data_0813b288_start + 0x30791C
    .global gUnk_MapDataResource_208
    .set gUnk_MapDataResource_208, jp_data_0813b288_start + 0x307A10
    .global gUnk_MapDataResource_209
    .set gUnk_MapDataResource_209, jp_data_0813b288_start + 0x307B10
    .global gUnk_MapDataResource_200
    .set gUnk_MapDataResource_200, jp_data_0813b288_start + 0x307B94
    .global gUnk_MapDataResource_201
    .set gUnk_MapDataResource_201, jp_data_0813b288_start + 0x30A86C
    .global gUnk_MapDataResource_314
    .set gUnk_MapDataResource_314, jp_data_0813b288_start + 0x30A9D8
    .global gUnk_MapDataResource_315
    .set gUnk_MapDataResource_315, jp_data_0813b288_start + 0x30BAD4
    .global gUnk_MapDataResource_316
    .set gUnk_MapDataResource_316, jp_data_0813b288_start + 0x30BBD8
    .global gUnk_MapDataResource_317
    .set gUnk_MapDataResource_317, jp_data_0813b288_start + 0x30BD80
    .global gUnk_MapDataResource_318
    .set gUnk_MapDataResource_318, jp_data_0813b288_start + 0x30BEE8
    .global gUnk_MapDataResource_304
    .set gUnk_MapDataResource_304, jp_data_0813b288_start + 0x30BFE0
    .global gUnk_MapDataResource_305
    .set gUnk_MapDataResource_305, jp_data_0813b288_start + 0x30C1A4
    .global gUnk_MapDataResource_306
    .set gUnk_MapDataResource_306, jp_data_0813b288_start + 0x30C308
    .global gUnk_MapDataResource_249
    .set gUnk_MapDataResource_249, jp_data_0813b288_start + 0x30C3C0
    .global gUnk_MapDataResource_250
    .set gUnk_MapDataResource_250, jp_data_0813b288_start + 0x30EAF8
    .global gUnk_MapDataResource_261
    .set gUnk_MapDataResource_261, jp_data_0813b288_start + 0x30EC00
    .global gUnk_MapDataResource_262
    .set gUnk_MapDataResource_262, jp_data_0813b288_start + 0x30ED84
    .global gUnk_MapDataResource_263
    .set gUnk_MapDataResource_263, jp_data_0813b288_start + 0x30EE88
    .global gUnk_MapDataResource_256
    .set gUnk_MapDataResource_256, jp_data_0813b288_start + 0x30EF54
    .global gUnk_MapDataResource_257
    .set gUnk_MapDataResource_257, jp_data_0813b288_start + 0x30F0B4
    .global gUnk_MapDataResource_258
    .set gUnk_MapDataResource_258, jp_data_0813b288_start + 0x30F1B4
    .global gUnk_MapDataResource_251
    .set gUnk_MapDataResource_251, jp_data_0813b288_start + 0x30F274
    .global gUnk_MapDataResource_252
    .set gUnk_MapDataResource_252, jp_data_0813b288_start + 0x30F3C0
    .global gUnk_MapDataResource_253
    .set gUnk_MapDataResource_253, jp_data_0813b288_start + 0x30F4A8
    .global gUnk_MapDataResource_073
    .set gUnk_MapDataResource_073, jp_data_0813b288_start + 0x30F550
    .global gUnk_MapDataResource_074
    .set gUnk_MapDataResource_074, jp_data_0813b288_start + 0x30FA10
    .global gUnk_MapDataResource_075
    .set gUnk_MapDataResource_075, jp_data_0813b288_start + 0x30FC44
    .global gUnk_MapDataResource_081
    .set gUnk_MapDataResource_081, jp_data_0813b288_start + 0x30FE1C
    .global gUnk_MapDataResource_082
    .set gUnk_MapDataResource_082, jp_data_0813b288_start + 0x3102D0
    .global gUnk_MapDataResource_083
    .set gUnk_MapDataResource_083, jp_data_0813b288_start + 0x3104F0
    .global gUnk_MapDataResource_028
    .set gUnk_MapDataResource_028, jp_data_0813b288_start + 0x3106B0
    .global gUnk_MapDataResource_029
    .set gUnk_MapDataResource_029, jp_data_0813b288_start + 0x3153BC
    .global gUnk_MapDataResource_031
    .set gUnk_MapDataResource_031, jp_data_0813b288_start + 0x3154F0
    .global gUnk_MapDataResource_032
    .set gUnk_MapDataResource_032, jp_data_0813b288_start + 0x316570
    .global gUnk_MapDataResource_033
    .set gUnk_MapDataResource_033, jp_data_0813b288_start + 0x317608
    .global gUnk_MapDataResource_030
    .set gUnk_MapDataResource_030, jp_data_0813b288_start + 0x317C48
    .global gUnk_MapDataResource_036
    .set gUnk_MapDataResource_036, jp_data_0813b288_start + 0x317D7C
    .global gUnk_MapDataResource_037
    .set gUnk_MapDataResource_037, jp_data_0813b288_start + 0x31CC28
    .global gUnk_MapDataResource_039
    .set gUnk_MapDataResource_039, jp_data_0813b288_start + 0x31CD24
    .global gUnk_MapDataResource_040
    .set gUnk_MapDataResource_040, jp_data_0813b288_start + 0x31DC4C
    .global gUnk_MapDataResource_041
    .set gUnk_MapDataResource_041, jp_data_0813b288_start + 0x31EC64
    .global gUnk_MapDataResource_038
    .set gUnk_MapDataResource_038, jp_data_0813b288_start + 0x31F1B8
    .global gUnk_MapDataResource_122
    .set gUnk_MapDataResource_122, jp_data_0813b288_start + 0x3212E8
    .global gUnk_MapDataResource_123
    .set gUnk_MapDataResource_123, jp_data_0813b288_start + 0x3214C4
    .global gUnk_MapDataResource_124
    .set gUnk_MapDataResource_124, jp_data_0813b288_start + 0x321630
    .global gUnk_MapDataResource_127
    .set gUnk_MapDataResource_127, jp_data_0813b288_start + 0x321718
    .global gUnk_MapDataResource_128
    .set gUnk_MapDataResource_128, jp_data_0813b288_start + 0x3218F0
    .global gUnk_MapDataResource_129
    .set gUnk_MapDataResource_129, jp_data_0813b288_start + 0x321A1C
    .global gUnk_MapDataResource_120
    .set gUnk_MapDataResource_120, jp_data_0813b288_start + 0x321B18
    .global gUnk_MapDataResource_121
    .set gUnk_MapDataResource_121, jp_data_0813b288_start + 0x324C38
    .global gUnk_MapDataResource_338
    .set gUnk_MapDataResource_338, jp_data_0813b288_start + 0x324D5C
    .global gUnk_MapDataResource_339
    .set gUnk_MapDataResource_339, jp_data_0813b288_start + 0x325B14
    .global gUnk_MapDataResource_340
    .set gUnk_MapDataResource_340, jp_data_0813b288_start + 0x325BB4
    .global gUnk_MapDataResource_341
    .set gUnk_MapDataResource_341, jp_data_0813b288_start + 0x325C4C
    .global gUnk_MapDataResource_342
    .set gUnk_MapDataResource_342, jp_data_0813b288_start + 0x325C58
    .global gUnk_MapDataResource_345
    .set gUnk_MapDataResource_345, jp_data_0813b288_start + 0x325D04
    .global gUnk_MapDataResource_346
    .set gUnk_MapDataResource_346, jp_data_0813b288_start + 0x325D80
    .global gUnk_MapDataResource_347
    .set gUnk_MapDataResource_347, jp_data_0813b288_start + 0x325D8C
    .global gUnk_MapDataResource_350
    .set gUnk_MapDataResource_350, jp_data_0813b288_start + 0x325DE8
    .global gUnk_MapDataResource_351
    .set gUnk_MapDataResource_351, jp_data_0813b288_start + 0x325E74
    .global gUnk_MapDataResource_352
    .set gUnk_MapDataResource_352, jp_data_0813b288_start + 0x325E80
    .global gUnk_MapDataResource_355
    .set gUnk_MapDataResource_355, jp_data_0813b288_start + 0x325EE0
    .global gUnk_MapDataResource_356
    .set gUnk_MapDataResource_356, jp_data_0813b288_start + 0x325F60
    .global gUnk_MapDataResource_357
    .set gUnk_MapDataResource_357, jp_data_0813b288_start + 0x325F6C
    .global gUnk_MapDataResource_360
    .set gUnk_MapDataResource_360, jp_data_0813b288_start + 0x325FC8
    .global gUnk_MapDataResource_361
    .set gUnk_MapDataResource_361, jp_data_0813b288_start + 0x32607C
    .global gUnk_MapDataResource_362
    .set gUnk_MapDataResource_362, jp_data_0813b288_start + 0x3260A8
    .global gUnk_MapDataResource_365
    .set gUnk_MapDataResource_365, jp_data_0813b288_start + 0x326190
    .global gUnk_MapDataResource_366
    .set gUnk_MapDataResource_366, jp_data_0813b288_start + 0x326254
    .global gUnk_MapDataResource_367
    .set gUnk_MapDataResource_367, jp_data_0813b288_start + 0x326260
    .global gUnk_MapDataResource_014
    .set gUnk_MapDataResource_014, jp_data_0813b288_start + 0x344D94
    .global gUnk_MapDataResource_015
    .set gUnk_MapDataResource_015, jp_data_0813b288_start + 0x346F2C
    .global gUnk_MapDataResource_017
    .set gUnk_MapDataResource_017, jp_data_0813b288_start + 0x346FD0
    .global gUnk_MapDataResource_018
    .set gUnk_MapDataResource_018, jp_data_0813b288_start + 0x347560
    .global gUnk_MapDataResource_019
    .set gUnk_MapDataResource_019, jp_data_0813b288_start + 0x347784
    .global gUnk_MapDataResource_016
    .set gUnk_MapDataResource_016, jp_data_0813b288_start + 0x34781C
    .global gUnk_MapDataResource_022
    .set gUnk_MapDataResource_022, jp_data_0813b288_start + 0x3478BC
    .global gUnk_MapDataResource_023
    .set gUnk_MapDataResource_023, jp_data_0813b288_start + 0x349814
    .global gUnk_MapDataResource_025
    .set gUnk_MapDataResource_025, jp_data_0813b288_start + 0x3498B4
    .global gUnk_MapDataResource_026
    .set gUnk_MapDataResource_026, jp_data_0813b288_start + 0x349E40
    .global gUnk_MapDataResource_027
    .set gUnk_MapDataResource_027, jp_data_0813b288_start + 0x34A05C
    .global gUnk_MapDataResource_024
    .set gUnk_MapDataResource_024, jp_data_0813b288_start + 0x34A104
    .global gUnk_MapDataResource_132
    .set gUnk_MapDataResource_132, jp_data_0813b288_start + 0x34A198
    .global gUnk_MapDataResource_133
    .set gUnk_MapDataResource_133, jp_data_0813b288_start + 0x34A370
    .global gUnk_MapDataResource_134
    .set gUnk_MapDataResource_134, jp_data_0813b288_start + 0x34A474
    .global gUnk_MapDataResource_137
    .set gUnk_MapDataResource_137, jp_data_0813b288_start + 0x34A544
    .global gUnk_MapDataResource_138
    .set gUnk_MapDataResource_138, jp_data_0813b288_start + 0x34A744
    .global gUnk_MapDataResource_139
    .set gUnk_MapDataResource_139, jp_data_0813b288_start + 0x34A7FC
    .global gUnk_MapDataResource_328
    .set gUnk_MapDataResource_328, jp_data_0813b288_start + 0x34A870
    .global gUnk_MapDataResource_329
    .set gUnk_MapDataResource_329, jp_data_0813b288_start + 0x34A9FC
    .global gUnk_MapDataResource_330
    .set gUnk_MapDataResource_330, jp_data_0813b288_start + 0x34AB14
    .global gUnk_MapDataResource_166
    .set gUnk_MapDataResource_166, jp_data_0813b288_start + 0x34ABA0
    .global gUnk_MapDataResource_167
    .set gUnk_MapDataResource_167, jp_data_0813b288_start + 0x34D664
    .global gUnk_MapDataResource_173
    .set gUnk_MapDataResource_173, jp_data_0813b288_start + 0x34D7A4
    .global gUnk_MapDataResource_174
    .set gUnk_MapDataResource_174, jp_data_0813b288_start + 0x34D8F0
    .global gUnk_MapDataResource_175
    .set gUnk_MapDataResource_175, jp_data_0813b288_start + 0x34DA00
    .global gUnk_MapDataResource_239
    .set gUnk_MapDataResource_239, jp_data_0813b288_start + 0x34DAD8
    .global gUnk_MapDataResource_240
    .set gUnk_MapDataResource_240, jp_data_0813b288_start + 0x34DF9C
    .global gUnk_MapDataResource_241
    .set gUnk_MapDataResource_241, jp_data_0813b288_start + 0x34E0B8
    .global gUnk_MapDataResource_234
    .set gUnk_MapDataResource_234, jp_data_0813b288_start + 0x34E1B4
    .global gUnk_MapDataResource_235
    .set gUnk_MapDataResource_235, jp_data_0813b288_start + 0x34E54C
    .global gUnk_MapDataResource_236
    .set gUnk_MapDataResource_236, jp_data_0813b288_start + 0x34E628
    .global gUnk_MapDataResource_292
    .set gUnk_MapDataResource_292, jp_data_0813b288_start + 0x34E708
    .global gUnk_MapDataResource_293
    .set gUnk_MapDataResource_293, jp_data_0813b288_start + 0x34E8FC
    .global gUnk_MapDataResource_294
    .set gUnk_MapDataResource_294, jp_data_0813b288_start + 0x34E9E4
    .global gUnk_MapDataResource_042
    .set gUnk_MapDataResource_042, jp_data_0813b288_start + 0x34EAC0
    .global gUnk_MapDataResource_043
    .set gUnk_MapDataResource_043, jp_data_0813b288_start + 0x353938
    .global gUnk_MapDataResource_045
    .set gUnk_MapDataResource_045, jp_data_0813b288_start + 0x353AC4
    .global gUnk_MapDataResource_046
    .set gUnk_MapDataResource_046, jp_data_0813b288_start + 0x354638
    .global gUnk_MapDataResource_047
    .set gUnk_MapDataResource_047, jp_data_0813b288_start + 0x354FB0
    .global gUnk_MapDataResource_044
    .set gUnk_MapDataResource_044, jp_data_0813b288_start + 0x355438
    .global gUnk_MapDataResource_050
    .set gUnk_MapDataResource_050, jp_data_0813b288_start + 0x3555AC
    .global gUnk_MapDataResource_051
    .set gUnk_MapDataResource_051, jp_data_0813b288_start + 0x35A244
    .global gUnk_MapDataResource_053
    .set gUnk_MapDataResource_053, jp_data_0813b288_start + 0x35A36C
    .global gUnk_MapDataResource_054
    .set gUnk_MapDataResource_054, jp_data_0813b288_start + 0x35AC40
    .global gUnk_MapDataResource_055
    .set gUnk_MapDataResource_055, jp_data_0813b288_start + 0x35B5A8
    .global gUnk_MapDataResource_052
    .set gUnk_MapDataResource_052, jp_data_0813b288_start + 0x35BA20
    .global gUnk_MapDataResource_106
    .set gUnk_MapDataResource_106, jp_data_0813b288_start + 0x35BB30
    .global gUnk_MapDataResource_107
    .set gUnk_MapDataResource_107, jp_data_0813b288_start + 0x35E310
    .global gUnk_MapDataResource_109
    .set gUnk_MapDataResource_109, jp_data_0813b288_start + 0x35E3A0
    .global gUnk_MapDataResource_110
    .set gUnk_MapDataResource_110, jp_data_0813b288_start + 0x35E560
    .global gUnk_MapDataResource_111
    .set gUnk_MapDataResource_111, jp_data_0813b288_start + 0x35E710
    .global gUnk_MapDataResource_108
    .set gUnk_MapDataResource_108, jp_data_0813b288_start + 0x35E860
    .global gUnk_MapDataResource_114
    .set gUnk_MapDataResource_114, jp_data_0813b288_start + 0x35EA14
    .global gUnk_MapDataResource_115
    .set gUnk_MapDataResource_115, jp_data_0813b288_start + 0x3608C8
    .global gUnk_MapDataResource_117
    .set gUnk_MapDataResource_117, jp_data_0813b288_start + 0x360950
    .global gUnk_MapDataResource_118
    .set gUnk_MapDataResource_118, jp_data_0813b288_start + 0x360AB4
    .global gUnk_MapDataResource_119
    .set gUnk_MapDataResource_119, jp_data_0813b288_start + 0x360C5C
    .global gUnk_MapDataResource_116
    .set gUnk_MapDataResource_116, jp_data_0813b288_start + 0x360DA8
    .global gUnk_MapDataResource_333
    .set gUnk_MapDataResource_333, jp_data_0813b288_start + 0x360EDC
    .global gUnk_MapDataResource_334
    .set gUnk_MapDataResource_334, jp_data_0813b288_start + 0x361094
    .global gUnk_MapDataResource_335
    .set gUnk_MapDataResource_335, jp_data_0813b288_start + 0x3611C4
    .global gUnk_MapDataResource_370
    .set gUnk_MapDataResource_370, jp_data_0813b288_start + 0x361264
    .global gUnk_MapDataResource_371
    .set gUnk_MapDataResource_371, jp_data_0813b288_start + 0x3612F8
    .global gUnk_MapDataResource_374
    .set gUnk_MapDataResource_374, jp_data_0813b288_start + 0x361340
    .global gUnk_MapDataResource_375
    .set gUnk_MapDataResource_375, jp_data_0813b288_start + 0x36144C
    .global gUnk_MapDataResource_376
    .set gUnk_MapDataResource_376, jp_data_0813b288_start + 0x3614C0
    .global gUnk_MapDataResource_377
    .set gUnk_MapDataResource_377, jp_data_0813b288_start + 0x3616E4
    .global gUnk_MapDataResource_378
    .set gUnk_MapDataResource_378, jp_data_0813b288_start + 0x3617D0
    .global gUnk_MapDataResource_379
    .set gUnk_MapDataResource_379, jp_data_0813b288_start + 0x3619B4
    .global gUnk_MapDataResource_297
    .set gUnk_MapDataResource_297, jp_data_0813b288_start + 0x361A80
    .global gUnk_MapDataResource_298
    .set gUnk_MapDataResource_298, jp_data_0813b288_start + 0x361BF4
    .global gUnk_MapDataResource_299
    .set gUnk_MapDataResource_299, jp_data_0813b288_start + 0x361D98
    .global gUnk_MapDataResource_290
    .set gUnk_MapDataResource_290, jp_data_0813b288_start + 0x361E70
    .global gUnk_MapDataResource_291
    .set gUnk_MapDataResource_291, jp_data_0813b288_start + 0x364868
    .global gUnk_MapDataResource_280
    .set gUnk_MapDataResource_280, jp_data_0813b288_start + 0x364958
    .global gUnk_MapDataResource_281
    .set gUnk_MapDataResource_281, jp_data_0813b288_start + 0x364BBC
    .global gUnk_MapDataResource_282
    .set gUnk_MapDataResource_282, jp_data_0813b288_start + 0x364D14
    .global gUnk_MapDataResource_285
    .set gUnk_MapDataResource_285, jp_data_0813b288_start + 0x364E18
    .global gUnk_MapDataResource_286
    .set gUnk_MapDataResource_286, jp_data_0813b288_start + 0x36503C
    .global gUnk_MapDataResource_287
    .set gUnk_MapDataResource_287, jp_data_0813b288_start + 0x365164
    .global gUnk_MapDataResource_278
    .set gUnk_MapDataResource_278, jp_data_0813b288_start + 0x365204
    .global gUnk_MapDataResource_279
    .set gUnk_MapDataResource_279, jp_data_0813b288_start + 0x367184

    @ Region-neutral labels for FieldPlotTypeDefinition raw render records.
    @ The record payload format is not decoded yet.
    .global gUnk_FieldPlotRenderRecord_004
    .set gUnk_FieldPlotRenderRecord_004, jp_data_0813b288_start + 0x2E2910
    .global gUnk_FieldPlotRenderRecord_011
    .set gUnk_FieldPlotRenderRecord_011, jp_data_0813b288_start + 0x2E2940
    .global gUnk_FieldPlotRenderRecord_006
    .set gUnk_FieldPlotRenderRecord_006, jp_data_0813b288_start + 0x2E2958
    .global gUnk_FieldPlotRenderRecord_002
    .set gUnk_FieldPlotRenderRecord_002, jp_data_0813b288_start + 0x2E2994
    .global gUnk_FieldPlotRenderRecord_010
    .set gUnk_FieldPlotRenderRecord_010, jp_data_0813b288_start + 0x2E29C4
    .global gUnk_FieldPlotRenderRecord_014
    .set gUnk_FieldPlotRenderRecord_014, jp_data_0813b288_start + 0x2E29E8
    .global gUnk_FieldPlotRenderRecord_017
    .set gUnk_FieldPlotRenderRecord_017, jp_data_0813b288_start + 0x2E2A18
    .global gUnk_FieldPlotRenderRecord_018
    .set gUnk_FieldPlotRenderRecord_018, jp_data_0813b288_start + 0x2E2A48
    .global gUnk_FieldPlotRenderRecord_015
    .set gUnk_FieldPlotRenderRecord_015, jp_data_0813b288_start + 0x2E2A78
    .global gUnk_FieldPlotRenderRecord_007
    .set gUnk_FieldPlotRenderRecord_007, jp_data_0813b288_start + 0x2E2AA8
    .global gUnk_FieldPlotRenderRecord_009
    .set gUnk_FieldPlotRenderRecord_009, jp_data_0813b288_start + 0x2E2ACC
    .global gUnk_FieldPlotRenderRecord_016
    .set gUnk_FieldPlotRenderRecord_016, jp_data_0813b288_start + 0x2E2B08
    .global gUnk_FieldPlotRenderRecord_001
    .set gUnk_FieldPlotRenderRecord_001, jp_data_0813b288_start + 0x2E2B38
    .global gUnk_FieldPlotRenderRecord_008
    .set gUnk_FieldPlotRenderRecord_008, jp_data_0813b288_start + 0x2E2B5C
    .global gUnk_FieldPlotRenderRecord_013
    .set gUnk_FieldPlotRenderRecord_013, jp_data_0813b288_start + 0x2E2B8C
    .global gUnk_FieldPlotRenderRecord_003
    .set gUnk_FieldPlotRenderRecord_003, jp_data_0813b288_start + 0x2E3E04
    .global gUnk_FieldPlotRenderRecord_012
    .set gUnk_FieldPlotRenderRecord_012, jp_data_0813b288_start + 0x2E5094
    .global gUnk_FieldPlotRenderRecord_005
    .set gUnk_FieldPlotRenderRecord_005, jp_data_0813b288_start + 0x2E50AC
    .global gUnk_FieldPlotRenderRecord_019
    .set gUnk_FieldPlotRenderRecord_019, jp_data_0813b288_start + 0x2E50E8
    .global gUnk_FieldPlotRenderRecord_000
    .set gUnk_FieldPlotRenderRecord_000, jp_data_0813b288_start + 0x2E5124
    .global gUnk_FieldPlotRenderRecord_033
    .set gUnk_FieldPlotRenderRecord_033, jp_data_0813b288_start + 0x320158
    .global gUnk_FieldPlotRenderRecord_031
    .set gUnk_FieldPlotRenderRecord_031, jp_data_0813b288_start + 0x320170
    .global gUnk_FieldPlotRenderRecord_034
    .set gUnk_FieldPlotRenderRecord_034, jp_data_0813b288_start + 0x320188
    .global gUnk_FieldPlotRenderRecord_032
    .set gUnk_FieldPlotRenderRecord_032, jp_data_0813b288_start + 0x3201A0
    .global gUnk_FieldPlotRenderRecord_023
    .set gUnk_FieldPlotRenderRecord_023, jp_data_0813b288_start + 0x3201B8
    .global gUnk_FieldPlotRenderRecord_025
    .set gUnk_FieldPlotRenderRecord_025, jp_data_0813b288_start + 0x3201D0
    .global gUnk_FieldPlotRenderRecord_026
    .set gUnk_FieldPlotRenderRecord_026, jp_data_0813b288_start + 0x3201F4
    .global gUnk_FieldPlotRenderRecord_020
    .set gUnk_FieldPlotRenderRecord_020, jp_data_0813b288_start + 0x32020C
    .global gUnk_FieldPlotRenderRecord_024
    .set gUnk_FieldPlotRenderRecord_024, jp_data_0813b288_start + 0x3202C0
    .global gUnk_FieldPlotRenderRecord_037
    .set gUnk_FieldPlotRenderRecord_037, jp_data_0813b288_start + 0x320338
    .global gUnk_FieldPlotRenderRecord_035
    .set gUnk_FieldPlotRenderRecord_035, jp_data_0813b288_start + 0x320350
    .global gUnk_FieldPlotRenderRecord_038
    .set gUnk_FieldPlotRenderRecord_038, jp_data_0813b288_start + 0x320368
    .global gUnk_FieldPlotRenderRecord_036
    .set gUnk_FieldPlotRenderRecord_036, jp_data_0813b288_start + 0x320380
    .global gUnk_FieldPlotRenderRecord_022
    .set gUnk_FieldPlotRenderRecord_022, jp_data_0813b288_start + 0x3203A4
    .global gUnk_FieldPlotRenderRecord_029
    .set gUnk_FieldPlotRenderRecord_029, jp_data_0813b288_start + 0x3203BC
    .global gUnk_FieldPlotRenderRecord_027
    .set gUnk_FieldPlotRenderRecord_027, jp_data_0813b288_start + 0x3203D4
    .global gUnk_FieldPlotRenderRecord_030
    .set gUnk_FieldPlotRenderRecord_030, jp_data_0813b288_start + 0x3203EC
    .global gUnk_FieldPlotRenderRecord_028
    .set gUnk_FieldPlotRenderRecord_028, jp_data_0813b288_start + 0x320404
    .global gUnk_FieldPlotRenderRecord_021
    .set gUnk_FieldPlotRenderRecord_021, jp_data_0813b288_start + 0x32041C

    @ Farm Status preview resource labels.  The asset roles remain unknown.
    .global gUnk_082AFC74
    .set gUnk_082AFC74, jp_data_0813b288_start + 0x1738A8
    .global gUnk_082AFCD4
    .set gUnk_082AFCD4, jp_data_0813b288_start + 0x173908
    .global gUnk_082AFDC8
    .set gUnk_082AFDC8, jp_data_0813b288_start + 0x1739FC
    .global gUnk_082AFE70
    .set gUnk_082AFE70, jp_data_0813b288_start + 0x173AA4
    .global gUnk_082AFED0
    .set gUnk_082AFED0, jp_data_0813b288_start + 0x173B04
    .global gUnk_082B0744
    .set gUnk_082B0744, jp_data_0813b288_start + 0x174378
    .global gUnk_082B07E0
    .set gUnk_082B07E0, jp_data_0813b288_start + 0x174414
    .global gUnk_082B2F20
    .set gUnk_082B2F20, jp_data_0813b288_start + 0x176B54
    .global gUnk_082B2F80
    .set gUnk_082B2F80, jp_data_0813b288_start + 0x176BB4
    .global gUnk_082B3074
    .set gUnk_082B3074, jp_data_0813b288_start + 0x176CA8
    .global gUnk_082B311C
    .set gUnk_082B311C, jp_data_0813b288_start + 0x176D50
    .global gUnk_082B317C
    .set gUnk_082B317C, jp_data_0813b288_start + 0x176DB0
    .global gUnk_082B39F0
    .set gUnk_082B39F0, jp_data_0813b288_start + 0x177624
    .global gUnk_082B3A8C
    .set gUnk_082B3A8C, jp_data_0813b288_start + 0x1776C0

    .global gUnk_086D6458
gUnk_086D6458:
    .incbin "baserom_jp.gba", 0x45C5B4, 0xC0

    .global gUnk_086D6518
gUnk_086D6518:
    .incbin "baserom_jp.gba", 0x45C674, 0x8

    .global gUnk_086D6520
gUnk_086D6520:
    .incbin "baserom_jp.gba", 0x45C67C, 0x8

    .global gUnk_086D6528
gUnk_086D6528:
    .incbin "baserom_jp.gba", 0x45C684, 0x20

    .global gUnk_086D6548
gUnk_086D6548:
    .incbin "baserom_jp.gba", 0x45C6A4, 0xC0

    .global gUnk_086D6608
gUnk_086D6608:
    .incbin "baserom_jp.gba", 0x45C764, 0x90

    .incbin "baserom_jp.gba", 0x45C7F4, (0x462520 - 0x45C7F4)

    .global gActorStateGridCellType0Data
gActorStateGridCellType0Data:
    .incbin "baserom_jp.gba", 0x462520, 0xC

    .global gActorStateGridCellType1Data
gActorStateGridCellType1Data:
    .incbin "baserom_jp.gba", 0x46252C, 0xC

    .global gActorStateGridCellType2Data
gActorStateGridCellType2Data:
    .incbin "baserom_jp.gba", 0x462538, 0xC

    .global gActorStateGridCellType3Data
gActorStateGridCellType3Data:
    .incbin "baserom_jp.gba", 0x462544, 0xC

    .global gActorStateGridCellType4Data
gActorStateGridCellType4Data:
    .incbin "baserom_jp.gba", 0x462550, (0x77F610 - 0x462550)
    .else
    .section .rodata

    .LDATA_BEG = 0x13B288

	us_data_0813b288_start:
	.incbin "baserom_us.gba", (.LDATA_BEG), (0x4F90CC - .LDATA_BEG)

	@ Region-neutral labels for gMapData raw resource targets.
	@ Their payload types are not decoded yet.
	.global gUnk_MapDataResource_092
	.set gUnk_MapDataResource_092, us_data_0813b288_start + 0x53EE60
	.global gUnk_MapDataResource_093
	.set gUnk_MapDataResource_093, us_data_0813b288_start + 0x54399C
	.global gUnk_MapDataResource_095
	.set gUnk_MapDataResource_095, us_data_0813b288_start + 0x543A94
	.global gUnk_MapDataResource_096
	.set gUnk_MapDataResource_096, us_data_0813b288_start + 0x545788
	.global gUnk_MapDataResource_097
	.set gUnk_MapDataResource_097, us_data_0813b288_start + 0x5463F4
	.global gUnk_MapDataResource_094
	.set gUnk_MapDataResource_094, us_data_0813b288_start + 0x546BCC
	.global gUnk_MapDataResource_100
	.set gUnk_MapDataResource_100, us_data_0813b288_start + 0x546CA4
	.global gUnk_MapDataResource_101
	.set gUnk_MapDataResource_101, us_data_0813b288_start + 0x54BCA4
	.global gUnk_MapDataResource_103
	.set gUnk_MapDataResource_103, us_data_0813b288_start + 0x54BD9C
	.global gUnk_MapDataResource_104
	.set gUnk_MapDataResource_104, us_data_0813b288_start + 0x54DB1C
	.global gUnk_MapDataResource_105
	.set gUnk_MapDataResource_105, us_data_0813b288_start + 0x54E784
	.global gUnk_MapDataResource_102
	.set gUnk_MapDataResource_102, us_data_0813b288_start + 0x54EEF4
	.global gUnk_MapDataResource_244
	.set gUnk_MapDataResource_244, us_data_0813b288_start + 0x54EFC8
	.global gUnk_MapDataResource_245
	.set gUnk_MapDataResource_245, us_data_0813b288_start + 0x54F1D4
	.global gUnk_MapDataResource_246
	.set gUnk_MapDataResource_246, us_data_0813b288_start + 0x54F32C
	.global gUnk_MapDataResource_056
	.set gUnk_MapDataResource_056, us_data_0813b288_start + 0x54F3B4
	.global gUnk_MapDataResource_057
	.set gUnk_MapDataResource_057, us_data_0813b288_start + 0x552484
	.global gUnk_MapDataResource_059
	.set gUnk_MapDataResource_059, us_data_0813b288_start + 0x552564
	.global gUnk_MapDataResource_060
	.set gUnk_MapDataResource_060, us_data_0813b288_start + 0x552C80
	.global gUnk_MapDataResource_061
	.set gUnk_MapDataResource_061, us_data_0813b288_start + 0x552EE0
	.global gUnk_MapDataResource_058
	.set gUnk_MapDataResource_058, us_data_0813b288_start + 0x552F5C
	.global gUnk_MapDataResource_064
	.set gUnk_MapDataResource_064, us_data_0813b288_start + 0x553040
	.global gUnk_MapDataResource_065
	.set gUnk_MapDataResource_065, us_data_0813b288_start + 0x555614
	.global gUnk_MapDataResource_067
	.set gUnk_MapDataResource_067, us_data_0813b288_start + 0x5556EC
	.global gUnk_MapDataResource_068
	.set gUnk_MapDataResource_068, us_data_0813b288_start + 0x555DF0
	.global gUnk_MapDataResource_069
	.set gUnk_MapDataResource_069, us_data_0813b288_start + 0x556014
	.global gUnk_MapDataResource_066
	.set gUnk_MapDataResource_066, us_data_0813b288_start + 0x556080
	.global gUnk_MapDataResource_222
	.set gUnk_MapDataResource_222, us_data_0813b288_start + 0x55614C
	.global gUnk_MapDataResource_223
	.set gUnk_MapDataResource_223, us_data_0813b288_start + 0x557A04
	.global gUnk_MapDataResource_268
	.set gUnk_MapDataResource_268, us_data_0813b288_start + 0x557B28
	.global gUnk_MapDataResource_269
	.set gUnk_MapDataResource_269, us_data_0813b288_start + 0x557D7C
	.global gUnk_MapDataResource_270
	.set gUnk_MapDataResource_270, us_data_0813b288_start + 0x557EB0
	.global gUnk_MapDataResource_273
	.set gUnk_MapDataResource_273, us_data_0813b288_start + 0x557F84
	.global gUnk_MapDataResource_274
	.set gUnk_MapDataResource_274, us_data_0813b288_start + 0x5581A4
	.global gUnk_MapDataResource_275
	.set gUnk_MapDataResource_275, us_data_0813b288_start + 0x558318
	.global gUnk_MapDataResource_266
	.set gUnk_MapDataResource_266, us_data_0813b288_start + 0x5583A8
	.global gUnk_MapDataResource_267
	.set gUnk_MapDataResource_267, us_data_0813b288_start + 0x55A920
	.global gUnk_MapDataResource_195
	.set gUnk_MapDataResource_195, us_data_0813b288_start + 0x55AA28
	.global gUnk_MapDataResource_196
	.set gUnk_MapDataResource_196, us_data_0813b288_start + 0x55AD48
	.global gUnk_MapDataResource_197
	.set gUnk_MapDataResource_197, us_data_0813b288_start + 0x55AE4C
	.global gUnk_MapDataResource_321
	.set gUnk_MapDataResource_321, us_data_0813b288_start + 0x55AF38
	.global gUnk_MapDataResource_322
	.set gUnk_MapDataResource_322, us_data_0813b288_start + 0x55C540
	.global gUnk_MapDataResource_178
	.set gUnk_MapDataResource_178, us_data_0813b288_start + 0x560130
	.global gUnk_MapDataResource_179
	.set gUnk_MapDataResource_179, us_data_0813b288_start + 0x560284
	.global gUnk_MapDataResource_180
	.set gUnk_MapDataResource_180, us_data_0813b288_start + 0x5603D4
	.global gUnk_MapDataResource_000
	.set gUnk_MapDataResource_000, us_data_0813b288_start + 0x5604A8
	.global gUnk_MapDataResource_001
	.set gUnk_MapDataResource_001, us_data_0813b288_start + 0x564058
	.global gUnk_MapDataResource_003
	.set gUnk_MapDataResource_003, us_data_0813b288_start + 0x56414C
	.global gUnk_MapDataResource_004
	.set gUnk_MapDataResource_004, us_data_0813b288_start + 0x5648F8
	.global gUnk_MapDataResource_005
	.set gUnk_MapDataResource_005, us_data_0813b288_start + 0x564D80
	.global gUnk_MapDataResource_002
	.set gUnk_MapDataResource_002, us_data_0813b288_start + 0x564E10
	.global gUnk_MapDataResource_008
	.set gUnk_MapDataResource_008, us_data_0813b288_start + 0x564F04
	.global gUnk_MapDataResource_009
	.set gUnk_MapDataResource_009, us_data_0813b288_start + 0x568CC0
	.global gUnk_MapDataResource_011
	.set gUnk_MapDataResource_011, us_data_0813b288_start + 0x568DA4
	.global gUnk_MapDataResource_012
	.set gUnk_MapDataResource_012, us_data_0813b288_start + 0x5696C8
	.global gUnk_MapDataResource_013
	.set gUnk_MapDataResource_013, us_data_0813b288_start + 0x569B7C
	.global gUnk_MapDataResource_010
	.set gUnk_MapDataResource_010, us_data_0813b288_start + 0x569C10
	.global gUnk_MapDataResource_070
	.set gUnk_MapDataResource_070, us_data_0813b288_start + 0x569CE4
	.global gUnk_MapDataResource_071
	.set gUnk_MapDataResource_071, us_data_0813b288_start + 0x56D660
	.global gUnk_MapDataResource_084
	.set gUnk_MapDataResource_084, us_data_0813b288_start + 0x56D72C
	.global gUnk_MapDataResource_085
	.set gUnk_MapDataResource_085, us_data_0813b288_start + 0x56E1AC
	.global gUnk_MapDataResource_086
	.set gUnk_MapDataResource_086, us_data_0813b288_start + 0x56E8A4
	.global gUnk_MapDataResource_072
	.set gUnk_MapDataResource_072, us_data_0813b288_start + 0x56EDEC
	.global gUnk_MapDataResource_078
	.set gUnk_MapDataResource_078, us_data_0813b288_start + 0x56EEA8
	.global gUnk_MapDataResource_079
	.set gUnk_MapDataResource_079, us_data_0813b288_start + 0x572800
	.global gUnk_MapDataResource_089
	.set gUnk_MapDataResource_089, us_data_0813b288_start + 0x5728C8
	.global gUnk_MapDataResource_090
	.set gUnk_MapDataResource_090, us_data_0813b288_start + 0x573454
	.global gUnk_MapDataResource_091
	.set gUnk_MapDataResource_091, us_data_0813b288_start + 0x573AB4
	.global gUnk_MapDataResource_080
	.set gUnk_MapDataResource_080, us_data_0813b288_start + 0x573FEC
	.global gUnk_MapDataResource_309
	.set gUnk_MapDataResource_309, us_data_0813b288_start + 0x5740A4
	.global gUnk_MapDataResource_310
	.set gUnk_MapDataResource_310, us_data_0813b288_start + 0x574298
	.global gUnk_MapDataResource_311
	.set gUnk_MapDataResource_311, us_data_0813b288_start + 0x574454
	.global gUnk_MapDataResource_168
	.set gUnk_MapDataResource_168, us_data_0813b288_start + 0x574520
	.global gUnk_MapDataResource_169
	.set gUnk_MapDataResource_169, us_data_0813b288_start + 0x5746EC
	.global gUnk_MapDataResource_170
	.set gUnk_MapDataResource_170, us_data_0813b288_start + 0x5748AC
	.global gUnk_MapDataResource_159
	.set gUnk_MapDataResource_159, us_data_0813b288_start + 0x574980
	.global gUnk_MapDataResource_160
	.set gUnk_MapDataResource_160, us_data_0813b288_start + 0x57608C
	.global gUnk_MapDataResource_161
	.set gUnk_MapDataResource_161, us_data_0813b288_start + 0x576244
	.global gUnk_MapDataResource_162
	.set gUnk_MapDataResource_162, us_data_0813b288_start + 0x5764AC
	.global gUnk_MapDataResource_163
	.set gUnk_MapDataResource_163, us_data_0813b288_start + 0x57668C
	.global gUnk_MapDataResource_229
	.set gUnk_MapDataResource_229, us_data_0813b288_start + 0x5767A0
	.global gUnk_MapDataResource_230
	.set gUnk_MapDataResource_230, us_data_0813b288_start + 0x576A88
	.global gUnk_MapDataResource_231
	.set gUnk_MapDataResource_231, us_data_0813b288_start + 0x576B3C
	.global gUnk_MapDataResource_224
	.set gUnk_MapDataResource_224, us_data_0813b288_start + 0x576BDC
	.global gUnk_MapDataResource_225
	.set gUnk_MapDataResource_225, us_data_0813b288_start + 0x576E50
	.global gUnk_MapDataResource_226
	.set gUnk_MapDataResource_226, us_data_0813b288_start + 0x576EE0
	.global gUnk_MapDataResource_323
	.set gUnk_MapDataResource_323, us_data_0813b288_start + 0x576F74
	.global gUnk_MapDataResource_324
	.set gUnk_MapDataResource_324, us_data_0813b288_start + 0x5770F8
	.global gUnk_MapDataResource_325
	.set gUnk_MapDataResource_325, us_data_0813b288_start + 0x5771E4
	.global gUnk_MapDataResource_185
	.set gUnk_MapDataResource_185, us_data_0813b288_start + 0x577268
	.global gUnk_MapDataResource_186
	.set gUnk_MapDataResource_186, us_data_0813b288_start + 0x5775B8
	.global gUnk_MapDataResource_187
	.set gUnk_MapDataResource_187, us_data_0813b288_start + 0x57779C
	.global gUnk_MapDataResource_190
	.set gUnk_MapDataResource_190, us_data_0813b288_start + 0x577914
	.global gUnk_MapDataResource_191
	.set gUnk_MapDataResource_191, us_data_0813b288_start + 0x577B60
	.global gUnk_MapDataResource_192
	.set gUnk_MapDataResource_192, us_data_0813b288_start + 0x577DAC
	.global gUnk_MapDataResource_183
	.set gUnk_MapDataResource_183, us_data_0813b288_start + 0x577EF8
	.global gUnk_MapDataResource_184
	.set gUnk_MapDataResource_184, us_data_0813b288_start + 0x57B6F4
	.global gUnk_MapDataResource_144
	.set gUnk_MapDataResource_144, us_data_0813b288_start + 0x57B86C
	.global gUnk_MapDataResource_145
	.set gUnk_MapDataResource_145, us_data_0813b288_start + 0x57BB6C
	.global gUnk_MapDataResource_146
	.set gUnk_MapDataResource_146, us_data_0813b288_start + 0x57BD6C
	.global gUnk_MapDataResource_149
	.set gUnk_MapDataResource_149, us_data_0813b288_start + 0x57BE98
	.global gUnk_MapDataResource_150
	.set gUnk_MapDataResource_150, us_data_0813b288_start + 0x57C1A0
	.global gUnk_MapDataResource_151
	.set gUnk_MapDataResource_151, us_data_0813b288_start + 0x57C4A4
	.global gUnk_MapDataResource_154
	.set gUnk_MapDataResource_154, us_data_0813b288_start + 0x57C5D0
	.global gUnk_MapDataResource_155
	.set gUnk_MapDataResource_155, us_data_0813b288_start + 0x57C8CC
	.global gUnk_MapDataResource_156
	.set gUnk_MapDataResource_156, us_data_0813b288_start + 0x57CB00
	.global gUnk_MapDataResource_142
	.set gUnk_MapDataResource_142, us_data_0813b288_start + 0x57CBF4
	.global gUnk_MapDataResource_143
	.set gUnk_MapDataResource_143, us_data_0813b288_start + 0x5801B8
	.global gUnk_MapDataResource_302
	.set gUnk_MapDataResource_302, us_data_0813b288_start + 0x580314
	.global gUnk_MapDataResource_303
	.set gUnk_MapDataResource_303, us_data_0813b288_start + 0x581D74
	.global gUnk_MapDataResource_212
	.set gUnk_MapDataResource_212, us_data_0813b288_start + 0x581E88
	.global gUnk_MapDataResource_213
	.set gUnk_MapDataResource_213, us_data_0813b288_start + 0x582040
	.global gUnk_MapDataResource_214
	.set gUnk_MapDataResource_214, us_data_0813b288_start + 0x582140
	.global gUnk_MapDataResource_217
	.set gUnk_MapDataResource_217, us_data_0813b288_start + 0x582260
	.global gUnk_MapDataResource_218
	.set gUnk_MapDataResource_218, us_data_0813b288_start + 0x5823F8
	.global gUnk_MapDataResource_219
	.set gUnk_MapDataResource_219, us_data_0813b288_start + 0x582510
	.global gUnk_MapDataResource_202
	.set gUnk_MapDataResource_202, us_data_0813b288_start + 0x5825B8
	.global gUnk_MapDataResource_203
	.set gUnk_MapDataResource_203, us_data_0813b288_start + 0x582734
	.global gUnk_MapDataResource_204
	.set gUnk_MapDataResource_204, us_data_0813b288_start + 0x582824
	.global gUnk_MapDataResource_207
	.set gUnk_MapDataResource_207, us_data_0813b288_start + 0x582904
	.global gUnk_MapDataResource_208
	.set gUnk_MapDataResource_208, us_data_0813b288_start + 0x5829F8
	.global gUnk_MapDataResource_209
	.set gUnk_MapDataResource_209, us_data_0813b288_start + 0x582AF8
	.global gUnk_MapDataResource_200
	.set gUnk_MapDataResource_200, us_data_0813b288_start + 0x582B7C
	.global gUnk_MapDataResource_201
	.set gUnk_MapDataResource_201, us_data_0813b288_start + 0x585854
	.global gUnk_MapDataResource_314
	.set gUnk_MapDataResource_314, us_data_0813b288_start + 0x5859C0
	.global gUnk_MapDataResource_315
	.set gUnk_MapDataResource_315, us_data_0813b288_start + 0x586ABC
	.global gUnk_MapDataResource_316
	.set gUnk_MapDataResource_316, us_data_0813b288_start + 0x586BC0
	.global gUnk_MapDataResource_317
	.set gUnk_MapDataResource_317, us_data_0813b288_start + 0x586D68
	.global gUnk_MapDataResource_318
	.set gUnk_MapDataResource_318, us_data_0813b288_start + 0x586ED0
	.global gUnk_MapDataResource_304
	.set gUnk_MapDataResource_304, us_data_0813b288_start + 0x586FC8
	.global gUnk_MapDataResource_305
	.set gUnk_MapDataResource_305, us_data_0813b288_start + 0x58718C
	.global gUnk_MapDataResource_306
	.set gUnk_MapDataResource_306, us_data_0813b288_start + 0x5872F0
	.global gUnk_MapDataResource_249
	.set gUnk_MapDataResource_249, us_data_0813b288_start + 0x5873A8
	.global gUnk_MapDataResource_250
	.set gUnk_MapDataResource_250, us_data_0813b288_start + 0x589AE0
	.global gUnk_MapDataResource_261
	.set gUnk_MapDataResource_261, us_data_0813b288_start + 0x589BE8
	.global gUnk_MapDataResource_262
	.set gUnk_MapDataResource_262, us_data_0813b288_start + 0x589D6C
	.global gUnk_MapDataResource_263
	.set gUnk_MapDataResource_263, us_data_0813b288_start + 0x589E70
	.global gUnk_MapDataResource_256
	.set gUnk_MapDataResource_256, us_data_0813b288_start + 0x589F3C
	.global gUnk_MapDataResource_257
	.set gUnk_MapDataResource_257, us_data_0813b288_start + 0x58A09C
	.global gUnk_MapDataResource_258
	.set gUnk_MapDataResource_258, us_data_0813b288_start + 0x58A19C
	.global gUnk_MapDataResource_251
	.set gUnk_MapDataResource_251, us_data_0813b288_start + 0x58A25C
	.global gUnk_MapDataResource_252
	.set gUnk_MapDataResource_252, us_data_0813b288_start + 0x58A3A8
	.global gUnk_MapDataResource_253
	.set gUnk_MapDataResource_253, us_data_0813b288_start + 0x58A490
	.global gUnk_MapDataResource_073
	.set gUnk_MapDataResource_073, us_data_0813b288_start + 0x58A538
	.global gUnk_MapDataResource_074
	.set gUnk_MapDataResource_074, us_data_0813b288_start + 0x58A9F8
	.global gUnk_MapDataResource_075
	.set gUnk_MapDataResource_075, us_data_0813b288_start + 0x58AC2C
	.global gUnk_MapDataResource_081
	.set gUnk_MapDataResource_081, us_data_0813b288_start + 0x58AE04
	.global gUnk_MapDataResource_082
	.set gUnk_MapDataResource_082, us_data_0813b288_start + 0x58B2B8
	.global gUnk_MapDataResource_083
	.set gUnk_MapDataResource_083, us_data_0813b288_start + 0x58B4D8
	.global gUnk_MapDataResource_028
	.set gUnk_MapDataResource_028, us_data_0813b288_start + 0x58B698
	.global gUnk_MapDataResource_029
	.set gUnk_MapDataResource_029, us_data_0813b288_start + 0x5903A4
	.global gUnk_MapDataResource_031
	.set gUnk_MapDataResource_031, us_data_0813b288_start + 0x5904D8
	.global gUnk_MapDataResource_032
	.set gUnk_MapDataResource_032, us_data_0813b288_start + 0x591558
	.global gUnk_MapDataResource_033
	.set gUnk_MapDataResource_033, us_data_0813b288_start + 0x5925F0
	.global gUnk_MapDataResource_030
	.set gUnk_MapDataResource_030, us_data_0813b288_start + 0x592C30
	.global gUnk_MapDataResource_036
	.set gUnk_MapDataResource_036, us_data_0813b288_start + 0x592D64
	.global gUnk_MapDataResource_037
	.set gUnk_MapDataResource_037, us_data_0813b288_start + 0x597C10
	.global gUnk_MapDataResource_039
	.set gUnk_MapDataResource_039, us_data_0813b288_start + 0x597D0C
	.global gUnk_MapDataResource_040
	.set gUnk_MapDataResource_040, us_data_0813b288_start + 0x598C34
	.global gUnk_MapDataResource_041
	.set gUnk_MapDataResource_041, us_data_0813b288_start + 0x599C4C
	.global gUnk_MapDataResource_038
	.set gUnk_MapDataResource_038, us_data_0813b288_start + 0x59A1A0
	.global gUnk_MapDataResource_122
	.set gUnk_MapDataResource_122, us_data_0813b288_start + 0x59C2D0
	.global gUnk_MapDataResource_123
	.set gUnk_MapDataResource_123, us_data_0813b288_start + 0x59C4AC
	.global gUnk_MapDataResource_124
	.set gUnk_MapDataResource_124, us_data_0813b288_start + 0x59C618
	.global gUnk_MapDataResource_127
	.set gUnk_MapDataResource_127, us_data_0813b288_start + 0x59C700
	.global gUnk_MapDataResource_128
	.set gUnk_MapDataResource_128, us_data_0813b288_start + 0x59C8D8
	.global gUnk_MapDataResource_129
	.set gUnk_MapDataResource_129, us_data_0813b288_start + 0x59CA04
	.global gUnk_MapDataResource_120
	.set gUnk_MapDataResource_120, us_data_0813b288_start + 0x59CB00
	.global gUnk_MapDataResource_121
	.set gUnk_MapDataResource_121, us_data_0813b288_start + 0x59FC20
	.global gUnk_MapDataResource_338
	.set gUnk_MapDataResource_338, us_data_0813b288_start + 0x59FD44
	.global gUnk_MapDataResource_339
	.set gUnk_MapDataResource_339, us_data_0813b288_start + 0x5A0AFC
	.global gUnk_MapDataResource_340
	.set gUnk_MapDataResource_340, us_data_0813b288_start + 0x5A0B9C
	.global gUnk_MapDataResource_341
	.set gUnk_MapDataResource_341, us_data_0813b288_start + 0x5A0C34
	.global gUnk_MapDataResource_342
	.set gUnk_MapDataResource_342, us_data_0813b288_start + 0x5A0C40
	.global gUnk_MapDataResource_345
	.set gUnk_MapDataResource_345, us_data_0813b288_start + 0x5A0CEC
	.global gUnk_MapDataResource_346
	.set gUnk_MapDataResource_346, us_data_0813b288_start + 0x5A0D68
	.global gUnk_MapDataResource_347
	.set gUnk_MapDataResource_347, us_data_0813b288_start + 0x5A0D74
	.global gUnk_MapDataResource_350
	.set gUnk_MapDataResource_350, us_data_0813b288_start + 0x5A0DD0
	.global gUnk_MapDataResource_351
	.set gUnk_MapDataResource_351, us_data_0813b288_start + 0x5A0E5C
	.global gUnk_MapDataResource_352
	.set gUnk_MapDataResource_352, us_data_0813b288_start + 0x5A0E68
	.global gUnk_MapDataResource_355
	.set gUnk_MapDataResource_355, us_data_0813b288_start + 0x5A0EC8
	.global gUnk_MapDataResource_356
	.set gUnk_MapDataResource_356, us_data_0813b288_start + 0x5A0F48
	.global gUnk_MapDataResource_357
	.set gUnk_MapDataResource_357, us_data_0813b288_start + 0x5A0F54
	.global gUnk_MapDataResource_360
	.set gUnk_MapDataResource_360, us_data_0813b288_start + 0x5A0FB0
	.global gUnk_MapDataResource_361
	.set gUnk_MapDataResource_361, us_data_0813b288_start + 0x5A1064
	.global gUnk_MapDataResource_362
	.set gUnk_MapDataResource_362, us_data_0813b288_start + 0x5A1090
	.global gUnk_MapDataResource_365
	.set gUnk_MapDataResource_365, us_data_0813b288_start + 0x5A1178
	.global gUnk_MapDataResource_366
	.set gUnk_MapDataResource_366, us_data_0813b288_start + 0x5A123C
	.global gUnk_MapDataResource_367
	.set gUnk_MapDataResource_367, us_data_0813b288_start + 0x5A1248
	.global gUnk_MapDataResource_014
	.set gUnk_MapDataResource_014, us_data_0813b288_start + 0x5BFD7C
	.global gUnk_MapDataResource_015
	.set gUnk_MapDataResource_015, us_data_0813b288_start + 0x5C1F14
	.global gUnk_MapDataResource_017
	.set gUnk_MapDataResource_017, us_data_0813b288_start + 0x5C1FB8
	.global gUnk_MapDataResource_018
	.set gUnk_MapDataResource_018, us_data_0813b288_start + 0x5C2548
	.global gUnk_MapDataResource_019
	.set gUnk_MapDataResource_019, us_data_0813b288_start + 0x5C276C
	.global gUnk_MapDataResource_016
	.set gUnk_MapDataResource_016, us_data_0813b288_start + 0x5C2804
	.global gUnk_MapDataResource_022
	.set gUnk_MapDataResource_022, us_data_0813b288_start + 0x5C28A4
	.global gUnk_MapDataResource_023
	.set gUnk_MapDataResource_023, us_data_0813b288_start + 0x5C47FC
	.global gUnk_MapDataResource_025
	.set gUnk_MapDataResource_025, us_data_0813b288_start + 0x5C489C
	.global gUnk_MapDataResource_026
	.set gUnk_MapDataResource_026, us_data_0813b288_start + 0x5C4E28
	.global gUnk_MapDataResource_027
	.set gUnk_MapDataResource_027, us_data_0813b288_start + 0x5C5044
	.global gUnk_MapDataResource_024
	.set gUnk_MapDataResource_024, us_data_0813b288_start + 0x5C50EC
	.global gUnk_MapDataResource_132
	.set gUnk_MapDataResource_132, us_data_0813b288_start + 0x5C5180
	.global gUnk_MapDataResource_133
	.set gUnk_MapDataResource_133, us_data_0813b288_start + 0x5C5358
	.global gUnk_MapDataResource_134
	.set gUnk_MapDataResource_134, us_data_0813b288_start + 0x5C545C
	.global gUnk_MapDataResource_137
	.set gUnk_MapDataResource_137, us_data_0813b288_start + 0x5C552C
	.global gUnk_MapDataResource_138
	.set gUnk_MapDataResource_138, us_data_0813b288_start + 0x5C572C
	.global gUnk_MapDataResource_139
	.set gUnk_MapDataResource_139, us_data_0813b288_start + 0x5C57E4
	.global gUnk_MapDataResource_328
	.set gUnk_MapDataResource_328, us_data_0813b288_start + 0x5C5858
	.global gUnk_MapDataResource_329
	.set gUnk_MapDataResource_329, us_data_0813b288_start + 0x5C59E4
	.global gUnk_MapDataResource_330
	.set gUnk_MapDataResource_330, us_data_0813b288_start + 0x5C5AFC
	.global gUnk_MapDataResource_166
	.set gUnk_MapDataResource_166, us_data_0813b288_start + 0x5C5B88
	.global gUnk_MapDataResource_167
	.set gUnk_MapDataResource_167, us_data_0813b288_start + 0x5C864C
	.global gUnk_MapDataResource_173
	.set gUnk_MapDataResource_173, us_data_0813b288_start + 0x5C878C
	.global gUnk_MapDataResource_174
	.set gUnk_MapDataResource_174, us_data_0813b288_start + 0x5C88D8
	.global gUnk_MapDataResource_175
	.set gUnk_MapDataResource_175, us_data_0813b288_start + 0x5C89E8
	.global gUnk_MapDataResource_239
	.set gUnk_MapDataResource_239, us_data_0813b288_start + 0x5C8AC0
	.global gUnk_MapDataResource_240
	.set gUnk_MapDataResource_240, us_data_0813b288_start + 0x5C8F84
	.global gUnk_MapDataResource_241
	.set gUnk_MapDataResource_241, us_data_0813b288_start + 0x5C90A0
	.global gUnk_MapDataResource_234
	.set gUnk_MapDataResource_234, us_data_0813b288_start + 0x5C919C
	.global gUnk_MapDataResource_235
	.set gUnk_MapDataResource_235, us_data_0813b288_start + 0x5C9534
	.global gUnk_MapDataResource_236
	.set gUnk_MapDataResource_236, us_data_0813b288_start + 0x5C9610
	.global gUnk_MapDataResource_292
	.set gUnk_MapDataResource_292, us_data_0813b288_start + 0x5C96F0
	.global gUnk_MapDataResource_293
	.set gUnk_MapDataResource_293, us_data_0813b288_start + 0x5C98E4
	.global gUnk_MapDataResource_294
	.set gUnk_MapDataResource_294, us_data_0813b288_start + 0x5C99CC
	.global gUnk_MapDataResource_042
	.set gUnk_MapDataResource_042, us_data_0813b288_start + 0x5C9AA8
	.global gUnk_MapDataResource_043
	.set gUnk_MapDataResource_043, us_data_0813b288_start + 0x5CE920
	.global gUnk_MapDataResource_045
	.set gUnk_MapDataResource_045, us_data_0813b288_start + 0x5CEAAC
	.global gUnk_MapDataResource_046
	.set gUnk_MapDataResource_046, us_data_0813b288_start + 0x5CF620
	.global gUnk_MapDataResource_047
	.set gUnk_MapDataResource_047, us_data_0813b288_start + 0x5CFF98
	.global gUnk_MapDataResource_044
	.set gUnk_MapDataResource_044, us_data_0813b288_start + 0x5D0420
	.global gUnk_MapDataResource_050
	.set gUnk_MapDataResource_050, us_data_0813b288_start + 0x5D0594
	.global gUnk_MapDataResource_051
	.set gUnk_MapDataResource_051, us_data_0813b288_start + 0x5D522C
	.global gUnk_MapDataResource_053
	.set gUnk_MapDataResource_053, us_data_0813b288_start + 0x5D5354
	.global gUnk_MapDataResource_054
	.set gUnk_MapDataResource_054, us_data_0813b288_start + 0x5D5C28
	.global gUnk_MapDataResource_055
	.set gUnk_MapDataResource_055, us_data_0813b288_start + 0x5D6590
	.global gUnk_MapDataResource_052
	.set gUnk_MapDataResource_052, us_data_0813b288_start + 0x5D6A08
	.global gUnk_MapDataResource_106
	.set gUnk_MapDataResource_106, us_data_0813b288_start + 0x5D6B18
	.global gUnk_MapDataResource_107
	.set gUnk_MapDataResource_107, us_data_0813b288_start + 0x5D92F8
	.global gUnk_MapDataResource_109
	.set gUnk_MapDataResource_109, us_data_0813b288_start + 0x5D9388
	.global gUnk_MapDataResource_110
	.set gUnk_MapDataResource_110, us_data_0813b288_start + 0x5D9548
	.global gUnk_MapDataResource_111
	.set gUnk_MapDataResource_111, us_data_0813b288_start + 0x5D96F8
	.global gUnk_MapDataResource_108
	.set gUnk_MapDataResource_108, us_data_0813b288_start + 0x5D9848
	.global gUnk_MapDataResource_114
	.set gUnk_MapDataResource_114, us_data_0813b288_start + 0x5D99FC
	.global gUnk_MapDataResource_115
	.set gUnk_MapDataResource_115, us_data_0813b288_start + 0x5DB8B0
	.global gUnk_MapDataResource_117
	.set gUnk_MapDataResource_117, us_data_0813b288_start + 0x5DB938
	.global gUnk_MapDataResource_118
	.set gUnk_MapDataResource_118, us_data_0813b288_start + 0x5DBA9C
	.global gUnk_MapDataResource_119
	.set gUnk_MapDataResource_119, us_data_0813b288_start + 0x5DBC44
	.global gUnk_MapDataResource_116
	.set gUnk_MapDataResource_116, us_data_0813b288_start + 0x5DBD90
	.global gUnk_MapDataResource_333
	.set gUnk_MapDataResource_333, us_data_0813b288_start + 0x5DBEC4
	.global gUnk_MapDataResource_334
	.set gUnk_MapDataResource_334, us_data_0813b288_start + 0x5DC07C
	.global gUnk_MapDataResource_335
	.set gUnk_MapDataResource_335, us_data_0813b288_start + 0x5DC1AC
	.global gUnk_MapDataResource_370
	.set gUnk_MapDataResource_370, us_data_0813b288_start + 0x5DC24C
	.global gUnk_MapDataResource_371
	.set gUnk_MapDataResource_371, us_data_0813b288_start + 0x5DC2E0
	.global gUnk_MapDataResource_374
	.set gUnk_MapDataResource_374, us_data_0813b288_start + 0x5DC328
	.global gUnk_MapDataResource_375
	.set gUnk_MapDataResource_375, us_data_0813b288_start + 0x5DC434
	.global gUnk_MapDataResource_376
	.set gUnk_MapDataResource_376, us_data_0813b288_start + 0x5DC4A8
	.global gUnk_MapDataResource_377
	.set gUnk_MapDataResource_377, us_data_0813b288_start + 0x5DC6CC
	.global gUnk_MapDataResource_378
	.set gUnk_MapDataResource_378, us_data_0813b288_start + 0x5DC7B8
	.global gUnk_MapDataResource_379
	.set gUnk_MapDataResource_379, us_data_0813b288_start + 0x5DC99C
	.global gUnk_MapDataResource_297
	.set gUnk_MapDataResource_297, us_data_0813b288_start + 0x5DCA68
	.global gUnk_MapDataResource_298
	.set gUnk_MapDataResource_298, us_data_0813b288_start + 0x5DCBDC
	.global gUnk_MapDataResource_299
	.set gUnk_MapDataResource_299, us_data_0813b288_start + 0x5DCD80
	.global gUnk_MapDataResource_290
	.set gUnk_MapDataResource_290, us_data_0813b288_start + 0x5DCE58
	.global gUnk_MapDataResource_291
	.set gUnk_MapDataResource_291, us_data_0813b288_start + 0x5DF850
	.global gUnk_MapDataResource_280
	.set gUnk_MapDataResource_280, us_data_0813b288_start + 0x5DF940
	.global gUnk_MapDataResource_281
	.set gUnk_MapDataResource_281, us_data_0813b288_start + 0x5DFBA4
	.global gUnk_MapDataResource_282
	.set gUnk_MapDataResource_282, us_data_0813b288_start + 0x5DFCFC
	.global gUnk_MapDataResource_285
	.set gUnk_MapDataResource_285, us_data_0813b288_start + 0x5DFE00
	.global gUnk_MapDataResource_286
	.set gUnk_MapDataResource_286, us_data_0813b288_start + 0x5E0024
	.global gUnk_MapDataResource_287
	.set gUnk_MapDataResource_287, us_data_0813b288_start + 0x5E014C
	.global gUnk_MapDataResource_278
	.set gUnk_MapDataResource_278, us_data_0813b288_start + 0x5E01EC
	.global gUnk_MapDataResource_279
	.set gUnk_MapDataResource_279, us_data_0813b288_start + 0x5E216C

	@ Region-neutral labels for FieldPlotTypeDefinition raw render records.
	@ The record payload format is not decoded yet.
	.global gUnk_FieldPlotRenderRecord_004
	.set gUnk_FieldPlotRenderRecord_004, us_data_0813b288_start + 0x55D8F8
	.global gUnk_FieldPlotRenderRecord_011
	.set gUnk_FieldPlotRenderRecord_011, us_data_0813b288_start + 0x55D928
	.global gUnk_FieldPlotRenderRecord_006
	.set gUnk_FieldPlotRenderRecord_006, us_data_0813b288_start + 0x55D940
	.global gUnk_FieldPlotRenderRecord_002
	.set gUnk_FieldPlotRenderRecord_002, us_data_0813b288_start + 0x55D97C
	.global gUnk_FieldPlotRenderRecord_010
	.set gUnk_FieldPlotRenderRecord_010, us_data_0813b288_start + 0x55D9AC
	.global gUnk_FieldPlotRenderRecord_014
	.set gUnk_FieldPlotRenderRecord_014, us_data_0813b288_start + 0x55D9D0
	.global gUnk_FieldPlotRenderRecord_017
	.set gUnk_FieldPlotRenderRecord_017, us_data_0813b288_start + 0x55DA00
	.global gUnk_FieldPlotRenderRecord_018
	.set gUnk_FieldPlotRenderRecord_018, us_data_0813b288_start + 0x55DA30
	.global gUnk_FieldPlotRenderRecord_015
	.set gUnk_FieldPlotRenderRecord_015, us_data_0813b288_start + 0x55DA60
	.global gUnk_FieldPlotRenderRecord_007
	.set gUnk_FieldPlotRenderRecord_007, us_data_0813b288_start + 0x55DA90
	.global gUnk_FieldPlotRenderRecord_009
	.set gUnk_FieldPlotRenderRecord_009, us_data_0813b288_start + 0x55DAB4
	.global gUnk_FieldPlotRenderRecord_016
	.set gUnk_FieldPlotRenderRecord_016, us_data_0813b288_start + 0x55DAF0
	.global gUnk_FieldPlotRenderRecord_001
	.set gUnk_FieldPlotRenderRecord_001, us_data_0813b288_start + 0x55DB20
	.global gUnk_FieldPlotRenderRecord_008
	.set gUnk_FieldPlotRenderRecord_008, us_data_0813b288_start + 0x55DB44
	.global gUnk_FieldPlotRenderRecord_013
	.set gUnk_FieldPlotRenderRecord_013, us_data_0813b288_start + 0x55DB74
	.global gUnk_FieldPlotRenderRecord_003
	.set gUnk_FieldPlotRenderRecord_003, us_data_0813b288_start + 0x55EDEC
	.global gUnk_FieldPlotRenderRecord_012
	.set gUnk_FieldPlotRenderRecord_012, us_data_0813b288_start + 0x56007C
	.global gUnk_FieldPlotRenderRecord_005
	.set gUnk_FieldPlotRenderRecord_005, us_data_0813b288_start + 0x560094
	.global gUnk_FieldPlotRenderRecord_019
	.set gUnk_FieldPlotRenderRecord_019, us_data_0813b288_start + 0x5600D0
	.global gUnk_FieldPlotRenderRecord_000
	.set gUnk_FieldPlotRenderRecord_000, us_data_0813b288_start + 0x56010C
	.global gUnk_FieldPlotRenderRecord_033
	.set gUnk_FieldPlotRenderRecord_033, us_data_0813b288_start + 0x59B140
	.global gUnk_FieldPlotRenderRecord_031
	.set gUnk_FieldPlotRenderRecord_031, us_data_0813b288_start + 0x59B158
	.global gUnk_FieldPlotRenderRecord_034
	.set gUnk_FieldPlotRenderRecord_034, us_data_0813b288_start + 0x59B170
	.global gUnk_FieldPlotRenderRecord_032
	.set gUnk_FieldPlotRenderRecord_032, us_data_0813b288_start + 0x59B188
	.global gUnk_FieldPlotRenderRecord_023
	.set gUnk_FieldPlotRenderRecord_023, us_data_0813b288_start + 0x59B1A0
	.global gUnk_FieldPlotRenderRecord_025
	.set gUnk_FieldPlotRenderRecord_025, us_data_0813b288_start + 0x59B1B8
	.global gUnk_FieldPlotRenderRecord_026
	.set gUnk_FieldPlotRenderRecord_026, us_data_0813b288_start + 0x59B1DC
	.global gUnk_FieldPlotRenderRecord_020
	.set gUnk_FieldPlotRenderRecord_020, us_data_0813b288_start + 0x59B1F4
	.global gUnk_FieldPlotRenderRecord_024
	.set gUnk_FieldPlotRenderRecord_024, us_data_0813b288_start + 0x59B2A8
	.global gUnk_FieldPlotRenderRecord_037
	.set gUnk_FieldPlotRenderRecord_037, us_data_0813b288_start + 0x59B320
	.global gUnk_FieldPlotRenderRecord_035
	.set gUnk_FieldPlotRenderRecord_035, us_data_0813b288_start + 0x59B338
	.global gUnk_FieldPlotRenderRecord_038
	.set gUnk_FieldPlotRenderRecord_038, us_data_0813b288_start + 0x59B350
	.global gUnk_FieldPlotRenderRecord_036
	.set gUnk_FieldPlotRenderRecord_036, us_data_0813b288_start + 0x59B368
	.global gUnk_FieldPlotRenderRecord_022
	.set gUnk_FieldPlotRenderRecord_022, us_data_0813b288_start + 0x59B38C
	.global gUnk_FieldPlotRenderRecord_029
	.set gUnk_FieldPlotRenderRecord_029, us_data_0813b288_start + 0x59B3A4
	.global gUnk_FieldPlotRenderRecord_027
	.set gUnk_FieldPlotRenderRecord_027, us_data_0813b288_start + 0x59B3BC
	.global gUnk_FieldPlotRenderRecord_030
	.set gUnk_FieldPlotRenderRecord_030, us_data_0813b288_start + 0x59B3D4
	.global gUnk_FieldPlotRenderRecord_028
	.set gUnk_FieldPlotRenderRecord_028, us_data_0813b288_start + 0x59B3EC
	.global gUnk_FieldPlotRenderRecord_021
	.set gUnk_FieldPlotRenderRecord_021, us_data_0813b288_start + 0x59B404

	.global gUnk_084F90CC
gUnk_084F90CC:
	.incbin "baserom_us.gba", 0x4F90CC, 0x16D4

	.global gUnk_084FA7A0
gUnk_084FA7A0:
	.incbin "baserom_us.gba", 0x4FA7A0, 0x200

	.global gUnk_084FA9A0
gUnk_084FA9A0:
	.incbin "baserom_us.gba", 0x4FA9A0, 0x288F0

	.global gUnk_08523290
gUnk_08523290:
	.incbin "baserom_us.gba", 0x523290, 0x3E04

	.global gUnk_08527094
gUnk_08527094:
	.incbin "baserom_us.gba", 0x527094, 0x1A4

	.global gUnk_08527238
gUnk_08527238:
	.incbin "baserom_us.gba", 0x527238, 0x110

	.global gUnk_08527348
gUnk_08527348:
	.incbin "baserom_us.gba", 0x527348, 0x1D8

	.global gUnk_08527520
gUnk_08527520:
	.incbin "baserom_us.gba", 0x527520, 0xB0

	.global gUnk_085275D0
gUnk_085275D0:
	.incbin "baserom_us.gba", 0x5275D0, 0x21C4

	.global gUnk_08529794
gUnk_08529794:
	.incbin "baserom_us.gba", 0x529794, 0x200

	.global gUnk_08529994
gUnk_08529994:
	.incbin "baserom_us.gba", 0x529994, 0x214

	.global gUnk_08529BA8
gUnk_08529BA8:
	.incbin "baserom_us.gba", 0x529BA8, 0x1FC

	.global gUnk_08529DA4
gUnk_08529DA4:
	.incbin "baserom_us.gba", 0x529DA4, 0x934

	.global gUnk_0852A6D8
gUnk_0852A6D8:
	.incbin "baserom_us.gba", 0x52A6D8, 0x114

	.global gUnk_0852A7EC
gUnk_0852A7EC:
	.incbin "baserom_us.gba", 0x52A7EC, 0x1D0

	.global gUnk_0852A9BC
gUnk_0852A9BC:
	.incbin "baserom_us.gba", 0x52A9BC, 0xB0

	.global gUnk_0852AA6C
gUnk_0852AA6C:
	.incbin "baserom_us.gba", 0x52AA6C, 0x1FD4

	.global gUnk_0852CA40
gUnk_0852CA40:
	.incbin "baserom_us.gba", 0x52CA40, 0x200

	.global gUnk_0852CC40
gUnk_0852CC40:
	.incbin "baserom_us.gba", 0x52CC40, 0x214

	.global gUnk_0852CE54
gUnk_0852CE54:
	.incbin "baserom_us.gba", 0x52CE54, 0x1FC

	.global gUnk_0852D050
gUnk_0852D050:
	.incbin "baserom_us.gba", 0x52D050, 0x934

	.global gUnk_0852D984
gUnk_0852D984:
	.incbin "baserom_us.gba", 0x52D984, 0x5E0A4

	@ Farm Status preview resource labels.  The asset roles remain unknown.
	.global gUnk_08529B18
	.set gUnk_08529B18, gUnk_08529994 + 0x184
	.global gUnk_08529B78
	.set gUnk_08529B78, gUnk_08529994 + 0x1E4
	.global gUnk_08529C6C
	.set gUnk_08529C6C, gUnk_08529BA8 + 0xC4
	.global gUnk_08529D14
	.set gUnk_08529D14, gUnk_08529BA8 + 0x16C
	.global gUnk_08529D74
	.set gUnk_08529D74, gUnk_08529BA8 + 0x1CC
	.global gUnk_0852A5E8
	.set gUnk_0852A5E8, gUnk_08529DA4 + 0x844
	.global gUnk_0852A684
	.set gUnk_0852A684, gUnk_08529DA4 + 0x8E0
	.global gUnk_0852CDC4
	.set gUnk_0852CDC4, gUnk_0852CC40 + 0x184
	.global gUnk_0852CE24
	.set gUnk_0852CE24, gUnk_0852CC40 + 0x1E4
	.global gUnk_0852CF18
	.set gUnk_0852CF18, gUnk_0852CE54 + 0xC4
	.global gUnk_0852CFC0
	.set gUnk_0852CFC0, gUnk_0852CE54 + 0x16C
	.global gUnk_0852D020
	.set gUnk_0852D020, gUnk_0852CE54 + 0x1CC
	.global gUnk_0852D894
	.set gUnk_0852D894, gUnk_0852D050 + 0x844
	.global gUnk_0852D930
	.set gUnk_0852D930, gUnk_0852D050 + 0x8E0

	.global gUnk_0858BA28
gUnk_0858BA28:
	.incbin "baserom_us.gba", 0x58BA28, 0xDB638

	.global gUnk_08667060
gUnk_08667060:
	.incbin "baserom_us.gba", 0x667060, 0x840

	.global gUnk_086678A0
gUnk_086678A0:
	.incbin "baserom_us.gba", 0x6678A0, 0x30080

	.global gUnk_08697920
gUnk_08697920:
	.incbin "baserom_us.gba", 0x697920, 0x11E0

	.global gUnk_08698B00
gUnk_08698B00:
	.incbin "baserom_us.gba", 0x698B00, 0x314

	.global gUnk_08698E14
gUnk_08698E14:
	.incbin "baserom_us.gba", 0x698E14, 0x11E0

	.global gUnk_08699FF4
gUnk_08699FF4:
	.incbin "baserom_us.gba", 0x699FF4, 0xB0

	.global gUnk_0869A0A4
gUnk_0869A0A4:
	.incbin "baserom_us.gba", 0x69A0A4, 0x11E0

	.global gUnk_0869B284
gUnk_0869B284:
	.incbin "baserom_us.gba", 0x69B284, 0x3A284

	.global gUnk_086D5508
gUnk_086D5508:
	.incbin "baserom_us.gba", 0x6D5508, 0xE60

	.global gUnk_086D6368
gUnk_086D6368:
	.incbin "baserom_us.gba", 0x6D6368, 0xF0

	.global gUnk_086D6458
gUnk_086D6458:
	.incbin "baserom_us.gba", 0x6D6458, 0xC0

	.global gUnk_086D6518
gUnk_086D6518:
	.incbin "baserom_us.gba", 0x6D6518, 0x8

	.global gUnk_086D6520
gUnk_086D6520:
	.incbin "baserom_us.gba", 0x6D6520, 0x8

	.global gUnk_086D6528
gUnk_086D6528:
	.incbin "baserom_us.gba", 0x6D6528, 0x20

	.global gUnk_086D6548
gUnk_086D6548:
	.incbin "baserom_us.gba", 0x6D6548, 0xC0

	.global gUnk_086D6608
gUnk_086D6608:
	.incbin "baserom_us.gba", 0x6D6608, 0x90

	.global gUnk_086D6698
gUnk_086D6698:
	.incbin "baserom_us.gba", 0x6D6698, 0xE60

	.global gUnk_086D74F8
gUnk_086D74F8:
	.incbin "baserom_us.gba", 0x6D74F8, 0x4ECC

	.global gActorStateGridCellType0Data
gActorStateGridCellType0Data:
	.incbin "baserom_us.gba", 0x6DC3C4, 0xC

	.global gActorStateGridCellType1Data
gActorStateGridCellType1Data:
	.incbin "baserom_us.gba", 0x6DC3D0, 0xC

	.global gActorStateGridCellType2Data
gActorStateGridCellType2Data:
	.incbin "baserom_us.gba", 0x6DC3DC, 0xC

	.global gActorStateGridCellType3Data
gActorStateGridCellType3Data:
	.incbin "baserom_us.gba", 0x6DC3E8, 0xC

	.global gActorStateGridCellType4Data
gActorStateGridCellType4Data:
	.incbin "baserom_us.gba", 0x6DC3F4, 0x158

	.global gUnk_086DC54C
gUnk_086DC54C:
	.incbin "baserom_us.gba", 0x6DC54C, 0x30

	.global gUnk_086DC57C
gUnk_086DC57C:
	.incbin "baserom_us.gba", 0x6DC57C, 0x70C

	.global gUnk_086DCC88
gUnk_086DCC88:
	.incbin "baserom_us.gba", 0x6DCC88, 0xA08

	.global gUnk_086DD690
gUnk_086DD690:
	.incbin "baserom_us.gba", 0x6DD690, 0x20

	.global gUnk_086DD6B0
gUnk_086DD6B0:
	.incbin "baserom_us.gba", 0x6DD6B0, 0x30

	.global gUnk_086DD6E0
gUnk_086DD6E0:
	.incbin "baserom_us.gba", 0x6DD6E0, 0x70C

	.global gUnk_086DDDEC
gUnk_086DDDEC:
	.incbin "baserom_us.gba", 0x6DDDEC, 0xA08

	.global gUnk_086DE7F4
gUnk_086DE7F4:
	.incbin "baserom_us.gba", 0x6DE7F4, 0xC4E8

	.global gUnk_086EACDC
gUnk_086EACDC:
	.incbin "baserom_us.gba", 0x6EACDC, 0x8

	.global gUnk_086EACE4
gUnk_086EACE4:
	.incbin "baserom_us.gba", 0x6EACE4, 0x20

	.global gUnk_086EAD04
gUnk_086EAD04:
	.incbin "baserom_us.gba", 0x6EAD04, 0x20

	.global gUnk_086EAD24
gUnk_086EAD24:
	.incbin "baserom_us.gba", 0x6EAD24, 0x20

	.global gUnk_086EAD44
gUnk_086EAD44:
	.incbin "baserom_us.gba", 0x6EAD44, 0x20

	.global gUnk_086EAD64
gUnk_086EAD64:
	.incbin "baserom_us.gba", 0x6EAD64, 0x20

	.global gUnk_086EAD84
gUnk_086EAD84:
	.incbin "baserom_us.gba", 0x6EAD84, 0x8

	.global gUnk_086EAD8C
gUnk_086EAD8C:
	.incbin "baserom_us.gba", 0x6EAD8C, 0x8220

	.global gUnk_086F2FAC
gUnk_086F2FAC:
	.incbin "baserom_us.gba", 0x6F2FAC, 0x7AD4

	.global gUnk_086FAA80
gUnk_086FAA80:
	.incbin "baserom_us.gba", 0x6FAA80, 0x584

	.global gUnk_086FB004
gUnk_086FB004:
	.incbin "baserom_us.gba", 0x6FB004, 0x2198

	.global gUnk_086FD19C
gUnk_086FD19C:
	.incbin "baserom_us.gba", 0x6FD19C, 0xA4

	.global gUnk_086FD240
gUnk_086FD240:
	.incbin "baserom_us.gba", 0x6FD240, 0x177F0

	.global gUnk_08714A30
gUnk_08714A30:
	.incbin "baserom_us.gba", 0x714A30, 0x130

	.global gUnk_08714B60
gUnk_08714B60:
	.incbin "baserom_us.gba", 0x714B60, 0x8C

	.global gUnk_08714BEC
gUnk_08714BEC:
	.incbin "baserom_us.gba", 0x714BEC, 0x2398

	.global gUnk_08716F84
gUnk_08716F84:
	.incbin "baserom_us.gba", 0x716F84, 0x134

	.global gUnk_087170B8
gUnk_087170B8:
	.incbin "baserom_us.gba", 0x7170B8, 0x6464

	.global gUnk_0871D51C
gUnk_0871D51C:
	.incbin "baserom_us.gba", 0x71D51C, 0x128C

	.global gUnk_0871E7A8
gUnk_0871E7A8:
	.incbin "baserom_us.gba", 0x71E7A8, 0x504

	.global gUnk_0871ECAC
gUnk_0871ECAC:
	.incbin "baserom_us.gba", 0x71ECAC, 0x128

	.global gUnk_0871EDD4
gUnk_0871EDD4:
	.incbin "baserom_us.gba", 0x71EDD4, 0x12C

	.global gUnk_0871EF00
gUnk_0871EF00:
	.incbin "baserom_us.gba", 0x71EF00, 0x6EA0

	.global gUnk_08725DA0
gUnk_08725DA0:
	.incbin "baserom_us.gba", 0x725DA0, 0xF2C

	.global gUnk_08726CCC
gUnk_08726CCC:
	.incbin "baserom_us.gba", 0x726CCC, 0x69C

	.global gUnk_08727368
gUnk_08727368:
	.incbin "baserom_us.gba", 0x727368, 0x70C

	.global gUnk_08727A74
gUnk_08727A74:
	.incbin "baserom_us.gba", 0x727A74, 0x794

	.global gUnk_08728208
gUnk_08728208:
	.incbin "baserom_us.gba", 0x728208, 0x118

	.global gUnk_08728320
gUnk_08728320:
	.incbin "baserom_us.gba", 0x728320, 0x105C

	.global gUnk_0872937C
gUnk_0872937C:
	.incbin "baserom_us.gba", 0x72937C, 0xE4

	.global gUnk_08729460
gUnk_08729460:
	.incbin "baserom_us.gba", 0x729460, 0x2A04

	.global gUnk_0872BE64
gUnk_0872BE64:
	.incbin "baserom_us.gba", 0x72BE64, 0x76C

	.global gUnk_0872C5D0
gUnk_0872C5D0:
	.incbin "baserom_us.gba", 0x72C5D0, 0x16C

	.global gUnk_0872C73C
gUnk_0872C73C:
	.incbin "baserom_us.gba", 0x72C73C, 0x110

	.global gUnk_0872C84C
gUnk_0872C84C:
	.incbin "baserom_us.gba", 0x72C84C, 0xD60

	.global gUnk_0872D5AC
gUnk_0872D5AC:
	.incbin "baserom_us.gba", 0x72D5AC, 0x20

	.global gUnk_0872D5CC
gUnk_0872D5CC:
	.incbin "baserom_us.gba", 0x72D5CC, 0x64

	.global gUnk_0872D630
gUnk_0872D630:
	.incbin "baserom_us.gba", 0x72D630, 0xA8

	.global gUnk_0872D6D8
gUnk_0872D6D8:
	.incbin "baserom_us.gba", 0x72D6D8, 0x70C

	.global gUnk_0872DDE4
gUnk_0872DDE4:
	.incbin "baserom_us.gba", 0x72DDE4, 0x60

	.global gUnk_0872DE44
gUnk_0872DE44:
	.incbin "baserom_us.gba", 0x72DE44, 0x1034

	.global gUnk_0872EE78
gUnk_0872EE78:
	.incbin "baserom_us.gba", 0x72EE78, 0x2A4

	.global gUnk_0872F11C
gUnk_0872F11C:
	.incbin "baserom_us.gba", 0x72F11C, 0xA0

	.global gUnk_0872F1BC
gUnk_0872F1BC:
	.incbin "baserom_us.gba", 0x72F1BC, 0x30

	.global gUnk_0872F1EC
gUnk_0872F1EC:
	.incbin "baserom_us.gba", 0x72F1EC, 0x30

	.global gUnk_0872F21C
gUnk_0872F21C:
	.incbin "baserom_us.gba", 0x72F21C, 0x880

	.global gUnk_0872FA9C
gUnk_0872FA9C:
	.incbin "baserom_us.gba", 0x72FA9C, 0x160

	.global gUnk_0872FBFC
gUnk_0872FBFC:
	.incbin "baserom_us.gba", 0x72FBFC, 0x38

	.global gUnk_0872FC34
gUnk_0872FC34:
	.incbin "baserom_us.gba", 0x72FC34, 0x238

	.global gUnk_0872FE6C
gUnk_0872FE6C:
	.incbin "baserom_us.gba", 0x72FE6C, 0x8C

	.global gUnk_0872FEF8
gUnk_0872FEF8:
	.incbin "baserom_us.gba", 0x72FEF8, 0x1A48

	.global gUnk_08731940
gUnk_08731940:
	.incbin "baserom_us.gba", 0x731940, 0x200

	.global gUnk_08731B40 @ChickenPortraits
gUnk_08731B40:
	.incbin "baserom_us.gba", 0x731B40, 0x6604

	.global gUnk_08738144 @gCalendarFont?
gUnk_08738144:
	.incbin "baserom_us.gba", 0x738144, 0x994

	.global gUnk_08738AD8
gUnk_08738AD8:
	.incbin "baserom_us.gba", 0x738AD8, 0x1F0

	.global gUnk_08738CC8
gUnk_08738CC8:
	.incbin "baserom_us.gba", 0x738CC8, 0x28

	.global gUnk_08738CF0
gUnk_08738CF0:
	.incbin "baserom_us.gba", 0x738CF0, 0x2C

	.global gUnk_08738D1C
gUnk_08738D1C:
	.incbin "baserom_us.gba", 0x738D1C, 0xCA8

	.global gUnk_087399C4
gUnk_087399C4:
	.incbin "baserom_us.gba", 0x7399C4, 0xA0

	.global gUnk_08739A64
gUnk_08739A64:
	.incbin "baserom_us.gba", 0x739A64, 0xC84

	.global gUnk_0873A6E8
gUnk_0873A6E8:
	.incbin "baserom_us.gba", 0x73A6E8, 0x76C

	.global gUnk_0873AE54
gUnk_0873AE54:
	.incbin "baserom_us.gba", 0x73AE54, 0x174

	.global gUnk_0873AFC8
gUnk_0873AFC8:
	.incbin "baserom_us.gba", 0x73AFC8, 0xE5C

	.global gUnk_0873BE24
gUnk_0873BE24:
	.incbin "baserom_us.gba", 0x73BE24, 0x124

	.global gUnk_0873BF48
gUnk_0873BF48:
	.incbin "baserom_us.gba", 0x73BF48, 0xA8

	.global gUnk_0873BFF0
gUnk_0873BFF0:
	.incbin "baserom_us.gba", 0x73BFF0, 0xC04

	.global gUnk_0873CBF4
gUnk_0873CBF4:
	.incbin "baserom_us.gba", 0x73CBF4, 0xC0

	.global gUnk_0873CCB4
gUnk_0873CCB4:
	.incbin "baserom_us.gba", 0x73CCB4, 0x1F8

	.global gUnk_0873CEAC
gUnk_0873CEAC:
	.incbin "baserom_us.gba", 0x73CEAC, 0xE4

	.global gUnk_0873CF90
gUnk_0873CF90:
	.incbin "baserom_us.gba", 0x73CF90, 0x2A4

	.global gUnk_0873D234
gUnk_0873D234:
	.incbin "baserom_us.gba", 0x73D234, 0x3C8

	.global gUnk_0873D5FC
gUnk_0873D5FC:
	.incbin "baserom_us.gba", 0x73D5FC, 0xDC

	.global gUnk_0873D6D8
gUnk_0873D6D8:
	.incbin "baserom_us.gba", 0x73D6D8, 0x76C

	.global gUnk_0873DE44
gUnk_0873DE44:
	.incbin "baserom_us.gba", 0x73DE44, 0x76C

	.global gUnk_0873E5B0
gUnk_0873E5B0:
	.incbin "baserom_us.gba", 0x73E5B0, 0x76C

	.global gUnk_0873ED1C
gUnk_0873ED1C:
	.incbin "baserom_us.gba", 0x73ED1C, 0x6AC

	.global gUnk_0873F3C8
gUnk_0873F3C8:
	.incbin "baserom_us.gba", 0x73F3C8, 0x20C

	.global gUnk_0873F5D4
gUnk_0873F5D4:
	.incbin "baserom_us.gba", 0x73F5D4, 0xD8

	.global gUnk_0873F6AC
gUnk_0873F6AC:
	.incbin "baserom_us.gba", 0x73F6AC, 0xA38

	.global gUnk_087400E4
gUnk_087400E4:
	.incbin "baserom_us.gba", 0x7400E4, 0xC0

	.global gUnk_087401A4
gUnk_087401A4:
	.incbin "baserom_us.gba", 0x7401A4, 0x2B0

	.global gUnk_08740454
gUnk_08740454:
	.incbin "baserom_us.gba", 0x740454, 0x14C

	.global gUnk_087405A0
gUnk_087405A0:
	.incbin "baserom_us.gba", 0x7405A0, 0x368

	.global gUnk_08740908
gUnk_08740908:
	.incbin "baserom_us.gba", 0x740908, 0xDC

	.global gUnk_087409E4
gUnk_087409E4:
	.incbin "baserom_us.gba", 0x7409E4, 0x2674

	.global gUnk_08743058
gUnk_08743058:
	.incbin "baserom_us.gba", 0x743058, 0x49BC

	.global gUnk_08747A14
gUnk_08747A14:
	.incbin "baserom_us.gba", 0x747A14, 0x60

	.global gUnk_08747A74
gUnk_08747A74:
	.incbin "baserom_us.gba", 0x747A74, 0x2F4C

	.global gUnk_0874A9C0
gUnk_0874A9C0:
	.incbin "baserom_us.gba", 0x74A9C0, 0x3970

	.global gUnk_0874E330
gUnk_0874E330:
	.incbin "baserom_us.gba", 0x74E330, 0x200

	.global gUnk_0874E530
gUnk_0874E530:
	.incbin "baserom_us.gba", 0x74E530, 0x118

	.global gUnk_0874E648
gUnk_0874E648:
	.incbin "baserom_us.gba", 0x74E648, 0x4F8

	.global gUnk_0874EB40
gUnk_0874EB40:
	.incbin "baserom_us.gba", 0x74EB40, 0x20

	.global gUnk_0874EB60
gUnk_0874EB60:
	.incbin "baserom_us.gba", 0x74EB60, 0x16C

	.global gUnk_0874ECCC
gUnk_0874ECCC:
	.incbin "baserom_us.gba", 0x74ECCC, 0x16C

	.global gUnk_0874EE38
gUnk_0874EE38:
	.incbin "baserom_us.gba", 0x74EE38, 0xDC

	.global gUnk_0874EF14
gUnk_0874EF14:
	.incbin "baserom_us.gba", 0x74EF14, 0x28

	.global gUnk_0874EF3C
gUnk_0874EF3C:
	.incbin "baserom_us.gba", 0x74EF3C, 0xB0

	.global gUnk_0874EFEC
gUnk_0874EFEC:
	.incbin "baserom_us.gba", 0x74EFEC, 0x64

	.global gUnk_0874F050
gUnk_0874F050:
	.incbin "baserom_us.gba", 0x74F050, 0x29C

	.global gUnk_0874F2EC
gUnk_0874F2EC:
	.incbin "baserom_us.gba", 0x74F2EC, 0x60

	.global gUnk_0874F34C
gUnk_0874F34C:
	.incbin "baserom_us.gba", 0x74F34C, 0x1394

	.global gUnk_087506E0
gUnk_087506E0:
	.incbin "baserom_us.gba", 0x7506E0, 0x56C

	.global gUnk_08750C4C
gUnk_08750C4C:
	.incbin "baserom_us.gba", 0x750C4C, 0x20

	.global gUnk_08750C6C
gUnk_08750C6C:
	.incbin "baserom_us.gba", 0x750C6C, 0x20

	.global gUnk_08750C8C
gUnk_08750C8C:
	.incbin "baserom_us.gba", 0x750C8C, 0x1C0

	.global gUnk_08750E4C
gUnk_08750E4C:
	.incbin "baserom_us.gba", 0x750E4C, 0x120

	.global gUnk_08750F6C
gUnk_08750F6C:
	.incbin "baserom_us.gba", 0x750F6C, 0x20

	.global gUnk_08750F8C
gUnk_08750F8C:
	.incbin "baserom_us.gba", 0x750F8C, 0x120

	.global gUnk_087510AC
gUnk_087510AC:
	.incbin "baserom_us.gba", 0x7510AC, 0x120

	.global gUnk_087511CC
gUnk_087511CC:
	.incbin "baserom_us.gba", 0x7511CC, 0x120

	.global gUnk_087512EC
gUnk_087512EC:
	.incbin "baserom_us.gba", 0x7512EC, 0x20

	.global gUnk_0875130C
gUnk_0875130C:
	.incbin "baserom_us.gba", 0x75130C, 0x120

	.global gUnk_0875142C
gUnk_0875142C:
	.incbin "baserom_us.gba", 0x75142C, 0x120

	.global gUnk_0875154C
gUnk_0875154C:
	.incbin "baserom_us.gba", 0x75154C, 0x120

	.global gUnk_0875166C
gUnk_0875166C:
	.incbin "baserom_us.gba", 0x75166C, 0x120

	.global gUnk_0875178C
gUnk_0875178C:
	.incbin "baserom_us.gba", 0x75178C, 0x20

	.global gUnk_087517AC
gUnk_087517AC:
	.incbin "baserom_us.gba", 0x7517AC, 0x120

	.global gUnk_087518CC
gUnk_087518CC:
	.incbin "baserom_us.gba", 0x7518CC, 0x80

	.global gUnk_0875194C
gUnk_0875194C:
	.incbin "baserom_us.gba", 0x75194C, 0x20

	.global gUnk_0875196C
gUnk_0875196C:
	.incbin "baserom_us.gba", 0x75196C, 0x80

	.global gUnk_087519EC
gUnk_087519EC:
	.incbin "baserom_us.gba", 0x7519EC, 0x20

	.global gUnk_08751A0C
gUnk_08751A0C:
	.incbin "baserom_us.gba", 0x751A0C, 0x80

	.global gUnk_08751A8C
gUnk_08751A8C:
	.incbin "baserom_us.gba", 0x751A8C, 0x20

	.global gUnk_08751AAC
gUnk_08751AAC:
	.incbin "baserom_us.gba", 0x751AAC, 0x80

	.global gUnk_08751B2C
gUnk_08751B2C:
	.incbin "baserom_us.gba", 0x751B2C, 0x20

	.global gUnk_08751B4C
gUnk_08751B4C:
	.incbin "baserom_us.gba", 0x751B4C, 0x80

	.global gUnk_08751BCC
gUnk_08751BCC:
	.incbin "baserom_us.gba", 0x751BCC, 0x20

	.global gUnk_08751BEC
gUnk_08751BEC:
	.incbin "baserom_us.gba", 0x751BEC, 0x80

	.global gUnk_08751C6C
gUnk_08751C6C:
	.incbin "baserom_us.gba", 0x751C6C, 0x20

	.global gUnk_08751C8C
gUnk_08751C8C:
	.incbin "baserom_us.gba", 0x751C8C, 0x80

	.global gUnk_08751D0C
gUnk_08751D0C:
	.incbin "baserom_us.gba", 0x751D0C, 0x20

	.global gUnk_08751D2C
gUnk_08751D2C:
	.incbin "baserom_us.gba", 0x751D2C, 0x80

	.global gUnk_08751DAC
gUnk_08751DAC:
	.incbin "baserom_us.gba", 0x751DAC, 0x20

	.global gUnk_08751DCC
gUnk_08751DCC:
	.incbin "baserom_us.gba", 0x751DCC, 0x80

	.global gUnk_08751E4C
gUnk_08751E4C:
	.incbin "baserom_us.gba", 0x751E4C, 0x20

	.global gUnk_08751E6C
gUnk_08751E6C:
	.incbin "baserom_us.gba", 0x751E6C, 0x80

	.global gUnk_08751EEC
gUnk_08751EEC:
	.incbin "baserom_us.gba", 0x751EEC, 0x20

	.global gUnk_08751F0C
gUnk_08751F0C:
	.incbin "baserom_us.gba", 0x751F0C, 0x80

	.global gUnk_08751F8C
gUnk_08751F8C:
	.incbin "baserom_us.gba", 0x751F8C, 0x20

	.global gUnk_08751FAC
gUnk_08751FAC:
	.incbin "baserom_us.gba", 0x751FAC, 0x80

	.global gUnk_0875202C
gUnk_0875202C:
	.incbin "baserom_us.gba", 0x75202C, 0x20

	.global gUnk_0875204C
gUnk_0875204C:
	.incbin "baserom_us.gba", 0x75204C, 0x80

	.global gUnk_087520CC
gUnk_087520CC:
	.incbin "baserom_us.gba", 0x7520CC, 0x20

	.global gUnk_087520EC
gUnk_087520EC:
	.incbin "baserom_us.gba", 0x7520EC, 0x80

	.global gUnk_0875216C
gUnk_0875216C:
	.incbin "baserom_us.gba", 0x75216C, 0x20

	.global gUnk_0875218C
gUnk_0875218C:
	.incbin "baserom_us.gba", 0x75218C, 0x80

	.global gUnk_0875220C
gUnk_0875220C:
	.incbin "baserom_us.gba", 0x75220C, 0x20

	.global gUnk_0875222C
gUnk_0875222C:
	.incbin "baserom_us.gba", 0x75222C, 0x80

	.global gUnk_087522AC
gUnk_087522AC:
	.incbin "baserom_us.gba", 0x7522AC, 0x20

	.global gUnk_087522CC
gUnk_087522CC:
	.incbin "baserom_us.gba", 0x7522CC, 0x80

	.global gUnk_0875234C
gUnk_0875234C:
	.incbin "baserom_us.gba", 0x75234C, 0x20

	.global gUnk_0875236C
gUnk_0875236C:
	.incbin "baserom_us.gba", 0x75236C, 0x80

	.global gUnk_087523EC
gUnk_087523EC:
	.incbin "baserom_us.gba", 0x7523EC, 0x20

	.global gUnk_0875240C
gUnk_0875240C:
	.incbin "baserom_us.gba", 0x75240C, 0x80

	.global gUnk_0875248C
gUnk_0875248C:
	.incbin "baserom_us.gba", 0x75248C, 0x20

	.global gUnk_087524AC
gUnk_087524AC:
	.incbin "baserom_us.gba", 0x7524AC, 0x80

	.global gUnk_0875252C
gUnk_0875252C:
	.incbin "baserom_us.gba", 0x75252C, 0x20

	.global gUnk_0875254C
gUnk_0875254C:
	.incbin "baserom_us.gba", 0x75254C, 0x80

	.global gUnk_087525CC
gUnk_087525CC:
	.incbin "baserom_us.gba", 0x7525CC, 0x20

	.global gUnk_087525EC
gUnk_087525EC:
	.incbin "baserom_us.gba", 0x7525EC, 0x80

	.global gUnk_0875266C
gUnk_0875266C:
	.incbin "baserom_us.gba", 0x75266C, 0x20

	.global gUnk_0875268C
gUnk_0875268C:
	.incbin "baserom_us.gba", 0x75268C, 0x80

	.global gUnk_0875270C
gUnk_0875270C:
	.incbin "baserom_us.gba", 0x75270C, 0x20

	.global gUnk_0875272C
gUnk_0875272C:
	.incbin "baserom_us.gba", 0x75272C, 0x80

	.global gUnk_087527AC
gUnk_087527AC:
	.incbin "baserom_us.gba", 0x7527AC, 0x20

	.global gUnk_087527CC
gUnk_087527CC:
	.incbin "baserom_us.gba", 0x7527CC, 0x80

	.global gUnk_0875284C
gUnk_0875284C:
	.incbin "baserom_us.gba", 0x75284C, 0x20

	.global gUnk_0875286C
gUnk_0875286C:
	.incbin "baserom_us.gba", 0x75286C, 0x80

	.global gUnk_087528EC
gUnk_087528EC:
	.incbin "baserom_us.gba", 0x7528EC, 0x20

	.global gUnk_0875290C
gUnk_0875290C:
	.incbin "baserom_us.gba", 0x75290C, 0x80

	.global gUnk_0875298C
gUnk_0875298C:
	.incbin "baserom_us.gba", 0x75298C, 0x20

	.global gUnk_087529AC
gUnk_087529AC:
	.incbin "baserom_us.gba", 0x7529AC, 0x80

	.global gUnk_08752A2C
gUnk_08752A2C:
	.incbin "baserom_us.gba", 0x752A2C, 0x80

	.global gUnk_08752AAC
gUnk_08752AAC:
	.incbin "baserom_us.gba", 0x752AAC, 0x20

	.global gUnk_08752ACC
gUnk_08752ACC:
	.incbin "baserom_us.gba", 0x752ACC, 0x80

	.global gUnk_08752B4C
gUnk_08752B4C:
	.incbin "baserom_us.gba", 0x752B4C, 0x80

	.global gUnk_08752BCC
gUnk_08752BCC:
	.incbin "baserom_us.gba", 0x752BCC, 0x80

	.global gUnk_08752C4C
gUnk_08752C4C:
	.incbin "baserom_us.gba", 0x752C4C, 0x80

	.global gUnk_08752CCC
gUnk_08752CCC:
	.incbin "baserom_us.gba", 0x752CCC, 0x80

	.global gUnk_08752D4C
gUnk_08752D4C:
	.incbin "baserom_us.gba", 0x752D4C, 0x80

	.global gUnk_08752DCC
gUnk_08752DCC:
	.incbin "baserom_us.gba", 0x752DCC, 0x80

	.global gUnk_08752E4C
gUnk_08752E4C:
	.incbin "baserom_us.gba", 0x752E4C, 0x80

	.global gUnk_08752ECC
gUnk_08752ECC:
	.incbin "baserom_us.gba", 0x752ECC, 0x20

	.global gUnk_08752EEC
gUnk_08752EEC:
	.incbin "baserom_us.gba", 0x752EEC, 0x80

	.global gUnk_08752F6C
gUnk_08752F6C:
	.incbin "baserom_us.gba", 0x752F6C, 0x20

	.global gUnk_08752F8C
gUnk_08752F8C:
	.incbin "baserom_us.gba", 0x752F8C, 0x80

	.global gUnk_0875300C
gUnk_0875300C:
	.incbin "baserom_us.gba", 0x75300C, 0x20

	.global gUnk_0875302C
gUnk_0875302C:
	.incbin "baserom_us.gba", 0x75302C, 0x80

	.global gUnk_087530AC
gUnk_087530AC:
	.incbin "baserom_us.gba", 0x7530AC, 0x20

	.global gUnk_087530CC
gUnk_087530CC:
	.incbin "baserom_us.gba", 0x7530CC, 0x80

	.global gUnk_0875314C
gUnk_0875314C:
	.incbin "baserom_us.gba", 0x75314C, 0x20

	.global gUnk_0875316C
gUnk_0875316C:
	.incbin "baserom_us.gba", 0x75316C, 0x80

	.global gUnk_087531EC
gUnk_087531EC:
	.incbin "baserom_us.gba", 0x7531EC, 0x20

	.global gUnk_0875320C
gUnk_0875320C:
	.incbin "baserom_us.gba", 0x75320C, 0x80

	.global gUnk_0875328C
gUnk_0875328C:
	.incbin "baserom_us.gba", 0x75328C, 0x20

	.global gUnk_087532AC
gUnk_087532AC:
	.incbin "baserom_us.gba", 0x7532AC, 0x80

	.global gUnk_0875332C
gUnk_0875332C:
	.incbin "baserom_us.gba", 0x75332C, 0x20

	.global gUnk_0875334C
gUnk_0875334C:
	.incbin "baserom_us.gba", 0x75334C, 0x80

	.global gUnk_087533CC
gUnk_087533CC:
	.incbin "baserom_us.gba", 0x7533CC, 0x20

	.global gUnk_087533EC
gUnk_087533EC:
	.incbin "baserom_us.gba", 0x7533EC, 0x80

	.global gUnk_0875346C
gUnk_0875346C:
	.incbin "baserom_us.gba", 0x75346C, 0x20

	.global gUnk_0875348C
gUnk_0875348C:
	.incbin "baserom_us.gba", 0x75348C, 0x80

	.global gUnk_0875350C
gUnk_0875350C:
	.incbin "baserom_us.gba", 0x75350C, 0x20

	.global gUnk_0875352C
gUnk_0875352C:
	.incbin "baserom_us.gba", 0x75352C, 0xDC

	.global gUnk_08753608
gUnk_08753608:
	.incbin "baserom_us.gba", 0x753608, 0xDC

	.global gUnk_087536E4
gUnk_087536E4:
	.incbin "baserom_us.gba", 0x7536E4, 0xEC

	.global gUnk_087537D0
gUnk_087537D0:
	.incbin "baserom_us.gba", 0x7537D0, 0xEA4

	.global gUnk_08754674
gUnk_08754674:
	.incbin "baserom_us.gba", 0x754674, 0x598

	.global gUnk_08754C0C
gUnk_08754C0C:
	.incbin "baserom_us.gba", 0x754C0C, 0x548

	.global gUnk_08755154
gUnk_08755154:
	.incbin "baserom_us.gba", 0x755154, 0xDC

	.global gUnk_08755230
gUnk_08755230:
	.incbin "baserom_us.gba", 0x755230, 0x30C

	.global gUnk_0875553C
gUnk_0875553C:
	.incbin "baserom_us.gba", 0x75553C, 0x30C

	.global gUnk_08755848
gUnk_08755848:
	.incbin "baserom_us.gba", 0x755848, 0x2298

	.global gUnk_08757AE0
gUnk_08757AE0:
	.incbin "baserom_us.gba", 0x757AE0, 0xC0

	.global gUnk_08757BA0
gUnk_08757BA0:
	.incbin "baserom_us.gba", 0x757BA0, 0xC

	.global gUnk_08757BAC
gUnk_08757BAC:
	.incbin "baserom_us.gba", 0x757BAC, 0x20

	.global gUnk_08757BCC
gUnk_08757BCC:
	.incbin "baserom_us.gba", 0x757BCC, 0xC

	.global gUnk_08757BD8
gUnk_08757BD8:
	.incbin "baserom_us.gba", 0x757BD8, 0x20

	.global gUnk_08757BF8
gUnk_08757BF8:
	.incbin "baserom_us.gba", 0x757BF8, 0x14

	.global gUnk_08757C0C
gUnk_08757C0C:
	.incbin "baserom_us.gba", 0x757C0C, 0x8

	.global gUnk_08757C14
gUnk_08757C14:
	.incbin "baserom_us.gba", 0x757C14, 0x30C

	.global gUnk_08757F20
gUnk_08757F20:
	.incbin "baserom_us.gba", 0x757F20, 0x30C

	.global gUnk_0875822C
gUnk_0875822C:
	.incbin "baserom_us.gba", 0x75822C, 0x212C

	.global gUnk_0875A358
gUnk_0875A358:
	.incbin "baserom_us.gba", 0x75A358, 0xC0

	.global gUnk_0875A418
gUnk_0875A418:
	.incbin "baserom_us.gba", 0x75A418, 0xC

	.global gUnk_0875A424
gUnk_0875A424:
	.incbin "baserom_us.gba", 0x75A424, 0x14

	.global gUnk_0875A438
gUnk_0875A438:
	.incbin "baserom_us.gba", 0x75A438, 0x8

	.global gUnk_0875A440 @ gClockFont
gUnk_0875A440:
	.incbin "baserom_us.gba", 0x75A440, 0x1004

	.global gUnk_0875B444
gUnk_0875B444:
	.incbin "baserom_us.gba", 0x75B444, 0x5B4
    .endif
