    .ifdef REGION_JP
    @ JP revision 0 script-adjacent data.
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
    @ The western revisions preserve this raw object's internal layout, but
    @ relocate every ROM pointer stored in it. Keep the labels and emitted
    @ lengths shared while selecting the independently matched source range.
    .macro FOMT_REGION_INCBIN offset, length
    .ifdef REGION_EU
        .incbin "baserom_eu.gba", \offset + 0x4C, \length
    .else
    .ifdef REGION_DE
        .incbin "baserom_de.gba", \offset + 0x4E8, \length
    .else
        .incbin "baserom_us.gba", \offset, \length
    .endif
    .endif
    .endm

    .section .rodata.data_080f1a80_suffix
	.global gUnk_080F42F0
gUnk_080F42F0:
	FOMT_REGION_INCBIN 0xF42F0, 0xEC

	.global gUnk_080F43DC
gUnk_080F43DC:
	FOMT_REGION_INCBIN 0xF43DC, 0x598

	.global gUnk_080F4974
gUnk_080F4974:
	FOMT_REGION_INCBIN 0xF4974, 0x4C

	.global gUnk_080F49C0
gUnk_080F49C0:
	FOMT_REGION_INCBIN 0xF49C0, 0x3B4

	.global gUnk_080F4D74
gUnk_080F4D74:
	FOMT_REGION_INCBIN 0xF4D74, 0x7CC

	.global gUnk_080F5540
gUnk_080F5540:
	FOMT_REGION_INCBIN 0xF5540, 0x43C

	.global gUnk_080F597C
gUnk_080F597C:
	FOMT_REGION_INCBIN 0xF597C, 0x50

	.global gUnk_080F59CC
gUnk_080F59CC:
	FOMT_REGION_INCBIN 0xF59CC, 0x3C8

	.global gUnk_080F5D94
gUnk_080F5D94:
	FOMT_REGION_INCBIN 0xF5D94, 0x468

	.global gUnk_080F61FC
gUnk_080F61FC:
	FOMT_REGION_INCBIN 0xF61FC, 0x174

	.global gUnk_080F6370
gUnk_080F6370:
	FOMT_REGION_INCBIN 0xF6370, 0x354

	.global gUnk_080F66C4
gUnk_080F66C4:
	FOMT_REGION_INCBIN 0xF66C4, 0x44C

	.global gUnk_080F6B10
gUnk_080F6B10:
	FOMT_REGION_INCBIN 0xF6B10, 0x3C

	.global gUnk_080F6B4C
gUnk_080F6B4C:
	FOMT_REGION_INCBIN 0xF6B4C, 0x29C

	.global gUnk_080F6DE8
gUnk_080F6DE8:
	FOMT_REGION_INCBIN 0xF6DE8, 0x210

	.global gUnk_080F6FF8
gUnk_080F6FF8:
	FOMT_REGION_INCBIN 0xF6FF8, 0x29C

	.global gUnk_080F7294
gUnk_080F7294:
	FOMT_REGION_INCBIN 0xF7294, 0x568

	.global gUnk_080F77FC
gUnk_080F77FC:
	FOMT_REGION_INCBIN 0xF77FC, 0x344

	.global gUnk_080F7B40
gUnk_080F7B40:
	FOMT_REGION_INCBIN 0xF7B40, 0x67C

	.global gUnk_080F81BC
gUnk_080F81BC:
	FOMT_REGION_INCBIN 0xF81BC, 0x4BC

	.global gUnk_080F8678
gUnk_080F8678:
	FOMT_REGION_INCBIN 0xF8678, 0x35C

	.global gUnk_080F89D4 @ script table
gUnk_080F89D4:
	FOMT_REGION_INCBIN 0xF89D4, 0x14C4
    .endif
