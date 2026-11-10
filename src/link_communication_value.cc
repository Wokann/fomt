#include "link_communication_value.hh"

void LinkCommunicationValue::Set(u8 first, u16 word)
{
    prefix.word = first;
    value[0] = word;
    value[1] = word >> 8;
}

void LinkCommunicationValue::Set(u8 first, u8 second, u8 const * bytes)
{
    prefix.bytes[0] = first;
    prefix.bytes[1] = second;
    value[0] = bytes[0];
    value[1] = bytes[1];
}

u8 LinkCommunicationValue::GetByte0() const
{
    return prefix.bytes[0];
}

u16 LinkCommunicationValue::GetValue() const
{
    return value[0] | (value[1] << 8);
}

u8 LinkCommunicationValue::GetByte1() const
{
    return prefix.bytes[1];
}

void LinkCommunicationValue::CopyValue(u8 * destination) const
{
    destination[0] = value[0];
    destination[1] = value[1];
}

u16 LinkCommunicationValue::GetPrefix() const
{
    return prefix.bytes[0] | (prefix.bytes[1] << 8);
}

bool LinkCommunicationValue::HasValue(u8 const * bytes) const
{
    bool result = false;
    if (bytes[0] == value[0] && bytes[1] == value[1])
        result = true;
    return result;
}
