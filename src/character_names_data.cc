#include "character_names_text.hh"

// Entries are indexed directly by Mary CharacterId.  ID 0 and the Child entry
// point at the original empty string retained in surrounding raw data.
CharacterNameEntry const gCharacterNameEntries[CHARACTER_NAME_ENTRY_COUNT] SECTION(".rodata.character_name_entries") = {
    { gText_CharacterName_Empty, 0x00000000 },            // ID 0
    { gText_CharacterName_Lillia, 0x0000004C },          // CHARACTER_LILLIA
    { gText_CharacterName_Rick, 0x0000006E },            // CHARACTER_RICK
    { gText_CharacterName_Popuri, 0x0000290D },          // CHARACTER_POPURI
    { gText_CharacterName_Barley, 0x00000044 },          // CHARACTER_BARLEY
    { gText_CharacterName_May, 0x0000006B },             // CHARACTER_MAY
    { gText_CharacterName_Saibara, 0x0000002C },         // CHARACTER_SAIBARA
    { gText_CharacterName_Gray, 0x0000001B },            // CHARACTER_GRAY
    { gText_CharacterName_Duke, 0x0000003F },            // CHARACTER_DUKE
    { gText_CharacterName_Manna, 0x0000002E },           // CHARACTER_MANNA
    { gText_CharacterName_Basil, 0x0000002D },           // CHARACTER_BASIL
    { gText_CharacterName_Anna, 0x0000005E },            // CHARACTER_ANNA
    { gText_CharacterName_Mary, 0x00005F53 },            // CHARACTER_MARY
    { gText_CharacterName_Thomas, 0x00000065 },          // CHARACTER_THOMAS
    { gText_CharacterName_Harris, 0x00000011 },          // CHARACTER_HARRIS
    { gText_CharacterName_Ellen, 0x00000037 },           // CHARACTER_ELLEN
    { gText_CharacterName_Stu, 0x00000016 },             // CHARACTER_STU
    { gText_CharacterName_Jeff, 0x00000077 },            // CHARACTER_JEFF
    { gText_CharacterName_Sasha, 0x00000078 },           // CHARACTER_SASHA
    { gText_CharacterName_Karen, 0x00005E3E },           // CHARACTER_KAREN
    { gText_CharacterName_Doctor, 0x0000004E },          // CHARACTER_DOCTOR
    { gText_CharacterName_Elli, 0x00005040 },            // CHARACTER_ELLI
    { gText_CharacterName_Carter, 0x00000052 },          // CHARACTER_CARTER
    { gText_CharacterName_Cliff, 0x00000019 },           // CHARACTER_CLIFF
    { gText_CharacterName_Doug, 0x0000002F },            // CHARACTER_DOUG
    { gText_CharacterName_Ann, 0x00005945 },             // CHARACTER_ANN
    { gText_CharacterName_Kai, 0x00000059 },             // CHARACTER_KAI
    { gText_CharacterName_Gotz, 0x0000000A },            // CHARACTER_GOTZ
    { gText_CharacterName_Zack, 0x00000075 },            // CHARACTER_ZACK
    { gText_CharacterName_Won, 0x0000004F },             // CHARACTER_WON
    { gText_CharacterName_Gourmet, 0x0000004C },         // CHARACTER_GOURMET
    { gText_CharacterName_HarvestGoddess, 0x00002420 },  // CHARACTER_HARVEST_GODDESS
    { gText_CharacterName_Kappa, 0x0000004C },           // CHARACTER_KAPPA
    { gText_CharacterName_Van, 0x0000004C },             // CHARACTER_VAN
    { gText_CharacterName_LouOrRuby, 0x0000004C },       // CHARACTER_LOU_OR_RUBY
    { gText_CharacterName_Empty, 0x00000000 },           // CHARACTER_CHILD
    { gText_CharacterName_Staid, 0x0000003C },           // CHARACTER_STAID
    { gText_CharacterName_Nappy, 0x0000005B },           // CHARACTER_NAPPY
    { gText_CharacterName_Bold, 0x00000010 },            // CHARACTER_BOLD
    { gText_CharacterName_Chef, 0x0000003A },            // CHARACTER_CHEF
    { gText_CharacterName_Aqua, 0x00000068 },            // CHARACTER_AQUA
    { gText_CharacterName_Hoggy, 0x0000002A },           // CHARACTER_HOGGY
    { gText_CharacterName_Timid, 0x00000041 },           // CHARACTER_TIMID
};
