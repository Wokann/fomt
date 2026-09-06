#ifndef CONTROL_OBJECT_HH
#define CONTROL_OBJECT_HH

#include "prelude.h"

struct ControlObject
{
    void * value;
    u8 unused_04[8];
    u8 byte_0c;
    u8 byte_0d;
    u8 byte_0e;
    u8 byte_0f;
};

#endif // CONTROL_OBJECT_HH
