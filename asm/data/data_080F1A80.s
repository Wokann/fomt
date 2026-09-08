    .ifdef REGION_JP
    @ JP revision 0 counterpart of the script and schedule-adjacent data.
    .section .rodata.data_080f1a80_prefix
jp_data_080f1a80_prefix_start:
    .incbin "baserom_jp.gba", 0xF2068, 0xBAC

    .global gUnk_080F29C0
gUnk_080F29C0 = jp_data_080f1a80_prefix_start + 0x1A8
    .global gUnk_080F2AF8
gUnk_080F2AF8 = jp_data_080f1a80_prefix_start + 0x2E0
    .global gUnk_080F2DC0
gUnk_080F2DC0 = jp_data_080f1a80_prefix_start + 0x5B0
    .global gUnk_080F3010
gUnk_080F3010 = jp_data_080f1a80_prefix_start + 0x604

    .section .rodata.data_080f1a80_suffix
jp_data_080f1a80_suffix_start:
    .incbin "baserom_jp.gba", 0xF3B4C, (0xF96F4 - 0xF3B4C)

    .global gUnk_080F42F0
gUnk_080F42F0 = jp_data_080f1a80_suffix_start + 0x000
    .global gUnk_080F43DC
gUnk_080F43DC = jp_data_080f1a80_suffix_start + 0xEC
    .global gUnk_080F4974
gUnk_080F4974 = jp_data_080f1a80_suffix_start + 0x678
    .global gUnk_080F49C0
gUnk_080F49C0 = jp_data_080f1a80_suffix_start + 0x6C4
    .global gUnk_080F4D74
gUnk_080F4D74 = jp_data_080f1a80_suffix_start + 0xA78
    .global gUnk_080F5540
gUnk_080F5540 = jp_data_080f1a80_suffix_start + 0x1244
    .global gUnk_080F597C
gUnk_080F597C = jp_data_080f1a80_suffix_start + 0x1680
    .global gUnk_080F59CC
gUnk_080F59CC = jp_data_080f1a80_suffix_start + 0x16D0
    .global gUnk_080F5D94
gUnk_080F5D94 = jp_data_080f1a80_suffix_start + 0x1A98
    .global gUnk_080F61FC
gUnk_080F61FC = jp_data_080f1a80_suffix_start + 0x1F20
    .global gUnk_080F6370
gUnk_080F6370 = jp_data_080f1a80_suffix_start + 0x2094
    .global gUnk_080F66C4
gUnk_080F66C4 = jp_data_080f1a80_suffix_start + 0x23E8
    .global gUnk_080F6B10
gUnk_080F6B10 = jp_data_080f1a80_suffix_start + 0x2814
    .global gUnk_080F6B4C
gUnk_080F6B4C = jp_data_080f1a80_suffix_start + 0x2850
    .global gUnk_080F6DE8
gUnk_080F6DE8 = jp_data_080f1a80_suffix_start + 0x2AEC
    .global gUnk_080F6FF8
gUnk_080F6FF8 = jp_data_080f1a80_suffix_start + 0x2CFC
    .global gUnk_080F7294
gUnk_080F7294 = jp_data_080f1a80_suffix_start + 0x2F98
    .global gUnk_080F77FC
gUnk_080F77FC = jp_data_080f1a80_suffix_start + 0x3500
    .global gUnk_080F7B40
gUnk_080F7B40 = jp_data_080f1a80_suffix_start + 0x3844
    .global gUnk_080F81BC
gUnk_080F81BC = jp_data_080f1a80_suffix_start + 0x3ECC
    .global gUnk_080F8678
gUnk_080F8678 = jp_data_080f1a80_suffix_start + 0x4588
    .global gUnk_080F89D4
gUnk_080F89D4 = jp_data_080f1a80_suffix_start + 0x48E4
    .else
    .section .rodata.data_080f1a80_prefix

	@ schedules

	@ .incbin "baserom_us.gba", 0xF1AC0, 0x500

	.global gUnk_080F280C
gUnk_080F280C:
	.incbin "baserom_us.gba", 0xF280C, 0x1B4

	.global gUnk_080F29C0
gUnk_080F29C0:
	.incbin "baserom_us.gba", 0xF29C0, 0x138

	.global gUnk_080F2AF8
gUnk_080F2AF8:
	.incbin "baserom_us.gba", 0xF2AF8, 0x2C8

	.global gUnk_080F2DC0
gUnk_080F2DC0:
	.incbin "baserom_us.gba", 0xF2DC0, 0x250

	.global gUnk_080F3010
gUnk_080F3010:
	.incbin "baserom_us.gba", 0xF3010, 0x3A8

	.section .rodata.data_080f1a80_suffix
	.global gUnk_080F42F0
gUnk_080F42F0:
	.incbin "baserom_us.gba", 0xF42F0, 0xEC

	.global gUnk_080F43DC
gUnk_080F43DC:
	.incbin "baserom_us.gba", 0xF43DC, 0x598

	.global gUnk_080F4974
gUnk_080F4974:
	.incbin "baserom_us.gba", 0xF4974, 0x4C

	.global gUnk_080F49C0
gUnk_080F49C0:
	.incbin "baserom_us.gba", 0xF49C0, 0x3B4

	.global gUnk_080F4D74
gUnk_080F4D74:
	.incbin "baserom_us.gba", 0xF4D74, 0x7CC

	.global gUnk_080F5540
gUnk_080F5540:
	.incbin "baserom_us.gba", 0xF5540, 0x43C

	.global gUnk_080F597C
gUnk_080F597C:
	.incbin "baserom_us.gba", 0xF597C, 0x50

	.global gUnk_080F59CC
gUnk_080F59CC:
	.incbin "baserom_us.gba", 0xF59CC, 0x3C8

	.global gUnk_080F5D94
gUnk_080F5D94:
	.incbin "baserom_us.gba", 0xF5D94, 0x468

	.global gUnk_080F61FC
gUnk_080F61FC:
	.incbin "baserom_us.gba", 0xF61FC, 0x174

	.global gUnk_080F6370
gUnk_080F6370:
	.incbin "baserom_us.gba", 0xF6370, 0x354

	.global gUnk_080F66C4
gUnk_080F66C4:
	.incbin "baserom_us.gba", 0xF66C4, 0x44C

	.global gUnk_080F6B10
gUnk_080F6B10:
	.incbin "baserom_us.gba", 0xF6B10, 0x3C

	.global gUnk_080F6B4C
gUnk_080F6B4C:
	.incbin "baserom_us.gba", 0xF6B4C, 0x29C

	.global gUnk_080F6DE8
gUnk_080F6DE8:
	.incbin "baserom_us.gba", 0xF6DE8, 0x210

	.global gUnk_080F6FF8
gUnk_080F6FF8:
	.incbin "baserom_us.gba", 0xF6FF8, 0x29C

	.global gUnk_080F7294
gUnk_080F7294:
	.incbin "baserom_us.gba", 0xF7294, 0x568

	.global gUnk_080F77FC
gUnk_080F77FC:
	.incbin "baserom_us.gba", 0xF77FC, 0x344

	.global gUnk_080F7B40
gUnk_080F7B40:
	.incbin "baserom_us.gba", 0xF7B40, 0x67C

	.global gUnk_080F81BC
gUnk_080F81BC:
	.incbin "baserom_us.gba", 0xF81BC, 0x4BC

	.global gUnk_080F8678
gUnk_080F8678:
	.incbin "baserom_us.gba", 0xF8678, 0x35C

	.global gUnk_080F89D4 @ script table
gUnk_080F89D4:
	.incbin "baserom_us.gba", 0xF89D4, 0x14C4
    .endif
