#include "prelude.h"
#include "control_widget.hh"
#pragma implementation "control_object.hh"
#include "control_object.hh"

void ControlObject::Open()
{
    ControlWidget::Open();
    byte_0d = 1;
    byte_0f = 1;
}

void ControlObject::OpenImmediate()
{
    ControlWidget::OpenImmediate();
    byte_0d = 1;
    byte_0f = 1;
}

u32 ControlObject::GetUnk0C() const
{
    return byte_0c;
}

void ControlObject::ClearUnk0F()
{
    byte_0f = 0;
}
