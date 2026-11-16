#include "symbols.hh"
#include "bytecode.hh"
#include "rom_import.hh"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace mary
{
namespace
{

struct Slot
{
    bool present;
    std::size_t texts;
};
using Region = std::pair<std::string, std::vector<Slot>>;

std::vector<Slot> slots(const fs::path &path)
{
    auto rom = read_binary(path);
    auto layout = resolve_script_layout(rom);
    std::vector<Slot> result;
    for (auto &location : layout.scripts)
    {
        if (!location)
        {
            result.push_back({ false, 0 });
            continue;
        }
        Bytes riff(rom.begin() + location->offset,
                   rom.begin() + location->offset + location->riff_length);
        Bytes backing(rom.begin() + location->offset, rom.end());
        result.push_back({ true, decode_script(riff, backing).strings.size() });
    }
    return result;
}
std::optional<std::string> condition(const std::vector<Region> &regions,
                                     const std::vector<std::size_t> &selected)
{
    if (selected.size() == regions.size())
        return std::nullopt;
    std::string result;
    for (auto index : selected)
    {
        if (!result.empty())
            result += " || ";
        result += "defined(REGION_" + regions[index].first + ")";
    }
    return result;
}
std::string decimal(std::size_t value, unsigned width)
{
    std::ostringstream out;
    out << std::setw(int(width)) << std::setfill('0') << value;
    return out.str();
}
std::string render(const std::string &family, const std::vector<Region> &regions)
{
    auto upper = family;
    std::transform(upper.begin(),
                   upper.end(),
                   upper.begin(),
                   [](unsigned char c) { return char(std::toupper(c)); });
    std::string out =
        "// " + upper +
        "-only decompiler symbols. Post-preprocess positions are IDs.\nmary_script_symbols\n{\n";
    std::size_t count = 0;
    for (auto &region : regions)
        count = std::max(count, region.second.size());
    for (std::size_t id = 0; id < count; ++id)
    {
        std::vector<std::size_t> present;
        for (std::size_t i = 0; i < regions.size(); ++i)
            if (id < regions[i].second.size() && regions[i].second[id].present)
                present.push_back(i);
        out += "    // Script ID: " + decimal(id, 4) + "\n";
        if (present.empty())
        {
            out += "    NULL,\n\n";
            continue;
        }
        auto guard = condition(regions, present);
        if (guard)
            out += "    #if " + *guard + "\n";
        std::string indent = guard ? "        " : "    ";
        out += indent + "EventScript_" + decimal(id, 4) + "\n" + indent + "{\n";
        std::size_t texts = 0;
        for (auto region : present)
            texts = std::max(texts, regions[region].second[id].texts);
        for (std::size_t text = 0; text < texts; ++text)
        {
            std::vector<std::size_t> available;
            for (auto region : present)
                if (text < regions[region].second[id].texts)
                    available.push_back(region);
            auto text_guard = condition(regions, available);
            auto name = "gText_EventScript_" + decimal(id, 4) + "_" + decimal(text, 3) + ",\n";
            if (text_guard)
                out += indent + "    #if " + *text_guard + "\n" + indent + "        " + name +
                       indent + "    #endif\n";
            else
                out += indent + "    " + name;
        }
        out += indent + "},\n";
        if (guard)
            out += "    #else\n        NULL,\n    #endif\n";
        out += '\n';
    }
    return out + "};\n";
}

} // namespace

void generate_symbol_tables(const std::vector<fs::path> &roms, const fs::path &output)
{
    if (roms.size() != 6)
        throw std::runtime_error(
            "symbol generation requires FoMT JP/US/EU/DE and MFoMT JP/US ROMs");
    std::vector<Region> fomt{ { "JP", slots(roms[0]) },
                              { "US", slots(roms[1]) },
                              { "EU", slots(roms[2]) },
                              { "DE", slots(roms[3]) } };
    std::vector<Region> mfomt{ { "JP", slots(roms[4]) }, { "US", slots(roms[5]) } };
    fs::create_directories(output);
    write_text(output / "fomt_scripts_text.mary.sym", render("fomt", fomt));
    write_text(output / "mfomt_scripts_text.mary.sym", render("mfomt", mfomt));
}

} // namespace mary
