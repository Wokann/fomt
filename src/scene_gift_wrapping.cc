#include "config.h"
#include "hardware_blend_owner.hh"
#include "hardware_input.hh"
#include "game_state.hh"
#include "world_runtime.hh"
#include "money_account.hh"
#include "rucksack.hh"
#include "prelude.h"
#include "scene_gift_wrapping.hh"

GiftWrappingSceneCore::GiftWrappingSceneCore(GameStateSaveImage * image)
    : GameSceneMenuSelectionCore(image), item_description(),
      held_tool(&save->farmer.unk_5C), held_item(&save->farmer.held_item),
      rucksack(&save->farmer.rucksack), phase(0)
{
}

GiftWrappingSceneCore::~GiftWrappingSceneCore()
{
}

void GiftWrappingSceneCore::DrawTools(u32 count)
{
    for (u32 index = 0; index < count; ++index)
    {
        ToolStack stack = rucksack->GetToolAt(index);
        if (!stack.IsEmpty())
        {
#if defined(REGION_EU) || defined(REGION_DE)
            // Upgrade levels are stored by Farmer, not by the inventory slot.
            Tool base_tool = stack.GetTool();
            Tool tool = save->farmer.GetUpgradedTool(base_tool);
#else
            Tool tool = stack.GetTool();
#endif
            u16 icon = tool.GetIconId();
#if defined(REGION_JP)
            func_080CB304(left_panel.value, index, gUnk_083ED9FC, icon, stack.GetAmount());
#else
            func_080CB304(left_panel.value, index, gUnk_086678A0, icon, stack.GetAmount());
#endif
        }
    }
    if (!held_tool->IsEmpty())
    {
#if defined(REGION_EU) || defined(REGION_DE)
        Tool base_tool = held_tool->GetTool();
        Tool tool = save->farmer.GetUpgradedTool(base_tool);
#else
        Tool tool = held_tool->GetTool();
#endif
        u16 icon = tool.GetIconId();
#if defined(REGION_JP)
        func_080CBAF0(left_panel.value, gUnk_083ED9FC, icon, held_tool->GetAmount());
#else
        func_080CBAF0(left_panel.value, gUnk_086678A0, icon, held_tool->GetAmount());
#endif
    }
}

void GiftWrappingSceneCore::DrawItems(u32 count)
{
    for (u32 index = 0; index < count; ++index)
    {
        RucksackItem item = rucksack->GetItemAt(index);
        if (!item.IsEmpty())
        {
            u16 icon = 0;
            switch (item.GetKind())
            {
            case RucksackItem::KIND_FOOD:
                icon = item.GetFood().GetIconId();
                break;
            case RucksackItem::KIND_ARTICLE:
                icon = item.GetArticle().GetIconId();
                break;
            }
            if (item.IsWrapped())
                icon = 0x160;
#if defined(REGION_JP)
            func_080CC728(right_panel.value, index, gUnk_083ED9FC, icon, 1);
#else
            func_080CC728(right_panel.value, index, gUnk_086678A0, icon, 1);
#endif
        }
    }
    if (!IsHeldItemEmpty(held_item))
    {
        switch (held_item->GetKind())
        {
        case HeldItem::KIND_FOOD:
        {
            u16 icon = func_0800F20C(held_item).GetIconId();
            if (func_0800F294(held_item).IsWrapped())
                icon = 0x160;
#if defined(REGION_JP)
            func_080CCE58(right_panel.value, gUnk_083ED9FC, icon, 1);
#else
            func_080CCE58(right_panel.value, gUnk_086678A0, icon, 1);
#endif
            break;
        }
        case HeldItem::KIND_ARTICLE:
        {
            u16 icon = held_item->GetArticle().GetIconId();
            if (func_0800F294(held_item).IsWrapped())
                icon = 0x160;
#if defined(REGION_JP)
            func_080CCE58(right_panel.value, gUnk_083ED9FC, icon, 1);
#else
            func_080CCE58(right_panel.value, gUnk_086678A0, icon, 1);
#endif
            break;
        }
        case HeldItem::KIND_DOG:
            if (save->dog.GetGrowthStage() == 0)
                func_080CCE58(right_panel.value, gActorIndexedResourceArchive, 0x3DA, 1);
            else
                func_080CCE58(right_panel.value, gActorIndexedResourceArchive, 0x374, 1);
            break;
        case HeldItem::KIND_CHICKEN:
        {
            int slot = GetHeldChickenSlot(held_item);
            Chicken * chicken = save->farm.coop.GetChicken(slot);
            if (chicken != nullptr)
            {
                if (chicken->GetGrowthStage() == 0)
                    func_080CCE58(right_panel.value, gActorIndexedResourceArchive, 0x73D, 1);
                else
                    func_080CCE58(right_panel.value, gActorIndexedResourceArchive, 0x734, 1);
            }
            break;
        }
        case HeldItem::KIND_BASKET:
#if defined(REGION_JP)
            func_080CCE58(right_panel.value, gUnk_083ED9FC, 0x35, 1);
#else
            func_080CCE58(right_panel.value, gUnk_086678A0, 0x35, 1);
#endif
            break;
        case HeldItem::KIND_ACTOR_GRAPHIC:
            break;
        }
    }
}

void GiftWrappingSceneCore::UpdateDescription(i32 selection)
{
    char const * text = nullptr;
    item_description[0] = '\0';
    switch (selection)
    {
    case 0:
        if (!held_tool->IsEmpty())
            text = FormatMenuToolDescription(this, item_description, held_tool->GetTool(), 1);
        break;
    case 9:
        if (!IsHeldItemEmpty(held_item))
            text = FormatMenuHeldItemDescription(this, item_description, held_item);
        break;
    default:
        if (selection <= 8)
        {
            if (!rucksack->GetToolAt(GetItemIndex(selection, 0)).IsEmpty())
                text = FormatMenuToolDescription(this, item_description,
                    rucksack->GetToolAt(GetItemIndex(selection, 0)).GetTool(), 0);
        }
        else
        {
            RucksackItem item = rucksack->GetItemAt(GetItemIndex(selection, 0));
            if (!item.IsEmpty())
                text = func_080CFA38(this, item_description, item);
        }
        break;
    }
    if (text != nullptr)
        func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(text), 0, 0);
    else
        func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_EmptyDescription), 0, 0);
}

void GiftWrappingSceneCore::BeginWrap(i32 selection)
{
    if (selection == 0)
    {
        if (held_tool->IsEmpty())
            music.Start(0xC7);
        else
        {
            func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
            ui.ShowPortrait(0x43);
            phase = 2;
            music.Start(0xC7);
        }
    }
    else if (selection <= 8)
    {
        ToolStack tool = rucksack->GetToolAt(GetItemIndex(selection, 0));
        if (tool.IsEmpty())
            music.Start(0xC7);
        else
        {
            func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
            ui.ShowPortrait(0x43);
            phase = 2;
            music.Start(0xC7);
        }
    }
    else if (selection == 9)
    {
        if (IsHeldItemEmpty(held_item))
        {
            music.Start(0xC7);
            return;
        }
        switch (held_item->GetKind())
        {
        case HeldItem::KIND_FOOD:
            if (func_0800F388(held_item))
            {
                func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
                ui.ShowPortrait(0x43);
                phase = 2;
                music.Start(0xC7);
            }
            else
            {
                func_08050E30(&ui, gText_GiftWrap_Confirm, gText_GiftWrap_Yes, gText_GiftWrap_No, nullptr, nullptr, nullptr);
                ui.ShowPortrait(0x43);
                phase = 1;
            }
            break;
        case HeldItem::KIND_ARTICLE:
            if (func_0800F388(held_item))
            {
                func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
                ui.ShowPortrait(0x43);
                phase = 2;
                music.Start(0xC7);
            }
            else if (!held_item->GetArticle().CanBeDiscarded())
            {
                func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
                ui.ShowPortrait(0x43);
                phase = 2;
                music.Start(0xC7);
            }
            else
            {
                func_08050E30(&ui, gText_GiftWrap_Confirm, gText_GiftWrap_Yes, gText_GiftWrap_No, nullptr, nullptr, nullptr);
                ui.ShowPortrait(0x43);
                phase = 1;
            }
            break;
        case HeldItem::KIND_DOG:
            func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_DogWarning), 0, 0);
            ui.ShowPortrait(0x45);
            phase = 2;
            music.Start(0xC7);
            break;
        default:
            func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
            ui.ShowPortrait(0x43);
            phase = 2;
            music.Start(0xC7);
            break;
        }
    }
    else
    {
        RucksackItem item = rucksack->GetItemAt(GetItemIndex(selection, 0));
        if (item.IsEmpty())
            music.Start(0xC7);
        else if (item.IsWrapped())
        {
            func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
            ui.ShowPortrait(0x43);
            phase = 2;
            music.Start(0xC7);
        }
        else if (item.GetKind() == RucksackItem::KIND_FOOD)
        {
            func_08050E30(&ui, gText_GiftWrap_Confirm, gText_GiftWrap_Yes, gText_GiftWrap_No, nullptr, nullptr, nullptr);
            ui.ShowPortrait(0x43);
            phase = 1;
        }
        else if (!item.GetArticle().CanBeDiscarded())
        {
            func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_CannotWrap), 0, 0);
            ui.ShowPortrait(0x43);
            phase = 2;
            music.Start(0xC7);
        }
        else
        {
            func_08050E30(&ui, gText_GiftWrap_Confirm, gText_GiftWrap_Yes, gText_GiftWrap_No, nullptr, nullptr, nullptr);
            ui.ShowPortrait(0x43);
            phase = 1;
        }
    }
}

void GiftWrappingSceneCore::WrapItem(i32 selection)
{
    if (selection == 9)
    {
        func_0800F528(held_item);
#if defined(REGION_JP)
        func_080CCE58(right_panel.value, gUnk_083ED9FC, 0x160, 1);
#else
        func_080CCE58(right_panel.value, gUnk_086678A0, 0x160, 1);
#endif
    }
    else
    {
        rucksack->GetItemAt(GetItemIndex(selection, 0)).TryWrap();
        GameMenuSpritePanel * panel = right_panel.value;
#if defined(REGION_JP)
        func_080CC728(panel, GetItemIndex(selection, 0), gUnk_083ED9FC, 0x160, 1);
#else
        func_080CC728(panel, GetItemIndex(selection, 0), gUnk_086678A0, 0x160, 1);
#endif
    }
    SubtractMoneyFromAccount(&save->money_account, 100);
    save->npcs.AddUnk00_6(1);
}

void GiftWrappingSceneCore::Run()
{
    EnableHardwareForcedBlank(this);
    func_080CE294(this);
    u32 count = rucksack->GetSize();
    left_panel = new GameMenuTilemapPanel(
            GetHardwareDmaQueue(reinterpret_cast<void * const *>(this)),
            GetHardwareCommandList(reinterpret_cast<void * const *>(this)), count, gText_GiftWrap_Tools, true);
    func_080CB090(left_panel.value);
    DrawTools(count);
    right_panel = new GameMenuSpritePanel(
            GetHardwareDmaQueue(reinterpret_cast<void * const *>(this)),
            GetHardwareCommandList(reinterpret_cast<void * const *>(this)), count, gText_GiftWrap_Items, true);
    func_080CC310(right_panel.value);
    DrawItems(count);
    cursor = new GameSceneMenuCursorData(this, 1);
    sprite = new GameSceneMenuSpriteData(this);
    UpdateDescription(cursor.value->selection);
    HardwareDisplayRegisterValue display_value;
    GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->SetBlendControl(display_value = BLDCNT_TGT1_ALL);
    HardwareBlendOwner blend(new HardwareBlendObject(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))));
    blend.object->blend.Begin(0x889, 1, 1);
    GetHardwareCommandList(reinterpret_cast<void * const *>(this))->Append(blend.object);
    bool finished = false;
    bool leave = false;
    for (;;)
    {
        UpdateHardwareFrame(this);
        UpdateHardwareInput(reinterpret_cast<void * const *>(this));
        Update();
        if (blend.IsQueued())
            continue;
        if (finished)
            return;
        i32 previous = cursor.value->selection;
        switch (phase)
        {
        case 0:
            if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_UP))
            {
                cursor.value->MoveUp();
                music.Start(0xCB);
            }
            else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_DOWN))
            {
                cursor.value->MoveDown();
                music.Start(0xCB);
            }
            else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_RIGHT))
            {
                func_080CDCD0(cursor.value);
                music.Start(0xCB);
            }
            else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_LEFT))
            {
                cursor.value->MoveLeft();
                music.Start(0xCB);
            }
            else
            {
                bool switch_panel = false;
                if (HardwareKeySnapshot::ShoulderBits(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)), R_BUTTON)
                    || HardwareKeySnapshot::ShoulderBits(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)), L_BUTTON))
                    switch_panel = true;
                if (switch_panel)
                {
                    cursor.value->SwitchPanel();
                    music.Start(0xCB);
                }
                else if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & A_BUTTON))
                    BeginWrap(cursor.value->selection);
                else if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & B_BUTTON))
                {
                    func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_Recommendation), 0, 0);
                    ui.ShowPortrait(0x43);
                    leave = true;
                    phase = 2;
                }
            }
            if (previous != cursor.value->selection)
                UpdateDescription(cursor.value->selection);
            break;
        case 1:
            if (unk_88 == 3)
            {
                switch (ui.GetChoiceResult())
                {
                case 1:
                    func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_Complete), 0, 0);
                    ui.ShowPortrait(0x43);
                    WrapItem(cursor.value->selection);
                    leave = true;
                    phase = 2;
                    break;
                case 2:
                    func_08050DC8(reinterpret_cast<void * const *>(&ui), reinterpret_cast<u32>(gText_GiftWrap_SelectItem), 0, 0);
                    ui.ShowPortrait(0x43);
                    phase = 2;
                    break;
                }
            }
            break;
        case 2:
            if (unk_88 == 3)
            {
                func_08050E5C(reinterpret_cast<void * const *>(&ui));
                if (leave)
                {
                    if (!blend.IsQueued())
                    {
                        finished = true;
                        blend.object->blend.End(0x889, 1, 1);
                        GetHardwareCommandList(reinterpret_cast<void * const *>(this))->Append(blend.object);
                    }
                    phase = 0;
                }
                else
                    UpdateDescription(cursor.value->selection);
                phase = 0;
            }
            break;
        }
    }
}


GiftWrappingScene::GiftWrappingScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(new GiftWrappingSceneCore(image)), continuation(next)
{
}

inline GiftWrappingSceneCoreOwner::~GiftWrappingSceneCoreOwner() { delete value; }

GiftWrappingScene::~GiftWrappingScene()
{
}

SceneTransitionOwner GiftWrappingScene::Run()
{
    core.value->Run();
    return continuation;
}

// The leading library literal is emitted through the existing <new> dependency.
#include FOMT_TEXT_INCLUDE(scene_gift_wrapping.cc)
