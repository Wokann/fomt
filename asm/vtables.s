    .ifdef REGION_JP
    @ JP revision 0 virtual-table region.
    @
    @ AScene and AUnk_0800080C are emitted from their ordinary C++ class
    @ declarations. The remaining tables stay in this static ROM range.

    .section .rodata.080E6C20
    .set jp_vtables_start, jp_vtables_raw_after_vtable_77d0 - 0x1E14
    .global vtable_unk_080E77E0
    .set vtable_unk_080E77E0, jp_vtables_start + 0x1E14
jp_vtables_raw_after_vtable_77d0:
    .incbin "baserom_jp.gba", 0xE6C20, (0xE6C50 - 0xE6C20)

    .else

    .section .rodata

	.section .rodata.080E77E0

	.global vtable_unk_080E77E0
vtable_unk_080E77E0:
	.incbin "baserom_us.gba", 0xE77E0, 0x30

    .endif
