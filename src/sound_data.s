    .ifdef REGION_JP
    @ JP revision 0 song table.  The player/track allocation and its pointer
    @ table are ordinary C structures in src/m4a.c.

    .include "six/asm/prelude.s"
    .include "six/asm/macros.s"

    .section .rodata.gSongTable, "a"
    .global gSongTable
gSongTable:
    .incbin "baserom_jp.gba", 0x13BD34, 0x698
    .else
    .include "data/sound/song_table.s"
    .endif
