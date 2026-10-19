#ifndef LINK_COMMUNICATION_DATA_HH
#define LINK_COMMUNICATION_DATA_HH

#include "prelude.h"

extern "C" {

// These fields are selected by the native Link Communication menu.  Their
// layout is proven, but their individual meanings are not decoded yet.
struct LinkCommunicationDataRecord
{
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
};

struct LinkCommunicationGameCode
{
    u32 game_code;
    u32 unk_04;
};

extern LinkCommunicationDataRecord const gUnk_081007AC[5];
extern LinkCommunicationDataRecord const gUnk_081007D4[5];
extern LinkCommunicationDataRecord const gUnk_081007FC[5];
extern LinkCommunicationDataRecord const gUnk_08100824[5];
extern LinkCommunicationDataRecord const gUnk_0810084C[5];
extern LinkCommunicationDataRecord const gUnk_08100874[5];
extern LinkCommunicationDataRecord const gUnk_0810089C[5];
extern LinkCommunicationDataRecord const gUnk_081008C4[5];
extern LinkCommunicationDataRecord const gUnk_081008EC[5];
extern LinkCommunicationDataRecord const gUnk_08100914[5];
extern LinkCommunicationDataRecord const gUnk_0810093C[5];
extern LinkCommunicationDataRecord const gUnk_08100964[5];
extern LinkCommunicationDataRecord const gUnk_0810098C[5];
extern LinkCommunicationDataRecord const gUnk_081009B4[5];
extern LinkCommunicationDataRecord const gUnk_081009DC[5];
extern LinkCommunicationDataRecord const gUnk_08100A04[5];

extern char const gCppRuntimeBadAlloc_LinkCommunication[];
extern LinkCommunicationGameCode const gLinkCommunicationGameCodeA4N;
extern LinkCommunicationGameCode const gLinkCommunicationGameCodeGYW;
extern char const gCppRuntimeBadAlloc_LinkCommunicationA4N[];
extern char const gCppRuntimeBadAlloc_LinkCommunicationGYW[];

}

// A serialized two-byte prefix and two payload bytes. The native API
// exposes both halfword and byte views of the prefix. Its protocol
// meaning is still unknown; do not impose halfword alignment on the record.
struct PACKED LinkCommunicationValue
{
    union PACKED {
        u16 word;
        u8 bytes[2];
    } prefix;
    u8 value[2];

    void Set(u8 first, u16 word);
    void Set(u8 first, u8 second, u8 const * bytes);
    u8 GetByte0() const;
    u16 GetValue() const;
    u8 GetByte1() const;
    void CopyValue(u8 * destination) const;
    u16 GetPrefix() const;
    bool HasValue(u8 const * bytes) const;
};

typedef char LinkCommunicationValue_size[sizeof(LinkCommunicationValue) == 4 ? 1 : -1];
typedef char LinkCommunicationValue_prefix[offsetof(LinkCommunicationValue, prefix) == 0 ? 1 : -1];

typedef char LinkCommunicationValue_prefix_size[sizeof(((LinkCommunicationValue *)0)->prefix) == 2 ? 1 : -1];

typedef char LinkCommunicationValue_alignment[__alignof__(LinkCommunicationValue) == 1 ? 1 : -1];
typedef char LinkCommunicationValue_value[offsetof(LinkCommunicationValue, value) == 2 ? 1 : -1];

extern char const gText_LinkCommunication_Waiting[];
extern char const gText_LinkCommunication_SendingGameData[];
extern char const gText_LinkCommunication_TestingConnection[];
extern char const gText_LinkCommunication_CannotResendPreviousData[];
extern char const gText_LinkCommunication_ProceedQuestion[];
extern char const gText_LinkCommunication_Yes[];
extern char const gText_LinkCommunication_No[];
extern char const gText_LinkCommunication_WaitingForOtherPlayer[];
extern char const gText_LinkCommunication_NowSendingData[];
extern char const gText_LinkCommunication_DataExchangeFailed[];
extern char const gText_LinkCommunication_QuitCommunication[];
extern char const gText_LinkCommunication_OtherPlayerCanceled[];
extern char const gText_LinkCommunication_IncompatibleGameData[];
extern char const gText_LinkCommunication_ExchangeRestriction[];
extern char const gText_LinkCommunication_ActionQuestion[];
#if defined(REGION_DE)
extern char const gText_LinkCommunication_ActionYes[];
extern char const gText_LinkCommunication_ActionNo[];
#endif
extern char const gText_LinkCommunication_Declined[];
extern char const gText_LinkCommunication_Complete[];

#if defined(REGION_JP)
extern u16 const gLinkCommunicationCharacterCodeTable[];
#else
extern u8 const gLinkCommunicationCharacterCodeTable[];
#endif

#endif // LINK_COMMUNICATION_DATA_HH
