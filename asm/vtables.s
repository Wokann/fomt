    .ifdef REGION_JP
    @ JP revision 0 virtual-table region.
    @
    @ AScene and AUnk_0800080C are emitted from their ordinary C++ class
    @ declarations. The remaining tables stay in this static ROM range.

    .section .rodata.080E68B8
    .set jp_vtables_start, jp_vtables_raw_after_vtable_7444 - 0x1AAC
    .global vtable_unk_080E7478
    .set vtable_unk_080E7478, jp_vtables_start + 0x1AAC
    .global vtable_unk_080E748C
    .set vtable_unk_080E748C, jp_vtables_start + 0x1AC0
    .global vtable_unk_080E749C
    .set vtable_unk_080E749C, jp_vtables_start + 0x1AD0
    .global vtable_unk_080E74AC
    .set vtable_unk_080E74AC, jp_vtables_start + 0x1AE0
    .global vtable_unk_080E74BC
    .set vtable_unk_080E74BC, jp_vtables_start + 0x1AF0
    .global vtable_unk_080E74CC
    .set vtable_unk_080E74CC, jp_vtables_start + 0x1B00
    .global vtable_unk_080E74DC
    .set vtable_unk_080E74DC, jp_vtables_start + 0x1B10
    .global vtable_unk_080E7568
    .set vtable_unk_080E7568, jp_vtables_start + 0x1B9C
    .global vtable_unk_080E759C
    .set vtable_unk_080E759C, jp_vtables_start + 0x1BD0
    .global vtable_unk_080E75B4
    .set vtable_unk_080E75B4, jp_vtables_start + 0x1BE8
    .global vtable_unk_080E75CC
    .set vtable_unk_080E75CC, jp_vtables_start + 0x1C00
    .global vtable_unk_080E75E4
    .set vtable_unk_080E75E4, jp_vtables_start + 0x1C18
    .global vtable_unk_080E75FC
    .set vtable_unk_080E75FC, jp_vtables_start + 0x1C30
    .global vtable_unk_080E7614
    .set vtable_unk_080E7614, jp_vtables_start + 0x1C48
    .global vtable_unk_080E762C
    .set vtable_unk_080E762C, jp_vtables_start + 0x1C60
    .global vtable_unk_080E7644
    .set vtable_unk_080E7644, jp_vtables_start + 0x1C78
    .global vtable_unk_080E765C
    .set vtable_unk_080E765C, jp_vtables_start + 0x1C90
    .global vtable_unk_080E7674
    .set vtable_unk_080E7674, jp_vtables_start + 0x1CA8
    .global vtable_unk_080E768C
    .set vtable_unk_080E768C, jp_vtables_start + 0x1CC0
    .global vtable_unk_080E76A4
    .set vtable_unk_080E76A4, jp_vtables_start + 0x1CD8
    .global vtable_unk_080E76BC
    .set vtable_unk_080E76BC, jp_vtables_start + 0x1CF0
    .global vtable_unk_080E76D4
    .set vtable_unk_080E76D4, jp_vtables_start + 0x1D08
    .global vtable_unk_080E76E8
    .set vtable_unk_080E76E8, jp_vtables_start + 0x1D1C
    .global vtable_unk_080E76F8
    .set vtable_unk_080E76F8, jp_vtables_start + 0x1D2C
    .global vtable_unk_080E7708
    .set vtable_unk_080E7708, jp_vtables_start + 0x1D3C
    .global vtable_unk_080E7714
    .set vtable_unk_080E7714, jp_vtables_start + 0x1D48
    .global vtable_unk_080E7728
    .set vtable_unk_080E7728, jp_vtables_start + 0x1D5C
    .global vtable_unk_080E7738
    .set vtable_unk_080E7738, jp_vtables_start + 0x1D6C
    .global vtable_unk_080E7748
    .set vtable_unk_080E7748, jp_vtables_start + 0x1D7C
    .global vtable_unk_080E7758
    .set vtable_unk_080E7758, jp_vtables_start + 0x1D8C
    .global vtable_unk_080E7768
    .set vtable_unk_080E7768, jp_vtables_start + 0x1D9C
    .global vtable_unk_080E7778
    .set vtable_unk_080E7778, jp_vtables_start + 0x1DAC
    .global vtable_unk_080E77A4
    .set vtable_unk_080E77A4, jp_vtables_start + 0x1DD8
    .global vtable_unk_080E77D0
    .set vtable_unk_080E77D0, jp_vtables_start + 0x1E04
    .global vtable_unk_080E77E0
    .set vtable_unk_080E77E0, jp_vtables_start + 0x1E14
jp_vtables_raw_after_vtable_7444:
    .incbin "baserom_jp.gba", 0xE68B8, (0xE6C50 - 0xE68B8)

    .else

    .section .rodata

	.section .rodata.080E7478

	.global vtable_unk_080E7478
vtable_unk_080E7478:
	.incbin "baserom_us.gba", 0xE7478, 0x14

	.global vtable_unk_080E748C
vtable_unk_080E748C:
	.incbin "baserom_us.gba", 0xE748C, 0x10

	.global vtable_unk_080E749C
vtable_unk_080E749C:
	.incbin "baserom_us.gba", 0xE749C, 0x10

	.global vtable_unk_080E74AC
vtable_unk_080E74AC:
	.incbin "baserom_us.gba", 0xE74AC, 0x10

	.global vtable_unk_080E74BC
vtable_unk_080E74BC:
	.incbin "baserom_us.gba", 0xE74BC, 0x10

	.global vtable_unk_080E74CC
vtable_unk_080E74CC:
	.incbin "baserom_us.gba", 0xE74CC, 0x10

	.global vtable_unk_080E74DC
vtable_unk_080E74DC:
	.incbin "baserom_us.gba", 0xE74DC, 0x8C

	.global vtable_unk_080E7568
vtable_unk_080E7568:
	.incbin "baserom_us.gba", 0xE7568, 0x34

	.global vtable_unk_080E759C
vtable_unk_080E759C:
	.incbin "baserom_us.gba", 0xE759C, 0x18

	.global vtable_unk_080E75B4
vtable_unk_080E75B4:
	.incbin "baserom_us.gba", 0xE75B4, 0x18

	.global vtable_unk_080E75CC
vtable_unk_080E75CC:
	.incbin "baserom_us.gba", 0xE75CC, 0x18

	.global vtable_unk_080E75E4
vtable_unk_080E75E4:
	.incbin "baserom_us.gba", 0xE75E4, 0x18

	.global vtable_unk_080E75FC
vtable_unk_080E75FC:
	.incbin "baserom_us.gba", 0xE75FC, 0x18

	.global vtable_unk_080E7614
vtable_unk_080E7614:
	.incbin "baserom_us.gba", 0xE7614, 0x18

	.global vtable_unk_080E762C
vtable_unk_080E762C:
	.incbin "baserom_us.gba", 0xE762C, 0x18

	.global vtable_unk_080E7644
vtable_unk_080E7644:
	.incbin "baserom_us.gba", 0xE7644, 0x18

	.global vtable_unk_080E765C
vtable_unk_080E765C:
	.incbin "baserom_us.gba", 0xE765C, 0x18

	.global vtable_unk_080E7674
vtable_unk_080E7674:
	.incbin "baserom_us.gba", 0xE7674, 0x18

	.global vtable_unk_080E768C
vtable_unk_080E768C:
	.incbin "baserom_us.gba", 0xE768C, 0x18

	.global vtable_unk_080E76A4
vtable_unk_080E76A4:
	.incbin "baserom_us.gba", 0xE76A4, 0x18

	.global vtable_unk_080E76BC
vtable_unk_080E76BC:
	.incbin "baserom_us.gba", 0xE76BC, 0x18

	.global vtable_unk_080E76D4
vtable_unk_080E76D4:
	.incbin "baserom_us.gba", 0xE76D4, 0x14

	.global vtable_unk_080E76E8
vtable_unk_080E76E8:
	.incbin "baserom_us.gba", 0xE76E8, 0x10

	.global vtable_unk_080E76F8
vtable_unk_080E76F8:
	.incbin "baserom_us.gba", 0xE76F8, 0x10

	.global vtable_unk_080E7708
vtable_unk_080E7708:
	.incbin "baserom_us.gba", 0xE7708, 0xC

	.global vtable_unk_080E7714
vtable_unk_080E7714:
	.incbin "baserom_us.gba", 0xE7714, 0x14

	.global vtable_unk_080E7728
vtable_unk_080E7728:
	.incbin "baserom_us.gba", 0xE7728, 0x10

	.global vtable_unk_080E7738
vtable_unk_080E7738:
	.incbin "baserom_us.gba", 0xE7738, 0x10

	.global vtable_unk_080E7748
vtable_unk_080E7748:
	.incbin "baserom_us.gba", 0xE7748, 0x10

	.global vtable_unk_080E7758
vtable_unk_080E7758:
	.incbin "baserom_us.gba", 0xE7758, 0x10

	.global vtable_unk_080E7768
vtable_unk_080E7768:
	.incbin "baserom_us.gba", 0xE7768, 0x10

	.global vtable_unk_080E7778
vtable_unk_080E7778:
	.incbin "baserom_us.gba", 0xE7778, 0x2C

	.global vtable_unk_080E77A4
vtable_unk_080E77A4:
	.incbin "baserom_us.gba", 0xE77A4, 0x2C

	.global vtable_unk_080E77D0
vtable_unk_080E77D0:
	.incbin "baserom_us.gba", 0xE77D0, 0x10

	.global vtable_unk_080E77E0
vtable_unk_080E77E0:
	.incbin "baserom_us.gba", 0xE77E0, 0x30

    .endif
