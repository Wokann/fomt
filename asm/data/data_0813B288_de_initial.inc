@ Direct labels inside DE's original pre-IWRAM resource stream.
@ Each address is recovered from a matched DE ROM pointer literal.  Keeping
@ labels physical avoids synthetic .set aliases.
	@ Direct DE farm-status preview resources in the original asset stream.
	.incbin "baserom_de.gba", 0x13D308, 0x170E28
	.global gUnk_08527094
gUnk_08527094:
	.incbin "baserom_de.gba", 0x2AE130, 0x1A4
	.global gUnk_08527238
gUnk_08527238:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 00, 0, 0x110
	.global gUnk_08527348
gUnk_08527348:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 01, 0, 0x1D8
	.global gUnk_08527520
gUnk_08527520:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 02, 0, 0xB0
	.global gUnk_085275D0
gUnk_085275D0:
	.incbin "build/de/graphics/ui/farm_status/base_tiles.0x70"
	.global gUnk_08529794
gUnk_08529794:
	.incbin "build/de/graphics/ui/farm_status/base_tiles.gbapal"
	.global gUnk_08529994
gUnk_08529994:
	FOMT_FARM_STATUS_EXTERIOR_STYLE doghouse
	.global gUnk_082B0BB4
gUnk_082B0BB4:
	FOMT_FARM_STATUS_TILEMAP 0x2D0, 0x60
	.global gUnk_082B0C14
gUnk_082B0C14:
	FOMT_FARM_STATUS_TILEMAP 0x270, 0x30
	.global gUnk_08529BA8
gUnk_08529BA8:
	FOMT_FARM_STATUS_EXTERIOR_STYLE mailbox
	.global gUnk_082B0D08
gUnk_082B0D08:
	FOMT_FARM_STATUS_TILEMAP 0x120, 0xA8
	.global gUnk_082B0DB0
gUnk_082B0DB0:
	FOMT_FARM_STATUS_TILEMAP 0x060, 0x60
	.global gUnk_082B0E10
gUnk_082B0E10:
	FOMT_FARM_STATUS_TILEMAP 0x000, 0x30
	.global gUnk_08529DA4
gUnk_08529DA4:
	FOMT_FARM_STATUS_EXTERIOR_STYLE window
	.global gUnk_082B1684
gUnk_082B1684:
	FOMT_FARM_STATUS_TILEMAP 0x438, 0x9A
	.incbin "baserom_de.gba", 0x2B171E, 0x2
	.global gUnk_082B1720
gUnk_082B1720:
	FOMT_FARM_STATUS_TILEMAP 0x390, 0x54
	.global gUnk_0852A6D8
gUnk_0852A6D8:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 03, 0, 0x114
	.global gUnk_0852A7EC
gUnk_0852A7EC:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 04, 0, 0x1D0
	.global gUnk_0852A9BC
gUnk_0852A9BC:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 05, 0, 0xB0
	.global gUnk_0852AA6C
gUnk_0852AA6C:
	.incbin "baserom_de.gba", 0x2B1B08, 0x1FD4
	.global gUnk_0852CA40
gUnk_0852CA40:
	.incbin "baserom_de.gba", 0x2B3ADC, 0x200
	.global gUnk_0852CC40
gUnk_0852CC40:
	.incbin "baserom_de.gba", 0x2B3CDC, 0x184
	.global gUnk_082B3E60
gUnk_082B3E60:
	FOMT_FARM_STATUS_TILEMAP 0x330, 0x60
	.global gUnk_082B3EC0
gUnk_082B3EC0:
	FOMT_FARM_STATUS_TILEMAP 0x2A0, 0x30
	.global gUnk_0852CE54
gUnk_0852CE54:
	.incbin "baserom_de.gba", 0x2B3EF0, 0xC4
	.global gUnk_082B3FB4
gUnk_082B3FB4:
	FOMT_FARM_STATUS_TILEMAP 0x1C8, 0xA8
	.global gUnk_082B405C
gUnk_082B405C:
	FOMT_FARM_STATUS_TILEMAP 0x0C0, 0x60
	.global gUnk_082B40BC
gUnk_082B40BC:
	FOMT_FARM_STATUS_TILEMAP 0x030, 0x30
	.global gUnk_0852D050
gUnk_0852D050:
	.incbin "baserom_de.gba", 0x2B40EC, 0x844
	.global gUnk_082B4930
gUnk_082B4930:
	FOMT_FARM_STATUS_TILEMAP 0x4D2, 0x9A
	.incbin "baserom_de.gba", 0x2B49CA, 0x2
	.global gUnk_082B49CC
gUnk_082B49CC:
	FOMT_FARM_STATUS_TILEMAP 0x3E4, 0x54
	.global gUnk_0852D984
gUnk_0852D984:
	.incbin "baserom_de.gba", 0x2B4A20, (0x2B78F8 - 0x2B4A20)
	.incbin "build/de/graphics/portraits/shared/portrait_tiles.4bpp"
	.incbin "baserom_de.gba", 0x312138, (0x312AC4 - 0x312138)

	@ DE places these archive payloads earlier than the corresponding US stream.
	@ Keep their common symbols on the physical DE bytes rather than aliases.
	.global gUnk_0858BA28
gUnk_0858BA28:
	.incbin "baserom_de.gba", 0x312AC4, (0x32A498 - 0x312AC4)
	.incbin "build/de/graphics/sprites/shared/actor_tiles.4bpp"
	.incbin "baserom_de.gba", 0x3E8E58, (0x3EE0FC - 0x3E8E58)
	.global gUnk_08667060
gUnk_08667060:
	.incbin "baserom_de.gba", 0x3EE0FC, 0x840
	.global gUnk_086678A0
gUnk_086678A0:
	.incbin "baserom_de.gba", 0x3EE93C, 0x12848

	@ Direct DE gMapData resource labels recovered from the matched pointer table.
	.global gUnk_MapDataResource_092
gUnk_MapDataResource_092:
	.incbin "baserom_de.gba", 0x401184, 0x4B3C
	.global gUnk_MapDataResource_093
gUnk_MapDataResource_093:
	.incbin "baserom_de.gba", 0x405CC0, 0xF8
	.global gUnk_MapDataResource_095
gUnk_MapDataResource_095:
	.incbin "baserom_de.gba", 0x405DB8, 0x1CF4
	.global gUnk_MapDataResource_096
gUnk_MapDataResource_096:
	.incbin "baserom_de.gba", 0x407AAC, 0xC6C
	.global gUnk_MapDataResource_097
gUnk_MapDataResource_097:
	.incbin "baserom_de.gba", 0x408718, 0x7D8
	.global gUnk_MapDataResource_094
gUnk_MapDataResource_094:
	.incbin "baserom_de.gba", 0x408EF0, 0xD8
	.global gUnk_MapDataResource_100
gUnk_MapDataResource_100:
	.incbin "baserom_de.gba", 0x408FC8, 0x5000
	.global gUnk_MapDataResource_101
gUnk_MapDataResource_101:
	.incbin "baserom_de.gba", 0x40DFC8, 0xF8
	.global gUnk_MapDataResource_103
gUnk_MapDataResource_103:
	.incbin "baserom_de.gba", 0x40E0C0, 0x1D80
	.global gUnk_MapDataResource_104
gUnk_MapDataResource_104:
	.incbin "baserom_de.gba", 0x40FE40, 0xC68
	.global gUnk_MapDataResource_105
gUnk_MapDataResource_105:
	.incbin "baserom_de.gba", 0x410AA8, 0x770
	.global gUnk_MapDataResource_102
gUnk_MapDataResource_102:
	.incbin "baserom_de.gba", 0x411218, 0xD4
	.global gUnk_MapDataResource_244
gUnk_MapDataResource_244:
	.incbin "baserom_de.gba", 0x4112EC, 0x20C
	.global gUnk_MapDataResource_245
gUnk_MapDataResource_245:
	.incbin "baserom_de.gba", 0x4114F8, 0x158
	.global gUnk_MapDataResource_246
gUnk_MapDataResource_246:
	.incbin "baserom_de.gba", 0x411650, 0x88
	.global gUnk_MapDataResource_056
gUnk_MapDataResource_056:
	.incbin "baserom_de.gba", 0x4116D8, 0x30D0
	.global gUnk_MapDataResource_057
gUnk_MapDataResource_057:
	.incbin "baserom_de.gba", 0x4147A8, 0xE0
	.global gUnk_MapDataResource_059
gUnk_MapDataResource_059:
	.incbin "baserom_de.gba", 0x414888, 0x71C
	.global gUnk_MapDataResource_060
gUnk_MapDataResource_060:
	.incbin "baserom_de.gba", 0x414FA4, 0x260
	.global gUnk_MapDataResource_061
gUnk_MapDataResource_061:
	.incbin "baserom_de.gba", 0x415204, 0x7C
	.global gUnk_MapDataResource_058
gUnk_MapDataResource_058:
	.incbin "baserom_de.gba", 0x415280, 0xE4
	.global gUnk_MapDataResource_064
gUnk_MapDataResource_064:
	.incbin "baserom_de.gba", 0x415364, 0x25D4
	.global gUnk_MapDataResource_065
gUnk_MapDataResource_065:
	.incbin "baserom_de.gba", 0x417938, 0xD8
	.global gUnk_MapDataResource_067
gUnk_MapDataResource_067:
	.incbin "baserom_de.gba", 0x417A10, 0x704
	.global gUnk_MapDataResource_068
gUnk_MapDataResource_068:
	.incbin "baserom_de.gba", 0x418114, 0x224
	.global gUnk_MapDataResource_069
gUnk_MapDataResource_069:
	.incbin "baserom_de.gba", 0x418338, 0x6C
	.global gUnk_MapDataResource_066
gUnk_MapDataResource_066:
	.incbin "baserom_de.gba", 0x4183A4, 0xCC
	.global gUnk_MapDataResource_222
gUnk_MapDataResource_222:
	.incbin "baserom_de.gba", 0x418470, 0x18B8
	.global gUnk_MapDataResource_223
gUnk_MapDataResource_223:
	.incbin "baserom_de.gba", 0x419D28, 0x124
	.global gUnk_MapDataResource_268
gUnk_MapDataResource_268:
	.incbin "baserom_de.gba", 0x419E4C, 0x254
	.global gUnk_MapDataResource_269
gUnk_MapDataResource_269:
	.incbin "baserom_de.gba", 0x41A0A0, 0x134
	.global gUnk_MapDataResource_270
gUnk_MapDataResource_270:
	.incbin "baserom_de.gba", 0x41A1D4, 0xD4
	.global gUnk_MapDataResource_273
gUnk_MapDataResource_273:
	.incbin "baserom_de.gba", 0x41A2A8, 0x220
	.global gUnk_MapDataResource_274
gUnk_MapDataResource_274:
	.incbin "baserom_de.gba", 0x41A4C8, 0x174
	.global gUnk_MapDataResource_275
gUnk_MapDataResource_275:
	.incbin "baserom_de.gba", 0x41A63C, 0x90
	.global gUnk_MapDataResource_266
gUnk_MapDataResource_266:
	.incbin "baserom_de.gba", 0x41A6CC, 0x2578
	.global gUnk_MapDataResource_267
gUnk_MapDataResource_267:
	.incbin "baserom_de.gba", 0x41CC44, 0x108
	.global gUnk_MapDataResource_195
gUnk_MapDataResource_195:
	.incbin "baserom_de.gba", 0x41CD4C, 0x320
	.global gUnk_MapDataResource_196
gUnk_MapDataResource_196:
	.incbin "baserom_de.gba", 0x41D06C, 0x104
	.global gUnk_MapDataResource_197
gUnk_MapDataResource_197:
	.incbin "baserom_de.gba", 0x41D170, 0xEC
	.global gUnk_MapDataResource_321
gUnk_MapDataResource_321:
	.incbin "baserom_de.gba", 0x41D25C, 0x1608
	.global gUnk_MapDataResource_322
gUnk_MapDataResource_322:
	.incbin "baserom_de.gba", 0x41E864, 0x158
	.global gUnk_08697920
gUnk_08697920:
	.incbin "baserom_de.gba", 0x41E9BC, 0x11E0
	.global gUnk_08698B00
gUnk_08698B00:
	.incbin "baserom_de.gba", 0x41FB9C, 0x80

	@ Direct DE FieldPlot render-record labels in the original asset stream.
	.global gUnk_FieldPlotRenderRecord_004
gUnk_FieldPlotRenderRecord_004:
	.incbin "baserom_de.gba", 0x41FC1C, 0x30
	.global gUnk_FieldPlotRenderRecord_011
gUnk_FieldPlotRenderRecord_011:
	.incbin "baserom_de.gba", 0x41FC4C, 0x18
	.global gUnk_FieldPlotRenderRecord_006
gUnk_FieldPlotRenderRecord_006:
	.incbin "baserom_de.gba", 0x41FC64, 0x3C
	.global gUnk_FieldPlotRenderRecord_002
gUnk_FieldPlotRenderRecord_002:
	.incbin "baserom_de.gba", 0x41FCA0, 0x30
	.global gUnk_FieldPlotRenderRecord_010
gUnk_FieldPlotRenderRecord_010:
	.incbin "baserom_de.gba", 0x41FCD0, 0x24
	.global gUnk_FieldPlotRenderRecord_014
gUnk_FieldPlotRenderRecord_014:
	.incbin "baserom_de.gba", 0x41FCF4, 0x30
	.global gUnk_FieldPlotRenderRecord_017
gUnk_FieldPlotRenderRecord_017:
	.incbin "baserom_de.gba", 0x41FD24, 0x30
	.global gUnk_FieldPlotRenderRecord_018
gUnk_FieldPlotRenderRecord_018:
	.incbin "baserom_de.gba", 0x41FD54, 0x30
	.global gUnk_FieldPlotRenderRecord_015
gUnk_FieldPlotRenderRecord_015:
	.incbin "baserom_de.gba", 0x41FD84, 0x30
	.global gUnk_FieldPlotRenderRecord_007
gUnk_FieldPlotRenderRecord_007:
	.incbin "baserom_de.gba", 0x41FDB4, 0x24
	.global gUnk_FieldPlotRenderRecord_009
gUnk_FieldPlotRenderRecord_009:
	.incbin "baserom_de.gba", 0x41FDD8, 0x3C
	.global gUnk_FieldPlotRenderRecord_016
gUnk_FieldPlotRenderRecord_016:
	.incbin "baserom_de.gba", 0x41FE14, 0x30
	.global gUnk_FieldPlotRenderRecord_001
gUnk_FieldPlotRenderRecord_001:
	.incbin "baserom_de.gba", 0x41FE44, 0x24
	.global gUnk_FieldPlotRenderRecord_008
gUnk_FieldPlotRenderRecord_008:
	.incbin "baserom_de.gba", 0x41FE68, 0x30
	.global gUnk_FieldPlotRenderRecord_013
gUnk_FieldPlotRenderRecord_013:
	.incbin "baserom_de.gba", 0x41FE98, 0x18
	.global gUnk_08698E14
gUnk_08698E14:
	.incbin "baserom_de.gba", 0x41FEB0, 0x11E0
	.global gUnk_08699FF4
gUnk_08699FF4:
	.incbin "baserom_de.gba", 0x421090, 0x80
	.global gUnk_FieldPlotRenderRecord_003
gUnk_FieldPlotRenderRecord_003:
	.incbin "baserom_de.gba", 0x421110, 0x30
	.global gUnk_0869A0A4
gUnk_0869A0A4:
	.incbin "baserom_de.gba", 0x421140, 0x11E0
	.global gUnk_0869B284
gUnk_0869B284:
	.incbin "baserom_de.gba", 0x422320, 0x80
	.global gUnk_FieldPlotRenderRecord_012
gUnk_FieldPlotRenderRecord_012:
	.incbin "baserom_de.gba", 0x4223A0, 0x18
	.global gUnk_FieldPlotRenderRecord_005
gUnk_FieldPlotRenderRecord_005:
	.incbin "baserom_de.gba", 0x4223B8, 0x3C
	.global gUnk_FieldPlotRenderRecord_019
gUnk_FieldPlotRenderRecord_019:
	.incbin "baserom_de.gba", 0x4223F4, 0x3C
	.global gUnk_FieldPlotRenderRecord_000
gUnk_FieldPlotRenderRecord_000:
	.incbin "baserom_de.gba", 0x422430, 0x24
	.global gUnk_MapDataResource_178
gUnk_MapDataResource_178:
	.incbin "baserom_de.gba", 0x422454, 0x154
	.global gUnk_MapDataResource_179
gUnk_MapDataResource_179:
	.incbin "baserom_de.gba", 0x4225A8, 0x150
	.global gUnk_MapDataResource_180
gUnk_MapDataResource_180:
	.incbin "baserom_de.gba", 0x4226F8, 0xD4
	.global gUnk_MapDataResource_000
gUnk_MapDataResource_000:
	.incbin "baserom_de.gba", 0x4227CC, 0x3BB0
	.global gUnk_MapDataResource_001
gUnk_MapDataResource_001:
	.incbin "baserom_de.gba", 0x42637C, 0xF4
	.global gUnk_MapDataResource_003
gUnk_MapDataResource_003:
	.incbin "baserom_de.gba", 0x426470, 0x7AC
	.global gUnk_MapDataResource_004
gUnk_MapDataResource_004:
	.incbin "baserom_de.gba", 0x426C1C, 0x488
	.global gUnk_MapDataResource_005
gUnk_MapDataResource_005:
	.incbin "baserom_de.gba", 0x4270A4, 0x90
	.global gUnk_MapDataResource_002
gUnk_MapDataResource_002:
	.incbin "baserom_de.gba", 0x427134, 0xF4
	.global gUnk_MapDataResource_008
gUnk_MapDataResource_008:
	.incbin "baserom_de.gba", 0x427228, 0x3DBC
	.global gUnk_MapDataResource_009
gUnk_MapDataResource_009:
	.incbin "baserom_de.gba", 0x42AFE4, 0xE4
	.global gUnk_MapDataResource_011
gUnk_MapDataResource_011:
	.incbin "baserom_de.gba", 0x42B0C8, 0x924
	.global gUnk_MapDataResource_012
gUnk_MapDataResource_012:
	.incbin "baserom_de.gba", 0x42B9EC, 0x4B4
	.global gUnk_MapDataResource_013
gUnk_MapDataResource_013:
	.incbin "baserom_de.gba", 0x42BEA0, 0x94
	.global gUnk_MapDataResource_010
gUnk_MapDataResource_010:
	.incbin "baserom_de.gba", 0x42BF34, 0xD4
	.global gUnk_MapDataResource_070
gUnk_MapDataResource_070:
	.incbin "baserom_de.gba", 0x42C008, 0x397C
	.global gUnk_MapDataResource_071
gUnk_MapDataResource_071:
	.incbin "baserom_de.gba", 0x42F984, 0xCC
	.global gUnk_MapDataResource_084
gUnk_MapDataResource_084:
	.incbin "baserom_de.gba", 0x42FA50, 0xA80
	.global gUnk_MapDataResource_085
gUnk_MapDataResource_085:
	.incbin "baserom_de.gba", 0x4304D0, 0x6F8
	.global gUnk_MapDataResource_086
gUnk_MapDataResource_086:
	.incbin "baserom_de.gba", 0x430BC8, 0x548
	.global gUnk_MapDataResource_072
gUnk_MapDataResource_072:
	.incbin "baserom_de.gba", 0x431110, 0xBC
	.global gUnk_MapDataResource_078
gUnk_MapDataResource_078:
	.incbin "baserom_de.gba", 0x4311CC, 0x3958
	.global gUnk_MapDataResource_079
gUnk_MapDataResource_079:
	.incbin "baserom_de.gba", 0x434B24, 0xC8
	.global gUnk_MapDataResource_089
gUnk_MapDataResource_089:
	.incbin "baserom_de.gba", 0x434BEC, 0xB8C
	.global gUnk_MapDataResource_090
gUnk_MapDataResource_090:
	.incbin "baserom_de.gba", 0x435778, 0x660
	.global gUnk_MapDataResource_091
gUnk_MapDataResource_091:
	.incbin "baserom_de.gba", 0x435DD8, 0x538
	.global gUnk_MapDataResource_080
gUnk_MapDataResource_080:
	.incbin "baserom_de.gba", 0x436310, 0xB8
	.global gUnk_MapDataResource_309
gUnk_MapDataResource_309:
	.incbin "baserom_de.gba", 0x4363C8, 0x1F4
	.global gUnk_MapDataResource_310
gUnk_MapDataResource_310:
	.incbin "baserom_de.gba", 0x4365BC, 0x1BC
	.global gUnk_MapDataResource_311
gUnk_MapDataResource_311:
	.incbin "baserom_de.gba", 0x436778, 0xCC
	.global gUnk_MapDataResource_168
gUnk_MapDataResource_168:
	.incbin "baserom_de.gba", 0x436844, 0x1CC
	.global gUnk_MapDataResource_169
gUnk_MapDataResource_169:
	.incbin "baserom_de.gba", 0x436A10, 0x1C0
	.global gUnk_MapDataResource_170
gUnk_MapDataResource_170:
	.incbin "baserom_de.gba", 0x436BD0, 0xD4
	.global gUnk_MapDataResource_159
gUnk_MapDataResource_159:
	.incbin "baserom_de.gba", 0x436CA4, 0x170C
	.global gUnk_MapDataResource_160
gUnk_MapDataResource_160:
	.incbin "baserom_de.gba", 0x4383B0, 0x1B8
	.global gUnk_MapDataResource_161
gUnk_MapDataResource_161:
	.incbin "baserom_de.gba", 0x438568, 0x268
	.global gUnk_MapDataResource_162
gUnk_MapDataResource_162:
	.incbin "baserom_de.gba", 0x4387D0, 0x1E0
	.global gUnk_MapDataResource_163
gUnk_MapDataResource_163:
	.incbin "baserom_de.gba", 0x4389B0, 0x114
	.global gUnk_MapDataResource_229
gUnk_MapDataResource_229:
	.incbin "baserom_de.gba", 0x438AC4, 0x2E8
	.global gUnk_MapDataResource_230
gUnk_MapDataResource_230:
	.incbin "baserom_de.gba", 0x438DAC, 0xB4
	.global gUnk_MapDataResource_231
gUnk_MapDataResource_231:
	.incbin "baserom_de.gba", 0x438E60, 0xA0
	.global gUnk_MapDataResource_224
gUnk_MapDataResource_224:
	.incbin "baserom_de.gba", 0x438F00, 0x274
	.global gUnk_MapDataResource_225
gUnk_MapDataResource_225:
	.incbin "baserom_de.gba", 0x439174, 0x90
	.global gUnk_MapDataResource_226
gUnk_MapDataResource_226:
	.incbin "baserom_de.gba", 0x439204, 0x94
	.global gUnk_MapDataResource_323
gUnk_MapDataResource_323:
	.incbin "baserom_de.gba", 0x439298, 0x184
	.global gUnk_MapDataResource_324
gUnk_MapDataResource_324:
	.incbin "baserom_de.gba", 0x43941C, 0xEC
	.global gUnk_MapDataResource_325
gUnk_MapDataResource_325:
	.incbin "baserom_de.gba", 0x439508, 0x84
	.global gUnk_MapDataResource_185
gUnk_MapDataResource_185:
	.incbin "baserom_de.gba", 0x43958C, 0x350
	.global gUnk_MapDataResource_186
gUnk_MapDataResource_186:
	.incbin "baserom_de.gba", 0x4398DC, 0x1E4
	.global gUnk_MapDataResource_187
gUnk_MapDataResource_187:
	.incbin "baserom_de.gba", 0x439AC0, 0x178
	.global gUnk_MapDataResource_190
gUnk_MapDataResource_190:
	.incbin "baserom_de.gba", 0x439C38, 0x24C
	.global gUnk_MapDataResource_191
gUnk_MapDataResource_191:
	.incbin "baserom_de.gba", 0x439E84, 0x24C
	.global gUnk_MapDataResource_192
gUnk_MapDataResource_192:
	.incbin "baserom_de.gba", 0x43A0D0, 0x14C
	.global gUnk_MapDataResource_183
gUnk_MapDataResource_183:
	.incbin "baserom_de.gba", 0x43A21C, 0x37FC
	.global gUnk_MapDataResource_184
gUnk_MapDataResource_184:
	.incbin "baserom_de.gba", 0x43DA18, 0x178
	.global gUnk_MapDataResource_144
gUnk_MapDataResource_144:
	.incbin "baserom_de.gba", 0x43DB90, 0x300
	.global gUnk_MapDataResource_145
gUnk_MapDataResource_145:
	.incbin "baserom_de.gba", 0x43DE90, 0x200
	.global gUnk_MapDataResource_146
gUnk_MapDataResource_146:
	.incbin "baserom_de.gba", 0x43E090, 0x12C
	.global gUnk_MapDataResource_149
gUnk_MapDataResource_149:
	.incbin "baserom_de.gba", 0x43E1BC, 0x308
	.global gUnk_MapDataResource_150
gUnk_MapDataResource_150:
	.incbin "baserom_de.gba", 0x43E4C4, 0x304
	.global gUnk_MapDataResource_151
gUnk_MapDataResource_151:
	.incbin "baserom_de.gba", 0x43E7C8, 0x12C
	.global gUnk_MapDataResource_154
gUnk_MapDataResource_154:
	.incbin "baserom_de.gba", 0x43E8F4, 0x2FC
	.global gUnk_MapDataResource_155
gUnk_MapDataResource_155:
	.incbin "baserom_de.gba", 0x43EBF0, 0x234
	.global gUnk_MapDataResource_156
gUnk_MapDataResource_156:
	.incbin "baserom_de.gba", 0x43EE24, 0xF4
	.global gUnk_MapDataResource_142
gUnk_MapDataResource_142:
	.incbin "baserom_de.gba", 0x43EF18, 0x35C4
	.global gUnk_MapDataResource_143
gUnk_MapDataResource_143:
	.incbin "baserom_de.gba", 0x4424DC, 0x15C
	.global gUnk_MapDataResource_302
gUnk_MapDataResource_302:
	.incbin "baserom_de.gba", 0x442638, 0x1A60
	.global gUnk_MapDataResource_303
gUnk_MapDataResource_303:
	.incbin "baserom_de.gba", 0x444098, 0x114
	.global gUnk_MapDataResource_212
gUnk_MapDataResource_212:
	.incbin "baserom_de.gba", 0x4441AC, 0x1B8
	.global gUnk_MapDataResource_213
gUnk_MapDataResource_213:
	.incbin "baserom_de.gba", 0x444364, 0x100
	.global gUnk_MapDataResource_214
gUnk_MapDataResource_214:
	.incbin "baserom_de.gba", 0x444464, 0x120
	.global gUnk_MapDataResource_217
gUnk_MapDataResource_217:
	.incbin "baserom_de.gba", 0x444584, 0x198
	.global gUnk_MapDataResource_218
gUnk_MapDataResource_218:
	.incbin "baserom_de.gba", 0x44471C, 0x118
	.global gUnk_MapDataResource_219
gUnk_MapDataResource_219:
	.incbin "baserom_de.gba", 0x444834, 0xA8
	.global gUnk_MapDataResource_202
gUnk_MapDataResource_202:
	.incbin "baserom_de.gba", 0x4448DC, 0x17C
	.global gUnk_MapDataResource_203
gUnk_MapDataResource_203:
	.incbin "baserom_de.gba", 0x444A58, 0xF0
	.global gUnk_MapDataResource_204
gUnk_MapDataResource_204:
	.incbin "baserom_de.gba", 0x444B48, 0xE0
	.global gUnk_MapDataResource_207
gUnk_MapDataResource_207:
	.incbin "baserom_de.gba", 0x444C28, 0xF4
	.global gUnk_MapDataResource_208
gUnk_MapDataResource_208:
	.incbin "baserom_de.gba", 0x444D1C, 0x100
	.global gUnk_MapDataResource_209
gUnk_MapDataResource_209:
	.incbin "baserom_de.gba", 0x444E1C, 0x84
	.global gUnk_MapDataResource_200
gUnk_MapDataResource_200:
	.incbin "baserom_de.gba", 0x444EA0, 0x2CD8
	.global gUnk_MapDataResource_201
gUnk_MapDataResource_201:
	.incbin "baserom_de.gba", 0x447B78, 0x16C
	.global gUnk_MapDataResource_314
gUnk_MapDataResource_314:
	.incbin "baserom_de.gba", 0x447CE4, 0x10FC
	.global gUnk_MapDataResource_315
gUnk_MapDataResource_315:
	.incbin "baserom_de.gba", 0x448DE0, 0x104
	.global gUnk_MapDataResource_316
gUnk_MapDataResource_316:
	.incbin "baserom_de.gba", 0x448EE4, 0x1A8
	.global gUnk_MapDataResource_317
gUnk_MapDataResource_317:
	.incbin "baserom_de.gba", 0x44908C, 0x168
	.global gUnk_MapDataResource_318
gUnk_MapDataResource_318:
	.incbin "baserom_de.gba", 0x4491F4, 0xF8
	.global gUnk_MapDataResource_304
gUnk_MapDataResource_304:
	.incbin "baserom_de.gba", 0x4492EC, 0x1C4
	.global gUnk_MapDataResource_305
gUnk_MapDataResource_305:
	.incbin "baserom_de.gba", 0x4494B0, 0x164
	.global gUnk_MapDataResource_306
gUnk_MapDataResource_306:
	.incbin "baserom_de.gba", 0x449614, 0xB8
	.global gUnk_MapDataResource_249
gUnk_MapDataResource_249:
	.incbin "baserom_de.gba", 0x4496CC, 0x2738
	.global gUnk_MapDataResource_250
gUnk_MapDataResource_250:
	.incbin "baserom_de.gba", 0x44BE04, 0x108
	.global gUnk_MapDataResource_261
gUnk_MapDataResource_261:
	.incbin "baserom_de.gba", 0x44BF0C, 0x184
	.global gUnk_MapDataResource_262
gUnk_MapDataResource_262:
	.incbin "baserom_de.gba", 0x44C090, 0x104
	.global gUnk_MapDataResource_263
gUnk_MapDataResource_263:
	.incbin "baserom_de.gba", 0x44C194, 0xCC
	.global gUnk_MapDataResource_256
gUnk_MapDataResource_256:
	.incbin "baserom_de.gba", 0x44C260, 0x160
	.global gUnk_MapDataResource_257
gUnk_MapDataResource_257:
	.incbin "baserom_de.gba", 0x44C3C0, 0x100
	.global gUnk_MapDataResource_258
gUnk_MapDataResource_258:
	.incbin "baserom_de.gba", 0x44C4C0, 0xC0
	.global gUnk_MapDataResource_251
gUnk_MapDataResource_251:
	.incbin "baserom_de.gba", 0x44C580, 0x14C
	.global gUnk_MapDataResource_252
gUnk_MapDataResource_252:
	.incbin "baserom_de.gba", 0x44C6CC, 0xE8
	.global gUnk_MapDataResource_253
gUnk_MapDataResource_253:
	.incbin "baserom_de.gba", 0x44C7B4, 0xA8
	.global gUnk_MapDataResource_073
gUnk_MapDataResource_073:
	.incbin "baserom_de.gba", 0x44C85C, 0x4C0
	.global gUnk_MapDataResource_074
gUnk_MapDataResource_074:
	.incbin "baserom_de.gba", 0x44CD1C, 0x234
	.global gUnk_MapDataResource_075
gUnk_MapDataResource_075:
	.incbin "baserom_de.gba", 0x44CF50, 0x1D8
	.global gUnk_MapDataResource_081
gUnk_MapDataResource_081:
	.incbin "baserom_de.gba", 0x44D128, 0x4B4
	.global gUnk_MapDataResource_082
gUnk_MapDataResource_082:
	.incbin "baserom_de.gba", 0x44D5DC, 0x220
	.global gUnk_MapDataResource_083
gUnk_MapDataResource_083:
	.incbin "baserom_de.gba", 0x44D7FC, 0x1C0
	.global gUnk_MapDataResource_028
gUnk_MapDataResource_028:
	.incbin "baserom_de.gba", 0x44D9BC, 0x4D0C
	.global gUnk_MapDataResource_029
gUnk_MapDataResource_029:
	.incbin "baserom_de.gba", 0x4526C8, 0x134
	.global gUnk_MapDataResource_031
gUnk_MapDataResource_031:
	.incbin "baserom_de.gba", 0x4527FC, 0x1080
	.global gUnk_MapDataResource_032
gUnk_MapDataResource_032:
	.incbin "baserom_de.gba", 0x45387C, 0x1098
	.global gUnk_MapDataResource_033
gUnk_MapDataResource_033:
	.incbin "baserom_de.gba", 0x454914, 0x640
	.global gUnk_MapDataResource_030
gUnk_MapDataResource_030:
	.incbin "baserom_de.gba", 0x454F54, 0x134
	.global gUnk_MapDataResource_036
gUnk_MapDataResource_036:
	.incbin "baserom_de.gba", 0x455088, 0x4EAC
	.global gUnk_MapDataResource_037
gUnk_MapDataResource_037:
	.incbin "baserom_de.gba", 0x459F34, 0xFC
	.global gUnk_MapDataResource_039
gUnk_MapDataResource_039:
	.incbin "baserom_de.gba", 0x45A030, 0xF28
	.global gUnk_MapDataResource_040
gUnk_MapDataResource_040:
	.incbin "baserom_de.gba", 0x45AF58, 0x1018
	.global gUnk_MapDataResource_041
gUnk_MapDataResource_041:
	.incbin "baserom_de.gba", 0x45BF70, 0x554
	.global gUnk_MapDataResource_038
gUnk_MapDataResource_038:
	.incbin "baserom_de.gba", 0x45C4C4, 0xE0
	.global gUnk_086D5508
gUnk_086D5508:
	.incbin "baserom_de.gba", 0x45C5A4, 0xE60
	.global gUnk_086D6368
gUnk_086D6368:
	.incbin "baserom_de.gba", 0x45D404, 0x60
	.global gUnk_FieldPlotRenderRecord_033
gUnk_FieldPlotRenderRecord_033:
	.incbin "baserom_de.gba", 0x45D464, 0x18
	.global gUnk_FieldPlotRenderRecord_031
gUnk_FieldPlotRenderRecord_031:
	.incbin "baserom_de.gba", 0x45D47C, 0x18
	.global gUnk_FieldPlotRenderRecord_034
gUnk_FieldPlotRenderRecord_034:
	.incbin "baserom_de.gba", 0x45D494, 0x18
	.global gUnk_FieldPlotRenderRecord_032
gUnk_FieldPlotRenderRecord_032:
	.incbin "baserom_de.gba", 0x45D4AC, 0x18
	.global gUnk_FieldPlotRenderRecord_023
gUnk_FieldPlotRenderRecord_023:
	.incbin "baserom_de.gba", 0x45D4C4, 0x18
	.global gUnk_FieldPlotRenderRecord_025
gUnk_FieldPlotRenderRecord_025:
	.incbin "baserom_de.gba", 0x45D4DC, 0x18
	.global gUnk_086D6458
gUnk_086D6458:
	.incbin "baserom_de.gba", 0x45D4F4, 0xC
	.global gUnk_FieldPlotRenderRecord_026
gUnk_FieldPlotRenderRecord_026:
	.incbin "baserom_de.gba", 0x45D500, 0x18
	.global gUnk_FieldPlotRenderRecord_020
gUnk_FieldPlotRenderRecord_020:
	.incbin "baserom_de.gba", 0x45D518, 0x9C
	.global gUnk_086D6518
gUnk_086D6518:
	.incbin "baserom_de.gba", 0x45D5B4, 0x8
	.global gUnk_086D6520
gUnk_086D6520:
	.incbin "baserom_de.gba", 0x45D5BC, 0x8
	.global gUnk_086D6528
gUnk_086D6528:
	.incbin "baserom_de.gba", 0x45D5C4, 0x8
	.global gUnk_FieldPlotRenderRecord_024
gUnk_FieldPlotRenderRecord_024:
	.incbin "baserom_de.gba", 0x45D5CC, 0x18
	.global gUnk_086D6548
gUnk_086D6548:
	.incbin "baserom_de.gba", 0x45D5E4, 0x60
	.global gUnk_FieldPlotRenderRecord_037
gUnk_FieldPlotRenderRecord_037:
	.incbin "baserom_de.gba", 0x45D644, 0x18
	.global gUnk_FieldPlotRenderRecord_035
gUnk_FieldPlotRenderRecord_035:
	.incbin "baserom_de.gba", 0x45D65C, 0x18
	.global gUnk_FieldPlotRenderRecord_038
gUnk_FieldPlotRenderRecord_038:
	.incbin "baserom_de.gba", 0x45D674, 0x18
	.global gUnk_FieldPlotRenderRecord_036
gUnk_FieldPlotRenderRecord_036:
	.incbin "baserom_de.gba", 0x45D68C, 0x18
	.global gUnk_086D6608
gUnk_086D6608:
	.incbin "baserom_de.gba", 0x45D6A4, 0xC
	.global gUnk_FieldPlotRenderRecord_022
gUnk_FieldPlotRenderRecord_022:
	.incbin "baserom_de.gba", 0x45D6B0, 0x18
	.global gUnk_FieldPlotRenderRecord_029
gUnk_FieldPlotRenderRecord_029:
	.incbin "baserom_de.gba", 0x45D6C8, 0x18
	.global gUnk_FieldPlotRenderRecord_027
gUnk_FieldPlotRenderRecord_027:
	.incbin "baserom_de.gba", 0x45D6E0, 0x18
	.global gUnk_FieldPlotRenderRecord_030
gUnk_FieldPlotRenderRecord_030:
	.incbin "baserom_de.gba", 0x45D6F8, 0x18
	.global gUnk_FieldPlotRenderRecord_028
gUnk_FieldPlotRenderRecord_028:
	.incbin "baserom_de.gba", 0x45D710, 0x18
	.global gUnk_FieldPlotRenderRecord_021
gUnk_FieldPlotRenderRecord_021:
	.incbin "baserom_de.gba", 0x45D728, 0xC
	.global gUnk_086D6698
gUnk_086D6698:
	.incbin "baserom_de.gba", 0x45D734, 0xE60
	.global gUnk_086D74F8
gUnk_086D74F8:
	.incbin "baserom_de.gba", 0x45E594, 0x60
	.global gUnk_MapDataResource_122
gUnk_MapDataResource_122:
	.incbin "baserom_de.gba", 0x45E5F4, 0x1DC
	.global gUnk_MapDataResource_123
gUnk_MapDataResource_123:
	.incbin "baserom_de.gba", 0x45E7D0, 0x16C
	.global gUnk_MapDataResource_124
gUnk_MapDataResource_124:
	.incbin "baserom_de.gba", 0x45E93C, 0xE8
	.global gUnk_MapDataResource_127
gUnk_MapDataResource_127:
	.incbin "baserom_de.gba", 0x45EA24, 0x1D8
	.global gUnk_MapDataResource_128
gUnk_MapDataResource_128:
	.incbin "baserom_de.gba", 0x45EBFC, 0x12C
	.global gUnk_MapDataResource_129
gUnk_MapDataResource_129:
	.incbin "baserom_de.gba", 0x45ED28, 0xFC
	.global gUnk_MapDataResource_120
gUnk_MapDataResource_120:
	.incbin "baserom_de.gba", 0x45EE24, 0x3120
	.global gUnk_MapDataResource_121
gUnk_MapDataResource_121:
	.incbin "baserom_de.gba", 0x461F44, 0x124
	.global gUnk_MapDataResource_338
gUnk_MapDataResource_338:
	.incbin "baserom_de.gba", 0x462068, 0xDB8
	.global gUnk_MapDataResource_339
gUnk_MapDataResource_339:
	.incbin "baserom_de.gba", 0x462E20, 0xA0
	.global gUnk_MapDataResource_340
gUnk_MapDataResource_340:
	.incbin "baserom_de.gba", 0x462EC0, 0x98
	.global gUnk_MapDataResource_341
gUnk_MapDataResource_341:
	.incbin "baserom_de.gba", 0x462F58, 0xC
	.global gUnk_MapDataResource_342
gUnk_MapDataResource_342:
	.incbin "baserom_de.gba", 0x462F64, 0xAC
	.global gUnk_MapDataResource_345
gUnk_MapDataResource_345:
	.incbin "baserom_de.gba", 0x463010, 0x7C
	.global gUnk_MapDataResource_346
gUnk_MapDataResource_346:
	.incbin "baserom_de.gba", 0x46308C, 0xC
	.global gUnk_MapDataResource_347
gUnk_MapDataResource_347:
	.incbin "baserom_de.gba", 0x463098, 0x5C
	.global gUnk_MapDataResource_350
gUnk_MapDataResource_350:
	.incbin "baserom_de.gba", 0x4630F4, 0x8C
	.global gUnk_MapDataResource_351
gUnk_MapDataResource_351:
	.incbin "baserom_de.gba", 0x463180, 0xC
	.global gUnk_MapDataResource_352
gUnk_MapDataResource_352:
	.incbin "baserom_de.gba", 0x46318C, 0x60
	.global gUnk_MapDataResource_355
gUnk_MapDataResource_355:
	.incbin "baserom_de.gba", 0x4631EC, 0x80
	.global gUnk_MapDataResource_356
gUnk_MapDataResource_356:
	.incbin "baserom_de.gba", 0x46326C, 0xC
	.global gUnk_MapDataResource_357
gUnk_MapDataResource_357:
	.incbin "baserom_de.gba", 0x463278, 0x5C
	.global gUnk_MapDataResource_360
gUnk_MapDataResource_360:
	.incbin "baserom_de.gba", 0x4632D4, 0xB4
	.global gUnk_MapDataResource_361
gUnk_MapDataResource_361:
	.incbin "baserom_de.gba", 0x463388, 0x2C
	.global gUnk_MapDataResource_362
gUnk_MapDataResource_362:
	.incbin "baserom_de.gba", 0x4633B4, 0xAC
	.global gActorStateGridCellType0Data
gActorStateGridCellType0Data:
	.incbin "baserom_de.gba", 0x463460, 0xC
	.global gActorStateGridCellType1Data
gActorStateGridCellType1Data:
	.incbin "baserom_de.gba", 0x46346C, 0xC
	.global gActorStateGridCellType2Data
gActorStateGridCellType2Data:
	.incbin "baserom_de.gba", 0x463478, 0xC
	.global gActorStateGridCellType3Data
gActorStateGridCellType3Data:
	.incbin "baserom_de.gba", 0x463484, 0xC
	.global gActorStateGridCellType4Data
gActorStateGridCellType4Data:
	.incbin "baserom_de.gba", 0x463490, 0xC
	.global gUnk_MapDataResource_365
gUnk_MapDataResource_365:
	.incbin "baserom_de.gba", 0x46349C, 0xC4
	.global gUnk_MapDataResource_366
gUnk_MapDataResource_366:
	.incbin "baserom_de.gba", 0x463560, 0xC
	.global gUnk_MapDataResource_367
gUnk_MapDataResource_367:
	.incbin "baserom_de.gba", 0x46356C, 0x7C
	.global gUnk_086DC54C
gUnk_086DC54C:
	.incbin "baserom_de.gba", 0x4635E8, 0x30
	.global gUnk_086DC57C
gUnk_086DC57C:
	.incbin "baserom_de.gba", 0x463618, 0x8
	.global gUnk_FieldRenderResource_143
gUnk_FieldRenderResource_143:
	.incbin "baserom_de.gba", 0x463620, 0x200
	.global gUnk_FieldRenderResource_144
gUnk_FieldRenderResource_144:
	.incbin "baserom_de.gba", 0x463820, 0x200
	.global gUnk_FieldRenderResource_145
gUnk_FieldRenderResource_145:
	.incbin "baserom_de.gba", 0x463A20, 0x200
	.global gUnk_FarmHouseTilePatchResource_020
gUnk_FarmHouseTilePatchResource_020:
	.incbin "baserom_de.gba", 0x463C20, 0xC4
	.global gUnk_FieldRenderResource_223
gUnk_FieldRenderResource_223:
	.incbin "baserom_de.gba", 0x463CE4, 0x20
	.global gUnk_FieldRenderResource_224
gUnk_FieldRenderResource_224:
	.incbin "baserom_de.gba", 0x463D04, 0x20
	.global gUnk_086DCC88
gUnk_086DCC88:
	.incbin "baserom_de.gba", 0x463D24, 0x20
	.global gUnk_FarmHouseTilePatchResource_018
gUnk_FarmHouseTilePatchResource_018:
	.incbin "baserom_de.gba", 0x463D44, 0x204
	.global gUnk_FarmHouseTilePatchResource_019
gUnk_FarmHouseTilePatchResource_019:
	.incbin "baserom_de.gba", 0x463F48, 0x7E4
	.global gUnk_086DD690
gUnk_086DD690:
	.incbin "baserom_de.gba", 0x46472C, 0x20
	.global gUnk_086DD6B0
gUnk_086DD6B0:
	.incbin "baserom_de.gba", 0x46474C, 0x30
	.global gUnk_086DD6E0
gUnk_086DD6E0:
	.incbin "baserom_de.gba", 0x46477C, 0x8
	.global gUnk_FieldRenderResource_148
gUnk_FieldRenderResource_148:
	.incbin "baserom_de.gba", 0x464784, 0x200
	.global gUnk_FieldRenderResource_149
gUnk_FieldRenderResource_149:
	.incbin "baserom_de.gba", 0x464984, 0x200
	.global gUnk_FieldRenderResource_150
gUnk_FieldRenderResource_150:
	.incbin "baserom_de.gba", 0x464B84, 0x200
	.global gUnk_FarmHouseTilePatchResource_023
gUnk_FarmHouseTilePatchResource_023:
	.incbin "baserom_de.gba", 0x464D84, 0xC4
	.global gUnk_FieldRenderResource_225
gUnk_FieldRenderResource_225:
	.incbin "baserom_de.gba", 0x464E48, 0x20
	.global gUnk_FieldRenderResource_226
gUnk_FieldRenderResource_226:
	.incbin "baserom_de.gba", 0x464E68, 0x20
	.global gUnk_086DDDEC
gUnk_086DDDEC:
	.incbin "baserom_de.gba", 0x464E88, 0x20
	.global gUnk_FarmHouseTilePatchResource_021
gUnk_FarmHouseTilePatchResource_021:
	.incbin "baserom_de.gba", 0x464EA8, 0x204
	.global gUnk_FarmHouseTilePatchResource_022
gUnk_FarmHouseTilePatchResource_022:
	.incbin "baserom_de.gba", 0x4650AC, 0x7E4
	.global gUnk_086DE7F4
gUnk_086DE7F4:
	.incbin "baserom_de.gba", 0x465890, 0x20
	.global gUnk_FieldRenderResource_134
gUnk_FieldRenderResource_134:
	.incbin "baserom_de.gba", 0x4658B0, 0x630
	.global gUnk_FieldRenderResource_135
gUnk_FieldRenderResource_135:
	.incbin "baserom_de.gba", 0x465EE0, 0x630
	.global gUnk_FieldRenderResource_136
gUnk_FieldRenderResource_136:
	.incbin "baserom_de.gba", 0x466510, 0x630
	.global gUnk_FieldRenderResource_128
gUnk_FieldRenderResource_128:
	.incbin "baserom_de.gba", 0x466B40, 0x2A8
	.global gUnk_FieldRenderResource_129
gUnk_FieldRenderResource_129:
	.incbin "baserom_de.gba", 0x466DE8, 0x2A8
	.global gUnk_FieldRenderResource_139
gUnk_FieldRenderResource_139:
	.incbin "baserom_de.gba", 0x467090, 0x30
	.global gUnk_FieldRenderResource_140
gUnk_FieldRenderResource_140:
	.incbin "baserom_de.gba", 0x4670C0, 0x30
	.global gUnk_FarmHouseTilePatchResource_024
gUnk_FarmHouseTilePatchResource_024:
	.incbin "baserom_de.gba", 0x4670F0, 0x1384
	.global gUnk_FieldRenderResource_132
gUnk_FieldRenderResource_132:
	.incbin "baserom_de.gba", 0x468474, 0x2A8
	.global gUnk_FieldRenderResource_133
gUnk_FieldRenderResource_133:
	.incbin "baserom_de.gba", 0x46871C, 0x2A8
	.global gUnk_FarmHouseTilePatchResource_026
gUnk_FarmHouseTilePatchResource_026:
	.incbin "baserom_de.gba", 0x4689C4, 0x1384
	.global gUnk_FarmHouseTilePatchResource_013
gUnk_FarmHouseTilePatchResource_013:
	.incbin "baserom_de.gba", 0x469D48, 0x244
	.global gUnk_FarmHouseTilePatchResource_025
gUnk_FarmHouseTilePatchResource_025:
	.incbin "baserom_de.gba", 0x469F8C, 0x104
	.global gUnk_FieldRenderResource_211
gUnk_FieldRenderResource_211:
	.incbin "baserom_de.gba", 0x46A090, 0x20
	.global gUnk_FieldRenderResource_214
gUnk_FieldRenderResource_214:
	.incbin "baserom_de.gba", 0x46A0B0, 0x20
	.global gUnk_FieldRenderResource_207
gUnk_FieldRenderResource_207:
	.incbin "baserom_de.gba", 0x46A0D0, 0x20
	.global gUnk_FieldRenderResource_210
gUnk_FieldRenderResource_210:
	.incbin "baserom_de.gba", 0x46A0F0, 0x20
	.global gUnk_FarmHouseTilePatchResource_002
gUnk_FarmHouseTilePatchResource_002:
	.incbin "baserom_de.gba", 0x46A110, 0x484
	.global gUnk_FieldRenderResource_038
gUnk_FieldRenderResource_038:
	.incbin "baserom_de.gba", 0x46A594, 0x1DC
	.global gUnk_FieldRenderResource_039
gUnk_FieldRenderResource_039:
	.incbin "baserom_de.gba", 0x46A770, 0x1DC
	.global gUnk_FieldRenderResource_040
gUnk_FieldRenderResource_040:
	.incbin "baserom_de.gba", 0x46A94C, 0x1DC
	.global gUnk_FieldRenderResource_030
gUnk_FieldRenderResource_030:
	.incbin "baserom_de.gba", 0x46AB28, 0xFC
	.global gUnk_FieldRenderResource_031
gUnk_FieldRenderResource_031:
	.incbin "baserom_de.gba", 0x46AC24, 0xFC
	.global gUnk_FieldRenderResource_032
gUnk_FieldRenderResource_032:
	.incbin "baserom_de.gba", 0x46AD20, 0xFC
	.global gUnk_FieldRenderResource_012
gUnk_FieldRenderResource_012:
	.incbin "baserom_de.gba", 0x46AE1C, 0x270
	.global gUnk_FieldRenderResource_013
gUnk_FieldRenderResource_013:
	.incbin "baserom_de.gba", 0x46B08C, 0x270
	.global gUnk_FieldRenderResource_006
gUnk_FieldRenderResource_006:
	.incbin "baserom_de.gba", 0x46B2FC, 0x1A0
	.global gUnk_FieldRenderResource_007
gUnk_FieldRenderResource_007:
	.incbin "baserom_de.gba", 0x46B49C, 0x1A0
	.global gUnk_FieldRenderResource_000
gUnk_FieldRenderResource_000:
	.incbin "baserom_de.gba", 0x46B63C, 0xD0
	.global gUnk_FieldRenderResource_001
gUnk_FieldRenderResource_001:
	.incbin "baserom_de.gba", 0x46B70C, 0xD0
	.global gUnk_FarmHouseTilePatchResource_000
gUnk_FarmHouseTilePatchResource_000:
	.incbin "baserom_de.gba", 0x46B7DC, 0x244
	.global gUnk_FarmHouseTilePatchResource_007
gUnk_FarmHouseTilePatchResource_007:
	.incbin "baserom_de.gba", 0x46BA20, 0xE04
	.global gUnk_FieldRenderResource_024
gUnk_FieldRenderResource_024:
	.incbin "baserom_de.gba", 0x46C824, 0x268
	.global gUnk_FieldRenderResource_025
gUnk_FieldRenderResource_025:
	.incbin "baserom_de.gba", 0x46CA8C, 0x268
	.global gUnk_FieldRenderResource_018
gUnk_FieldRenderResource_018:
	.incbin "baserom_de.gba", 0x46CCF4, 0x150
	.global gUnk_FieldRenderResource_019
gUnk_FieldRenderResource_019:
	.incbin "baserom_de.gba", 0x46CE44, 0x150
	.global gUnk_FarmHouseTilePatchResource_011
gUnk_FarmHouseTilePatchResource_011:
	.incbin "baserom_de.gba", 0x46CF94, 0x244
	.global gUnk_FarmHouseTilePatchResource_009
gUnk_FarmHouseTilePatchResource_009:
	.incbin "baserom_de.gba", 0x46D1D8, 0x704
	.global gUnk_FarmHouseTilePatchResource_004
gUnk_FarmHouseTilePatchResource_004:
	.incbin "baserom_de.gba", 0x46D8DC, 0x724
	.global gUnk_FarmHouseTilePatchResource_003
gUnk_FarmHouseTilePatchResource_003:
	.incbin "baserom_de.gba", 0x46E000, 0x484
	.global gUnk_FieldRenderResource_043
gUnk_FieldRenderResource_043:
	.incbin "baserom_de.gba", 0x46E484, 0x1BC
	.global gUnk_FieldRenderResource_044
gUnk_FieldRenderResource_044:
	.incbin "baserom_de.gba", 0x46E640, 0x1BC
	.global gUnk_FieldRenderResource_045
gUnk_FieldRenderResource_045:
	.incbin "baserom_de.gba", 0x46E7FC, 0x1BC
	.global gUnk_FieldRenderResource_035
gUnk_FieldRenderResource_035:
	.incbin "baserom_de.gba", 0x46E9B8, 0xEC
	.global gUnk_FieldRenderResource_036
gUnk_FieldRenderResource_036:
	.incbin "baserom_de.gba", 0x46EAA4, 0xEC
	.global gUnk_FieldRenderResource_037
gUnk_FieldRenderResource_037:
	.incbin "baserom_de.gba", 0x46EB90, 0xEC
	.global gUnk_FieldRenderResource_016
gUnk_FieldRenderResource_016:
	.incbin "baserom_de.gba", 0x46EC7C, 0x270
	.global gUnk_FieldRenderResource_017
gUnk_FieldRenderResource_017:
	.incbin "baserom_de.gba", 0x46EEEC, 0x270
	.global gUnk_FieldRenderResource_010
gUnk_FieldRenderResource_010:
	.incbin "baserom_de.gba", 0x46F15C, 0x180
	.global gUnk_FieldRenderResource_011
gUnk_FieldRenderResource_011:
	.incbin "baserom_de.gba", 0x46F2DC, 0x180
	.global gUnk_FieldRenderResource_004
gUnk_FieldRenderResource_004:
	.incbin "baserom_de.gba", 0x46F45C, 0xC0
	.global gUnk_FieldRenderResource_005
gUnk_FieldRenderResource_005:
	.incbin "baserom_de.gba", 0x46F51C, 0xC0
	.global gUnk_FarmHouseTilePatchResource_001
gUnk_FarmHouseTilePatchResource_001:
	.incbin "baserom_de.gba", 0x46F5DC, 0x244
	.global gUnk_FarmHouseTilePatchResource_008
gUnk_FarmHouseTilePatchResource_008:
	.incbin "baserom_de.gba", 0x46F820, 0xE04
	.global gUnk_FieldRenderResource_028
gUnk_FieldRenderResource_028:
	.incbin "baserom_de.gba", 0x470624, 0x23C
	.global gUnk_FieldRenderResource_029
gUnk_FieldRenderResource_029:
	.incbin "baserom_de.gba", 0x470860, 0x23C
	.global gUnk_FieldRenderResource_022
gUnk_FieldRenderResource_022:
	.incbin "baserom_de.gba", 0x470A9C, 0x138
	.global gUnk_FieldRenderResource_023
gUnk_FieldRenderResource_023:
	.incbin "baserom_de.gba", 0x470BD4, 0x138
	.global gUnk_FarmHouseTilePatchResource_012
gUnk_FarmHouseTilePatchResource_012:
	.incbin "baserom_de.gba", 0x470D0C, 0x244
	.global gUnk_FarmHouseTilePatchResource_010
gUnk_FarmHouseTilePatchResource_010:
	.incbin "baserom_de.gba", 0x470F50, 0x704
	.global gUnk_FarmHouseTilePatchResource_005
gUnk_FarmHouseTilePatchResource_005:
	.incbin "baserom_de.gba", 0x471654, 0x724
	.global gUnk_086EACDC
gUnk_086EACDC:
	.incbin "baserom_de.gba", 0x471D78, 0x8
	.global gUnk_086EACE4
gUnk_086EACE4:
	.incbin "baserom_de.gba", 0x471D80, 0x20
	.global gUnk_086EAD04
gUnk_086EAD04:
	.incbin "baserom_de.gba", 0x471DA0, 0x20
	.global gUnk_086EAD24
gUnk_086EAD24:
	.incbin "baserom_de.gba", 0x471DC0, 0x20
	.global gUnk_086EAD44
gUnk_086EAD44:
	.incbin "baserom_de.gba", 0x471DE0, 0x20
	.global gUnk_086EAD64
gUnk_086EAD64:
	.incbin "baserom_de.gba", 0x471E00, 0x20
	.global gUnk_086EAD84
gUnk_086EAD84:
	.incbin "baserom_de.gba", 0x471E20, 0x8
	.global gUnk_086EAD8C
gUnk_086EAD8C:
	.incbin "baserom_de.gba", 0x471E28, 0x20
	.global gUnk_FieldRenderResource_154
gUnk_FieldRenderResource_154:
	.incbin "baserom_de.gba", 0x471E48, 0xC
	.global gUnk_FieldRenderResource_219
gUnk_FieldRenderResource_219:
	.incbin "baserom_de.gba", 0x471E54, 0x20
	.global gUnk_FieldRenderResource_222
gUnk_FieldRenderResource_222:
	.incbin "baserom_de.gba", 0x471E74, 0x20
	.global gUnk_FieldRenderResource_157
gUnk_FieldRenderResource_157:
	.incbin "baserom_de.gba", 0x471E94, 0xC
	.global gUnk_FieldRenderResource_151
gUnk_FieldRenderResource_151:
	.incbin "baserom_de.gba", 0x471EA0, 0xC
	.global gUnk_FieldRenderResource_166
gUnk_FieldRenderResource_166:
	.incbin "baserom_de.gba", 0x471EAC, 0x5C
	.global gUnk_FieldRenderResource_160
gUnk_FieldRenderResource_160:
	.incbin "baserom_de.gba", 0x471F08, 0x5C
	.global gUnk_FieldRenderResource_163
gUnk_FieldRenderResource_163:
	.incbin "baserom_de.gba", 0x471F64, 0x5C
	.global gUnk_FieldRenderResource_227
gUnk_FieldRenderResource_227:
	.incbin "baserom_de.gba", 0x471FC0, 0x8
	.global gUnk_FieldRenderResource_119
gUnk_FieldRenderResource_119:
	.incbin "baserom_de.gba", 0x471FC8, 0x8
	.global gUnk_FieldRenderResource_106
gUnk_FieldRenderResource_106:
	.incbin "baserom_de.gba", 0x471FD0, 0x20
	.global gUnk_FieldRenderResource_107
gUnk_FieldRenderResource_107:
	.incbin "baserom_de.gba", 0x471FF0, 0x20
	.global gUnk_FieldRenderResource_203
gUnk_FieldRenderResource_203:
	.incbin "baserom_de.gba", 0x472010, 0x20
	.global gUnk_FieldRenderResource_206
gUnk_FieldRenderResource_206:
	.incbin "baserom_de.gba", 0x472030, 0x20
	.global gUnk_FieldRenderResource_199
gUnk_FieldRenderResource_199:
	.incbin "baserom_de.gba", 0x472050, 0x20
	.global gUnk_FieldRenderResource_202
gUnk_FieldRenderResource_202:
	.incbin "baserom_de.gba", 0x472070, 0x20
	.global gUnk_FieldRenderResource_179
gUnk_FieldRenderResource_179:
	.incbin "baserom_de.gba", 0x472090, 0x20
	.global gUnk_FieldRenderResource_182
gUnk_FieldRenderResource_182:
	.incbin "baserom_de.gba", 0x4720B0, 0x20
	.global gUnk_FieldRenderResource_187
gUnk_FieldRenderResource_187:
	.incbin "baserom_de.gba", 0x4720D0, 0x20
	.global gUnk_FieldRenderResource_190
gUnk_FieldRenderResource_190:
	.incbin "baserom_de.gba", 0x4720F0, 0x20
	.global gUnk_FieldRenderResource_183
gUnk_FieldRenderResource_183:
	.incbin "baserom_de.gba", 0x472110, 0x20
	.global gUnk_FieldRenderResource_186
gUnk_FieldRenderResource_186:
	.incbin "baserom_de.gba", 0x472130, 0x20
	.global gUnk_FieldRenderResource_169
gUnk_FieldRenderResource_169:
	.incbin "baserom_de.gba", 0x472150, 0x18
	.global gUnk_FieldRenderResource_170
gUnk_FieldRenderResource_170:
	.incbin "baserom_de.gba", 0x472168, 0x18
	.global gUnk_FieldRenderResource_195
gUnk_FieldRenderResource_195:
	.incbin "baserom_de.gba", 0x472180, 0x20
	.global gUnk_FieldRenderResource_198
gUnk_FieldRenderResource_198:
	.incbin "baserom_de.gba", 0x4721A0, 0x20
	.global gUnk_FieldRenderResource_191
gUnk_FieldRenderResource_191:
	.incbin "baserom_de.gba", 0x4721C0, 0x20
	.global gUnk_FieldRenderResource_194
gUnk_FieldRenderResource_194:
	.incbin "baserom_de.gba", 0x4721E0, 0x20
	.global gUnk_FieldRenderResource_103
gUnk_FieldRenderResource_103:
	.incbin "baserom_de.gba", 0x472200, 0x20
	.global gUnk_FieldRenderResource_102
gUnk_FieldRenderResource_102:
	.incbin "baserom_de.gba", 0x472220, 0x20
	.global gUnk_FieldRenderResource_089
gUnk_FieldRenderResource_089:
	.incbin "baserom_de.gba", 0x472240, 0x60
	.global gUnk_FieldRenderResource_099
gUnk_FieldRenderResource_099:
	.incbin "baserom_de.gba", 0x4722A0, 0x24
	.global gUnk_FieldRenderResource_082
gUnk_FieldRenderResource_082:
	.incbin "baserom_de.gba", 0x4722C4, 0x12C
	.global gUnk_FieldRenderResource_083
gUnk_FieldRenderResource_083:
	.incbin "baserom_de.gba", 0x4723F0, 0x12C
	.global gUnk_FieldRenderResource_096
gUnk_FieldRenderResource_096:
	.incbin "baserom_de.gba", 0x47251C, 0x18
	.global gUnk_FieldRenderResource_070
gUnk_FieldRenderResource_070:
	.incbin "baserom_de.gba", 0x472534, 0x18
	.global gUnk_FieldRenderResource_071
gUnk_FieldRenderResource_071:
	.incbin "baserom_de.gba", 0x47254C, 0x18
	.global gUnk_FieldRenderResource_078
gUnk_FieldRenderResource_078:
	.incbin "baserom_de.gba", 0x472564, 0x18
	.global gUnk_FieldRenderResource_079
gUnk_FieldRenderResource_079:
	.incbin "baserom_de.gba", 0x47257C, 0x18
	.global gUnk_FieldRenderResource_074
gUnk_FieldRenderResource_074:
	.incbin "baserom_de.gba", 0x472594, 0x18
	.global gUnk_FieldRenderResource_075
gUnk_FieldRenderResource_075:
	.incbin "baserom_de.gba", 0x4725AC, 0x18
	.global gUnk_FieldRenderResource_058
gUnk_FieldRenderResource_058:
	.incbin "baserom_de.gba", 0x4725C4, 0x30
	.global gUnk_FieldRenderResource_059
gUnk_FieldRenderResource_059:
	.incbin "baserom_de.gba", 0x4725F4, 0x30
	.global gUnk_FieldRenderResource_054
gUnk_FieldRenderResource_054:
	.incbin "baserom_de.gba", 0x472624, 0x30
	.global gUnk_FieldRenderResource_055
gUnk_FieldRenderResource_055:
	.incbin "baserom_de.gba", 0x472654, 0x30
	.global gUnk_FieldRenderResource_092
gUnk_FieldRenderResource_092:
	.incbin "baserom_de.gba", 0x472684, 0xF0
	.global gUnk_FieldRenderResource_066
gUnk_FieldRenderResource_066:
	.incbin "baserom_de.gba", 0x472774, 0x38
	.global gUnk_FieldRenderResource_067
gUnk_FieldRenderResource_067:
	.incbin "baserom_de.gba", 0x4727AC, 0x38
	.global gUnk_FieldRenderResource_062
gUnk_FieldRenderResource_062:
	.incbin "baserom_de.gba", 0x4727E4, 0x38
	.global gUnk_FieldRenderResource_063
gUnk_FieldRenderResource_063:
	.incbin "baserom_de.gba", 0x47281C, 0x38
	.global gUnk_FarmHouseTilePatchResource_006
gUnk_FarmHouseTilePatchResource_006:
	.incbin "baserom_de.gba", 0x472854, 0x184
	.global gUnk_FieldRenderResource_086
gUnk_FieldRenderResource_086:
	.incbin "baserom_de.gba", 0x4729D8, 0x60
	.global gUnk_FieldRenderResource_050
gUnk_FieldRenderResource_050:
	.incbin "baserom_de.gba", 0x472A38, 0x30
	.global gUnk_FieldRenderResource_051
gUnk_FieldRenderResource_051:
	.incbin "baserom_de.gba", 0x472A68, 0x30
	.global gUnk_FieldRenderResource_046
gUnk_FieldRenderResource_046:
	.incbin "baserom_de.gba", 0x472A98, 0x30
	.global gUnk_FieldRenderResource_047
gUnk_FieldRenderResource_047:
	.incbin "baserom_de.gba", 0x472AC8, 0x30
	.global gUnk_FieldRenderResource_093
gUnk_FieldRenderResource_093:
	.incbin "baserom_de.gba", 0x472AF8, 0xC
	.global gUnk_FieldRenderResource_173
gUnk_FieldRenderResource_173:
	.incbin "baserom_de.gba", 0x472B04, 0x20
	.global gUnk_FieldRenderResource_176
gUnk_FieldRenderResource_176:
	.incbin "baserom_de.gba", 0x472B24, 0x20
	.global gUnk_FarmHouseTilePatchResource_027
gUnk_FarmHouseTilePatchResource_027:
	.incbin "baserom_de.gba", 0x472B44, 0x1004
	.global gUnk_FarmHouseVisualResource_004
gUnk_FarmHouseVisualResource_004:
	.incbin "baserom_de.gba", 0x473B48, 0x3C4
	.global gUnk_FarmHouseVisualResource_005
gUnk_FarmHouseVisualResource_005:
	.incbin "baserom_de.gba", 0x473F0C, 0x20
	.global gUnk_FarmHouseVisualResource_000
gUnk_FarmHouseVisualResource_000:
	.incbin "baserom_de.gba", 0x473F2C, 0x30
	.global gUnk_FarmHouseVisualResource_001
gUnk_FarmHouseVisualResource_001:
	.incbin "baserom_de.gba", 0x473F5C, 0x30
	.global gUnk_FarmHouseVisualResource_010
gUnk_FarmHouseVisualResource_010:
	.incbin "baserom_de.gba", 0x473F8C, 0x424
	.global gUnk_FarmHouseVisualResource_011
gUnk_FarmHouseVisualResource_011:
	.incbin "baserom_de.gba", 0x4743B0, 0x60
	.global gUnk_FarmHouseVisualResource_006
gUnk_FarmHouseVisualResource_006:
	.incbin "baserom_de.gba", 0x474410, 0xD4
	.global gUnk_FarmHouseVisualResource_007
gUnk_FarmHouseVisualResource_007:
	.incbin "baserom_de.gba", 0x4744E4, 0xD4
	.global gUnk_FarmHouseVisualResource_012
gUnk_FarmHouseVisualResource_012:
	.incbin "baserom_de.gba", 0x4745B8, 0x60
	.global gUnk_FarmHouseVisualResource_034
gUnk_FarmHouseVisualResource_034:
	.incbin "baserom_de.gba", 0x474618, 0x364
	.global gUnk_FarmHouseVisualResource_035
gUnk_FarmHouseVisualResource_035:
	.incbin "baserom_de.gba", 0x47497C, 0x60
	.global gUnk_FarmHouseVisualResource_030
gUnk_FarmHouseVisualResource_030:
	.incbin "baserom_de.gba", 0x4749DC, 0x28
	.global gUnk_FarmHouseVisualResource_031
gUnk_FarmHouseVisualResource_031:
	.incbin "baserom_de.gba", 0x474A04, 0x28
	.global gUnk_FarmHouseVisualResource_036
gUnk_FarmHouseVisualResource_036:
	.incbin "baserom_de.gba", 0x474A2C, 0x60
	.global gUnk_FarmHouseVisualResource_041
gUnk_FarmHouseVisualResource_041:
	.incbin "baserom_de.gba", 0x474A8C, 0x10DC
	.global gUnk_FarmHouseVisualResource_042
gUnk_FarmHouseVisualResource_042:
	.incbin "baserom_de.gba", 0x475B68, 0x80
	.global gUnk_FarmHouseVisualResource_037
gUnk_FarmHouseVisualResource_037:
	.incbin "baserom_de.gba", 0x475BE8, 0x120
	.global gUnk_FarmHouseVisualResource_038
gUnk_FarmHouseVisualResource_038:
	.incbin "baserom_de.gba", 0x475D08, 0x120
	.global gUnk_FarmHouseTilePatchAnimationResource_001
gUnk_FarmHouseTilePatchAnimationResource_001:
	.incbin "baserom_de.gba", 0x475E28, 0x304
	.global gUnk_FarmHouseTilePatchAnimationResource_000
gUnk_FarmHouseTilePatchAnimationResource_000:
	.incbin "baserom_de.gba", 0x47612C, 0x904
	.global gUnk_FarmHouseVisualResource_022
gUnk_FarmHouseVisualResource_022:
	.incbin "baserom_de.gba", 0x476A30, 0xB9C
	.global gUnk_FarmHouseVisualResource_023
gUnk_FarmHouseVisualResource_023:
	.incbin "baserom_de.gba", 0x4775CC, 0x20
	.global gUnk_FarmHouseVisualResource_018
gUnk_FarmHouseVisualResource_018:
	.incbin "baserom_de.gba", 0x4775EC, 0x138
	.global gUnk_FarmHouseVisualResource_019
gUnk_FarmHouseVisualResource_019:
	.incbin "baserom_de.gba", 0x477724, 0x138
	.global gUnk_FarmHouseVisualResource_028
gUnk_FarmHouseVisualResource_028:
	.incbin "baserom_de.gba", 0x47785C, 0x16EC
	.global gUnk_FarmHouseVisualResource_029
gUnk_FarmHouseVisualResource_029:
	.incbin "baserom_de.gba", 0x478F48, 0x60
	.global gUnk_FarmHouseVisualResource_024
gUnk_FarmHouseVisualResource_024:
	.incbin "baserom_de.gba", 0x478FA8, 0x510
	.global gUnk_FarmHouseVisualResource_025
gUnk_FarmHouseVisualResource_025:
	.incbin "baserom_de.gba", 0x4794B8, 0x510
	.global gUnk_FarmHouseVisualResource_015
gUnk_FarmHouseVisualResource_015:
	.incbin "baserom_de.gba", 0x4799C8, 0x418
	.global gUnk_FarmHouseVisualResource_016
gUnk_FarmHouseVisualResource_016:
	.incbin "baserom_de.gba", 0x479DE0, 0x60
	.global gUnk_FarmHouseVisualResource_013
gUnk_FarmHouseVisualResource_013:
	.incbin "baserom_de.gba", 0x479E40, 0xD4
	.global gUnk_FarmHouseVisualResource_014
gUnk_FarmHouseVisualResource_014:
	.incbin "baserom_de.gba", 0x479F14, 0xD4
	.global gUnk_FarmHouseVisualResource_017
gUnk_FarmHouseVisualResource_017:
	.incbin "baserom_de.gba", 0x479FE8, 0x60
	.global gUnk_086F2FAC
gUnk_086F2FAC:
	.incbin "baserom_de.gba", 0x47A048, 0x31FC
	.global gUnk_FieldRenderResource_114
gUnk_FieldRenderResource_114:
	.incbin "baserom_de.gba", 0x47D244, 0x20
	.global gUnk_FieldRenderResource_115
gUnk_FieldRenderResource_115:
	.incbin "baserom_de.gba", 0x47D264, 0x20
	.global gUnk_FieldRenderResource_118
gUnk_FieldRenderResource_118:
	.incbin "baserom_de.gba", 0x47D284, 0x8
	.global gUnk_FieldRenderResource_110
gUnk_FieldRenderResource_110:
	.incbin "baserom_de.gba", 0x47D28C, 0x20
	.global gUnk_FieldRenderResource_111
gUnk_FieldRenderResource_111:
	.incbin "baserom_de.gba", 0x47D2AC, 0x20
	.global gUnk_FieldRenderResource_215
gUnk_FieldRenderResource_215:
	.incbin "baserom_de.gba", 0x47D2CC, 0x20
	.global gUnk_FieldRenderResource_218
gUnk_FieldRenderResource_218:
	.incbin "baserom_de.gba", 0x47D2EC, 0x20
	.global gUnk_FarmHouseTilePatchResource_014
gUnk_FarmHouseTilePatchResource_014:
	.incbin "baserom_de.gba", 0x47D30C, 0x804
	.global gUnk_FieldRenderResource_122
gUnk_FieldRenderResource_122:
	.incbin "baserom_de.gba", 0x47DB10, 0x1C0
	.global gUnk_FieldRenderResource_123
gUnk_FieldRenderResource_123:
	.incbin "baserom_de.gba", 0x47DCD0, 0x1C0
	.global gUnk_FarmHouseTilePatchResource_015
gUnk_FarmHouseTilePatchResource_015:
	.incbin "baserom_de.gba", 0x47DE90, 0x1884
	.global gUnk_FarmHouseTilePatchResource_016
gUnk_FarmHouseTilePatchResource_016:
	.incbin "baserom_de.gba", 0x47F714, 0x804
	.global gUnk_FieldRenderResource_126
gUnk_FieldRenderResource_126:
	.incbin "baserom_de.gba", 0x47FF18, 0x1C0
	.global gUnk_FieldRenderResource_127
gUnk_FieldRenderResource_127:
	.incbin "baserom_de.gba", 0x4800D8, 0x1C0
	.global gUnk_FarmHouseTilePatchResource_017
gUnk_FarmHouseTilePatchResource_017:
	.incbin "baserom_de.gba", 0x480298, 0x1884
	.global gUnk_086FAA80
gUnk_086FAA80:
	.incbin "baserom_de.gba", 0x481B1C, 0x584
	.global gUnk_MapDataResource_014
gUnk_MapDataResource_014:
	.global gUnk_086FB004
gUnk_086FB004:
	.incbin "baserom_de.gba", 0x4820A0, 0x2198
	.global gUnk_MapDataResource_015
gUnk_MapDataResource_015:
	.global gUnk_086FD19C
gUnk_086FD19C:
	.incbin "baserom_de.gba", 0x484238, 0xA4
	.global gUnk_MapDataResource_017
gUnk_MapDataResource_017:
	.global gUnk_086FD240
gUnk_086FD240:
	.incbin "baserom_de.gba", 0x4842DC, 0x590
	.global gUnk_MapDataResource_018
gUnk_MapDataResource_018:
	.incbin "baserom_de.gba", 0x48486C, 0x224
	.global gUnk_MapDataResource_019
gUnk_MapDataResource_019:
	.incbin "baserom_de.gba", 0x484A90, 0x98
	.global gUnk_MapDataResource_016
gUnk_MapDataResource_016:
	.incbin "baserom_de.gba", 0x484B28, 0xA0
	.global gUnk_MapDataResource_022
gUnk_MapDataResource_022:
	.incbin "baserom_de.gba", 0x484BC8, 0x1F58
	.global gUnk_MapDataResource_023
gUnk_MapDataResource_023:
	.incbin "baserom_de.gba", 0x486B20, 0xA0
	.global gUnk_MapDataResource_025
gUnk_MapDataResource_025:
	.incbin "baserom_de.gba", 0x486BC0, 0x58C
	.global gUnk_MapDataResource_026
gUnk_MapDataResource_026:
	.incbin "baserom_de.gba", 0x48714C, 0x21C
	.global gUnk_MapDataResource_027
gUnk_MapDataResource_027:
	.incbin "baserom_de.gba", 0x487368, 0xA8
	.global gUnk_MapDataResource_024
gUnk_MapDataResource_024:
	.incbin "baserom_de.gba", 0x487410, 0x94
	.global gUnk_MapDataResource_132
gUnk_MapDataResource_132:
	.incbin "baserom_de.gba", 0x4874A4, 0x1D8
	.global gUnk_MapDataResource_133
gUnk_MapDataResource_133:
	.incbin "baserom_de.gba", 0x48767C, 0x104
	.global gUnk_MapDataResource_134
gUnk_MapDataResource_134:
	.incbin "baserom_de.gba", 0x487780, 0xD0
	.global gUnk_MapDataResource_137
gUnk_MapDataResource_137:
	.incbin "baserom_de.gba", 0x487850, 0x200
	.global gUnk_MapDataResource_138
gUnk_MapDataResource_138:
	.incbin "baserom_de.gba", 0x487A50, 0xB8
	.global gUnk_MapDataResource_139
gUnk_MapDataResource_139:
	.incbin "baserom_de.gba", 0x487B08, 0x74
	.global gUnk_MapDataResource_328
gUnk_MapDataResource_328:
	.incbin "baserom_de.gba", 0x487B7C, 0x18C
	.global gUnk_MapDataResource_329
gUnk_MapDataResource_329:
	.incbin "baserom_de.gba", 0x487D08, 0x118
	.global gUnk_MapDataResource_330
gUnk_MapDataResource_330:
	.incbin "baserom_de.gba", 0x487E20, 0x8C
	.global gUnk_MapDataResource_166
gUnk_MapDataResource_166:
	.incbin "baserom_de.gba", 0x487EAC, 0x2AC4
	.global gUnk_MapDataResource_167
gUnk_MapDataResource_167:
	.incbin "baserom_de.gba", 0x48A970, 0x140
	.global gUnk_MapDataResource_173
gUnk_MapDataResource_173:
	.incbin "baserom_de.gba", 0x48AAB0, 0x14C
	.global gUnk_MapDataResource_174
gUnk_MapDataResource_174:
	.incbin "baserom_de.gba", 0x48ABFC, 0x110
	.global gUnk_MapDataResource_175
gUnk_MapDataResource_175:
	.incbin "baserom_de.gba", 0x48AD0C, 0xD8
	.global gUnk_MapDataResource_239
gUnk_MapDataResource_239:
	.incbin "baserom_de.gba", 0x48ADE4, 0x4C4
	.global gUnk_MapDataResource_240
gUnk_MapDataResource_240:
	.incbin "baserom_de.gba", 0x48B2A8, 0x11C
	.global gUnk_MapDataResource_241
gUnk_MapDataResource_241:
	.incbin "baserom_de.gba", 0x48B3C4, 0xFC
	.global gUnk_MapDataResource_234
gUnk_MapDataResource_234:
	.incbin "baserom_de.gba", 0x48B4C0, 0x398
	.global gUnk_MapDataResource_235
gUnk_MapDataResource_235:
	.incbin "baserom_de.gba", 0x48B858, 0xDC
	.global gUnk_MapDataResource_236
gUnk_MapDataResource_236:
	.incbin "baserom_de.gba", 0x48B934, 0xE0
	.global gUnk_MapDataResource_292
gUnk_MapDataResource_292:
	.incbin "baserom_de.gba", 0x48BA14, 0x1F4
	.global gUnk_MapDataResource_293
gUnk_MapDataResource_293:
	.incbin "baserom_de.gba", 0x48BC08, 0xE8
	.global gUnk_MapDataResource_294
gUnk_MapDataResource_294:
	.incbin "baserom_de.gba", 0x48BCF0, 0xDC
	.global gUnk_MapDataResource_042
gUnk_MapDataResource_042:
	.incbin "baserom_de.gba", 0x48BDCC, 0x4E78
	.global gUnk_MapDataResource_043
gUnk_MapDataResource_043:
	.incbin "baserom_de.gba", 0x490C44, 0x18C
	.global gUnk_MapDataResource_045
gUnk_MapDataResource_045:
	.incbin "baserom_de.gba", 0x490DD0, 0xB74
	.global gUnk_MapDataResource_046
gUnk_MapDataResource_046:
	.incbin "baserom_de.gba", 0x491944, 0x978
	.global gUnk_MapDataResource_047
gUnk_MapDataResource_047:
	.incbin "baserom_de.gba", 0x4922BC, 0x488
	.global gUnk_MapDataResource_044
gUnk_MapDataResource_044:
	.incbin "baserom_de.gba", 0x492744, 0x174
	.global gUnk_MapDataResource_050
gUnk_MapDataResource_050:
	.incbin "baserom_de.gba", 0x4928B8, 0x4C98
	.global gUnk_MapDataResource_051
gUnk_MapDataResource_051:
	.incbin "baserom_de.gba", 0x497550, 0x128
	.global gUnk_MapDataResource_053
gUnk_MapDataResource_053:
	.incbin "baserom_de.gba", 0x497678, 0x8D4
	.global gUnk_MapDataResource_054
gUnk_MapDataResource_054:
	.incbin "baserom_de.gba", 0x497F4C, 0x968
	.global gUnk_MapDataResource_055
gUnk_MapDataResource_055:
	.incbin "baserom_de.gba", 0x4988B4, 0x478
	.global gUnk_MapDataResource_052
gUnk_MapDataResource_052:
	.incbin "baserom_de.gba", 0x498D2C, 0x110
	.global gUnk_MapDataResource_106
gUnk_MapDataResource_106:
	.incbin "baserom_de.gba", 0x498E3C, 0x27E0
	.global gUnk_MapDataResource_107
gUnk_MapDataResource_107:
	.incbin "baserom_de.gba", 0x49B61C, 0x90
	.global gUnk_MapDataResource_109
gUnk_MapDataResource_109:
	.incbin "baserom_de.gba", 0x49B6AC, 0x1C0
	.global gUnk_MapDataResource_110
gUnk_MapDataResource_110:
	.incbin "baserom_de.gba", 0x49B86C, 0x1B0
	.global gUnk_MapDataResource_111
gUnk_MapDataResource_111:
	.incbin "baserom_de.gba", 0x49BA1C, 0xB0
	.global gUnk_08714A30
gUnk_08714A30:
	.incbin "baserom_de.gba", 0x49BACC, 0xA0
	.global gUnk_MapDataResource_108
gUnk_MapDataResource_108:
	.incbin "baserom_de.gba", 0x49BB6C, 0x90
	.global gUnk_08714B60
gUnk_08714B60:
	.incbin "baserom_de.gba", 0x49BBFC, 0x8C
	.global gUnk_08714BEC
gUnk_08714BEC:
	.incbin "baserom_de.gba", 0x49BC88, 0x98
	.global gUnk_MapDataResource_114
gUnk_MapDataResource_114:
	.incbin "baserom_de.gba", 0x49BD20, 0x1EB4
	.global gUnk_MapDataResource_115
gUnk_MapDataResource_115:
	.incbin "baserom_de.gba", 0x49DBD4, 0x88
	.global gUnk_MapDataResource_117
gUnk_MapDataResource_117:
	.incbin "baserom_de.gba", 0x49DC5C, 0x164
	.global gUnk_MapDataResource_118
gUnk_MapDataResource_118:
	.incbin "baserom_de.gba", 0x49DDC0, 0x1A8
	.global gUnk_MapDataResource_119
gUnk_MapDataResource_119:
	.incbin "baserom_de.gba", 0x49DF68, 0xB8
	.global gUnk_08716F84
gUnk_08716F84:
	.incbin "baserom_de.gba", 0x49E020, 0x94
	.global gUnk_MapDataResource_116
gUnk_MapDataResource_116:
	.incbin "baserom_de.gba", 0x49E0B4, 0xA0
	.global gUnk_087170B8
gUnk_087170B8:
	.incbin "baserom_de.gba", 0x49E154, 0x94
	.global gUnk_MapDataResource_333
gUnk_MapDataResource_333:
	.incbin "baserom_de.gba", 0x49E1E8, 0x1B8
	.global gUnk_MapDataResource_334
gUnk_MapDataResource_334:
	.incbin "baserom_de.gba", 0x49E3A0, 0x130
	.global gUnk_MapDataResource_335
gUnk_MapDataResource_335:
	.incbin "baserom_de.gba", 0x49E4D0, 0xA0
	.global gUnk_MapDataResource_370
gUnk_MapDataResource_370:
	.incbin "baserom_de.gba", 0x49E570, 0x94
	.global gUnk_MapDataResource_371
gUnk_MapDataResource_371:
	.incbin "baserom_de.gba", 0x49E604, 0x48
	.global gUnk_MapDataResource_374
gUnk_MapDataResource_374:
	.incbin "baserom_de.gba", 0x49E64C, 0x10C
	.global gUnk_MapDataResource_375
gUnk_MapDataResource_375:
	.incbin "baserom_de.gba", 0x49E758, 0x74
	.global gUnk_MapDataResource_376
gUnk_MapDataResource_376:
	.incbin "baserom_de.gba", 0x49E7CC, 0x224
	.global gUnk_MapDataResource_377
gUnk_MapDataResource_377:
	.incbin "baserom_de.gba", 0x49E9F0, 0xEC
	.global gUnk_MapDataResource_378
gUnk_MapDataResource_378:
	.incbin "baserom_de.gba", 0x49EADC, 0x1E4
	.global gUnk_MapDataResource_379
gUnk_MapDataResource_379:
	.incbin "baserom_de.gba", 0x49ECC0, 0xCC
	.global gUnk_MapDataResource_297
gUnk_MapDataResource_297:
	.incbin "baserom_de.gba", 0x49ED8C, 0x174
	.global gUnk_MapDataResource_298
gUnk_MapDataResource_298:
	.incbin "baserom_de.gba", 0x49EF00, 0x1A4
	.global gUnk_MapDataResource_299
gUnk_MapDataResource_299:
	.incbin "baserom_de.gba", 0x49F0A4, 0xD8
	.global gUnk_MapDataResource_290
gUnk_MapDataResource_290:
	.incbin "baserom_de.gba", 0x49F17C, 0x29F8
	.global gUnk_MapDataResource_291
gUnk_MapDataResource_291:
	.incbin "baserom_de.gba", 0x4A1B74, 0xF0
	.global gUnk_MapDataResource_280
gUnk_MapDataResource_280:
	.incbin "baserom_de.gba", 0x4A1C64, 0x264
	.global gUnk_MapDataResource_281
gUnk_MapDataResource_281:
	.incbin "baserom_de.gba", 0x4A1EC8, 0x158
	.global gUnk_MapDataResource_282
gUnk_MapDataResource_282:
	.incbin "baserom_de.gba", 0x4A2020, 0x104
	.global gUnk_MapDataResource_285
gUnk_MapDataResource_285:
	.incbin "baserom_de.gba", 0x4A2124, 0x224
	.global gUnk_MapDataResource_286
gUnk_MapDataResource_286:
	.incbin "baserom_de.gba", 0x4A2348, 0x128
	.global gUnk_MapDataResource_287
gUnk_MapDataResource_287:
	.incbin "baserom_de.gba", 0x4A2470, 0xA0
	.global gUnk_MapDataResource_278
gUnk_MapDataResource_278:
	.incbin "baserom_de.gba", 0x4A2510, 0x1F80
	.global gUnk_MapDataResource_279
gUnk_MapDataResource_279:
	.incbin "baserom_de.gba", 0x4A4490, 0x128

	@ Direct DE archive payload labels, ordered by their native ROM offsets.
	.global gUnk_0871D51C
gUnk_0871D51C:
	.incbin "baserom_de.gba", 0x4A45B8, 0x13BC
	.global gUnk_0871E7A8
gUnk_0871E7A8:
	.incbin "baserom_de.gba", 0x4A5974, 0x504
	.global gUnk_0871ECAC
gUnk_0871ECAC:
	.incbin "baserom_de.gba", 0x4A5E78, 0x128
	.global gUnk_0871EDD4
gUnk_0871EDD4:
	.incbin "baserom_de.gba", 0x4A5FA0, 0x12C
	.global gUnk_0871EF00
gUnk_0871EF00:
	.incbin "baserom_de.gba", 0x4A60CC, 0x6EA0
	.global gUnk_08725DA0
gUnk_08725DA0:
	.incbin "baserom_de.gba", 0x4ACF6C, 0xF2C
	.global gUnk_08726CCC
gUnk_08726CCC:
	.incbin "baserom_de.gba", 0x4ADE98, 0x69C
	.global gUnk_08727368
gUnk_08727368:
	.incbin "baserom_de.gba", 0x4AE534, 0x70C
	.global gUnk_08727A74
gUnk_08727A74:
	.incbin "baserom_de.gba", 0x4AEC40, 0x794
	.global gUnk_08728208
gUnk_08728208:
	.incbin "baserom_de.gba", 0x4AF3D4, 0x118
	.global gUnk_08728320
gUnk_08728320:
	.incbin "baserom_de.gba", 0x4AF4EC, 0x105C
	.global gUnk_0872937C
gUnk_0872937C:
	.incbin "baserom_de.gba", 0x4B0548, 0xE4
	.global gUnk_08729460
gUnk_08729460:
	.incbin "baserom_de.gba", 0x4B062C, 0x2A04
	.global gUnk_0872BE64
gUnk_0872BE64:
	.incbin "baserom_de.gba", 0x4B3030, 0x874
	.global gUnk_0872C5D0
gUnk_0872C5D0:
	.incbin "baserom_de.gba", 0x4B38A4, 0x16C
	.global gUnk_0872C73C
gUnk_0872C73C:
	.incbin "baserom_de.gba", 0x4B3A10, 0x110
	.global gUnk_0872C84C
gUnk_0872C84C:
	.incbin "baserom_de.gba", 0x4B3B20, 0xD60
	.global gUnk_0872D5AC
gUnk_0872D5AC:
	.incbin "baserom_de.gba", 0x4B4880, 0x20
	.global gUnk_0872D5CC
gUnk_0872D5CC:
	.incbin "baserom_de.gba", 0x4B48A0, 0x64
	.global gUnk_0872D630
gUnk_0872D630:
	.incbin "baserom_de.gba", 0x4B4904, 0xA8
	.global gUnk_0872D6D8
gUnk_0872D6D8:
	.incbin "baserom_de.gba", 0x4B49AC, 0x70C
	.global gUnk_0872DDE4
gUnk_0872DDE4:
	.incbin "baserom_de.gba", 0x4B50B8, 0x60
	.global gUnk_0872DE44
gUnk_0872DE44:
	.incbin "baserom_de.gba", 0x4B5118, 0x10CC
	.global gUnk_0872EE78
gUnk_0872EE78:
	.incbin "baserom_de.gba", 0x4B61E4, 0x2A4
	.global gUnk_0872F11C
gUnk_0872F11C:
	.incbin "baserom_de.gba", 0x4B6488, 0xA0
	.global gUnk_0872F1BC
gUnk_0872F1BC:
	.incbin "baserom_de.gba", 0x4B6528, 0x30
	.global gUnk_0872F1EC
gUnk_0872F1EC:
	.incbin "baserom_de.gba", 0x4B6558, 0x30
	.global gUnk_0872F21C
gUnk_0872F21C:
	.incbin "baserom_de.gba", 0x4B6588, 0x880
	.global gUnk_0872FA9C
gUnk_0872FA9C:
	.incbin "baserom_de.gba", 0x4B6E08, 0x160
	.global gUnk_0872FBFC
gUnk_0872FBFC:
	.incbin "baserom_de.gba", 0x4B6F68, 0x38
	.global gUnk_0872FC34
gUnk_0872FC34:
	.incbin "baserom_de.gba", 0x4B6FA0, 0x238
	.global gUnk_0872FE6C
gUnk_0872FE6C:
	.incbin "baserom_de.gba", 0x4B71D8, 0x8C
	.global gUnk_0872FEF8
gUnk_0872FEF8:
	.incbin "baserom_de.gba", 0x4B7264, 0x1A48
	.global gUnk_08731940
gUnk_08731940:
	.incbin "baserom_de.gba", 0x4B8CAC, 0x200
	.global gUnk_08731B40
gUnk_08731B40:
	.incbin "baserom_de.gba", 0x4B8EAC, 0x6604
	.global gUnk_08738144
gUnk_08738144:
	.incbin "baserom_de.gba", 0x4BF4B0, 0x994
	.global gUnk_08738AD8
gUnk_08738AD8:
	.incbin "baserom_de.gba", 0x4BFE44, 0x1F0
	.global gUnk_08738CC8
gUnk_08738CC8:
	.incbin "baserom_de.gba", 0x4C0034, 0x28
	.global gUnk_08738CF0
gUnk_08738CF0:
	.incbin "baserom_de.gba", 0x4C005C, 0x2C
	.global gUnk_08738D1C
gUnk_08738D1C:
	.incbin "baserom_de.gba", 0x4C0088, 0xCA8
	.global gUnk_087399C4
gUnk_087399C4:
	.incbin "baserom_de.gba", 0x4C0D30, 0xA0
	.global gUnk_08739A64
gUnk_08739A64:
	.incbin "baserom_de.gba", 0x4C0DD0, 0xC84
	.global gUnk_0873A6E8
gUnk_0873A6E8:
	.incbin "baserom_de.gba", 0x4C1A54, 0x76C
	.global gUnk_0873AE54
gUnk_0873AE54:
	.incbin "baserom_de.gba", 0x4C21C0, 0x174
	.global gUnk_0873AFC8
gUnk_0873AFC8:
	.incbin "baserom_de.gba", 0x4C2334, 0xE5C
	.global gUnk_0873BE24
gUnk_0873BE24:
	.incbin "baserom_de.gba", 0x4C3190, 0x124
	.global gUnk_0873BF48
gUnk_0873BF48:
	.incbin "baserom_de.gba", 0x4C32B4, 0xA8
	.global gUnk_0873BFF0
gUnk_0873BFF0:
	.incbin "baserom_de.gba", 0x4C335C, 0xC04
	.global gUnk_0873CBF4
gUnk_0873CBF4:
	.incbin "baserom_de.gba", 0x4C3F60, 0xC0
	.global gUnk_0873CCB4
gUnk_0873CCB4:
	.incbin "baserom_de.gba", 0x4C4020, 0x1F8
	.global gUnk_0873CEAC
gUnk_0873CEAC:
	.incbin "baserom_de.gba", 0x4C4218, 0xE4
	.global gUnk_0873CF90
gUnk_0873CF90:
	.incbin "baserom_de.gba", 0x4C42FC, 0x2A4
	.global gUnk_0873D234
gUnk_0873D234:
	.incbin "baserom_de.gba", 0x4C45A0, 0x3C8
	.global gUnk_0873D5FC
gUnk_0873D5FC:
	.incbin "baserom_de.gba", 0x4C4968, 0xDC
	.global gUnk_0873D6D8
gUnk_0873D6D8:
	.incbin "baserom_de.gba", 0x4C4A44, 0x874
	.global gUnk_0873DE44
gUnk_0873DE44:
	.incbin "baserom_de.gba", 0x4C52B8, 0x76C
	.global gUnk_0873E5B0
gUnk_0873E5B0:
	.incbin "baserom_de.gba", 0x4C5A24, 0x76C
	.global gUnk_0873ED1C
gUnk_0873ED1C:
	.incbin "baserom_de.gba", 0x4C6190, 0x6AC
	.global gUnk_0873F3C8
gUnk_0873F3C8:
	.incbin "baserom_de.gba", 0x4C683C, 0x20C
	.global gUnk_0873F5D4
gUnk_0873F5D4:
	.incbin "baserom_de.gba", 0x4C6A48, 0xD8
	.global gUnk_0873F6AC
gUnk_0873F6AC:
	.incbin "baserom_de.gba", 0x4C6B20, 0xA38
	.global gUnk_087400E4
gUnk_087400E4:
	.incbin "baserom_de.gba", 0x4C7558, 0xC0
	.global gUnk_087401A4
gUnk_087401A4:
	.incbin "baserom_de.gba", 0x4C7618, 0x2B0
	.global gUnk_08740454
gUnk_08740454:
	.incbin "baserom_de.gba", 0x4C78C8, 0x14C
	.global gUnk_087405A0
gUnk_087405A0:
	.incbin "baserom_de.gba", 0x4C7A14, 0x368
	.global gUnk_08740908
gUnk_08740908:
	.incbin "baserom_de.gba", 0x4C7D7C, 0xDC
	.global gUnk_087409E4
gUnk_087409E4:
	.incbin "baserom_de.gba", 0x4C7E58, 0x1010

	@ These payloads are addressed by gIntroSceneUnpackSources.  They occupy
	@ one physical DE stream, so expose direct labels at their native offsets
	@ instead of assigning US-stream aliases to the regional data.
	.global gUnk_IntroSceneUnpackSource_000
gUnk_IntroSceneUnpackSource_000:
	.incbin "build/de/graphics/intro_scene/objects/object_00.0x70"
	.global gUnk_IntroSceneUnpackSource_001
gUnk_IntroSceneUnpackSource_001:
	.incbin "build/de/graphics/intro_scene/objects/object_01.0x70"
	.global gUnk_IntroSceneUnpackSource_002
gUnk_IntroSceneUnpackSource_002:
	.incbin "build/de/graphics/intro_scene/objects/object_02.0x70"
	.global gUnk_IntroSceneUnpackSource_003
gUnk_IntroSceneUnpackSource_003:
	.incbin "build/de/graphics/intro_scene/objects/object_03.0x70"
	.global gUnk_IntroSceneUnpackSource_004
gUnk_IntroSceneUnpackSource_004:
	.incbin "build/de/graphics/intro_scene/objects/object_04.0x70"
	.global gUnk_IntroSceneUnpackSource_005
gUnk_IntroSceneUnpackSource_005:
	.incbin "build/de/graphics/intro_scene/objects/object_05.0x70"
	.global gUnk_IntroSceneUnpackSource_006
gUnk_IntroSceneUnpackSource_006:
	.incbin "build/de/graphics/intro_scene/objects/object_06.0x70"
	.global gUnk_IntroSceneUnpackSource_007
gUnk_IntroSceneUnpackSource_007:
	.incbin "build/de/graphics/intro_scene/objects/object_07.0x70"
	.global gUnk_IntroSceneUnpackSource_008
gUnk_IntroSceneUnpackSource_008:
	.incbin "build/de/graphics/intro_scene/objects/object_08.0x70"
	.global gUnk_IntroSceneUnpackSource_009
gUnk_IntroSceneUnpackSource_009:
	.incbin "build/de/graphics/intro_scene/objects/object_09.0x70"
	.global gUnk_IntroSceneUnpackSource_010
gUnk_IntroSceneUnpackSource_010:
	.incbin "build/de/graphics/intro_scene/objects/object_10.0x70"
	.global gUnk_IntroSceneUnpackSource_011
gUnk_IntroSceneUnpackSource_011:
	.incbin "build/de/graphics/intro_scene/objects/object_11.0x70"
	.global gUnk_IntroSceneUnpackSource_012
gUnk_IntroSceneUnpackSource_012:
	.incbin "build/de/graphics/intro_scene/objects/object_12.0x70"
	.global gUnk_IntroSceneUnpackSource_013
gUnk_IntroSceneUnpackSource_013:
	.incbin "build/de/graphics/intro_scene/objects/object_13.0x70"
	.global gUnk_IntroSceneUnpackSource_014
gUnk_IntroSceneUnpackSource_014:
	.incbin "build/de/graphics/intro_scene/objects/object_14.0x70"
	.global gUnk_IntroSceneUnpackSource_015
gUnk_IntroSceneUnpackSource_015:
	.incbin "build/de/graphics/intro_scene/objects/object_15.0x70"
	.global gUnk_IntroSceneUnpackSource_016
gUnk_IntroSceneUnpackSource_016:
	.incbin "build/de/graphics/intro_scene/objects/object_16.0x70"
	.global gUnk_IntroSceneUnpackSource_017
gUnk_IntroSceneUnpackSource_017:
	.incbin "build/de/graphics/intro_scene/objects/object_17.0x70"
	.global gUnk_IntroSceneUnpackSource_018
gUnk_IntroSceneUnpackSource_018:
	.incbin "build/de/graphics/intro_scene/objects/object_18.0x70"
	.global gUnk_IntroSceneUnpackSource_019
gUnk_IntroSceneUnpackSource_019:
	.incbin "build/de/graphics/intro_scene/objects/object_19.0x70"
	.global gUnk_08743058
gUnk_08743058:
	.incbin "build/de/graphics/intro_scene/background_tiles.0x70"
	.global gUnk_08747A14
gUnk_08747A14:
	.incbin "build/de/graphics/intro_scene/background_palettes.gbapal"
	.global gUnk_08747A74
gUnk_08747A74:
	.incbin "baserom_de.gba", 0x4CEEE8, 0x275C
	.global gUnk_IntroSceneStartupUnpackSource_000
gUnk_IntroSceneStartupUnpackSource_000:
	.incbin "build/de/graphics/intro_scene/startup_tilemaps/startup_00.0x70"
	.global gUnk_IntroSceneStartupUnpackSource_001
gUnk_IntroSceneStartupUnpackSource_001:
	.incbin "build/de/graphics/intro_scene/startup_tilemaps/startup_01.0x70"
	.global gUnk_IntroSceneStartupUnpackSource_002
gUnk_IntroSceneStartupUnpackSource_002:
	.incbin "build/de/graphics/intro_scene/startup_tilemaps/startup_02.0x70"
	.global gUnk_IntroSceneStartupUnpackSource_003
gUnk_IntroSceneStartupUnpackSource_003:
	.incbin "build/de/graphics/intro_scene/startup_tilemaps/startup_03.0x70"
	.global gUnk_0874A9C0
gUnk_0874A9C0:
	.incbin "baserom_de.gba", 0x4D1E2C, 0x3970
	.global gUnk_0874E330
gUnk_0874E330:
	.incbin "baserom_de.gba", 0x4D579C, 0x200
	.global gUnk_0874E530
gUnk_0874E530:
	.incbin "baserom_de.gba", 0x4D599C, 0x118
	.global gUnk_0874E648
gUnk_0874E648:
	.incbin "baserom_de.gba", 0x4D5AB4, 0x4F8
	.global gUnk_0874EB40
gUnk_0874EB40:
	.incbin "baserom_de.gba", 0x4D5FAC, 0x20
	.global gUnk_0874EB60
gUnk_0874EB60:
	.incbin "baserom_de.gba", 0x4D5FCC, 0x16C
	.global gUnk_0874ECCC
gUnk_0874ECCC:
	.incbin "baserom_de.gba", 0x4D6138, 0x16C
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_0874EE38
gUnk_0874EE38:
	.incbin "baserom_de.gba", 0x4D62A4, 0xDC
	.global gUnk_0874EF14
gUnk_0874EF14:
	.incbin "baserom_de.gba", 0x4D6380, 0x28
	.global gUnk_0874EF3C
gUnk_0874EF3C:
	.incbin "baserom_de.gba", 0x4D63A8, 0xB0
	.global gUnk_0874EFEC
gUnk_0874EFEC:
	.incbin "baserom_de.gba", 0x4D6458, 0x64
	.global gUnk_0874F050
gUnk_0874F050:
	.incbin "baserom_de.gba", 0x4D64BC, 0x29C
	.global gUnk_0874F2EC
gUnk_0874F2EC:
	.incbin "baserom_de.gba", 0x4D6758, 0x60
	.global gUnk_0874F34C
gUnk_0874F34C:
	.incbin "baserom_de.gba", 0x4D67B8, 0x1444
	.global gUnk_087506E0
gUnk_087506E0:
	.incbin "baserom_de.gba", 0x4D7BFC, 0x56C
	.global gUnk_08750C4C
gUnk_08750C4C:
	.incbin "baserom_de.gba", 0x4D8168, 0x20
	.global gUnk_08750C6C
gUnk_08750C6C:
	.incbin "baserom_de.gba", 0x4D8188, 0x20
	.global gUnk_08750C8C
gUnk_08750C8C:
	.incbin "baserom_de.gba", 0x4D81A8, 0x1C0
	.global gUnk_08750E4C
gUnk_08750E4C:
	.incbin "baserom_de.gba", 0x4D8368, 0x120
	.global gUnk_08750F6C
gUnk_08750F6C:
	.incbin "baserom_de.gba", 0x4D8488, 0x20
	.global gUnk_08750F8C
gUnk_08750F8C:
	.incbin "baserom_de.gba", 0x4D84A8, 0x120
	.global gUnk_087510AC
gUnk_087510AC:
	.incbin "baserom_de.gba", 0x4D85C8, 0x120
	.global gUnk_087511CC
gUnk_087511CC:
	.incbin "baserom_de.gba", 0x4D86E8, 0x120
	.global gUnk_087512EC
gUnk_087512EC:
	.incbin "baserom_de.gba", 0x4D8808, 0x20
	.global gUnk_0875130C
gUnk_0875130C:
	.incbin "baserom_de.gba", 0x4D8828, 0x120
	.global gUnk_0875142C
gUnk_0875142C:
	.incbin "baserom_de.gba", 0x4D8948, 0x120
	.global gUnk_0875154C
gUnk_0875154C:
	.incbin "baserom_de.gba", 0x4D8A68, 0x120
	.global gUnk_0875166C
gUnk_0875166C:
	.incbin "baserom_de.gba", 0x4D8B88, 0x120
	.global gUnk_0875178C
gUnk_0875178C:
	.incbin "baserom_de.gba", 0x4D8CA8, 0x20
	.global gUnk_087517AC
gUnk_087517AC:
	.incbin "baserom_de.gba", 0x4D8CC8, 0x120
	.global gUnk_087518CC
gUnk_087518CC:
	.incbin "baserom_de.gba", 0x4D8DE8, 0x80
	.global gUnk_0875194C
gUnk_0875194C:
	.incbin "baserom_de.gba", 0x4D8E68, 0x20
	.global gUnk_0875196C
gUnk_0875196C:
	.incbin "baserom_de.gba", 0x4D8E88, 0x80
	.global gUnk_087519EC
gUnk_087519EC:
	.incbin "baserom_de.gba", 0x4D8F08, 0x20
	.global gUnk_08751A0C
gUnk_08751A0C:
	.incbin "baserom_de.gba", 0x4D8F28, 0x80
	.global gUnk_08751A8C
gUnk_08751A8C:
	.incbin "baserom_de.gba", 0x4D8FA8, 0x20
	.global gUnk_08751AAC
gUnk_08751AAC:
	.incbin "baserom_de.gba", 0x4D8FC8, 0x80
	.global gUnk_08751B2C
gUnk_08751B2C:
	.incbin "baserom_de.gba", 0x4D9048, 0x20
	.global gUnk_08751B4C
gUnk_08751B4C:
	.incbin "baserom_de.gba", 0x4D9068, 0x80
	.global gUnk_08751BCC
gUnk_08751BCC:
	.incbin "baserom_de.gba", 0x4D90E8, 0x20
	.global gUnk_08751BEC
gUnk_08751BEC:
	.incbin "baserom_de.gba", 0x4D9108, 0x80
	.global gUnk_08751C6C
gUnk_08751C6C:
	.incbin "baserom_de.gba", 0x4D9188, 0x20
	.global gUnk_08751C8C
gUnk_08751C8C:
	.incbin "baserom_de.gba", 0x4D91A8, 0x80
	.global gUnk_08751D0C
gUnk_08751D0C:
	.incbin "baserom_de.gba", 0x4D9228, 0x20
	.global gUnk_08751D2C
gUnk_08751D2C:
	.incbin "baserom_de.gba", 0x4D9248, 0x80
	.global gUnk_08751DAC
gUnk_08751DAC:
	.incbin "baserom_de.gba", 0x4D92C8, 0x20
	.global gUnk_08751DCC
gUnk_08751DCC:
	.incbin "baserom_de.gba", 0x4D92E8, 0x80
	.global gUnk_08751E4C
gUnk_08751E4C:
	.incbin "baserom_de.gba", 0x4D9368, 0x20
	.global gUnk_08751E6C
gUnk_08751E6C:
	.incbin "baserom_de.gba", 0x4D9388, 0x80
	.global gUnk_08751EEC
gUnk_08751EEC:
	.incbin "baserom_de.gba", 0x4D9408, 0x20
	.global gUnk_08751F0C
gUnk_08751F0C:
	FOMT_RECORDS_TASK_TILES 00
	.global gUnk_08751F8C
gUnk_08751F8C:
	FOMT_RECORDS_TASK_PALETTE 00
	.global gUnk_08751FAC
gUnk_08751FAC:
	FOMT_RECORDS_TASK_TILES 01
	.global gUnk_0875202C
gUnk_0875202C:
	FOMT_RECORDS_TASK_PALETTE 01
	.global gUnk_0875204C
gUnk_0875204C:
	FOMT_RECORDS_TASK_TILES 02
	.global gUnk_087520CC
gUnk_087520CC:
	FOMT_RECORDS_TASK_PALETTE 02
	.global gUnk_087520EC
gUnk_087520EC:
	FOMT_RECORDS_TASK_TILES 03
	.global gUnk_0875216C
gUnk_0875216C:
	FOMT_RECORDS_TASK_PALETTE 03
	.global gUnk_0875218C
gUnk_0875218C:
	FOMT_RECORDS_TASK_TILES 04
	.global gUnk_0875220C
gUnk_0875220C:
	FOMT_RECORDS_TASK_PALETTE 04
	.global gUnk_0875222C
gUnk_0875222C:
	FOMT_RECORDS_TASK_TILES 05
	.global gUnk_087522AC
gUnk_087522AC:
	FOMT_RECORDS_TASK_PALETTE 05
	.global gUnk_087522CC
gUnk_087522CC:
	FOMT_RECORDS_TASK_TILES 06
	.global gUnk_0875234C
gUnk_0875234C:
	FOMT_RECORDS_TASK_PALETTE 06
	.global gUnk_0875236C
gUnk_0875236C:
	.incbin "baserom_de.gba", 0x4D9888, 0x80
	.global gUnk_087523EC
gUnk_087523EC:
	.incbin "baserom_de.gba", 0x4D9908, 0x20
	.global gUnk_0875240C
gUnk_0875240C:
	.incbin "baserom_de.gba", 0x4D9928, 0x80
	.global gUnk_0875248C
gUnk_0875248C:
	.incbin "baserom_de.gba", 0x4D99A8, 0x20
	.global gUnk_087524AC
gUnk_087524AC:
	.incbin "baserom_de.gba", 0x4D99C8, 0x80
	.global gUnk_0875252C
gUnk_0875252C:
	.incbin "baserom_de.gba", 0x4D9A48, 0x20
	.global gUnk_0875254C
gUnk_0875254C:
	.incbin "baserom_de.gba", 0x4D9A68, 0x80
	.global gUnk_087525CC
gUnk_087525CC:
	.incbin "baserom_de.gba", 0x4D9AE8, 0x20
	.global gUnk_087525EC
gUnk_087525EC:
	.incbin "baserom_de.gba", 0x4D9B08, 0x80
	.global gUnk_0875266C
gUnk_0875266C:
	.incbin "baserom_de.gba", 0x4D9B88, 0x20
	.global gUnk_0875268C
gUnk_0875268C:
	.incbin "baserom_de.gba", 0x4D9BA8, 0x80
	.global gUnk_0875270C
gUnk_0875270C:
	.incbin "baserom_de.gba", 0x4D9C28, 0x20
	.global gUnk_0875272C
gUnk_0875272C:
	.incbin "baserom_de.gba", 0x4D9C48, 0x80
	.global gUnk_087527AC
gUnk_087527AC:
	.incbin "baserom_de.gba", 0x4D9CC8, 0x20
	.global gUnk_087527CC
gUnk_087527CC:
	.incbin "baserom_de.gba", 0x4D9CE8, 0x80
	.global gUnk_0875284C
gUnk_0875284C:
	.incbin "baserom_de.gba", 0x4D9D68, 0x20
	.global gUnk_0875286C
gUnk_0875286C:
	.incbin "baserom_de.gba", 0x4D9D88, 0x80
	.global gUnk_087528EC
gUnk_087528EC:
	.incbin "baserom_de.gba", 0x4D9E08, 0x20
	.global gUnk_0875290C
gUnk_0875290C:
	.incbin "baserom_de.gba", 0x4D9E28, 0x80
	.global gUnk_0875298C
gUnk_0875298C:
	.incbin "baserom_de.gba", 0x4D9EA8, 0x20
	.global gUnk_087529AC
gUnk_087529AC:
	.incbin "baserom_de.gba", 0x4D9EC8, 0x80
	.global gUnk_08752A2C
gUnk_08752A2C:
	.incbin "baserom_de.gba", 0x4D9F48, 0x80
	.global gUnk_08752AAC
gUnk_08752AAC:
	.incbin "baserom_de.gba", 0x4D9FC8, 0x20
	.global gUnk_08752ACC
gUnk_08752ACC:
	.incbin "baserom_de.gba", 0x4D9FE8, 0x80
	.global gUnk_08752B4C
gUnk_08752B4C:
	.incbin "baserom_de.gba", 0x4DA068, 0x80
	.global gUnk_08752BCC
gUnk_08752BCC:
	.incbin "baserom_de.gba", 0x4DA0E8, 0x80
	.global gUnk_08752C4C
gUnk_08752C4C:
	.incbin "baserom_de.gba", 0x4DA168, 0x80
	.global gUnk_08752CCC
gUnk_08752CCC:
	.incbin "baserom_de.gba", 0x4DA1E8, 0x80
	.global gUnk_08752D4C
gUnk_08752D4C:
	.incbin "baserom_de.gba", 0x4DA268, 0x80
	.global gUnk_08752DCC
gUnk_08752DCC:
	.incbin "baserom_de.gba", 0x4DA2E8, 0x80
	.global gUnk_08752E4C
gUnk_08752E4C:
	FOMT_FARM_STATUS_SELECTOR_CASE_09 4bpp
	.global gUnk_08752ECC
gUnk_08752ECC:
	FOMT_FARM_STATUS_SELECTOR_CASE_09 gbapal
	.global gUnk_08752EEC
gUnk_08752EEC:
	.incbin "baserom_de.gba", 0x4DA408, 0x80
	.global gUnk_08752F6C
gUnk_08752F6C:
	.incbin "baserom_de.gba", 0x4DA488, 0x20
	.global gUnk_08752F8C
gUnk_08752F8C:
	.incbin "baserom_de.gba", 0x4DA4A8, 0x80
	.global gUnk_0875300C
gUnk_0875300C:
	.incbin "baserom_de.gba", 0x4DA528, 0x20
	.global gUnk_0875302C
gUnk_0875302C:
	.incbin "baserom_de.gba", 0x4DA548, 0x80
	.global gUnk_087530AC
gUnk_087530AC:
	.incbin "baserom_de.gba", 0x4DA5C8, 0x20
	.global gUnk_087530CC
gUnk_087530CC:
	.incbin "baserom_de.gba", 0x4DA5E8, 0x80
	.global gUnk_0875314C
gUnk_0875314C:
	.incbin "baserom_de.gba", 0x4DA668, 0x20
	.global gUnk_0875316C
gUnk_0875316C:
	.incbin "baserom_de.gba", 0x4DA688, 0x80
	.global gUnk_087531EC
gUnk_087531EC:
	.incbin "baserom_de.gba", 0x4DA708, 0x20
	.global gUnk_0875320C
gUnk_0875320C:
	.incbin "baserom_de.gba", 0x4DA728, 0x80
	.global gUnk_0875328C
gUnk_0875328C:
	.incbin "baserom_de.gba", 0x4DA7A8, 0x20
	.global gUnk_087532AC
gUnk_087532AC:
	.incbin "baserom_de.gba", 0x4DA7C8, 0x80
	.global gUnk_0875332C
gUnk_0875332C:
	.incbin "baserom_de.gba", 0x4DA848, 0x20
	.global gUnk_0875334C
gUnk_0875334C:
	.incbin "baserom_de.gba", 0x4DA868, 0x80
	.global gUnk_087533CC
gUnk_087533CC:
	.incbin "baserom_de.gba", 0x4DA8E8, 0x20
	.global gUnk_087533EC
gUnk_087533EC:
	.incbin "baserom_de.gba", 0x4DA908, 0x80
	.global gUnk_0875346C
gUnk_0875346C:
	.incbin "baserom_de.gba", 0x4DA988, 0x20
	.global gUnk_0875348C
gUnk_0875348C:
	.incbin "baserom_de.gba", 0x4DA9A8, 0x80
	.global gUnk_0875350C
gUnk_0875350C:
	.incbin "baserom_de.gba", 0x4DAA28, 0x20
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_0875352C
gUnk_0875352C:
	.incbin "baserom_de.gba", 0x4DAA48, 0xDC
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08753608
gUnk_08753608:
	.incbin "baserom_de.gba", 0x4DAB24, 0xDC
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_087536E4
gUnk_087536E4:
	.incbin "baserom_de.gba", 0x4DAC00, 0xEC
	.global gUnk_087537D0
gUnk_087537D0:
	.incbin "baserom_de.gba", 0x4DACEC, 0xEA4
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08754674
gUnk_08754674:
	.incbin "baserom_de.gba", 0x4DBB90, 0x598
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08754C0C
gUnk_08754C0C:
	.incbin "baserom_de.gba", 0x4DC128, 0x548
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08755154
gUnk_08755154:
	.incbin "baserom_de.gba", 0x4DC670, 0xDC
	.global gUnk_08755230
gUnk_08755230:
	FOMT_SEASONAL_NONWINTER_ASSET "bg_30.tilemap"
	.global gUnk_0875553C
gUnk_0875553C:
	FOMT_SEASONAL_NONWINTER_ASSET "bg_29.tilemap"
	.global gUnk_08755848
gUnk_08755848:
	FOMT_SEASONAL_NONWINTER_ASSET "nonwinter_tiles.0x70"
	.global gUnk_08757AE0
gUnk_08757AE0:
	FOMT_SEASONAL_NONWINTER_ASSET "nonwinter_palette_banks.gbapal"
	.global gUnk_08757BA0
gUnk_08757BA0:
	.incbin "baserom_de.gba", 0x4DF0BC, 0xC
	.global gUnk_08757BAC
gUnk_08757BAC:
	.incbin "baserom_de.gba", 0x4DF0C8, 0x20
	.global gUnk_08757BCC
gUnk_08757BCC:
	.incbin "baserom_de.gba", 0x4DF0E8, 0xC
	.global gUnk_08757BD8
gUnk_08757BD8:
	.incbin "baserom_de.gba", 0x4DF0F4, 0x20
	.global gUnk_08757BF8
gUnk_08757BF8:
	.incbin "baserom_de.gba", 0x4DF114, 0x14
	.global gUnk_08757C0C
gUnk_08757C0C:
	.incbin "baserom_de.gba", 0x4DF128, 0x8
	.global gUnk_08757C14
gUnk_08757C14:
	FOMT_SEASONAL_NONWINTER_ASSET "bg_30.tilemap"
	.global gUnk_08757F20
gUnk_08757F20:
	FOMT_SEASONAL_WINTER_ASSET "winter_bg_29.tilemap"
	.global gUnk_0875822C
gUnk_0875822C:
	FOMT_SEASONAL_WINTER_ASSET "winter_tiles.0x70"
	.global gUnk_0875A358
gUnk_0875A358:
	FOMT_SEASONAL_WINTER_ASSET "winter_palette_banks.gbapal"
	.global gUnk_0875A418
gUnk_0875A418:
	.incbin "baserom_de.gba", 0x4E1934, 0xC
	.global gUnk_0875A424
gUnk_0875A424:
	.incbin "baserom_de.gba", 0x4E1940, 0x14
	.global gUnk_0875A438
gUnk_0875A438:
	.incbin "baserom_de.gba", 0x4E1954, 0x8
	.global gUnk_0875A440
gUnk_0875A440:
	FOMT_CLOCK_FONT
	.global gUnk_0875B444
gUnk_0875B444:
	.incbin "baserom_de.gba", 0x4E2960, 0x3D4
	.global gUnk_UiSharedResourceData_000
gUnk_UiSharedResourceData_000:
	.incbin "build/de/graphics/ui/shared_resource/shared_resource.4bpp"
	.global gUnk_UiSharedResourceData_001
gUnk_UiSharedResourceData_001:
	.incbin "build/de/graphics/ui/shared_resource/shared_resource.gbapal"
