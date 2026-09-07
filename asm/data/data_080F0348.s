    .ifdef REGION_JP
    @ JP revision 0 counterpart of the localized data after gProductInfo.
    .section .rodata.load_error_prefix
    .incbin "baserom_jp.gba", 0xEFDAA, (0xEFDD0 - 0xEFDAA)

    .else
	.section .rodata.load_error_prefix
	.global gUnk_080F0566
gUnk_080F0566:
	.incbin "baserom_us.gba", 0xF0566, 0x26

    .endif
