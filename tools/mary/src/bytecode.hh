#ifndef MARY_BYTECODE_HH
#define MARY_BYTECODE_HH

#include "ir.hh"
#include <cstddef>

namespace mary
{

Bytes encode_script(const Script &script);
Script decode_script(const Bytes &riff);
// Backing starts at the RIFF header. Relocated STR entries may extend beyond it.
Script decode_script(const Bytes &riff, const Bytes &backing);
std::uint32_t read_u32(const Bytes &data, std::size_t offset);

} // namespace mary
#endif
