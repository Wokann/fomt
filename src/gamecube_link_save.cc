#include "gamecube_link_save.hh"
#include "game_state.hh"

// Save-image layout and native encoded-name fields are consumed here.
asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start __20GameCubeLinkSaveDataP18GameStateSaveImage\n"
    "__20GameCubeLinkSaveDataP18GameStateSaveImage:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "adds r4, r0, #0x0\n"
    "str r1, [r4]\n"
    "bl GetGameCubeLinkOutgoingSize\n"
    "bl __builtin_vec_new\n"
    "str r0, [r4, #0x4]\n"
    "adds r0, r4, #0x0\n"
    "bl GetGameCubeLinkIncomingSize\n"
    "bl __builtin_vec_new\n"
    "str r0, [r4, #0x8]\n"
    "movs r3, #0x0\n"
    "movs r6, #0x1\n"
    "adds r5, r4, #0x0\n"
    "adds r5, #0x18\n"
    ".Lgamecube_118_0024:\n"
    "ldr r0, [r4]\n"
    "adds r2, r3, #0x0\n"
    "cmp r3, #0x0\n"
    "bge .Lgamecube_118_002e\n"
    "adds r2, r3, #0x7\n"
    ".Lgamecube_118_002e:\n"
    "asrs r2, r2, #0x3\n"
    "lsls r1, r2, #0x3\n"
    "subs r1, r3, r1\n"
    "ldr r7, .Lgamecube_118_0054\n"
    "adds r0, r0, r7\n"
    "adds r0, r0, r2\n"
    "ldrb r0, [r0]\n"
    "asrs r0, r1\n"
    "ands r0, r6\n"
    "adds r1, r5, r3\n"
    "strb r0, [r1]\n"
    "adds r3, #0x1\n"
    "cmp r3, #0x30\n"
    "ble .Lgamecube_118_0024\n"
    "adds r0, r4, #0x0\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r1}\n"
    "bx r1\n"
    ".align 2, 0\n"
    ".Lgamecube_118_0054: .word 0x21d4\n"
    "\n"
);

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

asm_unified(
    "thumb_func_start EncodeGameCubeLinkName\n"
    "EncodeGameCubeLinkName:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "adds r7, r1, #0x0\n"
    ".ifdef REGION_JP\n"
    ".else\n"
    "adds r4, r2, #0x0\n"
    ".endif\n"
    "movs r5, #0x0\n"
    ".ifdef REGION_JP\n"
    "ldrb r0, [r2]\n"
    ".else\n"
    "ldrb r0, [r4]\n"
    ".endif\n"
    "cmp r0, #0x0\n"
    "beq .Lgamecube_138_0056\n"
    "ldr r0, .Lgamecube_138_0040\n"
    ".ifdef REGION_JP\n"
    "ldrh r0, [r0]\n"
    ".else\n"
    "ldrb r0, [r0]\n"
    ".endif\n"
    "mov ip, r0\n"
    ".ifdef REGION_JP\n"
    "adds r4, r7, #0x0\n"
    ".else\n"
    "adds r2, r7, #0x0\n"
    ".endif\n"
    ".Lgamecube_138_0016:\n"
    ".ifdef REGION_JP\n"
    "ldrb r1, [r2, #0x1]\n"
    "ldrb r0, [r2]\n"
    "lsls r0, r0, #0x8\n"
    "orrs r1, r0\n"
    "adds r2, #0x2\n"
    ".else\n"
    "ldrb r1, [r4]\n"
    "adds r4, #0x1\n"
    ".endif\n"
    "movs r3, #0x0\n"
    "cmp r1, ip\n"
    "beq .Lgamecube_138_0034\n"
    "ldr r6, .Lgamecube_138_0040\n"
    ".Lgamecube_138_0022:\n"
    "adds r0, r3, #0x1\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r3, r0, #0x18\n"
    ".ifdef REGION_JP\n"
    "cmp r3, #0xf9\n"
    ".else\n"
    "cmp r3, #0x60\n"
    ".endif\n"
    "bhi .Lgamecube_138_0038\n"
    ".ifdef REGION_JP\n"
    "lsls r0, r3, #0x1\n"
    "adds r0, r0, r6\n"
    "ldrh r0, [r0]\n"
    ".else\n"
    "adds r0, r3, r6\n"
    "ldrb r0, [r0]\n"
    ".endif\n"
    "cmp r1, r0\n"
    "bne .Lgamecube_138_0022\n"
    ".Lgamecube_138_0034:\n"
    ".ifdef REGION_JP\n"
    "cmp r3, #0xf9\n"
    ".else\n"
    "cmp r3, #0x60\n"
    ".endif\n"
    "bls .Lgamecube_138_0044\n"
    ".Lgamecube_138_0038:\n"
    "movs r0, #0x0\n"
    ".ifdef REGION_JP\n"
    "strb r0, [r4]\n"
    ".else\n"
    "strb r0, [r2]\n"
    ".endif\n"
    "b .Lgamecube_138_0056\n"
    ".align 2, 0\n"
    ".Lgamecube_138_0040: .word gLinkCommunicationCharacterCodeTable\n"
    ".Lgamecube_138_0044:\n"
    "adds r0, r3, #0x1\n"
    ".ifdef REGION_JP\n"
    "strb r0, [r4]\n"
    "adds r4, #0x1\n"
    ".else\n"
    "strb r0, [r2]\n"
    "adds r2, #0x1\n"
    ".endif\n"
    "adds r5, #0x1\n"
    ".ifdef REGION_JP\n"
    "cmp r5, #0x6\n"
    ".else\n"
    "cmp r5, #0xb\n"
    ".endif\n"
    "bhi .Lgamecube_138_0056\n"
    ".ifdef REGION_JP\n"
    "ldrb r0, [r2]\n"
    ".else\n"
    "ldrb r0, [r4]\n"
    ".endif\n"
    "cmp r0, #0x0\n"
    "bne .Lgamecube_138_0016\n"
    ".Lgamecube_138_0056:\n"
    ".ifdef REGION_JP\n"
    "cmp r5, #0x7\n"
    ".else\n"
    "cmp r5, #0xc\n"
    ".endif\n"
    "bhi .Lgamecube_138_0066\n"
    "movs r2, #0x0\n"
    ".Lgamecube_138_005c:\n"
    "adds r0, r7, r5\n"
    "strb r2, [r0]\n"
    "adds r5, #0x1\n"
    ".ifdef REGION_JP\n"
    "cmp r5, #0x7\n"
    ".else\n"
    "cmp r5, #0xc\n"
    ".endif\n"
    "bls .Lgamecube_138_005c\n"
    ".Lgamecube_138_0066:\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r0}\n"
    "bx r0\n"
    "\n"
    "thumb_func_start DecodeGameCubeLinkName\n"
    "DecodeGameCubeLinkName:\n"
    ".ifdef REGION_JP\n"
    "push {r4, r5, lr}\n"
    "adds r4, r2, #0x0\n"
    "adds r3, r1, #0x0\n"
    "movs r2, #0x0\n"
    ".Lgamecube_jp_139_0008:\n"
    "ldrb r0, [r4]\n"
    ".else\n"
    "push {r4, lr}\n"
    "movs r3, #0x0\n"
    "ldrb r0, [r2]\n"
    ".endif\n"
    "cmp r0, #0x0\n"
    "beq .Lgamecube_139_002e\n"
    ".ifdef REGION_JP\n"
    "cmp r0, #0xf9\n"
    "bhi .Lgamecube_139_002e\n"
    "ldr r5, .Lgamecube_139_0038\n"
    ".Lgamecube_jp_139_0014:\n"
    ".else\n"
    ".endif\n"
    "subs r0, #0x1\n"
    ".ifdef REGION_JP\n"
    "lsls r0, r0, #0x1\n"
    "adds r0, r0, r5\n"
    "ldrh r1, [r0]\n"
    "lsrs r0, r1, #0x8\n"
    "strb r0, [r3]\n"
    ".else\n"
    "cmp r0, #0x60\n"
    "bhi .Lgamecube_139_002e\n"
    "ldr r4, .Lgamecube_139_0038\n"
    ".Lgamecube_139_0012:\n"
    "adds r0, r0, r4\n"
    "ldrb r0, [r0]\n"
    "strb r0, [r1]\n"
    "adds r1, #0x1\n"
    ".endif\n"
    "adds r3, #0x1\n"
    ".ifdef REGION_JP\n"
    "strb r1, [r3]\n"
    "adds r3, #0x1\n"
    "adds r2, #0x1\n"
    "cmp r2, #0x6\n"
    ".else\n"
    "cmp r3, #0xb\n"
    ".endif\n"
    "bgt .Lgamecube_139_002e\n"
    ".ifdef REGION_JP\n"
    "adds r0, r4, r2\n"
    ".else\n"
    "adds r0, r2, r3\n"
    ".endif\n"
    "ldrb r0, [r0]\n"
    "cmp r0, #0x0\n"
    "beq .Lgamecube_139_002e\n"
    ".ifdef REGION_JP\n"
    "cmp r0, #0xf9\n"
    "bls .Lgamecube_jp_139_0014\n"
    ".else\n"
    "subs r0, #0x1\n"
    "cmp r0, #0x60\n"
    "bls .Lgamecube_139_0012\n"
    ".endif\n"
    ".Lgamecube_139_002e:\n"
    "movs r0, #0x0\n"
    ".ifdef REGION_JP\n"
    "strb r0, [r3]\n"
    "pop {r4, r5}\n"
    ".else\n"
    "strb r0, [r1]\n"
    "pop {r4}\n"
    ".endif\n"
    "pop {r0}\n"
    "bx r0\n"
    ".align 2, 0\n"
    ".Lgamecube_139_0038: .word gLinkCommunicationCharacterCodeTable\n"
);

#include FOMT_TEXT_INCLUDE(gamecube_link_save.cc)

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
