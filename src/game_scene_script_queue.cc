#include "game_scene_script_queue.hh"

// Each member releases its constructed request range in reverse queue order.
GameSceneScriptQueues::~GameSceneScriptQueues() {}
