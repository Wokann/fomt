#ifndef LINK_COMMUNICATION_VALUE_HH
#define LINK_COMMUNICATION_VALUE_HH

#include "prelude.h"

// A serialized two-byte prefix and two payload bytes. The native API
// exposes both halfword and byte views of the prefix. Its protocol
// meaning is still unknown; do not impose halfword alignment on the record.
struct PACKED LinkCommunicationValue
{
    union PACKED {
        u16 word;
        u8 bytes[2];
    } prefix;
    u8 value[2];

    void Set(u8 first, u16 word);
    void Set(u8 first, u8 second, u8 const * bytes);
    u8 GetByte0() const;
    u16 GetValue() const;
    u8 GetByte1() const;
    void CopyValue(u8 * destination) const;
    u16 GetPrefix() const;
    bool HasValue(u8 const * bytes) const;
};




#endif // LINK_COMMUNICATION_VALUE_HH
