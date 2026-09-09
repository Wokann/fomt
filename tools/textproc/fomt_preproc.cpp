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

bool IsAssemblyDataSectionTransition(const std::string &line)
{
    const std::string trimmed = Trim(line);
    return trimmed == ".text" || trimmed.rfind(".section", 0) == 0;
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
    if (local_end == lines.size()
        || (!IsAssemblyAlign(lines[local_end])
            && !IsAssemblyDataSectionTransition(lines[local_end]))) {
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

std::set<std::string> FindExpressionReferencedCharArrays(
    const std::string &source)
{
    // A direct function expression such as "return gText_Name;" is another
    // normal C/C++ way to consume a named byte string.  agbcp 2.9 sometimes
    // materializes a second .LC copy for this form, even though it preserves
    // the named definition in a custom data section.
    static const std::regex declaration_pattern(
        R"(\bchar\s+const\s+([A-Za-z_][A-Za-z0-9_]*)\s*\[\s*\])");

    std::set<std::string> result;
    for (std::sregex_iterator match(source.begin(), source.end(),
             declaration_pattern), end;
         match != end; ++match) {
        const std::string name = (*match)[1].str();
        const std::regex use_pattern(
            R"((?:\breturn\s+|[=(,]\s*)" + name + R"(\b))");
        if (std::regex_search(source, use_pattern))
            result.insert(name);
    }
    return result;
}

void FixupExpressionStringLiteralReferences(std::vector<std::string> &lines,
    const std::set<std::string> &target_names,
    std::vector<std::pair<std::size_t, std::size_t>> &removals,
    std::set<std::string> &removed_local_constants)
{
    // Do not infer an intended target from a byte sequence alone.  A repair
    // is permitted only when source syntax has already proved that a named
    // array is used as an expression, and exactly one such named array has
    // the compiler constant's byte-for-byte payload.
    for (std::size_t local_label = 0; local_label < lines.size(); ++local_label) {
        const std::string label_line = Trim(lines[local_label]);
        if (label_line.size() < 5 || label_line.back() != ':'
            || label_line.rfind(".LC", 0) != 0) {
            continue;
        }
        const std::string local_constant = label_line.substr(0,
            label_line.size() - 1);
        if (removed_local_constants.find(local_constant)
            != removed_local_constants.end()) {
            continue;
        }

        const std::vector<std::string> local_payload =
            AssemblyStringPayloadAfter(lines, local_label);
        if (local_payload.empty())
            continue;

        std::string target_name;
        for (const std::string &candidate : target_names) {
            const std::size_t target_label = FindAssemblyLabel(lines, candidate);
            if (target_label == std::string::npos
                || AssemblyStringPayloadAfter(lines, target_label) != local_payload) {
                continue;
            }
            if (!target_name.empty()) {
                target_name.clear();
                break;
            }
            target_name = candidate;
        }
        if (target_name.empty())
            continue;

        std::vector<std::size_t> words;
        for (std::size_t index = 0; index < lines.size(); ++index) {
            const std::string word = Trim(lines[index]);
            if (word == ".word " + local_constant
                || word == ".word\t" + local_constant) {
                words.push_back(index);
            }
        }
        if (words.empty())
            continue;

        const std::size_t local_end = local_label + 1 + local_payload.size();
        if (local_end == lines.size()
            || (!IsAssemblyAlign(lines[local_end])
                && !IsAssemblyDataSectionTransition(lines[local_end]))) {
            throw std::runtime_error("unexpected compiler-constant layout for expression '"
                + target_name + "'");
        }

        for (const std::size_t word_index : words) {
            const std::size_t indent_end = lines[word_index].find_first_not_of(" \t");
            const std::string indent = indent_end == std::string::npos
                ? "" : lines[word_index].substr(0, indent_end);
            lines[word_index] = indent + ".word\t" + target_name;
        }
        if (removed_local_constants.insert(local_constant).second)
            removals.emplace_back(local_label, local_end);
    }
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
    const std::set<std::string> expression_targets =
        FindExpressionReferencedCharArrays(source);
    if (references.empty() && arrays.empty() && aggregates.empty()
        && expression_targets.empty()) {
        return assembly;
    }

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

    FixupExpressionStringLiteralReferences(lines, expression_targets, removals,
        removed_local_constants);

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

bool IsNumericLocalLabelWithPrefix(const std::string &line,
    std::string_view prefix)
{
    const std::string marker = Trim(line);
    if (marker.size() <= prefix.size() + 1 || marker.back() != ':'
        || marker.compare(0, prefix.size(), prefix) != 0) {
        return false;
    }

    return std::all_of(marker.begin()
            + static_cast<std::ptrdiff_t>(prefix.size()),
        marker.end() - 1, [](unsigned char character) {
            return std::isdigit(character) != 0;
        });
}

bool IsCompilerDebugMarker(const std::string &line)
{
    // Preserve the established matching scope for older normalization passes.
    return IsNumericLocalLabelWithPrefix(line, ".LM")
        || IsNumericLocalLabelWithPrefix(line, ".LBB")
        || IsNumericLocalLabelWithPrefix(line, ".LBE");
}

bool IsExtendedCompilerDebugMarker(const std::string &line)
{
    // GCC 2.9-arm additionally emits .LSM source-map labels between every
    // instruction. Newer scheduling repairs opt in to skipping them; older
    // normalizers retain their original matching scope.
    return IsCompilerDebugMarker(line)
        || IsNumericLocalLabelWithPrefix(line, ".LSM");
}

std::vector<std::size_t> FindAdjacentInstructions(
    const std::vector<std::string> &lines, std::size_t start,
    std::size_t count, bool skip_extended_debug_markers = false)
{
    std::vector<std::size_t> result;
    for (std::size_t index = start; index < lines.size() && result.size() < count;
         ++index) {
        const std::string trimmed = Trim(lines[index]);
        if (trimmed.empty()
            || (skip_extended_debug_markers
                    ? IsExtendedCompilerDebugMarker(trimmed)
                    : IsCompilerDebugMarker(trimmed))) {
            continue;
        }
        if (trimmed.front() == '.' || trimmed.back() == ':')
            return {};
        result.push_back(index);
    }
    return result.size() == count ? result : std::vector<std::size_t>();
}

std::string InstructionIndent(const std::string &line)
{
    const std::size_t first = line.find_first_not_of("\t ");
    return first == std::string::npos ? "\t" : line.substr(0, first);
}

bool ContainsRegisterToken(const std::string &line, const std::string &reg)
{
    std::size_t position = line.find(reg);
    while (position != std::string::npos) {
        const bool left_boundary = position == 0
            || (!std::isalnum(static_cast<unsigned char>(line[position - 1]))
                && line[position - 1] != '_');
        const std::size_t end = position + reg.size();
        const bool right_boundary = end == line.size()
            || (!std::isalnum(static_cast<unsigned char>(line[end]))
                && line[end] != '_');
        if (left_boundary && right_boundary)
            return true;
        position = line.find(reg, position + 1);
    }
    return false;
}

bool IsWriteOnlyRegisterAssignment(const std::string &line,
    const std::string &reg)
{
    const std::size_t opcode_end = line.find_first_of("\t ");
    if (opcode_end == std::string::npos)
        return false;

    const std::string opcode = line.substr(0, opcode_end);
    const bool writes_first_operand = opcode == "mov" || opcode == "add"
        || opcode == "sub" || opcode == "lsl" || opcode == "lsr"
        || opcode == "asr" || opcode == "ldr" || opcode == "mvn"
        || opcode == "and" || opcode == "orr" || opcode == "eor"
        || opcode == "mul" || opcode == "neg" || opcode == "bic";
    if (!writes_first_operand)
        return false;

    const std::string operands = Trim(line.substr(opcode_end));
    if (operands.compare(0, reg.size(), reg) != 0
        || operands.size() == reg.size() || operands[reg.size()] != ',') {
        return false;
    }
    return !ContainsRegisterToken(operands.substr(reg.size()), reg);
}

bool IsControlTransferInstruction(const std::string &line)
{
    const std::size_t opcode_end = line.find_first_of("\t ");
    const std::string opcode = line.substr(0, opcode_end);
    return opcode == "b" || opcode == "beq" || opcode == "bne"
        || opcode == "bcs" || opcode == "bcc" || opcode == "bmi"
        || opcode == "bpl" || opcode == "bvs" || opcode == "bvc"
        || opcode == "bhi" || opcode == "bls" || opcode == "bge"
        || opcode == "blt" || opcode == "bgt" || opcode == "ble"
        || opcode == "bl" || opcode == "blx" || opcode == "bx";
}

bool BranchTargetCannotObserveRegister(const std::vector<std::string> &lines,
    std::size_t branch_index, const std::string &target,
    const std::string &reg)
{
    std::size_t target_index = branch_index + 1;
    for (; target_index < lines.size(); ++target_index) {
        if (Trim(lines[target_index]) == target + ":")
            break;
    }
    if (target_index == lines.size())
        return false;

    // Follow the branch target's straight-line path until the staging
    // register is overwritten, returned, or an unproven control transfer is
    // encountered. This is independent of source function and label names.
    for (++target_index; target_index < lines.size(); ++target_index) {
        const std::string instruction = Trim(lines[target_index]);
        if (instruction.empty() || IsExtendedCompilerDebugMarker(instruction)
            || instruction.back() == ':') {
            continue;
        }
        if (instruction.rfind(".size", 0) == 0
            || instruction.rfind(".LFE", 0) == 0) {
            return true;
        }
        if (instruction.front() == '.')
            continue;
        if (IsControlTransferInstruction(instruction))
            return instruction.rfind("bx", 0) == 0
                && !ContainsRegisterToken(instruction, reg);
        if (!ContainsRegisterToken(instruction, reg))
            continue;
        if (instruction.rfind("pop", 0) == 0)
            return true;
        return IsWriteOnlyRegisterAssignment(instruction, reg);
    }
    return false;
}

void NormalizeStackedArgumentCalleeSavedSetup(std::vector<std::string> &lines)
{
    // Affected agbcp builds sometimes save r1 through a low callee-saved
    // register before loading a stacked argument into r1, then copy the saved
    // value into a high callee-saved register.  When that low register is
    // immediately overwritten from r2, the independent operations can be
    // scheduled in the original order without changing any live value:
    //
    //   stage = r1; r1 = stacked; save0 = r0; high = stage;
    //   stage = r2; save3 = r3; scratch = sp + n; call
    //
    // becomes:
    //
    //   save0 = r0; high = r1; stage = r2; save3 = r3;
    //   r1 = stacked; scratch = sp + n; call
    //
    // The rule intentionally depends only on this complete data-flow shape.
    // It accepts arbitrary stack offsets, high registers, scratch offsets,
    // and call targets; it has no source-function, label, ROM-offset, or hex
    // byte dependency.
    static const std::regex stage_r1_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r1,[\t ]+#0$)");
    static const std::regex stacked_argument_pattern(
        R"(^ldr[\t ]+r1,[\t ]+\[sp,[\t ]+#(0x)?[0-9a-fA-F]+\]$)");
    static const std::regex save_r0_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r0,[\t ]+#0$)");
    static const std::regex move_staged_r1_pattern(
        R"(^mov[\t ]+(r(?:8|9|1[0-2])|ip|sl|fp),[\t ]+(r[4-7])$)");
    static const std::regex save_r2_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r2,[\t ]+#0$)");
    static const std::regex save_r3_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r3,[\t ]+#0$)");
    static const std::regex scratch_pattern(
        R"(^add[\t ]+r0,[\t ]+sp,[\t ]+#(?:0x)?[0-9a-fA-F]+$)");
    static const std::regex call_pattern(
        R"(^bl[\t ]+[^ \t]+(?:[\t ]+@.*)?$)");

    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::vector<std::size_t> steps =
            FindAdjacentInstructions(lines, index, 8, true);
        if (steps.empty())
            continue;

        std::smatch stage_r1;
        std::smatch save_r0;
        std::smatch move_staged_r1;
        std::smatch save_r2;
        std::smatch save_r3;
        const std::string stage_instruction = Trim(lines[steps[0]]);
        const std::string stacked_argument_instruction = Trim(lines[steps[1]]);
        const std::string save_r0_instruction = Trim(lines[steps[2]]);
        const std::string move_staged_r1_instruction = Trim(lines[steps[3]]);
        const std::string save_r2_instruction = Trim(lines[steps[4]]);
        const std::string save_r3_instruction = Trim(lines[steps[5]]);
        const std::string scratch_instruction = Trim(lines[steps[6]]);
        const std::string call_instruction = Trim(lines[steps[7]]);
        if (!std::regex_match(stage_instruction, stage_r1, stage_r1_pattern)
            || !std::regex_match(stacked_argument_instruction,
                stacked_argument_pattern)
            || !std::regex_match(save_r0_instruction, save_r0, save_r0_pattern)
            || !std::regex_match(move_staged_r1_instruction, move_staged_r1,
                move_staged_r1_pattern)
            || !std::regex_match(save_r2_instruction, save_r2, save_r2_pattern)
            || !std::regex_match(save_r3_instruction, save_r3, save_r3_pattern)
            || !std::regex_match(scratch_instruction, scratch_pattern)
            || !std::regex_match(call_instruction, call_pattern)) {
            continue;
        }

        const std::string stage = stage_r1[1].str();
        const std::string saved_r0 = save_r0[1].str();
        const std::string saved_r2 = save_r2[1].str();
        const std::string saved_r3 = save_r3[1].str();
        if (move_staged_r1[2].str() != stage || saved_r2 != stage
            || stage == saved_r0 || stage == saved_r3
            || saved_r0 == saved_r3) {
            continue;
        }

        const std::string indent = InstructionIndent(lines[steps[0]]);
        const std::string stacked_argument = lines[steps[1]];
        const std::string scratch = lines[steps[6]];
        const std::string call = lines[steps[7]];
        lines[steps[0]] = indent + "add\t" + saved_r0 + ", r0, #0";
        lines[steps[1]] = indent + "mov\t" + move_staged_r1[1].str()
            + ", r1";
        lines[steps[2]] = indent + "add\t" + saved_r2 + ", r2, #0";
        lines[steps[3]] = indent + "add\t" + saved_r3 + ", r3, #0";
        lines[steps[4]] = stacked_argument;
        lines[steps[5]] = scratch;
        lines[steps[6]] = call;
        lines.erase(lines.begin() + static_cast<std::ptrdiff_t>(steps[7]));
        index = steps[6];
    }
}

void NormalizeDeferredCalleeSavedArgumentSetup(std::vector<std::string> &lines)
{
    // In this Thumb argument-preservation shape, agbcp first copies r1
    // through a callee-saved staging register, then reloads the stacked fifth
    // argument before moving that copy to a high register. The original
    // compiler placed the independent high-register assignment first.
    //
    // The complete argument/data-flow shape proves that the staging register
    // is dead on the accepted path. Branch-target scanning additionally
    // proves that the rejected path cannot observe its old value. No function
    // name, ROM offset, linker label, or hard-coded instruction address
    // participates in matching.
    static const std::regex stage_r1_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r1,[\t ]+#0$)");
    static const std::regex stacked_argument_pattern(
        R"(^ldr[\t ]+r1,[\t ]+\[sp,[\t ]+#(0x)?[0-9a-fA-F]+\]$)");
    static const std::regex save_r0_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r0,[\t ]+#0$)");
    static const std::regex move_staged_r1_pattern(
        R"(^mov[\t ]+(r(?:8|9|1[0-2])|ip|sl|fp),[\t ]+(r[4-7])$)");
    static const std::regex save_r2_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r2,[\t ]+#0$)");
    static const std::regex save_r3_pattern(
        R"(^add[\t ]+(r[4-7]),[\t ]+r3,[\t ]+#0$)");
    static const std::regex scratch_pattern(
        R"(^add[\t ]+r0,[\t ]+sp,[\t ]+#(?:0x)?[0-9a-fA-F]+$)");
    static const std::regex call_pattern(
        R"(^bl[\t ]+[^ \t]+(?:[\t ]+@.*)?$)");
    static const std::regex save_result_pattern(
        R"(^mov[\t ]+(?:r(?:[0-9]|1[0-2])|ip|sl|fp),[\t ]+r0$)");
    static const std::regex subtract_one_pattern(
        R"(^sub[\t ]+r0,[\t ]+r0,[\t ]+#(?:0x)?1$)");
    static const std::regex compare_one_pattern(
        R"(^cmp[\t ]+r0,[\t ]+#(?:0x)?1$)");
    static const std::regex invalid_branch_pattern(
        R"(^bhi[\t ]+(\.L[A-Za-z0-9_]+)([\t ]+@.*)?$)");
    static const std::regex overwrite_stage_pattern(
        R"(^lsr[\t ]+(r[4-7]),[\t ]+(r[4-7]),[\t ]+#(?:0x)?[0-9a-fA-F]+$)");

    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::vector<std::size_t> steps =
            FindAdjacentInstructions(lines, index, 13, true);
        if (steps.empty())
            continue;

        std::smatch stage_r1;
        std::smatch save_r0;
        std::smatch move_staged_r1;
        std::smatch save_r2;
        std::smatch save_r3;
        std::smatch invalid_branch;
        std::smatch overwrite_stage;
        const std::string stage_instruction = Trim(lines[steps[0]]);
        const std::string stacked_argument_instruction = Trim(lines[steps[1]]);
        const std::string save_r0_instruction = Trim(lines[steps[2]]);
        const std::string move_staged_r1_instruction = Trim(lines[steps[3]]);
        const std::string save_r2_instruction = Trim(lines[steps[4]]);
        const std::string save_r3_instruction = Trim(lines[steps[5]]);
        const std::string scratch_instruction = Trim(lines[steps[6]]);
        const std::string call_instruction = Trim(lines[steps[7]]);
        const std::string save_result_instruction = Trim(lines[steps[8]]);
        const std::string subtract_one_instruction = Trim(lines[steps[9]]);
        const std::string compare_one_instruction = Trim(lines[steps[10]]);
        const std::string invalid_branch_instruction = Trim(lines[steps[11]]);
        const std::string overwrite_stage_instruction = Trim(lines[steps[12]]);
        if (!std::regex_match(stage_instruction, stage_r1,
                stage_r1_pattern)
            || !std::regex_match(stacked_argument_instruction,
                stacked_argument_pattern)
            || !std::regex_match(save_r0_instruction, save_r0,
                save_r0_pattern)
            || !std::regex_match(move_staged_r1_instruction, move_staged_r1,
                move_staged_r1_pattern)
            || !std::regex_match(save_r2_instruction, save_r2,
                save_r2_pattern)
            || !std::regex_match(save_r3_instruction, save_r3,
                save_r3_pattern)
            || !std::regex_match(scratch_instruction, scratch_pattern)
            || !std::regex_match(call_instruction, call_pattern)
            || !std::regex_match(save_result_instruction, save_result_pattern)
            || !std::regex_match(subtract_one_instruction, subtract_one_pattern)
            || !std::regex_match(compare_one_instruction, compare_one_pattern)
            || !std::regex_match(invalid_branch_instruction, invalid_branch,
                invalid_branch_pattern)
            || !std::regex_match(overwrite_stage_instruction, overwrite_stage,
                overwrite_stage_pattern)) {
            continue;
        }

        const std::string stage = stage_r1[1].str();
        const std::string saved_r0 = save_r0[1].str();
        const std::string saved_r2 = save_r2[1].str();
        const std::string saved_r3 = save_r3[1].str();
        if (move_staged_r1[2].str() != stage
            || overwrite_stage[1].str() != stage
            || overwrite_stage[2].str() != saved_r2
            || stage == saved_r0 || stage == saved_r2 || stage == saved_r3
            || saved_r0 == saved_r2 || saved_r0 == saved_r3
            || saved_r2 == saved_r3
            || !BranchTargetCannotObserveRegister(lines, steps[11],
                invalid_branch[1].str(), stage)) {
            continue;
        }

        const std::string indent = InstructionIndent(lines[steps[0]]);
        const std::string stacked_argument = lines[steps[1]];
        const std::string scratch = lines[steps[6]];
        const std::string call = lines[steps[7]];
        lines[steps[0]] = indent + "add\t" + saved_r0 + ", r0, #0";
        lines[steps[1]] = indent + "mov\t" + move_staged_r1[1].str()
            + ", r1";
        lines[steps[2]] = indent + "add\t" + saved_r2 + ", r2, #0";
        lines[steps[3]] = indent + "add\t" + saved_r3 + ", r3, #0";
        lines[steps[4]] = stacked_argument;
        lines[steps[5]] = scratch;
        lines[steps[6]] = call;
        lines.erase(lines.begin() + static_cast<std::ptrdiff_t>(steps[7]));
        index = steps[6];
    }
}

void NormalizeHighRegisterTileAddressSetup(std::vector<std::string> &lines)
{
    // agbcp can fold a high-register buffer base into r0 and then copy it to
    // r1. The original scheduling makes a temporary ordinary-register base
    // copy explicit. The final r2 control setup overwrites that temporary
    // before the call, so both forms preserve every input and output.
    //
    // This is deliberately identified by register data flow only. It accepts
    // any call target and any immediate tile/scratch dimensions; it does not
    // use function names, labels, or ROM-specific addresses.
    static const std::regex shift_pattern(
        R"(^lsl[\t ]+r0,[\t ]+r1,[\t ]+#(?:0x)?[0-9a-fA-F]+$)");
    static const std::regex folded_base_pattern(
        R"(^add[\t ]+r0,[\t ]+r0,[\t ]+(r(?:8|9|1[0-2])|ip|sl|fp)$)");
    static const std::regex copy_destination_pattern(
        R"(^add[\t ]+r1,[\t ]+r0,[\t ]+#0$)");
    static const std::regex add_tile_pattern(
        R"(^add[\t ]+r1,[\t ]+r1,[\t ]+#(?:0x)?[0-9a-fA-F]+$)");
    static const std::regex scratch_pattern(
        R"(^add[\t ]+r0,[\t ]+sp,[\t ]+#(?:0x)?[0-9a-fA-F]+$)");
    static const std::regex control_pattern(
        R"(^mov[\t ]+r2,[\t ]+#(?:0x)?[0-9a-fA-F]+$)");
    static const std::regex call_pattern(
        R"(^bl[\t ]+[^ \t]+(?:[\t ]+@.*)?$)");

    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::vector<std::size_t> steps =
            FindAdjacentInstructions(lines, index, 7, true);
        std::smatch folded_base;
        const std::string folded_base_instruction = steps.empty()
            ? "" : Trim(lines[steps[1]]);
        if (steps.empty()
            || !std::regex_match(Trim(lines[steps[0]]), shift_pattern)
            || !std::regex_match(folded_base_instruction, folded_base,
                folded_base_pattern)
            || !std::regex_match(Trim(lines[steps[2]]), copy_destination_pattern)
            || !std::regex_match(Trim(lines[steps[3]]), add_tile_pattern)
            || !std::regex_match(Trim(lines[steps[4]]), scratch_pattern)
            || !std::regex_match(Trim(lines[steps[5]]), control_pattern)
            || !std::regex_match(Trim(lines[steps[6]]), call_pattern)) {
            continue;
        }

        const std::string indent = InstructionIndent(lines[steps[0]]);
        lines[steps[1]] = indent + "mov\tr2, " + folded_base[1].str();
        lines[steps[2]] = indent + "add\tr1, r0, r2";
        index = steps[6];
    }
}

void NormalizeCpuFastSetFillSetup(std::vector<std::string> &lines)
{
    // GCC 2.9's Thumb scheduler recognizes a filled copy count as
    // ((count << 9) >> 11).  The original compiler emitted the equivalent
    // (count >> 2) & 0x1FFFFF form and kept that mask in the unreachable
    // literal-pool slot after the full-buffer fast path.  The rewrite is
    // intentionally identified by the complete CpuFastSet sequence rather
    // than by a source function or symbol name.
    static const std::regex move_fill_pattern(R"(^mov[\t ]+r7,[\t ]+r9$)");
    static const std::regex shift_height_pattern(
        R"(^lsl[\t ]+r0,[\t ]+r0,[\t ]+#0x5$)");
    static const std::regex multiply_pattern(
        R"(^mul[\t ]+r2,[\t ]+r2,[\t ]+r0$)");
    static const std::regex store_fill_pattern(R"(^str[\t ]+r7,[\t ]+\[sp\]$)");
    static const std::regex shift_count_pattern(
        R"(^lsl[\t ]+r2,[\t ]+r2,[\t ]+#0x9$)");
    static const std::regex reduce_count_pattern(
        R"(^lsr[\t ]+r2,[\t ]+r2,[\t ]+#0xb$)");
    static const std::regex fixed_source_pattern(
        R"(^mov[\t ]+r0,[\t ]+#0x80$)");
    static const std::regex fixed_shift_pattern(
        R"(^lsl[\t ]+r0,[\t ]+r0,[\t ]+#0x11$)");
    static const std::regex combine_control_pattern(
        R"(^orr[\t ]+r2,[\t ]+r2,[\t ]+r0$)");
    static const std::regex stack_source_pattern(R"(^mov[\t ]+r0,[\t ]+sp$)");
    static const std::regex destination_pattern(R"(^mov[\t ]+r1,[\t ]+r8$)");
    static const std::regex call_pattern(R"(^bl[\t ]+CpuFastSet$)");
    static const std::regex branch_pattern(
        R"(^b[\t ]+\.L[A-Za-z0-9_]+(?:[\t ]+@.*)?$)");
    std::size_t literal_number = 0;

    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::vector<std::size_t> steps =
            FindAdjacentInstructions(lines, index, 13);
        if (steps.empty())
            continue;

        if (!std::regex_match(Trim(lines[steps[0]]), move_fill_pattern)
            || !std::regex_match(Trim(lines[steps[1]]), shift_height_pattern)
            || !std::regex_match(Trim(lines[steps[2]]), multiply_pattern)
            || !std::regex_match(Trim(lines[steps[3]]), store_fill_pattern)
            || !std::regex_match(Trim(lines[steps[4]]), shift_count_pattern)
            || !std::regex_match(Trim(lines[steps[5]]), reduce_count_pattern)
            || !std::regex_match(Trim(lines[steps[6]]), fixed_source_pattern)
            || !std::regex_match(Trim(lines[steps[7]]), fixed_shift_pattern)
            || !std::regex_match(Trim(lines[steps[8]]), combine_control_pattern)
            || !std::regex_match(Trim(lines[steps[9]]), stack_source_pattern)
            || !std::regex_match(Trim(lines[steps[10]]), destination_pattern)
            || !std::regex_match(Trim(lines[steps[11]]), call_pattern)
            || !std::regex_match(Trim(lines[steps[12]]), branch_pattern)) {
            continue;
        }

        const std::string indent = InstructionIndent(lines[steps[0]]);
        const std::string literal = ".Lfomt_cpu_fastset_mask_"
            + std::to_string(literal_number++);
        lines[steps[0]] = indent + "lsl\tr0, r0, #0x5";
        lines[steps[1]] = indent + "mul\tr2, r2, r0";
        lines[steps[2]] = indent + "mov\tr7, r9";
        lines[steps[3]] = indent + "str\tr7, [sp]";
        lines[steps[4]] = indent + "lsr\tr2, r2, #0x2";
        lines[steps[5]] = indent + "ldr\tr0, " + literal;
        lines[steps[6]] = indent + "and\tr2, r2, r0";
        lines[steps[7]] = indent + "mov\tr0, #0x80";
        lines[steps[8]] = indent + "lsl\tr0, r0, #0x11";
        lines[steps[9]] = indent + "orr\tr2, r2, r0";
        lines[steps[10]] = indent + "mov\tr0, sp";
        lines[steps[11]] = indent + "mov\tr1, r8";

        const std::size_t branch = steps[12];
        lines.insert(lines.begin() + branch, indent + "bl\tCpuFastSet");
        lines.insert(lines.begin() + branch + 2,
            { indent + ".align\t2, 0", literal + ":",
                indent + ".word\t0x1fffff" });
        index = branch + 4;
    }
}

void NormalizeCpuFastSetRowSetup(std::vector<std::string> &lines)
{
    // This is another old-agbcp scheduling difference around CpuFastSet. Both
    // normalized forms prepare distinct call registers, so the complete
    // matched sequences are register-independent and semantically identical.
    static const std::regex load_mask_pattern(
        R"(^ldr[\t ]+r4,[\t ]+\.L[A-Za-z0-9_+]+$)");
    static const std::regex copy_width_pattern(R"(^mov[\t ]+r0,[\t ]+ip$)");
    static const std::regex and_width_pattern(
        R"(^and[\t ]+r4,[\t ]+r4,[\t ]+r0$)");
    static const std::regex load_second_mask_pattern(
        R"(^ldr[\t ]+r0,[\t ]+\.L[A-Za-z0-9_+]+$)");
    static const std::regex and_second_mask_pattern(
        R"(^and[\t ]+r4,[\t ]+r4,[\t ]+r0$)");
    static const std::regex fixed_source_pattern(
        R"(^mov[\t ]+r1,[\t ]+#0x80$)");
    static const std::regex fixed_shift_pattern(
        R"(^lsl[\t ]+r1,[\t ]+r1,[\t ]+#0x11$)");
    static const std::regex fixed_store_pattern(R"(^mov[\t ]+r8,[\t ]+r1$)");

    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::vector<std::size_t> steps =
            FindAdjacentInstructions(lines, index, 8);
        if (steps.empty())
            continue;
        if (!std::regex_match(Trim(lines[steps[0]]), load_mask_pattern)
            || !std::regex_match(Trim(lines[steps[1]]), copy_width_pattern)
            || !std::regex_match(Trim(lines[steps[2]]), and_width_pattern)
            || !std::regex_match(Trim(lines[steps[3]]), load_second_mask_pattern)
            || !std::regex_match(Trim(lines[steps[4]]), and_second_mask_pattern)
            || !std::regex_match(Trim(lines[steps[5]]), fixed_source_pattern)
            || !std::regex_match(Trim(lines[steps[6]]), fixed_shift_pattern)
            || !std::regex_match(Trim(lines[steps[7]]), fixed_store_pattern)) {
            continue;
        }

        const std::string indent = InstructionIndent(lines[steps[0]]);
        lines[steps[1]] = indent + "mov\tr2, ip";
        lines[steps[2]] = indent + "and\tr4, r4, r2";
        lines[steps[5]] = indent + "mov\tr0, #0x80";
        lines[steps[6]] = indent + "lsl\tr0, r0, #0x11";
        lines[steps[7]] = indent + "mov\tr8, r0";
        index = steps[7];
    }

    static const std::regex move_fill_pattern(R"(^mov[\t ]+r0,[\t ]+r9$)");
    static const std::regex store_fill_pattern(R"(^str[\t ]+r0,[\t ]+\[sp\]$)");
    static const std::regex copy_mask_pattern(
        R"(^add[\t ]+r2,[\t ]+r4,[\t ]+#0$)");
    static const std::regex copy_fixed_pattern(R"(^mov[\t ]+r1,[\t ]+r8$)");
    static const std::regex combine_pattern(
        R"(^orr[\t ]+r2,[\t ]+r2,[\t ]+r1$)");
    static const std::regex stack_source_pattern(R"(^mov[\t ]+r0,[\t ]+sp$)");
    static const std::regex destination_pattern(
        R"(^add[\t ]+r1,[\t ]+r5,[\t ]+#0$)");
    static const std::regex call_pattern(R"(^bl[\t ]+CpuFastSet$)");

    for (std::size_t index = 0; index < lines.size(); ++index) {
        const std::vector<std::size_t> steps =
            FindAdjacentInstructions(lines, index, 8);
        if (steps.empty())
            continue;
        if (!std::regex_match(Trim(lines[steps[0]]), move_fill_pattern)
            || !std::regex_match(Trim(lines[steps[1]]), store_fill_pattern)
            || !std::regex_match(Trim(lines[steps[2]]), copy_mask_pattern)
            || !std::regex_match(Trim(lines[steps[3]]), copy_fixed_pattern)
            || !std::regex_match(Trim(lines[steps[4]]), combine_pattern)
            || !std::regex_match(Trim(lines[steps[5]]), stack_source_pattern)
            || !std::regex_match(Trim(lines[steps[6]]), destination_pattern)
            || !std::regex_match(Trim(lines[steps[7]]), call_pattern)) {
            continue;
        }

        const std::string indent = InstructionIndent(lines[steps[0]]);
        lines[steps[0]] = indent + "mov\tr1, r9";
        lines[steps[1]] = indent + "str\tr1, [sp]";
        lines[steps[2]] = indent + "mov\tr0, sp";
        lines[steps[3]] = indent + "add\tr1, r5, #0";
        lines[steps[4]] = indent + "mov\tr2, r8";
        lines[steps[5]] = indent + "orr\tr2, r2, r4";
        lines[steps[6]] = indent + "bl\tCpuFastSet";
        lines.erase(lines.begin() + steps[7]);
        index = steps[6];
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
    NormalizeStackedArgumentCalleeSavedSetup(lines);
    NormalizeDeferredCalleeSavedArgumentSetup(lines);
    NormalizeCpuFastSetFillSetup(lines);
    NormalizeCpuFastSetRowSetup(lines);
    NormalizeHighRegisterTileAddressSetup(lines);
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
    Require(IsCompilerDebugMarker(".LBB2:")
                && !IsCompilerDebugMarker(".LSM1:")
                && IsExtendedCompilerDebugMarker(".LSM1:")
                && IsExtendedCompilerDebugMarker(".LBE3:"),
        "compiler debug-marker recognition scope failed");
    const std::vector<std::string> source_map_marker_lines = SplitLines(
        "\tadd\tr4, r1, #0\n"
        ".LSM1:\n"
        "\tldr\tr1, [sp, #0xac]\n");
    Require(FindAdjacentInstructions(source_map_marker_lines, 0, 2).empty()
                && FindAdjacentInstructions(source_map_marker_lines, 0, 2, true).size()
                    == 2,
        "extended source-map marker skipping was not isolated");

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

    const std::string section_boundary_source =
        "char const gSectionBoundaryText[] = \"A\";\n"
        "char const * const gSectionBoundaryPointer = gSectionBoundaryText;\n";
    const std::string section_boundary_assembly =
        "\t.section .rodata.named,\"a\",%progbits\n"
        "gSectionBoundaryText:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.globl\tgSectionBoundaryPointer\n"
        "\t.section .rodata\n"
        "\t.align\t2, 0\n"
        ".LC0:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.section .rodata.pointers,\"a\",%progbits\n"
        "\t.align\t2, 0\n"
        "gSectionBoundaryPointer:\n"
        "\t.word\t.LC0\n";
    const std::string section_boundary_output = PreprocessAssembly(
        section_boundary_source, section_boundary_assembly);
    Require(section_boundary_output.find(".LC0:") == std::string::npos
            && section_boundary_output.find("\t.word\tgSectionBoundaryText")
                != std::string::npos,
        "section-bound compiler string relocation was not restored");

    const std::string expression_source =
        "char const gFunctionText[] = \"A\";\n"
        "char const * FunctionText() { return gFunctionText; }\n";
    const std::string expression_assembly =
        "\t.section .rodata.named,\"a\",%progbits\n"
        "gFunctionText:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.section .rodata\n"
        "\t.align\t2, 0\n"
        ".LC0:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.text\n"
        "FunctionText:\n"
        "\t.word\t.LC0\n";
    const std::string expression_output = PreprocessAssembly(
        expression_source, expression_assembly);
    Require(expression_output.find(".LC0:") == std::string::npos
            && expression_output.find("\t.word\tgFunctionText")
                != std::string::npos,
        "function-expression compiler string relocation was not restored");

    const std::string stacked_setup_assembly =
        "\t.text\n"
        "generic_stacked_dispatch:\n"
        "\tadd\tr5, r1, #0\n"
        "\tldr\tr1, [sp, #0x30]\n"
        "\tadd\tr4, r0, #0\n"
        "\tmov\tsl, r5\n"
        "\tadd\tr5, r2, #0\n"
        "\tadd\tr6, r3, #0\n"
        "\tadd\tr0, sp, #0xc\n"
        "\tbl\tany_callee\n"
        "nonmatching_stacked_dispatch:\n"
        "\tadd\tr5, r1, #0\n"
        "\tldr\tr1, [sp, #0x30]\n"
        "\tadd\tr4, r0, #0\n"
        "\tmov\tsl, r5\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0xc\n"
        "\tbl\tany_callee\n";
    const std::string normalized_stacked_setup =
        PreprocessAssembly("", stacked_setup_assembly);
    Require(normalized_stacked_setup.find("\tadd\tr4, r0, #0\n"
                                        "\tmov\tsl, r1\n"
                                        "\tadd\tr5, r2, #0\n"
                                        "\tadd\tr6, r3, #0\n"
                                        "\tldr\tr1, [sp, #0x30]\n"
                                        "\tadd\tr0, sp, #0xc\n"
                                        "\tbl\tany_callee\n")
            != std::string::npos,
        "generic stacked-argument setup was not normalized");
    Require(normalized_stacked_setup.find("nonmatching_stacked_dispatch:\n"
                                        "\tadd\tr5, r1, #0\n"
                                        "\tldr\tr1, [sp, #0x30]\n"
                                        "\tadd\tr4, r0, #0\n"
                                        "\tmov\tsl, r5\n"
                                        "\tadd\tr6, r2, #0\n")
            != std::string::npos,
        "non-equivalent stacked-argument setup was changed");

    const std::string trampoline_assembly =
        "\t.text\n"
        "literal_dispatch:\n"
        "\tldr\tr2, .Lliteral_dispatch_target\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\t_call_via_r2\n"
        "unrelated_call:\n"
        "\tldr\tr2, [r0]\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\t_call_via_r2\n";
    const std::string normalized = PreprocessAssembly("", trampoline_assembly);
    Require(normalized.find("\tadd\tr1, r5, #0\n"
                            "\tldr\tr2, .Lliteral_dispatch_target\n"
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

    const std::string cpu_fast_set_assembly =
        "\t.text\n"
        "full_fill:\n"
        "\tmov\tr7, r9\n"
        "\tlsl\tr0, r0, #0x5\n"
        "\tmul\tr2, r2, r0\n"
        "\tstr\tr7, [sp]\n"
        "\tlsl\tr2, r2, #0x9\n"
        "\tlsr\tr2, r2, #0xb\n"
        "\tmov\tr0, #0x80\n"
        "\tlsl\tr0, r0, #0x11\n"
        "\torr\tr2, r2, r0\n"
        "\tmov\tr0, sp\n"
        "\tmov\tr1, r8\n"
        "\tbl\tCpuFastSet\n"
        "\tb\t.Ldone\n"
        ".Lpartial:\n"
        "\tldr\tr4, .Lmask\n"
        "\tmov\tr0, ip\n"
        "\tand\tr4, r4, r0\n"
        "\tldr\tr0, .Lmask+0x4\n"
        "\tand\tr4, r4, r0\n"
        "\tmov\tr1, #0x80\n"
        "\tlsl\tr1, r1, #0x11\n"
        "\tmov\tr8, r1\n"
        ".Lrow:\n"
        "\tmov\tr0, r9\n"
        "\tstr\tr0, [sp]\n"
        "\tadd\tr2, r4, #0\n"
        "\tmov\tr1, r8\n"
        "\torr\tr2, r2, r1\n"
        "\tmov\tr0, sp\n"
        "\tadd\tr1, r5, #0\n"
        "\tbl\tCpuFastSet\n"
        ".Ldone:\n"
        "\tbx\tlr\n"
        ".Lmask:\n"
        "\t.word\t0x3ffffff8\n"
        "\t.word\t0x1fffff\n";
    const std::string normalized_cpu_fast_set =
        PreprocessAssembly("", cpu_fast_set_assembly);
    Require(normalized_cpu_fast_set.find("\tlsr\tr2, r2, #0x2\n"
                                         "\tldr\tr0, .Lfomt_cpu_fastset_mask_0\n"
                                         "\tand\tr2, r2, r0\n") != std::string::npos,
        "full CpuFastSet count was not normalized");
    Require(normalized_cpu_fast_set.find(".Lfomt_cpu_fastset_mask_0:\n"
                                         "\t.word\t0x1fffff\n") != std::string::npos,
        "full CpuFastSet mask literal was not emitted");
    Require(normalized_cpu_fast_set.find("\tmov\tr2, ip\n"
                                         "\tand\tr4, r4, r2\n"
                                         "\tldr\tr0, .Lmask+0x4\n") != std::string::npos,
        "row CpuFastSet count setup was not normalized");
    Require(normalized_cpu_fast_set.find("\tmov\tr1, r9\n"
                                         "\tstr\tr1, [sp]\n"
                                         "\tmov\tr0, sp\n"
                                         "\tadd\tr1, r5, #0\n"
                                         "\tmov\tr2, r8\n"
                                         "\torr\tr2, r2, r4\n"
                                         "\tbl\tCpuFastSet\n") != std::string::npos,
        "row CpuFastSet arguments were not normalized");
    Require(normalized_cpu_fast_set.find("\tlsl\tr2, r2, #0x9\n")
                == std::string::npos,
        "legacy full CpuFastSet count sequence was retained");

    const std::string fixed_register_assembly =
        "\t.text\n"
        "generic_wrapper:\n"
        "\tadd\tr4, r1, #0\n"
        "\tldr\tr1, [sp, #0xac]\n"
        "\tadd\tr5, r0, #0\n"
        "\tmov\tr9, r4\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0x4\n"
        "\tbl\tGenericCallee\n"
        "\tmov\tsl, r0\n"
        "\tsub\tr0, r0, #0x1\n"
        "\tcmp\tr0, #0x1\n"
        "\tbhi\t.Lgeneric_invalid\n"
        "\tlsr\tr4, r6, #0x3\n"
        "unrelated_wrapper:\n"
        "\tadd\tr4, r1, #0\n"
        "\tldr\tr1, [sp, #0xac]\n"
        "\tadd\tr5, r0, #0\n"
        "\tmov\tr9, r4\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0x4\n"
        "\tbl\tUnprovenCallee\n"
        "\tmov\tsl, r0\n"
        "\tsub\tr0, r0, #0x1\n"
        "\tcmp\tr0, #0x1\n"
        "\tbhi\t.Lunrelated_invalid\n"
        "\tlsr\tr5, r6, #0x3\n"
        "tile_address:\n"
        "\tlsl\tr0, r1, #0x5\n"
        "\tadd\tr0, r0, r9\n"
        "\tadd\tr1, r0, #0\n"
        "\tadd\tr1, r1, #0x20\n"
        "\tadd\tr0, sp, #0x64\n"
        "\tmov\tr2, #0x8\n"
        "\tbl\tGenericCopy\n"
        "unrelated_tile_address:\n"
        "\tlsl\tr0, r1, #0x5\n"
        "\tadd\tr0, r0, r8\n"
        "\tadd\tr1, r0, #0\n"
        "\tadd\tr1, r1, #0x20\n"
        "\tadd\tr0, sp, #0x64\n"
        "\tmov\tr2, #0x8\n"
        "\tbl\tOtherCopy\n"
        "unsafe_wrapper:\n"
        "\tadd\tr4, r1, #0\n"
        "\tldr\tr1, [sp, #0xac]\n"
        "\tadd\tr5, r0, #0\n"
        "\tmov\tr9, r4\n"
        "\tadd\tr6, r2, #0\n"
        "\tadd\tr7, r3, #0\n"
        "\tadd\tr0, sp, #0x4\n"
        "\tbl\tUnsafeCallee\n"
        "\tmov\tsl, r0\n"
        "\tsub\tr0, r0, #0x1\n"
        "\tcmp\tr0, #0x1\n"
        "\tbhi\t.Lunsafe_invalid\n"
        "\tlsr\tr4, r6, #0x3\n"
        ".Lgeneric_invalid:\n"
        "\tmov\tr0, #0\n"
        "\tpop\t{r4, r5, r6, r7, pc}\n"
        ".Lunrelated_invalid:\n"
        "\tmov\tr0, #0\n"
        "\tpop\t{r4, r5, r6, r7, pc}\n"
        ".Lunsafe_invalid:\n"
        "\tadd\tr0, r4, #0\n"
        "\tbx\tlr\n";
    const std::vector<std::string> fixed_register_lines =
        SplitLines(fixed_register_assembly);
    Require(FindAdjacentInstructions(fixed_register_lines, 2, 13).size() == 13,
        "compiler debug markers interrupted instruction matching");
    Require(std::regex_match("add r4, r1, #0",
                std::regex(R"(^add[\t ]+r4,[\t ]+r1,[\t ]+#0$)"))
            && std::regex_match("ldr r1, [sp, #0xac]",
                std::regex(R"(^ldr[\t ]+r1,[\t ]+\[sp,[\t ]+#(0x)?[0-9a-fA-F]+\]$)"))
            && std::regex_match("bhi .Lgeneric_invalid",
                std::regex(R"(^bhi[\t ]+\.L[A-Za-z0-9_]+([\t ]+@.*)?$)")),
        "generic argument-preservation patterns failed to match");
    const std::string normalized_fixed_registers =
        PreprocessAssembly("", fixed_register_assembly);
    Require(normalized_fixed_registers.find("\tadd\tr5, r0, #0\n"
                                            "\tmov\tr9, r1\n"
                                            "\tadd\tr6, r2, #0\n"
                                            "\tadd\tr7, r3, #0\n"
                                            "\tldr\tr1, [sp, #0xac]\n"
                                            "\tadd\tr0, sp, #0x4\n"
                                            "\tbl\tGenericCallee\n")
                != std::string::npos,
        "generic deferred argument setup was not normalized");
    Require(normalized_fixed_registers.find("unrelated_wrapper:\n"
                                            "\tadd\tr4, r1, #0\n"
                                            "\tldr\tr1, [sp, #0xac]\n")
                != std::string::npos,
        "unproven r4 staging sequence was changed");
    Require(normalized_fixed_registers.find("tile_address:\n"
                                            "\tlsl\tr0, r1, #0x5\n"
                                            "\tmov\tr2, r9\n"
                                            "\tadd\tr1, r0, r2\n"
                                            "\tadd\tr1, r1, #0x20\n")
                != std::string::npos,
        "high-register tile address setup was not normalized");
    Require(normalized_fixed_registers.find("unrelated_tile_address:\n"
                                            "\tlsl\tr0, r1, #0x5\n"
                                            "\tmov\tr2, r8\n"
                                            "\tadd\tr1, r0, r2\n")
                != std::string::npos,
        "generic high-register address setup was not normalized");
    Require(normalized_fixed_registers.find("unsafe_wrapper:\n"
                                            "\tadd\tr4, r1, #0\n"
                                            "\tldr\tr1, [sp, #0xac]\n")
                != std::string::npos,
        "branch-visible staging value was changed");
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
