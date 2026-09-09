    .ifdef REGION_JP
    @ JP revision 0 virtual-table region.
    @
    @ AScene and AUnk_0800080C are emitted from their ordinary C++ class
    @ declarations. The remaining tables stay in this static ROM range.

    .section .rodata.080E5A34
    .set jp_vtables_start, jp_vtables_raw_after_vtable_65e0 - 0xC28
    .global vtable_unk_080E65F4
    .set vtable_unk_080E65F4, jp_vtables_start + 0xC28
    .global vtable_unk_080E6644
    .set vtable_unk_080E6644, jp_vtables_start + 0xC78
    .global vtable_unk_080E6658
    .set vtable_unk_080E6658, jp_vtables_start + 0xC8C
    .global vtable_unk_080E6708
    .set vtable_unk_080E6708, jp_vtables_start + 0xD3C
    .global vtable_unk_080E671C
    .set vtable_unk_080E671C, jp_vtables_start + 0xD50
    .global vtable_unk_080E676C
    .set vtable_unk_080E676C, jp_vtables_start + 0xDA0
    .global vtable_unk_080E681C
    .set vtable_unk_080E681C, jp_vtables_start + 0xE50
    .global vtable_unk_080E6828
    .set vtable_unk_080E6828, jp_vtables_start + 0xE5C
    .global vtable_unk_080E6864
    .set vtable_unk_080E6864, jp_vtables_start + 0xE98
    .global __vt_12AActorEntity
    .set __vt_12AActorEntity, jp_vtables_start + 0xEAC
    .global vtable_unk_080E68B4
    .set vtable_unk_080E68B4, jp_vtables_start + 0xEE8
    .global vtable_unk_080E68C8
    .set vtable_unk_080E68C8, jp_vtables_start + 0xEFC
    .global vtable_unk_080E6904
    .set vtable_unk_080E6904, jp_vtables_start + 0xF38
    .global vtable_unk_080E6918
    .set vtable_unk_080E6918, jp_vtables_start + 0xF4C
    .global vtable_unk_080E6958
    .set vtable_unk_080E6958, jp_vtables_start + 0xF8C
    .global vtable_unk_080E6998
    .set vtable_unk_080E6998, jp_vtables_start + 0xFCC
    .global vtable_unk_080E69D8
    .set vtable_unk_080E69D8, jp_vtables_start + 0x100C
    .global vtable_unk_080E6A18
    .set vtable_unk_080E6A18, jp_vtables_start + 0x104C
    .global vtable_unk_080E6A58
    .set vtable_unk_080E6A58, jp_vtables_start + 0x108C
    .global vtable_unk_080E6A98
    .set vtable_unk_080E6A98, jp_vtables_start + 0x10CC
    .global vtable_unk_080E6AD8
    .set vtable_unk_080E6AD8, jp_vtables_start + 0x110C
    .global vtable_unk_080E6B18
    .set vtable_unk_080E6B18, jp_vtables_start + 0x114C
    .global vtable_unk_080E6B58
    .set vtable_unk_080E6B58, jp_vtables_start + 0x118C
    .global vtable_unk_080E6B98
    .set vtable_unk_080E6B98, jp_vtables_start + 0x11CC
    .global vtable_unk_080E6BD8
    .set vtable_unk_080E6BD8, jp_vtables_start + 0x120C
    .global vtable_unk_080E6C18
    .set vtable_unk_080E6C18, jp_vtables_start + 0x124C
    .global vtable_unk_080E6C58
    .set vtable_unk_080E6C58, jp_vtables_start + 0x128C
    .global vtable_unk_080E6C98
    .set vtable_unk_080E6C98, jp_vtables_start + 0x12CC
    .global vtable_unk_080E6CD8
    .set vtable_unk_080E6CD8, jp_vtables_start + 0x130C
    .global vtable_unk_080E6D18
    .set vtable_unk_080E6D18, jp_vtables_start + 0x134C
    .global vtable_unk_080E6D58
    .set vtable_unk_080E6D58, jp_vtables_start + 0x138C
    .global vtable_unk_080E6D98
    .set vtable_unk_080E6D98, jp_vtables_start + 0x13CC
    .global vtable_unk_080E6DD8
    .set vtable_unk_080E6DD8, jp_vtables_start + 0x140C
    .global vtable_unk_080E6E18
    .set vtable_unk_080E6E18, jp_vtables_start + 0x144C
    .global vtable_unk_080E6E58
    .set vtable_unk_080E6E58, jp_vtables_start + 0x148C
    .global vtable_unk_080E6E98
    .set vtable_unk_080E6E98, jp_vtables_start + 0x14CC
    .global vtable_unk_080E6ED8
    .set vtable_unk_080E6ED8, jp_vtables_start + 0x150C
    .global vtable_unk_080E6F18
    .set vtable_unk_080E6F18, jp_vtables_start + 0x154C
    .global vtable_unk_080E6F58
    .set vtable_unk_080E6F58, jp_vtables_start + 0x158C
    .global vtable_unk_080E6F98
    .set vtable_unk_080E6F98, jp_vtables_start + 0x15CC
    .global vtable_unk_080E6FD8
    .set vtable_unk_080E6FD8, jp_vtables_start + 0x160C
    .global vtable_unk_080E7018
    .set vtable_unk_080E7018, jp_vtables_start + 0x164C
    .global vtable_unk_080E7058
    .set vtable_unk_080E7058, jp_vtables_start + 0x168C
    .global vtable_unk_080E7098
    .set vtable_unk_080E7098, jp_vtables_start + 0x16CC
    .global vtable_unk_080E70D8
    .set vtable_unk_080E70D8, jp_vtables_start + 0x170C
    .global vtable_unk_080E7118
    .set vtable_unk_080E7118, jp_vtables_start + 0x174C
    .global vtable_unk_080E7158
    .set vtable_unk_080E7158, jp_vtables_start + 0x178C
    .global vtable_unk_080E7198
    .set vtable_unk_080E7198, jp_vtables_start + 0x17CC
    .global __vt_10ANpcEntity
    .set __vt_10ANpcEntity, jp_vtables_start + 0x180C
    .global vtable_unk_080E7218
    .set vtable_unk_080E7218, jp_vtables_start + 0x184C
    .global vtable_unk_080E725C
    .set vtable_unk_080E725C, jp_vtables_start + 0x1890
    .global vtable_unk_080E72A0
    .set vtable_unk_080E72A0, jp_vtables_start + 0x18D4
    .global vtable_unk_080E72E4
    .set vtable_unk_080E72E4, jp_vtables_start + 0x1918
    .global vtable_unk_080E7328
    .set vtable_unk_080E7328, jp_vtables_start + 0x195C
    .global vtable_unk_080E736C
    .set vtable_unk_080E736C, jp_vtables_start + 0x19A0
    .global vtable_unk_080E7380
    .set vtable_unk_080E7380, jp_vtables_start + 0x19B4
    .global vtable_unk_080E73B4
    .set vtable_unk_080E73B4, jp_vtables_start + 0x19E8
    .global vtable_unk_080E73E8
    .set vtable_unk_080E73E8, jp_vtables_start + 0x1A1C
    .global vtable_unk_080E73FC
    .set vtable_unk_080E73FC, jp_vtables_start + 0x1A30
    .global vtable_unk_080E7430
    .set vtable_unk_080E7430, jp_vtables_start + 0x1A64
    .global vtable_unk_080E7444
    .set vtable_unk_080E7444, jp_vtables_start + 0x1A78
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
jp_vtables_raw_after_vtable_65e0:
    .incbin "baserom_jp.gba", 0xE5A34, (0xE6C50 - 0xE5A34)

    .else

    .section .rodata

	.section .rodata.080E65F4

	.global vtable_unk_080E65F4
vtable_unk_080E65F4:
	.incbin "baserom_us.gba", 0xE65F4, 0x50

	.global vtable_unk_080E6644
vtable_unk_080E6644:
	.incbin "baserom_us.gba", 0xE6644, 0x14

	.global vtable_unk_080E6658
vtable_unk_080E6658:
	.incbin "baserom_us.gba", 0xE6658, 0xB0

	.global vtable_unk_080E6708
vtable_unk_080E6708:
	.incbin "baserom_us.gba", 0xE6708, 0x14

	.global vtable_unk_080E671C
vtable_unk_080E671C:
	.incbin "baserom_us.gba", 0xE671C, 0x50

	.global vtable_unk_080E676C
vtable_unk_080E676C:
	.incbin "baserom_us.gba", 0xE676C, 0xB0

	.global vtable_unk_080E681C
vtable_unk_080E681C:
	.incbin "baserom_us.gba", 0xE681C, 0xC

	.global vtable_unk_080E6828
vtable_unk_080E6828:
	.incbin "baserom_us.gba", 0xE6828, 0x3C

	.global vtable_unk_080E6864
vtable_unk_080E6864:
	.incbin "baserom_us.gba", 0xE6864, 0x14

	.global __vt_12AActorEntity
__vt_12AActorEntity:
	.incbin "baserom_us.gba", 0xE6878, 0x3C

	.global vtable_unk_080E68B4
vtable_unk_080E68B4:
	.incbin "baserom_us.gba", 0xE68B4, 0x14

	.global vtable_unk_080E68C8
vtable_unk_080E68C8:
	.incbin "baserom_us.gba", 0xE68C8, 0x3C

	.global vtable_unk_080E6904
vtable_unk_080E6904:
	.incbin "baserom_us.gba", 0xE6904, 0x14

	.global vtable_unk_080E6918
vtable_unk_080E6918:
	.incbin "baserom_us.gba", 0xE6918, 0x40

	.global vtable_unk_080E6958
vtable_unk_080E6958:
	.incbin "baserom_us.gba", 0xE6958, 0x40

	.global vtable_unk_080E6998
vtable_unk_080E6998:
	.incbin "baserom_us.gba", 0xE6998, 0x40

	.global vtable_unk_080E69D8
vtable_unk_080E69D8:
	.incbin "baserom_us.gba", 0xE69D8, 0x40

	.global vtable_unk_080E6A18
vtable_unk_080E6A18:
	.incbin "baserom_us.gba", 0xE6A18, 0x40

	.global vtable_unk_080E6A58
vtable_unk_080E6A58:
	.incbin "baserom_us.gba", 0xE6A58, 0x40

	.global vtable_unk_080E6A98
vtable_unk_080E6A98:
	.incbin "baserom_us.gba", 0xE6A98, 0x40

	.global vtable_unk_080E6AD8
vtable_unk_080E6AD8:
	.incbin "baserom_us.gba", 0xE6AD8, 0x40

	.global vtable_unk_080E6B18
vtable_unk_080E6B18:
	.incbin "baserom_us.gba", 0xE6B18, 0x40

	.global vtable_unk_080E6B58
vtable_unk_080E6B58:
	.incbin "baserom_us.gba", 0xE6B58, 0x40

	.global vtable_unk_080E6B98
vtable_unk_080E6B98:
	.incbin "baserom_us.gba", 0xE6B98, 0x40

	.global vtable_unk_080E6BD8
vtable_unk_080E6BD8:
	.incbin "baserom_us.gba", 0xE6BD8, 0x40

	.global vtable_unk_080E6C18
vtable_unk_080E6C18:
	.incbin "baserom_us.gba", 0xE6C18, 0x40

	.global vtable_unk_080E6C58
vtable_unk_080E6C58:
	.incbin "baserom_us.gba", 0xE6C58, 0x40

	.global vtable_unk_080E6C98
vtable_unk_080E6C98:
	.incbin "baserom_us.gba", 0xE6C98, 0x40

	.global vtable_unk_080E6CD8
vtable_unk_080E6CD8:
	.incbin "baserom_us.gba", 0xE6CD8, 0x40

	.global vtable_unk_080E6D18
vtable_unk_080E6D18:
	.incbin "baserom_us.gba", 0xE6D18, 0x40

	.global vtable_unk_080E6D58
vtable_unk_080E6D58:
	.incbin "baserom_us.gba", 0xE6D58, 0x40

	.global vtable_unk_080E6D98
vtable_unk_080E6D98:
	.incbin "baserom_us.gba", 0xE6D98, 0x40

	.global vtable_unk_080E6DD8
vtable_unk_080E6DD8:
	.incbin "baserom_us.gba", 0xE6DD8, 0x40

	.global vtable_unk_080E6E18
vtable_unk_080E6E18:
	.incbin "baserom_us.gba", 0xE6E18, 0x40

	.global vtable_unk_080E6E58
vtable_unk_080E6E58:
	.incbin "baserom_us.gba", 0xE6E58, 0x40

	.global vtable_unk_080E6E98
vtable_unk_080E6E98:
	.incbin "baserom_us.gba", 0xE6E98, 0x40

	.global vtable_unk_080E6ED8
vtable_unk_080E6ED8:
	.incbin "baserom_us.gba", 0xE6ED8, 0x40

	.global vtable_unk_080E6F18
vtable_unk_080E6F18:
	.incbin "baserom_us.gba", 0xE6F18, 0x40

	.global vtable_unk_080E6F58
vtable_unk_080E6F58:
	.incbin "baserom_us.gba", 0xE6F58, 0x40

	.global vtable_unk_080E6F98
vtable_unk_080E6F98:
	.incbin "baserom_us.gba", 0xE6F98, 0x40

	.global vtable_unk_080E6FD8
vtable_unk_080E6FD8:
	.incbin "baserom_us.gba", 0xE6FD8, 0x40

	.global vtable_unk_080E7018
vtable_unk_080E7018:
	.incbin "baserom_us.gba", 0xE7018, 0x40

	.global vtable_unk_080E7058
vtable_unk_080E7058:
	.incbin "baserom_us.gba", 0xE7058, 0x40

	.global vtable_unk_080E7098
vtable_unk_080E7098:
	.incbin "baserom_us.gba", 0xE7098, 0x40

	.global vtable_unk_080E70D8
vtable_unk_080E70D8:
	.incbin "baserom_us.gba", 0xE70D8, 0x40

	.global vtable_unk_080E7118
vtable_unk_080E7118:
	.incbin "baserom_us.gba", 0xE7118, 0x40

	.global vtable_unk_080E7158
vtable_unk_080E7158:
	.incbin "baserom_us.gba", 0xE7158, 0x40

	.global vtable_unk_080E7198
vtable_unk_080E7198:
	.incbin "baserom_us.gba", 0xE7198, 0x40

	.global __vt_10ANpcEntity
__vt_10ANpcEntity:
	.incbin "baserom_us.gba", 0xE71D8, 0x40

	.global vtable_unk_080E7218
vtable_unk_080E7218:
	.incbin "baserom_us.gba", 0xE7218, 0x44

	.global vtable_unk_080E725C
vtable_unk_080E725C:
	.incbin "baserom_us.gba", 0xE725C, 0x44

	.global vtable_unk_080E72A0
vtable_unk_080E72A0:
	.incbin "baserom_us.gba", 0xE72A0, 0x44

	.global vtable_unk_080E72E4
vtable_unk_080E72E4:
	.incbin "baserom_us.gba", 0xE72E4, 0x44

	.global vtable_unk_080E7328
vtable_unk_080E7328:
	.incbin "baserom_us.gba", 0xE7328, 0x44

	.global vtable_unk_080E736C
vtable_unk_080E736C:
	.incbin "baserom_us.gba", 0xE736C, 0x14

	.global vtable_unk_080E7380
vtable_unk_080E7380:
	.incbin "baserom_us.gba", 0xE7380, 0x34

	.global vtable_unk_080E73B4
vtable_unk_080E73B4:
	.incbin "baserom_us.gba", 0xE73B4, 0x34

	.global vtable_unk_080E73E8
vtable_unk_080E73E8:
	.incbin "baserom_us.gba", 0xE73E8, 0x14

	.global vtable_unk_080E73FC
vtable_unk_080E73FC:
	.incbin "baserom_us.gba", 0xE73FC, 0x34

	.global vtable_unk_080E7430
vtable_unk_080E7430:
	.incbin "baserom_us.gba", 0xE7430, 0x14

	.global vtable_unk_080E7444
vtable_unk_080E7444:
	.incbin "baserom_us.gba", 0xE7444, 0x34

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
