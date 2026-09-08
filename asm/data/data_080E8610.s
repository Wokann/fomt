    .ifdef REGION_JP
    @ JP revision 0 counterpart of data_080E8610.s.
    @
    @ The source module is already data-only incbin content.  This static JP
    @ range retains its exported data names and covers the verified JP span.

	.section .rodata.sram_signature_trailer
	.incbin "baserom_jp.gba", 0xE7A7C, (0xE7AA4 - 0xE7A7C)

	.section .rodata.intro_scene_startup_resources_trailer
	.incbin "baserom_jp.gba", 0xE7AB4, (0xE7AC8 - 0xE7AB4)

    .else

	.section .rodata.sram_signature_trailer
	.incbin "baserom_us.gba", 0xE864C, (0xE8684 - 0xE864C)

	.section .rodata.intro_scene_startup_resources_trailer
	.incbin "baserom_us.gba", 0xE8694, (0xE86A8 - 0xE8694)

    .endif
