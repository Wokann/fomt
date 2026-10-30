#include "prelude.h"

#pragma implementation "ui_vcount.hh"
#include "ui_vcount.hh"
#include "gbaio.h"

extern "C" {
UiSceneCore * const * gUiVCountContext;
}

static inline void SetUiVCountCompare(u16 line)
{
    // Preserve the status bits, then install the next comparison line.
    REG_DISPSTAT &= 0xFF;
    REG_DISPSTAT |= line << 8;
}

extern "C" void UpdateUiVCount(UiSceneCore * core)
{
    // The original handler reads only the low byte of VCOUNT.
    switch (REG(u8, 0x04000006)) {
    case 23:
        while ((REG_DISPSTAT & 2) == 0) {}
        REG_BG2CNT = 0x3E43;
        SetUiVCountCompare(159);
        break;
    case 159:
        REG_BG2CNT = 0x3E41;
        SetUiVCountCompare(23);
        break;
    }
}

extern "C" void HandleUiVCountInterrupt()
{
    UpdateUiVCount(*gUiVCountContext);
}

UiVCountBinding::UiVCountBinding(UiSceneCore * const & input)
    : value(input), guard(4), context(value),
      previous_handler(ExchangeInterruptHandler(2, HandleUiVCountInterrupt))
{
    AcknowledgeAndEnableInterrupts(4);
}

UiVCountBinding::~UiVCountBinding()
{
    DisableInterrupts(4);
    ExchangeInterruptHandler(2, previous_handler);
}
