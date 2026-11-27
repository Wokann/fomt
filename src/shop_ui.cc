#include "shop_ui.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"asm/gba.inc\"\n"
);

void SetShopMessageText(ShopScreenCore * core, char const * text)
{
    FirstFieldUiOwner & ui = (FirstFieldUiOwner &)core->dialog;

    func_08050EBC(ui, 4);
    func_08050EBC(ui, 8);
    func_08050EBC(ui, 1);
    func_08050EBC(ui, 2);
    func_08050EBC(ui, 0x10);
    func_08050EBC(ui, 0x20);

    func_08050D8C(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(text));
}

asm_unified(
    "    .align 2, 0\n"
);

#include "ui_state.hh"
void SetShopDescriptionText(ShopScreenCore * core, char const * text)
{
    FirstFieldUiOwner & ui = (FirstFieldUiOwner &)core->dialog;
    func_08050E98(ui, 4);
    func_08050E98(ui, 8);
    func_08050E98(ui, 1);
    func_08050E98(ui, 2);
    func_08050E98(ui, 0x10);
    func_08050E98(ui, 0x20);
    func_08050DC8(reinterpret_cast<void * const *>(&ui),
        reinterpret_cast<u32>(text), 0, 0);
}

asm_unified(
    "    .align 2, 0\n"
);

u8 func_080CAC3C(ShopScreenCore const * core)
{
    return core->unk_6A3;
}

asm_unified(
    "    .align 2, 0\n"
);

u8 func_080CAC48(ShopScreenCore const * core)
{
    return core->unk_6A1;
}

asm_unified(
    "    .align 2, 0\n"
);

void SetVCountCompareRegister(void * receiver, u16 line)
{
    REG_DISPSTAT = REG_DISPSTAT & 0xFF;
    REG_DISPSTAT = REG_DISPSTAT | (line << 8);
}

asm_unified(
    "    .align 2, 0\n"
);
