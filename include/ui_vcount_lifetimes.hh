#ifndef UI_VCOUNT_LIFETIMES_HH
#define UI_VCOUNT_LIFETIMES_HH

#include "ui_vcount.hh"

#pragma interface "ui_vcount_lifetimes.hh"

inline UiVCountContextScope::~UiVCountContextScope()
{
    gUiVCountContext = previous;
}


#endif // UI_VCOUNT_LIFETIMES_HH
