/*
 * Harvest Moon: Friends of Mineral Town (JP, revision 0) ROM layout.
 *
 * This is a static linker script for the normal source/object build.  Its
 * ROM placements were verified against baserom_jp.gba before being recorded;
 * do not replace the object list with a whole-ROM incbin.
 */

OUTPUT_ARCH(arm)

_M4aNumMusicPlayers = 5;
_M4aMaxLines = 0x50;

/* Verified against the JP m4a tables in baserom_jp.gba. */
gMPlayJumpTableTemplate = 0x0813ABCC;
gScaleTable = 0x0813AC5C;
gFreqTable = 0x0813AD10;
gPcmSamplesPerVBlankTable = 0x0813AD40;
gCgbScaleTable = 0x0813AD58;
gCgbFreqTable = 0x0813ADDC;
gNoiseTable = 0x0813ADF4;
gCgb3Vol = 0x0813AE30;
gClockTable = 0x0813AE40;
gXcmdTable = 0x0813AE74;

MEMORY
{
    EWRAM (w!x) : ORIGIN = 0x02000000, LENGTH = 256K
    IWRAM (w!x) : ORIGIN = 0x03000000, LENGTH = 32K
    ROM   (rx)  : ORIGIN = 0x08000000, LENGTH = 32M
}

SECTIONS
{
    .ewram_bss (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/sound_data.o(.sbss);
        . = ALIGN(4); src/m4a.o(.gSoundInfo);
        . = ALIGN(4); src/m4a.o(.gMPlayJumpTable);
        . = ALIGN(4); src/m4a.o(.gCgbChans);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerA);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerB);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerC);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerE);
        . = ALIGN(4); src/m4a.o(.gMPlayMemAccArea);
        . = ALIGN(4); src/m4a.o(.gMusicPlayerD);
        __ewram_bss_end = .;
    } > EWRAM

    .bss (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/m4a.o(.bss);
        . = ALIGN(4);
        . = 0x000400; gUnk_03000400 = .;
        . = 0x000402; gUnk_03000402 = .;
        . = 0x000404; gUnk_03000404 = .;
        . = 0x000408; gUnk_03000408 = .;
        . = 0x00040C; gUnk_0300040C = .;
        . = 0x000410; gUnk_03000410 = .;
        . = 0x000414; gUnk_03000414 = .;
        . = 0x000418; gUnk_03000418 = .;
        . = 0x00041C; gUnk_0300041C = .;
        . = 0x000420; gUnk_03000420 = .;
        . = 0x000430; gUnk_03000430 = .;
        . = 0x000450; gUnk_03000450 = .;
        . = 0x000490; /* end */
    } > IWRAM

    .rom : ALIGN(4)
    {
        . = 0x0; /* JP ROM 0x08000000, independently matched */
        src/crt0.o(.rom_header);
        . = 0x18C; /* JP ROM 0x0800018C, independently matched */
        asm/main.o(.text);
        . = 0x2E0; /* JP ROM 0x080002E0, independently matched */
        asm/sram_proxy_1.o(.text);
        . = 0x4C4; /* JP ROM 0x080004C4, independently matched */
        asm/interrupt.o(.text);
        . = 0x59C; /* JP ROM 0x0800059C, independently matched */
        src/new.o(.text);
        src/pure_virtual.o(.text);
        . = 0x63C; /* JP ROM 0x0800063C, independently matched */
        asm/sram_proxy_2.o(.text);
        . = 0x7EC; /* JP ROM 0x080007EC, independently matched */
        src/scene.o(.text);
        . = 0x82C; /* JP ROM 0x0800082C, independently matched */
        asm/scene.o(.text);
        . = 0x914; /* JP ROM 0x08000914, independently matched */
        asm/intro_scene.o(.text);
        . = 0x37A0; /* JP ROM 0x080037A0, independently matched */
        asm/new_game.o(.text);
        . = 0x7130; /* JP ROM 0x08007130, independently matched */
        src/hardware.o(.text);
        . = 0x7374; /* JP ROM 0x08007374, independently matched */
        asm/hardware.o(.text);
        . = 0x9A50; /* JP ROM 0x08009A50, independently matched */
        src/farm.o(.text);
        . = 0x9F94; /* JP ROM 0x08009F94, independently matched */
        src/field.o(.text);
        . = 0xB0BC; /* JP ROM 0x0800B0BC, independently matched */
        src/shipping_bin.o(.text);
        . = 0xB2CC; /* JP ROM 0x0800B2CC, independently matched */
        src/tool_chest.o(.text);
        . = 0xB640; /* JP ROM 0x0800B640, independently matched */
        src/fridge.o(.text);
        . = 0xB8C4; /* JP ROM 0x0800B8C4, independently matched */
        src/shelf.o(.text);
        . = 0xBB40; /* JP ROM 0x0800BB40, independently matched */
        src/record_player.o(.text);
        . = 0xBC38; /* JP ROM 0x0800BC38, independently matched */
        src/code_0800BC58.o(.text);
        . = 0xBE50; /* JP ROM 0x0800BE50, independently matched */
        src/farm_house.o(.text);
        . = 0xC430; /* JP ROM 0x0800C430, independently matched */
        src/coop.o(.text);
        . = 0xCD9C; /* JP ROM 0x0800CD9C, independently matched */
        src/barn.o(.text);
        . = 0xDB0C; /* JP ROM 0x0800DB0C, independently matched */
        src/item.o(.text);
        . = 0xE2C4; /* JP ROM 0x0800E2C4, independently matched */
        src/code_0800E2E4.o(.text);
        . = 0xE334; /* JP ROM 0x0800E334, independently matched */
        src/farmer.o(.text);
        . = 0xEFCC; /* JP ROM 0x0800EFCC, independently matched */
        src/rucksack_item.o(.text);
        . = 0xF150; /* JP ROM 0x0800F150, independently matched */
        src/held_item.o(.text);
        . = 0xF554; /* JP ROM 0x0800F554, independently matched */
        src/rucksack.o(.text);
        . = 0xFF6C; /* JP ROM 0x0800FF6C, independently matched */
        asm/more_items.o(.text);
        . = 0x1002C; /* JP ROM 0x0801002C, independently matched */
        asm/game_scene.o(.text);
        . = 0x10328; /* JP ROM 0x08010328, bounded by game_scene and entity */
        asm/game_state.o(.text);
        . = 0x1FB0C; /* JP ROM 0x0801FB0C, independently matched */
        src/entity.o(.text);
        . = 0x1FDAC; /* JP ROM 0x0801FDAC, independently matched */
        src/code_entity_08020018.o(.text);
        . = 0x1FDF4; /* JP ROM 0x0801FDF4, independently matched */
        asm/code_entities.o(.text);
        . = 0x31E70; /* JP ROM 0x08031E70, independently matched */
        src/entity_actor.o(.text);
        . = 0x321C0; /* JP ROM 0x080321C0, independently matched */
        asm/code_entities_080320DC.o(.text);
        . = 0x34A80; /* JP ROM 0x08034A80, independently matched */
        src/npc_entity.o(.text);
        . = 0x35114; /* JP ROM 0x08035114, independently matched */
        asm/code_entities_08034CEC.o(.text);

        . = 0x3A518; /* JP ROM 0x0803A518, independently matched */

        asm/code_0803A8A4.o(.text);
        . = 0x3BB78; /* JP counterpart of US function 0x0803BDE4. */
        src/code_0803BDE4.o(.text);
        . = 0x3BB90; /* JP ROM 0x0803BDFC, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BDFC);
        . = 0x3BC30; /* JP counterpart of US function 0x0803BE9C. */
        src/code_0803BE9C.o(.text);
        . = 0x3BC44; /* JP counterparts of US functions 0x0803BEB0..0x0803BEC8. */
        src/code_0803BEB0.o(.text);
        . = 0x3BC68; /* JP counterparts of US functions 0x0803BED4/0x0803BEE0. */
        src/code_0803BED4.o(.text);
        . = 0x3BC80; /* JP counterparts of US functions 0x0803BEEC/0x0803BEF4. */
        src/code_0803BEEC.o(.text);
        . = 0x3BC90; /* JP counterparts of US functions 0x0803BEFC/0x0803BF08. */
        src/code_0803BEFC.o(.text);
        . = 0x3BCA8; /* JP ROM 0x0803BF14, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803BF14);
        . = 0x3C2AC; /* JP counterparts of US functions 0x0803C518/0x0803C52C. */
        src/code_0803C518.o(.text);
        . = 0x3C2D4; /* JP counterparts of US functions 0x0803C540/0x0803C544. */
        src/code_0803C540.o(.text);
        . = 0x3C2E0; /* JP ROM 0x0803C54C, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803C54C);
        . = 0x3E080; /* JP counterpart of shared schedule gate func_0803E40C. */
        src/code_0803E40C.o(.text);
        . = 0x3E0BC; /* JP ROM 0x0803E448, remaining raw control code */
        asm/code_0803A8A4.o(.text.code_0803E448);
        . = 0x3EB08; /* JP ROM 0x0803EB08, independently matched */
        src/script_engine.o(.text);
        . = 0x3F704; /* JP ROM 0x0803F704, independently matched */
        asm/code_0803EE94.o(.text);
        . = 0x50AE8; /* JP counterpart of shared first-field forwarding adapters. */
        src/code_08050D5C.o(.text);
        . = 0x50B18; /* JP counterpart of shared argument-normalizing forwarding adapters. */
        src/code_08050D8C.o(.text);
        . = 0x50B64; /* JP counterpart of shared first-field status-byte adapters. */
        src/code_08050DD8.o(.text);
        . = 0x50B7C; /* JP counterpart of shared first-field query adapter. */
        src/code_08050DF0.o(.text);
        . = 0x50B98; /* JP counterpart of shared long-argument forwarding adapters. */
        src/code_08050E0C.o(.text);
        . = 0x50BDC; /* JP counterpart of shared first-field UI-adjacent adapters. */
        src/code_08050E50.o(.text);
        . = 0x50C24; /* JP counterpart of shared first-field UI-flag adapters. */
        src/code_08050E98.o(.text);
        . = 0x50C70; /* JP ROM 0x08050C70, remaining raw UI-adjacent code. */
        asm/code_0803EE94.o(.text.code_08050E50);

        . = 0x9AB3C; /* JP ROM 0x0809AB3C, independently matched */

        src/actor.o(.text);
        . = 0x9AB64; /* JP ROM 0x0809AB64, independently matched */
        src/animal.o(.text);
        . = 0x9AD64; /* JP ROM 0x0809AD64, independently matched */
        src/pet.o(.text);
        . = 0x9AE8C; /* JP ROM 0x0809AE8C, independently matched */
        src/livestock.o(.text);
        . = 0x9B260; /* JP ROM 0x0809B260, independently matched */
        src/barn_animal.o(.text);
        . = 0x9B40C; /* JP ROM 0x0809B40C, independently matched */
        src/dog.o(.text);
        . = 0x9B608; /* JP ROM 0x0809B608, independently matched */
        src/horse.o(.text);
        . = 0x9B69C; /* JP ROM 0x0809B69C, independently matched */
        src/chicken.o(.text);
        . = 0x9B780; /* JP ROM 0x0809B780, independently matched */
        src/cow.o(.text);
        . = 0x9B8CC; /* JP ROM 0x0809B8CC, independently matched */
        src/sheep.o(.text);
        . = 0x9BA20; /* JP ROM 0x0809BA20, independently matched */
        src/code_actor_0809BFE8.o(.text);
        . = 0x9BB98; /* JP ROM 0x0809BB98, unlabelled raw helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C160);
        . = 0x9BC64; /* JP ROM 0x0809BC64, shared selector */
        src/code_actor_0809C22C.o(.text);
        . = 0x9BD3C; /* JP ROM 0x0809BD3C, shared table accessor */
        src/code_actor_0809C304.o(.text);
        . = 0x9BD50; /* JP ROM 0x0809BD50, raw actor helper */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C318);
        . = 0x9BD64; /* JP ROM 0x0809BD64, shared paired-state predicate */
        src/code_actor_0809C32C.o(.text);
        . = 0x9BDC4; /* JP ROM 0x0809BDC4, shared nonzero-state predicate */
        src/code_actor_0809C38C.o(.text);
        . = 0x9BDF4; /* JP ROM 0x0809BDF4, shared state initializer */
        src/code_actor_0809C3BC.o(.text);
        . = 0x9BE18; /* JP ROM 0x0809BE18, shared state advancement */
        src/code_actor_0809C3E0.o(.text);
        . = 0x9BE58; /* JP ROM 0x0809BE58, shared state reset */
        src/code_actor_0809C420.o(.text);
        . = 0x9BE7C; /* JP ROM 0x0809BE7C, shared conditional state advance */
        src/code_actor_0809C444.o(.text);
        . = 0x9BEAC; /* JP ROM 0x0809BEAC, shared state-update dispatcher */
        src/code_actor_0809C474.o(.text);
        . = 0x9BEEC; /* JP ROM 0x0809BEEC, shared state-update dispatcher */
        src/code_actor_0809C4B4.o(.text);
        . = 0x9BF1C; /* JP ROM 0x0809BF1C, shared word clear */
        src/code_actor_0809C4E4.o(.text);
        . = 0x9BF24; /* JP ROM 0x0809BF24, shared selection helper and raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C4EC);
        . = 0x9BFEC; /* JP ROM 0x0809BFEC, set bounded flag */
        src/code_actor_0809C5B4.o(.text);
        . = 0x9C008; /* JP ROM 0x0809C008, clear bounded flag */
        src/code_actor_0809C5D0.o(.text);
        . = 0x9C024; /* JP ROM 0x0809C024, clear flag word */
        src/code_actor_0809C5EC.o(.text);
        . = 0x9C02C; /* JP ROM 0x0809C02C, test flag word */
        src/code_actor_0809C5F4.o(.text);
        . = 0x9C038; /* JP ROM 0x0809C038, register event-state variable */
        src/code_actor_0809C600.o(.text);
        . = 0x9C07C; /* JP ROM 0x0809C07C, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C644);
        . = 0x9C0CC; /* JP ROM 0x0809C0CC, compare selected u16 */
        src/code_actor_0809C694.o(.text);
        . = 0x9C0E4; /* JP ROM 0x0809C0E4, set selected u16 */
        src/code_actor_0809C6AC.o(.text);
        . = 0x9C0E8; /* JP ROM 0x0809C0E8, reset selected u16 */
        src/code_actor_0809C6B0.o(.text);
        . = 0x9C0F4; /* JP ROM 0x0809C0F4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809C6BC);
        . = 0x9C7B0; /* JP ROM 0x0809CD78, clear tracked counters */
        src/code_actor_0809CD78.o(.text);
        . = 0x9C7D0; /* JP ROM 0x0809C7D0, update count and maximum */
        src/code_actor_0809CD98.o(.text);
        . = 0x9C804; /* JP ROM 0x0809C804, test tracked counts */
        src/code_actor_0809CDCC.o(.text);
        . = 0x9C824; /* JP ROM 0x0809C824, sum tracked counts */
        src/code_actor_0809CDEC.o(.text);
        . = 0x9C854; /* JP ROM 0x0809C854, get record count */
        src/code_actor_0809CE1C.o(.text);
        . = 0x9C85C; /* JP ROM 0x0809C85C, get record maximum */
        src/code_actor_0809CE24.o(.text);
        . = 0x9C868; /* JP ROM 0x0809C868, map six input codes */
        src/code_actor_0809CE30.o(.text);
        . = 0x9C8B4; /* JP ROM 0x0809C8B4, get fishing-record name */
        src/code_actor_0809CE7C.o(.text);
        . = 0x9C8C4; /* JP ROM 0x0809C8C4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809CE8C);
        . = 0x9CE50; /* JP ROM 0x0809D418, map a segmented input value */
        src/code_actor_0809D418.o(.text);
        . = 0x9CEA8; /* JP ROM 0x0809D470, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D470);
        . = 0x9D210; /* JP ROM 0x0809D7D8, classify actor-state value */
        src/code_actor_0809D7D8.o(.text);
        . = 0x9D2D8; /* JP ROM 0x0809D8A0, read state value */
        src/code_actor_0809D8A0.o(.text);
        . = 0x9D2DC; /* JP ROM 0x0809D8A4, map one state value */
        src/code_actor_0809D8A4.o(.text);
        . = 0x9D2F0; /* JP ROM 0x0809D8B8, map two state values */
        src/code_actor_0809D8B8.o(.text);
        . = 0x9D30C; /* JP ROM 0x0809D8D4, read packed grid-cell value */
        src/code_actor_0809D8D4.o(.text);
        . = 0x9D320; /* JP ROM 0x0809D8E8, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809D8E8);
        . = 0x9D964; /* JP counterpart of US function 0x0809DF2C. */
        src/code_actor_0809DF2C.o(.text);
        . = 0x9D9E4; /* JP ROM 0x0809DFAC, count actor-state flag bits */
        src/code_actor_0809DFAC.o(.text);
        . = 0x9DA64; /* JP ROM 0x0809E02C, count actor-state flag bits */
        src/code_actor_0809E02C.o(.text);
        . = 0x9DAE4; /* JP ROM 0x0809E0AC, select actor-state cell-type data */
        src/code_actor_0809E0AC.o(.text);
        . = 0x9DB50; /* JP ROM 0x0809E118, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E118);
        . = 0x9DBAC; /* JP ROM 0x0809E174, read actor-state bit 0 */
        src/code_actor_0809E174.o(.text);
        . = 0x9DBBC; /* JP ROM 0x0809E184, read actor-state bit 2 */
        src/code_actor_0809E184.o(.text);
        . = 0x9DBCC; /* JP ROM 0x0809E194, read actor-state bit 3 */
        src/code_actor_0809E194.o(.text);
        . = 0x9DBDC; /* JP ROM 0x0809E1A4, read actor-state bit 4 */
        src/code_actor_0809E1A4.o(.text);
        . = 0x9DBEC; /* JP ROM 0x0809E1B4, remaining raw actor code */
        asm/code_actor_0809BFE8.o(.text.code_actor_0809E1B4);
        . = 0x9DD0C; /* JP ROM 0x0809DD0C, independently matched */
        src/npc.o(.text);
        . = 0x9DE90; /* JP ROM 0x0809DE90, independently matched */
        src/bachelorette.o(.text);
        . = 0x9E060; /* JP ROM 0x0809E060, independently matched */
        src/harvest_sprite.o(.text);

        . = 0x9E23C; /* JP ROM 0x0809E23C, independently matched */

        asm/code_809E804.o(.text);
        . = 0x9E504; /* JP counterpart of shared NPC runtime fields. */
        src/npc_runtime_data.o(.text);
        . = 0x9E530; /* JP ROM 0x0809E530, remaining raw NPC runtime code. */
        asm/code_809E804.o(.text.npc_runtime_data_after);

        . = 0xD0D4C; /* JP ROM 0x080D0D4C, independently matched */

        src/m4a_1.o(.text);
        . = 0xD1968; /* JP ROM 0x080D1968, independently matched */
        src/m4a.o(.text);
        . = 0xD2F00; /* JP ROM 0x080D2F00, independently matched */
        asm/code_lib_syscall.o(.text);
        . = 0xD2F30; /* JP ROM 0x080D2F30, independently matched */
        asm/code_lib_sram.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        /* these need to be recompiled using -mthumb-interwork */
        /* *libc.a:memcmp.o(.text); */
        /* *libc.a:memcpy.o(.text); */
        /* *libc.a:memmove.o(.text); */
        /* *libc.a:memset.o(.text); */
        /* *libc.a:strcat.o(.text); */
        /* *libc.a:strcpy.o(.text); */
        /* *libc.a:strlen.o(.text); */
        . = 0xD3100; /* JP ROM 0x080D3100, independently matched */
        asm/code_libc_string.o(.text);

        . = 0xD3378; /* JP ROM 0x080D3378, independently matched */

        asm/code_linkonce.o(.text.code_080D3BC0);
        *(.gnu.linkonce.t.__as__6AnimalRC6Animal);
        . = 0xD6078; /* JP ROM 0x080D6078, independently matched */
        asm/code_linkonce.o(.text.code_080D68C0);
        *(.gnu.linkonce.t.__as__5SheepRC5Sheep);
        *(.gnu.linkonce.t.__as__3CowRC3Cow);
        *(.gnu.linkonce.t.__as__9LivestockRC9Livestock);
        *(.gnu.linkonce.t.push_back__t8FixedVec2Z12RucksackItemUl8G12RucksackItem);
        *(.gnu.linkonce.t.push_front__t8FixedVec2Z12RucksackItemUl8G12RucksackItem);
        *(.gnu.linkonce.t.push_back__t8FixedVec2Z9ToolStackUl8G9ToolStack);
        *(.gnu.linkonce.t.push_front__t8FixedVec2Z9ToolStackUl8G9ToolStack);
        . = 0xD761C; /* JP ROM 0x080D761C, direct function match */
        asm/code_linkonce.o(.text.code_080D7CFC);
        *(.gnu.linkonce.t.__lower_bound__H4ZPC12JumpTableEntZiZ28ScriptJumpTableSearchCompareZl_X01T0RCX11X21PX31_X01);
        . = 0xE0690; /* JP ROM 0x080E0690, independently matched */
        asm/code_linkonce.o(.text.code_080E0EF0);

        . = 0xE4E0C; /* JP C++ table region begins after code_linkonce. */
        asm/vtables.o(.rodata);

        . = 0xE7A40; /* JP data_080E8610 begins after the C++ table region. */
        asm/data/data_080E8610.o(.rodata);
        data/text/common/sram_signature.o(.rodata.sram_signature);
        asm/data/data_080E8610.o(.rodata.sram_signature_trailer);
        . = ALIGN(4); src/new_game_menu_data.o(.rodata);
        . = ALIGN(4); data/text/new_game_status.o(.rodata.new_game_status_labels);
        . = ALIGN(4); data/text/new_game_help.o(.rodata.new_game_help_text);
        . = ALIGN(4); data/text/new_game_save.o(.rodata.new_game_save_text);
        . = 0xE7D80; /* JP raw data after the regional new-game save text. */
        asm/data/data_080E8610.o(.rodata.new_game_save_trailer);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_prefix);
        . = 0xE7DAC; /* JP runtime data between identity text groups. */
        asm/data/data_080E8610.o(.rodata.new_game_identity_prefix_trailer);
        . = ALIGN(4); data/text/new_game_identity.o(.rodata.new_game_identity_labels);
        . = 0xE7E24; /* JP raw data after the regional identity labels. */
        asm/data/data_080E8610.o(.rodata.new_game_identity_labels_trailer);
        data/text/new_game_name_entry.o(.rodata.new_game_name_entry_characters);
        data/text/new_game_name_entry_ui.o(.rodata.new_game_name_entry_ui);
        . = 0xE80EC; /* JP data after the regional name-entry UI fields. */
        asm/data/data_080E8610.o(.rodata.new_game_name_entry_trailer);
        asm/data/data_080E8610.o(.rodata.field_plot_prefix);
        src/field_data.o(.rodata.field_plot_weather_ordinary);
        src/field_data.o(.rodata.field_plot_weather_special_3);
        src/field_data.o(.rodata.field_plot_weather_special_4);
        src/field_data.o(.rodata.field_plot_growth_transitions);
        src/field_data.o(.rodata.field_plot_definitions);
        . = 0xE8A6C; /* JP ROM 0x080E8A6C, independently matched */
        src/shipping_bin.o(.rodata);
        src/record_player.o(.rodata);
        . = 0xE8AB4; /* JP item tables begin here. */
        src/item.o(.rodata);
        data/text/tool.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/item.o(.rodata.item_tool);
        FILL(0xFF);
        data/text/food.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/item.o(.rodata.item_food);
        FILL(0xFF);
        data/text/article.o(.rodata);
        FILL(0x00);
        . = ALIGN(4);
        src/item.o(.rodata.item_article);
        FILL(0xFF);
        src/item.o(.rodata.item_product);
        . = 0xEFD48; /* JP counterpart of data_080F0348. */
        asm/data/data_080F0348.o(.rodata);
        FILL(0x00);
        data/text/calendar.o(.rodata.calendar.season);
        data/text/calendar.o(.rodata.calendar.none);
        data/text/calendar.o(.rodata.calendar.weekday);
        . = 0xEFD78; /* JP data after the calendar text arrays. */
        asm/data/data_080F0348.o(.rodata.calendar_trailer);
        FILL(0x00);
        data/text/load_error.o(.rodata.load_error);
        . = 0xEFDDC; /* JP data after the load-failure text. */
        asm/data/data_080F0348.o(.rodata.load_error_trailer);
        FILL(0x00);
        data/text/help_menu.o(.rodata.help_menu);
        . = 0xEFE2B; /* JP data after the four help-menu labels. */
        asm/data/data_080F0348.o(.rodata.help_menu_trailer);
        FILL(0x00);
        data/text/animal_memorial.o(.rodata.animal_memorial);
        . = 0xEFF44; /* JP data after the animal memorial text pieces. */
        asm/data/data_080F0348.o(.rodata.animal_memorial_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/not_available.o(.rodata.not_available);
        asm/data/data_080F0348.o(.rodata.not_available_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/fixed_labels.o(.rodata.fixed_labels);
        . = 0xF11F0; /* JP runtime bytes after the two fixed labels. */
        asm/data/data_080F0348.o(.rodata.fixed_labels_trailer);
        FILL(0x00);
        . = ALIGN(4); data/text/common/ui_error.o(.rodata.ui_error);
        asm/data/data_080F0348.o(.rodata.ui_error_trailer);
        FILL(0x00);
        . = ALIGN(4); src/menu_data.o(.rodata.menu_entry_ids);
        FILL(0x00);
        . = ALIGN(4); data/text/menu.o(.rodata.menu_labels);
        FILL(0x00);
        . = ALIGN(4); src/menu_data.o(.rodata.menu_label_pointers);
        FILL(0xFF);
        . = ALIGN(4); asm/data/data_080F0348.o(.rodata.menu_data_trailer);
        FILL(0xFF);
        . = 0xF12DC; /* JP schedule table block. */
        src/data_schedules.o(.rodata);
        . = 0xF1810; /* JP counterpart of data_080F1A80. */
        asm/data/data_080F1A80.o(.rodata);
        . = 0xF96F4; /* JP ScriptEngine string object. */
        src/script_engine.o(.rodata);
        . = 0xF9708; /* JP localized non-script data before event RIFFs. */
        asm/data/data_080F9EB8.o(.rodata.localized_data_prefix);
        . = 0xF97E6; data/text/festival_contestants.o(.rodata.festival_contestants_set0);
        . = 0xF996C; asm/data/data_080F9EB8.o(.rodata.festival_contestants_set0_trailer_prefix);
        . = 0xF9994; data/text/frisbee.o(.rodata.frisbee_scoreboard);
        . = 0xF99AB; asm/data/data_080F9EB8.o(.rodata.frisbee_scoreboard_trailer);
        . = 0xF9BD4; data/text/frisbee.o(.rodata.frisbee);
        . = 0xF9F4F; asm/data/data_080F9EB8.o(.rodata.frisbee_text_trailer);
        . = 0xF9FD6; data/text/festival_contestants.o(.rodata.festival_contestants_set1);
        . = 0xFA1DE; asm/data/data_080F9EB8.o(.rodata.festival_contestants_set1_trailer_prefix);
        . = 0xFA280; data/text/horse_race.o(.rodata.horse_race_dialogue);
        . = 0xFA712; asm/data/data_080F9EB8.o(.rodata.horse_race_dialogue_trailer);
        . = 0xFA73C; data/text/horse_race.o(.rodata.horse_race_ticket_ui);
        . = 0xFA860; src/horse_race_data.o(.rodata.horse_race_ticket_controls);
        . = 0xFA88C; asm/data/data_080F9EB8.o(.rodata.horse_race_ticket_controls_trailer_prefix);
        . = 0xFA898; data/text/horse_race_prizes.o(.rodata.horse_race_prize_catalog);
        . = 0xFA988; asm/data/data_080F9EB8.o(.rodata.horse_race_prize_catalog_trailer_prefix);
        . = 0xFA9A0; data/text/horse_race_prizes.o(.rodata.horse_race_prize_exchange);
        . = 0xFAA37; asm/data/data_080F9EB8.o(.rodata.horse_race_prize_exchange_padding);
        . = 0xFAA38; asm/data/data_080F9EB8.o(.rodata.horse_race_prize_exchange_trailer_prefix);
        . = 0xFB11C; data/text/farm_status.o(.rodata);
        . = 0xFB224; asm/data/data_080F9EB8.o(.rodata.farm_status_trailer_prefix);
        . = 0xFB230; data/text/animal_contest.o(.rodata.animal_contest_status_prefix);
        . = 0xFB24C; data/text/animal_contest.o(.rodata.animal_contest_status);
        . = 0xFB27C; data/text/animal_contest.o(.rodata.animal_contest);
        . = 0xFB618; asm/data/data_080F9EB8.o(.rodata.animal_contest_bad_alloc);
        . = 0xFB624; data/text/animal_contest.o(.rodata.animal_contest_confirmation);
        . = 0xFB643; asm/data/data_080F9EB8.o(.rodata.animal_contest_confirmation_padding);
        . = 0xFB644; asm/data/data_080F9EB8.o(.rodata.animal_contest_trailer);
        . = 0xFB764; data/text/records.o(.rodata);
        . = 0xFB8B8; asm/data/data_080F9EB8.o(.rodata.records_trailer);
        . = 0xFB938; data/text/staff_credits.o(.rodata.staff_credits);
        . = 0xFBE88; asm/data/data_080F9EB8.o(.rodata.staff_credits_trailer_prefix);
        . = 0xFBE9C; data/text/town_map.o(.rodata);
        . = 0xFC7E5; asm/data/data_080F9EB8.o(.rodata.town_map_padding);
        . = 0xFC7E8; asm/data/data_080F9EB8.o(.rodata.town_map_trailer);
        . = 0xFCCB8; data/text/library.o(.rodata.library_info);
        . = 0xFCCF3; asm/data/data_080F9EB8.o(.rodata.library_info_trailer);
        . = 0xFD0B0; data/text/library.o(.rodata.library_menu);
        . = 0xFD0C2; asm/data/data_080F9EB8.o(.rodata.library_menu_trailer);
        . = 0xFD0D0; data/text/poultry_shop.o(.rodata.poultry_shop_menu);
        . = 0xFD0E9; asm/data/data_080F9EB8.o(.rodata.poultry_shop_menu_padding);
        . = 0xFD0EC; src/poultry_shop_data.o(.rodata.poultry_shop_catalog);
        . = 0xFD150; data/text/poultry_shop.o(.rodata.poultry_shop_status_prefix);
        . = 0xFD152; asm/data/data_080F9EB8.o(.rodata.poultry_shop_status_prefix_padding);
        . = 0xFD154; data/text/poultry_shop.o(.rodata.poultry_shop_status);
        . = 0xFD1E3; asm/data/data_080F9EB8.o(.rodata.poultry_shop_status_padding);
        . = 0xFD1E4; data/text/poultry_shop.o(.rodata.poultry_shop_dialogue);
        . = 0xFD552; asm/data/data_080F9EB8.o(.rodata.poultry_shop_trailer);
        . = 0xFD560; src/supermarket_data.o(.rodata.supermarket_crop_catalog);
        . = 0xFD5C8; data/text/supermarket.o(.rodata.supermarket_primary_text);
        . = 0xFD708; src/supermarket_data.o(.rodata.supermarket_additional_seed_catalog);
        . = 0xFD748; data/text/supermarket.o(.rodata.supermarket_secondary_text);
        . = 0xFD804; asm/data/data_080F9EB8.o(.rodata.supermarket_trailer);
        . = 0xFD810; src/clinic_data.o(.rodata.clinic_catalog);
        . = 0xFD830; data/text/clinic.o(.rodata.clinic_text);
        . = 0xFD9D6; asm/data/data_080F9EB8.o(.rodata.clinic_text_padding);
        . = 0xFD9D8; asm/data/data_080F9EB8.o(.rodata.inn_shop_prefix);
        . = 0xFD9E4; data/text/inn_shop.o(.rodata.inn_shop_descriptions);
        FILL(0x00);
        . = 0xFDA54; src/inn_shop_data.o(.rodata.inn_shop_catalog);
        . = 0xFDB50; data/text/inn_shop.o(.rodata.inn_shop_dialogue);
        . = 0xFDBE4; asm/data/data_080F9EB8.o(.rodata.inn_shop_trailer);
        . = 0xFDBF0; src/won_shop_data.o(.rodata.won_shop_catalog);
        . = 0xFDC40; data/text/won_shop.o(.rodata.won_shop_dialogue);
        . = 0xFDEA2; asm/data/data_080F9EB8.o(.rodata.won_shop_post_dialogue_padding);
        . = 0xFDEA4; data/text/won_shop.o(.rodata.won_shop_delivery_dialogue);
        . = 0xFDF90; asm/data/data_080F9EB8.o(.rodata.won_shop_trailer);
        . = 0xFDF9C; src/winery_shop_data.o(.rodata.winery_shop_catalog);
        . = 0xFDFAC; data/text/winery_shop.o(.rodata.winery_shop_dialogue);
        . = 0xFE178; asm/data/data_080F9EB8.o(.rodata.winery_shop_trailer);
        . = 0xFE184; src/special_merchant_shop_data.o(.rodata.special_merchant_shop_catalog);
        . = 0xFE1FC; data/text/special_merchant_shop.o(.rodata.special_merchant_shop_text);
        . = 0xFE394; asm/data/data_080F9EB8.o(.rodata.special_merchant_shop_trailer);
        . = 0xFE3A0; data/text/beach_cafe_shop.o(.rodata.beach_cafe_shop_descriptions);
        . = 0xFE414; src/beach_cafe_shop_data.o(.rodata.beach_cafe_shop_catalog);
        . = 0xFE4A0; data/text/beach_cafe_shop.o(.rodata.beach_cafe_shop_dialogue);
        . = 0xFE530; asm/data/data_080F9EB8.o(.rodata.beach_cafe_shop_trailer);
        . = 0xFE53C; data/text/blacksmith.o(.rodata.blacksmith_menu);
        . = 0xFE6A0; asm/data/data_080F9EB8.o(.rodata.blacksmith_menu_padding);
        FILL(0xFF);
        . = 0xFE6A4; src/blacksmith_data.o(.rodata.blacksmith_catalog);
        . = 0xFE77C; data/text/blacksmith.o(.rodata.blacksmith_dialogue);
        . = 0xFEC84; asm/data/data_080F9EB8.o(.rodata.carpenter_menu_prefix);
        FILL(0x00);
        . = 0xFEC90; data/text/carpenter.o(.rodata.carpenter_menu);
        . = 0xFF084; src/carpenter_data.o(.rodata.carpenter_catalog);
        FILL(0xFF);
        . = 0xFF214; asm/data/data_080F9EB8.o(.rodata.carpenter_catalog_trailer);
        FILL(0x00);
        . = 0xFF218; data/text/carpenter.o(.rodata.carpenter_dialogue);
        . = 0xFF4FC; asm/data/data_080F9EB8.o(.rodata.carpenter_trailer);
        FILL(0xFF);
        . = 0xFF508; data/text/livestock_shop.o(.rodata.livestock_shop_menu);
        . = 0xFF539; asm/data/data_080F9EB8.o(.rodata.livestock_shop_menu_padding);
        . = 0xFF53C; src/livestock_shop_data.o(.rodata.livestock_shop_catalog);
        . = 0xFF618; data/text/livestock_shop.o(.rodata.livestock_shop_status_prefix);
        . = 0xFF61A; asm/data/data_080F9EB8.o(.rodata.livestock_shop_status_prefix_padding);
        . = 0xFF61C; data/text/livestock_shop.o(.rodata.livestock_shop_status);
        . = 0xFF6C3; asm/data/data_080F9EB8.o(.rodata.livestock_shop_status_padding);
        . = 0xFF6C4; data/text/livestock_shop.o(.rodata.livestock_shop_dialogue);
        . = 0xFF9A2; asm/data/data_080F9EB8.o(.rodata.livestock_shop_dialogue_padding);
        . = 0xFF9A4; asm/data/data_080F9EB8.o(.rodata.home_storage_prefix);
        FILL(0x00);
        . = 0xFF9B4; data/text/home_storage.o(.rodata.home_storage_fridge);
        . = 0xFFA14; asm/data/data_080F9EB8.o(.rodata.home_storage_fridge_trailer);
        . = 0xFFA20; data/text/home_storage.o(.rodata.home_storage_confirmation);
        . = 0xFFA30; asm/data/data_080F9EB8.o(.rodata.home_storage_confirmation_padding);
        . = 0xFFA34; data/text/home_storage.o(.rodata.home_storage_tool_chest_category);
        . = 0xFFA44; asm/data/data_080F9EB8.o(.rodata.home_storage_tool_chest_category_trailer);
        . = 0xFFA54; data/text/home_storage.o(.rodata.home_storage_shelf);
        . = 0xFFAB4; asm/data/data_080F9EB8.o(.rodata.home_storage_shelf_trailer);
        . = 0xFFAC4; data/text/home_storage.o(.rodata.home_storage_tool_chest_header);
        . = 0xFFAD4; asm/data/data_080F9EB8.o(.rodata.home_storage_trailer);
        . = 0xFFAE0; asm/data/data_080F9EB8.o(.rodata.blacksmith_upgrade_prefix);
        FILL(0x00);
        . = 0xFFAE4; data/text/blacksmith.o(.rodata.blacksmith_upgrade_prompts);
        FILL(0x00);
        . = 0xFFCCC; data/text/blacksmith.o(.rodata.blacksmith_upgrade_dynamic);
        . = 0xFFD04; asm/data/data_080F9EB8.o(.rodata.blacksmith_upgrade_result_padding);
        FILL(0x00);
        . = 0xFFD08; data/text/blacksmith.o(.rodata.blacksmith_upgrade_result);
        . = 0xFFD54; asm/data/data_080F9EB8.o(.rodata.gift_wrap_prefix);
        . = 0xFFD64; data/text/gift_wrap.o(.rodata.gift_wrap);
        . = 0xFFE64; asm/data/data_080F9EB8.o(.rodata.gift_wrap_trailer);
        FILL(0x00);
        . = 0xFFE70; data/text/link_communication.o(.rodata.link_communication);
        . = 0x100130; asm/data/data_080F9EB8.o(.rodata.link_communication_trailer);
        . = 0x1005EA; data/text/recovery_status.o(.rodata);
        . = 0x1008F9; asm/data/data_080F9EB8.o(.rodata.recovery_status_trailer_prefix);
        . = 0x1008FC; data/text/cooking_menu.o(.rodata);
        . = 0x100A0F; asm/data/data_080F9EB8.o(.rodata.cooking_menu_padding);
        . = 0x100A10; data/text/cooking_menu.o(.rodata.cooking_result_text);
        . = 0x100A22; asm/data/data_080F9EB8.o(.rodata.cooking_result_trailer);
        . = 0x100A84; data/text/cooking_recipe_actions.o(.rodata);
        . = 0x100B21; asm/data/data_080F9EB8.o(.rodata.cooking_recipe_actions_padding);
        . = 0x100B24; data/text/cooking_recipe_actions.o(.rodata.cooking_recipe_actions_extra_text);
        . = 0x100B4E; asm/data/data_080F9EB8.o(.rodata.cooking_recipe_actions_extra_padding);
        . = 0x100B50; data/text/cooking_recipe_inventory.o(.rodata);
        . = 0x100C24; asm/data/data_080F9EB8.o(.rodata.cooking_recipe_inventory_trailer);
        . = 0x103194; asm/data/data_080F9EB8.o(.rodata);
        . = 0x1032C4; data/text/fishing_results.o(.rodata);
        . = 0x103509; asm/data/data_080F9EB8.o(.rodata.fishing_results_text_padding);
        . = 0x10350C; src/fishing_results_data.o(.rodata.fishing_record_names);
        . = 0x1035F8; asm/data/data_080F9EB8.o(.rodata.fishing_results_trailer);
        . = 0x103C1C; data/text/character_names.o(.rodata);
        . = 0x103D9B; asm/data/data_080F9EB8.o(.rodata.character_names_text_padding);
        . = 0x103D9C; src/character_names_data.o(.rodata.character_name_entries);
        . = 0x103EF4; asm/data/data_080F9EB8.o(.rodata.character_names_table_trailer);
        . = 0x1044B0; data/text/calendar.o(.rodata.calendar.festival_text);
        . = 0x1048DB; asm/data/data_080F9EB8.o(.rodata.calendar_festival_dynamic_trailer);
        . = 0x10491C; data/text/calendar.o(.rodata.calendar.no_plans_text);
        . = 0x104935; asm/data/data_080F9EB8.o(.rodata.calendar_no_plans_trailer);
        . = 0x1070F4; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_animal_husbandry);
        . = 0x10737B; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_animal_husbandry_trailer);
        . = 0x1073B9; data/text/festival_contestants.o(.rodata.festival_contestants_set2);
. = 0x1074BD; asm/data/data_080F9EB8.o(.rodata.festival_contestants_set2_trailer);
. = 0x1074C0; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_chicken_festival_opening);
. = 0x1075EA; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_chicken_festival_opening_trailer);
. = 0x1075EC; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_chicken_festival_mid);
        . = 0x107620; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_chicken_festival_instructions);
. = 0x107801; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_chicken_festival_trailer);
        . = 0x1078E0; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_harvest_instructions);
        . = 0x107A5B; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_harvest_instructions_trailer);
        . = 0x107A5C; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_harvest_results);
        . = 0x107AA9; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_harvest_results_trailer);
        . = 0x107B1C; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_watering_instructions);
        . = 0x107D37; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_watering_instructions_trailer);
        . = 0x107D38; data/text/harvest_sprite_minigames.o(.rodata.harvest_sprite_minigames_watering_results);
        . = 0x107D89; asm/data/data_080F9EB8.o(.rodata.harvest_sprite_minigames_watering_results_trailer);
        . = 0x107DAC; src/reference_guide.o(.rodata.reference_guide);
        . = 0x1189D4; asm/data/data_080F9EB8.o(.rodata.reference_guide_unextracted_trailer);
        . = 0x13BCF8; /* JP m4a player and song tables. */
        src/sound_data.o(.rodata.*);
        . = 0x13C3CC; /* JP asset container, independently matched. */
        . = ALIGN(4); asm/data/data_0813B288.o(.rodata);
    } > ROM = 0xFF

    .iwram : ALIGN(4)
    {
        asm/code_iwram.o(.iwram);
    } > IWRAM AT> ROM = 0xFF

    __iwram_vma     = ADDR(.iwram);
    __iwram_vma_end = ADDR(.iwram) + SIZEOF(.iwram);
    __iwram_lma     = LOADADDR(.iwram);

    .pad : ALIGN(4)
    {
        LONG(0);
        /* JP asset data ends at 0x0877FE58 after the IWRAM load image. */
        . = 0x000801A8;
    } > ROM = 0xFF

    /* DWARF 2 sections */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_info     0 : { *(.debug_info) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        /* JP vtable bytes and labels are emitted by asm/vtables.o above. */
        *(.gnu.linkonce.d.__vt_*)
        *(.gnu.linkonce.t._._*)
        *(*);
    }
}
