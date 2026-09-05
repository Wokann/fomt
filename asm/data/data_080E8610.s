    .ifdef REGION_JP
    @ JP revision 0 counterpart of data_080E8610.s.
    @
    @ The source module is already data-only incbin content.  This static JP
    @ range retains its exported data names and covers the verified JP span.

	.section .rodata

	.global init_array
init_array:
	.incbin "baserom_jp.gba", 0xE7A40, 0x1C

	.section .rodata.sram_signature_trailer
	.incbin "baserom_jp.gba", 0xE7A7C, (0xE7AB4 - 0xE7A7C)

	.global gUnk_080E8684
gUnk_080E8684:
	.incbin "baserom_jp.gba", 0xE7AB4, (0xE7AC8 - 0xE7AB4)

	.section .rodata.new_game_save_trailer
	.incbin "baserom_jp.gba", 0xE7D80, (0xE7D94 - 0xE7D80)

	.section .rodata.new_game_identity_prefix_trailer
	.incbin "baserom_jp.gba", 0xE7DAC, (0xE7DB8 - 0xE7DAC)

	.section .rodata.new_game_identity_labels_trailer
	.incbin "baserom_jp.gba", 0xE7E24, (0xE7E2E - 0xE7E24)

	.section .rodata.new_game_name_entry_trailer
	.incbin "baserom_jp.gba", 0xE80EC, (0xE80F4 - 0xE80EC)

	.section .rodata.field_plot_prefix
	.incbin "baserom_jp.gba", 0xE80F4, (0xE8164 - 0xE80F4)
    .else

    .section .rodata

	.global init_array
init_array:
	.word 0, 0, 0, 0

	@ "bad_alloc"
	.incbin "baserom_us.gba", 0xE8620, 0x0C

	.section .rodata.sram_signature_trailer
	.incbin "baserom_us.gba", 0xE864C, (0xE8684 - 0xE864C)

	.global gUnk_080E8684
gUnk_080E8684:
	.incbin "baserom_us.gba", 0xE8684, (0xE86A8 - 0xE8684)

	.section .rodata.new_game_save_trailer
	.incbin "baserom_us.gba", 0xE8920, (0xE8934 - 0xE8920)

	.section .rodata.new_game_identity_prefix_trailer
	.incbin "baserom_us.gba", 0xE894C, (0xE8958 - 0xE894C)

	.section .rodata.new_game_identity_labels_trailer
	.incbin "baserom_us.gba", 0xE89AC, (0xE89B6 - 0xE89AC)

	.section .rodata.new_game_name_entry_trailer
	.incbin "baserom_us.gba", 0xE8C4C, (0xE8CC4 - 0xE8C4C)

    .endif
