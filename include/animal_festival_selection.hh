#ifndef ANIMAL_FESTIVAL_SELECTION_HH
#define ANIMAL_FESTIVAL_SELECTION_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "prelude.h"

extern char const gText_AnimalStatusScreen_Unavailable[];
extern u16 const gAnimalStatusScreenDigitGlyphs[];
extern char const gText_AnimalStatusScreen_Healthy[];
extern char const gText_AnimalStatusScreen_Unhappy[];
extern char const gText_AnimalStatusScreen_Sick[];
extern char const gText_AnimalStatusScreen_Spring[];
extern char const gText_AnimalStatusScreen_Summer[];
extern char const gText_AnimalStatusScreen_Autumn[];
extern char const gText_AnimalStatusScreen_Winter[];
extern char const gText_AnimalStatusScreen_Age[];
extern char const gText_AnimalStatusScreen_Day[];

extern char const gText_AnimalContest_ChickenConfirmation[];
extern char const gText_AnimalContest_Yes[];
extern char const gText_AnimalContest_No[];
extern char const gText_AnimalContest_CowConfirmation[];
extern char const gText_AnimalContest_SheepConfirmation[];
extern char const gText_AnimalContest_BabyChickIneligible[];
extern char const gText_AnimalContest_AdultCowIneligible[];
extern char const gText_AnimalContest_AdultSheepIneligible[];
extern char const gText_AnimalContest_SickChickenIneligible[];
extern char const gText_AnimalContest_SickCowIneligible[];
extern char const gText_AnimalContest_SickSheepIneligible[];
extern char const gText_AnimalContest_PregnantCowIneligible[];
extern char const gText_AnimalContest_PregnantSheepIneligible[];
extern char const gText_AnimalContest_ShornSheepIneligible[];
extern char const gText_AnimalContest_ChickenSelectionPrompt[];
extern char const gText_AnimalContest_CowSelectionPrompt[];
extern char const gText_AnimalContest_SheepSelectionPrompt[];
extern char const gText_AnimalContest_ChickenEntryDeclinedResponse[];
extern char const gText_AnimalContest_LivestockEntryDeclinedResponse[];

#if defined(REGION_JP)
extern char const gText_AnimalContest_ChickenEntryAccepted[];
extern char const gText_AnimalContest_CowEntryAccepted[];
extern char const gText_AnimalContest_SheepEntryAccepted[];
extern char const gText_AnimalContest_ChickenEntryDeclinedQuestion[];
extern char const gText_AnimalContest_LivestockEntryDeclinedQuestion[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_AnimalContest_EntryAccepted[];
extern char const gText_AnimalContest_EntryDeclinedQuestion[];
#endif

struct GameStateSaveImage;
#include "hardware_context.hh"
#include "smart_ptr.hh"

#include "scroll_state.hh"
#include "hardware_sound.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "obj_tile_collection.hh"
#include "obj_palette_pool.hh"
#include "ui_state.hh"


template <typename T, u32 Capacity>
struct FestivalSelectionRecords {
    FestivalSelectionRecords() : count(0) {}
    T * Begin() { return reinterpret_cast<T *>(storage); }
    T * End() { return &Begin()[count]; }
    ~FestivalSelectionRecords()
    {
        T * first = Begin();
        T * last = End();
        for (; first != last; ++first)
            first->~T();
    }
    u32 count;
    u32 storage[Capacity * sizeof(T) / sizeof(u32)];
};

// These two counted arrays have verified strides and lifetime bounds. Their
// fields remain unnamed until the native selection code is further decoded.
struct FestivalSelectionRow16 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
};

struct FestivalSelectionRow12 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
};

struct FestivalSelectionSprite {
    i16 x;
    i16 y;
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u8 unk_34;
};

struct FestivalSelectionCursor {
    u16 unk_00;
    u32 unk_04;
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u8 unk_38;
};

struct FestivalSelectionScrollOwner {
    ScrollState * value;
    ~FestivalSelectionScrollOwner() { delete value; }
};

#pragma interface "animal_festival_selection.hh"

struct FestivalAnimalSelectionCore;

// The native selection keeps the requested kind even when no animal is chosen.
struct FestivalAnimalSelectionResult {
    MaryFestivalAnimalKind kind;
    i32 animal_index; // -1 means the selection was cancelled.
};

struct FestivalAnimalSelectionScene : AScene {
    FestivalAnimalSelectionScene(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryFestivalAnimalKind kind);
    virtual ~FestivalAnimalSelectionScene();
    virtual SceneTransitionOwner Run();
    FestivalAnimalSelectionResult GetSelectionResult() const;
    SmartPtr<FestivalAnimalSelectionCore> core;
};

// Construction and Run still use their complete named native implementations.
// Only constructed ranges and owned resources participate in destruction.
struct FestivalAnimalSelectionCore : HardwareContext {
    FestivalAnimalSelectionCore(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryFestivalAnimalKind kind) asm("ConstructFestivalAnimalSelectionCore");
    ~FestivalAnimalSelectionCore();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryFestivalAnimalKind kind;
    FestivalAnimalSelectionResult result;
    FestivalSelectionScrollOwner scroll;
    u16 unk_20;
    IndexedResourceArchive archive;
    IndexedResourceArchive cursor_archive;
    FestivalSelectionSprite sprites[2];
    FestivalSelectionCursor cursor;
    u32 unk_130;
    UiStateOwner ui;
#if defined(REGION_JP)
    u8 unk_138[0x3920 - 0x138];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    u8 unk_138[0x3EA0 - 0x138];
#endif
    FestivalSelectionRecords<FestivalSelectionRow16, 16> rows_3EA0;
    FestivalSelectionRecords<FestivalSelectionRow12, 16> rows_3FA4;
    u32 unk_4068_count;
    u32 unk_406C[16];
    u32 unk_40AC;
    ObjTileCollectionEntry tiles_40B0;
    ObjPaletteCollectionEntry palette_40B8;
    ObjTileCollectionEntry tiles_40C0;
    ObjPaletteCollectionEntry palette_40C8;
    ObjTileCollectionEntry row_tiles[10];
    ObjPaletteCollectionEntry row_palettes[10];
    HardwareMusicPlayerSlot music;
    u32 unk_4174;
};

#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif
#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif
#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif



EXTERN_C
SceneTransitionOwner RunFestivalAnimalSelectionCore(FestivalAnimalSelectionCore * core);
EXTERN_C_END

#endif // ANIMAL_FESTIVAL_SELECTION_HH
