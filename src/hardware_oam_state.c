#include "hardware_oam_state.hh"
#include "hardware_display_output.hh"
#include "gbasvc.h"

void func_08009834(void * object)
{
    u8 * bytes = (u8 *)object;
    u8 old_count = bytes[0];
    u8 new_count = bytes[1];
    if (old_count > new_count) {
        u8 * entry = bytes + 4 + (new_count << 3);
        u8 * end = bytes + 4 + (old_count << 3);
        do {
            entry[1] = 2;
            entry += 8;
        } while (entry != end);
    }
    bytes[0] = new_count;
    bytes[2] = bytes[3];
}

void func_08009864(void * object)
{
    func_0800977C(object);
    func_08009834(object);
}

void func_08009878(void * object)
{
    CpuFastSet((u8 *)object + 4, (void *)0x07000000, 0x100);
    func_08009834(object);
}

void func_08009898(void * object)
{
    func_080097A4(object);
    func_08009834(object);
}
