    .ifdef REGION_JP
    @ JP revision 0 virtual-table region.
    @
    @ AScene and AUnk_0800080C are emitted from their ordinary C++ class
    @ declarations. The remaining tables stay in this static ROM range.

    .section .rodata
    .set jp_vtables_start, jp_vtables_raw_start - 0x8B8
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
    .global vtable_unk_080E7928
    .set vtable_unk_080E7928, jp_vtables_start + 0x1F5C
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

jp_vtables_raw_start:
    .incbin "baserom_jp.gba", 0xE56C4, (0xE6C50 - 0xE56C4)

    .section .rodata.080E6D68
jp_vtables_raw_after_script_engine_adjacent:
    .incbin "baserom_jp.gba", 0xE6D68, (0xE6D74 - 0xE6D68)

    .section .rodata.080E6E98
jp_vtables_raw_after_vtable_7a48:
    .incbin "baserom_jp.gba", 0xE6E98, (0xE7A40 - 0xE6E98)
    .else

    .section .rodata

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

	.section .rodata.080E7928

	.global vtable_unk_080E7928
vtable_unk_080E7928:
	.incbin "baserom_us.gba", 0xE7928, 0xC

	.section .rodata.080E7A58

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
