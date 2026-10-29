#ifndef CONTROL_OBJECT_HH
#define CONTROL_OBJECT_HH

#include "control_widget.hh"

#pragma interface "control_object.hh"

struct ControlObject : ControlWidget {
    ControlObject(u32 background, u32 screen, u32 palette, u32 mode, u32 unk_0c);
    virtual ~ControlObject();
    virtual void Open() SECTION(".text.control_object_callbacks");
    virtual void OpenImmediate() SECTION(".text.control_object_callbacks");
    u32 GetUnk0C() const SECTION(".text.control_object_callbacks");
    void ClearUnk0F() SECTION(".text.control_object_callbacks");
    void * unk_08;
    u8 byte_0c;
    u8 byte_0d;
    u8 byte_0e;
    u8 byte_0f;
};

typedef char ControlObjectSizeCheck[sizeof(ControlObject) == 16 ? 1 : -1];
typedef char ControlObjectPayloadCheck[offsetof(ControlObject, unk_08) == 8 ? 1 : -1];
typedef char ControlObjectFlagsCheck[offsetof(ControlObject, byte_0c) == 12 ? 1 : -1];

#pragma implementation
#endif // CONTROL_OBJECT_HH
