    .section .rodata

    @ Direct physical labels for the map and field-render resource island.
    @ These payloads are raw assets, not inferred C structures.  Each label
    @ begins at its own emitted bytes so C/C++ references are real symbols,
    @ rather than aliases into a parent incbin object.
    .macro FOMT_STATIC_RESOURCE_INCBIN offset, length
    .ifdef REGION_JP
        .incbin "baserom_jp.gba", 0x118D18 + \offset, \length
    .else
    .ifdef REGION_EU
        .incbin "baserom_eu.gba", 0x117C2C + \offset, \length
    .else
    .ifdef REGION_DE
        .incbin "baserom_de.gba", 0x119C54 + \offset, \length
    .else
        .incbin "baserom_us.gba", 0x117BD4 + \offset, \length
    .endif
    .endif
    .endif
    .endm

    .global gUnk_FieldRenderResource_146
gUnk_FieldRenderResource_146:
    FOMT_STATIC_RESOURCE_INCBIN 0x0, 0xC

    .global gUnk_FieldRenderResource_147
gUnk_FieldRenderResource_147:
    FOMT_STATIC_RESOURCE_INCBIN 0xC, 0x100

    .global gUnk_MapDataResource_098
gUnk_MapDataResource_098:
    FOMT_STATIC_RESOURCE_INCBIN 0x10C, 0x30

    .global gUnk_MapDataResource_099
gUnk_MapDataResource_099:
    FOMT_STATIC_RESOURCE_INCBIN 0x13C, 0x3A98

    .global gUnk_FieldRenderResource_120
gUnk_FieldRenderResource_120:
    FOMT_STATIC_RESOURCE_INCBIN 0x3BD4, 0x14

    .global gUnk_FieldRenderResource_121
gUnk_FieldRenderResource_121:
    FOMT_STATIC_RESOURCE_INCBIN 0x3BE8, 0x690

    .global gUnk_MapDataResource_247
gUnk_MapDataResource_247:
    FOMT_STATIC_RESOURCE_INCBIN 0x4278, 0x20

    .global gUnk_MapDataResource_248
gUnk_MapDataResource_248:
    FOMT_STATIC_RESOURCE_INCBIN 0x4298, 0x348

    .global gUnk_MapDataResource_062
gUnk_MapDataResource_062:
    FOMT_STATIC_RESOURCE_INCBIN 0x45E0, 0x34

    .global gUnk_MapDataResource_063
gUnk_MapDataResource_063:
    FOMT_STATIC_RESOURCE_INCBIN 0x4614, 0x1400

    .global gUnk_FieldRenderResource_137
gUnk_FieldRenderResource_137:
    FOMT_STATIC_RESOURCE_INCBIN 0x5A14, 0x10

    .global gUnk_FieldRenderResource_138
gUnk_FieldRenderResource_138:
    FOMT_STATIC_RESOURCE_INCBIN 0x5A24, 0x318

    .global gUnk_FieldRenderResource_130
gUnk_FieldRenderResource_130:
    FOMT_STATIC_RESOURCE_INCBIN 0x5D3C, 0x14

    .global gUnk_FieldRenderResource_131
gUnk_FieldRenderResource_131:
    FOMT_STATIC_RESOURCE_INCBIN 0x5D50, 0x154

    .global gUnk_FieldRenderResource_141
gUnk_FieldRenderResource_141:
    FOMT_STATIC_RESOURCE_INCBIN 0x5EA4, 0x8

    .global gUnk_FieldRenderResource_142
gUnk_FieldRenderResource_142:
    FOMT_STATIC_RESOURCE_INCBIN 0x5EAC, 0x18

    .global gUnk_MapDataResource_271
gUnk_MapDataResource_271:
    FOMT_STATIC_RESOURCE_INCBIN 0x5EC4, 0x34

    .global gUnk_MapDataResource_272
gUnk_MapDataResource_272:
    FOMT_STATIC_RESOURCE_INCBIN 0x5EF8, 0x348

    .global gUnk_MapDataResource_276
gUnk_MapDataResource_276:
    FOMT_STATIC_RESOURCE_INCBIN 0x6240, 0x30

    .global gUnk_MapDataResource_277
gUnk_MapDataResource_277:
    FOMT_STATIC_RESOURCE_INCBIN 0x6270, 0x348

    .global gUnk_FieldRenderResource_212
gUnk_FieldRenderResource_212:
    FOMT_STATIC_RESOURCE_INCBIN 0x65B8, 0x4

    .global gUnk_FieldRenderResource_213
gUnk_FieldRenderResource_213:
    FOMT_STATIC_RESOURCE_INCBIN 0x65BC, 0x10

    .global gUnk_FieldRenderResource_208
gUnk_FieldRenderResource_208:
    FOMT_STATIC_RESOURCE_INCBIN 0x65CC, 0x4

    .global gUnk_FieldRenderResource_209
gUnk_FieldRenderResource_209:
    FOMT_STATIC_RESOURCE_INCBIN 0x65D0, 0x10

    .global gUnk_MapDataResource_198
gUnk_MapDataResource_198:
    FOMT_STATIC_RESOURCE_INCBIN 0x65E0, 0x28

    .global gUnk_MapDataResource_199
gUnk_MapDataResource_199:
    FOMT_STATIC_RESOURCE_INCBIN 0x6608, 0x78C

    .global gUnk_MapDataResource_181
gUnk_MapDataResource_181:
    FOMT_STATIC_RESOURCE_INCBIN 0x6D94, 0x30

    .global gUnk_MapDataResource_182
gUnk_MapDataResource_182:
    FOMT_STATIC_RESOURCE_INCBIN 0x6DC4, 0x348

    .global gUnk_FieldRenderResource_041
gUnk_FieldRenderResource_041:
    FOMT_STATIC_RESOURCE_INCBIN 0x710C, 0xC

    .global gUnk_FieldRenderResource_042
gUnk_FieldRenderResource_042:
    FOMT_STATIC_RESOURCE_INCBIN 0x7118, 0xF0

    .global gUnk_FieldRenderResource_033
gUnk_FieldRenderResource_033:
    FOMT_STATIC_RESOURCE_INCBIN 0x7208, 0xC

    .global gUnk_FieldRenderResource_034
gUnk_FieldRenderResource_034:
    FOMT_STATIC_RESOURCE_INCBIN 0x7214, 0x80

    .global gUnk_MapDataResource_006
gUnk_MapDataResource_006:
    FOMT_STATIC_RESOURCE_INCBIN 0x7294, 0x48

    .global gUnk_MapDataResource_007
gUnk_MapDataResource_007:
    FOMT_STATIC_RESOURCE_INCBIN 0x72DC, 0x2C00

    .global gUnk_FieldRenderResource_014
gUnk_FieldRenderResource_014:
    FOMT_STATIC_RESOURCE_INCBIN 0x9EDC, 0xC

    .global gUnk_FieldRenderResource_015
gUnk_FieldRenderResource_015:
    FOMT_STATIC_RESOURCE_INCBIN 0x9EE8, 0x138

    .global gUnk_FieldRenderResource_008
gUnk_FieldRenderResource_008:
    FOMT_STATIC_RESOURCE_INCBIN 0xA020, 0xC

    .global gUnk_FieldRenderResource_009
gUnk_FieldRenderResource_009:
    FOMT_STATIC_RESOURCE_INCBIN 0xA02C, 0xD0

    .global gUnk_FieldRenderResource_002
gUnk_FieldRenderResource_002:
    FOMT_STATIC_RESOURCE_INCBIN 0xA0FC, 0xC

    .global gUnk_FieldRenderResource_003
gUnk_FieldRenderResource_003:
    FOMT_STATIC_RESOURCE_INCBIN 0xA108, 0x68

    .global gUnk_FieldRenderResource_026
gUnk_FieldRenderResource_026:
    FOMT_STATIC_RESOURCE_INCBIN 0xA170, 0xC

    .global gUnk_FieldRenderResource_027
gUnk_FieldRenderResource_027:
    FOMT_STATIC_RESOURCE_INCBIN 0xA17C, 0x134

    .global gUnk_FieldRenderResource_020
gUnk_FieldRenderResource_020:
    FOMT_STATIC_RESOURCE_INCBIN 0xA2B0, 0xC

    .global gUnk_FieldRenderResource_021
gUnk_FieldRenderResource_021:
    FOMT_STATIC_RESOURCE_INCBIN 0xA2BC, 0xA8

    .global gUnk_MapDataResource_087
gUnk_MapDataResource_087:
    FOMT_STATIC_RESOURCE_INCBIN 0xA364, 0x24

    .global gUnk_MapDataResource_088
gUnk_MapDataResource_088:
    FOMT_STATIC_RESOURCE_INCBIN 0xA388, 0x2000

    .global gUnk_MapDataResource_312
gUnk_MapDataResource_312:
    FOMT_STATIC_RESOURCE_INCBIN 0xC388, 0x30

    .global gUnk_MapDataResource_313
gUnk_MapDataResource_313:
    FOMT_STATIC_RESOURCE_INCBIN 0xC3B8, 0x348

    .global gUnk_MapDataResource_171
gUnk_MapDataResource_171:
    FOMT_STATIC_RESOURCE_INCBIN 0xC700, 0x40

    .global gUnk_MapDataResource_172
gUnk_MapDataResource_172:
    FOMT_STATIC_RESOURCE_INCBIN 0xC740, 0x5E8

    .global gUnk_FieldRenderResource_155
gUnk_FieldRenderResource_155:
    FOMT_STATIC_RESOURCE_INCBIN 0xCD28, 0x4

    .global gUnk_FieldRenderResource_156
gUnk_FieldRenderResource_156:
    FOMT_STATIC_RESOURCE_INCBIN 0xCD2C, 0x8

    .global gUnk_FieldRenderResource_220
gUnk_FieldRenderResource_220:
    FOMT_STATIC_RESOURCE_INCBIN 0xCD34, 0x4

    .global gUnk_FieldRenderResource_221
gUnk_FieldRenderResource_221:
    FOMT_STATIC_RESOURCE_INCBIN 0xCD38, 0x10

    .global gUnk_MapDataResource_164
gUnk_MapDataResource_164:
    FOMT_STATIC_RESOURCE_INCBIN 0xCD48, 0x48

    .global gUnk_MapDataResource_165
gUnk_MapDataResource_165:
    FOMT_STATIC_RESOURCE_INCBIN 0xCD90, 0x5E8

    .global gUnk_FieldRenderResource_152
gUnk_FieldRenderResource_152:
    FOMT_STATIC_RESOURCE_INCBIN 0xD378, 0x4

    .global gUnk_FieldRenderResource_153
gUnk_FieldRenderResource_153:
    FOMT_STATIC_RESOURCE_INCBIN 0xD37C, 0x8

    .global gUnk_FieldRenderResource_167
gUnk_FieldRenderResource_167:
    FOMT_STATIC_RESOURCE_INCBIN 0xD384, 0x4

    .global gUnk_FieldRenderResource_168
gUnk_FieldRenderResource_168:
    FOMT_STATIC_RESOURCE_INCBIN 0xD388, 0x30

    .global gUnk_FieldRenderResource_161
gUnk_FieldRenderResource_161:
    FOMT_STATIC_RESOURCE_INCBIN 0xD3B8, 0x4

    .global gUnk_FieldRenderResource_162
gUnk_FieldRenderResource_162:
    FOMT_STATIC_RESOURCE_INCBIN 0xD3BC, 0x30

    .global gUnk_FieldRenderResource_164
gUnk_FieldRenderResource_164:
    FOMT_STATIC_RESOURCE_INCBIN 0xD3EC, 0x4

    .global gUnk_FieldRenderResource_165
gUnk_FieldRenderResource_165:
    FOMT_STATIC_RESOURCE_INCBIN 0xD3F0, 0x30

    .global gUnk_FieldRenderResource_108
gUnk_FieldRenderResource_108:
    FOMT_STATIC_RESOURCE_INCBIN 0xD420, 0x8

    .global gUnk_FieldRenderResource_109
gUnk_FieldRenderResource_109:
    FOMT_STATIC_RESOURCE_INCBIN 0xD428, 0x10

    .global gUnk_MapDataResource_232
gUnk_MapDataResource_232:
    FOMT_STATIC_RESOURCE_INCBIN 0xD438, 0x44

    .global gUnk_MapDataResource_233
gUnk_MapDataResource_233:
    FOMT_STATIC_RESOURCE_INCBIN 0xD47C, 0x498

    .global gUnk_MapDataResource_227
gUnk_MapDataResource_227:
    FOMT_STATIC_RESOURCE_INCBIN 0xD914, 0x2C

    .global gUnk_MapDataResource_228
gUnk_MapDataResource_228:
    FOMT_STATIC_RESOURCE_INCBIN 0xD940, 0x348

    .global gUnk_MapDataResource_326
gUnk_MapDataResource_326:
    FOMT_STATIC_RESOURCE_INCBIN 0xDC88, 0x24

    .global gUnk_MapDataResource_327
gUnk_MapDataResource_327:
    FOMT_STATIC_RESOURCE_INCBIN 0xDCAC, 0x348

    .global gUnk_MapDataResource_188
gUnk_MapDataResource_188:
    FOMT_STATIC_RESOURCE_INCBIN 0xDFF4, 0x38

    .global gUnk_MapDataResource_189
gUnk_MapDataResource_189:
    FOMT_STATIC_RESOURCE_INCBIN 0xE02C, 0x78C

    .global gUnk_FieldRenderResource_204
gUnk_FieldRenderResource_204:
    FOMT_STATIC_RESOURCE_INCBIN 0xE7B8, 0x4

    .global gUnk_FieldRenderResource_205
gUnk_FieldRenderResource_205:
    FOMT_STATIC_RESOURCE_INCBIN 0xE7BC, 0x10

    .global gUnk_FieldRenderResource_200
gUnk_FieldRenderResource_200:
    FOMT_STATIC_RESOURCE_INCBIN 0xE7CC, 0x4

    .global gUnk_FieldRenderResource_201
gUnk_FieldRenderResource_201:
    FOMT_STATIC_RESOURCE_INCBIN 0xE7D0, 0x10

    .global gUnk_MapDataResource_193
gUnk_MapDataResource_193:
    FOMT_STATIC_RESOURCE_INCBIN 0xE7E0, 0x30

    .global gUnk_MapDataResource_194
gUnk_MapDataResource_194:
    FOMT_STATIC_RESOURCE_INCBIN 0xE810, 0x78C

    .global gUnk_FieldRenderResource_180
gUnk_FieldRenderResource_180:
    FOMT_STATIC_RESOURCE_INCBIN 0xEF9C, 0x4

    .global gUnk_FieldRenderResource_181
gUnk_FieldRenderResource_181:
    FOMT_STATIC_RESOURCE_INCBIN 0xEFA0, 0x10

    .global gUnk_MapDataResource_147
gUnk_MapDataResource_147:
    FOMT_STATIC_RESOURCE_INCBIN 0xEFB0, 0x30

    .global gUnk_MapDataResource_148
gUnk_MapDataResource_148:
    FOMT_STATIC_RESOURCE_INCBIN 0xEFE0, 0x78C

    .global gUnk_FieldRenderResource_188
gUnk_FieldRenderResource_188:
    FOMT_STATIC_RESOURCE_INCBIN 0xF76C, 0x4

    .global gUnk_FieldRenderResource_189
gUnk_FieldRenderResource_189:
    FOMT_STATIC_RESOURCE_INCBIN 0xF770, 0x10

    .global gUnk_FieldRenderResource_184
gUnk_FieldRenderResource_184:
    FOMT_STATIC_RESOURCE_INCBIN 0xF780, 0x4

    .global gUnk_FieldRenderResource_185
gUnk_FieldRenderResource_185:
    FOMT_STATIC_RESOURCE_INCBIN 0xF784, 0x10

    .global gUnk_MapDataResource_152
gUnk_MapDataResource_152:
    FOMT_STATIC_RESOURCE_INCBIN 0xF794, 0x3C

    .global gUnk_MapDataResource_153
gUnk_MapDataResource_153:
    FOMT_STATIC_RESOURCE_INCBIN 0xF7D0, 0x78C

    .global gUnk_FieldRenderResource_171
gUnk_FieldRenderResource_171:
    FOMT_STATIC_RESOURCE_INCBIN 0xFF5C, 0x4

    .global gUnk_FieldRenderResource_172
gUnk_FieldRenderResource_172:
    FOMT_STATIC_RESOURCE_INCBIN 0xFF60, 0xC

    .global gUnk_FieldRenderResource_196
gUnk_FieldRenderResource_196:
    FOMT_STATIC_RESOURCE_INCBIN 0xFF6C, 0x4

    .global gUnk_FieldRenderResource_197
gUnk_FieldRenderResource_197:
    FOMT_STATIC_RESOURCE_INCBIN 0xFF70, 0x10

    .global gUnk_FieldRenderResource_192
gUnk_FieldRenderResource_192:
    FOMT_STATIC_RESOURCE_INCBIN 0xFF80, 0x4

    .global gUnk_FieldRenderResource_193
gUnk_FieldRenderResource_193:
    FOMT_STATIC_RESOURCE_INCBIN 0xFF84, 0x10

    .global gUnk_MapDataResource_157
gUnk_MapDataResource_157:
    FOMT_STATIC_RESOURCE_INCBIN 0xFF94, 0x2C

    .global gUnk_MapDataResource_158
gUnk_MapDataResource_158:
    FOMT_STATIC_RESOURCE_INCBIN 0xFFC0, 0x78C

    .global gUnk_MapDataResource_215
gUnk_MapDataResource_215:
    FOMT_STATIC_RESOURCE_INCBIN 0x1074C, 0x28

    .global gUnk_MapDataResource_216
gUnk_MapDataResource_216:
    FOMT_STATIC_RESOURCE_INCBIN 0x10774, 0x348

    .global gUnk_MapDataResource_220
gUnk_MapDataResource_220:
    FOMT_STATIC_RESOURCE_INCBIN 0x10ABC, 0x28

    .global gUnk_MapDataResource_221
gUnk_MapDataResource_221:
    FOMT_STATIC_RESOURCE_INCBIN 0x10AE4, 0x348

    .global gUnk_MapDataResource_205
gUnk_MapDataResource_205:
    FOMT_STATIC_RESOURCE_INCBIN 0x10E2C, 0x34

    .global gUnk_MapDataResource_206
gUnk_MapDataResource_206:
    FOMT_STATIC_RESOURCE_INCBIN 0x10E60, 0x348

    .global gUnk_MapDataResource_210
gUnk_MapDataResource_210:
    FOMT_STATIC_RESOURCE_INCBIN 0x111A8, 0x3C

    .global gUnk_MapDataResource_211
gUnk_MapDataResource_211:
    FOMT_STATIC_RESOURCE_INCBIN 0x111E4, 0x348

    .global gUnk_MapDataResource_319
gUnk_MapDataResource_319:
    FOMT_STATIC_RESOURCE_INCBIN 0x1152C, 0x28

    .global gUnk_MapDataResource_320
gUnk_MapDataResource_320:
    FOMT_STATIC_RESOURCE_INCBIN 0x11554, 0x348

    .global gUnk_MapDataResource_307
gUnk_MapDataResource_307:
    FOMT_STATIC_RESOURCE_INCBIN 0x1189C, 0x2C

    .global gUnk_MapDataResource_308
gUnk_MapDataResource_308:
    FOMT_STATIC_RESOURCE_INCBIN 0x118C8, 0x348

    .global gUnk_FieldRenderResource_104
gUnk_FieldRenderResource_104:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C10, 0x4

    .global gUnk_FieldRenderResource_105
gUnk_FieldRenderResource_105:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C14, 0x10

    .global gUnk_FieldRenderResource_090
gUnk_FieldRenderResource_090:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C24, 0x8

    .global gUnk_FieldRenderResource_091
gUnk_FieldRenderResource_091:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C2C, 0x30

    .global gUnk_FieldRenderResource_100
gUnk_FieldRenderResource_100:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C5C, 0xC

    .global gUnk_FieldRenderResource_101
gUnk_FieldRenderResource_101:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C68, 0x14

    .global gUnk_FieldRenderResource_084
gUnk_FieldRenderResource_084:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C7C, 0xC

    .global gUnk_FieldRenderResource_085
gUnk_FieldRenderResource_085:
    FOMT_STATIC_RESOURCE_INCBIN 0x11C88, 0x98

    .global gUnk_MapDataResource_264
gUnk_MapDataResource_264:
    FOMT_STATIC_RESOURCE_INCBIN 0x11D20, 0x34

    .global gUnk_MapDataResource_265
gUnk_MapDataResource_265:
    FOMT_STATIC_RESOURCE_INCBIN 0x11D54, 0x674

    .global gUnk_FieldRenderResource_097
gUnk_FieldRenderResource_097:
    FOMT_STATIC_RESOURCE_INCBIN 0x123C8, 0x4

    .global gUnk_FieldRenderResource_098
gUnk_FieldRenderResource_098:
    FOMT_STATIC_RESOURCE_INCBIN 0x123CC, 0xC

    .global gUnk_MapDataResource_259
gUnk_MapDataResource_259:
    FOMT_STATIC_RESOURCE_INCBIN 0x123D8, 0x34

    .global gUnk_MapDataResource_260
gUnk_MapDataResource_260:
    FOMT_STATIC_RESOURCE_INCBIN 0x1240C, 0x4EC

    .global gUnk_FieldRenderResource_072
gUnk_FieldRenderResource_072:
    FOMT_STATIC_RESOURCE_INCBIN 0x128F8, 0x8

    .global gUnk_FieldRenderResource_073
gUnk_FieldRenderResource_073:
    FOMT_STATIC_RESOURCE_INCBIN 0x12900, 0xC

    .global gUnk_FieldRenderResource_080
gUnk_FieldRenderResource_080:
    FOMT_STATIC_RESOURCE_INCBIN 0x1290C, 0x8

    .global gUnk_FieldRenderResource_081
gUnk_FieldRenderResource_081:
    FOMT_STATIC_RESOURCE_INCBIN 0x12914, 0xC

    .global gUnk_FieldRenderResource_076
gUnk_FieldRenderResource_076:
    FOMT_STATIC_RESOURCE_INCBIN 0x12920, 0x8

    .global gUnk_FieldRenderResource_077
gUnk_FieldRenderResource_077:
    FOMT_STATIC_RESOURCE_INCBIN 0x12928, 0xC

    .global gUnk_FieldRenderResource_060
gUnk_FieldRenderResource_060:
    FOMT_STATIC_RESOURCE_INCBIN 0x12934, 0x8

    .global gUnk_FieldRenderResource_061
gUnk_FieldRenderResource_061:
    FOMT_STATIC_RESOURCE_INCBIN 0x1293C, 0x18

    .global gUnk_FieldRenderResource_056
gUnk_FieldRenderResource_056:
    FOMT_STATIC_RESOURCE_INCBIN 0x12954, 0x8

    .global gUnk_FieldRenderResource_057
gUnk_FieldRenderResource_057:
    FOMT_STATIC_RESOURCE_INCBIN 0x1295C, 0x18

    .global gUnk_FieldRenderResource_068
gUnk_FieldRenderResource_068:
    FOMT_STATIC_RESOURCE_INCBIN 0x12974, 0x8

    .global gUnk_FieldRenderResource_069
gUnk_FieldRenderResource_069:
    FOMT_STATIC_RESOURCE_INCBIN 0x1297C, 0x1C

    .global gUnk_FieldRenderResource_064
gUnk_FieldRenderResource_064:
    FOMT_STATIC_RESOURCE_INCBIN 0x12998, 0x4

    .global gUnk_FieldRenderResource_065
gUnk_FieldRenderResource_065:
    FOMT_STATIC_RESOURCE_INCBIN 0x1299C, 0x1C

    .global gUnk_FieldRenderResource_087
gUnk_FieldRenderResource_087:
    FOMT_STATIC_RESOURCE_INCBIN 0x129B8, 0xC

    .global gUnk_FieldRenderResource_088
gUnk_FieldRenderResource_088:
    FOMT_STATIC_RESOURCE_INCBIN 0x129C4, 0x30

    .global gUnk_MapDataResource_254
gUnk_MapDataResource_254:
    FOMT_STATIC_RESOURCE_INCBIN 0x129F4, 0x30

    .global gUnk_MapDataResource_255
gUnk_MapDataResource_255:
    FOMT_STATIC_RESOURCE_INCBIN 0x12A24, 0x348

    .global gUnk_FieldRenderResource_052
gUnk_FieldRenderResource_052:
    FOMT_STATIC_RESOURCE_INCBIN 0x12D6C, 0x8

    .global gUnk_FieldRenderResource_053
gUnk_FieldRenderResource_053:
    FOMT_STATIC_RESOURCE_INCBIN 0x12D74, 0x18

    .global gUnk_FieldRenderResource_048
gUnk_FieldRenderResource_048:
    FOMT_STATIC_RESOURCE_INCBIN 0x12D8C, 0x8

    .global gUnk_FieldRenderResource_049
gUnk_FieldRenderResource_049:
    FOMT_STATIC_RESOURCE_INCBIN 0x12D94, 0x18

    .global gUnk_FieldRenderResource_094
gUnk_FieldRenderResource_094:
    FOMT_STATIC_RESOURCE_INCBIN 0x12DAC, 0x4

    .global gUnk_FieldRenderResource_095
gUnk_FieldRenderResource_095:
    FOMT_STATIC_RESOURCE_INCBIN 0x12DB0, 0x8

    .global gUnk_MapDataResource_076
gUnk_MapDataResource_076:
    FOMT_STATIC_RESOURCE_INCBIN 0x12DB8, 0x14

    .global gUnk_MapDataResource_077
gUnk_MapDataResource_077:
    FOMT_STATIC_RESOURCE_INCBIN 0x12DCC, 0xC00

    .global gUnk_MapDataResource_034
gUnk_MapDataResource_034:
    FOMT_STATIC_RESOURCE_INCBIN 0x139CC, 0x84

    .global gUnk_MapDataResource_035
gUnk_MapDataResource_035:
    FOMT_STATIC_RESOURCE_INCBIN 0x13A50, 0x3C80

    .global gUnk_MapDataResource_125
gUnk_MapDataResource_125:
    FOMT_STATIC_RESOURCE_INCBIN 0x176D0, 0x34

    .global gUnk_MapDataResource_126
gUnk_MapDataResource_126:
    FOMT_STATIC_RESOURCE_INCBIN 0x17704, 0x348

    .global gUnk_FieldRenderResource_174
gUnk_FieldRenderResource_174:
    FOMT_STATIC_RESOURCE_INCBIN 0x17A4C, 0x4

    .global gUnk_FieldRenderResource_175
gUnk_FieldRenderResource_175:
    FOMT_STATIC_RESOURCE_INCBIN 0x17A50, 0x10

    .global gUnk_MapDataResource_130
gUnk_MapDataResource_130:
    FOMT_STATIC_RESOURCE_INCBIN 0x17A60, 0x28

    .global gUnk_MapDataResource_131
gUnk_MapDataResource_131:
    FOMT_STATIC_RESOURCE_INCBIN 0x17A88, 0x348

    .global gUnk_MapDataResource_343
gUnk_MapDataResource_343:
    FOMT_STATIC_RESOURCE_INCBIN 0x17DD0, 0xC

    .global gUnk_MapDataResource_344
gUnk_MapDataResource_344:
    FOMT_STATIC_RESOURCE_INCBIN 0x17DDC, 0x30C

    .global gUnk_MapDataResource_348
gUnk_MapDataResource_348:
    FOMT_STATIC_RESOURCE_INCBIN 0x180E8, 0x8

    .global gUnk_MapDataResource_349
gUnk_MapDataResource_349:
    FOMT_STATIC_RESOURCE_INCBIN 0x180F0, 0x1068

    .global gUnk_MapDataResource_353
gUnk_MapDataResource_353:
    FOMT_STATIC_RESOURCE_INCBIN 0x19158, 0x8

    .global gUnk_MapDataResource_354
gUnk_MapDataResource_354:
    FOMT_STATIC_RESOURCE_INCBIN 0x19160, 0x4EC

    .global gUnk_MapDataResource_358
gUnk_MapDataResource_358:
    FOMT_STATIC_RESOURCE_INCBIN 0x1964C, 0x8

    .global gUnk_MapDataResource_359
gUnk_MapDataResource_359:
    FOMT_STATIC_RESOURCE_INCBIN 0x19654, 0x30C

    .global gUnk_MapDataResource_363
gUnk_MapDataResource_363:
    FOMT_STATIC_RESOURCE_INCBIN 0x19960, 0x10

    .global gUnk_MapDataResource_364
gUnk_MapDataResource_364:
    FOMT_STATIC_RESOURCE_INCBIN 0x19970, 0x258

    .global gUnk_MapDataResource_368
gUnk_MapDataResource_368:
    FOMT_STATIC_RESOURCE_INCBIN 0x19BC8, 0xC

    .global gUnk_MapDataResource_369
gUnk_MapDataResource_369:
    FOMT_STATIC_RESOURCE_INCBIN 0x19BD4, 0x30C

    .global gUnk_FarmHouseVisualResource_002
gUnk_FarmHouseVisualResource_002:
    FOMT_STATIC_RESOURCE_INCBIN 0x19EE0, 0x8

    .global gUnk_FarmHouseVisualResource_003
gUnk_FarmHouseVisualResource_003:
    FOMT_STATIC_RESOURCE_INCBIN 0x19EE8, 0x18

    .global gUnk_MapDataResource_020
gUnk_MapDataResource_020:
    FOMT_STATIC_RESOURCE_INCBIN 0x19F00, 0x28

    .global gUnk_MapDataResource_021
gUnk_MapDataResource_021:
    FOMT_STATIC_RESOURCE_INCBIN 0x19F28, 0xD20

    .global gUnk_FarmHouseVisualResource_008
gUnk_FarmHouseVisualResource_008:
    FOMT_STATIC_RESOURCE_INCBIN 0x1AC48, 0x8

    .global gUnk_FarmHouseVisualResource_009
gUnk_FarmHouseVisualResource_009:
    FOMT_STATIC_RESOURCE_INCBIN 0x1AC50, 0x6C

    .global gUnk_FarmHouseVisualResource_032
gUnk_FarmHouseVisualResource_032:
    FOMT_STATIC_RESOURCE_INCBIN 0x1ACBC, 0x8

    .global gUnk_FarmHouseVisualResource_033
gUnk_FarmHouseVisualResource_033:
    FOMT_STATIC_RESOURCE_INCBIN 0x1ACC4, 0x14

    .global gUnk_FarmHouseVisualResource_039
gUnk_FarmHouseVisualResource_039:
    FOMT_STATIC_RESOURCE_INCBIN 0x1ACD8, 0x8

    .global gUnk_FarmHouseVisualResource_040
gUnk_FarmHouseVisualResource_040:
    FOMT_STATIC_RESOURCE_INCBIN 0x1ACE0, 0x90

    .global gUnk_FarmHouseVisualResource_020
gUnk_FarmHouseVisualResource_020:
    FOMT_STATIC_RESOURCE_INCBIN 0x1AD70, 0x8

    .global gUnk_FarmHouseVisualResource_021
gUnk_FarmHouseVisualResource_021:
    FOMT_STATIC_RESOURCE_INCBIN 0x1AD78, 0x9C

    .global gUnk_FarmHouseVisualResource_026
gUnk_FarmHouseVisualResource_026:
    FOMT_STATIC_RESOURCE_INCBIN 0x1AE14, 0x8

    .global gUnk_FarmHouseVisualResource_027
gUnk_FarmHouseVisualResource_027:
    FOMT_STATIC_RESOURCE_INCBIN 0x1AE1C, 0x288

    .global gUnk_MapDataResource_135
gUnk_MapDataResource_135:
    FOMT_STATIC_RESOURCE_INCBIN 0x1B0A4, 0x20

    .global gUnk_MapDataResource_136
gUnk_MapDataResource_136:
    FOMT_STATIC_RESOURCE_INCBIN 0x1B0C4, 0x348

    .global gUnk_MapDataResource_140
gUnk_MapDataResource_140:
    FOMT_STATIC_RESOURCE_INCBIN 0x1B40C, 0x1C

    .global gUnk_MapDataResource_141
gUnk_MapDataResource_141:
    FOMT_STATIC_RESOURCE_INCBIN 0x1B428, 0x348

    .global gUnk_MapDataResource_331
gUnk_MapDataResource_331:
    FOMT_STATIC_RESOURCE_INCBIN 0x1B770, 0x28

    .global gUnk_MapDataResource_332
gUnk_MapDataResource_332:
    FOMT_STATIC_RESOURCE_INCBIN 0x1B798, 0x348

    .global gUnk_MapDataResource_176
gUnk_MapDataResource_176:
    FOMT_STATIC_RESOURCE_INCBIN 0x1BAE0, 0x30

    .global gUnk_MapDataResource_177
gUnk_MapDataResource_177:
    FOMT_STATIC_RESOURCE_INCBIN 0x1BB10, 0x348

    .global gUnk_FieldRenderResource_116
gUnk_FieldRenderResource_116:
    FOMT_STATIC_RESOURCE_INCBIN 0x1BE58, 0x8

    .global gUnk_FieldRenderResource_117
gUnk_FieldRenderResource_117:
    FOMT_STATIC_RESOURCE_INCBIN 0x1BE60, 0x10

    .global gUnk_MapDataResource_242
gUnk_MapDataResource_242:
    FOMT_STATIC_RESOURCE_INCBIN 0x1BE70, 0x64

    .global gUnk_MapDataResource_243
gUnk_MapDataResource_243:
    FOMT_STATIC_RESOURCE_INCBIN 0x1BED4, 0xAB0

    .global gUnk_MapDataResource_237
gUnk_MapDataResource_237:
    FOMT_STATIC_RESOURCE_INCBIN 0x1C984, 0x3C

    .global gUnk_MapDataResource_238
gUnk_MapDataResource_238:
    FOMT_STATIC_RESOURCE_INCBIN 0x1C9C0, 0x678

    .global gUnk_FieldRenderResource_112
gUnk_FieldRenderResource_112:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D038, 0x8

    .global gUnk_FieldRenderResource_113
gUnk_FieldRenderResource_113:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D040, 0x10

    .global gUnk_FieldRenderResource_216
gUnk_FieldRenderResource_216:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D050, 0x4

    .global gUnk_FieldRenderResource_217
gUnk_FieldRenderResource_217:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D054, 0x10

    .global gUnk_MapDataResource_295
gUnk_MapDataResource_295:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D064, 0x30

    .global gUnk_MapDataResource_296
gUnk_MapDataResource_296:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D094, 0x348

    .global gUnk_MapDataResource_048
gUnk_MapDataResource_048:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D3DC, 0x4C

    .global gUnk_MapDataResource_049
gUnk_MapDataResource_049:
    FOMT_STATIC_RESOURCE_INCBIN 0x1D428, 0x2B40

    .global gUnk_FieldRenderResource_124
gUnk_FieldRenderResource_124:
    FOMT_STATIC_RESOURCE_INCBIN 0x1FF68, 0x10

    .global gUnk_FieldRenderResource_125
gUnk_FieldRenderResource_125:
    FOMT_STATIC_RESOURCE_INCBIN 0x1FF78, 0xE0

    .global gUnk_MapDataResource_112
gUnk_MapDataResource_112:
    FOMT_STATIC_RESOURCE_INCBIN 0x20058, 0x10

    .global gUnk_MapDataResource_113
gUnk_MapDataResource_113:
    FOMT_STATIC_RESOURCE_INCBIN 0x20068, 0xE10

    .global gUnk_MapDataResource_336
gUnk_MapDataResource_336:
    FOMT_STATIC_RESOURCE_INCBIN 0x20E78, 0x30

    .global gUnk_MapDataResource_337
gUnk_MapDataResource_337:
    FOMT_STATIC_RESOURCE_INCBIN 0x20EA8, 0x348

    .global gUnk_MapDataResource_372
gUnk_MapDataResource_372:
    FOMT_STATIC_RESOURCE_INCBIN 0x211F0, 0x8

    .global gUnk_MapDataResource_373
gUnk_MapDataResource_373:
    FOMT_STATIC_RESOURCE_INCBIN 0x211F8, 0x258

    .global gUnk_MapDataResource_300
gUnk_MapDataResource_300:
    FOMT_STATIC_RESOURCE_INCBIN 0x21450, 0x30

    .global gUnk_MapDataResource_301
gUnk_MapDataResource_301:
    FOMT_STATIC_RESOURCE_INCBIN 0x21480, 0x348

    .global gUnk_MapDataResource_283
gUnk_MapDataResource_283:
    FOMT_STATIC_RESOURCE_INCBIN 0x217C8, 0x38

    .global gUnk_MapDataResource_284
gUnk_MapDataResource_284:
    FOMT_STATIC_RESOURCE_INCBIN 0x21800, 0x348

    .global gUnk_MapDataResource_288
gUnk_MapDataResource_288:
    FOMT_STATIC_RESOURCE_INCBIN 0x21B48, 0x24

    .global gUnk_MapDataResource_289
gUnk_MapDataResource_289:
    FOMT_STATIC_RESOURCE_INCBIN 0x21B6C, 0x348
