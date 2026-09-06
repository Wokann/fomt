#include "prelude.h"

struct PointerOwner
{
    void * value;
};

extern "C" u32 func_0803BAAC(void * value);
extern "C" void func_0803BCF8(void * value);
extern "C" void func_0803BD60(void * value);

EC u32 func_0803BEB0(PointerOwner & owner)
{
    return func_0803BAAC(owner.value);
}

EC void func_0803BEBC(PointerOwner & owner)
{
    func_0803BCF8(owner.value);
}

EC void func_0803BEC8(PointerOwner & owner)
{
    func_0803BD60(owner.value);
}
