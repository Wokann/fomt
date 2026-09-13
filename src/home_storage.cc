#include "home_storage.hh"

// This entire physical ROM block is text (including the original runtime
// strings), so one regional include preserves its native object order.
#include FOMT_TEXT_INCLUDE(home_storage.cc)
