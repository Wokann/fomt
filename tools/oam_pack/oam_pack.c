/*
 * FoMT indexed-PNG OAM packer.
 *
 * A forward resource compiler: it accepts an indexed full PNG, produces a
 * 4bpp tile stream and ordinary eight-byte GBA OAM template entries, then
 * renders those bytes back to prove the visible pixels are preserved.  A ROM
 * archive is optional and is used only as a byte-level comparison oracle.
 */

#include <errno.h>
#include <inttypes.h>
#include <png.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Image {
    int width;
    int height;
    uint16_t palette[16];
    uint8_t *pixels;
};

struct Bytes {
    uint8_t *data;
    size_t size;
    size_t capacity;
};

struct Piece {
    int x;
    int y;
    int width;
    int height;
    int tile_start;
};

struct Pieces {
    struct Piece *data;
    size_t count;
    size_t capacity;
};

struct Dimension {
    int width;
    int height;
    int shape;
    int size;
};

static const struct Dimension sDimensions[] = {
    {64, 64, 0, 3}, {64, 32, 1, 3}, {32, 64, 2, 3},
    {32, 32, 0, 2}, {32, 16, 1, 2}, {16, 32, 2, 2},
    {32, 8, 1, 1}, {16, 16, 0, 1}, {8, 32, 2, 1},
    {16, 8, 1, 0}, {8, 16, 2, 0}, {8, 8, 0, 0},
};

static void Fail(const char *message)
{
    fprintf(stderr, "oam_pack: %s\n", message);
    exit(EXIT_FAILURE);
}

static void FailPath(const char *action, const char *path)
{
    fprintf(stderr, "oam_pack: %s %s: %s\n", action, path, strerror(errno));
    exit(EXIT_FAILURE);
}

static int ParseNumber(const char *text)
{
    char *end = NULL;
    long value = strtol(text, &end, 0);
    if (!text[0] || (end != NULL && *end) || value < INT32_MIN || value > INT32_MAX)
        Fail("invalid numeric argument");
    return (int)value;
}

static void *CheckedAlloc(size_t size)
{
    void *result = malloc(size ? size : 1);
    if (result == NULL)
        Fail("out of memory");
    return result;
}

static void BytesAppend(struct Bytes *bytes, const void *data, size_t size)
{
    if (bytes->size + size > bytes->capacity) {
        size_t capacity = bytes->capacity ? bytes->capacity : 256;
        while (capacity < bytes->size + size)
            capacity *= 2;
        bytes->data = realloc(bytes->data, capacity);
        if (bytes->data == NULL)
            Fail("out of memory");
        bytes->capacity = capacity;
    }
    memcpy(bytes->data + bytes->size, data, size);
    bytes->size += size;
}

static void PiecesAppend(struct Pieces *pieces, struct Piece piece)
{
    if (pieces->count == pieces->capacity) {
        size_t capacity = pieces->capacity ? pieces->capacity * 2 : 16;
        pieces->data = realloc(pieces->data, capacity * sizeof(*pieces->data));
        if (pieces->data == NULL)
            Fail("out of memory");
        pieces->capacity = capacity;
    }
    pieces->data[pieces->count++] = piece;
}

static void ReadIndexedPng(const char *path, struct Image *image)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL)
        FailPath("cannot open", path);
    uint8_t signature[8];
    if (fread(signature, 1, sizeof(signature), file) != sizeof(signature)
     || png_sig_cmp(signature, 0, sizeof(signature)))
        Fail("input is not a PNG");

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png == NULL)
        Fail("cannot initialize libpng reader");
    png_infop info = png_create_info_struct(png);
    if (info == NULL)
        Fail("cannot initialize libpng reader");
    if (setjmp(png_jmpbuf(png)))
        Fail("cannot decode indexed PNG");
    png_init_io(png, file);
    png_set_sig_bytes(png, sizeof(signature));
    png_read_info(png, info);
    int depth = png_get_bit_depth(png, info);
    int color_type = png_get_color_type(png, info);
    png_colorp palette = NULL;
    int palette_size = 0;
    if (color_type != PNG_COLOR_TYPE_PALETTE || !png_get_PLTE(png, info, &palette, &palette_size))
        Fail("input must be a palette-indexed PNG");
    if (palette_size > 16)
        Fail("input palette has more than 16 entries; FoMT sprites are 4bpp");
    for (int index = 0; index < palette_size; index++) {
        unsigned red = ((unsigned)palette[index].red * 31 + 127) / 255;
        unsigned green = ((unsigned)palette[index].green * 31 + 127) / 255;
        unsigned blue = ((unsigned)palette[index].blue * 31 + 127) / 255;
        image->palette[index] = (uint16_t)(red | (green << 5) | (blue << 10));
    }
    if (depth < 8)
        png_set_packing(png);
    png_read_update_info(png, info);
    image->width = (int)png_get_image_width(png, info);
    image->height = (int)png_get_image_height(png, info);
    if (image->width <= 0 || image->height <= 0)
        Fail("input has invalid dimensions");
    size_t row_bytes = png_get_rowbytes(png, info);
    if (row_bytes < (size_t)image->width)
        Fail("input has unexpected packed rows");
    uint8_t *rows = CheckedAlloc(row_bytes * (size_t)image->height);
    png_bytep *row_pointers = CheckedAlloc(sizeof(*row_pointers) * (size_t)image->height);
    for (int y = 0; y < image->height; y++)
        row_pointers[y] = rows + row_bytes * (size_t)y;
    png_read_image(png, row_pointers);
    image->pixels = CheckedAlloc((size_t)image->width * image->height);
    for (int y = 0; y < image->height; y++)
        memcpy(image->pixels + (size_t)y * image->width, row_pointers[y], image->width);
    free(row_pointers);
    free(rows);
    png_destroy_read_struct(&png, &info, NULL);
    fclose(file);
}

/*
 * Full portrait sources are normally tile-aligned.  A few legacy archive
 * exports are cropped to their visible bounds instead (for example 78x76).
 * Treat the omitted right/bottom pixels as transparent rather than rejecting
 * the artwork: OAM can only encode complete 8x8 tiles, and this padding does
 * not alter any authored pixel or palette index.
 */
static void PadImageToTiles(struct Image *image)
{
    int padded_width = (image->width + 7) & ~7;
    int padded_height = (image->height + 7) & ~7;
    if (padded_width == image->width && padded_height == image->height)
        return;
    uint8_t *pixels = calloc((size_t)padded_width * padded_height, 1);
    if (pixels == NULL)
        Fail("out of memory");
    for (int y = 0; y < image->height; y++)
        memcpy(pixels + (size_t)y * padded_width,
               image->pixels + (size_t)y * image->width, image->width);
    fprintf(stderr, "oam_pack: padded source canvas from %dx%d to %dx%d with transparent tile edges\n",
            image->width, image->height, padded_width, padded_height);
    free(image->pixels);
    image->pixels = pixels;
    image->width = padded_width;
    image->height = padded_height;
}

static bool TileIsActive(const struct Image *image, int tile_x, int tile_y)
{
    for (int y = 0; y < 8; y++) {
        const uint8_t *row = image->pixels + (size_t)(tile_y * 8 + y) * image->width + tile_x * 8;
        for (int x = 0; x < 8; x++)
            if (row[x] != 0)
                return true;
    }
    return false;
}

static int RemainingInRect(const uint8_t *remaining, int grid_width, int x, int y, int width, int height)
{
    int count = 0;
    for (int row = y; row < y + height; row++)
        for (int column = x; column < x + width; column++)
            count += remaining[row * grid_width + column] != 0;
    return count;
}

static bool RectTouchesOccupied(const uint8_t *occupied, int grid_width, int x, int y, int width, int height)
{
    if (occupied == NULL)
        return false;
    for (int row = y; row < y + height; row++)
        for (int column = x; column < x + width; column++)
            if (occupied[row * grid_width + column])
                return true;
    return false;
}

static void MarkRectOccupied(uint8_t *occupied, int grid_width, int x, int y, int width, int height)
{
    for (int row = y; row < y + height; row++)
        for (int column = x; column < x + width; column++)
            occupied[row * grid_width + column] = 1;
}

static struct Piece ChoosePiece(const uint8_t *remaining, const uint8_t *occupied,
                                int grid_width, int grid_height, int anchor_x, int anchor_y, int tile_start)
{
    bool found = false;
    struct Piece best = {0};
    int best_count = -1;
    int best_density = -1;
    int best_area = -1;
    for (size_t dimension_index = 0; dimension_index < sizeof(sDimensions) / sizeof(sDimensions[0]); dimension_index++) {
        const struct Dimension *dimension = &sDimensions[dimension_index];
        int tiles_wide = dimension->width / 8;
        int tiles_high = dimension->height / 8;
        int area = tiles_wide * tiles_high;
        int x_low = anchor_x - tiles_wide + 1;
        int x_high = anchor_x;
        int y_low = anchor_y - tiles_high + 1;
        int y_high = anchor_y;
        if (x_low < 0) x_low = 0;
        if (y_low < 0) y_low = 0;
        if (x_high > grid_width - tiles_wide) x_high = grid_width - tiles_wide;
        if (y_high > grid_height - tiles_high) y_high = grid_height - tiles_high;
        for (int y = y_low; y <= y_high; y++) {
            for (int x = x_low; x <= x_high; x++) {
                if (RectTouchesOccupied(occupied, grid_width, x, y, tiles_wide, tiles_high))
                    continue;
                int count = RemainingInRect(remaining, grid_width, x, y, tiles_wide, tiles_high);
                if (count == 0 || (area != 1 && (count < 2 || count * 2 < area)))
                    continue;
                int density = count * 1000 / area;
                if (!found || count > best_count || (count == best_count && density > best_density)
                 || (count == best_count && density == best_density && area > best_area)
                 || (count == best_count && density == best_density && area == best_area
                  && (y < best.y / 8 || (y == best.y / 8 && x < best.x / 8)))) {
                    best = (struct Piece){x * 8, y * 8, dimension->width, dimension->height, tile_start};
                    best_count = count;
                    best_density = density;
                    best_area = area;
                    found = true;
                }
            }
        }
    }
    if (!found)
        Fail("could not select an OAM piece for an active tile");
    return best;
}

static void EncodeTile(const struct Image *image, int x, int y, uint8_t output[32])
{
    for (int row = 0; row < 8; row++) {
        for (int pair = 0; pair < 4; pair++) {
            uint8_t first = image->pixels[(size_t)(y + row) * image->width + x + pair * 2];
            uint8_t second = image->pixels[(size_t)(y + row) * image->width + x + pair * 2 + 1];
            output[row * 4 + pair] = first | (second << 4);
        }
    }
}

static void PackDense(const struct Image *image, int tile_base, struct Pieces *pieces, struct Bytes *tiles)
{
    if (image->width % 8 || image->height % 8)
        Fail("input dimensions must be multiples of 8");
    int grid_width = image->width / 8;
    int grid_height = image->height / 8;
    uint8_t *remaining = calloc((size_t)grid_width * grid_height, 1);
    if (remaining == NULL)
        Fail("out of memory");
    int remaining_count = 0;
    for (int y = 0; y < grid_height; y++) {
        for (int x = 0; x < grid_width; x++) {
            if (TileIsActive(image, x, y)) {
                remaining[y * grid_width + x] = 1;
                remaining_count++;
            }
        }
    }
    while (remaining_count) {
        int anchor_x = 0;
        int anchor_y = 0;
        bool found = false;
        for (int y = 0; y < grid_height && !found; y++)
            for (int x = 0; x < grid_width; x++)
                if (remaining[y * grid_width + x]) {
                    anchor_x = x;
                    anchor_y = y;
                    found = true;
                    break;
                }
        struct Piece piece = ChoosePiece(remaining, NULL, grid_width, grid_height, anchor_x, anchor_y,
                                         tile_base + (int)(tiles->size / 32));
        for (int row = 0; row < piece.height / 8; row++) {
            for (int column = 0; column < piece.width / 8; column++) {
                uint8_t encoded[32];
                EncodeTile(image, piece.x + column * 8, piece.y + row * 8, encoded);
                BytesAppend(tiles, encoded, sizeof(encoded));
                int cell = (piece.y / 8 + row) * grid_width + piece.x / 8 + column;
                if (remaining[cell]) {
                    remaining[cell] = 0;
                    remaining_count--;
                }
            }
        }
        PiecesAppend(pieces, piece);
    }
    free(remaining);
    if (pieces->count > 128)
        Fail("packed image uses more than GBA's 128 OAM entries");
    if (tile_base + (int)(tiles->size / 32) > 0x400)
        Fail("packed image exceeds GBA attr2's 10-bit tile range");
}

static void PackOpaque(const struct Image *image, int tile_base, struct Pieces *pieces, struct Bytes *tiles)
{
    if (image->width % 8 || image->height % 8)
        Fail("input dimensions must be multiples of 8");
    int grid_width = image->width / 8;
    int grid_height = image->height / 8;
    uint8_t *remaining = calloc((size_t)grid_width * grid_height, 1);
    uint8_t *occupied = calloc((size_t)grid_width * grid_height, 1);
    if (remaining == NULL || occupied == NULL)
        Fail("out of memory");
    int remaining_count = 0;
    for (int y = 0; y < grid_height; y++) {
        for (int x = 0; x < grid_width; x++) {
            if (TileIsActive(image, x, y)) {
                remaining[y * grid_width + x] = 1;
                remaining_count++;
            }
        }
    }
    while (remaining_count) {
        int anchor_x = 0;
        int anchor_y = 0;
        bool found = false;
        for (int y = 0; y < grid_height && !found; y++)
            for (int x = 0; x < grid_width; x++)
                if (remaining[y * grid_width + x]) {
                    anchor_x = x;
                    anchor_y = y;
                    found = true;
                    break;
                }
        struct Piece piece = ChoosePiece(remaining, occupied, grid_width, grid_height, anchor_x, anchor_y,
                                         tile_base + (int)(tiles->size / 32));
        for (int row = 0; row < piece.height / 8; row++) {
            for (int column = 0; column < piece.width / 8; column++) {
                uint8_t encoded[32];
                EncodeTile(image, piece.x + column * 8, piece.y + row * 8, encoded);
                BytesAppend(tiles, encoded, sizeof(encoded));
                int cell = (piece.y / 8 + row) * grid_width + piece.x / 8 + column;
                if (remaining[cell]) {
                    remaining[cell] = 0;
                    remaining_count--;
                }
            }
        }
        MarkRectOccupied(occupied, grid_width, piece.x / 8, piece.y / 8, piece.width / 8, piece.height / 8);
        PiecesAppend(pieces, piece);
    }
    free(remaining);
    free(occupied);
    if (pieces->count > 128)
        Fail("packed image uses more than GBA's 128 OAM entries");
    if (tile_base + (int)(tiles->size / 32) > 0x400)
        Fail("packed image exceeds GBA attr2's 10-bit tile range");
}

static bool IsOamDimension(int width, int height)
{
    for (size_t index = 0; index < sizeof(sDimensions) / sizeof(sDimensions[0]); index++)
        if (sDimensions[index].width == width && sDimensions[index].height == height)
            return true;
    return false;
}

/*
 * A complete source canvas need not have a single column partition: 64x72,
 * for example, requires a 64-wide 32-pixel row but a narrower top row because
 * GBA has no 64x8 object.  Partition each row independently.  This is a
 * deterministic forward rule that uses no ROM layout data and always retains
 * transparent tiles inside its chosen legal OAM rectangles.
 */
static bool CanvasCanPartitionWidth(int width, int height)
{
    if (width == 0)
        return true;
    if (width < 0 || width % 8)
        return false;
    size_t cells = (size_t)width / 8;
    uint8_t *reachable = calloc(cells + 1, 1);
    if (reachable == NULL)
        Fail("out of memory");
    reachable[0] = 1;
    for (size_t start = 0; start < cells; start++) {
        if (!reachable[start])
            continue;
        for (size_t index = 0; index < sizeof(sDimensions) / sizeof(sDimensions[0]); index++) {
            const struct Dimension *dimension = &sDimensions[index];
            if (dimension->height != height)
                continue;
            size_t end = start + (size_t)dimension->width / 8;
            if (end <= cells)
                reachable[end] = 1;
        }
    }
    bool result = reachable[cells] != 0;
    free(reachable);
    return result;
}

static int CanvasRowHeight(int remaining, int width)
{
    static const int heights[] = {64, 32, 16, 8};
    for (size_t index = 0; index < sizeof(heights) / sizeof(heights[0]); index++)
        if (heights[index] <= remaining && CanvasCanPartitionWidth(width, heights[index]))
            return heights[index];
    Fail("canvas height cannot be expressed with GBA object dimensions");
    return 0;
}

static int CanvasPieceWidth(int remaining, int height)
{
    static const int widths[] = {64, 32, 16, 8};
    for (size_t index = 0; index < sizeof(widths) / sizeof(widths[0]); index++) {
        int width = widths[index];
        if (width <= remaining && IsOamDimension(width, height)
         && CanvasCanPartitionWidth(remaining - width, height))
            return width;
    }
    Fail("canvas width cannot be expressed with GBA object dimensions");
    return 0;
}

static void PackCanvas(const struct Image *image, int tile_base, struct Pieces *pieces, struct Bytes *tiles)
{
    if (image->width % 8 || image->height % 8)
        Fail("input dimensions must be multiples of 8");
    int remaining_height = image->height;
    while (remaining_height) {
        int row_height = CanvasRowHeight(remaining_height, image->width);
        int y = remaining_height - row_height;
        int x = 0;
        while (x < image->width) {
            int width = CanvasPieceWidth(image->width - x, row_height);
            struct Piece piece = {
                x, y, width, row_height, tile_base + (int)(tiles->size / 32)
            };
            for (int tile_y = 0; tile_y < row_height / 8; tile_y++) {
                for (int tile_x = 0; tile_x < width / 8; tile_x++) {
                    uint8_t encoded[32];
                    EncodeTile(image, x + tile_x * 8, y + tile_y * 8, encoded);
                    BytesAppend(tiles, encoded, sizeof(encoded));
                }
            }
            PiecesAppend(pieces, piece);
            x += width;
        }
        remaining_height -= row_height;
    }
    if (pieces->count > 128)
        Fail("packed image uses more than GBA's 128 OAM entries");
    if (tile_base + (int)(tiles->size / 32) > 0x400)
        Fail("packed image exceeds GBA attr2's 10-bit tile range");
}

static void AppendU16(struct Bytes *bytes, uint16_t value)
{
    uint8_t raw[2] = {(uint8_t)value, (uint8_t)(value >> 8)};
    BytesAppend(bytes, raw, sizeof(raw));
}

static void EncodeOam(const struct Pieces *pieces, int origin_x, int origin_y, int palette_bank, struct Bytes *oam)
{
    if (palette_bank < 0 || palette_bank > 15)
        Fail("palette bank must be between 0 and 15");
    for (size_t index = 0; index < pieces->count; index++) {
        const struct Piece *piece = &pieces->data[index];
        const struct Dimension *dimension = NULL;
        for (size_t i = 0; i < sizeof(sDimensions) / sizeof(sDimensions[0]); i++)
            if (sDimensions[i].width == piece->width && sDimensions[i].height == piece->height)
                dimension = &sDimensions[i];
        if (dimension == NULL)
            Fail("internal OAM dimension error");
        int x = piece->x + origin_x;
        int y = piece->y + origin_y;
        if (x < -256 || x > 255 || y < -128 || y > 127)
            Fail("generated OAM position is outside signed GBA coordinates");
        uint16_t attr0 = (uint16_t)((y & 0xFF) | (dimension->shape << 14));
        uint16_t attr1 = (uint16_t)((x & 0x1FF) | (dimension->size << 14));
        uint16_t attr2 = (uint16_t)(piece->tile_start | (palette_bank << 12));
        AppendU16(oam, attr0);
        AppendU16(oam, attr1);
        AppendU16(oam, attr2);
        AppendU16(oam, 0);
    }
}

static void EncodePalette(const struct Image *image, struct Bytes *palette)
{
    for (int index = 0; index < 16; index++)
        AppendU16(palette, image->palette[index]);
}

static uint8_t DecodePixel(const struct Bytes *tiles, int tile_id, int pixel)
{
    uint8_t byte = tiles->data[(size_t)tile_id * 32 + pixel / 2];
    return pixel & 1 ? byte >> 4 : byte & 0x0F;
}

static void VerifyRender(const struct Image *image, const struct Pieces *pieces, const struct Bytes *tiles, int tile_base)
{
    uint8_t *rendered = calloc((size_t)image->width * image->height, 1);
    if (rendered == NULL)
        Fail("out of memory");
    for (size_t i = 0; i < pieces->count; i++) {
        const struct Piece *piece = &pieces->data[i];
        int tiles_wide = piece->width / 8;
        for (int tile_y = 0; tile_y < piece->height / 8; tile_y++) {
            for (int tile_x = 0; tile_x < tiles_wide; tile_x++) {
                int tile = piece->tile_start - tile_base + tile_y * tiles_wide + tile_x;
                for (int pixel_y = 0; pixel_y < 8; pixel_y++) {
                    for (int pixel_x = 0; pixel_x < 8; pixel_x++) {
                        uint8_t value = DecodePixel(tiles, tile, pixel_y * 8 + pixel_x);
                        if (value)
                            rendered[(size_t)(piece->y + tile_y * 8 + pixel_y) * image->width
                                     + piece->x + tile_x * 8 + pixel_x] = value;
                    }
                }
            }
        }
    }
    if (memcmp(rendered, image->pixels, (size_t)image->width * image->height)) {
        for (int y = 0; y < image->height; y++) {
            for (int x = 0; x < image->width; x++) {
                size_t offset = (size_t)y * image->width + x;
                if (rendered[offset] != image->pixels[offset]) {
                    fprintf(stderr, "oam_pack: render verification differs at (%d, %d): got %u expected %u\n",
                            x, y, rendered[offset], image->pixels[offset]);
                    free(rendered);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    free(rendered);
}

static void WriteFile(const char *path, const uint8_t *data, size_t size)
{
    FILE *file = fopen(path, "wb");
    if (file == NULL)
        FailPath("cannot write", path);
    if (fwrite(data, 1, size, file) != size)
        FailPath("cannot write", path);
    fclose(file);
}

static void WriteAsm(const char *path, const char *label, const struct Bytes *oam)
{
    FILE *file = fopen(path, "w");
    if (file == NULL)
        FailPath("cannot write", path);
    fprintf(file, ".section .rodata\n.align 2\n.global %s\n%s:\n", label, label);
    for (size_t offset = 0; offset < oam->size; offset += 8) {
        uint16_t attr0 = oam->data[offset] | (uint16_t)oam->data[offset + 1] << 8;
        uint16_t attr1 = oam->data[offset + 2] | (uint16_t)oam->data[offset + 3] << 8;
        uint16_t attr2 = oam->data[offset + 4] | (uint16_t)oam->data[offset + 5] << 8;
        fprintf(file, "    .hword 0x%04X, 0x%04X, 0x%04X, 0x0000\n", attr0, attr1, attr2);
    }
    fclose(file);
}

static uint32_t ReadU32(const uint8_t *data, size_t offset)
{
    return data[offset] | (uint32_t)data[offset + 1] << 8 | (uint32_t)data[offset + 2] << 16 | (uint32_t)data[offset + 3] << 24;
}

static uint16_t ReadU16(const uint8_t *data, size_t offset)
{
    return data[offset] | (uint16_t)data[offset + 1] << 8;
}

static uint8_t *ReadRange(const char *path, int offset, int length)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL)
        FailPath("cannot open", path);
    if (fseek(file, offset, SEEK_SET) != 0)
        FailPath("cannot seek", path);
    uint8_t *data = CheckedAlloc((size_t)length);
    if (fread(data, 1, length, file) != (size_t)length)
        Fail("reference ROM ends before archive range");
    fclose(file);
    return data;
}

static bool CompareBlob(const char *name, const uint8_t *actual, size_t actual_size,
                        const uint8_t *expected, size_t expected_size)
{
    bool same = actual_size == expected_size && !memcmp(actual, expected, actual_size);
    printf("%s: generated %zu bytes, reference %zu bytes%s\n", name, actual_size, expected_size,
           same ? ", identical" : ", differs");
    if (!same) {
        size_t limit = actual_size < expected_size ? actual_size : expected_size;
        for (size_t index = 0; index < limit; index++) {
            if (actual[index] != expected[index]) {
                printf("  first difference at 0x%zX: generated %02X, reference %02X\n",
                       index, actual[index], expected[index]);
                break;
            }
        }
    }
    return same;
}

static bool ComparePortraitReference(const char *rom_path, int archive_offset, int archive_length,
                                     int portrait_id, const struct Bytes *tiles, const struct Bytes *palette,
                                     const struct Bytes *oam,
                                     bool dump_reference)
{
    static const int strides[] = {4, 16, 8, 32, 32, 8, 4};
    uint8_t *archive = ReadRange(rom_path, archive_offset, archive_length);
    size_t tables[7];
    size_t cursor = 0;
    for (size_t index = 0; index < 7; index++) {
        if (cursor + 4 > (size_t)archive_length)
            Fail("reference archive ends in table count");
        uint32_t count = ReadU32(archive, cursor);
        cursor += 4;
        tables[index] = cursor;
        if (count > ((size_t)archive_length - cursor) / strides[index])
            Fail("reference archive table exceeds range");
        cursor += (size_t)count * strides[index];
    }
    uint32_t portraits = ReadU32(archive, 0);
    if (portrait_id < 0 || (uint32_t)portrait_id >= portraits)
        Fail("portrait ID is outside reference archive");
    uint16_t descriptor_id = ReadU16(archive, tables[0] + (size_t)portrait_id * 4 + 2);
    size_t descriptor = tables[1] + (size_t)descriptor_id * 16;
    uint16_t oam_count = ReadU16(archive, descriptor);
    uint16_t oam_start = ReadU16(archive, descriptor + 2);
    uint16_t tile_count = ReadU16(archive, descriptor + 4);
    uint16_t tile_start = ReadU16(archive, descriptor + 6);
    uint16_t palette_id = ReadU16(archive, descriptor + 10);
    if (dump_reference) {
        printf("reference portrait %d: descriptor %u, %u OAM entries from %u, %u tiles from %u, palette %u\n",
               portrait_id, descriptor_id, oam_count, oam_start, tile_count, tile_start, palette_id);
        for (uint16_t index = 0; index < oam_count; index++) {
            const uint8_t *entry = archive + tables[2] + (size_t)(oam_start + index) * 8;
            uint16_t attr0 = ReadU16(entry, 0);
            uint16_t attr1 = ReadU16(entry, 2);
            uint16_t attr2 = ReadU16(entry, 4);
            int x = attr1 & 0x1FF;
            int y = attr0 & 0xFF;
            if (x > 255) x -= 512;
            if (y > 127) y -= 256;
            printf("  %02u: x=%d y=%d shape=%u size=%u tile=%u raw=%04X,%04X,%04X,%04X\n",
                   index, x, y, attr0 >> 14, attr1 >> 14, attr2 & 0x3FF,
                   attr0, attr1, attr2, ReadU16(entry, 6));
        }
    }
    bool same_tiles = CompareBlob("tiles", tiles->data, tiles->size,
                                  archive + tables[3] + (size_t)tile_start * 32, (size_t)tile_count * 32);
    bool same_palette = CompareBlob("palette", palette->data, palette->size,
                                    archive + tables[4] + (size_t)palette_id * 32, 32);
    bool same_oam = CompareBlob("OAM", oam->data, oam->size,
                                archive + tables[2] + (size_t)oam_start * 8, (size_t)oam_count * 8);
    free(archive);
    return same_tiles && same_palette && same_oam;
}

static void PrintUsage(void)
{
    fputs("usage: oam_pack IMAGE.png --tiles OUT.4bpp --palette OUT.gbapal --oam OUT.oam [options]\n"
          "  --asm OUT.s --label SYMBOL       optional readable OAM source\n"
          "  --strategy dense|opaque|canvas     dense, non-overlapping opaque, or fixed canvas\n"
          "  --origin-x N --origin-y N         OAM origin for PNG top-left\n"
          "  --tile-base N --palette-bank N    attr2 tile/palette values\n"
          "  --reference-rom ROM --reference-offset N --portrait-id N\n"
          "                                    compare generated bytes with a FoMT portrait\n"
          "  --reference-length N              defaults to 0x5E0A4\n"
          "  --reference-dump                  show original descriptor/OAM fields\n"
          "  --report-only                     do not fail when comparison differs\n", stderr);
}

int main(int argc, char **argv)
{
    const char *image_path = NULL;
    const char *tiles_path = NULL;
    const char *palette_path = NULL;
    const char *oam_path = NULL;
    const char *asm_path = NULL;
    const char *label = "gGeneratedOam";
    const char *reference_rom = NULL;
    int reference_offset = -1;
    int reference_length = 0x5E0A4;
    int portrait_id = -1;
    int origin_x = 0;
    int origin_y = 0;
    int tile_base = 0;
    int palette_bank = 0;
    bool report_only = false;
    bool dump_reference = false;
    enum { STRATEGY_DENSE, STRATEGY_OPAQUE, STRATEGY_CANVAS } strategy = STRATEGY_DENSE;
    for (int index = 1; index < argc; index++) {
        const char *argument = argv[index];
        if (argument[0] != '-') {
            if (image_path != NULL)
                Fail("only one input PNG is accepted");
            image_path = argument;
        } else if (!strcmp(argument, "--report-only")) {
            report_only = true;
        } else if (!strcmp(argument, "--reference-dump")) {
            dump_reference = true;
        } else {
            if (++index == argc)
                Fail("option requires an argument");
            const char *value = argv[index];
            if (!strcmp(argument, "--tiles")) tiles_path = value;
            else if (!strcmp(argument, "--palette")) palette_path = value;
            else if (!strcmp(argument, "--oam")) oam_path = value;
            else if (!strcmp(argument, "--asm")) asm_path = value;
            else if (!strcmp(argument, "--label")) label = value;
            else if (!strcmp(argument, "--strategy")) {
                if (!strcmp(value, "dense")) strategy = STRATEGY_DENSE;
                else if (!strcmp(value, "opaque")) strategy = STRATEGY_OPAQUE;
                else if (!strcmp(value, "canvas")) strategy = STRATEGY_CANVAS;
                else Fail("strategy must be dense, opaque or canvas");
            }
            else if (!strcmp(argument, "--origin-x")) origin_x = ParseNumber(value);
            else if (!strcmp(argument, "--origin-y")) origin_y = ParseNumber(value);
            else if (!strcmp(argument, "--tile-base")) tile_base = ParseNumber(value);
            else if (!strcmp(argument, "--palette-bank")) palette_bank = ParseNumber(value);
            else if (!strcmp(argument, "--reference-rom")) reference_rom = value;
            else if (!strcmp(argument, "--reference-offset")) reference_offset = ParseNumber(value);
            else if (!strcmp(argument, "--reference-length")) reference_length = ParseNumber(value);
            else if (!strcmp(argument, "--portrait-id")) portrait_id = ParseNumber(value);
            else {
                PrintUsage();
                Fail("unknown option");
            }
        }
    }
    if (image_path == NULL || tiles_path == NULL || palette_path == NULL || oam_path == NULL) {
        PrintUsage();
        Fail("input PNG, --tiles, --palette and --oam are required");
    }
    if ((reference_rom != NULL || reference_offset >= 0 || portrait_id >= 0)
     && (reference_rom == NULL || reference_offset < 0 || portrait_id < 0))
        Fail("reference comparison requires --reference-rom, --reference-offset and --portrait-id");
    if (tile_base < 0 || tile_base > 0x3FF)
        Fail("tile base must be between 0 and 1023");

    struct Image image = {0};
    struct Pieces pieces = {0};
    struct Bytes tiles = {0};
    struct Bytes palette = {0};
    struct Bytes oam = {0};
    ReadIndexedPng(image_path, &image);
    PadImageToTiles(&image);
    if (strategy == STRATEGY_CANVAS)
        PackCanvas(&image, tile_base, &pieces, &tiles);
    else if (strategy == STRATEGY_OPAQUE)
        PackOpaque(&image, tile_base, &pieces, &tiles);
    else
        PackDense(&image, tile_base, &pieces, &tiles);
    EncodePalette(&image, &palette);
    EncodeOam(&pieces, origin_x, origin_y, palette_bank, &oam);
    VerifyRender(&image, &pieces, &tiles, tile_base);
    WriteFile(tiles_path, tiles.data, tiles.size);
    WriteFile(palette_path, palette.data, palette.size);
    WriteFile(oam_path, oam.data, oam.size);
    if (asm_path != NULL)
        WriteAsm(asm_path, label, &oam);
    printf("packed %s: %dx%d, %zu OAM pieces, %zu tiles; visible indexed pixels verified\n",
           image_path, image.width, image.height, pieces.count, tiles.size / 32);
    bool identical = true;
    if (reference_rom != NULL)
        identical = ComparePortraitReference(reference_rom, reference_offset, reference_length, portrait_id, &tiles, &palette, &oam,
                                              dump_reference);
    free(image.pixels);
    free(pieces.data);
    free(tiles.data);
    free(palette.data);
    free(oam.data);
    return identical || report_only ? EXIT_SUCCESS : EXIT_FAILURE;
}
