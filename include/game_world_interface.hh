#ifndef GAME_WORLD_INTERFACE_HH
#define GAME_WORLD_INTERFACE_HH

#include "prelude.h"

struct GameScene;
struct GameSceneWorld;
struct GameSceneWorldInstanceOwner;
struct GameSceneWorldMap;
struct GameStateSaveImage;
struct IndexedResourceArchive;

EXTERN_C

// Construct the concrete world and its saved-map owner.
// The last argument's role is unknown; native callers pass false or true.
GameSceneWorldInstanceOwner CreateGameWorld(GameStateSaveImage * save, GameScene * scene, bool unk);

IndexedResourceArchive * func_0801FBDC(GameSceneWorld & world);
IndexedResourceArchive * GetWorldMapSpriteArchive(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC24(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC30(GameSceneWorld & world);
GameSceneWorldMap * func_0801FC9C(GameSceneWorld & world);
GameSceneWorldMap * func_0801FCA0(GameSceneWorld & world);

void ClearWorldWeatherEffect(GameSceneWorld & world);

EXTERN_C_END

#endif // GAME_WORLD_INTERFACE_HH
