#include "m4a.h"

#include "gbaio.h"
#include "gbasvc.h"

#include "data/m4a_config.h"

#define SOUND_INFO_PTR (*(struct SoundInfo **)0x3007FF0)

#define MPLAY_JUMP_TABLE_FUNC(n) (*(gMPlayJumpTable + (n)))

// m4a_1
extern u32 MultByQ32(u32 multiplier, u32 multiplicand);
extern void SoundMain(void);
extern void SoundMainRam_load(struct SoundInfo * sound_info);
extern void RealClear64byte(void);
extern void RealClearChain(void * x);
extern void MPlayJumpTableCopy(MPlayFunc * mplay_jump_table);
extern void MPlayMain(struct MusicPlayer * music_player);
extern void TrackStop(struct MusicPlayer * music_player, struct MusicPlayerTrack * track);

// m4a
extern void MPlayContinue(struct MusicPlayer * music_player);
extern void FadeOutBody(struct MusicPlayer * music_player);
extern void TrkVolPitSet(struct MusicPlayer * music_player, struct MusicPlayerTrack * track);
extern void MPlayFadeOut(struct MusicPlayer * music_player, u16 speed);
extern void ClearChain(void * x);
extern void Clear64byte(void * addr);
extern void SoundInit(struct SoundInfo * soundInfo);
extern void MPlayExtender(struct CgbChannel * cgb_channels);
extern void MPlayOpen(struct MusicPlayer * music_player, struct MusicPlayerTrack * track, u8 a3);
extern void CgbSound(void);
extern void CgbOscOff(u8);
extern void CgbModVol(struct CgbChannel * chan);
extern u32 MidiKeyToCgbFreq(u8, u8, u8);
extern void DummyFunc(void);
extern void SampleFreqSet(u32 freq);
extern void ClearModM(struct MusicPlayerTrack * track);

// sound command handler functions
extern void ply_fine(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_goto(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_patt(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_pend(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_rept(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_memacc(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_prio(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_tempo(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_keysh(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_voice(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_vol(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_pan(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_bend(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_bendr(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_lfos(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_lfodl(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_mod(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_modt(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_tune(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_port(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xcmd(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_endtie(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_note(u32 note_cmd, struct MusicPlayer *, struct MusicPlayerTrack *);

// extended sound command handler functions
extern void ply_xxx(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xwave(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xtype(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xatta(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xdeca(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xsust(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xrele(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xiecv(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xiecl(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xleng(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xswee(struct MusicPlayer *, struct MusicPlayerTrack *);

SECTION(".bss") ALIGN(4) u8 SoundMainRam[0x400] = { 0 };

SECTION(".gMusicPlayerTrackA")
struct MusicPlayerTrack gMusicPlayerTrackA[8] = { 0 };

SECTION(".gMusicPlayerTrackB")
struct MusicPlayerTrack gMusicPlayerTrackB[8] = { 0 };

SECTION(".gMusicPlayerTrackC")
struct MusicPlayerTrack gMusicPlayerTrackC[8] = { 0 };

SECTION(".gMusicPlayerTrackD")
struct MusicPlayerTrack gMusicPlayerTrackD[8] = { 0 };

SECTION(".gMusicPlayerTrackE")
struct MusicPlayerTrack gMusicPlayerTrackE[8] = { 0 };

SECTION(".gSoundInfo")
struct SoundInfo gSoundInfo = { 0 };

SECTION(".gMPlayJumpTable")
MPlayFunc gMPlayJumpTable[36] = { 0 };

SECTION(".gCgbChans")
struct CgbChannel gCgbChans[4] = { 0 };

SECTION(".gMPlayMemAccArea")
u8 gMPlayMemAccArea[0x10] = { 0 };

// The driver copies this ROM template into gMPlayJumpTable during sound
// initialization.  These are deliberately ordinary C function pointers so
// the linker retains the original per-region Thumb relocations.
MPlayFunc const gMPlayJumpTableTemplate[] = {
    ply_fine,
    ply_goto,
    ply_patt,
    ply_pend,
    ply_rept,
    ply_fine,
    ply_fine,
    ply_fine,
    ply_fine,
    ply_prio,
    ply_tempo,
    ply_keysh,
    ply_voice,
    ply_vol,
    ply_pan,
    ply_bend,
    ply_bendr,
    ply_lfos,
    ply_lfodl,
    ply_mod,
    ply_modt,
    ply_fine,
    ply_fine,
    ply_tune,
    ply_fine,
    ply_fine,
    ply_fine,
    ply_port,
    ply_fine,
    ply_endtie,
    SampleFreqSet,
    TrackStop,
    FadeOutBody,
    TrkVolPitSet,
    RealClearChain,
    RealClear64byte,
};

typedef void (*XcmdFunc)(struct MusicPlayer *, struct MusicPlayerTrack *);

u8 const gScaleTable[] = {
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
};

u32 const gFreqTable[] = {
    2147483648u,
    2275179671u,
    2410468894u,
    2553802834u,
    2705659852u,
    2866546760u,
    3037000500u,
    3217589947u,
    3408917802u,
    3611622603u,
    3826380858u,
    4053909305u,
};

u16 const gPcmSamplesPerVBlankTable[] = {
    96, 132, 176, 224, 264, 304, 352, 448, 528, 608, 672, 704,
};

u8 const gCgbScaleTable[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB,
};

i16 const gCgbFreqTable[] = {
    -2004, -1891, -1785, -1685, -1591, -1501,
    -1417, -1337, -1262, -1192, -1125, -1062,
};

u8 const gNoiseTable[] = {
    0xD7, 0xD6, 0xD5, 0xD4, 0xC7, 0xC6, 0xC5, 0xC4,
    0xB7, 0xB6, 0xB5, 0xB4, 0xA7, 0xA6, 0xA5, 0xA4,
    0x97, 0x96, 0x95, 0x94, 0x87, 0x86, 0x85, 0x84,
    0x77, 0x76, 0x75, 0x74, 0x67, 0x66, 0x65, 0x64,
    0x57, 0x56, 0x55, 0x54, 0x47, 0x46, 0x45, 0x44,
    0x37, 0x36, 0x35, 0x34, 0x27, 0x26, 0x25, 0x24,
    0x17, 0x16, 0x15, 0x14, 0x07, 0x06, 0x05, 0x04,
    0x03, 0x02, 0x01, 0x00,
};

u8 const gCgb3Vol[] = {
    0x00, 0x00,
    0x60, 0x60, 0x60, 0x60,
    0x40, 0x40, 0x40, 0x40,
    0x80, 0x80, 0x80, 0x80,
    0x20, 0x20,
};

u8 const gClockTable[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x1C, 0x1E, 0x20, 0x24, 0x28, 0x2A, 0x2C,
    0x30, 0x34, 0x36, 0x38, 0x3C, 0x40, 0x42, 0x44,
    0x48, 0x4C, 0x4E, 0x50, 0x54, 0x58, 0x5A, 0x5C,
    0x60,
};

XcmdFunc const gXcmdTable[] = {
    ply_xxx,
    ply_xwave,
    ply_xtype,
    ply_xxx,
    ply_xatta,
    ply_xdeca,
    ply_xsust,
    ply_xrele,
    ply_xiecv,
    ply_xiecl,
    ply_xleng,
    ply_xswee,
};

// The two 128-entry ToneData tables are selected by the song headers.
// Their non-pointer fields match between JP and US; regional raw-asset
// labels preserve the original waveform relocations.
extern struct WaveData gM4aWaveData_000;
extern struct WaveData gM4aWaveData_001;
extern struct WaveData gM4aWaveData_002;
extern struct WaveData gM4aWaveData_003;
extern struct WaveData gM4aWaveData_004;
extern struct WaveData gM4aWaveData_005;
extern struct WaveData gM4aWaveData_006;
extern struct WaveData gM4aWaveData_007;
extern struct WaveData gM4aWaveData_008;
extern struct WaveData gM4aWaveData_009;
extern struct WaveData gM4aWaveData_010;
extern struct WaveData gM4aWaveData_011;
extern struct WaveData gM4aWaveData_012;
extern struct WaveData gM4aWaveData_013;
extern struct WaveData gM4aWaveData_014;
extern struct WaveData gM4aWaveData_015;
extern struct WaveData gM4aWaveData_016;
extern struct WaveData gM4aWaveData_017;
extern struct WaveData gM4aWaveData_018;
extern struct WaveData gM4aWaveData_019;
extern struct WaveData gM4aWaveData_020;
extern struct WaveData gM4aWaveData_021;
extern struct WaveData gM4aWaveData_022;
extern struct WaveData gM4aWaveData_023;
extern struct WaveData gM4aWaveData_024;
extern struct WaveData gM4aWaveData_025;
extern struct WaveData gM4aWaveData_026;
extern struct WaveData gM4aWaveData_027;
extern struct WaveData gM4aWaveData_028;
extern struct WaveData gM4aWaveData_029;
extern struct WaveData gM4aWaveData_030;
extern struct WaveData gM4aWaveData_031;
extern struct WaveData gM4aWaveData_032;
extern struct WaveData gM4aWaveData_033;
extern struct WaveData gM4aWaveData_034;
extern struct WaveData gM4aWaveData_035;
extern struct WaveData gM4aWaveData_036;
extern struct WaveData gM4aWaveData_037;
extern struct WaveData gM4aWaveData_038;
extern struct WaveData gM4aWaveData_039;
extern struct WaveData gM4aWaveData_040;
extern struct WaveData gM4aWaveData_041;
extern struct WaveData gM4aWaveData_042;
extern struct WaveData gM4aWaveData_043;
extern struct WaveData gM4aWaveData_044;
extern struct WaveData gM4aWaveData_045;
extern struct WaveData gM4aWaveData_046;
extern struct WaveData gM4aWaveData_047;
extern struct WaveData gM4aWaveData_048;
extern struct WaveData gM4aWaveData_049;
extern struct WaveData gM4aWaveData_050;
extern struct WaveData gM4aWaveData_051;
extern struct WaveData gM4aWaveData_052;
extern struct WaveData gM4aWaveData_053;
extern struct WaveData gM4aWaveData_054;
extern struct WaveData gM4aWaveData_055;
extern struct WaveData gM4aWaveData_056;
extern struct WaveData gM4aWaveData_057;
extern struct WaveData gM4aWaveData_058;
extern struct WaveData gM4aWaveData_059;
extern struct WaveData gM4aWaveData_060;
extern struct WaveData gM4aWaveData_061;
extern struct WaveData gM4aWaveData_062;
extern struct WaveData gM4aWaveData_063;
extern struct WaveData gM4aWaveData_064;
extern struct WaveData gM4aWaveData_065;
extern struct WaveData gM4aWaveData_066;
extern struct WaveData gM4aWaveData_067;
extern struct WaveData gM4aWaveData_068;
extern struct WaveData gM4aWaveData_069;
extern struct WaveData gM4aWaveData_070;
extern struct WaveData gM4aWaveData_071;
extern struct WaveData gM4aWaveData_072;
extern struct WaveData gM4aWaveData_073;
extern struct WaveData gM4aWaveData_074;
extern struct WaveData gM4aWaveData_075;
extern struct WaveData gM4aWaveData_076;
extern struct WaveData gM4aWaveData_077;
extern struct WaveData gM4aWaveData_078;
extern struct WaveData gM4aWaveData_079;
extern struct WaveData gM4aWaveData_080;
extern struct WaveData gM4aWaveData_081;
extern struct WaveData gM4aWaveData_082;
extern struct WaveData gM4aWaveData_083;
extern struct WaveData gM4aWaveData_084;
extern struct WaveData gM4aWaveData_085;
extern struct WaveData gM4aWaveData_086;
extern struct WaveData gM4aWaveData_087;
extern struct WaveData gM4aWaveData_088;
extern struct WaveData gM4aWaveData_089;
extern struct WaveData gM4aWaveData_090;
extern struct WaveData gM4aWaveData_091;
extern struct WaveData gM4aWaveData_092;
extern struct WaveData gM4aWaveData_093;
extern struct WaveData gM4aWaveData_094;
extern struct WaveData gM4aWaveData_095;
extern struct WaveData gM4aWaveData_096;
extern struct WaveData gM4aWaveData_097;
extern struct WaveData gM4aWaveData_098;
extern struct WaveData gM4aWaveData_099;
extern struct WaveData gM4aWaveData_100;
extern struct WaveData gM4aWaveData_101;
extern struct WaveData gM4aWaveData_102;
extern struct WaveData gM4aWaveData_103;
extern struct WaveData gM4aWaveData_104;
extern struct WaveData gM4aWaveData_105;
extern struct WaveData gM4aCgbWave_000;
extern struct WaveData gM4aCgbWave_001;
extern struct WaveData gM4aCgbWave_002;
extern struct WaveData gM4aCgbWave_003;
extern struct WaveData gM4aCgbWave_004;
extern struct WaveData gM4aCgbWave_005;
extern struct WaveData gM4aCgbWave_006;
extern struct WaveData gM4aCgbWave_007;
extern struct ToneData const gM4aSfxVoiceGroup[];

SECTION(".rodata.gM4aVoiceGroups")
struct ToneData const gM4aBgmVoiceGroup[] = {
    /* 000 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_000, 0x33, 0x00, 0xFF, 0x00 },
    /* 001 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_001, 0xFF, 0x00, 0xFF, 0x00 },
    /* 002 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_000, 0x0F, 0x00, 0xFF, 0xD8 },
    /* 003 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_000, 0x33, 0x00, 0xFF, 0xD8 },
    /* 004 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_002, 0xFF, 0x00, 0xFF, 0x00 },
    /* 005 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 006 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_003, 0xFF, 0x00, 0xFF, 0x7F },
    /* 007 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_004, 0xFF, 0x00, 0xFF, 0xA5 },
    /* 008 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_005, 0xFF, 0x00, 0xFF, 0xB2 },
    /* 009 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_006, 0xFF, 0x00, 0xFF, 0x7F },
    /* 010 */ { 0x80, 0x00, 0x00, 0x00, (struct WaveData *)&gM4aSfxVoiceGroup[0x5C], 0x00, 0x00, 0x00, 0x00 },
    /* 011 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_007, 0xFF, 0x00, 0xFF, 0x00 },
    /* 012 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_008, 0xFF, 0x00, 0xFF, 0x95 },
    /* 013 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_009, 0x1A, 0x00, 0xFF, 0x7F },
    /* 014 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_010, 0xFF, 0x00, 0xFF, 0x00 },
    /* 015 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 016 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 017 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_011, 0xFF, 0x00, 0xFF, 0xA5 },
    /* 018 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 019 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_012, 0xFF, 0x00, 0xFF, 0xA5 },
    /* 020 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_013, 0xFF, 0x00, 0xFF, 0x7F },
    /* 021 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 022 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_014, 0xFF, 0x00, 0xFF, 0x00 },
    /* 023 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_015, 0xFF, 0x00, 0xFF, 0x00 },
    /* 024 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_016, 0x40, 0x00, 0xFF, 0xA5 },
    /* 025 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 026 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_017, 0xFF, 0x00, 0xFF, 0xA5 },
    /* 027 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_018, 0xFF, 0x00, 0xFF, 0x7F },
    /* 028 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_019, 0xFF, 0x00, 0xFF, 0x7F },
    /* 029 */ { 0x09, 0x3C, 0x00, 0x00, (struct WaveData *)0x0, 0x00, 0x00, 0x0F, 0x00 },
    /* 030 */ { 0x09, 0x3C, 0x00, 0x00, (struct WaveData *)0x1, 0x00, 0x00, 0x0F, 0x00 },
    /* 031 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 032 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_007, 0x00, 0x00, 0x0F, 0x00 },
    /* 033 */ { 0x02, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x02, 0x00, 0x00 },
    /* 034 */ { 0x02, 0x3C, 0x00, 0x00, (struct WaveData *)0x1, 0x00, 0x00, 0x0F, 0x00 },
    /* 035 */ { 0x02, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 036 */ { 0x02, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x03, 0x03, 0x00 },
    /* 037 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_001, 0x00, 0x00, 0x0F, 0x01 },
    /* 038 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_001, 0x00, 0x03, 0x00, 0x01 },
    /* 039 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_007, 0x00, 0x00, 0x0F, 0x00 },
    /* 040 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_003, 0x00, 0x00, 0x0F, 0x00 },
    /* 041 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_004, 0x00, 0x00, 0x03, 0x00 },
    /* 042 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_000, 0x01, 0x01, 0x03, 0x01 },
    /* 043 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_005, 0x00, 0x00, 0x0F, 0x00 },
    /* 044 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_006, 0x00, 0x03, 0x00, 0x00 },
    /* 045 */ { 0x0B, 0x3C, 0x00, 0x00, &gM4aCgbWave_000, 0x00, 0x01, 0x03, 0x01 },
    /* 046 */ { 0x0C, 0x3C, 0x00, 0x00, (struct WaveData *)0x0, 0x00, 0x00, 0x0F, 0x00 },
    /* 047 */ { 0x0C, 0x3C, 0x00, 0x00, (struct WaveData *)0x0, 0x00, 0x03, 0x00, 0x00 },
    /* 048 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_020, 0x33, 0x00, 0xFF, 0x7F },
    /* 049 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_021, 0xFF, 0x00, 0xFF, 0x00 },
    /* 050 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_022, 0xFF, 0x00, 0xFF, 0x00 },
    /* 051 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_023, 0xFF, 0x00, 0xFF, 0x00 },
    /* 052 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_024, 0xFF, 0x00, 0xFF, 0x00 },
    /* 053 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_025, 0xFF, 0x00, 0xFF, 0x00 },
    /* 054 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_026, 0xFF, 0x00, 0xFF, 0x00 },
    /* 055 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_027, 0xFF, 0x00, 0xFF, 0x00 },
    /* 056 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_028, 0xFF, 0x00, 0xFF, 0x00 },
    /* 057 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_029, 0xFF, 0x00, 0xFF, 0x00 },
    /* 058 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_030, 0xFF, 0x00, 0xFF, 0xD8 },
    /* 059 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_031, 0xFF, 0x00, 0xFF, 0x00 },
    /* 060 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_032, 0xFF, 0x00, 0xFF, 0x00 },
    /* 061 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_033, 0xFF, 0x00, 0xFF, 0x00 },
    /* 062 */ { 0x02, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x03, 0x00 },
    /* 063 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 064 */ { 0x02, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 065 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_005, 0x00, 0x00, 0x0F, 0x00 },
    /* 066 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_002, 0x00, 0x03, 0x03, 0x00 },
    /* 067 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_001, 0x00, 0x00, 0x0F, 0x00 },
    /* 068 */ { 0x03, 0x3C, 0x00, 0x00, &gM4aCgbWave_004, 0x00, 0x03, 0x03, 0x00 },
    /* 069 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 070 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 071 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 072 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 073 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 074 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 075 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 076 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 077 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 078 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 079 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 080 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 081 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 082 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 083 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 084 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 085 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 086 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 087 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 088 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 089 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 090 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 091 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 092 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 093 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 094 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 095 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 096 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 097 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 098 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 099 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 100 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 101 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 102 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 103 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 104 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 105 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 106 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 107 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 108 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 109 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 110 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 111 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 112 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 113 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 114 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 115 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 116 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 117 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 118 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 119 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 120 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 121 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 122 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 123 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 124 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 125 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 126 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 127 */ { 0x09, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x03, 0x00, 0x00 },
};

SECTION(".rodata.gM4aVoiceGroups")
struct ToneData const gM4aSfxVoiceGroup[] = {
    /* 000 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_034, 0xFF, 0x00, 0xFF, 0x00 },
    /* 001 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_035, 0xFF, 0x00, 0xFF, 0xA5 },
    /* 002 */ { 0x09, 0x3C, 0x00, 0x00, (struct WaveData *)0x3, 0x00, 0x04, 0x00, 0x00 },
    /* 003 */ { 0x02, 0x3C, 0x00, 0x00, (struct WaveData *)0x1, 0x00, 0x05, 0x00, 0x00 },
    /* 004 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_005, 0xFF, 0x00, 0xFF, 0xB2 },
    /* 005 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 006 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_003, 0xFF, 0x00, 0xFF, 0x7F },
    /* 007 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_012, 0xFF, 0x00, 0xFF, 0xA5 },
    /* 008 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 009 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 010 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_036, 0xFF, 0x00, 0xFF, 0x00 },
    /* 011 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_037, 0xFF, 0x00, 0xFF, 0x00 },
    /* 012 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_038, 0xFF, 0x00, 0xFF, 0x00 },
    /* 013 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_039, 0xFF, 0x00, 0xFF, 0x00 },
    /* 014 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_040, 0xFF, 0x00, 0xFF, 0x00 },
    /* 015 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_041, 0xFF, 0x00, 0xFF, 0x00 },
    /* 016 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 017 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 018 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_000, 0x33, 0x00, 0xFF, 0xD8 },
    /* 019 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_011, 0xFF, 0x00, 0xFF, 0xA5 },
    /* 020 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_018, 0xFF, 0x00, 0xFF, 0x7F },
    /* 021 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 022 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 023 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 024 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 025 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 026 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 027 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 028 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 029 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 030 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 031 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 032 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 033 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 034 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 035 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 036 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 037 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 038 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 039 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 040 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 041 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 042 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 043 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 044 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 045 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 046 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 047 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 048 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 049 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 050 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 051 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 052 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 053 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 054 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 055 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 056 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 057 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 058 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 059 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 060 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 061 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 062 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 063 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 064 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_042, 0xFF, 0x00, 0xFF, 0x00 },
    /* 065 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_043, 0xFF, 0x00, 0xFF, 0x00 },
    /* 066 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_044, 0xFF, 0x00, 0xFF, 0x00 },
    /* 067 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_045, 0xFF, 0x00, 0xFF, 0x00 },
    /* 068 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_046, 0xFF, 0x00, 0xFF, 0x00 },
    /* 069 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_047, 0xFF, 0x00, 0xFF, 0x00 },
    /* 070 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_048, 0xFF, 0x00, 0xFF, 0x00 },
    /* 071 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_049, 0xFF, 0x00, 0xFF, 0x00 },
    /* 072 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_050, 0xFF, 0x00, 0xFF, 0x00 },
    /* 073 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_051, 0xFF, 0x00, 0xFF, 0x00 },
    /* 074 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_052, 0xFF, 0x00, 0xFF, 0x00 },
    /* 075 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_053, 0xFF, 0x00, 0xFF, 0x00 },
    /* 076 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_054, 0xFF, 0x00, 0xFF, 0x00 },
    /* 077 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_045, 0xFF, 0x00, 0xFF, 0x00 },
    /* 078 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_055, 0xFF, 0x00, 0xFF, 0x00 },
    /* 079 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_056, 0xFF, 0x00, 0xFF, 0x00 },
    /* 080 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_057, 0xFF, 0x00, 0xFF, 0x00 },
    /* 081 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_058, 0xFF, 0x00, 0xFF, 0x00 },
    /* 082 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_059, 0xFF, 0x00, 0xFF, 0x00 },
    /* 083 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_060, 0xFF, 0x00, 0xFF, 0x00 },
    /* 084 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_061, 0xFF, 0x00, 0xFF, 0x00 },
    /* 085 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_062, 0xFF, 0x00, 0xFF, 0x00 },
    /* 086 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_063, 0xFF, 0x00, 0xFF, 0x00 },
    /* 087 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_064, 0xFF, 0x00, 0xFF, 0x00 },
    /* 088 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_065, 0xFF, 0x00, 0xFF, 0x00 },
    /* 089 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_066, 0xFF, 0x00, 0xFF, 0x00 },
    /* 090 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_067, 0xFF, 0x00, 0xFF, 0x00 },
    /* 091 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_068, 0xFF, 0x00, 0xFF, 0x00 },
    /* 092 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_069, 0xFF, 0x00, 0xFF, 0x00 },
    /* 093 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_070, 0xFF, 0x00, 0xFF, 0x00 },
    /* 094 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_071, 0xFF, 0x00, 0xFF, 0x00 },
    /* 095 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_072, 0xFF, 0x00, 0xFF, 0x00 },
    /* 096 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_073, 0xFF, 0x00, 0xFF, 0x00 },
    /* 097 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_074, 0xFF, 0x00, 0xFF, 0x00 },
    /* 098 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_075, 0xFF, 0x00, 0xFF, 0x00 },
    /* 099 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_076, 0xFF, 0x00, 0xFF, 0x00 },
    /* 100 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_077, 0xFF, 0x00, 0xFF, 0x00 },
    /* 101 */ { 0x0C, 0x3C, 0x00, 0x00, (struct WaveData *)0x0, 0x00, 0x00, 0x0F, 0x00 },
    /* 102 */ { 0x08, 0x3C, 0x00, 0x00, &gM4aWaveData_078, 0xFF, 0x00, 0xFF, 0x00 },
    /* 103 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_079, 0xFF, 0x00, 0xFF, 0x00 },
    /* 104 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_080, 0xFF, 0x00, 0xFF, 0x00 },
    /* 105 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_081, 0xFF, 0x00, 0xFF, 0x00 },
    /* 106 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_033, 0xFF, 0x00, 0xFF, 0x00 },
    /* 107 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_082, 0xFF, 0x00, 0xFF, 0x00 },
    /* 108 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_083, 0xFF, 0x00, 0xFF, 0x00 },
    /* 109 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_084, 0xFF, 0x00, 0xFF, 0x00 },
    /* 110 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_085, 0xFF, 0x00, 0xFF, 0x00 },
    /* 111 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_086, 0xFF, 0x00, 0xFF, 0x00 },
    /* 112 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_087, 0xFF, 0x00, 0xFF, 0x00 },
    /* 113 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_088, 0xFF, 0x00, 0xFF, 0x00 },
    /* 114 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_089, 0xFF, 0x00, 0xFF, 0x00 },
    /* 115 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_090, 0xFF, 0x00, 0xFF, 0x00 },
    /* 116 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_091, 0xFF, 0x00, 0xFF, 0x00 },
    /* 117 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 118 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_092, 0xFF, 0x00, 0xFF, 0x00 },
    /* 119 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_093, 0xFF, 0x00, 0xFF, 0x00 },
    /* 120 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_094, 0xFF, 0x00, 0xFF, 0x00 },
    /* 121 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_095, 0xFF, 0x00, 0xFF, 0x00 },
    /* 122 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_096, 0xFF, 0x00, 0xFF, 0x00 },
    /* 123 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_097, 0xFF, 0x00, 0xFF, 0x00 },
    /* 124 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_098, 0xFF, 0x00, 0xFF, 0x00 },
    /* 125 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 126 */ { 0x01, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x00, 0x0F, 0x00 },
    /* 127 */ { 0x09, 0x3C, 0x00, 0x00, (struct WaveData *)0x2, 0x00, 0x03, 0x00, 0x00 },
};

// These seven valid ToneData records follow the two referenced voice groups,
// but no owner table has been recovered yet.  Keep their unknown identity
// explicit while preserving their typed layout and raw-asset relocations.
SECTION(".rodata.gM4aVoiceGroups")
struct ToneData const gUnk_M4aToneDataTail[] = {
    /* 000 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_099, 0xFF, 0x00, 0xFF, 0x00 },
    /* 001 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_100, 0xFF, 0x00, 0xFF, 0x00 },
    /* 002 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_101, 0xFF, 0x00, 0xFF, 0x00 },
    /* 003 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_102, 0xFF, 0x00, 0xFF, 0x00 },
    /* 004 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_103, 0xFF, 0x00, 0xFF, 0x00 },
    /* 005 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_104, 0xFF, 0x00, 0xFF, 0x00 },
    /* 006 */ { 0x00, 0x3C, 0x00, 0x00, &gM4aWaveData_105, 0xFF, 0x00, 0xFF, 0x00 },
};

// This table follows the still-raw M4A voice/sample configuration block in
// ROM, so it has a distinct output section despite sharing this driver source.
SECTION(".rodata.gMusicPlayerTable")
struct MusicPlayerEnt const gMusicPlayerTable[] = {
    { &gMusicPlayerA, gMusicPlayerTrackA, 8, 0 },
    { &gMusicPlayerB, gMusicPlayerTrackB, 8, 0 },
    { &gMusicPlayerC, gMusicPlayerTrackC, 8, 0 },
    { &gMusicPlayerD, gMusicPlayerTrackD, 8, 0 },
    { &gMusicPlayerE, gMusicPlayerTrackE, 8, 0 },
};

// Each row retains its original audio-ID slot.  Empty slots deliberately share
// the one zero track instead of inventing separate payloads.
extern struct Song gSong_Unused;
extern struct Song gSong_Audio001;
extern struct Song gSong_Audio002;
extern struct Song gSong_Audio003;
extern struct Song gSong_Audio004;
extern struct Song gSong_Audio005;
extern struct Song gSong_Audio006;
extern struct Song gSong_Audio007;
extern struct Song gSong_Audio008;
extern struct Song gSong_Audio009;
extern struct Song gSong_Audio010;
extern struct Song gSong_Audio011;
extern struct Song gSong_Audio012;
extern struct Song gSong_Audio013;
extern struct Song gSong_Audio014;
extern struct Song gSong_Audio015;
extern struct Song gSong_Audio016;
extern struct Song gSong_Audio017;
extern struct Song gSong_Audio018;
extern struct Song gSong_Audio019;
extern struct Song gSong_Audio020;
extern struct Song gSong_Audio021;
extern struct Song gSong_Audio022;
extern struct Song gSong_Audio023;
extern struct Song gSong_Audio024;
extern struct Song gSong_Audio025;
extern struct Song gSong_Audio026;
extern struct Song gSong_Audio027;
extern struct Song gSong_Audio028;
extern struct Song gSong_Audio029;
extern struct Song gSong_Audio030;
extern struct Song gSong_Audio031;
extern struct Song gSong_Audio032;
extern struct Song gSong_Audio033;
extern struct Song gSong_Audio034;
extern struct Song gSong_Audio035;
extern struct Song gSong_Audio036;
extern struct Song gSong_Audio037;
extern struct Song gSong_Audio101;
extern struct Song gSong_Audio102;
extern struct Song gSong_Audio103;
extern struct Song gSong_Audio104;
extern struct Song gSong_Audio105;
extern struct Song gSong_Audio106;
extern struct Song gSong_Audio107;
extern struct Song gSong_Audio108;
extern struct Song gSong_Audio109;
extern struct Song gSong_Audio110;
extern struct Song gSong_Audio111;
extern struct Song gSong_Audio112;
extern struct Song gSong_Audio113;
extern struct Song gSong_Audio114;
extern struct Song gSong_Audio115;
extern struct Song gSong_Audio116;
extern struct Song gSong_Audio117;
extern struct Song gSong_Audio118;
extern struct Song gSong_Audio119;
extern struct Song gSong_Audio120;
extern struct Song gSong_Audio121;
extern struct Song gSong_Audio122;
extern struct Song gSong_Audio123;
extern struct Song gSong_Audio124;
extern struct Song gSong_Audio125;
extern struct Song gSong_Audio126;
extern struct Song gSong_Audio127;
extern struct Song gSong_Audio128;
extern struct Song gSong_Audio129;
extern struct Song gSong_Audio130;
extern struct Song gSong_Audio131;
extern struct Song gSong_Audio132;
extern struct Song gSong_Audio133;
extern struct Song gSong_Audio134;
extern struct Song gSong_Audio135;
extern struct Song gSong_Audio136;
extern struct Song gSong_Audio137;
extern struct Song gSong_Audio138;
extern struct Song gSong_Audio139;
extern struct Song gSong_Audio140;
extern struct Song gSong_Audio141;
extern struct Song gSong_Audio142;
extern struct Song gSong_Audio143;
extern struct Song gSong_Audio144;
extern struct Song gSong_Audio145;
extern struct Song gSong_Audio146;
extern struct Song gSong_Audio147;
extern struct Song gSong_Audio148;
extern struct Song gSong_Audio149;
extern struct Song gSong_Audio150;
extern struct Song gSong_Audio151;
extern struct Song gSong_Audio152;
extern struct Song gSong_Audio153;
extern struct Song gSong_Audio154;
extern struct Song gSong_Audio155;
extern struct Song gSong_Audio156;
extern struct Song gSong_Audio157;
extern struct Song gSong_Audio158;
extern struct Song gSong_Audio159;
extern struct Song gSong_Audio160;
extern struct Song gSong_Audio161;
extern struct Song gSong_Audio162;
extern struct Song gSong_Audio163;
extern struct Song gSong_Audio164;
extern struct Song gSong_Audio165;
extern struct Song gSong_Audio166;
extern struct Song gSong_Audio167;
extern struct Song gSong_Audio168;
extern struct Song gSong_Audio169;
extern struct Song gSong_Audio170;
extern struct Song gSong_Audio171;
extern struct Song gSong_Audio172;
extern struct Song gSong_Audio173;
extern struct Song gSong_Audio174;
extern struct Song gSong_Audio175;
extern struct Song gSong_Audio176;
extern struct Song gSong_Audio177;
extern struct Song gSong_Audio178;
extern struct Song gSong_Audio179;
extern struct Song gSong_Audio180;
extern struct Song gSong_Audio181;
extern struct Song gSong_Audio182;
extern struct Song gSong_Audio183;
extern struct Song gSong_Audio184;
extern struct Song gSong_Audio185;
extern struct Song gSong_Audio186;
extern struct Song gSong_Audio187;
extern struct Song gSong_Audio188;
extern struct Song gSong_Audio189;
extern struct Song gSong_Audio190;
extern struct Song gSong_Audio191;
extern struct Song gSong_Audio192;
extern struct Song gSong_Audio193;
extern struct Song gSong_Audio197;
extern struct Song gSong_Audio198;
extern struct Song gSong_Audio199;
extern struct Song gSong_Audio200;
extern struct Song gSong_Audio201;
extern struct Song gSong_Audio202;
extern struct Song gSong_Audio203;
extern struct Song gSong_Audio204;
extern struct Song gSong_Audio205;
extern struct Song gSong_Audio206;
extern struct Song gSong_Audio207;
extern struct Song gSong_Audio208;
extern struct Song gSong_Audio209;
extern struct Song gSong_Audio210;

SECTION(".rodata.gSongTable")
struct SongEnt const gSongTable[] = {
    /* 000: AUDIO_UNUSED_SLOT_000 */ { &gSong_Unused, 0, 0 },
    /* 001: AUDIO_BGM_SPRING */ { &gSong_Audio001, 0, 0 },
    /* 002: AUDIO_BGM_SUMMER */ { &gSong_Audio002, 0, 0 },
    /* 003: AUDIO_BGM_AUTUMN */ { &gSong_Audio003, 0, 0 },
    /* 004: AUDIO_BGM_WINTER */ { &gSong_Audio004, 0, 0 },
    /* 005: AUDIO_BGM_SADNESS */ { &gSong_Audio005, 0, 0 },
    /* 006: AUDIO_BGM_WEDDING */ { &gSong_Audio006, 0, 0 },
    /* 007: AUDIO_BGM_FESTIVAL */ { &gSong_Audio007, 0, 0 },
    /* 008: AUDIO_BGM_MUSIC_FESTIVAL */ { &gSong_Audio008, 0, 0 },
    /* 009: AUDIO_BGM_ANIMAL_FESTIVAL */ { &gSong_Audio009, 0, 0 },
    /* 010: AUDIO_AMBIENCE_RAIN */ { &gSong_Audio010, 0, 0 },
    /* 011: AUDIO_AMBIENCE_STORM */ { &gSong_Audio011, 0, 0 },
    /* 012: AUDIO_AMBIENCE_BEACH */ { &gSong_Audio012, 0, 0 },
    /* 013: AUDIO_BGM_MINERAL_TOWN */ { &gSong_Audio013, 0, 0 },
    /* 014: AUDIO_AMBIENCE_NIGHT */ { &gSong_Audio014, 0, 0 },
    /* 015: AUDIO_BGM_MUSIC_FESTIVAL_PERFORMANCE */ { &gSong_Audio015, 0, 0 },
    /* 016: AUDIO_BGM_RIVAL_EVENT */ { &gSong_Audio016, 0, 0 },
    /* 017: AUDIO_BGM_LOVE_EVENT */ { &gSong_Audio017, 0, 0 },
    /* 018: AUDIO_RECORD_SPRING_SONG */ { &gSong_Audio018, 0, 0 },
    /* 019: AUDIO_RECORD_TOWN_SPIRIT */ { &gSong_Audio019, 0, 0 },
    /* 020: AUDIO_RECORD_FLOWER_BUD_FALL */ { &gSong_Audio020, 0, 0 },
    /* 021: AUDIO_RECORD_64_MEMORIES */ { &gSong_Audio021, 0, 0 },
    /* 022: AUDIO_RECORD_MARINE_JAZZ */ { &gSong_Audio022, 0, 0 },
    /* 023: AUDIO_RECORD_BUTTERFLY */ { &gSong_Audio023, 0, 0 },
    /* 024: AUDIO_RECORD_SUMMER_MEMORIES */ { &gSong_Audio024, 0, 0 },
    /* 025: AUDIO_RECORD_AUTUMN_JOY */ { &gSong_Audio025, 0, 0 },
    /* 026: AUDIO_RECORD_QUIET_WINTER */ { &gSong_Audio026, 0, 0 },
    /* 027: AUDIO_RECORD_GRIFFIN_BLUE */ { &gSong_Audio027, 0, 0 },
    /* 028: AUDIO_RECORD_ALBUM_11 */ { &gSong_Audio028, 0, 0 },
    /* 029: AUDIO_RECORD_ALBUM_12 */ { &gSong_Audio029, 0, 0 },
    /* 030: AUDIO_RECORD_ALBUM_13 */ { &gSong_Audio030, 0, 0 },
    /* 031: AUDIO_RECORD_ALBUM_14 */ { &gSong_Audio031, 0, 0 },
    /* 032: AUDIO_RECORD_ALBUM_15 */ { &gSong_Audio032, 0, 0 },
    /* 033: AUDIO_BGM_HORSE_RACE_MINIGAME */ { &gSong_Audio033, 0, 0 },
    /* 034: AUDIO_BGM_HARVEST_SPRITE_MINIGAME */ { &gSong_Audio034, 0, 0 },
    /* 035: AUDIO_BGM_TITLE_SCREEN */ { &gSong_Audio035, 0, 0 },
    /* 036: AUDIO_BGM_CREDITS */ { &gSong_Audio036, 0, 0 },
    /* 037: AUDIO_BGM_CHILDHOOD */ { &gSong_Audio037, 0, 0 },
    /* 038: AUDIO_UNUSED_SLOT_038 */ { &gSong_Unused, 0, 0 },
    /* 039: AUDIO_UNUSED_SLOT_039 */ { &gSong_Unused, 0, 0 },
    /* 040: AUDIO_UNUSED_SLOT_040 */ { &gSong_Unused, 0, 0 },
    /* 041: AUDIO_UNUSED_SLOT_041 */ { &gSong_Unused, 0, 0 },
    /* 042: AUDIO_UNUSED_SLOT_042 */ { &gSong_Unused, 0, 0 },
    /* 043: AUDIO_UNUSED_SLOT_043 */ { &gSong_Unused, 0, 0 },
    /* 044: AUDIO_UNUSED_SLOT_044 */ { &gSong_Unused, 0, 0 },
    /* 045: AUDIO_UNUSED_SLOT_045 */ { &gSong_Unused, 0, 0 },
    /* 046: AUDIO_UNUSED_SLOT_046 */ { &gSong_Unused, 0, 0 },
    /* 047: AUDIO_UNUSED_SLOT_047 */ { &gSong_Unused, 0, 0 },
    /* 048: AUDIO_UNUSED_SLOT_048 */ { &gSong_Unused, 0, 0 },
    /* 049: AUDIO_UNUSED_SLOT_049 */ { &gSong_Unused, 0, 0 },
    /* 050: AUDIO_UNUSED_SLOT_050 */ { &gSong_Unused, 0, 0 },
    /* 051: AUDIO_UNUSED_SLOT_051 */ { &gSong_Unused, 0, 0 },
    /* 052: AUDIO_UNUSED_SLOT_052 */ { &gSong_Unused, 0, 0 },
    /* 053: AUDIO_UNUSED_SLOT_053 */ { &gSong_Unused, 0, 0 },
    /* 054: AUDIO_UNUSED_SLOT_054 */ { &gSong_Unused, 0, 0 },
    /* 055: AUDIO_UNUSED_SLOT_055 */ { &gSong_Unused, 0, 0 },
    /* 056: AUDIO_UNUSED_SLOT_056 */ { &gSong_Unused, 0, 0 },
    /* 057: AUDIO_UNUSED_SLOT_057 */ { &gSong_Unused, 0, 0 },
    /* 058: AUDIO_UNUSED_SLOT_058 */ { &gSong_Unused, 0, 0 },
    /* 059: AUDIO_UNUSED_SLOT_059 */ { &gSong_Unused, 0, 0 },
    /* 060: AUDIO_UNUSED_SLOT_060 */ { &gSong_Unused, 0, 0 },
    /* 061: AUDIO_UNUSED_SLOT_061 */ { &gSong_Unused, 0, 0 },
    /* 062: AUDIO_UNUSED_SLOT_062 */ { &gSong_Unused, 0, 0 },
    /* 063: AUDIO_UNUSED_SLOT_063 */ { &gSong_Unused, 0, 0 },
    /* 064: AUDIO_UNUSED_SLOT_064 */ { &gSong_Unused, 0, 0 },
    /* 065: AUDIO_UNUSED_SLOT_065 */ { &gSong_Unused, 0, 0 },
    /* 066: AUDIO_UNUSED_SLOT_066 */ { &gSong_Unused, 0, 0 },
    /* 067: AUDIO_UNUSED_SLOT_067 */ { &gSong_Unused, 0, 0 },
    /* 068: AUDIO_UNUSED_SLOT_068 */ { &gSong_Unused, 0, 0 },
    /* 069: AUDIO_UNUSED_SLOT_069 */ { &gSong_Unused, 0, 0 },
    /* 070: AUDIO_UNUSED_SLOT_070 */ { &gSong_Unused, 0, 0 },
    /* 071: AUDIO_UNUSED_SLOT_071 */ { &gSong_Unused, 0, 0 },
    /* 072: AUDIO_UNUSED_SLOT_072 */ { &gSong_Unused, 0, 0 },
    /* 073: AUDIO_UNUSED_SLOT_073 */ { &gSong_Unused, 0, 0 },
    /* 074: AUDIO_UNUSED_SLOT_074 */ { &gSong_Unused, 0, 0 },
    /* 075: AUDIO_UNUSED_SLOT_075 */ { &gSong_Unused, 0, 0 },
    /* 076: AUDIO_UNUSED_SLOT_076 */ { &gSong_Unused, 0, 0 },
    /* 077: AUDIO_UNUSED_SLOT_077 */ { &gSong_Unused, 0, 0 },
    /* 078: AUDIO_UNUSED_SLOT_078 */ { &gSong_Unused, 0, 0 },
    /* 079: AUDIO_UNUSED_SLOT_079 */ { &gSong_Unused, 0, 0 },
    /* 080: AUDIO_UNUSED_SLOT_080 */ { &gSong_Unused, 0, 0 },
    /* 081: AUDIO_UNUSED_SLOT_081 */ { &gSong_Unused, 0, 0 },
    /* 082: AUDIO_UNUSED_SLOT_082 */ { &gSong_Unused, 0, 0 },
    /* 083: AUDIO_UNUSED_SLOT_083 */ { &gSong_Unused, 0, 0 },
    /* 084: AUDIO_UNUSED_SLOT_084 */ { &gSong_Unused, 0, 0 },
    /* 085: AUDIO_UNUSED_SLOT_085 */ { &gSong_Unused, 0, 0 },
    /* 086: AUDIO_UNUSED_SLOT_086 */ { &gSong_Unused, 0, 0 },
    /* 087: AUDIO_UNUSED_SLOT_087 */ { &gSong_Unused, 0, 0 },
    /* 088: AUDIO_UNUSED_SLOT_088 */ { &gSong_Unused, 0, 0 },
    /* 089: AUDIO_UNUSED_SLOT_089 */ { &gSong_Unused, 0, 0 },
    /* 090: AUDIO_UNUSED_SLOT_090 */ { &gSong_Unused, 0, 0 },
    /* 091: AUDIO_UNUSED_SLOT_091 */ { &gSong_Unused, 0, 0 },
    /* 092: AUDIO_UNUSED_SLOT_092 */ { &gSong_Unused, 0, 0 },
    /* 093: AUDIO_UNUSED_SLOT_093 */ { &gSong_Unused, 0, 0 },
    /* 094: AUDIO_UNUSED_SLOT_094 */ { &gSong_Unused, 0, 0 },
    /* 095: AUDIO_UNUSED_SLOT_095 */ { &gSong_Unused, 0, 0 },
    /* 096: AUDIO_UNUSED_SLOT_096 */ { &gSong_Unused, 0, 0 },
    /* 097: AUDIO_UNUSED_SLOT_097 */ { &gSong_Unused, 0, 0 },
    /* 098: AUDIO_UNUSED_SLOT_098 */ { &gSong_Unused, 0, 0 },
    /* 099: AUDIO_UNUSED_SLOT_099 */ { &gSong_Unused, 0, 0 },
    /* 100: AUDIO_UNUSED_SLOT_100 */ { &gSong_Unused, 0, 0 },
    /* 101: AUDIO_SFX_EAT */ { &gSong_Audio101, 3, 3 },
    /* 102: AUDIO_SFX_DRINK */ { &gSong_Audio102, 3, 3 },
    /* 103: AUDIO_SEQUENCE_103 */ { &gSong_Audio103, 3, 3 },
    /* 104: AUDIO_SEQUENCE_104 */ { &gSong_Audio104, 3, 3 },
    /* 105: AUDIO_SFX_ENTER_HOT_SPRING */ { &gSong_Audio105, 3, 3 },
    /* 106: AUDIO_SFX_PICK_UP_ITEM */ { &gSong_Audio106, 3, 3 },
    /* 107: AUDIO_SEQUENCE_107 */ { &gSong_Audio107, 3, 3 },
    /* 108: AUDIO_SFX_THROW_ITEM */ { &gSong_Audio108, 3, 3 },
    /* 109: AUDIO_SFX_THROWN_ITEM_LANDS */ { &gSong_Audio109, 3, 3 },
    /* 110: AUDIO_SFX_SHIPMENT_DEPOSIT */ { &gSong_Audio110, 3, 3 },
    /* 111: AUDIO_SFX_SICKLE_CUT */ { &gSong_Audio111, 3, 3 },
    /* 112: AUDIO_SEQUENCE_112 */ { &gSong_Audio112, 3, 3 },
    /* 113: AUDIO_SEQUENCE_113 */ { &gSong_Audio113, 3, 3 },
    /* 114: AUDIO_SEQUENCE_114 */ { &gSong_Audio114, 3, 3 },
    /* 115: AUDIO_SEQUENCE_115 */ { &gSong_Audio115, 3, 3 },
    /* 116: AUDIO_SEQUENCE_116 */ { &gSong_Audio116, 3, 3 },
    /* 117: AUDIO_SEQUENCE_117 */ { &gSong_Audio117, 3, 3 },
    /* 118: AUDIO_SFX_HOE_TILL */ { &gSong_Audio118, 3, 3 },
    /* 119: AUDIO_SEQUENCE_119 */ { &gSong_Audio119, 3, 3 },
    /* 120: AUDIO_SEQUENCE_120 */ { &gSong_Audio120, 3, 3 },
    /* 121: AUDIO_SFX_LIGHT_FIREPLACE */ { &gSong_Audio121, 3, 3 },
    /* 122: AUDIO_SEQUENCE_122 */ { &gSong_Audio122, 3, 3 },
    /* 123: AUDIO_SEQUENCE_123 */ { &gSong_Audio123, 3, 3 },
    /* 124: AUDIO_SFX_ADD_ITEM_TO_FIRE */ { &gSong_Audio124, 3, 3 },
    /* 125: AUDIO_SFX_HAMMER_SMALL_STONE */ { &gSong_Audio125, 3, 3 },
    /* 126: AUDIO_SFX_HAMMER_LARGE_STONE */ { &gSong_Audio126, 3, 3 },
    /* 127: AUDIO_SFX_HAMMER_HUGE_STONE */ { &gSong_Audio127, 3, 3 },
    /* 128: AUDIO_SEQUENCE_128 */ { &gSong_Audio128, 3, 3 },
    /* 129: AUDIO_SEQUENCE_129 */ { &gSong_Audio129, 3, 3 },
    /* 130: AUDIO_SEQUENCE_130 */ { &gSong_Audio130, 3, 3 },
    /* 131: AUDIO_SFX_HAMMER_MAX_CHARGED_SWING */ { &gSong_Audio131, 3, 3 },
    /* 132: AUDIO_SFX_AXE_BRANCH_CHOP */ { &gSong_Audio132, 3, 3 },
    /* 133: AUDIO_SFX_AXE_STUMP_CHOP */ { &gSong_Audio133, 3, 3 },
    /* 134: AUDIO_SEQUENCE_134 */ { &gSong_Audio134, 3, 3 },
    /* 135: AUDIO_SEQUENCE_135 */ { &gSong_Audio135, 3, 3 },
    /* 136: AUDIO_SEQUENCE_136 */ { &gSong_Audio136, 3, 3 },
    /* 137: AUDIO_SEQUENCE_137 */ { &gSong_Audio137, 3, 3 },
    /* 138: AUDIO_SFX_AXE_MAX_CHARGED_SWING */ { &gSong_Audio138, 3, 3 },
    /* 139: AUDIO_SFX_WATERING_CAN_POUR */ { &gSong_Audio139, 3, 3 },
    /* 140: AUDIO_SEQUENCE_140 */ { &gSong_Audio140, 3, 3 },
    /* 141: AUDIO_SEQUENCE_141 */ { &gSong_Audio141, 3, 3 },
    /* 142: AUDIO_SEQUENCE_142 */ { &gSong_Audio142, 3, 3 },
    /* 143: AUDIO_SEQUENCE_143 */ { &gSong_Audio143, 3, 3 },
    /* 144: AUDIO_SEQUENCE_144 */ { &gSong_Audio144, 3, 3 },
    /* 145: AUDIO_SFX_WATERING_CAN_MAX_CHARGED_POUR */ { &gSong_Audio145, 3, 3 },
    /* 146: AUDIO_SFX_WATER_SPLASH */ { &gSong_Audio146, 3, 3 },
    /* 147: AUDIO_SFX_BRUSH_LIVESTOCK */ { &gSong_Audio147, 3, 3 },
    /* 148: AUDIO_SFX_SOW_SEEDS */ { &gSong_Audio148, 3, 3 },
    /* 149: AUDIO_SFX_DOCTOR_EXAMINATION */ { &gSong_Audio149, 3, 3 },
    /* 150: AUDIO_SEQUENCE_150 */ { &gSong_Audio150, 3, 3 },
    /* 151: AUDIO_SEQUENCE_151 */ { &gSong_Audio151, 3, 3 },
    /* 152: AUDIO_SEQUENCE_152 */ { &gSong_Audio152, 3, 3 },
    /* 153: AUDIO_SEQUENCE_153 */ { &gSong_Audio153, 3, 3 },
    /* 154: AUDIO_SEQUENCE_154 */ { &gSong_Audio154, 3, 3 },
    /* 155: AUDIO_SEQUENCE_155 */ { &gSong_Audio155, 3, 3 },
    /* 156: AUDIO_SFX_OPEN_DOOR */ { &gSong_Audio156, 3, 3 },
    /* 157: AUDIO_SFX_HEAL_OR_PURIFY */ { &gSong_Audio157, 3, 3 },
    /* 158: AUDIO_SEQUENCE_158 */ { &gSong_Audio158, 3, 3 },
    /* 159: AUDIO_SFX_MILK_COW */ { &gSong_Audio159, 3, 3 },
    /* 160: AUDIO_SFX_SHEAR_SHEEP */ { &gSong_Audio160, 3, 3 },
    /* 161: AUDIO_SFX_COW_MOO */ { &gSong_Audio161, 3, 3 },
    /* 162: AUDIO_SEQUENCE_162 */ { &gSong_Audio162, 3, 3 },
    /* 163: AUDIO_SFX_SHEEP_BLEAT */ { &gSong_Audio163, 3, 3 },
    /* 164: AUDIO_SEQUENCE_164 */ { &gSong_Audio164, 3, 3 },
    /* 165: AUDIO_SEQUENCE_165 */ { &gSong_Audio165, 3, 3 },
    /* 166: AUDIO_SEQUENCE_166 */ { &gSong_Audio166, 3, 3 },
    /* 167: AUDIO_SFX_FOAL_NEIGH */ { &gSong_Audio167, 3, 3 },
    /* 168: AUDIO_SEQUENCE_168 */ { &gSong_Audio168, 3, 3 },
    /* 169: AUDIO_SFX_DOG_BARK */ { &gSong_Audio169, 3, 3 },
    /* 170: AUDIO_SEQUENCE_170 */ { &gSong_Audio170, 3, 3 },
    /* 171: AUDIO_SEQUENCE_171 */ { &gSong_Audio171, 3, 3 },
    /* 172: AUDIO_SFX_BABY_CRY */ { &gSong_Audio172, 3, 3 },
    /* 173: AUDIO_SFX_HARVEST_SPRITE_FUSION_FINISH */ { &gSong_Audio173, 3, 3 },
    /* 174: AUDIO_SFX_HARVEST_SPRITE_FUSION_PULSE */ { &gSong_Audio174, 3, 3 },
    /* 175: AUDIO_SFX_TIME_PASSES */ { &gSong_Audio175, 3, 3 },
    /* 176: AUDIO_SFX_SUCCESS */ { &gSong_Audio176, 3, 3 },
    /* 177: AUDIO_SFX_FIREWORK_LAUNCH */ { &gSong_Audio177, 3, 3 },
    /* 178: AUDIO_SFX_FIREWORK_EXPLOSION */ { &gSong_Audio178, 3, 3 },
    /* 179: AUDIO_SFX_CEREMONIAL_CHIME */ { &gSong_Audio179, 3, 3 },
    /* 180: AUDIO_SEQUENCE_180 */ { &gSong_Audio180, 3, 3 },
    /* 181: AUDIO_SFX_VICTORY */ { &gSong_Audio181, 3, 3 },
    /* 182: AUDIO_SFX_ITEM_OBTAINED */ { &gSong_Audio182, 3, 3 },
    /* 183: AUDIO_SEQUENCE_183 */ { &gSong_Audio183, 3, 3 },
    /* 184: AUDIO_SFX_ATTENTION_CHIME */ { &gSong_Audio184, 3, 3 },
    /* 185: AUDIO_SEQUENCE_185 */ { &gSong_Audio185, 3, 3 },
    /* 186: AUDIO_SEQUENCE_186 */ { &gSong_Audio186, 3, 3 },
    /* 187: AUDIO_SEQUENCE_187 */ { &gSong_Audio187, 3, 3 },
    /* 188: AUDIO_SFX_STAR_SPARKLE */ { &gSong_Audio188, 3, 3 },
    /* 189: AUDIO_SEQUENCE_189 */ { &gSong_Audio189, 3, 3 },
    /* 190: AUDIO_SFX_HARVEST_GODDESS_APPEARS */ { &gSong_Audio190, 3, 3 },
    /* 191: AUDIO_SEQUENCE_191 */ { &gSong_Audio191, 3, 3 },
    /* 192: AUDIO_SFX_QUESTION_EMOTE */ { &gSong_Audio192, 3, 3 },
    /* 193: AUDIO_SFX_APPLAUSE */ { &gSong_Audio193, 3, 3 },
    /* 194: AUDIO_UNUSED_SLOT_194 */ { &gSong_Unused, 0, 0 },
    /* 195: AUDIO_UNUSED_SLOT_195 */ { &gSong_Unused, 0, 0 },
    /* 196: AUDIO_UNUSED_SLOT_196 */ { &gSong_Unused, 0, 0 },
    /* 197: AUDIO_SEQUENCE_197 */ { &gSong_Audio197, 3, 3 },
    /* 198: AUDIO_SEQUENCE_198 */ { &gSong_Audio198, 3, 3 },
    /* 199: AUDIO_SFX_INCORRECT_ANSWER */ { &gSong_Audio199, 3, 3 },
    /* 200: AUDIO_SFX_KAPPA_SURPRISE */ { &gSong_Audio200, 3, 3 },
    /* 201: AUDIO_SEQUENCE_201 */ { &gSong_Audio201, 3, 3 },
    /* 202: AUDIO_SEQUENCE_202 */ { &gSong_Audio202, 3, 3 },
    /* 203: AUDIO_SEQUENCE_203 */ { &gSong_Audio203, 3, 3 },
    /* 204: AUDIO_SFX_CHICKEN_CLUCK */ { &gSong_Audio204, 3, 3 },
    /* 205: AUDIO_SFX_CLOSE_DOOR */ { &gSong_Audio205, 3, 3 },
    /* 206: AUDIO_SEQUENCE_206 */ { &gSong_Audio206, 3, 3 },
    /* 207: AUDIO_SEQUENCE_207 */ { &gSong_Audio207, 3, 3 },
    /* 208: AUDIO_SEQUENCE_208 */ { &gSong_Audio208, 3, 3 },
    /* 209: AUDIO_SEQUENCE_209 */ { &gSong_Audio209, 3, 3 },
    /* 210: AUDIO_SEQUENCE_210 */ { &gSong_Audio210, 3, 3 },
};


u32 MidiKeyToFreq(struct WaveData * wav, u8 key, u8 fine_adjust)
{
    u32 val1;
    u32 val2;
    u32 fine_adjust_shifted = fine_adjust << 24;

    if (key > 178)
    {
        key = 178;
        fine_adjust_shifted = 255 << 24;
    }

    val1 = gScaleTable[key];
    val1 = gFreqTable[val1 & 0xF] >> (val1 >> 4);

    val2 = gScaleTable[key + 1];
    val2 = gFreqTable[val2 & 0xF] >> (val2 >> 4);

    return MultByQ32(wav->freq, val1 + MultByQ32(val2 - val1, fine_adjust_shifted));
}

void UnusedDummyFunc(void) {}

void MPlayContinue(struct MusicPlayer * music_player)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->status &= ~MUSICPLAYER_STATUS_PAUSE;
        music_player->ident = ID_NUMBER;
    }
}

void MPlayFadeOut(struct MusicPlayer * music_player, u16 speed)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->fade_oc = speed;
        music_player->fade_oi = speed;
        music_player->fade_ov = 64 << FADE_VOL_SHIFT;
        music_player->ident = ID_NUMBER;
    }
}

void m4aSoundInit(void)
{
    int i;

    CpuCopy32(((void *)(((iptr)SoundMainRam_load) & ~1)), SoundMainRam, sizeof(SoundMainRam));

    SoundInit(&gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(SOUND_MODE);

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
    {
        struct MusicPlayer * music_player = gMusicPlayerTable[i].music_player;
        MPlayOpen(music_player, gMusicPlayerTable[i].track, gMusicPlayerTable[i].num_tracks);
        music_player->unk_B = gMusicPlayerTable[i].unk_A;
        music_player->mem_acc_area = gMPlayMemAccArea;
    }
}

void m4aSoundMain(void)
{
    SoundMain();
}

void m4aSongNumStart(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    m4aMPlayStart(music_player_ent->music_player, song_ent->song);
}

void m4aSongNumStartOrChange(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song != song_ent->song)
    {
        m4aMPlayStart(music_player_ent->music_player, song_ent->song);
    }
    else
    {
        if ((music_player_ent->music_player->status & MUSICPLAYER_STATUS_TRACK) == 0 ||
            ((music_player_ent->music_player->status & MUSICPLAYER_STATUS_PAUSE) != 0))
        {
            m4aMPlayStart(music_player_ent->music_player, song_ent->song);
        }
    }
}

void m4aSongNumStartOrContinue(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song != song_ent->song)
        m4aMPlayStart(music_player_ent->music_player, song_ent->song);
    else if ((music_player_ent->music_player->status & MUSICPLAYER_STATUS_TRACK) == 0)
        m4aMPlayStart(music_player_ent->music_player, song_ent->song);
    else if (music_player_ent->music_player->status & MUSICPLAYER_STATUS_PAUSE)
        MPlayContinue(music_player_ent->music_player);
}

void m4aSongNumStop(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song == song_ent->song)
        m4aMPlayStop(music_player_ent->music_player);
}

void m4aSongNumContinue(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song == song_ent->song)
        MPlayContinue(music_player_ent->music_player);
}

void m4aMPlayAllStop(void)
{
    int i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        m4aMPlayStop(gMusicPlayerTable[i].music_player);
}

void m4aMPlayContinue(struct MusicPlayer * music_player)
{
    MPlayContinue(music_player);
}

void m4aMPlayAllContinue(void)
{
    int i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        MPlayContinue(gMusicPlayerTable[i].music_player);
}

void m4aMPlayFadeOut(struct MusicPlayer * music_player, u16 speed)
{
    MPlayFadeOut(music_player, speed);
}

void m4aMPlayFadeOutTemporarily(struct MusicPlayer * music_player, u16 speed)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->fade_oc = speed;
        music_player->fade_oi = speed;
        music_player->fade_ov = (64 << FADE_VOL_SHIFT) | TEMPORARY_FADE;
        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayFadeIn(struct MusicPlayer * music_player, u16 speed)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->fade_oc = speed;
        music_player->fade_oi = speed;
        music_player->fade_ov = (0 << FADE_VOL_SHIFT) | FADE_IN;
        music_player->status &= ~MUSICPLAYER_STATUS_PAUSE;
        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayImmInit(struct MusicPlayer * music_player)
{
    int track_count = music_player->track_count;
    struct MusicPlayerTrack * track = music_player->tracks;

    while (track_count > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            if (track->flags & MPT_FLG_START)
            {
                Clear64byte(track);
                track->flags = MPT_FLG_EXIST;
                track->bend_range = 2;
                track->vol_x = 64;
                track->lfo_speed = 22;
                track->tone.kind = 1;
            }
        }

        track_count--;
        track++;
    }
}

void MPlayExtender(struct CgbChannel * cgb_channels)
{
    struct SoundInfo * sound_info;
    u32 ident;

    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE | SOUND_4_ON | SOUND_3_ON | SOUND_2_ON | SOUND_1_ON;

    REG_SOUNDCNT_L = 0; // set master volume to zero
    REG_NR12 = 0x8;
    REG_NR22 = 0x8;
    REG_NR42 = 0x8;
    REG_NR14 = 0x80;
    REG_NR24 = 0x80;
    REG_NR44 = 0x80;
    REG_NR30 = 0;
    REG_NR50 = 0x77;

    sound_info = SOUND_INFO_PTR;

    ident = sound_info->ident;

    if (ident != ID_NUMBER)
        return;

    sound_info->ident++;

    gMPlayJumpTable[8] = ply_memacc;
    gMPlayJumpTable[17] = ply_lfos;
    gMPlayJumpTable[19] = ply_mod;
    gMPlayJumpTable[28] = ply_xcmd;
    gMPlayJumpTable[29] = ply_endtie;
    gMPlayJumpTable[30] = SampleFreqSet;
    gMPlayJumpTable[31] = TrackStop;
    gMPlayJumpTable[32] = FadeOutBody;
    gMPlayJumpTable[33] = TrkVolPitSet;

    sound_info->cgb_channels = cgb_channels;
    sound_info->cgb_sound_func = CgbSound;
    sound_info->cgb_osc_off_func = CgbOscOff;
    sound_info->midi_to_cgb_func = MidiKeyToCgbFreq;
    sound_info->max_lines = MAX_LINES;

    CpuFill32(0, cgb_channels, sizeof(struct CgbChannel) * 4);

    cgb_channels[0].type = 1;
    cgb_channels[0].pan_mask = 0x11;
    cgb_channels[1].type = 2;
    cgb_channels[1].pan_mask = 0x22;
    cgb_channels[2].type = 3;
    cgb_channels[2].pan_mask = 0x44;
    cgb_channels[3].type = 4;
    cgb_channels[3].pan_mask = 0x88;

    sound_info->ident = ident;
}

void MusicPlayerJumpTableCopy(void)
{
    asm("swi 0x2A");
}

void ClearChain(void * x)
{
    void (*func)(void *) = MPLAY_JUMP_TABLE_FUNC(34);
    func(x);
}

void Clear64byte(void * x)
{
    void (*func)(void *) = MPLAY_JUMP_TABLE_FUNC(35);
    func(x);
}

void SoundInit(struct SoundInfo * sound_info)
{
    sound_info->ident = 0;

    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DST_FIXED) << 16) | 4;

    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DST_FIXED) << 16) | 4;

    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE | SOUND_4_ON | SOUND_3_ON | SOUND_2_ON | SOUND_1_ON;
    REG_SOUNDCNT_H =
        SOUND_B_FIFO_RESET | SOUND_B_TIMER_0 | SOUND_B_LEFT_OUTPUT | SOUND_A_FIFO_RESET | SOUND_A_TIMER_0 | SOUND_A_RIGHT_OUTPUT | SOUND_ALL_MIX_FULL;
    REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | 0x40;

    REG_DMA1SAD = (uptr)sound_info->pcm_buffer;
    REG_DMA1DAD = (uptr)&REG_FIFO_A;
    REG_DMA2SAD = (uptr)sound_info->pcm_buffer + PCM_DMA_BUF_SIZE;
    REG_DMA2DAD = (uptr)&REG_FIFO_B;

    SOUND_INFO_PTR = sound_info;
    CpuFill32(0, sound_info, sizeof(struct SoundInfo));

    sound_info->max_channels = 8;
    sound_info->master_volume = 15;
    sound_info->plynote = ply_note;
    sound_info->cgb_sound_func = (CgbSoundFunc)DummyFunc;
    sound_info->cgb_osc_off_func = (CgbOscOffFunc)DummyFunc;
    sound_info->midi_to_cgb_func = (MidiKeyToCgbFreqFunc)DummyFunc;
    sound_info->ext_vol_pit_func = (ExtVolPitFunc)DummyFunc;

    MPlayJumpTableCopy(gMPlayJumpTable);

    sound_info->mplay_jump_table = gMPlayJumpTable;

    SampleFreqSet(SOUND_MODE_FREQ_13379);

    sound_info->ident = ID_NUMBER;
}

void SampleFreqSet(u32 freq)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;

    freq = (freq & 0xF0000) >> 16;
    sound_info->freq = freq;
    sound_info->pcm_samples_per_vblank = gPcmSamplesPerVBlankTable[freq - 1];
    sound_info->pcm_dma_period = PCM_DMA_BUF_SIZE / sound_info->pcm_samples_per_vblank;

    // LCD refresh rate 59.7275Hz
    sound_info->pcm_freq = (597275 * sound_info->pcm_samples_per_vblank + 5000) / 10000;

    // CPU frequency 16.78Mhz
    sound_info->div_freq = (16777216 / sound_info->pcm_freq + 1) >> 1;

    // Turn off timer 0.
    REG_TM0CNT_H = 0;

    // cycles per LCD fresh 280896
    REG_TM0CNT_L = -(280896 / sound_info->pcm_samples_per_vblank);

    m4aSoundVSyncOn();

    while (*(volatile u8 *)&REG_VCOUNT == 159)
        ;

    while (*(volatile u8 *)&REG_VCOUNT != 159)
        ;

    REG_TM0CNT_H = TIMER_ENABLE | TIMER_1CLK;
}

void m4aSoundMode(u32 mode)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    u32 temp;

    if (sound_info->ident != ID_NUMBER)
        return;

    sound_info->ident++;

    temp = mode & (SOUND_MODE_REVERB_SET | SOUND_MODE_REVERB_VAL);

    if (temp)
        sound_info->reverb = temp & SOUND_MODE_REVERB_VAL;

    temp = mode & SOUND_MODE_MAXCHN;

    if (temp)
    {
        struct SoundChannel * chan;

        sound_info->max_channels = temp >> SOUND_MODE_MAXCHN_SHIFT;

        temp = MAX_DIRECTSOUND_CHANNELS;
        chan = &sound_info->chans[0];

        while (temp != 0)
        {
            chan->flags = 0;
            temp--;
            chan++;
        }
    }

    temp = mode & SOUND_MODE_MASVOL;

    if (temp)
        sound_info->master_volume = temp >> SOUND_MODE_MASVOL_SHIFT;

    temp = mode & SOUND_MODE_DA_BIT;

    if (temp)
    {
        temp = (temp & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | temp;
    }

    temp = mode & SOUND_MODE_FREQ;

    if (temp)
    {
        m4aSoundVSyncOff();
        SampleFreqSet(temp);
    }

    sound_info->ident = ID_NUMBER;
}

void SoundClear(void)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    int i;
    void * chan;

    if (sound_info->ident != ID_NUMBER)
        return;

    sound_info->ident++;

    i = MAX_DIRECTSOUND_CHANNELS;
    chan = &sound_info->chans[0];

    while (i > 0)
    {
        ((struct SoundChannel *)chan)->flags = 0;
        i--;
        chan = (void *)((iptr)chan + sizeof(struct SoundChannel));
    }

    chan = sound_info->cgb_channels;

    if (chan)
    {
        i = 1;

        while (i <= 4)
        {
            sound_info->cgb_osc_off_func(i);
            ((struct CgbChannel *)chan)->flags = 0;
            i++;
            chan = (void *)((iptr)chan + sizeof(struct CgbChannel));
        }
    }

    sound_info->ident = ID_NUMBER;
}

void m4aSoundVSyncOff(void)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;

    if (sound_info->ident >= ID_NUMBER && sound_info->ident <= ID_NUMBER + 1)
    {
        sound_info->ident += 10;

        if (REG_DMA1CNT & (DMA_REPEAT << 16))
            REG_DMA1CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DST_FIXED) << 16) | 4;

        if (REG_DMA2CNT & (DMA_REPEAT << 16))
            REG_DMA2CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DST_FIXED) << 16) | 4;

        REG_DMA1CNT_H = DMA_32BIT;
        REG_DMA2CNT_H = DMA_32BIT;

        CpuFill32(0, sound_info->pcm_buffer, sizeof(sound_info->pcm_buffer));
    }
}

void m4aSoundVSyncOn(void)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    u32 ident = sound_info->ident;

    if (ident == ID_NUMBER)
        return;

    REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
    REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;

    sound_info->pcm_dma_counter = 0;
    sound_info->ident = ident - 10;
}

void MPlayOpen(struct MusicPlayer * music_player, struct MusicPlayerTrack * tracks, u8 track_count)
{
    struct SoundInfo * sound_info;

    if (track_count == 0)
        return;

    if (track_count > MAX_MUSICPLAYER_TRACKS)
        track_count = MAX_MUSICPLAYER_TRACKS;

    sound_info = SOUND_INFO_PTR;

    if (sound_info->ident != ID_NUMBER)
        return;

    sound_info->ident++;

    Clear64byte(music_player);

    music_player->tracks = tracks;
    music_player->track_count = track_count;
    music_player->status = MUSICPLAYER_STATUS_PAUSE;

    while (track_count != 0)
    {
        tracks->flags = 0;
        track_count--;
        tracks++;
    }

    // append music player and MPlayMain to linked list

    if (sound_info->mplay_head_func != NULL)
    {
        music_player->next_func = sound_info->mplay_head_func;
        music_player->next = sound_info->mplay_head;
        // NULL assignment semantically useless, but required for match
        sound_info->mplay_head_func = NULL;
    }

    sound_info->mplay_head = music_player;
    sound_info->mplay_head_func = MPlayMain;
    sound_info->ident = ID_NUMBER;
    music_player->ident = ID_NUMBER;
}

void m4aMPlayStart(struct MusicPlayer * music_player, struct Song * song_header)
{
    int i;
    u8 unk_B;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    unk_B = music_player->unk_B;

    if (!unk_B ||
        ((!music_player->song || !(music_player->tracks[0].flags & MPT_FLG_START)) &&
         ((music_player->status & MUSICPLAYER_STATUS_TRACK) == 0 || (music_player->status & MUSICPLAYER_STATUS_PAUSE))) ||
        (music_player->priority <= song_header->priority))
    {
        music_player->ident++;
        music_player->status = 0;
        music_player->song = song_header;
        music_player->tone = song_header->tone;
        music_player->priority = song_header->priority;
        music_player->clock = 0;
        music_player->tempo_d = 150;
        music_player->tempo_i = 150;
        music_player->tempo_u = 0x100;
        music_player->tempo_c = 0;
        music_player->fade_oi = 0;

        i = 0;
        track = music_player->tracks;

        while (i < song_header->track_count && i < music_player->track_count)
        {
            TrackStop(music_player, track);
            track->flags = MPT_FLG_EXIST | MPT_FLG_START;
            track->chan = 0;
            track->cmd_ptr = song_header->part[i];
            i++;
            track++;
        }

        while (i < music_player->track_count)
        {
            TrackStop(music_player, track);
            track->flags = 0;
            i++;
            track++;
        }

        if (song_header->reverb & SOUND_MODE_REVERB_SET)
            m4aSoundMode(song_header->reverb);

        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayStop(struct MusicPlayer * music_player)
{
    int i;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;
    music_player->status |= MUSICPLAYER_STATUS_PAUSE;

    i = music_player->track_count;
    track = music_player->tracks;

    while (i > 0)
    {
        TrackStop(music_player, track);
        i--;
        track++;
    }

    music_player->ident = ID_NUMBER;
}

void FadeOutBody(struct MusicPlayer * music_player)
{
    int i;
    struct MusicPlayerTrack * track;
    u16 fade_ov;

    if (music_player->fade_oi == 0)
        return;
    if (--music_player->fade_oc != 0)
        return;

    music_player->fade_oc = music_player->fade_oi;

    if (music_player->fade_ov & FADE_IN)
    {
        if ((u16)(music_player->fade_ov += (4 << FADE_VOL_SHIFT)) >= (64 << FADE_VOL_SHIFT))
        {
            music_player->fade_ov = (64 << FADE_VOL_SHIFT);
            music_player->fade_oi = 0;
        }
    }
    else
    {
        if ((i16)(music_player->fade_ov -= (4 << FADE_VOL_SHIFT)) <= 0)
        {
            i = music_player->track_count;
            track = music_player->tracks;

            while (i > 0)
            {
                u32 val;

                TrackStop(music_player, track);

                val = TEMPORARY_FADE;
                fade_ov = music_player->fade_ov;
                val &= fade_ov;

                if (!val)
                    track->flags = 0;

                i--;
                track++;
            }

            if (music_player->fade_ov & TEMPORARY_FADE)
                music_player->status |= MUSICPLAYER_STATUS_PAUSE;
            else
                music_player->status = MUSICPLAYER_STATUS_PAUSE;

            music_player->fade_oi = 0;
            return;
        }
    }

    i = music_player->track_count;
    track = music_player->tracks;

    while (i > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            fade_ov = music_player->fade_ov;

            track->vol_x = (fade_ov >> FADE_VOL_SHIFT);
            track->flags |= MPT_FLG_VOLCHG;
        }

        i--;
        track++;
    }
}

void TrkVolPitSet(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    if (track->flags & MPT_FLG_VOLSET)
    {
        int x;
        int y;

        x = (u32)(track->vol * track->vol_x) >> 5;

        if (track->mod_t == 1)
            x = (u32)(x * (track->mod_m + 128)) >> 7;

        y = 2 * track->pan + track->panX;

        if (track->mod_t == 2)
            y += track->mod_m;

        if (y < -128)
            y = -128;
        else if (y > 127)
            y = 127;

        track->vol_mr = (u32)((y + 128) * x) >> 8;
        track->vol_ml = (u32)((127 - y) * x) >> 8;
    }

    if (track->flags & MPT_FLG_PITSET)
    {
        int bend = track->bend * track->bend_range;
        int x = (track->tune + bend) * 4 + (track->key_shift << 8) + (track->key_shift_x << 8) + track->pit_x;

        if (track->mod_t == 0)
            x += 16 * track->mod_m;

        track->key_m = x >> 8;
        track->pit_m = x;
    }

    track->flags &= ~(MPT_FLG_PITSET | MPT_FLG_VOLSET);
}

u32 MidiKeyToCgbFreq(u8 chan_num, u8 key, u8 fine_adjust)
{
    if (chan_num == 4)
    {
        if (key <= 20)
        {
            key = 0;
        }
        else
        {
            key -= 21;
            if (key > 59)
                key = 59;
        }

        return gNoiseTable[key];
    }
    else
    {
        int val1;
        int val2;

        if (key <= 35)
        {
            fine_adjust = 0;
            key = 0;
        }
        else
        {
            key -= 36;
            if (key > 130)
            {
                key = 130;
                fine_adjust = 255;
            }
        }

        val1 = gCgbScaleTable[key];
        val1 = gCgbFreqTable[val1 & 0xF] >> (val1 >> 4);

        val2 = gCgbScaleTable[key + 1];
        val2 = gCgbFreqTable[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fine_adjust * (val2 - val1)) >> 8) + 2048;
    }
}

void CgbOscOff(u8 chan_num)
{
    switch (chan_num)
    {
        case 1:
            REG_NR12 = 8;
            REG_NR14 = 0x80;
            break;
        case 2:
            REG_NR22 = 8;
            REG_NR24 = 0x80;
            break;
        case 3:
            REG_NR30 = 0;
            break;
        default:
            REG_NR42 = 8;
            REG_NR44 = 0x80;
    }
}

static inline int CgbPan(struct CgbChannel * chan)
{
    u32 volume_right = chan->volume_right;
    u32 volume_left = chan->volume_left;

    if ((volume_right = (u8)volume_right) >= (volume_left = (u8)volume_left))
    {
        if (volume_right / 2 >= volume_left)
        {
            chan->pan = 0x0F;
            return 1;
        }
    }
    else
    {
        if (volume_left / 2 >= volume_right)
        {
            chan->pan = 0xF0;
            return 1;
        }
    }

    return 0;
}

void CgbModVol(struct CgbChannel * chan)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;

    if (!CgbPan(chan))
    {
        chan->pan = 0xFF;
        chan->envelope_goal = (u32)(chan->volume_left + chan->volume_right);
        chan->envelope_goal /= 16;
    }
    else
    {
        chan->envelope_goal = (u32)(chan->volume_left + chan->volume_right);
        chan->envelope_goal /= 16;
        if (chan->envelope_goal > 15)
            chan->envelope_goal = 15;
    }

    chan->sustain_goal = (chan->envelope_goal * chan->sustain + 15) >> 4;
    chan->pan &= chan->pan_mask;
}

void CgbSound(void)
{
    int ch;
    struct CgbChannel * channels;
    int prev_c15;
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    volatile u8 * nrx0ptr;
    volatile u8 * nrx1ptr;
    volatile u8 * nrx2ptr;
    volatile u8 * nrx3ptr;
    volatile u8 * nrx4ptr;
    int envelope_step_time_and_dir;

    // Most comparision operations that cast to i8 perform 'and' by 0xFF.
    int mask = 0xff;

    if (sound_info->c15)
        sound_info->c15--;
    else
        sound_info->c15 = 14;

    for (ch = 1, channels = sound_info->cgb_channels; ch <= 4; ch++, channels++)
    {
        if (!(channels->flags & SOUND_CHANNEL_SF_ON))
            continue;

        /* 1. determine hardware channel registers */
        switch (ch)
        {
            case 1:
                nrx0ptr = (volatile u8 *)&REG_NR10;
                nrx1ptr = (volatile u8 *)&REG_NR11;
                nrx2ptr = (volatile u8 *)&REG_NR12;
                nrx3ptr = (volatile u8 *)&REG_NR13;
                nrx4ptr = (volatile u8 *)&REG_NR14;
                break;
            case 2:
                nrx0ptr = (volatile u8 *)&REG_NR10 + 1;
                nrx1ptr = (volatile u8 *)&REG_NR21;
                nrx2ptr = (volatile u8 *)&REG_NR22;
                nrx3ptr = (volatile u8 *)&REG_NR23;
                nrx4ptr = (volatile u8 *)&REG_NR24;
                break;
            case 3:
                nrx0ptr = (volatile u8 *)&REG_NR30;
                nrx1ptr = (volatile u8 *)&REG_NR31;
                nrx2ptr = (volatile u8 *)&REG_NR32;
                nrx3ptr = (volatile u8 *)&REG_NR33;
                nrx4ptr = (volatile u8 *)&REG_NR34;
                break;
            default:
                nrx0ptr = (volatile u8 *)&REG_NR30 + 1;
                nrx1ptr = (volatile u8 *)&REG_NR41;
                nrx2ptr = (volatile u8 *)&REG_NR42;
                nrx3ptr = (volatile u8 *)&REG_NR43;
                nrx4ptr = (volatile u8 *)&REG_NR44;
                break;
        }

        prev_c15 = sound_info->c15;
        envelope_step_time_and_dir = *nrx2ptr;

        /* 2. calculate envelope volume */
        if (channels->flags & SOUND_CHANNEL_SF_START)
        {
            if (!(channels->flags & SOUND_CHANNEL_SF_STOP))
            {
                channels->flags = SOUND_CHANNEL_SF_ENV_ATTACK;
                channels->modify = CGB_CHANNEL_MO_PIT | CGB_CHANNEL_MO_VOL;
                CgbModVol(channels);
                switch (ch)
                {
                    case 1:
                        *nrx0ptr = channels->sweep;
                        // fallthrough
                    case 2:
                        *nrx1ptr = ((u32)channels->wav << 6) + channels->length;
                        goto init_env_step_time_dir;
                    case 3:
                        if (channels->wav != channels->current_ptr)
                        {
                            *nrx0ptr = 0x40;
                            REG_WAVE_RAM0 = channels->wav[0];
                            REG_WAVE_RAM1 = channels->wav[1];
                            REG_WAVE_RAM2 = channels->wav[2];
                            REG_WAVE_RAM3 = channels->wav[3];
                            channels->current_ptr = channels->wav;
                        }
                        *nrx0ptr = 0;
                        *nrx1ptr = channels->length;
                        if (channels->length)
                            channels->n4 = 0xC0;
                        else
                            channels->n4 = 0x80;
                        break;
                    default:
                        *nrx1ptr = channels->length;
                        *nrx3ptr = (u32)channels->wav << 3;
                    init_env_step_time_dir:
                        envelope_step_time_and_dir = channels->attack + CGB_NRx2_ENV_DIR_INC;
                        if (channels->length)
                            channels->n4 = 0x40;
                        else
                            channels->n4 = 0x00;
                        break;
                }
                channels->envelope_counter = channels->attack;
                if ((i8)(channels->attack & mask))
                {
                    channels->envelope_volume = 0;
                    goto envelope_step_complete;
                }
                else
                {
                    // skip attack phase if attack is instantaneous (=0)
                    goto envelope_decay_start;
                }
            }
            else
            {
                goto oscillator_off;
            }
        }
        else if (channels->flags & SOUND_CHANNEL_SF_IEC)
        {
            channels->pseudo_echo_length--;
            if ((i8)(channels->pseudo_echo_length & mask) <= 0)
            {
            oscillator_off:
                CgbOscOff(ch);
                channels->flags = 0;
                goto channel_complete;
            }
            goto envelope_complete;
        }
        else if ((channels->flags & SOUND_CHANNEL_SF_STOP) && (channels->flags & SOUND_CHANNEL_SF_ENV))
        {
            channels->flags &= ~SOUND_CHANNEL_SF_ENV;
            channels->envelope_counter = channels->release;
            if ((i8)(channels->release & mask))
            {
                channels->modify |= CGB_CHANNEL_MO_VOL;
                if (ch != 3)
                    envelope_step_time_and_dir = channels->release | CGB_NRx2_ENV_DIR_DEC;
                goto envelope_step_complete;
            }
            else
            {
                goto envelope_pseudoecho_start;
            }
        }
        else
        {
        envelope_step_repeat:
            if (channels->envelope_counter == 0)
            {
                if (ch == 3)
                    channels->modify |= CGB_CHANNEL_MO_VOL;

                CgbModVol(channels);
                if ((channels->flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_RELEASE)
                {
                    channels->envelope_volume--;
                    if ((i8)(channels->envelope_volume & mask) <= 0)
                    {
                    envelope_pseudoecho_start:
                        channels->envelope_volume = ((channels->envelope_goal * channels->pseudo_echo_volume) + 0xFF) >> 8;
                        if (channels->envelope_volume)
                        {
                            channels->flags |= SOUND_CHANNEL_SF_IEC;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            if (ch != 3)
                                envelope_step_time_and_dir = 0 | CGB_NRx2_ENV_DIR_INC;
                            goto envelope_complete;
                        }
                        else
                        {
                            goto oscillator_off;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->release;
                    }
                }
                else if ((channels->flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_SUSTAIN)
                {
                envelope_sustain:
                    channels->envelope_volume = channels->sustain_goal;
                    channels->envelope_counter = 7;
                }
                else if ((channels->flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_DECAY)
                {
                    int envelope_volume, sustain_goal;

                    channels->envelope_volume--;
                    envelope_volume = (i8)(channels->envelope_volume & mask);
                    sustain_goal = (i8)(channels->sustain_goal);
                    if (envelope_volume <= sustain_goal)
                    {
                    envelope_sustain_start:
                        if (channels->sustain == 0)
                        {
                            channels->flags &= ~SOUND_CHANNEL_SF_ENV;
                            goto envelope_pseudoecho_start;
                        }
                        else
                        {
                            channels->flags--;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            if (ch != 3)
                                envelope_step_time_and_dir = 0 | CGB_NRx2_ENV_DIR_INC;
                            goto envelope_sustain;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->decay;
                    }
                }
                else
                {
                    channels->envelope_volume++;
                    if ((u8)(channels->envelope_volume & mask) >= channels->envelope_goal)
                    {
                    envelope_decay_start:
                        channels->flags--;
                        channels->envelope_counter = channels->decay;
                        if ((u8)(channels->envelope_counter & mask))
                        {
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            channels->envelope_volume = channels->envelope_goal;
                            if (ch != 3)
                                envelope_step_time_and_dir = channels->decay | CGB_NRx2_ENV_DIR_DEC;
                        }
                        else
                        {
                            goto envelope_sustain_start;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->attack;
                    }
                }
            }
        }

    envelope_step_complete:
        // every 15 frames, envelope calculation has to be done twice
        // to keep up with the hardware envelope rate (1/64 s)
        channels->envelope_counter--;
        if (prev_c15 == 0)
        {
            prev_c15--;
            goto envelope_step_repeat;
        }

    envelope_complete:
        /* 3. apply pitch to HW registers */
        if (channels->modify & CGB_CHANNEL_MO_PIT)
        {
            if (ch < 4 && (channels->type & TONEDATA_TYPE_FIX))
            {
                int dac_pwm_rate = REG_SOUNDBIAS_H;

                if (dac_pwm_rate < 0x40) // if PWM rate = 32768 Hz
                    channels->frequency = (channels->frequency + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80) // if PWM rate = 65536 Hz
                    channels->frequency = (channels->frequency + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->frequency;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->frequency;
            channels->n4 = (channels->n4 & 0xC0) + (*((u8 *)(&channels->frequency) + 1));
            *nrx4ptr = (i8)(channels->n4 & mask);
        }

        /* 4. apply envelope & volume to HW registers */
        if (channels->modify & CGB_CHANNEL_MO_VOL)
        {
            REG_NR51 = (REG_NR51 & ~channels->pan_mask) | channels->pan;
            if (ch == 3)
            {
                *nrx2ptr = gCgb3Vol[channels->envelope_volume];
                if (channels->n4 & 0x80)
                {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= 0x7f;
                }
            }
            else
            {
                u32 envMask = 0xF;
                *nrx2ptr = (envelope_step_time_and_dir & envMask) + (channels->envelope_volume << 4);
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                    *nrx4ptr = channels->n4 | 0x80;
            }
        }

    channel_complete:
        channels->modify = 0;
    }
}

void m4aMPlayTempoControl(struct MusicPlayer * music_player, u16 tempo)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->tempo_u = tempo;
        music_player->tempo_i = (music_player->tempo_d * music_player->tempo_u) >> 8;
        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayVolumeControl(struct MusicPlayer * music_player, u16 track_bits, u16 volume)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->vol_x = volume / 4;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void m4aMPlayPitchControl(struct MusicPlayer * music_player, u16 track_bits, i16 pitch)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->key_shift_x = pitch >> 8;
                track->pit_x = pitch;
                track->flags |= MPT_FLG_PITCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void m4aMPlayPanpotControl(struct MusicPlayer * music_player, u16 track_bits, i8 pan)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->panX = pan;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void ClearModM(struct MusicPlayerTrack * track)
{
    track->lfo_speed_c = 0;
    track->mod_m = 0;

    if (track->mod_t == 0)
        track->flags |= MPT_FLG_PITCHG;
    else
        track->flags |= MPT_FLG_VOLCHG;
}

void m4aMPlayModDepthSet(struct MusicPlayer * music_player, u16 track_bits, u8 mod_depth)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->mod = mod_depth;

                if (!track->mod)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void m4aMPlayLFOSpeedSet(struct MusicPlayer * music_player, u16 track_bits, u8 lfo_speed)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->lfo_speed = lfo_speed;

                if (!track->lfo_speed)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void ply_memacc(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    u32 op;
    u8 * addr;
    u8 data;

#define MEMACC_COND_JUMP(cond)                                                                                                                                 \
    if (cond)                                                                                                                                                  \
        goto cond_true;                                                                                                                                        \
    else                                                                                                                                                       \
        goto cond_false;

    op = *track->cmd_ptr;
    track->cmd_ptr++;

    addr = music_player->mem_acc_area + *track->cmd_ptr;
    track->cmd_ptr++;

    data = *track->cmd_ptr;
    track->cmd_ptr++;

    switch (op)
    {
        case 0:
            *addr = data;
            return;
        case 1:
            *addr += data;
            return;
        case 2:
            *addr -= data;
            return;
        case 3:
            *addr = music_player->mem_acc_area[data];
            return;
        case 4:
            *addr += music_player->mem_acc_area[data];
            return;
        case 5:
            *addr -= music_player->mem_acc_area[data];
            return;
        case 6:
            MEMACC_COND_JUMP(*addr == data)
            return;
        case 7:
            MEMACC_COND_JUMP(*addr != data)
            return;
        case 8:
            MEMACC_COND_JUMP(*addr > data)
            return;
        case 9:
            MEMACC_COND_JUMP(*addr >= data)
            return;
        case 10:
            MEMACC_COND_JUMP(*addr <= data)
            return;
        case 11:
            MEMACC_COND_JUMP(*addr < data)
            return;
        case 12:
            MEMACC_COND_JUMP(*addr == music_player->mem_acc_area[data])
            return;
        case 13:
            MEMACC_COND_JUMP(*addr != music_player->mem_acc_area[data])
            return;
        case 14:
            MEMACC_COND_JUMP(*addr > music_player->mem_acc_area[data])
            return;
        case 15:
            MEMACC_COND_JUMP(*addr >= music_player->mem_acc_area[data])
            return;
        case 16:
            MEMACC_COND_JUMP(*addr <= music_player->mem_acc_area[data])
            return;
        case 17:
            MEMACC_COND_JUMP(*addr < music_player->mem_acc_area[data])
            return;
        default:
            return;
    }

cond_true:
{
    // *& is required for matching
    (MPLAY_JUMP_TABLE_FUNC(1))(music_player, track);
    return;
}

cond_false:
    track->cmd_ptr += 4;

#undef MEMACC_COND_JUMP
}

void ply_xcmd(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    u32 n = *track->cmd_ptr;
    track->cmd_ptr++;

    gXcmdTable[n](music_player, track);
}

void ply_xxx(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    gMPlayJumpTable[0](music_player, track);
}

#define READ_XCMD_BYTE(var, n)                                                                                                                                 \
    {                                                                                                                                                          \
        u32 byte = track->cmd_ptr[(n)];                                                                                                                        \
        byte <<= n * 8;                                                                                                                                        \
        (var) &= ~(0xFF << (n * 8));                                                                                                                           \
        (var) |= byte;                                                                                                                                         \
    }

void ply_xwave(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    u32 wav;

#ifdef UBFIX
    wav = 0;
#endif

    READ_XCMD_BYTE(wav, 0) // UB: uninitialized variable
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (struct WaveData *)wav;
    track->cmd_ptr += 4;
}

void ply_xtype(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.kind = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xatta(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.attack = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xdeca(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.decay = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xsust(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.sustain = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xrele(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.release = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xiecv(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->pseudo_echo_volume = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xiecl(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->pseudo_echo_length = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xleng(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.length = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xswee(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.pan_sweep = *track->cmd_ptr;
    track->cmd_ptr++;
}

#undef READ_XCMD_BYTE

void DummyFunc(void) {}
