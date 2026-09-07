#ifndef FARM_STATUS_SCREEN_DATA_HH
#define FARM_STATUS_SCREEN_DATA_HH

#include "prelude.h"

struct FarmStatusScreenResourceDescriptor
{
    u16 first;
    u16 second;
};

struct FarmStatusScreenBuildingPreview
{
    u8 const *unk_00;
    u8 const *unk_04;
    u16 x;
    u16 y;
    u8 width;
    u8 height;
    u16 unused;
};

struct FarmStatusScreenExteriorStyleData
{
    u8 doghouse[3];
    u8 mailbox[3][3];
};

#if defined(REGION_JP)
extern u8 const gUnk_082AFC74[];
extern u8 const gUnk_082AFCD4[];
extern u8 const gUnk_082AFDC8[];
extern u8 const gUnk_082AFE70[];
extern u8 const gUnk_082AFED0[];
extern u8 const gUnk_082B0744[];
extern u8 const gUnk_082B07E0[];
extern u8 const gUnk_082B2F20[];
extern u8 const gUnk_082B2F80[];
extern u8 const gUnk_082B3074[];
extern u8 const gUnk_082B311C[];
extern u8 const gUnk_082B317C[];
extern u8 const gUnk_082B39F0[];
extern u8 const gUnk_082B3A8C[];
#else
extern u8 const gUnk_08529B18[];
extern u8 const gUnk_08529B78[];
extern u8 const gUnk_08529C6C[];
extern u8 const gUnk_08529D14[];
extern u8 const gUnk_08529D74[];
extern u8 const gUnk_0852A5E8[];
extern u8 const gUnk_0852A684[];
extern u8 const gUnk_0852CDC4[];
extern u8 const gUnk_0852CE24[];
extern u8 const gUnk_0852CF18[];
extern u8 const gUnk_0852CFC0[];
extern u8 const gUnk_0852D020[];
extern u8 const gUnk_0852D894[];
extern u8 const gUnk_0852D930[];
#endif

extern u16 const gFarmStatusScreenPreloadedGlyphs[];
extern char const gCppRuntimeBadAlloc_FarmStatusScreenGlyphs[];
extern FarmStatusScreenResourceDescriptor const gFarmStatusScreenResourceDescriptors[];
extern u16 const gFarmStatusScreenTileLookup[];
extern FarmStatusScreenBuildingPreview const gFarmStatusScreenFarmHousePreviews[];
extern FarmStatusScreenBuildingPreview const gFarmStatusScreenCoopPreviews[];
extern FarmStatusScreenBuildingPreview const gFarmStatusScreenBarnPreviews[];
extern FarmStatusScreenExteriorStyleData const gFarmStatusScreenExteriorStyleData;
extern char const gCppRuntimeBadAlloc_FarmStatusScreenTrailer[];

#endif // FARM_STATUS_SCREEN_DATA_HH
