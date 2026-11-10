#pragma implementation "font_draw.hh"
#include "font_draw.hh"

#include "gbasvc.h"

EXTERN_C

// Complete native compositors retain their original divided assembly syntax.
asm(
    ".text\n"
    ".syntax divided\n"
    ".thumb\n"
    "\t.align 2, 0\n"
    "\t.globl\tDrawCharacterGlyphTo2DGfxBuffer\n"
    "\t.type\t DrawCharacterGlyphTo2DGfxBuffer,function\n"
    "\t.thumb_func\n"
    "DrawCharacterGlyphTo2DGfxBuffer:\n"
    "\tpush\t{r4, r5, r6, r7, lr}\n"
    "\tmov\tr7, sl\n"
    "\tmov\tr6, r9\n"
    "\tmov\tr5, r8\n"
    "\tpush\t{r5, r6, r7}\n"
    "\tadd\tsp, sp, #-0x8c\n"
    "\tadd\tr5, r0, #0\n"
    "\tmov\tr9, r1\n"
    "\tadd\tr6, r2, #0\n"
    "\tadd\tr7, r3, #0\n"
    "\tldr\tr1, [sp, #0xac]\n"
    "\tadd\tr0, sp, #0x4\n"
    "\tbl\tDrawCharacterGlyph\n"
    "\tmov\tsl, r0\n"
    "\tsub\tr0, r0, #0x1\n"
    "\tcmp\tr0, #0x1\n"
    "\tbhi\t.Lfont_draw_normal_16\t@cond_branch\n"
    "\tlsr\tr4, r6, #0x3\n"
    "\tstr\tr4, [sp, #0x84]\n"
    "\tlsr\tr2, r7, #0x3\n"
    "\tlsl\tr0, r5, #0x10\n"
    "\tlsr\tr0, r0, #0x10\n"
    "\tmov\tr8, r0\n"
    "\tlsr\tr0, r5, #0x10\n"
    "\tmov\tip, r0\n"
    "\tcmp\tr4, r8\n"
    "\tbcs\t.Lfont_draw_normal_19\t@cond_branch\n"
    "\tcmp\tr2, r0\n"
    "\tbcs\t.Lfont_draw_normal_19\t@cond_branch\n"
    "\tmov\tr1, #0x0\n"
    "\tmov\tr3, #0x7\n"
    "\tadd\tr0, r6, #0\n"
    "\tand\tr0, r0, r3\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_normal_20\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_normal_20:\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_normal_22\t@cond_branch\n"
    "\tmov\tr1, #0x0\n"
    "\tadd\tr0, r7, #0\n"
    "\tand\tr0, r0, r3\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_normal_23\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_normal_23:\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_normal_22\t@cond_branch\n"
    "\tmov\tr0, #0x0\n"
    "\tstr\tr0, [sp, #0x88]\n"
    "\tadd\tr0, r4, #0x1\n"
    "\tcmp\tr0, r8\n"
    "\tbcs\t.Lfont_draw_normal_25\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    "\tstr\tr1, [sp, #0x88]\n"
    ".Lfont_draw_normal_25:\n"
    "\tmov\tr7, #0x0\n"
    "\tadd\tr5, r2, #0x1\n"
    "\tcmp\tr5, ip\n"
    "\tbcs\t.Lfont_draw_normal_26\t@cond_branch\n"
    "\tmov\tr7, #0x1\n"
    ".Lfont_draw_normal_26:\n"
    "\tmov\tr0, r8\n"
    "\tmul\tr0, r0, r2\n"
    "\tadd\tr0, r0, r4\n"
    "\tlsl\tr0, r0, #0x5\n"
    "\tmov\tr2, r9\n"
    "\tadd\tr6, r0, r2\n"
    "\tadd\tr0, sp, #0x4\n"
    "\tadd\tr1, r6, #0\n"
    "\tmov\tr2, #0x8\n"
    "\tbl\tCpuFastSet\n"
    "\tcmp\tr7, #0\n"
    "\tbeq\t.Lfont_draw_normal_27\t@cond_branch\n"
    "\tmov\tr1, r8\n"
    "\tmul\tr1, r1, r5\n"
    "\tadd\tr1, r1, r4\n"
    "\tlsl\tr1, r1, #0x5\n"
    "\tadd\tr1, r1, r9\n"
    "\tadd\tr0, sp, #0x44\n"
    "\tmov\tr2, #0x8\n"
    "\tbl\tCpuFastSet\n"
    ".Lfont_draw_normal_27:\n"
    "\tldr\tr0, [sp, #0x88]\n"
    "\tcmp\tr0, #0\n"
    "\tbeq\t.Lfont_draw_normal_19\t@cond_branch\n"
    "\tmov\tr1, sl\n"
    "\tcmp\tr1, #0x1\n"
    "\tbls\t.Lfont_draw_normal_19\t@cond_branch\n"
    "\tadd\tr1, r6, #0\n"
    "\tadd\tr1, r1, #0x20\n"
    "\tadd\tr0, sp, #0x24\n"
    "\tmov\tr2, #0x8\n"
    "\tbl\tCpuFastSet\n"
    "\tcmp\tr7, #0\n"
    "\tbeq\t.Lfont_draw_normal_19\t@cond_branch\n"
    "\tmov\tr0, r8\n"
    "\tmul\tr0, r0, r5\n"
    "\tldr\tr2, [sp, #0x84]\n"
    "\tadd\tr1, r2, r0\n"
    "\tlsl\tr0, r1, #0x5\n"
    "\tmov\tr2, r9\n"
    "\tadd\tr1, r0, r2\n"
    "\tadd\tr1, r1, #0x20\n"
    "\tadd\tr0, sp, #0x64\n"
    "\tmov\tr2, #0x8\n"
    "\tbl\tCpuFastSet\n"
    "\tb\t.Lfont_draw_normal_19\n"
    ".Lfont_draw_normal_I1_396:\n"
    ".Lfont_draw_normal_22:\n"
    "\tadd\tr0, sp, #0x4\n"
    "\tstr\tr0, [sp]\n"
    "\tadd\tr0, r5, #0\n"
    "\tmov\tr1, r9\n"
    "\tadd\tr2, r6, #0\n"
    "\tadd\tr3, r7, #0\n"
    "\tbl\tDrawCharacterGlyphTo2DGfxBufferUnaligned\n"
    ".Lfont_draw_normal_I1_413:\n"
    ".Lfont_draw_normal_19:\n"
    "\tmov\tr0, sl\n"
    "\tb\t.Lfont_draw_normal_31\n"
    ".Lfont_draw_normal_I1_421:\n"
    ".Lfont_draw_normal_16:\n"
    "\tmov\tr0, #0x0\n"
    ".Lfont_draw_normal_I1_426:\n"
    ".Lfont_draw_normal_31:\n"
    "\tadd\tsp, sp, #0x8c\n"
    "\tpop\t{r3, r4, r5}\n"
    "\tmov\tr8, r3\n"
    "\tmov\tr9, r4\n"
    "\tmov\tsl, r5\n"
    "\tpop\t{r4, r5, r6, r7}\n"
    "\tpop\t{r1}\n"
    "\tbx\tr1\n"
    ".Lfont_draw_normal_fe1:\n"
    "\t.align 2, 0\n"
    "\n"
    "@ Compose a glyph with the requested foreground/background palette pair.\n"
);

asm(
    ".text\n"
    ".syntax divided\n"
    ".thumb\n"
    "\t.align 2, 0\n"
    "\t.globl\tDrawCharacterGlyphTo2DGfxBufferExt\n"
    "\t.type\t DrawCharacterGlyphTo2DGfxBufferExt,function\n"
    "\t.thumb_func\n"
    "DrawCharacterGlyphTo2DGfxBufferExt:\n"
    "\tpush\t{r4, r5, r6, r7, lr}\n"
    "\tmov\tr7, sl\n"
    "\tmov\tr6, r9\n"
    "\tmov\tr5, r8\n"
    "\tpush\t{r5, r6, r7}\n"
    "\tadd\tsp, sp, #-0xa0\n"
    "\tadd\tr4, r0, #0\n"
    "\tmov\tsl, r1\n"
    "\tadd\tr5, r2, #0\n"
    "\tadd\tr6, r3, #0\n"
    "\tldr\tr1, [sp, #0xc0]\n"
    "\tadd\tr0, sp, #0xc\n"
    "\tbl\tDrawCharacterGlyph\n"
    "\tstr\tr0, [sp, #0x8c]\n"
    "\tsub\tr0, r0, #0x1\n"
    "\tcmp\tr0, #0x1\n"
    "\tbls\t.Lfont_draw_ext_CB32\n"
    "\tb\t.Lfont_draw_ext_4\t@long jump\n"
    ".Lfont_draw_ext_CB32:\n"
    "\tlsr\tr0, r5, #0x3\n"
    "\tmov\tip, r0\n"
    "\tlsr\tr3, r6, #0x3\n"
    "\tlsl\tr0, r4, #0x10\n"
    "\tlsr\tr0, r0, #0x10\n"
    "\tmov\tr8, r0\n"
    "\tlsr\tr0, r4, #0x10\n"
    "\tadd\tr7, r0, #0\n"
    "\tcmp\tip, r8\n"
    "\tbcc\t.Lfont_draw_ext_CB52\n"
    "\tb\t.Lfont_draw_ext_7\t@long jump\n"
    ".Lfont_draw_ext_CB52:\n"
    "\tcmp\tr3, r0\n"
    "\tbcc\t.Lfont_draw_ext_CB54\n"
    "\tb\t.Lfont_draw_ext_7\t@long jump\n"
    ".Lfont_draw_ext_CB54:\n"
    "\tmov\tr1, #0x0\n"
    "\tmov\tr2, #0x7\n"
    "\tadd\tr0, r5, #0\n"
    "\tand\tr0, r0, r2\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_ext_8\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_ext_8:\n"
    "\tcmp\tr1, #0\n"
    "\tbne\t.Lfont_draw_ext_CB74\n"
    "\tb\t.Lfont_draw_ext_10\t@long jump\n"
    ".Lfont_draw_ext_CB74:\n"
    "\tmov\tr1, #0x0\n"
    "\tadd\tr0, r6, #0\n"
    "\tand\tr0, r0, r2\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_ext_11\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_ext_11:\n"
    "\tcmp\tr1, #0\n"
    "\tbne\t.Lfont_draw_ext_CB92\n"
    "\tb\t.Lfont_draw_ext_10\t@long jump\n"
    ".Lfont_draw_ext_CB92:\n"
    "\tmov\tr1, #0x0\n"
    "\tmov\tr0, ip\n"
    "\tadd\tr0, r0, #0x1\n"
    "\tcmp\tr0, r8\n"
    "\tbcs\t.Lfont_draw_ext_13\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_ext_13:\n"
    "\tstr\tr1, [sp, #0x90]\n"
    "\tmov\tr0, #0x0\n"
    "\tadd\tr1, r3, #0x1\n"
    "\tstr\tr1, [sp, #0x98]\n"
    "\tcmp\tr1, r7\n"
    "\tbcs\t.Lfont_draw_ext_14\t@cond_branch\n"
    "\tmov\tr0, #0x1\n"
    ".Lfont_draw_ext_14:\n"
    "\tstr\tr0, [sp, #0x94]\n"
    "\tmov\tr0, r8\n"
    "\t.code\t16\n"
    "\tmul\tr0, r0, r3\n"
    "\t.code\t16\n"
    "\tadd\tr3, r0, #0\n"
    "\tmov\tr1, ip\n"
    "\t.code\t16\n"
    "\tadd\tr2, r3, r1\n"
    "\tlsl\tr2, r2, #0x5\n"
    "\tldr\tr0, [sp, #0xc8]\n"
    "\t.code\t16\n"
    "\tldr\tr1, [sp, #0xc4]\n"
    "\t.code\t16\n"
    "\tsub\tr6, r0, r1\n"
    "\tmov\tr0, #0xf\n"
    "\tand\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x4\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x8\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr5, r0, #0x10\n"
    "\torr\tr5, r5, r0\n"
    "\tmov\tr0, sl\n"
    "\t.code\t16\n"
    "\tadd\tr7, r2, r0\n"
    "\tadd\tr4, sp, #0xc\n"
    "\tadd\tr2, sp, #0x2c\n"
    "\tstr\tr3, [sp, #0x9c]\n"
    "\tmov\tr9, r6\n"
    "\tcmp\tr4, r2\n"
    "\tbeq\t.Lfont_draw_ext_15\t@cond_branch\n"
    "\tldr\tr3, .Lfont_draw_ext_44\n"
    ".Lfont_draw_ext_16:\n"
    "\tldmia\tr4!, {r0}\n"
    "\tadd\tr1, r0, #0\n"
    "\tand\tr1, r1, r3\n"
    "\tlsr\tr0, r0, #0x1\n"
    "\tand\tr0, r0, r3\n"
    "\torr\tr1, r1, r0\n"
    "\tmul\tr1, r1, r6\n"
    "\tadd\tr1, r5, r1\n"
    "\tadd\tr1, r1, r0\n"
    "\tstmia\tr7!, {r1}\n"
    "\tcmp\tr4, r2\n"
    "\tbne\t.Lfont_draw_ext_16\t@cond_branch\n"
    ".Lfont_draw_ext_15:\n"
    "\tldr\tr1, [sp, #0x94]\n"
    "\t.code\t16\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_ext_21\t@cond_branch\n"
    "\tldr\tr0, [sp, #0x98]\n"
    "\t.code\t16\n"
    "\tmov\tr2, r8\n"
    "\tmul\tr2, r2, r0\n"
    "\tadd\tr2, r2, ip\n"
    "\tlsl\tr2, r2, #0x5\n"
    "\tmov\tr7, r9\n"
    "\tmov\tr0, #0xf\n"
    "\tldr\tr1, [sp, #0xc4]\n"
    "\t.code\t16\n"
    "\tand\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x4\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x8\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr3, r0, #0x10\n"
    "\torr\tr3, r3, r0\n"
    "\tmov\tr0, sl\n"
    "\t.code\t16\n"
    "\tadd\tr6, r2, r0\n"
    "\tadd\tr2, sp, #0x4c\n"
    "\tadd\tr4, sp, #0x6c\n"
    "\tcmp\tr2, r4\n"
    "\tbeq\t.Lfont_draw_ext_21\t@cond_branch\n"
    "\tldr\tr5, .Lfont_draw_ext_44\n"
    ".Lfont_draw_ext_23:\n"
    "\tldmia\tr2!, {r0}\n"
    "\tadd\tr1, r0, #0\n"
    "\tand\tr1, r1, r5\n"
    "\tlsr\tr0, r0, #0x1\n"
    "\tand\tr0, r0, r5\n"
    "\torr\tr1, r1, r0\n"
    "\tmul\tr1, r1, r7\n"
    "\tadd\tr1, r3, r1\n"
    "\tadd\tr1, r1, r0\n"
    "\tstmia\tr6!, {r1}\n"
    "\tcmp\tr2, r4\n"
    "\tbne\t.Lfont_draw_ext_23\t@cond_branch\n"
    ".Lfont_draw_ext_21:\n"
    "\tldr\tr1, [sp, #0x90]\n"
    "\t.code\t16\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_ext_7\t@cond_branch\n"
    "\tldr\tr0, [sp, #0x8c]\n"
    "\t.code\t16\n"
    "\tcmp\tr0, #0x1\n"
    "\tbls\t.Lfont_draw_ext_7\t@cond_branch\n"
    "\tldr\tr3, [sp, #0x9c]\n"
    "\t.code\t16\n"
    "\tadd\tr3, r3, ip\n"
    "\tlsl\tr0, r3, #0x5\n"
    "\t.code\t16\n"
    "\tmov\tr1, sl\n"
    "\t.code\t16\n"
    "\tadd\tr3, r0, r1\n"
    "\tmov\tr7, r9\n"
    "\tmov\tr0, #0xf\n"
    "\tldr\tr1, [sp, #0xc4]\n"
    "\t.code\t16\n"
    "\tand\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x4\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x8\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr2, r0, #0x10\n"
    "\torr\tr2, r2, r0\n"
    "\tadd\tr6, r3, #0\n"
    "\tadd\tr6, r6, #0x20\n"
    "\tadd\tr5, sp, #0x2c\n"
    "\tadd\tr4, r5, #0\n"
    "\tadd\tr4, r4, #0x20\n"
    "\tcmp\tr5, r4\n"
    "\tbeq\t.Lfont_draw_ext_30\t@cond_branch\n"
    "\tldr\tr3, .Lfont_draw_ext_44\n"
    ".Lfont_draw_ext_31:\n"
    "\tldmia\tr5!, {r0}\n"
    "\tadd\tr1, r0, #0\n"
    "\tand\tr1, r1, r3\n"
    "\tlsr\tr0, r0, #0x1\n"
    "\tand\tr0, r0, r3\n"
    "\torr\tr1, r1, r0\n"
    "\tmul\tr1, r1, r7\n"
    "\tadd\tr1, r2, r1\n"
    "\tadd\tr1, r1, r0\n"
    "\tstmia\tr6!, {r1}\n"
    "\tcmp\tr5, r4\n"
    "\tbne\t.Lfont_draw_ext_31\t@cond_branch\n"
    ".Lfont_draw_ext_30:\n"
    "\tldr\tr0, [sp, #0x94]\n"
    "\t.code\t16\n"
    "\tcmp\tr0, #0\n"
    "\tbeq\t.Lfont_draw_ext_7\t@cond_branch\n"
    "\tldr\tr1, [sp, #0x98]\n"
    "\t.code\t16\n"
    "\tmov\tr0, r8\n"
    "\t.code\t16\n"
    "\tmul\tr0, r0, r1\n"
    "\tmov\tr1, ip\n"
    "\t.code\t16\n"
    "\tadd\tr2, r1, r0\n"
    "\tlsl\tr0, r2, #0x5\n"
    "\t.code\t16\n"
    "\tmov\tr1, sl\n"
    "\t.code\t16\n"
    "\tadd\tr2, r0, r1\n"
    "\tmov\tr7, r9\n"
    "\tmov\tr0, #0xf\n"
    "\tldr\tr1, [sp, #0xc4]\n"
    "\t.code\t16\n"
    "\tand\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x4\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr1, r0, #0x8\n"
    "\torr\tr0, r0, r1\n"
    "\tlsl\tr4, r0, #0x10\n"
    "\torr\tr4, r4, r0\n"
    "\tadd\tr6, r2, #0\n"
    "\tadd\tr6, r6, #0x20\n"
    "\tadd\tr3, sp, #0x6c\n"
    "\tadd\tr2, sp, #0x8c\n"
    "\tcmp\tr3, r2\n"
    "\tbeq\t.Lfont_draw_ext_7\t@cond_branch\n"
    "\tldr\tr5, .Lfont_draw_ext_44\n"
    ".Lfont_draw_ext_38:\n"
    "\tldmia\tr3!, {r0}\n"
    "\tadd\tr1, r0, #0\n"
    "\tand\tr1, r1, r5\n"
    "\tlsr\tr0, r0, #0x1\n"
    "\tand\tr0, r0, r5\n"
    "\torr\tr1, r1, r0\n"
    "\tmul\tr1, r1, r7\n"
    "\tadd\tr1, r4, r1\n"
    "\tadd\tr1, r1, r0\n"
    "\tstmia\tr6!, {r1}\n"
    "\tcmp\tr3, r2\n"
    "\tbne\t.Lfont_draw_ext_38\t@cond_branch\n"
    "\tb\t.Lfont_draw_ext_7\n"
    ".Lfont_draw_ext_45:\n"
    "\t.align\t2, 0\n"
    ".Lfont_draw_ext_44:\n"
    "\t.word\t0x11111111\n"
    ".Lfont_draw_ext_I1_891:\n"
    ".Lfont_draw_ext_10:\n"
    "\tadd\tr0, sp, #0xc\n"
    "\t.code\t16\n"
    "\tstr\tr0, [sp]\n"
    "\tldr\tr1, [sp, #0xc4]\n"
    "\t.code\t16\n"
    "\tstr\tr1, [sp, #0x4]\n"
    "\tldr\tr0, [sp, #0xc8]\n"
    "\tstr\tr0, [sp, #0x8]\n"
    "\tadd\tr0, r4, #0\n"
    "\tmov\tr1, sl\n"
    "\tadd\tr2, r5, #0\n"
    "\tadd\tr3, r6, #0\n"
    "\tbl\tDrawCharacterGlyphTo2DGfxBufferExtUnaligned\n"
    ".Lfont_draw_ext_I1_931:\n"
    ".Lfont_draw_ext_7:\n"
    "\tldr\tr0, [sp, #0x8c]\n"
    "\tb\t.Lfont_draw_ext_43\n"
    ".Lfont_draw_ext_I1_938:\n"
    ".Lfont_draw_ext_4:\n"
    "\tmov\tr0, #0x0\n"
    ".Lfont_draw_ext_43:\n"
    "\tadd\tsp, sp, #0xa0\n"
    "\tpop\t{r3, r4, r5}\n"
    "\tmov\tr8, r3\n"
    "\tmov\tr9, r4\n"
    "\tmov\tsl, r5\n"
    "\tpop\t{r4, r5, r6, r7}\n"
    "\tpop\t{r1}\n"
    "\tbx\tr1\n"
    ".Lfont_draw_ext_fe1:\n"
    "\t.align 2, 0\n"
    "\n"
    "@ Fill an aligned tile rectangle, or the whole buffer when it is covered.\n"
);

// Fill every tile in a packed two-dimensional 4bpp buffer with one palette
// nibble. The size word carries tile width in its low half and height in its
// high half.
void Clear2DGfxBuffer(u32 size, void *buffer, u32 color)
{
    u32 color_word = color & 0xF;
    u32 temporary;

    temporary = color_word << 4;
    color_word |= temporary;
    temporary = color_word << 8;
    color_word |= temporary;
    temporary = color_word << 16;
    color_word |= temporary;

    temporary = (u16)size;
    temporary *= (size >> 16) << 5;

    u32 fill_color = color_word;
    CpuFastSet(&fill_color, buffer,
        CPUSET_SRC_FIXED | ((temporary >> 2) & 0x1FFFFF));
}

asm(
    ".text\n"
    ".syntax divided\n"
    ".thumb\n"
    "\t.align 2, 0\n"
    "\t.globl\tClear2DGfxBufferRect\n"
    "\t.type\t Clear2DGfxBufferRect,function\n"
    "\t.thumb_func\n"
    "Clear2DGfxBufferRect:\n"
    "\tpush\t{r4, r5, r6, r7, lr}\n"
    "\tmov\tr7, r9\n"
    "\tmov\tr6, r8\n"
    "\tpush\t{r6, r7}\n"
    "\tadd\tsp, sp, #-0x4\n"
    "\tmov\tr8, r1\n"
    "\tadd\tr5, r2, #0\n"
    "\tldr\tr1, [sp, #0x20]\n"
    "\tmov\tip, r1\n"
    "\tldr\tr6, [sp, #0x24]\n"
    "\tldr\tr1, [sp, #0x28]\n"
    "\tmov\tr2, #0xf\n"
    "\tand\tr1, r1, r2\n"
    "\tlsl\tr2, r1, #0x4\n"
    "\torr\tr1, r1, r2\n"
    "\tlsl\tr2, r1, #0x8\n"
    "\torr\tr1, r1, r2\n"
    "\tlsl\tr2, r1, #0x10\n"
    "\torr\tr2, r2, r1\n"
    "\tmov\tr9, r2\n"
    "\tlsl\tr1, r0, #0x10\n"
    "\tlsr\tr2, r1, #0x10\n"
    "\tlsr\tr0, r0, #0x10\n"
    "\tlsl\tr1, r2, #0x3\n"
    "\tlsl\tr4, r0, #0x3\n"
    "\tcmp\tr5, #0\n"
    "\tbne\t.Lfont_draw_clear_rectangle_36\t@cond_branch\n"
    "\tcmp\tr3, #0\n"
    "\tbne\t.Lfont_draw_clear_rectangle_36\t@cond_branch\n"
    "\tcmp\tip, r1\n"
    "\tbcc\t.Lfont_draw_clear_rectangle_36\t@cond_branch\n"
    "\tcmp\tr6, r4\n"
    "\tbcc\t.Lfont_draw_clear_rectangle_36\t@cond_branch\n"
    "\tlsl\tr0, r0, #0x5\n"
    "\tmul\tr2, r2, r0\n"
    "\tmov\tr7, r9\n"
    "\tstr\tr7, [sp]\n"
    "\tlsr\tr2, r2, #0x2\n"
    "\tldr\tr0, .Lfont_draw_clear_rectangle_fomt_cpu_fastset_mask_0\n"
    "\tand\tr2, r2, r0\n"
    "\tmov\tr0, #0x80\n"
    "\tlsl\tr0, r0, #0x11\n"
    "\torr\tr2, r2, r0\n"
    "\tmov\tr0, sp\n"
    "\tmov\tr1, r8\n"
    "\tbl\tCpuFastSet\n"
    "\tb\t.Lfont_draw_clear_rectangle_35\n"
    "\t.align\t2, 0\n"
    ".Lfont_draw_clear_rectangle_fomt_cpu_fastset_mask_0:\n"
    "\t.word\t0x1fffff\n"
    ".Lfont_draw_clear_rectangle_36:\n"
    "\tcmp\tr5, r2\n"
    "\tbcs\t.Lfont_draw_clear_rectangle_35\t@cond_branch\n"
    "\tcmp\tr3, r0\n"
    "\tbcs\t.Lfont_draw_clear_rectangle_35\t@cond_branch\n"
    "\tmov\tr7, ip\n"
    "\tadd\tr0, r5, r7\n"
    "\tcmp\tr0, r1\n"
    "\tbcc\t.Lfont_draw_clear_rectangle_39\t@cond_branch\n"
    "\tsub\tr1, r1, r5\n"
    "\tmov\tip, r1\n"
    ".Lfont_draw_clear_rectangle_39:\n"
    "\tadd\tr0, r3, r6\n"
    "\tcmp\tr0, r4\n"
    "\tbcc\t.Lfont_draw_clear_rectangle_40\t@cond_branch\n"
    "\tsub\tr6, r4, r3\n"
    ".Lfont_draw_clear_rectangle_40:\n"
    "\tmov\tr1, #0x0\n"
    "\tmov\tr4, #0x7\n"
    "\tadd\tr0, r5, #0\n"
    "\tand\tr0, r0, r4\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_clear_rectangle_41\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_clear_rectangle_41:\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_clear_rectangle_35\t@cond_branch\n"
    "\tmov\tr1, #0x0\n"
    "\tadd\tr0, r3, #0\n"
    "\tand\tr0, r0, r4\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_clear_rectangle_43\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_clear_rectangle_43:\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_clear_rectangle_35\t@cond_branch\n"
    "\tmov\tr1, #0x0\n"
    "\tmov\tr0, ip\n"
    "\tand\tr0, r0, r4\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_clear_rectangle_45\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_clear_rectangle_45:\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_clear_rectangle_35\t@cond_branch\n"
    "\tmov\tr1, #0x0\n"
    "\tadd\tr0, r6, #0\n"
    "\tand\tr0, r0, r4\n"
    "\tcmp\tr0, #0\n"
    "\tbne\t.Lfont_draw_clear_rectangle_47\t@cond_branch\n"
    "\tmov\tr1, #0x1\n"
    ".Lfont_draw_clear_rectangle_47:\n"
    "\tcmp\tr1, #0\n"
    "\tbeq\t.Lfont_draw_clear_rectangle_35\t@cond_branch\n"
    "\tlsr\tr6, r6, #0x3\n"
    "\tlsr\tr0, r3, #0x3\n"
    "\tmul\tr0, r0, r2\n"
    "\tlsr\tr1, r5, #0x3\n"
    "\tadd\tr0, r0, r1\n"
    "\tlsl\tr0, r0, #0x5\n"
    "\tmov\tr1, r8\n"
    "\tadd\tr5, r1, r0\n"
    "\tlsl\tr7, r2, #0x5\n"
    "\tldr\tr4, .Lfont_draw_clear_rectangle_54\n"
    "\tmov\tr2, ip\n"
    "\tand\tr4, r4, r2\n"
    "\tldr\tr0, .Lfont_draw_clear_rectangle_58\n"
    "\tand\tr4, r4, r0\n"
    "\tmov\tr0, #0x80\n"
    "\tlsl\tr0, r0, #0x11\n"
    "\tmov\tr8, r0\n"
    ".Lfont_draw_clear_rectangle_49:\n"
    "\tmov\tr1, r9\n"
    "\tstr\tr1, [sp]\n"
    "\tmov\tr0, sp\n"
    "\tadd\tr1, r5, #0\n"
    "\tmov\tr2, r8\n"
    "\torr\tr2, r2, r4\n"
    "\tbl\tCpuFastSet\n"
    "\tadd\tr5, r5, r7\n"
    "\tsub\tr6, r6, #0x1\n"
    "\tcmp\tr6, #0\n"
    "\tbne\t.Lfont_draw_clear_rectangle_49\t@cond_branch\n"
    ".Lfont_draw_clear_rectangle_35:\n"
    "\tadd\tsp, sp, #0x4\n"
    "\tpop\t{r3, r4}\n"
    "\tmov\tr8, r3\n"
    "\tmov\tr9, r4\n"
    "\tpop\t{r4, r5, r6, r7}\n"
    "\tpop\t{r0}\n"
    "\tbx\tr0\n"
    ".Lfont_draw_clear_rectangle_55:\n"
    "\t.align\t2, 0\n"
    ".Lfont_draw_clear_rectangle_54: .word 0x3ffffff8\n"
    ".Lfont_draw_clear_rectangle_58: .word 0x1fffff\n"
    ".Lfont_draw_clear_rectangle_fe3:\n"
    "\t.align 2, 0\n"
);

// Draws a terminated Shift-JIS byte stream. A double-width character is
// accumulated from two input bytes when the first byte produces no glyph.
void DrawStringTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string)
{
    u8 const *current = string;
    i32 maximum_x = (size << 16) >> 13;
    i32 character = 0;
    u8 byte = *current;

    while (byte != 0 && (u32)x < (u32)maximum_x) {
        u32 glyph_width;

        character |= byte;
        glyph_width = DrawCharacterGlyphTo2DGfxBuffer(size, buffer, x, y,
            character);
        switch (glyph_width) {
        case 1:
            character = 0;
            x += 8;
            break;
        case 0:
            break;
        case 2:
            character = 0;
            x += 16;
            break;
        default:
            return;
        }

        current++;
        byte = *current;
        character <<= 8;
    }
}

// Equivalent string walker for the extended glyph compositor. The two extra
// values are forwarded unchanged to every resolved character.
void DrawStringTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string, i32 foreground, i32 background)
{
    u8 const *current = string;
    i32 maximum_x = (size << 16) >> 13;
    i32 character = 0;
    u8 byte = *current;

    while (byte != 0 && (u32)x < (u32)maximum_x) {
        u32 glyph_width;

        character |= byte;
        glyph_width = DrawCharacterGlyphTo2DGfxBufferExt(size, buffer, x, y,
            character, foreground, background);
        switch (glyph_width) {
        case 1:
            character = 0;
            x += 8;
            break;
        case 0:
            break;
        case 2:
            character = 0;
            x += 16;
            break;
        default:
            return;
        }

        current++;
        byte = *current;
        character <<= 8;
    }
}

// The original game reserves two ABI-compatible unaligned glyph paths, but
// both are deliberate no-ops. They return zero and leave the destination
// untouched; callers already ignore the return value on their fallback path.
i32 DrawCharacterGlyphTo2DGfxBufferUnaligned(u32 size, void *buffer, i32 x,
    i32 y, void *glyph)
{
    return 0;
}

i32 DrawCharacterGlyphTo2DGfxBufferExtUnaligned(u32 size, void *buffer,
    i32 x, i32 y, void *glyph, i32 foreground, i32 background)
{
    return 0;
}

// Copy a complete packed 4bpp tile buffer. The low and high halves of size
// are its tile width and height respectively.
void Copy2DGfxBuffer(u32 size, void *destination, void const *source)
{
    u32 tile_width = (u16)size;
    u32 tile_height = size >> 16;
    u32 word_count = tile_width * tile_height;

    word_count <<= 5;
    word_count >>= 2;
    word_count &= 0x1FFFFF;
    CpuFastSet(source, destination, word_count);
}

// Fill a tilemap rectangle with sequential tile IDs. The row stride is in
// 16-bit entries, so it may be larger than the visible width.
void Fill2DGfxTilemapRect(u16 *destination, u32 first_tile, u32 width,
    u32 height, u32 palette, u32 row_stride)
{
    u16 tile = first_tile;
    u16 palette_value = palette;
    u16 *row_pointer = destination;

    for (u32 row = 0; row < height; ++row) {
        for (u32 column = 0; column < width; ++column)
            *destination++ = tile++ | (palette_value << 12);

        row_pointer += row_stride;
        destination = row_pointer;
    }
}

EXTERN_C_END

FontTilemapRectCommand::FontTilemapRectCommand(u16 * destination, u16 first_tile,
    u32 width, u32 height, u16 palette, u32 row_stride)
{
    this->destination = destination;
    this->first_tile = first_tile;
    this->width = width;
    this->height = height;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapRectCommand::~FontTilemapRectCommand()
{
}
