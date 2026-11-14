#ifndef GAME_MENU_HH
#define GAME_MENU_HH

#include "prelude.h"
#include "hardware_context.hh"
#include "utility/fixed_str.hh"
#include "game_menu_command_queue.hh"

#include "game_menu_panels.hh"
// Target selection indices: left header 0, left cells 1..8,
// right header 9 and right cells 10..17.
struct MenuGridNavigation {
    i32 up;
    i32 down;
    i32 left;
    i32 right;
};
typedef char MenuGridNavigationSizeCheck[sizeof(MenuGridNavigation) == 16 ? 1 : -1];
typedef char MenuGridNavigationDownCheck[offsetof(MenuGridNavigation, down) == 4 ? 1 : -1];
typedef char MenuGridNavigationLeftCheck[offsetof(MenuGridNavigation, left) == 8 ? 1 : -1];
typedef char MenuGridNavigationRightCheck[offsetof(MenuGridNavigation, right) == 12 ? 1 : -1];
extern MenuGridNavigation const gMenuGridNavigation[18];

extern char const gText_ToolStatus_GemOfTruth[];
extern char const gText_ToolStatus_EnergyLabel[];
extern char const gText_ToolStatus_ValueSeparator[];
extern char const gText_ToolStatus_EnergyFatigueLineBreak[];
extern char const gText_ToolStatus_FatigueLabel[];
extern char const gText_ToolStatus_FatigueMaximum[];
extern char const gText_ToolStatus_PedometerLabel[];
extern char const gText_ToolStatus_PedometerStepsSuffix[];

#if defined(REGION_JP)
extern char const gText_ToolStatus_DescriptionQuoteOpen[];
extern char const gText_ToolStatus_DescriptionQuoteClose[];
extern char const gText_ToolStatus_RemainingSquaresPrefix[];
extern char const gText_ToolStatus_RemainingSquaresSuffix[];
#else
extern char const gText_ToolStatus_DescriptionQuotePrefix[];
extern char const gText_ToolStatus_RemainingSquaresSuffix[];
#endif

extern char const gText_AnimalStatus_Dog[];
extern char const gText_AnimalStatus_Puppy[];
extern char const gText_AnimalStatus_Chicken[];
extern char const gText_AnimalStatus_Chick[];
extern char const gText_AnimalStatus_Sick[];
extern char const gText_AnimalStatus_Unhappy[];
extern char const gText_AnimalStatus_Healthy[];

extern char const gText_ItemStatus_BasketName[];
extern char const gText_ItemStatus_BasketDescription[];
#if defined(REGION_JP)
extern char const gText_ItemStatus_BasketHoldingSuffix[];
#else
extern char const gText_ItemStatus_BasketHoldingPrefix[];
extern char const gText_ItemStatus_BasketHoldingSuffix[];
#endif
extern char const gText_ItemStatus_WrappedAsPresent[];
extern char const * const gItemStatusWrappedAsPresentTextRef;

extern char const gText_ItemDiscard_Confirm[];
extern char const * const gItemDiscardConfirmTextRef;
extern char const gText_ItemDiscard_CannotDiscard[];
extern char const * const gItemDiscardCannotDiscardTextRef;
extern char const gText_ItemDiscard_Cursed[];
extern char const * const gItemDiscardCursedTextRef;

struct GameStateSaveImage;
struct Tool;
struct HeldItem;
struct RucksackItem;

#include "game_menu_lifetimes.hh"

// Both concrete panels place the same state immediately after their base.
// These native accessors take that base pointer, not an invented derived view.
u32 GetMenuPanelItemCount(GameMenuPanel const *);
u8 GetMenuPanelHeaderEnabled(GameMenuPanel const *);


extern "C" {
#if defined(REGION_JP)
extern u8 const gUnk_084DABB8[];
#else
extern u8 const gUnk_08754C0C[];
#endif
}

extern "C" u8 const gUiHandCursorArchive[];

extern "C" {
// Actual existing native entries, not generated wrappers or aliases.
void func_080CE294(GameSceneMenuCorePrefix *);
i32 func_080CDCD0(GameSceneMenuCursorData *);
char const * FormatMenuToolDescription(GameSceneMenuCorePrefix *, FixedStr<99> &,
    Tool const &, u8 held);
char const * FormatMenuHeldItemDescription(GameSceneMenuCorePrefix *, FixedStr<99> &,
    HeldItem const *);
char const * func_080CFA38(GameSceneMenuCorePrefix *, FixedStr<99> &, RucksackItem);
void UpdateMenuCursorRendering(GameSceneMenuCursorData *);
void UpdateMenuSpriteRendering(GameSceneMenuSpriteData *);
void UpdateMenuTilemapRendering(GameSceneMenuTilemapData *);
void UpdateMenuPanelSprites(GameMenuPanel *, HardwareSpriteBufferState *);
}


#endif // GAME_MENU_HH
