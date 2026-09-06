#include "prelude.h"

EC void func_08050478(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3);
EC void func_08050664(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2);

EC void func_08050E0C(void * const * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3)
{
    func_08050478(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1, arg_sp2, arg_sp3);
}

EC void func_08050E30(void * const * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2)
{
    func_08050664(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1, arg_sp2);
}
