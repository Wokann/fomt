#include "prelude.h"

struct SignedPairOwner
{
    i16 const * value;
};

EC i32 func_0803BEEC(SignedPairOwner const & owner)
{
    return owner.value[0];
}

EC i32 func_0803BEF4(SignedPairOwner const & owner)
{
    return owner.value[1];
}
