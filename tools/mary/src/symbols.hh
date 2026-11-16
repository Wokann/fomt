#ifndef MARY_SYMBOLS_HH
#define MARY_SYMBOLS_HH

#include "io.hh"
#include <vector>

namespace mary
{
void generate_symbol_tables(const std::vector<fs::path> &roms, const fs::path &output);
} // namespace mary
#endif
