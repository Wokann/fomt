#ifndef FARMER_HH
#define FARMER_HH

#include "prelude.h"

#include "utility/fixed_str.hh"
#include "unknown_types.hh" // GameDate
#include "actor.hh"
#include "item.hh"
#include "held_item.hh"
#include "rucksack.hh"

struct Farmer
{
    struct ToolLevel
    {
        enum
        {
            LEVEL_0,
            LEVEL_1,
            LEVEL_2,
            LEVEL_3,
            LEVEL_4,
            LEVEL_5,
        };

        ToolLevel();

        u32 unk_000 : 16;
        u32 unk_010 : 3;
        u32 unk_013 : 3;
    };

    enum
    {
        MAX_COUNT_STEPS = 1000000000
    };

    Farmer(char const * player_name, GameDate const & birth_date);
    Farmer(Farmer const & other);

    char const * GetName() const;
    ActorLocation GetLocation() const;
    char const * GetSpouseNickname() const;
    GameDate GetBirthday() const;
    Tool GetUpgradedTool(Tool tool) const;
    u32 GetStepCount() const;
    void RecordPedometerStep();
    // The limit is twelve encoded bytes, not twelve Unicode characters.
    void SetSpouseNickname(char const * value);

    FixedStr<12> name;
    FixedStr<12> spouse_nickname;
    GameDate birthday;
    ActorLocation location;
    ToolLevel unk_2C[6]; /* tool level */
    u32 num_power_berries : 4;
    bool unk_44_04 : 1; /* ate_mysterious_berry? */
    bool unk_44_05 : 1;
    bool unk_44_06 : 1;
    u32 stamina : 8;
    u32 unk_44_0F : 8; /* fatigue? */
    u32 unk_44_17 : 8;
    u32 step_count : 30;
    u32 unk_48_1D : 3;
    u32 unk_4C_00 : 7;
    u32 deepest_mine_floor : 8;
    u32 unk_4C_0F : 30;
    u32 unk_50_0D : 3;
    HeldItem unk_54;  /* held item? */
    ToolStack unk_5C; /* held tool? */
    Rucksack rucksack;
};

typedef char FarmerNameOffsetCheck[offsetof(Farmer, name) == 0 ? 1 : -1];
typedef char FarmerSpouseNicknameOffsetCheck[offsetof(Farmer, spouse_nickname) == 0x10 ? 1 : -1];
typedef char FarmerBirthdayOffsetCheck[offsetof(Farmer, birthday) == 0x20 ? 1 : -1];

typedef char FarmerToolLevelSizeCheck[sizeof(Farmer::ToolLevel) == 4 ? 1 : -1];
typedef char FarmerHeldItemOffsetCheck[offsetof(Farmer, unk_54) == 0x54 ? 1 : -1];
typedef char FarmerRucksackOffsetCheck[offsetof(Farmer, rucksack) == 0x60 ? 1 : -1];
typedef char FarmerSizeCheck[sizeof(Farmer) == 0x98 ? 1 : -1];

/* Farmer methods */
EC unsigned int func_0800E4F0(Farmer const & self);
EC unsigned int func_0800E4FC(Farmer const & self);
EC bool func_0800E504(Farmer const & self);
EC unsigned int func_0800E51C(Farmer const & self);
EC unsigned int func_0800E530(Farmer const & self);
EC bool func_0800E53C(Farmer const & self);
EC Farmer::ToolLevel const & func_0800E548(Farmer const & self, unsigned int idx);
EC bool func_0800E934(Farmer const & self);
EC bool func_0800E940(Farmer const & self);
EC unsigned int func_0800E94C(Farmer const & self);
EC unsigned int func_0800E970(Farmer const & self);
EC unsigned int GetDeepestMineFloor(Farmer const & self);
EC unsigned int func_0800E988(Farmer const & self);
EC unsigned int func_0800E9A0(Farmer const & self);
EC void func_0800E9E4(Farmer & self, int increase);
EC void func_0800EA38(Farmer & self, int decrease);
EC void func_0800EA44(Farmer & self);
EC void func_0800EA68(Farmer & self, int arg_1);
EC void func_0800EAD4(Farmer & self, int decrease);
EC void func_0800EAE0(Farmer & self);
EC void func_0800EAF0(Farmer & self);
EC void func_0800EAFC(Farmer & self);
EC Farmer::ToolLevel & func_0800EB2C(Farmer & self, int idx);
EC void func_0800EB34(Farmer & self, ActorLocation const & location);
EC unsigned int func_0800EB3C(Farmer & self);
EC unsigned int func_0800EBC4(Farmer & self);
EC unsigned int func_0800EC4C(Farmer & self);
EC unsigned int func_0800ECB0(Farmer & self);
EC void func_0800ED14(Farmer & self);
EC void func_0800ED20(Farmer & self);
EC void func_0800ED2C(Farmer & self);
EC void func_0800ED3C(Farmer & self, unsigned int arg_1);
EC void func_0800ED54(Farmer & self, int arg_1);
EC bool func_0800EE2C(Farmer & self);
EC void func_0800EE60(Farmer & self);
EC bool UpdateDeepestMineFloor(Farmer & self, unsigned int floor);
EC void func_0800EEF8(Farmer & self);

/* Farmer::ToolLevel methods */
EC unsigned int func_0800EF68(Farmer::ToolLevel const & self);
EC unsigned int func_0800EF6C(Farmer::ToolLevel const & self);
EC bool func_0800EF74(Farmer::ToolLevel const & self);
EC void func_0800EF88(Farmer::ToolLevel & self, int arg_1);
EC void func_0800EFB4(Farmer::ToolLevel & self, unsigned int arg_1);
EC void func_0800EFD8(Farmer::ToolLevel & self);

#endif // FARMER_HH
