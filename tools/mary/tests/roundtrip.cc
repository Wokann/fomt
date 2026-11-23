#include "ast.hh"
#include "bytecode.hh"
#include "decompiler.hh"
#include "driver.hh"
#include "legacy.hh"
#include "low_level.hh"
#include "mary_c.hh"
#include "pretty.hh"
#include "rom_import.hh"

#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace mary;

namespace {

void require(bool condition, const char *message)
{
    if (!condition)
        throw std::runtime_error(message);
}

template<class Function>
void rejects(Function function, const char *message)
{
    try
    {
        function();
    }
    catch (const std::exception &)
    {
        return;
    }
    throw std::runtime_error(message);
}

void source_roundtrip()
{
    Options options;
    options.define("MARY_FOMT_US");
    auto scope = parse_constant_header(R"(
#define PACK(season, day) ((season) | ((day) << 2))
typedef enum Season { SPRING = 0, SUMMER = 1, } Season;
typedef enum Date { DATE_TEST = PACK(SUMMER, 19), } Date;
)", options);
    require(scope.integer_constant("DATE_TEST") == 77, "function macro constant changed");
    auto calls = parse_callable_table(R"(
mary_callable_table { Print, ReadValue, }
void Print(const char *text);
int ReadValue(int index);
)", options, scope);
    auto table = parse_script_table("mary_script_table { NULL, Example, }", options);
    auto map = Charmap::parse("41=A\n42=B\n43=C\n0D=\\r\n0A=\\n\n05={Press}\n");
    auto source = R"(
mary_text_table
{
    const char Message[] = "A\r\n" "B{Press}";
}
void Example(void)
{
    int value;
    value = ReadValue(DATE_TEST);
    if (value != 0)
    {
        Print(Message);
    }
    else
    {
    }
    for (value = 0; value < 3; value++)
    {
        switch (value)
        {
            case 0:
                value += 1;
                break;
            default:
                value -= 1;
                break;
        }
    }
    do
    {
        value--;
    }
    while (value);
}
)";
    auto parsed = parse_mary_c(source, options, calls.scope, &table, &map);
    auto expected = encode_script(parsed.at(0).script);
    auto decoded = decode_script(expected);
    auto statements = decompile_script(decoded, calls.scope, "Example");
    auto c = format_mary_c("Example", statements, &map, 1);
    auto again = parse_mary_c(c, options, calls.scope, nullptr, &map);
    require(encode_script(again.at(0).script) == expected, "Mary-C source round trip changed bytes");
    auto legacy = format_legacy(1, "Example", statements, &map);
    auto old = parse_legacy(legacy, &map, calls.scope);
    require(encode_script(old.scripts.at(0).script) == expected, "legacy source round trip changed bytes");

    auto raw = "mary_script(1) void Example(void) { mary_ir {" + format_ir(decoded) + "} }";
    auto numbered = parse_mary_c(raw, options, {}, nullptr, nullptr);
    require(encode_script(numbered.at(0).script) == expected, "numbered IR depends on original tables");
    require(numbered[0].text_names.size() == decoded.strings.size(), "raw IR omitted text symbols");
}

void preprocessing_and_encoding()
{
    Options options;
    options.define("MARY_FOMT_JP");
    auto source = R"(
#define SUM(a,b) ((a) + (b))
#define ALIAS SUM
#define RECURSIVE RECURSIVE
#if defined(REGION_JP) && (0 && 1 / 0 || 1)
typedef enum Result { VALUE = ALIAS(SUM(1, 2), 4), } Result;
#else
invalid
#endif
)";
    auto constants = parse_constant_header(source, options);
    require(constants.integer_constant("VALUE") == 7, "macro rescan or conditional evaluation changed");
    rejects([&] { parse_constant_header("typedef enum X { V = 1 << 64, } X;"); }, "overflowing shift accepted");

    auto map = Charmap::parse(preprocess_charmap(
        "# comment\r\n#if defined(REGION_JP)\r\n8140=　\r\n#else\r\n20= \r\n#endif\r\n", options));
    require(map.encode_text("　") == Bytes({0x81, 0x40}), "regional charmap changed");
    auto ambiguous = Charmap::parse("FA40=same\nFA41=same\n");
    require(!ambiguous.decode_one(Bytes{0xFA, 0x41}), "ambiguous bytes printed as canonical text");
    require(ambiguous.raw_sequence_length(Bytes{0xFA, 0x20}) == 2, "unknown multibyte sequence split");
    rejects([] { Charmap::parse("4100=bad\n"); }, "STR terminator accepted in a mapping");
    rejects([] { decode_script(Bytes{'R', 'I', 'F', 'F'}); }, "truncated RIFF accepted");
}

void source_mapping()
{
    Options options;
    options.define("MARY_FOMT_JP");
    auto source = std::string(R"(#if 0
#include "test.mary.h"
#endif
#if defined(REGION_JP)
#define THRESHOLD 12
#else
#define THRESHOLD 24
#endif
mary_script(4) void Preview(void)
{
    int hour = 15;
    if (hour > THRESHOLD)
    {
        return;
    }
}
)");
    auto processed = preprocess_file(source, "preview.mary.c", options, {});
    const auto script = parse_mary_c(processed, {}).at(0).script;
    std::vector<CodeSource> locations;
    const auto encoded = encode_script(script, &locations);
    require(encoded == encode_script(script), "source mapping changed RIFF bytes");
    const auto branch = std::find_if(locations.begin(), locations.end(), [](const CodeSource &entry)
    {
        return entry.condition_start != SIZE_MAX;
    });
    require(branch != locations.end() && branch->line == 12 && !branch->jump_on_true,
        "source condition lost its line around an include and a regional macro");
    require(branch->condition_start < branch->pc && encoded.at(24 + branch->pc) == 0x1b,
        "source condition points outside its generated BEQ");
    require(std::any_of(locations.begin(), locations.end(), [&](const CodeSource &entry)
    {
        return entry.pc == branch->condition_start && entry.line == branch->line;
    }), "condition entry PC is missing its source line");
}

void put_word(Bytes &rom, std::size_t at, std::uint32_t value)
{
    for (unsigned n = 0; n < 4; ++n)
        rom.at(at + n) = std::uint8_t(value >> (8 * n));
}

void import_boundaries()
{
    Bytes rom(0x200000, 0xFF);
    const std::string title = "HARVESTMOGBA", code = "A4NE";
    std::copy(title.begin(), title.end(), rom.begin() + 0xA0);
    std::copy(code.begin(), code.end(), rom.begin() + 0xAC);
    auto native = identify_rom(rom);
    require(native.has_value(), "supported ROM header was not recognized");
    std::fill(rom.begin() + native->pointer_table_offset,
              rom.begin() + native->pointer_table_offset + native->slot_count * 4, 0);
    for (auto at : native->references)
        put_word(rom, at, gba_pointer(native->pointer_table_offset));
    Script script;
    script.instructions = {{Op::PushInt, 1}, {Op::Discard}};
    auto riff = encode_script(script);
    std::copy(riff.begin(), riff.end(), rom.begin() + 0x100000);
    put_word(rom, native->pointer_table_offset + 4, gba_pointer(0x100000));
    auto layout = resolve_script_layout(rom);
    require(layout.scripts[1]->riff_length == riff.size(), "script allocation is incorrect");
    auto original = rom;
    Script oversized = script;
    oversized.strings.push_back(Bytes(4096, 'A'));
    rejects([&] { write_single_script_in_place(rom, layout, 1, encode_script(oversized)); }, "oversized in-place import accepted");
    require(rom == original, "failed import changed ROM data");

    std::vector<std::optional<Bytes>> slots{std::nullopt, riff, std::nullopt};
    auto packed = PackedScripts::from_slots(slots);
    auto written = write_packed_scripts(rom, layout, packed, 0x140000, 0x120000);
    require(written.first.start == 0x140000 && written.second.start == 0x120000,
            "relocation destinations changed");
    for (auto at : native->references)
        require(read_u32(rom, at) == 0x08120000, "native table reference was not relocated");
    auto relocated = resolve_script_layout(rom);
    require(relocated.metadata_present && relocated.slot_count == 3
                && relocated.scripts[1]->offset == 0x140000,
            "relocated-table metadata did not round trip");
    require(!relocated.scripts[0] && !relocated.scripts[2], "null slots changed");
    rejects([&] { write_single_script_at(rom, relocated, 1, riff, 0x120000); }, "script/table overlap accepted");
}

} // namespace

int main()
{
    try
    {
        preprocessing_and_encoding();
        source_roundtrip();
        source_mapping();
        import_boundaries();
        std::cout << "Source round trips, source mapping, regional preprocessing, and import boundaries passed.\n";
    }
    catch (const std::exception &error)
    {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
