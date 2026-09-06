#include "prelude.h"

struct PointerOwner
{
    void * value;
};

extern "C" void func_0803BD88(void * value);
extern "C" void func_0803BDB8(void * value);

EC void func_0803BED4(PointerOwner & owner)
{
    func_0803BD88(owner.value);
}

EC void func_0803BEE0(PointerOwner & owner)
{
    func_0803BDB8(owner.value);
}
