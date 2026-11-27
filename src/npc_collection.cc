#include "npc_collection.hh"
#include "character_names_empty.hh"

// Names and birthday records precede the implementation dependencies in ROM.
#include FOMT_TEXT_INCLUDE(npc_collection.cc)

CharacterNameEntry const gCharacterNameEntries[] = {
    { gText_CharacterName_Empty,          0,                        0                                  }, // ID 0
    { gText_CharacterName_Lillia,         BIRTHDAY_LILLIA,          0                                  }, // CHARACTER_LILLIA
    { gText_CharacterName_Rick,           BIRTHDAY_RICK,            0                                  }, // CHARACTER_RICK
    { gText_CharacterName_Popuri,         BIRTHDAY_POPURI,          BIRTHDAY_POPURI_ALTERNATE          }, // CHARACTER_POPURI
    { gText_CharacterName_Barley,         BIRTHDAY_BARLEY,          0                                  }, // CHARACTER_BARLEY
    { gText_CharacterName_May,            BIRTHDAY_MAY,             0                                  }, // CHARACTER_MAY
    { gText_CharacterName_Saibara,        BIRTHDAY_SAIBARA,         0                                  }, // CHARACTER_SAIBARA
    { gText_CharacterName_Gray,           BIRTHDAY_GRAY,            0                                  }, // CHARACTER_GRAY
    { gText_CharacterName_Duke,           BIRTHDAY_DUKE,            0                                  }, // CHARACTER_DUKE
    { gText_CharacterName_Manna,          BIRTHDAY_MANNA,           0                                  }, // CHARACTER_MANNA
    { gText_CharacterName_Basil,          BIRTHDAY_BASIL,           0                                  }, // CHARACTER_BASIL
    { gText_CharacterName_Anna,           BIRTHDAY_ANNA,            0                                  }, // CHARACTER_ANNA
    { gText_CharacterName_Mary,           BIRTHDAY_MARY,            BIRTHDAY_MARY_ALTERNATE            }, // CHARACTER_MARY
    { gText_CharacterName_Thomas,         BIRTHDAY_THOMAS,          0                                  }, // CHARACTER_THOMAS
    { gText_CharacterName_Harris,         BIRTHDAY_HARRIS,          0                                  }, // CHARACTER_HARRIS
    { gText_CharacterName_Ellen,          BIRTHDAY_ELLEN,           0                                  }, // CHARACTER_ELLEN
    { gText_CharacterName_Stu,            BIRTHDAY_STU,             0                                  }, // CHARACTER_STU
    { gText_CharacterName_Jeff,           BIRTHDAY_JEFF,            0                                  }, // CHARACTER_JEFF
    { gText_CharacterName_Sasha,          BIRTHDAY_SASHA,           0                                  }, // CHARACTER_SASHA
    { gText_CharacterName_Karen,          BIRTHDAY_KAREN,           BIRTHDAY_KAREN_ALTERNATE           }, // CHARACTER_KAREN
    { gText_CharacterName_Doctor,         BIRTHDAY_DOCTOR,          0                                  }, // CHARACTER_DOCTOR
    { gText_CharacterName_Elli,           BIRTHDAY_ELLI,            BIRTHDAY_ELLI_ALTERNATE            }, // CHARACTER_ELLI
    { gText_CharacterName_Carter,         BIRTHDAY_CARTER,          0                                  }, // CHARACTER_CARTER
    { gText_CharacterName_Cliff,          BIRTHDAY_CLIFF,           0                                  }, // CHARACTER_CLIFF
    { gText_CharacterName_Doug,           BIRTHDAY_DOUG,            0                                  }, // CHARACTER_DOUG
    { gText_CharacterName_Ann,            BIRTHDAY_ANN,             BIRTHDAY_ANN_ALTERNATE             }, // CHARACTER_ANN
    { gText_CharacterName_Kai,            BIRTHDAY_KAI,             0                                  }, // CHARACTER_KAI
    { gText_CharacterName_Gotz,           BIRTHDAY_GOTZ,            0                                  }, // CHARACTER_GOTZ
    { gText_CharacterName_Zack,           BIRTHDAY_ZACK,            0                                  }, // CHARACTER_ZACK
    { gText_CharacterName_Won,            BIRTHDAY_WON,             0                                  }, // CHARACTER_WON
    { gText_CharacterName_Gourmet,        SPECIALDAY_GOURMET,       0                                  }, // CHARACTER_GOURMET
    { gText_CharacterName_HarvestGoddess, BIRTHDAY_HARVEST_GODDESS, BIRTHDAY_HARVEST_GODDESS_ALTERNATE }, // CHARACTER_HARVEST_GODDESS
    { gText_CharacterName_Kappa,          SPECIALDAY_KAPPA,         0                                  }, // CHARACTER_KAPPA
    { gText_CharacterName_Van,            SPECIALDAY_VAN,           0                                  }, // CHARACTER_VAN
    { gText_CharacterName_LouOrRuby,      SPECIALDAY_LOU_OR_RUBY,   0                                  }, // CHARACTER_LOU_OR_RUBY
    { gText_CharacterName_Empty,          0,                        0                                  }, // CHARACTER_CHILD
    { gText_CharacterName_Staid,          BIRTHDAY_STAID,           0                                  }, // CHARACTER_STAID
    { gText_CharacterName_Nappy,          BIRTHDAY_NAPPY,           0                                  }, // CHARACTER_NAPPY
    { gText_CharacterName_Bold,           BIRTHDAY_BOLD,            0                                  }, // CHARACTER_BOLD
    { gText_CharacterName_Chef,           BIRTHDAY_CHEF,            0                                  }, // CHARACTER_CHEF
    { gText_CharacterName_Aqua,           BIRTHDAY_AQUA,            0                                  }, // CHARACTER_AQUA
    { gText_CharacterName_Hoggy,          BIRTHDAY_HOGGY,           0                                  }, // CHARACTER_HOGGY
    { gText_CharacterName_Timid,          BIRTHDAY_TIMID,           0                                  }, // CHARACTER_TIMID
};

#include "game_state.hh"
#include "npc_schedule.hh"

#include <algorithm>
#include <stdlib.h>

static inline ActorLocation InitialNpcLocation()
{
    return ActorLocation(Location(MAP_NONE, 0, 0), FACING_DOWN);
}

NpcCollection::NpcCollection()
    : unk_00_0(0), unk_00_6(0), library_second_floor_visit_count(0), library_second_floor_visited_today(false),
      unk_02_6(0), has_child(false), unk_03_2(0),
      wedding_date(),
      lillia(InitialNpcLocation()),
      rick(InitialNpcLocation()),
      popuri(InitialNpcLocation()),
      barley(InitialNpcLocation()),
      may(InitialNpcLocation()),
      saibara(InitialNpcLocation()),
      gray(InitialNpcLocation()),
      duke(InitialNpcLocation()),
      manna(InitialNpcLocation()),
      basil(InitialNpcLocation()),
      anna(InitialNpcLocation()),
      mary(InitialNpcLocation()),
      thomas(InitialNpcLocation()),
      harris(InitialNpcLocation()),
      ellen(InitialNpcLocation()),
      stu(InitialNpcLocation()),
      jeff(InitialNpcLocation()),
      sasha(InitialNpcLocation()),
      karen(InitialNpcLocation()),
      doctor(InitialNpcLocation()),
      elli(InitialNpcLocation()),
      carter(InitialNpcLocation()),
      cliff(InitialNpcLocation()),
      doug(InitialNpcLocation()),
      ann(InitialNpcLocation()),
      kai(InitialNpcLocation()),
      gotz(InitialNpcLocation()),
      zack(InitialNpcLocation()),
      won(InitialNpcLocation()),
      gourmet(InitialNpcLocation()),
      harvest_goddess(InitialNpcLocation()),
      kappa(InitialNpcLocation()),
      van(InitialNpcLocation()),
      lou(InitialNpcLocation()),
      staid(InitialNpcLocation()),
      nappy(InitialNpcLocation()),
      bold(InitialNpcLocation()),
      chef(InitialNpcLocation()),
      aqua(InitialNpcLocation()),
      hoggy(InitialNpcLocation()),
      timid(InitialNpcLocation())
{
    days_since_pregnancy_event = 0;
    unk_474 = 0;
    // The remaining state bits, child walking bit and object padding are not cleared.
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
);
#if defined(REGION_JP)

char const * NpcCollection::GetCharacterName(u32 character_id) const
{
    bool valid = character_id <= 0x2A;
    if (!valid)
        return gText_CharacterName_Empty;
    switch (character_id) {
    case 0x23:
        return child.GetName();
    case 0:
    default:
        return gCharacterNameEntries[character_id].text;
    }
}

asm_unified(
    "    .align 2, 0\n"
    "    .global GetCharacterBirthdayCode__C13NpcCollectionUiRC8GameDate\n"
    "    .thumb_func\n"
    "GetCharacterBirthdayCode__C13NpcCollectionUiRC8GameDate: @ 0x0809F8AC\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #4\n"
    "\tadds r4, r0, #0\n"
    "\tadds r3, r1, #0\n"
    "\tmov r8, r2\n"
    "\tmovs r0, #0\n"
    "\tcmp r3, #0x2a\n"
    "\tbhi .L0809FE8E\n"
    "\tmovs r0, #1\n"
    ".L0809FE8E:\n"
    "\tcmp r0, #0\n"
    "\tbne .L0809FEA4\n"
    "\tmovs r0, #4\n"
    "\trsbs r0, r0, #0\n"
    "\tands r0, r6\n"
    "\tmovs r2, #0x3c\n"
    "\tmovs r1, #0x7d\n"
    "\trsbs r1, r1, #0\n"
    "\tands r0, r1\n"
    "\torrs r0, r2\n"
    "\tb .L080A001C\n"
    ".L0809FEA4:\n"
    "\tcmp r3, #0x23\n"
    "\tbls .L0809FEAA\n"
    "\tb .L0809FFE4\n"
    ".L0809FEAA:\n"
    "\tlsls r0, r3, #2\n"
    "\tldr r1, .L0809FEB4 @ =.L0809FEB8\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L0809FEB4: .word .L0809FEB8\n"
    ".L0809FEB8: @ jump table\n"
    "\t.word .L0809FFE4 @ case 0\n"
    "\t.word .L0809FFE4 @ case 1\n"
    "\t.word .L0809FFE4 @ case 2\n"
    "\t.word .L0809FF48 @ case 3\n"
    "\t.word .L0809FFE4 @ case 4\n"
    "\t.word .L0809FFE4 @ case 5\n"
    "\t.word .L0809FFE4 @ case 6\n"
    "\t.word .L0809FFE4 @ case 7\n"
    "\t.word .L0809FFE4 @ case 8\n"
    "\t.word .L0809FFE4 @ case 9\n"
    "\t.word .L0809FFE4 @ case 10\n"
    "\t.word .L0809FFE4 @ case 11\n"
    "\t.word .L0809FF48 @ case 12\n"
    "\t.word .L0809FFE4 @ case 13\n"
    "\t.word .L0809FFE4 @ case 14\n"
    "\t.word .L0809FFE4 @ case 15\n"
    "\t.word .L0809FFE4 @ case 16\n"
    "\t.word .L0809FFE4 @ case 17\n"
    "\t.word .L0809FFE4 @ case 18\n"
    "\t.word .L0809FF48 @ case 19\n"
    "\t.word .L0809FFE4 @ case 20\n"
    "\t.word .L0809FF48 @ case 21\n"
    "\t.word .L0809FFE4 @ case 22\n"
    "\t.word .L0809FFE4 @ case 23\n"
    "\t.word .L0809FFE4 @ case 24\n"
    "\t.word .L0809FF48 @ case 25\n"
    "\t.word .L0809FFE4 @ case 26\n"
    "\t.word .L0809FFE4 @ case 27\n"
    "\t.word .L0809FFE4 @ case 28\n"
    "\t.word .L0809FFE4 @ case 29\n"
    "\t.word .L0809FFE4 @ case 30\n"
    "\t.word .L0809FF48 @ case 31\n"
    "\t.word .L0809FFE4 @ case 32\n"
    "\t.word .L0809FFE4 @ case 33\n"
    "\t.word .L0809FFE4 @ case 34\n"
    "\t.word .L0809FFDC @ case 35\n"
    ".L0809FF48:\n"
    "\tlsls r0, r3, #3\n"
    "\tldr r1, .L0809FFD8 @ =gCharacterNameEntries\n"
    "\tadds r0, r0, r1\n"
    "\tadds r6, r0, #0\n"
    "\tldrb r0, [r6, #4]\n"
    "\tlsls r1, r0, #0x1e\n"
    "\tlsls r0, r0, #0x19\n"
    "\tlsrs r0, r0, #0x1b\n"
    "\tmovs r7, #3\n"
    "\tlsrs r1, r1, #0x1e\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tands r4, r5\n"
    "\torrs r4, r1\n"
    "\tsubs r0, #1\n"
    "\tcmp r0, #0x1d\n"
    "\tbls .L0809FF70\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    ".L0809FF70:\n"
    "\tmovs r1, #0x1f\n"
    "\tmov sl, r1\n"
    "\tmov r2, sl\n"
    "\tands r0, r2\n"
    "\tlsls r0, r0, #2\n"
    "\tmovs r3, #0x7d\n"
    "\trsbs r3, r3, #0\n"
    "\tmov sb, r3\n"
    "\tands r3, r4\n"
    "\torrs r3, r0\n"
    "\tadds r5, r3, #0\n"
    "\tmov r0, r8\n"
    "\tldrb r2, [r0]\n"
    "\tlsls r1, r2, #0x1e\n"
    "\tlsls r0, r3, #0x1e\n"
    "\tcmp r1, r0\n"
    "\tbne .L0809FFD4\n"
    "\tlsls r1, r2, #0x19\n"
    "\tlsrs r1, r1, #0x1b\n"
    "\tadds r1, #1\n"
    "\tlsls r0, r3, #0x19\n"
    "\tlsrs r0, r0, #0x1b\n"
    "\tadds r0, #1\n"
    "\tcmp r1, r0\n"
    "\tbne .L0809FFD4\n"
    "\tldrb r1, [r6, #5]\n"
    "\tlsls r0, r1, #0x1e\n"
    "\tlsrs r0, r0, #0x1e\n"
    "\tlsls r1, r1, #0x19\n"
    "\tlsrs r1, r1, #0x1b\n"
    "\tands r0, r7\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tmov r2, sp\n"
    "\tldrb r2, [r2]\n"
    "\tands r4, r2\n"
    "\torrs r4, r0\n"
    "\tsubs r0, r1, #1\n"
    "\tcmp r0, #0x1d\n"
    "\tbls .L0809FFC6\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    ".L0809FFC6:\n"
    "\tmov r3, sl\n"
    "\tands r0, r3\n"
    "\tlsls r0, r0, #2\n"
    "\tmov r1, sb\n"
    "\tands r4, r1\n"
    "\tadds r5, r4, #0\n"
    "\torrs r5, r0\n"
    ".L0809FFD4:\n"
    "\tadds r0, r5, #0\n"
    "\tb .L080A001C\n"
    "\t.align 2, 0\n"
    ".L0809FFD8: .word gCharacterNameEntries\n"
    ".L0809FFDC:\n"
    "\tadds r0, r4, #4\n"
    "\tbl GetBirthdayCode__C5Child\n"
    "\tb .L080A001C\n"
    ".L0809FFE4:\n"
    "\tlsls r0, r3, #3\n"
    "\tldr r1, .L080A002C @ =gCharacterNameEntries\n"
    "\tadds r0, r0, r1\n"
    "\tldrb r0, [r0, #4]\n"
    "\tlsls r1, r0, #0x1e\n"
    "\tlsls r0, r0, #0x19\n"
    "\tlsrs r0, r0, #0x1b\n"
    "\tlsrs r1, r1, #0x1e\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tands r4, r7\n"
    "\torrs r4, r1\n"
    "\tsubs r1, r0, #1\n"
    "\tcmp r1, #0x1d\n"
    "\tbls .L080A000C\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    "\tadds r1, r0, #0\n"
    ".L080A000C:\n"
    "\tmovs r0, #0x1f\n"
    "\tands r1, r0\n"
    "\tlsls r1, r1, #2\n"
    "\tmovs r0, #0x7d\n"
    "\trsbs r0, r0, #0\n"
    "\tands r4, r0\n"
    "\torrs r4, r1\n"
    "\tadds r0, r4, #0\n"
    ".L080A001C:\n"
    "\tadd sp, #4\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    ".L080A002C: .word gCharacterNameEntries\n"
    "\n"
    "    .global GetNpc__C13NpcCollectionUi\n"
    "    .thumb_func\n"
    "GetNpc__C13NpcCollectionUi: @ 0x0809FA68\n"
    "\tpush {lr}\n"
    "\tadds r2, r0, #0\n"
    "\tsubs r0, r1, #1\n"
    "\tcmp r0, #0x29\n"
    "\tbhi .L080A00F0\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A0044 @ =.L080A0048\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A0044: .word .L080A0048\n"
    ".L080A0048: @ jump table\n"
    "\t.word .L080A00FC @ case 0\n"
    "\t.word .L080A0102 @ case 1\n"
    "\t.word .L080A0108 @ case 2\n"
    "\t.word .L080A010E @ case 3\n"
    "\t.word .L080A0114 @ case 4\n"
    "\t.word .L080A011A @ case 5\n"
    "\t.word .L080A0120 @ case 6\n"
    "\t.word .L080A0126 @ case 7\n"
    "\t.word .L080A012C @ case 8\n"
    "\t.word .L080A0132 @ case 9\n"
    "\t.word .L080A0138 @ case 10\n"
    "\t.word .L080A013E @ case 11\n"
    "\t.word .L080A0144 @ case 12\n"
    "\t.word .L080A014A @ case 13\n"
    "\t.word .L080A0150 @ case 14\n"
    "\t.word .L080A0156 @ case 15\n"
    "\t.word .L080A015C @ case 16\n"
    "\t.word .L080A0162 @ case 17\n"
    "\t.word .L080A0168 @ case 18\n"
    "\t.word .L080A016E @ case 19\n"
    "\t.word .L080A0174 @ case 20\n"
    "\t.word .L080A017A @ case 21\n"
    "\t.word .L080A0180 @ case 22\n"
    "\t.word .L080A0186 @ case 23\n"
    "\t.word .L080A018C @ case 24\n"
    "\t.word .L080A0192 @ case 25\n"
    "\t.word .L080A0198 @ case 26\n"
    "\t.word .L080A019E @ case 27\n"
    "\t.word .L080A01A4 @ case 28\n"
    "\t.word .L080A01AA @ case 29\n"
    "\t.word .L080A01B0 @ case 30\n"
    "\t.word .L080A01B6 @ case 31\n"
    "\t.word .L080A01BC @ case 32\n"
    "\t.word .L080A01C2 @ case 33\n"
    "\t.word .L080A00F4 @ case 34\n"
    "\t.word .L080A01C8 @ case 35\n"
    "\t.word .L080A01CE @ case 36\n"
    "\t.word .L080A01D4 @ case 37\n"
    "\t.word .L080A01DA @ case 38\n"
    "\t.word .L080A01E0 @ case 39\n"
    "\t.word .L080A01E6 @ case 40\n"
    "\t.word .L080A01EC @ case 41\n"
    ".L080A00F0:\n"
    "\tmovs r0, #0\n"
    "\tb .L080A01F0\n"
    ".L080A00F4:\n"
    "\tadds r0, r2, #0\n"
    "\tbl GetChild__C13NpcCollection\n"
    "\tb .L080A01F0\n"
    ".L080A00FC:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x70\n"
    "\tb .L080A01F0\n"
    ".L080A0102:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x84\n"
    "\tb .L080A01F0\n"
    ".L080A0108:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x98\n"
    "\tb .L080A01F0\n"
    ".L080A010E:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xb0\n"
    "\tb .L080A01F0\n"
    ".L080A0114:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xc4\n"
    "\tb .L080A01F0\n"
    ".L080A011A:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xd8\n"
    "\tb .L080A01F0\n"
    ".L080A0120:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xf0\n"
    "\tb .L080A01F0\n"
    ".L080A0126:\n"
    "\tmovs r1, #0x82\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A012C:\n"
    "\tmovs r1, #0x8c\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0132:\n"
    "\tmovs r1, #0x96\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0138:\n"
    "\tmovs r1, #0xa0\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A013E:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0144:\n"
    "\tmovs r1, #0xb6\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A014A:\n"
    "\tmovs r1, #0xc0\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0150:\n"
    "\tmovs r1, #0xca\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0156:\n"
    "\tmovs r1, #0xd4\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A015C:\n"
    "\tmovs r1, #0xde\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0162:\n"
    "\tmovs r1, #0xe8\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0168:\n"
    "\tmovs r1, #0xf2\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A016E:\n"
    "\tmovs r1, #0xfe\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0174:\n"
    "\tmovs r1, #0x84\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A017A:\n"
    "\tmovs r1, #0x8a\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0180:\n"
    "\tmovs r1, #0x8f\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0186:\n"
    "\tmovs r1, #0x94\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A018C:\n"
    "\tmovs r1, #0x99\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0192:\n"
    "\tmovs r1, #0x9f\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0198:\n"
    "\tmovs r1, #0xa4\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A019E:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01A4:\n"
    "\tmovs r1, #0xaf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01AA:\n"
    "\tmovs r1, #0xb4\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01B0:\n"
    "\tmovs r1, #0xb9\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01B6:\n"
    "\tmovs r1, #0xbf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01BC:\n"
    "\tmovs r1, #0xc4\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01C2:\n"
    "\tmovs r1, #0xca\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01C8:\n"
    "\tmovs r1, #0xcf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01CE:\n"
    "\tmovs r1, #0xd8\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01D4:\n"
    "\tmovs r1, #0xe1\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01DA:\n"
    "\tmovs r1, #0xea\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01E0:\n"
    "\tmovs r1, #0xf3\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01E6:\n"
    "\tmovs r1, #0xfc\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01EC:\n"
    "\tldr r1, .L080A01F4 @ =0x00000414\n"
    ".L080A01EE:\n"
    "\tadds r0, r2, r1\n"
    ".L080A01F0:\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    ".L080A01F4: .word 0x00000414\n"
    "\n"
    "    .global GetBachelorette__C13NpcCollectionUi\n"
    "    .thumb_func\n"
    "GetBachelorette__C13NpcCollectionUi: @ 0x0809FC30\n"
    "\tpush {lr}\n"
    "\tadds r2, r0, #0\n"
    "\tsubs r0, r1, #3\n"
    "\tcmp r0, #0x1c\n"
    "\tbhi .L080A0284\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A020C @ =.L080A0210\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A020C: .word .L080A0210\n"
    ".L080A0210: @ jump table\n"
    "\t.word .L080A0288 @ case 0\n"
    "\t.word .L080A0284 @ case 1\n"
    "\t.word .L080A0284 @ case 2\n"
    "\t.word .L080A0284 @ case 3\n"
    "\t.word .L080A0284 @ case 4\n"
    "\t.word .L080A0284 @ case 5\n"
    "\t.word .L080A0284 @ case 6\n"
    "\t.word .L080A0284 @ case 7\n"
    "\t.word .L080A0284 @ case 8\n"
    "\t.word .L080A028E @ case 9\n"
    "\t.word .L080A0284 @ case 10\n"
    "\t.word .L080A0284 @ case 11\n"
    "\t.word .L080A0284 @ case 12\n"
    "\t.word .L080A0284 @ case 13\n"
    "\t.word .L080A0284 @ case 14\n"
    "\t.word .L080A0284 @ case 15\n"
    "\t.word .L080A0294 @ case 16\n"
    "\t.word .L080A0284 @ case 17\n"
    "\t.word .L080A029A @ case 18\n"
    "\t.word .L080A0284 @ case 19\n"
    "\t.word .L080A0284 @ case 20\n"
    "\t.word .L080A0284 @ case 21\n"
    "\t.word .L080A02A0 @ case 22\n"
    "\t.word .L080A0284 @ case 23\n"
    "\t.word .L080A0284 @ case 24\n"
    "\t.word .L080A0284 @ case 25\n"
    "\t.word .L080A0284 @ case 26\n"
    "\t.word .L080A0284 @ case 27\n"
    "\t.word .L080A02A6 @ case 28\n"
    ".L080A0284:\n"
    "\tmovs r0, #0\n"
    "\tb .L080A02AC\n"
    ".L080A0288:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x98\n"
    "\tb .L080A02AC\n"
    ".L080A028E:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A02AA\n"
    ".L080A0294:\n"
    "\tmovs r1, #0xf2\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A02AA\n"
    ".L080A029A:\n"
    "\tmovs r1, #0x84\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A02AA\n"
    ".L080A02A0:\n"
    "\tmovs r1, #0x99\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A02AA\n"
    ".L080A02A6:\n"
    "\tmovs r1, #0xb9\n"
    "\tlsls r1, r1, #2\n"
    ".L080A02AA:\n"
    "\tadds r0, r2, r1\n"
    ".L080A02AC:\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    ".global GetHarvestSpriteByCharacterId__C13NpcCollectionUi\n"
    ".thumb_func\n"
    "GetHarvestSpriteByCharacterId__C13NpcCollectionUi:\n"
    "\tpush {lr}\n"
    "\tadds r2, r0, #0\n"
    "\tadds r0, r1, #0\n"
    "\tsubs r0, #0x24\n"
    "\tcmp r0, #6\n"
    "\tbhi .L080A02E8\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A02C8\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A02C8: .word .L080A02CC\n"
    ".L080A02CC: .word .L080A02EC\n"
    "\t.word .L080A02F2\n"
    "\t.word .L080A02F8\n"
    "\t.word .L080A02FE\n"
    "\t.word .L080A0304\n"
    "\t.word .L080A030A\n"
    "\t.word .L080A0310\n"
    ".L080A02E8:\n"
    "\tmovs r0, #0\n"
    "\tb .L080A0314\n"
    ".L080A02EC:\n"
    "\tmovs r1, #0xcf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A02F2:\n"
    "\tmovs r1, #0xd8\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A02F8:\n"
    "\tmovs r1, #0xe1\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A02FE:\n"
    "\tmovs r1, #0xea\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A0304:\n"
    "\tmovs r1, #0xf3\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A030A:\n"
    "\tmovs r1, #0xfc\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A0310:\n"
    "\tldr r1, .L080A0318\n"
    ".L080A0312:\n"
    "\tadds r0, r2, r1\n"
    ".L080A0314:\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    ".L080A0318: .word 0x00000414\n"
    "\n"
);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)

char const * NpcCollection::GetCharacterName(u32 character_id) const
{
    bool valid = character_id <= 0x2A;
    if (!valid)
        return gText_CharacterName_Empty;
    switch (character_id) {
    case 0x23:
        return child.GetName();
    case 0:
    default:
        return gCharacterNameEntries[character_id].text;
    }
}

asm_unified(
    "    .align 2, 0\n"
    "\tthumb_func_start GetCharacterBirthdayCode__C13NpcCollectionUiRC8GameDate\n"
    "GetCharacterBirthdayCode__C13NpcCollectionUiRC8GameDate: @ 0x0809FE74\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #4\n"
    "\tadds r4, r0, #0\n"
    "\tadds r3, r1, #0\n"
    "\tmov r8, r2\n"
    "\tmovs r0, #0\n"
    "\tcmp r3, #0x2a\n"
    "\tbhi .L0809FE8E\n"
    "\tmovs r0, #1\n"
    ".L0809FE8E:\n"
    "\tcmp r0, #0\n"
    "\tbne .L0809FEA4\n"
    "\tmovs r0, #4\n"
    "\trsbs r0, r0, #0\n"
    "\tands r0, r6\n"
    "\tmovs r2, #0x3c\n"
    "\tmovs r1, #0x7d\n"
    "\trsbs r1, r1, #0\n"
    "\tands r0, r1\n"
    "\torrs r0, r2\n"
    "\tb .L080A001C\n"
    ".L0809FEA4:\n"
    "\tcmp r3, #0x23\n"
    "\tbls .L0809FEAA\n"
    "\tb .L0809FFE4\n"
    ".L0809FEAA:\n"
    "\tlsls r0, r3, #2\n"
    "\tldr r1, .L0809FEB4 @ =.L0809FEB8\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L0809FEB4: .word .L0809FEB8\n"
    ".L0809FEB8: @ jump table\n"
    "\t.word .L0809FFE4 @ case 0\n"
    "\t.word .L0809FFE4 @ case 1\n"
    "\t.word .L0809FFE4 @ case 2\n"
    "\t.word .L0809FF48 @ case 3\n"
    "\t.word .L0809FFE4 @ case 4\n"
    "\t.word .L0809FFE4 @ case 5\n"
    "\t.word .L0809FFE4 @ case 6\n"
    "\t.word .L0809FFE4 @ case 7\n"
    "\t.word .L0809FFE4 @ case 8\n"
    "\t.word .L0809FFE4 @ case 9\n"
    "\t.word .L0809FFE4 @ case 10\n"
    "\t.word .L0809FFE4 @ case 11\n"
    "\t.word .L0809FF48 @ case 12\n"
    "\t.word .L0809FFE4 @ case 13\n"
    "\t.word .L0809FFE4 @ case 14\n"
    "\t.word .L0809FFE4 @ case 15\n"
    "\t.word .L0809FFE4 @ case 16\n"
    "\t.word .L0809FFE4 @ case 17\n"
    "\t.word .L0809FFE4 @ case 18\n"
    "\t.word .L0809FF48 @ case 19\n"
    "\t.word .L0809FFE4 @ case 20\n"
    "\t.word .L0809FF48 @ case 21\n"
    "\t.word .L0809FFE4 @ case 22\n"
    "\t.word .L0809FFE4 @ case 23\n"
    "\t.word .L0809FFE4 @ case 24\n"
    "\t.word .L0809FF48 @ case 25\n"
    "\t.word .L0809FFE4 @ case 26\n"
    "\t.word .L0809FFE4 @ case 27\n"
    "\t.word .L0809FFE4 @ case 28\n"
    "\t.word .L0809FFE4 @ case 29\n"
    "\t.word .L0809FFE4 @ case 30\n"
    "\t.word .L0809FF48 @ case 31\n"
    "\t.word .L0809FFE4 @ case 32\n"
    "\t.word .L0809FFE4 @ case 33\n"
    "\t.word .L0809FFE4 @ case 34\n"
    "\t.word .L0809FFDC @ case 35\n"
    ".L0809FF48:\n"
    "\tlsls r0, r3, #3\n"
    "\tldr r1, .L0809FFD8 @ =gCharacterNameEntries\n"
    "\tadds r0, r0, r1\n"
    "\tadds r6, r0, #0\n"
    "\tldrb r0, [r6, #4]\n"
    "\tlsls r1, r0, #0x1e\n"
    "\tlsls r0, r0, #0x19\n"
    "\tlsrs r0, r0, #0x1b\n"
    "\tmovs r7, #3\n"
    "\tlsrs r1, r1, #0x1e\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tands r4, r5\n"
    "\torrs r4, r1\n"
    "\tsubs r0, #1\n"
    "\tcmp r0, #0x1d\n"
    "\tbls .L0809FF70\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    ".L0809FF70:\n"
    "\tmovs r1, #0x1f\n"
    "\tmov sl, r1\n"
    "\tmov r2, sl\n"
    "\tands r0, r2\n"
    "\tlsls r0, r0, #2\n"
    "\tmovs r3, #0x7d\n"
    "\trsbs r3, r3, #0\n"
    "\tmov sb, r3\n"
    "\tands r3, r4\n"
    "\torrs r3, r0\n"
    "\tadds r5, r3, #0\n"
    "\tmov r0, r8\n"
    "\tldrb r2, [r0]\n"
    "\tlsls r1, r2, #0x1e\n"
    "\tlsls r0, r3, #0x1e\n"
    "\tcmp r1, r0\n"
    "\tbne .L0809FFD4\n"
    "\tlsls r1, r2, #0x19\n"
    "\tlsrs r1, r1, #0x1b\n"
    "\tadds r1, #1\n"
    "\tlsls r0, r3, #0x19\n"
    "\tlsrs r0, r0, #0x1b\n"
    "\tadds r0, #1\n"
    "\tcmp r1, r0\n"
    "\tbne .L0809FFD4\n"
    "\tldrb r1, [r6, #5]\n"
    "\tlsls r0, r1, #0x1e\n"
    "\tlsrs r0, r0, #0x1e\n"
    "\tlsls r1, r1, #0x19\n"
    "\tlsrs r1, r1, #0x1b\n"
    "\tands r0, r7\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tmov r2, sp\n"
    "\tldrb r2, [r2]\n"
    "\tands r4, r2\n"
    "\torrs r4, r0\n"
    "\tsubs r0, r1, #1\n"
    "\tcmp r0, #0x1d\n"
    "\tbls .L0809FFC6\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    ".L0809FFC6:\n"
    "\tmov r3, sl\n"
    "\tands r0, r3\n"
    "\tlsls r0, r0, #2\n"
    "\tmov r1, sb\n"
    "\tands r4, r1\n"
    "\tadds r5, r4, #0\n"
    "\torrs r5, r0\n"
    ".L0809FFD4:\n"
    "\tadds r0, r5, #0\n"
    "\tb .L080A001C\n"
    "\t.align 2, 0\n"
    ".L0809FFD8: .word gCharacterNameEntries\n"
    ".L0809FFDC:\n"
    "\tadds r0, r4, #4\n"
    "\tbl GetBirthdayCode__C5Child\n"
    "\tb .L080A001C\n"
    ".L0809FFE4:\n"
    "\tlsls r0, r3, #3\n"
    "\tldr r1, .L080A002C @ =gCharacterNameEntries\n"
    "\tadds r0, r0, r1\n"
    "\tldrb r0, [r0, #4]\n"
    "\tlsls r1, r0, #0x1e\n"
    "\tlsls r0, r0, #0x19\n"
    "\tlsrs r0, r0, #0x1b\n"
    "\tlsrs r1, r1, #0x1e\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tands r4, r7\n"
    "\torrs r4, r1\n"
    "\tsubs r1, r0, #1\n"
    "\tcmp r1, #0x1d\n"
    "\tbls .L080A000C\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    "\tadds r1, r0, #0\n"
    ".L080A000C:\n"
    "\tmovs r0, #0x1f\n"
    "\tands r1, r0\n"
    "\tlsls r1, r1, #2\n"
    "\tmovs r0, #0x7d\n"
    "\trsbs r0, r0, #0\n"
    "\tands r4, r0\n"
    "\torrs r4, r1\n"
    "\tadds r0, r4, #0\n"
    ".L080A001C:\n"
    "\tadd sp, #4\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    ".L080A002C: .word gCharacterNameEntries\n"
    "\n"
    "\tthumb_func_start GetNpc__C13NpcCollectionUi\n"
    "GetNpc__C13NpcCollectionUi: @ 0x080A0030\n"
    "\tpush {lr}\n"
    "\tadds r2, r0, #0\n"
    "\tsubs r0, r1, #1\n"
    "\tcmp r0, #0x29\n"
    "\tbhi .L080A00F0\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A0044 @ =.L080A0048\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A0044: .word .L080A0048\n"
    ".L080A0048: @ jump table\n"
    "\t.word .L080A00FC @ case 0\n"
    "\t.word .L080A0102 @ case 1\n"
    "\t.word .L080A0108 @ case 2\n"
    "\t.word .L080A010E @ case 3\n"
    "\t.word .L080A0114 @ case 4\n"
    "\t.word .L080A011A @ case 5\n"
    "\t.word .L080A0120 @ case 6\n"
    "\t.word .L080A0126 @ case 7\n"
    "\t.word .L080A012C @ case 8\n"
    "\t.word .L080A0132 @ case 9\n"
    "\t.word .L080A0138 @ case 10\n"
    "\t.word .L080A013E @ case 11\n"
    "\t.word .L080A0144 @ case 12\n"
    "\t.word .L080A014A @ case 13\n"
    "\t.word .L080A0150 @ case 14\n"
    "\t.word .L080A0156 @ case 15\n"
    "\t.word .L080A015C @ case 16\n"
    "\t.word .L080A0162 @ case 17\n"
    "\t.word .L080A0168 @ case 18\n"
    "\t.word .L080A016E @ case 19\n"
    "\t.word .L080A0174 @ case 20\n"
    "\t.word .L080A017A @ case 21\n"
    "\t.word .L080A0180 @ case 22\n"
    "\t.word .L080A0186 @ case 23\n"
    "\t.word .L080A018C @ case 24\n"
    "\t.word .L080A0192 @ case 25\n"
    "\t.word .L080A0198 @ case 26\n"
    "\t.word .L080A019E @ case 27\n"
    "\t.word .L080A01A4 @ case 28\n"
    "\t.word .L080A01AA @ case 29\n"
    "\t.word .L080A01B0 @ case 30\n"
    "\t.word .L080A01B6 @ case 31\n"
    "\t.word .L080A01BC @ case 32\n"
    "\t.word .L080A01C2 @ case 33\n"
    "\t.word .L080A00F4 @ case 34\n"
    "\t.word .L080A01C8 @ case 35\n"
    "\t.word .L080A01CE @ case 36\n"
    "\t.word .L080A01D4 @ case 37\n"
    "\t.word .L080A01DA @ case 38\n"
    "\t.word .L080A01E0 @ case 39\n"
    "\t.word .L080A01E6 @ case 40\n"
    "\t.word .L080A01EC @ case 41\n"
    ".L080A00F0:\n"
    "\tmovs r0, #0\n"
    "\tb .L080A01F0\n"
    ".L080A00F4:\n"
    "\tadds r0, r2, #0\n"
    "\tbl GetChild__C13NpcCollection\n"
    "\tb .L080A01F0\n"
    ".L080A00FC:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x70\n"
    "\tb .L080A01F0\n"
    ".L080A0102:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x84\n"
    "\tb .L080A01F0\n"
    ".L080A0108:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x98\n"
    "\tb .L080A01F0\n"
    ".L080A010E:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xb0\n"
    "\tb .L080A01F0\n"
    ".L080A0114:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xc4\n"
    "\tb .L080A01F0\n"
    ".L080A011A:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xd8\n"
    "\tb .L080A01F0\n"
    ".L080A0120:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0xf0\n"
    "\tb .L080A01F0\n"
    ".L080A0126:\n"
    "\tmovs r1, #0x82\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A012C:\n"
    "\tmovs r1, #0x8c\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0132:\n"
    "\tmovs r1, #0x96\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0138:\n"
    "\tmovs r1, #0xa0\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A013E:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0144:\n"
    "\tmovs r1, #0xb6\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A014A:\n"
    "\tmovs r1, #0xc0\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0150:\n"
    "\tmovs r1, #0xca\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0156:\n"
    "\tmovs r1, #0xd4\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A015C:\n"
    "\tmovs r1, #0xde\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0162:\n"
    "\tmovs r1, #0xe8\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0168:\n"
    "\tmovs r1, #0xf2\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A016E:\n"
    "\tmovs r1, #0xfe\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A01EE\n"
    ".L080A0174:\n"
    "\tmovs r1, #0x84\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A017A:\n"
    "\tmovs r1, #0x8a\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0180:\n"
    "\tmovs r1, #0x8f\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0186:\n"
    "\tmovs r1, #0x94\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A018C:\n"
    "\tmovs r1, #0x99\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0192:\n"
    "\tmovs r1, #0x9f\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A0198:\n"
    "\tmovs r1, #0xa4\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A019E:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01A4:\n"
    "\tmovs r1, #0xaf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01AA:\n"
    "\tmovs r1, #0xb4\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01B0:\n"
    "\tmovs r1, #0xb9\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01B6:\n"
    "\tmovs r1, #0xbf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01BC:\n"
    "\tmovs r1, #0xc4\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01C2:\n"
    "\tmovs r1, #0xca\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01C8:\n"
    "\tmovs r1, #0xcf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01CE:\n"
    "\tmovs r1, #0xd8\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01D4:\n"
    "\tmovs r1, #0xe1\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01DA:\n"
    "\tmovs r1, #0xea\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01E0:\n"
    "\tmovs r1, #0xf3\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01E6:\n"
    "\tmovs r1, #0xfc\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A01EE\n"
    ".L080A01EC:\n"
    "\tldr r1, .L080A01F4 @ =0x00000414\n"
    ".L080A01EE:\n"
    "\tadds r0, r2, r1\n"
    ".L080A01F0:\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    ".L080A01F4: .word 0x00000414\n"
    "\n"
    "\tthumb_func_start GetBachelorette__C13NpcCollectionUi\n"
    "GetBachelorette__C13NpcCollectionUi: @ 0x080A01F8\n"
    "\tpush {lr}\n"
    "\tadds r2, r0, #0\n"
    "\tsubs r0, r1, #3\n"
    "\tcmp r0, #0x1c\n"
    "\tbhi .L080A0284\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A020C @ =.L080A0210\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A020C: .word .L080A0210\n"
    ".L080A0210: @ jump table\n"
    "\t.word .L080A0288 @ case 0\n"
    "\t.word .L080A0284 @ case 1\n"
    "\t.word .L080A0284 @ case 2\n"
    "\t.word .L080A0284 @ case 3\n"
    "\t.word .L080A0284 @ case 4\n"
    "\t.word .L080A0284 @ case 5\n"
    "\t.word .L080A0284 @ case 6\n"
    "\t.word .L080A0284 @ case 7\n"
    "\t.word .L080A0284 @ case 8\n"
    "\t.word .L080A028E @ case 9\n"
    "\t.word .L080A0284 @ case 10\n"
    "\t.word .L080A0284 @ case 11\n"
    "\t.word .L080A0284 @ case 12\n"
    "\t.word .L080A0284 @ case 13\n"
    "\t.word .L080A0284 @ case 14\n"
    "\t.word .L080A0284 @ case 15\n"
    "\t.word .L080A0294 @ case 16\n"
    "\t.word .L080A0284 @ case 17\n"
    "\t.word .L080A029A @ case 18\n"
    "\t.word .L080A0284 @ case 19\n"
    "\t.word .L080A0284 @ case 20\n"
    "\t.word .L080A0284 @ case 21\n"
    "\t.word .L080A02A0 @ case 22\n"
    "\t.word .L080A0284 @ case 23\n"
    "\t.word .L080A0284 @ case 24\n"
    "\t.word .L080A0284 @ case 25\n"
    "\t.word .L080A0284 @ case 26\n"
    "\t.word .L080A0284 @ case 27\n"
    "\t.word .L080A02A6 @ case 28\n"
    ".L080A0284:\n"
    "\tmovs r0, #0\n"
    "\tb .L080A02AC\n"
    ".L080A0288:\n"
    "\tadds r0, r2, #0\n"
    "\tadds r0, #0x98\n"
    "\tb .L080A02AC\n"
    ".L080A028E:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A02AA\n"
    ".L080A0294:\n"
    "\tmovs r1, #0xf2\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A02AA\n"
    ".L080A029A:\n"
    "\tmovs r1, #0x84\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A02AA\n"
    ".L080A02A0:\n"
    "\tmovs r1, #0x99\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A02AA\n"
    ".L080A02A6:\n"
    "\tmovs r1, #0xb9\n"
    "\tlsls r1, r1, #2\n"
    ".L080A02AA:\n"
    "\tadds r0, r2, r1\n"
    ".L080A02AC:\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    ".global GetHarvestSpriteByCharacterId__C13NpcCollectionUi\n"
    ".thumb_func\n"
    "GetHarvestSpriteByCharacterId__C13NpcCollectionUi:\n"
    "\tpush {lr}\n"
    "\tadds r2, r0, #0\n"
    "\tadds r0, r1, #0\n"
    "\tsubs r0, #0x24\n"
    "\tcmp r0, #6\n"
    "\tbhi .L080A02E8\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A02C8\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A02C8: .word .L080A02CC\n"
    ".L080A02CC: .word .L080A02EC\n"
    "\t.word .L080A02F2\n"
    "\t.word .L080A02F8\n"
    "\t.word .L080A02FE\n"
    "\t.word .L080A0304\n"
    "\t.word .L080A030A\n"
    "\t.word .L080A0310\n"
    ".L080A02E8:\n"
    "\tmovs r0, #0\n"
    "\tb .L080A0314\n"
    ".L080A02EC:\n"
    "\tmovs r1, #0xcf\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A02F2:\n"
    "\tmovs r1, #0xd8\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A02F8:\n"
    "\tmovs r1, #0xe1\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A02FE:\n"
    "\tmovs r1, #0xea\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A0304:\n"
    "\tmovs r1, #0xf3\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A030A:\n"
    "\tmovs r1, #0xfc\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A0312\n"
    ".L080A0310:\n"
    "\tldr r1, .L080A0318\n"
    ".L080A0312:\n"
    "\tadds r0, r2, r1\n"
    ".L080A0314:\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    ".L080A0318: .word 0x00000414\n"
    "\n"
);
#endif

HarvestSprite const * NpcCollection::GetHarvestSpriteByIndex(u32 index) const
{
    switch (index) {
    default: return nullptr;
    case 0: return &staid;
    case 1: return &nappy;
    case 2: return &bold;
    case 3: return &chef;
    case 4: return &aqua;
    case 5: return &hoggy;
    case 6: return &timid;
    }
}

Child const * NpcCollection::GetChild() const
{
    return has_child ? &child : nullptr;
}

asm_unified(
    ".text\n"
);
#if defined(REGION_JP)

u32 NpcCollection::GetUnk03_2() const
{
    return unk_03_2;
}

void NpcCollection::SetUnk03_2(u32 value)
{
    unk_03_2 = value;
}

ActorLocation NpcCollection::GetNpcLocation(u32 character_id) const
{
    Npc const * npc = GetNpc(character_id);

    if (npc != nullptr)
        return npc->GetLocation();

    return ActorLocation(Location(MAP_FARM, 0, 0), 0);
}

#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)

u32 NpcCollection::GetUnk03_2() const
{
    return unk_03_2;
}

void NpcCollection::SetUnk03_2(u32 value)
{
    unk_03_2 = value;
}

ActorLocation NpcCollection::GetNpcLocation(u32 character_id) const
{
    Npc const * npc = GetNpc(character_id);

    if (npc != nullptr)
        return npc->GetLocation();

    return ActorLocation(Location(MAP_FARM, 0, 0), 0);
}

#endif

u32 NpcCollection::GetPartnerCharacterId() const
{
    if (popuri.GetPlayerEventCount() > 4) return CHARACTER_POPURI;
    if (mary.GetPlayerEventCount() > 4) return CHARACTER_MARY;
    if (karen.GetPlayerEventCount() > 4) return CHARACTER_KAREN;
    if (elli.GetPlayerEventCount() > 4) return CHARACTER_ELLI;
    if (ann.GetPlayerEventCount() > 4) return CHARACTER_ANN;
    if (harvest_goddess.GetPlayerEventCount() > 4) return CHARACTER_HARVEST_GODDESS;
    return 0;
}

u32 NpcCollection::GetSpouseCharacterId() const
{
    if (popuri.GetPlayerEventCount() > 5) return CHARACTER_POPURI;
    if (mary.GetPlayerEventCount() > 5) return CHARACTER_MARY;
    if (karen.GetPlayerEventCount() > 5) return CHARACTER_KAREN;
    if (elli.GetPlayerEventCount() > 5) return CHARACTER_ELLI;
    if (ann.GetPlayerEventCount() > 5) return CHARACTER_ANN;
    if (harvest_goddess.GetPlayerEventCount() > 5) return CHARACTER_HARVEST_GODDESS;
    return 0;
}

bool NpcCollection::IsMarried() const
{
    return GetSpouseCharacterId() != 0;
}

asm_unified(
    ".text\n"
);
#if defined(REGION_JP)

bool NpcCollection::HasRequiredFriendshipLevels() const
{
    bool result = true;

    for (u32 id = 1; id <= 0x2A; id++)
    {
        switch (id)
        {
        case 0x17:
        case 0x1A:
        case 0x1E:
        case 0x20:
        case 0x23:
            break;
        default:
            Npc const * npc = GetNpc(id);

            if (npc != nullptr && npc->GetFriendship() <= 0xF9)
                result = false;
            break;
        }
    }

    return result;
}

u32 NpcCollection::GetUnk00_0() const
{
    return unk_00_0;
}

u32 NpcCollection::GetUnk00_6() const
{
    return unk_00_6;
}

u32 NpcCollection::GetLibrarySecondFloorVisitCount() const
{
    return library_second_floor_visit_count;
}

ActorLocation const * NpcCollection::GetSouthTownNpcLocation1(u32 slot) const
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_1_0;
    case 1: return &locations.south_town_1_1;
    case 2: return &locations.south_town_1_2;
    }
}

ActorLocation const * NpcCollection::GetSouthTownNpcLocation2(u32 slot) const
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_2_0;
    case 1: return &locations.south_town_2_1;
    case 2: return &locations.south_town_2_2;
    }
}

ActorLocation const * NpcCollection::GetYodelRanchHouseNpcLocation() const
{
    return &locations.yodel_ranch_house;
}

ActorLocation const * NpcCollection::GetInnSecondFloorNpcLocation() const
{
    return &locations.inn_second_floor;
}

asm_unified(
    "    .align 2, 0\n"
    "    .global CreateChild__13NpcCollectionRC8GameDate\n"
    "    .thumb_func\n"
    "CreateChild__13NpcCollectionRC8GameDate: @ 0x080A0020\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sb\n"
    "\tmov r6, r8\n"
    "\tpush {r6, r7}\n"
    "\tsub sp, #0x38\n"
    "\tadds r7, r0, #0\n"
    "\tmov sb, r1\n"
    "\tldrb r1, [r7, #3]\n"
    "\tlsls r0, r1, #0x1e\n"
    "\tlsrs r0, r0, #0x1f\n"
    "\tmov r8, r0\n"
    "\tcmp r0, #0\n"
    "\tbne .L080A069E\n"
    "\tmovs r0, #2\n"
    "\torrs r0, r1\n"
    "\tstrb r0, [r7, #3]\n"
    "\tadd r1, sp, #0x30\n"
    "\tmovs r4, #0x1d\n"
    "\tldrh r2, [r1]\n"
    "\tldr r3, .L080A06AC @ =0xFFFFFC00\n"
    "\tadds r0, r3, #0\n"
    "\tands r0, r2\n"
    "\torrs r0, r4\n"
    "\tstrh r0, [r1]\n"
    "\tmovs r6, #0x90\n"
    "\tldrb r4, [r1, #1]\n"
    "\tmovs r2, #3\n"
    "\tadds r0, r2, #0\n"
    "\tands r0, r4\n"
    "\torrs r0, r6\n"
    "\tstrb r0, [r1, #1]\n"
    "\tmovs r5, #1\n"
    "\tldrh r4, [r1, #2]\n"
    "\tadds r0, r3, #0\n"
    "\tands r0, r4\n"
    "\torrs r0, r5\n"
    "\tstrh r0, [r1, #2]\n"
    "\tldrb r0, [r1, #3]\n"
    "\tands r2, r0\n"
    "\torrs r2, r6\n"
    "\tstrb r2, [r1, #3]\n"
    "\tldrh r0, [r1, #4]\n"
    "\tands r3, r0\n"
    "\torrs r3, r5\n"
    "\tstrh r3, [r1, #4]\n"
    "\tadd r4, sp, #0x28\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r2, #6\n"
    "\tbl memcpy\n"
    "\tmov r0, r8\n"
    "\tstrb r0, [r4, #6]\n"
    "\tmov r0, sp\n"
    "\tmov r1, sb\n"
    "\tadds r2, r4, #0\n"
    "\tbl __5ChildRC8GameDateRC13ActorLocation\n"
    "\tadds r1, r7, #4\n"
    "\tmov r0, sp\n"
    "\tldm r0!, {r2, r3, r4}\n"
    "\tstm r1!, {r2, r3, r4}\n"
    "\tldm r0!, {r2, r3}\n"
    "\tstm r1!, {r2, r3}\n"
    "\tadds r0, r7, #0\n"
    "\tadds r0, #0x18\n"
    "\tadd r1, sp, #0x14\n"
    "\tbl strcpy\n"
    "\tadds r1, r7, #0\n"
    "\tadds r1, #0x28\n"
    "\tadd r0, sp, #0x24\n"
    "\tldrb r0, [r0]\n"
    "\tstrb r0, [r1]\n"
    "\tmov r0, sp\n"
    "\tadds r0, #0x25\n"
    "\tldrb r0, [r0]\n"
    "\tadds r1, #1\n"
    "\tstrb r0, [r1]\n"
    "\tmov r0, sp\n"
    "\tadds r0, #0x26\n"
    "\tldrb r1, [r0]\n"
    "\tlsls r1, r1, #0x1f\n"
    "\tadds r3, r7, #0\n"
    "\tadds r3, #0x2a\n"
    "\tlsrs r1, r1, #0x1f\n"
    "\tldrb r2, [r3]\n"
    "\tmovs r0, #2\n"
    "\trsbs r0, r0, #0\n"
    "\tands r0, r2\n"
    "\torrs r0, r1\n"
    "\tstrb r0, [r3]\n"
    ".L080A069E:\n"
    "\tadd sp, #0x38\n"
    "\tpop {r3, r4}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    ".L080A06AC: .word 0xFFFFFC00\n"
);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)

bool NpcCollection::HasRequiredFriendshipLevels() const
{
    bool result = true;

    for (u32 id = 1; id <= 0x2A; id++)
    {
        switch (id)
        {
        case 0x17:
        case 0x1A:
        case 0x1E:
        case 0x20:
        case 0x23:
            break;
        default:
            Npc const * npc = GetNpc(id);

            if (npc != nullptr && npc->GetFriendship() <= 0xF9)
                result = false;
            break;
        }
    }

    return result;
}

u32 NpcCollection::GetUnk00_0() const
{
    return unk_00_0;
}

u32 NpcCollection::GetUnk00_6() const
{
    return unk_00_6;
}

u32 NpcCollection::GetLibrarySecondFloorVisitCount() const
{
    return library_second_floor_visit_count;
}

ActorLocation const * NpcCollection::GetSouthTownNpcLocation1(u32 slot) const
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_1_0;
    case 1: return &locations.south_town_1_1;
    case 2: return &locations.south_town_1_2;
    }
}

ActorLocation const * NpcCollection::GetSouthTownNpcLocation2(u32 slot) const
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_2_0;
    case 1: return &locations.south_town_2_1;
    case 2: return &locations.south_town_2_2;
    }
}

ActorLocation const * NpcCollection::GetYodelRanchHouseNpcLocation() const
{
    return &locations.yodel_ranch_house;
}

ActorLocation const * NpcCollection::GetInnSecondFloorNpcLocation() const
{
    return &locations.inn_second_floor;
}

asm_unified(
    "    .align 2, 0\n"
    "\tthumb_func_start CreateChild__13NpcCollectionRC8GameDate\n"
    "CreateChild__13NpcCollectionRC8GameDate: @ 0x080A05E8\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sb\n"
    "\tmov r6, r8\n"
    "\tpush {r6, r7}\n"
    "\tsub sp, #0x38\n"
    "\tadds r7, r0, #0\n"
    "\tmov sb, r1\n"
    "\tldrb r1, [r7, #3]\n"
    "\tlsls r0, r1, #0x1e\n"
    "\tlsrs r0, r0, #0x1f\n"
    "\tmov r8, r0\n"
    "\tcmp r0, #0\n"
    "\tbne .L080A069E\n"
    "\tmovs r0, #2\n"
    "\torrs r0, r1\n"
    "\tstrb r0, [r7, #3]\n"
    "\tadd r1, sp, #0x30\n"
    "\tmovs r4, #0x1d\n"
    "\tldrh r2, [r1]\n"
    "\tldr r3, .L080A06AC @ =0xFFFFFC00\n"
    "\tadds r0, r3, #0\n"
    "\tands r0, r2\n"
    "\torrs r0, r4\n"
    "\tstrh r0, [r1]\n"
    "\tmovs r6, #0x90\n"
    "\tldrb r4, [r1, #1]\n"
    "\tmovs r2, #3\n"
    "\tadds r0, r2, #0\n"
    "\tands r0, r4\n"
    "\torrs r0, r6\n"
    "\tstrb r0, [r1, #1]\n"
    "\tmovs r5, #1\n"
    "\tldrh r4, [r1, #2]\n"
    "\tadds r0, r3, #0\n"
    "\tands r0, r4\n"
    "\torrs r0, r5\n"
    "\tstrh r0, [r1, #2]\n"
    "\tldrb r0, [r1, #3]\n"
    "\tands r2, r0\n"
    "\torrs r2, r6\n"
    "\tstrb r2, [r1, #3]\n"
    "\tldrh r0, [r1, #4]\n"
    "\tands r3, r0\n"
    "\torrs r3, r5\n"
    "\tstrh r3, [r1, #4]\n"
    "\tadd r4, sp, #0x28\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r2, #6\n"
    "\tbl memcpy\n"
    "\tmov r0, r8\n"
    "\tstrb r0, [r4, #6]\n"
    "\tmov r0, sp\n"
    "\tmov r1, sb\n"
    "\tadds r2, r4, #0\n"
    "\tbl __5ChildRC8GameDateRC13ActorLocation\n"
    "\tadds r1, r7, #4\n"
    "\tmov r0, sp\n"
    "\tldm r0!, {r2, r3, r4}\n"
    "\tstm r1!, {r2, r3, r4}\n"
    "\tldm r0!, {r2, r3}\n"
    "\tstm r1!, {r2, r3}\n"
    "\tadds r0, r7, #0\n"
    "\tadds r0, #0x18\n"
    "\tadd r1, sp, #0x14\n"
    "\tbl strcpy\n"
    "\tadds r1, r7, #0\n"
    "\tadds r1, #0x28\n"
    "\tadd r0, sp, #0x24\n"
    "\tldrb r0, [r0]\n"
    "\tstrb r0, [r1]\n"
    "\tmov r0, sp\n"
    "\tadds r0, #0x25\n"
    "\tldrb r0, [r0]\n"
    "\tadds r1, #1\n"
    "\tstrb r0, [r1]\n"
    "\tmov r0, sp\n"
    "\tadds r0, #0x26\n"
    "\tldrb r1, [r0]\n"
    "\tlsls r1, r1, #0x1f\n"
    "\tadds r3, r7, #0\n"
    "\tadds r3, #0x2a\n"
    "\tlsrs r1, r1, #0x1f\n"
    "\tldrb r2, [r3]\n"
    "\tmovs r0, #2\n"
    "\trsbs r0, r0, #0\n"
    "\tands r0, r2\n"
    "\torrs r0, r1\n"
    "\tstrb r0, [r3]\n"
    ".L080A069E:\n"
    "\tadd sp, #0x38\n"
    "\tpop {r3, r4}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    ".L080A06AC: .word 0xFFFFFC00\n"
    "\n"
);
#endif

Npc * NpcCollection::GetNpc(u32 character_id)
{
    switch (character_id) {
    default: return nullptr;
    case CHARACTER_CHILD: return GetChild();
    case CHARACTER_LILLIA: return &lillia;
    case CHARACTER_RICK: return &rick;
    case CHARACTER_POPURI: return &popuri;
    case CHARACTER_BARLEY: return &barley;
    case CHARACTER_MAY: return &may;
    case CHARACTER_SAIBARA: return &saibara;
    case CHARACTER_GRAY: return &gray;
    case CHARACTER_DUKE: return &duke;
    case CHARACTER_MANNA: return &manna;
    case CHARACTER_BASIL: return &basil;
    case CHARACTER_ANNA: return &anna;
    case CHARACTER_MARY: return &mary;
    case CHARACTER_THOMAS: return &thomas;
    case CHARACTER_HARRIS: return &harris;
    case CHARACTER_ELLEN: return &ellen;
    case CHARACTER_STU: return &stu;
    case CHARACTER_JEFF: return &jeff;
    case CHARACTER_SASHA: return &sasha;
    case CHARACTER_KAREN: return &karen;
    case CHARACTER_DOCTOR: return &doctor;
    case CHARACTER_ELLI: return &elli;
    case CHARACTER_CARTER: return &carter;
    case CHARACTER_CLIFF: return &cliff;
    case CHARACTER_DOUG: return &doug;
    case CHARACTER_ANN: return &ann;
    case CHARACTER_KAI: return &kai;
    case CHARACTER_GOTZ: return &gotz;
    case CHARACTER_ZACK: return &zack;
    case CHARACTER_WON: return &won;
    case CHARACTER_GOURMET: return &gourmet;
    case CHARACTER_HARVEST_GODDESS: return &harvest_goddess;
    case CHARACTER_KAPPA: return &kappa;
    case CHARACTER_VAN: return &van;
    case CHARACTER_LOU_OR_RUBY: return &lou;
    case CHARACTER_STAID: return &staid;
    case CHARACTER_NAPPY: return &nappy;
    case CHARACTER_BOLD: return &bold;
    case CHARACTER_CHEF: return &chef;
    case CHARACTER_AQUA: return &aqua;
    case CHARACTER_HOGGY: return &hoggy;
    case CHARACTER_TIMID: return &timid;
    }
}

Bachelorette * NpcCollection::GetBachelorette(u32 character_id)
{
    switch (character_id) {
    default: return nullptr;
    case CHARACTER_POPURI: return &popuri;
    case CHARACTER_MARY: return &mary;
    case CHARACTER_KAREN: return &karen;
    case CHARACTER_ELLI: return &elli;
    case CHARACTER_ANN: return &ann;
    case CHARACTER_HARVEST_GODDESS: return &harvest_goddess;
    }
}

HarvestSprite * NpcCollection::GetHarvestSpriteByCharacterId(u32 character_id)
{
    switch (character_id) {
    default: return nullptr;
    case CHARACTER_STAID: return &staid;
    case CHARACTER_NAPPY: return &nappy;
    case CHARACTER_BOLD: return &bold;
    case CHARACTER_CHEF: return &chef;
    case CHARACTER_AQUA: return &aqua;
    case CHARACTER_HOGGY: return &hoggy;
    case CHARACTER_TIMID: return &timid;
    }
}

HarvestSprite * NpcCollection::GetHarvestSpriteByIndex(u32 index)
{
    switch (index) {
    default: return nullptr;
    case 0: return &staid;
    case 1: return &nappy;
    case 2: return &bold;
    case 3: return &chef;
    case 4: return &aqua;
    case 5: return &hoggy;
    case 6: return &timid;
    }
}

Child * NpcCollection::GetChild()
{
    return has_child ? &child : nullptr;
}

void NpcCollection::AddUnk00_0(u32 amount)
{
    unk_00_0 = std::min(unk_00_0 + amount, 63u);
}

void NpcCollection::AddUnk00_6(u32 amount)
{
    unk_00_6 = std::min(unk_00_6 + amount, 127u);
}

void NpcCollection::RecordLibrarySecondFloorVisit()
{
    if (!library_second_floor_visited_today) {
        library_second_floor_visit_count = std::min(library_second_floor_visit_count + 1, 255u);
        library_second_floor_visited_today = true;
    }
}

ActorLocation * NpcCollection::GetSouthTownNpcLocation1(u32 slot)
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_1_0;
    case 1: return &locations.south_town_1_1;
    case 2: return &locations.south_town_1_2;
    }
}

ActorLocation * NpcCollection::GetSouthTownNpcLocation2(u32 slot)
{
    switch (slot) {
    case 0:
    default: return &locations.south_town_2_0;
    case 1: return &locations.south_town_2_1;
    case 2: return &locations.south_town_2_2;
    }
}

ActorLocation * NpcCollection::GetYodelRanchHouseNpcLocation()
{
    return &locations.yodel_ranch_house;
}

ActorLocation * NpcCollection::GetInnSecondFloorNpcLocation()
{
    return &locations.inn_second_floor;
}

static inline void ResetHarvestSpriteForDay(HarvestSprite & sprite, u32 slot)
{
    sprite.DayUpdate();
    ActorLocation location;
    InitializeHarvestSpriteHutLocation(&location, slot);
    sprite.SetLocation(location);
    // Preserve the native zero-initialized opaque argument to the state setter.
    u32 unk_data = 0;
    sprite.method_0809E7C8(&unk_data);
}

void NpcCollection::DayUpdate(GameStateClock const & clock, GameEventState const & events,
    Farmer const & farmer, Farm const & farm)
{
    library_second_floor_visited_today = false;
    u32 spouse = GetSpouseCharacterId();
    bool married = spouse != 0;
    lillia.DayUpdate(rand() % 100);
    rick.DayUpdate(rand() % 100);
    if (popuri.GetRivalEventCount() <= 4 || clock.calendar.date.season == SEASON_SUMMER)
        popuri.DayUpdate(married, rand() % 100);
    barley.DayUpdate(rand() % 100);
    may.DayUpdate(rand() % 100);
    saibara.DayUpdate();
    gray.DayUpdate(rand() % 100);
    duke.DayUpdate(rand() % 100);
    manna.DayUpdate(rand() % 100);
    basil.DayUpdate(rand() % 100);
    anna.DayUpdate(rand() % 100);
    mary.DayUpdate(married, rand() % 100);
    thomas.DayUpdate(rand() % 100);
    harris.DayUpdate(rand() % 100);
    ellen.DayUpdate(rand() % 100);
    stu.DayUpdate(rand() % 100);
    jeff.DayUpdate(rand() % 100);
    sasha.DayUpdate(rand() % 100);
    karen.DayUpdate(married, rand() % 100);
    doctor.DayUpdate(rand() % 100);
    elli.DayUpdate(married, rand() % 100);
    carter.DayUpdate(rand() % 100);
    cliff.DayUpdate(rand() % 100);
    doug.DayUpdate(rand() % 100);
    ann.DayUpdate(married, rand() % 100);
    if (clock.calendar.date.season == SEASON_SUMMER) {
        // Preserve the original second addition when Kai's friendship increases.
        u32 old_friendship = kai.GetFriendship();
        kai.DayUpdate(rand() % 100);
        if (kai.GetFriendship() > old_friendship)
            kai.AddFriendship(kai.GetFriendship() - old_friendship);
    }
    gotz.DayUpdate();
    zack.DayUpdate(rand() % 100);
    won.DayUpdate(rand() % 100);
    gourmet.DayUpdate(rand() % 100);
    harvest_goddess.DayUpdate(married, rand() % 100);
    kappa.DayUpdate(rand() % 100);
    if (events.van_introduction_event_state == 2)
        van.Npc::DayUpdate(rand() % 100);
    if (events.lou_or_ruby_introduction_event_state == 2)
        lou.DayUpdate(rand() % 100);
    if (has_child)
        child.DayUpdate();

    ResetHarvestSpriteForDay(staid, 0);
    ClearHarvestSpriteWorkTarget(work_targets.values, 0);
    ResetHarvestSpriteForDay(nappy, 1);
    ClearHarvestSpriteWorkTarget(work_targets.values, 1);
    ResetHarvestSpriteForDay(bold, 2);
    ClearHarvestSpriteWorkTarget(work_targets.values, 2);
    ResetHarvestSpriteForDay(chef, 3);
    ClearHarvestSpriteWorkTarget(work_targets.values, 3);
    ResetHarvestSpriteForDay(aqua, 4);
    ClearHarvestSpriteWorkTarget(work_targets.values, 4);
    ResetHarvestSpriteForDay(hoggy, 5);
    ClearHarvestSpriteWorkTarget(work_targets.values, 5);
    ResetHarvestSpriteForDay(timid, 6);
    ClearHarvestSpriteWorkTarget(work_targets.values, 6);

    if (events.popuri_pregnancy_event_state == 2 || events.ann_pregnancy_event_state == 2
        || events.elli_pregnancy_event_state == 2 || events.karen_pregnancy_event_state == 2
        || events.mary_pregnancy_event_state == 2 || events.harvest_goddess_pregnancy_event_state == 2) {
        // The native check is equality, not a clamp for larger saved values.
        if (days_since_pregnancy_event != 60)
            ++days_since_pregnancy_event;
    }

    if (popuri.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_POPURI)) {
        if (farm.coop.CountChickens() == 8) {
            u32 affection = 0;
            for (u32 slot = 0; slot < 8; ++slot) {
                Chicken const * chicken = farm.coop.GetChicken(slot);
                if (chicken != nullptr)
                    affection += chicken->GetAffection();
            }
            affection /= 8;
            while (popuri.method_0809E4BC() <= 4
                && affection >= gUnk_BacheloretteLoveThresholds00[popuri.method_0809E4BC()]) {
                popuri.AddLove(2500);
                popuri.method_0809E550();
            }
        }
    }
    if (mary.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_MARY)) {
        u32 value = library_second_floor_visit_count;
        while (mary.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds01[mary.method_0809E4BC()]) {
            mary.AddLove(2500);
            mary.method_0809E550();
        }
    }
    if (karen.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_KAREN)) {
        u32 value = unk_00_6;
        while (karen.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds02[karen.method_0809E4BC()]) {
            karen.AddLove(2500);
            karen.method_0809E550();
        }
    }
    if (elli.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_ELLI)) {
        u32 value = func_0800E970(farmer);
        while (elli.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds03[elli.method_0809E4BC()]) {
            elli.AddLove(2500);
            elli.method_0809E550();
        }
    }
    if (ann.method_0809E4BC() <= 4 && (!married || spouse == CHARACTER_ANN)) {
        u32 value = unk_00_0;
        while (ann.method_0809E4BC() <= 4
            && value >= gUnk_BacheloretteLoveThresholds04[ann.method_0809E4BC()]) {
            ann.AddLove(2500);
            ann.method_0809E550();
        }
    }

    if (unk_02_6 <= 4) {
        u32 friendship = 0;
        u32 count = 0;
        for (u32 id = 0; id <= CHARACTER_TIMID; ++id) {
            switch (id) {
            case CHARACTER_CLIFF:
            case CHARACTER_KAI:
            case CHARACTER_GOURMET:
            case CHARACTER_VAN:
            case CHARACTER_LOU_OR_RUBY:
            case CHARACTER_CHILD:
                break;
            default:
                Npc * npc = GetNpc(id);
                if (npc != nullptr) {
                    friendship += npc->GetFriendship();
                    ++count;
                }
                break;
            }
        }
        u32 average = friendship / count;
        while (unk_02_6 <= 4 && average >= gUnk_BacheloretteLoveThresholds05[unk_02_6]) {
            if (!married || spouse == CHARACTER_POPURI) popuri.AddLove(2500);
            if (!married || spouse == CHARACTER_MARY) mary.AddLove(2500);
            if (!married || spouse == CHARACTER_KAREN) karen.AddLove(2500);
            if (!married || spouse == CHARACTER_ELLI) elli.AddLove(2500);
            if (!married || spouse == CHARACTER_ANN) ann.AddLove(2500);
            if (!married || spouse == CHARACTER_HARVEST_GODDESS) harvest_goddess.AddLove(2500);
            ++unk_02_6;
        }
    }
    ActorLocation location;
    InitializeSouthTownNpcLocation1(&location, 0);
    locations.south_town_1_0 = location;
    InitializeSouthTownNpcLocation1(&location, 1);
    locations.south_town_1_1 = location;
    InitializeSouthTownNpcLocation1(&location, 2);
    locations.south_town_1_2 = location;
    InitializeSouthTownNpcLocation2(&location, 0);
    locations.south_town_2_0 = location;
    InitializeSouthTownNpcLocation2(&location, 1);
    locations.south_town_2_1 = location;
    InitializeSouthTownNpcLocation2(&location, 2);
    locations.south_town_2_2 = location;
    InitializeYodelRanchHouseNpcLocation(&location);
    locations.yodel_ranch_house = location;
    InitializeInnSecondFloorNpcLocation(&location);
    locations.inn_second_floor = location;
}

void NpcCollection::SetWeddingDate(WeddingDate const & date)
{
    wedding_date = date;
}

WeddingDate const & NpcCollection::GetWeddingDate() const
{
    return wedding_date;
}

asm_unified(
    ".text\n"
#if defined(REGION_JP)
    "    .global ApplyDroppedItemFriendshipPenalty__13NpcCollectionRC8LocationRC14GameEventState\n"
    "    .thumb_func\n"
    "ApplyDroppedItemFriendshipPenalty__13NpcCollectionRC8LocationRC14GameEventState: @ 0x080A0EBC\n"
    "\tpush {r4, r5, r6, lr}\n"
    "\tadds r4, r0, #0\n"
    "\tadds r6, r2, #0\n"
    "\tldrh r0, [r1]\n"
    "\tlsls r0, r0, #0x16\n"
    "\tlsrs r0, r0, #0x16\n"
    "\tcmp r0, #0x2a\n"
    "\tbls .Ljp_080A1496\n"
    "\tb .Ljp_080A1798\n"
    ".Ljp_080A1496:\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .Ljp_080A14A0 @ =.Ljp_080A14A4\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".Ljp_080A14A0: .word .Ljp_080A14A4\n"
    ".Ljp_080A14A4: @ jump table\n"
    "\t.word .Ljp_080A1550 @ case 0\n"
    "\t.word .Ljp_080A1550 @ case 1\n"
    "\t.word .Ljp_080A1798 @ case 2\n"
    "\t.word .Ljp_080A1550 @ case 3\n"
    "\t.word .Ljp_080A1550 @ case 4\n"
    "\t.word .Ljp_080A1550 @ case 5\n"
    "\t.word .Ljp_080A1550 @ case 6\n"
    "\t.word .Ljp_080A1550 @ case 7\n"
    "\t.word .Ljp_080A1550 @ case 8\n"
    "\t.word .Ljp_080A1798 @ case 9\n"
    "\t.word .Ljp_080A1636 @ case 10\n"
    "\t.word .Ljp_080A1636 @ case 11\n"
    "\t.word .Ljp_080A164E @ case 12\n"
    "\t.word .Ljp_080A1654 @ case 13\n"
    "\t.word .Ljp_080A165A @ case 14\n"
    "\t.word .Ljp_080A1678 @ case 15\n"
    "\t.word .Ljp_080A1678 @ case 16\n"
    "\t.word .Ljp_080A1798 @ case 17\n"
    "\t.word .Ljp_080A1798 @ case 18\n"
    "\t.word .Ljp_080A1696 @ case 19\n"
    "\t.word .Ljp_080A1696 @ case 20\n"
    "\t.word .Ljp_080A16A8 @ case 21\n"
    "\t.word .Ljp_080A16A8 @ case 22\n"
    "\t.word .Ljp_080A16A8 @ case 23\n"
    "\t.word .Ljp_080A16BA @ case 24\n"
    "\t.word .Ljp_080A16BA @ case 25\n"
    "\t.word .Ljp_080A16BA @ case 26\n"
    "\t.word .Ljp_080A16BA @ case 27\n"
    "\t.word .Ljp_080A16EC @ case 28\n"
    "\t.word .Ljp_080A1798 @ case 29\n"
    "\t.word .Ljp_080A173C @ case 30\n"
    "\t.word .Ljp_080A174E @ case 31\n"
    "\t.word .Ljp_080A174E @ case 32\n"
    "\t.word .Ljp_080A174E @ case 33\n"
    "\t.word .Ljp_080A174E @ case 34\n"
    "\t.word .Ljp_080A1798 @ case 35\n"
    "\t.word .Ljp_080A1760 @ case 36\n"
    "\t.word .Ljp_080A1798 @ case 37\n"
    "\t.word .Ljp_080A1766 @ case 38\n"
    "\t.word .Ljp_080A1798 @ case 39\n"
    "\t.word .Ljp_080A1776 @ case 40\n"
    "\t.word .Ljp_080A1784 @ case 41\n"
    "\t.word .Ljp_080A1784 @ case 42\n"
    ".Ljp_080A1550:\n"
    "\tmovs r5, #1\n"
    ".Ljp_080A1552:\n"
    "\tmovs r1, #1\n"
    "\tcmp r5, #0x21\n"
    "\tbeq .Ljp_080A1570\n"
    "\tcmp r5, #0x21\n"
    "\tbhi .Ljp_080A1562\n"
    "\tcmp r5, #0x20\n"
    "\tbeq .Ljp_080A1580\n"
    "\tb .Ljp_080A1582\n"
    ".Ljp_080A1562:\n"
    "\tcmp r5, #0x22\n"
    "\tbne .Ljp_080A1582\n"
    "\tadds r0, r6, #0\n"
    "\tadds r0, #0x3b\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x1b\n"
    "\tb .Ljp_080A1578\n"
    ".Ljp_080A1570:\n"
    "\tadds r0, r6, #0\n"
    "\tadds r0, #0x3a\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x19\n"
    ".Ljp_080A1578:\n"
    "\tlsrs r0, r0, #0x1e\n"
    "\tcmp r0, #2\n"
    "\tbeq .Ljp_080A1582\n"
    "\tb .Ljp_080A1598\n"
    ".Ljp_080A1580:\n"
    "\tmovs r1, #0\n"
    ".Ljp_080A1582:\n"
    "\tcmp r1, #0\n"
    "\tbeq .Ljp_080A1598\n"
    "\tadds r0, r4, #0\n"
    "\tadds r1, r5, #0\n"
    "\tbl GetNpc__13NpcCollectionUi\n"
    "\tcmp r0, #0\n"
    "\tbeq .Ljp_080A1598\n"
    "\tmovs r1, #1\n"
    "\tbl SubtractFriendship__3Npci\n"
    ".Ljp_080A1598:\n"
    "\tsubs r0, r5, #3\n"
    "\tcmp r0, #0x1c\n"
    "\tbhi .Ljp_080A162E\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .Ljp_080A15A8 @ =.Ljp_080A15AC\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".Ljp_080A15A8: .word .Ljp_080A15AC\n"
    ".Ljp_080A15AC: @ jump table\n"
    "\t.word .Ljp_080A1620 @ case 0\n"
    "\t.word .Ljp_080A162E @ case 1\n"
    "\t.word .Ljp_080A162E @ case 2\n"
    "\t.word .Ljp_080A162E @ case 3\n"
    "\t.word .Ljp_080A162E @ case 4\n"
    "\t.word .Ljp_080A162E @ case 5\n"
    "\t.word .Ljp_080A162E @ case 6\n"
    "\t.word .Ljp_080A162E @ case 7\n"
    "\t.word .Ljp_080A162E @ case 8\n"
    "\t.word .Ljp_080A1620 @ case 9\n"
    "\t.word .Ljp_080A162E @ case 10\n"
    "\t.word .Ljp_080A162E @ case 11\n"
    "\t.word .Ljp_080A162E @ case 12\n"
    "\t.word .Ljp_080A162E @ case 13\n"
    "\t.word .Ljp_080A162E @ case 14\n"
    "\t.word .Ljp_080A162E @ case 15\n"
    "\t.word .Ljp_080A1620 @ case 16\n"
    "\t.word .Ljp_080A162E @ case 17\n"
    "\t.word .Ljp_080A1620 @ case 18\n"
    "\t.word .Ljp_080A162E @ case 19\n"
    "\t.word .Ljp_080A162E @ case 20\n"
    "\t.word .Ljp_080A162E @ case 21\n"
    "\t.word .Ljp_080A1620 @ case 22\n"
    "\t.word .Ljp_080A162E @ case 23\n"
    "\t.word .Ljp_080A162E @ case 24\n"
    "\t.word .Ljp_080A162E @ case 25\n"
    "\t.word .Ljp_080A162E @ case 26\n"
    "\t.word .Ljp_080A162E @ case 27\n"
    "\t.word .Ljp_080A1620 @ case 28\n"
    ".Ljp_080A1620:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r1, r5, #0\n"
    "\tbl GetBachelorette__13NpcCollectionUi\n"
    "\tmovs r1, #0xc8\n"
    "\tbl SubtractLove__12Bachelorettei\n"
    ".Ljp_080A162E:\n"
    "\tadds r5, #1\n"
    "\tcmp r5, #0x2a\n"
    "\tbls .Ljp_080A1552\n"
    "\tb .Ljp_080A1798\n"
    ".Ljp_080A1636:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0x70\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0x84\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r4, #0x98\n"
    "\tb .Ljp_080A16D8\n"
    ".Ljp_080A164E:\n"
    "\tmovs r1, #0x8a\n"
    "\tlsls r1, r1, #2\n"
    "\tb .Ljp_080A177A\n"
    ".Ljp_080A1654:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #2\n"
    "\tb .Ljp_080A177A\n"
    ".Ljp_080A165A:\n"
    "\tmovs r1, #0xca\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xd4\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0x84\n"
    "\tlsls r0, r0, #2\n"
    "\tb .Ljp_080A16D6\n"
    ".Ljp_080A1678:\n"
    "\tmovs r1, #0xde\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xe8\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0xf2\n"
    "\tlsls r0, r0, #1\n"
    "\tb .Ljp_080A16D6\n"
    ".Ljp_080A1696:\n"
    "\tmovs r1, #0xfe\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0x84\n"
    "\tlsls r0, r0, #2\n"
    "\tb .Ljp_080A16D6\n"
    ".Ljp_080A16A8:\n"
    "\tmovs r1, #0x94\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0x99\n"
    "\tlsls r0, r0, #2\n"
    "\tb .Ljp_080A16D6\n"
    ".Ljp_080A16BA:\n"
    "\tmovs r1, #0x96\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xa0\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0xaa\n"
    "\tlsls r0, r0, #1\n"
    ".Ljp_080A16D6:\n"
    "\tadds r4, r4, r0\n"
    ".Ljp_080A16D8:\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xfa\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, #0\n"
    "\tbl SubtractLove__12Bachelorettei\n"
    "\tb .Ljp_080A1798\n"
    ".Ljp_080A16EC:\n"
    "\tmovs r1, #0xcf\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xd8\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xe1\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xea\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xf3\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xfc\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tldr r1, .Ljp_080A1738 @ =0x00000414\n"
    "\tb .Ljp_080A177A\n"
    "\t.align 2, 0\n"
    ".Ljp_080A1738: .word 0x00000414\n"
    ".Ljp_080A173C:\n"
    "\tmovs r1, #0xb6\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xc0\n"
    "\tlsls r1, r1, #1\n"
    "\tb .Ljp_080A177A\n"
    ".Ljp_080A174E:\n"
    "\tmovs r1, #0x82\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0x8c\n"
    "\tlsls r1, r1, #1\n"
    "\tb .Ljp_080A177A\n"
    ".Ljp_080A1760:\n"
    "\tmovs r1, #0x9f\n"
    "\tlsls r1, r1, #2\n"
    "\tb .Ljp_080A177A\n"
    ".Ljp_080A1766:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xd8\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xf0\n"
    "\tb .Ljp_080A177C\n"
    ".Ljp_080A1776:\n"
    "\tmovs r1, #0xa4\n"
    "\tlsls r1, r1, #2\n"
    ".Ljp_080A177A:\n"
    "\tadds r0, r4, r1\n"
    ".Ljp_080A177C:\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tb .Ljp_080A1798\n"
    ".Ljp_080A1784:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xb0\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xc4\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    ".Ljp_080A1798:\n"
    "\tpop {r4, r5, r6}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    "\n"
    "\tthumb_func_start ApplyDroppedItemFriendshipPenalty__13NpcCollectionRC8LocationRC14GameEventState\n"
    "ApplyDroppedItemFriendshipPenalty__13NpcCollectionRC8LocationRC14GameEventState: @ 0x080A1484\n"
    "\tpush {r4, r5, r6, lr}\n"
    "\tadds r4, r0, #0\n"
    "\tadds r6, r2, #0\n"
    "\tldrh r0, [r1]\n"
    "\tlsls r0, r0, #0x16\n"
    "\tlsrs r0, r0, #0x16\n"
    "\tcmp r0, #0x2a\n"
    "\tbls .L080A1496\n"
    "\tb .L080A1798\n"
    ".L080A1496:\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A14A0 @ =.L080A14A4\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A14A0: .word .L080A14A4\n"
    ".L080A14A4: @ jump table\n"
    "\t.word .L080A1550 @ case 0\n"
    "\t.word .L080A1550 @ case 1\n"
    "\t.word .L080A1798 @ case 2\n"
    "\t.word .L080A1550 @ case 3\n"
    "\t.word .L080A1550 @ case 4\n"
    "\t.word .L080A1550 @ case 5\n"
    "\t.word .L080A1550 @ case 6\n"
    "\t.word .L080A1550 @ case 7\n"
    "\t.word .L080A1550 @ case 8\n"
    "\t.word .L080A1798 @ case 9\n"
    "\t.word .L080A1636 @ case 10\n"
    "\t.word .L080A1636 @ case 11\n"
    "\t.word .L080A164E @ case 12\n"
    "\t.word .L080A1654 @ case 13\n"
    "\t.word .L080A165A @ case 14\n"
    "\t.word .L080A1678 @ case 15\n"
    "\t.word .L080A1678 @ case 16\n"
    "\t.word .L080A1798 @ case 17\n"
    "\t.word .L080A1798 @ case 18\n"
    "\t.word .L080A1696 @ case 19\n"
    "\t.word .L080A1696 @ case 20\n"
    "\t.word .L080A16A8 @ case 21\n"
    "\t.word .L080A16A8 @ case 22\n"
    "\t.word .L080A16A8 @ case 23\n"
    "\t.word .L080A16BA @ case 24\n"
    "\t.word .L080A16BA @ case 25\n"
    "\t.word .L080A16BA @ case 26\n"
    "\t.word .L080A16BA @ case 27\n"
    "\t.word .L080A16EC @ case 28\n"
    "\t.word .L080A1798 @ case 29\n"
    "\t.word .L080A173C @ case 30\n"
    "\t.word .L080A174E @ case 31\n"
    "\t.word .L080A174E @ case 32\n"
    "\t.word .L080A174E @ case 33\n"
    "\t.word .L080A174E @ case 34\n"
    "\t.word .L080A1798 @ case 35\n"
    "\t.word .L080A1760 @ case 36\n"
    "\t.word .L080A1798 @ case 37\n"
    "\t.word .L080A1766 @ case 38\n"
    "\t.word .L080A1798 @ case 39\n"
    "\t.word .L080A1776 @ case 40\n"
    "\t.word .L080A1784 @ case 41\n"
    "\t.word .L080A1784 @ case 42\n"
    ".L080A1550:\n"
    "\tmovs r5, #1\n"
    ".L080A1552:\n"
    "\tmovs r1, #1\n"
    "\tcmp r5, #0x21\n"
    "\tbeq .L080A1570\n"
    "\tcmp r5, #0x21\n"
    "\tbhi .L080A1562\n"
    "\tcmp r5, #0x20\n"
    "\tbeq .L080A1580\n"
    "\tb .L080A1582\n"
    ".L080A1562:\n"
    "\tcmp r5, #0x22\n"
    "\tbne .L080A1582\n"
    "\tadds r0, r6, #0\n"
    "\tadds r0, #0x3b\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x1b\n"
    "\tb .L080A1578\n"
    ".L080A1570:\n"
    "\tadds r0, r6, #0\n"
    "\tadds r0, #0x3a\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x19\n"
    ".L080A1578:\n"
    "\tlsrs r0, r0, #0x1e\n"
    "\tcmp r0, #2\n"
    "\tbeq .L080A1582\n"
    "\tb .L080A1598\n"
    ".L080A1580:\n"
    "\tmovs r1, #0\n"
    ".L080A1582:\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080A1598\n"
    "\tadds r0, r4, #0\n"
    "\tadds r1, r5, #0\n"
    "\tbl GetNpc__13NpcCollectionUi\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080A1598\n"
    "\tmovs r1, #1\n"
    "\tbl SubtractFriendship__3Npci\n"
    ".L080A1598:\n"
    "\tsubs r0, r5, #3\n"
    "\tcmp r0, #0x1c\n"
    "\tbhi .L080A162E\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L080A15A8 @ =.L080A15AC\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L080A15A8: .word .L080A15AC\n"
    ".L080A15AC: @ jump table\n"
    "\t.word .L080A1620 @ case 0\n"
    "\t.word .L080A162E @ case 1\n"
    "\t.word .L080A162E @ case 2\n"
    "\t.word .L080A162E @ case 3\n"
    "\t.word .L080A162E @ case 4\n"
    "\t.word .L080A162E @ case 5\n"
    "\t.word .L080A162E @ case 6\n"
    "\t.word .L080A162E @ case 7\n"
    "\t.word .L080A162E @ case 8\n"
    "\t.word .L080A1620 @ case 9\n"
    "\t.word .L080A162E @ case 10\n"
    "\t.word .L080A162E @ case 11\n"
    "\t.word .L080A162E @ case 12\n"
    "\t.word .L080A162E @ case 13\n"
    "\t.word .L080A162E @ case 14\n"
    "\t.word .L080A162E @ case 15\n"
    "\t.word .L080A1620 @ case 16\n"
    "\t.word .L080A162E @ case 17\n"
    "\t.word .L080A1620 @ case 18\n"
    "\t.word .L080A162E @ case 19\n"
    "\t.word .L080A162E @ case 20\n"
    "\t.word .L080A162E @ case 21\n"
    "\t.word .L080A1620 @ case 22\n"
    "\t.word .L080A162E @ case 23\n"
    "\t.word .L080A162E @ case 24\n"
    "\t.word .L080A162E @ case 25\n"
    "\t.word .L080A162E @ case 26\n"
    "\t.word .L080A162E @ case 27\n"
    "\t.word .L080A1620 @ case 28\n"
    ".L080A1620:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r1, r5, #0\n"
    "\tbl GetBachelorette__13NpcCollectionUi\n"
    "\tmovs r1, #0xc8\n"
    "\tbl SubtractLove__12Bachelorettei\n"
    ".L080A162E:\n"
    "\tadds r5, #1\n"
    "\tcmp r5, #0x2a\n"
    "\tbls .L080A1552\n"
    "\tb .L080A1798\n"
    ".L080A1636:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0x70\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0x84\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r4, #0x98\n"
    "\tb .L080A16D8\n"
    ".L080A164E:\n"
    "\tmovs r1, #0x8a\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A177A\n"
    ".L080A1654:\n"
    "\tmovs r1, #0xaa\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A177A\n"
    ".L080A165A:\n"
    "\tmovs r1, #0xca\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xd4\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0x84\n"
    "\tlsls r0, r0, #2\n"
    "\tb .L080A16D6\n"
    ".L080A1678:\n"
    "\tmovs r1, #0xde\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xe8\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0xf2\n"
    "\tlsls r0, r0, #1\n"
    "\tb .L080A16D6\n"
    ".L080A1696:\n"
    "\tmovs r1, #0xfe\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0x84\n"
    "\tlsls r0, r0, #2\n"
    "\tb .L080A16D6\n"
    ".L080A16A8:\n"
    "\tmovs r1, #0x94\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0x99\n"
    "\tlsls r0, r0, #2\n"
    "\tb .L080A16D6\n"
    ".L080A16BA:\n"
    "\tmovs r1, #0x96\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xa0\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r0, #0xaa\n"
    "\tlsls r0, r0, #1\n"
    ".L080A16D6:\n"
    "\tadds r4, r4, r0\n"
    ".L080A16D8:\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xfa\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, #0\n"
    "\tbl SubtractLove__12Bachelorettei\n"
    "\tb .L080A1798\n"
    ".L080A16EC:\n"
    "\tmovs r1, #0xcf\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xd8\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xe1\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xea\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xf3\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xfc\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tldr r1, .L080A1738 @ =0x00000414\n"
    "\tb .L080A177A\n"
    "\t.align 2, 0\n"
    ".L080A1738: .word 0x00000414\n"
    ".L080A173C:\n"
    "\tmovs r1, #0xb6\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0xc0\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A177A\n"
    ".L080A174E:\n"
    "\tmovs r1, #0x82\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r0, r4, r1\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tmovs r1, #0x8c\n"
    "\tlsls r1, r1, #1\n"
    "\tb .L080A177A\n"
    ".L080A1760:\n"
    "\tmovs r1, #0x9f\n"
    "\tlsls r1, r1, #2\n"
    "\tb .L080A177A\n"
    ".L080A1766:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xd8\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xf0\n"
    "\tb .L080A177C\n"
    ".L080A1776:\n"
    "\tmovs r1, #0xa4\n"
    "\tlsls r1, r1, #2\n"
    ".L080A177A:\n"
    "\tadds r0, r4, r1\n"
    ".L080A177C:\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tb .L080A1798\n"
    ".L080A1784:\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xb0\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xc4\n"
    "\tmovs r1, #5\n"
    "\tbl SubtractFriendship__3Npci\n"
    ".L080A1798:\n"
    "\tpop {r4, r5, r6}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    "\n"
#endif
);
