#ifndef ANIMAL_MEMORIAL_HH
#define ANIMAL_MEMORIAL_HH

#include "prelude.h"
#include "fomt_constants.hh"
#include "utility/fixed_str.hh"

struct GameSceneState;

// Append matching chickens, cows, then sheep without clearing the prefix.
// Keep the original 899-byte content limit and wait after each three names.
// The final partial group also receives a wait control; empty lists add none.
EXTERN_C
void AppendAnimalMemorialNames(GameSceneState * state,
    MaryLivestockLifeState life_state, FixedStr<899> & output);
EXTERN_C_END

#endif // ANIMAL_MEMORIAL_HH
