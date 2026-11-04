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
    switch (REG(u8, &REG_VCOUNT)) {
    case 23:
        while ((REG_DISPSTAT & DISPSTAT_HBLANK) == 0) {}
        REG_BG2CNT = BGCNT_PRIORITY(3) | BGCNT_MOSAIC | BGCNT_SCREENBASE(30) | BGCNT_WRAP;
        SetUiVCountCompare(159);
        break;
    case 159:
        REG_BG2CNT = BGCNT_PRIORITY(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(30) | BGCNT_WRAP;
        SetUiVCountCompare(23);
        break;
    }
}

extern "C" void HandleUiVCountInterrupt()
{
    UpdateUiVCount(*gUiVCountContext);
}

UiVCountBinding::UiVCountBinding(UiSceneCore * const & input)
    : value(input), guard(INTR_FLAG_VCOUNT), context(value),
      previous_handler(ExchangeInterruptHandler(2, HandleUiVCountInterrupt))
{
    AcknowledgeAndEnableInterrupts(INTR_FLAG_VCOUNT);
}

UiVCountBinding::~UiVCountBinding()
{
    DisableInterrupts(INTR_FLAG_VCOUNT);
    ExchangeInterruptHandler(2, previous_handler);
}
