#ifndef FIELD_ITEM_DATA_HH
#define FIELD_ITEM_DATA_HH

#include "field.hh"

struct Unk_081043BCRecord
{
    u32 value_00;
    u32 value_04;
    i16 x;
    i16 y;
};

extern Unk_081043BCRecord const gUnk_081043BC[];
extern char const gCppRuntimeBadAlloc_FieldItemRecordsTrailer[];

#endif // FIELD_ITEM_DATA_HH
