#ifndef BACHELORETTE_MARRIAGE_CANDIDATE_DATA_HH
#define BACHELORETTE_MARRIAGE_CANDIDATE_DATA_HH

#include "prelude.h"
#include "fomt_constants.mary.h"

enum
{
    MARRIAGE_CANDIDATE_CHARACTER_COUNT = 6,
};

// Native marriage-condition code traverses these MaryCharacterId values in
// this fixed order.
extern u32 const gMarriageCandidateCharacterIds[MARRIAGE_CANDIDATE_CHARACTER_COUNT];

#endif // BACHELORETTE_MARRIAGE_CANDIDATE_DATA_HH
