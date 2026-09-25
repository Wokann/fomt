// Audit the non-image lookup fields in FarmHouse visual descriptors.
// A renderer reads width * height indices and uses each as a 32-bit lookup
// entry. This verifies only the code-proven bounds and regional equality;
// it does not assume these values are a palette or an editable image.
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { REGION_COUNT = 4, DESCRIPTOR_COUNT = 7 };
static char const *const region_names[REGION_COUNT] = {"jp", "us", "eu", "de"};
static size_t const table_bases[REGION_COUNT] =
    {0x106C24, 0x1070DC, 0x107134, 0x107B00};

typedef struct {
    unsigned char *bytes;
    size_t size;
} Rom;

typedef struct {
    unsigned width;
    unsigned height;
    unsigned distinct;
    unsigned max_index;
    size_t cell_count;
    size_t value_count;
    size_t values_offset;
    size_t indices_offset;
    unsigned char const *indices;
    unsigned char const *values;
} LookupRect;

static void fail(char const *message)
{
    fprintf(stderr, "farm-house-lookup-audit: %s\n", message);
    exit(1);
}

static Rom read_rom(char const *path)
{
    FILE *file = fopen(path, "rb");
    if (!file)
        fail("cannot open input ROM");
    if (fseek(file, 0, SEEK_END) != 0)
        fail("cannot seek input ROM");
    long length = ftell(file);
    if (length < 0 || fseek(file, 0, SEEK_SET) != 0)
        fail("cannot measure input ROM");
    Rom rom = {malloc((size_t)length ? (size_t)length : 1), (size_t)length};
    if (!rom.bytes)
        fail("out of memory");
    if (fread(rom.bytes, 1, rom.size, file) != rom.size || fclose(file) != 0)
        fail("cannot read input ROM");
    return rom;
}

static void check_range(Rom const *rom, size_t offset, size_t length)
{
    if (offset > rom->size || length > rom->size - offset)
        fail("descriptor range exceeds ROM");
}

static uint32_t read_le32(unsigned char const *bytes)
{
    return (uint32_t)bytes[0] | (uint32_t)bytes[1] << 8 |
           (uint32_t)bytes[2] << 16 | (uint32_t)bytes[3] << 24;
}

static size_t pointer_offset(Rom const *rom, size_t field)
{
    check_range(rom, field, 4);
    uint32_t pointer = read_le32(rom->bytes + field);
    if (pointer < 0x08000000u ||
        (size_t)(pointer - 0x08000000u) >= rom->size)
        fail("invalid FarmHouse lookup pointer");
    return (size_t)(pointer - 0x08000000u);
}

static LookupRect parse_rect(Rom const *rom, size_t table_base, unsigned number)
{
    size_t record = table_base + 0x128 + (size_t)number * 0x2C;
    check_range(rom, record, 0x2C);
    LookupRect rect = {0};
    rect.width = rom->bytes[record];
    rect.height = rom->bytes[record + 1];
    if (!rect.width || !rect.height)
        fail("FarmHouse lookup rectangle is empty");
    rect.cell_count = (size_t)rect.width * rect.height;
    rect.values_offset = pointer_offset(rom, record + 0x10);
    rect.indices_offset = pointer_offset(rom, record + 0x14);
    check_range(rom, rect.indices_offset, rect.cell_count);
    rect.indices = rom->bytes + rect.indices_offset;
    unsigned char seen[256] = {0};
    for (size_t cell = 0; cell < rect.cell_count; cell++) {
        unsigned index = rect.indices[cell];
        if (index > rect.max_index)
            rect.max_index = index;
        if (!seen[index]) {
            seen[index] = 1;
            rect.distinct++;
        }
    }
    rect.value_count = (size_t)rect.max_index + 1;
    check_range(rom, rect.values_offset, rect.value_count * 4);
    rect.values = rom->bytes + rect.values_offset;
    return rect;
}

static void verify_rects(LookupRect const rects[REGION_COUNT][DESCRIPTOR_COUNT])
{
    for (unsigned number = 0; number < DESCRIPTOR_COUNT; number++) {
        LookupRect const *reference = &rects[0][number];
        for (unsigned region = 1; region < REGION_COUNT; region++) {
            LookupRect const *other = &rects[region][number];
            if (reference->width != other->width ||
                reference->height != other->height ||
                reference->max_index != other->max_index ||
                memcmp(reference->indices, other->indices,
                       reference->cell_count) != 0 ||
                memcmp(reference->values, other->values,
                       reference->value_count * 4) != 0)
                fail("FarmHouse lookup fields differ between regions");
        }
    }
}

static void write_csv(char const *path,
                      LookupRect const rects[REGION_COUNT][DESCRIPTOR_COUNT])
{
    FILE *file = fopen(path, "wb");
    if (!file)
        fail("cannot open CSV output");
    if (fprintf(file,
                "descriptor,width,height,cells,distinct_indices,max_index,"
                "minimum_values,jp_values_offset,jp_indices_offset,"
                "all_regions_shared\r\n") < 0)
        fail("cannot write CSV header");
    for (unsigned number = 0; number < DESCRIPTOR_COUNT; number++) {
        LookupRect const *rect = &rects[0][number];
        if (fprintf(file, "%u,%u,%u,%zu,%u,%u,%zu,0x%zX,0x%zX,True\r\n",
                    number, rect->width, rect->height, rect->cell_count,
                    rect->distinct, rect->max_index, rect->value_count,
                    rect->values_offset, rect->indices_offset) < 0)
            fail("cannot write CSV row");
    }
    if (fclose(file) != 0)
        fail("cannot close CSV output");
}

int main(int argc, char **argv)
{
    char const *paths[REGION_COUNT] = {0};
    char const *csv = NULL;
    for (int arg = 1; arg < argc; arg++) {
        if (strcmp(argv[arg], "--rom") == 0 && arg + 2 < argc) {
            char const *name = argv[++arg];
            char const *path = argv[++arg];
            unsigned region;
            for (region = 0; region < REGION_COUNT; region++)
                if (strcmp(name, region_names[region]) == 0)
                    break;
            if (region == REGION_COUNT || paths[region])
                fail("unknown or duplicate region");
            paths[region] = path;
        } else if (strcmp(argv[arg], "--csv") == 0 && arg + 1 < argc) {
            csv = argv[++arg];
        } else {
            fail("usage: [--rom REGION ROM] x4 [--csv OUTPUT]");
        }
    }
    Rom roms[REGION_COUNT];
    LookupRect rects[REGION_COUNT][DESCRIPTOR_COUNT];
    for (unsigned region = 0; region < REGION_COUNT; region++) {
        if (!paths[region])
            fail("requires exactly jp, us, eu, and de ROMs");
        roms[region] = read_rom(paths[region]);
        for (unsigned number = 0; number < DESCRIPTOR_COUNT; number++)
            rects[region][number] =
                parse_rect(&roms[region], table_bases[region], number);
    }
    verify_rects(rects);
    if (csv)
        write_csv(csv, rects);
    size_t cells = 0;
    unsigned max_index = 0;
    for (unsigned number = 0; number < DESCRIPTOR_COUNT; number++) {
        cells += rects[0][number].cell_count;
        if (rects[0][number].max_index > max_index)
            max_index = rects[0][number].max_index;
    }
    printf("verified %u FarmHouse lookup rectangles across all regions; "
           "%zu cells, maximum lookup index %u, "
           "all referenced values are shared\n",
           DESCRIPTOR_COUNT, cells, max_index);
    for (unsigned region = 0; region < REGION_COUNT; region++)
        free(roms[region].bytes);
    return 0;
}
