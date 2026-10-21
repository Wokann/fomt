#ifndef FARM_HH
#define FARM_HH

#include "prelude.h"

#include "utility/fixed_str.hh"
#include "horse.hh"
#include "shipping_bin.hh"
#include "farm_house.hh"
#include "barn.hh"
#include "coop.hh"
#include "field.hh"

struct Farm
{
    // clang-format off

    enum { FIELD_WIDTH = 43 };
    enum { FIELD_HEIGHT = 25 };

    enum { MAX_UNK_0010_0 = 999 };

    // clang-format on

    // Optional horse storage is copied word-by-word even when unoccupied.
    typedef u32 HorseStorage[(sizeof(Horse) + sizeof(u32) - 1) / sizeof(u32)];

    Farm(char const * name);
    Farm(Farm const & other);

    static Vec2 smethod_08009ADC();
    static Vec2 smethod_08009AE8();

    char const * GetName() const;
    u32 GetUnk10() const;
    Horse const * GetHorse() const;
    bool GetUnkFlag11() const;
    bool method_08009B20() const;
    bool GetUnkFlag12() const;

    void method_08009B68(u32 added);
    void method_08009BAC(u32 taken);
    void SetHorse(Horse const & horse);
    Horse * GetHorse();
    void RemoveHorse();
    void method_08009C60();
    void DayUpdate(int weather, GameDate const & date);
    void method_08009F80();

    /* +0000 */ FixedStr<12> name;
    /* +0010 */ u32 unk_0010_0 : 10;
    /* +0010 */ bool has_horse : 1;
    /* +0010 */ bool unk_0010_11 : 1;
    /* +0010 */ bool unk_0010_12 : 1;
    /* +0014 */ HorseStorage horse_storage;
    /* +0040 */ ShippingBin shipping_bin;
    /* +01E0 */ FarmHouse farm_house;
    /* +03FC */ Coop coop;
    /* +05DC */ Barn barn;
    /* +09C8 */ Field<FIELD_WIDTH, FIELD_HEIGHT> field;
};

typedef char FarmHorseStorageSizeCheck[sizeof(Farm::HorseStorage) == 0x2C ? 1 : -1];
typedef char FarmHorseStorageOffsetCheck[offsetof(Farm, horse_storage) == 0x14 ? 1 : -1];
typedef char FarmShippingBinOffsetCheck[offsetof(Farm, shipping_bin) == 0x40 ? 1 : -1];
typedef char FarmCoopOffsetCheck[offsetof(Farm, coop) == 0x3FC ? 1 : -1];
typedef char FarmBarnOffsetCheck[offsetof(Farm, barn) == 0x5DC ? 1 : -1];
typedef char FarmFieldOffsetCheck[offsetof(Farm, field) == 0x9C8 ? 1 : -1];
typedef char FarmSizeCheck[sizeof(Farm) == 0x1A94 ? 1 : -1];

#endif // FARM_HH
