#include "pure_virtual.h"

// The original runtime hook returns immediately, without trapping or aborting.

void __pure_virtual(void) {}
