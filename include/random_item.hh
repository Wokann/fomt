#ifndef RANDOM_ITEM_HH
#define RANDOM_ITEM_HH

#include "prelude.h"

#define RANDOM_ITEM_CANDIDATE_COUNT 59
#define RANDOM_ITEM_SELECTION_CONTEXT_COUNT 4
#define RANDOM_ITEM_SELECTION_SLOT_COUNT 7

// Native selection reads a signed slot from the selected context and uses the
// first two bytes as an inclusive random range.
struct RandomItemCandidateConfiguration
{
    u8 minimum_value;
    u8 maximum_value;
    i8 selection_by_context[RANDOM_ITEM_SELECTION_CONTEXT_COUNT][RANDOM_ITEM_SELECTION_SLOT_COUNT];
    u8 unknown_1E;
    u8 unknown_1F;
};

extern u8 const gRandomItemSelectionWeights[7][5];
extern RandomItemCandidateConfiguration const
    gRandomItemCandidateConfigurations[RANDOM_ITEM_CANDIDATE_COUNT];
extern char const gCppRuntimeBadAlloc_RandomItemCandidateConfigurations[];

#endif // RANDOM_ITEM_HH
