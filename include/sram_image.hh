#ifndef SRAM_IMAGE_HH
#define SRAM_IMAGE_HH

#include "prelude.h"
#include "gbaio.h"
#include "game_state_types.hh"

struct SramAccess;

// Cartridge SRAM offsets are relative to SRAM_BASE. Bits 0 and 1 of
// present_slots mark the two independent files; last_slot is zero-based.
struct SramImageHeader {
    /* 0x00 */ char signature[32];
    /* 0x20 */ u32 present_slots;
    /* 0x24 */ u32 last_slot;
};

enum {
    SRAM_SAVE_SLOT_COUNT = 2,
    SRAM_SAVE_SLOT_BYTES = (SRAM_SIZE - sizeof(SramImageHeader)) / SRAM_SAVE_SLOT_COUNT
};
typedef char SramImageHeaderSizeCheck[sizeof(SramImageHeader) == 0x28 ? 1 : -1];
typedef char SramImageSlotSizeCheck[SRAM_SAVE_SLOT_BYTES == 0x3FEC ? 1 : -1];

// On-cartridge layout. The writer stores the raw image (including its
// internal padding), then the unsigned sum of those image bytes.
struct SramSaveRecord {
    /* 0x0000 */ u32 image_bytes;
    /* 0x0004 */ GameStateSaveImage image;
    /* 0x34F8 */ u32 checksum;
};

struct SramSaveSlot {
    SramSaveRecord record;
    // Outside the range read and written by the game-state serializer.
    u8 remainder[SRAM_SAVE_SLOT_BYTES - sizeof(SramSaveRecord)];
};

struct SramImage {
    /* 0x0000 */ SramImageHeader header;
    /* 0x0028, 0x4014 */ SramSaveSlot slots[SRAM_SAVE_SLOT_COUNT];
};
typedef char SramSaveRecordImageCheck[offsetof(SramSaveRecord, image) == 4 ? 1 : -1];
typedef char SramSaveRecordChecksumCheck[offsetof(SramSaveRecord, checksum) == 0x34F8 ? 1 : -1];
typedef char SramSaveRecordSizeCheck[sizeof(SramSaveRecord) == 0x34FC ? 1 : -1];
typedef char SramSaveSlotSizeCheck[sizeof(SramSaveSlot) == SRAM_SAVE_SLOT_BYTES ? 1 : -1];
typedef char SramImageSizeCheck[sizeof(SramImage) == SRAM_SIZE ? 1 : -1];

EXTERN_C

// Fixed 32-byte header used to identify a valid FOMT SRAM image.
extern char const gSramImageSignature[32];

u8 IsValidSramImage(struct SramAccess *source);
void InitializeSramImageHeader(struct SramAccess *destination);
u32 GetSramSaveSlotMask(struct SramAccess *source);
u32 GetSramSaveSlotOffset(struct SramAccess const *unused, u32 index);
void MarkSramSaveSlotPresent(struct SramAccess *source, u32 index);
void ClearSramSaveSlotPresent(struct SramAccess *source, u32 index);
void SetLastUsedSramSaveSlot(struct SramAccess *destination, u32 value);
u32 GetLastUsedSramSaveSlot(struct SramAccess *source);


EXTERN_C_END

#endif // SRAM_IMAGE_HH
