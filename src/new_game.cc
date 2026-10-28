#include "new_game.hh"
#include "new_game_identity.hh"
#include "new_game_name_input.hh"
#include "intro_scene.hh"
#include "new_game_data.hh"
#include "farm_status_screen_data.hh"
#include "game_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_accessors.hh"
#include "hardware_state_clear.hh"
#include "hardware_blend_object.hh"
#include "hardware_display_state.hh"
#include "hardware_sprite_buffer.hh"
#include "hardware_dma.hh"
#include "hardware_interrupt_guard.hh"
#include "hardware_music_player.hh"
#include "sram_image.hh"
#include "ui_state.hh"
#include <string.h>
#include "game_scene.hh"
#pragma implementation

// Keep the GNU C++ tables and partial-core tables in retail ROM order.
// Their real ABI labels have one definition each; no aliases are used.
NewGameNativeVTableEntry __vt_26NewGameFreshSaveTransition[4] = {
    nullptr, nullptr,
    reinterpret_cast<NewGameNativeVTableEntry>(DestroyFreshSaveGameTransition),
    reinterpret_cast<NewGameNativeVTableEntry>(CreateFreshSaveGameScene),
};
NewGameNativeVTableEntry __vt_21NewGameNameEntryScene[4] = {
    nullptr, nullptr,
    reinterpret_cast<NewGameNativeVTableEntry>(func_08004C54),
    reinterpret_cast<NewGameNativeVTableEntry>(func_08004C68),
};
void * operator new(unsigned long);
void operator delete(void *);
inline void * operator new(unsigned long, void * location) { return location; }
inline void * operator new[](unsigned long, void * location) { return location; }

static inline void QueueMenuBlend(HardwareBootstrap * core, HardwareBlendObject & blend)
{
    HardwareLinkedList * list =
        GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    list->Append(&blend);
}

static inline bool MenuBlendIsQueued(HardwareBlendObject const & blend)
{
    return blend.previous_slot != nullptr;
}

static inline u32 SpriteTileIndex(HardwareStateEntry & entry)
{
    return GetHardwareSharedStateTileIndex(&entry, entry.handle);
}

static inline u32 SpritePaletteBank(HardwareResourceEntry & entry)
{
    return GetHardwarePoolHandleIndex(&entry, entry.handle);
}

NewGameNameEntryScene::NewGameNameEntryScene() {}

NewGameNameEntryScene::~NewGameNameEntryScene() {}

SceneTransitionOwner NewGameNameEntryScene::Run()
{
    HardwareManagerOwner manager;
    func_08008DB8(0x23);
    FixedStr<12> player_name ALIGN(4);
    FixedStr<12> farm_name ALIGN(4);
    FixedStr<12> dog_name ALIGN(4);
    GameDate birthday(SEASON_SPRING, 0);
    u8 confirmed;
    do {
        {
            NewGameNameInputScene input(gText_NewGameIdentity_PlayerPrefix, player_name);
            input.Run();
            player_name = input.GetName();
        }
        {
            NewGameBirthdayInputScene input(birthday);
            input.Run();
            birthday = input.GetDate();
        }
        {
            NewGameNameInputScene input(gText_NewGameIdentity_FarmPrefix, farm_name);
            input.Run();
            farm_name = input.GetName();
        }
        {
            NewGameNameInputScene input(gText_NewGameIdentity_DogPrefix, dog_name);
            input.Run();
            dog_name = input.GetName();
        }
        {
            NewGameIdentityScene input(player_name, birthday, farm_name, dog_name);
            input.Run();
            confirmed = input.GetConfirmed();
        }
    } while (!confirmed);
    return SceneTransitionOwner(new NewGameFreshSaveTransition(
        farm_name, player_name, birthday, dog_name));
}

SceneOwner NewGameFreshSaveTransition::CreateScene()
{
    return SceneOwner(new GameSceneScriptController(farm_name,
        player_name, birthday, dog_name));
}

// The native slot forwards to base cleanup; the fixed strings have trivial destruction.
void DestroyFreshSaveGameTransition(NewGameFreshSaveTransition * transition, int flags)
{
    DestroySceneTransitionBase(reinterpret_cast<SceneTransition *>(transition), flags);
}

// The birthday UI wraps invalid day fields; ordinary GameDate construction
// elsewhere retains its existing packed-value semantics.
static inline void SetBirthdayInputDate(GameDate & destination, Season season,
    u32 const & requested_day)
{
    destination.season = season;
    u32 day = requested_day;
    if (day > 29)
        day %= 30;
    destination.day = day;
}

NewGameBirthdayInputCore * InitializeBirthdayInputCore(NewGameBirthdayInputCore * core, GameDate birthday)
{
    HardwareInputRepeatParameters input(30, 1);
    ConstructHardwareBootstrapWithInput(core, &input);
#if defined(REGION_JP)
    core->vtable = reinterpret_cast<void **>(const_cast<NewGameSceneVTableFunction *>(vtable_unk_080E7AB4));
#else
    core->vtable = reinterpret_cast<void **>(const_cast<NewGameSceneVTableFunction *>(vtable_unk_080E7AC4));
#endif
    core->unk_08 = 0;
    // Allocate the owner before acquiring its temporary shared resources.
    void * storage = ::operator new(sizeof(UiStateOwner));
    {
        HardwareStateOwner shared;
        HardwareResource resources;
        core->ui_state = new (storage) UiStateOwner(0, 31, 15, core->unk_08, shared, resources);
    }
    new (&core->music_players[0]) HardwareMusicPlayerSlot(1);
    new (&core->music_players[1]) HardwareMusicPlayerSlot(2);
    new (&core->glyph_tiles) HardwareStateEntry(7);
    new (&core->glyph_palette) HardwareResourceEntry;
    new (&core->cursor_tiles) HardwareStateEntry(3);
    new (&core->cursor_palette) HardwareResourceEntry;
    SetBirthdayInputDate(core->birthday, birthday.GetSeason(), birthday.GetDay());
    core->step = 0;
    core->dialogue_state = 2;
    switch (core->birthday.GetSeason()) {
    case SEASON_SPRING: core->season_column = 0; break;
#if defined(REGION_JP)
    case SEASON_SUMMER: core->season_column = 1; break;
    case SEASON_FALL: core->season_column = 2; break;
    case SEASON_WINTER: core->season_column = 3; break;
#else
    case SEASON_SUMMER: core->season_column = 4; break;
    case SEASON_FALL: core->season_column = 8; break;
    case SEASON_WINTER: core->season_column = 12; break;
#endif
    }
    core->day = core->birthday.GetDay() + 1;
    core->cursor_column = core->season_column;
    core->cursor_row = 0;
    core->saved_season_column = 0;
    core->cursor_visible = 0;
    return core;
}

// The core still has an explicit native callback table. End the constructed
// member lifetimes in their original order and forward the deleting flags to
// the existing base destructor rather than inventing another deletion layer.
void DestroyBirthdayInputCore(NewGameBirthdayInputCore * core, u32 flags)
{
    core->cursor_palette.~HardwareResourceEntry();
    core->cursor_tiles.~HardwareStateEntry();
    core->glyph_palette.~HardwareResourceEntry();
    core->glyph_tiles.~HardwareStateEntry();
    if (core->ui_state != nullptr)
        delete core->ui_state;
    DestroyHardwareBootstrap(core, flags);
}

NewGameBirthdayInputScene::NewGameBirthdayInputScene(GameDate birthday)
{
    core = InitializeBirthdayInputCore(static_cast<NewGameBirthdayInputCore *>(
        ::operator new(sizeof(NewGameBirthdayInputCore))), birthday);
}

NewGameBirthdayInputScene::~NewGameBirthdayInputScene()
{
    // The outer scene has its real C++ lifetime. Its core still has a partial
    // bootstrap ABI view, so retain the verified virtual cleanup of that core.
    NewGameBirthdayInputCore * object = core;
    if (object != nullptr)
        ((void (*)(NewGameBirthdayInputCore *, int))object->vtable[2])(object, 3);
}

SceneTransitionOwner NewGameBirthdayInputScene::Run()
{
    return func_0806DB38(core);
}

GameDate NewGameBirthdayInputScene::GetDate() const
{
    return core->birthday;
}

void MoveBirthdayInputCursor(NewGameBirthdayInputCore * core)
{
    // Direction buttons occupy the low byte of the repeated-key ABI word.
    u32 input = GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core));
    if (reinterpret_cast<u8 const *>(&input)[0] & 0x40) {
        if (core->cursor_row != 0) {
            core->music_players[1].Start(0xCB);
            if (core->cursor_row > 1)
                core->cursor_row--;
            else if (core->cursor_row == 1) {
#if defined(REGION_JP)
                if (core->cursor_column > 1)
                    core->cursor_row = 4;
                else
                    core->cursor_row = 5;
#else
                if (core->cursor_column > 3)
                    core->cursor_row = 4;
                else
                    core->cursor_row = 5;
#endif
            }
        }
    } else if (reinterpret_cast<u8 const *>(&input)[0] & 0x80) {
        if (core->cursor_row != 0) {
            core->music_players[1].Start(0xCB);
            core->cursor_row++;
            if (core->cursor_row == 6 || (core->cursor_row == 5 &&
#if defined(REGION_JP)
                    core->cursor_column > 1))
#else
                    core->cursor_column > 3))
#endif
                core->cursor_row = 1;
        }
    } else if (reinterpret_cast<u8 const *>(&input)[0] & 0x20) {
        core->music_players[1].Start(0xCB);
#if defined(REGION_JP)
        core->cursor_column--;
        if (core->cursor_row == 0) {
            if (core->cursor_column < 0)
                core->cursor_column = 3;
        } else if (core->cursor_column < 0) {
            core->cursor_row--;
            if (core->cursor_row <= 0) {
                core->cursor_row = 5;
                core->cursor_column = 1;
            } else
                core->cursor_column = 6;
        }
#else
        if (core->cursor_row == 0) {
            core->cursor_column -= 4;
            if (core->cursor_column < 0)
                core->cursor_column = 12;
        } else {
            core->cursor_column -= 2;
            if (core->cursor_column < 0) {
                core->cursor_row--;
                if (core->cursor_row <= 0) {
                    core->cursor_row = 5;
                    core->cursor_column = 3;
                } else
                    core->cursor_column = 13;
            }
        }
#endif
    } else if (reinterpret_cast<u8 const *>(&input)[0] & 0x10) {
        core->music_players[1].Start(0xCB);
#if defined(REGION_JP)
        core->cursor_column++;
        if (core->cursor_row == 0) {
            if (core->cursor_column > 3)
                core->cursor_column = 0;
        } else if (core->cursor_row == 5) {
            if (core->cursor_column > 1) {
                core->cursor_row = 1;
                core->cursor_column = 0;
            }
        } else if (core->cursor_column > 6) {
            core->cursor_row++;
            core->cursor_column = 0;
        }
#else
        if (core->cursor_row == 0) {
            core->cursor_column += 4;
            if (core->cursor_column > 12)
                core->cursor_column = 0;
        } else {
            core->cursor_column += 2;
            if (core->cursor_row == 5) {
                if (core->cursor_column > 3) {
                    core->cursor_row = 1;
                    core->cursor_column = 1;
                }
            } else if (core->cursor_column > 13) {
                core->cursor_row++;
                core->cursor_column = 1;
            }
        }
#endif
    }
}

bool ConfirmBirthdayInputSelection(NewGameBirthdayInputCore * core)
{
    bool complete = false;
    bool pressed = false;
    if ((static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core))) & 1) ||
        (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core))) & 8))
        pressed = true;
    if (pressed) {
        core->music_players[1].Start(0x6A);
        if (core->cursor_row == 0) {
            core->saved_season_column = core->cursor_column;
            core->cursor_row = (core->day - 1) / 7 + 1;
#if defined(REGION_JP)
            core->cursor_column = (core->day - 1) % 7;
#else
            core->cursor_column = ((core->day - 1) % 7) * 2 + 1;
#endif
        } else complete = true;
    }
    return complete;
}

bool CancelBirthdayInputSelection(NewGameBirthdayInputCore * core)
{
    bool cancelled = false;
    if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core))) & 2) {
        core->music_players[1].Start(0x6C);
        if (core->cursor_row > 0) {
            core->cursor_column = core->saved_season_column;
            core->cursor_row = 0;
#if defined(REGION_JP)
            core->glyphs[1].glyph_index = 19;
            core->glyphs[2].glyph_index = 19;
#else
            core->glyphs[6].glyph_index = 34;
            core->glyphs[7].glyph_index = 34;
#endif
        } else cancelled = true;
    }
    return cancelled;
}

void AppendBirthdayInputGlyph(NewGameBirthdayInputCore * core, i32 x, i32 y,
    i32 glyph, i32 priority)
{
    core->glyphs[core->glyph_count].x = x;
    core->glyphs[core->glyph_count].y = y;
    core->glyphs[core->glyph_count].glyph_index = glyph;
    core->glyphs[core->glyph_count].priority = priority;
    core->glyph_count++;
}

static inline void SubmitBirthdaySprite(NewGameBirthdayInputCore * core,
    HardwareSpriteOamRecord const & attributes)
{
    HardwareSpriteBufferState * buffer =
        GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    u32 const & position_and_mode = reinterpret_cast<u32 const &>(attributes);
    u32 count = buffer->sprite_count;
    if (count < ARRAY_COUNT(buffer->sprites)) {
        HardwareSpriteOamRecord & destination = buffer->sprites[count];
        reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
        reinterpret_cast<u16 *>(&destination)[2] =
            reinterpret_cast<u16 const *>(&attributes)[2];
        buffer->sprite_count = count + 1;
    }
}

void RenderBirthdayInputSprites(NewGameBirthdayInputCore * core)
{
    HardwareSpriteOamRecord attributes;
    attributes.affine_mode = 0;
    attributes.object_mode = 0;
    attributes.color_mode = 0;
#if defined(REGION_JP)
    attributes.shape = 0;
#else
    attributes.shape = 2;
#endif
    attributes.affine_index_low = 0;
    attributes.horizontal_flip = 0;
    attributes.vertical_flip = 0;
#if defined(REGION_JP)
    attributes.size = 1;
#else
    attributes.size = 0;
#endif
    attributes.palette_bank = static_cast<u16>(SpritePaletteBank(core->glyph_palette));
    attributes.affine_coefficient = 0;
    attributes.mosaic = 1;
    for (i32 index = core->glyph_count - 1; index >= 0; --index) {
        attributes.priority = core->glyphs[index].priority;
        attributes.x = core->glyphs[index].x;
        attributes.y = core->glyphs[index].y;
#if defined(REGION_JP)
        attributes.tile_index = SpriteTileIndex(core->glyph_tiles)
            + core->glyphs[index].glyph_index * 4;
#else
        attributes.tile_index = SpriteTileIndex(core->glyph_tiles)
            + core->glyphs[index].glyph_index * 2;
#endif
        SubmitBirthdaySprite(core, attributes);
    }
    // Copy only the six attribute bytes; the buffer owns affine coefficients.
    if (core->cursor_visible) {
        {
            HardwareSpriteBufferState * buffer =
                GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
            u32 const & position_and_mode =
                reinterpret_cast<u32 const &>(core->cursor_attributes);
            u32 count = buffer->sprite_count;
            if (count < ARRAY_COUNT(buffer->sprites)) {
                HardwareSpriteOamRecord & destination = buffer->sprites[count];
                reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
                reinterpret_cast<u16 *>(&destination)[2] = core->cursor_attributes.tile_attributes;
                buffer->sprite_count = count + 1;
            }
        }
#if !defined(REGION_JP)
        if (core->cursor_row == 0) {
            core->cursor_attributes.x = core->cursor_column * 16 + 16;
            {
                HardwareSpriteBufferState * buffer =
                    GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
                u32 const & position_and_mode =
                    reinterpret_cast<u32 const &>(core->cursor_attributes);
                u32 count = buffer->sprite_count;
                if (count < ARRAY_COUNT(buffer->sprites)) {
                    HardwareSpriteOamRecord & destination = buffer->sprites[count];
                    reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
                    reinterpret_cast<u16 *>(&destination)[2] = core->cursor_attributes.tile_attributes;
                    buffer->sprite_count = count + 1;
                }
            }
            core->cursor_attributes.x = core->cursor_column * 16 + 32;
            {
                HardwareSpriteBufferState * buffer =
                    GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
                u32 const & position_and_mode =
                    reinterpret_cast<u32 const &>(core->cursor_attributes);
                u32 count = buffer->sprite_count;
                if (count < ARRAY_COUNT(buffer->sprites)) {
                    HardwareSpriteOamRecord & destination = buffer->sprites[count];
                    reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
                    reinterpret_cast<u16 *>(&destination)[2] = core->cursor_attributes.tile_attributes;
                    buffer->sprite_count = count + 1;
                }
            }
        }
#endif
    }
}

void InitializeBirthdayInputCursor(NewGameBirthdayInputCore * core)
{
    CopyHardwareDma3(gUiSharedPalette,
        reinterpret_cast<void *>(0x05000200 + SpritePaletteBank(core->cursor_palette) * 32), 32);
    *reinterpret_cast<u16 *>(0x0500020E + SpritePaletteBank(core->cursor_palette) * 32) = 0x027F;
    FillHardwareDma3(0, &core->cursor_attributes, sizeof(core->cursor_attributes));
#if defined(REGION_JP)
    core->cursor_attributes.size = 2;
    core->cursor_attributes.shape = 1;
#else
    core->cursor_attributes.size = 1;
    core->cursor_attributes.shape = 0;
#endif
    core->cursor_attributes.object_mode = 1;
    // Use the native OAM halfword view for the tile and palette fields.
    reinterpret_cast<HardwareSpriteOamRecord &>(core->cursor_attributes).tile_index = SpriteTileIndex(core->cursor_tiles);
    reinterpret_cast<HardwareSpriteOamRecord &>(core->cursor_attributes).palette_bank = SpritePaletteBank(core->cursor_palette);
    reinterpret_cast<HardwareSpriteOamRecord &>(core->cursor_attributes).priority = 3;
    for (int tile = 0; tile < 8; ++tile) {
        for (int row = 0; row < 8; ++row) {
            *reinterpret_cast<u32 *>(0x06010000
                + (SpriteTileIndex(core->cursor_tiles) + tile) * 32 + row * 4) = 0x77777777;
        }
    }
#if defined(REGION_JP)
    i32 cell_width = core->cursor_column * 32;
    i32 gutter = core->cursor_column * 2 + 2;
    core->cursor_attributes.x = cell_width + gutter;
#else
    core->cursor_attributes.x = core->cursor_column * 16;
#endif
    core->cursor_attributes.y = 40;
}

void BuildBirthdayInputGlyphs(NewGameBirthdayInputCore * core)
{
    core->glyph_count = 0;
#if defined(REGION_JP)
    int title[3];
    title[0] = core->season_column + 10;
#else
    int title[8];
    switch (core->season_column) {
    case 0: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 10;
    } break;
    case 4: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 16;
    } break;
    case 8: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 22;
    } break;
    default: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 28;
    } break;
    }
#endif
#if defined(REGION_JP)
    title[1] = static_cast<i8>(core->day / 10) == 0 ? 20 : static_cast<i8>(core->day / 10);
    title[2] = static_cast<i8>(core->day % 10);
    AppendBirthdayInputGlyph(core, 144, 8, title[0], 1);
    AppendBirthdayInputGlyph(core, 192, 8, title[1], 1);
    AppendBirthdayInputGlyph(core, 208, 8, title[2], 1);
    for (int i = 0; i < 3; ++i)
        AppendBirthdayInputGlyph(core, 80 + i * 16, 8, i + 14, 1);
    AppendBirthdayInputGlyph(core, 160, 8, 17, 1);
    AppendBirthdayInputGlyph(core, 176, 8, 18, 1);
    AppendBirthdayInputGlyph(core, 224, 8, 16, 1);
    for (int i = 0; i < 4; ++i)
        AppendBirthdayInputGlyph(core, 18 + i * 34, 40, i + 10, 3);
#else
#if defined(REGION_DE)
    title[6] = static_cast<i8>(core->day / 10) == 0 ? 45 : static_cast<i8>(core->day / 10);
#else
    title[6] = static_cast<i8>(core->day / 10) == 0 ? 26 : static_cast<i8>(core->day / 10);
#endif
    title[7] = static_cast<i8>(core->day % 10);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, 120 + i * 8, 8, title[i], 1);
    AppendBirthdayInputGlyph(core, 192, 8, title[6], 1);
    AppendBirthdayInputGlyph(core, 200, 8, title[7], 1);
#endif
    u8 day = 1;
    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 7; ++column) {
#if defined(REGION_JP)
            if (day > 9) AppendBirthdayInputGlyph(core, column * 34 + 2, row * 18 + 64, static_cast<u8>(day / 10u), 3);
            AppendBirthdayInputGlyph(core, column * 34 + 18, row * 18 + 64, static_cast<u8>(day % 10u), 3);
#else
            if (day > 9) AppendBirthdayInputGlyph(core, column * 32 + 16, row * 18 + 64, static_cast<u8>(day / 10u), 3);
            AppendBirthdayInputGlyph(core, column * 32 + 24, row * 18 + 64, static_cast<u8>(day % 10u), 3);
#endif
            ++day;
            if (day > 30) break;
        }
    }
#if !defined(REGION_JP)
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8, 40, i + 10, 3);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 64, 40, i + 16, 3);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 128, 40, i + 22, 3);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 192, 40, i + 28, 3);
#if defined(REGION_DE)
    for (int i = 0; i < 10; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 8, 8, i + 35, 3);
#else
    for (int i = 0; i < 8; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 8, 8, i + 35, 3);
#endif
#endif
}

void UpdateBirthdayInputUi(NewGameBirthdayInputCore * core)
{
    UiStateOwner const * ui = core->ui_state;
    HardwareCoreState * state = static_cast<HardwareCoreState *>(GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = core->music_players;
    switch (ui->Update(state, sprites, display, links, manager, music)) {
    case 0:
        if (core->dialogue_state == 0) {
            func_08050D5C(core->ui_state);
            core->dialogue_state = 3;
        } else {
            core->dialogue_state = 2;
        }
        break;
    case 3:
        if (core->dialogue_state == 5) {
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state));
            core->dialogue_state = 1;
        } else if (core->dialogue_state == 4) {
            u32 selection = core->ui_state->GetChoiceResult();
            core->dialogue_state = 5;
            if (selection == 1) core->dialogue_choice = 0;
            else if (selection == 2) core->dialogue_choice = 1;
        } else if (core->dialogue_state == 3) {
            core->dialogue_state = 5;
            func_08050E30(core->ui_state, gText_AnimalContest_FinalConfirmation,
                gText_AnimalContest_FinalYes, gText_AnimalContest_FinalNo, nullptr, nullptr, nullptr);
            core->dialogue_state = 4;
        }
        break;
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
        break;
    }
}
