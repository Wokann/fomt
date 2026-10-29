#include "control_object.hh"

extern "C" void OpenControlWidget(ControlObject & object);
extern "C" void OpenControlWidgetImmediate(ControlObject & object);

EC void func_0803C518(ControlObject & object)
{
    OpenControlWidget(object);
    object.byte_0d = 1;
    object.byte_0f = 1;
}

EC void func_0803C52C(ControlObject & object)
{
    OpenControlWidgetImmediate(object);
    object.byte_0d = 1;
    object.byte_0f = 1;
}
