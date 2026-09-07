#ifndef ANIMAL_DATA_HH
#define ANIMAL_DATA_HH

#include "prelude.h"

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
