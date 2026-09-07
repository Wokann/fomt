#include "item_status_text.hh"

char const gText_ItemStatus_BasketName[] =
    "かご\r\n\x00";

char const gText_ItemStatus_BasketDescription[] =
    "出荷物をためておける。\r\n\x00\x00\x00";

char const gText_ItemStatus_BasketHoldingSuffix[] =
    "個入ってる。\x00\x00\x00";

char const gText_ItemStatus_WrappedAsPresent[] =
    "を\r\n"
    "プレゼント用に包んでもらった\r\n"
    "もの。\x00\x00\x00";

char const * const gItemStatusWrappedAsPresentTextRef =
    gText_ItemStatus_WrappedAsPresent;
