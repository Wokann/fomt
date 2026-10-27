#include "game_world.hh"
#include "game_state.hh"
#include "game_scene.hh"
#if defined(REGION_JP)
#include "data/scripts/jp/fomt_scripts.mary.h"
#elif defined(REGION_US)
#include "data/scripts/us/fomt_scripts.mary.h"
#elif defined(REGION_EU)
#include "data/scripts/eu/fomt_scripts.mary.h"
#else
#include "data/scripts/de/fomt_scripts.mary.h"
#endif

void GameSceneWorldPrefix::ShipProduct(Product const & product)
{
    ShippingBin & shipping = save->farm.shipping_bin;
    i32 product_id = product.GetId();
    u32 previous = shipping.IsDisplayEnabled(product_id)
        ? shipping.GetAmountShipped(product_id) : 0;
    shipping.Ship(product);
    u32 count = shipping.GetAmountShipped(product_id);
    if (previous < count) {
        switch (count) {
        case 10000:
            QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Shipping_10000Items, product_id), 1);
            break;
        case 100000:
            QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Shipping_100000Items, product_id), 1);
            break;
        case 1000000:
            QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Shipping_1000000Items, product_id), 1);
            break;
        case 10000000:
            QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Shipping_10000000Items, product_id), 1);
            break;
        case 100000000:
            QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Shipping_100000000Items, product_id), 1);
            break;
        case 1000000000:
            QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Shipping_1000000000Items, product_id), 1);
            break;
        }
    }
    if (save->event_state.achievement_shipped_every_item_kind_state == 0
        && shipping.HasShippedOneOfEachProduct()) {
        QueueScript(GameSceneScriptRequest(
            EventScript_AchievementEvent_Shipping_EveryItemKind, 0), 1);
    }
}
