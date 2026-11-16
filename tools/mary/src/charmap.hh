#ifndef MARY_CHARMAP_HH
#define MARY_CHARMAP_HH

#include "ir.hh"
#include <map>
#include <optional>
#include <set>
#include <string>
#include <string_view>
#include <utility>

namespace mary
{

class Charmap
{
  public:
    // Input contains only the active region's records. Directive selection is
    // separate: a mapped quote or comment delimiter is data, not a C token.
    static Charmap parse(std::string_view source);
    Bytes encode_text(std::string_view text) const;
    std::optional<std::pair<std::size_t, std::string>> decode_one(const Bytes &bytes,
                                                                  std::size_t at = 0) const;
    std::size_t raw_sequence_length(const Bytes &bytes, std::size_t at = 0) const;
    static bool is_named_escape(std::string_view text);

  private:
    std::map<Bytes, std::string> decoding;
    std::map<std::string, Bytes> encoding;
    std::set<std::string> ambiguous;
    std::map<std::uint8_t, std::set<std::size_t>> multibyte_lengths;
    std::size_t max_bytes = 0;
    std::size_t max_text_bytes = 0;
};

} // namespace mary
#endif
