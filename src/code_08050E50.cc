#include "prelude.h"

// The wrapper's only recovered layout fact is the owned pointer in its first
// field.  Each adapter forwards that pointer and preserves the original
// argument registers for the underlying UI-adjacent implementation.
EC void func_08050AD8(void * object, u32 arg_r1);
EC void func_08050B3C(void * object);
EC void func_08050B50(void * object, char const * text);
EC void func_08050C18(void * object);
EC void func_08050C2C(void * object, u32 arg_r1);
EC void func_08050C64(void * object);

EC void func_08050E50(void * const * object, u32 arg_r1)
{
    func_08050AD8(*object, arg_r1);
}

EC void func_08050E5C(void * const * object)
{
    func_08050B3C(*object);
}

EC void func_08050E68(void * const * object, char const * text)
{
    func_08050B50(*object, text);
}

EC void func_08050E74(void * const * object)
{
    func_08050C18(*object);
}

EC void func_08050E80(void * const * object, u32 arg_r1)
{
    func_08050C2C(*object, arg_r1);
}

EC void func_08050E8C(void * const * object)
{
    func_08050C64(*object);
}
