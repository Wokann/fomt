#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace {

std::string Trim(const std::string &value)
{
    const auto first = value.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";

    const auto last = value.find_last_not_of(" \t");
    return value.substr(first, last - first + 1);
}

std::string TrimWhitespace(const std::string &value)
{
    const auto first = value.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";

    const auto last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

std::string ReadTextFile(const std::filesystem::path &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input)
        throw std::runtime_error("cannot read '" + path.string() + "'");

    std::ostringstream buffer;
    buffer << input.rdbuf();
    return buffer.str();
}

void EnsureParentDirectory(const std::filesystem::path &path)
{
    const auto parent = path.parent_path();
    if (!parent.empty())
        std::filesystem::create_directories(parent);
}

void WriteTextFile(const std::filesystem::path &path, const std::string &contents)
{
    EnsureParentDirectory(path);
    std::ofstream output(path, std::ios::binary | std::ios::trunc);
    if (!output)
        throw std::runtime_error("cannot write '" + path.string() + "'");
    output << contents;
    if (!output)
        throw std::runtime_error("cannot write '" + path.string() + "'");
}

std::vector<std::string> SplitLines(const std::string &source)
{
    std::vector<std::string> lines;
    std::istringstream input(source);
    std::string line;
    while (std::getline(input, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        lines.push_back(std::move(line));
    }
    return lines;
}

std::string JoinLines(const std::vector<std::string> &lines)
{
    std::ostringstream output;
    for (const std::string &line : lines)
        output << line << '\n';
    return output.str();
}

bool IsAssemblyStringPayload(const std::string &line)
{
    const std::string trimmed = Trim(line);
    return trimmed.rfind(".ascii", 0) == 0
        || trimmed.rfind(".string", 0) == 0;
}

bool IsAssemblyAlign(const std::string &line)
{
    return Trim(line).rfind(".align", 0) == 0;
}

bool IsExecutableSectionDirective(const std::string &line)
{
    static const std::regex pattern(
        R"(^[\t ]*\.section[\t ]+[A-Za-z0-9_.]+,"ax",%progbits[\t ]*$)");
    return std::regex_match(line, pattern);
}

bool IsCompilerDataTailAlignment(const std::string &line)
{
    // agbcp 2.9 emits this exact alignment while changing from an alloc-only
    // section to a function section. A C/C++ ALIGN(n) attribute is emitted
    // before its object's label instead, so it is not matched.
    static const std::regex pattern(
        R"(^[\t ]*\.align[\t ]+2,[\t ]*0[\t ]*$)");
    return std::regex_match(line, pattern);
}

bool RemoveCompilerDataTailAlignmentBefore(std::vector<std::string> &lines,
    std::size_t next_section)
{
    std::size_t previous = next_section;
    while (previous != 0 && Trim(lines[previous - 1]).empty())
        --previous;
    if (previous == 0 || !IsCompilerDataTailAlignment(lines[previous - 1]))
        return false;

    lines.erase(lines.begin() + static_cast<std::ptrdiff_t>(previous - 1));
    return true;
}

std::size_t FindAssemblyLabel(const std::vector<std::string> &lines,
    const std::string &label)
{
    const std::string wanted = label + ":";
    for (std::size_t index = 0; index < lines.size(); ++index) {
        if (Trim(lines[index]) == wanted)
            return index;
    }
    return std::string::npos;
}

std::vector<std::string> AssemblyStringPayloadAfter(const std::vector<std::string> &lines,
    std::size_t label_index)
{
    std::vector<std::string> payload;
    for (std::size_t index = label_index + 1;
         index < lines.size() && IsAssemblyStringPayload(lines[index]); ++index) {
        payload.push_back(Trim(lines[index]));
    }
    return payload;
}

std::map<std::string, std::string> FindDirectConstCharPointerInitializers(
    const std::string &source)
{
    // This recognizes the ordinary C++ form
    // "char const * const pointer = named_char_array;" in every translation
    // unit.  agbcp 2.9 can replace its target with a duplicate .LC string;
    // only a byte-for-byte match is eligible for repair below.
    static const std::regex pattern(
        R"((?:extern\s+)?char\s+const\s*\*\s*const\s+([A-Za-z_][A-Za-z0-9_]*)\s*=\s*([A-Za-z_][A-Za-z0-9_]*)\s*;)");

    std::map<std::string, std::string> result;
    for (std::sregex_iterator match(source.begin(), source.end(), pattern), end;
         match != end; ++match) {
        result.emplace((*match)[1].str(), (*match)[2].str());
    }
    return result;
}

struct ConstCharPointerArrayInitializer {
    std::string reference_name;
    std::vector<std::string> target_names;
};

std::vector<ConstCharPointerArrayInitializer> FindConstCharPointerArrayInitializers(
    const std::string &source)
{
    // Keep this deliberately constrained to a flat, ordinary pointer array.
    // The generated assembly is checked before any anonymous compiler constant
    // is replaced by a named relocation.
    std::vector<ConstCharPointerArrayInitializer> result;
    static constexpr char kDeclarator[] = "char const * const";
    std::size_t at = 0;
    while ((at = source.find(kDeclarator, at)) != std::string::npos) {
        std::size_t cursor = at + sizeof(kDeclarator) - 1;
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size()
            || !(std::isalpha(static_cast<unsigned char>(source[cursor])) != 0
                || source[cursor] == '_')) {
            at = cursor;
            continue;
        }

        const std::size_t name_begin = cursor++;
        while (cursor < source.size()
            && (std::isalnum(static_cast<unsigned char>(source[cursor])) != 0
                || source[cursor] == '_')) {
            ++cursor;
        }
        const std::string name = source.substr(name_begin, cursor - name_begin);
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size() || source[cursor] != '[') {
            at = cursor;
            continue;
        }
        const std::size_t dimension_end = source.find(']', cursor + 1);
        if (dimension_end == std::string::npos) {
            at = cursor + 1;
            continue;
        }
        cursor = dimension_end + 1;
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size() || source[cursor] != '=') {
            at = cursor;
            continue;
        }
        ++cursor;
        while (cursor < source.size()
            && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
            ++cursor;
        }
        if (cursor == source.size() || source[cursor] != '{') {
            at = cursor;
            continue;
        }
        const std::size_t entries_begin = ++cursor;
        const std::size_t entries_end = source.find('}', entries_begin);
        if (entries_end == std::string::npos) {
            at = entries_begin;
            continue;
        }

        ConstCharPointerArrayInitializer initializer;
        initializer.reference_name = name;

        bool valid = true;
        std::istringstream entries(source.substr(entries_begin, entries_end - entries_begin));
        std::string entry;
        while (std::getline(entries, entry, ',')) {
            entry = TrimWhitespace(entry);
            if (entry.empty()) {
                continue;
            } else if (entry == "nullptr" || entry == "0") {
                initializer.target_names.emplace_back();
            } else if (!entry.empty()
                && (std::isalpha(static_cast<unsigned char>(entry.front())) != 0
                    || entry.front() == '_')
                && std::all_of(entry.begin() + 1, entry.end(), [](const char value) {
                    return std::isalnum(static_cast<unsigned char>(value)) != 0 || value == '_';
                })) {
                initializer.target_names.push_back(std::move(entry));
            } else {
                valid = false;
                break;
            }
        }
        if (valid && !initializer.target_names.empty())
            result.push_back(std::move(initializer));
        at = entries_end + 1;
    }
    return result;
}

bool IsIdentifier(const std::string &value)
{
    if (value.empty()
        || !(std::isalpha(static_cast<unsigned char>(value.front())) != 0
            || value.front() == '_')) {
        return false;
    }
    return std::all_of(value.begin() + 1, value.end(), [](const char value) {
        return std::isalnum(static_cast<unsigned char>(value)) != 0 || value == '_';
    });
}

std::size_t SkipWhitespace(const std::string &source, std::size_t cursor)
{
    while (cursor < source.size()
        && std::isspace(static_cast<unsigned char>(source[cursor])) != 0) {
        ++cursor;
    }
    return cursor;
}

std::size_t FindMatchingDelimiter(const std::string &source, std::size_t begin,
    char open, char close)
{
    if (begin == source.size() || source[begin] != open)
        return std::string::npos;

    std::size_t depth = 0;
    bool in_string = false;
    bool in_character = false;
    bool in_line_comment = false;
    bool in_block_comment = false;
    for (std::size_t cursor = begin; cursor < source.size(); ++cursor) {
        const char value = source[cursor];
        const char next = cursor + 1 < source.size() ? source[cursor + 1] : '\0';
        if (in_line_comment) {
            if (value == '\n')
                in_line_comment = false;
            continue;
        }
        if (in_block_comment) {
            if (value == '*' && next == '/') {
                in_block_comment = false;
                ++cursor;
            }
            continue;
        }
        if (in_string || in_character) {
            if (value == '\\') {
                ++cursor;
            } else if ((in_string && value == '"')
                || (in_character && value == '\'')) {
                in_string = false;
                in_character = false;
            }
            continue;
        }
        if (value == '/' && next == '/') {
            in_line_comment = true;
            ++cursor;
            continue;
        }
        if (value == '/' && next == '*') {
            in_block_comment = true;
            ++cursor;
            continue;
        }
        if (value == '"') {
            in_string = true;
            continue;
        }
        if (value == '\'') {
            in_character = true;
            continue;
        }
        if (value == open) {
            ++depth;
        } else if (value == close && --depth == 0) {
            return cursor;
        }
    }
    return std::string::npos;
}

std::string StripAggregateBraces(std::string value)
{
    value = TrimWhitespace(value);
    while (!value.empty() && (value.front() == '{' || value.front() == '}')) {
        value.erase(value.begin());
        value = TrimWhitespace(value);
    }
    while (!value.empty() && (value.back() == '{' || value.back() == '}')) {
        value.pop_back();
        value = TrimWhitespace(value);
    }
    return value;
}

std::vector<std::string> FlattenAggregateInitializer(const std::string &source,
    std::size_t begin, std::size_t end)
{
    std::vector<std::string> result;
    std::size_t field_begin = begin;
    std::size_t parenthesis_depth = 0;
    bool in_string = false;
    bool in_character = false;
    bool in_line_comment = false;
    bool in_block_comment = false;

    const auto append_field = [&]() {
        const std::string field = StripAggregateBraces(
            source.substr(field_begin, end - field_begin));
        if (!field.empty())
            result.push_back(field);
    };

    for (std::size_t cursor = begin; cursor < end; ++cursor) {
        const char value = source[cursor];
        const char next = cursor + 1 < end ? source[cursor + 1] : '\0';
        if (in_line_comment) {
            if (value == '\n')
                in_line_comment = false;
            continue;
        }
        if (in_block_comment) {
            if (value == '*' && next == '/') {
                in_block_comment = false;
                ++cursor;
            }
            continue;
        }
        if (in_string || in_character) {
            if (value == '\\') {
                ++cursor;
            } else if ((in_string && value == '"')
                || (in_character && value == '\'')) {
                in_string = false;
                in_character = false;
            }
            continue;
        }
        if (value == '/' && next == '/') {
            in_line_comment = true;
            ++cursor;
            continue;
        }
        if (value == '/' && next == '*') {
            in_block_comment = true;
            ++cursor;
            continue;
        }
        if (value == '"') {
            in_string = true;
            continue;
        }
        if (value == '\'') {
            in_character = true;
            continue;
        }
        if (value == '(') {
            ++parenthesis_depth;
        } else if (value == ')' && parenthesis_depth != 0) {
            --parenthesis_depth;
        } else if (value == ',' && parenthesis_depth == 0) {
            const std::string field = StripAggregateBraces(
                source.substr(field_begin, cursor - field_begin));
            if (!field.empty())
                result.push_back(field);
            field_begin = cursor + 1;
        }
    }
    append_field();
    return result;
}

struct WordOnlyAggregateInitializer {
    std::string reference_name;
    std::vector<std::string> fields;
};

std::vector<WordOnlyAggregateInitializer> FindWordOnlyAggregateInitializers(
    const std::string &source)
{
    // This is intentionally a lexical, source-order parser.  It accepts an
    // ordinary aggregate initializer only when its emitted object later proves
    // to contain precisely one .word for every source field.  That condition
    // makes it safe for pointer-bearing structure arrays without guessing any
    // field types or changing byte/halfword records.
    std::vector<WordOnlyAggregateInitializer> result;
    for (std::size_t at = 0; at < source.size();) {
        if (!(std::isalpha(static_cast<unsigned char>(source[at])) != 0
                || source[at] == '_')) {
            ++at;
            continue;
        }
        const std::size_t name_begin = at++;
        while (at < source.size()
            && (std::isalnum(static_cast<unsigned char>(source[at])) != 0
                || source[at] == '_')) {
            ++at;
        }
        const std::string name = source.substr(name_begin, at - name_begin);
        if (name.empty() || name.front() != 'g')
            continue;

        std::size_t cursor = SkipWhitespace(source, at);
        while (cursor < source.size() && source[cursor] == '[') {
            const std::size_t end = FindMatchingDelimiter(source, cursor, '[', ']');
            if (end == std::string::npos) {
                cursor = source.size();
                break;
            }
            cursor = SkipWhitespace(source, end + 1);
        }
        while (cursor < source.size()) {
            const std::size_t attribute_begin = cursor;
            while (cursor < source.size()
                && (std::isalnum(static_cast<unsigned char>(source[cursor])) != 0
                    || source[cursor] == '_')) {
                ++cursor;
            }
            const std::string attribute = source.substr(attribute_begin,
                cursor - attribute_begin);
            if (attribute != "ALIGN" && attribute != "SECTION"
                && attribute != "__attribute__") {
                cursor = attribute_begin;
                break;
            }
            cursor = SkipWhitespace(source, cursor);
            if (cursor == source.size() || source[cursor] != '(') {
                cursor = attribute_begin;
                break;
            }
            const std::size_t end = FindMatchingDelimiter(source, cursor, '(', ')');
            if (end == std::string::npos) {
                cursor = source.size();
                break;
            }
            cursor = SkipWhitespace(source, end + 1);
        }
        if (cursor == source.size() || source[cursor] != '=')
            continue;
        cursor = SkipWhitespace(source, cursor + 1);
        if (cursor == source.size() || source[cursor] != '{')
            continue;
        const std::size_t end = FindMatchingDelimiter(source, cursor, '{', '}');
        if (end == std::string::npos)
            continue;

        std::vector<std::string> fields = FlattenAggregateInitializer(source,
            cursor + 1, end);
        if (!fields.empty())
            result.push_back({ name, std::move(fields) });
        at = end + 1;
    }
    return result;
}

std::vector<std::size_t> FindObjectWordInitializers(
    const std::vector<std::string> &lines, std::size_t label_index)
{
    std::vector<std::size_t> result;
    static const std::regex global_pattern(
        R"(^[\t ]*\.(?:globl|global)[\t ]+[A-Za-z_][A-Za-z0-9_]*[\t ]*$)");
    for (std::size_t index = label_index + 1; index < lines.size(); ++index) {
        if (std::regex_match(lines[index], global_pattern))
            break;
        if (Trim(lines[index]).rfind(".word", 0) == 0)
            result.push_back(index);
    }
    return result;
}

void FixupConstCharPointerWord(std::vector<std::string> &lines,
    std::size_t word_index, const std::string &reference_name,
    const std::string &target_name,
    std::vector<std::pair<std::size_t, std::size_t>> &removals,
    std::set<std::string> &removed_local_constants)
{
    if (word_index == lines.size())
        throw std::runtime_error("missing initializer for '" + reference_name + "'");

    const std::string word = Trim(lines[word_index]);
    static constexpr std::string_view kWord = ".word";
    if (word.rfind(kWord, 0) != 0)
        throw std::runtime_error("expected .word initializer for '" + reference_name + "'");
    const std::string local_constant = Trim(word.substr(kWord.size()));
    if (local_constant.rfind(".LC", 0) != 0)
        return;

    const std::size_t local_label = FindAssemblyLabel(lines, local_constant);
    const std::size_t target_label = FindAssemblyLabel(lines, target_name);
    if (local_label == std::string::npos || target_label == std::string::npos) {
        throw std::runtime_error("cannot resolve compiler constant for '"
            + reference_name + "'");
    }

    const std::vector<std::string> local_payload =
        AssemblyStringPayloadAfter(lines, local_label);
    const std::vector<std::string> target_payload =
        AssemblyStringPayloadAfter(lines, target_label);
    if (local_payload.empty() || local_payload != target_payload) {
        throw std::runtime_error("compiler constant for '" + reference_name
            + "' does not exactly duplicate '" + target_name + "'");
    }

    const std::size_t local_end = local_label + 1 + local_payload.size();
    if (local_end == lines.size() || !IsAssemblyAlign(lines[local_end])) {
        throw std::runtime_error("unexpected compiler-constant layout for '"
            + reference_name + "'");
    }

    const std::size_t indent_end = lines[word_index].find_first_not_of(" \t");
    const std::string indent = indent_end == std::string::npos
        ? "" : lines[word_index].substr(0, indent_end);
    lines[word_index] = indent + ".word\t" + target_name;
    if (removed_local_constants.insert(local_constant).second)
        removals.emplace_back(local_label, local_end);
}

std::string FixupSameUnitConstCharReferences(const std::string &source,
    const std::string &assembly)
{
    const std::map<std::string, std::string> references =
        FindDirectConstCharPointerInitializers(source);
    const std::vector<ConstCharPointerArrayInitializer> arrays =
        FindConstCharPointerArrayInitializers(source);
    const std::vector<WordOnlyAggregateInitializer> aggregates =
        FindWordOnlyAggregateInitializers(source);
    if (references.empty() && arrays.empty() && aggregates.empty())
        return assembly;

    std::vector<std::string> lines = SplitLines(assembly);
    std::vector<std::pair<std::size_t, std::size_t>> removals;
    std::set<std::string> removed_local_constants;

    for (const WordOnlyAggregateInitializer &aggregate : aggregates) {
        const std::size_t reference_label = FindAssemblyLabel(lines,
            aggregate.reference_name);
        if (reference_label == std::string::npos)
            continue;

        const std::vector<std::size_t> words = FindObjectWordInitializers(lines,
            reference_label);
        if (words.size() != aggregate.fields.size())
            continue;

        for (std::size_t index = 0; index < words.size(); ++index) {
            const std::string target_name = TrimWhitespace(aggregate.fields[index]);
            if (!IsIdentifier(target_name)
                || FindAssemblyLabel(lines, target_name) == std::string::npos
                || AssemblyStringPayloadAfter(lines,
                       FindAssemblyLabel(lines, target_name)).empty()) {
                continue;
            }
            const std::string reference = aggregate.reference_name + "["
                + std::to_string(index) + "]";
            FixupConstCharPointerWord(lines, words[index], reference, target_name,
                removals, removed_local_constants);
        }
    }

    for (const auto &[reference_name, target_name] : references) {
        const std::size_t reference_label = FindAssemblyLabel(lines, reference_name);
        if (reference_label == std::string::npos)
            continue;

        std::size_t word_index = reference_label + 1;
        while (word_index < lines.size() && Trim(lines[word_index]).empty())
            ++word_index;
        FixupConstCharPointerWord(lines, word_index, reference_name, target_name,
            removals, removed_local_constants);
    }

    for (const ConstCharPointerArrayInitializer &array : arrays) {
        const std::size_t reference_label = FindAssemblyLabel(lines, array.reference_name);
        if (reference_label == std::string::npos)
            continue;

        std::size_t word_index = reference_label + 1;
        for (std::size_t index = 0; index < array.target_names.size(); ++index) {
            while (word_index < lines.size() && Trim(lines[word_index]).empty())
                ++word_index;
            const std::string reference = array.reference_name + "["
                + std::to_string(index) + "]";
            if (array.target_names[index].empty()) {
                if (word_index == lines.size()
                    || Trim(lines[word_index]).rfind(".word", 0) != 0) {
                    throw std::runtime_error("expected .word initializer for '" + reference + "'");
                }
            } else {
                FixupConstCharPointerWord(lines, word_index, reference,
                    array.target_names[index], removals, removed_local_constants);
            }
            ++word_index;
        }
    }

    std::sort(removals.rbegin(), removals.rend());
    for (const auto &[begin, end] : removals)
        lines.erase(lines.begin() + static_cast<std::ptrdiff_t>(begin),
            lines.begin() + static_cast<std::ptrdiff_t>(end));
    return JoinLines(lines);
}

void RemoveCompilerDataSectionTailAlignment(std::vector<std::string> &lines)
{
    // Old agbcp closes an alloc-only section with ".align 2, 0" before it
    // opens the following executable section. The executable section has its
    // own leading alignment, so retaining the former only changes the size of
    // the preceding data section. In a ROM layout with an exact next address,
    // that manufactured padding can make the linker move backwards.
    //
    // This deliberately removes only an alignment immediately at a data ->
    // executable section transition. Source ALIGN(n) declarations align the
    // following named object and therefore do not have this shape.
    bool have_current_section = false;
    bool current_section_is_executable = false;
    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::string trimmed = Trim(lines[index]);
        if (trimmed == ".text") {
            if (have_current_section && !current_section_is_executable
                && RemoveCompilerDataTailAlignmentBefore(lines, index)) {
                --index;
            }
            have_current_section = true;
            current_section_is_executable = true;
            continue;
        }
        if (trimmed.rfind(".section", 0) != 0)
            continue;

        const bool next_section_is_executable =
            IsExecutableSectionDirective(lines[index]);
        if (next_section_is_executable && have_current_section
            && !current_section_is_executable
            && RemoveCompilerDataTailAlignmentBefore(lines, index)) {
                --index;
        }
        have_current_section = true;
        current_section_is_executable = next_section_is_executable;
    }
}

void NormalizeCallViaR2ArgumentSetup(std::vector<std::string> &lines)
{
    // agbcp sometimes schedules a PC-relative r2 load before the independent
    // r1 register copy immediately before libgcc's _call_via_r2 trampoline.
    // The ARM procedure-call ABI makes those two preparations independent.
    // Put the argument registers in their conventional r0/r1/r2 order when
    // the exact safe three-instruction pattern is present. This is purposely
    // generic: it applies to any ordinary C/C++ source that calls the shared
    // ARM trampoline, not to a particular function or data label.
    static const std::regex literal_r2_pattern(
        R"(^ldr[\t ]+r2,[\t ]+\.L[A-Za-z0-9_+]+$)");
    static const std::regex copy_r1_pattern(
        R"(^adds?[\t ]+r1,[\t ]+r(?:[0-9]|1[0-2]),[\t ]+#0$)");
    static const std::regex call_pattern(
        R"(^bl[\t ]+_call_via_r2$)");

    for (std::size_t index = 0; index + 2 < lines.size(); ++index) {
        if (!std::regex_match(Trim(lines[index]), literal_r2_pattern)
            || !std::regex_match(Trim(lines[index + 1]), copy_r1_pattern)
            || !std::regex_match(Trim(lines[index + 2]), call_pattern)) {
            continue;
        }

        std::swap(lines[index], lines[index + 1]);
        ++index;
    }
}

void NormalizeThreeOutcomeZeroBranch(std::vector<std::string> &lines)
{
    // agbcp may emit a three-outcome dispatch as
    //
    //   cmp rN, #1; beq one; cmp rN, #0; beq zero; cmp rN, #2; beq two
    //
    // while the original compiler used "cmp rN, #1; bcc zero" for its
    // second comparison. The two forms are exactly equivalent for every
    // unsigned machine word: the only value below one is zero. Normalize only
    // this complete, adjacent dispatch shape; unrelated zero comparisons are
    // deliberately left untouched.
    static const std::regex compare_pattern(
        R"(^cmp[\t ]+r([0-9]|1[0-2]),[\t ]+#(?:0x)?([0-9a-fA-F]+)$)");
    static const std::regex branch_pattern(
        R"(^beq[\t ]+([^\t ]+)(?:[\t ]+@.*)?$)");
    static const std::regex debug_marker_pattern(R"(^\.LM[0-9]+:$)");

    const auto next_instruction = [&lines](std::size_t index) {
        while (index < lines.size()) {
            const std::string trimmed = Trim(lines[index]);
            if (!trimmed.empty()
                && !std::regex_match(trimmed, debug_marker_pattern)) {
                break;
            }
            ++index;
        }
        return index;
    };

    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::size_t first_index = next_instruction(index);
        const std::size_t second_index = next_instruction(first_index + 1);
        const std::size_t third_index = next_instruction(second_index + 1);
        const std::size_t fourth_index = next_instruction(third_index + 1);
        const std::size_t fifth_index = next_instruction(fourth_index + 1);
        const std::size_t sixth_index = next_instruction(fifth_index + 1);
        if (sixth_index >= lines.size())
            break;
        std::smatch first_compare;
        std::smatch first_branch;
        std::smatch zero_compare;
        std::smatch zero_branch;
        std::smatch two_compare;
        std::smatch two_branch;
        const std::string first = Trim(lines[first_index]);
        const std::string second = Trim(lines[second_index]);
        const std::string third = Trim(lines[third_index]);
        const std::string fourth = Trim(lines[fourth_index]);
        const std::string fifth = Trim(lines[fifth_index]);
        const std::string sixth = Trim(lines[sixth_index]);
        if (!std::regex_match(first, first_compare, compare_pattern)
            || !std::regex_match(second, first_branch, branch_pattern)
            || !std::regex_match(third, zero_compare, compare_pattern)
            || !std::regex_match(fourth, zero_branch, branch_pattern)
            || !std::regex_match(fifth, two_compare, compare_pattern)
            || !std::regex_match(sixth, two_branch, branch_pattern)
            || first_compare[2].str() != "1"
            || zero_compare[2].str() != "0"
            || two_compare[2].str() != "2"
            || first_compare[1].str() != zero_compare[1].str()
            || first_compare[1].str() != two_compare[1].str()) {
            continue;
        }

        const std::string indent = lines[third_index].substr(0,
            lines[third_index].find_first_not_of("\t "));
        const std::string branch_indent = lines[fourth_index].substr(0,
            lines[fourth_index].find_first_not_of("\t "));
        lines[third_index] = indent + "cmp\tr" + zero_compare[1].str() + ", #0x1";
        lines[fourth_index] = branch_indent + "bcc\t" + zero_branch[1].str();
        index = sixth_index;
    }
}

std::string AlignExecutableSections(const std::string &assembly)
{
    // This is the former align_sections.sh policy, now applied by the same
    // generic pass that repairs relocations.  It only closes executable
    // compiler sections; explicitly aligned .rodata objects keep the exact
    // ALIGN(n) directives emitted from their ordinary C/C++ declarations.
    static const std::regex section_pattern(
        R"(^[\t ]*\.section[\t ]+([A-Za-z0-9_.]+),"ax",%progbits[\t ]*$)");

    std::vector<std::string> lines = SplitLines(assembly);
    RemoveCompilerDataSectionTailAlignment(lines);
    NormalizeCallViaR2ArgumentSetup(lines);
    NormalizeThreeOutcomeZeroBranch(lines);
    std::vector<std::string> sections;
    std::set<std::string> seen_sections;
    for (const std::string &line : lines) {
        std::smatch match;
        if (std::regex_match(line, match, section_pattern)
            && seen_sections.insert(match[1].str()).second) {
            sections.push_back(match[1].str());
        }
    }

    for (const std::string &section : sections) {
        lines.push_back("\t.section \"" + section + "\"");
        lines.push_back("\t.align 2, 0");
    }
    lines.push_back("\t.text");
    lines.push_back("\t.align 2, 0");
    return JoinLines(lines);
}

std::string PreprocessAssembly(const std::string &source, const std::string &assembly)
{
    return AlignExecutableSections(FixupSameUnitConstCharReferences(source, assembly));
}

void Require(bool condition, const std::string &message)
{
    if (!condition)
        throw std::runtime_error("self-test failed: " + message);
}

void SelfTest()
{
    const std::string source =
        "char const gNamedByteSequence[] = \"A\";\n"
        "char const * const gPointerToNamedByteSequence = gNamedByteSequence;\n"
        "char const * const gNamedPointers[] = {\n"
        "    gNamedByteSequence,\n"
        "    gNamedByteSequence,\n"
        "};\n"
        "struct NamedPointerPair { unsigned int kind; char const *text; "
        "unsigned int value; char const *repeat; };\n"
        "NamedPointerPair const gNamedPointerPairs[] = {\n"
        "    { 0, gNamedByteSequence, 1, gNamedByteSequence },\n"
        "};\n";
    const std::string assembly =
        "\t.section .rodata.sample,\"a\",%progbits\n"
        "gNamedByteSequence:\n"
        "\t.ascii\t\"A\\000\"\n"
        ".LC0:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.align\t2, 0\n"
        "gPointerToNamedByteSequence:\n"
        "\t.word\t.LC0\n"
        ".LC1:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.align\t2, 0\n"
        "gNamedPointers:\n"
        "\t.word\t.LC1\n"
        "\t.word\t.LC1\n"
        ".LC2:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.align\t2, 0\n"
        "gNamedPointerPairs:\n"
        "\t.word\t0\n"
        "\t.word\t.LC2\n"
        "\t.word\t1\n"
        "\t.word\t.LC2\n"
        "\t.section .rodata.compiler_tail,\"a\",%progbits\n"
        "gCompilerPaddedText:\n"
        "\t.ascii\t\"Error\\000\"\n"
        "\t.align\t2, 0\n"
        "\t.section .text.sample,\"ax\",%progbits\n"
        "sample_function:\n"
        "\tbx\tlr\n"
        "\t.section .rodata.default_tail,\"a\",%progbits\n"
        "gDefaultCompilerPaddedData:\n"
        "\t.byte\t0x1\n"
        "\t.align\t2, 0\n"
        "\t.text\n"
        "default_sample_function:\n"
        "\tbx\tlr\n";

    const std::string output = PreprocessAssembly(source, assembly);
    Require(output.find(".LC0:") == std::string::npos
            && output.find(".LC1:") == std::string::npos
            && output.find(".LC2:") == std::string::npos,
        "duplicate compiler string constants were retained");
    Require(output.find(".word\tgNamedByteSequence") != std::string::npos,
        "named text relocation was not restored");
    Require(output.find("\t.section \".text.sample\"\n\t.align 2, 0\n") != std::string::npos,
        "executable section alignment was not appended");
    Require(output.find("\t.section \".rodata.sample\"") == std::string::npos,
        "ordinary rodata was given an implicit text-section alignment");
    Require(output.find("gCompilerPaddedText:\n\t.ascii\t\"Error\\000\"\n"
                        "\t.align\t2, 0\n\t.section .text.sample") == std::string::npos,
        "compiler data-section tail alignment was retained");
    Require(output.find("gCompilerPaddedText:\n\t.ascii\t\"Error\\000\"\n"
                        "\t.section .text.sample") != std::string::npos,
        "compiler data-section tail alignment removed data payload");
    Require(output.find("gDefaultCompilerPaddedData:\n\t.byte\t0x1\n"
                        "\t.align\t2, 0\n\t.text\n") == std::string::npos,
        "ordinary rodata tail alignment was retained");
    Require(output.find("gDefaultCompilerPaddedData:\n\t.byte\t0x1\n"
                        "\t.text\n") != std::string::npos,
        "ordinary rodata tail alignment removed data payload");

    const std::string trampoline_assembly =
        "\t.text\n"
        "glyph_renderer:\n"
        "\tldr\tr2, .Lglyph_renderer_target\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\t_call_via_r2\n"
        "unrelated_call:\n"
        "\tldr\tr2, [r0]\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\t_call_via_r2\n";
    const std::string normalized = PreprocessAssembly("", trampoline_assembly);
    Require(normalized.find("\tadd\tr1, r5, #0\n"
                            "\tldr\tr2, .Lglyph_renderer_target\n"
                            "\tbl\t_call_via_r2\n") != std::string::npos,
        "safe _call_via_r2 argument setup was not normalized");
    Require(normalized.find("\tldr\tr2, [r0]\n"
                            "\tadd\tr1, r5, #0\n"
                            "\tbl\t_call_via_r2\n") != std::string::npos,
        "non-literal _call_via_r2 setup was changed");

    const std::string three_outcome_assembly =
        "\t.text\n"
        "three_outcome:\n"
        "\tcmp\tr0, #0x1\n"
        "\tbeq\t.Lone\n"
        "\tcmp\tr0, #0\n"
        "\tbeq\t.Lzero\n"
        "\tcmp\tr0, #0x2\n"
        "\tbeq\t.Ltwo\n"
        "ordinary_zero_test:\n"
        "\tcmp\tr1, #0\n"
        "\tbeq\t.Lordinary\n";
    const std::string normalized_dispatch =
        PreprocessAssembly("", three_outcome_assembly);
    Require(normalized_dispatch.find("\tcmp\tr0, #0x1\n"
                                    "\tbcc\t.Lzero\n"
                                    "\tcmp\tr0, #0x2\n") != std::string::npos,
        "three-outcome zero branch was not normalized");
    Require(normalized_dispatch.find("ordinary_zero_test:\n"
                                    "\tcmp\tr1, #0\n"
                                    "\tbeq\t.Lordinary\n") != std::string::npos,
        "ordinary zero comparison was changed");
}

const char *Usage()
{
    return "usage:\n"
           "  fomt-preproc self-test\n"
           "  fomt-preproc asm SOURCE ASSEMBLY\n";
}

int Run(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]) == "self-test") {
        SelfTest();
        std::cout << "fomt-preproc: self-test passed\n";
        return 0;
    }
    if (argc == 4 && std::string(argv[1]) == "asm") {
        const std::filesystem::path source = argv[2];
        const std::filesystem::path assembly = argv[3];
        WriteTextFile(assembly, PreprocessAssembly(ReadTextFile(source), ReadTextFile(assembly)));
        return 0;
    }
    throw std::runtime_error(Usage());
}

} // namespace

int main(int argc, char **argv)
{
    try {
        return Run(argc, argv);
    } catch (const std::exception &error) {
        std::cerr << "fomt-preproc: " << error.what() << '\n';
        return 2;
    }
}
