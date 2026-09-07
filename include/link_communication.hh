#ifndef LINK_COMMUNICATION_HH
#define LINK_COMMUNICATION_HH

#include "prelude.h"

EXTERN_C

// These fields are selected by the native Link Communication menu.  Their
// layout is proven, but their individual meanings are not decoded yet.
struct LinkCommunicationDataRecord
{
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
};

enum
{
    LINK_COMMUNICATION_DATA_GROUP_SIZE = 5,
};

extern LinkCommunicationDataRecord const gUnk_081007AC[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_081007D4[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_081007FC[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_08100824[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_0810084C[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_08100874[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_0810089C[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_081008C4[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_081008EC[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_08100914[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_0810093C[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_08100964[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_0810098C[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_081009B4[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_081009DC[LINK_COMMUNICATION_DATA_GROUP_SIZE];
extern LinkCommunicationDataRecord const gUnk_08100A04[LINK_COMMUNICATION_DATA_GROUP_SIZE];

extern char const gCppRuntimeBadAlloc_LinkCommunication[];

EXTERN_C_END

#endif // LINK_COMMUNICATION_HH
