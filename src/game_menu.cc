#include "prelude.h"
#include "new_game.hh"
#include <new>

#pragma implementation "game_menu.hh"
#include "game_menu.hh"

GameSceneMenuCorePrefix::GameSceneMenuCorePrefix(GameStateSaveImage * image)
    : save(image), music(1),
#if defined(REGION_JP)
      archive(gUnk_084DABB8),
#else
      archive(gUnk_08754C0C),
#endif
      resource_state(&archive, 0, 0x100), unk_78(), unk_7C(),
      ui(0, 29, 0, 0, HardwareStateOwner(), HardwareResource())
{
}

void GameSceneMenuCorePrefix::Update()
{
    // The existing C hardware interface views the first native owner pointer.
    void * const * hardware_owner = reinterpret_cast<void * const *>(this);
    unk_84 = ui.GetState();
    HardwareCoreState * hardware = static_cast<HardwareCoreState *>(GetHardwareCoreState(hardware_owner));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(hardware_owner);
    HardwareDisplayState * display = GetHardwareDisplayState(hardware_owner);
    HardwareLinkedList * links = GetHardwareCommandList(hardware_owner);
    HardwareInterruptList * manager = GetHardwareInterruptList(hardware_owner);
    HardwareMusicPlayerSlot * music_player = &music;
    unk_88 = ui.Update(hardware, sprites, display, links, manager, music_player);
    if (unk_78.value != nullptr)
        unk_78.value->vfunc_0C();
    GameSceneMenuOwnedDataPrefix * renderer = unk_7C.value;
    if (renderer != nullptr) {
#if defined(REGION_JP)
        loc_080CBD9C(renderer, GetHardwareSpriteBuffer(hardware_owner));
#else
        func_080CC58C(renderer, GetHardwareSpriteBuffer(hardware_owner));
#endif
    }
}

void GameSceneMenuCommandQueue::ClearNodes()
{
    GameSceneMenuCommandNode * node = sentinel->next;
    while (node != sentinel) {
        GameSceneMenuCommandNode * old = node;
        node = node->next;
        if (old != nullptr)
            free(old);
    }
    GameSceneMenuCommandNode * head = sentinel;
    head->next = head;
    head->previous = head;
}

GameSceneMenuTilemapData::~GameSceneMenuTilemapData()
{
    GameSceneMenuCommandIterator current = commands.Begin();
    GameSceneMenuCommandIterator end = commands.End();
    for (; current != end; ++current)
        delete *current;
}

GameSceneMenuCursorData::GameSceneMenuCursorData(GameSceneMenuCorePrefix * owner, u32 input)
    : core(owner), selection(input), previous(input), state(2), resource(),
      archive(gUiHandCursorArchive), sprite(&archive, 0, 0x100)
{
    left_limit = static_cast<GameSceneMenuOwnedDataState *>(core->unk_78.value)->GetUnk298();
    right_limit = static_cast<GameSceneMenuOwnedDataState *>(core->unk_7C.value)->GetUnk298() + 9;
}

inline void GameSceneMenuCursorData::RefreshBounds()
{
    left_limit = static_cast<GameSceneMenuOwnedDataState *>(core->unk_78.value)->GetUnk298();
    right_limit = static_cast<GameSceneMenuOwnedDataState *>(core->unk_7C.value)->GetUnk298() + 9;
}

i32 GameSceneMenuCursorData::MoveUp()
{
    RefreshBounds();
    i32 next = gMenuGridNavigation[selection].up;
    if (selection == 0)
    {
        if (previous != 9)
        {
            u32 column = previous - 5;
            next = previous + 4;
            if (column <= 3)
                next = previous;
        }
    }
    else if (selection == 9 && previous != 0)
    {
        u32 column = previous - 14;
        next = previous + 4;
        if (column <= 3)
            next = previous;
    }
    i32 old;
    if (next <= 8)
    {
        old = selection;
        if (next == 0 && static_cast<GameSceneMenuOwnedDataState *>(core->unk_78.value)->GetUnk27C() == 0)
            next = old + 4;
        while (next > left_limit)
            next = gMenuGridNavigation[next].up;
    }
    else
    {
        old = selection;
        if (next == 9 && static_cast<GameSceneMenuOwnedDataState *>(core->unk_7C.value)->GetUnk27C() == 0)
            next = old + 4;
        while (next > right_limit)
            next = gMenuGridNavigation[next].up;
    }
    if (next != old)
    {
        previous = old;
        selection = next;
    }
    return next;
}

i32 GameSceneMenuCursorData::MoveDown()
{
    RefreshBounds();
    i32 next = gMenuGridNavigation[selection].down;
    if (selection == 0)
    {
        if (previous != 9)
        {
            u32 column = previous - 1;
            next = previous - 4;
            if (column <= 3)
                next = previous;
        }
    }
    else if (selection == 9 && previous != 0)
    {
        u32 column = previous - 10;
        next = previous - 4;
        if (column <= 3)
            next = previous;
    }
    i32 old;
    if (next <= 8)
    {
        old = selection;
        if (next == 0 && static_cast<GameSceneMenuOwnedDataState *>(core->unk_78.value)->GetUnk27C() == 0)
            next = old - 4;
        while (next > left_limit)
        {
            next = gMenuGridNavigation[next].down;
            if (next == 0 && static_cast<GameSceneMenuOwnedDataState *>(core->unk_78.value)->GetUnk27C() == 0)
                next = old;
        }
    }
    else
    {
        old = selection;
        if (next == 9 && static_cast<GameSceneMenuOwnedDataState *>(core->unk_7C.value)->GetUnk27C() == 0)
            next = old - 4;
        while (next > right_limit)
        {
            next = gMenuGridNavigation[next].down;
            if (next == 9 && static_cast<GameSceneMenuOwnedDataState *>(core->unk_7C.value)->GetUnk27C() == 0)
                next = old;
        }
    }
    if (next != old)
    {
        previous = old;
        selection = next;
    }
    return next;
}

i32 GameSceneMenuCursorData::MoveLeft()
{
    RefreshBounds();
    i32 next = gMenuGridNavigation[selection].left;
    if (next <= 8)
    {
        if (next == 0)
        {
            u8 header = static_cast<GameSceneMenuOwnedDataState *>(core->unk_78.value)->GetUnk27C();
            if (header == 0)
                next = selection;
        }
        else
        {
            while (next > left_limit)
            {
                if (left_limit <= 4)
                    next = left_limit;
                else
                    next = gMenuGridNavigation[next].left;
            }
        }
        if (next == 4 && previous == left_limit && previous > 4)
            next = previous;
    }
    else
    {
        if (next == 9)
        {
            u8 header = static_cast<GameSceneMenuOwnedDataState *>(core->unk_7C.value)->GetUnk27C();
            if (header == 0)
                next = 0;
        }
        else
        {
            while (next > right_limit)
            {
                if (right_limit <= 13)
                    next = right_limit;
                else
                    next = gMenuGridNavigation[next].left;
            }
        }
        if (next == 13 && previous == right_limit && previous > 13)
            next = previous;
    }
    if (next != selection)
    {
        previous = selection;
        selection = next;
    }
    return next;
}

i32 GameSceneMenuCursorData::SwitchPanel()
{
    i32 next = 10;
    if (selection < 9)
    {
        if (core->unk_7C.value == nullptr)
            next = selection;
    }
    else
    {
        GameSceneMenuOwnedDataPrefix * destination = core->unk_78.value;
        next = 1;
        if (destination == nullptr)
            next = selection;
    }
    if (next != selection)
    {
        previous = selection;
        selection = next;
    }
    return next;
}

void GameSceneMenuCursorData::SetSelection(i32 next)
{
    RefreshBounds();
    previous = selection;
    selection = next;
}

GameSceneMenuSpriteData::GameSceneMenuSpriteData(GameSceneMenuCorePrefix * owner)
    : core(owner),
#if defined(REGION_JP)
      archive(gUnk_084DABB8),
#else
      archive(gUnk_08754C0C),
#endif
      sprite(&archive, 1, 0x100), state(4), resource(),
      unk_7C(18), unk_80(0), unk_84(0)
{
}

GameSceneMenuSelectionCore::GameSceneMenuSelectionCore(GameStateSaveImage * image)
    : GameSceneMenuCorePrefix(image), cursor(), sprite(), tilemap()
{
}

void GameSceneMenuSelectionCore::Update()
{
    if (cursor.value != nullptr)
        func_080CDDD4(cursor.value);
    if (sprite.value != nullptr)
        func_080CECE8(sprite.value);
    if (tilemap.value != nullptr) {
#if defined(REGION_JP)
        loc_080CDFA0(tilemap.value);
#else
        func_080CE790(tilemap.value);
#endif
    }
    GameSceneMenuCorePrefix::Update();
}

MenuGridPosition GetMenuGridLeftCellPosition(GameSceneMenuOwnedDataPrefix const *, i32 index)
{
    return gMenuGridCellPositions[index];
}

MenuGridPosition GetMenuGridLeftHeaderPosition(GameSceneMenuOwnedDataPrefix const *)
{
    return gMenuGridHeaderPosition;
}

MenuGridPosition GetMenuGridRightCellPosition(GameSceneMenuOwnedDataPrefix const *, i32 index)
{
    MenuGridPosition position = gMenuGridCellPositions[index];
    position.x += 120;
    return position;
}

MenuGridPosition GetMenuGridRightHeaderPosition(GameSceneMenuOwnedDataPrefix const *)
{
    MenuGridPosition position = gMenuGridHeaderPosition;
    position.x += 120;
    return position;
}

MenuGridPosition GameSceneMenuCorePrefix::GetCursorPosition(i32 index) const
{
    MenuGridPosition position;
    switch (index) {
    case 0:
        if (unk_78.value != nullptr)
            position = GetMenuGridLeftHeaderPosition(unk_78.value);
        break;
    case 9:
        if (unk_7C.value != nullptr)
            position = GetMenuGridRightHeaderPosition(unk_7C.value);
        break;
    default:
        if (index <= 8) {
            if (unk_78.value != nullptr)
                position = GetMenuGridLeftCellPosition(unk_78.value, index - 1);
        } else {
            if (unk_7C.value != nullptr)
                position = GetMenuGridRightCellPosition(unk_7C.value, index - 10);
        }
        break;
    }
    return position;
}

i32 GameSceneMenuCorePrefix::GetItemIndex(i32 selection, i32 page) const
{
    i32 offset;
    if (selection <= 8)
        offset = (page << 3) - 1;
    else
        offset = (page << 3) - 10;
    return selection + offset;
}

void GameSceneMenuSpriteData::Show(i32 selection, u32 page)
{
    unk_84 = 1;
    sprite.unk_34 = 1;
    // Wait until the current animation wraps.
    for (;;) {
        if (UpdateIndexedResourceHandle(&sprite.handle).flags.wrapped)
            break;
    }
    MenuGridPosition position = core->GetCursorPosition(selection);
    sprite.unk_00 = position.x + 8;
    sprite.unk_02 = position.y;
    unk_7C = selection;
    unk_80 = page;
}

void GameSceneMenuSpriteData::Hide()
{
    unk_84 = 0;
    sprite.unk_34 = 0;
    unk_7C = 18;
    unk_80 = 0;
}
