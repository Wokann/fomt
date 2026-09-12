#ifndef ANIMAL_DATA_HH
#define ANIMAL_DATA_HH

#include "prelude.h"

// The animal memorial message is assembled by native code from these direct
// text pointers. The US version has a separate farm-name suffix, while JP has
// a natural-life sentence instead.
extern char const gText_AnimalMemorial_LineBreak[];
extern char const gText_AnimalMemorial_Continue[];
extern char const gText_AnimalMemorial_PageBreak[];
extern char const gText_AnimalMemorial_Header[];
extern char const gText_AnimalMemorial_FarmPrefix[];
#if !defined(REGION_JP)
extern char const gText_AnimalMemorial_FarmSuffix[];
#endif
extern char const gText_AnimalMemorial_PassedAway[];
extern char const gText_AnimalMemorial_NamesIntro[];
extern char const gText_AnimalMemorial_PrayerIntro[];
extern char const gText_AnimalMemorial_PrayerEnding[];
#if defined(REGION_DE)
extern char const gText_AnimalMemorial_DeathHeader[];
extern char const gText_AnimalMemorial_DeathFarmPrefix[];
#endif
#if defined(REGION_JP)
extern char const gText_AnimalMemorial_PassedNaturalLife[];
#endif
extern char const gCppRuntimeBadAlloc_AnimalMemorial[];
extern char const gCppRuntimeError_AnimalMemorial[];
extern char const gText_AnimalMemorialFallbackNone[];

// The labels retain their established US-ROM names.  The same object is
// positioned at the corresponding JP address by each regional linker script.
extern u8 const gUnk_080F06FD[];
extern u8 const gUnk_080F0704[];
extern u8 const gUnk_080F0718[];
extern u8 const gUnk_080F0730[];

extern u8 const gUnk_080F0748[];
extern u8 const gUnk_080F0770[];
extern u8 const gUnk_080F0800[];

struct AnimalDataEntry {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
};

extern AnimalDataEntry const gUnk_080F0838[2][2][13];
extern u16 const gUnk_080F0908[2][13];
extern AnimalDataEntry const gUnk_080F093C[28];
extern u16 const gUnk_080F09AC[2][7];
extern AnimalDataEntry const gUnk_080F09C8[40];
extern u16 const gUnk_080F0A68[10];
extern AnimalDataEntry const gUnk_080F0A7C[112];
extern u16 const gUnk_080F0C3C[28];
extern AnimalDataEntry const gUnk_080F0C74[112];
extern u16 const gUnk_080F0E34[28];
extern char const gCppRuntimeBadAlloc_AnimalDataFirst[];
extern char const gCppRuntimeBadAlloc_AnimalDataSecond[];
extern char const gCppRuntimeError_AnimalData[];
extern char const gText_AnimalDataFallbackNone[];
extern char const gCppRuntimeBadAlloc_AnimalDataThird[];
extern char const gCppRuntimeError_AnimalDataSecond[];

#endif // ANIMAL_DATA_HH
