@ Direct labels inside DE's original pre-IWRAM resource stream.
@ Each address is recovered from a matched DE ROM pointer literal; the
@ seven entries marked below are bounded by their verified contiguous
@ neighbours.  Keeping labels physical avoids synthetic .set aliases.
	.incbin "baserom_de.gba", 0x13D308, 0x391BE0
	.global gUnk_08747A74
gUnk_08747A74:
	.incbin "baserom_de.gba", 0x4CEEE8, 0x2F44
	.global gUnk_0874A9C0
gUnk_0874A9C0:
	.incbin "baserom_de.gba", 0x4D1E2C, 0x3970
	.global gUnk_0874E330
gUnk_0874E330:
	.incbin "baserom_de.gba", 0x4D579C, 0x200
	.global gUnk_0874E530
gUnk_0874E530:
	.incbin "baserom_de.gba", 0x4D599C, 0x118
	.global gUnk_0874E648
gUnk_0874E648:
	.incbin "baserom_de.gba", 0x4D5AB4, 0x4F8
	.global gUnk_0874EB40
gUnk_0874EB40:
	.incbin "baserom_de.gba", 0x4D5FAC, 0x20
	.global gUnk_0874EB60
gUnk_0874EB60:
	.incbin "baserom_de.gba", 0x4D5FCC, 0x16C
	.global gUnk_0874ECCC
gUnk_0874ECCC:
	.incbin "baserom_de.gba", 0x4D6138, 0x16C
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_0874EE38
gUnk_0874EE38:
	.incbin "baserom_de.gba", 0x4D62A4, 0xDC
	.global gUnk_0874EF14
gUnk_0874EF14:
	.incbin "baserom_de.gba", 0x4D6380, 0x28
	.global gUnk_0874EF3C
gUnk_0874EF3C:
	.incbin "baserom_de.gba", 0x4D63A8, 0xB0
	.global gUnk_0874EFEC
gUnk_0874EFEC:
	.incbin "baserom_de.gba", 0x4D6458, 0x64
	.global gUnk_0874F050
gUnk_0874F050:
	.incbin "baserom_de.gba", 0x4D64BC, 0x29C
	.global gUnk_0874F2EC
gUnk_0874F2EC:
	.incbin "baserom_de.gba", 0x4D6758, 0x60
	.global gUnk_0874F34C
gUnk_0874F34C:
	.incbin "baserom_de.gba", 0x4D67B8, 0x1444
	.global gUnk_087506E0
gUnk_087506E0:
	.incbin "baserom_de.gba", 0x4D7BFC, 0x56C
	.global gUnk_08750C4C
gUnk_08750C4C:
	.incbin "baserom_de.gba", 0x4D8168, 0x20
	.global gUnk_08750C6C
gUnk_08750C6C:
	.incbin "baserom_de.gba", 0x4D8188, 0x20
	.global gUnk_08750C8C
gUnk_08750C8C:
	.incbin "baserom_de.gba", 0x4D81A8, 0x1C0
	.global gUnk_08750E4C
gUnk_08750E4C:
	.incbin "baserom_de.gba", 0x4D8368, 0x120
	.global gUnk_08750F6C
gUnk_08750F6C:
	.incbin "baserom_de.gba", 0x4D8488, 0x20
	.global gUnk_08750F8C
gUnk_08750F8C:
	.incbin "baserom_de.gba", 0x4D84A8, 0x120
	.global gUnk_087510AC
gUnk_087510AC:
	.incbin "baserom_de.gba", 0x4D85C8, 0x120
	.global gUnk_087511CC
gUnk_087511CC:
	.incbin "baserom_de.gba", 0x4D86E8, 0x120
	.global gUnk_087512EC
gUnk_087512EC:
	.incbin "baserom_de.gba", 0x4D8808, 0x20
	.global gUnk_0875130C
gUnk_0875130C:
	.incbin "baserom_de.gba", 0x4D8828, 0x120
	.global gUnk_0875142C
gUnk_0875142C:
	.incbin "baserom_de.gba", 0x4D8948, 0x120
	.global gUnk_0875154C
gUnk_0875154C:
	.incbin "baserom_de.gba", 0x4D8A68, 0x120
	.global gUnk_0875166C
gUnk_0875166C:
	.incbin "baserom_de.gba", 0x4D8B88, 0x120
	.global gUnk_0875178C
gUnk_0875178C:
	.incbin "baserom_de.gba", 0x4D8CA8, 0x20
	.global gUnk_087517AC
gUnk_087517AC:
	.incbin "baserom_de.gba", 0x4D8CC8, 0x120
	.global gUnk_087518CC
gUnk_087518CC:
	.incbin "baserom_de.gba", 0x4D8DE8, 0x80
	.global gUnk_0875194C
gUnk_0875194C:
	.incbin "baserom_de.gba", 0x4D8E68, 0x20
	.global gUnk_0875196C
gUnk_0875196C:
	.incbin "baserom_de.gba", 0x4D8E88, 0x80
	.global gUnk_087519EC
gUnk_087519EC:
	.incbin "baserom_de.gba", 0x4D8F08, 0x20
	.global gUnk_08751A0C
gUnk_08751A0C:
	.incbin "baserom_de.gba", 0x4D8F28, 0x80
	.global gUnk_08751A8C
gUnk_08751A8C:
	.incbin "baserom_de.gba", 0x4D8FA8, 0x20
	.global gUnk_08751AAC
gUnk_08751AAC:
	.incbin "baserom_de.gba", 0x4D8FC8, 0x80
	.global gUnk_08751B2C
gUnk_08751B2C:
	.incbin "baserom_de.gba", 0x4D9048, 0x20
	.global gUnk_08751B4C
gUnk_08751B4C:
	.incbin "baserom_de.gba", 0x4D9068, 0x80
	.global gUnk_08751BCC
gUnk_08751BCC:
	.incbin "baserom_de.gba", 0x4D90E8, 0x20
	.global gUnk_08751BEC
gUnk_08751BEC:
	.incbin "baserom_de.gba", 0x4D9108, 0x80
	.global gUnk_08751C6C
gUnk_08751C6C:
	.incbin "baserom_de.gba", 0x4D9188, 0x20
	.global gUnk_08751C8C
gUnk_08751C8C:
	.incbin "baserom_de.gba", 0x4D91A8, 0x80
	.global gUnk_08751D0C
gUnk_08751D0C:
	.incbin "baserom_de.gba", 0x4D9228, 0x20
	.global gUnk_08751D2C
gUnk_08751D2C:
	.incbin "baserom_de.gba", 0x4D9248, 0x80
	.global gUnk_08751DAC
gUnk_08751DAC:
	.incbin "baserom_de.gba", 0x4D92C8, 0x20
	.global gUnk_08751DCC
gUnk_08751DCC:
	.incbin "baserom_de.gba", 0x4D92E8, 0x80
	.global gUnk_08751E4C
gUnk_08751E4C:
	.incbin "baserom_de.gba", 0x4D9368, 0x20
	.global gUnk_08751E6C
gUnk_08751E6C:
	.incbin "baserom_de.gba", 0x4D9388, 0x80
	.global gUnk_08751EEC
gUnk_08751EEC:
	.incbin "baserom_de.gba", 0x4D9408, 0x20
	.global gUnk_08751F0C
gUnk_08751F0C:
	.incbin "baserom_de.gba", 0x4D9428, 0x80
	.global gUnk_08751F8C
gUnk_08751F8C:
	.incbin "baserom_de.gba", 0x4D94A8, 0x20
	.global gUnk_08751FAC
gUnk_08751FAC:
	.incbin "baserom_de.gba", 0x4D94C8, 0x80
	.global gUnk_0875202C
gUnk_0875202C:
	.incbin "baserom_de.gba", 0x4D9548, 0x20
	.global gUnk_0875204C
gUnk_0875204C:
	.incbin "baserom_de.gba", 0x4D9568, 0x80
	.global gUnk_087520CC
gUnk_087520CC:
	.incbin "baserom_de.gba", 0x4D95E8, 0x20
	.global gUnk_087520EC
gUnk_087520EC:
	.incbin "baserom_de.gba", 0x4D9608, 0x80
	.global gUnk_0875216C
gUnk_0875216C:
	.incbin "baserom_de.gba", 0x4D9688, 0x20
	.global gUnk_0875218C
gUnk_0875218C:
	.incbin "baserom_de.gba", 0x4D96A8, 0x80
	.global gUnk_0875220C
gUnk_0875220C:
	.incbin "baserom_de.gba", 0x4D9728, 0x20
	.global gUnk_0875222C
gUnk_0875222C:
	.incbin "baserom_de.gba", 0x4D9748, 0x80
	.global gUnk_087522AC
gUnk_087522AC:
	.incbin "baserom_de.gba", 0x4D97C8, 0x20
	.global gUnk_087522CC
gUnk_087522CC:
	.incbin "baserom_de.gba", 0x4D97E8, 0x80
	.global gUnk_0875234C
gUnk_0875234C:
	.incbin "baserom_de.gba", 0x4D9868, 0x20
	.global gUnk_0875236C
gUnk_0875236C:
	.incbin "baserom_de.gba", 0x4D9888, 0x80
	.global gUnk_087523EC
gUnk_087523EC:
	.incbin "baserom_de.gba", 0x4D9908, 0x20
	.global gUnk_0875240C
gUnk_0875240C:
	.incbin "baserom_de.gba", 0x4D9928, 0x80
	.global gUnk_0875248C
gUnk_0875248C:
	.incbin "baserom_de.gba", 0x4D99A8, 0x20
	.global gUnk_087524AC
gUnk_087524AC:
	.incbin "baserom_de.gba", 0x4D99C8, 0x80
	.global gUnk_0875252C
gUnk_0875252C:
	.incbin "baserom_de.gba", 0x4D9A48, 0x20
	.global gUnk_0875254C
gUnk_0875254C:
	.incbin "baserom_de.gba", 0x4D9A68, 0x80
	.global gUnk_087525CC
gUnk_087525CC:
	.incbin "baserom_de.gba", 0x4D9AE8, 0x20
	.global gUnk_087525EC
gUnk_087525EC:
	.incbin "baserom_de.gba", 0x4D9B08, 0x80
	.global gUnk_0875266C
gUnk_0875266C:
	.incbin "baserom_de.gba", 0x4D9B88, 0x20
	.global gUnk_0875268C
gUnk_0875268C:
	.incbin "baserom_de.gba", 0x4D9BA8, 0x80
	.global gUnk_0875270C
gUnk_0875270C:
	.incbin "baserom_de.gba", 0x4D9C28, 0x20
	.global gUnk_0875272C
gUnk_0875272C:
	.incbin "baserom_de.gba", 0x4D9C48, 0x80
	.global gUnk_087527AC
gUnk_087527AC:
	.incbin "baserom_de.gba", 0x4D9CC8, 0x20
	.global gUnk_087527CC
gUnk_087527CC:
	.incbin "baserom_de.gba", 0x4D9CE8, 0x80
	.global gUnk_0875284C
gUnk_0875284C:
	.incbin "baserom_de.gba", 0x4D9D68, 0x20
	.global gUnk_0875286C
gUnk_0875286C:
	.incbin "baserom_de.gba", 0x4D9D88, 0x80
	.global gUnk_087528EC
gUnk_087528EC:
	.incbin "baserom_de.gba", 0x4D9E08, 0x20
	.global gUnk_0875290C
gUnk_0875290C:
	.incbin "baserom_de.gba", 0x4D9E28, 0x80
	.global gUnk_0875298C
gUnk_0875298C:
	.incbin "baserom_de.gba", 0x4D9EA8, 0x20
	.global gUnk_087529AC
gUnk_087529AC:
	.incbin "baserom_de.gba", 0x4D9EC8, 0x80
	.global gUnk_08752A2C
gUnk_08752A2C:
	.incbin "baserom_de.gba", 0x4D9F48, 0x80
	.global gUnk_08752AAC
gUnk_08752AAC:
	.incbin "baserom_de.gba", 0x4D9FC8, 0x20
	.global gUnk_08752ACC
gUnk_08752ACC:
	.incbin "baserom_de.gba", 0x4D9FE8, 0x80
	.global gUnk_08752B4C
gUnk_08752B4C:
	.incbin "baserom_de.gba", 0x4DA068, 0x80
	.global gUnk_08752BCC
gUnk_08752BCC:
	.incbin "baserom_de.gba", 0x4DA0E8, 0x80
	.global gUnk_08752C4C
gUnk_08752C4C:
	.incbin "baserom_de.gba", 0x4DA168, 0x80
	.global gUnk_08752CCC
gUnk_08752CCC:
	.incbin "baserom_de.gba", 0x4DA1E8, 0x80
	.global gUnk_08752D4C
gUnk_08752D4C:
	.incbin "baserom_de.gba", 0x4DA268, 0x80
	.global gUnk_08752DCC
gUnk_08752DCC:
	.incbin "baserom_de.gba", 0x4DA2E8, 0x80
	.global gUnk_08752E4C
gUnk_08752E4C:
	.incbin "baserom_de.gba", 0x4DA368, 0x80
	.global gUnk_08752ECC
gUnk_08752ECC:
	.incbin "baserom_de.gba", 0x4DA3E8, 0x20
	.global gUnk_08752EEC
gUnk_08752EEC:
	.incbin "baserom_de.gba", 0x4DA408, 0x80
	.global gUnk_08752F6C
gUnk_08752F6C:
	.incbin "baserom_de.gba", 0x4DA488, 0x20
	.global gUnk_08752F8C
gUnk_08752F8C:
	.incbin "baserom_de.gba", 0x4DA4A8, 0x80
	.global gUnk_0875300C
gUnk_0875300C:
	.incbin "baserom_de.gba", 0x4DA528, 0x20
	.global gUnk_0875302C
gUnk_0875302C:
	.incbin "baserom_de.gba", 0x4DA548, 0x80
	.global gUnk_087530AC
gUnk_087530AC:
	.incbin "baserom_de.gba", 0x4DA5C8, 0x20
	.global gUnk_087530CC
gUnk_087530CC:
	.incbin "baserom_de.gba", 0x4DA5E8, 0x80
	.global gUnk_0875314C
gUnk_0875314C:
	.incbin "baserom_de.gba", 0x4DA668, 0x20
	.global gUnk_0875316C
gUnk_0875316C:
	.incbin "baserom_de.gba", 0x4DA688, 0x80
	.global gUnk_087531EC
gUnk_087531EC:
	.incbin "baserom_de.gba", 0x4DA708, 0x20
	.global gUnk_0875320C
gUnk_0875320C:
	.incbin "baserom_de.gba", 0x4DA728, 0x80
	.global gUnk_0875328C
gUnk_0875328C:
	.incbin "baserom_de.gba", 0x4DA7A8, 0x20
	.global gUnk_087532AC
gUnk_087532AC:
	.incbin "baserom_de.gba", 0x4DA7C8, 0x80
	.global gUnk_0875332C
gUnk_0875332C:
	.incbin "baserom_de.gba", 0x4DA848, 0x20
	.global gUnk_0875334C
gUnk_0875334C:
	.incbin "baserom_de.gba", 0x4DA868, 0x80
	.global gUnk_087533CC
gUnk_087533CC:
	.incbin "baserom_de.gba", 0x4DA8E8, 0x20
	.global gUnk_087533EC
gUnk_087533EC:
	.incbin "baserom_de.gba", 0x4DA908, 0x80
	.global gUnk_0875346C
gUnk_0875346C:
	.incbin "baserom_de.gba", 0x4DA988, 0x20
	.global gUnk_0875348C
gUnk_0875348C:
	.incbin "baserom_de.gba", 0x4DA9A8, 0x80
	.global gUnk_0875350C
gUnk_0875350C:
	.incbin "baserom_de.gba", 0x4DAA28, 0x20
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_0875352C
gUnk_0875352C:
	.incbin "baserom_de.gba", 0x4DAA48, 0xDC
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08753608
gUnk_08753608:
	.incbin "baserom_de.gba", 0x4DAB24, 0xDC
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_087536E4
gUnk_087536E4:
	.incbin "baserom_de.gba", 0x4DAC00, 0xEC
	.global gUnk_087537D0
gUnk_087537D0:
	.incbin "baserom_de.gba", 0x4DACEC, 0xEA4
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08754674
gUnk_08754674:
	.incbin "baserom_de.gba", 0x4DBB90, 0x598
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08754C0C
gUnk_08754C0C:
	.incbin "baserom_de.gba", 0x4DC128, 0x548
	@ Position bounded by adjacent verified DE resources.
	.global gUnk_08755154
gUnk_08755154:
	.incbin "baserom_de.gba", 0x4DC670, 0xDC
	.global gUnk_08755230
gUnk_08755230:
	.incbin "baserom_de.gba", 0x4DC74C, 0x30C
	.global gUnk_0875553C
gUnk_0875553C:
	.incbin "baserom_de.gba", 0x4DCA58, 0x30C
	.global gUnk_08755848
gUnk_08755848:
	.incbin "baserom_de.gba", 0x4DCD64, 0x2298
	.global gUnk_08757AE0
gUnk_08757AE0:
	.incbin "baserom_de.gba", 0x4DEFFC, 0xC0
	.global gUnk_08757BA0
gUnk_08757BA0:
	.incbin "baserom_de.gba", 0x4DF0BC, 0xC
	.global gUnk_08757BAC
gUnk_08757BAC:
	.incbin "baserom_de.gba", 0x4DF0C8, 0x20
	.global gUnk_08757BCC
gUnk_08757BCC:
	.incbin "baserom_de.gba", 0x4DF0E8, 0xC
	.global gUnk_08757BD8
gUnk_08757BD8:
	.incbin "baserom_de.gba", 0x4DF0F4, 0x20
	.global gUnk_08757BF8
gUnk_08757BF8:
	.incbin "baserom_de.gba", 0x4DF114, 0x14
	.global gUnk_08757C0C
gUnk_08757C0C:
	.incbin "baserom_de.gba", 0x4DF128, 0x8
	.global gUnk_08757C14
gUnk_08757C14:
	.incbin "baserom_de.gba", 0x4DF130, 0x30C
	.global gUnk_08757F20
gUnk_08757F20:
	.incbin "baserom_de.gba", 0x4DF43C, 0x30C
	.global gUnk_0875822C
gUnk_0875822C:
	.incbin "baserom_de.gba", 0x4DF748, 0x212C
	.global gUnk_0875A358
gUnk_0875A358:
	.incbin "baserom_de.gba", 0x4E1874, 0xC0
	.global gUnk_0875A418
gUnk_0875A418:
	.incbin "baserom_de.gba", 0x4E1934, 0xC
	.global gUnk_0875A424
gUnk_0875A424:
	.incbin "baserom_de.gba", 0x4E1940, 0x14
	.global gUnk_0875A438
gUnk_0875A438:
	.incbin "baserom_de.gba", 0x4E1954, 0x8
	.global gUnk_0875A440
gUnk_0875A440:
	.incbin "baserom_de.gba", 0x4E195C, 0x1004
	.global gUnk_0875B444
gUnk_0875B444:
	.incbin "baserom_de.gba", 0x4E2960, 0x3D4
	.global gUnk_UiSharedResourceData_000
gUnk_UiSharedResourceData_000:
	.incbin "baserom_de.gba", 0x4E2D34, 0x120
	.global gUnk_UiSharedResourceData_001
gUnk_UiSharedResourceData_001:
	.incbin "baserom_de.gba", 0x4E2E54, 0x182F8
