#ifndef NEW_GAME_IDENTITY_TEXT_HH
#define NEW_GAME_IDENTITY_TEXT_HH

#include "prelude.h"

// Prefixes and fixed labels shown while initializing a new player record.
extern char const gText_NewGameIdentity_PlayerPrefix[];
extern char const gText_NewGameIdentity_FarmPrefix[];
extern char const gText_NewGameIdentity_DogPrefix[];
extern char const gText_NewGameIdentity_PlayerName[];
extern char const gText_NewGameIdentity_PlayerBirthday[];
extern char const gText_NewGameIdentity_FarmName[];
extern char const gText_NewGameIdentity_DogName[];
extern char const gText_NewGameIdentity_Confirm[];
extern char const gText_NewGameIdentity_Yes[];
extern char const gText_NewGameIdentity_No[];

#if defined(REGION_JP)
extern char const gText_NewGameIdentity_BirthMonthSuffix[];
extern char const gText_NewGameIdentity_BirthDaySuffix[];
#endif

#endif // NEW_GAME_IDENTITY_TEXT_HH
