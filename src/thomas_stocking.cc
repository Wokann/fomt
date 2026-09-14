#include "thomas_stocking.hh"

EXTERN_C

// func_08043458 samples (rand() >> 4) & 0xFF against these five weights.
// It uses an inclusive comparison and subtracts the rejected byte value.
u8 const gThomasStockingGiftSelectionWeights[5] ALIGN(1) = {
    125,
    43,
    43,
    43,
    1,
};

EXTERN_C_END
