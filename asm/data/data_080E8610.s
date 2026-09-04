    .ifdef REGION_JP
    @ JP revision 0 counterpart of data_080E8610.s.
    @
    @ The source module is already data-only incbin content.  This static JP
    @ range retains its exported data names and covers the verified JP span.

	.section .rodata

	.global init_array
init_array:
	.incbin "baserom_jp.gba", 0xE7A40, 0x1C

	.global gUnk_080E862C
gUnk_080E862C:
	.incbin "baserom_jp.gba", 0xE7A5C, 0x58

	.global gUnk_080E8684
gUnk_080E8684:
	.incbin "baserom_jp.gba", 0xE7AB4, (0xE7AC8 - 0xE7AB4)

	.section .rodata.new_game_save_trailer

	.global gUnk_080E8934
gUnk_080E8934:
	.incbin "baserom_jp.gba", 0xE7D64, (0xE7D94 - 0xE7D64)

	.section .rodata.new_game_identity_prefix_trailer
	.incbin "baserom_jp.gba", 0xE7DAC, (0xE7DB8 - 0xE7DAC)

	.section .rodata.new_game_identity_labels_trailer
	.incbin "baserom_jp.gba", 0xE7E24, (0xE8014 - 0xE7E24)

	.global gUnk_080E8BE4
gUnk_080E8BE4:
	.incbin "baserom_jp.gba", 0xE8014, 0x10

	.global gUnk_080E8BF4
gUnk_080E8BF4:
	.incbin "baserom_jp.gba", 0xE8024, 0x8

	.global gUnk_080E8BFC
gUnk_080E8BFC:
	.incbin "baserom_jp.gba", 0xE802C, 0x18

	.global gUnk_080E8C14
gUnk_080E8C14:
	.incbin "baserom_jp.gba", 0xE8044, 0x18

	.global gUnk_080E8C2C
gUnk_080E8C2C:
	.incbin "baserom_jp.gba", 0xE805C, 0x18

	.global gUnk_080E8C44
gUnk_080E8C44:
	.incbin "baserom_jp.gba", 0xE8074, 0x4

	.global gUnk_080E8C48
gUnk_080E8C48:
	.incbin "baserom_jp.gba", 0xE8078, 0x7C

	.global gUnk_080E8CC4
gUnk_080E8CC4:
	.incbin "baserom_jp.gba", 0xE80F4, 0x40

	.global gUnk_080E8D04
gUnk_080E8D04:
	.incbin "baserom_jp.gba", 0xE8134, 0x8

	.global gUnk_080E8D0C
gUnk_080E8D0C:
	.incbin "baserom_jp.gba", 0xE813C, 0x8

	.global gUnk_080E8D14
gUnk_080E8D14:
	.incbin "baserom_jp.gba", 0xE8144, 0x6E4

	.incbin "baserom_jp.gba", 0xE8828, 0x70

	.global gUnk_080E93F8
gUnk_080E93F8:
	.incbin "baserom_jp.gba", 0xE8898, 0x1D4
    .else

    .section .rodata

	.global init_array
init_array:
	.word 0, 0, 0, 0

	@ "bad_alloc"
	.incbin "baserom_us.gba", 0xE8620, 0x0C

	.global gUnk_080E862C
gUnk_080E862C:
	.incbin "baserom_us.gba", 0xE862C, 0x58

	.global gUnk_080E8684
gUnk_080E8684:
	.incbin "baserom_us.gba", 0xE8684, (0xE86A8 - 0xE8684)

	.section .rodata.new_game_save_trailer
	.incbin "baserom_us.gba", 0xE8920, (0xE8934 - 0xE8920)

	.section .rodata.new_game_identity_prefix_trailer
	.incbin "baserom_us.gba", 0xE894C, (0xE8958 - 0xE894C)

	.section .rodata.new_game_identity_labels_trailer
	.incbin "baserom_us.gba", 0xE89AC, (0xE89B6 - 0xE89AC)

	.global gUnk_080E89B6
gUnk_080E89B6:
	.incbin "baserom_us.gba", 0xE89B6, 0x22E

	.global gUnk_080E8BE4
gUnk_080E8BE4:
	.incbin "baserom_us.gba", 0xE8BE4, 0x10

	.global gUnk_080E8BF4
gUnk_080E8BF4:
	.incbin "baserom_us.gba", 0xE8BF4, 0x8

	.global gUnk_080E8BFC
gUnk_080E8BFC:
	.incbin "baserom_us.gba", 0xE8BFC, 0x18

	.global gUnk_080E8C14
gUnk_080E8C14:
	.incbin "baserom_us.gba", 0xE8C14, 0x18

	.global gUnk_080E8C2C
gUnk_080E8C2C:
	.incbin "baserom_us.gba", 0xE8C2C, 0x18

	.global gUnk_080E8C44
gUnk_080E8C44:
	.incbin "baserom_us.gba", 0xE8C44, 0x4

	.global gUnk_080E8C48
gUnk_080E8C48:
	.incbin "baserom_us.gba", 0xE8C48, 0x7C

	.global gUnk_080E8CC4
gUnk_080E8CC4:
	.incbin "baserom_us.gba", 0xE8CC4, 0x40

	.global gUnk_080E8D04
gUnk_080E8D04:
	.incbin "baserom_us.gba", 0xE8D04, 0x8

	.global gUnk_080E8D0C
gUnk_080E8D0C:
	.incbin "baserom_us.gba", 0xE8D0C, 0x8

	.global gUnk_080E8D14
gUnk_080E8D14:
	.incbin "baserom_us.gba", 0xE8D14, 0x6E4

	.global gUnk_080E93F8
gUnk_080E93F8:
	.incbin "baserom_us.gba", 0xE93F8, 0x1D4

    .endif
