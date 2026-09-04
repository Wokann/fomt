    .ifdef REGION_JP

    .section .rodata.item_tool
    .global gToolInfo
gToolInfo:
    .incbin "baserom_jp.gba", 0xE9EEC, (0xEA2B8 - 0xE9EEC)

    .section .rodata.item_food
    .global gFoodInfo
gFoodInfo:
    .incbin "baserom_jp.gba", 0xED3D8, (0xEDE88 - 0xED3D8)

    .section .rodata.item_article
    .global gArticleInfo
gArticleInfo:
    .incbin "baserom_jp.gba", 0xEF738, (0xEFBAC - 0xEF738)

    .section .rodata.item_product
    .global gProductInfo
gProductInfo:
    .incbin "baserom_jp.gba", 0xEFBAC, (0xEFD48 - 0xEFBAC)

    .endif
