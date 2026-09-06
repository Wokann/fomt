#include "prelude.h"

// These small adapters forward to the object stored in their first field.
// The concrete owner type has not been recovered yet, so preserve the
// verified pointer-level interface rather than assigning an unsupported name.
EC void func_0805039C(void * object);
EC void func_080503E4(void * object);
EC void func_080503FC(void * object);
EC void func_08050410(void * object);

EC void func_08050D5C(void * const * object)
{
    func_0805039C(*object);
}

EC void func_08050D68(void * const * object)
{
    func_080503E4(*object);
}

EC void func_08050D74(void * const * object)
{
    func_080503FC(*object);
}

EC void func_08050D80(void * const * object)
{
    func_08050410(*object);
}
