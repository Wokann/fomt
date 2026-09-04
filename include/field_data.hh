#ifndef FIELD_DATA_HH
#define FIELD_DATA_HH

#include "field.hh"

// One entry for each FieldPlot type.  The first pointer selects a contiguous
// group of render records; the next five bytes select a record for states 2-6.
struct FieldPlotTypeDefinition
{
    /* +00 */ Unk_Something const * render_variants;
    /* +04 */ u8 state_2_variant_index;
    /* +05 */ u8 state_3_variant_index;
    /* +06 */ u8 state_4_variant_index;
    /* +07 */ u8 state_5_variant_index;
    /* +08 */ u8 state_6_variant_index;
    /* +09 */ u8 reserved_variant_index;
    /* +0A */ u16 result_item_id;
};

extern FieldPlotTypeDefinition const gFieldPlotTypeDefinitions[39];

#endif // FIELD_DATA_HH
