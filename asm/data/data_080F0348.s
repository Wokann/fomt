    .ifdef REGION_JP
    @ JP revision 0 counterpart of the localized data after gProductInfo.
    .section .rodata
    .incbin "baserom_jp.gba", 0xEFD48, (0xEFD52 - 0xEFD48)

    .section .rodata.calendar_trailer
    .incbin "baserom_jp.gba", 0xEFD78, (0xEFDD0 - 0xEFD78)

    .section .rodata.fixed_labels_trailer
    .incbin "baserom_jp.gba", 0xF11F0, (0xF11FC - 0xF11F0)

    .section .rodata.ui_error_trailer
    .incbin "baserom_jp.gba", 0xF1202, (0xF1228 - 0xF1202)

    .section .rodata.menu_data_trailer
    .incbin "baserom_jp.gba", 0xF12AC, (0xF12DC - 0xF12AC)
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

	.section .rodata.fixed_labels_trailer
	.incbin "baserom_us.gba", 0xF1994, (0xF19A0 - 0xF1994)

	.section .rodata.ui_error_trailer
	.incbin "baserom_us.gba", 0xF19A6, (0xF19AE - 0xF19A6)

	.global gUnk_080F19AE
gUnk_080F19AE:
	.incbin "baserom_us.gba", 0xF19AE, (0xF19CC - 0xF19AE)

	.section .rodata.menu_data_trailer
	.incbin "baserom_us.gba", 0xF1A50, (0xF1A66 - 0xF1A50)

	.global gUnk_080F1A66
gUnk_080F1A66:
	.incbin "baserom_us.gba", 0xF1A66, (0xF1A80 - 0xF1A66)
    .endif
