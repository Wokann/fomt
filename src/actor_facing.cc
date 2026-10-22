#include "actor_facing.hh"

#include "fomt_constants.hh"

extern "C" i32 GetRelativeFacing(i32 facing, i32 relative)
{
    // Relative order is forward, left, right, back. Invalid relative values
    // intentionally fall through to the next outer case, as in the original.
    switch (facing) {
    case FACING_DOWN:
        switch (relative) {
        case 0: return FACING_DOWN;
        case 1: return FACING_RIGHT;
        case 2: return FACING_LEFT;
        case 3: return FACING_UP;
        }
    case FACING_UP:
        switch (relative) {
        case 0: return FACING_UP;
        case 1: return FACING_LEFT;
        case 2: return FACING_RIGHT;
        case 3: return FACING_DOWN;
        }
    case FACING_LEFT:
        switch (relative) {
        case 0: return FACING_LEFT;
        case 1: return FACING_DOWN;
        case 2: return FACING_UP;
        case 3: return FACING_RIGHT;
        }
    case FACING_RIGHT:
        switch (relative) {
        case 0: return FACING_RIGHT;
        case 1: return FACING_UP;
        case 2: return FACING_DOWN;
        case 3: return FACING_LEFT;
        }
    }
    return facing;
}
