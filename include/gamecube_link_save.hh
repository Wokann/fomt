#ifndef GAMECUBE_LINK_SAVE_HH
#define GAMECUBE_LINK_SAVE_HH

#include "prelude.h"

struct GameStateSaveImage;

// The wire format stores encoded character indices, not ROM text pointers.
// The three names and milestone bytes have protocol-defined capacities.
#if defined(REGION_JP)
enum { GAMECUBE_LINK_ENCODED_NAME_SIZE = 8 };
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
enum { GAMECUBE_LINK_ENCODED_NAME_SIZE = 13 };
#endif

struct PACKED GameCubeLinkOutgoingPacket {
    u8 farm_name[GAMECUBE_LINK_ENCODED_NAME_SIZE];
    u8 player_name[GAMECUBE_LINK_ENCODED_NAME_SIZE];
    u8 child_name[GAMECUBE_LINK_ENCODED_NAME_SIZE];
    u8 milestones[4];
};

struct PACKED GameCubeLinkIncomingPacket {
    // Decoded into the three 16-byte SRAM name fields at record +14/+24/+34.
    u8 names[3][GAMECUBE_LINK_ENCODED_NAME_SIZE];
    u8 milestones[8];
};

// Native allocation/destruction owns the two packet buffers. The save image
// is borrowed. Constructor expansion proves 49 one-byte milestone flags;
// the final three bytes are the normal padding of this word-aligned object.
struct GameCubeLinkSaveData {
    GameCubeLinkSaveData(GameStateSaveImage * image);
    ~GameCubeLinkSaveData();
    GameStateSaveImage * save;
    GameCubeLinkOutgoingPacket * outgoing;
    GameCubeLinkIncomingPacket * incoming;
    u32 unk_0C; // Copied from saved link record +0 before the transfer.
    u32 unk_10; // Copied from saved link record +4 before the transfer.
    u32 unk_14; // Written back to saved link record +4 on receipt.
    bool received_milestones[49];
};

typedef char GameCubeLinkOutgoingPacketSizeCheck[sizeof(GameCubeLinkOutgoingPacket) == 3 * GAMECUBE_LINK_ENCODED_NAME_SIZE + 4 ? 1 : -1];
typedef char GameCubeLinkIncomingPacketSizeCheck[sizeof(GameCubeLinkIncomingPacket) == 3 * GAMECUBE_LINK_ENCODED_NAME_SIZE + 8 ? 1 : -1];
typedef char GameCubeLinkSaveDataFlagsCheck[offsetof(GameCubeLinkSaveData, received_milestones) == 0x18 ? 1 : -1];
typedef char GameCubeLinkSaveDataSizeCheck[sizeof(GameCubeLinkSaveData) == 0x4C ? 1 : -1];

EXTERN_C

void PrepareGameCubeLinkOutgoingData(GameCubeLinkSaveData * data);
u32 GetGameCubeLinkLocalGameCode(GameCubeLinkSaveData const * data);
u32 GetGameCubeLinkRemoteGameCode(GameCubeLinkSaveData const * data);
u32 * GetGameCubeLinkRecordWords(GameCubeLinkSaveData * data);
GameCubeLinkOutgoingPacket * GetGameCubeLinkOutgoingPacket(GameCubeLinkSaveData * data);
u32 GetGameCubeLinkOutgoingSize(GameCubeLinkSaveData const * data);
GameCubeLinkIncomingPacket * GetGameCubeLinkIncomingPacket(GameCubeLinkSaveData * data);
u32 GetGameCubeLinkIncomingSize(GameCubeLinkSaveData const * data);
u32 GetGameCubeLinkReceivedRecordValue(GameCubeLinkSaveData const * data);
void DecodeGameCubeLinkReceivedName0(GameCubeLinkSaveData const * data, char * output);
void DecodeGameCubeLinkReceivedName1(GameCubeLinkSaveData const * data, char * output);
void DecodeGameCubeLinkReceivedName2(GameCubeLinkSaveData const * data, char * output);
u8 const * GetGameCubeLinkReceivedMilestones(GameCubeLinkSaveData const * data);
void CopyGameCubeLinkPayloadBytes(GameCubeLinkSaveData const * data, u8 * output, u8 const * input, u32 count);
void EncodeGameCubeLinkName(GameCubeLinkSaveData const * data, u8 * output, char const * input);
void DecodeGameCubeLinkName(GameCubeLinkSaveData const * data, char * output, u8 const * input);

EXTERN_C_END

extern "C" {
struct LinkCommunicationGameCode
{
    u32 game_code;
    u32 unk_04;
};

extern LinkCommunicationGameCode const gLinkCommunicationGameCodeA4N;
extern LinkCommunicationGameCode const gLinkCommunicationGameCodeGYW;
}

#if defined(REGION_JP)
extern u16 const gLinkCommunicationCharacterCodeTable[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern u8 const gLinkCommunicationCharacterCodeTable[];
#endif

// These legacy entry copies decode the same three incoming-name fields.
EXTERN_C
void func_08094914(GameCubeLinkSaveData const * data, char * output);
void func_08094920(GameCubeLinkSaveData const * data, char * output);
void func_08094930(GameCubeLinkSaveData const * data, char * output);
EXTERN_C_END

#endif // GAMECUBE_LINK_SAVE_HH
