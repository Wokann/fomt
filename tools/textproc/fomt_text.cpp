#include <algorithm>
#include <cctype>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
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
                if (byte == 0)
                    throw std::runtime_error("source text cannot embed the reserved 00 terminator");
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
        throw std::runtime_error("line " + std::to_string(line_number) + ": expected one quoted .string literal");
    }

    std::string output;
    for (std::size_t at = 1; at + 1 < literal.size(); ++at) {
        const char character = literal[at];
        if (character != '\\') {
            output.push_back(character);
            continue;
        }

        if (++at + 1 >= literal.size()) {
            throw std::runtime_error("line " + std::to_string(line_number) + ": trailing backslash in .string literal");
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

void EmitCppString(std::ostringstream &output, const std::string &label, const Bytes &bytes)
{
    output << "char const " << label << "[] =\n";
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

std::string CompileCppTextInclude(const std::string &source, const Charmap &charmap)
{
    std::ostringstream output;
    output << "// Generated by fomt-text.  Do not edit.\n\n";
    const std::vector<std::string> includes = ExtractIncludeDirectives(source);
    for (const std::string &include : includes)
        output << include << '\n';
    if (!includes.empty())
        output << '\n';

    std::istringstream lines(source);
    std::string line;
    std::string current_label;
    std::string current_text;
    bool has_current_label = false;
    bool current_has_string = false;
    bool current_string_emitted = false;
    std::size_t line_number = 0;

    const auto EmitCurrentString = [&]() {
        if (!has_current_label || !current_has_string || current_string_emitted)
            return;

        Bytes bytes;
        try {
            bytes = charmap.EncodeText(current_text);
        } catch (const std::runtime_error &error) {
            throw std::runtime_error("text label '" + current_label + "': " + error.what());
        }
        EmitCppString(output, current_label, bytes);
        current_string_emitted = true;
    };

    while (std::getline(lines, line)) {
        ++line_number;
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::string trimmed = Trim(line);
        if (trimmed.empty() || trimmed.rfind("//", 0) == 0 || trimmed.front() == '#')
            continue;

        constexpr char kDeclaration[] = "char const ";
        std::string declaration_line = trimmed;
        if (declaration_line.rfind("extern ", 0) == 0)
            declaration_line = Trim(declaration_line.substr(sizeof("extern ") - 1));
        if (declaration_line.rfind(kDeclaration, 0) == 0) {
            if (has_current_label && !current_string_emitted) {
                throw std::runtime_error("line " + std::to_string(line_number) + ": text label '"
                    + current_label + "' has no terminating semicolon");
            }

            const std::string declaration = Trim(declaration_line.substr(sizeof(kDeclaration) - 1));
            const std::size_t equals = declaration.find('=');
            if (equals == std::string::npos) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": expected '=' in text declaration");
            }
            const std::string array = Trim(declaration.substr(0, equals));
            if (array.size() < 3 || array.substr(array.size() - 2) != "[]") {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": text declaration must use an unsized char array");
            }
            const std::string label = Trim(array.substr(0, array.size() - 2));
            if (!IsValidLabel(label)) {
                throw std::runtime_error("line " + std::to_string(line_number)
                    + ": invalid text label '" + label + "'");
            }

            current_label = label;
            has_current_label = true;
            current_has_string = false;
            current_string_emitted = false;
            current_text.clear();

            const std::string initial_literal = Trim(declaration.substr(equals + 1));
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
            if (!has_current_label || current_string_emitted) {
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

    if (has_current_label && !current_string_emitted) {
        if (!current_has_string)
            throw std::runtime_error("label '" + current_label + "' has no text string");
        throw std::runtime_error("label '" + current_label + "' has no terminating semicolon");
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
    const std::string map_source = "0A=\\n\n0D=\\r\n20= \n41=A\n42=B\n43=C\n";
    const Charmap map = Charmap::Parse(map_source);
    Require(map.EncodeText("A\\nB\\xFE") == Bytes{0x41, 0x0A, 0x42, 0xFE},
        "named controls and explicit bytes do not encode");
    Require(map.DecodeText(Bytes{0x41, 0x0A, 0xFE}) == "A\\n\\xFE",
        "unknown bytes do not round-trip as escapes");

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

    bool rejected_unmapped = false;
    try {
        static_cast<void>(map.EncodeText("Z"));
    } catch (const std::runtime_error &) {
        rejected_unmapped = true;
    }
    Require(rejected_unmapped, "unmapped text was accepted");
}

const char *Usage()
{
    return "usage:\n"
           "  fomt-text self-test\n"
           "  fomt-text validate CHARMAP\n"
           "  fomt-text encode CHARMAP INPUT OUTPUT\n"
           "  fomt-text decode CHARMAP INPUT OUTPUT\n"
           "  fomt-text cpp CHARMAP INPUT OUTPUT\n";
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
