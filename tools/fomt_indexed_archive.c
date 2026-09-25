// Rebuild the single-tile class of FoMT IndexedResourceArchive from indexed PNGs.
// The seven native counted tables remain source data in ARCHIVE_ORIGINAL;
// each drawable descriptor's tile and palette are rebuilt from its PNG.
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void fail(char const *message)
{
    fprintf(stderr, "fomt-indexed-archive: %s\n", message);
    exit(1);
}

static unsigned char *read_file(char const *path, size_t *size)
{
    FILE *file = fopen(path, "rb");
    if (!file)
        fail("cannot open input file");
    if (fseek(file, 0, SEEK_END) != 0)
        fail("cannot seek input file");
    long length = ftell(file);
    if (length < 0 || fseek(file, 0, SEEK_SET) != 0)
        fail("cannot measure input file");
    unsigned char *bytes = malloc((size_t)length ? (size_t)length : 1);
    if (!bytes)
        fail("out of memory");
    if (fread(bytes, 1, (size_t)length, file) != (size_t)length)
        fail("cannot read input file");
    if (fclose(file) != 0)
        fail("cannot close input file");
    *size = (size_t)length;
    return bytes;
}

static void write_file(char const *path, unsigned char const *bytes, size_t size)
{
    FILE *file = fopen(path, "wb");
    if (!file)
        fail("cannot open output file");
    if (fwrite(bytes, 1, size, file) != size || fclose(file) != 0)
        fail("cannot write output file");
}

static unsigned read_le16(unsigned char const *bytes)
{
    return (unsigned)bytes[0] | (unsigned)bytes[1] << 8;
}

static uint32_t read_le32(unsigned char const *bytes)
{
    return (uint32_t)bytes[0] | (uint32_t)bytes[1] << 8 |
           (uint32_t)bytes[2] << 16 | (uint32_t)bytes[3] << 24;
}

static uint32_t read_be32(unsigned char const *bytes)
{
    return (uint32_t)bytes[3] | (uint32_t)bytes[2] << 8 |
           (uint32_t)bytes[1] << 16 | (uint32_t)bytes[0] << 24;
}

static void group_path(char path[512], char const *directory,
                       unsigned group, char const *extension)
{
    int length = snprintf(path, 512, "%s/full/group_%03u.%s",
                          directory, group, extension);
    if (length < 0 || length >= 512)
        fail("group source path is too long");
}

static void verify_png_size(char const *path)
{
    size_t size;
    unsigned char *png = read_file(path, &size);
    static unsigned char const signature[8] =
        {137, 80, 78, 71, 13, 10, 26, 10};
    if (size < 24 || memcmp(png, signature, 8) != 0 ||
        memcmp(png + 12, "IHDR", 4) != 0 ||
        read_be32(png + 16) != 8 || read_be32(png + 20) != 8)
        fail("single-tile archive source PNG must be 8 by 8 pixels");
    free(png);
}

int main(int argc, char **argv)
{
    if (argc != 5 || strcmp(argv[1], "rebuild-single-tile") != 0)
        fail("usage: rebuild-single-tile ARCHIVE_ORIGINAL SOURCE_DIR OUTPUT");
    size_t size;
    unsigned char *archive = read_file(argv[2], &size);
    static unsigned const strides[7] = {4, 16, 8, 32, 32, 8, 4};
    size_t offsets[7];
    uint32_t counts[7];
    size_t cursor = 0;
    for (unsigned table = 0; table < 7; table++) {
        if (size - cursor < 4)
            fail("archive ends before a table count");
        counts[table] = read_le32(archive + cursor);
        cursor += 4;
        offsets[table] = cursor;
        if (counts[table] > (size - cursor) / strides[table])
            fail("archive table exceeds its source allocation");
        cursor += (size_t)counts[table] * strides[table];
    }
    if (cursor != size || !counts[1] || !counts[3] || !counts[4])
        fail("archive has an invalid seven-table layout");
    unsigned char *assigned = calloc(counts[3], 1);
    unsigned char *assigned_palette = calloc(counts[4], 1);
    if (!assigned || !assigned_palette)
        fail("out of memory");
    unsigned drawable = 0;
    for (unsigned group = 0; group < counts[1]; group++) {
        unsigned char const *descriptor = archive + offsets[1] + group * 16;
        unsigned oam_count = read_le16(descriptor);
        if (!oam_count) {
            for (unsigned byte = 0; byte < 16; byte++)
                if (descriptor[byte])
                    fail("non-drawable descriptor is not empty");
            continue;
        }
        unsigned oam = read_le16(descriptor + 2);
        unsigned tile_count = read_le16(descriptor + 4);
        unsigned tile = read_le16(descriptor + 6);
        unsigned palette_count = read_le16(descriptor + 8);
        unsigned palette = read_le16(descriptor + 10);
        if (oam_count != 1 || oam >= counts[2] || tile_count != 1 ||
            tile >= counts[3] || palette_count != 1 || palette >= counts[4] ||
            read_le16(descriptor + 12) || read_le16(descriptor + 14))
            fail("descriptor is outside the supported single-tile layout");
        unsigned char const *oam_data = archive + offsets[2] + oam * 8;
        unsigned attr0 = read_le16(oam_data);
        unsigned attr1 = read_le16(oam_data + 2);
        unsigned attr2 = read_le16(oam_data + 4);
        if ((attr0 & 0xC300u) || (attr1 & 0xF000u) || (attr2 & 0x3FFu))
            fail("descriptor OAM is not an unflipped 8 by 8 tile");

        char path[512];
        group_path(path, argv[3], group, "png");
        verify_png_size(path);
        group_path(path, argv[3], group, "gbapal");
        size_t palette_size;
        unsigned char *colors = read_file(path, &palette_size);
        if (palette_size != 32)
            fail("single-tile PNG did not convert to a 32-byte palette");
        unsigned char *native_palette = archive + offsets[4] + palette * 32;
        if (assigned_palette[palette] && memcmp(native_palette, colors, 32) != 0)
            fail("two drawable groups assign different colors to one palette");
        memcpy(native_palette, colors, 32);
        assigned_palette[palette] = 1;
        free(colors);
        group_path(path, argv[3], group, "4bpp");
        size_t tile_size;
        unsigned char *pixels = read_file(path, &tile_size);
        if (tile_size != 32)
            fail("single-tile PNG did not convert to 32 bytes of 4bpp");
        unsigned char *native = archive + offsets[3] + tile * 32;
        if (assigned[tile] && memcmp(native, pixels, 32) != 0)
            fail("two drawable groups assign different pixels to one tile");
        memcpy(native, pixels, 32);
        assigned[tile] = 1;
        drawable++;
        free(pixels);
    }
    if (!drawable)
        fail("archive has no drawable groups");
    for (unsigned tile = 0; tile < counts[3]; tile++)
        if (!assigned[tile])
            fail("a native tile has no editable PNG owner");
    for (unsigned palette = 0; palette < counts[4]; palette++)
        if (!assigned_palette[palette])
            fail("a native palette has no editable PNG owner");
    free(assigned);
    free(assigned_palette);
    write_file(argv[4], archive, size);
    free(archive);
    return 0;
}
