#include "player_collection_events.hh"

#include "player_actor.hh"
#include "game_state.hh"
#include "game_scene.hh"
#include "entity_ui.hh"
#if defined(REGION_JP)
#include "data/scripts/jp/fomt_scripts.mary.h"
#elif defined(REGION_US)
#include "data/scripts/us/fomt_scripts.mary.h"
#elif defined(REGION_EU)
#include "data/scripts/eu/fomt_scripts.mary.h"
#else
#include "data/scripts/de/fomt_scripts.mary.h"
#endif

void CheckPlayerCollectionEvents(PlayerActor const & player)
{
    if (player.save_image->mine_floor.CountHarvestGoddessJewels() == 9
        && player.save_image->event_state.harvest_goddess_jewel_exchange_state == EVENT_LIFECYCLE_NOT_STARTED
        && player.farmer->held_item.GetKind() == HeldItem::KIND_ARTICLE
        && player.farmer->held_item.GetArticle().GetId() == ITEM_ARTICLE_HARVEST_GODDESS_JEWEL) {
        player.game_object->QueueScript(GameSceneScriptRequest(
            EventScript_AchievementEvent_Collection_HarvestGoddessJewelsExchange, 0), 0);
    }
    if (player.save_image->mine_floor.CountKappaJewels() == 9
        && player.save_image->event_state.kappa_jewel_exchange_state == EVENT_LIFECYCLE_NOT_STARTED
        && player.farmer->held_item.GetKind() == HeldItem::KIND_ARTICLE
        && player.farmer->held_item.GetArticle().GetId() == ITEM_ARTICLE_KAPPA_JEWEL) {
        player.game_object->QueueScript(GameSceneScriptRequest(
            EventScript_AchievementEvent_Collection_KappaJewelsExchange, 0), 0);
    }
    if (player.save_image->event_state.achievement_collected_every_spring_mine_item_state == ACHIEVEMENT_EVENT_NOT_REACHED) {
        bool all_shipped = true;
        for (u32 i = 0; i < ARRAY_COUNT(gSpringMineCollectionProducts); ++i) {
            if (!player.save_image->farm.shipping_bin.IsDisplayEnabled(gSpringMineCollectionProducts[i])) {
                all_shipped = false;
                break;
            }
        }
        if (all_shipped
            && player.save_image->mine_floor.GetFlag10()
            && player.save_image->mine_floor.GetFlag11()
            && player.save_image->mine_floor.CountHarvestGoddessJewels()
            && player.save_image->mine_floor.GetFlag12()) {
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_SpringMine_CollectedEveryItem, 0), 0);
        }
    }
    if (player.save_image->event_state.achievement_collected_every_lake_mine_item_state == ACHIEVEMENT_EVENT_NOT_REACHED) {
        bool all_shipped = true;
        for (u32 i = 0; i < ARRAY_COUNT(gLakeMineCollectionProducts); ++i) {
            if (!player.save_image->farm.shipping_bin.IsDisplayEnabled(gLakeMineCollectionProducts[i])) {
                all_shipped = false;
                break;
            }
        }
        if (all_shipped
            && player.save_image->cursed_tools.HaveFoundAllTools()
            && player.save_image->mine_floor.GetFlag0()
            && player.save_image->mine_floor.CountKappaJewels()) {
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_LakeMine_CollectedEveryItem, 0), 0);
        }
    }
}
