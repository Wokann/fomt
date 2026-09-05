#ifndef CHARACTER_NAMES_TEXT_HH
#define CHARACTER_NAMES_TEXT_HH

#include "prelude.h"

// The native name lookup has an empty ID 0 record followed by one record for
// each Mary CharacterId from 1 to 42.  The second word is retained as observed
// data until its purpose is decompiled.
struct CharacterNameEntry
{
    char const *text;
    u32 unk_04;
};

enum
{
    CHARACTER_NAME_ENTRY_COUNT = 43,
};

extern char const gText_CharacterName_Lillia[];
extern char const gText_CharacterName_Rick[];
extern char const gText_CharacterName_Popuri[];
extern char const gText_CharacterName_Barley[];
extern char const gText_CharacterName_May[];
extern char const gText_CharacterName_Saibara[];
extern char const gText_CharacterName_Gray[];
extern char const gText_CharacterName_Duke[];
extern char const gText_CharacterName_Manna[];
extern char const gText_CharacterName_Basil[];
extern char const gText_CharacterName_Anna[];
extern char const gText_CharacterName_Mary[];
extern char const gText_CharacterName_Thomas[];
extern char const gText_CharacterName_Harris[];
extern char const gText_CharacterName_Ellen[];
extern char const gText_CharacterName_Stu[];
extern char const gText_CharacterName_Jeff[];
extern char const gText_CharacterName_Sasha[];
extern char const gText_CharacterName_Karen[];
extern char const gText_CharacterName_Doctor[];
extern char const gText_CharacterName_Elli[];
extern char const gText_CharacterName_Carter[];
extern char const gText_CharacterName_Cliff[];
extern char const gText_CharacterName_Doug[];
extern char const gText_CharacterName_Ann[];
extern char const gText_CharacterName_Kai[];
extern char const gText_CharacterName_Gotz[];
extern char const gText_CharacterName_Zack[];
extern char const gText_CharacterName_Won[];
extern char const gText_CharacterName_Gourmet[];
extern char const gText_CharacterName_HarvestGoddess[];
extern char const gText_CharacterName_Kappa[];
extern char const gText_CharacterName_Van[];
extern char const gText_CharacterName_LouOrRuby[];
extern char const gText_CharacterName_Empty[];
extern char const gText_CharacterName_Staid[];
extern char const gText_CharacterName_Nappy[];
extern char const gText_CharacterName_Bold[];
extern char const gText_CharacterName_Chef[];
extern char const gText_CharacterName_Aqua[];
extern char const gText_CharacterName_Hoggy[];
extern char const gText_CharacterName_Timid[];

extern CharacterNameEntry const gCharacterNameEntries[CHARACTER_NAME_ENTRY_COUNT];

#endif // CHARACTER_NAMES_TEXT_HH
