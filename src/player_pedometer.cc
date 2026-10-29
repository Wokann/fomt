#include "player_pedometer.hh"

#include "player_actor.hh"
#include "farmer.hh"
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

void UpdatePlayerPedometer(PlayerActor const & player)
{
    u32 previous = player.farmer->GetStepCount();
    player.farmer->RecordPedometerStep();
    if (previous != player.farmer->GetStepCount()) {
        switch (player.farmer->GetStepCount()) {
        case 10000:
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Pedometer_10000Steps, 0), 1);
            break;
        case 100000:
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Pedometer_100000Steps, 0), 1);
            break;
        case 1000000:
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Pedometer_1000000Steps, 0), 1);
            break;
        case 10000000:
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Pedometer_10000000Steps, 0), 1);
            break;
        case 100000000:
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Pedometer_100000000Steps, 0), 1);
            break;
        case 1000000000:
            player.game_object->QueueScript(GameSceneScriptRequest(
                EventScript_AchievementEvent_Pedometer_1000000000Steps, 0), 1);
            break;
        }
    }
}
