# Label-bound IndexedResourceArchive inventory

This generated inventory examines only DE `.incbin` records already
bounded by the project, then validates the native archive header. It is not
a blind ROM scan and does not claim that every parseable byte sequence is an
image resource. `different` means that the complete DE archive payload does
not occur verbatim in that regional ROM and therefore requires a separate
regional pipeline before it can be treated as shared.

| Label | JP | US | EU | DE | Length | Header counts | Entries | Source status |
| --- | --- | --- | --- | --- | ---: | --- | ---: | --- |
| `gUnk_08527094` | `0x2AD1F0` | `0x527094` | `0x5270F0` | `0x2AE130` | `0x1A4` | 4, 8, 7, 4, 1, 0 | 8 | unmanaged, four-region identical |
| `gUnk_08667060` | `0x3ED1BC` | `0x667060` | `0x6670BC` | `0x3EE0FC` | `0x840` | 3, 16, 3, 52, 2, 0 | 16 | rebuild: `graphics/small_companion_archive/` |
| `gUnk_086678A0` | `0x3ED9FC` | `0x6678A0` | `0x6678FC` | `0x3EE93C` | `0x12848` | 493, 500, 101, 1624, 342, 0 | 532 | rebuild: `graphics/common_resource_archive/` |
| `gUnk_086F2FAC` | `0x479108` | `0x6F2FAC` | `0x6F3008` | `0x47A048` | `0x31FC` | 4, 16, 2, 384, 4, 0 | 16 | rebuild: `graphics/shared_resource_086f2fac/` |
| `gUnk_086FAA80` | `0x480BDC` | `0x6FAA80` | `0x6FAADC` | `0x481B1C` | `0x584` | 3, 9, 1, 36, 1, 0 | 9 | rebuild: `graphics/shared_resource_086faa80/` |
| `gUnk_0871D51C` | different | different | different | `0x4A45B8` | `0x13BC` | 11, 33, 1, 132, 1, 0 | 47 | regional payload differs |
| `gUnk_0871E7A8` | `0x4A4910` | `0x71E7A8` | `0x71E804` | `0x4A5974` | `0x504` | 8, 8, 1, 32, 1, 0 | 8 | rebuild: `graphics/ui/menu_resource_archive/` |
| `gUnk_0871ECAC` | `0x4A4E14` | `0x71ECAC` | `0x71ED08` | `0x4A5E78` | `0x128` | 1, 5, 1, 4, 1, 0 | 4 | unmanaged, four-region identical |
| `gUnk_0871EDD4` | `0x4A4F3C` | `0x71EDD4` | `0x71EE30` | `0x4A5FA0` | `0x12C` | 1, 5, 1, 4, 1, 0 | 5 | unmanaged, four-region identical |
| `gUnk_0871EF00` | `0x4A5068` | `0x71EF00` | `0x71EF5C` | `0x4A60CC` | `0x6EA0` | 27, 102, 1, 768, 46, 0 | 124 | rebuild: `graphics/large_resource_archive/` |
| `gUnk_08725DA0` | `0x4ABF08` | `0x725DA0` | `0x725DFC` | `0x4ACF6C` | `0xF2C` | 6, 6, 20, 109, 2, 0 | 6 | rebuild: `graphics/shared_resource_08725da0/` |
| `gUnk_08726CCC` | `0x4ACE34` | `0x726CCC` | `0x726D28` | `0x4ADE98` | `0x69C` | 1, 1, 9, 48, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_08727368` | `0x4AD4D0` | `0x727368` | `0x7273C4` | `0x4AE534` | `0x70C` | 3, 21, 68, 22, 1, 0 | 37 | unmanaged, four-region identical |
| `gUnk_08727A74` | `0x4ADBDC` | `0x727A74` | `0x727AD0` | `0x4AEC40` | `0x794` | 1, 1, 36, 49, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_08728208` | different | `0x728208` | `0x728264` | `0x4AF3D4` | `0x118` | 1, 3, 3, 4, 1, 0 | 4 | regional payload differs |
| `gUnk_08728320` | `0x4AE488` | `0x728320` | `0x72837C` | `0x4AF4EC` | `0x105C` | 7, 21, 32, 107, 1, 0 | 21 | unmanaged, four-region identical |
| `gUnk_0872937C` | `0x4AF4E4` | `0x72937C` | `0x7293D8` | `0x4B0548` | `0xE4` | 1, 3, 1, 3, 1, 0 | 3 | unmanaged, four-region identical |
| `gUnk_08729460` | `0x4AF5C8` | `0x729460` | `0x7294BC` | `0x4B062C` | `0x2A04` | 1, 3, 9, 330, 1, 0 | 3 | unmanaged, four-region identical |
| `gUnk_0872BE64` | different | different | different | `0x4B3030` | `0x874` | 1, 1, 4, 64, 1, 0 | 1 | regional payload differs |
| `gUnk_0872DE44` | different | different | different | `0x4B5118` | `0x10CC` | 27, 27, 9, 110, 1, 0 | 27 | regional payload differs |
| `gUnk_0872EE78` | `0x4B4FE0` | `0x72EE78` | `0x72EED4` | `0x4B61E4` | `0x2A4` | 4, 4, 1, 16, 1, 0 | 4 | unmanaged, four-region identical |
| `gUnk_08731B40` | `0x4B7CA8` | `0x731B40` | `0x731B9C` | `0x4B8EAC` | `0x6604` | 20, 20, 13, 794, 3, 0 | 20 | unmanaged, four-region identical |
| `gUnk_08738144` | different | different | different | `0x4BF4B0` | `0x994` | 3, 3, 2, 72, 1, 0 | 3 | regional payload differs |
| `gUnk_0873A6E8` | different | different | different | `0x4C1A54` | `0x76C` | 1, 1, 3, 56, 1, 0 | 1 | regional payload differs |
| `gUnk_0873AE54` | `0x4C0FBC` | `0x73AE54` | `0x73AEB0` | `0x4C21C0` | `0x174` | 2, 2, 1, 8, 1, 0 | 2 | unmanaged, four-region identical |
| `gUnk_0873AFC8` | `0x4C1130` | `0x73AFC8` | `0x73B024` | `0x4C2334` | `0xE5C` | 1, 1, 9, 110, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_0873CCB4` | `0x4C2E1C` | `0x73CCB4` | `0x73CD10` | `0x4C4020` | `0x1F8` | 1, 2, 2, 12, 1, 0 | 2 | unmanaged, four-region identical |
| `gUnk_0873CEAC` | `0x4C3014` | `0x73CEAC` | `0x73CF08` | `0x4C4218` | `0xE4` | 1, 1, 2, 4, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_0873CF90` | `0x4C30F8` | `0x73CF90` | `0x73CFEC` | `0x4C42FC` | `0x2A4` | 4, 4, 1, 16, 1, 0 | 4 | unmanaged, four-region identical |
| `gUnk_0873D234` | `0x4C339C` | `0x73D234` | `0x73D290` | `0x4C45A0` | `0x3C8` | 3, 6, 1, 24, 1, 0 | 6 | unmanaged, four-region identical |
| `gUnk_0873D5FC` | `0x4C3764` | `0x73D5FC` | `0x73D658` | `0x4C4968` | `0xDC` | 1, 1, 1, 4, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_0873D6D8` | different | different | different | `0x4C4A44` | `0x874` | 1, 1, 4, 64, 1, 0 | 1 | regional payload differs |
| `gUnk_0873DE44` | `0x4C3FAC` | `0x73DE44` | `0x73DEA0` | `0x4C52B8` | `0x76C` | 1, 1, 3, 56, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_0873E5B0` | `0x4C4718` | `0x73E5B0` | `0x73E60C` | `0x4C5A24` | `0x76C` | 1, 1, 3, 56, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_0873ED1C` | `0x4C4E84` | `0x73ED1C` | `0x73ED78` | `0x4C6190` | `0x6AC` | 3, 10, 11, 41, 2, 0 | 11 | unmanaged, four-region identical |
| `gUnk_087401A4` | `0x4C630C` | `0x7401A4` | `0x740200` | `0x4C7618` | `0x2B0` | 1, 4, 4, 16, 1, 0 | 4 | unmanaged, four-region identical |
| `gUnk_08740454` | `0x4C65BC` | `0x740454` | `0x7404B0` | `0x4C78C8` | `0x14C` | 1, 3, 2, 6, 1, 0 | 3 | unmanaged, four-region identical |
| `gUnk_087405A0` | `0x4C6708` | `0x7405A0` | `0x7405FC` | `0x4C7A14` | `0x368` | 2, 1, 2, 24, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_08740908` | `0x4C6A70` | `0x740908` | `0x740964` | `0x4C7D7C` | `0xDC` | 1, 1, 1, 4, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_087409E4` | `0x4C6B4C` | `0x7409E4` | `0x740A40` | `0x4C7E58` | `0x1010` | 1, 3, 18, 120, 1, 0 | 4 | unmanaged, four-region identical |
| `gUnk_0874EE38` | `0x4D5354` | `0x74EE38` | `0x74EE94` | `0x4D62A4` | `0xDC` | 1, 1, 1, 4, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_0874F34C` | different | different | different | `0x4D67B8` | `0x1444` | 22, 22, 7, 140, 3, 0 | 22 | regional payload differs |
| `gUnk_087506E0` | `0x4D668C` | `0x7506E0` | `0x75073C` | `0x4D7BFC` | `0x56C` | 4, 4, 10, 36, 1, 0 | 4 | unmanaged, four-region identical |
| `gUnk_0875352C` | `0x4D94D8` | `0x75352C` | `0x753588` | `0x4DAA48` | `0xDC` | 1, 1, 1, 4, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_08753608` | `0x4D95B4` | `0x753608` | `0x753664` | `0x4DAB24` | `0xDC` | 1, 1, 1, 4, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_087536E4` | `0x4D9690` | `0x7536E4` | `0x753740` | `0x4DAC00` | `0xEC` | 2, 4, 3, 2, 1, 0 | 4 | unmanaged, four-region identical |
| `gUnk_087537D0` | `0x4D977C` | `0x7537D0` | `0x75382C` | `0x4DACEC` | `0xEA4` | 20, 40, 11, 73, 13, 0 | 40 | rebuild: `graphics/ui/farm_status/resource_archive/` |
| `gUnk_08754674` | `0x4DA620` | `0x754674` | `0x7546D0` | `0x4DBB90` | `0x598` | 1, 3, 3, 40, 1, 0 | 4 | rebuild: `graphics/ui/cooking_resource_archive/` |
| `gUnk_08754C0C` | `0x4DABB8` | `0x754C0C` | `0x754C68` | `0x4DC128` | `0x548` | 2, 4, 2, 36, 2, 0 | 5 | rebuild: `graphics/ui/small_resource_archive/` |
| `gUnk_08755154` | `0x4DB100` | `0x755154` | `0x7551B0` | `0x4DC670` | `0xDC` | 1, 1, 1, 4, 1, 0 | 1 | unmanaged, four-region identical |
| `gUnk_0875B444` | different | `0x75B444` | `0x75B4A0` | `0x4E2960` | `0x3D4` | 6, 6, 1, 24, 1, 0 | 6 | regional payload differs |

Generated records: 51 (10 rebuilt, 32 unmanaged but four-region identical, 9 regionally different). Regenerate with:

```console
make indexed-resource-archive-inventory
```
