    .ifdef REGION_JP
    @ JP revision 0 virtual-table region.
    @
    @ The US source already models this as raw data entries.  JP keeps one
    @ static ROM range and exports the same source labels relative to the
    @ verified beginning of its corresponding region.

    .section .rodata
jp_vtables_start:
    .global __vt_6AScene
    .set __vt_6AScene, jp_vtables_start + 0x0
    .global __vt_13AUnk_0800080C
    .set __vt_13AUnk_0800080C, jp_vtables_start + 0x10
    .global vtable_unk_080E59EC
    .set vtable_unk_080E59EC, jp_vtables_start + 0x20
    .global vtable_unk_080E59FC
    .set vtable_unk_080E59FC, jp_vtables_start + 0x30
    .global vtable_unk_080E5A0C
    .set vtable_unk_080E5A0C, jp_vtables_start + 0x40
    .global vtable_unk_080E5A18
    .set vtable_unk_080E5A18, jp_vtables_start + 0x4C
    .global vtable_unk_080E5A28
    .set vtable_unk_080E5A28, jp_vtables_start + 0x5C
    .global vtable_unk_080E5A3C
    .set vtable_unk_080E5A3C, jp_vtables_start + 0x70
    .global vtable_unk_080E5A4C
    .set vtable_unk_080E5A4C, jp_vtables_start + 0x80
    .global vtable_unk_080E5A5C
    .set vtable_unk_080E5A5C, jp_vtables_start + 0x90
    .global vtable_unk_080E5A68
    .set vtable_unk_080E5A68, jp_vtables_start + 0x9C
    .global vtable_unk_080E5A78
    .set vtable_unk_080E5A78, jp_vtables_start + 0xAC
    .global vtable_unk_080E5A88
    .set vtable_unk_080E5A88, jp_vtables_start + 0xBC
    .global vtable_unk_080E5A98
    .set vtable_unk_080E5A98, jp_vtables_start + 0xCC
    .global vtable_unk_080E5AA4
    .set vtable_unk_080E5AA4, jp_vtables_start + 0xD8
    .global vtable_unk_080E5AB4
    .set vtable_unk_080E5AB4, jp_vtables_start + 0xE8
    .global vtable_unk_080E5AC0
    .set vtable_unk_080E5AC0, jp_vtables_start + 0xF4
    .global vtable_unk_080E5AD0
    .set vtable_unk_080E5AD0, jp_vtables_start + 0x104
    .global vtable_unk_080E5AE0
    .set vtable_unk_080E5AE0, jp_vtables_start + 0x114
    .global vtable_unk_080E5AF0
    .set vtable_unk_080E5AF0, jp_vtables_start + 0x124
    .global vtable_unk_080E5B00
    .set vtable_unk_080E5B00, jp_vtables_start + 0x134
    .global vtable_unk_080E5B0C
    .set vtable_unk_080E5B0C, jp_vtables_start + 0x140
    .global vtable_unk_080E5B18
    .set vtable_unk_080E5B18, jp_vtables_start + 0x14C
    .global vtable_unk_080E5B3C
    .set vtable_unk_080E5B3C, jp_vtables_start + 0x170
    .global vtable_unk_080E5B48
    .set vtable_unk_080E5B48, jp_vtables_start + 0x17C
    .global vtable_unk_080E5B54
    .set vtable_unk_080E5B54, jp_vtables_start + 0x188
    .global vtable_unk_080E5B60
    .set vtable_unk_080E5B60, jp_vtables_start + 0x194
    .global vtable_unk_080E5B70
    .set vtable_unk_080E5B70, jp_vtables_start + 0x1A4
    .global vtable_unk_080E5B80
    .set vtable_unk_080E5B80, jp_vtables_start + 0x1B4
    .global vtable_unk_080E5B90
    .set vtable_unk_080E5B90, jp_vtables_start + 0x1C4
    .global vtable_unk_080E5BB4
    .set vtable_unk_080E5BB4, jp_vtables_start + 0x1E8
    .global vtable_unk_080E5BD8
    .set vtable_unk_080E5BD8, jp_vtables_start + 0x20C
    .global vtable_unk_080E5BE8
    .set vtable_unk_080E5BE8, jp_vtables_start + 0x21C
    .global vtable_unk_080E5BF8
    .set vtable_unk_080E5BF8, jp_vtables_start + 0x22C
    .global vtable_unk_080E5C08
    .set vtable_unk_080E5C08, jp_vtables_start + 0x23C
    .global vtable_unk_080E5C14
    .set vtable_unk_080E5C14, jp_vtables_start + 0x248
    .global vtable_unk_080E5C24
    .set vtable_unk_080E5C24, jp_vtables_start + 0x258
    .global vtable_unk_080E5C34
    .set vtable_unk_080E5C34, jp_vtables_start + 0x268
    .global vtable_unk_080E5C44
    .set vtable_unk_080E5C44, jp_vtables_start + 0x278
    .global vtable_unk_080E5C54
    .set vtable_unk_080E5C54, jp_vtables_start + 0x288
    .global vtable_unk_080E5C64
    .set vtable_unk_080E5C64, jp_vtables_start + 0x298
    .global vtable_unk_080E5C74
    .set vtable_unk_080E5C74, jp_vtables_start + 0x2A8
    .global vtable_unk_080E5C84
    .set vtable_unk_080E5C84, jp_vtables_start + 0x2B8
    .global vtable_unk_080E5C94
    .set vtable_unk_080E5C94, jp_vtables_start + 0x2C8
    .global vtable_unk_080E5CA4
    .set vtable_unk_080E5CA4, jp_vtables_start + 0x2D8
    .global vtable_unk_080E5CB4
    .set vtable_unk_080E5CB4, jp_vtables_start + 0x2E8
    .global vtable_unk_080E5CC4
    .set vtable_unk_080E5CC4, jp_vtables_start + 0x2F8
    .global vtable_unk_080E5CD4
    .set vtable_unk_080E5CD4, jp_vtables_start + 0x308
    .global vtable_unk_080E5CE4
    .set vtable_unk_080E5CE4, jp_vtables_start + 0x318
    .global vtable_unk_080E5CF4
    .set vtable_unk_080E5CF4, jp_vtables_start + 0x328
    .global vtable_unk_080E5D04
    .set vtable_unk_080E5D04, jp_vtables_start + 0x338
    .global vtable_unk_080E5D14
    .set vtable_unk_080E5D14, jp_vtables_start + 0x348
    .global vtable_unk_080E5D24
    .set vtable_unk_080E5D24, jp_vtables_start + 0x358
    .global vtable_unk_080E5D34
    .set vtable_unk_080E5D34, jp_vtables_start + 0x368
    .global vtable_unk_080E5D44
    .set vtable_unk_080E5D44, jp_vtables_start + 0x378
    .global vtable_unk_080E5D54
    .set vtable_unk_080E5D54, jp_vtables_start + 0x388
    .global vtable_unk_080E5D64
    .set vtable_unk_080E5D64, jp_vtables_start + 0x398
    .global vtable_unk_080E5D74
    .set vtable_unk_080E5D74, jp_vtables_start + 0x3A8
    .global vtable_unk_080E5D84
    .set vtable_unk_080E5D84, jp_vtables_start + 0x3B8
    .global vtable_unk_080E5D94
    .set vtable_unk_080E5D94, jp_vtables_start + 0x3C8
    .global vtable_unk_080E5DA4
    .set vtable_unk_080E5DA4, jp_vtables_start + 0x3D8
    .global vtable_unk_080E5DB4
    .set vtable_unk_080E5DB4, jp_vtables_start + 0x3E8
    .global vtable_unk_080E5DC4
    .set vtable_unk_080E5DC4, jp_vtables_start + 0x3F8
    .global vtable_unk_080E5DD4
    .set vtable_unk_080E5DD4, jp_vtables_start + 0x408
    .global vtable_unk_080E5DE4
    .set vtable_unk_080E5DE4, jp_vtables_start + 0x418
    .global vtable_unk_080E5DF4
    .set vtable_unk_080E5DF4, jp_vtables_start + 0x428
    .global vtable_unk_080E5E04
    .set vtable_unk_080E5E04, jp_vtables_start + 0x438
    .global vtable_unk_080E5E14
    .set vtable_unk_080E5E14, jp_vtables_start + 0x448
    .global vtable_unk_080E5E24
    .set vtable_unk_080E5E24, jp_vtables_start + 0x458
    .global vtable_unk_080E5E34
    .set vtable_unk_080E5E34, jp_vtables_start + 0x468
    .global vtable_unk_080E5E44
    .set vtable_unk_080E5E44, jp_vtables_start + 0x478
    .global vtable_unk_080E5E54
    .set vtable_unk_080E5E54, jp_vtables_start + 0x488
    .global vtable_unk_080E5E64
    .set vtable_unk_080E5E64, jp_vtables_start + 0x498
    .global vtable_unk_080E5E74
    .set vtable_unk_080E5E74, jp_vtables_start + 0x4A8
    .global vtable_unk_080E5E84
    .set vtable_unk_080E5E84, jp_vtables_start + 0x4B8
    .global vtable_unk_080E5E94
    .set vtable_unk_080E5E94, jp_vtables_start + 0x4C8
    .global vtable_unk_080E5EA4
    .set vtable_unk_080E5EA4, jp_vtables_start + 0x4D8
    .global vtable_unk_080E5EB4
    .set vtable_unk_080E5EB4, jp_vtables_start + 0x4E8
    .global vtable_unk_080E602C
    .set vtable_unk_080E602C, jp_vtables_start + 0x660
    .global vtable_unk_080E6038
    .set vtable_unk_080E6038, jp_vtables_start + 0x66C
    .global vtable_unk_080E61A0
    .set vtable_unk_080E61A0, jp_vtables_start + 0x7D4
    .global __vt_7AEntity
    .set __vt_7AEntity, jp_vtables_start + 0x884
    .global vtable_unk_080E6284
    .set vtable_unk_080E6284, jp_vtables_start + 0x8B8
    .global vtable_unk_080E6310
    .set vtable_unk_080E6310, jp_vtables_start + 0x944
    .global vtable_unk_080E639C
    .set vtable_unk_080E639C, jp_vtables_start + 0x9D0
    .global vtable_unk_080E6428
    .set vtable_unk_080E6428, jp_vtables_start + 0xA5C
    .global vtable_unk_080E64B4
    .set vtable_unk_080E64B4, jp_vtables_start + 0xAE8
    .global vtable_unk_080E64C8
    .set vtable_unk_080E64C8, jp_vtables_start + 0xAFC
    .global __vt_15Entity_080E6554
    .set __vt_15Entity_080E6554, jp_vtables_start + 0xB88
    .global vtable_unk_080E65E0
    .set vtable_unk_080E65E0, jp_vtables_start + 0xC14
    .global vtable_unk_080E65F4
    .set vtable_unk_080E65F4, jp_vtables_start + 0xC28
    .global vtable_unk_080E6644
    .set vtable_unk_080E6644, jp_vtables_start + 0xC78
    .global vtable_unk_080E6658
    .set vtable_unk_080E6658, jp_vtables_start + 0xC8C
    .global vtable_unk_080E6708
    .set vtable_unk_080E6708, jp_vtables_start + 0xD3C
    .global vtable_unk_080E671C
    .set vtable_unk_080E671C, jp_vtables_start + 0xD50
    .global vtable_unk_080E676C
    .set vtable_unk_080E676C, jp_vtables_start + 0xDA0
    .global vtable_unk_080E681C
    .set vtable_unk_080E681C, jp_vtables_start + 0xE50
    .global vtable_unk_080E6828
    .set vtable_unk_080E6828, jp_vtables_start + 0xE5C
    .global vtable_unk_080E6864
    .set vtable_unk_080E6864, jp_vtables_start + 0xE98
    .global __vt_12AActorEntity
    .set __vt_12AActorEntity, jp_vtables_start + 0xEAC
    .global vtable_unk_080E68B4
    .set vtable_unk_080E68B4, jp_vtables_start + 0xEE8
    .global vtable_unk_080E68C8
    .set vtable_unk_080E68C8, jp_vtables_start + 0xEFC
    .global vtable_unk_080E6904
    .set vtable_unk_080E6904, jp_vtables_start + 0xF38
    .global vtable_unk_080E6918
    .set vtable_unk_080E6918, jp_vtables_start + 0xF4C
    .global vtable_unk_080E6958
    .set vtable_unk_080E6958, jp_vtables_start + 0xF8C
    .global vtable_unk_080E6998
    .set vtable_unk_080E6998, jp_vtables_start + 0xFCC
    .global vtable_unk_080E69D8
    .set vtable_unk_080E69D8, jp_vtables_start + 0x100C
    .global vtable_unk_080E6A18
    .set vtable_unk_080E6A18, jp_vtables_start + 0x104C
    .global vtable_unk_080E6A58
    .set vtable_unk_080E6A58, jp_vtables_start + 0x108C
    .global vtable_unk_080E6A98
    .set vtable_unk_080E6A98, jp_vtables_start + 0x10CC
    .global vtable_unk_080E6AD8
    .set vtable_unk_080E6AD8, jp_vtables_start + 0x110C
    .global vtable_unk_080E6B18
    .set vtable_unk_080E6B18, jp_vtables_start + 0x114C
    .global vtable_unk_080E6B58
    .set vtable_unk_080E6B58, jp_vtables_start + 0x118C
    .global vtable_unk_080E6B98
    .set vtable_unk_080E6B98, jp_vtables_start + 0x11CC
    .global vtable_unk_080E6BD8
    .set vtable_unk_080E6BD8, jp_vtables_start + 0x120C
    .global vtable_unk_080E6C18
    .set vtable_unk_080E6C18, jp_vtables_start + 0x124C
    .global vtable_unk_080E6C58
    .set vtable_unk_080E6C58, jp_vtables_start + 0x128C
    .global vtable_unk_080E6C98
    .set vtable_unk_080E6C98, jp_vtables_start + 0x12CC
    .global vtable_unk_080E6CD8
    .set vtable_unk_080E6CD8, jp_vtables_start + 0x130C
    .global vtable_unk_080E6D18
    .set vtable_unk_080E6D18, jp_vtables_start + 0x134C
    .global vtable_unk_080E6D58
    .set vtable_unk_080E6D58, jp_vtables_start + 0x138C
    .global vtable_unk_080E6D98
    .set vtable_unk_080E6D98, jp_vtables_start + 0x13CC
    .global vtable_unk_080E6DD8
    .set vtable_unk_080E6DD8, jp_vtables_start + 0x140C
    .global vtable_unk_080E6E18
    .set vtable_unk_080E6E18, jp_vtables_start + 0x144C
    .global vtable_unk_080E6E58
    .set vtable_unk_080E6E58, jp_vtables_start + 0x148C
    .global vtable_unk_080E6E98
    .set vtable_unk_080E6E98, jp_vtables_start + 0x14CC
    .global vtable_unk_080E6ED8
    .set vtable_unk_080E6ED8, jp_vtables_start + 0x150C
    .global vtable_unk_080E6F18
    .set vtable_unk_080E6F18, jp_vtables_start + 0x154C
    .global vtable_unk_080E6F58
    .set vtable_unk_080E6F58, jp_vtables_start + 0x158C
    .global vtable_unk_080E6F98
    .set vtable_unk_080E6F98, jp_vtables_start + 0x15CC
    .global vtable_unk_080E6FD8
    .set vtable_unk_080E6FD8, jp_vtables_start + 0x160C
    .global vtable_unk_080E7018
    .set vtable_unk_080E7018, jp_vtables_start + 0x164C
    .global vtable_unk_080E7058
    .set vtable_unk_080E7058, jp_vtables_start + 0x168C
    .global vtable_unk_080E7098
    .set vtable_unk_080E7098, jp_vtables_start + 0x16CC
    .global vtable_unk_080E70D8
    .set vtable_unk_080E70D8, jp_vtables_start + 0x170C
    .global vtable_unk_080E7118
    .set vtable_unk_080E7118, jp_vtables_start + 0x174C
    .global vtable_unk_080E7158
    .set vtable_unk_080E7158, jp_vtables_start + 0x178C
    .global vtable_unk_080E7198
    .set vtable_unk_080E7198, jp_vtables_start + 0x17CC
    .global __vt_10ANpcEntity
    .set __vt_10ANpcEntity, jp_vtables_start + 0x180C
    .global vtable_unk_080E7218
    .set vtable_unk_080E7218, jp_vtables_start + 0x184C
    .global vtable_unk_080E725C
    .set vtable_unk_080E725C, jp_vtables_start + 0x1890
    .global vtable_unk_080E72A0
    .set vtable_unk_080E72A0, jp_vtables_start + 0x18D4
    .global vtable_unk_080E72E4
    .set vtable_unk_080E72E4, jp_vtables_start + 0x1918
    .global vtable_unk_080E7328
    .set vtable_unk_080E7328, jp_vtables_start + 0x195C
    .global vtable_unk_080E736C
    .set vtable_unk_080E736C, jp_vtables_start + 0x19A0
    .global vtable_unk_080E7380
    .set vtable_unk_080E7380, jp_vtables_start + 0x19B4
    .global vtable_unk_080E73B4
    .set vtable_unk_080E73B4, jp_vtables_start + 0x19E8
    .global vtable_unk_080E73E8
    .set vtable_unk_080E73E8, jp_vtables_start + 0x1A1C
    .global vtable_unk_080E73FC
    .set vtable_unk_080E73FC, jp_vtables_start + 0x1A30
    .global vtable_unk_080E7430
    .set vtable_unk_080E7430, jp_vtables_start + 0x1A64
    .global vtable_unk_080E7444
    .set vtable_unk_080E7444, jp_vtables_start + 0x1A78
    .global vtable_unk_080E7478
    .set vtable_unk_080E7478, jp_vtables_start + 0x1AAC
    .global vtable_unk_080E748C
    .set vtable_unk_080E748C, jp_vtables_start + 0x1AC0
    .global vtable_unk_080E749C
    .set vtable_unk_080E749C, jp_vtables_start + 0x1AD0
    .global vtable_unk_080E74AC
    .set vtable_unk_080E74AC, jp_vtables_start + 0x1AE0
    .global vtable_unk_080E74BC
    .set vtable_unk_080E74BC, jp_vtables_start + 0x1AF0
    .global vtable_unk_080E74CC
    .set vtable_unk_080E74CC, jp_vtables_start + 0x1B00
    .global vtable_unk_080E74DC
    .set vtable_unk_080E74DC, jp_vtables_start + 0x1B10
    .global vtable_unk_080E7568
    .set vtable_unk_080E7568, jp_vtables_start + 0x1B9C
    .global vtable_unk_080E759C
    .set vtable_unk_080E759C, jp_vtables_start + 0x1BD0
    .global vtable_unk_080E75B4
    .set vtable_unk_080E75B4, jp_vtables_start + 0x1BE8
    .global vtable_unk_080E75CC
    .set vtable_unk_080E75CC, jp_vtables_start + 0x1C00
    .global vtable_unk_080E75E4
    .set vtable_unk_080E75E4, jp_vtables_start + 0x1C18
    .global vtable_unk_080E75FC
    .set vtable_unk_080E75FC, jp_vtables_start + 0x1C30
    .global vtable_unk_080E7614
    .set vtable_unk_080E7614, jp_vtables_start + 0x1C48
    .global vtable_unk_080E762C
    .set vtable_unk_080E762C, jp_vtables_start + 0x1C60
    .global vtable_unk_080E7644
    .set vtable_unk_080E7644, jp_vtables_start + 0x1C78
    .global vtable_unk_080E765C
    .set vtable_unk_080E765C, jp_vtables_start + 0x1C90
    .global vtable_unk_080E7674
    .set vtable_unk_080E7674, jp_vtables_start + 0x1CA8
    .global vtable_unk_080E768C
    .set vtable_unk_080E768C, jp_vtables_start + 0x1CC0
    .global vtable_unk_080E76A4
    .set vtable_unk_080E76A4, jp_vtables_start + 0x1CD8
    .global vtable_unk_080E76BC
    .set vtable_unk_080E76BC, jp_vtables_start + 0x1CF0
    .global vtable_unk_080E76D4
    .set vtable_unk_080E76D4, jp_vtables_start + 0x1D08
    .global vtable_unk_080E76E8
    .set vtable_unk_080E76E8, jp_vtables_start + 0x1D1C
    .global vtable_unk_080E76F8
    .set vtable_unk_080E76F8, jp_vtables_start + 0x1D2C
    .global vtable_unk_080E7708
    .set vtable_unk_080E7708, jp_vtables_start + 0x1D3C
    .global vtable_unk_080E7714
    .set vtable_unk_080E7714, jp_vtables_start + 0x1D48
    .global vtable_unk_080E7728
    .set vtable_unk_080E7728, jp_vtables_start + 0x1D5C
    .global vtable_unk_080E7738
    .set vtable_unk_080E7738, jp_vtables_start + 0x1D6C
    .global vtable_unk_080E7748
    .set vtable_unk_080E7748, jp_vtables_start + 0x1D7C
    .global vtable_unk_080E7758
    .set vtable_unk_080E7758, jp_vtables_start + 0x1D8C
    .global vtable_unk_080E7768
    .set vtable_unk_080E7768, jp_vtables_start + 0x1D9C
    .global vtable_unk_080E7778
    .set vtable_unk_080E7778, jp_vtables_start + 0x1DAC
    .global vtable_unk_080E77A4
    .set vtable_unk_080E77A4, jp_vtables_start + 0x1DD8
    .global vtable_unk_080E77D0
    .set vtable_unk_080E77D0, jp_vtables_start + 0x1E04
    .global vtable_unk_080E77E0
    .set vtable_unk_080E77E0, jp_vtables_start + 0x1E14
    .global __vt_13AScriptEngine
    .set __vt_13AScriptEngine, jp_vtables_start + 0x1E44
    .global vtable_unk_080E7838
    .set vtable_unk_080E7838, jp_vtables_start + 0x1E6C
    .global vtable_unk_080E7848
    .set vtable_unk_080E7848, jp_vtables_start + 0x1E7C
    .global vtable_unk_080E7858
    .set vtable_unk_080E7858, jp_vtables_start + 0x1E8C
    .global vtable_unk_080E7868
    .set vtable_unk_080E7868, jp_vtables_start + 0x1E9C
    .global vtable_unk_080E7878
    .set vtable_unk_080E7878, jp_vtables_start + 0x1EAC
    .global vtable_unk_080E7888
    .set vtable_unk_080E7888, jp_vtables_start + 0x1EBC
    .global vtable_unk_080E7898
    .set vtable_unk_080E7898, jp_vtables_start + 0x1ECC
    .global vtable_unk_080E78A8
    .set vtable_unk_080E78A8, jp_vtables_start + 0x1EDC
    .global vtable_unk_080E78C0
    .set vtable_unk_080E78C0, jp_vtables_start + 0x1EF4
    .global vtable_unk_080E78E0
    .set vtable_unk_080E78E0, jp_vtables_start + 0x1F14
    .global vtable_unk_080E78F0
    .set vtable_unk_080E78F0, jp_vtables_start + 0x1F24
    .global vtable_unk_080E7908
    .set vtable_unk_080E7908, jp_vtables_start + 0x1F3C
    .global vtable_unk_080E7928
    .set vtable_unk_080E7928, jp_vtables_start + 0x1F5C
    .global vtable_unk_080E7934
    .set vtable_unk_080E7934, jp_vtables_start + 0x1F68
    .global vtable_unk_080E7944
    .set vtable_unk_080E7944, jp_vtables_start + 0x1F78
    .global vtable_unk_080E7950
    .set vtable_unk_080E7950, jp_vtables_start + 0x1F84
    .global vtable_unk_080E7960
    .set vtable_unk_080E7960, jp_vtables_start + 0x1F94
    .global vtable_unk_080E7970
    .set vtable_unk_080E7970, jp_vtables_start + 0x1FA4
    .global vtable_unk_080E797C
    .set vtable_unk_080E797C, jp_vtables_start + 0x1FB0
    .global vtable_unk_080E798C
    .set vtable_unk_080E798C, jp_vtables_start + 0x1FC0
    .global vtable_unk_080E799C
    .set vtable_unk_080E799C, jp_vtables_start + 0x1FD0
    .global vtable_unk_080E79A8
    .set vtable_unk_080E79A8, jp_vtables_start + 0x1FDC
    .global vtable_unk_080E79B8
    .set vtable_unk_080E79B8, jp_vtables_start + 0x1FEC
    .global vtable_unk_080E79C8
    .set vtable_unk_080E79C8, jp_vtables_start + 0x1FFC
    .global vtable_unk_080E79DC
    .set vtable_unk_080E79DC, jp_vtables_start + 0x2010
    .global vtable_unk_080E79E8
    .set vtable_unk_080E79E8, jp_vtables_start + 0x201C
    .global vtable_unk_080E79F8
    .set vtable_unk_080E79F8, jp_vtables_start + 0x202C
    .global vtable_unk_080E7A08
    .set vtable_unk_080E7A08, jp_vtables_start + 0x203C
    .global vtable_unk_080E7A18
    .set vtable_unk_080E7A18, jp_vtables_start + 0x204C
    .global vtable_unk_080E7A28
    .set vtable_unk_080E7A28, jp_vtables_start + 0x205C
    .global vtable_unk_080E7A38
    .set vtable_unk_080E7A38, jp_vtables_start + 0x206C
    .global vtable_unk_080E7A48
    .set vtable_unk_080E7A48, jp_vtables_start + 0x207C
    .global vtable_unk_080E7A58
    .set vtable_unk_080E7A58, jp_vtables_start + 0x208C
    .global vtable_unk_080E7A68
    .set vtable_unk_080E7A68, jp_vtables_start + 0x209C
    .global vtable_unk_080E7A78
    .set vtable_unk_080E7A78, jp_vtables_start + 0x20AC
    .global vtable_unk_080E7A88
    .set vtable_unk_080E7A88, jp_vtables_start + 0x20BC
    .global vtable_unk_080E7A98
    .set vtable_unk_080E7A98, jp_vtables_start + 0x20CC
    .global vtable_unk_080E7AA8
    .set vtable_unk_080E7AA8, jp_vtables_start + 0x20DC
    .global vtable_unk_080E7AB4
    .set vtable_unk_080E7AB4, jp_vtables_start + 0x20E8
    .global vtable_unk_080E7AC4
    .set vtable_unk_080E7AC4, jp_vtables_start + 0x20F8
    .global vtable_unk_080E7AD0
    .set vtable_unk_080E7AD0, jp_vtables_start + 0x2104
    .global vtable_unk_080E7AE0
    .set vtable_unk_080E7AE0, jp_vtables_start + 0x2114
    .global vtable_unk_080E7AEC
    .set vtable_unk_080E7AEC, jp_vtables_start + 0x2120
    .global vtable_unk_080E7AFC
    .set vtable_unk_080E7AFC, jp_vtables_start + 0x2130
    .global vtable_unk_080E7B0C
    .set vtable_unk_080E7B0C, jp_vtables_start + 0x2140
    .global vtable_unk_080E7B1C
    .set vtable_unk_080E7B1C, jp_vtables_start + 0x2150
    .global vtable_unk_080E7B2C
    .set vtable_unk_080E7B2C, jp_vtables_start + 0x2160
    .global vtable_unk_080E7B3C
    .set vtable_unk_080E7B3C, jp_vtables_start + 0x2170
    .global vtable_unk_080E7B4C
    .set vtable_unk_080E7B4C, jp_vtables_start + 0x2180
    .global vtable_unk_080E7B5C
    .set vtable_unk_080E7B5C, jp_vtables_start + 0x2190
    .global vtable_unk_080E7B68
    .set vtable_unk_080E7B68, jp_vtables_start + 0x219C
    .global vtable_unk_080E7B78
    .set vtable_unk_080E7B78, jp_vtables_start + 0x21AC
    .global vtable_unk_080E7B88
    .set vtable_unk_080E7B88, jp_vtables_start + 0x21BC
    .global vtable_unk_080E7B98
    .set vtable_unk_080E7B98, jp_vtables_start + 0x21CC
    .global vtable_unk_080E7BA4
    .set vtable_unk_080E7BA4, jp_vtables_start + 0x21D8
    .global vtable_unk_080E7BB4
    .set vtable_unk_080E7BB4, jp_vtables_start + 0x21E8
    .global vtable_unk_080E7BC0
    .set vtable_unk_080E7BC0, jp_vtables_start + 0x21F4
    .global vtable_unk_080E7BD0
    .set vtable_unk_080E7BD0, jp_vtables_start + 0x2204
    .global vtable_unk_080E7BDC
    .set vtable_unk_080E7BDC, jp_vtables_start + 0x2210
    .global vtable_unk_080E7BEC
    .set vtable_unk_080E7BEC, jp_vtables_start + 0x2220
    .global vtable_unk_080E7BF8
    .set vtable_unk_080E7BF8, jp_vtables_start + 0x222C
    .global vtable_unk_080E7C08
    .set vtable_unk_080E7C08, jp_vtables_start + 0x223C
    .global vtable_unk_080E7C14
    .set vtable_unk_080E7C14, jp_vtables_start + 0x2248
    .global vtable_unk_080E7C20
    .set vtable_unk_080E7C20, jp_vtables_start + 0x2254
    .global vtable_unk_080E7C30
    .set vtable_unk_080E7C30, jp_vtables_start + 0x2264
    .global vtable_unk_080E7C40
    .set vtable_unk_080E7C40, jp_vtables_start + 0x2274
    .global vtable_unk_080E7C4C
    .set vtable_unk_080E7C4C, jp_vtables_start + 0x2280
    .global vtable_unk_080E7C5C
    .set vtable_unk_080E7C5C, jp_vtables_start + 0x2290
    .global vtable_unk_080E7C68
    .set vtable_unk_080E7C68, jp_vtables_start + 0x229C
    .global vtable_unk_080E7C78
    .set vtable_unk_080E7C78, jp_vtables_start + 0x22AC
    .global vtable_unk_080E7C84
    .set vtable_unk_080E7C84, jp_vtables_start + 0x22B8
    .global vtable_unk_080E7C94
    .set vtable_unk_080E7C94, jp_vtables_start + 0x22C8
    .global vtable_unk_080E7CA0
    .set vtable_unk_080E7CA0, jp_vtables_start + 0x22D4
    .global vtable_unk_080E7CB0
    .set vtable_unk_080E7CB0, jp_vtables_start + 0x22E4
    .global vtable_unk_080E7CBC
    .set vtable_unk_080E7CBC, jp_vtables_start + 0x22F0
    .global vtable_unk_080E7CCC
    .set vtable_unk_080E7CCC, jp_vtables_start + 0x2300
    .global vtable_unk_080E7CD8
    .set vtable_unk_080E7CD8, jp_vtables_start + 0x230C
    .global vtable_unk_080E7CE8
    .set vtable_unk_080E7CE8, jp_vtables_start + 0x231C
    .global vtable_unk_080E7CF4
    .set vtable_unk_080E7CF4, jp_vtables_start + 0x2328
    .global vtable_unk_080E7D04
    .set vtable_unk_080E7D04, jp_vtables_start + 0x2338
    .global vtable_unk_080E7D14
    .set vtable_unk_080E7D14, jp_vtables_start + 0x2348
    .global vtable_unk_080E7D20
    .set vtable_unk_080E7D20, jp_vtables_start + 0x2354
    .global vtable_unk_080E7D30
    .set vtable_unk_080E7D30, jp_vtables_start + 0x2364
    .global vtable_unk_080E7D3C
    .set vtable_unk_080E7D3C, jp_vtables_start + 0x2370
    .global vtable_unk_080E7D4C
    .set vtable_unk_080E7D4C, jp_vtables_start + 0x2380
    .global vtable_unk_080E7D58
    .set vtable_unk_080E7D58, jp_vtables_start + 0x238C
    .global vtable_unk_080E7D68
    .set vtable_unk_080E7D68, jp_vtables_start + 0x239C
    .global vtable_unk_080E7D74
    .set vtable_unk_080E7D74, jp_vtables_start + 0x23A8
    .global vtable_unk_080E7D84
    .set vtable_unk_080E7D84, jp_vtables_start + 0x23B8
    .global vtable_unk_080E7D90
    .set vtable_unk_080E7D90, jp_vtables_start + 0x23C4
    .global vtable_unk_080E7DA0
    .set vtable_unk_080E7DA0, jp_vtables_start + 0x23D4
    .global vtable_unk_080E7DAC
    .set vtable_unk_080E7DAC, jp_vtables_start + 0x23E0
    .global vtable_unk_080E7DBC
    .set vtable_unk_080E7DBC, jp_vtables_start + 0x23F0
    .global vtable_unk_080E7DC8
    .set vtable_unk_080E7DC8, jp_vtables_start + 0x23FC
    .global vtable_unk_080E7DD8
    .set vtable_unk_080E7DD8, jp_vtables_start + 0x240C
    .global vtable_unk_080E7DE4
    .set vtable_unk_080E7DE4, jp_vtables_start + 0x2418
    .global vtable_unk_080E7DF4
    .set vtable_unk_080E7DF4, jp_vtables_start + 0x2428
    .global vtable_unk_080E7F00
    .set vtable_unk_080E7F00, jp_vtables_start + 0x2534
    .global vtable_unk_080E7F0C
    .set vtable_unk_080E7F0C, jp_vtables_start + 0x2540
    .global vtable_unk_080E8018
    .set vtable_unk_080E8018, jp_vtables_start + 0x264C
    .global vtable_unk_080E8028
    .set vtable_unk_080E8028, jp_vtables_start + 0x265C
    .global vtable_unk_080E812C
    .set vtable_unk_080E812C, jp_vtables_start + 0x2760
    .global vtable_unk_080E8230
    .set vtable_unk_080E8230, jp_vtables_start + 0x2864
    .global vtable_unk_080E823C
    .set vtable_unk_080E823C, jp_vtables_start + 0x2870
    .global vtable_unk_080E824C
    .set vtable_unk_080E824C, jp_vtables_start + 0x2880
    .global vtable_unk_080E825C
    .set vtable_unk_080E825C, jp_vtables_start + 0x2890
    .global vtable_unk_080E8268
    .set vtable_unk_080E8268, jp_vtables_start + 0x289C
    .global vtable_unk_080E8278
    .set vtable_unk_080E8278, jp_vtables_start + 0x28AC
    .global vtable_unk_080E8288
    .set vtable_unk_080E8288, jp_vtables_start + 0x28BC
    .global vtable_unk_080E8298
    .set vtable_unk_080E8298, jp_vtables_start + 0x28CC
    .global vtable_unk_080E82A8
    .set vtable_unk_080E82A8, jp_vtables_start + 0x28DC
    .global vtable_unk_080E82B8
    .set vtable_unk_080E82B8, jp_vtables_start + 0x28EC
    .global vtable_unk_080E82D8
    .set vtable_unk_080E82D8, jp_vtables_start + 0x290C
    .global vtable_unk_080E82E4
    .set vtable_unk_080E82E4, jp_vtables_start + 0x2918
    .global vtable_unk_080E830C
    .set vtable_unk_080E830C, jp_vtables_start + 0x2940
    .global vtable_unk_080E831C
    .set vtable_unk_080E831C, jp_vtables_start + 0x2950
    .global vtable_unk_080E8344
    .set vtable_unk_080E8344, jp_vtables_start + 0x2978
    .global vtable_unk_080E8404
    .set vtable_unk_080E8404, jp_vtables_start + 0x2A38
    .global vtable_unk_080E8440
    .set vtable_unk_080E8440, jp_vtables_start + 0x2A74
    .global vtable_unk_080E8500
    .set vtable_unk_080E8500, jp_vtables_start + 0x2B34
    .global vtable_unk_080E850C
    .set vtable_unk_080E850C, jp_vtables_start + 0x2B40
    .global vtable_unk_080E851C
    .set vtable_unk_080E851C, jp_vtables_start + 0x2B50
    .global vtable_unk_080E8528
    .set vtable_unk_080E8528, jp_vtables_start + 0x2B5C
    .global vtable_unk_080E8538
    .set vtable_unk_080E8538, jp_vtables_start + 0x2B6C
    .global vtable_unk_080E8544
    .set vtable_unk_080E8544, jp_vtables_start + 0x2B78
    .global vtable_unk_080E8554
    .set vtable_unk_080E8554, jp_vtables_start + 0x2B88
    .global vtable_unk_080E8560
    .set vtable_unk_080E8560, jp_vtables_start + 0x2B94
    .global vtable_unk_080E8570
    .set vtable_unk_080E8570, jp_vtables_start + 0x2BA4
    .global vtable_unk_080E857C
    .set vtable_unk_080E857C, jp_vtables_start + 0x2BB0
    .global vtable_unk_080E8588
    .set vtable_unk_080E8588, jp_vtables_start + 0x2BBC
    .global vtable_unk_080E8594
    .set vtable_unk_080E8594, jp_vtables_start + 0x2BC8
    .global vtable_unk_080E85A0
    .set vtable_unk_080E85A0, jp_vtables_start + 0x2BD4
    .global vtable_unk_080E85AC
    .set vtable_unk_080E85AC, jp_vtables_start + 0x2BE0
    .global vtable_unk_080E85BC
    .set vtable_unk_080E85BC, jp_vtables_start + 0x2BF0
    .global vtable_unk_080E85CC
    .set vtable_unk_080E85CC, jp_vtables_start + 0x2C00
    .global vtable_unk_080E85DC
    .set vtable_unk_080E85DC, jp_vtables_start + 0x2C10
    .global vtable_unk_080E85E8
    .set vtable_unk_080E85E8, jp_vtables_start + 0x2C1C

    .incbin "baserom_jp.gba", 0xE4E0C, 0x2C34
    .else

    .section .rodata

	.global vtable_unk_080E59EC
vtable_unk_080E59EC:
	.incbin "baserom_us.gba", 0xE59EC, 0x10

	.global vtable_unk_080E59FC
vtable_unk_080E59FC:
	.incbin "baserom_us.gba", 0xE59FC, 0x10

	.global vtable_unk_080E5A0C
vtable_unk_080E5A0C:
	.incbin "baserom_us.gba", 0xE5A0C, 0xC

	.global vtable_unk_080E5A18
vtable_unk_080E5A18:
	.incbin "baserom_us.gba", 0xE5A18, 0x10

	@ ASprite
	.global vtable_unk_080E5A28
vtable_unk_080E5A28:
	.incbin "baserom_us.gba", 0xE5A28, 0x14

	.global vtable_unk_080E5A3C
vtable_unk_080E5A3C:
	.incbin "baserom_us.gba", 0xE5A3C, 0x10

	.global vtable_unk_080E5A4C
vtable_unk_080E5A4C:
	.incbin "baserom_us.gba", 0xE5A4C, 0x10

	.global vtable_unk_080E5A5C
vtable_unk_080E5A5C:
	.incbin "baserom_us.gba", 0xE5A5C, 0xC

	.global vtable_unk_080E5A68
vtable_unk_080E5A68:
	.incbin "baserom_us.gba", 0xE5A68, 0x10

	.global vtable_unk_080E5A78
vtable_unk_080E5A78:
	.incbin "baserom_us.gba", 0xE5A78, 0x10

	.global vtable_unk_080E5A88
vtable_unk_080E5A88:
	.incbin "baserom_us.gba", 0xE5A88, 0x10

	.global vtable_unk_080E5A98
vtable_unk_080E5A98:
	.incbin "baserom_us.gba", 0xE5A98, 0xC

	.global vtable_unk_080E5AA4
vtable_unk_080E5AA4:
	.incbin "baserom_us.gba", 0xE5AA4, 0x10

	.global vtable_unk_080E5AB4
vtable_unk_080E5AB4:
	.incbin "baserom_us.gba", 0xE5AB4, 0xC

	.global vtable_unk_080E5AC0
vtable_unk_080E5AC0:
	.incbin "baserom_us.gba", 0xE5AC0, 0x10

	.global vtable_unk_080E5AD0
vtable_unk_080E5AD0:
	.incbin "baserom_us.gba", 0xE5AD0, 0x10

	.global vtable_unk_080E5AE0
vtable_unk_080E5AE0:
	.incbin "baserom_us.gba", 0xE5AE0, 0x10

	.global vtable_unk_080E5AF0
vtable_unk_080E5AF0:
	.incbin "baserom_us.gba", 0xE5AF0, 0x10

	.global vtable_unk_080E5B00
vtable_unk_080E5B00:
	.incbin "baserom_us.gba", 0xE5B00, 0xC

	.global vtable_unk_080E5B0C
vtable_unk_080E5B0C:
	.incbin "baserom_us.gba", 0xE5B0C, 0xC

	.global vtable_unk_080E5B18
vtable_unk_080E5B18:
	.incbin "baserom_us.gba", 0xE5B18, 0x24

	.global vtable_unk_080E5B3C
vtable_unk_080E5B3C:
	.incbin "baserom_us.gba", 0xE5B3C, 0xC

	.global vtable_unk_080E5B48
vtable_unk_080E5B48:
	.incbin "baserom_us.gba", 0xE5B48, 0xC

	.global vtable_unk_080E5B54
vtable_unk_080E5B54:
	.incbin "baserom_us.gba", 0xE5B54, 0xC

	.global vtable_unk_080E5B60
vtable_unk_080E5B60:
	.incbin "baserom_us.gba", 0xE5B60, 0x10

	.global vtable_unk_080E5B70
vtable_unk_080E5B70:
	.incbin "baserom_us.gba", 0xE5B70, 0x10

	.global vtable_unk_080E5B80
vtable_unk_080E5B80:
	.incbin "baserom_us.gba", 0xE5B80, 0x10

	.global vtable_unk_080E5B90
vtable_unk_080E5B90:
	.incbin "baserom_us.gba", 0xE5B90, 0x24

	.global vtable_unk_080E5BB4
vtable_unk_080E5BB4:
	.incbin "baserom_us.gba", 0xE5BB4, 0x24

	.global vtable_unk_080E5BD8
vtable_unk_080E5BD8:
	.incbin "baserom_us.gba", 0xE5BD8, 0x10

	.global vtable_unk_080E5BE8
vtable_unk_080E5BE8:
	.incbin "baserom_us.gba", 0xE5BE8, 0x10

	.global vtable_unk_080E5BF8
vtable_unk_080E5BF8:
	.incbin "baserom_us.gba", 0xE5BF8, 0x10

	.global vtable_unk_080E5C08
vtable_unk_080E5C08:
	.incbin "baserom_us.gba", 0xE5C08, 0xC

	.global vtable_unk_080E5C14
vtable_unk_080E5C14:
	.incbin "baserom_us.gba", 0xE5C14, 0x10

	.global vtable_unk_080E5C24
vtable_unk_080E5C24:
	.incbin "baserom_us.gba", 0xE5C24, 0x10

	.global vtable_unk_080E5C34
vtable_unk_080E5C34:
	.incbin "baserom_us.gba", 0xE5C34, 0x10

	.global vtable_unk_080E5C44
vtable_unk_080E5C44:
	.incbin "baserom_us.gba", 0xE5C44, 0x10

	.global vtable_unk_080E5C54
vtable_unk_080E5C54:
	.incbin "baserom_us.gba", 0xE5C54, 0x10

	.global vtable_unk_080E5C64
vtable_unk_080E5C64:
	.incbin "baserom_us.gba", 0xE5C64, 0x10

	.global vtable_unk_080E5C74
vtable_unk_080E5C74:
	.incbin "baserom_us.gba", 0xE5C74, 0x10

	.global vtable_unk_080E5C84
vtable_unk_080E5C84:
	.incbin "baserom_us.gba", 0xE5C84, 0x10

	.global vtable_unk_080E5C94
vtable_unk_080E5C94:
	.incbin "baserom_us.gba", 0xE5C94, 0x10

	.global vtable_unk_080E5CA4
vtable_unk_080E5CA4:
	.incbin "baserom_us.gba", 0xE5CA4, 0x10

	.global vtable_unk_080E5CB4
vtable_unk_080E5CB4:
	.incbin "baserom_us.gba", 0xE5CB4, 0x10

	.global vtable_unk_080E5CC4
vtable_unk_080E5CC4:
	.incbin "baserom_us.gba", 0xE5CC4, 0x10

	.global vtable_unk_080E5CD4
vtable_unk_080E5CD4:
	.incbin "baserom_us.gba", 0xE5CD4, 0x10

	.global vtable_unk_080E5CE4
vtable_unk_080E5CE4:
	.incbin "baserom_us.gba", 0xE5CE4, 0x10

	.global vtable_unk_080E5CF4
vtable_unk_080E5CF4:
	.incbin "baserom_us.gba", 0xE5CF4, 0x10

	.global vtable_unk_080E5D04
vtable_unk_080E5D04:
	.incbin "baserom_us.gba", 0xE5D04, 0x10

	.global vtable_unk_080E5D14
vtable_unk_080E5D14:
	.incbin "baserom_us.gba", 0xE5D14, 0x10

	.global vtable_unk_080E5D24
vtable_unk_080E5D24:
	.incbin "baserom_us.gba", 0xE5D24, 0x10

	.global vtable_unk_080E5D34
vtable_unk_080E5D34:
	.incbin "baserom_us.gba", 0xE5D34, 0x10

	.global vtable_unk_080E5D44
vtable_unk_080E5D44:
	.incbin "baserom_us.gba", 0xE5D44, 0x10

	.global vtable_unk_080E5D54
vtable_unk_080E5D54:
	.incbin "baserom_us.gba", 0xE5D54, 0x10

	.global vtable_unk_080E5D64
vtable_unk_080E5D64:
	.incbin "baserom_us.gba", 0xE5D64, 0x10

	.global vtable_unk_080E5D74
vtable_unk_080E5D74:
	.incbin "baserom_us.gba", 0xE5D74, 0x10

	.global vtable_unk_080E5D84
vtable_unk_080E5D84:
	.incbin "baserom_us.gba", 0xE5D84, 0x10

	.global vtable_unk_080E5D94
vtable_unk_080E5D94:
	.incbin "baserom_us.gba", 0xE5D94, 0x10

	.global vtable_unk_080E5DA4
vtable_unk_080E5DA4:
	.incbin "baserom_us.gba", 0xE5DA4, 0x10

	.global vtable_unk_080E5DB4
vtable_unk_080E5DB4:
	.incbin "baserom_us.gba", 0xE5DB4, 0x10

	.global vtable_unk_080E5DC4
vtable_unk_080E5DC4:
	.incbin "baserom_us.gba", 0xE5DC4, 0x10

	.global vtable_unk_080E5DD4
vtable_unk_080E5DD4:
	.incbin "baserom_us.gba", 0xE5DD4, 0x10

	.global vtable_unk_080E5DE4
vtable_unk_080E5DE4:
	.incbin "baserom_us.gba", 0xE5DE4, 0x10

	.global vtable_unk_080E5DF4
vtable_unk_080E5DF4:
	.incbin "baserom_us.gba", 0xE5DF4, 0x10

	.global vtable_unk_080E5E04
vtable_unk_080E5E04:
	.incbin "baserom_us.gba", 0xE5E04, 0x10

	.global vtable_unk_080E5E14
vtable_unk_080E5E14:
	.incbin "baserom_us.gba", 0xE5E14, 0x10

	.global vtable_unk_080E5E24
vtable_unk_080E5E24:
	.incbin "baserom_us.gba", 0xE5E24, 0x10

	.global vtable_unk_080E5E34
vtable_unk_080E5E34:
	.incbin "baserom_us.gba", 0xE5E34, 0x10

	.global vtable_unk_080E5E44
vtable_unk_080E5E44:
	.incbin "baserom_us.gba", 0xE5E44, 0x10

	.global vtable_unk_080E5E54
vtable_unk_080E5E54:
	.incbin "baserom_us.gba", 0xE5E54, 0x10

	.global vtable_unk_080E5E64
vtable_unk_080E5E64:
	.incbin "baserom_us.gba", 0xE5E64, 0x10

	.global vtable_unk_080E5E74
vtable_unk_080E5E74:
	.incbin "baserom_us.gba", 0xE5E74, 0x10

	.global vtable_unk_080E5E84
vtable_unk_080E5E84:
	.incbin "baserom_us.gba", 0xE5E84, 0x10

	.global vtable_unk_080E5E94
vtable_unk_080E5E94:
	.incbin "baserom_us.gba", 0xE5E94, 0x10

	.global vtable_unk_080E5EA4
vtable_unk_080E5EA4:
	.incbin "baserom_us.gba", 0xE5EA4, 0x10

	.global vtable_unk_080E5EB4
vtable_unk_080E5EB4:
	.incbin "baserom_us.gba", 0xE5EB4, 0x10

	.global vtable_unk_080E5EC4
vtable_unk_080E5EC4: @ game object
	.word 0, 0
	.word func_080179CC @ 08
	.word func_08017C30 @ 0C
	.word func_080182C8 @ 10
	.word 0x0801FD59
	.word 0x0801FD51
	.word 0x0801FD49
	.word func_0801FD6C
	.word func_0801FD60 @ 20
	.word func_0801FD3C
	.word func_08019F7C
	.word func_08019FE8
	.word func_0801A054 @ 30
	.word func_0801A8E0
	.word func_0801FD0C
	.word 0x0801FD01
	.word 0x0801FCF5
	.word 0x0801B5C1
	.word 0x0801FCDD
	.word 0x0801FCB5
	.word 0x0801B9E9
	.word 0x0801FD31
	.word 0x0801FC55
	.word 0x0801FC49
	.word 0x0801FC61
	.word 0x0801FC6D
	.word 0x0801FC3D
	.word 0x0801FC0D
	.word 0x0801FC01
	.word 0x0801FBF5
	.word 0x0801FBE9
	.word func_0801DD78
	.word func_0801DD18
	.word func_0801DD24
	.word func_0801DD30
	.word 0x0801DD3D
	.word 0x0801DD49
	.word 0x0801DD55
	.word 0x0801DD61
	.word 0x0801DD6D
	.word 0x0801DD85
	.word 0x0801DE55
	.word func_0801DE24
	.word func_08017C00
	.word func_08019BEC
	.word func_08019B90
	.word func_0801EAA0
	.word func_0801C29C
	.word 0x0801CA1D
	.word 0x0801C49D
	.word 0x0801CAD9
	.word 0x0801CEFD
	.word 0x0801D23D
	.word 0x0801D3FD
	.word 0x0801D4E1
	.word 0x0801D5BD
	.word 0x0801D7B1
	.word 0x0801D88D
	.word 0x0801CBB1
	.word 0x0801CFB9
	.word 0x0801C3DD
	.word 0x0801C3E1
	.word 0x0801DE31
	.word func_0801DE3C
	.word func_0801DE48
	.word func_0801DEB4
	.word func_0801DDCC
	.word func_0801DDF8
	.word func_0801DCD4
	.word func_0801DC24
	.word func_0801DCA8
	.word func_08019F38
	.word func_0801D8CC
	.word func_0801D948
	.word func_0801FAA8
	.word func_0801FAB8
	.word 0x0801B499
	.word 0x0801E085
	.word 0x0801C0E1
	.word func_0801D9A8
	.word 0x0801FCA5
	.word 0x0801D9BD
	.word func_0801DB44
	.word 0x0801F519
	.word func_0801F5F0
	.word func_0801EE00
	.word func_0801F924
	.word 0x0801C551
	.word 0x0801C69D

	.global vtable_unk_080E602C
vtable_unk_080E602C:
	.incbin "baserom_us.gba", 0xE602C, 0xC

	.global vtable_unk_080E6038
vtable_unk_080E6038:
	.incbin "baserom_us.gba", 0xE6038, 0x168

	.global vtable_unk_080E61A0
vtable_unk_080E61A0:
	.incbin "baserom_us.gba", 0xE61A0, 0xB0

	.section .rodata.080E6284

	.global vtable_unk_080E6284
vtable_unk_080E6284:
	.incbin "baserom_us.gba", 0xE6284, 0x8C

	.global vtable_unk_080E6310
vtable_unk_080E6310:
	.incbin "baserom_us.gba", 0xE6310, 0x8C

	.global vtable_unk_080E639C
vtable_unk_080E639C:
	.incbin "baserom_us.gba", 0xE639C, 0x8C

	.global vtable_unk_080E6428
vtable_unk_080E6428:
	.incbin "baserom_us.gba", 0xE6428, 0x8C

	.global vtable_unk_080E64B4
vtable_unk_080E64B4:
	.incbin "baserom_us.gba", 0xE64B4, 0x14

	.global vtable_unk_080E64C8
vtable_unk_080E64C8:
	.incbin "baserom_us.gba", 0xE64C8, 0x8C

	.global __vt_15Entity_080E6554
__vt_15Entity_080E6554:
	.incbin "baserom_us.gba", 0xE6554, 0x8C

	.global vtable_unk_080E65E0
vtable_unk_080E65E0:
	.incbin "baserom_us.gba", 0xE65E0, 0x14

	.global vtable_unk_080E65F4
vtable_unk_080E65F4:
	.incbin "baserom_us.gba", 0xE65F4, 0x50

	.global vtable_unk_080E6644
vtable_unk_080E6644:
	.incbin "baserom_us.gba", 0xE6644, 0x14

	.global vtable_unk_080E6658
vtable_unk_080E6658:
	.incbin "baserom_us.gba", 0xE6658, 0xB0

	.global vtable_unk_080E6708
vtable_unk_080E6708:
	.incbin "baserom_us.gba", 0xE6708, 0x14

	.global vtable_unk_080E671C
vtable_unk_080E671C:
	.incbin "baserom_us.gba", 0xE671C, 0x50

	.global vtable_unk_080E676C
vtable_unk_080E676C:
	.incbin "baserom_us.gba", 0xE676C, 0xB0

	.global vtable_unk_080E681C
vtable_unk_080E681C:
	.incbin "baserom_us.gba", 0xE681C, 0xC

	.global vtable_unk_080E6828
vtable_unk_080E6828:
	.incbin "baserom_us.gba", 0xE6828, 0x3C

	.global vtable_unk_080E6864
vtable_unk_080E6864:
	.incbin "baserom_us.gba", 0xE6864, 0x14

	.global __vt_12AActorEntity
__vt_12AActorEntity:
	.incbin "baserom_us.gba", 0xE6878, 0x3C

	.global vtable_unk_080E68B4
vtable_unk_080E68B4:
	.incbin "baserom_us.gba", 0xE68B4, 0x14

	.global vtable_unk_080E68C8
vtable_unk_080E68C8:
	.incbin "baserom_us.gba", 0xE68C8, 0x3C

	.global vtable_unk_080E6904
vtable_unk_080E6904:
	.incbin "baserom_us.gba", 0xE6904, 0x14

	.global vtable_unk_080E6918
vtable_unk_080E6918:
	.incbin "baserom_us.gba", 0xE6918, 0x40

	.global vtable_unk_080E6958
vtable_unk_080E6958:
	.incbin "baserom_us.gba", 0xE6958, 0x40

	.global vtable_unk_080E6998
vtable_unk_080E6998:
	.incbin "baserom_us.gba", 0xE6998, 0x40

	.global vtable_unk_080E69D8
vtable_unk_080E69D8:
	.incbin "baserom_us.gba", 0xE69D8, 0x40

	.global vtable_unk_080E6A18
vtable_unk_080E6A18:
	.incbin "baserom_us.gba", 0xE6A18, 0x40

	.global vtable_unk_080E6A58
vtable_unk_080E6A58:
	.incbin "baserom_us.gba", 0xE6A58, 0x40

	.global vtable_unk_080E6A98
vtable_unk_080E6A98:
	.incbin "baserom_us.gba", 0xE6A98, 0x40

	.global vtable_unk_080E6AD8
vtable_unk_080E6AD8:
	.incbin "baserom_us.gba", 0xE6AD8, 0x40

	.global vtable_unk_080E6B18
vtable_unk_080E6B18:
	.incbin "baserom_us.gba", 0xE6B18, 0x40

	.global vtable_unk_080E6B58
vtable_unk_080E6B58:
	.incbin "baserom_us.gba", 0xE6B58, 0x40

	.global vtable_unk_080E6B98
vtable_unk_080E6B98:
	.incbin "baserom_us.gba", 0xE6B98, 0x40

	.global vtable_unk_080E6BD8
vtable_unk_080E6BD8:
	.incbin "baserom_us.gba", 0xE6BD8, 0x40

	.global vtable_unk_080E6C18
vtable_unk_080E6C18:
	.incbin "baserom_us.gba", 0xE6C18, 0x40

	.global vtable_unk_080E6C58
vtable_unk_080E6C58:
	.incbin "baserom_us.gba", 0xE6C58, 0x40

	.global vtable_unk_080E6C98
vtable_unk_080E6C98:
	.incbin "baserom_us.gba", 0xE6C98, 0x40

	.global vtable_unk_080E6CD8
vtable_unk_080E6CD8:
	.incbin "baserom_us.gba", 0xE6CD8, 0x40

	.global vtable_unk_080E6D18
vtable_unk_080E6D18:
	.incbin "baserom_us.gba", 0xE6D18, 0x40

	.global vtable_unk_080E6D58
vtable_unk_080E6D58:
	.incbin "baserom_us.gba", 0xE6D58, 0x40

	.global vtable_unk_080E6D98
vtable_unk_080E6D98:
	.incbin "baserom_us.gba", 0xE6D98, 0x40

	.global vtable_unk_080E6DD8
vtable_unk_080E6DD8:
	.incbin "baserom_us.gba", 0xE6DD8, 0x40

	.global vtable_unk_080E6E18
vtable_unk_080E6E18:
	.incbin "baserom_us.gba", 0xE6E18, 0x40

	.global vtable_unk_080E6E58
vtable_unk_080E6E58:
	.incbin "baserom_us.gba", 0xE6E58, 0x40

	.global vtable_unk_080E6E98
vtable_unk_080E6E98:
	.incbin "baserom_us.gba", 0xE6E98, 0x40

	.global vtable_unk_080E6ED8
vtable_unk_080E6ED8:
	.incbin "baserom_us.gba", 0xE6ED8, 0x40

	.global vtable_unk_080E6F18
vtable_unk_080E6F18:
	.incbin "baserom_us.gba", 0xE6F18, 0x40

	.global vtable_unk_080E6F58
vtable_unk_080E6F58:
	.incbin "baserom_us.gba", 0xE6F58, 0x40

	.global vtable_unk_080E6F98
vtable_unk_080E6F98:
	.incbin "baserom_us.gba", 0xE6F98, 0x40

	.global vtable_unk_080E6FD8
vtable_unk_080E6FD8:
	.incbin "baserom_us.gba", 0xE6FD8, 0x40

	.global vtable_unk_080E7018
vtable_unk_080E7018:
	.incbin "baserom_us.gba", 0xE7018, 0x40

	.global vtable_unk_080E7058
vtable_unk_080E7058:
	.incbin "baserom_us.gba", 0xE7058, 0x40

	.global vtable_unk_080E7098
vtable_unk_080E7098:
	.incbin "baserom_us.gba", 0xE7098, 0x40

	.global vtable_unk_080E70D8
vtable_unk_080E70D8:
	.incbin "baserom_us.gba", 0xE70D8, 0x40

	.global vtable_unk_080E7118
vtable_unk_080E7118:
	.incbin "baserom_us.gba", 0xE7118, 0x40

	.global vtable_unk_080E7158
vtable_unk_080E7158:
	.incbin "baserom_us.gba", 0xE7158, 0x40

	.global vtable_unk_080E7198
vtable_unk_080E7198:
	.incbin "baserom_us.gba", 0xE7198, 0x40

	.global __vt_10ANpcEntity
__vt_10ANpcEntity:
	.incbin "baserom_us.gba", 0xE71D8, 0x40

	.global vtable_unk_080E7218
vtable_unk_080E7218:
	.incbin "baserom_us.gba", 0xE7218, 0x44

	.global vtable_unk_080E725C
vtable_unk_080E725C:
	.incbin "baserom_us.gba", 0xE725C, 0x44

	.global vtable_unk_080E72A0
vtable_unk_080E72A0:
	.incbin "baserom_us.gba", 0xE72A0, 0x44

	.global vtable_unk_080E72E4
vtable_unk_080E72E4:
	.incbin "baserom_us.gba", 0xE72E4, 0x44

	.global vtable_unk_080E7328
vtable_unk_080E7328:
	.incbin "baserom_us.gba", 0xE7328, 0x44

	.global vtable_unk_080E736C
vtable_unk_080E736C:
	.incbin "baserom_us.gba", 0xE736C, 0x14

	.global vtable_unk_080E7380
vtable_unk_080E7380:
	.incbin "baserom_us.gba", 0xE7380, 0x34

	.global vtable_unk_080E73B4
vtable_unk_080E73B4:
	.incbin "baserom_us.gba", 0xE73B4, 0x34

	.global vtable_unk_080E73E8
vtable_unk_080E73E8:
	.incbin "baserom_us.gba", 0xE73E8, 0x14

	.global vtable_unk_080E73FC
vtable_unk_080E73FC:
	.incbin "baserom_us.gba", 0xE73FC, 0x34

	.global vtable_unk_080E7430
vtable_unk_080E7430:
	.incbin "baserom_us.gba", 0xE7430, 0x14

	.global vtable_unk_080E7444
vtable_unk_080E7444:
	.incbin "baserom_us.gba", 0xE7444, 0x34

	.global vtable_unk_080E7478
vtable_unk_080E7478:
	.incbin "baserom_us.gba", 0xE7478, 0x14

	.global vtable_unk_080E748C
vtable_unk_080E748C:
	.incbin "baserom_us.gba", 0xE748C, 0x10

	.global vtable_unk_080E749C
vtable_unk_080E749C:
	.incbin "baserom_us.gba", 0xE749C, 0x10

	.global vtable_unk_080E74AC
vtable_unk_080E74AC:
	.incbin "baserom_us.gba", 0xE74AC, 0x10

	.global vtable_unk_080E74BC
vtable_unk_080E74BC:
	.incbin "baserom_us.gba", 0xE74BC, 0x10

	.global vtable_unk_080E74CC
vtable_unk_080E74CC:
	.incbin "baserom_us.gba", 0xE74CC, 0x10

	.global vtable_unk_080E74DC
vtable_unk_080E74DC:
	.incbin "baserom_us.gba", 0xE74DC, 0x8C

	.global vtable_unk_080E7568
vtable_unk_080E7568:
	.incbin "baserom_us.gba", 0xE7568, 0x34

	.global vtable_unk_080E759C
vtable_unk_080E759C:
	.incbin "baserom_us.gba", 0xE759C, 0x18

	.global vtable_unk_080E75B4
vtable_unk_080E75B4:
	.incbin "baserom_us.gba", 0xE75B4, 0x18

	.global vtable_unk_080E75CC
vtable_unk_080E75CC:
	.incbin "baserom_us.gba", 0xE75CC, 0x18

	.global vtable_unk_080E75E4
vtable_unk_080E75E4:
	.incbin "baserom_us.gba", 0xE75E4, 0x18

	.global vtable_unk_080E75FC
vtable_unk_080E75FC:
	.incbin "baserom_us.gba", 0xE75FC, 0x18

	.global vtable_unk_080E7614
vtable_unk_080E7614:
	.incbin "baserom_us.gba", 0xE7614, 0x18

	.global vtable_unk_080E762C
vtable_unk_080E762C:
	.incbin "baserom_us.gba", 0xE762C, 0x18

	.global vtable_unk_080E7644
vtable_unk_080E7644:
	.incbin "baserom_us.gba", 0xE7644, 0x18

	.global vtable_unk_080E765C
vtable_unk_080E765C:
	.incbin "baserom_us.gba", 0xE765C, 0x18

	.global vtable_unk_080E7674
vtable_unk_080E7674:
	.incbin "baserom_us.gba", 0xE7674, 0x18

	.global vtable_unk_080E768C
vtable_unk_080E768C:
	.incbin "baserom_us.gba", 0xE768C, 0x18

	.global vtable_unk_080E76A4
vtable_unk_080E76A4:
	.incbin "baserom_us.gba", 0xE76A4, 0x18

	.global vtable_unk_080E76BC
vtable_unk_080E76BC:
	.incbin "baserom_us.gba", 0xE76BC, 0x18

	.global vtable_unk_080E76D4
vtable_unk_080E76D4:
	.incbin "baserom_us.gba", 0xE76D4, 0x14

	.global vtable_unk_080E76E8
vtable_unk_080E76E8:
	.incbin "baserom_us.gba", 0xE76E8, 0x10

	.global vtable_unk_080E76F8
vtable_unk_080E76F8:
	.incbin "baserom_us.gba", 0xE76F8, 0x10

	.global vtable_unk_080E7708
vtable_unk_080E7708:
	.incbin "baserom_us.gba", 0xE7708, 0xC

	.global vtable_unk_080E7714
vtable_unk_080E7714:
	.incbin "baserom_us.gba", 0xE7714, 0x14

	.global vtable_unk_080E7728
vtable_unk_080E7728:
	.incbin "baserom_us.gba", 0xE7728, 0x10

	.global vtable_unk_080E7738
vtable_unk_080E7738:
	.incbin "baserom_us.gba", 0xE7738, 0x10

	.global vtable_unk_080E7748
vtable_unk_080E7748:
	.incbin "baserom_us.gba", 0xE7748, 0x10

	.global vtable_unk_080E7758
vtable_unk_080E7758:
	.incbin "baserom_us.gba", 0xE7758, 0x10

	.global vtable_unk_080E7768
vtable_unk_080E7768:
	.incbin "baserom_us.gba", 0xE7768, 0x10

	.global vtable_unk_080E7778
vtable_unk_080E7778:
	.incbin "baserom_us.gba", 0xE7778, 0x2C

	.global vtable_unk_080E77A4
vtable_unk_080E77A4:
	.incbin "baserom_us.gba", 0xE77A4, 0x2C

	.global vtable_unk_080E77D0
vtable_unk_080E77D0:
	.incbin "baserom_us.gba", 0xE77D0, 0x10

	.global vtable_unk_080E77E0
vtable_unk_080E77E0:
	.incbin "baserom_us.gba", 0xE77E0, 0x30

	.section .rodata.080E7824

	.global __vt_12ScriptEngine
__vt_12ScriptEngine:
	.word 0, 0
	.4byte func_080E0EF0 @ ScriptEngine::~ScriptEngine
	.4byte method_0803EFD8__13AScriptEngine
	.4byte func_0803F8DC @ ScriptEngine::OnCall

	.global vtable_unk_080E7838
vtable_unk_080E7838:
	.incbin "baserom_us.gba", 0xE7838, 0x10

	.global vtable_unk_080E7848
vtable_unk_080E7848:
	.incbin "baserom_us.gba", 0xE7848, 0x10

	.global vtable_unk_080E7858
vtable_unk_080E7858:
	.incbin "baserom_us.gba", 0xE7858, 0x10

	.global vtable_unk_080E7868
vtable_unk_080E7868:
	.incbin "baserom_us.gba", 0xE7868, 0x10

	.global vtable_unk_080E7878
vtable_unk_080E7878:
	.incbin "baserom_us.gba", 0xE7878, 0x10

	.global vtable_unk_080E7888
vtable_unk_080E7888:
	.incbin "baserom_us.gba", 0xE7888, 0x10

	.global vtable_unk_080E7898
vtable_unk_080E7898:
	.incbin "baserom_us.gba", 0xE7898, 0x10

	.global vtable_unk_080E78A8
vtable_unk_080E78A8:
	.incbin "baserom_us.gba", 0xE78A8, 0x18

	.global vtable_unk_080E78C0
vtable_unk_080E78C0:
	.incbin "baserom_us.gba", 0xE78C0, 0x20

	.global vtable_unk_080E78E0
vtable_unk_080E78E0:
	.incbin "baserom_us.gba", 0xE78E0, 0x10

	.global vtable_unk_080E78F0
vtable_unk_080E78F0:
	.incbin "baserom_us.gba", 0xE78F0, 0x18

	.global vtable_unk_080E7908
vtable_unk_080E7908:
	.incbin "baserom_us.gba", 0xE7908, 0x20

	.global vtable_unk_080E7928
vtable_unk_080E7928:
	.incbin "baserom_us.gba", 0xE7928, 0xC

	.global vtable_unk_080E7934
vtable_unk_080E7934:
	.incbin "baserom_us.gba", 0xE7934, 0x10

	.global vtable_unk_080E7944
vtable_unk_080E7944:
	.incbin "baserom_us.gba", 0xE7944, 0xC

	.global vtable_unk_080E7950
vtable_unk_080E7950:
	.incbin "baserom_us.gba", 0xE7950, 0x10

	.global vtable_unk_080E7960
vtable_unk_080E7960:
	.incbin "baserom_us.gba", 0xE7960, 0x10

	.global vtable_unk_080E7970
vtable_unk_080E7970:
	.incbin "baserom_us.gba", 0xE7970, 0xC

	.global vtable_unk_080E797C
vtable_unk_080E797C:
	.incbin "baserom_us.gba", 0xE797C, 0x10

	.global vtable_unk_080E798C
vtable_unk_080E798C:
	.incbin "baserom_us.gba", 0xE798C, 0x10

	.global vtable_unk_080E799C
vtable_unk_080E799C:
	.incbin "baserom_us.gba", 0xE799C, 0xC

	.global vtable_unk_080E79A8
vtable_unk_080E79A8:
	.incbin "baserom_us.gba", 0xE79A8, 0x10

	.global vtable_unk_080E79B8
vtable_unk_080E79B8:
	.incbin "baserom_us.gba", 0xE79B8, 0x10

	.global vtable_unk_080E79C8
vtable_unk_080E79C8:
	.incbin "baserom_us.gba", 0xE79C8, 0x14

	.global vtable_unk_080E79DC
vtable_unk_080E79DC:
	.incbin "baserom_us.gba", 0xE79DC, 0xC

	.global vtable_unk_080E79E8
vtable_unk_080E79E8:
	.incbin "baserom_us.gba", 0xE79E8, 0x10

	.global vtable_unk_080E79F8
vtable_unk_080E79F8:
	.incbin "baserom_us.gba", 0xE79F8, 0x10

	.global vtable_unk_080E7A08
vtable_unk_080E7A08:
	.incbin "baserom_us.gba", 0xE7A08, 0x10

	.global vtable_unk_080E7A18
vtable_unk_080E7A18:
	.incbin "baserom_us.gba", 0xE7A18, 0x10

	.global vtable_unk_080E7A28
vtable_unk_080E7A28:
	.incbin "baserom_us.gba", 0xE7A28, 0x10

	.global vtable_unk_080E7A38
vtable_unk_080E7A38:
	.incbin "baserom_us.gba", 0xE7A38, 0x10

	.global vtable_unk_080E7A48
vtable_unk_080E7A48:
	.incbin "baserom_us.gba", 0xE7A48, 0x10

	.global vtable_unk_080E7A58
vtable_unk_080E7A58:
	.incbin "baserom_us.gba", 0xE7A58, 0x10

	.global vtable_unk_080E7A68
vtable_unk_080E7A68:
	.incbin "baserom_us.gba", 0xE7A68, 0x10

	.global vtable_unk_080E7A78
vtable_unk_080E7A78:
	.incbin "baserom_us.gba", 0xE7A78, 0x10

	.global vtable_unk_080E7A88
vtable_unk_080E7A88:
	.incbin "baserom_us.gba", 0xE7A88, 0x10

	.global vtable_unk_080E7A98
vtable_unk_080E7A98:
	.incbin "baserom_us.gba", 0xE7A98, 0x10

	.global vtable_unk_080E7AA8
vtable_unk_080E7AA8:
	.incbin "baserom_us.gba", 0xE7AA8, 0xC

	.global vtable_unk_080E7AB4
vtable_unk_080E7AB4:
	.incbin "baserom_us.gba", 0xE7AB4, 0x10

	.global vtable_unk_080E7AC4
vtable_unk_080E7AC4:
	.incbin "baserom_us.gba", 0xE7AC4, 0xC

	.global vtable_unk_080E7AD0
vtable_unk_080E7AD0:
	.incbin "baserom_us.gba", 0xE7AD0, 0x10

	.global vtable_unk_080E7AE0
vtable_unk_080E7AE0:
	.incbin "baserom_us.gba", 0xE7AE0, 0xC

	.global vtable_unk_080E7AEC
vtable_unk_080E7AEC:
	.incbin "baserom_us.gba", 0xE7AEC, 0x10

	.global vtable_unk_080E7AFC
vtable_unk_080E7AFC:
	.incbin "baserom_us.gba", 0xE7AFC, 0x10

	.global vtable_unk_080E7B0C
vtable_unk_080E7B0C:
	.incbin "baserom_us.gba", 0xE7B0C, 0x10

	.global vtable_unk_080E7B1C
vtable_unk_080E7B1C:
	.incbin "baserom_us.gba", 0xE7B1C, 0x10

	.global vtable_unk_080E7B2C
vtable_unk_080E7B2C:
	.incbin "baserom_us.gba", 0xE7B2C, 0x10

	.global vtable_unk_080E7B3C
vtable_unk_080E7B3C:
	.incbin "baserom_us.gba", 0xE7B3C, 0x10

	.global vtable_unk_080E7B4C
vtable_unk_080E7B4C:
	.incbin "baserom_us.gba", 0xE7B4C, 0x10

	.global vtable_unk_080E7B5C
vtable_unk_080E7B5C:
	.incbin "baserom_us.gba", 0xE7B5C, 0xC

	.global vtable_unk_080E7B68
vtable_unk_080E7B68:
	.incbin "baserom_us.gba", 0xE7B68, 0x10

	.global vtable_unk_080E7B78
vtable_unk_080E7B78:
	.incbin "baserom_us.gba", 0xE7B78, 0x10

	.global vtable_unk_080E7B88
vtable_unk_080E7B88:
	.incbin "baserom_us.gba", 0xE7B88, 0x10

	.global vtable_unk_080E7B98
vtable_unk_080E7B98:
	.incbin "baserom_us.gba", 0xE7B98, 0xC

	.global vtable_unk_080E7BA4
vtable_unk_080E7BA4:
	.incbin "baserom_us.gba", 0xE7BA4, 0x10

	.global vtable_unk_080E7BB4
vtable_unk_080E7BB4:
	.incbin "baserom_us.gba", 0xE7BB4, 0xC

	.global vtable_unk_080E7BC0
vtable_unk_080E7BC0:
	.incbin "baserom_us.gba", 0xE7BC0, 0x10

	.global vtable_unk_080E7BD0
vtable_unk_080E7BD0:
	.incbin "baserom_us.gba", 0xE7BD0, 0xC

	.global vtable_unk_080E7BDC
vtable_unk_080E7BDC:
	.incbin "baserom_us.gba", 0xE7BDC, 0x10

	.global vtable_unk_080E7BEC
vtable_unk_080E7BEC:
	.incbin "baserom_us.gba", 0xE7BEC, 0xC

	.global vtable_unk_080E7BF8
vtable_unk_080E7BF8:
	.incbin "baserom_us.gba", 0xE7BF8, 0x10

	.global vtable_unk_080E7C08
vtable_unk_080E7C08:
	.incbin "baserom_us.gba", 0xE7C08, 0xC

	.global vtable_unk_080E7C14
vtable_unk_080E7C14:
	.incbin "baserom_us.gba", 0xE7C14, 0xC

	.global vtable_unk_080E7C20
vtable_unk_080E7C20:
	.incbin "baserom_us.gba", 0xE7C20, 0x10

	.global vtable_unk_080E7C30
vtable_unk_080E7C30:
	.incbin "baserom_us.gba", 0xE7C30, 0x10

	.global vtable_unk_080E7C40
vtable_unk_080E7C40:
	.incbin "baserom_us.gba", 0xE7C40, 0xC

	.global vtable_unk_080E7C4C
vtable_unk_080E7C4C:
	.incbin "baserom_us.gba", 0xE7C4C, 0x10

	.global vtable_unk_080E7C5C
vtable_unk_080E7C5C:
	.incbin "baserom_us.gba", 0xE7C5C, 0xC

	.global vtable_unk_080E7C68
vtable_unk_080E7C68:
	.incbin "baserom_us.gba", 0xE7C68, 0x10

	.global vtable_unk_080E7C78
vtable_unk_080E7C78:
	.incbin "baserom_us.gba", 0xE7C78, 0xC

	.global vtable_unk_080E7C84
vtable_unk_080E7C84:
	.incbin "baserom_us.gba", 0xE7C84, 0x10

	.global vtable_unk_080E7C94
vtable_unk_080E7C94:
	.incbin "baserom_us.gba", 0xE7C94, 0xC

	.global vtable_unk_080E7CA0
vtable_unk_080E7CA0:
	.incbin "baserom_us.gba", 0xE7CA0, 0x10

	.global vtable_unk_080E7CB0
vtable_unk_080E7CB0:
	.incbin "baserom_us.gba", 0xE7CB0, 0xC

	.global vtable_unk_080E7CBC
vtable_unk_080E7CBC:
	.incbin "baserom_us.gba", 0xE7CBC, 0x10

	.global vtable_unk_080E7CCC
vtable_unk_080E7CCC:
	.incbin "baserom_us.gba", 0xE7CCC, 0xC

	.global vtable_unk_080E7CD8
vtable_unk_080E7CD8:
	.incbin "baserom_us.gba", 0xE7CD8, 0x10

	.global vtable_unk_080E7CE8
vtable_unk_080E7CE8:
	.incbin "baserom_us.gba", 0xE7CE8, 0xC

	.global vtable_unk_080E7CF4
vtable_unk_080E7CF4:
	.incbin "baserom_us.gba", 0xE7CF4, 0x10

	.global vtable_unk_080E7D04
vtable_unk_080E7D04:
	.incbin "baserom_us.gba", 0xE7D04, 0x10

	.global vtable_unk_080E7D14
vtable_unk_080E7D14:
	.incbin "baserom_us.gba", 0xE7D14, 0xC

	.global vtable_unk_080E7D20
vtable_unk_080E7D20:
	.incbin "baserom_us.gba", 0xE7D20, 0x10

	.global vtable_unk_080E7D30
vtable_unk_080E7D30:
	.incbin "baserom_us.gba", 0xE7D30, 0xC

	.global vtable_unk_080E7D3C
vtable_unk_080E7D3C:
	.incbin "baserom_us.gba", 0xE7D3C, 0x10

	.global vtable_unk_080E7D4C
vtable_unk_080E7D4C:
	.incbin "baserom_us.gba", 0xE7D4C, 0xC

	.global vtable_unk_080E7D58
vtable_unk_080E7D58:
	.incbin "baserom_us.gba", 0xE7D58, 0x10

	.global vtable_unk_080E7D68
vtable_unk_080E7D68:
	.incbin "baserom_us.gba", 0xE7D68, 0xC

	.global vtable_unk_080E7D74
vtable_unk_080E7D74:
	.incbin "baserom_us.gba", 0xE7D74, 0x10

	.global vtable_unk_080E7D84
vtable_unk_080E7D84:
	.incbin "baserom_us.gba", 0xE7D84, 0xC

	.global vtable_unk_080E7D90
vtable_unk_080E7D90:
	.incbin "baserom_us.gba", 0xE7D90, 0x10

	.global vtable_unk_080E7DA0
vtable_unk_080E7DA0:
	.incbin "baserom_us.gba", 0xE7DA0, 0xC

	.global vtable_unk_080E7DAC
vtable_unk_080E7DAC:
	.incbin "baserom_us.gba", 0xE7DAC, 0x10

	.global vtable_unk_080E7DBC
vtable_unk_080E7DBC:
	.incbin "baserom_us.gba", 0xE7DBC, 0xC

	.global vtable_unk_080E7DC8
vtable_unk_080E7DC8:
	.incbin "baserom_us.gba", 0xE7DC8, 0x10

	.global vtable_unk_080E7DD8
vtable_unk_080E7DD8:
	.incbin "baserom_us.gba", 0xE7DD8, 0xC

	.global vtable_unk_080E7DE4
vtable_unk_080E7DE4:
	.incbin "baserom_us.gba", 0xE7DE4, 0x10

	.global vtable_unk_080E7DF4
vtable_unk_080E7DF4:
	.incbin "baserom_us.gba", 0xE7DF4, 0x10C

	.global vtable_unk_080E7F00
vtable_unk_080E7F00:
	.incbin "baserom_us.gba", 0xE7F00, 0xC

	.global vtable_unk_080E7F0C
vtable_unk_080E7F0C:
	.incbin "baserom_us.gba", 0xE7F0C, 0x10C

	.global vtable_unk_080E8018
vtable_unk_080E8018:
	.incbin "baserom_us.gba", 0xE8018, 0x10

	.global vtable_unk_080E8028
vtable_unk_080E8028:
	.incbin "baserom_us.gba", 0xE8028, 0x104

	.global vtable_unk_080E812C
vtable_unk_080E812C:
	.incbin "baserom_us.gba", 0xE812C, 0x104

	.global vtable_unk_080E8230
vtable_unk_080E8230:
	.incbin "baserom_us.gba", 0xE8230, 0xC

	.global vtable_unk_080E823C
vtable_unk_080E823C:
	.incbin "baserom_us.gba", 0xE823C, 0x10

	.global vtable_unk_080E824C
vtable_unk_080E824C:
	.incbin "baserom_us.gba", 0xE824C, 0x10

	.global vtable_unk_080E825C
vtable_unk_080E825C:
	.incbin "baserom_us.gba", 0xE825C, 0xC

	.global vtable_unk_080E8268
vtable_unk_080E8268:
	.incbin "baserom_us.gba", 0xE8268, 0x10

	.global vtable_unk_080E8278
vtable_unk_080E8278:
	.incbin "baserom_us.gba", 0xE8278, 0x10

	.global vtable_unk_080E8288
vtable_unk_080E8288:
	.incbin "baserom_us.gba", 0xE8288, 0x10

	.global vtable_unk_080E8298
vtable_unk_080E8298:
	.incbin "baserom_us.gba", 0xE8298, 0x10

	.global vtable_unk_080E82A8
vtable_unk_080E82A8:
	.incbin "baserom_us.gba", 0xE82A8, 0x10

	.global vtable_unk_080E82B8
vtable_unk_080E82B8:
	.incbin "baserom_us.gba", 0xE82B8, 0x20

	.global vtable_unk_080E82D8
vtable_unk_080E82D8:
	.incbin "baserom_us.gba", 0xE82D8, 0xC

	.global vtable_unk_080E82E4
vtable_unk_080E82E4:
	.incbin "baserom_us.gba", 0xE82E4, 0x28

	.global vtable_unk_080E830C
vtable_unk_080E830C:
	.incbin "baserom_us.gba", 0xE830C, 0x10

	.global vtable_unk_080E831C
vtable_unk_080E831C:
	.incbin "baserom_us.gba", 0xE831C, 0x28

	.global vtable_unk_080E8344
vtable_unk_080E8344:
	.incbin "baserom_us.gba", 0xE8344, 0xC0

	.global vtable_unk_080E8404
vtable_unk_080E8404:
	.incbin "baserom_us.gba", 0xE8404, 0x3C

	.global vtable_unk_080E8440
vtable_unk_080E8440:
	.incbin "baserom_us.gba", 0xE8440, 0xC0

	.global vtable_unk_080E8500
vtable_unk_080E8500:
	.incbin "baserom_us.gba", 0xE8500, 0xC

	.global vtable_unk_080E850C
vtable_unk_080E850C:
	.incbin "baserom_us.gba", 0xE850C, 0x10

	.global vtable_unk_080E851C
vtable_unk_080E851C:
	.incbin "baserom_us.gba", 0xE851C, 0xC

	.global vtable_unk_080E8528
vtable_unk_080E8528:
	.incbin "baserom_us.gba", 0xE8528, 0x10

	.global vtable_unk_080E8538
vtable_unk_080E8538:
	.incbin "baserom_us.gba", 0xE8538, 0xC

	.global vtable_unk_080E8544
vtable_unk_080E8544:
	.incbin "baserom_us.gba", 0xE8544, 0x10

	.global vtable_unk_080E8554
vtable_unk_080E8554:
	.incbin "baserom_us.gba", 0xE8554, 0xC

	.global vtable_unk_080E8560
vtable_unk_080E8560:
	.incbin "baserom_us.gba", 0xE8560, 0x10

	.global vtable_unk_080E8570
vtable_unk_080E8570:
	.incbin "baserom_us.gba", 0xE8570, 0xC

	.global vtable_unk_080E857C
vtable_unk_080E857C:
	.incbin "baserom_us.gba", 0xE857C, 0xC

	.global vtable_unk_080E8588
vtable_unk_080E8588:
	.incbin "baserom_us.gba", 0xE8588, 0xC

	.global vtable_unk_080E8594
vtable_unk_080E8594:
	.incbin "baserom_us.gba", 0xE8594, 0xC

	.global vtable_unk_080E85A0
vtable_unk_080E85A0:
	.incbin "baserom_us.gba", 0xE85A0, 0xC

	.global vtable_unk_080E85AC
vtable_unk_080E85AC:
	.incbin "baserom_us.gba", 0xE85AC, 0x10

	.global vtable_unk_080E85BC
vtable_unk_080E85BC:
	.incbin "baserom_us.gba", 0xE85BC, 0x10

	.global vtable_unk_080E85CC
vtable_unk_080E85CC:
	.incbin "baserom_us.gba", 0xE85CC, 0x10

	.global vtable_unk_080E85DC
vtable_unk_080E85DC:
	.incbin "baserom_us.gba", 0xE85DC, 0xC

	.global vtable_unk_080E85E8
vtable_unk_080E85E8:
	.incbin "baserom_us.gba", 0xE85E8, 0x28

    .endif
