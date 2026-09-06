#include "u16_pair.hh"

extern "C" void func_0803BDE4(U16Pair & value, u32 first, u32 second);
extern "C" void func_0803BDEC(U16Pair & value, u32 first, u32 second);

struct U16PairOwner
{
    U16Pair * value;
};

EC void func_0803BEFC(U16PairOwner & owner, u32 first, u32 second)
{
    func_0803BDE4(*owner.value, first, second);
}

EC void func_0803BF08(U16PairOwner & owner, u32 first, u32 second)
{
    func_0803BDEC(*owner.value, first, second);
}
