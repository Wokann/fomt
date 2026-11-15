#include "config.h"
#include "gamecube_link_save.hh"
#include "game_state.hh"

GameCubeLinkSaveData::GameCubeLinkSaveData(GameStateSaveImage * image)
    : save(image)
{
    outgoing = reinterpret_cast<GameCubeLinkOutgoingPacket *>(new u8[GetGameCubeLinkOutgoingSize(this)]);
    incoming = reinterpret_cast<GameCubeLinkIncomingPacket *>(new u8[GetGameCubeLinkIncomingSize(this)]);
    for (int i = 0; i < static_cast<int>(ARRAY_COUNT(received_milestones)); ++i) {
        GameStateLinkRecord const & record = save->link_record;
        int byte_index = i / 8;
        int bit_index = i % 8;
        int bits = record.received_milestones[byte_index];
        bool received = ((bits >> bit_index) & 1) != 0;
        received_milestones[i] = received;
    }
}

GameCubeLinkSaveData::~GameCubeLinkSaveData()
{
    delete[] reinterpret_cast<u8 *>(outgoing);
    delete[] reinterpret_cast<u8 *>(incoming);
}

void PrepareGameCubeLinkOutgoingData(GameCubeLinkSaveData * data)
{
    GameCubeLinkOutgoingPacket * packet = data->outgoing;
    GameStateLinkRecord const & record = data->save->link_record;
    u32 first = record.unk_00;
    u32 second = record.unk_04;
    char const * farm = data->save->farm.GetName();
    char const * player = data->save->farmer.GetName();
    char const * child = data->save->npcs.GetChild()->GetName();
    u8 const * milestones = data->save->link_record.local_milestones;
    data->unk_0C = first;
    data->unk_10 = second;
    EncodeGameCubeLinkName(data, packet->farm_name, farm);
    EncodeGameCubeLinkName(data, packet->player_name, player);
    EncodeGameCubeLinkName(data, packet->child_name, child);
    CopyGameCubeLinkPayloadBytes(data, packet->milestones, milestones, sizeof(packet->milestones));
}

u32 GetGameCubeLinkLocalGameCode(GameCubeLinkSaveData const *)
{
    return gLinkCommunicationGameCodeA4N.game_code;
}

u32 GetGameCubeLinkRemoteGameCode(GameCubeLinkSaveData const *)
{
    return gLinkCommunicationGameCodeGYW.game_code;
}

extern "C" u32 * func_080948F8(GameCubeLinkSaveData * data)
{
    return &data->unk_0C;
}

u32 * GetGameCubeLinkRecordWords(GameCubeLinkSaveData * data)
{
    return &data->unk_0C;
}

GameCubeLinkOutgoingPacket * GetGameCubeLinkOutgoingPacket(GameCubeLinkSaveData * data)
{
    return data->outgoing;
}

u32 GetGameCubeLinkOutgoingSize(GameCubeLinkSaveData const *)
{
    return sizeof(GameCubeLinkOutgoingPacket);
}

GameCubeLinkIncomingPacket * GetGameCubeLinkIncomingPacket(GameCubeLinkSaveData * data)
{
    return data->incoming;
}

u32 GetGameCubeLinkIncomingSize(GameCubeLinkSaveData const *)
{
    return sizeof(GameCubeLinkIncomingPacket);
}

u32 GetGameCubeLinkReceivedRecordValue(GameCubeLinkSaveData const * data)
{
    return data->unk_14;
}

void func_08094914(GameCubeLinkSaveData const * data, char * output)
{
    DecodeGameCubeLinkName(data, output, data->incoming->names[0]);
}

void func_08094920(GameCubeLinkSaveData const * data, char * output)
{
    DecodeGameCubeLinkName(data, output, data->incoming->names[1]);
}

void func_08094930(GameCubeLinkSaveData const * data, char * output)
{
    DecodeGameCubeLinkName(data, output, data->incoming->names[2]);
}

void DecodeGameCubeLinkReceivedName0(GameCubeLinkSaveData const * data, char * output)
{
    DecodeGameCubeLinkName(data, output, data->incoming->names[0]);
}

void DecodeGameCubeLinkReceivedName1(GameCubeLinkSaveData const * data, char * output)
{
    DecodeGameCubeLinkName(data, output, data->incoming->names[1]);
}

void DecodeGameCubeLinkReceivedName2(GameCubeLinkSaveData const * data, char * output)
{
    DecodeGameCubeLinkName(data, output, data->incoming->names[2]);
}

u8 const * GetGameCubeLinkReceivedMilestones(GameCubeLinkSaveData const * data)
{
    return data->incoming->milestones;
}

void CopyGameCubeLinkPayloadBytes(GameCubeLinkSaveData const *, u8 * output, u8 const * input, u32 count)
{
    for (u32 i = 0; i < count; ++i)
        output[i] = input[i];
}

#include FOMT_TEXT_INCLUDE(gamecube_link_save.cc)

void EncodeGameCubeLinkName(GameCubeLinkSaveData const *, u8 * output, char const * input)
{
    u32 count = 0;
    for (; count < GAMECUBE_LINK_ENCODED_NAME_SIZE - 1 && *input; ++count) {
#if defined(REGION_JP)
        unsigned character = static_cast<u8>(input[1]) | (static_cast<u8>(input[0]) << 8);
        input += 2;
#else
        unsigned character = static_cast<u8>(*input++);
#endif
        u8 index = 0;
        for (; index < ARRAY_COUNT(gLinkCommunicationCharacterCodeTable) - 1; ++index)
            if (character == gLinkCommunicationCharacterCodeTable[index])
                break;
        if (index >= ARRAY_COUNT(gLinkCommunicationCharacterCodeTable) - 1) {
            output[count] = 0;
            break;
        }
        output[count] = index + 1;
    }
    for (; count < GAMECUBE_LINK_ENCODED_NAME_SIZE; ++count)
        output[count] = 0;
}

void DecodeGameCubeLinkName(GameCubeLinkSaveData const *, char * output, u8 const * input)
{
    char * cursor = output;
    for (int i = 0; i < GAMECUBE_LINK_ENCODED_NAME_SIZE - 1; ++i) {
        u8 value = input[i];
        if (!value)
            break;
#if defined(REGION_JP)
#ifdef BUGFIX
        // Wire indexes are one-based, including the final nonzero glyph.
        if (static_cast<u32>(value - 1) >= ARRAY_COUNT(gLinkCommunicationCharacterCodeTable) - 1)
#else
        // The original receiver stops one index before the encoder's last glyph.
        if (value >= ARRAY_COUNT(gLinkCommunicationCharacterCodeTable) - 1)
#endif
            break;
        u16 code = gLinkCommunicationCharacterCodeTable[value - 1];
        *cursor++ = code >> 8;
        *cursor++ = code;
#else
        if (static_cast<u32>(value - 1) >= ARRAY_COUNT(gLinkCommunicationCharacterCodeTable) - 1)
            break;
        *cursor++ = gLinkCommunicationCharacterCodeTable[value - 1];
#endif
    }
    *cursor = 0;
}

extern "C" {

// The native link packet constructors load the first word of each object.
// These are ASCII protocol identifiers, not display text.  They deliberately
// use byte-wise constants instead of the regional charmap pipeline.
LinkCommunicationGameCode const gLinkCommunicationGameCodeA4N = {
#if defined(REGION_JP)
    (u32)'A' | ((u32)'4' << 8) | ((u32)'N' << 16) | ((u32)'J' << 24),
#elif defined(REGION_EU)
    (u32)'A' | ((u32)'4' << 8) | ((u32)'N' << 16) | ((u32)'P' << 24),
#elif defined(REGION_DE)
    (u32)'A' | ((u32)'4' << 8) | ((u32)'N' << 16) | ((u32)'D' << 24),
#else
    (u32)'A' | ((u32)'4' << 8) | ((u32)'N' << 16) | ((u32)'E' << 24),
#endif
    0x00000000,
};

LinkCommunicationGameCode const gLinkCommunicationGameCodeGYW = {
#if defined(REGION_JP)
    (u32)'G' | ((u32)'Y' << 8) | ((u32)'W' << 16) | ((u32)'J' << 24),
#elif defined(REGION_EU) || defined(REGION_DE)
    (u32)'G' | ((u32)'Y' << 8) | ((u32)'W' << 16) | ((u32)'P' << 24),
#else
    (u32)'G' | ((u32)'Y' << 8) | ((u32)'W' << 16) | ((u32)'E' << 24),
#endif
    0x00000000,
};


}
