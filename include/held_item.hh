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

        u16 unk_k5_02;
    };

    Kind kind : 3;
    bool wrapped : 1;
    STRUCT_PAD(0x01, 0x02);
    Inner inner;
};

typedef char HeldItemSizeCheck[sizeof(HeldItem) == 8 ? 1 : -1];
typedef char HeldItemPayloadCheck[offsetof(HeldItem, inner) == 2 ? 1 : -1];

EC bool IsHeldItemEmpty(HeldItem const * self);
EC RucksackItem func_0800F294(HeldItem const * self);
EC void ClearHeldItem(HeldItem * self);
// A missing, wrong-kind or out-of-range chicken slot returns -1.
EC int GetHeldChickenSlot(HeldItem const * self);
// Preserve the native modulo-eight selection, rather than clamping the slot.
EC void SetHeldChickenSlot(HeldItem * self, fu8 slot);
EC void func_0800F418(HeldItem * self, RucksackItem rucksack_item);

#endif // HELD_ITEM_HH
