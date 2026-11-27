#ifndef HELD_ITEM_HH
#define HELD_ITEM_HH

#include "prelude.h"
#include "fomt_constants.hh"

#include "rucksack_item.hh"

struct HeldItem
{
    HeldItem();

    // The saved three-bit kind excludes Mary's -1 API sentinel. Keeping
    // only 0..5 in this enum preserves the native unsigned bit-field reads.
    enum Kind
    {
        KIND_FOOD = HELD_ITEM_KIND_FOOD,
        KIND_ARTICLE = HELD_ITEM_KIND_ARTICLE,
        KIND_DOG = HELD_ITEM_KIND_DOG,
        KIND_CHICKEN = HELD_ITEM_KIND_CHICKEN,
        KIND_BASKET = HELD_ITEM_KIND_BASKET,
        KIND_ACTOR_GRAPHIC = HELD_ITEM_KIND_ACTOR_GRAPHIC,
    };

    Kind GetKind() const;
    Article GetArticle() const;

    union PACKED Inner
    {
        struct
        {
            u8 id;
            i8 stamina_bonus;
            i8 fatigue_bonus;
        } food;

        struct
        {
            u8 id;
        } article;

        struct
        {
            u8 slot;
        } chicken;

        u16 actor_graphic_index;
    };

    Kind kind : 3;
    bool wrapped : 1;
    STRUCT_PAD(0x01, 0x02);
    Inner inner;
};


EC bool IsHeldItemEmpty(HeldItem const * self);
EC Food func_0800F20C(HeldItem const * self);
EC RucksackItem func_0800F294(HeldItem const * self);
EC bool func_0800F388(HeldItem const * self);
EC bool func_0800F528(HeldItem * self);
EC void ClearHeldItem(HeldItem * self);
EC void func_0800F3B0(HeldItem * self, Food food);
EC void func_0800F3E8(HeldItem * self, Article article);
// A missing, wrong-kind or out-of-range chicken slot returns -1.
EC int GetHeldChickenSlot(HeldItem const * self);
EC int GetHeldActorGraphicIndex(HeldItem const * self);
// Preserve the native modulo-eight selection, rather than clamping the slot.
EC void SetHeldChickenSlot(HeldItem * self, fu8 slot);
EC void func_0800F418(HeldItem * self, RucksackItem rucksack_item);
EC void func_0800F510(HeldItem * self, int graphic);

#endif // HELD_ITEM_HH
