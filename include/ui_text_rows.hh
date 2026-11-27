#ifndef UI_TEXT_ROWS_HH
#define UI_TEXT_ROWS_HH

#include "prelude.h"
#include "font_draw.hh"
#include "gbaio.h"
#include "gbasvc.h"
#include "hardware_dma.hh"
#include "hardware_linked_list.hh"
#include "obj_palette_pool.hh"
#include "obj_tile_collection.hh"
#include "utility/container_algorithms.hh"


struct UiDmaTransferQueue;

// The output base supplies native no-op cursor/page defaults and a byte-valued
// stop query. Concrete output storage below owns its three glyph rows.
// The input adapter below stores a copied key snapshot and a byte-valued gate;
// variable-store implementations still have additional native storage.

// Plain inline storage types precede the explicit virtual interface.
// Native selection storage: three owned rows, each with seven 16-byte
// entries. The buffer prefix and scalar control fields remain unknown.
struct UnkUiSelectionTileBuffer
{
    // Buffers intentionally start uninitialized, including the inline array.
    UnkUiSelectionTileBuffer() {}
    u32 unk_00;
    u32 tiles[64];
};

struct UnkUiSelectionPixels
{
    UnkUiSelectionTileBuffer * value;
    UnkUiSelectionPixels() : value(new UnkUiSelectionTileBuffer) {}
    ~UnkUiSelectionPixels() { delete value; }
};

struct UnkUiSelectionEntry
{
    UnkUiSelectionPixels pixels;
    ObjTileCollectionEntry state;
    bool changed;
    UnkUiSelectionEntry() : changed(false) {}
};

struct UnkUiSelectionRow
{
    UnkUiSelectionEntry entries[7];
    UnkUiSelectionEntry & Entry(unsigned index) { return entries[index]; }
};

struct UnkUiSelectionRowOwner
{
    UnkUiSelectionRow * value;
    UnkUiSelectionRowOwner() : value(nullptr) {}
    ~UnkUiSelectionRowOwner() { delete value; }
    UnkUiSelectionRow * Get() const { return value; }
    UnkUiSelectionRow * operator->() const { return value; }
    UnkUiSelectionRowOwner & operator=(UnkUiSelectionRow * input)
    {
        UnkUiSelectionRow * const previous = value;
        if (input != previous && previous != nullptr)
            delete previous;
        value = input;
        return *this;
    }
};


struct UnkUiSelectionDimensions
{
    u16 width;
    u16 height;
    UnkUiSelectionDimensions(u16 first, u16 second) : width(first), height(second) {}
};


// Eight 16-byte DMA descriptors; only the counted range has an active lifetime.
struct UiDmaTransferQueue
{
    u32 count;
    u8 storage[8 * sizeof(DmaTransferDescriptor)];

    UiDmaTransferQueue() : count(0) {}
    DmaTransferDescriptor * Begin()
    {
        return reinterpret_cast<DmaTransferDescriptor *>(storage);
    }
    DmaTransferDescriptor * End()
    {
        return reinterpret_cast<DmaTransferDescriptor *>(storage + count * sizeof(DmaTransferDescriptor));
    }
    bool Empty() const { return count == 0; }
    void Clear()
    {
        typedef __type_traits<DmaTransferDescriptor>::has_trivial_destructor Trait;
        DmaTransferDescriptor * first = Begin();
        DmaTransferDescriptor * last = End();
        destroy_range_inl(first, last, Trait());
        count -= last - first;
    }
    ~UiDmaTransferQueue()
    {
        typedef __type_traits<DmaTransferDescriptor>::has_trivial_destructor Trait;
        DmaTransferDescriptor * last = End();
        destroy_range_inl(Begin(), last, Trait());
    }
};

#pragma interface "ui_text_commands.hh"
struct UiTextOutput
{
    virtual ~UiTextOutput() {}
    virtual bool Emit(u32 code) = 0;
    virtual void CarriageReturn() {}
    virtual void LineFeed() {}
    virtual void NextPage() {}
    virtual u8 ShouldStop() { return false; }
};

#pragma interface "ui_text_commands.hh"
struct UiTextInput
{
    virtual ~UiTextInput() {}
    virtual bool Fast() { return false; }
    virtual bool WaitForInput() { return false; }
    virtual bool Resume() { return true; }
};


// A repeating BG tile upload. Alternating mode toggles its nibble mask each
// run; it is not compression. That mode requires at least one 32-byte tile.
#pragma interface "ui_text_commands.hh"
struct UiTextTileCopyCommand : HardwareLinkBase
{
    UiTextTileCopyCommand(u32 const *, u32 *, u32, bool);
    virtual bool Run();
    u32 const * source;
    u32 * destination;
    u16 tile_count : 14;
    u16 nibble_phase : 1;
    u16 alternate_nibbles : 1;
};

#pragma interface "ui_text_commands.hh"
struct UnkUiSelectionData : UiTextOutput
{
    UnkUiSelectionData(ObjPaletteCollectionEntry *, ObjTileCollection const &);
    virtual bool Emit(u32);
    virtual void CarriageReturn();
    virtual void LineFeed();
    virtual void NextPage();
    // Return the stored byte unchanged; do not normalize it to a C++ bool.
    virtual u8 ShouldStop();
    ObjPaletteCollectionEntry * palette;
    UnkUiSelectionRowOwner rows[3];
    u16 unk_14;
    u16 unk_16;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
};

// The native UI update copies input.pressed into this word-sized snapshot.
// Only its low eight key bits are queried; allow_resume gates resumption.
#pragma interface "ui_text_commands.hh"
struct UiTextInputAdapter : UiTextInput
{
    virtual ~UiTextInputAdapter() {}
    UiTextInputAdapter(u32 const &, u8);
    virtual bool Fast();
    virtual bool WaitForInput();
    virtual bool Resume();
    u32 pressed;
    u8 allow_resume;
};

#pragma interface "ui_text_commands.hh"
struct UiDmaTransferCommand : HardwareLinkBase
{
    inline UiDmaTransferCommand(UiDmaTransferQueue & value);
    UiDmaTransferQueue * queue;
    virtual bool Run();
};


// Upload changed glyph buffers from the three physical rows, then retire
// this queued command. The output storage and its resource handles are borrowed.
static inline bool HasUiSelectionState(ObjTileCollectionEntry const & state)
{
    return state.handle != 0;
}

static inline u32 UiSelectionTileIndex(ObjTileCollectionEntry & state)
{
    return GetObjTileIndex(&state, state.handle);
}

static inline UnkUiSelectionEntry & GetUiTextEntry(UnkUiSelectionData & object,
    int row, int column)
{
    return object.rows[row]->Entry(column);
}

static inline void UploadUiTextOutput(UnkUiSelectionData * object)
{
    for (int row = 0; row <= 2; ++row)
    {
        int column = 0;
        for (; column <= 6; ++column)
        {
            UnkUiSelectionEntry & entry = GetUiTextEntry(*object, row, column);
            if (entry.changed)
            {
                if (HasUiSelectionState(entry.state))
                {
                    u32 const * pixels = entry.pixels.value->tiles;
                    u32 const index = UiSelectionTileIndex(entry.state);
                    CpuFastSet(pixels, reinterpret_cast<void *>(OBJ_VRAM0 + index * TILE_SIZE_4BPP), 64);
                }
                entry.changed = false;
            }
        }
    }
    if (object->unk_19)
        object->unk_19 = 0;
    if (object->unk_1a)
        object->unk_1a = 0;
}

#pragma interface "ui_text_commands.hh"
struct UiTextOutputUploadCommand : HardwareLinkBase
{
    inline UiTextOutputUploadCommand(UnkUiSelectionData * const & value);
    virtual inline bool Run();
    UnkUiSelectionData * output;
};

// One-shot window setup: a background screen block, border tile index,
// background palette bank and hand-cursor OBJ palette bank. The upper nine
// bits retain their previous value and still have no established meaning.
#pragma interface "ui_text_commands.hh"
struct UiTextWindowSetupCommand : HardwareLinkBase
{
    UiTextWindowSetupCommand(u32, u32, u32, u32);
    virtual bool Run();
    unsigned screen_block : 5;
    unsigned first_tile : 10;
    unsigned background_palette : 4;
    unsigned cursor_palette : 4;
    unsigned unk_0c_23 : 9;
};





// Execute the active descriptors, then release their counted storage.


#pragma interface "ui_text_commands.hh"

// Command runs are retained before the class-generated cleanup entries.
inline bool UiTextOutputUploadCommand::Run()
{
    UiTextOutputUploadCommand * command = this;
    UploadUiTextOutput(command->output);
    return false;
}



static inline void FillUiFastWords(u32 value, void * destination, u32 count)
{
    u32 volatile source = value;
    CpuFastSet((void const *)&source, destination, CPUSET_SRC_FIXED | count);
}


static inline u32 DrawUiTextEntry(UnkUiSelectionEntry * entry, u32 code, u32 column)
{
    if (column <= 3) {
        UnkUiSelectionTileBuffer * buffer = entry->pixels.value;
        u32 x = (column & 3) * 8;
        UnkUiSelectionDimensions dimensions(4, 2);
        u32 result = DrawCharacterGlyphTo2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions),
            buffer->tiles, x, 0, code);
        if (result == 1 || result == 2)
            entry->changed = HasUiSelectionState(entry->state);
        return result;
    }
    return 0;
}

static inline void ClearUiTextEntry(UnkUiSelectionEntry * entry)
{
    UnkUiSelectionTileBuffer * buffer = entry->pixels.value;
    UnkUiSelectionDimensions dimensions(4, 2);
    Clear2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions), buffer->tiles, 0);
    entry->changed = HasUiSelectionState(entry->state);
}

static inline int GetUiTextPhysicalRow(UnkUiSelectionData const * object, int row)
{
    int result = row + object->unk_18;
    if (result > 2)
        result -= 3;
    return result;
}

static inline bool HasUiTextAdvanceKeys(u8 value)
{
    return value;
}


#endif // UI_TEXT_ROWS_HH
