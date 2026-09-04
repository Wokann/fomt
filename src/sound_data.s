    .ifdef REGION_JP
    @ JP revision 0 sound tables.  Keep the EWRAM track allocation identical
    @ to the US source, but take the region-specific ROM table bytes directly
    @ from the matched JP source ROM.

    .include "six/asm/prelude.s"
    .include "six/asm/macros.s"
    .include "asm/m4a.s"

    .equiv NUM_TRACKS, 8

    .macro def_music_player_track name:req
    bss \name .section=.sbss
    .space MusicPlayerTrack_size * NUM_TRACKS
    endb
    .endm

    def_music_player_track gMusicPlayerTrackA
    def_music_player_track gMusicPlayerTrackB
    def_music_player_track gMusicPlayerTrackC
    def_music_player_track gMusicPlayerTrackD
    def_music_player_track gMusicPlayerTrackE
    .purgem def_music_player_track

    .section .rodata.gMusicPlayerTable, "a"
    .global gMusicPlayerTable
gMusicPlayerTable:
    .incbin "baserom_jp.gba", 0x13BCF8, 0x3C

    .section .rodata.gSongTable, "a"
    .global gSongTable
gSongTable:
    .incbin "baserom_jp.gba", 0x13BD34, 0x698
    .else
    .include "data/sound/music_player_table.s"
    .include "data/sound/song_table.s"
    .endif
