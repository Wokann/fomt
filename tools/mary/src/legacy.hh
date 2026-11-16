#ifndef MARY_LEGACY_HH
#define MARY_LEGACY_HH

#include "mary_c.hh"

namespace mary
{
struct LegacyContext
{
    ConstScope scope;
    std::vector<NamedScript> scripts;
};
LegacyContext parse_legacy(std::string_view source,
                           const Charmap *map = nullptr,
                           const ConstScope &scope = {},
                           bool allow_scripts = true);
} // namespace mary
#endif
