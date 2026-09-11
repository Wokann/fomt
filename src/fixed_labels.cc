#include "fixed_labels.hh"

// The padding is an original ROM field between independent labels, not part
// of either string.  Regional text fragments are included at their physical
// ROM positions in this owning module.
#if defined(REGION_JP)
#define FOMT_FIXED_LABELS_TEXT_MONEYBAGS
#include FOMT_TEXT_INCLUDE(fixed_labels.cc)
#undef FOMT_FIXED_LABELS_TEXT_MONEYBAGS
u8 const gFixedLabelsPaddingBeforeUnnamedSetting[] = {
    0, 0, 0, 0,
};
#define FOMT_FIXED_LABELS_TEXT_UNNAMED_SETTING
#include FOMT_TEXT_INCLUDE(fixed_labels.cc)
#undef FOMT_FIXED_LABELS_TEXT_UNNAMED_SETTING
#else
#define FOMT_FIXED_LABELS_TEXT_MONEYBAGS
#include FOMT_TEXT_INCLUDE(fixed_labels.cc)
#undef FOMT_FIXED_LABELS_TEXT_MONEYBAGS
u8 const gFixedLabelsPaddingBeforeUnnamedSetting[] = {
    0, 0, 0, 0,
};
#define FOMT_FIXED_LABELS_TEXT_UNNAMED_SETTING
#include FOMT_TEXT_INCLUDE(fixed_labels.cc)
#undef FOMT_FIXED_LABELS_TEXT_UNNAMED_SETTING
#endif

#define FOMT_FIXED_LABELS_TEXT_RUNTIME
#include "data/text/common/fixed_labels.cc"
#undef FOMT_FIXED_LABELS_TEXT_RUNTIME
