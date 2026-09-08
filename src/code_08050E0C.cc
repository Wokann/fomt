#include "ui_text_layout.hh"

EC void func_08050478(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3);
EC void func_08050664(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2);

UiTextLayoutPositionTable const gUiTextLayoutPositionTable = {
    0x00,
    {
        { 0x08, 0x09, 0x00, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x40, 0x41, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x42 },
        { 0x09, 0x0A, 0x00, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x42, 0x00, 0x00 },
    },
};

EC void func_08050E0C(void * const * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3)
{
    func_08050478(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1, arg_sp2, arg_sp3);
}

EC void func_08050E30(void * const * object, u32 arg_r1, u32 arg_r2, u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2)
{
    func_08050664(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1, arg_sp2);
}
