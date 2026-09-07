#ifndef FARM_HOUSE_HH
#define FARM_HOUSE_HH

#include "prelude.h"

#include "furniture.hh"
#include "unknown_types.hh"

struct FarmHouse
{
    FarmHouse();

    u32 GetUpgradeLevel() const;
    Fridge const * GetFridge() const;
    Shelf const * GetShelf() const;
    RecordPlayer const * GetRecordPlayer() const;
    u32 GetWindowStyle() const;
    u32 GetMailboxStyle() const;
    u32 GetDoghouseStyle() const;
    bool HasBathroom() const;
    bool HasLargeBed() const;
    bool HasCarpet() const;
    bool HasVase() const;
    u32 GetVaseArticleId() const;
    bool HasMirror() const;
    bool HasClock() const;
    bool HasStocking() const;
    bool IsFireplaceLighted() const;
    bool HasKitchen() const;
    bool HasKitchenKnife() const;
    bool HasKitchenFryingPan() const;
    bool HasKitchenPot() const;
    bool HasKitchenMixer() const;
    bool HasKitchenWhisk() const;
    bool HasKitchenRollingPin() const;
    bool HasKitchenOven() const;
    bool HasKitchenSeasoningSet() const;
    u32 GetStockingArticleId() const;
    void UpgradeHouseLevel();
    Fridge * GetFridge();
    Shelf * GetShelf();
    RecordPlayer * GetRecordPlayer();
    void SetWindowStyle(u32 style_id);
    void SetMailboxStyle(u32 style_id);
    void SetDoghouseStyle(u32 style_id);
    void AddBathroom();
    void AddFridge();
    void AddShelf();
    void AddRecordPlayer();
    void AddLargeBed();
    void AddCarpet();
    void AddVase();
    void SetVaseArticleId(u32 article_id);
    void AddMirror();
    void AddClock();
    void AddStocking();
    void RemoveStocking();
    void LightFireplace();
    void AddKitchen();
    void AddKitchenKnife();
    void AddKitchenFryingPan();
    void AddKitchenPot();
    void AddKitchenMixer();
    void AddKitchenWhisk();
    void KitchenRollingPin();
    void AddKitchenOven();
    void AddKitchenSeasoningSet();
    void SetStockingArticleId(u32 article_id);
    void DayUpdate(Season season);

    /* +000 */ u32 upgrade_level : 2;
    /* +000 */ u32 window_style : 2;
    /* +000 */ u32 mailbox_style : 2;
    /* +000 */ u32 doghouse_style : 2;
    /* +001 */ bool has_bathroom : 1;
    /* +001 */ bool has_fridge : 1;
    /* +001 */ bool has_shelf : 1;
    /* +001 */ bool has_record_player : 1;
    /* +001 */ bool has_large_bed : 1;
    /* +001 */ bool has_carpet : 1;
    /* +001 */ bool has_vase : 1;
    /* +001 */ u32 vase_article_id : 8;
    /* +002 */ u32 vase_article_lifespan : 4;
    /* +003 */ bool has_mirror : 1;
    /* +003 */ bool has_clock : 1;
    /* +003 */ bool has_stocking : 1;
    /* +003 */ u32 stocking_article_id : 8;
    /* +004 */ bool fireplace_lighted : 1;
    /* +004 */ bool has_kitchen : 1;
    /* +005 */ bool has_kitchen_knife : 1;
    /* +005 */ bool has_kitchen_frying_pan : 1;
    /* +005 */ bool has_kitchen_pot : 1;
    /* +005 */ bool has_kitchen_mixer : 1;
    /* +005 */ bool has_kitchen_whisk : 1;
    /* +005 */ bool has_kitchen_rolling_pin : 1;
    /* +005 */ bool has_kitchen_oven : 1;
    /* +005 */ bool has_kitchen_seasoning_set : 1;
    /* +008 */ Fridge fridge;
    /* +108 */ Shelf shelf;
    /* +188 */ RecordPlayer record_player;
    /* +18C */ ToolChest tool_chest;
    /* +20C */ Unk_0800BC58 unk;
};

// func_080A5AB0 reads the destination tile and source pointer from these
// records.  The two bytes after destination_tile are compiler alignment for
// the pointer, not an independently meaningful ROM field.
struct FarmHouseTilePatchDescriptor
{
    u16 destination_tile;
    u8 const * frame_data;
};

// Callers additionally read frame_count at +0x08.  As above, both the
// pointer alignment and tail alignment are natural structure padding.
struct FarmHouseTilePatchAnimationDescriptor
{
    u16 destination_tile;
    u8 const * frame_data;
    u16 frame_count;
};

// The numeric group names deliberately describe only the four physically
// contiguous ROM groups.  The still-native callers do not prove a stronger
// gameplay-specific subdivision yet.
struct FarmHouseTilePatchData
{
    FarmHouseTilePatchDescriptor group0[7];
    FarmHouseTilePatchAnimationDescriptor animation_group0[4];
    FarmHouseTilePatchDescriptor group1[3];
    FarmHouseTilePatchAnimationDescriptor animation_group1[14];
};

extern FarmHouseTilePatchData const gFarmHouseTilePatchData;

#endif // FARM_HOUSE_HH
