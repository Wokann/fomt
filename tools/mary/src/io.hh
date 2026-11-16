#ifndef MARY_IO_HH
#define MARY_IO_HH

#include "ir.hh"
#include <filesystem>
#include <string>

namespace mary
{
namespace fs = std::filesystem;
Bytes read_binary(const fs::path &path);
std::string read_text(const fs::path &path);
void write_binary(const fs::path &path, const Bytes &bytes);
void write_text(const fs::path &path, const std::string &text);
void write_rom_atomically(const fs::path &path, const Bytes &bytes);
std::string assembler_path(const fs::path &path);
std::string makefile_path(const fs::path &path);
std::string hex(std::size_t value, unsigned width = 0);
} // namespace mary
#endif
