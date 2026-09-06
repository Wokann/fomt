#include "prelude.h"

EC void func_08050424(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3);

EC void func_08050D8C(void * const * object, u32 arg_r1)
{
    func_08050424(*object, arg_r1, 0x100, 0);
}

EC void func_08050DA0(void * const * object, u32 arg_r1, u32 arg_r2)
{
    func_08050424(*object, arg_r1, 0x100, arg_r2);
}

EC void func_08050DB4(void * const * object, u32 arg_r1, u16 arg_r2)
{
    func_08050424(*object, arg_r1, arg_r2, 0);
}

EC void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2, u32 arg_r3)
{
    func_08050424(*object, arg_r1, arg_r2, arg_r3);
}
