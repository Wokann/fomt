#include "io.hh"

#include <chrono>
#include <cerrno>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <stdexcept>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#else
#include <unistd.h>
#endif

namespace mary
{

Bytes read_binary(const fs::path &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input)
        throw std::runtime_error("cannot read " + path.u8string());
    Bytes bytes((std::istreambuf_iterator<char>(input)), {});
    if (input.bad())
        throw std::runtime_error("failed reading " + path.u8string());
    return bytes;
}
std::string read_text(const fs::path &path)
{
    auto bytes = read_binary(path);
    for (std::size_t at = 0; at < bytes.size();)
    {
        auto lead = bytes[at++];
        if (lead < 0x80)
            continue;
        unsigned count = lead >= 0xc2 && lead <= 0xdf   ? 1
                         : lead >= 0xe0 && lead <= 0xef ? 2
                         : lead >= 0xf0 && lead <= 0xf4 ? 3
                                                        : 0;
        std::uint32_t value = lead & (count == 1 ? 31 : count == 2 ? 15 : 7);
        if (!count || count > bytes.size() - at)
            throw std::runtime_error("invalid UTF-8 in " + path.u8string());
        auto minimum = count == 1 ? 0x80u : count == 2 ? 0x800u : 0x10000u;
        for (unsigned i = 0; i < count; ++i)
        {
            auto c = bytes[at++];
            if ((c & 0xc0) != 0x80)
                throw std::runtime_error("invalid UTF-8 in " + path.u8string());
            value = (value << 6) | (c & 63);
        }
        if (value < minimum || value > 0x10ffff || (value >= 0xd800 && value <= 0xdfff))
            throw std::runtime_error("invalid UTF-8 in " + path.u8string());
    }
    return std::string(bytes.begin(), bytes.end());
}
void write_binary(const fs::path &path, const Bytes &bytes)
{
    std::ofstream output(path, std::ios::binary | std::ios::trunc);
    if (!output)
        throw std::runtime_error("cannot write " + path.u8string());
    output.write(reinterpret_cast<const char *>(bytes.data()), std::streamsize(bytes.size()));
    output.close();
    if (!output)
        throw std::runtime_error("failed writing " + path.u8string());
}
void write_text(const fs::path &path, const std::string &text)
{
    write_binary(path, Bytes(text.begin(), text.end()));
}
void write_rom_atomically(const fs::path &path, const Bytes &bytes)
{
    auto parent = path.parent_path();
    if (parent.empty())
        parent = ".";
    auto nonce = std::chrono::steady_clock::now().time_since_epoch().count();
    fs::path temporary;
    std::FILE *file = nullptr;
    for (unsigned attempt = 0; attempt < 1000; ++attempt)
    {
        temporary =
            parent / fs::u8path(path.filename().u8string() + ".mary-" + std::to_string(nonce) +
                                "-" + std::to_string(attempt) + ".tmp");
#ifdef _WIN32
        auto descriptor = _wopen(
            temporary.c_str(), _O_WRONLY | _O_CREAT | _O_EXCL | _O_BINARY, _S_IREAD | _S_IWRITE);
        if (descriptor >= 0)
        {
            file = _fdopen(descriptor, "wb");
            if (!file)
            {
                _close(descriptor);
                std::error_code ignored;
                fs::remove(temporary, ignored);
                throw std::runtime_error("cannot open temporary ROM stream");
            }
        }
#else
        file = std::fopen(temporary.c_str(), "wbx");
#endif
        if (file)
            break;
        if (errno != EEXIST)
            throw std::runtime_error("cannot create temporary output: " + temporary.u8string());
    }
    if (!file)
        throw std::runtime_error("cannot allocate a unique temporary output file");
    try
    {
        if (std::fwrite(bytes.data(), 1, bytes.size(), file) != bytes.size() || std::fflush(file))
            throw std::runtime_error("failed writing temporary ROM");
#ifdef _WIN32
        if (_commit(_fileno(file)))
#else
        if (fsync(fileno(file)))
#endif
            throw std::runtime_error("failed synchronizing temporary ROM");
        auto closed = std::fclose(file);
        file = nullptr;
        if (closed)
            throw std::runtime_error("failed closing temporary ROM");
#ifdef _WIN32
        if (!MoveFileExW(temporary.c_str(),
                         path.c_str(),
                         MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH))
            throw std::runtime_error("cannot replace output ROM; Windows error " +
                                     std::to_string(GetLastError()));
#else
        fs::rename(temporary, path);
#endif
    }
    catch (...)
    {
        if (file)
            std::fclose(file);
        std::error_code ignored;
        fs::remove(temporary, ignored);
        throw;
    }
}
std::string assembler_path(const fs::path &path)
{
    std::string out;
    for (auto c : path.generic_u8string())
    {
        if (c == '"')
            out += '\\';
        out += c;
    }
    return out;
}
std::string makefile_path(const fs::path &path)
{
    std::string out;
    for (auto c : path.generic_u8string())
    {
        if (c == '$')
            out += '$';
        if (c == '#' || c == ':' || c == ' ')
            out += '\\';
        out += c;
    }
    return out;
}
std::string hex(std::size_t value, unsigned width)
{
    std::ostringstream text;
    text << std::uppercase << std::hex << std::setfill('0') << std::setw(int(width)) << value;
    return text.str();
}

} // namespace mary
