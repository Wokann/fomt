#include "rom_import.hh"
#include "bytecode.hh"

#include <algorithm>
#include <limits>
#include <stdexcept>

namespace mary
{
namespace
{
constexpr std::size_t metadata_size = 32;
const std::string metadata_magic = "MARYTAB1";
[[noreturn]] void fail(const std::string &text)
{
    throw std::runtime_error(text);
}
std::size_t add(std::size_t a, std::size_t b)
{
    if (b > SIZE_MAX - a)
        fail("ROM offset overflow");
    return a + b;
}
std::size_t align4(std::size_t value)
{
    return add(value, 3) & ~std::size_t(3);
}
void checked(const Bytes &rom, Range range)
{
    if (range.start > range.end || range.end > rom.size())
        fail("range is outside the ROM");
}
void aligned(std::size_t value)
{
    if (value % 4)
        fail("ROM address must be four-byte aligned");
}
void disjoint(Range a, Range b)
{
    if (a.start < b.end && b.start < a.end)
        fail("ROM write ranges overlap");
}
void protect_references(const ScriptLayout &layout, Range range)
{
    for (auto at : layout.native.references)
        disjoint(range, { at, at + 4 });
}
void patch(Bytes &rom, std::size_t at, std::uint32_t value)
{
    checked(rom, { at, add(at, 4) });
    for (unsigned i = 0; i < 4; ++i)
        rom[at + i] = std::uint8_t(value >> (i * 8));
}
void validate_riff(const Bytes &riff)
{
    if (riff.size() < 12 || !std::equal(riff.begin(), riff.begin() + 4, "RIFF") ||
        !std::equal(riff.begin() + 8, riff.begin() + 12, "SCR ") ||
        read_u32(riff, 4) != riff.size())
        fail("compiled data is not a complete RIFF/SCR script");
}
std::optional<std::array<std::uint32_t, 5>> metadata(const Bytes &rom,
                                                     const NativeScriptLayout &native)
{
    const auto at = native.pointer_table_offset;
    checked(rom, { at, at + metadata_size });
    if (!std::equal(rom.begin() + at, rom.begin() + at + 8, metadata_magic.begin()))
        return std::nullopt;
    std::array<std::uint32_t, 5> words{};
    std::uint32_t checksum = 0x4d415259;
    for (std::size_t i = 0; i < words.size(); ++i)
    {
        words[i] = read_u32(rom, at + 8 + i * 4);
        checksum ^= words[i];
    }
    if (words[0] != 1 || read_u32(rom, at + 28) != checksum || words[2] == 0 ||
        words[1] >= gba_rom_max_size || words[1] > rom.size() ||
        words[2] > (rom.size() - words[1]) / 4 || words[3] > words[4] || words[4] > rom.size())
        fail("invalid Mary pointer-table metadata");
    return words;
}
void write_metadata(Bytes &rom,
                    const NativeScriptLayout &native,
                    std::size_t table,
                    std::size_t slots,
                    Range scripts)
{
    if (table > UINT32_MAX || slots > UINT32_MAX || scripts.start > UINT32_MAX ||
        scripts.end > UINT32_MAX)
        fail("metadata exceeds 32-bit fields");
    auto at = native.pointer_table_offset;
    checked(rom, { at, at + metadata_size });
    std::copy(metadata_magic.begin(), metadata_magic.end(), rom.begin() + at);
    std::array<std::uint32_t, 5> words{ 1,
                                        std::uint32_t(table),
                                        std::uint32_t(slots),
                                        std::uint32_t(scripts.start),
                                        std::uint32_t(scripts.end) };
    std::uint32_t checksum = 0x4d415259;
    for (std::size_t i = 0; i < words.size(); ++i)
    {
        patch(rom, at + 8 + i * 4, words[i]);
        checksum ^= words[i];
    }
    patch(rom, at + 28, checksum);
}
Range table_range(const Bytes &rom, std::size_t at, std::size_t slots)
{
    if (at > rom.size() || slots > (rom.size() - at) / 4)
        fail("truncated pointer table");
    return { at, at + slots * 4 };
}
} // namespace

std::optional<NativeScriptLayout> identify_rom(const Bytes &rom)
{
    if (rom.size() < 0xb0)
        return std::nullopt;
    std::string title(rom.begin() + 0xa0, rom.begin() + 0xac),
        code(rom.begin() + 0xac, rom.begin() + 0xb0);
    if (title == std::string("BOKUMONOGBA\0", 12) && code == "A4NJ")
        return NativeScriptLayout{
            "MARY_FOMT_JP", 0x0f8230, 1329, { 0x03f510, 0x0df4d4, 0x0dfce0 }
        };
    if (title == "HARVESTMOGBA" && code == "A4NE")
        return NativeScriptLayout{
            "MARY_FOMT_US", 0x0f89d4, 1329, { 0x03f89c, 0x0dfd20, 0x0e0534 }
        };
    if (title == "HARVESTMOGBA" && code == "A4NP")
        return NativeScriptLayout{
            "MARY_FOMT_EU", 0x0f8a20, 1329, { 0x03f8b0, 0x0dfd6c, 0x0e0580 }
        };
    if (title == "HARVESTMOGER" && code == "A4ND")
        return NativeScriptLayout{
            "MARY_FOMT_DE", 0x0f8ebc, 1329, { 0x03f794, 0x0dfc84, 0x0e0498 }
        };
    if (title == std::string("BOKUMONOGBA\0", 12) && code == "BFGJ")
        return NativeScriptLayout{
            "MARY_MFOMT_JP", 0x10145c, 1416, { 0x03f7e4, 0x0e7d64, 0x0e8578 }
        };
    if (title == std::string("HM MFOM USA\0", 12) && code == "BFGE")
        return NativeScriptLayout{
            "MARY_MFOMT_US", 0x1014bc, 1416, { 0x03fa88, 0x0e8254, 0x0e8a68 }
        };
    return std::nullopt;
}
std::size_t normalize_rom_offset(std::size_t address)
{
    auto offset = address < gba_rom_base ? address : address - gba_rom_base;
    if (offset >= gba_rom_max_size)
        fail("address is outside the GBA ROM space");
    return offset;
}
std::uint32_t gba_pointer(std::size_t offset)
{
    if (offset >= gba_rom_max_size)
        fail("offset is outside the GBA ROM space");
    return std::uint32_t(gba_rom_base + offset);
}
std::optional<std::pair<std::size_t, std::uint8_t>> range_occupancy(const Bytes &rom, Range range)
{
    checked(rom, range);
    for (auto at = range.start; at < range.end; ++at)
        if (rom[at] != 0 && rom[at] != 0xff)
            return std::make_pair(at, rom[at]);
    return std::nullopt;
}
PackedScripts PackedScripts::from_slots(const std::vector<std::optional<Bytes>> &slots)
{
    PackedScripts result;
    for (auto &slot : slots)
    {
        if (!slot)
        {
            result.offsets.emplace_back();
            continue;
        }
        validate_riff(*slot);
        result.offsets.push_back(result.bytes.size());
        result.bytes.insert(result.bytes.end(), slot->begin(), slot->end());
        result.bytes.resize(align4(result.bytes.size()), 0);
    }
    return result;
}
ScriptLayout resolve_script_layout(const Bytes &rom,
                                   std::optional<std::pair<std::size_t, std::size_t>> manual)
{
    auto native = identify_rom(rom);
    if (!native)
        fail("unsupported ROM header; explicit RIFF offsets can still be decoded");
    ScriptLayout result{
        *native, native->pointer_table_offset, native->slot_count, std::nullopt, {}, false
    };
    if (manual)
    {
        aligned(manual->first);
        result.pointer_table_offset = manual->first;
        result.slot_count = manual->second;
        auto at = native->pointer_table_offset;
        result.metadata_present =
            at <= rom.size() && rom.size() - at >= 8 &&
            std::equal(rom.begin() + at, rom.begin() + at + 8, metadata_magic.begin());
    }
    else if (auto info = metadata(rom, *native))
    {
        result.pointer_table_offset = (*info)[1];
        result.slot_count = (*info)[2];
        result.metadata_present = true;
    }
    table_range(rom, result.pointer_table_offset, result.slot_count);
    std::optional<Range> area;
    bool contiguous = true;
    for (std::size_t i = 0; i < result.slot_count; ++i)
    {
        auto pointer = read_u32(rom, result.pointer_table_offset + i * 4);
        if (!pointer)
        {
            result.scripts.emplace_back();
            continue;
        }
        auto at = normalize_rom_offset(pointer);
        checked(rom, { at, add(at, 8) });
        if (!std::equal(rom.begin() + at, rom.begin() + at + 4, "RIFF"))
            fail("script pointer does not address RIFF");
        auto length = read_u32(rom, at + 4);
        if (length < 12)
            fail("invalid script RIFF length");
        auto end = align4(add(at, length));
        checked(rom, { at, end });
        result.scripts.push_back(ScriptLocation{ i, at, length, end });
        if (!area)
            area = Range{ at, end };
        else
        {
            if (at != area->end)
                contiguous = false;
            area->end = end;
        }
    }
    if (contiguous)
        result.script_area = area;
    return result;
}
Range write_single_script_in_place(Bytes &rom,
                                   const ScriptLayout &layout,
                                   std::size_t id,
                                   const Bytes &riff)
{
    validate_riff(riff);
    if (id >= layout.scripts.size() || !layout.scripts[id])
        fail("script ID is outside the table or is a null slot");
    auto &where = *layout.scripts[id];
    auto allocation = where.allocation();
    checked(rom, allocation);
    if (align4(riff.size()) > allocation.size())
        fail("compiled script exceeds its original allocation");
    std::copy(riff.begin(), riff.end(), rom.begin() + where.offset);
    std::fill(rom.begin() + where.offset + riff.size(), rom.begin() + allocation.end, 0);
    return allocation;
}
Range write_single_script_at(Bytes &rom,
                             const ScriptLayout &layout,
                             std::size_t id,
                             const Bytes &riff,
                             std::size_t destination)
{
    aligned(destination);
    validate_riff(riff);
    Range range{ destination, add(destination, align4(riff.size())) };
    checked(rom, range);
    disjoint(range, table_range(rom, layout.pointer_table_offset, layout.slot_count));
    protect_references(layout, range);
    if (layout.metadata_present)
        disjoint(range,
                 { layout.native.pointer_table_offset,
                   layout.native.pointer_table_offset + metadata_size });
    if (id >= layout.slot_count)
        fail("script ID is outside pointer table");
    auto pointer = gba_pointer(destination);
    std::copy(riff.begin(), riff.end(), rom.begin() + destination);
    std::fill(rom.begin() + destination + riff.size(), rom.begin() + range.end, 0);
    patch(rom, layout.pointer_table_offset + id * 4, pointer);
    return range;
}
std::pair<Range, Range> write_packed_scripts(Bytes &rom,
                                             const ScriptLayout &layout,
                                             const PackedScripts &scripts,
                                             std::size_t destination,
                                             std::optional<std::size_t> relocated_table)
{
    aligned(destination);
    Range data{ destination, add(destination, scripts.bytes.size()) };
    checked(rom, data);
    auto table = relocated_table ? *relocated_table : layout.pointer_table_offset;
    aligned(table);
    auto range = table_range(rom, table, scripts.offsets.size());
    disjoint(data, range);
    protect_references(layout, data);
    protect_references(layout, range);
    if (layout.metadata_present || table != layout.native.pointer_table_offset)
    {
        Range original{ layout.native.pointer_table_offset,
                        layout.native.pointer_table_offset + metadata_size };
        disjoint(data, original);
        disjoint(range, original);
    }
    std::vector<std::pair<std::size_t, std::uint32_t>> patches;
    if (table != layout.pointer_table_offset)
        for (auto reference : layout.native.references)
        {
            if (read_u32(rom, reference) != gba_pointer(layout.pointer_table_offset))
                fail("native pointer-table reference differs from expected table");
            patches.emplace_back(reference, gba_pointer(table));
        }
    std::vector<std::uint32_t> pointers;
    for (auto offset : scripts.offsets)
        pointers.push_back(offset ? gba_pointer(add(destination, *offset)) : 0);
    std::copy(scripts.bytes.begin(), scripts.bytes.end(), rom.begin() + destination);
    for (std::size_t i = 0; i < pointers.size(); ++i)
        patch(rom, table + i * 4, pointers[i]);
    if (table == layout.pointer_table_offset && pointers.size() < layout.slot_count)
    {
        auto old = table_range(rom, table, layout.slot_count);
        std::fill(rom.begin() + range.end, rom.begin() + old.end, 0);
    }
    if (!relocated_table && layout.script_area && destination == layout.script_area->start &&
        data.end <= layout.script_area->end)
        std::fill(rom.begin() + data.end, rom.begin() + layout.script_area->end, 0);
    for (auto entry : patches)
        patch(rom, entry.first, entry.second);
    if (table != layout.pointer_table_offset || layout.metadata_present)
        write_metadata(rom, layout.native, table, pointers.size(), data);
    return { data, range };
}
bool valid_script_pointer(const Bytes &rom, std::uint32_t pointer)
{
    try
    {
        auto at = normalize_rom_offset(pointer);
        if (at > rom.size() || rom.size() - at < 8)
            return false;
        if (!std::equal(rom.begin() + at, rom.begin() + at + 4, "RIFF"))
            return false;
        auto size = read_u32(rom, at + 4);
        return size >= 12 && size <= rom.size() - at;
    }
    catch (const std::exception &)
    {
        return false;
    }
}
std::size_t infer_pointer_count(const Bytes &rom, const ScriptLayout &layout)
{
    auto at = table_range(rom, layout.pointer_table_offset, layout.slot_count).end,
         slot = layout.slot_count, inferred = slot;
    while (at <= rom.size() && rom.size() - at >= 4)
    {
        if (!range_occupancy(rom, { at, at + 4 }))
        {
            at += 4;
            ++slot;
            continue;
        }
        if (!valid_script_pointer(rom, read_u32(rom, at)))
            break;
        inferred = ++slot;
        at += 4;
    }
    return inferred;
}
std::optional<std::pair<std::size_t, std::uint32_t>> pointer_extension_conflict(const Bytes &rom,
                                                                                Range range)
{
    checked(rom, range);
    aligned(range.start);
    aligned(range.end);
    for (auto at = range.start; at < range.end; at += 4)
    {
        auto word = read_u32(rom, at);
        if (range_occupancy(rom, { at, at + 4 }) && !valid_script_pointer(rom, word))
            return std::make_pair(at, word);
    }
    return std::nullopt;
}

} // namespace mary
