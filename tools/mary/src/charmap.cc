#include "charmap.hh"

#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace mary
{
namespace
{

bool blank(std::string_view value)
{
    return std::all_of(
        value.begin(), value.end(), [](unsigned char c) { return std::isspace(c) != 0; });
}

unsigned hex(char c)
{
    if (c >= '0' && c <= '9')
        return unsigned(c - '0');
    if (c >= 'a' && c <= 'f')
        return unsigned(c - 'a') + 10;
    if (c >= 'A' && c <= 'F')
        return unsigned(c - 'A') + 10;
    throw std::runtime_error("invalid hexadecimal byte sequence in charmap");
}

bool continuation(unsigned char c)
{
    return (c & 0xc0) == 0x80;
}

} // namespace

Charmap Charmap::parse(std::string_view source)
{
    Charmap result;
    std::size_t line = 0;
    while (!source.empty())
    {
        ++line;
        auto end = source.find('\n');
        auto record = source.substr(0, end);
        source = end == std::string_view::npos ? std::string_view{} : source.substr(end + 1);
        if (!record.empty() && record.back() == '\r')
            record.remove_suffix(1);
        auto first = record.find_first_not_of(" \t\r");
        if (blank(record) || (first != std::string_view::npos && record[first] == '#'))
            continue;
        try
        {
            auto eq = record.find('=');
            if (eq == std::string_view::npos)
                throw std::runtime_error("expected HEX=TEXT");
            auto key = record.substr(0, eq), text = record.substr(eq + 1);
            if (key.empty() || key.size() % 2)
                throw std::runtime_error("invalid hexadecimal key");
            // Empty slots are legal but still require a valid hexadecimal key.
            Bytes bytes;
            for (std::size_t i = 0; i < key.size(); i += 2)
                bytes.push_back(std::uint8_t(hex(key[i]) * 16 + hex(key[i + 1])));
            if (text.empty())
                continue;
            if (std::find(bytes.begin(), bytes.end(), 0) != bytes.end())
                throw std::runtime_error("mapping contains reserved STR terminator 00");
            auto value = std::string(text);
            if (!result.decoding.emplace(bytes, value).second)
                throw std::runtime_error("byte sequence is defined more than once");
            if (!result.encoding.emplace(value, bytes).second)
                result.ambiguous.insert(value);
            result.max_bytes = std::max(result.max_bytes, bytes.size());
            result.max_text_bytes = std::max(result.max_text_bytes, text.size());
            if (bytes.size() > 1)
                result.multibyte_lengths[bytes.front()].insert(bytes.size());
        }
        catch (const std::runtime_error &e)
        {
            throw std::runtime_error("charmap line " + std::to_string(line) + ": " + e.what());
        }
    }
    return result;
}

Bytes Charmap::encode_text(std::string_view text) const
{
    Bytes result;
    for (std::size_t at = 0; at < text.size();)
    {
        bool matched = false;
        for (auto size = std::min(max_text_bytes, text.size() - at); size; --size)
        {
            // UTF-8 character boundaries give the same order as longest
            // Unicode-scalar matching, without converting the whole string.
            if (at + size < text.size() &&
                continuation(static_cast<unsigned char>(text[at + size])))
                continue;
            auto found = encoding.find(std::string(text.substr(at, size)));
            if (found == encoding.end())
                continue;
            result.insert(result.end(), found->second.begin(), found->second.end());
            at += size;
            matched = true;
            break;
        }
        if (!matched)
        {
            auto end = at + 1;
            while (end < text.size() && continuation(static_cast<unsigned char>(text[end])))
                ++end;
            throw std::runtime_error("text contains an unmapped character: '" +
                                     std::string(text.substr(at, end - at)) + "'");
        }
    }
    return result;
}

std::optional<std::pair<std::size_t, std::string>> Charmap::decode_one(const Bytes &bytes,
                                                                       std::size_t at) const
{
    if (at > bytes.size())
        throw std::out_of_range("charmap byte offset");
    for (auto count = std::min(max_bytes, bytes.size() - at); count; --count)
    {
        auto found = decoding.find(Bytes(bytes.begin() + at, bytes.begin() + at + count));
        if (found != decoding.end() && !ambiguous.count(found->second))
            return std::make_pair(count, found->second);
    }
    return std::nullopt;
}

std::size_t Charmap::raw_sequence_length(const Bytes &bytes, std::size_t at) const
{
    if (at > bytes.size())
        throw std::out_of_range("charmap byte offset");
    const auto remaining = bytes.size() - at;
    if (!remaining)
        return 0;
    for (auto count = std::min(max_bytes, remaining); count > 1; --count)
        if (decoding.count(Bytes(bytes.begin() + at, bytes.begin() + at + count)))
            return count;
    auto lengths = multibyte_lengths.find(bytes[at]);
    if (lengths != multibyte_lengths.end())
        for (auto length : lengths->second)
            if (length <= remaining)
                return length;
    return 1;
}

bool Charmap::is_named_escape(std::string_view text)
{
    if (text.empty() || text.front() != '\\' || text.size() < 2)
        return false;
    for (std::size_t i = 2; i < text.size(); ++i)
        if (!continuation(static_cast<unsigned char>(text[i])))
            return false;
    return true;
}

} // namespace mary
