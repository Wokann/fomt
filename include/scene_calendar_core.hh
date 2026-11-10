#ifndef SCENE_CALENDAR_CORE_HH
#define SCENE_CALENDAR_CORE_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "unknown_types.hh"
struct GameStateSaveImage;
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_handle.hh"
#include "obj_tile_collection.hh"
#include "obj_palette_collection.hh"
#include "ui_state.hh"
#include "font_decimal.hh"
// Embedded at +0x21C in the calendar core. F0 supplies the season, F1 the
// one-based day, and F2 the partner name used by the marriage notice.
#pragma interface "scene_calendar.hh"
struct CalendarTextVariables : ScriptTextVariableStore {
    virtual ~CalendarTextVariables() {}
    virtual UiTextSubstitution Lookup(u32 code);

    i8 day;
    i8 season;
    char const * partner_name;
};

typedef char CalendarTextVariablesSizeCheck[sizeof(CalendarTextVariables) == 12 ? 1 : -1];
typedef char CalendarTextVariablesDayCheck[offsetof(CalendarTextVariables, day) == 4 ? 1 : -1];
typedef char CalendarTextVariablesSeasonCheck[offsetof(CalendarTextVariables, season) == 5 ? 1 : -1];
typedef char CalendarTextVariablesPartnerCheck[offsetof(CalendarTextVariables, partner_name) == 8 ? 1 : -1];

#pragma interface "scene_calendar.hh"

struct CalendarSprite {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
};

// Four-byte records consumed by month-grid selection and marker drawing.
// The builder leaves slot zero unused and fills subsequent slots.
struct CalendarEventMarker {
    i8 event_id;
    u8 day;
    u8 kind : 4;
    u8 column : 4;
    u8 row : 4;
    u8 unk_3_high : 4;
};

struct CalendarSceneCore : HardwareContext {
    explicit CalendarSceneCore(GameStateSaveImage * image);
    // The implicit virtual destructor releases the native members in reverse order.
    SceneTransitionOwner Run();
    void UpdateDialogue();
    void LoadGraphics();
    void BuildMonthGrid();
    void Draw();
    void DrawNumber(i32 x, i32 y, i32 value, i32 width, i32 palette);
    void DrawGlyph(i32 x, i32 y, i32 glyph, i32 palette);

    GameStateSaveImage * image;
    u32 unk_0C;
    GameSceneTalkWindowOwner ui;
    HardwareMusicPlayerSlot music_players[3];
    IndexedResourceArchive glyph_archive;
    IndexedResourceArchive marker_archive;
    IndexedResourceArchive cursor_archive;
    CalendarSprite glyph_sprite;
    CalendarSprite marker_sprite;
    CalendarSprite cursor_sprite;
    // Digits, year/season labels and weekday labels share this glyph archive.
    u16 glyph_tile_offsets[22];
    u16 marker_tile_offsets[4];
    ObjTileCollectionEntry glyph_tiles;
    ObjPaletteCollectionEntry weekday_palette;
    ObjPaletteCollectionEntry sunday_palette;
    ObjPaletteCollectionEntry saturday_palette;
    ObjTileCollectionEntry marker_tiles;
    ObjPaletteCollectionEntry marker_palette;
    ObjTileCollectionEntry cursor_tiles;
    ObjPaletteCollectionEntry cursor_palette;
    u8 days[6][7];
    GameDate date;
    i16 year;
    i16 season;
    u8 cursor_column;
    u8 cursor_row;
    i16 wedding_year;
    i16 wedding_season;
    i16 wedding_day;
    CalendarEventMarker events[10];
    i16 phase;
    i8 dialogue_phase;
    u16 selected_event;
    CalendarTextVariables text_variables;
};

typedef char CalendarSpriteSizeCheck[sizeof(CalendarSprite) == 0x30 ? 1 : -1];
typedef char CalendarMarkerSizeCheck[sizeof(CalendarEventMarker) == 4 ? 1 : -1];
typedef char CalendarCoreImageCheck[offsetof(CalendarSceneCore, image) == 8 ? 1 : -1];
typedef char CalendarCoreUiCheck[offsetof(CalendarSceneCore, ui) == 0x10 ? 1 : -1];
typedef char CalendarCoreArchiveCheck[offsetof(CalendarSceneCore, glyph_archive) == 0x20 ? 1 : -1];
typedef char CalendarCoreSpriteCheck[offsetof(CalendarSceneCore, glyph_sprite) == 0xB0 ? 1 : -1];
typedef char CalendarCoreGlyphOffsetsCheck[offsetof(CalendarSceneCore, glyph_tile_offsets) == 0x140 ? 1 : -1];
typedef char CalendarCoreMarkerOffsetsCheck[offsetof(CalendarSceneCore, marker_tile_offsets) == 0x16C ? 1 : -1];
typedef char CalendarCoreTileOwnerCheck[offsetof(CalendarSceneCore, glyph_tiles) == 0x174 ? 1 : -1];
typedef char CalendarCoreDaysCheck[offsetof(CalendarSceneCore, days) == 0x1B4 ? 1 : -1];
typedef char CalendarCoreDateCheck[offsetof(CalendarSceneCore, date) == 0x1DE ? 1 : -1];
typedef char CalendarCoreYearCheck[offsetof(CalendarSceneCore, year) == 0x1E0 ? 1 : -1];
typedef char CalendarCoreCursorCheck[offsetof(CalendarSceneCore, cursor_column) == 0x1E4 ? 1 : -1];
typedef char CalendarCoreWeddingCheck[offsetof(CalendarSceneCore, wedding_year) == 0x1E6 ? 1 : -1];
typedef char CalendarCoreEventsCheck[offsetof(CalendarSceneCore, events) == 0x1EC ? 1 : -1];
typedef char CalendarCorePhaseCheck[offsetof(CalendarSceneCore, phase) == 0x214 ? 1 : -1];
typedef char CalendarCoreDialogueCheck[offsetof(CalendarSceneCore, dialogue_phase) == 0x216 ? 1 : -1];
typedef char CalendarCoreSelectedEventCheck[offsetof(CalendarSceneCore, selected_event) == 0x218 ? 1 : -1];
typedef char CalendarCoreVariablesCheck[offsetof(CalendarSceneCore, text_variables) == 0x21C ? 1 : -1];
typedef char CalendarCoreSizeCheck[sizeof(CalendarSceneCore) == 0x228 ? 1 : -1];

#pragma interface "scene_calendar.hh"

#pragma interface "scene_calendar.hh"

// One-based day, unlike the packed zero-based GameDate save value.
struct PACKED CalendarFestivalDate
{
    u8 season;
    u8 day;
};

typedef char CalendarFestivalDateSizeCheck[sizeof(CalendarFestivalDate) == 2 ? 1 : -1];

extern CalendarFestivalDate const gCalendarFestivalDates[];
extern char const gText_Calendar_Spring[];
extern char const gText_Calendar_Summer[];
extern char const gText_Calendar_Autumn[];
extern char const gText_Calendar_Winter[];

extern char const gText_Calendar_Festival_NewYearFestival[];
extern char const gText_Calendar_Festival_SpringThanksgiving[];
extern char const gText_Calendar_Festival_SpringHorseRace[];
extern char const gText_Calendar_Festival_CookingFestival[];
extern char const gText_Calendar_Festival_BeachDay[];
extern char const gText_Calendar_Festival_ChickenFestival[];
extern char const gText_Calendar_Festival_CowFestival[];
extern char const gText_Calendar_Festival_FireworksFestival[];
extern char const gText_Calendar_Festival_MusicFestival[];
extern char const gText_Calendar_Festival_HarvestFestival[];
extern char const gText_Calendar_Festival_FullMoonFestival[];
extern char const gText_Calendar_Festival_FallHorseRace[];
extern char const gText_Calendar_Festival_SheepFestival[];
extern char const gText_Calendar_Festival_PumpkinFestival[];
extern char const gText_Calendar_Festival_WinterThanksgiving[];
extern char const gText_Calendar_Festival_StarryNightFestival[];
extern char const gText_Calendar_Festival_YearEndGathering[];
extern char const gText_Calendar_Festival_Marriage[];
extern char const gText_Calendar_Festival_WeddingAnniversary[];
extern char const gText_Calendar_Festival_NoPlans[];


#endif // SCENE_CALENDAR_CORE_HH
