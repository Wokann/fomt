#ifndef SCROLL_MENU_HH
#define SCROLL_MENU_HH

#include "prelude.h"
#include "hardware_context.hh"
#include "resource_handle.hh"
#include "smart_ptr.hh"

struct ScrollMenu;
struct ScrollState;

// Both row formats are selected by their vertical position while scrolling.
struct ScrollMenuSpriteRow
{
    i16 y;
    i32 x;
    u8 const * tiles;
    u16 const * palette;
};

struct ScrollMenuTransferRow
{
    i16 y;
    void const * source;
    void * destination;
    u32 size;
};

struct ScrollMenuSpriteRows
{
    ScrollMenuSpriteRow * first;
    ScrollMenuSpriteRow * last;
    u32 unk_08;
    ScrollMenuSpriteRow * capacity_end;
};

struct ScrollMenuTransferRows
{
    ScrollMenuTransferRow * first;
    ScrollMenuTransferRow * last;
    u32 unk_08;
    ScrollMenuTransferRow * capacity_end;
};

#pragma interface "scroll_menu.hh"
struct ScrollMenuPage
{
    ScrollMenuPage(ScrollMenu * menu, u32 unk_58c, u32 rows, char const * title);
    virtual ~ScrollMenuPage();
    virtual u32 Draw();

    void SetPosition(i16 position);
    i16 GetMaximumScrollPosition() const;
    ScrollState * GetScrollState() const;
    ScrollMenu * GetMenu() const;

    ScrollMenu * menu;
    ScrollState * scroll;
    u32 unk_08;
    // The title occupies 22 columns by two rows of 4bpp tiles.
    u8 title_tiles[22 * 2 * 32];
    u32 unk_58C;
    i16 scroll_position;
    ScrollMenuSpriteRows sprites;
    ScrollMenuTransferRows transfers;
};

// Each menu owns its current page and deletes it through the page interface.
typedef SmartPtr<ScrollMenuPage> ScrollMenuPageOwner;

struct ScrollMenuSprite
{
    i16 x;
    i16 y;
    IndexedResourceHandle handle;
    IndexedResourceSpriteParameters parameters;
    u8 unk_34;
};

#pragma interface "scroll_menu.hh"
struct ScrollMenu : HardwareContext
{
    ScrollMenu(u8 allow_select_exit);
    // RunScrollMenu dispatches left/right as 0/1 through virtual slot 0x0C.
    virtual void ChangePage(i32 direction) = 0;

    ScrollMenuPageOwner page;
    IndexedResourceArchive archive;
    ScrollMenuSprite scroll_up;
    ScrollMenuSprite scroll_down;
    ScrollMenuSprite next_page;
    ScrollMenuSprite previous_page;
    u8 allow_select_exit;
};

typedef char ScrollMenuSpriteRowSizeCheck[sizeof(ScrollMenuSpriteRow) == 16 ? 1 : -1];
typedef char ScrollMenuTransferRowSizeCheck[sizeof(ScrollMenuTransferRow) == 16 ? 1 : -1];
typedef char ScrollMenuPagePositionCheck[offsetof(ScrollMenuPage, scroll_position) == 0x590 ? 1 : -1];
typedef char ScrollMenuPageSpritesCheck[offsetof(ScrollMenuPage, sprites) == 0x594 ? 1 : -1];
typedef char ScrollMenuPageTransfersCheck[offsetof(ScrollMenuPage, transfers) == 0x5A4 ? 1 : -1];
typedef char ScrollMenuPageSizeCheck[sizeof(ScrollMenuPage) == 0x5B8 ? 1 : -1];
typedef char ScrollMenuSpriteSizeCheck[sizeof(ScrollMenuSprite) == 0x38 ? 1 : -1];
typedef char ScrollMenuPageOffsetCheck[offsetof(ScrollMenu, page) == 8 ? 1 : -1];
typedef char ScrollMenuArchiveOffsetCheck[offsetof(ScrollMenu, archive) == 0xC ? 1 : -1];
typedef char ScrollMenuSpritesOffsetCheck[offsetof(ScrollMenu, scroll_up) == 0x3C ? 1 : -1];
typedef char ScrollMenuSelectFlagCheck[offsetof(ScrollMenu, allow_select_exit) == 0x11C ? 1 : -1];
typedef char ScrollMenuSizeCheck[sizeof(ScrollMenu) == 0x120 ? 1 : -1];

EXTERN_C

void UpdateScrollMenu(ScrollMenu * menu);
void RunScrollMenu(ScrollMenu * menu);
void ClearScrollMenuPage(ScrollMenu * menu);
void SetScrollMenuPage(ScrollMenu * menu, ScrollMenuPage ** page);
void SetScrollMenuPosition(ScrollMenu * context, i16 scroll_position);
i16 GetScrollMenuPosition(ScrollMenu const * context);

EXTERN_C_END

extern u16 const gScrollMenuDigitGlyphs[];

#endif // SCROLL_MENU_HH
