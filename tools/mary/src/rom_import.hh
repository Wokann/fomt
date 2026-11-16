#ifndef MARY_ROM_IMPORT_HH
#define MARY_ROM_IMPORT_HH

#include "ir.hh"
#include <array>
#include <optional>
#include <string>
#include <utility>

namespace mary
{

constexpr std::size_t gba_rom_base = 0x08000000;
constexpr std::size_t gba_rom_max_size = 0x02000000;
struct Range
{
    std::size_t start, end;
    std::size_t size() const
    {
        return end - start;
    }
};
struct NativeScriptLayout
{
    std::string target;
    std::size_t pointer_table_offset, slot_count;
    std::array<std::size_t, 3> references;
};
struct ScriptLocation
{
    std::size_t id, offset, riff_length, allocation_end;
    Range allocation() const
    {
        return { offset, allocation_end };
    }
};
struct ScriptLayout
{
    NativeScriptLayout native;
    std::size_t pointer_table_offset, slot_count;
    std::optional<Range> script_area;
    std::vector<std::optional<ScriptLocation>> scripts;
    bool metadata_present;
};
struct PackedScripts
{
    Bytes bytes;
    std::vector<std::optional<std::size_t>> offsets;
    static PackedScripts from_slots(const std::vector<std::optional<Bytes>> &slots);
};

std::optional<NativeScriptLayout> identify_rom(const Bytes &rom);
std::size_t normalize_rom_offset(std::size_t address);
std::uint32_t gba_pointer(std::size_t offset);
std::optional<std::pair<std::size_t, std::uint8_t>> range_occupancy(const Bytes &rom, Range range);
ScriptLayout resolve_script_layout(
    const Bytes &rom,
    std::optional<std::pair<std::size_t, std::size_t>> manual_table = std::nullopt);
Range write_single_script_in_place(Bytes &rom,
                                   const ScriptLayout &layout,
                                   std::size_t id,
                                   const Bytes &riff);
Range write_single_script_at(Bytes &rom,
                             const ScriptLayout &layout,
                             std::size_t id,
                             const Bytes &riff,
                             std::size_t destination);
std::pair<Range, Range> write_packed_scripts(
    Bytes &rom,
    const ScriptLayout &layout,
    const PackedScripts &scripts,
    std::size_t destination,
    std::optional<std::size_t> table_destination = std::nullopt);
bool valid_script_pointer(const Bytes &rom, std::uint32_t word);
std::size_t infer_pointer_count(const Bytes &rom, const ScriptLayout &layout);
std::optional<std::pair<std::size_t, std::uint32_t>> pointer_extension_conflict(const Bytes &rom,
                                                                                Range range);

} // namespace mary
#endif
