#include <algorithm>
#include <cctype>
#include <cstdint>
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

using Bytes = std::vector<std::uint8_t>;

std::string Trim(const std::string &value)
{
    const auto first = value.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";

    const auto last = value.find_last_not_of(" \t");
    return value.substr(first, last - first + 1);
}

bool IsHexDigit(char value)
{
    return std::isxdigit(static_cast<unsigned char>(value)) != 0;
}

std::uint8_t ParseHexByte(char high, char low)
{
    const std::string text{high, low};
    return static_cast<std::uint8_t>(std::stoul(text, nullptr, 16));
}

std::string HexByte(std::uint8_t value)
{
    static constexpr char kDigits[] = "0123456789ABCDEF";
    std::string result = "00";
    result[0] = kDigits[value >> 4];
    result[1] = kDigits[value & 0x0F];
    return result;
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

Bytes ReadBinaryFile(const std::filesystem::path &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input)
        throw std::runtime_error("cannot read '" + path.string() + "'");

    return Bytes(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
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

void WriteBinaryFile(const std::filesystem::path &path, const Bytes &contents)
{
    EnsureParentDirectory(path);
    std::ofstream output(path, std::ios::binary | std::ios::trunc);
    if (!output)
        throw std::runtime_error("cannot write '" + path.string() + "'");
    output.write(reinterpret_cast<const char *>(contents.data()), static_cast<std::streamsize>(contents.size()));
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

std::map<std::string, std::string> FindConstTextReferenceInitializers(
    const std::string &source)
{
    // These remain ordinary C++ declarations.  agbcp 2.9 can turn their
    // target into a duplicate .LC string, which is repaired after compilation.
    static const std::regex pattern(
        R"(char\s+const\s*\*\s*const\s+([A-Za-z_][A-Za-z0-9_]*)\s*=\s*([A-Za-z_][A-Za-z0-9_]*)\s*;)");

    std::map<std::string, std::string> result;
    for (std::sregex_iterator match(source.begin(), source.end(), pattern), end;
         match != end; ++match) {
        result.emplace((*match)[1].str(), (*match)[2].str());
    }
    return result;
}

std::string FixupSameUnitTextReferences(const std::string &source,
    const std::string &assembly)
{
    const std::map<std::string, std::string> references =
        FindConstTextReferenceInitializers(source);
    if (references.empty())
        return assembly;

    std::vector<std::string> lines = SplitLines(assembly);
    std::vector<std::pair<std::size_t, std::size_t>> removals;
    std::set<std::string> removed_local_constants;

    for (const auto &[reference_name, target_name] : references) {
        const std::size_t reference_label = FindAssemblyLabel(lines, reference_name);
        if (reference_label == std::string::npos)
            continue;

        std::size_t word_index = reference_label + 1;
        while (word_index < lines.size() && Trim(lines[word_index]).empty())
            ++word_index;
        if (word_index == lines.size())
            throw std::runtime_error("missing initializer for '" + reference_name + "'");

        const std::string word = Trim(lines[word_index]);
        static constexpr std::string_view kWord = ".word";
        if (word.rfind(kWord, 0) != 0)
            throw std::runtime_error("expected .word initializer for '" + reference_name + "'");
        const std::string local_constant = Trim(word.substr(kWord.size()));
        if (local_constant.rfind(".LC", 0) != 0)
            continue;
        if (!removed_local_constants.insert(local_constant).second)
            throw std::runtime_error("duplicate compiler constant '" + local_constant + "'");

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

        std::size_t local_end = local_label + 1 + local_payload.size();
        if (local_end == lines.size() || !IsAssemblyAlign(lines[local_end])) {
            throw std::runtime_error("unexpected compiler-constant layout for '"
                + reference_name + "'");
        }

        const std::size_t indent_end = lines[word_index].find_first_not_of(" \t");
        const std::string indent = indent_end == std::string::npos
            ? "" : lines[word_index].substr(0, indent_end);
        lines[word_index] = indent + ".word\t" + target_name;
        removals.emplace_back(local_label, local_end);
    }

    std::sort(removals.rbegin(), removals.rend());
    for (const auto &[begin, end] : removals)
        lines.erase(lines.begin() + static_cast<std::ptrdiff_t>(begin),
            lines.begin() + static_cast<std::ptrdiff_t>(end));
    return JoinLines(lines);
}

class Charmap {
public:
    static Charmap Parse(const std::string &source)
    {
        Charmap result;
        std::istringstream lines(source);
        std::string line;
        std::size_t line_number = 0;

        while (std::getline(lines, line)) {
            ++line_number;
            if (!line.empty() && line.back() == '\r')
                line.pop_back();

            const std::string trimmed = Trim(line);
            if (trimmed.empty() || trimmed.front() == '#')
                continue;

            const auto equals = line.find('=');
            if (equals == std::string::npos)
                throw std::runtime_error(LineError(line_number, "expected HEX=TEXT"));

            const std::string hex = Trim(line.substr(0, equals));
            const std::string text = line.substr(equals + 1);
            if (hex.empty() || hex.size() % 2 != 0
                || !std::all_of(hex.begin(), hex.end(), IsHexDigit)) {
                throw std::runtime_error(LineError(line_number, "invalid hexadecimal byte sequence '" + hex + "'"));
            }

            // Mary-style tables use an empty right-hand side for unassigned slots.
            if (text.empty())
                continue;

            Bytes bytes;
            bytes.reserve(hex.size() / 2);
            for (std::size_t at = 0; at < hex.size(); at += 2)
                bytes.push_back(ParseHexByte(hex[at], hex[at + 1]));

            if (std::find(bytes.begin(), bytes.end(), 0) != bytes.end()) {
                throw std::runtime_error(LineError(
                    line_number, "00 is reserved for the FOMT string terminator"));
            }
            if (result.decode_.count(bytes) != 0)
                throw std::runtime_error(LineError(line_number, "byte sequence '" + hex + "' is defined more than once"));

            result.max_bytes_ = std::max(result.max_bytes_, bytes.size());
            result.max_text_bytes_ = std::max(result.max_text_bytes_, text.size());
            if (bytes.size() > 1) {
                auto &lengths = result.multibyte_lengths_[bytes.front()];
                if (std::find(lengths.begin(), lengths.end(), bytes.size()) == lengths.end()) {
                    lengths.push_back(bytes.size());
                    std::sort(lengths.begin(), lengths.end());
                }
            }

            if (result.encode_.count(text) != 0)
                result.ambiguous_text_.insert(text);
            else
                result.encode_.emplace(text, bytes);
            result.decode_.emplace(std::move(bytes), text);
        }

        if (result.decode_.empty())
            throw std::runtime_error("charmap does not contain any assigned entries");
        return result;
    }

    Bytes EncodeText(const std::string &source) const
    {
        Bytes output;
        std::size_t at = 0;
        while (at < source.size()) {
            if (source.compare(at, 2, "\\x") == 0) {
                if (at + 4 > source.size() || !IsHexDigit(source[at + 2]) || !IsHexDigit(source[at + 3])) {
                    throw std::runtime_error("malformed raw byte escape at byte " + std::to_string(at) + ": expected \\xNN");
                }
                const std::uint8_t byte = ParseHexByte(source[at + 2], source[at + 3]);
                output.push_back(byte);
                at += 4;
                continue;
            }

            const std::vector<std::uint8_t> *match = nullptr;
            std::size_t match_length = 0;
            for (const auto &[text, bytes] : encode_) {
                if (text.size() <= match_length || text.size() > source.size() - at)
                    continue;
                if (source.compare(at, text.size(), text) == 0) {
                    match = &bytes;
                    match_length = text.size();
                }
            }

            if (match == nullptr) {
                const std::size_t snippet_length = std::min<std::size_t>(4, source.size() - at);
                throw std::runtime_error(
                    "source text contains an unmapped sequence at byte " + std::to_string(at)
                    + ": '" + source.substr(at, snippet_length) + "'");
            }
            output.insert(output.end(), match->begin(), match->end());
            at += match_length;
        }
        return output;
    }

    std::string DecodeText(const Bytes &source) const
    {
        std::string output;
        std::size_t at = 0;
        while (at < source.size()) {
            const std::string *match = nullptr;
            std::size_t match_length = 0;
            const std::size_t maximum = std::min(max_bytes_, source.size() - at);
            for (std::size_t count = maximum; count != 0; --count) {
                const Bytes candidate(source.begin() + static_cast<std::ptrdiff_t>(at),
                    source.begin() + static_cast<std::ptrdiff_t>(at + count));
                const auto found = decode_.find(candidate);
                if (found != decode_.end() && ambiguous_text_.count(found->second) == 0) {
                    match = &found->second;
                    match_length = count;
                    break;
                }
            }

            if (match != nullptr) {
                if (*match == "\\")
                    output += "\\x" + HexByte(source[at]);
                else
                    output += *match;
                at += match_length;
                continue;
            }

            const std::size_t raw_length = RawSequenceLength(source, at);
            for (std::size_t offset = 0; offset < raw_length; ++offset)
                output += "\\x" + HexByte(source[at + offset]);
            at += raw_length;
        }
        return output;
    }

    std::size_t EntryCount() const
    {
        return decode_.size();
    }

private:
    static std::string LineError(std::size_t number, const std::string &message)
    {
        return "charmap line " + std::to_string(number) + ": " + message;
    }

    std::size_t RawSequenceLength(const Bytes &source, std::size_t at) const
    {
        const std::size_t maximum = std::min(max_bytes_, source.size() - at);
        for (std::size_t count = maximum; count > 1; --count) {
            const Bytes candidate(source.begin() + static_cast<std::ptrdiff_t>(at),
                source.begin() + static_cast<std::ptrdiff_t>(at + count));
            if (decode_.count(candidate) != 0)
                return count;
        }

        const auto lengths = multibyte_lengths_.find(source[at]);
        if (lengths != multibyte_lengths_.end()) {
            for (const std::size_t length : lengths->second) {
                if (length <= source.size() - at)
                    return length;
            }
        }
        return 1;
    }

    std::map<Bytes, std::string> decode_;
    std::map<std::string, Bytes> encode_;
    std::set<std::string> ambiguous_text_;
    std::map<std::uint8_t, std::vector<std::size_t>> multibyte_lengths_;
    std::size_t max_bytes_ = 0;
    std::size_t max_text_bytes_ = 0;
};

bool IsValidLabel(const std::string &label)
{
    if (label.empty())
        return false;
    const auto first = static_cast<unsigned char>(label.front());
    if (!(std::isalpha(first) || label.front() == '_' || label.front() == '.'))
        return false;

    return std::all_of(label.begin() + 1, label.end(), [](char value) {
        const auto character = static_cast<unsigned char>(value);
        return std::isalnum(character) || value == '_' || value == '.';
    });
}

std::string ParseStringLiteral(const std::string &source, std::size_t line_number)
{
    const std::string literal = Trim(source);
    if (literal.size() < 2 || literal.front() != '"' || literal.back() != '"') {
        throw std::runtime_error("line " + std::to_string(line_number) + ": expected one quoted C++ string literal");
    }

    std::string output;
    for (std::size_t at = 1; at + 1 < literal.size(); ++at) {
        const char character = literal[at];
        if (character != '\\') {
            output.push_back(character);
            continue;
        }

        if (++at + 1 >= literal.size()) {
            throw std::runtime_error("line " + std::to_string(line_number) + ": trailing backslash in C++ string literal");
        }
        const char escaped = literal[at];
        if (escaped == '"' || escaped == '\\')
            output.push_back(escaped);
        else {
            // Controls such as \n and \p are intentionally resolved by the
            // selected charmap, rather than being hard-coded in this tool.
            output.push_back('\\');
            output.push_back(escaped);
        }
    }
    return output;
}

void EmitCppString(std::ostringstream &output, const std::string &declarator, const Bytes &bytes,
    const std::string &storage_class = "")
{
    output << storage_class << "char const " << declarator << " =\n";
    if (bytes.empty()) {
        output << "    \"\";\n\n";
        return;
    }

    for (std::size_t at = 0; at < bytes.size(); at += 16) {
        output << "    \"";
        const std::size_t end = std::min(at + 16, bytes.size());
        for (std::size_t index = at; index < end; ++index)
            output << "\\x" << HexByte(bytes[index]);
        output << '"';
        output << (end == bytes.size() ? ";\n\n" : "\n");
    }
}

void EmitGuideCppString(std::ostringstream &output, const std::string &label,
    const std::string &section, const Bytes &bytes)
{
    // agbcp treats a const char array as its initializer literal when that
    // array decays inside a later pointer table.  A first-member wrapper
    // preserves the emitted symbol address while keeping pointer tables tied
    // to the explicitly sectioned object rather than its default .rodata copy.
    output << "extern ReferenceGuideTextStorage<" << (bytes.size() + 1) << "> const "
           << label << " SECTION(\"" << section << "\") =\n{\n";
    if (bytes.empty()) {
        output << "    \"\"\n};\n\n";
        return;
    }

    for (std::size_t at = 0; at < bytes.size(); at += 16) {
        output << "    \"";
        const std::size_t end = std::min(at + 16, bytes.size());
        for (std::size_t index = at; index < end; ++index)
            output << "\\x" << HexByte(bytes[index]);
        output << '"' << (end == bytes.size() ? "\n};\n\n" : "\n");
    }
}

void EmitStaffCreditsCppString(std::ostringstream &output, const std::string &label,
    std::size_t storage_size, const Bytes &bytes)
{
    if (bytes.size() + 1 > storage_size) {
        throw std::runtime_error("staff-credit text '" + label
            + "' exceeds its original storage field");
    }

    // The maintained source intentionally has no byte capacities.  The
    // original field size is recovered from the baseline pointer table, then
    // emitted here so shorter edited strings retain the original zero-fill.
    output << "extern StaffCreditsTextStorage<" << storage_size << "> const " << label
           << " SECTION(\".rodata.staff_credits\") ALIGN(1) =\n{\n";
    if (bytes.empty()) {
        output << "    \"\"\n};\n\n";
        return;
    }

    for (std::size_t at = 0; at < bytes.size(); at += 16) {
        output << "    \"";
        const std::size_t end = std::min(at + 16, bytes.size());
        for (std::size_t index = at; index < end; ++index)
            output << "\\x" << HexByte(bytes[index]);
        output << '"' << (end == bytes.size() ? "\n};\n\n" : "\n");
    }
}

void EmitCppStringRows(std::ostringstream &output, const std::string &declarator,
    const std::vector<Bytes> &rows)
{
    output << "char const " << declarator << " =\n{\n";
    for (std::size_t row = 0; row < rows.size(); ++row) {
        output << "    \"";
        for (const std::uint8_t byte : rows[row])
            output << "\\x" << HexByte(byte);
        output << '"' << (row + 1 == rows.size() ? "\n" : ",\n");
    }
    output << "};\n\n";
}

std::size_t SourceLineNumber(const std::string &source, std::size_t at)
{
    return 1 + static_cast<std::size_t>(std::count(source.begin(), source.begin() + at, '\n'));
}

std::size_t FindCppQuotedLiteralEnd(const std::string &source, std::size_t begin,
    std::size_t line_number)
{
    if (begin >= source.size() || source[begin] != '"') {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": expected a quoted C++ string literal");
    }

    for (std::size_t at = begin + 1; at < source.size(); ++at) {
        if (source[at] == '\\') {
            if (++at == source.size()) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": trailing backslash in C++ string literal");
            }
            continue;
        }
        if (source[at] == '"')
            return at + 1;
    }

    throw std::runtime_error("line " + std::to_string(line_number)
        + ": unterminated C++ string literal");
}

std::size_t FindCppCharacterLiteralEnd(const std::string &source, std::size_t begin,
    std::size_t line_number)
{
    if (begin >= source.size() || source[begin] != '\'') {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": expected a C++ character literal");
    }

    for (std::size_t at = begin + 1; at < source.size(); ++at) {
        if (source[at] == '\\') {
            if (++at == source.size()) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": trailing backslash in C++ character literal");
            }
            continue;
        }
        if (source[at] == '\'')
            return at + 1;
    }

    throw std::runtime_error("line " + std::to_string(line_number)
        + ": unterminated C++ character literal");
}

void ValidatePageBreakLayout(const std::string &source)
{
    bool previous_literal_was_page_break = false;
    std::size_t previous_page_break_line = 0;
    for (std::size_t at = 0; at < source.size();) {
        if (source.compare(at, 2, "//") == 0) {
            const std::size_t newline = source.find('\n', at + 2);
            at = newline == std::string::npos ? source.size() : newline + 1;
            continue;
        }
        if (source.compare(at, 2, "/*") == 0) {
            const std::size_t close = source.find("*/", at + 2);
            if (close == std::string::npos) {
                throw std::runtime_error("line " + std::to_string(SourceLineNumber(source, at))
                    + ": unterminated C++ block comment");
            }
            at = close + 2;
            continue;
        }
        if (source[at] == '\'') {
            at = FindCppCharacterLiteralEnd(source, at, SourceLineNumber(source, at));
            continue;
        }
        if (source[at] != '"') {
            ++at;
            continue;
        }

        const std::size_t line_number = SourceLineNumber(source, at);
        const std::size_t end = FindCppQuotedLiteralEnd(source, at, line_number);
        const std::string text = ParseStringLiteral(source.substr(at, end - at), line_number);
        const std::size_t page_break = text.find("\\p");

        if (page_break != std::string::npos && page_break + 2 != text.size()) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": \\p must end its quoted string literal");
        }
        if (previous_literal_was_page_break && text.empty()) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": an empty string literal may not follow a \\p page break");
        }
        if (previous_literal_was_page_break && line_number == previous_page_break_line) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": text after \\p must start on the next source line");
        }
        previous_literal_was_page_break = page_break != std::string::npos;
        previous_page_break_line = line_number;
        at = end;
    }
}

std::string EmitInlineCppStringLiteral(const Bytes &bytes)
{
    std::ostringstream output;
    if (bytes.empty())
        return "\"\"";

    for (std::size_t at = 0; at < bytes.size(); at += 16) {
        output << '"';
        const std::size_t end = std::min(at + 16, bytes.size());
        for (std::size_t index = at; index < end; ++index)
            output << "\\x" << HexByte(bytes[index]);
        output << '"';
    }
    return output.str();
}

bool HasStructuredTextInitializer(const std::string &source)
{
    std::istringstream lines(source);
    std::string line;
    while (std::getline(lines, line)) {
        const std::string trimmed = Trim(line);
        if (trimmed.empty() || trimmed.rfind("//", 0) == 0 || trimmed[0] == '#')
            continue;
        if (trimmed.rfind("char const ", 0) == 0
            || trimmed.rfind("extern char const ", 0) == 0) {
            continue;
        }
        const std::size_t equals = trimmed.find('=');
        if (equals != std::string::npos && trimmed.find('{', equals + 1) != std::string::npos)
            return true;
    }
    return false;
}

std::string CompileCppStructuredTextSource(const std::string &source, const Charmap &charmap)
{
    std::ostringstream output;
    output << "// Generated by fomt-text.  Do not edit.\n\n";

    std::size_t brace_depth = 0;
    bool direct_text_declaration = false;
    bool direct_text_initializer = false;
    bool encoded_text = false;
    for (std::size_t at = 0; at < source.size();) {
        const std::size_t line_begin = source.rfind('\n', at);
        const std::size_t first_column = line_begin == std::string::npos ? 0 : line_begin + 1;
        const bool after_line_whitespace = std::all_of(
            source.begin() + static_cast<std::ptrdiff_t>(first_column),
            source.begin() + static_cast<std::ptrdiff_t>(at), [](char value) {
                return std::isspace(static_cast<unsigned char>(value)) != 0;
            });
        if (after_line_whitespace && source.compare(at, sizeof("char const ") - 1, "char const ") == 0)
            direct_text_declaration = true;
        if (source[at] == '#'
            && after_line_whitespace) {
            const std::size_t newline = source.find('\n', at + 1);
            const std::size_t end = newline == std::string::npos ? source.size() : newline + 1;
            output << source.substr(at, end - at);
            at = end;
            continue;
        }
        if (source.compare(at, 2, "//") == 0) {
            const std::size_t newline = source.find('\n', at + 2);
            const std::size_t end = newline == std::string::npos ? source.size() : newline + 1;
            output << source.substr(at, end - at);
            at = end;
            continue;
        }
        if (source.compare(at, 2, "/*") == 0) {
            const std::size_t close = source.find("*/", at + 2);
            if (close == std::string::npos) {
                throw std::runtime_error("line " + std::to_string(SourceLineNumber(source, at))
                    + ": unterminated C++ block comment");
            }
            const std::size_t end = close + 2;
            output << source.substr(at, end - at);
            at = end;
            continue;
        }
        if (source[at] == '"') {
            const std::size_t line_number = SourceLineNumber(source, at);
            const std::size_t end = FindCppQuotedLiteralEnd(source, at, line_number);
            if (brace_depth == 0 && !direct_text_initializer) {
                output << source.substr(at, end - at);
            } else {
                Bytes bytes;
                try {
                    bytes = charmap.EncodeText(ParseStringLiteral(source.substr(at, end - at), line_number));
                } catch (const std::runtime_error &error) {
                    throw std::runtime_error("structured text at line "
                        + std::to_string(line_number) + ": " + error.what());
                }
                output << EmitInlineCppStringLiteral(bytes);
                encoded_text = true;
            }
            at = end;
            continue;
        }
        if (source[at] == '\'') {
            const std::size_t end = FindCppCharacterLiteralEnd(source, at, SourceLineNumber(source, at));
            output << source.substr(at, end - at);
            at = end;
            continue;
        }
        if (source[at] == '{') {
            ++brace_depth;
        } else if (source[at] == '}') {
            if (brace_depth == 0) {
                throw std::runtime_error("line " + std::to_string(SourceLineNumber(source, at))
                    + ": unmatched closing brace in structured text source");
            }
            --brace_depth;
        } else if (source[at] == '=' && direct_text_declaration) {
            direct_text_initializer = true;
        } else if (source[at] == ';' && direct_text_declaration) {
            direct_text_declaration = false;
            direct_text_initializer = false;
        }
        output << source[at++];
    }

    if (brace_depth != 0)
        throw std::runtime_error("structured text source has an unmatched opening brace");
    if (!encoded_text)
        throw std::runtime_error("structured text source has no string literal inside an initializer");
    return output.str();
}

std::size_t ParsePositiveDecimal(const std::string &source, std::size_t line_number,
    const std::string &description)
{
    if (source.empty() || !std::all_of(source.begin(), source.end(), [](char value) {
            return std::isdigit(static_cast<unsigned char>(value)) != 0;
        })) {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": " + description + " must be a positive decimal integer");
    }

    const std::size_t value = static_cast<std::size_t>(std::stoul(source));
    if (value == 0) {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": " + description + " must be greater than zero");
    }
    return value;
}

struct TextDeclarator {
    std::string label;
    std::string emitted;
    bool is_fixed_width = false;
    std::size_t fixed_width = 0;
    bool is_fixed_rows = false;
    std::size_t row_count = 0;
    std::size_t row_width = 0;
};

TextDeclarator ParseTextDeclarator(const std::string &source, std::size_t line_number)
{
    const std::size_t first_open = source.find('[');
    if (first_open == std::string::npos) {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": text declaration must use a char array");
    }

    TextDeclarator result;
    result.label = Trim(source.substr(0, first_open));
    if (!IsValidLabel(result.label)) {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": invalid text label '" + result.label + "'");
    }

    const std::size_t first_close = source.find(']', first_open + 1);
    if (first_close == std::string::npos) {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": unterminated first array dimension");
    }

    const std::string first_dimension = Trim(source.substr(first_open + 1, first_close - first_open - 1));
    std::size_t after_dimensions = first_close + 1;
    if (first_dimension.empty()) {
        const std::string attributes = Trim(source.substr(after_dimensions));
        result.emitted = result.label + "[]" + (attributes.empty() ? "" : " " + attributes);
        return result;
    }

    const std::size_t first_width = ParsePositiveDecimal(first_dimension, line_number, "fixed text width");
    if (after_dimensions >= source.size() || source[after_dimensions] != '[') {
        result.is_fixed_width = true;
        result.fixed_width = first_width;
        const std::string attributes = Trim(source.substr(after_dimensions));
        result.emitted = result.label + "[" + std::to_string(result.fixed_width) + "]"
            + (attributes.empty() ? "" : " " + attributes);
        return result;
    }
    const std::size_t second_close = source.find(']', after_dimensions + 1);
    if (second_close == std::string::npos) {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": unterminated fixed-row width");
    }

    result.row_count = first_width;
    result.row_width = ParsePositiveDecimal(
        Trim(source.substr(after_dimensions + 1, second_close - after_dimensions - 1)),
        line_number, "fixed-row width");
    result.is_fixed_rows = true;
    const std::string attributes = Trim(source.substr(second_close + 1));
    result.emitted = result.label + "[" + std::to_string(result.row_count) + "]["
        + std::to_string(result.row_width) + "]" + (attributes.empty() ? "" : " " + attributes);
    return result;
}

std::vector<std::string> ExtractIncludeDirectives(const std::string &source)
{
    std::vector<std::string> includes;
    std::istringstream lines(source);
    std::string line;
    while (std::getline(lines, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(line);
        if (trimmed.rfind("#include", 0) == 0)
            includes.push_back(trimmed);
    }
    return includes;
}

struct GuidePageSource {
    std::string page;
    std::vector<std::string> lines;
};

// The collection manifest is an ordinary X-macro list.  Its source order is
// the game-visible book directory; ROM order independently preserves the
// physical data sequence.
struct GuideManifestEntry {
    std::string page;
    std::size_t rom_order;
    bool include_in_catalog;
};

struct GuideCollectionPage {
    GuideManifestEntry manifest;
    GuidePageSource source;
};


struct GuideCatalogEntry {
    std::string label;
    std::string text;
};

using GuideTextCatalog = std::map<Bytes, std::string>;

Bytes PadGuideTextStorage(const Bytes &text)
{
    // A source string has one implicit terminator.  Keep its physical object
    // four-byte aligned without exposing a capacity in the maintained source.
    constexpr std::size_t kAlignment = 4;
    Bytes storage = text;
    const std::size_t size_with_terminator = storage.size() + 1;
    const std::size_t padding = (kAlignment - (size_with_terminator % kAlignment)) % kAlignment;
    storage.insert(storage.end(), padding, 0);
    return storage;
}

std::string GuideSectionStem(const std::string &page);

std::string RepeatGuideText(const std::string &unit, std::size_t count)
{
    std::string result;
    result.reserve(unit.size() * count);
    for (std::size_t index = 0; index < count; ++index)
        result += unit;
    return result;
}

std::string GuideLineLabel(const std::string &page, std::size_t index,
    const std::string &text)
{
    // Slot zero is the fixed header row.  The remaining names retain their
    // physical line-slot number even when a layout primitive occupies a slot.
    if (index == 0)
        return "gText_ReferenceGuide_" + GuideSectionStem(page) + "_Title";

    if (text.empty())
        return "gText_ReferenceGuide_EmptyLine";

    // These are layout primitives rather than content belonging to a book.
    // Keep their names global so every page directly points at one semantic
    // object when the original ROM shares the same address.
    const std::string ideographic_space = "\xE3\x80\x80";
    const std::string fullwidth_hyphen = "\xEF\xBC\x8D";
    if (text == ideographic_space)
        return "gText_ReferenceGuide_IndentedEmptyLine";
    if (text == RepeatGuideText(ideographic_space, 14))
        return "gText_ReferenceGuide_PaddedEmptyLine";
    if (text == RepeatGuideText(fullwidth_hyphen, 14))
        return "gText_ReferenceGuide_SectionDivider";
    if (text == RepeatGuideText(".", 28))
        return "gText_ReferenceGuide_RecipeSectionDivider";

    std::string number = std::to_string(index);
    if (index < 10)
        number.insert(number.begin(), '0');
    return "gText_ReferenceGuide_" + GuideSectionStem(page) + "_Line" + number;
}

std::string GuideSectionStem(const std::string &page)
{
    std::string result;
    for (std::size_t index = 0; index < page.size(); ++index) {
        const unsigned char value = static_cast<unsigned char>(page[index]);
        const bool begins_word = index != 0
            && ((std::isupper(value) != 0
                    && (std::islower(static_cast<unsigned char>(page[index - 1])) != 0
                        || (index + 1 < page.size()
                            && std::islower(static_cast<unsigned char>(page[index + 1])) != 0)))
                 || (std::isdigit(value) != 0
                    && std::isdigit(static_cast<unsigned char>(page[index - 1])) == 0
                    && page[index - 1] != '_'));
        if (begins_word)
            result.push_back('_');
        result.push_back(static_cast<char>(std::tolower(value)));
    }
    return result;
}

std::string StripLineComment(const std::string &source)
{
    bool in_string = false;
    bool escaped = false;
    for (std::size_t index = 0; index < source.size(); ++index) {
        const char value = source[index];
        if (in_string) {
            if (escaped)
                escaped = false;
            else if (value == '\\')
                escaped = true;
            else if (value == '"')
                in_string = false;
            continue;
        }
        if (value == '"') {
            in_string = true;
            continue;
        }
        if (value == '/' && index + 1 < source.size() && source[index + 1] == '/')
            return source.substr(0, index);
    }
    return source;
}

bool IsGuidePageSource(const std::string &source)
{
    return source.find("END_FOMT_REFERENCE_GUIDE_PAGE") != std::string::npos;
}

GuidePageSource ParseGuidePageSource(const std::string &source, const std::string &page)
{
    if (!IsValidLabel(page))
        throw std::runtime_error("invalid generated guide-page name '" + page + "'");

    GuidePageSource result{page, {}};
    enum class ParseState {
        TitleKeyword,
        TitleText,
        MainKeyword,
        MainText,
        Closed,
    };
    ParseState state = ParseState::TitleKeyword;
    std::istringstream lines(source);
    std::string line;
    std::size_t line_number = 0;

    while (std::getline(lines, line)) {
        ++line_number;
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(StripLineComment(line));
        if (trimmed.empty())
            continue;

        if (trimmed.rfind("FOMT_REFERENCE_GUIDE_PAGE(", 0) == 0) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": guide-page name is generated from the manifest; remove the manual declaration");
        }

        if (state == ParseState::TitleKeyword) {
            if (trimmed != "TITLE") {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": expected TITLE at the start of the guide page");
            }
            state = ParseState::TitleText;
            continue;
        }

        if (state == ParseState::TitleText) {
            result.lines.push_back(ParseStringLiteral(trimmed, line_number));
            state = ParseState::MainKeyword;
            continue;
        }

        if (state == ParseState::MainKeyword) {
            if (trimmed != "MAIN") {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": expected MAIN after the title text");
            }
            state = ParseState::MainText;
            continue;
        }

        if (state == ParseState::MainText) {
            if (trimmed == "END_FOMT_REFERENCE_GUIDE_PAGE") {
                state = ParseState::Closed;
                continue;
            }
            result.lines.push_back(ParseStringLiteral(trimmed, line_number));
            continue;
        }

        throw std::runtime_error("line " + std::to_string(line_number)
            + ": text after END_FOMT_REFERENCE_GUIDE_PAGE");
    }

    if (state != ParseState::Closed)
        throw std::runtime_error("guide page '" + result.page
            + "' has no END_FOMT_REFERENCE_GUIDE_PAGE");
    if (result.lines.size() < 2)
        throw std::runtime_error("guide page '" + result.page
            + "' must contain one TITLE text and at least one MAIN text row");
    return result;
}

// Staff credits are maintained as one visible scrolling sequence rather than
// as separately named storage fields.  The original pointer table supplies
// the physical field order, widths, and repeated-pointer relationships.
struct StaffCreditsSource {
    std::vector<std::string> lines;
};

bool IsStaffCreditsSource(const std::string &source)
{
    return source.find("END_FOMT_STAFF_CREDITS") != std::string::npos;
}

StaffCreditsSource ParseStaffCreditsSource(const std::string &source)
{
    StaffCreditsSource result;
    bool started = false;
    bool closed = false;
    std::istringstream lines(source);
    std::string line;
    std::size_t line_number = 0;

    while (std::getline(lines, line)) {
        ++line_number;
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(StripLineComment(line));
        if (trimmed.empty())
            continue;

        if (!started) {
            if (trimmed != "FOMT_STAFF_CREDITS") {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": expected FOMT_STAFF_CREDITS at the start of the staff credits");
            }
            started = true;
            continue;
        }

        if (closed) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": text after END_FOMT_STAFF_CREDITS");
        }
        if (trimmed == "END_FOMT_STAFF_CREDITS") {
            closed = true;
            continue;
        }
        result.lines.push_back(ParseStringLiteral(trimmed, line_number));
    }

    if (!started)
        throw std::runtime_error("staff-credit source has no FOMT_STAFF_CREDITS marker");
    if (!closed)
        throw std::runtime_error("staff-credit source has no END_FOMT_STAFF_CREDITS marker");
    if (result.lines.empty())
        throw std::runtime_error("staff-credit source has no visible rows");
    return result;
}

struct StaffCreditsRomLayout {
    std::uint32_t text_start;
    std::uint32_t table_start;
};

StaffCreditsRomLayout StaffCreditsLayoutForRegion(const std::string &region)
{
    if (region == "JP")
        return {0x000FB938, 0x000FBC88};
    if (region == "US")
        return {0x000FC0A4, 0x000FC4B4};
    throw std::runtime_error("staff-credit compilation requires region JP or US");
}

std::uint32_t ReadLittleEndian32(const Bytes &source, std::size_t offset,
    const std::string &description)
{
    if (offset > source.size() || source.size() - offset < 4)
        throw std::runtime_error(description + " extends past the baseline ROM");
    return static_cast<std::uint32_t>(source[offset])
        | (static_cast<std::uint32_t>(source[offset + 1]) << 8)
        | (static_cast<std::uint32_t>(source[offset + 2]) << 16)
        | (static_cast<std::uint32_t>(source[offset + 3]) << 24);
}

struct StaffCreditsTextField {
    std::uint32_t address;
    std::size_t storage_size;
};

struct StaffCreditsBaseline {
    std::vector<std::uint32_t> row_addresses;
    std::vector<StaffCreditsTextField> fields;
    std::uint32_t table_end;
};

StaffCreditsBaseline ReadStaffCreditsBaseline(const Bytes &rom,
    const StaffCreditsRomLayout &layout)
{
    constexpr std::uint32_t kGbaRomBase = 0x08000000;
    if (layout.text_start >= layout.table_start || layout.table_start >= rom.size())
        throw std::runtime_error("invalid staff-credit baseline layout");

    StaffCreditsBaseline result;
    for (std::uint32_t offset = layout.table_start;; offset += 4) {
        const std::uint32_t pointer = ReadLittleEndian32(rom, offset,
            "staff-credit pointer table");
        if (pointer == 0) {
            result.table_end = offset + 4;
            break;
        }
        const std::uint32_t first = kGbaRomBase + layout.text_start;
        const std::uint32_t last = kGbaRomBase + layout.table_start;
        if (pointer < first || pointer >= last) {
            throw std::runtime_error("staff-credit pointer table references data outside its text pool");
        }
        result.row_addresses.push_back(pointer - kGbaRomBase);
    }
    if (result.row_addresses.empty())
        throw std::runtime_error("staff-credit pointer table has no rows");

    std::set<std::uint32_t> distinct_addresses(result.row_addresses.begin(),
        result.row_addresses.end());
    for (const std::uint32_t address : distinct_addresses) {
        const auto next = distinct_addresses.upper_bound(address);
        const std::uint32_t end = next == distinct_addresses.end()
            ? layout.table_start : *next;
        if (address >= end) {
            throw std::runtime_error("staff-credit text fields are not in ascending physical order");
        }
        const std::size_t storage_size = end - address;
        const auto first = rom.begin() + address;
        if (std::find(first, first + storage_size, 0) == first + storage_size) {
            throw std::runtime_error("staff-credit text field has no terminating zero");
        }
        result.fields.push_back({address, storage_size});
    }
    return result;
}

std::string StaffCreditsLineLabel(std::size_t source_line)
{
    std::string number = std::to_string(source_line);
    while (number.size() < 3)
        number.insert(number.begin(), '0');
    return "gText_StaffCredits_Line" + number;
}

std::string CompileStaffCredits(const std::string &source, const std::string &region,
    const Bytes &rom, const Charmap &charmap)
{
    const StaffCreditsSource credits = ParseStaffCreditsSource(source);
    const StaffCreditsBaseline baseline = ReadStaffCreditsBaseline(rom,
        StaffCreditsLayoutForRegion(region));
    if (credits.lines.size() != baseline.row_addresses.size()) {
        throw std::runtime_error("staff-credit source has "
            + std::to_string(credits.lines.size()) + " visible rows, but the " + region
            + " baseline pointer table has " + std::to_string(baseline.row_addresses.size()));
    }

    std::map<std::uint32_t, Bytes> text_by_address;
    std::map<std::uint32_t, std::size_t> first_row_by_address;
    for (std::size_t row = 0; row < credits.lines.size(); ++row) {
        Bytes bytes;
        try {
            bytes = charmap.EncodeText(credits.lines[row]);
        } catch (const std::runtime_error &error) {
            throw std::runtime_error("staff-credit row " + std::to_string(row)
                + ": " + error.what());
        }

        const std::uint32_t address = baseline.row_addresses[row];
        const auto inserted = text_by_address.emplace(address, bytes);
        if (inserted.second) {
            first_row_by_address.emplace(address, row);
            continue;
        }
        if (inserted.first->second != bytes) {
            throw std::runtime_error("staff-credit row " + std::to_string(row)
                + " shares its original pointer with row "
                + std::to_string(first_row_by_address.at(address))
                + ", so both visible rows must contain the same text");
        }
    }

    std::map<std::uint32_t, std::string> label_by_address;
    std::size_t empty_field_count = 0;
    for (const StaffCreditsTextField &field : baseline.fields) {
        const Bytes &bytes = text_by_address.at(field.address);
        if (bytes.empty() && empty_field_count++ == 0) {
            label_by_address.emplace(field.address, "gText_StaffCredits_EmptyLine");
        } else {
            label_by_address.emplace(field.address,
                StaffCreditsLineLabel(first_row_by_address.at(field.address)));
        }
    }

    std::ostringstream output;
    output << "// Generated by fomt-text.  Do not edit.\n"
              "#include \"staff_credits_text.hh\"\n\n"
              "template <unsigned int Size>\n"
              "struct StaffCreditsTextStorage\n"
              "{\n"
              "    char bytes[Size];\n"
              "};\n\n";
    for (const StaffCreditsTextField &field : baseline.fields) {
        EmitStaffCreditsCppString(output, label_by_address.at(field.address),
            field.storage_size, text_by_address.at(field.address));
    }

    output << "extern char const * const gStaffCreditsLines[]"
              " SECTION(\".rodata.staff_credits\") = {\n";
    for (const std::uint32_t address : baseline.row_addresses)
        output << "    " << label_by_address.at(address) << ".bytes,\n";
    output << "    nullptr,\n};\n";
    return output.str();
}

bool TryParseGuideManifestRow(const std::string &source, std::vector<std::string> &arguments,
    std::size_t line_number)
{
    std::string row = source;
    if (!row.empty() && row.back() == ',')
        row.pop_back();
    row = Trim(row);
    if (row.size() < 2 || row.front() != '{' || row.back() != '}')
        return false;

    const std::string body = row.substr(1, row.size() - 2);
    std::size_t start = 0;
    bool in_string = false;
    bool escaped = false;
    while (start <= body.size()) {
        std::size_t comma = std::string::npos;
        for (std::size_t index = start; index < body.size(); ++index) {
            const char value = body[index];
            if (in_string) {
                if (escaped)
                    escaped = false;
                else if (value == '\\')
                    escaped = true;
                else if (value == '"')
                    in_string = false;
            } else if (value == '"') {
                in_string = true;
            } else if (value == ',') {
                comma = index;
                break;
            }
        }
        if (in_string) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": unterminated string in Reference Guide manifest row");
        }
        const std::string argument = Trim(body.substr(start,
            comma == std::string::npos ? std::string::npos : comma - start));
        if (argument.empty()) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": empty field in Reference Guide manifest row");
        }
        arguments.push_back(argument);
        if (comma == std::string::npos)
            break;
        start = comma + 1;
    }
    return true;
}

bool IsGuideManifestStem(const std::string &stem)
{
    if (stem.empty() || !(std::islower(static_cast<unsigned char>(stem.front())) != 0))
        return false;
    return std::all_of(stem.begin() + 1, stem.end(), [](char value) {
        const auto character = static_cast<unsigned char>(value);
        return std::islower(character) != 0 || std::isdigit(character) != 0 || value == '_';
    });
}

std::size_t ParseGuideRomOrder(const std::string &source, std::size_t line_number)
{
    if (source.empty() || !std::all_of(source.begin(), source.end(), [](char value) {
            return std::isdigit(static_cast<unsigned char>(value)) != 0;
        })) {
        throw std::runtime_error("line " + std::to_string(line_number)
            + ": Reference Guide ROM order must be a non-negative decimal integer");
    }
    return static_cast<std::size_t>(std::stoul(source));
}

bool ParseGuideCatalogFlag(const std::string &source, std::size_t line_number)
{
    if (source == "true")
        return true;
    if (source == "false")
        return false;
    throw std::runtime_error("line " + std::to_string(line_number)
        + ": Reference Guide catalog flag must be true or false");
}

std::vector<GuideManifestEntry> ParseGuideManifest(const std::filesystem::path &path,
    const std::string &region)
{
    if (region != "JP" && region != "US")
        throw std::runtime_error("guide collection region must be JP or US");

    std::vector<GuideManifestEntry> result;
    std::set<std::string> pages;
    std::set<std::size_t> rom_orders;
    std::istringstream lines(ReadTextFile(path));
    std::string line;
    std::size_t line_number = 0;
    bool in_region_us = false;
    bool include_current_line = true;
    bool in_manifest = false;
    bool manifest_closed = false;
    constexpr char kManifestStart[] = "FomtReferenceGuideBookManifest const gReferenceGuideBooks[] = {";
    while (std::getline(lines, line)) {
        ++line_number;
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(StripLineComment(line));
        if (trimmed.empty())
            continue;

        if (!in_manifest) {
            if (trimmed == kManifestStart) {
                if (manifest_closed) {
                    throw std::runtime_error("line " + std::to_string(line_number)
                        + ": duplicate Reference Guide manifest array");
                }
                in_manifest = true;
            }
            continue;
        }

        if (trimmed == "};") {
            if (in_region_us) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": Reference Guide manifest closes inside REGION_US conditional");
            }
            in_manifest = false;
            manifest_closed = true;
            continue;
        }

        if (trimmed == "#if defined(REGION_US)") {
            if (in_region_us) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": nested REGION_US conditional in Reference Guide catalog");
            }
            in_region_us = true;
            include_current_line = region == "US";
            continue;
        }
        if (trimmed == "#endif") {
            if (!in_region_us) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": unmatched #endif in Reference Guide catalog");
            }
            in_region_us = false;
            include_current_line = true;
            continue;
        }
        if (!include_current_line)
            continue;

        std::vector<std::string> arguments;
        if (!TryParseGuideManifestRow(trimmed, arguments, line_number)) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": expected a { \"book_name\", rom_order, catalog_flag } row");
        }
        if (arguments.size() != 3) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": invalid Reference Guide manifest entry");
        }
        const std::string page = ParseStringLiteral(arguments[0], line_number);
        if (!IsGuideManifestStem(page)) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": invalid Reference Guide book name");
        }
        const std::size_t rom_order = ParseGuideRomOrder(arguments[1], line_number);
        const bool include_in_catalog = ParseGuideCatalogFlag(arguments[2], line_number);
        if (!pages.insert(page).second
            || !rom_orders.insert(rom_order).second) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": duplicate Reference Guide name or ROM order");
        }
        result.push_back({page, rom_order, include_in_catalog});
    }

    if (in_region_us)
        throw std::runtime_error("Reference Guide catalog has an unterminated REGION_US conditional");
    if (in_manifest || !manifest_closed)
        throw std::runtime_error("guide collection manifest has no closed gReferenceGuideBooks array");
    if (result.empty())
        throw std::runtime_error("guide collection manifest has no selected entries");
    return result;
}

std::filesystem::path GuideArticlePath(const std::filesystem::path &manifest_path,
    const std::string &region, const std::string &page)
{
    const std::filesystem::path root = manifest_path.parent_path().parent_path();
    std::string lower_region = region;
    std::transform(lower_region.begin(), lower_region.end(), lower_region.begin(), [](char value) {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(value)));
    });
    return root / "data" / "text" / lower_region / "reference_guide"
        / (GuideSectionStem(page) + ".cc");
}

std::vector<GuideCollectionPage> ReadGuideCollectionPages(
    const std::filesystem::path &manifest_path, const std::string &region)
{
    std::vector<GuideCollectionPage> result;
    for (const GuideManifestEntry &entry : ParseGuideManifest(manifest_path, region)) {
        const std::filesystem::path article_path = GuideArticlePath(manifest_path, region, entry.page);
        const GuidePageSource source = ParseGuidePageSource(ReadTextFile(article_path), entry.page);
        result.push_back({entry, source});
    }
    return result;
}

std::vector<GuideCatalogEntry> ParseLegacyGuideCatalogEntries(const std::string &source)
{
    std::vector<GuideCatalogEntry> entries;
    std::string current_label;
    std::string current_text;
    bool has_current = false;
    std::istringstream lines(source);
    std::string line;
    std::size_t line_number = 0;

    const auto FinishCurrent = [&]() {
        entries.push_back({current_label, current_text});
        current_label.clear();
        current_text.clear();
        has_current = false;
    };

    while (std::getline(lines, line)) {
        ++line_number;
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(StripLineComment(line));
        if (trimmed.empty() || trimmed.rfind("#include", 0) == 0)
            continue;

        if (has_current) {
            std::string literal = trimmed;
            const bool terminated = !literal.empty() && literal.back() == ';';
            if (terminated)
                literal = Trim(literal.substr(0, literal.size() - 1));
            current_text += ParseStringLiteral(literal, line_number);
            if (terminated)
                FinishCurrent();
            continue;
        }

        constexpr char kPrefix[] = "char const gText_ReferenceGuide_";
        if (trimmed.rfind(kPrefix, 0) != 0)
            continue;

        const std::size_t equals = trimmed.find('=');
        if (equals == std::string::npos) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": guide text definition has no initializer");
        }
        const TextDeclarator declarator = ParseTextDeclarator(
            Trim(trimmed.substr(sizeof("char const ") - 1, equals - (sizeof("char const ") - 1))),
            line_number);
        if (declarator.is_fixed_rows) {
            throw std::runtime_error("line " + std::to_string(line_number)
                + ": guide text catalog does not support fixed-row text objects");
        }
        current_label = declarator.label;
        current_text.clear();
        has_current = true;

        std::string literal = Trim(trimmed.substr(equals + 1));
        if (literal.empty())
            continue;
        const bool terminated = literal.back() == ';';
        if (terminated)
            literal = Trim(literal.substr(0, literal.size() - 1));
        current_text = ParseStringLiteral(literal, line_number);
        if (terminated)
            FinishCurrent();
    }

    if (has_current) {
        throw std::runtime_error("guide text label '" + current_label
            + "' has no terminating semicolon");
    }
    return entries;
}

void AddGuideCatalogText(GuideTextCatalog &catalog, const Charmap &charmap,
    const std::string &text, const std::string &label)
{
    Bytes bytes;
    try {
        bytes = charmap.EncodeText(text);
    } catch (const std::runtime_error &error) {
        throw std::runtime_error("guide text label '" + label + "': " + error.what());
    }
    if (catalog.count(bytes) == 0)
        catalog.emplace(std::move(bytes), label);
}

void AddGuideCatalogSource(GuideTextCatalog &catalog, const std::string &source,
    const Charmap &charmap, const std::string &page_name = "")
{
    if (IsGuidePageSource(source)) {
        if (page_name.empty()) {
            throw std::runtime_error("guide page source requires a generated page name");
        }
        const GuidePageSource page = ParseGuidePageSource(source, page_name);
        for (std::size_t index = 0; index < page.lines.size(); ++index) {
            AddGuideCatalogText(catalog, charmap, page.lines[index],
                GuideLineLabel(page.page, index, page.lines[index]));
        }
        return;
    }

    for (const GuideCatalogEntry &entry : ParseLegacyGuideCatalogEntries(source))
        AddGuideCatalogText(catalog, charmap, entry.text, entry.label);
}

std::vector<std::filesystem::path> ExtractGuideCollectionIncludes(
    const std::filesystem::path &source_path)
{
    std::vector<std::filesystem::path> includes;
    std::istringstream lines(ReadTextFile(source_path));
    std::string line;
    while (std::getline(lines, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(StripLineComment(line));
        constexpr char kPrefix[] = "#include \"";
        if (trimmed.rfind(kPrefix, 0) != 0)
            continue;
        const std::size_t close = trimmed.find('"', sizeof(kPrefix) - 1);
        if (close == std::string::npos || !Trim(trimmed.substr(close + 1)).empty()) {
            throw std::runtime_error("invalid #include in guide collection '"
                + source_path.string() + "'");
        }
        const std::filesystem::path include = trimmed.substr(sizeof(kPrefix) - 1,
            close - (sizeof(kPrefix) - 1));
        if (include.extension() == ".cc")
            includes.push_back((source_path.parent_path() / include).lexically_normal());
    }
    return includes;
}

void AppendGuideCatalogSources(const std::filesystem::path &source_path,
    std::vector<std::filesystem::path> &result, std::set<std::filesystem::path> &active,
    std::set<std::filesystem::path> &leaves)
{
    const std::filesystem::path normalized = source_path.lexically_normal();
    if (!active.insert(normalized).second) {
        throw std::runtime_error("recursive guide collection include at '"
            + normalized.string() + "'");
    }
    const std::vector<std::filesystem::path> includes = ExtractGuideCollectionIncludes(normalized);
    if (includes.empty()) {
        if (!leaves.insert(normalized).second) {
            throw std::runtime_error("guide article appears more than once in its collection: '"
                + normalized.string() + "'");
        }
        result.push_back(normalized);
    } else {
        for (const std::filesystem::path &include : includes)
            AppendGuideCatalogSources(include, result, active, leaves);
    }
    active.erase(normalized);
}

std::vector<std::filesystem::path> ExpandGuideCatalogSources(
    const std::vector<std::filesystem::path> &sources)
{
    std::vector<std::filesystem::path> result;
    std::set<std::filesystem::path> active;
    std::set<std::filesystem::path> leaves;
    for (const std::filesystem::path &source : sources)
        AppendGuideCatalogSources(source, result, active, leaves);
    return result;
}

GuideTextCatalog BuildGuideTextCatalog(const Charmap &charmap,
    const std::vector<std::filesystem::path> &sources)
{
    if (sources.empty())
        throw std::runtime_error("guide compilation requires its guide-text catalog sources");

    GuideTextCatalog catalog;
    for (const std::filesystem::path &path : ExpandGuideCatalogSources(sources))
        AddGuideCatalogSource(catalog, ReadTextFile(path), charmap, path.stem().string());
    return catalog;
}

struct GuidePageOutput {
    std::string text;
    std::string table;
};

GuidePageOutput CompileGuidePage(const std::string &source, const std::string &page_name,
    const Charmap &charmap, const GuideTextCatalog &catalog)
{
    const GuidePageSource page = ParseGuidePageSource(source, page_name);
    std::ostringstream text_output;
    std::ostringstream table_output;
    // Guide article inputs are deliberately not C++ translation units.  The
    // generated C++ owns its required declaration header instead.
    text_output << "// Generated by fomt-text.  Do not edit.\n"
                   "#include \"reference_guide.hh\"\n\n";
    table_output << "// Generated by fomt-text.  Do not edit.\n"
                    "#include \"reference_guide.hh\"\n\n";

    std::vector<std::string> pointer_entries;
    const std::string section_stem = GuideSectionStem(page.page);
    const std::string guide_section = ".rodata.reference_guide";
    std::set<std::string> emitted_labels;
    for (std::size_t index = 0; index < page.lines.size(); ++index) {
        Bytes bytes;
        try {
            bytes = charmap.EncodeText(page.lines[index]);
        } catch (const std::runtime_error &error) {
            throw std::runtime_error("guide page '" + page.page + "' line "
                + std::to_string(index) + ": " + error.what());
        }
        const auto canonical = catalog.find(bytes);
        if (canonical == catalog.end()) {
            throw std::runtime_error("guide page '" + page.page
                + "' is absent from the guide-text catalog");
        }
        const std::string local_label = GuideLineLabel(page.page, index, page.lines[index]);
        pointer_entries.push_back(canonical->second);
        if (canonical->second == local_label && emitted_labels.insert(local_label).second) {
            EmitCppString(text_output, local_label + "[] SECTION(\"" + guide_section + "\")",
                PadGuideTextStorage(bytes), "extern ");
        }
    }

    std::set<std::string> table_labels(pointer_entries.begin(), pointer_entries.end());
    for (const std::string &label : table_labels)
        table_output << "extern char const " << label << "[];\n";
    if (!table_labels.empty())
        table_output << '\n';
    table_output << "extern char const * const gReferenceGuide_" << section_stem
                 << "[] SECTION(\"" << guide_section << "\") = {\n";
    for (const std::string &entry : pointer_entries)
        table_output << "    " << entry << ",\n";
    table_output << "    nullptr,\n};\n";
    return {text_output.str(), table_output.str()};
}

std::vector<std::string> ResolveGuidePointerEntries(const GuidePageSource &page,
    const Charmap &charmap, const GuideTextCatalog &catalog)
{
    std::vector<std::string> result;
    for (std::size_t index = 0; index < page.lines.size(); ++index) {
        Bytes bytes;
        try {
            bytes = charmap.EncodeText(page.lines[index]);
        } catch (const std::runtime_error &error) {
            throw std::runtime_error("guide page '" + page.page + "' line "
                + std::to_string(index) + ": " + error.what());
        }
        const auto canonical = catalog.find(bytes);
        if (canonical == catalog.end()) {
            throw std::runtime_error("guide page '" + page.page
                + "' is absent from the guide-text catalog");
        }
        result.push_back(canonical->second);
    }
    return result;
}

struct GuideCollectionOutput {
    std::string source;
};

GuideCollectionOutput CompileGuideCollection(const std::vector<GuideCollectionPage> &pages,
    const Charmap &charmap)
{
    // The manifest source is the runtime-directory order.  Its ROM-order
    // field determines physical order.  A false entry is an auxiliary page:
    // it joins the immediately preceding ROM group, so all group text is
    // emitted before that group's line-pointer tables.
    std::vector<std::size_t> physical_indexes;
    physical_indexes.reserve(pages.size());
    for (std::size_t index = 0; index < pages.size(); ++index)
        physical_indexes.push_back(index);
    std::sort(physical_indexes.begin(), physical_indexes.end(),
        [&pages](std::size_t left, std::size_t right) {
            return pages[left].manifest.rom_order < pages[right].manifest.rom_order;
        });

    std::vector<std::vector<std::size_t>> physical_groups;
    for (const std::size_t page_index : physical_indexes) {
        if (pages[page_index].manifest.include_in_catalog) {
            physical_groups.push_back({page_index});
            continue;
        }
        if (physical_groups.empty()) {
            throw std::runtime_error("Reference Guide auxiliary page '"
                + pages[page_index].manifest.page
                + "' has no preceding ROM group");
        }
        physical_groups.back().push_back(page_index);
    }

    GuideTextCatalog catalog;
    for (const std::vector<std::size_t> &group : physical_groups) {
        for (const std::size_t page_index : group) {
            const GuideCollectionPage &page = pages[page_index];
            for (std::size_t index = 0; index < page.source.lines.size(); ++index) {
                AddGuideCatalogText(catalog, charmap, page.source.lines[index],
                    GuideLineLabel(page.source.page, index, page.source.lines[index]));
            }
        }
    }

    std::vector<std::vector<std::string>> pointer_entries;
    pointer_entries.reserve(pages.size());
    for (const GuideCollectionPage &page : pages)
        pointer_entries.push_back(ResolveGuidePointerEntries(page.source, charmap, catalog));

    std::ostringstream output;
    output << "// Generated by fomt-text.  Do not edit.\n"
              "#include \"reference_guide.hh\"\n\n"
              "template <unsigned int Size>\n"
              "struct ReferenceGuideTextStorage\n"
              "{\n"
              "    char bytes[Size];\n"
              "};\n\n";
    for (const GuideCollectionPage &page : pages) {
        output << "extern char const * const gReferenceGuide_" << page.manifest.page << "[];\n";
    }
    output << '\n';

    constexpr char kGuideSection[] = ".rodata.reference_guide";
    output << "extern char const * const * const gReferenceGuideTables[]"
           << " SECTION(\"" << kGuideSection << "\") = {\n";
    for (const GuideCollectionPage &page : pages) {
        if (page.manifest.include_in_catalog)
            output << "    gReferenceGuide_" << page.manifest.page << ",\n";
    }
    output << "};\n\n";

    std::set<std::string> emitted_labels;
    for (const std::vector<std::size_t> &group : physical_groups) {
        for (const std::size_t page_index : group) {
            const GuideCollectionPage &page = pages[page_index];
            for (std::size_t line_index = 0; line_index < page.source.lines.size(); ++line_index) {
                const Bytes bytes = charmap.EncodeText(page.source.lines[line_index]);
                const std::string local_label = GuideLineLabel(page.source.page, line_index,
                    page.source.lines[line_index]);
                const std::string &canonical = catalog.at(bytes);
                if (canonical == local_label && emitted_labels.insert(local_label).second) {
                    EmitGuideCppString(output, local_label, kGuideSection,
                        PadGuideTextStorage(bytes));
                }
            }
        }

        for (const std::size_t page_index : group) {
            const GuideCollectionPage &page = pages[page_index];
            output << "extern char const * const gReferenceGuide_" << page.manifest.page
                   << "[] SECTION(\"" << kGuideSection << "\") = {\n";
            for (const std::string &entry : pointer_entries[page_index])
                output << "    " << entry << ".bytes,\n";
            output << "    nullptr,\n};\n\n";
        }
    }
    if (emitted_labels.size() != catalog.size())
        throw std::runtime_error("guide collection did not emit every canonical text object");
    return {output.str()};
}

std::string CompileCppTextInclude(const std::string &source, const Charmap &charmap)
{
    if (IsGuidePageSource(source))
        throw std::runtime_error("guide-page source must be processed with the guide command");
    if (IsStaffCreditsSource(source))
        throw std::runtime_error("staff-credit source must be processed with the staff-credits command");
    ValidatePageBreakLayout(source);
    if (HasStructuredTextInitializer(source))
        return CompileCppStructuredTextSource(source, charmap);

    std::ostringstream output;
    output << "// Generated by fomt-text.  Do not edit.\n\n";
    const std::vector<std::string> includes = ExtractIncludeDirectives(source);
    for (const std::string &include : includes)
        output << include << '\n';
    if (!includes.empty())
        output << '\n';

    std::istringstream lines(source);
    std::string line;
    TextDeclarator current_declarator;
    std::string current_text;
    std::vector<Bytes> current_rows;
    bool has_current_declaration = false;
    bool current_has_string = false;
    bool current_string_emitted = false;
    bool copying_passthrough_declaration = false;
    std::size_t line_number = 0;

    const auto EmitCurrentString = [&]() {
        if (!has_current_declaration || !current_has_string || current_string_emitted)
            return;

        Bytes bytes;
        try {
            bytes = charmap.EncodeText(current_text);
        } catch (const std::runtime_error &error) {
            throw std::runtime_error("text label '" + current_declarator.label + "': " + error.what());
        }
        if (current_declarator.is_fixed_width
            && bytes.size() + 1 > current_declarator.fixed_width) {
            throw std::runtime_error("text label '" + current_declarator.label + "' encodes to "
                + std::to_string(bytes.size() + 1) + " bytes including its terminator; maximum is "
                + std::to_string(current_declarator.fixed_width));
        }
        EmitCppString(output, current_declarator.emitted, bytes);
        current_string_emitted = true;
    };

    while (std::getline(lines, line)) {
        ++line_number;
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(line);

        // Text modules may keep a ROM pointer word directly beside the text it
        // references.  It is ordinary C++, not text for the charmap to encode;
        // preserve the complete declaration so the compiler emits its relocation.
        if (copying_passthrough_declaration) {
            output << line << '\n';
            if (line.find(';') != std::string::npos)
                copying_passthrough_declaration = false;
            continue;
        }
        if (trimmed.empty() || trimmed.rfind("//", 0) == 0 || trimmed.front() == '#')
            continue;

        if (has_current_declaration && current_declarator.is_fixed_rows) {
            if (trimmed == "};") {
                if (current_rows.size() != current_declarator.row_count) {
                    throw std::runtime_error("line " + std::to_string(line_number) + ": text label '"
                        + current_declarator.label + "' has " + std::to_string(current_rows.size())
                        + " rows; expected " + std::to_string(current_declarator.row_count));
                }
                EmitCppStringRows(output, current_declarator.emitted, current_rows);
                has_current_declaration = false;
                current_rows.clear();
                continue;
            }

            std::string literal = trimmed;
            if (!literal.empty() && literal.back() == ',')
                literal = Trim(literal.substr(0, literal.size() - 1));
            const std::string text = ParseStringLiteral(literal, line_number);
            Bytes bytes;
            try {
                bytes = charmap.EncodeText(text);
            } catch (const std::runtime_error &error) {
                throw std::runtime_error("text label '" + current_declarator.label + "': " + error.what());
            }
            const bool has_explicit_terminator = std::find(bytes.begin(), bytes.end(), 0) != bytes.end();
            const std::size_t initialized_width = bytes.size() + (has_explicit_terminator ? 0 : 1);
            if (initialized_width > current_declarator.row_width) {
                throw std::runtime_error("line " + std::to_string(line_number) + ": text label '"
                    + current_declarator.label + "' row encodes to " + std::to_string(bytes.size() + 1)
                    + " bytes including its implicit terminator; maximum is "
                    + std::to_string(current_declarator.row_width));
            }
            if (current_rows.size() == current_declarator.row_count) {
                throw std::runtime_error("line " + std::to_string(line_number) + ": text label '"
                    + current_declarator.label + "' has more than "
                    + std::to_string(current_declarator.row_count) + " rows");
            }
            current_rows.push_back(std::move(bytes));
            continue;
        }

        constexpr char kDeclaration[] = "char const ";
        std::string declaration_line = trimmed;
        if (declaration_line.rfind("extern ", 0) == 0)
            declaration_line = Trim(declaration_line.substr(sizeof("extern ") - 1));
        if (declaration_line.rfind(kDeclaration, 0) == 0) {
            if (has_current_declaration && !current_string_emitted) {
                throw std::runtime_error("line " + std::to_string(line_number) + ": text label '"
                    + current_declarator.label + "' has no terminating semicolon");
            }

            const std::string declaration = Trim(declaration_line.substr(sizeof(kDeclaration) - 1));
            const std::size_t equals = declaration.find('=');
            const std::string declarator = Trim(declaration.substr(0, equals));
            if (declarator.find('*') != std::string::npos) {
                output << line << '\n';
                if (line.find(';') == std::string::npos)
                    copying_passthrough_declaration = true;
                continue;
            }
            if (equals == std::string::npos) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": expected '=' in text declaration");
            }
            current_declarator = ParseTextDeclarator(declarator, line_number);
            has_current_declaration = true;
            current_has_string = false;
            current_string_emitted = false;
            current_text.clear();
            current_rows.clear();

            const std::string initial_literal = Trim(declaration.substr(equals + 1));
            if (current_declarator.is_fixed_rows) {
                if (initial_literal != "{") {
                    throw std::runtime_error("line " + std::to_string(line_number) + ": fixed-row text label '"
                        + current_declarator.label + "' must begin with '{'");
                }
                continue;
            }
            if (!initial_literal.empty()) {
                bool terminated = false;
                std::string literal = initial_literal;
                if (literal.back() == ';') {
                    terminated = true;
                    literal = Trim(literal.substr(0, literal.size() - 1));
                }
                current_text = ParseStringLiteral(literal, line_number);
                current_has_string = true;
                if (terminated)
                    EmitCurrentString();
            }
            continue;
        }

        if (!trimmed.empty() && trimmed.front() == '"') {
            if (!has_current_declaration || current_string_emitted) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": string literal must follow an unfinished text declaration");
            }
            bool terminated = false;
            std::string literal = trimmed;
            if (literal.back() == ';') {
                terminated = true;
                literal = Trim(literal.substr(0, literal.size() - 1));
            }
            current_text += ParseStringLiteral(literal, line_number);
            current_has_string = true;
            if (terminated)
                EmitCurrentString();
            continue;
        }

        throw std::runtime_error("line " + std::to_string(line_number)
            + ": expected a char const text declaration or quoted string continuation");
    }

    if (has_current_declaration && current_declarator.is_fixed_rows) {
        throw std::runtime_error("text label '" + current_declarator.label
            + "' has no closing '};'");
    }
    if (has_current_declaration && !current_string_emitted) {
        if (!current_has_string)
            throw std::runtime_error("label '" + current_declarator.label + "' has no text string");
        throw std::runtime_error("label '" + current_declarator.label + "' has no terminating semicolon");
    }
    EmitCurrentString();
    return output.str();
}

void Require(bool condition, const std::string &message)
{
    if (!condition)
        throw std::runtime_error("self-test failed: " + message);
}

void SelfTest()
{
    const std::string map_source = "05={Press}\n0A=\\n\n0C=\\p\n0D=\\r\n20= \n41=A\n42=B\n43=C\n";
    const Charmap map = Charmap::Parse(map_source);
    Require(map.EncodeText("A\\nB\\xFE") == Bytes{0x41, 0x0A, 0x42, 0xFE},
        "named controls and explicit bytes do not encode");
    Require(map.DecodeText(Bytes{0x41, 0x0A, 0xFE}) == "A\\n\\xFE",
        "unknown bytes do not round-trip as escapes");
    Require(GuideLineLabel("example", 1, "") == "gText_ReferenceGuide_EmptyLine",
        "empty guide text did not use the global layout label");
    Require(GuideLineLabel("example", 1, "\xE3\x80\x80")
            == "gText_ReferenceGuide_IndentedEmptyLine",
        "indented empty guide text did not use the global layout label");
    Require(GuideLineLabel("example", 1, RepeatGuideText("\xEF\xBC\x8D", 14))
            == "gText_ReferenceGuide_SectionDivider",
        "guide divider did not use the global layout label");
    Require(GuideLineLabel("example", 0, "A")
            == "gText_ReferenceGuide_example_Title",
        "guide title did not use the Title label");
    Require(GuideLineLabel("example", 5, "C")
            == "gText_ReferenceGuide_example_Line05",
        "guide line labels did not retain their physical slot number");

    const std::string generated = CompileCppTextInclude(
        "char const gText_Test[] =\n"
        "    \"A\\n\"\n"
        "    \"B\";\n", map);
    Require(generated.find("char const gText_Test[]") != std::string::npos,
        "generated C++ text symbol is missing");
    Require(generated.find("\\x41\\x0A\\x42") != std::string::npos,
        "generated C++ text bytes are wrong");
    Require(generated.find(".align") == std::string::npos,
        "generated C++ text must not emit assembler alignment");

    const std::string generated_page_break = CompileCppTextInclude(
        "char const gText_PageBreak[] =\r\n"
        "    \"A{Press}\\p\"\r\n"
        "    \"B\";\r\n", map);
    Require(generated_page_break.find("\\x41\\x05\\x0C\\x42") != std::string::npos,
        "trailing page-break text did not encode");

    const std::string generated_text_reference = CompileCppTextInclude(
        "#include \"test.hh\"\n"
        "char const gText_TestReference[] = \"A\";\n"
        "char const * const gTestTextReference =\n"
        "    gText_TestReference;\n", map);
    Require(generated_text_reference.find("char const * const gTestTextReference =\n"
                                         "    gText_TestReference;") != std::string::npos,
        "text-reference pointer declaration was not preserved");

    bool rejected_inline_page_break = false;
    try {
        static_cast<void>(CompileCppTextInclude(
            "char const gText_InlinePageBreak[] =\n"
            "    \"\\pA\";\n", map));
    } catch (const std::runtime_error &) {
        rejected_inline_page_break = true;
    }
    Require(rejected_inline_page_break, "inline page-break text was accepted");

    bool rejected_empty_page_break_line = false;
    try {
        static_cast<void>(CompileCppTextInclude(
            "char const gText_EmptyPageBreakLine[] =\n"
            "    \"\\p\"\n"
            "    \"\"\n"
            "    \"A\";\n", map));
    } catch (const std::runtime_error &) {
        rejected_empty_page_break_line = true;
    }
    Require(rejected_empty_page_break_line, "empty text after a page break was accepted");

    bool rejected_unsplit_page_break = false;
    try {
        static_cast<void>(CompileCppTextInclude(
            "char const gText_UnsplitPageBreak[] =\n"
            "    \"A\\p\" \"B\";\n", map));
    } catch (const std::runtime_error &) {
        rejected_unsplit_page_break = true;
    }
    Require(rejected_unsplit_page_break, "text after a page break stayed on the same source line");

    const std::string generated_inline = CompileCppTextInclude(
        "#include \"test.hh\"\n"
        "struct TestEntry { char name[8]; u32 value; };\n"
        "TestEntry const gTestEntries[] SECTION(\".rodata.test\") = {\n"
        "    { \"A\\n\" \"B\", 3 },\n"
        "};\n"
        "char const gText_TestStandalone[] SECTION(\".rodata.test\") = \"C\";\n", map);
    Require(generated_inline.find("TestEntry const gTestEntries[]") != std::string::npos,
        "structured text source did not preserve its C++ table declaration");
    Require(generated_inline.find("SECTION(\".rodata.test\")") != std::string::npos,
        "structured text source did not preserve its section declaration");
    Require(generated_inline.find("\\x41\\x0A") != std::string::npos
            && generated_inline.find("\\x42") != std::string::npos,
        "structured C++ text bytes are wrong");
    Require(generated_inline.find("gText_TestStandalone") != std::string::npos
            && generated_inline.find("\\x43") != std::string::npos,
        "structured source did not encode a direct text declaration");

    const std::string guide_source =
        "TITLE\n"
        "\"A\"\n"
        "MAIN\n"
        "\"B\"\n"
        "\"A\"\n"
        "\"\"\n"
        "\"\"\n"
        "\"C\"\n"
        "END_FOMT_REFERENCE_GUIDE_PAGE\n";
    GuideTextCatalog guide_catalog;
    AddGuideCatalogSource(guide_catalog, guide_source, map, "example");
    const GuidePageOutput generated_guide = CompileGuidePage(guide_source, "example", map,
        guide_catalog);
    Require(generated_guide.text.find("gText_ReferenceGuide_example_Title[]") != std::string::npos,
        "generated guide title is missing");
    Require(generated_guide.text.find("gText_ReferenceGuide_example_Line01[]") != std::string::npos,
        "generated guide line is missing");
    Require(generated_guide.text.find("gText_ReferenceGuide_example_Line02[]") == std::string::npos,
        "duplicate guide text was not reused");
    Require(generated_guide.text.find("gText_ReferenceGuide_example_Line05[]") != std::string::npos,
        "layout primitives did not preserve the following guide line number");
    Require(generated_guide.text.find("gText_ReferenceGuide_example_Title[4]") == std::string::npos,
        "generated guide text still contains a source byte capacity");
    Require(generated_guide.table.find("gReferenceGuide_example[]") != std::string::npos,
        "generated guide pointer table is missing");
    const std::size_t first_reference = generated_guide.table.find(
        "    gText_ReferenceGuide_example_Title,");
    Require(first_reference != std::string::npos
            && generated_guide.table.find("    gText_ReferenceGuide_example_Title,",
                   first_reference + 1) != std::string::npos,
        "generated guide table did not reuse the first matching text object");

    const std::vector<GuideCollectionPage> grouped_pages = {
        {{"first", 0, true}, {"first", {"A", "B"}}},
        {{"second", 1, false}, {"second", {"C", "A"}}},
    };
    const GuideCollectionOutput grouped = CompileGuideCollection(grouped_pages, map);
    const std::size_t master_table = grouped.source.find("gReferenceGuideTables[]");
    const std::size_t first_text = grouped.source.find("gText_ReferenceGuide_first_Title SECTION");
    const std::size_t second_text = grouped.source.find("gText_ReferenceGuide_second_Title SECTION");
    const std::size_t first_table = grouped.source.find("gReferenceGuide_first[] SECTION");
    const std::size_t second_table = grouped.source.find("gReferenceGuide_second[] SECTION");
    Require(master_table != std::string::npos && first_text != std::string::npos
            && second_text != std::string::npos && first_table != std::string::npos
            && second_table != std::string::npos
            && master_table < first_text && first_text < second_text
            && second_text < first_table && first_table < second_table,
        "auxiliary Reference Guide page did not emit text before both pointer tables");
    const std::size_t master_end = grouped.source.find("};", master_table);
    Require(master_end != std::string::npos
            && grouped.source.substr(master_table, master_end - master_table)
                   .find("gReferenceGuide_second,") == std::string::npos,
        "auxiliary Reference Guide page leaked into the master directory");

    GuideTextCatalog legacy_guide_catalog;
    AddGuideCatalogSource(legacy_guide_catalog,
        "char const gText_ReferenceGuide_Existing[4] =\n"
        "    \"A\";\n", map);
    Require(legacy_guide_catalog.at(map.EncodeText("A"))
            == "gText_ReferenceGuide_Existing",
        "legacy guide text was not included in the guide catalog");

    const std::string generated_rows = CompileCppTextInclude(
        "char const gText_TestRows[2][2] = {\n"
        "    \"A\",\n"
        "    \"B\"\n"
        "};\n", map);
    Require(generated_rows.find("char const gText_TestRows[2][2]") != std::string::npos,
        "generated fixed-row C++ text symbol is missing");
    Require(generated_rows.find("\\x41") != std::string::npos
            && generated_rows.find("\\x42") != std::string::npos,
        "generated fixed-row C++ text bytes are wrong");

    const std::string generated_padded_rows = CompileCppTextInclude(
        "char const gText_TestPaddedRows[2][4] = {\n"
        "    \"A\",\n"
        "    \"B\"\n"
        "};\n", map);
    Require(generated_padded_rows.find("char const gText_TestPaddedRows[2][4]")
            != std::string::npos,
        "generated zero-padded fixed-row C++ text symbol is missing");

    const std::string generated_embedded_terminator = CompileCppTextInclude(
        "char const gText_TestEmbeddedTerminator[1][3] = {\n"
        "    \"A\\x00B\"\n"
        "};\n", map);
    Require(generated_embedded_terminator.find("\\x41\\x00\\x42") != std::string::npos,
        "generated fixed-row C++ text lost its explicit terminator");

    const std::string generated_fixed_width = CompileCppTextInclude(
        "char const gText_TestFixed[4] =\n"
        "    \"A\";\n", map);
    Require(generated_fixed_width.find("char const gText_TestFixed[4]") != std::string::npos,
        "generated fixed-width C++ text declaration is missing");

    bool rejected_overflow = false;
    try {
        static_cast<void>(CompileCppTextInclude(
            "char const gText_TestOverflow[2] =\n"
            "    \"AB\";\n", map));
    } catch (const std::runtime_error &) {
        rejected_overflow = true;
    }
    Require(rejected_overflow, "fixed-width text overflow was accepted");

    bool rejected_unmapped = false;
    try {
        static_cast<void>(map.EncodeText("Z"));
    } catch (const std::runtime_error &) {
        rejected_unmapped = true;
    }
    Require(rejected_unmapped, "unmapped text was accepted");

    const std::string same_unit_source =
        "char const gText_Test[] = \"A\";\n"
        "char const * const gTextRef_Test = gText_Test;\n";
    const std::string same_unit_assembly =
        "\t.globl\tgText_Test\n"
        "gText_Test:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.globl\tgTextRef_Test\n"
        "\t.align\t2, 0\n"
        ".LC0:\n"
        "\t.ascii\t\"A\\000\"\n"
        "\t.align\t2, 0\n"
        "gTextRef_Test:\n"
        "\t.word\t.LC0\n";
    const std::string fixed_same_unit_assembly =
        FixupSameUnitTextReferences(same_unit_source, same_unit_assembly);
    Require(fixed_same_unit_assembly.find(".LC0:") == std::string::npos,
        "same-unit duplicate text constant was retained");
    Require(fixed_same_unit_assembly.find(".word\tgText_Test") != std::string::npos,
        "same-unit text reference was not changed to a named relocation");
}

const char *Usage()
{
    return "usage:\n"
           "  fomt-text self-test\n"
           "  fomt-text validate CHARMAP\n"
           "  fomt-text encode CHARMAP INPUT OUTPUT\n"
           "  fomt-text decode CHARMAP INPUT OUTPUT\n"
           "  fomt-text cpp CHARMAP INPUT OUTPUT\n"
           "  fomt-text fixup-refs SOURCE ASSEMBLY\n"
           "  fomt-text guide CHARMAP INPUT TEXT_OUTPUT TABLE_OUTPUT [CATALOG_SOURCE ...]\n"
           "  fomt-text guide-collection CHARMAP REGION MANIFEST OUTPUT\n"
           "  fomt-text staff-credits CHARMAP REGION BASEROM INPUT OUTPUT\n";
}

int Run(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]) == "self-test") {
        SelfTest();
        std::cout << "fomt-text: self-test passed\n";
        return 0;
    }
    if (argc == 3 && std::string(argv[1]) == "validate") {
        const Charmap charmap = Charmap::Parse(ReadTextFile(argv[2]));
        std::cout << "fomt-text: " << charmap.EntryCount() << " charmap entries validated\n";
        return 0;
    }
    if (argc == 4 && std::string(argv[1]) == "fixup-refs") {
        const std::filesystem::path source = argv[2];
        const std::filesystem::path assembly = argv[3];
        WriteTextFile(assembly, FixupSameUnitTextReferences(
            ReadTextFile(source), ReadTextFile(assembly)));
        return 0;
    }
    if (argc == 6 && std::string(argv[1]) == "guide-collection") {
        const Charmap charmap = Charmap::Parse(ReadTextFile(argv[2]));
        const std::string region = argv[3];
        const std::filesystem::path manifest = argv[4];
        const std::filesystem::path output = argv[5];
        const GuideCollectionOutput generated = CompileGuideCollection(
            ReadGuideCollectionPages(manifest, region), charmap);
        WriteTextFile(output, generated.source);
        return 0;
    }
    if (argc == 7 && std::string(argv[1]) == "staff-credits") {
        const Charmap charmap = Charmap::Parse(ReadTextFile(argv[2]));
        const std::string region = argv[3];
        const std::filesystem::path baserom = argv[4];
        const std::filesystem::path input = argv[5];
        const std::filesystem::path output = argv[6];
        WriteTextFile(output, CompileStaffCredits(ReadTextFile(input), region,
            ReadBinaryFile(baserom), charmap));
        return 0;
    }
    if (argc >= 6 && std::string(argv[1]) == "guide") {
        const Charmap charmap = Charmap::Parse(ReadTextFile(argv[2]));
        const std::filesystem::path input = argv[3];
        const std::filesystem::path text_output = argv[4];
        const std::filesystem::path table_output = argv[5];
        std::vector<std::filesystem::path> catalog_sources;
        for (int index = 6; index < argc; ++index)
            catalog_sources.emplace_back(argv[index]);
        if (catalog_sources.empty())
            catalog_sources.push_back(input);

        const GuideTextCatalog catalog = BuildGuideTextCatalog(charmap, catalog_sources);
        const GuidePageOutput generated = CompileGuidePage(ReadTextFile(input), input.stem().string(),
            charmap, catalog);
        WriteTextFile(text_output, generated.text);
        WriteTextFile(table_output, generated.table);
        return 0;
    }
    if (argc != 5)
        throw std::runtime_error(Usage());

    const Charmap charmap = Charmap::Parse(ReadTextFile(argv[2]));
    const std::filesystem::path input = argv[3];
    const std::filesystem::path output = argv[4];
    const std::string command = argv[1];

    if (command == "encode") {
        std::string text = ReadTextFile(input);
        while (!text.empty() && (text.back() == '\r' || text.back() == '\n'))
            text.pop_back();
        WriteBinaryFile(output, charmap.EncodeText(text));
        return 0;
    }
    if (command == "decode") {
        WriteTextFile(output, charmap.DecodeText(ReadBinaryFile(input)));
        return 0;
    }
    if (command == "cpp") {
        WriteTextFile(output, CompileCppTextInclude(ReadTextFile(input), charmap));
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
        std::cerr << "fomt-text: " << error.what() << '\n';
        return 2;
    }
}
