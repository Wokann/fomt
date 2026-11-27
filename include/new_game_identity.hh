#ifndef NEW_GAME_IDENTITY_HH
#define NEW_GAME_IDENTITY_HH

// Four fixed form fields are rendered as two tile rows each. Widths are
// shared with the remaining assembly; field count and height describe this
// screen's actual format, not arbitrary additional rows or fields.
#define NEW_GAME_IDENTITY_FIELD_COUNT 4
#define NEW_GAME_IDENTITY_TILE_HEIGHT 2
#define NEW_GAME_IDENTITY_VALUE_WIDTH 12
#if defined(REGION_JP)
#define NEW_GAME_IDENTITY_LABEL_WIDTH NEW_GAME_IDENTITY_VALUE_WIDTH
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#define NEW_GAME_IDENTITY_LABEL_WIDTH 14
#endif

// Each 4bpp tile is 32 bytes. The native buffer has one u32 prefix; the
// bootstrap has two words. The C++ checks below verify these ABI facts.
#define NEW_GAME_IDENTITY_VALUE_TILE_BYTES (NEW_GAME_IDENTITY_VALUE_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT * 32)
#define NEW_GAME_IDENTITY_LABEL_TILE_BYTES (NEW_GAME_IDENTITY_LABEL_WIDTH * NEW_GAME_IDENTITY_TILE_HEIGHT * 32)
#define NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES (4 + NEW_GAME_IDENTITY_VALUE_TILE_BYTES)
#define NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES (4 + NEW_GAME_IDENTITY_LABEL_TILE_BYTES)
#define NEW_GAME_IDENTITY_VALUE_TILES_OFFSET (8 + 4)
#define NEW_GAME_IDENTITY_LABEL_TILES_OFFSET (8 + NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES + 4)
#define NEW_GAME_IDENTITY_CORE_DATA_OFFSET (8 + NEW_GAME_IDENTITY_FIELD_COUNT * (NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES))
#define NEW_GAME_IDENTITY_CORE_UI_OFFSET (NEW_GAME_IDENTITY_CORE_DATA_OFFSET + 4)
#define NEW_GAME_IDENTITY_CORE_MUSIC_OFFSET (NEW_GAME_IDENTITY_CORE_UI_OFFSET + 4)
#define NEW_GAME_IDENTITY_CORE_FIELDS_OFFSET (NEW_GAME_IDENTITY_CORE_MUSIC_OFFSET + 4)

#ifndef __ASSEMBLER__

#include "new_game_ui.hh"
#include "scene.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "ui_state.hh"
#include "unknown_types.hh"
#include "utility/fixed_str.hh"

typedef NewGameTextTileBuffer<NEW_GAME_IDENTITY_VALUE_WIDTH, NEW_GAME_IDENTITY_TILE_HEIGHT> NewGameIdentityValueBuffer;
typedef NewGameTextTileBuffer<NEW_GAME_IDENTITY_LABEL_WIDTH, NEW_GAME_IDENTITY_TILE_HEIGHT> NewGameIdentityLabelBuffer;


// Physical field order: player name, birthday, farm name, dog name. Native
// construction bounds each byte string to 15 bytes plus its terminator;
// InitializeNewGameIdentityScreen renders these four values in this order.
enum NewGameIdentityField {
    NEW_GAME_IDENTITY_PLAYER_NAME,
    NEW_GAME_IDENTITY_BIRTHDAY,
    NEW_GAME_IDENTITY_FARM_NAME,
    NEW_GAME_IDENTITY_DOG_NAME,
};


#pragma interface "new_game_identity.hh"
struct NewGameIdentityCore;

struct NewGameIdentityScene : AScene {
    NewGameIdentityScene(char const * player_name, GameDate birthday,
        char const * farm_name, char const * dog_name)
        asm("ConstructNewGameIdentityScene");
    virtual ~NewGameIdentityScene() asm("DestroyNewGameIdentityScene");
    virtual SceneTransitionOwner Run() asm("RunNewGameIdentityScene");
    u8 GetConfirmed() const asm("GetNewGameIdentitySceneConfirmed");
    NewGameIdentityCore * core;
};

// JP stores values followed by labels in one equal-width array. Overseas
// labels are wider and form their own array; following members use the
// resulting C++ layout.
// The unknown scalar and control-byte names retain their original US offsets.
struct NewGameIdentityCore : HardwareContext {
    NewGameIdentityCore(char const * player_name, GameDate birthday,
        char const * farm_name, char const * dog_name)
        asm("InitializeNewGameIdentityCore");
    virtual ~NewGameIdentityCore() asm("DestroyNewGameIdentityCore");
#if defined(REGION_JP)
    NewGameIdentityValueBuffer buffers[2 * NEW_GAME_IDENTITY_FIELD_COUNT];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    NewGameIdentityValueBuffer value_buffers[NEW_GAME_IDENTITY_FIELD_COUNT];
    NewGameIdentityLabelBuffer label_buffers[NEW_GAME_IDENTITY_FIELD_COUNT];
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


#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif


EXTERN_C

// Form construction and UI setup retain their native assembly. The
// running core and scene below share their real allocation and return-owner ABI.
// Both constructors pass the existing packed date by value: season in bits
// 0..1 and the zero-based day in bits 2..6. Bit 7 is not part of the date.
// Construct the bootstrap, uninitialized tile buffers and owned UI, then
// format the four bounded fields. Names and the birthday use at most 15
// encoded bytes plus NUL; JP appends its month/day suffixes. Only confirmed
// is reset here: the running screen initializes its other control bytes.
NewGameIdentityCore * InitializeNewGameIdentityCore(NewGameIdentityCore * core,
    char const * player_name, GameDate birthday, char const * farm_name, char const * dog_name);
void DestroyNewGameIdentityCore(NewGameIdentityCore * core, int flags);
SceneTransitionOwner RunNewGameIdentityCore(NewGameIdentityCore * core);
void BlankNewGameIdentityDisplay(NewGameIdentityCore * core);
void ResetNewGameIdentityControl(NewGameIdentityCore * core);
// Configure the confirmation screen, draw the four values and labels, queue
// all eight tile buffers, build their BG map, and update the UI owner once.
// JP shares the value width for labels; overseas labels have their own width.
void InitializeNewGameIdentityScreen(NewGameIdentityCore * core);
void UpdateNewGameIdentityDialog(NewGameIdentityCore * core);
extern int (*__vt_19NewGameIdentityCore[])(...);

// Native ABI declarations for the scene lifecycle and its byte-result accessors.
NewGameIdentityScene * ConstructNewGameIdentityScene(NewGameIdentityScene * scene,
    char const * player_name, GameDate birthday, char const * farm_name, char const * dog_name);
void DestroyNewGameIdentityScene(NewGameIdentityScene * scene, int flags);
SceneTransitionOwner RunNewGameIdentityScene(NewGameIdentityScene * scene);
u8 GetNewGameIdentitySceneConfirmed(NewGameIdentityScene const * scene);
u8 GetNewGameIdentityCoreConfirmed(NewGameIdentityCore const * core);

EXTERN_C_END

extern char const gText_NewGameIdentity_BirthMonthSuffix[];
extern char const gText_NewGameIdentity_BirthDaySuffix[];
extern char const gText_NewGameIdentity_PlayerName[];
extern char const gText_NewGameIdentity_PlayerBirthday[];
extern char const gText_NewGameIdentity_FarmName[];
extern char const gText_NewGameIdentity_DogName[];
extern char const gText_NewGameIdentity_Confirm[];
extern char const gText_NewGameIdentity_Yes[];
extern char const gText_NewGameIdentity_No[];

#endif // !__ASSEMBLER__

#endif // NEW_GAME_IDENTITY_HH
