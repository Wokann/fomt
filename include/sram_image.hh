#ifndef SRAM_IMAGE_HH
#define SRAM_IMAGE_HH

#include "prelude.h"

struct SramAccess;

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

extern char const gUnk_SramSignatureTrailerBadAllocFirst[];
extern char const gUnk_SramSignatureTrailerEmptyText[];
extern char const gUnk_SramSignatureTrailerBadAllocSecond[];
extern char const gUnk_SramSignatureTrailerBadAllocThird[];
extern char const gUnk_SramSignatureTrailerError[];
extern char const gUnk_SramSignatureTrailerNotAvailable[];

EXTERN_C_END

#endif // SRAM_IMAGE_HH
