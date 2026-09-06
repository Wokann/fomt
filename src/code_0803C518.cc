#include "control_object.hh"

extern "C" void func_0803BEBC(ControlObject & object);
extern "C" void func_0803BEC8(ControlObject & object);

EC void func_0803C518(ControlObject & object)
{
    func_0803BEBC(object);
    object.byte_0d = 1;
    object.byte_0f = 1;
}

EC void func_0803C52C(ControlObject & object)
{
    func_0803BEC8(object);
    object.byte_0d = 1;
    object.byte_0f = 1;
}
