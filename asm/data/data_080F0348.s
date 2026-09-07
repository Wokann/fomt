    .ifdef REGION_JP
    @ JP revision 0 counterpart of the localized data after gProductInfo.
    .section .rodata
    .incbin "baserom_jp.gba", 0xEFD48, (0xEFD52 - 0xEFD48)

    .section .rodata.calendar_trailer
    .incbin "baserom_jp.gba", 0xEFD78, (0xEFDD0 - 0xEFD78)


    .else
    .section .rodata

	.global gUnk_080F04E4
gUnk_080F04E4:
	.incbin "baserom_us.gba", 0xF04E4, 0xA

	.section .rodata.calendar_trailer
	.incbin "baserom_us.gba", 0xF0534, 0x32

	.section .rodata.load_error_prefix
	.global gUnk_080F0566
gUnk_080F0566:
	.incbin "baserom_us.gba", 0xF0566, 0x26

    .endif
