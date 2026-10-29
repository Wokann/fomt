#ifndef NEW_GAME_IDENTITY_HH
#define NEW_GAME_IDENTITY_HH

#include "new_game.hh"

typedef char NewGameIdentityValueBufferSizeCheck[
    sizeof(NewGameTextTileBuffer<12>) == 0x304 ? 1 : -1];
typedef char NewGameIdentityLabelBufferSizeCheck[
    sizeof(NewGameTextTileBuffer<14>) == 0x384 ? 1 : -1];
typedef char NewGameIdentityTilesOffsetCheck[
    offsetof(NewGameTextTileBuffer<12>, tiles) == 4 ? 1 : -1];
typedef char NewGameIdentityTextBufferSizeCheck[sizeof(FixedStr<15>) == 0x10 ? 1 : -1];

// Physical field order: player name, birthday, farm name, dog name. Native
// construction bounds each byte string to 15 bytes plus its terminator;
// InitializeNewGameIdentityScreen renders these four values in this order.
enum NewGameIdentityField {
    NEW_GAME_IDENTITY_PLAYER_NAME,
    NEW_GAME_IDENTITY_BIRTHDAY,
    NEW_GAME_IDENTITY_FARM_NAME,
    NEW_GAME_IDENTITY_DOG_NAME,
    NEW_GAME_IDENTITY_FIELD_COUNT,
};

// The identity-confirmation form owns a 0x1878-byte JP core or a 0x1A78-byte
// overseas core. JP uses eight equal-width buffers: four values followed by
// four labels. Overseas labels are wider and form their own four-entry array.
// The unknown scalar and control-byte names retain their original US offsets.
#pragma interface "new_game_identity.hh"
struct NewGameIdentityCore : HardwareBootstrap {
    virtual ~NewGameIdentityCore() asm("DestroyNewGameIdentityCore")
        SECTION(".text.new_game_identity_core_cleanup");
#if defined(REGION_JP)
    NewGameTextTileBuffer<12> buffers[8];
#else
    NewGameTextTileBuffer<12> value_buffers[4];
    NewGameTextTileBuffer<14> label_buffers[4];
#endif
    u32 unk_1A28;
    UiStateOwner * ui_state;
    HardwareMusicPlayerSlot music;
    FixedStr<15> fields[NEW_GAME_IDENTITY_FIELD_COUNT];
    u8 unk_1A74;
    u8 unk_1A75;
    u8 confirmed;
    u8 unk_1A77;
};

struct NewGameIdentityScene : AScene {
    NewGameIdentityScene(char const * player_name, GameDate birthday,
        char const * farm_name, char const * dog_name)
        asm("ConstructNewGameIdentityScene") SECTION(".text.new_game_identity_scene");
    virtual ~NewGameIdentityScene() asm("DestroyNewGameIdentityScene") SECTION(".text.new_game_identity_scene");
    virtual SceneTransitionOwner Run() asm("RunNewGameIdentityScene") SECTION(".text.new_game_identity_scene");
    u8 GetConfirmed() const asm("GetNewGameIdentitySceneConfirmed") SECTION(".text.new_game_identity_scene");
    NewGameIdentityCore * core;
};
#pragma implementation


#if defined(REGION_JP)
typedef char NewGameIdentityCoreSizeCheck[sizeof(NewGameIdentityCore) == 0x1878 ? 1 : -1];
typedef char NewGameIdentityCoreBuffersCheck[offsetof(NewGameIdentityCore, buffers) == 8 ? 1 : -1];
typedef char NewGameIdentityCoreUnk1A28Check[offsetof(NewGameIdentityCore, unk_1A28) == 0x1828 ? 1 : -1];
typedef char NewGameIdentityCoreUiCheck[offsetof(NewGameIdentityCore, ui_state) == 0x182C ? 1 : -1];
typedef char NewGameIdentityCoreMusicCheck[offsetof(NewGameIdentityCore, music) == 0x1830 ? 1 : -1];
typedef char NewGameIdentityCoreFieldsCheck[offsetof(NewGameIdentityCore, fields) == 0x1834 ? 1 : -1];
typedef char NewGameIdentityCoreControlCheck[offsetof(NewGameIdentityCore, unk_1A74) == 0x1874 ? 1 : -1];
typedef char NewGameIdentityCoreResultCheck[offsetof(NewGameIdentityCore, confirmed) == 0x1876 ? 1 : -1];
#else
typedef char NewGameIdentityCoreSizeCheck[sizeof(NewGameIdentityCore) == 0x1A78 ? 1 : -1];
typedef char NewGameIdentityCoreValueBuffersCheck[offsetof(NewGameIdentityCore, value_buffers) == 8 ? 1 : -1];
typedef char NewGameIdentityCoreLabelBuffersCheck[offsetof(NewGameIdentityCore, label_buffers) == 0xC18 ? 1 : -1];
typedef char NewGameIdentityCoreUnk1A28Check[offsetof(NewGameIdentityCore, unk_1A28) == 0x1A28 ? 1 : -1];
typedef char NewGameIdentityCoreUiCheck[offsetof(NewGameIdentityCore, ui_state) == 0x1A2C ? 1 : -1];
typedef char NewGameIdentityCoreMusicCheck[offsetof(NewGameIdentityCore, music) == 0x1A30 ? 1 : -1];
typedef char NewGameIdentityCoreFieldsCheck[offsetof(NewGameIdentityCore, fields) == 0x1A34 ? 1 : -1];
typedef char NewGameIdentityCoreControlCheck[offsetof(NewGameIdentityCore, unk_1A74) == 0x1A74 ? 1 : -1];
typedef char NewGameIdentityCoreResultCheck[offsetof(NewGameIdentityCore, confirmed) == 0x1A76 ? 1 : -1];
#endif
typedef char NewGameIdentitySceneSizeCheck[sizeof(NewGameIdentityScene) == 8 ? 1 : -1];
typedef char NewGameIdentitySceneCoreCheck[offsetof(NewGameIdentityScene, core) == 4 ? 1 : -1];


EXTERN_C

// Form construction uses C++; UI setup remains native assembly. The
// running core and scene below share their real allocation and return-owner ABI.
// Both constructors pass the existing packed date by value: season in bits
// 0..1 and the zero-based day in bits 2..6. Bit 7 is not part of the date.
// Construct the bootstrap, uninitialized tile buffers and owned UI, then
// format the four bounded fields. Names and the birthday use at most 15
// encoded bytes plus NUL; JP appends its month/day suffixes. Only confirmed
// is reset here: the running screen initializes its other control bytes.
NewGameIdentityCore * InitializeNewGameIdentityCore(NewGameIdentityCore * core,
    char const * player_name, GameDate birthday, char const * farm_name, char const * dog_name)
    SECTION(".text.new_game_identity_core_constructor");
void DestroyNewGameIdentityCore(NewGameIdentityCore * core, int flags)
    SECTION(".text.new_game_identity_core_cleanup");
SceneTransitionOwner RunNewGameIdentityCore(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_run");
void BlankNewGameIdentityDisplay(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_initialization");
void ResetNewGameIdentityControl(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_initialization");
// Configure the confirmation screen, draw the four values and labels, queue
// all eight tile buffers, build their BG map, and update the UI owner once.
// JP has eight 12x2 buffers; overseas labels use separate 14x2 buffers.
void InitializeNewGameIdentityScreen(NewGameIdentityCore * core);
void UpdateNewGameIdentityDialog(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_update");
extern int (*__vt_19NewGameIdentityCore[])(...);
extern NewGameNativeVTableEntry __vt_20NewGameIdentityScene[4];

// Native ABI declarations for the scene lifecycle and its byte-result accessors.
NewGameIdentityScene * ConstructNewGameIdentityScene(NewGameIdentityScene * scene,
    char const * player_name, GameDate birthday, char const * farm_name, char const * dog_name)
    SECTION(".text.new_game_identity_scene");
void DestroyNewGameIdentityScene(NewGameIdentityScene * scene, int flags)
    SECTION(".text.new_game_identity_scene");
SceneTransitionOwner RunNewGameIdentityScene(NewGameIdentityScene * scene)
    SECTION(".text.new_game_identity_scene");
u8 GetNewGameIdentitySceneConfirmed(NewGameIdentityScene const * scene)
    SECTION(".text.new_game_identity_scene");
u8 GetNewGameIdentityCoreConfirmed(NewGameIdentityCore const * core)
    SECTION(".text.new_game_identity_scene");

EXTERN_C_END

#endif // NEW_GAME_IDENTITY_HH
