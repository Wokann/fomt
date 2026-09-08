    .ifdef REGION_JP
    @ JP revision 0 counterpart of data_080E8610.s.
    @
    @ The source module is already data-only incbin content.  This static JP
    @ range retains its exported data names and covers the verified JP span.

	.section .rodata.sram_signature_trailer
	.incbin "baserom_jp.gba", 0xE7A7C, (0xE7AA4 - 0xE7A7C)

    .else

	.section .rodata.sram_signature_trailer
	.incbin "baserom_us.gba", 0xE864C, (0xE8684 - 0xE864C)

    .endif
